/********************************************************************************
** Form generated from reading UI file 'materialpurinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATERIALPURINFO_H
#define UI_MATERIALPURINFO_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MaterialPurInfo
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
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelUnit;
    QComboBox *comboBoxUnit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelUnitPrice;
    QDoubleSpinBox *spinBoxPrice;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labelNowNumber;
    QLineEdit *lineEditInventory;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelNumber;
    QDoubleSpinBox *spinBoxNumber;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEditTotalMoney;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonCancel;

    void setupUi(QWidget *MaterialPurInfo)
    {
        if (MaterialPurInfo->objectName().isEmpty())
            MaterialPurInfo->setObjectName(QStringLiteral("MaterialPurInfo"));
        MaterialPurInfo->resize(381, 511);
        verticalLayout = new QVBoxLayout(MaterialPurInfo);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(MaterialPurInfo);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEditMatName = new QLineEdit(MaterialPurInfo);
        lineEditMatName->setObjectName(QStringLiteral("lineEditMatName"));
        lineEditMatName->setEnabled(false);
        lineEditMatName->setMinimumSize(QSize(200, 30));
        lineEditMatName->setMaximumSize(QSize(200, 16777215));
        lineEditMatName->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(lineEditMatName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(MaterialPurInfo);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEditBarCode = new QLineEdit(MaterialPurInfo);
        lineEditBarCode->setObjectName(QStringLiteral("lineEditBarCode"));
        lineEditBarCode->setEnabled(false);
        lineEditBarCode->setMinimumSize(QSize(200, 30));
        lineEditBarCode->setMaximumSize(QSize(200, 16777215));
        lineEditBarCode->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(lineEditBarCode);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        labelUnit = new QLabel(MaterialPurInfo);
        labelUnit->setObjectName(QStringLiteral("labelUnit"));

        horizontalLayout_7->addWidget(labelUnit);

        comboBoxUnit = new QComboBox(MaterialPurInfo);
        comboBoxUnit->setObjectName(QStringLiteral("comboBoxUnit"));
        comboBoxUnit->setMinimumSize(QSize(200, 30));
        comboBoxUnit->setMaximumSize(QSize(200, 16777215));
        comboBoxUnit->setStyleSheet(QLatin1String("background-color:white;\n"
""));

        horizontalLayout_7->addWidget(comboBoxUnit);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelUnitPrice = new QLabel(MaterialPurInfo);
        labelUnitPrice->setObjectName(QStringLiteral("labelUnitPrice"));

        horizontalLayout_3->addWidget(labelUnitPrice);

        spinBoxPrice = new QDoubleSpinBox(MaterialPurInfo);
        spinBoxPrice->setObjectName(QStringLiteral("spinBoxPrice"));
        spinBoxPrice->setMinimumSize(QSize(200, 30));
        spinBoxPrice->setMaximumSize(QSize(200, 16777215));
        spinBoxPrice->setMaximum(100000);

        horizontalLayout_3->addWidget(spinBoxPrice);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        labelNowNumber = new QLabel(MaterialPurInfo);
        labelNowNumber->setObjectName(QStringLiteral("labelNowNumber"));

        horizontalLayout_6->addWidget(labelNowNumber);

        lineEditInventory = new QLineEdit(MaterialPurInfo);
        lineEditInventory->setObjectName(QStringLiteral("lineEditInventory"));
        lineEditInventory->setEnabled(false);
        lineEditInventory->setMinimumSize(QSize(200, 30));
        lineEditInventory->setMaximumSize(QSize(200, 16777215));
        lineEditInventory->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_6->addWidget(lineEditInventory);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        labelNumber = new QLabel(MaterialPurInfo);
        labelNumber->setObjectName(QStringLiteral("labelNumber"));

        horizontalLayout_5->addWidget(labelNumber);

        spinBoxNumber = new QDoubleSpinBox(MaterialPurInfo);
        spinBoxNumber->setObjectName(QStringLiteral("spinBoxNumber"));
        spinBoxNumber->setMinimumSize(QSize(200, 30));
        spinBoxNumber->setMaximumSize(QSize(200, 16777215));
        spinBoxNumber->setMinimum(1);
        spinBoxNumber->setMaximum(100000);

        horizontalLayout_5->addWidget(spinBoxNumber);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(MaterialPurInfo);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEditTotalMoney = new QLineEdit(MaterialPurInfo);
        lineEditTotalMoney->setObjectName(QStringLiteral("lineEditTotalMoney"));
        lineEditTotalMoney->setEnabled(false);
        lineEditTotalMoney->setMinimumSize(QSize(200, 30));
        lineEditTotalMoney->setMaximumSize(QSize(200, 16777215));
        lineEditTotalMoney->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_4->addWidget(lineEditTotalMoney);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        pushButtonSave = new QPushButton(MaterialPurInfo);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSave->setIcon(icon);

        horizontalLayout_8->addWidget(pushButtonSave);

        pushButtonCancel = new QPushButton(MaterialPurInfo);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon1);

        horizontalLayout_8->addWidget(pushButtonCancel);


        verticalLayout->addLayout(horizontalLayout_8);

        QWidget::setTabOrder(pushButtonSave, lineEditBarCode);
        QWidget::setTabOrder(lineEditBarCode, comboBoxUnit);
        QWidget::setTabOrder(comboBoxUnit, lineEditInventory);
        QWidget::setTabOrder(lineEditInventory, lineEditTotalMoney);
        QWidget::setTabOrder(lineEditTotalMoney, lineEditMatName);
        QWidget::setTabOrder(lineEditMatName, pushButtonCancel);

        retranslateUi(MaterialPurInfo);

        QMetaObject::connectSlotsByName(MaterialPurInfo);
    } // setupUi

    void retranslateUi(QWidget *MaterialPurInfo)
    {
        MaterialPurInfo->setWindowTitle(QApplication::translate("MaterialPurInfo", "Form", 0));
        label->setText(QApplication::translate("MaterialPurInfo", "\345\216\237\346\226\231\345\220\215\347\247\260\357\274\232", 0));
        label_2->setText(QApplication::translate("MaterialPurInfo", "\346\235\241\345\275\242\347\240\201\357\274\232", 0));
        labelUnit->setText(QApplication::translate("MaterialPurInfo", "\345\215\225\344\275\215\357\274\232", 0));
        labelUnitPrice->setText(QApplication::translate("MaterialPurInfo", "\345\215\225\344\273\267\357\274\232", 0));
        labelNowNumber->setText(QApplication::translate("MaterialPurInfo", "\347\216\260\346\234\211\345\272\223\345\255\230\357\274\232", 0));
        labelNumber->setText(QApplication::translate("MaterialPurInfo", "\346\225\260\351\207\217\357\274\232", 0));
        label_4->setText(QApplication::translate("MaterialPurInfo", "\351\207\221\351\242\235(\345\205\203)\357\274\232", 0));
        pushButtonSave->setText(QApplication::translate("MaterialPurInfo", " \344\277\235\345\255\230", 0));
        pushButtonCancel->setText(QApplication::translate("MaterialPurInfo", " \345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class MaterialPurInfo: public Ui_MaterialPurInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATERIALPURINFO_H
