/********************************************************************************
** Form generated from reading UI file 'reasonwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REASONWIDGET_H
#define UI_REASONWIDGET_H

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

class Ui_ReasonWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonOk;
    QPushButton *pushButtonCancel;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonDel;

    void setupUi(QWidget *ReasonWidget)
    {
        if (ReasonWidget->objectName().isEmpty())
            ReasonWidget->setObjectName(QStringLiteral("ReasonWidget"));
        ReasonWidget->resize(410, 327);
        verticalLayout_2 = new QVBoxLayout(ReasonWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        tableWidget = new QTableWidget(ReasonWidget);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButtonOk = new QPushButton(ReasonWidget);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));
        pushButtonOk->setMaximumSize(QSize(100, 16777215));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\347\241\256\350\256\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonOk->setIcon(icon);

        horizontalLayout->addWidget(pushButtonOk);

        pushButtonCancel = new QPushButton(ReasonWidget);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setMaximumSize(QSize(100, 16777215));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon1);

        horizontalLayout->addWidget(pushButtonCancel);

        pushButtonAdd = new QPushButton(ReasonWidget);
        pushButtonAdd->setObjectName(QStringLiteral("pushButtonAdd"));
        pushButtonAdd->setMaximumSize(QSize(100, 16777215));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/image/addfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonAdd->setIcon(icon2);

        horizontalLayout->addWidget(pushButtonAdd);

        pushButtonDel = new QPushButton(ReasonWidget);
        pushButtonDel->setObjectName(QStringLiteral("pushButtonDel"));
        pushButtonDel->setMaximumSize(QSize(100, 16777215));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/image/\345\210\240 \351\231\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonDel->setIcon(icon3);

        horizontalLayout->addWidget(pushButtonDel);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(ReasonWidget);

        QMetaObject::connectSlotsByName(ReasonWidget);
    } // setupUi

    void retranslateUi(QWidget *ReasonWidget)
    {
        ReasonWidget->setWindowTitle(QApplication::translate("ReasonWidget", "Form", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ReasonWidget", "\345\216\237\345\233\240", 0));
        pushButtonOk->setText(QApplication::translate("ReasonWidget", " \347\241\256\345\256\232", 0));
        pushButtonCancel->setText(QApplication::translate("ReasonWidget", " \345\217\226\346\266\210", 0));
        pushButtonAdd->setText(QApplication::translate("ReasonWidget", " \346\267\273\345\212\240", 0));
        pushButtonDel->setText(QApplication::translate("ReasonWidget", " \345\210\240\351\231\244", 0));
    } // retranslateUi

};

namespace Ui {
    class ReasonWidget: public Ui_ReasonWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REASONWIDGET_H
