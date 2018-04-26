/********************************************************************************
** Form generated from reading UI file 'warehousemanage.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAREHOUSEMANAGE_H
#define UI_WAREHOUSEMANAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_warehousemanage
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *treeWidget;
    QTabWidget *tabWidget;

    void setupUi(QWidget *warehousemanage)
    {
        if (warehousemanage->objectName().isEmpty())
            warehousemanage->setObjectName(QStringLiteral("warehousemanage"));
        warehousemanage->resize(526, 330);
        verticalLayout = new QVBoxLayout(warehousemanage);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 6, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        treeWidget = new QTreeWidget(warehousemanage);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\345\256\236\346\227\266\345\272\223\345\255\230\347\244\272\346\204\217\345\233\276.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/image/\350\260\203\346\225\264.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/image/\347\233\230\347\202\271.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/image/\345\217\230\346\233\264.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/image/image/\346\210\220\346\234\254\347\273\237\350\256\241\345\210\206\346\236\220.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/image/image/\344\273\267\346\240\274\345\214\272\351\227\264.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/image/image/\345\272\223\345\255\230\350\260\203\346\213\250.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem->setIcon(0, icon);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem1->setIcon(0, icon1);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem2->setIcon(0, icon2);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem3->setIcon(0, icon3);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem4->setIcon(0, icon4);
        QTreeWidgetItem *__qtreewidgetitem5 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem5->setIcon(0, icon5);
        QTreeWidgetItem *__qtreewidgetitem6 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem6->setIcon(0, icon6);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setMinimumSize(QSize(320, 0));
        treeWidget->setMaximumSize(QSize(320, 16777215));
        treeWidget->setStyleSheet(QLatin1String("QTreeWidget::item:selected:active\n"
"{\n"
"background-color: #FF92BB;\n"
"color:black;\n"
"font-size:11px;\n"
"font-weight:bold;\n"
"}\n"
"\n"
"QTreeWidget::item\n"
"{\n"
"height:60px;\n"
"font-size:11px;\n"
"font-weight:bold;\n"
"}\n"
"\n"
"QTreeWidget::item:selected:!active\n"
"{\n"
"background-color:#33A1C9;\n"
"color:black;\n"
"}\n"
""));
        treeWidget->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(treeWidget);

        tabWidget = new QTabWidget(warehousemanage);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));

        horizontalLayout->addWidget(tabWidget);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(warehousemanage);

        QMetaObject::connectSlotsByName(warehousemanage);
    } // setupUi

    void retranslateUi(QWidget *warehousemanage)
    {
        warehousemanage->setWindowTitle(QApplication::translate("warehousemanage", "Form", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("warehousemanage", "1", 0));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("warehousemanage", "\345\256\236\346\227\266\345\272\223\345\255\230", 0));
        QTreeWidgetItem *___qtreewidgetitem2 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem2->setText(0, QApplication::translate("warehousemanage", "\345\272\223\345\255\230\350\260\203\346\225\264", 0));
        QTreeWidgetItem *___qtreewidgetitem3 = treeWidget->topLevelItem(2);
        ___qtreewidgetitem3->setText(0, QApplication::translate("warehousemanage", "\345\272\223\345\255\230\347\233\230\347\202\271", 0));
        QTreeWidgetItem *___qtreewidgetitem4 = treeWidget->topLevelItem(3);
        ___qtreewidgetitem4->setText(0, QApplication::translate("warehousemanage", "\345\272\223\345\255\230\345\217\230\346\233\264\350\256\260\345\275\225", 0));
        QTreeWidgetItem *___qtreewidgetitem5 = treeWidget->topLevelItem(4);
        ___qtreewidgetitem5->setText(0, QApplication::translate("warehousemanage", "\346\210\220\346\234\254\350\260\203\344\273\267\345\215\225", 0));
        QTreeWidgetItem *___qtreewidgetitem6 = treeWidget->topLevelItem(5);
        ___qtreewidgetitem6->setText(0, QApplication::translate("warehousemanage", "\345\272\223\345\255\230\344\270\212\344\270\213\351\231\220", 0));
        QTreeWidgetItem *___qtreewidgetitem7 = treeWidget->topLevelItem(6);
        ___qtreewidgetitem7->setText(0, QApplication::translate("warehousemanage", "\345\272\227\345\206\205\350\260\203\346\213\250", 0));
        treeWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class warehousemanage: public Ui_warehousemanage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAREHOUSEMANAGE_H
