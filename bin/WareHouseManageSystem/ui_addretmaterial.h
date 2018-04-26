/********************************************************************************
** Form generated from reading UI file 'addretmaterial.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDRETMATERIAL_H
#define UI_ADDRETMATERIAL_H

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

class Ui_addretmaterial
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *tableWidgetData;
    QTableWidget *tableWidgetEditData;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBoxAllSelect;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonDel;
    QPushButton *pushButtonCancel;

    void setupUi(QWidget *addretmaterial)
    {
        if (addretmaterial->objectName().isEmpty())
            addretmaterial->setObjectName(QStringLiteral("addretmaterial"));
        addretmaterial->resize(577, 545);
        addretmaterial->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(addretmaterial);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        tableWidgetData = new QTableWidget(addretmaterial);
        if (tableWidgetData->columnCount() < 2)
            tableWidgetData->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidgetData->setObjectName(QStringLiteral("tableWidgetData"));

        verticalLayout->addWidget(tableWidgetData);

        tableWidgetEditData = new QTableWidget(addretmaterial);
        if (tableWidgetEditData->columnCount() < 2)
            tableWidgetEditData->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetEditData->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetEditData->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        tableWidgetEditData->setObjectName(QStringLiteral("tableWidgetEditData"));

        verticalLayout->addWidget(tableWidgetEditData);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        checkBoxAllSelect = new QCheckBox(addretmaterial);
        checkBoxAllSelect->setObjectName(QStringLiteral("checkBoxAllSelect"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\345\205\250\351\200\211.png"), QSize(), QIcon::Normal, QIcon::Off);
        checkBoxAllSelect->setIcon(icon);

        horizontalLayout_2->addWidget(checkBoxAllSelect);

        pushButtonSave = new QPushButton(addretmaterial);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        pushButtonSave->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSave->setIcon(icon1);

        horizontalLayout_2->addWidget(pushButtonSave);

        pushButtonDel = new QPushButton(addretmaterial);
        pushButtonDel->setObjectName(QStringLiteral("pushButtonDel"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/image/\345\210\240 \351\231\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonDel->setIcon(icon2);

        horizontalLayout_2->addWidget(pushButtonDel);

        pushButtonCancel = new QPushButton(addretmaterial);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon3);

        horizontalLayout_2->addWidget(pushButtonCancel);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(addretmaterial);

        QMetaObject::connectSlotsByName(addretmaterial);
    } // setupUi

    void retranslateUi(QWidget *addretmaterial)
    {
        addretmaterial->setWindowTitle(QApplication::translate("addretmaterial", "Form", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetData->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("addretmaterial", "\345\216\237\346\226\231\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetData->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("addretmaterial", "\345\216\237\346\226\231\347\274\226\347\240\201", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetEditData->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("addretmaterial", "\345\216\237\346\226\231\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetEditData->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("addretmaterial", "\345\216\237\346\226\231\347\274\226\347\240\201", 0));
        checkBoxAllSelect->setText(QApplication::translate("addretmaterial", "\345\205\250\351\200\211", 0));
        pushButtonSave->setText(QApplication::translate("addretmaterial", " \344\277\235\345\255\230", 0));
        pushButtonDel->setText(QApplication::translate("addretmaterial", " \345\210\240\351\231\244", 0));
        pushButtonCancel->setText(QApplication::translate("addretmaterial", " \345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class addretmaterial: public Ui_addretmaterial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDRETMATERIAL_H
