/********************************************************************************
** Form generated from reading UI file 'materialinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATERIALINFO_H
#define UI_MATERIALINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MaterialInfo
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditBarCode;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *comboBoxWareHouse;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *comboBoxUnit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *lineEditNumber;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonDel;
    QPushButton *pushButtonCancel;

    void setupUi(QWidget *MaterialInfo)
    {
        if (MaterialInfo->objectName().isEmpty())
            MaterialInfo->setObjectName(QStringLiteral("MaterialInfo"));
        MaterialInfo->resize(403, 426);
        MaterialInfo->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(MaterialInfo);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(MaterialInfo);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEditName = new QLineEdit(MaterialInfo);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));
        lineEditName->setEnabled(false);
        lineEditName->setMinimumSize(QSize(200, 30));
        lineEditName->setMaximumSize(QSize(200, 16777215));
        lineEditName->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(lineEditName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(MaterialInfo);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEditBarCode = new QLineEdit(MaterialInfo);
        lineEditBarCode->setObjectName(QStringLiteral("lineEditBarCode"));
        lineEditBarCode->setEnabled(false);
        lineEditBarCode->setMinimumSize(QSize(200, 30));
        lineEditBarCode->setMaximumSize(QSize(200, 16777215));
        lineEditBarCode->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(lineEditBarCode);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(MaterialInfo);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        comboBoxWareHouse = new QComboBox(MaterialInfo);
        comboBoxWareHouse->setObjectName(QStringLiteral("comboBoxWareHouse"));
        comboBoxWareHouse->setMinimumSize(QSize(200, 30));
        comboBoxWareHouse->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_3->addWidget(comboBoxWareHouse);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(MaterialInfo);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        comboBoxUnit = new QComboBox(MaterialInfo);
        comboBoxUnit->setObjectName(QStringLiteral("comboBoxUnit"));
        comboBoxUnit->setMinimumSize(QSize(200, 30));
        comboBoxUnit->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_4->addWidget(comboBoxUnit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(MaterialInfo);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        lineEditNumber = new QLineEdit(MaterialInfo);
        lineEditNumber->setObjectName(QStringLiteral("lineEditNumber"));
        lineEditNumber->setMinimumSize(QSize(200, 30));
        lineEditNumber->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_5->addWidget(lineEditNumber);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        pushButtonSave = new QPushButton(MaterialInfo);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSave->setIcon(icon);

        horizontalLayout_6->addWidget(pushButtonSave);

        pushButtonDel = new QPushButton(MaterialInfo);
        pushButtonDel->setObjectName(QStringLiteral("pushButtonDel"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/image/\345\210\240 \351\231\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonDel->setIcon(icon1);

        horizontalLayout_6->addWidget(pushButtonDel);

        pushButtonCancel = new QPushButton(MaterialInfo);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon2);

        horizontalLayout_6->addWidget(pushButtonCancel);


        verticalLayout->addLayout(horizontalLayout_6);


        retranslateUi(MaterialInfo);

        QMetaObject::connectSlotsByName(MaterialInfo);
    } // setupUi

    void retranslateUi(QWidget *MaterialInfo)
    {
        MaterialInfo->setWindowTitle(QApplication::translate("MaterialInfo", "Form", 0));
        label->setText(QApplication::translate("MaterialInfo", "\345\216\237\346\226\231\345\220\215\347\247\260\357\274\232", 0));
        label_2->setText(QApplication::translate("MaterialInfo", "\346\235\241\345\275\242\347\240\201\357\274\232", 0));
        label_3->setText(QApplication::translate("MaterialInfo", "\344\273\223\345\272\223\357\274\232", 0));
        label_4->setText(QApplication::translate("MaterialInfo", "\346\266\210\350\200\227\345\215\225\344\275\215\357\274\232", 0));
        label_5->setText(QApplication::translate("MaterialInfo", "\346\266\210\350\200\227\346\225\260\351\207\217", 0));
        pushButtonSave->setText(QApplication::translate("MaterialInfo", " \344\277\235\345\255\230", 0));
        pushButtonDel->setText(QApplication::translate("MaterialInfo", " \345\210\240\351\231\244", 0));
        pushButtonCancel->setText(QApplication::translate("MaterialInfo", " \345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class MaterialInfo: public Ui_MaterialInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATERIALINFO_H
