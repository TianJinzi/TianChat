#ifndef OFFLINEDIALOG_H
#define OFFLINEDIALOG_H

#include <QDialog>

namespace Ui {
class OffLineDialog;
}

class OffLineDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OffLineDialog(QWidget *parent = nullptr);
    ~OffLineDialog();

signals:
    void sig_switch_login();

private:
    Ui::OffLineDialog *ui;
};

#endif // OFFLINEDIALOG_H
