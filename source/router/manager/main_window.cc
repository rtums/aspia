//
// Aspia Project
// Copyright (C) 2020 Dmitry Chapyshev <dmitry@aspia.ru>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <https://www.gnu.org/licenses/>.
//

#include "router/manager/main_window.h"

#include "router/manager/user_dialog.h"

#include <QMessageBox>

namespace router {

MainWindow::MainWindow()
{
    ui.setupUi(this);

    connect(ui.button_disconnect, &QPushButton::released, this, &MainWindow::onDisconnectOne);
    connect(ui.button_disconnect_all, &QPushButton::released, this, &MainWindow::onDisconnectAll);
    connect(ui.button_refresh_active, &QPushButton::released, this, &MainWindow::onRefresh);

    connect(ui.button_add_user, &QPushButton::released, this, &MainWindow::onAddUser);
    connect(ui.button_modify_user, &QPushButton::released, this, &MainWindow::onModifyUser);
    connect(ui.button_delete_user, &QPushButton::released, this, &MainWindow::onDeleteUser);
}

MainWindow::~MainWindow()
{

}

void MainWindow::onDisconnectOne()
{

}

void MainWindow::onDisconnectAll()
{

}

void MainWindow::onRefresh()
{

}

void MainWindow::onAddUser()
{
    UserDialog(this).exec();
}

void MainWindow::onModifyUser()
{

}

void MainWindow::onDeleteUser()
{

}

} // namespace router