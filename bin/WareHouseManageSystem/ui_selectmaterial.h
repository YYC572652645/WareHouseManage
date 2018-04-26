/********************************************************************************
** Form generated from reading UI file 'selectmaterial.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTMATERIAL_H
#define UI_SELECTMATERIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectMaterial
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *tableWidget;

    void setupUi(QWidget *SelectMaterial)
    {
        if (SelectMaterial->objectName().isEmpty())
            SelectMaterial->setObjectName(QStringLiteral("SelectMaterial"));
        SelectMaterial->resize(598, 568);
        verticalLayout = new QVBoxLayout(SelectMaterial);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(3, 3, 3, 3);
        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        tableWidget = new QTableWidget(SelectMaterial);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);


        retranslateUi(SelectMaterial);

        QMetaObject::connectSlotsByName(SelectMaterial);
    } // setupUi

    void retranslateUi(QWidget *SelectMaterial)
    {
        SelectMaterial->setWindowTitle(QApplication::translate("SelectMaterial", "Form", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("SelectMaterial", "\345\216\237\346\226\231\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("SelectMaterial", "\345\216\237\346\226\231\347\274\226\347\240\201", 0));
    } // retranslateUi

};

namespace Ui {
    class SelectMaterial: public Ui_SelectMaterial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTMATERIAL_H
