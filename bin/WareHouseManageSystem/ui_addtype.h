/********************************************************************************
** Form generated from reading UI file 'addtype.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTYPE_H
#define UI_ADDTYPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddType
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButtonOk;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButtonCancel;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QWidget *AddType)
    {
        if (AddType->objectName().isEmpty())
            AddType->setObjectName(QStringLiteral("AddType"));
        AddType->resize(370, 166);
        verticalLayout = new QVBoxLayout(AddType);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(AddType);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(AddType);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        pushButtonOk = new QPushButton(AddType);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));
        pushButtonOk->setMinimumSize(QSize(100, 30));
        pushButtonOk->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\347\241\256\350\256\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonOk->setIcon(icon);

        horizontalLayout_2->addWidget(pushButtonOk);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        pushButtonCancel = new QPushButton(AddType);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setMinimumSize(QSize(100, 30));
        pushButtonCancel->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon1);

        horizontalLayout_2->addWidget(pushButtonCancel);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(AddType);

        QMetaObject::connectSlotsByName(AddType);
    } // setupUi

    void retranslateUi(QWidget *AddType)
    {
        AddType->setWindowTitle(QApplication::translate("AddType", "Form", 0));
        label->setText(QApplication::translate("AddType", "\344\276\233\345\272\224\345\225\206\345\210\206\347\261\273\345\220\215\347\247\260\357\274\232", 0));
        pushButtonOk->setText(QApplication::translate("AddType", " \347\241\256\345\256\232", 0));
        pushButtonCancel->setText(QApplication::translate("AddType", " \345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class AddType: public Ui_AddType {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTYPE_H
