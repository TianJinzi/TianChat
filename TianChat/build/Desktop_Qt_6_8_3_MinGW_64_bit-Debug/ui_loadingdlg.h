/********************************************************************************
** Form generated from reading UI file 'loadingdlg.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADINGDLG_H
#define UI_LOADINGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoadingDlg
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *status_lb;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *loading_lb;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *LoadingDlg)
    {
        if (LoadingDlg->objectName().isEmpty())
            LoadingDlg->setObjectName("LoadingDlg");
        LoadingDlg->resize(400, 300);
        verticalLayout = new QVBoxLayout(LoadingDlg);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 15, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        widget = new QWidget(LoadingDlg);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(0, 30));
        widget->setMaximumSize(QSize(16777215, 30));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        status_lb = new QLabel(widget);
        status_lb->setObjectName("status_lb");

        verticalLayout_2->addWidget(status_lb);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(LoadingDlg);
        widget_2->setObjectName("widget_2");
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName("horizontalLayout");
        loading_lb = new QLabel(widget_2);
        loading_lb->setObjectName("loading_lb");
        loading_lb->setMinimumSize(QSize(200, 200));
        loading_lb->setMaximumSize(QSize(200, 200));

        horizontalLayout->addWidget(loading_lb);


        verticalLayout->addWidget(widget_2);

        verticalSpacer_2 = new QSpacerItem(20, 15, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(LoadingDlg);

        QMetaObject::connectSlotsByName(LoadingDlg);
    } // setupUi

    void retranslateUi(QDialog *LoadingDlg)
    {
        LoadingDlg->setWindowTitle(QCoreApplication::translate("LoadingDlg", "Dialog", nullptr));
        status_lb->setText(QString());
        loading_lb->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoadingDlg: public Ui_LoadingDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADINGDLG_H
