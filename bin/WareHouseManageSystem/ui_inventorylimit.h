/********************************************************************************
** Form generated from reading UI file 'inventorylimit.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVENTORYLIMIT_H
#define UI_INVENTORYLIMIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InventoryLimit
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QWidget *widgetControl;
    QPushButton *pushButtonNoSelect;
    QPushButton *pushButtonSetUp;
    QLabel *labelSize;
    QPushButton *pushButtonAllSelect;
    QTableWidget *tableWidget;

    void setupUi(QWidget *InventoryLimit)
    {
        if (InventoryLimit->objectName().isEmpty())
            InventoryLimit->setObjectName(QStringLiteral("InventoryLimit"));
        InventoryLimit->resize(232, 158);
        InventoryLimit->setStyleSheet(QLatin1String("QPushButton:hover\n"
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
"width: 150px;\n"
"border-radius:2px;\n"
"spacing:2px;\n"
"padding: 0px 0px;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(InventoryLimit);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 0, -1, -1);
        widgetControl = new QWidget(InventoryLimit);
        widgetControl->setObjectName(QStringLiteral("widgetControl"));
        widgetControl->setMinimumSize(QSize(0, 20));
        pushButtonNoSelect = new QPushButton(widgetControl);
        pushButtonNoSelect->setObjectName(QStringLiteral("pushButtonNoSelect"));
        pushButtonNoSelect->setGeometry(QRect(171, 31, 150, 16));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\345\205\250\344\270\215\351\200\211.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonNoSelect->setIcon(icon);
        pushButtonSetUp = new QPushButton(widgetControl);
        pushButtonSetUp->setObjectName(QStringLiteral("pushButtonSetUp"));
        pushButtonSetUp->setGeometry(QRect(327, 31, 150, 16));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/image/\347\241\256\350\256\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSetUp->setIcon(icon1);
        labelSize = new QLabel(widgetControl);
        labelSize->setObjectName(QStringLiteral("labelSize"));
        labelSize->setGeometry(QRect(653, 11, 16, 18));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        labelSize->setFont(font);
        pushButtonAllSelect = new QPushButton(widgetControl);
        pushButtonAllSelect->setObjectName(QStringLiteral("pushButtonAllSelect"));
        pushButtonAllSelect->setGeometry(QRect(15, 31, 150, 16));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/image/\346\211\271\351\207\217.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonAllSelect->setIcon(icon2);

        verticalLayout->addWidget(widgetControl);

        tableWidget = new QTableWidget(InventoryLimit);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(InventoryLimit);

        QMetaObject::connectSlotsByName(InventoryLimit);
    } // setupUi

    void retranslateUi(QWidget *InventoryLimit)
    {
        InventoryLimit->setWindowTitle(QApplication::translate("InventoryLimit", "Form", 0));
        pushButtonNoSelect->setText(QApplication::translate("InventoryLimit", " \345\205\250\344\270\215\351\200\211", 0));
        pushButtonSetUp->setText(QApplication::translate("InventoryLimit", " \346\211\271\351\207\217\350\256\276\347\275\256\344\276\233\345\272\224\345\225\206", 0));
        labelSize->setText(QString());
        pushButtonAllSelect->setText(QApplication::translate("InventoryLimit", " \345\205\250\351\200\211", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("InventoryLimit", "\345\216\237\346\226\231\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("InventoryLimit", "\346\235\241\345\275\242\347\240\201", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("InventoryLimit", "\345\272\223\345\255\230\345\215\225\344\275\215", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("InventoryLimit", "\344\270\212\351\231\220", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("InventoryLimit", "\344\270\213\351\231\220", 0));
    } // retranslateUi

};

namespace Ui {
    class InventoryLimit: public Ui_InventoryLimit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVENTORYLIMIT_H
