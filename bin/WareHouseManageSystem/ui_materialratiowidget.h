/********************************************************************************
** Form generated from reading UI file 'materialratiowidget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATERIALRATIOWIDGET_H
#define UI_MATERIALRATIOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MaterialRatioWidget
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidgetData;
    QTabWidget *tabWidgetMaterialRatio;
    QWidget *tabMaterialRatioInfo;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *lineEditNameInfo;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QLineEdit *lineEditWareHouse;
    QListWidget *listWidgetWhse;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_5;
    QLineEdit *lineEditPrice;
    QLabel *label_7;
    QListWidget *listWidgetData;
    QPushButton *pushButtonAddNewMat;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButtonSaveInfo;
    QPushButton *pushButtonCancelInfo;

    void setupUi(QWidget *MaterialRatioWidget)
    {
        if (MaterialRatioWidget->objectName().isEmpty())
            MaterialRatioWidget->setObjectName(QStringLiteral("MaterialRatioWidget"));
        MaterialRatioWidget->resize(982, 627);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MaterialRatioWidget->sizePolicy().hasHeightForWidth());
        MaterialRatioWidget->setSizePolicy(sizePolicy);
        MaterialRatioWidget->setStyleSheet(QLatin1String("QComboBox {  \n"
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
"border-radius:2px;\n"
"width: 150px;\n"
"spacing:2px;\n"
"padding: 0px 0px;\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(MaterialRatioWidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 0, -1, -1);
        treeWidgetData = new QTreeWidget(MaterialRatioWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidgetData->setHeaderItem(__qtreewidgetitem);
        treeWidgetData->setObjectName(QStringLiteral("treeWidgetData"));

        verticalLayout->addWidget(treeWidgetData);


        horizontalLayout_2->addLayout(verticalLayout);

        tabWidgetMaterialRatio = new QTabWidget(MaterialRatioWidget);
        tabWidgetMaterialRatio->setObjectName(QStringLiteral("tabWidgetMaterialRatio"));
        tabMaterialRatioInfo = new QWidget();
        tabMaterialRatioInfo->setObjectName(QStringLiteral("tabMaterialRatioInfo"));
        verticalLayout_5 = new QVBoxLayout(tabMaterialRatioInfo);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_6 = new QLabel(tabMaterialRatioInfo);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(0, 30));
        label_6->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_6->setFont(font);
        label_6->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"background-color:rgb(180, 85, 100);\n"
"color:white;\n"
"font-size:14px;\n"
"font-weight:bold;\n"
"}"));
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(tabMaterialRatioInfo);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_2);

        lineEditNameInfo = new QLineEdit(tabMaterialRatioInfo);
        lineEditNameInfo->setObjectName(QStringLiteral("lineEditNameInfo"));
        lineEditNameInfo->setEnabled(false);
        lineEditNameInfo->setMinimumSize(QSize(200, 0));
        lineEditNameInfo->setMaximumSize(QSize(200, 16777215));
        lineEditNameInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_4->addWidget(lineEditNameInfo);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_3 = new QLabel(tabMaterialRatioInfo);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_3);

        lineEditWareHouse = new QLineEdit(tabMaterialRatioInfo);
        lineEditWareHouse->setObjectName(QStringLiteral("lineEditWareHouse"));
        lineEditWareHouse->setEnabled(false);
        lineEditWareHouse->setMinimumSize(QSize(200, 0));
        lineEditWareHouse->setMaximumSize(QSize(200, 16777215));
        lineEditWareHouse->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_6->addWidget(lineEditWareHouse);


        verticalLayout_2->addLayout(horizontalLayout_6);

        listWidgetWhse = new QListWidget(tabMaterialRatioInfo);
        listWidgetWhse->setObjectName(QStringLiteral("listWidgetWhse"));

        verticalLayout_2->addWidget(listWidgetWhse);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_4 = new QLabel(tabMaterialRatioInfo);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_4->setWordWrap(false);

        horizontalLayout_7->addWidget(label_4);

        checkBox = new QCheckBox(tabMaterialRatioInfo);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setMinimumSize(QSize(30, 0));
        checkBox->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_7->addWidget(checkBox);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_5 = new QLabel(tabMaterialRatioInfo);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_8->addWidget(label_5);

        lineEditPrice = new QLineEdit(tabMaterialRatioInfo);
        lineEditPrice->setObjectName(QStringLiteral("lineEditPrice"));
        lineEditPrice->setMinimumSize(QSize(200, 30));
        lineEditPrice->setMaximumSize(QSize(200, 30));
        lineEditPrice->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_8->addWidget(lineEditPrice);


        verticalLayout_2->addLayout(horizontalLayout_8);

        label_7 = new QLabel(tabMaterialRatioInfo);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(0, 30));
        label_7->setMaximumSize(QSize(16777215, 30));
        label_7->setFont(font);
        label_7->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"background-color:rgb(180, 85, 100);\n"
"color:white;\n"
"font-size:14px;\n"
"font-weight:bold;\n"
"}"));
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_7);

        listWidgetData = new QListWidget(tabMaterialRatioInfo);
        listWidgetData->setObjectName(QStringLiteral("listWidgetData"));

        verticalLayout_2->addWidget(listWidgetData);

        pushButtonAddNewMat = new QPushButton(tabMaterialRatioInfo);
        pushButtonAddNewMat->setObjectName(QStringLiteral("pushButtonAddNewMat"));
        pushButtonAddNewMat->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/image/addfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonAddNewMat->setIcon(icon);

        verticalLayout_2->addWidget(pushButtonAddNewMat);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButtonSaveInfo = new QPushButton(tabMaterialRatioInfo);
        pushButtonSaveInfo->setObjectName(QStringLiteral("pushButtonSaveInfo"));
        pushButtonSaveInfo->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSaveInfo->setIcon(icon1);

        horizontalLayout_5->addWidget(pushButtonSaveInfo);

        pushButtonCancelInfo = new QPushButton(tabMaterialRatioInfo);
        pushButtonCancelInfo->setObjectName(QStringLiteral("pushButtonCancelInfo"));
        pushButtonCancelInfo->setStyleSheet(QStringLiteral(""));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancelInfo->setIcon(icon2);

        horizontalLayout_5->addWidget(pushButtonCancelInfo);


        verticalLayout_2->addLayout(horizontalLayout_5);


        verticalLayout_5->addLayout(verticalLayout_2);

        tabWidgetMaterialRatio->addTab(tabMaterialRatioInfo, QString());

        horizontalLayout_2->addWidget(tabWidgetMaterialRatio);

        horizontalLayout_2->setStretch(0, 6);
        horizontalLayout_2->setStretch(1, 4);

        verticalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(MaterialRatioWidget);

        QMetaObject::connectSlotsByName(MaterialRatioWidget);
    } // setupUi

    void retranslateUi(QWidget *MaterialRatioWidget)
    {
        MaterialRatioWidget->setWindowTitle(QApplication::translate("MaterialRatioWidget", "Form", 0));
        label_6->setText(QApplication::translate("MaterialRatioWidget", " \345\237\272\346\234\254\344\277\241\346\201\257", 0));
        label_2->setText(QApplication::translate("MaterialRatioWidget", " \345\225\206\345\223\201\345\220\215\347\247\260\357\274\232", 0));
        lineEditNameInfo->setPlaceholderText(QApplication::translate("MaterialRatioWidget", "\345\277\205\345\241\253", 0));
        label_3->setText(QApplication::translate("MaterialRatioWidget", " \345\207\272\345\223\201\344\273\223\345\272\223\357\274\232", 0));
        lineEditWareHouse->setPlaceholderText(QApplication::translate("MaterialRatioWidget", "\345\277\205\345\241\253", 0));
        label_4->setText(QApplication::translate("MaterialRatioWidget", " \346\240\271\346\215\256\345\212\240\345\267\245\345\216\237\346\226\231\350\256\241\347\256\227\346\210\220\346\234\254\344\273\267\357\274\232", 0));
        checkBox->setText(QString());
        label_5->setText(QApplication::translate("MaterialRatioWidget", " \346\210\220\346\234\254\344\273\267\357\274\232", 0));
        lineEditPrice->setPlaceholderText(QApplication::translate("MaterialRatioWidget", "\345\277\205\345\241\253", 0));
        label_7->setText(QApplication::translate("MaterialRatioWidget", " \346\255\244\345\225\206\345\223\201\345\212\240\345\267\245\351\234\200\350\246\201\347\232\204\345\216\237\346\226\231", 0));
        pushButtonAddNewMat->setText(QApplication::translate("MaterialRatioWidget", " \346\267\273\345\212\240\346\226\260\345\216\237\346\226\231", 0));
        pushButtonSaveInfo->setText(QApplication::translate("MaterialRatioWidget", " \344\277\235\345\255\230", 0));
        pushButtonCancelInfo->setText(QApplication::translate("MaterialRatioWidget", " \345\217\226\346\266\210", 0));
        tabWidgetMaterialRatio->setTabText(tabWidgetMaterialRatio->indexOf(tabMaterialRatioInfo), QApplication::translate("MaterialRatioWidget", "\345\225\206\345\223\201\344\277\241\346\201\257", 0));
    } // retranslateUi

};

namespace Ui {
    class MaterialRatioWidget: public Ui_MaterialRatioWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATERIALRATIOWIDGET_H
