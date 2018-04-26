/********************************************************************************
** Form generated from reading UI file 'accountexport.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTEXPORT_H
#define UI_ACCOUNTEXPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccountExport
{
public:
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidgetAccount;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBoxAllSelect;
    QLabel *labelEmail;
    QLineEdit *lineEditEmail;
    QPushButton *pushButtonExport;

    void setupUi(QWidget *AccountExport)
    {
        if (AccountExport->objectName().isEmpty())
            AccountExport->setObjectName(QStringLiteral("AccountExport"));
        AccountExport->resize(699, 566);
        verticalLayout_2 = new QVBoxLayout(AccountExport);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));

        verticalLayout->addLayout(horizontalLayout);

        tableWidgetAccount = new QTableWidget(AccountExport);
        if (tableWidgetAccount->columnCount() < 5)
            tableWidgetAccount->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetAccount->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetAccount->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetAccount->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetAccount->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetAccount->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidgetAccount->setObjectName(QStringLiteral("tableWidgetAccount"));

        verticalLayout->addWidget(tableWidgetAccount);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        checkBoxAllSelect = new QCheckBox(AccountExport);
        checkBoxAllSelect->setObjectName(QStringLiteral("checkBoxAllSelect"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(11);
        checkBoxAllSelect->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\347\241\256\350\256\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        checkBoxAllSelect->setIcon(icon);

        horizontalLayout_2->addWidget(checkBoxAllSelect);

        labelEmail = new QLabel(AccountExport);
        labelEmail->setObjectName(QStringLiteral("labelEmail"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setWeight(50);
        labelEmail->setFont(font1);

        horizontalLayout_2->addWidget(labelEmail);

        lineEditEmail = new QLineEdit(AccountExport);
        lineEditEmail->setObjectName(QStringLiteral("lineEditEmail"));
        lineEditEmail->setMinimumSize(QSize(0, 30));
        lineEditEmail->setMaximumSize(QSize(16777215, 30));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        lineEditEmail->setFont(font2);

        horizontalLayout_2->addWidget(lineEditEmail);

        pushButtonExport = new QPushButton(AccountExport);
        pushButtonExport->setObjectName(QStringLiteral("pushButtonExport"));
        pushButtonExport->setMinimumSize(QSize(200, 30));
        pushButtonExport->setFont(font1);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/export.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonExport->setIcon(icon1);

        horizontalLayout_2->addWidget(pushButtonExport);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(AccountExport);

        QMetaObject::connectSlotsByName(AccountExport);
    } // setupUi

    void retranslateUi(QWidget *AccountExport)
    {
        AccountExport->setWindowTitle(QApplication::translate("AccountExport", "Form", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetAccount->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("AccountExport", "\344\276\233\345\272\224\345\225\206", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetAccount->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("AccountExport", "\345\215\225\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetAccount->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("AccountExport", "\347\261\273\345\236\213", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetAccount->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("AccountExport", "\346\223\215\344\275\234\346\227\266\351\227\264", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetAccount->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("AccountExport", "\347\212\266\346\200\201", 0));
        checkBoxAllSelect->setText(QApplication::translate("AccountExport", "\345\205\250\351\200\211", 0));
        labelEmail->setText(QApplication::translate("AccountExport", "\351\202\256\347\256\261\357\274\232", 0));
        pushButtonExport->setText(QApplication::translate("AccountExport", " \345\257\274\345\207\272", 0));
    } // retranslateUi

};

namespace Ui {
    class AccountExport: public Ui_AccountExport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTEXPORT_H
