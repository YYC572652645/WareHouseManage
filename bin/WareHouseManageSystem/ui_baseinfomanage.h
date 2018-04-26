/********************************************************************************
** Form generated from reading UI file 'baseinfomanage.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BASEINFOMANAGE_H
#define UI_BASEINFOMANAGE_H

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

class Ui_baseinfomanage
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *treeWidget;
    QTabWidget *tabWidget;

    void setupUi(QWidget *baseinfomanage)
    {
        if (baseinfomanage->objectName().isEmpty())
            baseinfomanage->setObjectName(QStringLiteral("baseinfomanage"));
        baseinfomanage->resize(455, 193);
        baseinfomanage->setStyleSheet(QLatin1String("QPushButton:hover\n"
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
"}"));
        verticalLayout = new QVBoxLayout(baseinfomanage);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 6, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        treeWidget = new QTreeWidget(baseinfomanage);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\345\216\237\346\226\231\345\234\210.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/image/\344\273\223\345\272\223\344\277\241\346\201\257.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/image/\344\276\233\345\272\224\345\225\206\344\277\241\346\201\257.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/image/\351\207\207\350\264\255\346\250\241\346\235\277.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/image/image/\345\216\237\346\226\231\351\205\215\346\257\224.png"), QSize(), QIcon::Normal, QIcon::Off);
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
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setMinimumSize(QSize(320, 0));
        treeWidget->setMaximumSize(QSize(200, 16777215));
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

        tabWidget = new QTabWidget(baseinfomanage);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));

        horizontalLayout->addWidget(tabWidget);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(baseinfomanage);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(baseinfomanage);
    } // setupUi

    void retranslateUi(QWidget *baseinfomanage)
    {
        baseinfomanage->setWindowTitle(QApplication::translate("baseinfomanage", "Form", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("baseinfomanage", "\345\237\272\347\241\200\345\212\237\350\203\275", 0));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("baseinfomanage", "\345\216\237\346\226\231\350\256\276\347\275\256", 0));
        QTreeWidgetItem *___qtreewidgetitem2 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem2->setText(0, QApplication::translate("baseinfomanage", "\344\273\223\345\272\223\350\256\276\347\275\256", 0));
        QTreeWidgetItem *___qtreewidgetitem3 = treeWidget->topLevelItem(2);
        ___qtreewidgetitem3->setText(0, QApplication::translate("baseinfomanage", "\344\276\233\345\272\224\345\225\206\350\256\276\347\275\256", 0));
        QTreeWidgetItem *___qtreewidgetitem4 = treeWidget->topLevelItem(3);
        ___qtreewidgetitem4->setText(0, QApplication::translate("baseinfomanage", "\351\207\207\350\264\255\346\250\241\346\235\277\350\256\276\347\275\256", 0));
        QTreeWidgetItem *___qtreewidgetitem5 = treeWidget->topLevelItem(4);
        ___qtreewidgetitem5->setText(0, QApplication::translate("baseinfomanage", "\345\225\206\345\223\201\345\216\237\346\226\231\350\256\276\347\275\256", 0));
        treeWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class baseinfomanage: public Ui_baseinfomanage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASEINFOMANAGE_H
