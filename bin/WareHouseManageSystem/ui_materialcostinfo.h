/********************************************************************************
** Form generated from reading UI file 'materialcostinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATERIALCOSTINFO_H
#define UI_MATERIALCOSTINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_materialcostinfo
{
public:
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_19;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditMatName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditBarCode;
    QHBoxLayout *horizontalLayout_12;
    QLabel *labelUnit_2;
    QLineEdit *lineEditSpec;
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelUnit;
    QLineEdit *lineEditUnitName;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelUnitPrice;
    QLineEdit *lineEditPriceBefore;
    QHBoxLayout *horizontalLayout_10;
    QLabel *labelAdjustNumber;
    QDoubleSpinBox *spinBoxPriceAfter;
    QHBoxLayout *horizontalLayout_11;
    QLabel *labelLaterNumber;
    QLineEdit *lineEditDifference;
    QHBoxLayout *horizontalLayout_9;
    QWidget *widgetControl;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonDel;
    QPushButton *pushButtonCancel;

    void setupUi(QWidget *materialcostinfo)
    {
        if (materialcostinfo->objectName().isEmpty())
            materialcostinfo->setObjectName(QStringLiteral("materialcostinfo"));
        materialcostinfo->resize(428, 502);
        verticalLayout_3 = new QVBoxLayout(materialcostinfo);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(9, 9, 9, 9);
        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(9, 9, 9, 9);
        label_19 = new QLabel(materialcostinfo);
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
        label = new QLabel(materialcostinfo);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEditMatName = new QLineEdit(materialcostinfo);
        lineEditMatName->setObjectName(QStringLiteral("lineEditMatName"));
        lineEditMatName->setEnabled(false);
        lineEditMatName->setMinimumSize(QSize(220, 30));
        lineEditMatName->setMaximumSize(QSize(220, 16777215));
        lineEditMatName->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(lineEditMatName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(materialcostinfo);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEditBarCode = new QLineEdit(materialcostinfo);
        lineEditBarCode->setObjectName(QStringLiteral("lineEditBarCode"));
        lineEditBarCode->setEnabled(false);
        lineEditBarCode->setMinimumSize(QSize(220, 30));
        lineEditBarCode->setMaximumSize(QSize(220, 16777215));
        lineEditBarCode->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(lineEditBarCode);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        labelUnit_2 = new QLabel(materialcostinfo);
        labelUnit_2->setObjectName(QStringLiteral("labelUnit_2"));

        horizontalLayout_12->addWidget(labelUnit_2);

        lineEditSpec = new QLineEdit(materialcostinfo);
        lineEditSpec->setObjectName(QStringLiteral("lineEditSpec"));
        lineEditSpec->setEnabled(false);
        lineEditSpec->setMinimumSize(QSize(220, 30));
        lineEditSpec->setMaximumSize(QSize(200, 16777215));
        lineEditSpec->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_12->addWidget(lineEditSpec);


        verticalLayout->addLayout(horizontalLayout_12);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        labelUnit = new QLabel(materialcostinfo);
        labelUnit->setObjectName(QStringLiteral("labelUnit"));

        horizontalLayout_7->addWidget(labelUnit);

        lineEditUnitName = new QLineEdit(materialcostinfo);
        lineEditUnitName->setObjectName(QStringLiteral("lineEditUnitName"));
        lineEditUnitName->setEnabled(false);
        lineEditUnitName->setMinimumSize(QSize(220, 30));
        lineEditUnitName->setMaximumSize(QSize(200, 16777215));
        lineEditUnitName->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_7->addWidget(lineEditUnitName);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelUnitPrice = new QLabel(materialcostinfo);
        labelUnitPrice->setObjectName(QStringLiteral("labelUnitPrice"));

        horizontalLayout_3->addWidget(labelUnitPrice);

        lineEditPriceBefore = new QLineEdit(materialcostinfo);
        lineEditPriceBefore->setObjectName(QStringLiteral("lineEditPriceBefore"));
        lineEditPriceBefore->setEnabled(false);
        lineEditPriceBefore->setMinimumSize(QSize(220, 30));
        lineEditPriceBefore->setMaximumSize(QSize(200, 16777215));
        lineEditPriceBefore->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_3->addWidget(lineEditPriceBefore);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        labelAdjustNumber = new QLabel(materialcostinfo);
        labelAdjustNumber->setObjectName(QStringLiteral("labelAdjustNumber"));

        horizontalLayout_10->addWidget(labelAdjustNumber);

        spinBoxPriceAfter = new QDoubleSpinBox(materialcostinfo);
        spinBoxPriceAfter->setObjectName(QStringLiteral("spinBoxPriceAfter"));
        spinBoxPriceAfter->setMinimumSize(QSize(220, 30));
        spinBoxPriceAfter->setMaximumSize(QSize(200, 16777215));
        spinBoxPriceAfter->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        spinBoxPriceAfter->setMaximum(100000);

        horizontalLayout_10->addWidget(spinBoxPriceAfter);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        labelLaterNumber = new QLabel(materialcostinfo);
        labelLaterNumber->setObjectName(QStringLiteral("labelLaterNumber"));

        horizontalLayout_11->addWidget(labelLaterNumber);

        lineEditDifference = new QLineEdit(materialcostinfo);
        lineEditDifference->setObjectName(QStringLiteral("lineEditDifference"));
        lineEditDifference->setEnabled(false);
        lineEditDifference->setMinimumSize(QSize(220, 30));
        lineEditDifference->setMaximumSize(QSize(200, 16777215));
        lineEditDifference->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_11->addWidget(lineEditDifference);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));

        verticalLayout->addLayout(horizontalLayout_9);

        widgetControl = new QWidget(materialcostinfo);
        widgetControl->setObjectName(QStringLiteral("widgetControl"));
        verticalLayout_4 = new QVBoxLayout(widgetControl);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        pushButtonSave = new QPushButton(widgetControl);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSave->setIcon(icon);

        horizontalLayout_8->addWidget(pushButtonSave);

        pushButtonDel = new QPushButton(widgetControl);
        pushButtonDel->setObjectName(QStringLiteral("pushButtonDel"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/image/\345\210\240 \351\231\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonDel->setIcon(icon1);

        horizontalLayout_8->addWidget(pushButtonDel);

        pushButtonCancel = new QPushButton(widgetControl);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon2);

        horizontalLayout_8->addWidget(pushButtonCancel);


        verticalLayout_4->addLayout(horizontalLayout_8);


        verticalLayout->addWidget(widgetControl);


        verticalLayout_3->addLayout(verticalLayout);

        QWidget::setTabOrder(pushButtonCancel, pushButtonSave);
        QWidget::setTabOrder(pushButtonSave, lineEditMatName);
        QWidget::setTabOrder(lineEditMatName, lineEditBarCode);

        retranslateUi(materialcostinfo);

        QMetaObject::connectSlotsByName(materialcostinfo);
    } // setupUi

    void retranslateUi(QWidget *materialcostinfo)
    {
        materialcostinfo->setWindowTitle(QApplication::translate("materialcostinfo", "Form", 0));
        label_19->setText(QApplication::translate("materialcostinfo", " \345\237\272\346\234\254\344\277\241\346\201\257", 0));
        label->setText(QApplication::translate("materialcostinfo", "\345\216\237\346\226\231\345\220\215\347\247\260\357\274\232", 0));
        label_2->setText(QApplication::translate("materialcostinfo", "\346\235\241\345\275\242\347\240\201\357\274\232", 0));
        labelUnit_2->setText(QApplication::translate("materialcostinfo", "\350\247\204\346\240\274\357\274\232", 0));
        labelUnit->setText(QApplication::translate("materialcostinfo", "\350\256\241\344\273\267\345\215\225\344\275\215\357\274\232", 0));
        labelUnitPrice->setText(QApplication::translate("materialcostinfo", "\350\260\203\344\273\267\345\211\215\346\210\220\346\234\254\344\273\267\357\274\210\345\205\203\357\274\211\357\274\232", 0));
        labelAdjustNumber->setText(QApplication::translate("materialcostinfo", "\350\260\203\344\273\267\345\220\216\346\210\220\346\234\254\344\273\267\357\274\210\345\205\203\357\274\211\357\274\232", 0));
        labelLaterNumber->setText(QApplication::translate("materialcostinfo", "\345\267\256\345\274\202\357\274\210\345\205\203\357\274\211", 0));
        pushButtonSave->setText(QApplication::translate("materialcostinfo", " \344\277\235\345\255\230", 0));
        pushButtonDel->setText(QApplication::translate("materialcostinfo", " \345\210\240\351\231\244", 0));
        pushButtonCancel->setText(QApplication::translate("materialcostinfo", " \345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class materialcostinfo: public Ui_materialcostinfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATERIALCOSTINFO_H
