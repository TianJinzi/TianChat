#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "TcpMgr.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _login_dlg(nullptr)
    , _reg_dlg(nullptr)
    , _reset_dlg(nullptr)
    , _chat_dlg(nullptr)
{
    ui->setupUi(this);
    _login_dlg=new LoginDialog(this);
    //让他可以嵌套到主窗口里
    _login_dlg->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    setCentralWidget(_login_dlg);
    _ui_status=LOGIN_UI;
    //_login_dlg->show();

    //创建和注册消息连接
    connect(_login_dlg,&LoginDialog::switchRegister,this,&MainWindow::SlotSwitchReg);
    connect(_login_dlg,&LoginDialog::switchReset,this,&MainWindow::SlotSwitchReset);
    connect(TcpMgr::GetInstance().get(),&TcpMgr::sig_swich_chatdlg,this,&MainWindow::SlotSwitchChat);
    connect(TcpMgr::GetInstance().get(),&TcpMgr::sig_notify_offline,this,&MainWindow::SlotChatSwitchOffDialog);
    connect(TcpMgr::GetInstance().get(),&TcpMgr::sig_connection_close,this,&MainWindow::SlotExcetpOffline);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SlotSwitchReg()
{

    _reg_dlg = new RegisterDialog(this);
    _reg_dlg->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    connect(_reg_dlg, &RegisterDialog::sigSwitchLogin, this, &MainWindow::SlotSwitchLogin);
    _reg_dlg->setVisible(false);   // 首次创建时立即隐藏，避免作为独立窗口闪现

    QWidget* oldWid = centralWidget();
    if (oldWid) oldWid->hide();
    setCentralWidget(_reg_dlg);
    _reg_dlg->show();
    _ui_status=REGISTER_UI;
}

void MainWindow::SlotSwitchLogin()
{
    _login_dlg=new LoginDialog(this);
    _login_dlg->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    connect(_login_dlg,&LoginDialog::switchRegister,this,&MainWindow::SlotSwitchReg);
    connect(_login_dlg,&LoginDialog::switchReset,this,&MainWindow::SlotSwitchReset);

    QWidget* oldWid = centralWidget();
    if (oldWid) oldWid->hide();

    this->setMaximumSize(300,500);
    this->setMinimumSize(300,500);
    setCentralWidget(_login_dlg);
    _login_dlg->show();
    _ui_status=LOGIN_UI;
}

void MainWindow::SlotSwitchReset()
{
    //创建一个CentralWidget, 并将其设置为MainWindow的中心部件
    _reset_dlg = new ResetDialog(this);
    _reset_dlg->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    connect(_reset_dlg, &ResetDialog::switchLogin, this, &MainWindow::SlotResetSwitchLogin);

    QWidget* oldWid = centralWidget();
    if (oldWid) oldWid->hide();

    setCentralWidget(_reset_dlg);
    _reset_dlg->show();
    //注册返回登录信号和槽函数
    _ui_status=RESET_UI;
}

void MainWindow::SlotResetSwitchLogin()
{
    //创建一个CentralWidget, 并将其设置为MainWindow的中心部件
    _login_dlg = new LoginDialog(this);
    _login_dlg->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
        //连接登录界面忘记密码信号
    connect(_login_dlg, &LoginDialog::switchReset, this, &MainWindow::SlotSwitchReset);
        //连接登录界面忘记密码信号
    connect(_login_dlg, &LoginDialog::switchRegister, this, &MainWindow::SlotSwitchReg);

    QWidget* oldWid = centralWidget();
    if (oldWid) oldWid->hide();

    setCentralWidget(_login_dlg);
    _login_dlg->show();
    _ui_status=LOGIN_UI;
}

void MainWindow::SlotSwitchChat()
{
    _chat_dlg=new ChatDialog(this);
    _chat_dlg->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    _chat_dlg->hide(); // 避免作为独立窗口闪现

    if (_login_dlg) _login_dlg->hide();
    if (_reg_dlg)   _reg_dlg->hide();
    if (_reset_dlg) _reset_dlg->hide();

    QWidget* oldWid = centralWidget();
    if (oldWid) oldWid->hide();

    setCentralWidget(_chat_dlg);
    _chat_dlg->show();
    this->setMinimumSize(QSize(1050,900));
    this->setMaximumSize(QWIDGETSIZE_MAX,QWIDGETSIZE_MAX);
    _ui_status=CHAT_UI;
}
void MainWindow::SlotOffLineSwitchLogin()
{
    if(_ui_status==LOGIN_UI){
        return;
    }
    _login_dlg=new LoginDialog(this);
    _login_dlg->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    connect(_login_dlg,&LoginDialog::switchRegister,this,&MainWindow::SlotSwitchReg);
    connect(_login_dlg,&LoginDialog::switchReset,this,&MainWindow::SlotSwitchReset);

    QWidget* oldWid = centralWidget();
    if (oldWid) oldWid->hide();

    setCentralWidget(_login_dlg);
    _login_dlg->show();
    _ui_status=LOGIN_UI;
}

void MainWindow::SlotChatSwitchOffDialog()
{
    if(_ui_status==LOGIN_UI){
        return;
    }
    _offLine_dlg=new OffLineDialog(this);
    _offLine_dlg->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    connect(_offLine_dlg,&OffLineDialog::sig_switch_login,this,&MainWindow::SlotOffLineSwitchLogin);

    QWidget* oldWid=centralWidget();
    if(oldWid) {
        oldWid->disconnect();
        delete oldWid;
        oldWid=nullptr;
    }
    setCentralWidget(_offLine_dlg);
    _offLine_dlg->show();
    this->setMinimumSize(QSize(300,500));
    this->setMaximumSize(QSize(300,500));
}

void MainWindow::SlotExcetpOffline()
{
    QMessageBox::information(this,"下线提示","心跳超时或者异常断线，该终端下线");
    TcpMgr::GetInstance()->CloseConnection();
    SlotSwitchLogin();
}
