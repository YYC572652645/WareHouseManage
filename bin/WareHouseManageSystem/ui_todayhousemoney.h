/********************************************************************************
** Form generated from reading UI file 'todayhousemoney.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TODAYHOUSEMONEY_H
#define UI_TODAYHOUSEMONEY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_todayhousemoney
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QCustomPlot *widgetCustomPlot;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_4;
    QLabel *labelReturnsMoney;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;
    QLabel *labelProfitMoney;
    QLabel *label;
    QLabel *label_5;
    QLabel *labelPurchaseMoney;
    QLabel *labelStorageMoney;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_6;
    QLabel *labelRealMoney;

    void setupUi(QWidget *todayhousemoney)
    {
        if (todayhousemoney->objectName().isEmpty())
            todayhousemoney->setObjectName(QStringLiteral("todayhousemoney"));
        todayhousemoney->resize(571, 244);
        verticalLayout_2 = new QVBoxLayout(todayhousemoney);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, -1, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widgetCustomPlot = new QCustomPlot(todayhousemoney);
        widgetCustomPlot->setObjectName(QStringLiteral("widgetCustomPlot"));

        verticalLayout->addWidget(widgetCustomPlot);

        groupBox = new QGroupBox(todayhousemoney);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        groupBox->setFont(font);
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_5 = new QSpacerItem(120, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 5, 2, 1, 1);

        labelReturnsMoney = new QLabel(groupBox);
        labelReturnsMoney->setObjectName(QStringLiteral("labelReturnsMoney"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(11);
        labelReturnsMoney->setFont(font1);

        gridLayout->addWidget(labelReturnsMoney, 4, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 5, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        label_4->setFont(font2);

        gridLayout->addWidget(label_4, 3, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 1, 1, 1);

        labelProfitMoney = new QLabel(groupBox);
        labelProfitMoney->setObjectName(QStringLiteral("labelProfitMoney"));
        labelProfitMoney->setFont(font1);

        gridLayout->addWidget(labelProfitMoney, 7, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font2);

        gridLayout->addWidget(label, 0, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font2);

        gridLayout->addWidget(label_5, 6, 1, 1, 1);

        labelPurchaseMoney = new QLabel(groupBox);
        labelPurchaseMoney->setObjectName(QStringLiteral("labelPurchaseMoney"));
        labelPurchaseMoney->setFont(font1);

        gridLayout->addWidget(labelPurchaseMoney, 4, 1, 1, 1);

        labelStorageMoney = new QLabel(groupBox);
        labelStorageMoney->setObjectName(QStringLiteral("labelStorageMoney"));
        labelStorageMoney->setFont(font1);

        gridLayout->addWidget(labelStorageMoney, 1, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font2);

        gridLayout->addWidget(label_2, 3, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(120, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 0, 3, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font2);

        gridLayout->addWidget(label_6, 0, 2, 1, 1);

        labelRealMoney = new QLabel(groupBox);
        labelRealMoney->setObjectName(QStringLiteral("labelRealMoney"));
        labelRealMoney->setFont(font1);

        gridLayout->addWidget(labelRealMoney, 1, 2, 1, 1);


        verticalLayout_3->addLayout(gridLayout);


        verticalLayout->addWidget(groupBox);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(todayhousemoney);

        QMetaObject::connectSlotsByName(todayhousemoney);
    } // setupUi

    void retranslateUi(QWidget *todayhousemoney)
    {
        todayhousemoney->setWindowTitle(QApplication::translate("todayhousemoney", "Form", 0));
        groupBox->setTitle(QApplication::translate("todayhousemoney", "\344\273\212\346\227\245\346\212\245\350\241\250\344\277\241\346\201\257", 0));
        labelReturnsMoney->setText(QApplication::translate("todayhousemoney", "0.00\345\205\203", 0));
        label_4->setText(QApplication::translate("todayhousemoney", "\351\200\200\350\264\247\345\207\272\345\272\223\351\207\221\351\242\235", 0));
        labelProfitMoney->setText(QApplication::translate("todayhousemoney", "0.00\345\205\203", 0));
        label->setText(QApplication::translate("todayhousemoney", "\345\205\245\345\272\223\351\207\221\351\242\235", 0));
        label_5->setText(QApplication::translate("todayhousemoney", "\351\224\200\345\224\256\346\257\233\345\210\251\346\266\246", 0));
        labelPurchaseMoney->setText(QApplication::translate("todayhousemoney", "0.00\345\205\203", 0));
        labelStorageMoney->setText(QApplication::translate("todayhousemoney", "0.00\345\205\203", 0));
        label_2->setText(QApplication::translate("todayhousemoney", "\351\224\200\345\224\256\351\207\221\351\242\235", 0));
        label_6->setText(QApplication::translate("todayhousemoney", "\345\256\236\351\231\205\346\266\210\350\200\227\351\207\221\351\242\235", 0));
        labelRealMoney->setText(QApplication::translate("todayhousemoney", "0.00\345\205\203", 0));
    } // retranslateUi

};

namespace Ui {
    class todayhousemoney: public Ui_todayhousemoney {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TODAYHOUSEMONEY_H
