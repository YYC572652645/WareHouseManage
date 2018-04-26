/********************************************************************************
** Form generated from reading UI file 'reporttable.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTTABLE_H
#define UI_REPORTTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reporttable
{
public:
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QTreeWidget *treeWidget;
    QTabWidget *tabWidgetData;

    void setupUi(QWidget *reporttable)
    {
        if (reporttable->objectName().isEmpty())
            reporttable->setObjectName(QStringLiteral("reporttable"));
        reporttable->resize(451, 318);
        reporttable->setStyleSheet(QLatin1String("\n"
"QPushButton:hover\n"
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
"border-radius:2px;\n"
"spacing:2px;\n"
"padding: 0px 0px;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(reporttable);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, -1, 0, 0);
        splitter = new QSplitter(reporttable);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        treeWidget = new QTreeWidget(splitter);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\351\207\207\350\264\255\346\212\245\350\241\250.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/image/\345\272\223\345\255\230\346\212\245\350\241\250.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/image/\344\276\233\345\272\224\345\225\206\346\212\245\350\241\250.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/image/\345\216\237\346\226\231\345\234\210.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem1->setIcon(0, icon);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem2->setIcon(0, icon);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem3->setIcon(0, icon);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem(treeWidget);
        QTreeWidgetItem *__qtreewidgetitem5 = new QTreeWidgetItem(__qtreewidgetitem4);
        __qtreewidgetitem5->setIcon(0, icon1);
        QTreeWidgetItem *__qtreewidgetitem6 = new QTreeWidgetItem(__qtreewidgetitem4);
        __qtreewidgetitem6->setIcon(0, icon1);
        QTreeWidgetItem *__qtreewidgetitem7 = new QTreeWidgetItem(__qtreewidgetitem4);
        __qtreewidgetitem7->setIcon(0, icon1);
        QTreeWidgetItem *__qtreewidgetitem8 = new QTreeWidgetItem(treeWidget);
        QTreeWidgetItem *__qtreewidgetitem9 = new QTreeWidgetItem(__qtreewidgetitem8);
        __qtreewidgetitem9->setIcon(0, icon2);
        QTreeWidgetItem *__qtreewidgetitem10 = new QTreeWidgetItem(__qtreewidgetitem8);
        __qtreewidgetitem10->setIcon(0, icon2);
        QTreeWidgetItem *__qtreewidgetitem11 = new QTreeWidgetItem(treeWidget);
        QTreeWidgetItem *__qtreewidgetitem12 = new QTreeWidgetItem(__qtreewidgetitem11);
        __qtreewidgetitem12->setIcon(0, icon3);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setMinimumSize(QSize(320, 0));
        treeWidget->setMaximumSize(QSize(450, 16777215));
        treeWidget->setStyleSheet(QLatin1String("QTreeWidget::item:selected:active\n"
"{\n"
"background-color: #FF92BB;\n"
"color:black;\n"
"}\n"
"\n"
"QTreeWidget::item\n"
"{\n"
"height:60px;\n"
"}\n"
"\n"
"QTreeWidget::item:selected:!active\n"
"{\n"
"background-color:#33A1C9;\n"
"color:black;\n"
"}\n"
""));
        treeWidget->setIconSize(QSize(30, 30));
        splitter->addWidget(treeWidget);
        tabWidgetData = new QTabWidget(splitter);
        tabWidgetData->setObjectName(QStringLiteral("tabWidgetData"));
        tabWidgetData->setStyleSheet(QLatin1String("QTabBar::tab\n"
"{\n"
"min-width:300px;\n"
"color: white;\n"
"background-color:rgb(44, 62, 80);\n"
"border: 0px solid;\n"
"border-top-left-radius: 10px;\n"
"border-top-right-radius: 10px;\n"
"padding:5px;\n"
"}\n"
"\n"
"QTabBar::tab:!selected\n"
"{\n"
"margin-top: 5px;\n"
"}\n"
"\n"
"QTabBar::tab:selected\n"
"{\n"
"color: rgb(230,250,0);\n"
"font-size:12px;\n"
"font-weight:bold;\n"
"}"));
        splitter->addWidget(tabWidgetData);

        verticalLayout->addWidget(splitter);


        retranslateUi(reporttable);

        tabWidgetData->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(reporttable);
    } // setupUi

    void retranslateUi(QWidget *reporttable)
    {
        reporttable->setWindowTitle(QApplication::translate("reporttable", "Form", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("reporttable", "1", 0));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("reporttable", "\351\207\207\350\264\255\346\212\245\350\241\250", 0));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QApplication::translate("reporttable", "\351\207\207\350\264\255\345\205\245\345\272\223\346\230\216\347\273\206\346\212\245\350\241\250", 0));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem3->setText(0, QApplication::translate("reporttable", "\351\207\207\350\264\255\345\205\245\345\272\223\346\261\207\346\200\273\346\212\245\350\241\250", 0));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem1->child(2);
        ___qtreewidgetitem4->setText(0, QApplication::translate("reporttable", "\351\207\207\350\264\255\351\200\200\350\264\247\346\230\216\347\273\206\346\212\245\350\241\250", 0));
        QTreeWidgetItem *___qtreewidgetitem5 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem5->setText(0, QApplication::translate("reporttable", "\345\272\223\345\255\230\346\212\245\350\241\250", 0));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem5->child(0);
        ___qtreewidgetitem6->setText(0, QApplication::translate("reporttable", "\350\260\203\346\225\264\345\215\225\346\230\216\347\273\206\346\212\245\350\241\250", 0));
        QTreeWidgetItem *___qtreewidgetitem7 = ___qtreewidgetitem5->child(1);
        ___qtreewidgetitem7->setText(0, QApplication::translate("reporttable", "\347\233\230\345\255\230\345\215\225\346\230\216\347\273\206\346\212\245\350\241\250", 0));
        QTreeWidgetItem *___qtreewidgetitem8 = ___qtreewidgetitem5->child(2);
        ___qtreewidgetitem8->setText(0, QApplication::translate("reporttable", "\347\233\230\345\255\230\345\215\225\346\261\207\346\200\273\346\212\245\350\241\250", 0));
        QTreeWidgetItem *___qtreewidgetitem9 = treeWidget->topLevelItem(2);
        ___qtreewidgetitem9->setText(0, QApplication::translate("reporttable", "\344\276\233\345\272\224\345\225\206\346\212\245\350\241\250", 0));
        QTreeWidgetItem *___qtreewidgetitem10 = ___qtreewidgetitem9->child(0);
        ___qtreewidgetitem10->setText(0, QApplication::translate("reporttable", "\344\276\233\345\272\224\345\225\206\344\276\233\350\264\247\346\230\216\347\273\206\346\212\245\350\241\250", 0));
        QTreeWidgetItem *___qtreewidgetitem11 = ___qtreewidgetitem9->child(1);
        ___qtreewidgetitem11->setText(0, QApplication::translate("reporttable", "\344\276\233\345\272\224\345\225\206\344\276\233\350\264\247\346\261\207\346\200\273\346\212\245\350\241\250", 0));
        QTreeWidgetItem *___qtreewidgetitem12 = treeWidget->topLevelItem(3);
        ___qtreewidgetitem12->setText(0, QApplication::translate("reporttable", "\351\224\200\345\224\256\346\212\245\350\241\250", 0));
        QTreeWidgetItem *___qtreewidgetitem13 = ___qtreewidgetitem12->child(0);
        ___qtreewidgetitem13->setText(0, QApplication::translate("reporttable", "\345\216\237\346\226\231\351\224\200\345\224\256\346\212\245\350\241\250", 0));
        treeWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class reporttable: public Ui_reporttable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTTABLE_H
