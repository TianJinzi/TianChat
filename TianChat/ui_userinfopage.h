/********************************************************************************
** Form generated from reading UI file 'userinfopage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINFOPAGE_H
#define UI_USERINFOPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserInfoPage
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QSpacerItem *verticalSpacer_3;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *head_lb;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *up_btn;
    QSpacerItem *verticalSpacer;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *nick_ed;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *name_ed;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *desc_ed;
    QSpacerItem *horizontalSpacer_5;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *UserInfoPage)
    {
        if (UserInfoPage->objectName().isEmpty())
            UserInfoPage->setObjectName("UserInfoPage");
        UserInfoPage->resize(422, 599);
        horizontalLayout = new QHBoxLayout(UserInfoPage);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widget = new QWidget(UserInfoPage);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(250, 0));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        label = new QLabel(widget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setMinimumSize(QSize(0, 270));
        horizontalLayout_5 = new QHBoxLayout(widget_2);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        head_lb = new QLabel(widget_2);
        head_lb->setObjectName("head_lb");
        head_lb->setMinimumSize(QSize(200, 200));
        head_lb->setMaximumSize(QSize(200, 200));

        horizontalLayout_5->addWidget(head_lb);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        up_btn = new QPushButton(widget_2);
        up_btn->setObjectName("up_btn");
        up_btn->setMinimumSize(QSize(60, 0));
        up_btn->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_5->addWidget(up_btn);


        verticalLayout->addWidget(widget_2);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName("widget_3");
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(widget_3);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(35, 0));
        label_2->setMaximumSize(QSize(35, 16777215));

        horizontalLayout_2->addWidget(label_2);

        nick_ed = new QLineEdit(widget_3);
        nick_ed->setObjectName("nick_ed");

        horizontalLayout_2->addWidget(nick_ed);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(widget_3);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName("widget_4");
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(widget_4);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(35, 0));
        label_3->setMaximumSize(QSize(35, 16777215));

        horizontalLayout_3->addWidget(label_3);

        name_ed = new QLineEdit(widget_4);
        name_ed->setObjectName("name_ed");

        horizontalLayout_3->addWidget(name_ed);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(widget_4);

        widget_5 = new QWidget(widget);
        widget_5->setObjectName("widget_5");
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_4 = new QLabel(widget_5);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(35, 0));
        label_4->setMaximumSize(QSize(35, 16777215));

        horizontalLayout_4->addWidget(label_4);

        desc_ed = new QLineEdit(widget_5);
        desc_ed->setObjectName("desc_ed");

        horizontalLayout_4->addWidget(desc_ed);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);


        verticalLayout->addWidget(widget_5);

        frame = new QFrame(widget);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        pushButton = new QPushButton(frame);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(60, 0));
        pushButton->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_6->addWidget(pushButton);


        verticalLayout->addWidget(frame);


        horizontalLayout->addWidget(widget);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(UserInfoPage);

        QMetaObject::connectSlotsByName(UserInfoPage);
    } // setupUi

    void retranslateUi(QWidget *UserInfoPage)
    {
        UserInfoPage->setWindowTitle(QCoreApplication::translate("UserInfoPage", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("UserInfoPage", "\345\237\272\346\234\254\344\277\241\346\201\257", nullptr));
        head_lb->setText(QString());
        up_btn->setText(QCoreApplication::translate("UserInfoPage", "\344\270\212\344\274\240", nullptr));
        label_2->setText(QCoreApplication::translate("UserInfoPage", "\346\230\265\347\247\260\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("UserInfoPage", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("UserInfoPage", ":\346\217\217\350\277\260:", nullptr));
        pushButton->setText(QCoreApplication::translate("UserInfoPage", "\346\217\220\344\272\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserInfoPage: public Ui_UserInfoPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINFOPAGE_H
