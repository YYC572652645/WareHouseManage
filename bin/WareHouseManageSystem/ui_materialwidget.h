/********************************************************************************
** Form generated from reading UI file 'materialwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATERIALWIDGET_H
#define UI_MATERIALWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "baseinfomanage/materialsetup/materialcontrol/materialcontrol.h"

QT_BEGIN_NAMESPACE

class Ui_MaterialWidget
{
public:
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QWidget *widgetControl;
    QPushButton *pushButtonAddMaterial;
    QLabel *labelSize;
    QPushButton *pushButtonDeleteMat;
    QPushButton *pushButtonChangeType;
    QPushButton *pushButtonExtend;
    QTableWidget *tableWidget;
    QTabWidget *tabWidget;
    QWidget *tabAddType;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QTreeWidget *treeWidgetCateGory;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonAdd;
    QWidget *tabUnitLibrary;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_5;
    QTableWidget *tableWidgetUnitLibrary;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButtonAddUnit;
    QPushButton *pushButtonDelUnit;
    MaterialControl *tabAddMaterial;
    QVBoxLayout *verticalLayout_7;
    MaterialControl *tabMaterialInfo;
    QVBoxLayout *verticalLayout_3;

    void setupUi(QWidget *MaterialWidget)
    {
        if (MaterialWidget->objectName().isEmpty())
            MaterialWidget->setObjectName(QStringLiteral("MaterialWidget"));
        MaterialWidget->resize(488, 261);
        MaterialWidget->setStyleSheet(QLatin1String("QComboBox {  \n"
"background-color:white;\n"
"		   \n"
" }\n"
"\n"
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
"width: 150px;\n"
"border-radius:2px;\n"
"spacing:2px;\n"
"padding: 0px 0px;\n"
"}"));
        verticalLayout_6 = new QVBoxLayout(MaterialWidget);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, -1, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 0, -1, -1);
        widgetControl = new QWidget(MaterialWidget);
        widgetControl->setObjectName(QStringLiteral("widgetControl"));
        widgetControl->setMinimumSize(QSize(0, 20));
        pushButtonAddMaterial = new QPushButton(widgetControl);
        pushButtonAddMaterial->setObjectName(QStringLiteral("pushButtonAddMaterial"));
        pushButtonAddMaterial->setGeometry(QRect(0, 10, 161, 16));
        pushButtonAddMaterial->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/image/addfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonAddMaterial->setIcon(icon);
        labelSize = new QLabel(widgetControl);
        labelSize->setObjectName(QStringLiteral("labelSize"));
        labelSize->setGeometry(QRect(590, 10, 61, 16));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        labelSize->setFont(font);
        labelSize->setStyleSheet(QStringLiteral(""));
        pushButtonDeleteMat = new QPushButton(widgetControl);
        pushButtonDeleteMat->setObjectName(QStringLiteral("pushButtonDeleteMat"));
        pushButtonDeleteMat->setGeometry(QRect(170, 10, 150, 16));
        pushButtonDeleteMat->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/image/\345\210\240 \351\231\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonDeleteMat->setIcon(icon1);
        pushButtonChangeType = new QPushButton(widgetControl);
        pushButtonChangeType->setObjectName(QStringLiteral("pushButtonChangeType"));
        pushButtonChangeType->setGeometry(QRect(340, 10, 101, 16));
        pushButtonChangeType->setStyleSheet(QStringLiteral(""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/image/\350\260\203\346\225\264.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonChangeType->setIcon(icon2);
        pushButtonExtend = new QPushButton(widgetControl);
        pushButtonExtend->setObjectName(QStringLiteral("pushButtonExtend"));
        pushButtonExtend->setGeometry(QRect(480, 10, 81, 20));
        pushButtonExtend->setStyleSheet(QStringLiteral(""));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/image/export.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonExtend->setIcon(icon3);

        verticalLayout->addWidget(widgetControl);

        tableWidget = new QTableWidget(MaterialWidget);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);


        horizontalLayout_3->addLayout(verticalLayout);

        tabWidget = new QTabWidget(MaterialWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setStyleSheet(QLatin1String("QListWidget::item\n"
"{\n"
"height:40px;\n"
"}\n"
"QTabBar::tab\n"
"{\n"
"min-width:160px;\n"
"color: white;\n"
"background-color:rgb(44, 62, 80);\n"
"border: 0px solid;\n"
"border-top-left-radius: 10px;\n"
"border-top-right-radius: 10px;\n"
"padding:5px;\n"
"}\n"
"\n"
"QTabBar::tab:!selected\n"
"{\n"
"margin-top: 5px;\n"
"}\n"
"\n"
"QTabBar::tab:selected\n"
"{\n"
"color: rgb(230,250,0);\n"
"font-size:12px;\n"
"font-weight:bold;\n"
"}\n"
""));
        tabAddType = new QWidget();
        tabAddType->setObjectName(QStringLiteral("tabAddType"));
        verticalLayout_4 = new QVBoxLayout(tabAddType);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        treeWidgetCateGory = new QTreeWidget(tabAddType);
        treeWidgetCateGory->setObjectName(QStringLiteral("treeWidgetCateGory"));

        verticalLayout_2->addWidget(treeWidgetCateGory);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButtonAdd = new QPushButton(tabAddType);
        pushButtonAdd->setObjectName(QStringLiteral("pushButtonAdd"));
        pushButtonAdd->setStyleSheet(QStringLiteral(""));
        pushButtonAdd->setIcon(icon);

        horizontalLayout_2->addWidget(pushButtonAdd);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_2);

        tabWidget->addTab(tabAddType, QString());
        tabUnitLibrary = new QWidget();
        tabUnitLibrary->setObjectName(QStringLiteral("tabUnitLibrary"));
        verticalLayout_8 = new QVBoxLayout(tabUnitLibrary);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        tableWidgetUnitLibrary = new QTableWidget(tabUnitLibrary);
        if (tableWidgetUnitLibrary->columnCount() < 1)
            tableWidgetUnitLibrary->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetUnitLibrary->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        tableWidgetUnitLibrary->setObjectName(QStringLiteral("tableWidgetUnitLibrary"));

        verticalLayout_5->addWidget(tableWidgetUnitLibrary);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButtonAddUnit = new QPushButton(tabUnitLibrary);
        pushButtonAddUnit->setObjectName(QStringLiteral("pushButtonAddUnit"));
        pushButtonAddUnit->setStyleSheet(QStringLiteral(""));
        pushButtonAddUnit->setIcon(icon);

        horizontalLayout_4->addWidget(pushButtonAddUnit);

        pushButtonDelUnit = new QPushButton(tabUnitLibrary);
        pushButtonDelUnit->setObjectName(QStringLiteral("pushButtonDelUnit"));
        pushButtonDelUnit->setStyleSheet(QStringLiteral(""));
        pushButtonDelUnit->setIcon(icon1);

        horizontalLayout_4->addWidget(pushButtonDelUnit);


        verticalLayout_5->addLayout(horizontalLayout_4);


        verticalLayout_8->addLayout(verticalLayout_5);

        tabWidget->addTab(tabUnitLibrary, QString());
        tabAddMaterial = new MaterialControl();
        tabAddMaterial->setObjectName(QStringLiteral("tabAddMaterial"));
        verticalLayout_7 = new QVBoxLayout(tabAddMaterial);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(tabAddMaterial, QString());
        tabMaterialInfo = new MaterialControl();
        tabMaterialInfo->setObjectName(QStringLiteral("tabMaterialInfo"));
        verticalLayout_3 = new QVBoxLayout(tabMaterialInfo);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(tabMaterialInfo, QString());

        horizontalLayout_3->addWidget(tabWidget);

        horizontalLayout_3->setStretch(0, 6);
        horizontalLayout_3->setStretch(1, 4);

        verticalLayout_6->addLayout(horizontalLayout_3);


        retranslateUi(MaterialWidget);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MaterialWidget);
    } // setupUi

    void retranslateUi(QWidget *MaterialWidget)
    {
        MaterialWidget->setWindowTitle(QApplication::translate("MaterialWidget", "Form", 0));
        pushButtonAddMaterial->setText(QApplication::translate("MaterialWidget", " \346\267\273\345\212\240\345\216\237\346\226\231", 0));
        labelSize->setText(QApplication::translate("MaterialWidget", " \345\220\210\350\256\241\357\274\232", 0));
        pushButtonDeleteMat->setText(QApplication::translate("MaterialWidget", " \345\210\240\351\231\244\345\216\237\346\226\231", 0));
        pushButtonChangeType->setText(QApplication::translate("MaterialWidget", " \345\210\207\346\215\242\345\210\206\347\261\273", 0));
        pushButtonExtend->setText(QApplication::translate("MaterialWidget", " \345\257\274\345\207\272", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MaterialWidget", "\345\216\237\346\226\231ID", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MaterialWidget", "\345\216\237\346\226\231\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MaterialWidget", "\346\235\241\345\275\242\347\240\201", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidgetCateGory->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MaterialWidget", "\345\205\250\351\203\250\345\210\206\347\261\273", 0));
        pushButtonAdd->setText(QApplication::translate("MaterialWidget", " \346\267\273\345\212\240", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabAddType), QApplication::translate("MaterialWidget", "\346\267\273\345\212\240\345\210\206\347\261\273", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetUnitLibrary->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("MaterialWidget", "\345\215\225\344\275\215\345\220\215\347\247\260", 0));
        pushButtonAddUnit->setText(QApplication::translate("MaterialWidget", " \346\267\273\345\212\240", 0));
        pushButtonDelUnit->setText(QApplication::translate("MaterialWidget", " \345\210\240\351\231\244", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabUnitLibrary), QApplication::translate("MaterialWidget", "\345\215\225\344\275\215\345\272\223\347\256\241\347\220\206", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabAddMaterial), QApplication::translate("MaterialWidget", "\346\267\273\345\212\240\345\216\237\346\226\231", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabMaterialInfo), QApplication::translate("MaterialWidget", "\345\216\237\346\226\231\344\277\241\346\201\257", 0));
    } // retranslateUi

};

namespace Ui {
    class MaterialWidget: public Ui_MaterialWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATERIALWIDGET_H
