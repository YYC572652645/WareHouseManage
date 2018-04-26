/********************************************************************************
** Form generated from reading UI file 'warehousewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAREHOUSEWIDGET_H
#define UI_WAREHOUSEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WareHouseWidget
{
public:
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QWidget *widgetControl;
    QPushButton *pushButtonAddWareHouse;
    QLabel *labelSize;
    QTableWidget *tableWidgetWareHouse;
    QTabWidget *tabWidgetWareHouse;
    QWidget *tabAddWareHouse;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *lineEditName;
    QLabel *labelAddType;
    QListWidget *listWidgetAddMaterial;
    QPushButton *pushButtonAddSpType;
    QLabel *label_4;
    QListWidget *listWidgetAddExten;
    QPushButton *pushButtonAddSp;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonCancel;
    QWidget *tabWareHouseInfo;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *lineEditNameInfo;
    QLabel *labelTypeInfo;
    QListWidget *listWidgetMaterialInfo;
    QPushButton *pushButtonAddSpTypeInfo;
    QLabel *label_8;
    QListWidget *listWidgetExtenInfo;
    QPushButton *pushButtonAddSpInfo;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButtonSaveInfo;
    QPushButton *pushButtonDelWareHouse;
    QPushButton *pushButtonCancelInfo;

    void setupUi(QWidget *WareHouseWidget)
    {
        if (WareHouseWidget->objectName().isEmpty())
            WareHouseWidget->setObjectName(QStringLiteral("WareHouseWidget"));
        WareHouseWidget->resize(596, 384);
        WareHouseWidget->setStyleSheet(QLatin1String("QPushButton:hover\n"
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
        verticalLayout_7 = new QVBoxLayout(WareHouseWidget);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(-1, -1, -1, 0);
        groupBox = new QGroupBox(WareHouseWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setStyleSheet(QStringLiteral(""));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 0, -1, -1);
        widgetControl = new QWidget(groupBox);
        widgetControl->setObjectName(QStringLiteral("widgetControl"));
        widgetControl->setMinimumSize(QSize(0, 20));
        pushButtonAddWareHouse = new QPushButton(widgetControl);
        pushButtonAddWareHouse->setObjectName(QStringLiteral("pushButtonAddWareHouse"));
        pushButtonAddWareHouse->setGeometry(QRect(5, 23, 150, 16));
        pushButtonAddWareHouse->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/image/addfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonAddWareHouse->setIcon(icon);
        labelSize = new QLabel(widgetControl);
        labelSize->setObjectName(QStringLiteral("labelSize"));
        labelSize->setGeometry(QRect(170, 20, 16, 18));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        labelSize->setFont(font);

        verticalLayout->addWidget(widgetControl);

        tableWidgetWareHouse = new QTableWidget(groupBox);
        if (tableWidgetWareHouse->columnCount() < 1)
            tableWidgetWareHouse->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetWareHouse->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tableWidgetWareHouse->setObjectName(QStringLiteral("tableWidgetWareHouse"));
        tableWidgetWareHouse->setTextElideMode(Qt::ElideRight);

        verticalLayout->addWidget(tableWidgetWareHouse);


        verticalLayout_4->addLayout(verticalLayout);


        horizontalLayout_6->addWidget(groupBox);

        tabWidgetWareHouse = new QTabWidget(WareHouseWidget);
        tabWidgetWareHouse->setObjectName(QStringLiteral("tabWidgetWareHouse"));
        tabAddWareHouse = new QWidget();
        tabAddWareHouse->setObjectName(QStringLiteral("tabAddWareHouse"));
        verticalLayout_3 = new QVBoxLayout(tabAddWareHouse);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(3, 0, 3, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_3 = new QLabel(tabAddWareHouse);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(0, 30));
        label_3->setMaximumSize(QSize(16777215, 30));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);
        label_3->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"background-color:rgb(180, 85, 100);\n"
"color:white;\n"
"font-size:14px;\n"
"font-weight:bold;\n"
"}"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(tabAddWareHouse);
        label->setObjectName(QStringLiteral("label"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label);

        lineEditName = new QLineEdit(tabAddWareHouse);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));
        lineEditName->setMinimumSize(QSize(200, 0));
        lineEditName->setMaximumSize(QSize(200, 30));

        horizontalLayout_3->addWidget(lineEditName);


        verticalLayout_2->addLayout(horizontalLayout_3);

        labelAddType = new QLabel(tabAddWareHouse);
        labelAddType->setObjectName(QStringLiteral("labelAddType"));
        labelAddType->setMinimumSize(QSize(0, 30));
        labelAddType->setMaximumSize(QSize(16777215, 30));
        labelAddType->setFont(font1);
        labelAddType->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"background-color:rgb(180, 85, 100);\n"
"color:white;\n"
"font-size:14px;\n"
"font-weight:bold;\n"
"}"));
        labelAddType->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(labelAddType);

        listWidgetAddMaterial = new QListWidget(tabAddWareHouse);
        listWidgetAddMaterial->setObjectName(QStringLiteral("listWidgetAddMaterial"));
        listWidgetAddMaterial->setStyleSheet(QLatin1String("QPushButton:hover\n"
"{\n"
"background-color: rgb(180, 85, 100);\n"
"border-radius:5px;\n"
"color:white;\n"
"}\n"
"\n"
"QPushButton:hover:pressed\n"
"{\n"
"background-color:rgb(180, 85, 100);\n"
"border-radius:5px;\n"
"color:white;\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"background-color:rgb(100, 85, 80);\n"
"color:white;\n"
"border-radius:5px;\n"
"height: 20px;\n"
"min-width: 30px;\n"
"spacing: 10px;\n"
"padding: 0px 0px;\n"
"}"));
        listWidgetAddMaterial->setAutoScrollMargin(16);
        listWidgetAddMaterial->setResizeMode(QListView::Adjust);

        verticalLayout_2->addWidget(listWidgetAddMaterial);

        pushButtonAddSpType = new QPushButton(tabAddWareHouse);
        pushButtonAddSpType->setObjectName(QStringLiteral("pushButtonAddSpType"));
        pushButtonAddSpType->setStyleSheet(QStringLiteral(""));
        pushButtonAddSpType->setIcon(icon);

        verticalLayout_2->addWidget(pushButtonAddSpType);

        label_4 = new QLabel(tabAddWareHouse);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(0, 30));
        label_4->setMaximumSize(QSize(16777215, 30));
        label_4->setFont(font1);
        label_4->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"background-color:rgb(180, 85, 100);\n"
"color:white;\n"
"font-size:14px;\n"
"font-weight:bold;\n"
"}"));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_4);

        listWidgetAddExten = new QListWidget(tabAddWareHouse);
        listWidgetAddExten->setObjectName(QStringLiteral("listWidgetAddExten"));
        listWidgetAddExten->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-color:transparent;\n"
"}"));

        verticalLayout_2->addWidget(listWidgetAddExten);

        pushButtonAddSp = new QPushButton(tabAddWareHouse);
        pushButtonAddSp->setObjectName(QStringLiteral("pushButtonAddSp"));
        pushButtonAddSp->setStyleSheet(QStringLiteral(""));
        pushButtonAddSp->setIcon(icon);

        verticalLayout_2->addWidget(pushButtonAddSp);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButtonSave = new QPushButton(tabAddWareHouse);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        pushButtonSave->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSave->setIcon(icon1);

        horizontalLayout_2->addWidget(pushButtonSave);

        pushButtonCancel = new QPushButton(tabAddWareHouse);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setStyleSheet(QStringLiteral(""));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon2);

        horizontalLayout_2->addWidget(pushButtonCancel);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout_2);

        tabWidgetWareHouse->addTab(tabAddWareHouse, QString());
        tabWareHouseInfo = new QWidget();
        tabWareHouseInfo->setObjectName(QStringLiteral("tabWareHouseInfo"));
        verticalLayout_6 = new QVBoxLayout(tabWareHouseInfo);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(3, 0, 3, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_6 = new QLabel(tabWareHouseInfo);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(0, 30));
        label_6->setMaximumSize(QSize(16777215, 30));
        label_6->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"background-color:rgb(180, 85, 100);\n"
"color:white;\n"
"font-size:14px;\n"
"font-weight:bold;\n"
"}"));
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_5->addWidget(label_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(tabWareHouseInfo);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_2);

        lineEditNameInfo = new QLineEdit(tabWareHouseInfo);
        lineEditNameInfo->setObjectName(QStringLiteral("lineEditNameInfo"));
        lineEditNameInfo->setMinimumSize(QSize(200, 0));
        lineEditNameInfo->setMaximumSize(QSize(200, 30));

        horizontalLayout_4->addWidget(lineEditNameInfo);


        verticalLayout_5->addLayout(horizontalLayout_4);

        labelTypeInfo = new QLabel(tabWareHouseInfo);
        labelTypeInfo->setObjectName(QStringLiteral("labelTypeInfo"));
        labelTypeInfo->setMinimumSize(QSize(0, 30));
        labelTypeInfo->setMaximumSize(QSize(16777215, 30));
        labelTypeInfo->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"background-color:rgb(180, 85, 100);\n"
"color:white;\n"
"font-size:14px;\n"
"font-weight:bold;\n"
"}"));
        labelTypeInfo->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_5->addWidget(labelTypeInfo);

        listWidgetMaterialInfo = new QListWidget(tabWareHouseInfo);
        listWidgetMaterialInfo->setObjectName(QStringLiteral("listWidgetMaterialInfo"));
        listWidgetMaterialInfo->setStyleSheet(QStringLiteral(""));
        listWidgetMaterialInfo->setAutoScrollMargin(16);
        listWidgetMaterialInfo->setResizeMode(QListView::Adjust);

        verticalLayout_5->addWidget(listWidgetMaterialInfo);

        pushButtonAddSpTypeInfo = new QPushButton(tabWareHouseInfo);
        pushButtonAddSpTypeInfo->setObjectName(QStringLiteral("pushButtonAddSpTypeInfo"));
        pushButtonAddSpTypeInfo->setStyleSheet(QStringLiteral(""));
        pushButtonAddSpTypeInfo->setIcon(icon);

        verticalLayout_5->addWidget(pushButtonAddSpTypeInfo);

        label_8 = new QLabel(tabWareHouseInfo);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(0, 30));
        label_8->setMaximumSize(QSize(16777215, 30));
        label_8->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"background-color:rgb(180, 85, 100);\n"
"color:white;\n"
"font-size:14px;\n"
"font-weight:bold;\n"
"}"));
        label_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_5->addWidget(label_8);

        listWidgetExtenInfo = new QListWidget(tabWareHouseInfo);
        listWidgetExtenInfo->setObjectName(QStringLiteral("listWidgetExtenInfo"));
        listWidgetExtenInfo->setStyleSheet(QStringLiteral(""));

        verticalLayout_5->addWidget(listWidgetExtenInfo);

        pushButtonAddSpInfo = new QPushButton(tabWareHouseInfo);
        pushButtonAddSpInfo->setObjectName(QStringLiteral("pushButtonAddSpInfo"));
        pushButtonAddSpInfo->setStyleSheet(QStringLiteral(""));
        pushButtonAddSpInfo->setIcon(icon);

        verticalLayout_5->addWidget(pushButtonAddSpInfo);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButtonSaveInfo = new QPushButton(tabWareHouseInfo);
        pushButtonSaveInfo->setObjectName(QStringLiteral("pushButtonSaveInfo"));
        pushButtonSaveInfo->setStyleSheet(QStringLiteral(""));
        pushButtonSaveInfo->setIcon(icon1);

        horizontalLayout_5->addWidget(pushButtonSaveInfo);

        pushButtonDelWareHouse = new QPushButton(tabWareHouseInfo);
        pushButtonDelWareHouse->setObjectName(QStringLiteral("pushButtonDelWareHouse"));
        pushButtonDelWareHouse->setStyleSheet(QStringLiteral(""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/image/\345\210\240 \351\231\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonDelWareHouse->setIcon(icon3);

        horizontalLayout_5->addWidget(pushButtonDelWareHouse);

        pushButtonCancelInfo = new QPushButton(tabWareHouseInfo);
        pushButtonCancelInfo->setObjectName(QStringLiteral("pushButtonCancelInfo"));
        pushButtonCancelInfo->setStyleSheet(QStringLiteral(""));
        pushButtonCancelInfo->setIcon(icon2);

        horizontalLayout_5->addWidget(pushButtonCancelInfo);


        verticalLayout_5->addLayout(horizontalLayout_5);


        verticalLayout_6->addLayout(verticalLayout_5);

        tabWidgetWareHouse->addTab(tabWareHouseInfo, QString());

        horizontalLayout_6->addWidget(tabWidgetWareHouse);

        horizontalLayout_6->setStretch(0, 6);
        horizontalLayout_6->setStretch(1, 4);

        verticalLayout_7->addLayout(horizontalLayout_6);


        retranslateUi(WareHouseWidget);

        tabWidgetWareHouse->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(WareHouseWidget);
    } // setupUi

    void retranslateUi(QWidget *WareHouseWidget)
    {
        WareHouseWidget->setWindowTitle(QApplication::translate("WareHouseWidget", "Form", 0));
        groupBox->setTitle(QString());
        pushButtonAddWareHouse->setText(QApplication::translate("WareHouseWidget", " \346\267\273\345\212\240\344\273\223\345\272\223", 0));
        labelSize->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidgetWareHouse->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("WareHouseWidget", "\344\273\223\345\272\223\345\210\227\350\241\250", 0));
        label_3->setText(QApplication::translate("WareHouseWidget", " \345\237\272\346\234\254\344\277\241\346\201\257", 0));
        label->setText(QApplication::translate("WareHouseWidget", "\344\273\223\345\272\223\345\220\215\347\247\260\357\274\232", 0));
        lineEditName->setPlaceholderText(QApplication::translate("WareHouseWidget", "\345\277\205\345\241\253", 0));
        labelAddType->setText(QApplication::translate("WareHouseWidget", " \346\255\244\344\273\223\345\272\223\345\207\272\345\223\201\347\232\204\345\225\206\345\223\201\345\210\206\347\261\273", 0));
        pushButtonAddSpType->setText(QApplication::translate("WareHouseWidget", " \346\267\273\345\212\240\345\225\206\345\223\201\345\210\206\347\261\273", 0));
        label_4->setText(QApplication::translate("WareHouseWidget", " \346\255\244\344\273\223\345\272\223\345\207\272\345\223\201\347\232\204\345\225\206\345\223\201", 0));
        pushButtonAddSp->setText(QApplication::translate("WareHouseWidget", " \346\267\273\345\212\240\345\225\206\345\223\201", 0));
        pushButtonSave->setText(QApplication::translate("WareHouseWidget", " \344\277\235\345\255\230", 0));
        pushButtonCancel->setText(QApplication::translate("WareHouseWidget", " \345\217\226\346\266\210", 0));
        tabWidgetWareHouse->setTabText(tabWidgetWareHouse->indexOf(tabAddWareHouse), QApplication::translate("WareHouseWidget", "\346\267\273\345\212\240\344\273\223\345\272\223", 0));
        label_6->setText(QApplication::translate("WareHouseWidget", " \345\237\272\346\234\254\344\277\241\346\201\257", 0));
        label_2->setText(QApplication::translate("WareHouseWidget", " \344\273\223\345\272\223\345\220\215\347\247\260\357\274\232", 0));
        lineEditNameInfo->setPlaceholderText(QApplication::translate("WareHouseWidget", "\345\277\205\345\241\253", 0));
        labelTypeInfo->setText(QApplication::translate("WareHouseWidget", " \346\255\244\344\273\223\345\272\223\345\207\272\345\223\201\347\232\204\345\225\206\345\223\201\345\210\206\347\261\273", 0));
        pushButtonAddSpTypeInfo->setText(QApplication::translate("WareHouseWidget", " \346\267\273\345\212\240\345\225\206\345\223\201\345\210\206\347\261\273", 0));
        label_8->setText(QApplication::translate("WareHouseWidget", " \346\255\244\344\273\223\345\272\223\345\207\272\345\223\201\347\232\204\345\225\206\345\223\201", 0));
        pushButtonAddSpInfo->setText(QApplication::translate("WareHouseWidget", " \346\267\273\345\212\240\345\225\206\345\223\201", 0));
        pushButtonSaveInfo->setText(QApplication::translate("WareHouseWidget", " \344\277\235\345\255\230", 0));
        pushButtonDelWareHouse->setText(QApplication::translate("WareHouseWidget", " \345\210\240\351\231\244\344\273\223\345\272\223", 0));
        pushButtonCancelInfo->setText(QApplication::translate("WareHouseWidget", " \345\217\226\346\266\210", 0));
        tabWidgetWareHouse->setTabText(tabWidgetWareHouse->indexOf(tabWareHouseInfo), QApplication::translate("WareHouseWidget", "\344\273\223\345\272\223\344\277\241\346\201\257", 0));
    } // retranslateUi

};

namespace Ui {
    class WareHouseWidget: public Ui_WareHouseWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAREHOUSEWIDGET_H
