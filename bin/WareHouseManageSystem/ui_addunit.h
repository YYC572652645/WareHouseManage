/********************************************************************************
** Form generated from reading UI file 'addunit.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDUNIT_H
#define UI_ADDUNIT_H

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

class Ui_AddUnit
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

    void setupUi(QWidget *AddUnit)
    {
        if (AddUnit->objectName().isEmpty())
            AddUnit->setObjectName(QStringLiteral("AddUnit"));
        AddUnit->resize(381, 177);
        verticalLayout = new QVBoxLayout(AddUnit);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(AddUnit);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(AddUnit);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        pushButtonOk = new QPushButton(AddUnit);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));
        pushButtonOk->setMinimumSize(QSize(100, 30));
        pushButtonOk->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\347\241\256\350\256\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonOk->setIcon(icon);

        horizontalLayout_2->addWidget(pushButtonOk);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        pushButtonCancel = new QPushButton(AddUnit);
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


        retranslateUi(AddUnit);

        QMetaObject::connectSlotsByName(AddUnit);
    } // setupUi

    void retranslateUi(QWidget *AddUnit)
    {
        AddUnit->setWindowTitle(QApplication::translate("AddUnit", "Form", 0));
        label->setText(QApplication::translate("AddUnit", "\345\215\225\344\275\215\345\220\215\347\247\260\357\274\232", 0));
        pushButtonOk->setText(QApplication::translate("AddUnit", " \347\241\256\345\256\232", 0));
        pushButtonCancel->setText(QApplication::translate("AddUnit", " \345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class AddUnit: public Ui_AddUnit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDUNIT_H
