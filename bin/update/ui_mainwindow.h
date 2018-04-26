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
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelImage;
    QListWidget *listWidgetData;
    QHBoxLayout *horizontalLayout;
    QLabel *labelInfo;
    QPushButton *pushButtonUpdate;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(720, 497);
        MainWindow->setMaximumSize(QSize(1266, 1130));
        MainWindow->setStyleSheet(QLatin1String("\n"
"background-color: rgb(255, 255, 255);\n"
"image: url(:/image/image/loginbackground.png);\n"
"border-radius:5px;\n"
""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, -1, 12);
        horizontalSpacer = new QSpacerItem(40, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        labelImage = new QLabel(centralWidget);
        labelImage->setObjectName(QStringLiteral("labelImage"));
        labelImage->setStyleSheet(QStringLiteral("image: url(:/image/image/login.jpg);"));
        labelImage->setScaledContents(true);
        labelImage->setWordWrap(true);

        horizontalLayout_2->addWidget(labelImage);

        listWidgetData = new QListWidget(centralWidget);
        listWidgetData->setObjectName(QStringLiteral("listWidgetData"));
        listWidgetData->setStyleSheet(QLatin1String("QProgressBar\n"
"{\n"
"    border: 2px solid grey;\n"
"    border-radius: 5px;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QProgressBar::chunk\n"
"{\n"
"     background-color: #528B8B;\n"
"     width: 5px;\n"
"     margin: 0.5px;\n"
"}"));

        horizontalLayout_2->addWidget(listWidgetData);

        horizontalLayout_2->setStretch(0, 2);
        horizontalLayout_2->setStretch(1, 3);

        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelInfo = new QLabel(centralWidget);
        labelInfo->setObjectName(QStringLiteral("labelInfo"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        labelInfo->setFont(font);
        labelInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        labelInfo->setScaledContents(false);
        labelInfo->setAlignment(Qt::AlignCenter);
        labelInfo->setWordWrap(true);

        horizontalLayout->addWidget(labelInfo);

        pushButtonUpdate = new QPushButton(centralWidget);
        pushButtonUpdate->setObjectName(QStringLiteral("pushButtonUpdate"));
        pushButtonUpdate->setMaximumSize(QSize(220, 16777215));
        pushButtonUpdate->setFont(font);
        pushButtonUpdate->setStyleSheet(QLatin1String("QPushButton:hover\n"
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
"height: 30px;\n"
"border-radius:2px;\n"
"spacing:2px;\n"
"padding: 0px 0px;\n"
"color: white;\n"
"image: none;\n"
"}"));

        horizontalLayout->addWidget(pushButtonUpdate);


        verticalLayout_2->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        labelImage->setText(QString());
        labelInfo->setText(QString());
        pushButtonUpdate->setText(QApplication::translate("MainWindow", "\346\233\264\346\226\260", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
