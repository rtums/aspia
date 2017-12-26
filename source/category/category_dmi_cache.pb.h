// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: category_dmi_cache.proto

#ifndef PROTOBUF_category_5fdmi_5fcache_2eproto__INCLUDED
#define PROTOBUF_category_5fdmi_5fcache_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/message_lite.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_util.h>
// @@protoc_insertion_point(includes)

namespace protobuf_category_5fdmi_5fcache_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[2];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void InitDefaultsDmiCaches_ItemImpl();
void InitDefaultsDmiCaches_Item();
void InitDefaultsDmiCachesImpl();
void InitDefaultsDmiCaches();
inline void InitDefaults() {
  InitDefaultsDmiCaches_Item();
  InitDefaultsDmiCaches();
}
}  // namespace protobuf_category_5fdmi_5fcache_2eproto
namespace aspia {
namespace proto {
class DmiCaches;
class DmiCachesDefaultTypeInternal;
extern DmiCachesDefaultTypeInternal _DmiCaches_default_instance_;
class DmiCaches_Item;
class DmiCaches_ItemDefaultTypeInternal;
extern DmiCaches_ItemDefaultTypeInternal _DmiCaches_Item_default_instance_;
}  // namespace proto
}  // namespace aspia
namespace aspia {
namespace proto {

enum DmiCaches_Location {
  DmiCaches_Location_LOCATION_UNKNOWN = 0,
  DmiCaches_Location_LOCATION_INTERNAL = 1,
  DmiCaches_Location_LOCATION_EXTERNAL = 2,
  DmiCaches_Location_LOCATION_RESERVED = 3,
  DmiCaches_Location_DmiCaches_Location_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  DmiCaches_Location_DmiCaches_Location_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool DmiCaches_Location_IsValid(int value);
const DmiCaches_Location DmiCaches_Location_Location_MIN = DmiCaches_Location_LOCATION_UNKNOWN;
const DmiCaches_Location DmiCaches_Location_Location_MAX = DmiCaches_Location_LOCATION_RESERVED;
const int DmiCaches_Location_Location_ARRAYSIZE = DmiCaches_Location_Location_MAX + 1;

enum DmiCaches_Status {
  DmiCaches_Status_STATUS_UNKNOWN = 0,
  DmiCaches_Status_STATUS_ENABLED = 1,
  DmiCaches_Status_STATUS_DISABLED = 2,
  DmiCaches_Status_DmiCaches_Status_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  DmiCaches_Status_DmiCaches_Status_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool DmiCaches_Status_IsValid(int value);
const DmiCaches_Status DmiCaches_Status_Status_MIN = DmiCaches_Status_STATUS_UNKNOWN;
const DmiCaches_Status DmiCaches_Status_Status_MAX = DmiCaches_Status_STATUS_DISABLED;
const int DmiCaches_Status_Status_ARRAYSIZE = DmiCaches_Status_Status_MAX + 1;

enum DmiCaches_Mode {
  DmiCaches_Mode_MODE_UNKNOWN = 0,
  DmiCaches_Mode_MODE_WRITE_THRU = 1,
  DmiCaches_Mode_MODE_WRITE_BACK = 2,
  DmiCaches_Mode_MODE_WRITE_WITH_MEMORY_ADDRESS = 3,
  DmiCaches_Mode_DmiCaches_Mode_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  DmiCaches_Mode_DmiCaches_Mode_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool DmiCaches_Mode_IsValid(int value);
const DmiCaches_Mode DmiCaches_Mode_Mode_MIN = DmiCaches_Mode_MODE_UNKNOWN;
const DmiCaches_Mode DmiCaches_Mode_Mode_MAX = DmiCaches_Mode_MODE_WRITE_WITH_MEMORY_ADDRESS;
const int DmiCaches_Mode_Mode_ARRAYSIZE = DmiCaches_Mode_Mode_MAX + 1;

enum DmiCaches_SRAMType {
  DmiCaches_SRAMType_SRAM_TYPE_BAD = 0,
  DmiCaches_SRAMType_SRAM_TYPE_OTHER = 1,
  DmiCaches_SRAMType_SRAM_TYPE_UNKNOWN = 2,
  DmiCaches_SRAMType_SRAM_TYPE_NON_BURST = 4,
  DmiCaches_SRAMType_SRAM_TYPE_BURST = 8,
  DmiCaches_SRAMType_SRAM_TYPE_PIPELINE_BURST = 16,
  DmiCaches_SRAMType_SRAM_TYPE_SYNCHRONOUS = 32,
  DmiCaches_SRAMType_SRAM_TYPE_ASYNCHRONOUS = 64,
  DmiCaches_SRAMType_DmiCaches_SRAMType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  DmiCaches_SRAMType_DmiCaches_SRAMType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool DmiCaches_SRAMType_IsValid(int value);
const DmiCaches_SRAMType DmiCaches_SRAMType_SRAMType_MIN = DmiCaches_SRAMType_SRAM_TYPE_BAD;
const DmiCaches_SRAMType DmiCaches_SRAMType_SRAMType_MAX = DmiCaches_SRAMType_SRAM_TYPE_ASYNCHRONOUS;
const int DmiCaches_SRAMType_SRAMType_ARRAYSIZE = DmiCaches_SRAMType_SRAMType_MAX + 1;

enum DmiCaches_ErrorCorrectionType {
  DmiCaches_ErrorCorrectionType_ERROR_CORRECTION_TYPE_UNKNOWN = 0,
  DmiCaches_ErrorCorrectionType_ERROR_CORRECTION_TYPE_OTHER = 1,
  DmiCaches_ErrorCorrectionType_ERROR_CORRECTION_TYPE_NONE = 2,
  DmiCaches_ErrorCorrectionType_ERROR_CORRECTION_TYPE_PARITY = 3,
  DmiCaches_ErrorCorrectionType_ERROR_CORRECTION_TYPE_SINGLE_BIT_ECC = 4,
  DmiCaches_ErrorCorrectionType_ERROR_CORRECTION_TYPE_MULTI_BIT_ECC = 5,
  DmiCaches_ErrorCorrectionType_DmiCaches_ErrorCorrectionType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  DmiCaches_ErrorCorrectionType_DmiCaches_ErrorCorrectionType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool DmiCaches_ErrorCorrectionType_IsValid(int value);
const DmiCaches_ErrorCorrectionType DmiCaches_ErrorCorrectionType_ErrorCorrectionType_MIN = DmiCaches_ErrorCorrectionType_ERROR_CORRECTION_TYPE_UNKNOWN;
const DmiCaches_ErrorCorrectionType DmiCaches_ErrorCorrectionType_ErrorCorrectionType_MAX = DmiCaches_ErrorCorrectionType_ERROR_CORRECTION_TYPE_MULTI_BIT_ECC;
const int DmiCaches_ErrorCorrectionType_ErrorCorrectionType_ARRAYSIZE = DmiCaches_ErrorCorrectionType_ErrorCorrectionType_MAX + 1;

enum DmiCaches_Type {
  DmiCaches_Type_TYPE_UNKNOWN = 0,
  DmiCaches_Type_TYPE_OTHER = 1,
  DmiCaches_Type_TYPE_INSTRUCTION = 2,
  DmiCaches_Type_TYPE_DATA = 3,
  DmiCaches_Type_TYPE_UNIFIED = 4,
  DmiCaches_Type_DmiCaches_Type_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  DmiCaches_Type_DmiCaches_Type_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool DmiCaches_Type_IsValid(int value);
const DmiCaches_Type DmiCaches_Type_Type_MIN = DmiCaches_Type_TYPE_UNKNOWN;
const DmiCaches_Type DmiCaches_Type_Type_MAX = DmiCaches_Type_TYPE_UNIFIED;
const int DmiCaches_Type_Type_ARRAYSIZE = DmiCaches_Type_Type_MAX + 1;

enum DmiCaches_Associativity {
  DmiCaches_Associativity_ASSOCIATIVITY_UNKNOWN = 0,
  DmiCaches_Associativity_ASSOCIATIVITY_OTHER = 1,
  DmiCaches_Associativity_ASSOCIATIVITY_DIRECT_MAPPED = 2,
  DmiCaches_Associativity_ASSOCIATIVITY_2_WAY = 3,
  DmiCaches_Associativity_ASSOCIATIVITY_4_WAY = 4,
  DmiCaches_Associativity_ASSOCIATIVITY_FULLY = 5,
  DmiCaches_Associativity_ASSOCIATIVITY_8_WAY = 6,
  DmiCaches_Associativity_ASSOCIATIVITY_16_WAY = 7,
  DmiCaches_Associativity_ASSOCIATIVITY_12_WAY = 8,
  DmiCaches_Associativity_ASSOCIATIVITY_24_WAY = 9,
  DmiCaches_Associativity_ASSOCIATIVITY_32_WAY = 10,
  DmiCaches_Associativity_ASSOCIATIVITY_48_WAY = 11,
  DmiCaches_Associativity_ASSOCIATIVITY_64_WAY = 12,
  DmiCaches_Associativity_ASSOCIATIVITY_20_WAY = 13,
  DmiCaches_Associativity_DmiCaches_Associativity_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  DmiCaches_Associativity_DmiCaches_Associativity_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool DmiCaches_Associativity_IsValid(int value);
const DmiCaches_Associativity DmiCaches_Associativity_Associativity_MIN = DmiCaches_Associativity_ASSOCIATIVITY_UNKNOWN;
const DmiCaches_Associativity DmiCaches_Associativity_Associativity_MAX = DmiCaches_Associativity_ASSOCIATIVITY_20_WAY;
const int DmiCaches_Associativity_Associativity_ARRAYSIZE = DmiCaches_Associativity_Associativity_MAX + 1;

// ===================================================================

class DmiCaches_Item : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:aspia.proto.DmiCaches.Item) */ {
 public:
  DmiCaches_Item();
  virtual ~DmiCaches_Item();

  DmiCaches_Item(const DmiCaches_Item& from);

  inline DmiCaches_Item& operator=(const DmiCaches_Item& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  DmiCaches_Item(DmiCaches_Item&& from) noexcept
    : DmiCaches_Item() {
    *this = ::std::move(from);
  }

  inline DmiCaches_Item& operator=(DmiCaches_Item&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const DmiCaches_Item& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const DmiCaches_Item* internal_default_instance() {
    return reinterpret_cast<const DmiCaches_Item*>(
               &_DmiCaches_Item_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(DmiCaches_Item* other);
  friend void swap(DmiCaches_Item& a, DmiCaches_Item& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline DmiCaches_Item* New() const PROTOBUF_FINAL { return New(NULL); }

  DmiCaches_Item* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from)
    PROTOBUF_FINAL;
  void CopyFrom(const DmiCaches_Item& from);
  void MergeFrom(const DmiCaches_Item& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  void DiscardUnknownFields();
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(DmiCaches_Item* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::std::string GetTypeName() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string name = 1;
  void clear_name();
  static const int kNameFieldNumber = 1;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  #if LANG_CXX11
  void set_name(::std::string&& value);
  #endif
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // .aspia.proto.DmiCaches.Location location = 2;
  void clear_location();
  static const int kLocationFieldNumber = 2;
  ::aspia::proto::DmiCaches_Location location() const;
  void set_location(::aspia::proto::DmiCaches_Location value);

  // .aspia.proto.DmiCaches.Status status = 3;
  void clear_status();
  static const int kStatusFieldNumber = 3;
  ::aspia::proto::DmiCaches_Status status() const;
  void set_status(::aspia::proto::DmiCaches_Status value);

  // .aspia.proto.DmiCaches.Mode mode = 4;
  void clear_mode();
  static const int kModeFieldNumber = 4;
  ::aspia::proto::DmiCaches_Mode mode() const;
  void set_mode(::aspia::proto::DmiCaches_Mode value);

  // int32 level = 5;
  void clear_level();
  static const int kLevelFieldNumber = 5;
  ::google::protobuf::int32 level() const;
  void set_level(::google::protobuf::int32 value);

  // int32 maximum_size = 6;
  void clear_maximum_size();
  static const int kMaximumSizeFieldNumber = 6;
  ::google::protobuf::int32 maximum_size() const;
  void set_maximum_size(::google::protobuf::int32 value);

  // int32 current_size = 7;
  void clear_current_size();
  static const int kCurrentSizeFieldNumber = 7;
  ::google::protobuf::int32 current_size() const;
  void set_current_size(::google::protobuf::int32 value);

  // uint32 supported_sram_types = 8;
  void clear_supported_sram_types();
  static const int kSupportedSramTypesFieldNumber = 8;
  ::google::protobuf::uint32 supported_sram_types() const;
  void set_supported_sram_types(::google::protobuf::uint32 value);

  // .aspia.proto.DmiCaches.SRAMType current_sram_type = 9;
  void clear_current_sram_type();
  static const int kCurrentSramTypeFieldNumber = 9;
  ::aspia::proto::DmiCaches_SRAMType current_sram_type() const;
  void set_current_sram_type(::aspia::proto::DmiCaches_SRAMType value);

  // int32 speed = 10;
  void clear_speed();
  static const int kSpeedFieldNumber = 10;
  ::google::protobuf::int32 speed() const;
  void set_speed(::google::protobuf::int32 value);

  // .aspia.proto.DmiCaches.ErrorCorrectionType error_correction_type = 11;
  void clear_error_correction_type();
  static const int kErrorCorrectionTypeFieldNumber = 11;
  ::aspia::proto::DmiCaches_ErrorCorrectionType error_correction_type() const;
  void set_error_correction_type(::aspia::proto::DmiCaches_ErrorCorrectionType value);

  // .aspia.proto.DmiCaches.Type type = 12;
  void clear_type();
  static const int kTypeFieldNumber = 12;
  ::aspia::proto::DmiCaches_Type type() const;
  void set_type(::aspia::proto::DmiCaches_Type value);

  // .aspia.proto.DmiCaches.Associativity associativity = 13;
  void clear_associativity();
  static const int kAssociativityFieldNumber = 13;
  ::aspia::proto::DmiCaches_Associativity associativity() const;
  void set_associativity(::aspia::proto::DmiCaches_Associativity value);

  // @@protoc_insertion_point(class_scope:aspia.proto.DmiCaches.Item)
 private:

  ::google::protobuf::internal::InternalMetadataWithArenaLite _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  int location_;
  int status_;
  int mode_;
  ::google::protobuf::int32 level_;
  ::google::protobuf::int32 maximum_size_;
  ::google::protobuf::int32 current_size_;
  ::google::protobuf::uint32 supported_sram_types_;
  int current_sram_type_;
  ::google::protobuf::int32 speed_;
  int error_correction_type_;
  int type_;
  int associativity_;
  mutable int _cached_size_;
  friend struct ::protobuf_category_5fdmi_5fcache_2eproto::TableStruct;
  friend void ::protobuf_category_5fdmi_5fcache_2eproto::InitDefaultsDmiCaches_ItemImpl();
};
// -------------------------------------------------------------------

class DmiCaches : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:aspia.proto.DmiCaches) */ {
 public:
  DmiCaches();
  virtual ~DmiCaches();

  DmiCaches(const DmiCaches& from);

  inline DmiCaches& operator=(const DmiCaches& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  DmiCaches(DmiCaches&& from) noexcept
    : DmiCaches() {
    *this = ::std::move(from);
  }

  inline DmiCaches& operator=(DmiCaches&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const DmiCaches& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const DmiCaches* internal_default_instance() {
    return reinterpret_cast<const DmiCaches*>(
               &_DmiCaches_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(DmiCaches* other);
  friend void swap(DmiCaches& a, DmiCaches& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline DmiCaches* New() const PROTOBUF_FINAL { return New(NULL); }

  DmiCaches* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from)
    PROTOBUF_FINAL;
  void CopyFrom(const DmiCaches& from);
  void MergeFrom(const DmiCaches& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  void DiscardUnknownFields();
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(DmiCaches* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::std::string GetTypeName() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  typedef DmiCaches_Item Item;

  typedef DmiCaches_Location Location;
  static const Location LOCATION_UNKNOWN =
    DmiCaches_Location_LOCATION_UNKNOWN;
  static const Location LOCATION_INTERNAL =
    DmiCaches_Location_LOCATION_INTERNAL;
  static const Location LOCATION_EXTERNAL =
    DmiCaches_Location_LOCATION_EXTERNAL;
  static const Location LOCATION_RESERVED =
    DmiCaches_Location_LOCATION_RESERVED;
  static inline bool Location_IsValid(int value) {
    return DmiCaches_Location_IsValid(value);
  }
  static const Location Location_MIN =
    DmiCaches_Location_Location_MIN;
  static const Location Location_MAX =
    DmiCaches_Location_Location_MAX;
  static const int Location_ARRAYSIZE =
    DmiCaches_Location_Location_ARRAYSIZE;

  typedef DmiCaches_Status Status;
  static const Status STATUS_UNKNOWN =
    DmiCaches_Status_STATUS_UNKNOWN;
  static const Status STATUS_ENABLED =
    DmiCaches_Status_STATUS_ENABLED;
  static const Status STATUS_DISABLED =
    DmiCaches_Status_STATUS_DISABLED;
  static inline bool Status_IsValid(int value) {
    return DmiCaches_Status_IsValid(value);
  }
  static const Status Status_MIN =
    DmiCaches_Status_Status_MIN;
  static const Status Status_MAX =
    DmiCaches_Status_Status_MAX;
  static const int Status_ARRAYSIZE =
    DmiCaches_Status_Status_ARRAYSIZE;

  typedef DmiCaches_Mode Mode;
  static const Mode MODE_UNKNOWN =
    DmiCaches_Mode_MODE_UNKNOWN;
  static const Mode MODE_WRITE_THRU =
    DmiCaches_Mode_MODE_WRITE_THRU;
  static const Mode MODE_WRITE_BACK =
    DmiCaches_Mode_MODE_WRITE_BACK;
  static const Mode MODE_WRITE_WITH_MEMORY_ADDRESS =
    DmiCaches_Mode_MODE_WRITE_WITH_MEMORY_ADDRESS;
  static inline bool Mode_IsValid(int value) {
    return DmiCaches_Mode_IsValid(value);
  }
  static const Mode Mode_MIN =
    DmiCaches_Mode_Mode_MIN;
  static const Mode Mode_MAX =
    DmiCaches_Mode_Mode_MAX;
  static const int Mode_ARRAYSIZE =
    DmiCaches_Mode_Mode_ARRAYSIZE;

  typedef DmiCaches_SRAMType SRAMType;
  static const SRAMType SRAM_TYPE_BAD =
    DmiCaches_SRAMType_SRAM_TYPE_BAD;
  static const SRAMType SRAM_TYPE_OTHER =
    DmiCaches_SRAMType_SRAM_TYPE_OTHER;
  static const SRAMType SRAM_TYPE_UNKNOWN =
    DmiCaches_SRAMType_SRAM_TYPE_UNKNOWN;
  static const SRAMType SRAM_TYPE_NON_BURST =
    DmiCaches_SRAMType_SRAM_TYPE_NON_BURST;
  static const SRAMType SRAM_TYPE_BURST =
    DmiCaches_SRAMType_SRAM_TYPE_BURST;
  static const SRAMType SRAM_TYPE_PIPELINE_BURST =
    DmiCaches_SRAMType_SRAM_TYPE_PIPELINE_BURST;
  static const SRAMType SRAM_TYPE_SYNCHRONOUS =
    DmiCaches_SRAMType_SRAM_TYPE_SYNCHRONOUS;
  static const SRAMType SRAM_TYPE_ASYNCHRONOUS =
    DmiCaches_SRAMType_SRAM_TYPE_ASYNCHRONOUS;
  static inline bool SRAMType_IsValid(int value) {
    return DmiCaches_SRAMType_IsValid(value);
  }
  static const SRAMType SRAMType_MIN =
    DmiCaches_SRAMType_SRAMType_MIN;
  static const SRAMType SRAMType_MAX =
    DmiCaches_SRAMType_SRAMType_MAX;
  static const int SRAMType_ARRAYSIZE =
    DmiCaches_SRAMType_SRAMType_ARRAYSIZE;

  typedef DmiCaches_ErrorCorrectionType ErrorCorrectionType;
  static const ErrorCorrectionType ERROR_CORRECTION_TYPE_UNKNOWN =
    DmiCaches_ErrorCorrectionType_ERROR_CORRECTION_TYPE_UNKNOWN;
  static const ErrorCorrectionType ERROR_CORRECTION_TYPE_OTHER =
    DmiCaches_ErrorCorrectionType_ERROR_CORRECTION_TYPE_OTHER;
  static const ErrorCorrectionType ERROR_CORRECTION_TYPE_NONE =
    DmiCaches_ErrorCorrectionType_ERROR_CORRECTION_TYPE_NONE;
  static const ErrorCorrectionType ERROR_CORRECTION_TYPE_PARITY =
    DmiCaches_ErrorCorrectionType_ERROR_CORRECTION_TYPE_PARITY;
  static const ErrorCorrectionType ERROR_CORRECTION_TYPE_SINGLE_BIT_ECC =
    DmiCaches_ErrorCorrectionType_ERROR_CORRECTION_TYPE_SINGLE_BIT_ECC;
  static const ErrorCorrectionType ERROR_CORRECTION_TYPE_MULTI_BIT_ECC =
    DmiCaches_ErrorCorrectionType_ERROR_CORRECTION_TYPE_MULTI_BIT_ECC;
  static inline bool ErrorCorrectionType_IsValid(int value) {
    return DmiCaches_ErrorCorrectionType_IsValid(value);
  }
  static const ErrorCorrectionType ErrorCorrectionType_MIN =
    DmiCaches_ErrorCorrectionType_ErrorCorrectionType_MIN;
  static const ErrorCorrectionType ErrorCorrectionType_MAX =
    DmiCaches_ErrorCorrectionType_ErrorCorrectionType_MAX;
  static const int ErrorCorrectionType_ARRAYSIZE =
    DmiCaches_ErrorCorrectionType_ErrorCorrectionType_ARRAYSIZE;

  typedef DmiCaches_Type Type;
  static const Type TYPE_UNKNOWN =
    DmiCaches_Type_TYPE_UNKNOWN;
  static const Type TYPE_OTHER =
    DmiCaches_Type_TYPE_OTHER;
  static const Type TYPE_INSTRUCTION =
    DmiCaches_Type_TYPE_INSTRUCTION;
  static const Type TYPE_DATA =
    DmiCaches_Type_TYPE_DATA;
  static const Type TYPE_UNIFIED =
    DmiCaches_Type_TYPE_UNIFIED;
  static inline bool Type_IsValid(int value) {
    return DmiCaches_Type_IsValid(value);
  }
  static const Type Type_MIN =
    DmiCaches_Type_Type_MIN;
  static const Type Type_MAX =
    DmiCaches_Type_Type_MAX;
  static const int Type_ARRAYSIZE =
    DmiCaches_Type_Type_ARRAYSIZE;

  typedef DmiCaches_Associativity Associativity;
  static const Associativity ASSOCIATIVITY_UNKNOWN =
    DmiCaches_Associativity_ASSOCIATIVITY_UNKNOWN;
  static const Associativity ASSOCIATIVITY_OTHER =
    DmiCaches_Associativity_ASSOCIATIVITY_OTHER;
  static const Associativity ASSOCIATIVITY_DIRECT_MAPPED =
    DmiCaches_Associativity_ASSOCIATIVITY_DIRECT_MAPPED;
  static const Associativity ASSOCIATIVITY_2_WAY =
    DmiCaches_Associativity_ASSOCIATIVITY_2_WAY;
  static const Associativity ASSOCIATIVITY_4_WAY =
    DmiCaches_Associativity_ASSOCIATIVITY_4_WAY;
  static const Associativity ASSOCIATIVITY_FULLY =
    DmiCaches_Associativity_ASSOCIATIVITY_FULLY;
  static const Associativity ASSOCIATIVITY_8_WAY =
    DmiCaches_Associativity_ASSOCIATIVITY_8_WAY;
  static const Associativity ASSOCIATIVITY_16_WAY =
    DmiCaches_Associativity_ASSOCIATIVITY_16_WAY;
  static const Associativity ASSOCIATIVITY_12_WAY =
    DmiCaches_Associativity_ASSOCIATIVITY_12_WAY;
  static const Associativity ASSOCIATIVITY_24_WAY =
    DmiCaches_Associativity_ASSOCIATIVITY_24_WAY;
  static const Associativity ASSOCIATIVITY_32_WAY =
    DmiCaches_Associativity_ASSOCIATIVITY_32_WAY;
  static const Associativity ASSOCIATIVITY_48_WAY =
    DmiCaches_Associativity_ASSOCIATIVITY_48_WAY;
  static const Associativity ASSOCIATIVITY_64_WAY =
    DmiCaches_Associativity_ASSOCIATIVITY_64_WAY;
  static const Associativity ASSOCIATIVITY_20_WAY =
    DmiCaches_Associativity_ASSOCIATIVITY_20_WAY;
  static inline bool Associativity_IsValid(int value) {
    return DmiCaches_Associativity_IsValid(value);
  }
  static const Associativity Associativity_MIN =
    DmiCaches_Associativity_Associativity_MIN;
  static const Associativity Associativity_MAX =
    DmiCaches_Associativity_Associativity_MAX;
  static const int Associativity_ARRAYSIZE =
    DmiCaches_Associativity_Associativity_ARRAYSIZE;

  // accessors -------------------------------------------------------

  // repeated .aspia.proto.DmiCaches.Item item = 1;
  int item_size() const;
  void clear_item();
  static const int kItemFieldNumber = 1;
  const ::aspia::proto::DmiCaches_Item& item(int index) const;
  ::aspia::proto::DmiCaches_Item* mutable_item(int index);
  ::aspia::proto::DmiCaches_Item* add_item();
  ::google::protobuf::RepeatedPtrField< ::aspia::proto::DmiCaches_Item >*
      mutable_item();
  const ::google::protobuf::RepeatedPtrField< ::aspia::proto::DmiCaches_Item >&
      item() const;

  // @@protoc_insertion_point(class_scope:aspia.proto.DmiCaches)
 private:

  ::google::protobuf::internal::InternalMetadataWithArenaLite _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::aspia::proto::DmiCaches_Item > item_;
  mutable int _cached_size_;
  friend struct ::protobuf_category_5fdmi_5fcache_2eproto::TableStruct;
  friend void ::protobuf_category_5fdmi_5fcache_2eproto::InitDefaultsDmiCachesImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// DmiCaches_Item

// string name = 1;
inline void DmiCaches_Item::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& DmiCaches_Item::name() const {
  // @@protoc_insertion_point(field_get:aspia.proto.DmiCaches.Item.name)
  return name_.GetNoArena();
}
inline void DmiCaches_Item::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:aspia.proto.DmiCaches.Item.name)
}
#if LANG_CXX11
inline void DmiCaches_Item::set_name(::std::string&& value) {
  
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:aspia.proto.DmiCaches.Item.name)
}
#endif
inline void DmiCaches_Item::set_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:aspia.proto.DmiCaches.Item.name)
}
inline void DmiCaches_Item::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:aspia.proto.DmiCaches.Item.name)
}
inline ::std::string* DmiCaches_Item::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:aspia.proto.DmiCaches.Item.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* DmiCaches_Item::release_name() {
  // @@protoc_insertion_point(field_release:aspia.proto.DmiCaches.Item.name)
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void DmiCaches_Item::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:aspia.proto.DmiCaches.Item.name)
}

// .aspia.proto.DmiCaches.Location location = 2;
inline void DmiCaches_Item::clear_location() {
  location_ = 0;
}
inline ::aspia::proto::DmiCaches_Location DmiCaches_Item::location() const {
  // @@protoc_insertion_point(field_get:aspia.proto.DmiCaches.Item.location)
  return static_cast< ::aspia::proto::DmiCaches_Location >(location_);
}
inline void DmiCaches_Item::set_location(::aspia::proto::DmiCaches_Location value) {
  
  location_ = value;
  // @@protoc_insertion_point(field_set:aspia.proto.DmiCaches.Item.location)
}

// .aspia.proto.DmiCaches.Status status = 3;
inline void DmiCaches_Item::clear_status() {
  status_ = 0;
}
inline ::aspia::proto::DmiCaches_Status DmiCaches_Item::status() const {
  // @@protoc_insertion_point(field_get:aspia.proto.DmiCaches.Item.status)
  return static_cast< ::aspia::proto::DmiCaches_Status >(status_);
}
inline void DmiCaches_Item::set_status(::aspia::proto::DmiCaches_Status value) {
  
  status_ = value;
  // @@protoc_insertion_point(field_set:aspia.proto.DmiCaches.Item.status)
}

// .aspia.proto.DmiCaches.Mode mode = 4;
inline void DmiCaches_Item::clear_mode() {
  mode_ = 0;
}
inline ::aspia::proto::DmiCaches_Mode DmiCaches_Item::mode() const {
  // @@protoc_insertion_point(field_get:aspia.proto.DmiCaches.Item.mode)
  return static_cast< ::aspia::proto::DmiCaches_Mode >(mode_);
}
inline void DmiCaches_Item::set_mode(::aspia::proto::DmiCaches_Mode value) {
  
  mode_ = value;
  // @@protoc_insertion_point(field_set:aspia.proto.DmiCaches.Item.mode)
}

// int32 level = 5;
inline void DmiCaches_Item::clear_level() {
  level_ = 0;
}
inline ::google::protobuf::int32 DmiCaches_Item::level() const {
  // @@protoc_insertion_point(field_get:aspia.proto.DmiCaches.Item.level)
  return level_;
}
inline void DmiCaches_Item::set_level(::google::protobuf::int32 value) {
  
  level_ = value;
  // @@protoc_insertion_point(field_set:aspia.proto.DmiCaches.Item.level)
}

// int32 maximum_size = 6;
inline void DmiCaches_Item::clear_maximum_size() {
  maximum_size_ = 0;
}
inline ::google::protobuf::int32 DmiCaches_Item::maximum_size() const {
  // @@protoc_insertion_point(field_get:aspia.proto.DmiCaches.Item.maximum_size)
  return maximum_size_;
}
inline void DmiCaches_Item::set_maximum_size(::google::protobuf::int32 value) {
  
  maximum_size_ = value;
  // @@protoc_insertion_point(field_set:aspia.proto.DmiCaches.Item.maximum_size)
}

// int32 current_size = 7;
inline void DmiCaches_Item::clear_current_size() {
  current_size_ = 0;
}
inline ::google::protobuf::int32 DmiCaches_Item::current_size() const {
  // @@protoc_insertion_point(field_get:aspia.proto.DmiCaches.Item.current_size)
  return current_size_;
}
inline void DmiCaches_Item::set_current_size(::google::protobuf::int32 value) {
  
  current_size_ = value;
  // @@protoc_insertion_point(field_set:aspia.proto.DmiCaches.Item.current_size)
}

// uint32 supported_sram_types = 8;
inline void DmiCaches_Item::clear_supported_sram_types() {
  supported_sram_types_ = 0u;
}
inline ::google::protobuf::uint32 DmiCaches_Item::supported_sram_types() const {
  // @@protoc_insertion_point(field_get:aspia.proto.DmiCaches.Item.supported_sram_types)
  return supported_sram_types_;
}
inline void DmiCaches_Item::set_supported_sram_types(::google::protobuf::uint32 value) {
  
  supported_sram_types_ = value;
  // @@protoc_insertion_point(field_set:aspia.proto.DmiCaches.Item.supported_sram_types)
}

// .aspia.proto.DmiCaches.SRAMType current_sram_type = 9;
inline void DmiCaches_Item::clear_current_sram_type() {
  current_sram_type_ = 0;
}
inline ::aspia::proto::DmiCaches_SRAMType DmiCaches_Item::current_sram_type() const {
  // @@protoc_insertion_point(field_get:aspia.proto.DmiCaches.Item.current_sram_type)
  return static_cast< ::aspia::proto::DmiCaches_SRAMType >(current_sram_type_);
}
inline void DmiCaches_Item::set_current_sram_type(::aspia::proto::DmiCaches_SRAMType value) {
  
  current_sram_type_ = value;
  // @@protoc_insertion_point(field_set:aspia.proto.DmiCaches.Item.current_sram_type)
}

// int32 speed = 10;
inline void DmiCaches_Item::clear_speed() {
  speed_ = 0;
}
inline ::google::protobuf::int32 DmiCaches_Item::speed() const {
  // @@protoc_insertion_point(field_get:aspia.proto.DmiCaches.Item.speed)
  return speed_;
}
inline void DmiCaches_Item::set_speed(::google::protobuf::int32 value) {
  
  speed_ = value;
  // @@protoc_insertion_point(field_set:aspia.proto.DmiCaches.Item.speed)
}

// .aspia.proto.DmiCaches.ErrorCorrectionType error_correction_type = 11;
inline void DmiCaches_Item::clear_error_correction_type() {
  error_correction_type_ = 0;
}
inline ::aspia::proto::DmiCaches_ErrorCorrectionType DmiCaches_Item::error_correction_type() const {
  // @@protoc_insertion_point(field_get:aspia.proto.DmiCaches.Item.error_correction_type)
  return static_cast< ::aspia::proto::DmiCaches_ErrorCorrectionType >(error_correction_type_);
}
inline void DmiCaches_Item::set_error_correction_type(::aspia::proto::DmiCaches_ErrorCorrectionType value) {
  
  error_correction_type_ = value;
  // @@protoc_insertion_point(field_set:aspia.proto.DmiCaches.Item.error_correction_type)
}

// .aspia.proto.DmiCaches.Type type = 12;
inline void DmiCaches_Item::clear_type() {
  type_ = 0;
}
inline ::aspia::proto::DmiCaches_Type DmiCaches_Item::type() const {
  // @@protoc_insertion_point(field_get:aspia.proto.DmiCaches.Item.type)
  return static_cast< ::aspia::proto::DmiCaches_Type >(type_);
}
inline void DmiCaches_Item::set_type(::aspia::proto::DmiCaches_Type value) {
  
  type_ = value;
  // @@protoc_insertion_point(field_set:aspia.proto.DmiCaches.Item.type)
}

// .aspia.proto.DmiCaches.Associativity associativity = 13;
inline void DmiCaches_Item::clear_associativity() {
  associativity_ = 0;
}
inline ::aspia::proto::DmiCaches_Associativity DmiCaches_Item::associativity() const {
  // @@protoc_insertion_point(field_get:aspia.proto.DmiCaches.Item.associativity)
  return static_cast< ::aspia::proto::DmiCaches_Associativity >(associativity_);
}
inline void DmiCaches_Item::set_associativity(::aspia::proto::DmiCaches_Associativity value) {
  
  associativity_ = value;
  // @@protoc_insertion_point(field_set:aspia.proto.DmiCaches.Item.associativity)
}

// -------------------------------------------------------------------

// DmiCaches

// repeated .aspia.proto.DmiCaches.Item item = 1;
inline int DmiCaches::item_size() const {
  return item_.size();
}
inline void DmiCaches::clear_item() {
  item_.Clear();
}
inline const ::aspia::proto::DmiCaches_Item& DmiCaches::item(int index) const {
  // @@protoc_insertion_point(field_get:aspia.proto.DmiCaches.item)
  return item_.Get(index);
}
inline ::aspia::proto::DmiCaches_Item* DmiCaches::mutable_item(int index) {
  // @@protoc_insertion_point(field_mutable:aspia.proto.DmiCaches.item)
  return item_.Mutable(index);
}
inline ::aspia::proto::DmiCaches_Item* DmiCaches::add_item() {
  // @@protoc_insertion_point(field_add:aspia.proto.DmiCaches.item)
  return item_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::aspia::proto::DmiCaches_Item >*
DmiCaches::mutable_item() {
  // @@protoc_insertion_point(field_mutable_list:aspia.proto.DmiCaches.item)
  return &item_;
}
inline const ::google::protobuf::RepeatedPtrField< ::aspia::proto::DmiCaches_Item >&
DmiCaches::item() const {
  // @@protoc_insertion_point(field_list:aspia.proto.DmiCaches.item)
  return item_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace aspia

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::aspia::proto::DmiCaches_Location> : ::google::protobuf::internal::true_type {};
template <> struct is_proto_enum< ::aspia::proto::DmiCaches_Status> : ::google::protobuf::internal::true_type {};
template <> struct is_proto_enum< ::aspia::proto::DmiCaches_Mode> : ::google::protobuf::internal::true_type {};
template <> struct is_proto_enum< ::aspia::proto::DmiCaches_SRAMType> : ::google::protobuf::internal::true_type {};
template <> struct is_proto_enum< ::aspia::proto::DmiCaches_ErrorCorrectionType> : ::google::protobuf::internal::true_type {};
template <> struct is_proto_enum< ::aspia::proto::DmiCaches_Type> : ::google::protobuf::internal::true_type {};
template <> struct is_proto_enum< ::aspia::proto::DmiCaches_Associativity> : ::google::protobuf::internal::true_type {};

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_category_5fdmi_5fcache_2eproto__INCLUDED