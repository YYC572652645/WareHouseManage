/********************************************************************************
** Form generated from reading UI file 'setdefaultsup.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETDEFAULTSUP_H
#define UI_SETDEFAULTSUP_H

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

class Ui_SetDefaultSup
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditMatNumber;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *comboBoxSupplier;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonCancel;

    void setupUi(QWidget *SetDefaultSup)
    {
        if (SetDefaultSup->objectName().isEmpty())
            SetDefaultSup->setObjectName(QStringLiteral("SetDefaultSup"));
        SetDefaultSup->resize(485, 397);
        verticalLayout = new QVBoxLayout(SetDefaultSup);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(SetDefaultSup);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEditMatNumber = new QLineEdit(SetDefaultSup);
        lineEditMatNumber->setObjectName(QStringLiteral("lineEditMatNumber"));
        lineEditMatNumber->setEnabled(false);
        lineEditMatNumber->setMinimumSize(QSize(250, 30));
        lineEditMatNumber->setMaximumSize(QSize(250, 30));
        lineEditMatNumber->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(lineEditMatNumber);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(SetDefaultSup);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        comboBoxSupplier = new QComboBox(SetDefaultSup);
        comboBoxSupplier->setObjectName(QStringLiteral("comboBoxSupplier"));
        comboBoxSupplier->setMinimumSize(QSize(250, 30));
        comboBoxSupplier->setMaximumSize(QSize(250, 30));
        comboBoxSupplier->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        horizontalLayout_4->addWidget(comboBoxSupplier);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButtonSave = new QPushButton(SetDefaultSup);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\347\241\256\350\256\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSave->setIcon(icon);

        horizontalLayout_5->addWidget(pushButtonSave);

        pushButtonCancel = new QPushButton(SetDefaultSup);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon1);

        horizontalLayout_5->addWidget(pushButtonCancel);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(SetDefaultSup);

        QMetaObject::connectSlotsByName(SetDefaultSup);
    } // setupUi

    void retranslateUi(QWidget *SetDefaultSup)
    {
        SetDefaultSup->setWindowTitle(QApplication::translate("SetDefaultSup", "Form", 0));
        label->setText(QApplication::translate("SetDefaultSup", "\345\216\237\346\226\231\357\274\232", 0));
        label_4->setText(QApplication::translate("SetDefaultSup", "\351\273\230\350\256\244\344\276\233\345\272\224\345\225\206\357\274\232", 0));
        pushButtonSave->setText(QApplication::translate("SetDefaultSup", " \344\277\235\345\255\230", 0));
        pushButtonCancel->setText(QApplication::translate("SetDefaultSup", " \345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class SetDefaultSup: public Ui_SetDefaultSup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETDEFAULTSUP_H
