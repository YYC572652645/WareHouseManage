/********************************************************************************
** Form generated from reading UI file 'inventorydet.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVENTORYDET_H
#define UI_INVENTORYDET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InventoryDet
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditWareHouseName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditMatName;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEditBarCode;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEditOperType;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *lineEditNumber;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *lineEditChangeCount;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QLineEdit *lineEditOperPeople;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *lineEditOperTime;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QLineEdit *lineEditInvChangeTime;

    void setupUi(QWidget *InventoryDet)
    {
        if (InventoryDet->objectName().isEmpty())
            InventoryDet->setObjectName(QStringLiteral("InventoryDet"));
        InventoryDet->resize(362, 442);
        InventoryDet->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        verticalLayout = new QVBoxLayout(InventoryDet);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(InventoryDet);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEditWareHouseName = new QLineEdit(InventoryDet);
        lineEditWareHouseName->setObjectName(QStringLiteral("lineEditWareHouseName"));
        lineEditWareHouseName->setEnabled(false);
        lineEditWareHouseName->setMinimumSize(QSize(220, 30));
        lineEditWareHouseName->setMaximumSize(QSize(220, 16777215));

        horizontalLayout->addWidget(lineEditWareHouseName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(InventoryDet);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEditMatName = new QLineEdit(InventoryDet);
        lineEditMatName->setObjectName(QStringLiteral("lineEditMatName"));
        lineEditMatName->setEnabled(false);
        lineEditMatName->setMinimumSize(QSize(220, 30));
        lineEditMatName->setMaximumSize(QSize(220, 16777215));

        horizontalLayout_2->addWidget(lineEditMatName);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(InventoryDet);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEditBarCode = new QLineEdit(InventoryDet);
        lineEditBarCode->setObjectName(QStringLiteral("lineEditBarCode"));
        lineEditBarCode->setEnabled(false);
        lineEditBarCode->setMinimumSize(QSize(220, 30));
        lineEditBarCode->setMaximumSize(QSize(220, 16777215));

        horizontalLayout_3->addWidget(lineEditBarCode);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(InventoryDet);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEditOperType = new QLineEdit(InventoryDet);
        lineEditOperType->setObjectName(QStringLiteral("lineEditOperType"));
        lineEditOperType->setEnabled(false);
        lineEditOperType->setMinimumSize(QSize(220, 30));
        lineEditOperType->setMaximumSize(QSize(220, 16777215));

        horizontalLayout_4->addWidget(lineEditOperType);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(InventoryDet);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        lineEditNumber = new QLineEdit(InventoryDet);
        lineEditNumber->setObjectName(QStringLiteral("lineEditNumber"));
        lineEditNumber->setEnabled(false);
        lineEditNumber->setMinimumSize(QSize(220, 30));
        lineEditNumber->setMaximumSize(QSize(220, 16777215));

        horizontalLayout_5->addWidget(lineEditNumber);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(InventoryDet);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_6->addWidget(label_6);

        lineEditChangeCount = new QLineEdit(InventoryDet);
        lineEditChangeCount->setObjectName(QStringLiteral("lineEditChangeCount"));
        lineEditChangeCount->setEnabled(false);
        lineEditChangeCount->setMinimumSize(QSize(220, 30));
        lineEditChangeCount->setMaximumSize(QSize(220, 16777215));

        horizontalLayout_6->addWidget(lineEditChangeCount);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_8 = new QLabel(InventoryDet);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_8->addWidget(label_8);

        lineEditOperPeople = new QLineEdit(InventoryDet);
        lineEditOperPeople->setObjectName(QStringLiteral("lineEditOperPeople"));
        lineEditOperPeople->setEnabled(false);
        lineEditOperPeople->setMinimumSize(QSize(220, 30));
        lineEditOperPeople->setMaximumSize(QSize(220, 16777215));

        horizontalLayout_8->addWidget(lineEditOperPeople);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_7 = new QLabel(InventoryDet);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_7->addWidget(label_7);

        lineEditOperTime = new QLineEdit(InventoryDet);
        lineEditOperTime->setObjectName(QStringLiteral("lineEditOperTime"));
        lineEditOperTime->setEnabled(false);
        lineEditOperTime->setMinimumSize(QSize(220, 30));
        lineEditOperTime->setMaximumSize(QSize(220, 16777215));

        horizontalLayout_7->addWidget(lineEditOperTime);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_9 = new QLabel(InventoryDet);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_9->addWidget(label_9);

        lineEditInvChangeTime = new QLineEdit(InventoryDet);
        lineEditInvChangeTime->setObjectName(QStringLiteral("lineEditInvChangeTime"));
        lineEditInvChangeTime->setEnabled(false);
        lineEditInvChangeTime->setMinimumSize(QSize(220, 30));
        lineEditInvChangeTime->setMaximumSize(QSize(220, 16777215));

        horizontalLayout_9->addWidget(lineEditInvChangeTime);


        verticalLayout->addLayout(horizontalLayout_9);


        retranslateUi(InventoryDet);

        QMetaObject::connectSlotsByName(InventoryDet);
    } // setupUi

    void retranslateUi(QWidget *InventoryDet)
    {
        InventoryDet->setWindowTitle(QApplication::translate("InventoryDet", "Form", 0));
        label->setText(QApplication::translate("InventoryDet", "\344\273\223\345\272\223\345\220\215\347\247\260\357\274\232", 0));
        label_2->setText(QApplication::translate("InventoryDet", "\345\216\237\346\226\231\345\220\215\347\247\260\357\274\232", 0));
        label_3->setText(QApplication::translate("InventoryDet", "\346\235\241\345\275\242\347\240\201\357\274\232", 0));
        label_4->setText(QApplication::translate("InventoryDet", "\346\223\215\344\275\234\347\261\273\345\236\213\357\274\232", 0));
        label_5->setText(QApplication::translate("InventoryDet", "\345\215\225\345\217\267\357\274\232", 0));
        label_6->setText(QApplication::translate("InventoryDet", "\345\217\230\346\233\264\346\225\260\351\207\217\357\274\232", 0));
        label_8->setText(QApplication::translate("InventoryDet", "\346\223\215\344\275\234\344\272\272\357\274\232", 0));
        label_7->setText(QApplication::translate("InventoryDet", "\346\223\215\344\275\234\346\227\266\351\227\264\357\274\232", 0));
        label_9->setText(QApplication::translate("InventoryDet", "\345\272\223\345\255\230\345\217\230\346\233\264\346\227\266\351\227\264\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class InventoryDet: public Ui_InventoryDet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVENTORYDET_H
