/********************************************************************************
** Form generated from reading UI file 'addauthority.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDAUTHORITY_H
#define UI_ADDAUTHORITY_H

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

class Ui_AddAuthority
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditUserName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditPassWord;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonOk;
    QPushButton *pushButtonCancel;

    void setupUi(QWidget *AddAuthority)
    {
        if (AddAuthority->objectName().isEmpty())
            AddAuthority->setObjectName(QStringLiteral("AddAuthority"));
        AddAuthority->resize(350, 293);
        AddAuthority->setStyleSheet(QLatin1String("QPushButton:hover\n"
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
"width: 150px;\n"
"border-radius:2px;\n"
"spacing:2px;\n"
"padding: 0px 0px;\n"
"}"));
        verticalLayout = new QVBoxLayout(AddAuthority);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(AddAuthority);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEditUserName = new QLineEdit(AddAuthority);
        lineEditUserName->setObjectName(QStringLiteral("lineEditUserName"));
        lineEditUserName->setMinimumSize(QSize(0, 30));
        lineEditUserName->setMaximumSize(QSize(200, 16777215));

        horizontalLayout->addWidget(lineEditUserName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(AddAuthority);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEditPassWord = new QLineEdit(AddAuthority);
        lineEditPassWord->setObjectName(QStringLiteral("lineEditPassWord"));
        lineEditPassWord->setMinimumSize(QSize(0, 30));
        lineEditPassWord->setMaximumSize(QSize(200, 16777215));
        lineEditPassWord->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        horizontalLayout_2->addWidget(lineEditPassWord);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButtonOk = new QPushButton(AddAuthority);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));
        pushButtonOk->setMinimumSize(QSize(0, 30));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\347\241\256\350\256\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonOk->setIcon(icon);

        horizontalLayout_3->addWidget(pushButtonOk);

        pushButtonCancel = new QPushButton(AddAuthority);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setMinimumSize(QSize(0, 30));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon1);

        horizontalLayout_3->addWidget(pushButtonCancel);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(AddAuthority);

        QMetaObject::connectSlotsByName(AddAuthority);
    } // setupUi

    void retranslateUi(QWidget *AddAuthority)
    {
        AddAuthority->setWindowTitle(QApplication::translate("AddAuthority", "Form", 0));
        label->setText(QApplication::translate("AddAuthority", "\347\224\250\346\210\267\345\220\215\357\274\232", 0));
        label_2->setText(QApplication::translate("AddAuthority", "\345\257\206\347\240\201\357\274\232", 0));
        pushButtonOk->setText(QApplication::translate("AddAuthority", "\347\241\256\345\256\232", 0));
        pushButtonCancel->setText(QApplication::translate("AddAuthority", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class AddAuthority: public Ui_AddAuthority {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDAUTHORITY_H
