/********************************************************************************
** Form generated from reading UI file 'addtranmaterial.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTRANMATERIAL_H
#define UI_ADDTRANMATERIAL_H

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

class Ui_addtranmaterial
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

    void setupUi(QWidget *addtranmaterial)
    {
        if (addtranmaterial->objectName().isEmpty())
            addtranmaterial->setObjectName(QStringLiteral("addtranmaterial"));
        addtranmaterial->resize(577, 545);
        addtranmaterial->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(addtranmaterial);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        tableWidgetData = new QTableWidget(addtranmaterial);
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

        tableWidgetEditData = new QTableWidget(addtranmaterial);
        if (tableWidgetEditData->columnCount() < 5)
            tableWidgetEditData->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidgetEditData->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidgetEditData->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidgetEditData->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidgetEditData->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidgetEditData->setHorizontalHeaderItem(4, __qtablewidgetitem9);
        tableWidgetEditData->setObjectName(QStringLiteral("tableWidgetEditData"));

        verticalLayout->addWidget(tableWidgetEditData);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        checkBoxAllSelect = new QCheckBox(addtranmaterial);
        checkBoxAllSelect->setObjectName(QStringLiteral("checkBoxAllSelect"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\345\205\250\351\200\211.png"), QSize(), QIcon::Normal, QIcon::Off);
        checkBoxAllSelect->setIcon(icon);

        horizontalLayout_2->addWidget(checkBoxAllSelect);

        pushButtonSave = new QPushButton(addtranmaterial);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        pushButtonSave->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSave->setIcon(icon1);

        horizontalLayout_2->addWidget(pushButtonSave);

        pushButtonDel = new QPushButton(addtranmaterial);
        pushButtonDel->setObjectName(QStringLiteral("pushButtonDel"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/image/\345\210\240 \351\231\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonDel->setIcon(icon2);

        horizontalLayout_2->addWidget(pushButtonDel);

        pushButtonCancel = new QPushButton(addtranmaterial);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon3);

        horizontalLayout_2->addWidget(pushButtonCancel);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(addtranmaterial);

        QMetaObject::connectSlotsByName(addtranmaterial);
    } // setupUi

    void retranslateUi(QWidget *addtranmaterial)
    {
        addtranmaterial->setWindowTitle(QApplication::translate("addtranmaterial", "Form", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetData->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("addtranmaterial", "\345\216\237\346\226\231\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetData->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("addtranmaterial", "\345\216\237\346\226\231\347\274\226\347\240\201", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetData->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("addtranmaterial", "\345\215\225\344\273\267", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetData->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("addtranmaterial", "\346\225\260\351\207\217", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetData->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("addtranmaterial", "\345\215\225\344\275\215", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetEditData->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("addtranmaterial", "\345\216\237\346\226\231\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetEditData->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("addtranmaterial", "\345\216\237\346\226\231\347\274\226\347\240\201", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidgetEditData->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QApplication::translate("addtranmaterial", "\345\215\225\344\273\267", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidgetEditData->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QApplication::translate("addtranmaterial", "\346\225\260\351\207\217", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidgetEditData->horizontalHeaderItem(4);
        ___qtablewidgetitem9->setText(QApplication::translate("addtranmaterial", "\345\215\225\344\275\215", 0));
        checkBoxAllSelect->setText(QApplication::translate("addtranmaterial", "\345\205\250\351\200\211", 0));
        pushButtonSave->setText(QApplication::translate("addtranmaterial", " \344\277\235\345\255\230", 0));
        pushButtonDel->setText(QApplication::translate("addtranmaterial", " \345\210\240\351\231\244", 0));
        pushButtonCancel->setText(QApplication::translate("addtranmaterial", " \345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class addtranmaterial: public Ui_addtranmaterial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTRANMATERIAL_H
