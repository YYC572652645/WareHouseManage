/********************************************************************************
** Form generated from reading UI file 'defaultlimitinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEFAULTLIMITINFO_H
#define UI_DEFAULTLIMITINFO_H

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

class Ui_DefaultLimitInfo
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditMatName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditBarCode;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEditSpec;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLineEdit *lineEditUnit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelUpper;
    QLineEdit *lineEditUpper;
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelLower;
    QLineEdit *lineEditLower;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonCancel;

    void setupUi(QWidget *DefaultLimitInfo)
    {
        if (DefaultLimitInfo->objectName().isEmpty())
            DefaultLimitInfo->setObjectName(QStringLiteral("DefaultLimitInfo"));
        DefaultLimitInfo->resize(457, 443);
        verticalLayout = new QVBoxLayout(DefaultLimitInfo);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(DefaultLimitInfo);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEditMatName = new QLineEdit(DefaultLimitInfo);
        lineEditMatName->setObjectName(QStringLiteral("lineEditMatName"));
        lineEditMatName->setEnabled(false);
        lineEditMatName->setMinimumSize(QSize(250, 30));
        lineEditMatName->setMaximumSize(QSize(250, 30));
        lineEditMatName->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(lineEditMatName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(DefaultLimitInfo);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEditBarCode = new QLineEdit(DefaultLimitInfo);
        lineEditBarCode->setObjectName(QStringLiteral("lineEditBarCode"));
        lineEditBarCode->setEnabled(false);
        lineEditBarCode->setMinimumSize(QSize(250, 30));
        lineEditBarCode->setMaximumSize(QSize(250, 30));
        lineEditBarCode->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(lineEditBarCode);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(DefaultLimitInfo);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEditSpec = new QLineEdit(DefaultLimitInfo);
        lineEditSpec->setObjectName(QStringLiteral("lineEditSpec"));
        lineEditSpec->setEnabled(false);
        lineEditSpec->setMinimumSize(QSize(200, 30));
        lineEditSpec->setMaximumSize(QSize(250, 30));
        lineEditSpec->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_3->addWidget(lineEditSpec);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_5 = new QLabel(DefaultLimitInfo);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_6->addWidget(label_5);

        lineEditUnit = new QLineEdit(DefaultLimitInfo);
        lineEditUnit->setObjectName(QStringLiteral("lineEditUnit"));
        lineEditUnit->setEnabled(false);
        lineEditUnit->setMinimumSize(QSize(250, 30));
        lineEditUnit->setMaximumSize(QSize(250, 30));
        lineEditUnit->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_6->addWidget(lineEditUnit);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        labelUpper = new QLabel(DefaultLimitInfo);
        labelUpper->setObjectName(QStringLiteral("labelUpper"));

        horizontalLayout_4->addWidget(labelUpper);

        lineEditUpper = new QLineEdit(DefaultLimitInfo);
        lineEditUpper->setObjectName(QStringLiteral("lineEditUpper"));
        lineEditUpper->setMinimumSize(QSize(250, 30));
        lineEditUpper->setMaximumSize(QSize(250, 16777215));

        horizontalLayout_4->addWidget(lineEditUpper);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        labelLower = new QLabel(DefaultLimitInfo);
        labelLower->setObjectName(QStringLiteral("labelLower"));

        horizontalLayout_7->addWidget(labelLower);

        lineEditLower = new QLineEdit(DefaultLimitInfo);
        lineEditLower->setObjectName(QStringLiteral("lineEditLower"));
        lineEditLower->setMinimumSize(QSize(250, 30));
        lineEditLower->setMaximumSize(QSize(250, 16777215));

        horizontalLayout_7->addWidget(lineEditLower);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButtonSave = new QPushButton(DefaultLimitInfo);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\347\241\256\350\256\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSave->setIcon(icon);

        horizontalLayout_5->addWidget(pushButtonSave);

        pushButtonCancel = new QPushButton(DefaultLimitInfo);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon1);

        horizontalLayout_5->addWidget(pushButtonCancel);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(DefaultLimitInfo);

        QMetaObject::connectSlotsByName(DefaultLimitInfo);
    } // setupUi

    void retranslateUi(QWidget *DefaultLimitInfo)
    {
        DefaultLimitInfo->setWindowTitle(QApplication::translate("DefaultLimitInfo", "Form", 0));
        label->setText(QApplication::translate("DefaultLimitInfo", "\345\216\237\346\226\231\345\220\215\347\247\260\357\274\232", 0));
        label_2->setText(QApplication::translate("DefaultLimitInfo", " \346\235\241\345\275\242\347\240\201\357\274\232", 0));
        label_3->setText(QApplication::translate("DefaultLimitInfo", "\350\247\204\346\240\274\357\274\232", 0));
        label_5->setText(QApplication::translate("DefaultLimitInfo", "\345\272\223\345\255\230\345\215\225\344\275\215\357\274\232", 0));
        labelUpper->setText(QApplication::translate("DefaultLimitInfo", "\345\256\211\345\205\250\345\272\223\345\255\230\344\270\212\351\231\220\357\274\232", 0));
        lineEditUpper->setPlaceholderText(QApplication::translate("DefaultLimitInfo", "\345\277\205\345\241\253", 0));
        labelLower->setText(QApplication::translate("DefaultLimitInfo", "\345\256\211\345\205\250\345\272\223\345\255\230\344\270\213\351\231\220\357\274\232", 0));
        lineEditLower->setPlaceholderText(QApplication::translate("DefaultLimitInfo", "\345\277\205\345\241\253", 0));
        pushButtonSave->setText(QApplication::translate("DefaultLimitInfo", " \344\277\235\345\255\230", 0));
        pushButtonCancel->setText(QApplication::translate("DefaultLimitInfo", " \345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class DefaultLimitInfo: public Ui_DefaultLimitInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEFAULTLIMITINFO_H
