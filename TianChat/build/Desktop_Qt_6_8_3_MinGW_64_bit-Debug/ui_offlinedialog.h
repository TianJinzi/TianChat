/********************************************************************************
** Form generated from reading UI file 'offlinedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OFFLINEDIALOG_H
#define UI_OFFLINEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OffLineDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *sureBtn;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QDialog *OffLineDialog)
    {
        if (OffLineDialog->objectName().isEmpty())
            OffLineDialog->setObjectName("OffLineDialog");
        OffLineDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(OffLineDialog);
        verticalLayout->setObjectName("verticalLayout");
        widget = new QWidget(OffLineDialog);
        widget->setObjectName("widget");
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        label = new QLabel(widget);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        sureBtn = new QPushButton(widget_2);
        sureBtn->setObjectName("sureBtn");

        horizontalLayout->addWidget(sureBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(widget_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);


        verticalLayout->addWidget(widget);


        retranslateUi(OffLineDialog);

        QMetaObject::connectSlotsByName(OffLineDialog);
    } // setupUi

    void retranslateUi(QDialog *OffLineDialog)
    {
        OffLineDialog->setWindowTitle(QCoreApplication::translate("OffLineDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("OffLineDialog", "\346\234\254\350\264\246\345\217\267\345\267\262\345\234\250\345\205\266\344\273\226\350\256\276\345\244\207\344\270\212\347\231\273\345\275\225\357\274\201", nullptr));
        sureBtn->setText(QCoreApplication::translate("OffLineDialog", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OffLineDialog: public Ui_OffLineDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OFFLINEDIALOG_H
