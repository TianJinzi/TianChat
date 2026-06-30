#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "logindialog.h"
#include "registerdialog.h"
#include "resetdialog.h"
#include "chatdialog.h"
#include "offlinedialog.h"

/****************************************************
 * @file: mainwindow.h
 * @brief: 主窗口
 * @author: tian
 * @date: 2026/5/23
 *
 ****************************************************/

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
public slots:
    void SlotSwitchReg();
    void SlotSwitchLogin();
    void SlotSwitchReset();
    void SlotResetSwitchLogin();
    void SlotSwitchChat();
    void SlotOffLineSwitchLogin();
    void SlotChatSwitchOffDialog();

private:
    Ui::MainWindow *ui;
    LoginDialog* _login_dlg;
    RegisterDialog* _reg_dlg;
    ResetDialog* _reset_dlg;
    ChatDialog* _chat_dlg;
    OffLineDialog* _offLine_dlg;
};
#endif // MAINWINDOW_H
