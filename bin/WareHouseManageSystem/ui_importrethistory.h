/********************************************************************************
** Form generated from reading UI file 'importrethistory.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPORTRETHISTORY_H
#define UI_IMPORTRETHISTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImportRetHistory
{
public:
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidgetData;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonImport;
    QPushButton *pushButtonCancel;

    void setupUi(QWidget *ImportRetHistory)
    {
        if (ImportRetHistory->objectName().isEmpty())
            ImportRetHistory->setObjectName(QStringLiteral("ImportRetHistory"));
        ImportRetHistory->resize(611, 537);
        verticalLayout_2 = new QVBoxLayout(ImportRetHistory);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(6, 6, 6, 6);
        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableWidgetData = new QTableWidget(ImportRetHistory);
        if (tableWidgetData->columnCount() < 4)
            tableWidgetData->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidgetData->setObjectName(QStringLiteral("tableWidgetData"));

        verticalLayout->addWidget(tableWidgetData);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButtonImport = new QPushButton(ImportRetHistory);
        pushButtonImport->setObjectName(QStringLiteral("pushButtonImport"));
        pushButtonImport->setMinimumSize(QSize(0, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\347\241\256\350\256\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonImport->setIcon(icon);

        horizontalLayout->addWidget(pushButtonImport);

        pushButtonCancel = new QPushButton(ImportRetHistory);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon1);

        horizontalLayout->addWidget(pushButtonCancel);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(ImportRetHistory);

        QMetaObject::connectSlotsByName(ImportRetHistory);
    } // setupUi

    void retranslateUi(QWidget *ImportRetHistory)
    {
        ImportRetHistory->setWindowTitle(QApplication::translate("ImportRetHistory", "Form", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetData->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ImportRetHistory", "\344\276\233\345\272\224\345\225\206", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetData->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ImportRetHistory", "\351\200\200\350\264\247\345\215\225\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetData->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ImportRetHistory", "\351\200\200\350\264\247\346\227\245\346\234\237", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetData->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ImportRetHistory", "\347\212\266\346\200\201", 0));
        pushButtonImport->setText(QApplication::translate("ImportRetHistory", " \345\257\274\345\205\245", 0));
        pushButtonCancel->setText(QApplication::translate("ImportRetHistory", " \345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class ImportRetHistory: public Ui_ImportRetHistory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPORTRETHISTORY_H
