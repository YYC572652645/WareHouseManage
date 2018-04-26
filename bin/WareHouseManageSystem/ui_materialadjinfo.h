/********************************************************************************
** Form generated from reading UI file 'materialadjinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATERIALADJINFO_H
#define UI_MATERIALADJINFO_H

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

class Ui_materialadjinfo
{
public:
    QVBoxLayout *verticalLayout_2;
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
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelNumber;
    QLineEdit *lineEditNumber;
    QHBoxLayout *horizontalLayout_10;
    QLabel *labelAdjustNumber;
    QDoubleSpinBox *spinBoxAdjustNumber;
    QHBoxLayout *horizontalLayout_11;
    QLabel *labelLaterNumber;
    QLineEdit *lineEditLateNumber;
    QHBoxLayout *horizontalLayout_9;
    QLabel *labelNowNumber_2;
    QLineEdit *lineEditReason;
    QPushButton *pushButtonSelectReason;
    QWidget *widgetControl;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonDel;
    QPushButton *pushButtonCancel;

    void setupUi(QWidget *materialadjinfo)
    {
        if (materialadjinfo->objectName().isEmpty())
            materialadjinfo->setObjectName(QStringLiteral("materialadjinfo"));
        materialadjinfo->resize(456, 500);
        verticalLayout_2 = new QVBoxLayout(materialadjinfo);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(9, 9, 9, 9);
        label_19 = new QLabel(materialadjinfo);
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
        label = new QLabel(materialadjinfo);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEditMatName = new QLineEdit(materialadjinfo);
        lineEditMatName->setObjectName(QStringLiteral("lineEditMatName"));
        lineEditMatName->setEnabled(false);
        lineEditMatName->setMinimumSize(QSize(220, 30));
        lineEditMatName->setMaximumSize(QSize(220, 16777215));
        lineEditMatName->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(lineEditMatName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(materialadjinfo);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEditBarCode = new QLineEdit(materialadjinfo);
        lineEditBarCode->setObjectName(QStringLiteral("lineEditBarCode"));
        lineEditBarCode->setEnabled(false);
        lineEditBarCode->setMinimumSize(QSize(220, 30));
        lineEditBarCode->setMaximumSize(QSize(220, 16777215));
        lineEditBarCode->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(lineEditBarCode);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        labelUnit = new QLabel(materialadjinfo);
        labelUnit->setObjectName(QStringLiteral("labelUnit"));

        horizontalLayout_7->addWidget(labelUnit);

        comboBoxUnit = new QComboBox(materialadjinfo);
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
        labelUnitPrice = new QLabel(materialadjinfo);
        labelUnitPrice->setObjectName(QStringLiteral("labelUnitPrice"));

        horizontalLayout_3->addWidget(labelUnitPrice);

        lineEditPrice = new QLineEdit(materialadjinfo);
        lineEditPrice->setObjectName(QStringLiteral("lineEditPrice"));
        lineEditPrice->setEnabled(false);
        lineEditPrice->setMinimumSize(QSize(220, 30));
        lineEditPrice->setMaximumSize(QSize(200, 16777215));
        lineEditPrice->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_3->addWidget(lineEditPrice);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        labelNumber = new QLabel(materialadjinfo);
        labelNumber->setObjectName(QStringLiteral("labelNumber"));

        horizontalLayout_5->addWidget(labelNumber);

        lineEditNumber = new QLineEdit(materialadjinfo);
        lineEditNumber->setObjectName(QStringLiteral("lineEditNumber"));
        lineEditNumber->setEnabled(false);
        lineEditNumber->setMinimumSize(QSize(220, 30));
        lineEditNumber->setMaximumSize(QSize(200, 16777215));
        lineEditNumber->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_5->addWidget(lineEditNumber);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        labelAdjustNumber = new QLabel(materialadjinfo);
        labelAdjustNumber->setObjectName(QStringLiteral("labelAdjustNumber"));

        horizontalLayout_10->addWidget(labelAdjustNumber);

        spinBoxAdjustNumber = new QDoubleSpinBox(materialadjinfo);
        spinBoxAdjustNumber->setObjectName(QStringLiteral("spinBoxAdjustNumber"));
        spinBoxAdjustNumber->setMinimumSize(QSize(220, 30));
        spinBoxAdjustNumber->setMaximumSize(QSize(200, 16777215));
        spinBoxAdjustNumber->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        spinBoxAdjustNumber->setMinimum(-99999);
        spinBoxAdjustNumber->setMaximum(100000);

        horizontalLayout_10->addWidget(spinBoxAdjustNumber);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        labelLaterNumber = new QLabel(materialadjinfo);
        labelLaterNumber->setObjectName(QStringLiteral("labelLaterNumber"));

        horizontalLayout_11->addWidget(labelLaterNumber);

        lineEditLateNumber = new QLineEdit(materialadjinfo);
        lineEditLateNumber->setObjectName(QStringLiteral("lineEditLateNumber"));
        lineEditLateNumber->setEnabled(false);
        lineEditLateNumber->setMinimumSize(QSize(220, 30));
        lineEditLateNumber->setMaximumSize(QSize(200, 16777215));
        lineEditLateNumber->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_11->addWidget(lineEditLateNumber);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        labelNowNumber_2 = new QLabel(materialadjinfo);
        labelNowNumber_2->setObjectName(QStringLiteral("labelNowNumber_2"));

        horizontalLayout_9->addWidget(labelNowNumber_2);

        lineEditReason = new QLineEdit(materialadjinfo);
        lineEditReason->setObjectName(QStringLiteral("lineEditReason"));
        lineEditReason->setEnabled(false);
        lineEditReason->setMinimumSize(QSize(188, 30));
        lineEditReason->setMaximumSize(QSize(188, 16777215));
        lineEditReason->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_9->addWidget(lineEditReason);

        pushButtonSelectReason = new QPushButton(materialadjinfo);
        pushButtonSelectReason->setObjectName(QStringLiteral("pushButtonSelectReason"));
        pushButtonSelectReason->setMinimumSize(QSize(25, 25));
        pushButtonSelectReason->setMaximumSize(QSize(25, 25));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/image/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSelectReason->setIcon(icon);

        horizontalLayout_9->addWidget(pushButtonSelectReason);


        verticalLayout->addLayout(horizontalLayout_9);

        widgetControl = new QWidget(materialadjinfo);
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


        retranslateUi(materialadjinfo);

        QMetaObject::connectSlotsByName(materialadjinfo);
    } // setupUi

    void retranslateUi(QWidget *materialadjinfo)
    {
        materialadjinfo->setWindowTitle(QApplication::translate("materialadjinfo", "Form", 0));
        label_19->setText(QApplication::translate("materialadjinfo", " \345\237\272\346\234\254\344\277\241\346\201\257", 0));
        label->setText(QApplication::translate("materialadjinfo", "\345\216\237\346\226\231\345\220\215\347\247\260\357\274\232", 0));
        label_2->setText(QApplication::translate("materialadjinfo", "\346\235\241\345\275\242\347\240\201\357\274\232", 0));
        labelUnit->setText(QApplication::translate("materialadjinfo", "\350\260\203\346\225\264\345\215\225\344\275\215\357\274\232", 0));
        labelUnitPrice->setText(QApplication::translate("materialadjinfo", "\345\215\225\344\273\267\357\274\232", 0));
        labelNumber->setText(QApplication::translate("materialadjinfo", "\350\264\246\351\235\242\346\225\260\351\207\217\357\274\232", 0));
        labelAdjustNumber->setText(QApplication::translate("materialadjinfo", "\350\260\203\346\225\264\346\225\260\351\207\217\357\274\232", 0));
        labelLaterNumber->setText(QApplication::translate("materialadjinfo", "\350\260\203\346\225\264\345\220\216\346\225\260\351\207\217\357\274\232", 0));
        labelNowNumber_2->setText(QApplication::translate("materialadjinfo", "\351\200\200\350\264\247\345\216\237\345\233\240\357\274\232", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonSelectReason->setToolTip(QApplication::translate("materialadjinfo", "\351\200\211\346\213\251\351\200\200\350\264\247\345\216\237\345\233\240", 0));
#endif // QT_NO_TOOLTIP
        pushButtonSelectReason->setText(QString());
        pushButtonSave->setText(QApplication::translate("materialadjinfo", " \344\277\235\345\255\230", 0));
        pushButtonDel->setText(QApplication::translate("materialadjinfo", " \345\210\240\351\231\244", 0));
        pushButtonCancel->setText(QApplication::translate("materialadjinfo", " \345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class materialadjinfo: public Ui_materialadjinfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATERIALADJINFO_H
