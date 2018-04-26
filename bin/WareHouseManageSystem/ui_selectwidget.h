/********************************************************************************
** Form generated from reading UI file 'selectwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTWIDGET_H
#define UI_SELECTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectWidget
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QWidget *widgetControl;
    QLineEdit *lineEditMaterial;
    QPushButton *pushButtonYesterday;
    QPushButton *pushButtonLastWeek;
    QPushButton *pushButtonThisWeek;
    QPushButton *pushButtonThisMonth;
    QPushButton *pushButtonLastMonth;
    QPushButton *pushButtonSelect;
    QPushButton *pushButtonExtendEmail;
    QLabel *labelSup;
    QComboBox *comboBoxState;
    QLabel *labelState;
    QComboBox *comboBoxSupplier;
    QLabel *labelWareHouse;
    QComboBox *comboBoxWareHouse;
    QLabel *labelMatType;
    QComboBox *comboBoxMatType;
    QLabel *labelDateType;
    QComboBox *comboBoxTimeType;
    QLabel *labelBeginTime;
    QLabel *labelEndTime;
    QDateEdit *dateEditEndTime;
    QDateEdit *dateEditStartTime;
    QTableWidget *tableWidget;

    void setupUi(QWidget *SelectWidget)
    {
        if (SelectWidget->objectName().isEmpty())
            SelectWidget->setObjectName(QStringLiteral("SelectWidget"));
        SelectWidget->resize(352, 188);
        SelectWidget->setStyleSheet(QLatin1String("QComboBox \n"
"{  \n"
"background-color:white;\n"
"}\n"
"\n"
"\n"
"QComboBox \n"
"{  \n"
"background-color:white;\n"
"}\n"
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
"font-size:12px;\n"
"width: 100px;\n"
"border-radius:2px;\n"
"spacing:2px;\n"
"padding: 0px 0px;\n"
"}"));
        verticalLayout_4 = new QVBoxLayout(SelectWidget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        widgetControl = new QWidget(SelectWidget);
        widgetControl->setObjectName(QStringLiteral("widgetControl"));
        widgetControl->setMinimumSize(QSize(0, 20));
        lineEditMaterial = new QLineEdit(widgetControl);
        lineEditMaterial->setObjectName(QStringLiteral("lineEditMaterial"));
        lineEditMaterial->setGeometry(QRect(978, 10, 120, 22));
        lineEditMaterial->setMinimumSize(QSize(120, 0));
        lineEditMaterial->setMaximumSize(QSize(120, 16777215));
        pushButtonYesterday = new QPushButton(widgetControl);
        pushButtonYesterday->setObjectName(QStringLiteral("pushButtonYesterday"));
        pushButtonYesterday->setGeometry(QRect(1101, 10, 30, 30));
        pushButtonYesterday->setMinimumSize(QSize(30, 30));
        pushButtonYesterday->setMaximumSize(QSize(30, 16777215));
        pushButtonYesterday->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-color:transparent;\n"
"border-image: url(:/image/image/puton.png);\n"
"color:white;\n"
"}"));
        pushButtonYesterday->setCheckable(true);
        pushButtonLastWeek = new QPushButton(widgetControl);
        pushButtonLastWeek->setObjectName(QStringLiteral("pushButtonLastWeek"));
        pushButtonLastWeek->setGeometry(QRect(1167, 10, 30, 30));
        pushButtonLastWeek->setMinimumSize(QSize(30, 30));
        pushButtonLastWeek->setMaximumSize(QSize(30, 16777215));
        pushButtonLastWeek->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-color:transparent;\n"
"border-image: url(:/image/image/puton.png);\n"
"color:white;\n"
"}"));
        pushButtonLastWeek->setCheckable(true);
        pushButtonThisWeek = new QPushButton(widgetControl);
        pushButtonThisWeek->setObjectName(QStringLiteral("pushButtonThisWeek"));
        pushButtonThisWeek->setGeometry(QRect(1134, 10, 30, 30));
        pushButtonThisWeek->setMinimumSize(QSize(30, 30));
        pushButtonThisWeek->setMaximumSize(QSize(30, 16777215));
        pushButtonThisWeek->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-color:transparent;\n"
"border-image: url(:/image/image/puton.png);\n"
"color:white;\n"
"}"));
        pushButtonThisWeek->setCheckable(true);
        pushButtonThisMonth = new QPushButton(widgetControl);
        pushButtonThisMonth->setObjectName(QStringLiteral("pushButtonThisMonth"));
        pushButtonThisMonth->setGeometry(QRect(1200, 10, 30, 30));
        pushButtonThisMonth->setMinimumSize(QSize(30, 30));
        pushButtonThisMonth->setMaximumSize(QSize(30, 16777215));
        pushButtonThisMonth->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-color:transparent;\n"
"border-image: url(:/image/image/puton.png);\n"
"color:white;\n"
"}"));
        pushButtonThisMonth->setCheckable(true);
        pushButtonLastMonth = new QPushButton(widgetControl);
        pushButtonLastMonth->setObjectName(QStringLiteral("pushButtonLastMonth"));
        pushButtonLastMonth->setGeometry(QRect(1233, 10, 30, 30));
        pushButtonLastMonth->setMinimumSize(QSize(30, 30));
        pushButtonLastMonth->setMaximumSize(QSize(30, 16777215));
        pushButtonLastMonth->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-color:transparent;\n"
"border-image: url(:/image/image/puton.png);\n"
"color:white;\n"
"}"));
        pushButtonLastMonth->setCheckable(true);
        pushButtonSelect = new QPushButton(widgetControl);
        pushButtonSelect->setObjectName(QStringLiteral("pushButtonSelect"));
        pushButtonSelect->setGeometry(QRect(1266, 10, 80, 30));
        pushButtonSelect->setMaximumSize(QSize(80, 16777215));
        pushButtonSelect->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\346\237\245\350\257\242.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSelect->setIcon(icon);
        pushButtonExtendEmail = new QPushButton(widgetControl);
        pushButtonExtendEmail->setObjectName(QStringLiteral("pushButtonExtendEmail"));
        pushButtonExtendEmail->setGeometry(QRect(1349, 10, 80, 30));
        pushButtonExtendEmail->setMaximumSize(QSize(80, 16777215));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/export.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonExtendEmail->setIcon(icon1);
        labelSup = new QLabel(widgetControl);
        labelSup->setObjectName(QStringLiteral("labelSup"));
        labelSup->setGeometry(QRect(116, 12, 54, 16));
        comboBoxState = new QComboBox(widgetControl);
        comboBoxState->setObjectName(QStringLiteral("comboBoxState"));
        comboBoxState->setGeometry(QRect(52, 12, 60, 22));
        comboBoxState->setMinimumSize(QSize(0, 0));
        comboBoxState->setMaximumSize(QSize(80, 16777215));
        labelState = new QLabel(widgetControl);
        labelState->setObjectName(QStringLiteral("labelState"));
        labelState->setGeometry(QRect(-18, 12, 66, 16));
        comboBoxSupplier = new QComboBox(widgetControl);
        comboBoxSupplier->setObjectName(QStringLiteral("comboBoxSupplier"));
        comboBoxSupplier->setGeometry(QRect(174, 12, 60, 22));
        comboBoxSupplier->setMinimumSize(QSize(0, 0));
        comboBoxSupplier->setMaximumSize(QSize(80, 16777215));
        labelWareHouse = new QLabel(widgetControl);
        labelWareHouse->setObjectName(QStringLiteral("labelWareHouse"));
        labelWareHouse->setGeometry(QRect(238, 12, 66, 16));
        comboBoxWareHouse = new QComboBox(widgetControl);
        comboBoxWareHouse->setObjectName(QStringLiteral("comboBoxWareHouse"));
        comboBoxWareHouse->setGeometry(QRect(308, 12, 60, 22));
        comboBoxWareHouse->setMinimumSize(QSize(0, 0));
        comboBoxWareHouse->setMaximumSize(QSize(80, 16777215));
        labelMatType = new QLabel(widgetControl);
        labelMatType->setObjectName(QStringLiteral("labelMatType"));
        labelMatType->setGeometry(QRect(372, 12, 66, 16));
        comboBoxMatType = new QComboBox(widgetControl);
        comboBoxMatType->setObjectName(QStringLiteral("comboBoxMatType"));
        comboBoxMatType->setGeometry(QRect(442, 12, 60, 22));
        comboBoxMatType->setMinimumSize(QSize(0, 0));
        comboBoxMatType->setMaximumSize(QSize(80, 16777215));
        labelDateType = new QLabel(widgetControl);
        labelDateType->setObjectName(QStringLiteral("labelDateType"));
        labelDateType->setGeometry(QRect(506, 12, 66, 16));
        comboBoxTimeType = new QComboBox(widgetControl);
        comboBoxTimeType->setObjectName(QStringLiteral("comboBoxTimeType"));
        comboBoxTimeType->setGeometry(QRect(576, 12, 70, 22));
        comboBoxTimeType->setMinimumSize(QSize(0, 0));
        comboBoxTimeType->setMaximumSize(QSize(80, 16777215));
        labelBeginTime = new QLabel(widgetControl);
        labelBeginTime->setObjectName(QStringLiteral("labelBeginTime"));
        labelBeginTime->setGeometry(QRect(650, 12, 66, 16));
        labelEndTime = new QLabel(widgetControl);
        labelEndTime->setObjectName(QStringLiteral("labelEndTime"));
        labelEndTime->setGeometry(QRect(814, 10, 66, 16));
        dateEditEndTime = new QDateEdit(widgetControl);
        dateEditEndTime->setObjectName(QStringLiteral("dateEditEndTime"));
        dateEditEndTime->setGeometry(QRect(884, 12, 90, 22));
        dateEditEndTime->setMinimumSize(QSize(0, 0));
        dateEditStartTime = new QDateEdit(widgetControl);
        dateEditStartTime->setObjectName(QStringLiteral("dateEditStartTime"));
        dateEditStartTime->setGeometry(QRect(720, 12, 90, 22));
        dateEditStartTime->setMinimumSize(QSize(0, 0));

        verticalLayout_2->addWidget(widgetControl);

        tableWidget = new QTableWidget(SelectWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout_2->addWidget(tableWidget);


        verticalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(SelectWidget);

        QMetaObject::connectSlotsByName(SelectWidget);
    } // setupUi

    void retranslateUi(QWidget *SelectWidget)
    {
        SelectWidget->setWindowTitle(QApplication::translate("SelectWidget", "Form", 0));
        lineEditMaterial->setPlaceholderText(QApplication::translate("SelectWidget", "\345\216\237\346\226\231\345\220\215\346\210\226\346\235\241\345\275\242\347\240\201", 0));
        pushButtonYesterday->setText(QApplication::translate("SelectWidget", "\346\230\250\346\227\245", 0));
        pushButtonLastWeek->setText(QApplication::translate("SelectWidget", "\344\270\212\345\221\250", 0));
        pushButtonThisWeek->setText(QApplication::translate("SelectWidget", "\346\234\254\345\221\250", 0));
        pushButtonThisMonth->setText(QApplication::translate("SelectWidget", "\346\234\254\346\234\210", 0));
        pushButtonLastMonth->setText(QApplication::translate("SelectWidget", "\344\270\212\346\234\210", 0));
        pushButtonSelect->setText(QApplication::translate("SelectWidget", "\346\237\245\350\257\242\346\212\245\350\241\250", 0));
        pushButtonExtendEmail->setText(QApplication::translate("SelectWidget", "\345\257\274\345\207\272", 0));
        labelSup->setText(QApplication::translate("SelectWidget", " \344\276\233\345\272\224\345\225\206\357\274\232", 0));
        labelState->setText(QApplication::translate("SelectWidget", " \345\215\225\346\215\256\347\212\266\346\200\201\357\274\232", 0));
        labelWareHouse->setText(QApplication::translate("SelectWidget", " \345\205\245\345\272\223\344\273\223\345\272\223\357\274\232", 0));
        labelMatType->setText(QApplication::translate("SelectWidget", " \345\216\237\346\226\231\345\210\206\347\261\273\357\274\232", 0));
        labelDateType->setText(QApplication::translate("SelectWidget", " \346\227\245\346\234\237\347\261\273\345\236\213\357\274\232", 0));
        labelBeginTime->setText(QApplication::translate("SelectWidget", " \345\274\200\345\247\213\346\227\266\351\227\264\357\274\232", 0));
        labelEndTime->setText(QApplication::translate("SelectWidget", " \347\273\223\346\235\237\346\227\266\351\227\264\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class SelectWidget: public Ui_SelectWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTWIDGET_H
