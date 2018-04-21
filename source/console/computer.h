//
// PROJECT:         Aspia
// FILE:            console/computer.h
// LICENSE:         GNU General Public License 3
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#ifndef _ASPIA_CONSOLE__COMPUTER_H
#define _ASPIA_CONSOLE__COMPUTER_H

#include <QTreeWidget>

#include "protocol/address_book.pb.h"

namespace aspia {

class ComputerGroup;

class Computer : public QTreeWidgetItem
{
public:
    ~Computer();

    static std::unique_ptr<Computer> Create();

    QString Name() const;
    void SetName(const QString& name);
    QString Comment() const;
    void SetComment(const QString& comment);
    QString Address() const;
    void SetAddress(const QString& address);
    int Port() const;
    void SetPort(int port);
    QString UserName() const;
    void SetUserName(const QString& username);
    QString Password() const;
    void SetPassword(const QString& password);
    proto::desktop::Config DesktopManageSessionConfig() const;
    void SetDesktopManageSessionConfig(const proto::desktop::Config& config);
    proto::desktop::Config DesktopViewSessionConfig() const;
    void SetDesktopViewSessionConfig(const proto::desktop::Config& config);

    ComputerGroup* ParentComputerGroup();

private:
    friend class ComputerGroup;

    Computer(proto::Computer* computer, ComputerGroup* parent_group);

    proto::Computer* computer_;
    ComputerGroup* parent_group_;

    Q_DISABLE_COPY(Computer)
};

} // namespace aspia

#endif // _ASPIA_CONSOLE__COMPUTER_H