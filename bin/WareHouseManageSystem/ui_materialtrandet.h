/********************************************************************************
** Form generated from reading UI file 'materialtrandet.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATERIALTRANDET_H
#define UI_MATERIALTRANDET_H

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

class Ui_materialtrandet
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
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelUnit;
    QComboBox *comboBoxUnit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelUnitPrice;
    QLineEdit *lineEditPrice;
    QHBoxLayout *horizontalLayout_10;
    QLabel *labelNumber;
    QDoubleSpinBox *spinBoxNumber;
    QWidget *widgetControl;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonDel;
    QPushButton *pushButtonCancel;

    void setupUi(QWidget *materialtrandet)
    {
        if (materialtrandet->objectName().isEmpty())
            materialtrandet->setObjectName(QStringLiteral("materialtrandet"));
        materialtrandet->resize(409, 458);
        verticalLayout_3 = new QVBoxLayout(materialtrandet);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(9, 9, 9, 9);
        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(9, 9, 9, 9);
        label_19 = new QLabel(materialtrandet);
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
        label = new QLabel(materialtrandet);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEditMatName = new QLineEdit(materialtrandet);
        lineEditMatName->setObjectName(QStringLiteral("lineEditMatName"));
        lineEditMatName->setEnabled(false);
        lineEditMatName->setMinimumSize(QSize(220, 30));
        lineEditMatName->setMaximumSize(QSize(220, 16777215));
        lineEditMatName->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(lineEditMatName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(materialtrandet);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEditBarCode = new QLineEdit(materialtrandet);
        lineEditBarCode->setObjectName(QStringLiteral("lineEditBarCode"));
        lineEditBarCode->setEnabled(false);
        lineEditBarCode->setMinimumSize(QSize(220, 30));
        lineEditBarCode->setMaximumSize(QSize(220, 16777215));
        lineEditBarCode->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(lineEditBarCode);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        labelUnit = new QLabel(materialtrandet);
        labelUnit->setObjectName(QStringLiteral("labelUnit"));

        horizontalLayout_7->addWidget(labelUnit);

        comboBoxUnit = new QComboBox(materialtrandet);
        comboBoxUnit->setObjectName(QStringLiteral("comboBoxUnit"));
        comboBoxUnit->setMinimumSize(QSize(220, 30));
        comboBoxUnit->setMaximumSize(QSize(200, 16777215));
        comboBoxUnit->setStyleSheet(QLatin1String("background-color:white;\n"
"color: rgb(0, 0, 0);\n"
""));

        horizontalLayout_7->addWidget(comboBoxUnit);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelUnitPrice = new QLabel(materialtrandet);
        labelUnitPrice->setObjectName(QStringLiteral("labelUnitPrice"));

        horizontalLayout_3->addWidget(labelUnitPrice);

        lineEditPrice = new QLineEdit(materialtrandet);
        lineEditPrice->setObjectName(QStringLiteral("lineEditPrice"));
        lineEditPrice->setEnabled(false);
        lineEditPrice->setMinimumSize(QSize(220, 30));
        lineEditPrice->setMaximumSize(QSize(200, 16777215));
        lineEditPrice->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_3->addWidget(lineEditPrice);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        labelNumber = new QLabel(materialtrandet);
        labelNumber->setObjectName(QStringLiteral("labelNumber"));

        horizontalLayout_10->addWidget(labelNumber);

        spinBoxNumber = new QDoubleSpinBox(materialtrandet);
        spinBoxNumber->setObjectName(QStringLiteral("spinBoxNumber"));
        spinBoxNumber->setMinimumSize(QSize(220, 30));
        spinBoxNumber->setMaximumSize(QSize(200, 16777215));
        spinBoxNumber->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        spinBoxNumber->setMinimum(1);
        spinBoxNumber->setMaximum(100000);

        horizontalLayout_10->addWidget(spinBoxNumber);


        verticalLayout->addLayout(horizontalLayout_10);

        widgetControl = new QWidget(materialtrandet);
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
        QWidget::setTabOrder(pushButtonSave, comboBoxUnit);
        QWidget::setTabOrder(comboBoxUnit, lineEditMatName);
        QWidget::setTabOrder(lineEditMatName, lineEditBarCode);

        retranslateUi(materialtrandet);

        QMetaObject::connectSlotsByName(materialtrandet);
    } // setupUi

    void retranslateUi(QWidget *materialtrandet)
    {
        materialtrandet->setWindowTitle(QApplication::translate("materialtrandet", "Form", 0));
        label_19->setText(QApplication::translate("materialtrandet", " \345\237\272\346\234\254\344\277\241\346\201\257", 0));
        label->setText(QApplication::translate("materialtrandet", "\345\216\237\346\226\231\345\220\215\347\247\260\357\274\232", 0));
        label_2->setText(QApplication::translate("materialtrandet", "\346\235\241\345\275\242\347\240\201\357\274\232", 0));
        labelUnit->setText(QApplication::translate("materialtrandet", "\350\260\203\346\213\250\345\215\225\344\275\215\357\274\232", 0));
        labelUnitPrice->setText(QApplication::translate("materialtrandet", "\345\215\225\344\273\267\357\274\232", 0));
        labelNumber->setText(QApplication::translate("materialtrandet", "\350\260\203\346\213\250\346\225\260\351\207\217\357\274\232", 0));
        pushButtonSave->setText(QApplication::translate("materialtrandet", " \344\277\235\345\255\230", 0));
        pushButtonDel->setText(QApplication::translate("materialtrandet", " \345\210\240\351\231\244", 0));
        pushButtonCancel->setText(QApplication::translate("materialtrandet", " \345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class materialtrandet: public Ui_materialtrandet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATERIALTRANDET_H
