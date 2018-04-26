/********************************************************************************
** Form generated from reading UI file 'realtimeinventory.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REALTIMEINVENTORY_H
#define UI_REALTIMEINVENTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RealTimeInventory
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonExport;
    QSpacerItem *horizontalSpacer;
    QLabel *labelSize;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *tableWidgetData;

    void setupUi(QWidget *RealTimeInventory)
    {
        if (RealTimeInventory->objectName().isEmpty())
            RealTimeInventory->setObjectName(QStringLiteral("RealTimeInventory"));
        RealTimeInventory->resize(382, 240);
        RealTimeInventory->setStyleSheet(QLatin1String("QPushButton:hover\n"
"{\n"
"background-color: rgb(180, 85, 100);\n"
"color:white;\n"
"}\n"
"\n"
"QPushButton:hover:pressed\n"
"{\n"
"background-color:rgb(180, 85, 100);\n"
"color:white;\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"background-color:rgb(84, 115, 135);\n"
"color:white;\n"
"font-size:12px;\n"
"width: 100px;\n"
"border-radius:2px;\n"
"spacing:2px;\n"
"padding: 0px 0px;\n"
"}"));
        verticalLayout = new QVBoxLayout(RealTimeInventory);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(RealTimeInventory);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, -1, -1, -1);
        pushButtonExport = new QPushButton(widget);
        pushButtonExport->setObjectName(QStringLiteral("pushButtonExport"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/image/export.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonExport->setIcon(icon);

        horizontalLayout->addWidget(pushButtonExport);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        labelSize = new QLabel(widget);
        labelSize->setObjectName(QStringLiteral("labelSize"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        labelSize->setFont(font);

        horizontalLayout->addWidget(labelSize);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addWidget(widget);

        tableWidgetData = new QTableWidget(RealTimeInventory);
        if (tableWidgetData->columnCount() < 6)
            tableWidgetData->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidgetData->setObjectName(QStringLiteral("tableWidgetData"));

        verticalLayout->addWidget(tableWidgetData);


        retranslateUi(RealTimeInventory);

        QMetaObject::connectSlotsByName(RealTimeInventory);
    } // setupUi

    void retranslateUi(QWidget *RealTimeInventory)
    {
        RealTimeInventory->setWindowTitle(QApplication::translate("RealTimeInventory", "Form", 0));
        pushButtonExport->setText(QApplication::translate("RealTimeInventory", " \345\257\274\345\207\272", 0));
        labelSize->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidgetData->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("RealTimeInventory", "\345\216\237\346\226\231\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetData->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("RealTimeInventory", "\346\235\241\345\275\242\347\240\201", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetData->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("RealTimeInventory", "\345\272\223\345\255\230\351\207\221\351\242\235", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetData->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("RealTimeInventory", "\345\272\223\345\255\230\346\225\260", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetData->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("RealTimeInventory", "\345\215\225\344\275\215", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetData->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("RealTimeInventory", "\346\217\220\347\244\272", 0));
    } // retranslateUi

};

namespace Ui {
    class RealTimeInventory: public Ui_RealTimeInventory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REALTIMEINVENTORY_H
