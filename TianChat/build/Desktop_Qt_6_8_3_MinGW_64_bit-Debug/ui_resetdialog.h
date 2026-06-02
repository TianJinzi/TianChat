/********************************************************************************
** Form generated from reading UI file 'resetdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESETDIALOG_H
#define UI_RESETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "timerbtn.h"

QT_BEGIN_NAMESPACE

class Ui_ResetDialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_12;
    QLabel *err_tip;
    QHBoxLayout *horizontalLayout_8;
    QLabel *user_label;
    QLineEdit *user_edit;
    QHBoxLayout *horizontalLayout_9;
    QLabel *email_label;
    QLineEdit *email_edit;
    QHBoxLayout *horizontalLayout_10;
    QLabel *varify_label;
    QLineEdit *varify_edit;
    TimerBtn *varify_btn;
    QHBoxLayout *horizontalLayout_13;
    QLabel *pwd_label;
    QLineEdit *pwd_edit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_14;
    QPushButton *sure_btn;
    QPushButton *cancel;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *ResetDialog)
    {
        if (ResetDialog->objectName().isEmpty())
            ResetDialog->setObjectName("ResetDialog");
        ResetDialog->resize(300, 500);
        ResetDialog->setMinimumSize(QSize(300, 500));
        ResetDialog->setMaximumSize(QSize(300, 500));
        verticalLayout_4 = new QVBoxLayout(ResetDialog);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(5);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(5, 5, 5, 5);
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        err_tip = new QLabel(ResetDialog);
        err_tip->setObjectName("err_tip");
        err_tip->setMinimumSize(QSize(0, 25));
        err_tip->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_12->addWidget(err_tip);


        verticalLayout_3->addLayout(horizontalLayout_12);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        user_label = new QLabel(ResetDialog);
        user_label->setObjectName("user_label");
        user_label->setMinimumSize(QSize(35, 25));
        user_label->setMaximumSize(QSize(35, 25));

        horizontalLayout_8->addWidget(user_label);

        user_edit = new QLineEdit(ResetDialog);
        user_edit->setObjectName("user_edit");
        user_edit->setMinimumSize(QSize(0, 25));
        user_edit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_8->addWidget(user_edit);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        email_label = new QLabel(ResetDialog);
        email_label->setObjectName("email_label");
        email_label->setMinimumSize(QSize(35, 25));
        email_label->setMaximumSize(QSize(35, 25));

        horizontalLayout_9->addWidget(email_label);

        email_edit = new QLineEdit(ResetDialog);
        email_edit->setObjectName("email_edit");

        horizontalLayout_9->addWidget(email_edit);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        varify_label = new QLabel(ResetDialog);
        varify_label->setObjectName("varify_label");
        varify_label->setMinimumSize(QSize(35, 25));
        varify_label->setMaximumSize(QSize(35, 25));

        horizontalLayout_10->addWidget(varify_label);

        varify_edit = new QLineEdit(ResetDialog);
        varify_edit->setObjectName("varify_edit");

        horizontalLayout_10->addWidget(varify_edit);

        varify_btn = new TimerBtn(ResetDialog);
        varify_btn->setObjectName("varify_btn");
        varify_btn->setMinimumSize(QSize(40, 0));
        varify_btn->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_10->addWidget(varify_btn);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        pwd_label = new QLabel(ResetDialog);
        pwd_label->setObjectName("pwd_label");
        pwd_label->setMinimumSize(QSize(35, 25));
        pwd_label->setMaximumSize(QSize(35, 25));

        horizontalLayout_13->addWidget(pwd_label);

        pwd_edit = new QLineEdit(ResetDialog);
        pwd_edit->setObjectName("pwd_edit");

        horizontalLayout_13->addWidget(pwd_edit);


        verticalLayout_3->addLayout(horizontalLayout_13);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        sure_btn = new QPushButton(ResetDialog);
        sure_btn->setObjectName("sure_btn");

        horizontalLayout_14->addWidget(sure_btn);

        cancel = new QPushButton(ResetDialog);
        cancel->setObjectName("cancel");

        horizontalLayout_14->addWidget(cancel);


        verticalLayout_3->addLayout(horizontalLayout_14);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        verticalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(ResetDialog);

        QMetaObject::connectSlotsByName(ResetDialog);
    } // setupUi

    void retranslateUi(QDialog *ResetDialog)
    {
        ResetDialog->setWindowTitle(QCoreApplication::translate("ResetDialog", "Dialog", nullptr));
        err_tip->setText(QCoreApplication::translate("ResetDialog", "\351\224\231\350\257\257\346\217\220\347\244\272", nullptr));
        user_label->setText(QCoreApplication::translate("ResetDialog", "\347\224\250\346\210\267\345\220\215", nullptr));
        email_label->setText(QCoreApplication::translate("ResetDialog", "\351\202\256\347\256\261", nullptr));
        varify_label->setText(QCoreApplication::translate("ResetDialog", "\351\252\214\350\257\201\347\240\201", nullptr));
        varify_btn->setText(QCoreApplication::translate("ResetDialog", "\350\216\267\345\217\226", nullptr));
        pwd_label->setText(QCoreApplication::translate("ResetDialog", "\346\226\260\345\257\206\347\240\201", nullptr));
        sure_btn->setText(QCoreApplication::translate("ResetDialog", "\347\241\256\350\256\244", nullptr));
        cancel->setText(QCoreApplication::translate("ResetDialog", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResetDialog: public Ui_ResetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESETDIALOG_H
