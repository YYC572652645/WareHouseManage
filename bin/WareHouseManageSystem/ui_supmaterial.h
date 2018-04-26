/********************************************************************************
** Form generated from reading UI file 'supmaterial.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPMATERIAL_H
#define UI_SUPMATERIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SupMaterial
{
public:
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonDel;
    QPushButton *pushButtonExtend;
    QGroupBox *groupBoxSelect;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QTableWidget *tableWidgetAllMaterial;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonCancel;

    void setupUi(QWidget *SupMaterial)
    {
        if (SupMaterial->objectName().isEmpty())
            SupMaterial->setObjectName(QStringLiteral("SupMaterial"));
        SupMaterial->resize(736, 608);
        SupMaterial->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(SupMaterial);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableWidget = new QTableWidget(SupMaterial);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButtonAdd = new QPushButton(SupMaterial);
        pushButtonAdd->setObjectName(QStringLiteral("pushButtonAdd"));
        pushButtonAdd->setMinimumSize(QSize(100, 30));
        pushButtonAdd->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/image/addfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonAdd->setIcon(icon);

        horizontalLayout->addWidget(pushButtonAdd);

        pushButtonDel = new QPushButton(SupMaterial);
        pushButtonDel->setObjectName(QStringLiteral("pushButtonDel"));
        pushButtonDel->setMinimumSize(QSize(100, 30));
        pushButtonDel->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/image/\345\210\240 \351\231\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonDel->setIcon(icon1);

        horizontalLayout->addWidget(pushButtonDel);

        pushButtonExtend = new QPushButton(SupMaterial);
        pushButtonExtend->setObjectName(QStringLiteral("pushButtonExtend"));
        pushButtonExtend->setMinimumSize(QSize(100, 30));
        pushButtonExtend->setStyleSheet(QStringLiteral(""));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/image/export.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonExtend->setIcon(icon2);

        horizontalLayout->addWidget(pushButtonExtend);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(verticalLayout);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        groupBoxSelect = new QGroupBox(SupMaterial);
        groupBoxSelect->setObjectName(QStringLiteral("groupBoxSelect"));
        groupBoxSelect->setMinimumSize(QSize(300, 300));
        groupBoxSelect->setStyleSheet(QLatin1String("QGroupBox\n"
"{\n"
"color: rgb(0, 0, 0);\n"
"font-size:14px;\n"
"font-weight:bold;\n"
"}"));
        verticalLayout_6 = new QVBoxLayout(groupBoxSelect);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(3, 3, 3, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        tableWidgetAllMaterial = new QTableWidget(groupBoxSelect);
        if (tableWidgetAllMaterial->columnCount() < 2)
            tableWidgetAllMaterial->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetAllMaterial->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetAllMaterial->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        tableWidgetAllMaterial->setObjectName(QStringLiteral("tableWidgetAllMaterial"));

        verticalLayout_5->addWidget(tableWidgetAllMaterial);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButtonSave = new QPushButton(groupBoxSelect);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        pushButtonSave->setMinimumSize(QSize(100, 30));
        pushButtonSave->setStyleSheet(QStringLiteral(""));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSave->setIcon(icon3);

        horizontalLayout_2->addWidget(pushButtonSave);

        pushButtonCancel = new QPushButton(groupBoxSelect);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setMinimumSize(QSize(100, 30));
        pushButtonCancel->setStyleSheet(QStringLiteral(""));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/image/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon4);

        horizontalLayout_2->addWidget(pushButtonCancel);


        verticalLayout_5->addLayout(horizontalLayout_2);


        verticalLayout_6->addLayout(verticalLayout_5);


        horizontalLayout_4->addWidget(groupBoxSelect);


        verticalLayout_2->addLayout(horizontalLayout_4);


        retranslateUi(SupMaterial);

        QMetaObject::connectSlotsByName(SupMaterial);
    } // setupUi

    void retranslateUi(QWidget *SupMaterial)
    {
        SupMaterial->setWindowTitle(QApplication::translate("SupMaterial", "Form", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("SupMaterial", "\345\216\237\346\226\231\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("SupMaterial", "\345\216\237\346\226\231\347\274\226\347\240\201", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("SupMaterial", "\346\211\200\345\261\236\345\210\206\347\261\273", 0));
        pushButtonAdd->setText(QApplication::translate("SupMaterial", " \346\267\273\345\212\240", 0));
        pushButtonDel->setText(QApplication::translate("SupMaterial", " \345\210\240\351\231\244", 0));
        pushButtonExtend->setText(QApplication::translate("SupMaterial", " \345\257\274\345\207\272", 0));
        groupBoxSelect->setTitle(QApplication::translate("SupMaterial", "\351\200\211\346\213\251\345\216\237\346\226\231", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetAllMaterial->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("SupMaterial", "\345\216\237\346\226\231\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetAllMaterial->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("SupMaterial", "\345\216\237\346\226\231\347\274\226\347\240\201", 0));
        pushButtonSave->setText(QApplication::translate("SupMaterial", " \344\277\235\345\255\230", 0));
        pushButtonCancel->setText(QApplication::translate("SupMaterial", " \345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class SupMaterial: public Ui_SupMaterial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPMATERIAL_H
