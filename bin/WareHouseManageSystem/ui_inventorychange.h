/********************************************************************************
** Form generated from reading UI file 'inventorychange.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVENTORYCHANGE_H
#define UI_INVENTORYCHANGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InventoryChange
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QWidget *widgetControl;
    QPushButton *pushButtonSelect;
    QPushButton *pushButtonExport;
    QLabel *labelWshe;
    QComboBox *comboBoxWareHouse;
    QLabel *labelTime;
    QComboBox *comboBoxTime;
    QLabel *labelEnd;
    QDateEdit *dateEditEndTime;
    QLabel *labelSelect;
    QLineEdit *lineEditCondition;
    QLabel *labelStart;
    QDateEdit *dateEditStartTime;
    QTableWidget *tableWidgetData;

    void setupUi(QWidget *InventoryChange)
    {
        if (InventoryChange->objectName().isEmpty())
            InventoryChange->setObjectName(QStringLiteral("InventoryChange"));
        InventoryChange->resize(322, 193);
        InventoryChange->setStyleSheet(QLatin1String("QComboBox\n"
"{\n"
"background-color:white;\n"
"}\n"
"QPushButton:hover\n"
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
        verticalLayout_2 = new QVBoxLayout(InventoryChange);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 0, -1, -1);
        widgetControl = new QWidget(InventoryChange);
        widgetControl->setObjectName(QStringLiteral("widgetControl"));
        widgetControl->setMinimumSize(QSize(0, 20));
        pushButtonSelect = new QPushButton(widgetControl);
        pushButtonSelect->setObjectName(QStringLiteral("pushButtonSelect"));
        pushButtonSelect->setGeometry(QRect(399, 15, 70, 16));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\346\237\245\350\257\242.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSelect->setIcon(icon);
        pushButtonExport = new QPushButton(widgetControl);
        pushButtonExport->setObjectName(QStringLiteral("pushButtonExport"));
        pushButtonExport->setGeometry(QRect(475, 15, 69, 16));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/export.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonExport->setIcon(icon1);
        labelWshe = new QLabel(widgetControl);
        labelWshe->setObjectName(QStringLiteral("labelWshe"));
        labelWshe->setGeometry(QRect(22, 12, 42, 16));
        comboBoxWareHouse = new QComboBox(widgetControl);
        comboBoxWareHouse->setObjectName(QStringLiteral("comboBoxWareHouse"));
        comboBoxWareHouse->setGeometry(QRect(70, 12, 100, 22));
        comboBoxWareHouse->setMinimumSize(QSize(100, 0));
        comboBoxWareHouse->setMaximumSize(QSize(120, 16777215));
        labelTime = new QLabel(widgetControl);
        labelTime->setObjectName(QStringLiteral("labelTime"));
        labelTime->setGeometry(QRect(98, 12, 72, 16));
        comboBoxTime = new QComboBox(widgetControl);
        comboBoxTime->setObjectName(QStringLiteral("comboBoxTime"));
        comboBoxTime->setGeometry(QRect(176, 12, 100, 22));
        comboBoxTime->setMinimumSize(QSize(100, 0));
        comboBoxTime->setMaximumSize(QSize(120, 16777215));
        labelEnd = new QLabel(widgetControl);
        labelEnd->setObjectName(QStringLiteral("labelEnd"));
        labelEnd->setGeometry(QRect(249, 12, 72, 16));
        dateEditEndTime = new QDateEdit(widgetControl);
        dateEditEndTime->setObjectName(QStringLiteral("dateEditEndTime"));
        dateEditEndTime->setGeometry(QRect(327, 12, 100, 22));
        dateEditEndTime->setMinimumSize(QSize(100, 0));
        dateEditEndTime->setMaximumSize(QSize(120, 16777215));
        labelSelect = new QLabel(widgetControl);
        labelSelect->setObjectName(QStringLiteral("labelSelect"));
        labelSelect->setGeometry(QRect(325, 17, 72, 16));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelSelect->sizePolicy().hasHeightForWidth());
        labelSelect->setSizePolicy(sizePolicy);
        lineEditCondition = new QLineEdit(widgetControl);
        lineEditCondition->setObjectName(QStringLiteral("lineEditCondition"));
        lineEditCondition->setGeometry(QRect(403, 12, 130, 22));
        lineEditCondition->setMinimumSize(QSize(130, 0));
        lineEditCondition->setMaximumSize(QSize(120, 16777215));
        labelStart = new QLabel(widgetControl);
        labelStart->setObjectName(QStringLiteral("labelStart"));
        labelStart->setGeometry(QRect(174, 12, 72, 16));
        dateEditStartTime = new QDateEdit(widgetControl);
        dateEditStartTime->setObjectName(QStringLiteral("dateEditStartTime"));
        dateEditStartTime->setGeometry(QRect(252, 12, 100, 22));
        dateEditStartTime->setMinimumSize(QSize(100, 0));
        dateEditStartTime->setMaximumSize(QSize(120, 16777215));

        verticalLayout->addWidget(widgetControl);

        tableWidgetData = new QTableWidget(InventoryChange);
        if (tableWidgetData->columnCount() < 2)
            tableWidgetData->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidgetData->setObjectName(QStringLiteral("tableWidgetData"));

        verticalLayout->addWidget(tableWidgetData);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(InventoryChange);

        QMetaObject::connectSlotsByName(InventoryChange);
    } // setupUi

    void retranslateUi(QWidget *InventoryChange)
    {
        InventoryChange->setWindowTitle(QApplication::translate("InventoryChange", "Form", 0));
        pushButtonSelect->setText(QApplication::translate("InventoryChange", " \346\237\245\350\257\242", 0));
        pushButtonExport->setText(QApplication::translate("InventoryChange", " \345\257\274\345\207\272", 0));
        labelWshe->setText(QApplication::translate("InventoryChange", " \344\273\223\345\272\223\357\274\232", 0));
        labelTime->setText(QApplication::translate("InventoryChange", "  \346\237\245\350\257\242\346\227\266\351\227\264\357\274\232", 0));
        labelEnd->setText(QApplication::translate("InventoryChange", "  \347\273\223\346\235\237\346\227\245\346\234\237\357\274\232", 0));
        labelSelect->setText(QApplication::translate("InventoryChange", "  \346\237\245\350\257\242\346\235\241\344\273\266\357\274\232", 0));
        lineEditCondition->setPlaceholderText(QApplication::translate("InventoryChange", "\350\276\223\345\205\245\345\216\237\346\226\231\345\220\215\347\247\260\346\210\226\346\235\241\345\275\242\347\240\201", 0));
        labelStart->setText(QApplication::translate("InventoryChange", "  \345\274\200\345\247\213\346\227\245\346\234\237\357\274\232", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetData->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("InventoryChange", "\345\216\237\346\226\231\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetData->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("InventoryChange", "\346\235\241\345\275\242\347\240\201", 0));
    } // retranslateUi

};

namespace Ui {
    class InventoryChange: public Ui_InventoryChange {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVENTORYCHANGE_H
