/********************************************************************************
** Form generated from reading UI file 'administermanage.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINISTERMANAGE_H
#define UI_ADMINISTERMANAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdministerManage
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonAdd;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tableWidgetData;

    void setupUi(QWidget *AdministerManage)
    {
        if (AdministerManage->objectName().isEmpty())
            AdministerManage->setObjectName(QStringLiteral("AdministerManage"));
        AdministerManage->resize(528, 387);
        AdministerManage->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(AdministerManage);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButtonAdd = new QPushButton(AdministerManage);
        pushButtonAdd->setObjectName(QStringLiteral("pushButtonAdd"));
        pushButtonAdd->setMinimumSize(QSize(0, 30));
        pushButtonAdd->setStyleSheet(QLatin1String("QPushButton:hover\n"
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
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/image/addfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonAdd->setIcon(icon);

        horizontalLayout->addWidget(pushButtonAdd);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        tableWidgetData = new QTableWidget(AdministerManage);
        if (tableWidgetData->columnCount() < 4)
            tableWidgetData->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidgetData->setObjectName(QStringLiteral("tableWidgetData"));
        tableWidgetData->setStyleSheet(QLatin1String("QPushButton:hover\n"
"{\n"
"font-weight:bold;\n"
"}\n"
"\n"
"QPushButton:hover:pressed\n"
"{\n"
"font-weight:bold;\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"background-color:transparent;\n"
"border-radius:2px;\n"
"spacing:2px;\n"
"padding: 0px 0px;\n"
"max-width:70px;\n"
"}"));

        verticalLayout->addWidget(tableWidgetData);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(AdministerManage);

        QMetaObject::connectSlotsByName(AdministerManage);
    } // setupUi

    void retranslateUi(QWidget *AdministerManage)
    {
        AdministerManage->setWindowTitle(QApplication::translate("AdministerManage", "Form", 0));
        pushButtonAdd->setText(QApplication::translate("AdministerManage", "\346\267\273\345\212\240", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetData->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("AdministerManage", "\347\256\241\347\220\206\345\221\230ID", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetData->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("AdministerManage", "\347\256\241\347\220\206\345\221\230\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetData->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("AdministerManage", "\346\217\217\350\277\260", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetData->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("AdministerManage", "\346\223\215\344\275\234", 0));
    } // retranslateUi

};

namespace Ui {
    class AdministerManage: public Ui_AdministerManage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINISTERMANAGE_H
