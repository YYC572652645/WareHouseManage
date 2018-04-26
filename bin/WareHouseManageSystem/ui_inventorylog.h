/********************************************************************************
** Form generated from reading UI file 'inventorylog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVENTORYLOG_H
#define UI_INVENTORYLOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InventoryLog
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
    QLineEdit *lineEditStartTime;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEditEndTime;
    QLabel *label_18;
    QTableWidget *tableWidget;

    void setupUi(QWidget *InventoryLog)
    {
        if (InventoryLog->objectName().isEmpty())
            InventoryLog->setObjectName(QStringLiteral("InventoryLog"));
        InventoryLog->resize(752, 596);
        verticalLayout = new QVBoxLayout(InventoryLog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(InventoryLog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEditMatName = new QLineEdit(InventoryLog);
        lineEditMatName->setObjectName(QStringLiteral("lineEditMatName"));
        lineEditMatName->setEnabled(false);
        lineEditMatName->setMinimumSize(QSize(220, 30));
        lineEditMatName->setMaximumSize(QSize(220, 30));
        lineEditMatName->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(lineEditMatName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(InventoryLog);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEditBarCode = new QLineEdit(InventoryLog);
        lineEditBarCode->setObjectName(QStringLiteral("lineEditBarCode"));
        lineEditBarCode->setEnabled(false);
        lineEditBarCode->setMinimumSize(QSize(220, 30));
        lineEditBarCode->setMaximumSize(QSize(220, 30));
        lineEditBarCode->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(lineEditBarCode);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(InventoryLog);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEditStartTime = new QLineEdit(InventoryLog);
        lineEditStartTime->setObjectName(QStringLiteral("lineEditStartTime"));
        lineEditStartTime->setEnabled(false);
        lineEditStartTime->setMinimumSize(QSize(220, 30));
        lineEditStartTime->setMaximumSize(QSize(220, 30));
        lineEditStartTime->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_3->addWidget(lineEditStartTime);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(InventoryLog);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEditEndTime = new QLineEdit(InventoryLog);
        lineEditEndTime->setObjectName(QStringLiteral("lineEditEndTime"));
        lineEditEndTime->setEnabled(false);
        lineEditEndTime->setMinimumSize(QSize(220, 30));
        lineEditEndTime->setMaximumSize(QSize(220, 30));
        lineEditEndTime->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_4->addWidget(lineEditEndTime);


        verticalLayout->addLayout(horizontalLayout_4);

        label_18 = new QLabel(InventoryLog);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setMinimumSize(QSize(0, 30));
        label_18->setMaximumSize(QSize(16777215, 30));
        label_18->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"background-color:rgb(180, 85, 100);\n"
"color:white;\n"
"font-size:14px;\n"
"font-weight:bold;\n"
"}"));
        label_18->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(label_18);

        tableWidget = new QTableWidget(InventoryLog);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);


        retranslateUi(InventoryLog);

        QMetaObject::connectSlotsByName(InventoryLog);
    } // setupUi

    void retranslateUi(QWidget *InventoryLog)
    {
        InventoryLog->setWindowTitle(QApplication::translate("InventoryLog", "Form", 0));
        label->setText(QApplication::translate("InventoryLog", "\345\216\237\346\226\231\345\220\215\347\247\260\357\274\232", 0));
        label_2->setText(QApplication::translate("InventoryLog", "\346\235\241\345\275\242\347\240\201\357\274\232", 0));
        label_3->setText(QApplication::translate("InventoryLog", "\345\274\200\345\247\213\346\227\245\346\234\237\357\274\232", 0));
        label_4->setText(QApplication::translate("InventoryLog", "\347\273\223\346\235\237\346\227\245\346\234\237\357\274\232", 0));
        label_18->setText(QApplication::translate("InventoryLog", " \345\272\223\345\255\230\345\217\230\346\233\264\350\256\260\345\275\225", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("InventoryLog", "\346\223\215\344\275\234\347\261\273\345\236\213", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("InventoryLog", "\344\273\223\345\272\223\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("InventoryLog", "\345\217\230\346\233\264\346\225\260\351\207\217", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("InventoryLog", "\345\272\223\345\255\230\345\217\230\346\233\264\346\227\266\351\227\264", 0));
    } // retranslateUi

};

namespace Ui {
    class InventoryLog: public Ui_InventoryLog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVENTORYLOG_H
