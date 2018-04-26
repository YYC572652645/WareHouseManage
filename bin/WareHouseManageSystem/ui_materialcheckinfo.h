/********************************************************************************
** Form generated from reading UI file 'materialcheckinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATERIALCHECKINFO_H
#define UI_MATERIALCHECKINFO_H

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

class Ui_MaterialCheckInfo
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *tableWidgetData;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonCancel;

    void setupUi(QWidget *MaterialCheckInfo)
    {
        if (MaterialCheckInfo->objectName().isEmpty())
            MaterialCheckInfo->setObjectName(QStringLiteral("MaterialCheckInfo"));
        MaterialCheckInfo->resize(617, 512);
        verticalLayout = new QVBoxLayout(MaterialCheckInfo);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        tableWidgetData = new QTableWidget(MaterialCheckInfo);
        if (tableWidgetData->columnCount() < 5)
            tableWidgetData->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidgetData->setObjectName(QStringLiteral("tableWidgetData"));

        verticalLayout->addWidget(tableWidgetData);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButtonAdd = new QPushButton(MaterialCheckInfo);
        pushButtonAdd->setObjectName(QStringLiteral("pushButtonAdd"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/image/addfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonAdd->setIcon(icon);

        horizontalLayout->addWidget(pushButtonAdd);

        pushButtonSave = new QPushButton(MaterialCheckInfo);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/image/\347\241\256\350\256\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSave->setIcon(icon1);

        horizontalLayout->addWidget(pushButtonSave);

        pushButtonCancel = new QPushButton(MaterialCheckInfo);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon2);

        horizontalLayout->addWidget(pushButtonCancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(MaterialCheckInfo);

        QMetaObject::connectSlotsByName(MaterialCheckInfo);
    } // setupUi

    void retranslateUi(QWidget *MaterialCheckInfo)
    {
        MaterialCheckInfo->setWindowTitle(QApplication::translate("MaterialCheckInfo", "Form", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetData->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MaterialCheckInfo", "\345\216\237\346\226\231\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetData->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MaterialCheckInfo", "\346\235\241\345\275\242\347\240\201", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetData->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MaterialCheckInfo", "\345\215\225\344\273\267", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetData->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MaterialCheckInfo", "\345\256\236\351\231\205\346\225\260\351\207\217", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetData->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MaterialCheckInfo", "\347\233\230\345\255\230\345\215\225\344\275\215", 0));
        pushButtonAdd->setText(QApplication::translate("MaterialCheckInfo", " \346\267\273\345\212\240\345\216\237\346\226\231", 0));
        pushButtonSave->setText(QApplication::translate("MaterialCheckInfo", " \344\277\235\345\255\230", 0));
        pushButtonCancel->setText(QApplication::translate("MaterialCheckInfo", " \345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class MaterialCheckInfo: public Ui_MaterialCheckInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATERIALCHECKINFO_H
