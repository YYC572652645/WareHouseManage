/********************************************************************************
** Form generated from reading UI file 'editauthority.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITAUTHORITY_H
#define UI_EDITAUTHORITY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditAuthority
{
public:
    QVBoxLayout *verticalLayout_9;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBoxBasic;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBoxMaterial;
    QCheckBox *checkBoxWarehouse;
    QCheckBox *checkBoxSupplier;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *checkBoxTemplate;
    QCheckBox *checkBoxBom;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBoxCommon;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBoxPurchase;
    QCheckBox *checkBoxStorage;
    QCheckBox *checkBoxReturns;
    QSpacerItem *horizontalSpacer_4;
    QCheckBox *checkBoxSafety;
    QGroupBox *groupBoxWhse;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkBoxTimeinventory;
    QCheckBox *checkBoxAdjustment;
    QCheckBox *checkBoxCheck;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *checkBoxChange;
    QCheckBox *checkBoxAllot;
    QCheckBox *checkBoxReadjust;
    QSpacerItem *horizontalSpacer_6;
    QCheckBox *checkBoxRestrictions;
    QGroupBox *groupBoxOther;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *checkBoxRule;
    QCheckBox *checkBoxDefaultSupplier;
    QCheckBox *checkBoxAccount;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *checkBoxToday;
    QCheckBox *checkBoxUser;
    QSpacerItem *horizontalSpacer_9;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_11;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label;
    QLineEdit *lineEditUserName;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_2;
    QLineEdit *lineEditPassWord;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButtonOk;
    QPushButton *pushButtonCancel;

    void setupUi(QWidget *EditAuthority)
    {
        if (EditAuthority->objectName().isEmpty())
            EditAuthority->setObjectName(QStringLiteral("EditAuthority"));
        EditAuthority->resize(466, 657);
        EditAuthority->setStyleSheet(QLatin1String("QPushButton:hover\n"
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
"spacing:2px;\n"
"padding: 0px 0px;\n"
"}"));
        verticalLayout_9 = new QVBoxLayout(EditAuthority);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_9->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_9->addItem(horizontalSpacer_2);

        groupBoxBasic = new QGroupBox(EditAuthority);
        groupBoxBasic->setObjectName(QStringLiteral("groupBoxBasic"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        groupBoxBasic->setFont(font);
        groupBoxBasic->setCheckable(false);
        groupBoxBasic->setChecked(false);
        verticalLayout_6 = new QVBoxLayout(groupBoxBasic);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(2, 2, 2, 2);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        checkBoxMaterial = new QCheckBox(groupBoxBasic);
        checkBoxMaterial->setObjectName(QStringLiteral("checkBoxMaterial"));

        horizontalLayout->addWidget(checkBoxMaterial);

        checkBoxWarehouse = new QCheckBox(groupBoxBasic);
        checkBoxWarehouse->setObjectName(QStringLiteral("checkBoxWarehouse"));

        horizontalLayout->addWidget(checkBoxWarehouse);

        checkBoxSupplier = new QCheckBox(groupBoxBasic);
        checkBoxSupplier->setObjectName(QStringLiteral("checkBoxSupplier"));

        horizontalLayout->addWidget(checkBoxSupplier);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        checkBoxTemplate = new QCheckBox(groupBoxBasic);
        checkBoxTemplate->setObjectName(QStringLiteral("checkBoxTemplate"));

        horizontalLayout_7->addWidget(checkBoxTemplate);

        checkBoxBom = new QCheckBox(groupBoxBasic);
        checkBoxBom->setObjectName(QStringLiteral("checkBoxBom"));

        horizontalLayout_7->addWidget(checkBoxBom);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 1);
        horizontalLayout_7->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_7);


        verticalLayout_6->addLayout(verticalLayout);


        verticalLayout_9->addWidget(groupBoxBasic);

        groupBoxCommon = new QGroupBox(EditAuthority);
        groupBoxCommon->setObjectName(QStringLiteral("groupBoxCommon"));
        groupBoxCommon->setFont(font);
        verticalLayout_7 = new QVBoxLayout(groupBoxCommon);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(2, 2, 2, 2);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        checkBoxPurchase = new QCheckBox(groupBoxCommon);
        checkBoxPurchase->setObjectName(QStringLiteral("checkBoxPurchase"));

        horizontalLayout_2->addWidget(checkBoxPurchase);

        checkBoxStorage = new QCheckBox(groupBoxCommon);
        checkBoxStorage->setObjectName(QStringLiteral("checkBoxStorage"));

        horizontalLayout_2->addWidget(checkBoxStorage);

        checkBoxReturns = new QCheckBox(groupBoxCommon);
        checkBoxReturns->setObjectName(QStringLiteral("checkBoxReturns"));

        horizontalLayout_2->addWidget(checkBoxReturns);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);

        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_4);

        checkBoxSafety = new QCheckBox(groupBoxCommon);
        checkBoxSafety->setObjectName(QStringLiteral("checkBoxSafety"));

        verticalLayout_2->addWidget(checkBoxSafety);


        verticalLayout_7->addLayout(verticalLayout_2);


        verticalLayout_9->addWidget(groupBoxCommon);

        groupBoxWhse = new QGroupBox(EditAuthority);
        groupBoxWhse->setObjectName(QStringLiteral("groupBoxWhse"));
        groupBoxWhse->setFont(font);
        verticalLayout_4 = new QVBoxLayout(groupBoxWhse);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(2, 2, 2, 2);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        checkBoxTimeinventory = new QCheckBox(groupBoxWhse);
        checkBoxTimeinventory->setObjectName(QStringLiteral("checkBoxTimeinventory"));

        horizontalLayout_3->addWidget(checkBoxTimeinventory);

        checkBoxAdjustment = new QCheckBox(groupBoxWhse);
        checkBoxAdjustment->setObjectName(QStringLiteral("checkBoxAdjustment"));

        horizontalLayout_3->addWidget(checkBoxAdjustment);

        checkBoxCheck = new QCheckBox(groupBoxWhse);
        checkBoxCheck->setObjectName(QStringLiteral("checkBoxCheck"));

        horizontalLayout_3->addWidget(checkBoxCheck);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 1);

        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        checkBoxChange = new QCheckBox(groupBoxWhse);
        checkBoxChange->setObjectName(QStringLiteral("checkBoxChange"));

        horizontalLayout_4->addWidget(checkBoxChange);

        checkBoxAllot = new QCheckBox(groupBoxWhse);
        checkBoxAllot->setObjectName(QStringLiteral("checkBoxAllot"));

        horizontalLayout_4->addWidget(checkBoxAllot);

        checkBoxReadjust = new QCheckBox(groupBoxWhse);
        checkBoxReadjust->setObjectName(QStringLiteral("checkBoxReadjust"));

        horizontalLayout_4->addWidget(checkBoxReadjust);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);
        horizontalLayout_4->setStretch(2, 1);

        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_6);

        checkBoxRestrictions = new QCheckBox(groupBoxWhse);
        checkBoxRestrictions->setObjectName(QStringLiteral("checkBoxRestrictions"));

        verticalLayout_3->addWidget(checkBoxRestrictions);


        verticalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_9->addWidget(groupBoxWhse);

        groupBoxOther = new QGroupBox(EditAuthority);
        groupBoxOther->setObjectName(QStringLiteral("groupBoxOther"));
        groupBoxOther->setFont(font);
        verticalLayout_8 = new QVBoxLayout(groupBoxOther);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(2, 2, 2, 2);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        checkBoxRule = new QCheckBox(groupBoxOther);
        checkBoxRule->setObjectName(QStringLiteral("checkBoxRule"));

        horizontalLayout_5->addWidget(checkBoxRule);

        checkBoxDefaultSupplier = new QCheckBox(groupBoxOther);
        checkBoxDefaultSupplier->setObjectName(QStringLiteral("checkBoxDefaultSupplier"));

        horizontalLayout_5->addWidget(checkBoxDefaultSupplier);

        checkBoxAccount = new QCheckBox(groupBoxOther);
        checkBoxAccount->setObjectName(QStringLiteral("checkBoxAccount"));

        horizontalLayout_5->addWidget(checkBoxAccount);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 1);
        horizontalLayout_5->setStretch(2, 1);

        verticalLayout_5->addLayout(horizontalLayout_5);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_5->addItem(horizontalSpacer_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        checkBoxToday = new QCheckBox(groupBoxOther);
        checkBoxToday->setObjectName(QStringLiteral("checkBoxToday"));

        horizontalLayout_8->addWidget(checkBoxToday);

        checkBoxUser = new QCheckBox(groupBoxOther);
        checkBoxUser->setObjectName(QStringLiteral("checkBoxUser"));

        horizontalLayout_8->addWidget(checkBoxUser);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_9);

        horizontalLayout_8->setStretch(0, 1);
        horizontalLayout_8->setStretch(1, 1);
        horizontalLayout_8->setStretch(2, 1);

        verticalLayout_5->addLayout(horizontalLayout_8);


        verticalLayout_8->addLayout(verticalLayout_5);


        verticalLayout_9->addWidget(groupBoxOther);

        groupBox_5 = new QGroupBox(EditAuthority);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setFont(font);
        verticalLayout_10 = new QVBoxLayout(groupBox_5);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label = new QLabel(groupBox_5);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_9->addWidget(label);

        lineEditUserName = new QLineEdit(groupBox_5);
        lineEditUserName->setObjectName(QStringLiteral("lineEditUserName"));
        lineEditUserName->setMinimumSize(QSize(0, 30));

        horizontalLayout_9->addWidget(lineEditUserName);


        horizontalLayout_11->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_2 = new QLabel(groupBox_5);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_10->addWidget(label_2);

        lineEditPassWord = new QLineEdit(groupBox_5);
        lineEditPassWord->setObjectName(QStringLiteral("lineEditPassWord"));
        lineEditPassWord->setMinimumSize(QSize(0, 30));
        lineEditPassWord->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        horizontalLayout_10->addWidget(lineEditPassWord);


        horizontalLayout_11->addLayout(horizontalLayout_10);


        verticalLayout_10->addLayout(horizontalLayout_11);


        verticalLayout_9->addWidget(groupBox_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        pushButtonOk = new QPushButton(EditAuthority);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));
        pushButtonOk->setMinimumSize(QSize(0, 30));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\347\241\256\350\256\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonOk->setIcon(icon);

        horizontalLayout_6->addWidget(pushButtonOk);

        pushButtonCancel = new QPushButton(EditAuthority);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setMinimumSize(QSize(0, 30));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon1);

        horizontalLayout_6->addWidget(pushButtonCancel);


        verticalLayout_9->addLayout(horizontalLayout_6);


        retranslateUi(EditAuthority);

        QMetaObject::connectSlotsByName(EditAuthority);
    } // setupUi

    void retranslateUi(QWidget *EditAuthority)
    {
        EditAuthority->setWindowTitle(QApplication::translate("EditAuthority", "Form", 0));
        groupBoxBasic->setTitle(QApplication::translate("EditAuthority", "\345\237\272\347\241\200\345\212\237\350\203\275", 0));
        checkBoxMaterial->setText(QApplication::translate("EditAuthority", "\345\216\237\346\226\231\350\256\276\347\275\256", 0));
        checkBoxWarehouse->setText(QApplication::translate("EditAuthority", "\344\273\223\345\272\223\350\256\276\347\275\256", 0));
        checkBoxSupplier->setText(QApplication::translate("EditAuthority", "\344\276\233\345\272\224\345\225\206\350\256\276\347\275\256", 0));
        checkBoxTemplate->setText(QApplication::translate("EditAuthority", "\351\207\207\350\264\255\346\250\241\346\235\277\350\256\276\347\275\256", 0));
        checkBoxBom->setText(QApplication::translate("EditAuthority", "\345\225\206\345\223\201\345\216\237\346\226\231\350\256\276\347\275\256", 0));
        groupBoxCommon->setTitle(QApplication::translate("EditAuthority", "\350\277\233\350\264\247\345\270\270\347\224\250\345\212\237\350\203\275", 0));
        checkBoxPurchase->setText(QApplication::translate("EditAuthority", "\351\207\207\350\264\255\350\256\242\345\215\225", 0));
        checkBoxStorage->setText(QApplication::translate("EditAuthority", "\351\207\207\350\264\255\345\205\245\345\272\223", 0));
        checkBoxReturns->setText(QApplication::translate("EditAuthority", "\351\207\207\350\264\255\351\200\200\350\264\247", 0));
        checkBoxSafety->setText(QApplication::translate("EditAuthority", "\345\256\211\345\205\250\345\272\223\345\255\230\351\207\207\350\264\255", 0));
        groupBoxWhse->setTitle(QApplication::translate("EditAuthority", "\345\272\223\347\256\241\345\270\270\347\224\250\345\212\237\350\203\275", 0));
        checkBoxTimeinventory->setText(QApplication::translate("EditAuthority", "\345\256\236\346\227\266\345\272\223\345\255\230", 0));
        checkBoxAdjustment->setText(QApplication::translate("EditAuthority", "\345\272\223\345\255\230\350\260\203\346\225\264", 0));
        checkBoxCheck->setText(QApplication::translate("EditAuthority", "\345\272\223\345\255\230\347\233\230\347\202\271", 0));
        checkBoxChange->setText(QApplication::translate("EditAuthority", "\345\272\223\345\255\230\345\217\230\346\233\264\350\256\260\345\275\225", 0));
        checkBoxAllot->setText(QApplication::translate("EditAuthority", "\345\272\227\345\206\205\350\260\203\346\213\250", 0));
        checkBoxReadjust->setText(QApplication::translate("EditAuthority", "\346\210\220\346\234\254\350\260\203\344\273\267\345\215\225", 0));
        checkBoxRestrictions->setText(QApplication::translate("EditAuthority", "\345\272\223\345\255\230\344\270\212\344\270\213\351\231\220", 0));
        groupBoxOther->setTitle(QApplication::translate("EditAuthority", "\345\205\266\344\273\226", 0));
        checkBoxRule->setText(QApplication::translate("EditAuthority", "\346\235\203\351\231\220\346\223\215\344\275\234", 0));
        checkBoxDefaultSupplier->setText(QApplication::translate("EditAuthority", "\345\216\237\346\226\231\344\276\233\345\272\224\345\225\206", 0));
        checkBoxAccount->setText(QApplication::translate("EditAuthority", "\346\224\257\345\207\272\347\273\223\347\256\227", 0));
        checkBoxToday->setText(QApplication::translate("EditAuthority", "\344\273\212\346\227\245\346\212\245\350\241\250", 0));
        checkBoxUser->setText(QApplication::translate("EditAuthority", "\347\224\250\346\210\267\347\256\241\347\220\206", 0));
        groupBox_5->setTitle(QApplication::translate("EditAuthority", "\347\256\241\347\220\206\345\221\230\344\277\241\346\201\257", 0));
        label->setText(QApplication::translate("EditAuthority", "\347\224\250\346\210\267\345\220\215\357\274\232", 0));
        label_2->setText(QApplication::translate("EditAuthority", "\345\257\206\347\240\201\357\274\232", 0));
        pushButtonOk->setText(QApplication::translate("EditAuthority", "\347\241\256\345\256\232", 0));
        pushButtonCancel->setText(QApplication::translate("EditAuthority", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class EditAuthority: public Ui_EditAuthority {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITAUTHORITY_H
