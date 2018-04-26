/********************************************************************************
** Form generated from reading UI file 'edittemplate.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITTEMPLATE_H
#define UI_EDITTEMPLATE_H

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

class Ui_EditTemplate
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *tableWidgetData;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBoxAllSelect;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonCancel;

    void setupUi(QWidget *EditTemplate)
    {
        if (EditTemplate->objectName().isEmpty())
            EditTemplate->setObjectName(QStringLiteral("EditTemplate"));
        EditTemplate->resize(577, 545);
        EditTemplate->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(EditTemplate);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        tableWidgetData = new QTableWidget(EditTemplate);
        if (tableWidgetData->columnCount() < 2)
            tableWidgetData->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidgetData->setObjectName(QStringLiteral("tableWidgetData"));

        verticalLayout->addWidget(tableWidgetData);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        checkBoxAllSelect = new QCheckBox(EditTemplate);
        checkBoxAllSelect->setObjectName(QStringLiteral("checkBoxAllSelect"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\345\205\250\351\200\211.png"), QSize(), QIcon::Normal, QIcon::Off);
        checkBoxAllSelect->setIcon(icon);

        horizontalLayout_2->addWidget(checkBoxAllSelect);

        pushButtonSave = new QPushButton(EditTemplate);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        pushButtonSave->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSave->setIcon(icon1);

        horizontalLayout_2->addWidget(pushButtonSave);

        pushButtonCancel = new QPushButton(EditTemplate);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon2);

        horizontalLayout_2->addWidget(pushButtonCancel);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(EditTemplate);

        QMetaObject::connectSlotsByName(EditTemplate);
    } // setupUi

    void retranslateUi(QWidget *EditTemplate)
    {
        EditTemplate->setWindowTitle(QApplication::translate("EditTemplate", "Form", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetData->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("EditTemplate", "\345\216\237\346\226\231\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetData->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("EditTemplate", "\345\216\237\346\226\231\347\274\226\347\240\201", 0));
        checkBoxAllSelect->setText(QApplication::translate("EditTemplate", "\345\205\250\351\200\211", 0));
        pushButtonSave->setText(QApplication::translate("EditTemplate", " \344\277\235\345\255\230", 0));
        pushButtonCancel->setText(QApplication::translate("EditTemplate", " \345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class EditTemplate: public Ui_EditTemplate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITTEMPLATE_H
