/********************************************************************************
** Form generated from reading UI file 'startreceive.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTRECEIVE_H
#define UI_STARTRECEIVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartReceive
{
public:
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidgetData;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBoxAllSelect;
    QLabel *labelContent;
    QPushButton *pushButtonConfirm;

    void setupUi(QWidget *StartReceive)
    {
        if (StartReceive->objectName().isEmpty())
            StartReceive->setObjectName(QStringLiteral("StartReceive"));
        StartReceive->resize(663, 506);
        verticalLayout_2 = new QVBoxLayout(StartReceive);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(3, 3, 3, 3);
        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        listWidgetData = new QListWidget(StartReceive);
        listWidgetData->setObjectName(QStringLiteral("listWidgetData"));
        listWidgetData->setStyleSheet(QLatin1String("\n"
"QComboBox\n"
"{\n"
"	background-color: transparent;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView\n"
"{\n"
"selection-color:transparent;\n"
"selection-background-color:black;\n"
"background-color:rgb(200, 200, 200);\n"
"color:black;\n"
"font:14px;\n"
"}"));

        verticalLayout->addWidget(listWidgetData);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        checkBoxAllSelect = new QCheckBox(StartReceive);
        checkBoxAllSelect->setObjectName(QStringLiteral("checkBoxAllSelect"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\345\205\250\351\200\211.png"), QSize(), QIcon::Normal, QIcon::Off);
        checkBoxAllSelect->setIcon(icon);

        horizontalLayout->addWidget(checkBoxAllSelect);

        labelContent = new QLabel(StartReceive);
        labelContent->setObjectName(QStringLiteral("labelContent"));

        horizontalLayout->addWidget(labelContent);

        pushButtonConfirm = new QPushButton(StartReceive);
        pushButtonConfirm->setObjectName(QStringLiteral("pushButtonConfirm"));
        pushButtonConfirm->setMinimumSize(QSize(200, 0));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/image/\347\241\256\350\256\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonConfirm->setIcon(icon1);

        horizontalLayout->addWidget(pushButtonConfirm);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(StartReceive);

        QMetaObject::connectSlotsByName(StartReceive);
    } // setupUi

    void retranslateUi(QWidget *StartReceive)
    {
        StartReceive->setWindowTitle(QApplication::translate("StartReceive", "Form", 0));
        checkBoxAllSelect->setText(QApplication::translate("StartReceive", "\345\205\250\351\200\211", 0));
        labelContent->setText(QString());
        pushButtonConfirm->setText(QApplication::translate("StartReceive", " \347\241\256\350\256\244\346\224\266\350\264\247", 0));
    } // retranslateUi

};

namespace Ui {
    class StartReceive: public Ui_StartReceive {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTRECEIVE_H
