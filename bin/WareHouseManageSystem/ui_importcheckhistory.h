/********************************************************************************
** Form generated from reading UI file 'importcheckhistory.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPORTCHECKHISTORY_H
#define UI_IMPORTCHECKHISTORY_H

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

class Ui_ImportCheckHistory
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

    void setupUi(QWidget *ImportCheckHistory)
    {
        if (ImportCheckHistory->objectName().isEmpty())
            ImportCheckHistory->setObjectName(QStringLiteral("ImportCheckHistory"));
        ImportCheckHistory->resize(658, 589);
        verticalLayout_2 = new QVBoxLayout(ImportCheckHistory);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(6, 6, 6, 6);
        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableWidgetData = new QTableWidget(ImportCheckHistory);
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
        pushButtonImport = new QPushButton(ImportCheckHistory);
        pushButtonImport->setObjectName(QStringLiteral("pushButtonImport"));
        pushButtonImport->setMinimumSize(QSize(0, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\347\241\256\350\256\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonImport->setIcon(icon);

        horizontalLayout->addWidget(pushButtonImport);

        pushButtonCancel = new QPushButton(ImportCheckHistory);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon1);

        horizontalLayout->addWidget(pushButtonCancel);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(ImportCheckHistory);

        QMetaObject::connectSlotsByName(ImportCheckHistory);
    } // setupUi

    void retranslateUi(QWidget *ImportCheckHistory)
    {
        ImportCheckHistory->setWindowTitle(QApplication::translate("ImportCheckHistory", "Form", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetData->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ImportCheckHistory", "\344\273\223\345\272\223\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetData->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ImportCheckHistory", "\350\260\203\346\225\264\345\215\225\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetData->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ImportCheckHistory", "\347\233\230\345\255\230\346\227\245\346\234\237", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetData->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ImportCheckHistory", "\347\212\266\346\200\201", 0));
        pushButtonImport->setText(QApplication::translate("ImportCheckHistory", " \345\257\274\345\205\245", 0));
        pushButtonCancel->setText(QApplication::translate("ImportCheckHistory", " \345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class ImportCheckHistory: public Ui_ImportCheckHistory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPORTCHECKHISTORY_H
