/********************************************************************************
** Form generated from reading UI file 'addcheckmat.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCHECKMAT_H
#define UI_ADDCHECKMAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddCheckMat
{
public:
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidgetData;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBoxAllSelect;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonCancel;

    void setupUi(QWidget *AddCheckMat)
    {
        if (AddCheckMat->objectName().isEmpty())
            AddCheckMat->setObjectName(QStringLiteral("AddCheckMat"));
        AddCheckMat->resize(472, 433);
        verticalLayout_2 = new QVBoxLayout(AddCheckMat);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableWidgetData = new QTableWidget(AddCheckMat);
        if (tableWidgetData->columnCount() < 2)
            tableWidgetData->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidgetData->setObjectName(QStringLiteral("tableWidgetData"));

        verticalLayout->addWidget(tableWidgetData);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        checkBoxAllSelect = new QCheckBox(AddCheckMat);
        checkBoxAllSelect->setObjectName(QStringLiteral("checkBoxAllSelect"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\345\205\250\351\200\211.png"), QSize(), QIcon::Normal, QIcon::Off);
        checkBoxAllSelect->setIcon(icon);

        horizontalLayout->addWidget(checkBoxAllSelect);

        pushButtonSave = new QPushButton(AddCheckMat);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/image/\347\241\256\350\256\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSave->setIcon(icon1);

        horizontalLayout->addWidget(pushButtonSave);

        pushButtonCancel = new QPushButton(AddCheckMat);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon2);

        horizontalLayout->addWidget(pushButtonCancel);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(AddCheckMat);

        QMetaObject::connectSlotsByName(AddCheckMat);
    } // setupUi

    void retranslateUi(QWidget *AddCheckMat)
    {
        AddCheckMat->setWindowTitle(QApplication::translate("AddCheckMat", "Form", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetData->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("AddCheckMat", "\345\216\237\346\226\231\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetData->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("AddCheckMat", "\346\235\241\345\275\242\347\240\201", 0));
        checkBoxAllSelect->setText(QApplication::translate("AddCheckMat", "\345\205\250\351\200\211", 0));
        pushButtonSave->setText(QApplication::translate("AddCheckMat", " \344\277\235\345\255\230", 0));
        pushButtonCancel->setText(QApplication::translate("AddCheckMat", " \345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class AddCheckMat: public Ui_AddCheckMat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCHECKMAT_H
