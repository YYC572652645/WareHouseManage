/********************************************************************************
** Form generated from reading UI file 'addcommodity.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCOMMODITY_H
#define UI_ADDCOMMODITY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddCommodity
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEditSearch;
    QPushButton *pushButtonSearch;
    QTableWidget *tableWidgetData;
    QTreeWidget *treeWidgetData;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBoxSelect;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonCancel;

    void setupUi(QWidget *AddCommodity)
    {
        if (AddCommodity->objectName().isEmpty())
            AddCommodity->setObjectName(QStringLiteral("AddCommodity"));
        AddCommodity->resize(500, 579);
        AddCommodity->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(AddCommodity);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lineEditSearch = new QLineEdit(AddCommodity);
        lineEditSearch->setObjectName(QStringLiteral("lineEditSearch"));
        lineEditSearch->setMinimumSize(QSize(0, 30));

        horizontalLayout_3->addWidget(lineEditSearch);

        pushButtonSearch = new QPushButton(AddCommodity);
        pushButtonSearch->setObjectName(QStringLiteral("pushButtonSearch"));
        pushButtonSearch->setMinimumSize(QSize(120, 30));
        pushButtonSearch->setMaximumSize(QSize(120, 16777215));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\346\237\245\350\257\242.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSearch->setIcon(icon);

        horizontalLayout_3->addWidget(pushButtonSearch);


        verticalLayout->addLayout(horizontalLayout_3);

        tableWidgetData = new QTableWidget(AddCommodity);
        if (tableWidgetData->columnCount() < 1)
            tableWidgetData->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tableWidgetData->setObjectName(QStringLiteral("tableWidgetData"));

        verticalLayout->addWidget(tableWidgetData);

        treeWidgetData = new QTreeWidget(AddCommodity);
        treeWidgetData->setObjectName(QStringLiteral("treeWidgetData"));

        verticalLayout->addWidget(treeWidgetData);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        checkBoxSelect = new QCheckBox(AddCommodity);
        checkBoxSelect->setObjectName(QStringLiteral("checkBoxSelect"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/image/\345\205\250\351\200\211.png"), QSize(), QIcon::Normal, QIcon::Off);
        checkBoxSelect->setIcon(icon1);

        horizontalLayout_2->addWidget(checkBoxSelect);

        pushButtonSave = new QPushButton(AddCommodity);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        pushButtonSave->setMinimumSize(QSize(0, 30));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSave->setIcon(icon2);

        horizontalLayout_2->addWidget(pushButtonSave);

        pushButtonCancel = new QPushButton(AddCommodity);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setMinimumSize(QSize(0, 30));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon3);

        horizontalLayout_2->addWidget(pushButtonCancel);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(AddCommodity);

        QMetaObject::connectSlotsByName(AddCommodity);
    } // setupUi

    void retranslateUi(QWidget *AddCommodity)
    {
        AddCommodity->setWindowTitle(QApplication::translate("AddCommodity", "Form", 0));
        pushButtonSearch->setText(QApplication::translate("AddCommodity", " \346\220\234\347\264\242", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetData->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("AddCommodity", "\345\225\206\345\223\201", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidgetData->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("AddCommodity", "\345\225\206\345\223\201", 0));
        checkBoxSelect->setText(QApplication::translate("AddCommodity", "\345\205\250\351\200\211", 0));
        pushButtonSave->setText(QApplication::translate("AddCommodity", " \344\277\235\345\255\230", 0));
        pushButtonCancel->setText(QApplication::translate("AddCommodity", " \345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class AddCommodity: public Ui_AddCommodity {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCOMMODITY_H
