/********************************************************************************
** Form generated from reading UI file 'timematinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMEMATINFO_H
#define UI_TIMEMATINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TimeMatInfo
{
public:
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditMatInfo;
    QTableWidget *tableWidgetData;
    QLabel *labelInfo;

    void setupUi(QWidget *TimeMatInfo)
    {
        if (TimeMatInfo->objectName().isEmpty())
            TimeMatInfo->setObjectName(QStringLiteral("TimeMatInfo"));
        TimeMatInfo->resize(684, 527);
        verticalLayout_2 = new QVBoxLayout(TimeMatInfo);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(TimeMatInfo);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        lineEditMatInfo = new QLineEdit(TimeMatInfo);
        lineEditMatInfo->setObjectName(QStringLiteral("lineEditMatInfo"));
        lineEditMatInfo->setEnabled(false);
        lineEditMatInfo->setMinimumSize(QSize(220, 30));
        lineEditMatInfo->setMaximumSize(QSize(220, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        lineEditMatInfo->setFont(font1);
        lineEditMatInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(lineEditMatInfo);


        verticalLayout->addLayout(horizontalLayout);

        tableWidgetData = new QTableWidget(TimeMatInfo);
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
        tableWidgetData->setEnabled(false);
        tableWidgetData->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(tableWidgetData);

        labelInfo = new QLabel(TimeMatInfo);
        labelInfo->setObjectName(QStringLiteral("labelInfo"));
        labelInfo->setMinimumSize(QSize(0, 40));
        labelInfo->setMaximumSize(QSize(16777215, 40));
        labelInfo->setFont(font);
        labelInfo->setStyleSheet(QStringLiteral(""));
        labelInfo->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(labelInfo);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(TimeMatInfo);

        QMetaObject::connectSlotsByName(TimeMatInfo);
    } // setupUi

    void retranslateUi(QWidget *TimeMatInfo)
    {
        label->setText(QApplication::translate("TimeMatInfo", "\345\216\237\346\226\231\345\220\215\347\247\260\357\274\232", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetData->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("TimeMatInfo", "\344\273\223\345\272\223\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetData->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("TimeMatInfo", "\345\272\223\345\255\230\351\207\221\351\242\235", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetData->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("TimeMatInfo", "\345\272\223\345\255\230\346\225\260", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetData->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("TimeMatInfo", "\345\215\225\344\275\215", 0));
        labelInfo->setText(QApplication::translate("TimeMatInfo", "\345\220\210\350\256\241\357\274\232", 0));
        Q_UNUSED(TimeMatInfo);
    } // retranslateUi

};

namespace Ui {
    class TimeMatInfo: public Ui_TimeMatInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMEMATINFO_H
