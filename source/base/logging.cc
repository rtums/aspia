//
// PROJECT:         Aspia
// FILE:            base/logging.cc
// LICENSE:         Mozilla Public License Version 2.0
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#include "base/logging.h"

#include <io.h>
#include <limits.h>

#include <algorithm>
#include <cstring>
#include <cstdint>
#include <ctime>
#include <iomanip>
#include <ostream>
#include <string>
#include <thread>
#include <utility>

#include "base/macros.h"
#include "base/command_line.h"
#include "base/strings/string_util.h"
#include "base/strings/string_printf.h"
#include "base/strings/unicode.h"

using FileHandle = HANDLE;

// Windows warns on using write().  It prefers _write().
#define write(fd, buf, count) _write(fd, buf, static_cast<unsigned int>(count))
// Windows doesn't define STDERR_FILENO.  Define it here.
#define STDERR_FILENO 2

namespace aspia {

namespace {

const char* const log_severity_names[] = {"INFO", "WARNING", "ERROR", "FATAL"};

static_assert(LS_NUMBER == _countof(log_severity_names));

const char* log_severity_name(LoggingSeverity severity)
{
    if (severity >= 0 && severity < LS_NUMBER)
        return log_severity_names[severity];
    return "UNKNOWN";
}

LoggingSeverity g_min_log_level = LS_INFO;

LoggingDestination g_logging_destination = LOG_DEFAULT;

// For LOG_ERROR and above, always print to stderr.
const int kAlwaysPrintErrorLevel = LS_ERROR;

// Which log file to use? This is initialized by InitLogging or
// will be lazily initialized to the default value when it is
// first needed.
typedef std::wstring PathString;

PathString* g_log_file_name = nullptr;

// This file is lazily opened and the handle may be nullptr
FileHandle g_log_file = nullptr;

// What should be prepended to each message?
bool g_log_process_id = false;
bool g_log_thread_id = false;
bool g_log_timestamp = true;
bool g_log_tickcount = false;

// A log message handler that gets notified of every log message we process.
LogMessageHandlerFunction log_message_handler = nullptr;

// Helper functions to wrap platform differences.

int32_t CurrentProcessId()
{
    return GetCurrentProcessId();
}

uint64_t TickCount()
{
    return GetTickCount();
}

void DeleteFilePath(const PathString& log_name)
{
    DeleteFileW(log_name.c_str());
}

PathString GetDefaultLogFile()
{
    // On Windows we use the same path as the exe.
    wchar_t module_name[MAX_PATH];
    GetModuleFileNameW(nullptr, module_name, MAX_PATH);

    PathString log_name = module_name;
    PathString::size_type last_backslash = log_name.rfind('\\', log_name.size());
    if (last_backslash != PathString::npos)
        log_name.erase(last_backslash + 1);
    log_name += L"debug.log";
    return log_name;
}

// Called by logging functions to ensure that |g_log_file| is initialized
// and can be used for writing. Returns false if the file could not be
// initialized. |g_log_file| will be nullptr in this case.
bool InitializeLogFileHandle()
{
    if (g_log_file)
        return true;

    if (!g_log_file_name)
    {
        // Nobody has called InitLogging to specify a debug log file, so here we
        // initialize the log file name to a default.
        g_log_file_name = new PathString(GetDefaultLogFile());
    }

    if ((g_logging_destination & LOG_TO_FILE) != 0)
    {
        // The FILE_APPEND_DATA access mask ensures that the file is atomically
        // appended to across accesses from multiple threads.
        // https://msdn.microsoft.com/en-us/library/windows/desktop/aa364399(v=vs.85).aspx
        // https://msdn.microsoft.com/en-us/library/windows/desktop/aa363858(v=vs.85).aspx
        g_log_file = CreateFileW(g_log_file_name->c_str(), FILE_APPEND_DATA,
                                 FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr,
                                 OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
        if (g_log_file == INVALID_HANDLE_VALUE || g_log_file == nullptr)
        {
            // We are intentionally not using FilePath or FileUtil here to reduce the
            // dependencies of the logging implementation. For e.g. FilePath and
            // FileUtil depend on shell32 and user32.dll. This is not acceptable for
            // some consumers of base logging like chrome_elf, etc.
            // Please don't change the code below to use FilePath.
            // try the current directory
            wchar_t system_buffer[MAX_PATH];
            system_buffer[0] = 0;
            DWORD len = ::GetCurrentDirectoryW(_countof(system_buffer), system_buffer);
            if (len == 0 || len > _countof(system_buffer))
                return false;

            *g_log_file_name = system_buffer;
            // Append a trailing backslash if needed.
            if (g_log_file_name->back() != L'\\')
                *g_log_file_name += L"\\";
            *g_log_file_name += L"debug.log";

            g_log_file = CreateFileW(g_log_file_name->c_str(), FILE_APPEND_DATA,
                                     FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr,
                                     OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
            if (g_log_file == INVALID_HANDLE_VALUE || g_log_file == nullptr)
            {
                g_log_file = nullptr;
                return false;
            }
        }
    }

    return true;
}

void CloseFile(FileHandle log)
{
    CloseHandle(log);
}

void CloseLogFileUnlocked()
{
    if (!g_log_file)
        return;

    CloseFile(g_log_file);
    g_log_file = nullptr;
}

} // namespace

// This is never instantiated, it's just used for EAT_STREAM_PARAMETERS to have
// an object of the correct type on the LHS of the unused part of the ternary
// operator.
std::ostream* g_swallow_stream;

LoggingSettings::LoggingSettings()
    : logging_dest(LOG_DEFAULT),
      log_file(nullptr),
      lock_log(LOCK_LOG_FILE),
      delete_old(APPEND_TO_OLD_LOG_FILE)
{
    // Nothing
}

bool BaseInitLoggingImpl(const LoggingSettings& settings)
{
    g_logging_destination = settings.logging_dest;

    // ignore file options unless logging to file is set.
    if ((g_logging_destination & LOG_TO_FILE) == 0)
        return true;

    // Calling InitLogging twice or after some log call has already opened the
    // default log file will re-initialize to the new options.
    CloseLogFileUnlocked();

    if (!g_log_file_name)
        g_log_file_name = new PathString();
    *g_log_file_name = settings.log_file;
    if (settings.delete_old == DELETE_OLD_LOG_FILE)
        DeleteFilePath(*g_log_file_name);

    return InitializeLogFileHandle();
}

void SetMinLogLevel(LoggingSeverity level)
{
    g_min_log_level = std::min(LS_FATAL, level);
}

LoggingSeverity GetMinLogLevel()
{
    return g_min_log_level;
}

bool ShouldCreateLogMessage(LoggingSeverity severity)
{
    if (severity < g_min_log_level)
        return false;

    // Return true here unless we know ~LogMessage won't do anything. Note that
    // ~LogMessage writes to stderr if severity_ >= kAlwaysPrintErrorLevel, even
    // when g_logging_destination is LOG_NONE.
    return g_logging_destination != LOG_NONE || log_message_handler ||
           severity >= kAlwaysPrintErrorLevel;
}

void SetLogItems(bool enable_process_id, bool enable_thread_id,
                 bool enable_timestamp, bool enable_tickcount)
{
    g_log_process_id = enable_process_id;
    g_log_thread_id = enable_thread_id;
    g_log_timestamp = enable_timestamp;
    g_log_tickcount = enable_tickcount;
}

void SetLogMessageHandler(LogMessageHandlerFunction handler)
{
    log_message_handler = handler;
}

LogMessageHandlerFunction GetLogMessageHandler()
{
    return log_message_handler;
}

void MakeCheckOpValueString(std::ostream* os, std::nullptr_t /* p */)
{
    (*os) << "nullptr";
}

// Build the error message string.  This is separate from the "Impl"
// function template because it is not performance critical and so can
// be out of line, while the "Impl" code should be inline.  Caller
// takes ownership of the returned string.
template<class t1, class t2>
std::string* MakeCheckOpString(const t1& v1, const t2& v2, const char* names)
{
    std::ostringstream ss;
    ss << names << " (";
    MakeCheckOpValueString(&ss, v1);
    ss << " vs. ";
    MakeCheckOpValueString(&ss, v2);
    ss << ")";
    std::string* msg = new std::string(ss.str());
    return msg;
}

std::string* MakeCheckOpString(const int& v1, const int& v2, const char* names)
{
    return MakeCheckOpString<int, int>(v1, v2, names);
}

std::string* MakeCheckOpString(const unsigned long& v1, const unsigned long& v2, const char* names)
{
    return MakeCheckOpString<unsigned long, unsigned long>(v1, v2, names);
}

std::string* MakeCheckOpString(const unsigned long& v1, const unsigned int& v2, const char* names)
{
    return MakeCheckOpString<unsigned long, int>(v1, v2, names);
}

std::string* MakeCheckOpString(const unsigned int& v1, const unsigned long& v2, const char* names)
{
    return MakeCheckOpString<unsigned int, unsigned long>(v1, v2, names);
}

std::string* MakeCheckOpString(const std::string& v1, const std::string& v2, const char* names)
{
    return MakeCheckOpString<std::string, std::string>(v1, v2, names);
}

LogMessage::SaveLastError::SaveLastError()
    : last_error_(::GetLastError())
{
    // Nothing
}

LogMessage::SaveLastError::~SaveLastError()
{
    ::SetLastError(last_error_);
}

LogMessage::LogMessage(const char* file, int line, LoggingSeverity severity)
    : severity_(severity), file_(file), line_(line)
{
    Init(file, line);
}

LogMessage::LogMessage(const char* file, int line, const char* condition)
    : severity_(LS_FATAL), file_(file), line_(line)
{
    Init(file, line);
    stream_ << "Check failed: " << condition << ". ";
}

LogMessage::LogMessage(const char* file, int line, std::string* result)
    : severity_(LS_FATAL), file_(file), line_(line)
{
    Init(file, line);
    stream_ << "Check failed: " << *result;
    delete result;
}

LogMessage::LogMessage(const char* file, int line, LoggingSeverity severity,
                       std::string* result)
    : severity_(severity), file_(file), line_(line)
{
    Init(file, line);
    stream_ << "Check failed: " << *result;
    delete result;
}

LogMessage::~LogMessage()
{
    stream_ << std::endl;
    std::string str_newline(stream_.str());

    // Give any log message handler first dibs on the message.
    if (log_message_handler &&
        log_message_handler(severity_, file_, line_, message_start_, str_newline))
    {
        // The handler took care of it, no further processing.
        return;
    }

    if ((g_logging_destination & LOG_TO_SYSTEM_DEBUG_LOG) != 0)
    {
        OutputDebugStringA(str_newline.c_str());

        fwrite(str_newline.data(), str_newline.size(), 1, stderr);
        fflush(stderr);
    }
    else if (severity_ >= kAlwaysPrintErrorLevel)
    {
        // When we're only outputting to a log file, above a certain log level, we
        // should still output to stderr so that we can better detect and diagnose
        // problems with unit tests, especially on the buildbots.
        fwrite(str_newline.data(), str_newline.size(), 1, stderr);
        fflush(stderr);
    }

    // write to log file
    if ((g_logging_destination & LOG_TO_FILE) != 0)
    {
        // We can have multiple threads and/or processes, so try to prevent them
        // from clobbering each other's writes.
        // If the client app did not call InitLogging, and the lock has not
        // been created do it now. We do this on demand, but if two threads try
        // to do this at the same time, there will be a race condition to create
        // the lock. This is why InitLogging should be called from the main
        // thread at the beginning of execution.

        if (InitializeLogFileHandle())
        {
            DWORD num_written;
            WriteFile(g_log_file,
                      static_cast<const void*>(str_newline.c_str()),
                      static_cast<DWORD>(str_newline.length()),
                      &num_written,
                      nullptr);
        }
    }

    if (severity_ == LS_FATAL)
    {
        // Crash the process.
        __debugbreak();
    }
}

// writes the common header info to the stream
void LogMessage::Init(const char* file, int line)
{
    std::string_view filename(file);

    size_t last_slash_pos = filename.find_last_of("\\/");
    if (last_slash_pos != std::string_view::npos)
        filename.remove_prefix(last_slash_pos + 1);

    // TODO(darin): It might be nice if the columns were fixed width.

    stream_ <<  '[';

    if (g_log_process_id)
        stream_ << CurrentProcessId() << ':';

    if (g_log_thread_id)
        stream_ << std::this_thread::get_id() << ':';

    if (g_log_timestamp)
    {
        SYSTEMTIME local_time;
        GetLocalTime(&local_time);

        stream_ << std::setfill('0')
                << std::setw(2) << local_time.wMonth
                << std::setw(2) << local_time.wDay
                << '/'
                << std::setw(2) << local_time.wHour
                << std::setw(2) << local_time.wMinute
                << std::setw(2) << local_time.wSecond
                << '.'
                << std::setw(3) << local_time.wMilliseconds
                << ':';
    }

    if (g_log_tickcount)
        stream_ << TickCount() << ':';

    if (severity_ >= 0)
        stream_ << log_severity_name(severity_);
    else
        stream_ << "VERBOSE" << -severity_;

    stream_ << ":" << filename.data() << "(" << line << ")] ";

    message_start_ = stream_.str().length();
}

SystemErrorCode GetLastSystemErrorCode()
{
    return ::GetLastError();
}

std::string SystemErrorCodeToString(SystemErrorCode error_code)
{
    constexpr int kErrorMessageBufferSize = 256;
    char msgbuf[kErrorMessageBufferSize];

    static const DWORD flags = FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS;

    DWORD len = FormatMessageA(flags, nullptr, error_code, 0, msgbuf, _countof(msgbuf), nullptr);
    if (len)
    {
        // Messages returned by system end with line breaks.
        return aspia::CollapseWhitespaceASCII(msgbuf, true) +
               aspia::StringPrintf(" (0x%lX)", error_code);
    }

    return aspia::StringPrintf("Error (0x%lX) while retrieving error. (0x%lX)",
                               GetLastError(), error_code);
}

std::string GetLastSystemErrorString()
{
    return SystemErrorCodeToString(GetLastError());
}

Win32ErrorLogMessage::Win32ErrorLogMessage(const char* file,
                                           int line,
                                           LoggingSeverity severity,
                                           SystemErrorCode err)
    : err_(err),
      log_message_(file, line, severity)
{
    // Nothing
}

Win32ErrorLogMessage::~Win32ErrorLogMessage()
{
    stream() << ": " << SystemErrorCodeToString(err_);
}

void CloseLogFile()
{
    CloseLogFileUnlocked();
}

void RawLog(int level, const char* message)
{
    if (level >= g_min_log_level && message)
    {
        size_t bytes_written = 0;
        const size_t message_len = strlen(message);
        int rv;
        while (bytes_written < message_len)
        {
            rv = write(STDERR_FILENO,
                       message + bytes_written,
                       message_len - bytes_written);
            if (rv < 0)
            {
                // Give up, nothing we can do now.
                break;
            }
            bytes_written += rv;
        }

        if (message_len > 0 && message[message_len - 1] != '\n')
        {
            do
            {
                rv = write(STDERR_FILENO, "\n", 1);
                if (rv < 0)
                {
                    // Give up, nothing we can do now.
                    break;
                }
            }
            while (rv != 1);
        }
    }

    if (level == LS_FATAL)
        __debugbreak();
}

bool IsLoggingToFileEnabled()
{
    return g_logging_destination & LOG_TO_FILE;
}

std::wstring GetLogFileFullPath()
{
    if (g_log_file_name)
        return *g_log_file_name;
    return std::wstring();
}

void LogErrorNotReached(const char* file, int line)
{
    LogMessage(file, line, LS_ERROR).stream() << "NOTREACHED() hit.";
}

} // namespace aspia

std::ostream& std::operator<<(std::ostream& out, const wchar_t* wstr)
{
    return out << (wstr ? aspia::UTF8fromUNICODE(wstr) : std::string());
}
