#include "offlinedialog.h"
#include "ui_offlinedialog.h"
#include "mainwindow.h"

OffLineDialog::OffLineDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::OffLineDialog)
{
    ui->setupUi(this);
    connect(ui->sureBtn,&QPushButton::clicked,this,&OffLineDialog::sig_switch_login);
}
OffLineDialog::~OffLineDialog()
{
    delete ui;
}
