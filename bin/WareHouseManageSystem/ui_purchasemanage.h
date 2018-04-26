/********************************************************************************
** Form generated from reading UI file 'purchasemanage.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PURCHASEMANAGE_H
#define UI_PURCHASEMANAGE_H

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

class Ui_purchasemanage
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *treeWidget;
    QTabWidget *tabWidget;

    void setupUi(QWidget *purchasemanage)
    {
        if (purchasemanage->objectName().isEmpty())
            purchasemanage->setObjectName(QStringLiteral("purchasemanage"));
        purchasemanage->resize(455, 174);
        purchasemanage->setStyleSheet(QLatin1String("QPushButton:hover\n"
"{\n"
"background-color: rgb(44, 80, 80);\n"
"border-radius:5px;\n"
"color:white;\n"
"font-size:16px;\n"
"font-weight:500\n"
"}\n"
"\n"
"QPushButton:hover:pressed\n"
"{\n"
"background-color:darkred;\n"
"border-radius:5px;\n"
"color:white;\n"
"font-size:16px;\n"
"font-weight:500\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"background-color:transparent;\n"
"color:black;\n"
"border-radius:5px;\n"
"spacing: 10px;\n"
"padding: 0px 0px;\n"
"font-size:16px;\n"
"font-weight:500\n"
"}\n"
"\n"
"\n"
"QTreeWidget::item:selected:active\n"
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
        verticalLayout = new QVBoxLayout(purchasemanage);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 6, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        treeWidget = new QTreeWidget(purchasemanage);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\351\207\207\350\264\255\350\256\242\345\215\225.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/image/\351\207\207\350\264\255\345\205\245\345\272\223.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/image/\351\207\207\350\264\255\351\200\200\350\264\247.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/image/\345\256\211\345\205\250\345\272\223\345\255\230\350\256\276\347\275\256.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem->setIcon(0, icon);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem1->setIcon(0, icon1);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem2->setIcon(0, icon2);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem3->setIcon(0, icon3);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setMinimumSize(QSize(320, 0));
        treeWidget->setMaximumSize(QSize(320, 16777215));
        treeWidget->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(treeWidget);

        tabWidget = new QTabWidget(purchasemanage);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));

        horizontalLayout->addWidget(tabWidget);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(purchasemanage);

        QMetaObject::connectSlotsByName(purchasemanage);
    } // setupUi

    void retranslateUi(QWidget *purchasemanage)
    {
        purchasemanage->setWindowTitle(QApplication::translate("purchasemanage", "Form", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("purchasemanage", "1", 0));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("purchasemanage", "\351\207\207\350\264\255\350\256\242\345\215\225", 0));
        QTreeWidgetItem *___qtreewidgetitem2 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem2->setText(0, QApplication::translate("purchasemanage", "\351\207\207\350\264\255\345\205\245\345\272\223", 0));
        QTreeWidgetItem *___qtreewidgetitem3 = treeWidget->topLevelItem(2);
        ___qtreewidgetitem3->setText(0, QApplication::translate("purchasemanage", "\351\207\207\350\264\255\351\200\200\350\264\247", 0));
        QTreeWidgetItem *___qtreewidgetitem4 = treeWidget->topLevelItem(3);
        ___qtreewidgetitem4->setText(0, QApplication::translate("purchasemanage", "\345\256\211\345\205\250\345\272\223\345\255\230\351\207\207\350\264\255", 0));
        treeWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class purchasemanage: public Ui_purchasemanage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PURCHASEMANAGE_H
