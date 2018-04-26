/********************************************************************************
** Form generated from reading UI file 'templatepur.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEMPLATEPUR_H
#define UI_TEMPLATEPUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TemplatePur
{
public:
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *listWidgetData;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidgetSetNumber;
    QHBoxLayout *horizontalLayout;
    QLabel *labelSize;
    QCommandLinkButton *commandLinkButtonOrder;

    void setupUi(QWidget *TemplatePur)
    {
        if (TemplatePur->objectName().isEmpty())
            TemplatePur->setObjectName(QStringLiteral("TemplatePur"));
        TemplatePur->resize(865, 587);
        verticalLayout_2 = new QVBoxLayout(TemplatePur);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        listWidgetData = new QListWidget(TemplatePur);
        listWidgetData->setObjectName(QStringLiteral("listWidgetData"));

        horizontalLayout_2->addWidget(listWidgetData);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableWidgetSetNumber = new QTableWidget(TemplatePur);
        if (tableWidgetSetNumber->columnCount() < 5)
            tableWidgetSetNumber->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetSetNumber->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetSetNumber->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetSetNumber->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetSetNumber->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetSetNumber->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidgetSetNumber->setObjectName(QStringLiteral("tableWidgetSetNumber"));
        tableWidgetSetNumber->setMinimumSize(QSize(600, 0));

        verticalLayout->addWidget(tableWidgetSetNumber);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelSize = new QLabel(TemplatePur);
        labelSize->setObjectName(QStringLiteral("labelSize"));

        horizontalLayout->addWidget(labelSize);

        commandLinkButtonOrder = new QCommandLinkButton(TemplatePur);
        commandLinkButtonOrder->setObjectName(QStringLiteral("commandLinkButtonOrder"));
        commandLinkButtonOrder->setMaximumSize(QSize(200, 16777215));

        horizontalLayout->addWidget(commandLinkButtonOrder);

        horizontalLayout->setStretch(1, 2);

        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(TemplatePur);

        QMetaObject::connectSlotsByName(TemplatePur);
    } // setupUi

    void retranslateUi(QWidget *TemplatePur)
    {
        TemplatePur->setWindowTitle(QApplication::translate("TemplatePur", "Form", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetSetNumber->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("TemplatePur", "\345\216\237\346\226\231\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetSetNumber->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("TemplatePur", "\346\235\241\345\275\242\347\240\201", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetSetNumber->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("TemplatePur", "\345\272\223\345\255\230", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetSetNumber->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("TemplatePur", "\345\216\237\346\226\231\346\225\260\351\207\217", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetSetNumber->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("TemplatePur", "\345\215\225\344\275\215", 0));
        labelSize->setText(QString());
        commandLinkButtonOrder->setText(QApplication::translate("TemplatePur", "\347\224\237\346\210\220\351\207\207\350\264\255\350\256\242\345\215\225", 0));
    } // retranslateUi

};

namespace Ui {
    class TemplatePur: public Ui_TemplatePur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEMPLATEPUR_H
