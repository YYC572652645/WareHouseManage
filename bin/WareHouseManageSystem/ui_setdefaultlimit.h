/********************************************************************************
** Form generated from reading UI file 'setdefaultlimit.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETDEFAULTLIMIT_H
#define UI_SETDEFAULTLIMIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetDefaultLimit
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditMatNumber;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labelUpper;
    QLineEdit *lineEditUpper;
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelLower;
    QLineEdit *lineEditLower;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonCancel;

    void setupUi(QWidget *SetDefaultLimit)
    {
        if (SetDefaultLimit->objectName().isEmpty())
            SetDefaultLimit->setObjectName(QStringLiteral("SetDefaultLimit"));
        SetDefaultLimit->resize(477, 447);
        verticalLayout = new QVBoxLayout(SetDefaultLimit);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(SetDefaultLimit);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEditMatNumber = new QLineEdit(SetDefaultLimit);
        lineEditMatNumber->setObjectName(QStringLiteral("lineEditMatNumber"));
        lineEditMatNumber->setEnabled(false);
        lineEditMatNumber->setMinimumSize(QSize(250, 30));
        lineEditMatNumber->setMaximumSize(QSize(250, 30));
        lineEditMatNumber->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(lineEditMatNumber);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        labelUpper = new QLabel(SetDefaultLimit);
        labelUpper->setObjectName(QStringLiteral("labelUpper"));

        horizontalLayout_6->addWidget(labelUpper);

        lineEditUpper = new QLineEdit(SetDefaultLimit);
        lineEditUpper->setObjectName(QStringLiteral("lineEditUpper"));
        lineEditUpper->setMinimumSize(QSize(250, 30));
        lineEditUpper->setMaximumSize(QSize(250, 16777215));

        horizontalLayout_6->addWidget(lineEditUpper);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        labelLower = new QLabel(SetDefaultLimit);
        labelLower->setObjectName(QStringLiteral("labelLower"));

        horizontalLayout_7->addWidget(labelLower);

        lineEditLower = new QLineEdit(SetDefaultLimit);
        lineEditLower->setObjectName(QStringLiteral("lineEditLower"));
        lineEditLower->setMinimumSize(QSize(250, 30));
        lineEditLower->setMaximumSize(QSize(250, 16777215));

        horizontalLayout_7->addWidget(lineEditLower);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButtonSave = new QPushButton(SetDefaultLimit);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\347\241\256\350\256\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSave->setIcon(icon);

        horizontalLayout_5->addWidget(pushButtonSave);

        pushButtonCancel = new QPushButton(SetDefaultLimit);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon1);

        horizontalLayout_5->addWidget(pushButtonCancel);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(SetDefaultLimit);

        QMetaObject::connectSlotsByName(SetDefaultLimit);
    } // setupUi

    void retranslateUi(QWidget *SetDefaultLimit)
    {
        SetDefaultLimit->setWindowTitle(QApplication::translate("SetDefaultLimit", "Form", 0));
        label->setText(QApplication::translate("SetDefaultLimit", "\345\216\237\346\226\231\357\274\232", 0));
        labelUpper->setText(QApplication::translate("SetDefaultLimit", "\345\256\211\345\205\250\345\272\223\345\255\230\344\270\212\351\231\220\357\274\232", 0));
        lineEditUpper->setPlaceholderText(QApplication::translate("SetDefaultLimit", "\346\234\252\350\256\276\347\275\256", 0));
        labelLower->setText(QApplication::translate("SetDefaultLimit", "\345\256\211\345\205\250\345\272\223\345\255\230\344\270\213\351\231\220\357\274\232", 0));
        lineEditLower->setPlaceholderText(QApplication::translate("SetDefaultLimit", "\346\234\252\350\256\276\347\275\256", 0));
        pushButtonSave->setText(QApplication::translate("SetDefaultLimit", " \344\277\235\345\255\230", 0));
        pushButtonCancel->setText(QApplication::translate("SetDefaultLimit", " \345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class SetDefaultLimit: public Ui_SetDefaultLimit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETDEFAULTLIMIT_H
