/********************************************************************************
** Form generated from reading UI file 'purchasestorage.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PURCHASESTORAGE_H
#define UI_PURCHASESTORAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
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

class Ui_purchasestorage
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_20;
    QWidget *widgetControl;
    QPushButton *pushButtonClose;
    QLabel *labelState;
    QLabel *labelWareHouse;
    QComboBox *comboBoxStateSelect;
    QLabel *labelSupplier;
    QComboBox *comboBoxWareHouseSelect;
    QComboBox *comboBoxSupSelect;
    QLabel *labelTime;
    QLabel *labelStartTime;
    QComboBox *comboBoxTimeSelect;
    QDateEdit *dateEditStartTime;
    QLabel *labelEndTime;
    QDateEdit *dateEditEndTime;
    QPushButton *pushButtonSelect;
    QPushButton *pushButtonExtend;
    QPushButton *pushButtonAdd;
    QLabel *labelSize;
    QTableWidget *tableWidgetPur;
    QTabWidget *tabWidgetPurchase;
    QWidget *tabAddSto;
    QVBoxLayout *verticalLayout_3;
    QCommandLinkButton *commandLinkButtonPurHistory;
    QCommandLinkButton *commandLinkButtonStoHistory;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QComboBox *comboBoxPurWarHse;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QComboBox *comboBoxSupplier;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QDateEdit *dateEditArriveTime;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_6;
    QTimeEdit *timeEditAddTime;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QLineEdit *lineEditRemark;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_8;
    QPushButton *pushButtonAddPurMat;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonCancel;
    QWidget *tabPurInfo;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_18;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_19;
    QLineEdit *lineEditNumberInfo;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_20;
    QLineEdit *lineEditStateInfo;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_13;
    QLineEdit *lineEditSupplierInfo;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_16;
    QComboBox *comboBoxPurWarHseInfo;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_15;
    QDateEdit *dateEditArriveTimeInfo;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_21;
    QTimeEdit *timeEditStorageTime;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_17;
    QLineEdit *lineEditRemarkInfo;
    QCommandLinkButton *commandLinkButtonLog;
    QFrame *frame;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_5;
    QLabel *labelTotalCount;
    QSpacerItem *horizontalSpacer_8;
    QCommandLinkButton *commandLinkButtonEdit;
    QTableWidget *tableWidgetPurInfo;
    QPushButton *pushButtonPurMatInfo;
    QPushButton *pushButtonReConfirm;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonRefuse;
    QPushButton *pushButtonStart;
    QHBoxLayout *horizontalLayout_21;
    QPushButton *pushButtonFinish;
    QPushButton *pushButtonStartCarry;
    QHBoxLayout *horizontalLayout_17;
    QPushButton *pushButtonSaveInfo;
    QPushButton *pushButtonDel;
    QPushButton *pushButtonCancelInfo;

    void setupUi(QWidget *purchasestorage)
    {
        if (purchasestorage->objectName().isEmpty())
            purchasestorage->setObjectName(QStringLiteral("purchasestorage"));
        purchasestorage->resize(398, 486);
        purchasestorage->setStyleSheet(QLatin1String("QComboBox \n"
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
"border-radius:2px;\n"
"width:100px;\n"
"spacing:2px;\n"
"padding: 0px 0px;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(purchasestorage);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 0, -1, -1);
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));

        verticalLayout->addLayout(horizontalLayout_20);

        widgetControl = new QWidget(purchasestorage);
        widgetControl->setObjectName(QStringLiteral("widgetControl"));
        widgetControl->setMinimumSize(QSize(0, 20));
        pushButtonClose = new QPushButton(widgetControl);
        pushButtonClose->setObjectName(QStringLiteral("pushButtonClose"));
        pushButtonClose->setGeometry(QRect(11, 13, 38, 16));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/image/fail.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonClose->setIcon(icon);
        labelState = new QLabel(widgetControl);
        labelState->setObjectName(QStringLiteral("labelState"));
        labelState->setGeometry(QRect(55, 0, 37, 42));
        labelWareHouse = new QLabel(widgetControl);
        labelWareHouse->setObjectName(QStringLiteral("labelWareHouse"));
        labelWareHouse->setGeometry(QRect(142, 0, 37, 42));
        comboBoxStateSelect = new QComboBox(widgetControl);
        comboBoxStateSelect->setObjectName(QStringLiteral("comboBoxStateSelect"));
        comboBoxStateSelect->setGeometry(QRect(98, 10, 38, 22));
        comboBoxStateSelect->setMinimumSize(QSize(0, 0));
        labelSupplier = new QLabel(widgetControl);
        labelSupplier->setObjectName(QStringLiteral("labelSupplier"));
        labelSupplier->setGeometry(QRect(228, 0, 38, 42));
        comboBoxWareHouseSelect = new QComboBox(widgetControl);
        comboBoxWareHouseSelect->setObjectName(QStringLiteral("comboBoxWareHouseSelect"));
        comboBoxWareHouseSelect->setGeometry(QRect(185, 10, 37, 22));
        comboBoxWareHouseSelect->setMinimumSize(QSize(0, 0));
        comboBoxSupSelect = new QComboBox(widgetControl);
        comboBoxSupSelect->setObjectName(QStringLiteral("comboBoxSupSelect"));
        comboBoxSupSelect->setGeometry(QRect(272, 10, 37, 22));
        comboBoxSupSelect->setMinimumSize(QSize(0, 0));
        labelTime = new QLabel(widgetControl);
        labelTime->setObjectName(QStringLiteral("labelTime"));
        labelTime->setGeometry(QRect(315, 0, 37, 42));
        labelStartTime = new QLabel(widgetControl);
        labelStartTime->setObjectName(QStringLiteral("labelStartTime"));
        labelStartTime->setGeometry(QRect(402, 0, 37, 42));
        comboBoxTimeSelect = new QComboBox(widgetControl);
        comboBoxTimeSelect->setObjectName(QStringLiteral("comboBoxTimeSelect"));
        comboBoxTimeSelect->setGeometry(QRect(358, 10, 38, 22));
        comboBoxTimeSelect->setMinimumSize(QSize(0, 0));
        dateEditStartTime = new QDateEdit(widgetControl);
        dateEditStartTime->setObjectName(QStringLiteral("dateEditStartTime"));
        dateEditStartTime->setGeometry(QRect(445, 6, 38, 30));
        labelEndTime = new QLabel(widgetControl);
        labelEndTime->setObjectName(QStringLiteral("labelEndTime"));
        labelEndTime->setGeometry(QRect(489, 0, 37, 42));
        dateEditEndTime = new QDateEdit(widgetControl);
        dateEditEndTime->setObjectName(QStringLiteral("dateEditEndTime"));
        dateEditEndTime->setGeometry(QRect(532, 6, 37, 30));
        pushButtonSelect = new QPushButton(widgetControl);
        pushButtonSelect->setObjectName(QStringLiteral("pushButtonSelect"));
        pushButtonSelect->setGeometry(QRect(575, 13, 38, 16));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/image/\346\237\245\350\257\242.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSelect->setIcon(icon1);
        pushButtonExtend = new QPushButton(widgetControl);
        pushButtonExtend->setObjectName(QStringLiteral("pushButtonExtend"));
        pushButtonExtend->setGeometry(QRect(619, 13, 37, 16));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/image/export.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonExtend->setIcon(icon2);
        pushButtonAdd = new QPushButton(widgetControl);
        pushButtonAdd->setObjectName(QStringLiteral("pushButtonAdd"));
        pushButtonAdd->setGeometry(QRect(662, 13, 37, 16));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/image/addfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonAdd->setIcon(icon3);
        labelSize = new QLabel(widgetControl);
        labelSize->setObjectName(QStringLiteral("labelSize"));
        labelSize->setGeometry(QRect(705, 10, 16, 18));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        labelSize->setFont(font);

        verticalLayout->addWidget(widgetControl);

        tableWidgetPur = new QTableWidget(purchasestorage);
        if (tableWidgetPur->columnCount() < 4)
            tableWidgetPur->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetPur->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetPur->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetPur->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetPur->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidgetPur->setObjectName(QStringLiteral("tableWidgetPur"));

        verticalLayout->addWidget(tableWidgetPur);


        horizontalLayout_2->addLayout(verticalLayout);

        tabWidgetPurchase = new QTabWidget(purchasestorage);
        tabWidgetPurchase->setObjectName(QStringLiteral("tabWidgetPurchase"));
        tabAddSto = new QWidget();
        tabAddSto->setObjectName(QStringLiteral("tabAddSto"));
        verticalLayout_3 = new QVBoxLayout(tabAddSto);
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        commandLinkButtonPurHistory = new QCommandLinkButton(tabAddSto);
        commandLinkButtonPurHistory->setObjectName(QStringLiteral("commandLinkButtonPurHistory"));

        verticalLayout_3->addWidget(commandLinkButtonPurHistory);

        commandLinkButtonStoHistory = new QCommandLinkButton(tabAddSto);
        commandLinkButtonStoHistory->setObjectName(QStringLiteral("commandLinkButtonStoHistory"));

        verticalLayout_3->addWidget(commandLinkButtonStoHistory);

        label_7 = new QLabel(tabAddSto);
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

        horizontalSpacer_4 = new QSpacerItem(40, 3, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_3 = new QLabel(tabAddSto);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);

        horizontalLayout_6->addWidget(label_3);

        comboBoxPurWarHse = new QComboBox(tabAddSto);
        comboBoxPurWarHse->setObjectName(QStringLiteral("comboBoxPurWarHse"));
        comboBoxPurWarHse->setMinimumSize(QSize(200, 30));
        comboBoxPurWarHse->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_6->addWidget(comboBoxPurWarHse);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalSpacer_3 = new QSpacerItem(40, 3, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label = new QLabel(tabAddSto);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);

        horizontalLayout_4->addWidget(label);

        comboBoxSupplier = new QComboBox(tabAddSto);
        comboBoxSupplier->setObjectName(QStringLiteral("comboBoxSupplier"));
        comboBoxSupplier->setMinimumSize(QSize(200, 30));
        comboBoxSupplier->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_4->addWidget(comboBoxSupplier);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalSpacer_5 = new QSpacerItem(40, 3, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_5);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_2 = new QLabel(tabAddSto);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        horizontalLayout_5->addWidget(label_2);

        dateEditArriveTime = new QDateEdit(tabAddSto);
        dateEditArriveTime->setObjectName(QStringLiteral("dateEditArriveTime"));
        dateEditArriveTime->setMinimumSize(QSize(200, 30));
        dateEditArriveTime->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_5->addWidget(dateEditArriveTime);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalSpacer_6 = new QSpacerItem(40, 3, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_6);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_6 = new QLabel(tabAddSto);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);

        horizontalLayout_10->addWidget(label_6);

        timeEditAddTime = new QTimeEdit(tabAddSto);
        timeEditAddTime->setObjectName(QStringLiteral("timeEditAddTime"));
        timeEditAddTime->setMinimumSize(QSize(200, 30));
        timeEditAddTime->setMaximumSize(QSize(200, 30));
        timeEditAddTime->setStyleSheet(QStringLiteral(""));

        horizontalLayout_10->addWidget(timeEditAddTime);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalSpacer_9 = new QSpacerItem(40, 3, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_9);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_4 = new QLabel(tabAddSto);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        horizontalLayout_7->addWidget(label_4);

        lineEditRemark = new QLineEdit(tabAddSto);
        lineEditRemark->setObjectName(QStringLiteral("lineEditRemark"));
        lineEditRemark->setMinimumSize(QSize(200, 30));
        lineEditRemark->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_7->addWidget(lineEditRemark);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalSpacer_7 = new QSpacerItem(40, 3, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_7);

        label_8 = new QLabel(tabAddSto);
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

        pushButtonAddPurMat = new QPushButton(tabAddSto);
        pushButtonAddPurMat->setObjectName(QStringLiteral("pushButtonAddPurMat"));
        pushButtonAddPurMat->setMinimumSize(QSize(0, 60));
        pushButtonAddPurMat->setIcon(icon3);

        verticalLayout_3->addWidget(pushButtonAddPurMat);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        pushButtonSave = new QPushButton(tabAddSto);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/image/image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSave->setIcon(icon4);

        horizontalLayout_9->addWidget(pushButtonSave);

        pushButtonCancel = new QPushButton(tabAddSto);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/image/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon5);

        horizontalLayout_9->addWidget(pushButtonCancel);


        verticalLayout_3->addLayout(horizontalLayout_9);

        tabWidgetPurchase->addTab(tabAddSto, QString());
        tabPurInfo = new QWidget();
        tabPurInfo->setObjectName(QStringLiteral("tabPurInfo"));
        verticalLayout_5 = new QVBoxLayout(tabPurInfo);
        verticalLayout_5->setSpacing(2);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(2, 0, 2, 0);
        label_18 = new QLabel(tabPurInfo);
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

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_19 = new QLabel(tabPurInfo);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setFont(font1);

        horizontalLayout_15->addWidget(label_19);

        lineEditNumberInfo = new QLineEdit(tabPurInfo);
        lineEditNumberInfo->setObjectName(QStringLiteral("lineEditNumberInfo"));
        lineEditNumberInfo->setEnabled(false);
        lineEditNumberInfo->setMinimumSize(QSize(200, 0));
        lineEditNumberInfo->setMaximumSize(QSize(200, 16777215));
        lineEditNumberInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_15->addWidget(lineEditNumberInfo);


        verticalLayout_5->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_20 = new QLabel(tabPurInfo);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setFont(font1);

        horizontalLayout_16->addWidget(label_20);

        lineEditStateInfo = new QLineEdit(tabPurInfo);
        lineEditStateInfo->setObjectName(QStringLiteral("lineEditStateInfo"));
        lineEditStateInfo->setEnabled(false);
        lineEditStateInfo->setMinimumSize(QSize(200, 0));
        lineEditStateInfo->setMaximumSize(QSize(200, 16777215));
        lineEditStateInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_16->addWidget(lineEditStateInfo);


        verticalLayout_5->addLayout(horizontalLayout_16);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_13 = new QLabel(tabPurInfo);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font1);

        horizontalLayout_11->addWidget(label_13);

        lineEditSupplierInfo = new QLineEdit(tabPurInfo);
        lineEditSupplierInfo->setObjectName(QStringLiteral("lineEditSupplierInfo"));
        lineEditSupplierInfo->setEnabled(false);
        lineEditSupplierInfo->setMinimumSize(QSize(200, 0));
        lineEditSupplierInfo->setMaximumSize(QSize(200, 16777215));
        lineEditSupplierInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_11->addWidget(lineEditSupplierInfo);


        verticalLayout_5->addLayout(horizontalLayout_11);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_16 = new QLabel(tabPurInfo);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font1);

        horizontalLayout_13->addWidget(label_16);

        comboBoxPurWarHseInfo = new QComboBox(tabPurInfo);
        comboBoxPurWarHseInfo->setObjectName(QStringLiteral("comboBoxPurWarHseInfo"));
        comboBoxPurWarHseInfo->setMinimumSize(QSize(200, 0));
        comboBoxPurWarHseInfo->setMaximumSize(QSize(200, 16777215));
        comboBoxPurWarHseInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_13->addWidget(comboBoxPurWarHseInfo);


        verticalLayout_5->addLayout(horizontalLayout_13);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_15 = new QLabel(tabPurInfo);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font1);

        horizontalLayout_12->addWidget(label_15);

        dateEditArriveTimeInfo = new QDateEdit(tabPurInfo);
        dateEditArriveTimeInfo->setObjectName(QStringLiteral("dateEditArriveTimeInfo"));
        dateEditArriveTimeInfo->setMinimumSize(QSize(200, 0));
        dateEditArriveTimeInfo->setMaximumSize(QSize(200, 16777215));
        dateEditArriveTimeInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_12->addWidget(dateEditArriveTimeInfo);


        verticalLayout_5->addLayout(horizontalLayout_12);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        label_21 = new QLabel(tabPurInfo);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setFont(font1);

        horizontalLayout_18->addWidget(label_21);

        timeEditStorageTime = new QTimeEdit(tabPurInfo);
        timeEditStorageTime->setObjectName(QStringLiteral("timeEditStorageTime"));
        timeEditStorageTime->setMinimumSize(QSize(200, 0));
        timeEditStorageTime->setMaximumSize(QSize(200, 30));
        timeEditStorageTime->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_18->addWidget(timeEditStorageTime);


        verticalLayout_5->addLayout(horizontalLayout_18);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_17 = new QLabel(tabPurInfo);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setFont(font1);

        horizontalLayout_14->addWidget(label_17);

        lineEditRemarkInfo = new QLineEdit(tabPurInfo);
        lineEditRemarkInfo->setObjectName(QStringLiteral("lineEditRemarkInfo"));
        lineEditRemarkInfo->setMinimumSize(QSize(200, 0));
        lineEditRemarkInfo->setMaximumSize(QSize(200, 16777215));
        lineEditRemarkInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_14->addWidget(lineEditRemarkInfo);


        verticalLayout_5->addLayout(horizontalLayout_14);

        commandLinkButtonLog = new QCommandLinkButton(tabPurInfo);
        commandLinkButtonLog->setObjectName(QStringLiteral("commandLinkButtonLog"));

        verticalLayout_5->addWidget(commandLinkButtonLog);

        frame = new QFrame(tabPurInfo);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(0, 40));
        frame->setMaximumSize(QSize(16777215, 40));
        frame->setStyleSheet(QLatin1String("QFrame\n"
"{\n"
"background-color:rgb(180, 85, 100);\n"
"color:white;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_8 = new QVBoxLayout(frame);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(0, 30));
        label_5->setMaximumSize(QSize(16777215, 30));
        QFont font2;
        font2.setFamily(QStringLiteral("Aharoni"));
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        label_5->setFont(font2);
        label_5->setStyleSheet(QStringLiteral(""));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_8->addWidget(label_5);

        labelTotalCount = new QLabel(frame);
        labelTotalCount->setObjectName(QStringLiteral("labelTotalCount"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        labelTotalCount->setFont(font3);

        horizontalLayout_8->addWidget(labelTotalCount);

        horizontalSpacer_8 = new QSpacerItem(5, 5, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);

        commandLinkButtonEdit = new QCommandLinkButton(frame);
        commandLinkButtonEdit->setObjectName(QStringLiteral("commandLinkButtonEdit"));
        commandLinkButtonEdit->setMinimumSize(QSize(140, 0));
        commandLinkButtonEdit->setMaximumSize(QSize(200, 16777215));
        commandLinkButtonEdit->setStyleSheet(QStringLiteral("background-color: transparent;"));

        horizontalLayout_8->addWidget(commandLinkButtonEdit);


        verticalLayout_8->addLayout(horizontalLayout_8);


        verticalLayout_5->addWidget(frame);

        tableWidgetPurInfo = new QTableWidget(tabPurInfo);
        if (tableWidgetPurInfo->columnCount() < 6)
            tableWidgetPurInfo->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetPurInfo->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidgetPurInfo->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidgetPurInfo->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidgetPurInfo->setHorizontalHeaderItem(3, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidgetPurInfo->setHorizontalHeaderItem(4, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidgetPurInfo->setHorizontalHeaderItem(5, __qtablewidgetitem9);
        tableWidgetPurInfo->setObjectName(QStringLiteral("tableWidgetPurInfo"));

        verticalLayout_5->addWidget(tableWidgetPurInfo);

        pushButtonPurMatInfo = new QPushButton(tabPurInfo);
        pushButtonPurMatInfo->setObjectName(QStringLiteral("pushButtonPurMatInfo"));
        pushButtonPurMatInfo->setMinimumSize(QSize(0, 0));
        pushButtonPurMatInfo->setIcon(icon3);

        verticalLayout_5->addWidget(pushButtonPurMatInfo);

        pushButtonReConfirm = new QPushButton(tabPurInfo);
        pushButtonReConfirm->setObjectName(QStringLiteral("pushButtonReConfirm"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/image/image/\345\217\215\347\241\256\350\256\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonReConfirm->setIcon(icon6);

        verticalLayout_5->addWidget(pushButtonReConfirm);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButtonRefuse = new QPushButton(tabPurInfo);
        pushButtonRefuse->setObjectName(QStringLiteral("pushButtonRefuse"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/image/image/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonRefuse->setIcon(icon7);

        horizontalLayout_3->addWidget(pushButtonRefuse);

        pushButtonStart = new QPushButton(tabPurInfo);
        pushButtonStart->setObjectName(QStringLiteral("pushButtonStart"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/image/image/\347\241\256\350\256\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonStart->setIcon(icon8);

        horizontalLayout_3->addWidget(pushButtonStart);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        pushButtonFinish = new QPushButton(tabPurInfo);
        pushButtonFinish->setObjectName(QStringLiteral("pushButtonFinish"));
        pushButtonFinish->setIcon(icon8);

        horizontalLayout_21->addWidget(pushButtonFinish);

        pushButtonStartCarry = new QPushButton(tabPurInfo);
        pushButtonStartCarry->setObjectName(QStringLiteral("pushButtonStartCarry"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/image/image/\350\267\263\350\275\254.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonStartCarry->setIcon(icon9);

        horizontalLayout_21->addWidget(pushButtonStartCarry);


        verticalLayout_5->addLayout(horizontalLayout_21);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        pushButtonSaveInfo = new QPushButton(tabPurInfo);
        pushButtonSaveInfo->setObjectName(QStringLiteral("pushButtonSaveInfo"));
        pushButtonSaveInfo->setIcon(icon4);

        horizontalLayout_17->addWidget(pushButtonSaveInfo);

        pushButtonDel = new QPushButton(tabPurInfo);
        pushButtonDel->setObjectName(QStringLiteral("pushButtonDel"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/image/image/\345\210\240 \351\231\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonDel->setIcon(icon10);

        horizontalLayout_17->addWidget(pushButtonDel);

        pushButtonCancelInfo = new QPushButton(tabPurInfo);
        pushButtonCancelInfo->setObjectName(QStringLiteral("pushButtonCancelInfo"));
        pushButtonCancelInfo->setIcon(icon5);

        horizontalLayout_17->addWidget(pushButtonCancelInfo);


        verticalLayout_5->addLayout(horizontalLayout_17);

        tabWidgetPurchase->addTab(tabPurInfo, QString());

        horizontalLayout_2->addWidget(tabWidgetPurchase);

        horizontalLayout_2->setStretch(0, 6);
        horizontalLayout_2->setStretch(1, 4);

        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(purchasestorage);

        tabWidgetPurchase->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(purchasestorage);
    } // setupUi

    void retranslateUi(QWidget *purchasestorage)
    {
        purchasestorage->setWindowTitle(QApplication::translate("purchasestorage", "Form", 0));
        pushButtonClose->setText(QApplication::translate("purchasestorage", "\350\277\224\345\233\236", 0));
        labelState->setText(QApplication::translate("purchasestorage", "\347\212\266\346\200\201\357\274\232", 0));
        labelWareHouse->setText(QApplication::translate("purchasestorage", " \345\205\245\345\272\223\344\273\223\345\272\223\357\274\232", 0));
        labelSupplier->setText(QApplication::translate("purchasestorage", "  \344\276\233\345\272\224\345\225\206\357\274\232", 0));
        labelTime->setText(QApplication::translate("purchasestorage", " \345\205\245\345\272\223\346\227\245\346\234\237\357\274\232", 0));
        labelStartTime->setText(QApplication::translate("purchasestorage", " \345\274\200\345\247\213\346\227\245\346\234\237\357\274\232", 0));
        labelEndTime->setText(QApplication::translate("purchasestorage", " \347\273\223\346\235\237\346\227\245\346\234\237\357\274\232", 0));
        pushButtonSelect->setText(QApplication::translate("purchasestorage", "\346\237\245\350\257\242", 0));
        pushButtonExtend->setText(QApplication::translate("purchasestorage", "\345\257\274\345\207\272", 0));
        pushButtonAdd->setText(QApplication::translate("purchasestorage", "\346\267\273\345\212\240", 0));
        labelSize->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidgetPur->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("purchasestorage", "\344\276\233\345\272\224\345\225\206", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetPur->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("purchasestorage", "\345\205\245\345\272\223\345\215\225\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetPur->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("purchasestorage", "\345\205\245\345\272\223\346\227\245\346\234\237", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetPur->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("purchasestorage", "\347\212\266\346\200\201", 0));
        commandLinkButtonPurHistory->setText(QApplication::translate("purchasestorage", " \344\273\216\345\216\206\345\217\262\351\207\207\350\264\255\350\256\242\345\215\225\345\257\274\345\205\245", 0));
        commandLinkButtonStoHistory->setText(QApplication::translate("purchasestorage", " \344\273\216\345\216\206\345\217\262\345\205\245\345\272\223\345\215\225\345\257\274\345\205\245", 0));
        label_7->setText(QApplication::translate("purchasestorage", " \345\237\272\346\234\254\344\277\241\346\201\257", 0));
        label_3->setText(QApplication::translate("purchasestorage", "\345\205\245\345\272\223\344\273\223\345\272\223\357\274\232", 0));
#ifndef QT_NO_TOOLTIP
        comboBoxPurWarHse->setToolTip(QApplication::translate("purchasestorage", "\345\217\257\344\270\215\345\241\253", 0));
#endif // QT_NO_TOOLTIP
        comboBoxPurWarHse->setCurrentText(QString());
        label->setText(QApplication::translate("purchasestorage", "\344\276\233\345\272\224\345\225\206\357\274\232", 0));
        label_2->setText(QApplication::translate("purchasestorage", "\345\205\245\345\272\223\346\227\245\346\234\237\357\274\232", 0));
        label_6->setText(QApplication::translate("purchasestorage", "\345\205\245\345\272\223\346\227\266\351\227\264\357\274\232", 0));
        label_4->setText(QApplication::translate("purchasestorage", "\345\244\207\346\263\250\357\274\232", 0));
        lineEditRemark->setPlaceholderText(QApplication::translate("purchasestorage", "\345\217\257\344\270\215\345\241\253", 0));
        label_8->setText(QApplication::translate("purchasestorage", " \351\207\207\350\264\255\345\216\237\346\226\231", 0));
        pushButtonAddPurMat->setText(QApplication::translate("purchasestorage", " \346\267\273\345\212\240\351\207\207\350\264\255\345\216\237\346\226\231...", 0));
        pushButtonSave->setText(QApplication::translate("purchasestorage", "  \344\277\235\345\255\230", 0));
        pushButtonCancel->setText(QApplication::translate("purchasestorage", " \345\217\226\346\266\210", 0));
        tabWidgetPurchase->setTabText(tabWidgetPurchase->indexOf(tabAddSto), QApplication::translate("purchasestorage", "\346\267\273\345\212\240\345\205\245\345\272\223\345\215\225", 0));
        label_18->setText(QApplication::translate("purchasestorage", " \345\237\272\346\234\254\344\277\241\346\201\257", 0));
        label_19->setText(QApplication::translate("purchasestorage", "\345\205\245\345\272\223\345\215\225\345\217\267\357\274\232", 0));
        label_20->setText(QApplication::translate("purchasestorage", "\347\212\266\346\200\201\357\274\232", 0));
        label_13->setText(QApplication::translate("purchasestorage", "\344\276\233\345\272\224\345\225\206\357\274\232", 0));
        label_16->setText(QApplication::translate("purchasestorage", "\345\205\245\345\272\223\344\273\223\345\272\223\357\274\232", 0));
#ifndef QT_NO_TOOLTIP
        comboBoxPurWarHseInfo->setToolTip(QApplication::translate("purchasestorage", "\345\217\257\344\270\215\345\241\253", 0));
#endif // QT_NO_TOOLTIP
        comboBoxPurWarHseInfo->setCurrentText(QString());
        label_15->setText(QApplication::translate("purchasestorage", "\345\205\245\345\272\223\346\227\245\346\234\237\357\274\232", 0));
        label_21->setText(QApplication::translate("purchasestorage", "\345\205\245\345\272\223\346\227\266\351\227\264\357\274\232", 0));
        label_17->setText(QApplication::translate("purchasestorage", "\345\244\207\346\263\250\357\274\232", 0));
        lineEditRemarkInfo->setPlaceholderText(QApplication::translate("purchasestorage", "\345\217\257\344\270\215\345\241\253", 0));
        commandLinkButtonLog->setText(QApplication::translate("purchasestorage", " \345\244\204\347\220\206\350\256\260\345\275\225", 0));
        label_5->setText(QApplication::translate("purchasestorage", " \345\205\245\345\272\223\345\216\237\346\226\231", 0));
        labelTotalCount->setText(QString());
        commandLinkButtonEdit->setText(QApplication::translate("purchasestorage", " \347\274\226\350\276\221\345\205\245\345\272\223\345\216\237\346\226\231", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetPurInfo->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("purchasestorage", "\345\216\237\346\226\231\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetPurInfo->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("purchasestorage", "\346\235\241\345\275\242\347\240\201", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetPurInfo->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("purchasestorage", "\345\215\225\344\275\215", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidgetPurInfo->horizontalHeaderItem(3);
        ___qtablewidgetitem7->setText(QApplication::translate("purchasestorage", "\345\215\225\344\273\267", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidgetPurInfo->horizontalHeaderItem(4);
        ___qtablewidgetitem8->setText(QApplication::translate("purchasestorage", "\346\225\260\351\207\217", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidgetPurInfo->horizontalHeaderItem(5);
        ___qtablewidgetitem9->setText(QApplication::translate("purchasestorage", "\345\267\262\346\224\266\350\264\247\346\225\260\351\207\217", 0));
        pushButtonPurMatInfo->setText(QApplication::translate("purchasestorage", " \346\267\273\345\212\240\345\205\245\345\272\223\345\216\237\346\226\231", 0));
        pushButtonReConfirm->setText(QApplication::translate("purchasestorage", " \345\217\215\347\241\256\350\256\244", 0));
        pushButtonRefuse->setText(QApplication::translate("purchasestorage", " \346\213\222\347\273\235\346\224\266\350\264\247", 0));
        pushButtonStart->setText(QApplication::translate("purchasestorage", " \345\274\200\345\247\213\351\252\214\346\224\266", 0));
        pushButtonFinish->setText(QApplication::translate("purchasestorage", " \345\205\245\345\272\223\345\256\214\346\210\220", 0));
        pushButtonStartCarry->setText(QApplication::translate("purchasestorage", " \347\273\247\347\273\255\351\252\214\346\224\266", 0));
        pushButtonSaveInfo->setText(QApplication::translate("purchasestorage", " \344\277\235\345\255\230", 0));
        pushButtonDel->setText(QApplication::translate("purchasestorage", " \345\210\240\351\231\244", 0));
        pushButtonCancelInfo->setText(QApplication::translate("purchasestorage", " \345\217\226\346\266\210", 0));
        tabWidgetPurchase->setTabText(tabWidgetPurchase->indexOf(tabPurInfo), QApplication::translate("purchasestorage", "\345\205\245\345\272\223\345\215\225\350\257\246\346\203\205", 0));
    } // retranslateUi

};

namespace Ui {
    class purchasestorage: public Ui_purchasestorage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PURCHASESTORAGE_H
