/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionTodayHouseMoney;
    QAction *actionTableCenter;
    QAction *actionExit;
    QAction *actionBaseInfo;
    QAction *actionPurManage;
    QAction *actionWareHouseManage;
    QAction *actionMatSup;
    QAction *actionAccount;
    QAction *actionSwitchLanguage;
    QAction *actionVersion;
    QAction *actionUpdate;
    QAction *actionAdministrator;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidgetContent;
    QToolBar *toolBar;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(834, 393);
        actionTodayHouseMoney = new QAction(MainWindow);
        actionTodayHouseMoney->setObjectName(QStringLiteral("actionTodayHouseMoney"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\345\205\245\345\272\223.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTodayHouseMoney->setIcon(icon);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        actionTodayHouseMoney->setFont(font);
        actionTableCenter = new QAction(MainWindow);
        actionTableCenter->setObjectName(QStringLiteral("actionTableCenter"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/image/\346\212\245\350\241\250.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTableCenter->setIcon(icon1);
        actionTableCenter->setFont(font);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/image/\351\200\200\345\207\272.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon2);
        actionExit->setFont(font);
        actionBaseInfo = new QAction(MainWindow);
        actionBaseInfo->setObjectName(QStringLiteral("actionBaseInfo"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/image/\344\277\241\346\201\257\347\256\241\347\220\206.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBaseInfo->setIcon(icon3);
        actionBaseInfo->setFont(font);
        actionPurManage = new QAction(MainWindow);
        actionPurManage->setObjectName(QStringLiteral("actionPurManage"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/image/image/\350\217\234\345\223\201.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPurManage->setIcon(icon4);
        actionPurManage->setFont(font);
        actionWareHouseManage = new QAction(MainWindow);
        actionWareHouseManage->setObjectName(QStringLiteral("actionWareHouseManage"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/image/image/\344\273\223\345\272\223\347\256\241\347\220\206.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionWareHouseManage->setIcon(icon5);
        actionWareHouseManage->setFont(font);
        actionMatSup = new QAction(MainWindow);
        actionMatSup->setObjectName(QStringLiteral("actionMatSup"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/image/image/\344\276\233\345\272\224\345\225\206\347\256\241\347\220\206.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMatSup->setIcon(icon6);
        actionMatSup->setFont(font);
        actionAccount = new QAction(MainWindow);
        actionAccount->setObjectName(QStringLiteral("actionAccount"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/image/image/\347\273\223\347\256\227\347\256\241\347\220\206.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAccount->setIcon(icon7);
        actionAccount->setFont(font);
        actionSwitchLanguage = new QAction(MainWindow);
        actionSwitchLanguage->setObjectName(QStringLiteral("actionSwitchLanguage"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/image/image/\350\260\203\346\225\264.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSwitchLanguage->setIcon(icon8);
        actionSwitchLanguage->setFont(font);
        actionVersion = new QAction(MainWindow);
        actionVersion->setObjectName(QStringLiteral("actionVersion"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/image/image/\347\211\210\346\234\254.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionVersion->setIcon(icon9);
        QFont font1;
        font1.setFamily(QStringLiteral("Academy Engraved LET"));
        font1.setPointSize(10);
        actionVersion->setFont(font1);
        actionUpdate = new QAction(MainWindow);
        actionUpdate->setObjectName(QStringLiteral("actionUpdate"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/image/image/\347\211\210\346\234\254\346\233\264\346\226\260.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUpdate->setIcon(icon10);
        actionAdministrator = new QAction(MainWindow);
        actionAdministrator->setObjectName(QStringLiteral("actionAdministrator"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/image/image/\347\256\241\347\220\206\345\221\230.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdministrator->setIcon(icon11);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        tabWidgetContent = new QTabWidget(centralWidget);
        tabWidgetContent->setObjectName(QStringLiteral("tabWidgetContent"));

        horizontalLayout->addWidget(tabWidgetContent);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolBar->sizePolicy().hasHeightForWidth());
        toolBar->setSizePolicy(sizePolicy);
        toolBar->setMinimumSize(QSize(0, 0));
        toolBar->setMovable(false);
        toolBar->setIconSize(QSize(30, 30));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 834, 22));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        MainWindow->setMenuBar(menuBar);

        toolBar->addAction(actionBaseInfo);
        toolBar->addAction(actionPurManage);
        toolBar->addAction(actionWareHouseManage);
        toolBar->addSeparator();
        toolBar->addAction(actionMatSup);
        toolBar->addAction(actionAccount);
        toolBar->addAction(actionTodayHouseMoney);
        toolBar->addAction(actionTableCenter);
        toolBar->addSeparator();
        toolBar->addAction(actionSwitchLanguage);
        toolBar->addAction(actionExit);
        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(actionBaseInfo);
        menu->addAction(actionPurManage);
        menu->addAction(actionWareHouseManage);
        menu->addAction(actionMatSup);
        menu->addAction(actionTodayHouseMoney);
        menu->addAction(actionTableCenter);
        menu->addAction(actionExit);
        menu_2->addAction(actionVersion);
        menu_2->addAction(actionUpdate);
        menu_3->addAction(actionAdministrator);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionTodayHouseMoney->setText(QApplication::translate("MainWindow", "\344\273\212\346\227\245\346\212\245\350\241\250", 0));
#ifndef QT_NO_TOOLTIP
        actionTodayHouseMoney->setToolTip(QApplication::translate("MainWindow", "\344\273\212\346\227\245\346\212\245\350\241\250", 0));
#endif // QT_NO_TOOLTIP
        actionTableCenter->setText(QApplication::translate("MainWindow", "\346\212\245\350\241\250\344\270\255\345\277\203", 0));
#ifndef QT_NO_TOOLTIP
        actionTableCenter->setToolTip(QApplication::translate("MainWindow", "\346\212\245\350\241\250\344\270\255\345\277\203", 0));
#endif // QT_NO_TOOLTIP
        actionExit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272\347\231\273\345\275\225", 0));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("MainWindow", "\351\200\200\345\207\272\347\231\273\345\275\225", 0));
#endif // QT_NO_TOOLTIP
        actionBaseInfo->setText(QApplication::translate("MainWindow", "\345\237\272\347\241\200\345\212\237\350\203\275", 0));
#ifndef QT_NO_TOOLTIP
        actionBaseInfo->setToolTip(QApplication::translate("MainWindow", "\345\237\272\347\241\200\345\212\237\350\203\275", 0));
#endif // QT_NO_TOOLTIP
        actionPurManage->setText(QApplication::translate("MainWindow", "\350\277\233\350\264\247\345\270\270\347\224\250\345\212\237\350\203\275", 0));
#ifndef QT_NO_TOOLTIP
        actionPurManage->setToolTip(QApplication::translate("MainWindow", "\350\277\233\350\264\247\345\270\270\347\224\250\345\212\237\350\203\275", 0));
#endif // QT_NO_TOOLTIP
        actionWareHouseManage->setText(QApplication::translate("MainWindow", "\345\272\223\347\256\241\345\270\270\347\224\250\345\212\237\350\203\275", 0));
#ifndef QT_NO_TOOLTIP
        actionWareHouseManage->setToolTip(QApplication::translate("MainWindow", "\345\272\223\347\256\241\345\270\270\347\224\250\345\212\237\350\203\275", 0));
#endif // QT_NO_TOOLTIP
        actionMatSup->setText(QApplication::translate("MainWindow", "\345\216\237\346\226\231\344\276\233\345\272\224\345\225\206", 0));
#ifndef QT_NO_TOOLTIP
        actionMatSup->setToolTip(QApplication::translate("MainWindow", "\345\216\237\346\226\231\344\276\233\345\272\224\345\225\206", 0));
#endif // QT_NO_TOOLTIP
        actionAccount->setText(QApplication::translate("MainWindow", "\346\224\257\345\207\272\347\273\223\347\256\227", 0));
        actionSwitchLanguage->setText(QApplication::translate("MainWindow", "\345\210\207\346\215\242\344\270\272\350\213\261\346\226\207", 0));
#ifndef QT_NO_TOOLTIP
        actionSwitchLanguage->setToolTip(QApplication::translate("MainWindow", "\345\210\207\346\215\242\344\270\272\350\213\261\346\226\207", 0));
#endif // QT_NO_TOOLTIP
        actionVersion->setText(QApplication::translate("MainWindow", "\347\211\210\346\234\254\344\277\241\346\201\257", 0));
        actionUpdate->setText(QApplication::translate("MainWindow", "\346\243\200\346\237\245\346\233\264\346\226\260", 0));
#ifndef QT_NO_TOOLTIP
        actionUpdate->setToolTip(QApplication::translate("MainWindow", "\346\243\200\346\237\245\346\233\264\346\226\260", 0));
#endif // QT_NO_TOOLTIP
        actionAdministrator->setText(QApplication::translate("MainWindow", "\347\256\241\347\220\206\345\221\230\347\256\241\347\220\206", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\344\277\241\346\201\257\347\256\241\347\220\206", 0));
        menu_2->setTitle(QApplication::translate("MainWindow", "\345\205\263\344\272\216", 0));
        menu_3->setTitle(QApplication::translate("MainWindow", "\346\235\203\351\231\220\347\256\241\347\220\206", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
