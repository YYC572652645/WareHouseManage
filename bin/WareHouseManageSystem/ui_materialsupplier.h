/********************************************************************************
** Form generated from reading UI file 'materialsupplier.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATERIALSUPPLIER_H
#define UI_MATERIALSUPPLIER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MaterialSupplier
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonAllSelect;
    QPushButton *pushButtonNoSelect;
    QPushButton *pushButtonSetUp;
    QSpacerItem *horizontalSpacer;
    QLabel *labelSize;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *tableWidget;

    void setupUi(QWidget *MaterialSupplier)
    {
        if (MaterialSupplier->objectName().isEmpty())
            MaterialSupplier->setObjectName(QStringLiteral("MaterialSupplier"));
        MaterialSupplier->resize(519, 127);
        MaterialSupplier->setStyleSheet(QLatin1String("QPushButton:hover\n"
"{\n"
"background-color: rgb(180, 85, 100);\n"
"color:white;\n"
"}\n"
"\n"
"QPushButton:hover:pressed\n"
"{\n"
"background-color:rgb(180, 85, 100);\n"
"color:white;\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"background-color:rgb(84, 115, 135);\n"
"color:white;\n"
"\n"
"font-size:12px;\n"
"width:150px;\n"
"border-radius:2px;\n"
"spacing:2px;\n"
"padding: 0px 0px;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(MaterialSupplier);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, -1, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(5, 0, -1, -1);
        widget = new QWidget(MaterialSupplier);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, -1, -1, -1);
        pushButtonAllSelect = new QPushButton(widget);
        pushButtonAllSelect->setObjectName(QStringLiteral("pushButtonAllSelect"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\346\211\271\351\207\217.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonAllSelect->setIcon(icon);

        horizontalLayout->addWidget(pushButtonAllSelect);

        pushButtonNoSelect = new QPushButton(widget);
        pushButtonNoSelect->setObjectName(QStringLiteral("pushButtonNoSelect"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/image/\345\205\250\344\270\215\351\200\211.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonNoSelect->setIcon(icon1);

        horizontalLayout->addWidget(pushButtonNoSelect);

        pushButtonSetUp = new QPushButton(widget);
        pushButtonSetUp->setObjectName(QStringLiteral("pushButtonSetUp"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/image/\347\241\256\350\256\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSetUp->setIcon(icon2);

        horizontalLayout->addWidget(pushButtonSetUp);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        labelSize = new QLabel(widget);
        labelSize->setObjectName(QStringLiteral("labelSize"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        labelSize->setFont(font);

        horizontalLayout->addWidget(labelSize);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout->addWidget(widget);

        tableWidget = new QTableWidget(MaterialSupplier);
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


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(MaterialSupplier);

        QMetaObject::connectSlotsByName(MaterialSupplier);
    } // setupUi

    void retranslateUi(QWidget *MaterialSupplier)
    {
        MaterialSupplier->setWindowTitle(QApplication::translate("MaterialSupplier", "Form", 0));
        pushButtonAllSelect->setText(QApplication::translate("MaterialSupplier", " \345\205\250\351\200\211", 0));
        pushButtonNoSelect->setText(QApplication::translate("MaterialSupplier", " \345\205\250\344\270\215\351\200\211", 0));
        pushButtonSetUp->setText(QApplication::translate("MaterialSupplier", " \346\211\271\351\207\217\350\256\276\347\275\256\344\276\233\345\272\224\345\225\206", 0));
        labelSize->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MaterialSupplier", "\345\216\237\346\226\231\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MaterialSupplier", "\346\235\241\345\275\242\347\240\201", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MaterialSupplier", "\351\273\230\350\256\244\344\276\233\345\272\224\345\225\206", 0));
    } // retranslateUi

};

namespace Ui {
    class MaterialSupplier: public Ui_MaterialSupplier {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATERIALSUPPLIER_H
