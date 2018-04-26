/********************************************************************************
** Form generated from reading UI file 'defaultmatinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEFAULTMATINFO_H
#define UI_DEFAULTMATINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DefaultMatInfo
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
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *comboBoxSupplier;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonCancel;

    void setupUi(QWidget *DefaultMatInfo)
    {
        if (DefaultMatInfo->objectName().isEmpty())
            DefaultMatInfo->setObjectName(QStringLiteral("DefaultMatInfo"));
        DefaultMatInfo->resize(497, 456);
        verticalLayout = new QVBoxLayout(DefaultMatInfo);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(DefaultMatInfo);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEditMatName = new QLineEdit(DefaultMatInfo);
        lineEditMatName->setObjectName(QStringLiteral("lineEditMatName"));
        lineEditMatName->setEnabled(false);
        lineEditMatName->setMinimumSize(QSize(250, 30));
        lineEditMatName->setMaximumSize(QSize(250, 30));
        lineEditMatName->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(lineEditMatName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(DefaultMatInfo);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEditBarCode = new QLineEdit(DefaultMatInfo);
        lineEditBarCode->setObjectName(QStringLiteral("lineEditBarCode"));
        lineEditBarCode->setEnabled(false);
        lineEditBarCode->setMinimumSize(QSize(250, 30));
        lineEditBarCode->setMaximumSize(QSize(250, 30));
        lineEditBarCode->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(lineEditBarCode);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(DefaultMatInfo);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEditSpec = new QLineEdit(DefaultMatInfo);
        lineEditSpec->setObjectName(QStringLiteral("lineEditSpec"));
        lineEditSpec->setEnabled(false);
        lineEditSpec->setMinimumSize(QSize(250, 30));
        lineEditSpec->setMaximumSize(QSize(250, 30));
        lineEditSpec->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_3->addWidget(lineEditSpec);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(DefaultMatInfo);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        comboBoxSupplier = new QComboBox(DefaultMatInfo);
        comboBoxSupplier->setObjectName(QStringLiteral("comboBoxSupplier"));
        comboBoxSupplier->setMinimumSize(QSize(250, 30));
        comboBoxSupplier->setMaximumSize(QSize(250, 30));
        comboBoxSupplier->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        horizontalLayout_4->addWidget(comboBoxSupplier);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButtonSave = new QPushButton(DefaultMatInfo);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\347\241\256\350\256\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSave->setIcon(icon);

        horizontalLayout_5->addWidget(pushButtonSave);

        pushButtonCancel = new QPushButton(DefaultMatInfo);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon1);

        horizontalLayout_5->addWidget(pushButtonCancel);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(DefaultMatInfo);

        QMetaObject::connectSlotsByName(DefaultMatInfo);
    } // setupUi

    void retranslateUi(QWidget *DefaultMatInfo)
    {
        DefaultMatInfo->setWindowTitle(QApplication::translate("DefaultMatInfo", "Form", 0));
        label->setText(QApplication::translate("DefaultMatInfo", "\345\216\237\346\226\231\345\220\215\347\247\260\357\274\232", 0));
        label_2->setText(QApplication::translate("DefaultMatInfo", " \346\235\241\345\275\242\347\240\201\357\274\232", 0));
        label_3->setText(QApplication::translate("DefaultMatInfo", "\350\247\204\346\240\274\357\274\232", 0));
        label_4->setText(QApplication::translate("DefaultMatInfo", "\351\273\230\350\256\244\344\276\233\345\272\224\345\225\206\357\274\232", 0));
        pushButtonSave->setText(QApplication::translate("DefaultMatInfo", " \344\277\235\345\255\230", 0));
        pushButtonCancel->setText(QApplication::translate("DefaultMatInfo", " \345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class DefaultMatInfo: public Ui_DefaultMatInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEFAULTMATINFO_H
