/********************************************************************************
** Form generated from reading UI file 'confirmsafemat.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRMSAFEMAT_H
#define UI_CONFIRMSAFEMAT_H

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

class Ui_ConfirmSafeMat
{
public:
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidgetData;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonConfirm;
    QPushButton *pushButtonCancel;

    void setupUi(QWidget *ConfirmSafeMat)
    {
        if (ConfirmSafeMat->objectName().isEmpty())
            ConfirmSafeMat->setObjectName(QStringLiteral("ConfirmSafeMat"));
        ConfirmSafeMat->resize(474, 442);
        verticalLayout_2 = new QVBoxLayout(ConfirmSafeMat);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(3, 3, 3, 3);
        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableWidgetData = new QTableWidget(ConfirmSafeMat);
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
        tableWidgetData->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(tableWidgetData);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButtonConfirm = new QPushButton(ConfirmSafeMat);
        pushButtonConfirm->setObjectName(QStringLiteral("pushButtonConfirm"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\347\241\256\350\256\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonConfirm->setIcon(icon);

        horizontalLayout->addWidget(pushButtonConfirm);

        pushButtonCancel = new QPushButton(ConfirmSafeMat);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon1);

        horizontalLayout->addWidget(pushButtonCancel);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(ConfirmSafeMat);

        QMetaObject::connectSlotsByName(ConfirmSafeMat);
    } // setupUi

    void retranslateUi(QWidget *ConfirmSafeMat)
    {
        ConfirmSafeMat->setWindowTitle(QApplication::translate("ConfirmSafeMat", "Form", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetData->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ConfirmSafeMat", "\345\216\237\346\226\231\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetData->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ConfirmSafeMat", "\345\216\237\346\226\231\347\274\226\347\240\201", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetData->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ConfirmSafeMat", "\346\225\260\351\207\217", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetData->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ConfirmSafeMat", "\345\215\225\344\275\215", 0));
        pushButtonConfirm->setText(QApplication::translate("ConfirmSafeMat", " \347\241\256\350\256\244\351\207\207\350\264\255", 0));
        pushButtonCancel->setText(QApplication::translate("ConfirmSafeMat", " \345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class ConfirmSafeMat: public Ui_ConfirmSafeMat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRMSAFEMAT_H
