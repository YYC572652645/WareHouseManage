/********************************************************************************
** Form generated from reading UI file 'inventorycheck.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVENTORYCHECK_H
#define UI_INVENTORYCHECK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InventoryCheck
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QWidget *widgetControl;
    QLabel *labelState;
    QComboBox *comboBoxStateSelect;
    QComboBox *comboBoxWarHseSelect;
    QLabel *labelWhse;
    QLabel *labelDateTime;
    QDateEdit *dateEditSelect;
    QPushButton *pushButtonSelect;
    QPushButton *pushButtonExtend;
    QLabel *labelSize;
    QPushButton *pushButtonAdd;
    QTableWidget *tableWidgetCheck;
    QTabWidget *tabWidgetCheck;
    QWidget *tabAddCheck;
    QVBoxLayout *verticalLayout_3;
    QCommandLinkButton *commandLinkButtonImport;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QComboBox *comboBoxWarHse;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QCommandLinkButton *commandLinkButtonMatList;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonCancel;
    QWidget *tabCheckInfo;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_18;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_19;
    QLineEdit *lineEditNumberInfo;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_14;
    QLineEdit *lineEditCheckState;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_16;
    QComboBox *comboBoxWarHseInfo;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_12;
    QLabel *labelDate;
    QDateEdit *dateEditCheckTimeInfo;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_18;
    QLabel *labelTime;
    QTimeEdit *timeEditCheckTimeInfo;
    QSpacerItem *horizontalSpacer_8;
    QCommandLinkButton *commandLinkButtonLog;
    QSpacerItem *horizontalSpacer_11;
    QLabel *label_20;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_5;
    QCommandLinkButton *commandLinkButtonMatListInfo;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_19;
    QPushButton *pushButtonCheckFinishInfo;
    QPushButton *pushButtonCancelCheckInfo;
    QHBoxLayout *horizontalLayout_17;
    QPushButton *pushButtonSaveInfo;
    QPushButton *pushButtonDeleteInfo;
    QPushButton *pushButtonCancelInfo;

    void setupUi(QWidget *InventoryCheck)
    {
        if (InventoryCheck->objectName().isEmpty())
            InventoryCheck->setObjectName(QStringLiteral("InventoryCheck"));
        InventoryCheck->resize(402, 388);
        InventoryCheck->setStyleSheet(QLatin1String("QComboBox \n"
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
        verticalLayout_2 = new QVBoxLayout(InventoryCheck);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widgetControl = new QWidget(InventoryCheck);
        widgetControl->setObjectName(QStringLiteral("widgetControl"));
        widgetControl->setMinimumSize(QSize(0, 20));
        labelState = new QLabel(widgetControl);
        labelState->setObjectName(QStringLiteral("labelState"));
        labelState->setGeometry(QRect(191, 11, 28, 56));
        comboBoxStateSelect = new QComboBox(widgetControl);
        comboBoxStateSelect->setObjectName(QStringLiteral("comboBoxStateSelect"));
        comboBoxStateSelect->setGeometry(QRect(225, 28, 28, 22));
        comboBoxStateSelect->setMinimumSize(QSize(0, 0));
        comboBoxWarHseSelect = new QComboBox(widgetControl);
        comboBoxWarHseSelect->setObjectName(QStringLiteral("comboBoxWarHseSelect"));
        comboBoxWarHseSelect->setGeometry(QRect(293, 28, 28, 22));
        comboBoxWarHseSelect->setMinimumSize(QSize(0, 0));
        labelWhse = new QLabel(widgetControl);
        labelWhse->setObjectName(QStringLiteral("labelWhse"));
        labelWhse->setGeometry(QRect(259, 11, 28, 56));
        labelDateTime = new QLabel(widgetControl);
        labelDateTime->setObjectName(QStringLiteral("labelDateTime"));
        labelDateTime->setGeometry(QRect(327, 11, 27, 56));
        dateEditSelect = new QDateEdit(widgetControl);
        dateEditSelect->setObjectName(QStringLiteral("dateEditSelect"));
        dateEditSelect->setGeometry(QRect(360, 28, 28, 22));
        dateEditSelect->setMinimumSize(QSize(0, 0));
        pushButtonSelect = new QPushButton(widgetControl);
        pushButtonSelect->setObjectName(QStringLiteral("pushButtonSelect"));
        pushButtonSelect->setGeometry(QRect(394, 31, 28, 16));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\346\237\245\350\257\242.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSelect->setIcon(icon);
        pushButtonExtend = new QPushButton(widgetControl);
        pushButtonExtend->setObjectName(QStringLiteral("pushButtonExtend"));
        pushButtonExtend->setGeometry(QRect(428, 31, 28, 16));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/export.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonExtend->setIcon(icon1);
        labelSize = new QLabel(widgetControl);
        labelSize->setObjectName(QStringLiteral("labelSize"));
        labelSize->setGeometry(QRect(495, 11, 16, 18));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        labelSize->setFont(font);
        pushButtonAdd = new QPushButton(widgetControl);
        pushButtonAdd->setObjectName(QStringLiteral("pushButtonAdd"));
        pushButtonAdd->setGeometry(QRect(462, 31, 27, 16));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/image/addfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonAdd->setIcon(icon2);

        verticalLayout->addWidget(widgetControl);

        tableWidgetCheck = new QTableWidget(InventoryCheck);
        if (tableWidgetCheck->columnCount() < 4)
            tableWidgetCheck->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetCheck->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetCheck->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetCheck->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetCheck->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidgetCheck->setObjectName(QStringLiteral("tableWidgetCheck"));

        verticalLayout->addWidget(tableWidgetCheck);


        horizontalLayout_2->addLayout(verticalLayout);

        tabWidgetCheck = new QTabWidget(InventoryCheck);
        tabWidgetCheck->setObjectName(QStringLiteral("tabWidgetCheck"));
        tabAddCheck = new QWidget();
        tabAddCheck->setObjectName(QStringLiteral("tabAddCheck"));
        verticalLayout_3 = new QVBoxLayout(tabAddCheck);
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(2, 0, 2, 0);
        commandLinkButtonImport = new QCommandLinkButton(tabAddCheck);
        commandLinkButtonImport->setObjectName(QStringLiteral("commandLinkButtonImport"));

        verticalLayout_3->addWidget(commandLinkButtonImport);

        label_7 = new QLabel(tabAddCheck);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(0, 30));
        label_7->setMaximumSize(QSize(16777215, 30));
        label_7->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"background-color:rgb(180, 85, 100);\n"
"color:white;\n"
"font-size:14px;\n"
"font-weight:bold;\n"
"}"));
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_7);

        horizontalSpacer_7 = new QSpacerItem(40, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_7);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_3 = new QLabel(tabAddCheck);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);

        horizontalLayout_5->addWidget(label_3);

        comboBoxWarHse = new QComboBox(tabAddCheck);
        comboBoxWarHse->setObjectName(QStringLiteral("comboBoxWarHse"));
        comboBoxWarHse->setMinimumSize(QSize(200, 0));
        comboBoxWarHse->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_5->addWidget(comboBoxWarHse);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalSpacer_6 = new QSpacerItem(40, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_6);

        label_8 = new QLabel(tabAddCheck);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(0, 30));
        label_8->setMaximumSize(QSize(16777215, 30));
        label_8->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"background-color:rgb(180, 85, 100);\n"
"color:white;\n"
"font-size:14px;\n"
"font-weight:bold;\n"
"}"));
        label_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_8);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_4 = new QLabel(tabAddCheck);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        horizontalLayout_6->addWidget(label_4);

        commandLinkButtonMatList = new QCommandLinkButton(tabAddCheck);
        commandLinkButtonMatList->setObjectName(QStringLiteral("commandLinkButtonMatList"));
        commandLinkButtonMatList->setMinimumSize(QSize(200, 30));
        commandLinkButtonMatList->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_6->addWidget(commandLinkButtonMatList);


        verticalLayout_3->addLayout(horizontalLayout_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        pushButtonSave = new QPushButton(tabAddCheck);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSave->setIcon(icon3);

        horizontalLayout_7->addWidget(pushButtonSave);

        pushButtonCancel = new QPushButton(tabAddCheck);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/image/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon4);

        horizontalLayout_7->addWidget(pushButtonCancel);


        verticalLayout_3->addLayout(horizontalLayout_7);

        tabWidgetCheck->addTab(tabAddCheck, QString());
        tabCheckInfo = new QWidget();
        tabCheckInfo->setObjectName(QStringLiteral("tabCheckInfo"));
        verticalLayout_5 = new QVBoxLayout(tabCheckInfo);
        verticalLayout_5->setSpacing(2);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(2, 0, 2, 0);
        label_18 = new QLabel(tabCheckInfo);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setMinimumSize(QSize(0, 30));
        label_18->setMaximumSize(QSize(16777215, 30));
        label_18->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"background-color:rgb(180, 85, 100);\n"
"color:white;\n"
"font-size:14px;\n"
"font-weight:bold;\n"
"}"));
        label_18->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_5->addWidget(label_18);

        horizontalSpacer_12 = new QSpacerItem(40, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_5->addItem(horizontalSpacer_12);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_19 = new QLabel(tabCheckInfo);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setFont(font1);

        horizontalLayout_15->addWidget(label_19);

        lineEditNumberInfo = new QLineEdit(tabCheckInfo);
        lineEditNumberInfo->setObjectName(QStringLiteral("lineEditNumberInfo"));
        lineEditNumberInfo->setEnabled(false);
        lineEditNumberInfo->setMinimumSize(QSize(200, 0));
        lineEditNumberInfo->setMaximumSize(QSize(200, 16777215));
        lineEditNumberInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_15->addWidget(lineEditNumberInfo);


        verticalLayout_5->addLayout(horizontalLayout_15);

        horizontalSpacer = new QSpacerItem(40, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_5->addItem(horizontalSpacer);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_14 = new QLabel(tabCheckInfo);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font1);

        horizontalLayout_16->addWidget(label_14);

        lineEditCheckState = new QLineEdit(tabCheckInfo);
        lineEditCheckState->setObjectName(QStringLiteral("lineEditCheckState"));
        lineEditCheckState->setEnabled(false);
        lineEditCheckState->setMinimumSize(QSize(200, 0));
        lineEditCheckState->setMaximumSize(QSize(200, 16777215));
        lineEditCheckState->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_16->addWidget(lineEditCheckState);


        verticalLayout_5->addLayout(horizontalLayout_16);

        horizontalSpacer_3 = new QSpacerItem(40, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_5->addItem(horizontalSpacer_3);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_16 = new QLabel(tabCheckInfo);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font1);

        horizontalLayout_13->addWidget(label_16);

        comboBoxWarHseInfo = new QComboBox(tabCheckInfo);
        comboBoxWarHseInfo->setObjectName(QStringLiteral("comboBoxWarHseInfo"));
        comboBoxWarHseInfo->setMinimumSize(QSize(200, 0));
        comboBoxWarHseInfo->setMaximumSize(QSize(200, 16777215));
        comboBoxWarHseInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_13->addWidget(comboBoxWarHseInfo);


        verticalLayout_5->addLayout(horizontalLayout_13);

        horizontalSpacer_4 = new QSpacerItem(40, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_5->addItem(horizontalSpacer_4);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        labelDate = new QLabel(tabCheckInfo);
        labelDate->setObjectName(QStringLiteral("labelDate"));
        labelDate->setFont(font1);

        horizontalLayout_12->addWidget(labelDate);

        dateEditCheckTimeInfo = new QDateEdit(tabCheckInfo);
        dateEditCheckTimeInfo->setObjectName(QStringLiteral("dateEditCheckTimeInfo"));
        dateEditCheckTimeInfo->setEnabled(false);
        dateEditCheckTimeInfo->setMinimumSize(QSize(200, 0));
        dateEditCheckTimeInfo->setMaximumSize(QSize(200, 16777215));
        dateEditCheckTimeInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_12->addWidget(dateEditCheckTimeInfo);


        verticalLayout_5->addLayout(horizontalLayout_12);

        horizontalSpacer_5 = new QSpacerItem(40, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_5->addItem(horizontalSpacer_5);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        labelTime = new QLabel(tabCheckInfo);
        labelTime->setObjectName(QStringLiteral("labelTime"));
        labelTime->setFont(font1);

        horizontalLayout_18->addWidget(labelTime);

        timeEditCheckTimeInfo = new QTimeEdit(tabCheckInfo);
        timeEditCheckTimeInfo->setObjectName(QStringLiteral("timeEditCheckTimeInfo"));
        timeEditCheckTimeInfo->setEnabled(false);
        timeEditCheckTimeInfo->setMinimumSize(QSize(200, 0));
        timeEditCheckTimeInfo->setMaximumSize(QSize(200, 16777215));
        timeEditCheckTimeInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_18->addWidget(timeEditCheckTimeInfo);


        verticalLayout_5->addLayout(horizontalLayout_18);

        horizontalSpacer_8 = new QSpacerItem(40, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_5->addItem(horizontalSpacer_8);

        commandLinkButtonLog = new QCommandLinkButton(tabCheckInfo);
        commandLinkButtonLog->setObjectName(QStringLiteral("commandLinkButtonLog"));

        verticalLayout_5->addWidget(commandLinkButtonLog);

        horizontalSpacer_11 = new QSpacerItem(40, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_5->addItem(horizontalSpacer_11);

        label_20 = new QLabel(tabCheckInfo);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setMinimumSize(QSize(0, 30));
        label_20->setMaximumSize(QSize(16777215, 30));
        label_20->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"background-color:rgb(180, 85, 100);\n"
"color:white;\n"
"font-size:14px;\n"
"font-weight:bold;\n"
"}"));
        label_20->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_5->addWidget(label_20);

        horizontalSpacer_10 = new QSpacerItem(40, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_5->addItem(horizontalSpacer_10);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_5 = new QLabel(tabCheckInfo);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);

        horizontalLayout_8->addWidget(label_5);

        commandLinkButtonMatListInfo = new QCommandLinkButton(tabCheckInfo);
        commandLinkButtonMatListInfo->setObjectName(QStringLiteral("commandLinkButtonMatListInfo"));
        commandLinkButtonMatListInfo->setMinimumSize(QSize(200, 30));
        commandLinkButtonMatListInfo->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_8->addWidget(commandLinkButtonMatListInfo);


        verticalLayout_5->addLayout(horizontalLayout_8);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        pushButtonCheckFinishInfo = new QPushButton(tabCheckInfo);
        pushButtonCheckFinishInfo->setObjectName(QStringLiteral("pushButtonCheckFinishInfo"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/image/image/\347\241\256\350\256\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCheckFinishInfo->setIcon(icon5);

        horizontalLayout_19->addWidget(pushButtonCheckFinishInfo);

        pushButtonCancelCheckInfo = new QPushButton(tabCheckInfo);
        pushButtonCancelCheckInfo->setObjectName(QStringLiteral("pushButtonCancelCheckInfo"));
        pushButtonCancelCheckInfo->setIcon(icon4);

        horizontalLayout_19->addWidget(pushButtonCancelCheckInfo);


        verticalLayout_5->addLayout(horizontalLayout_19);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        pushButtonSaveInfo = new QPushButton(tabCheckInfo);
        pushButtonSaveInfo->setObjectName(QStringLiteral("pushButtonSaveInfo"));
        pushButtonSaveInfo->setIcon(icon3);

        horizontalLayout_17->addWidget(pushButtonSaveInfo);

        pushButtonDeleteInfo = new QPushButton(tabCheckInfo);
        pushButtonDeleteInfo->setObjectName(QStringLiteral("pushButtonDeleteInfo"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/image/image/\345\210\240 \351\231\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonDeleteInfo->setIcon(icon6);

        horizontalLayout_17->addWidget(pushButtonDeleteInfo);

        pushButtonCancelInfo = new QPushButton(tabCheckInfo);
        pushButtonCancelInfo->setObjectName(QStringLiteral("pushButtonCancelInfo"));
        pushButtonCancelInfo->setIcon(icon4);

        horizontalLayout_17->addWidget(pushButtonCancelInfo);


        verticalLayout_5->addLayout(horizontalLayout_17);

        tabWidgetCheck->addTab(tabCheckInfo, QString());

        horizontalLayout_2->addWidget(tabWidgetCheck);

        horizontalLayout_2->setStretch(0, 7);
        horizontalLayout_2->setStretch(1, 4);

        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(InventoryCheck);

        tabWidgetCheck->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(InventoryCheck);
    } // setupUi

    void retranslateUi(QWidget *InventoryCheck)
    {
        InventoryCheck->setWindowTitle(QApplication::translate("InventoryCheck", "Form", 0));
        labelState->setText(QApplication::translate("InventoryCheck", " \347\212\266\346\200\201\357\274\232", 0));
        labelWhse->setText(QApplication::translate("InventoryCheck", " \344\273\223\345\272\223\357\274\232", 0));
        labelDateTime->setText(QApplication::translate("InventoryCheck", " \347\233\230\345\255\230\346\227\245\346\234\237\357\274\232", 0));
        pushButtonSelect->setText(QApplication::translate("InventoryCheck", "\346\237\245\350\257\242", 0));
        pushButtonExtend->setText(QApplication::translate("InventoryCheck", "\345\257\274\345\207\272", 0));
        labelSize->setText(QString());
        pushButtonAdd->setText(QApplication::translate("InventoryCheck", "\346\267\273\345\212\240", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetCheck->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("InventoryCheck", "\344\273\223\345\272\223\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetCheck->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("InventoryCheck", "\347\233\230\345\255\230\345\215\225\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetCheck->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("InventoryCheck", "\347\233\230\345\255\230\346\227\245\346\234\237", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetCheck->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("InventoryCheck", "\347\212\266\346\200\201", 0));
        commandLinkButtonImport->setText(QApplication::translate("InventoryCheck", "\344\273\216\345\216\206\345\217\262\347\233\230\345\255\230\345\215\225\345\257\274\345\205\245", 0));
        label_7->setText(QApplication::translate("InventoryCheck", " \345\237\272\346\234\254\344\277\241\346\201\257", 0));
        label_3->setText(QApplication::translate("InventoryCheck", "\347\233\230\345\255\230\344\273\223\345\272\223\357\274\232", 0));
#ifndef QT_NO_TOOLTIP
        comboBoxWarHse->setToolTip(QApplication::translate("InventoryCheck", "\345\217\257\344\270\215\345\241\253", 0));
#endif // QT_NO_TOOLTIP
        comboBoxWarHse->setCurrentText(QString());
        label_8->setText(QApplication::translate("InventoryCheck", " \347\233\230\345\255\230\345\216\237\346\226\231", 0));
        label_4->setText(QApplication::translate("InventoryCheck", "\345\216\237\346\226\231\346\270\205\345\215\225\357\274\232", 0));
        commandLinkButtonMatList->setText(QApplication::translate("InventoryCheck", "0\351\241\271", 0));
        pushButtonSave->setText(QApplication::translate("InventoryCheck", "  \344\277\235\345\255\230", 0));
        pushButtonCancel->setText(QApplication::translate("InventoryCheck", " \345\217\226\346\266\210", 0));
        tabWidgetCheck->setTabText(tabWidgetCheck->indexOf(tabAddCheck), QApplication::translate("InventoryCheck", "\346\267\273\345\212\240\344\273\223\345\272\223\347\233\230\345\255\230\345\215\225", 0));
        label_18->setText(QApplication::translate("InventoryCheck", " \345\237\272\346\234\254\344\277\241\346\201\257", 0));
        label_19->setText(QApplication::translate("InventoryCheck", "\347\233\230\345\255\230\345\215\225\345\217\267\357\274\232", 0));
        label_14->setText(QApplication::translate("InventoryCheck", "\347\212\266\346\200\201\357\274\232", 0));
        label_16->setText(QApplication::translate("InventoryCheck", "\347\233\230\345\255\230\344\273\223\345\272\223\357\274\232", 0));
#ifndef QT_NO_TOOLTIP
        comboBoxWarHseInfo->setToolTip(QApplication::translate("InventoryCheck", "\345\217\257\344\270\215\345\241\253", 0));
#endif // QT_NO_TOOLTIP
        comboBoxWarHseInfo->setCurrentText(QString());
        labelDate->setText(QApplication::translate("InventoryCheck", "\347\233\230\345\255\230\346\227\245\346\234\237\357\274\232", 0));
        labelTime->setText(QApplication::translate("InventoryCheck", "\347\233\230\345\255\230\346\227\266\351\227\264\357\274\232", 0));
        commandLinkButtonLog->setText(QApplication::translate("InventoryCheck", " \345\244\204\347\220\206\350\256\260\345\275\225", 0));
        label_20->setText(QApplication::translate("InventoryCheck", " \345\237\272\346\234\254\344\277\241\346\201\257", 0));
        label_5->setText(QApplication::translate("InventoryCheck", "\345\216\237\346\226\231\346\270\205\345\215\225\357\274\232", 0));
        commandLinkButtonMatListInfo->setText(QApplication::translate("InventoryCheck", "0\351\241\271", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonCheckFinishInfo->setToolTip(QApplication::translate("InventoryCheck", "\345\274\200\345\247\213\347\241\256\350\256\244\351\207\207\350\264\255\345\216\237\346\226\231", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        pushButtonCheckFinishInfo->setWhatsThis(QApplication::translate("InventoryCheck", "\345\274\200\345\247\213\347\241\256\350\256\244\351\207\207\350\264\255\345\216\237\346\226\231", 0));
#endif // QT_NO_WHATSTHIS
        pushButtonCheckFinishInfo->setText(QApplication::translate("InventoryCheck", " \347\233\230\345\255\230\345\256\214\346\210\220", 0));
        pushButtonCancelCheckInfo->setText(QApplication::translate("InventoryCheck", " \345\217\226\346\266\210\347\233\230\345\255\230", 0));
        pushButtonSaveInfo->setText(QApplication::translate("InventoryCheck", " \344\277\235\345\255\230", 0));
        pushButtonDeleteInfo->setText(QApplication::translate("InventoryCheck", " \345\210\240\351\231\244", 0));
        pushButtonCancelInfo->setText(QApplication::translate("InventoryCheck", " \345\217\226\346\266\210", 0));
        tabWidgetCheck->setTabText(tabWidgetCheck->indexOf(tabCheckInfo), QApplication::translate("InventoryCheck", "\344\273\223\345\272\223\347\233\230\345\255\230\345\215\225\350\257\246\346\203\205", 0));
    } // retranslateUi

};

namespace Ui {
    class InventoryCheck: public Ui_InventoryCheck {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVENTORYCHECK_H
