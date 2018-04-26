/********************************************************************************
** Form generated from reading UI file 'materialretinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATERIALRETINFO_H
#define UI_MATERIALRETINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_materialretinfo
{
public:
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QScrollArea *scrollAreaSide;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_19;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditMatName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditBarCode;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labelNowNumber;
    QLineEdit *lineEditWareHouse;
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelUnit;
    QComboBox *comboBoxUnit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelUnitPrice;
    QDoubleSpinBox *spinBoxPrice;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelNumber;
    QDoubleSpinBox *spinBoxNumber;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEditTotalMoney;
    QHBoxLayout *horizontalLayout_9;
    QLabel *labelNowNumber_2;
    QLineEdit *lineEditReason;
    QLabel *labelSide;
    QPushButton *pushButtonAddNew;
    QWidget *widgetControl;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonDel;
    QPushButton *pushButtonCancel;

    void setupUi(QWidget *materialretinfo)
    {
        if (materialretinfo->objectName().isEmpty())
            materialretinfo->setObjectName(QStringLiteral("materialretinfo"));
        materialretinfo->resize(535, 656);
        verticalLayout_3 = new QVBoxLayout(materialretinfo);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_2);

        scrollAreaSide = new QScrollArea(materialretinfo);
        scrollAreaSide->setObjectName(QStringLiteral("scrollAreaSide"));
        scrollAreaSide->setMinimumSize(QSize(0, 220));
        scrollAreaSide->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        scrollAreaSide->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 533, 592));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_19 = new QLabel(scrollAreaWidgetContents);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setMinimumSize(QSize(0, 30));
        label_19->setMaximumSize(QSize(16777215, 30));
        label_19->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"background-color:rgb(180, 85, 100);\n"
"color:white;\n"
"font-size:14px;\n"
"font-weight:bold;\n"
"}"));
        label_19->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(label_19);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEditMatName = new QLineEdit(scrollAreaWidgetContents);
        lineEditMatName->setObjectName(QStringLiteral("lineEditMatName"));
        lineEditMatName->setEnabled(false);
        lineEditMatName->setMinimumSize(QSize(220, 30));
        lineEditMatName->setMaximumSize(QSize(220, 16777215));
        lineEditMatName->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(lineEditMatName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEditBarCode = new QLineEdit(scrollAreaWidgetContents);
        lineEditBarCode->setObjectName(QStringLiteral("lineEditBarCode"));
        lineEditBarCode->setEnabled(false);
        lineEditBarCode->setMinimumSize(QSize(220, 30));
        lineEditBarCode->setMaximumSize(QSize(220, 16777215));
        lineEditBarCode->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(lineEditBarCode);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        labelNowNumber = new QLabel(scrollAreaWidgetContents);
        labelNowNumber->setObjectName(QStringLiteral("labelNowNumber"));

        horizontalLayout_6->addWidget(labelNowNumber);

        lineEditWareHouse = new QLineEdit(scrollAreaWidgetContents);
        lineEditWareHouse->setObjectName(QStringLiteral("lineEditWareHouse"));
        lineEditWareHouse->setEnabled(false);
        lineEditWareHouse->setMinimumSize(QSize(220, 30));
        lineEditWareHouse->setMaximumSize(QSize(220, 16777215));
        lineEditWareHouse->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_6->addWidget(lineEditWareHouse);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        labelUnit = new QLabel(scrollAreaWidgetContents);
        labelUnit->setObjectName(QStringLiteral("labelUnit"));

        horizontalLayout_7->addWidget(labelUnit);

        comboBoxUnit = new QComboBox(scrollAreaWidgetContents);
        comboBoxUnit->setObjectName(QStringLiteral("comboBoxUnit"));
        comboBoxUnit->setMinimumSize(QSize(220, 30));
        comboBoxUnit->setMaximumSize(QSize(200, 16777215));
        comboBoxUnit->setStyleSheet(QLatin1String("background-color:white;\n"
""));
        comboBoxUnit->setMinimumContentsLength(0);
        comboBoxUnit->setDuplicatesEnabled(false);

        horizontalLayout_7->addWidget(comboBoxUnit);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelUnitPrice = new QLabel(scrollAreaWidgetContents);
        labelUnitPrice->setObjectName(QStringLiteral("labelUnitPrice"));

        horizontalLayout_3->addWidget(labelUnitPrice);

        spinBoxPrice = new QDoubleSpinBox(scrollAreaWidgetContents);
        spinBoxPrice->setObjectName(QStringLiteral("spinBoxPrice"));
        spinBoxPrice->setMinimumSize(QSize(220, 30));
        spinBoxPrice->setMaximumSize(QSize(220, 30));
        spinBoxPrice->setFocusPolicy(Qt::ClickFocus);
        spinBoxPrice->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBoxPrice->setMaximum(100000);

        horizontalLayout_3->addWidget(spinBoxPrice);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        labelNumber = new QLabel(scrollAreaWidgetContents);
        labelNumber->setObjectName(QStringLiteral("labelNumber"));

        horizontalLayout_5->addWidget(labelNumber);

        spinBoxNumber = new QDoubleSpinBox(scrollAreaWidgetContents);
        spinBoxNumber->setObjectName(QStringLiteral("spinBoxNumber"));
        spinBoxNumber->setMinimumSize(QSize(220, 30));
        spinBoxNumber->setMaximumSize(QSize(200, 16777215));
        spinBoxNumber->setFocusPolicy(Qt::ClickFocus);
        spinBoxNumber->setMinimum(1);
        spinBoxNumber->setMaximum(100000);

        horizontalLayout_5->addWidget(spinBoxNumber);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEditTotalMoney = new QLineEdit(scrollAreaWidgetContents);
        lineEditTotalMoney->setObjectName(QStringLiteral("lineEditTotalMoney"));
        lineEditTotalMoney->setEnabled(false);
        lineEditTotalMoney->setMinimumSize(QSize(220, 30));
        lineEditTotalMoney->setMaximumSize(QSize(200, 16777215));
        lineEditTotalMoney->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_4->addWidget(lineEditTotalMoney);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        labelNowNumber_2 = new QLabel(scrollAreaWidgetContents);
        labelNowNumber_2->setObjectName(QStringLiteral("labelNowNumber_2"));

        horizontalLayout_9->addWidget(labelNowNumber_2);

        lineEditReason = new QLineEdit(scrollAreaWidgetContents);
        lineEditReason->setObjectName(QStringLiteral("lineEditReason"));
        lineEditReason->setMinimumSize(QSize(220, 30));
        lineEditReason->setMaximumSize(QSize(220, 16777215));

        horizontalLayout_9->addWidget(lineEditReason);


        verticalLayout->addLayout(horizontalLayout_9);

        labelSide = new QLabel(scrollAreaWidgetContents);
        labelSide->setObjectName(QStringLiteral("labelSide"));
        labelSide->setMinimumSize(QSize(0, 30));
        labelSide->setMaximumSize(QSize(16777215, 30));
        labelSide->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"background-color:rgb(180, 85, 100);\n"
"color:white;\n"
"font-size:14px;\n"
"font-weight:bold;\n"
"}"));
        labelSide->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(labelSide);

        pushButtonAddNew = new QPushButton(scrollAreaWidgetContents);
        pushButtonAddNew->setObjectName(QStringLiteral("pushButtonAddNew"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/image/addfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonAddNew->setIcon(icon);

        verticalLayout->addWidget(pushButtonAddNew);

        widgetControl = new QWidget(scrollAreaWidgetContents);
        widgetControl->setObjectName(QStringLiteral("widgetControl"));
        verticalLayout_4 = new QVBoxLayout(widgetControl);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        pushButtonSave = new QPushButton(widgetControl);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSave->setIcon(icon1);

        horizontalLayout_8->addWidget(pushButtonSave);

        pushButtonDel = new QPushButton(widgetControl);
        pushButtonDel->setObjectName(QStringLiteral("pushButtonDel"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/image/\345\210\240 \351\231\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonDel->setIcon(icon2);

        horizontalLayout_8->addWidget(pushButtonDel);

        pushButtonCancel = new QPushButton(widgetControl);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon3);

        horizontalLayout_8->addWidget(pushButtonCancel);


        verticalLayout_4->addLayout(horizontalLayout_8);


        verticalLayout->addWidget(widgetControl);


        verticalLayout_2->addLayout(verticalLayout);

        scrollAreaSide->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollAreaSide);

        QWidget::setTabOrder(pushButtonCancel, lineEditWareHouse);
        QWidget::setTabOrder(lineEditWareHouse, pushButtonSave);
        QWidget::setTabOrder(pushButtonSave, comboBoxUnit);
        QWidget::setTabOrder(comboBoxUnit, lineEditTotalMoney);
        QWidget::setTabOrder(lineEditTotalMoney, lineEditMatName);
        QWidget::setTabOrder(lineEditMatName, lineEditBarCode);

        retranslateUi(materialretinfo);

        QMetaObject::connectSlotsByName(materialretinfo);
    } // setupUi

    void retranslateUi(QWidget *materialretinfo)
    {
        materialretinfo->setWindowTitle(QApplication::translate("materialretinfo", "Form", 0));
        label_19->setText(QApplication::translate("materialretinfo", " \345\237\272\346\234\254\344\277\241\346\201\257", 0));
        label->setText(QApplication::translate("materialretinfo", "\345\216\237\346\226\231\345\220\215\347\247\260\357\274\232", 0));
        label_2->setText(QApplication::translate("materialretinfo", "\346\235\241\345\275\242\347\240\201\357\274\232", 0));
        labelNowNumber->setText(QApplication::translate("materialretinfo", "\344\270\273\351\200\200\350\264\247\344\273\223\345\272\223\357\274\232", 0));
        labelUnit->setText(QApplication::translate("materialretinfo", "\345\215\225\344\275\215\357\274\232", 0));
        labelUnitPrice->setText(QApplication::translate("materialretinfo", "\345\215\225\344\273\267\357\274\232", 0));
        labelNumber->setText(QApplication::translate("materialretinfo", "\346\225\260\351\207\217\357\274\232", 0));
        label_4->setText(QApplication::translate("materialretinfo", "\351\207\221\351\242\235(\345\205\203)\357\274\232", 0));
        labelNowNumber_2->setText(QApplication::translate("materialretinfo", "\351\200\200\350\264\247\345\216\237\345\233\240\357\274\232", 0));
        labelSide->setText(QApplication::translate("materialretinfo", " \345\210\206\344\273\223\351\200\200\350\264\247", 0));
        pushButtonAddNew->setText(QApplication::translate("materialretinfo", " \346\267\273\345\212\240\346\226\260\347\232\204\345\210\206\344\273\223\351\200\200\350\264\247...", 0));
        pushButtonSave->setText(QApplication::translate("materialretinfo", " \344\277\235\345\255\230", 0));
        pushButtonDel->setText(QApplication::translate("materialretinfo", " \345\210\240\351\231\244", 0));
        pushButtonCancel->setText(QApplication::translate("materialretinfo", " \345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class materialretinfo: public Ui_materialretinfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATERIALRETINFO_H
