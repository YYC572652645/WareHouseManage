/********************************************************************************
** Form generated from reading UI file 'purreturngood.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PURRETURNGOOD_H
#define UI_PURRETURNGOOD_H

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

class Ui_PurReturnGood
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QWidget *widgetControl;
    QPushButton *pushButtonAdd;
    QLabel *labelState;
    QLabel *labelSup;
    QComboBox *comboBoxStateSelect;
    QComboBox *comboBoxSupSelect;
    QLabel *labelReturnDate;
    QDateEdit *dateEditSelect;
    QPushButton *pushButtonSelect;
    QLabel *labelSize;
    QPushButton *pushButtonExtend;
    QTableWidget *tableWidgetReturn;
    QTabWidget *tabWidgetReturns;
    QWidget *tabAddRet;
    QVBoxLayout *verticalLayout_3;
    QCommandLinkButton *commandLinkButtonImport;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QComboBox *comboBoxSupplier;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QDateEdit *dateEditArriveTime;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_6;
    QTimeEdit *timeEditReturn;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QComboBox *comboBoxRetWarHse;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLineEdit *lineEditRemark;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_8;
    QPushButton *pushButtonAddRetMat;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonCancel;
    QWidget *tabRetInfo;
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
    QComboBox *comboBoxSupplierInfo;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_16;
    QComboBox *comboBoxRetWarHseInfo;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_15;
    QDateEdit *dateEditArriveTimeInfo;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_21;
    QTimeEdit *timeEditReturnInfo;
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
    QTableWidget *tableWidgetRetInfo;
    QPushButton *pushButtonRetMatInfo;
    QPushButton *pushButtonStartSureInfo;
    QHBoxLayout *horizontalLayout_17;
    QPushButton *pushButtonSaveInfo;
    QPushButton *pushButtonDeleteInfo;
    QPushButton *pushButtonCancelInfo;

    void setupUi(QWidget *PurReturnGood)
    {
        if (PurReturnGood->objectName().isEmpty())
            PurReturnGood->setObjectName(QStringLiteral("PurReturnGood"));
        PurReturnGood->resize(402, 500);
        PurReturnGood->setStyleSheet(QLatin1String("QComboBox \n"
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
"height: 30px;\n"
"font-size:12px;\n"
"width: 100px;\n"
"border-radius:2px;\n"
"spacing:2px;\n"
"padding: 0px 0px;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(PurReturnGood);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 0, -1, -1);
        widgetControl = new QWidget(PurReturnGood);
        widgetControl->setObjectName(QStringLiteral("widgetControl"));
        widgetControl->setMinimumSize(QSize(0, 20));
        pushButtonAdd = new QPushButton(widgetControl);
        pushButtonAdd->setObjectName(QStringLiteral("pushButtonAdd"));
        pushButtonAdd->setGeometry(QRect(440, 17, 49, 30));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/image/addfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonAdd->setIcon(icon);
        labelState = new QLabel(widgetControl);
        labelState->setObjectName(QStringLiteral("labelState"));
        labelState->setGeometry(QRect(11, 20, 42, 16));
        labelSup = new QLabel(widgetControl);
        labelSup->setObjectName(QStringLiteral("labelSup"));
        labelSup->setGeometry(QRect(113, 11, 49, 42));
        comboBoxStateSelect = new QComboBox(widgetControl);
        comboBoxStateSelect->setObjectName(QStringLiteral("comboBoxStateSelect"));
        comboBoxStateSelect->setGeometry(QRect(59, 17, 48, 30));
        comboBoxSupSelect = new QComboBox(widgetControl);
        comboBoxSupSelect->setObjectName(QStringLiteral("comboBoxSupSelect"));
        comboBoxSupSelect->setGeometry(QRect(168, 17, 48, 30));
        labelReturnDate = new QLabel(widgetControl);
        labelReturnDate->setObjectName(QStringLiteral("labelReturnDate"));
        labelReturnDate->setGeometry(QRect(222, 11, 49, 42));
        dateEditSelect = new QDateEdit(widgetControl);
        dateEditSelect->setObjectName(QStringLiteral("dateEditSelect"));
        dateEditSelect->setGeometry(QRect(277, 17, 48, 30));
        pushButtonSelect = new QPushButton(widgetControl);
        pushButtonSelect->setObjectName(QStringLiteral("pushButtonSelect"));
        pushButtonSelect->setGeometry(QRect(331, 17, 49, 30));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/image/\346\237\245\350\257\242.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSelect->setIcon(icon1);
        labelSize = new QLabel(widgetControl);
        labelSize->setObjectName(QStringLiteral("labelSize"));
        labelSize->setGeometry(QRect(495, 11, 16, 18));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        labelSize->setFont(font);
        pushButtonExtend = new QPushButton(widgetControl);
        pushButtonExtend->setObjectName(QStringLiteral("pushButtonExtend"));
        pushButtonExtend->setGeometry(QRect(386, 17, 48, 30));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/image/export.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonExtend->setIcon(icon2);

        verticalLayout->addWidget(widgetControl);

        tableWidgetReturn = new QTableWidget(PurReturnGood);
        if (tableWidgetReturn->columnCount() < 4)
            tableWidgetReturn->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetReturn->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetReturn->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetReturn->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetReturn->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidgetReturn->setObjectName(QStringLiteral("tableWidgetReturn"));

        verticalLayout->addWidget(tableWidgetReturn);


        horizontalLayout_2->addLayout(verticalLayout);

        tabWidgetReturns = new QTabWidget(PurReturnGood);
        tabWidgetReturns->setObjectName(QStringLiteral("tabWidgetReturns"));
        tabAddRet = new QWidget();
        tabAddRet->setObjectName(QStringLiteral("tabAddRet"));
        verticalLayout_3 = new QVBoxLayout(tabAddRet);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(2, 0, 2, 0);
        commandLinkButtonImport = new QCommandLinkButton(tabAddRet);
        commandLinkButtonImport->setObjectName(QStringLiteral("commandLinkButtonImport"));

        verticalLayout_3->addWidget(commandLinkButtonImport);

        label_7 = new QLabel(tabAddRet);
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

        horizontalSpacer_7 = new QSpacerItem(40, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(tabAddRet);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);

        horizontalLayout_3->addWidget(label);

        comboBoxSupplier = new QComboBox(tabAddRet);
        comboBoxSupplier->setObjectName(QStringLiteral("comboBoxSupplier"));
        comboBoxSupplier->setMinimumSize(QSize(200, 30));
        comboBoxSupplier->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_3->addWidget(comboBoxSupplier);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalSpacer_3 = new QSpacerItem(40, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(tabAddRet);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        horizontalLayout_4->addWidget(label_2);

        dateEditArriveTime = new QDateEdit(tabAddRet);
        dateEditArriveTime->setObjectName(QStringLiteral("dateEditArriveTime"));
        dateEditArriveTime->setMinimumSize(QSize(200, 30));
        dateEditArriveTime->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_4->addWidget(dateEditArriveTime);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalSpacer_4 = new QSpacerItem(40, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_4);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_6 = new QLabel(tabAddRet);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);

        horizontalLayout_9->addWidget(label_6);

        timeEditReturn = new QTimeEdit(tabAddRet);
        timeEditReturn->setObjectName(QStringLiteral("timeEditReturn"));
        timeEditReturn->setMinimumSize(QSize(200, 30));
        timeEditReturn->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_9->addWidget(timeEditReturn);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalSpacer = new QSpacerItem(40, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_3 = new QLabel(tabAddRet);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        horizontalLayout_5->addWidget(label_3);

        comboBoxRetWarHse = new QComboBox(tabAddRet);
        comboBoxRetWarHse->setObjectName(QStringLiteral("comboBoxRetWarHse"));
        comboBoxRetWarHse->setMinimumSize(QSize(200, 30));
        comboBoxRetWarHse->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_5->addWidget(comboBoxRetWarHse);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalSpacer_5 = new QSpacerItem(40, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_4 = new QLabel(tabAddRet);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        horizontalLayout_6->addWidget(label_4);

        lineEditRemark = new QLineEdit(tabAddRet);
        lineEditRemark->setObjectName(QStringLiteral("lineEditRemark"));
        lineEditRemark->setMinimumSize(QSize(200, 30));
        lineEditRemark->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_6->addWidget(lineEditRemark);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalSpacer_6 = new QSpacerItem(40, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_6);

        label_8 = new QLabel(tabAddRet);
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

        pushButtonAddRetMat = new QPushButton(tabAddRet);
        pushButtonAddRetMat->setObjectName(QStringLiteral("pushButtonAddRetMat"));
        pushButtonAddRetMat->setMinimumSize(QSize(0, 60));
        pushButtonAddRetMat->setIcon(icon);

        verticalLayout_3->addWidget(pushButtonAddRetMat);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        pushButtonSave = new QPushButton(tabAddRet);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSave->setIcon(icon3);

        horizontalLayout_7->addWidget(pushButtonSave);

        pushButtonCancel = new QPushButton(tabAddRet);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/image/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon4);

        horizontalLayout_7->addWidget(pushButtonCancel);


        verticalLayout_3->addLayout(horizontalLayout_7);

        tabWidgetReturns->addTab(tabAddRet, QString());
        tabRetInfo = new QWidget();
        tabRetInfo->setObjectName(QStringLiteral("tabRetInfo"));
        verticalLayout_5 = new QVBoxLayout(tabRetInfo);
        verticalLayout_5->setSpacing(2);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(2, 0, 2, 0);
        label_18 = new QLabel(tabRetInfo);
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
        label_19 = new QLabel(tabRetInfo);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setFont(font1);

        horizontalLayout_15->addWidget(label_19);

        lineEditNumberInfo = new QLineEdit(tabRetInfo);
        lineEditNumberInfo->setObjectName(QStringLiteral("lineEditNumberInfo"));
        lineEditNumberInfo->setEnabled(false);
        lineEditNumberInfo->setMinimumSize(QSize(200, 0));
        lineEditNumberInfo->setMaximumSize(QSize(200, 16777215));
        lineEditNumberInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_15->addWidget(lineEditNumberInfo);


        verticalLayout_5->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_20 = new QLabel(tabRetInfo);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setFont(font1);

        horizontalLayout_16->addWidget(label_20);

        lineEditStateInfo = new QLineEdit(tabRetInfo);
        lineEditStateInfo->setObjectName(QStringLiteral("lineEditStateInfo"));
        lineEditStateInfo->setEnabled(false);
        lineEditStateInfo->setMinimumSize(QSize(200, 0));
        lineEditStateInfo->setMaximumSize(QSize(200, 16777215));
        lineEditStateInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_16->addWidget(lineEditStateInfo);


        verticalLayout_5->addLayout(horizontalLayout_16);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_13 = new QLabel(tabRetInfo);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font1);

        horizontalLayout_11->addWidget(label_13);

        comboBoxSupplierInfo = new QComboBox(tabRetInfo);
        comboBoxSupplierInfo->setObjectName(QStringLiteral("comboBoxSupplierInfo"));
        comboBoxSupplierInfo->setMinimumSize(QSize(200, 0));
        comboBoxSupplierInfo->setMaximumSize(QSize(200, 16777215));
        comboBoxSupplierInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_11->addWidget(comboBoxSupplierInfo);


        verticalLayout_5->addLayout(horizontalLayout_11);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_16 = new QLabel(tabRetInfo);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font1);

        horizontalLayout_13->addWidget(label_16);

        comboBoxRetWarHseInfo = new QComboBox(tabRetInfo);
        comboBoxRetWarHseInfo->setObjectName(QStringLiteral("comboBoxRetWarHseInfo"));
        comboBoxRetWarHseInfo->setMinimumSize(QSize(200, 0));
        comboBoxRetWarHseInfo->setMaximumSize(QSize(200, 16777215));
        comboBoxRetWarHseInfo->setAcceptDrops(false);
        comboBoxRetWarHseInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_13->addWidget(comboBoxRetWarHseInfo);


        verticalLayout_5->addLayout(horizontalLayout_13);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_15 = new QLabel(tabRetInfo);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font1);

        horizontalLayout_12->addWidget(label_15);

        dateEditArriveTimeInfo = new QDateEdit(tabRetInfo);
        dateEditArriveTimeInfo->setObjectName(QStringLiteral("dateEditArriveTimeInfo"));
        dateEditArriveTimeInfo->setMinimumSize(QSize(200, 0));
        dateEditArriveTimeInfo->setMaximumSize(QSize(200, 16777215));
        dateEditArriveTimeInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_12->addWidget(dateEditArriveTimeInfo);


        verticalLayout_5->addLayout(horizontalLayout_12);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        label_21 = new QLabel(tabRetInfo);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setFont(font1);

        horizontalLayout_18->addWidget(label_21);

        timeEditReturnInfo = new QTimeEdit(tabRetInfo);
        timeEditReturnInfo->setObjectName(QStringLiteral("timeEditReturnInfo"));
        timeEditReturnInfo->setMinimumSize(QSize(200, 0));
        timeEditReturnInfo->setMaximumSize(QSize(200, 16777215));
        timeEditReturnInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_18->addWidget(timeEditReturnInfo);


        verticalLayout_5->addLayout(horizontalLayout_18);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_17 = new QLabel(tabRetInfo);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setFont(font1);

        horizontalLayout_14->addWidget(label_17);

        lineEditRemarkInfo = new QLineEdit(tabRetInfo);
        lineEditRemarkInfo->setObjectName(QStringLiteral("lineEditRemarkInfo"));
        lineEditRemarkInfo->setMinimumSize(QSize(200, 0));
        lineEditRemarkInfo->setMaximumSize(QSize(200, 16777215));
        lineEditRemarkInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_14->addWidget(lineEditRemarkInfo);


        verticalLayout_5->addLayout(horizontalLayout_14);

        commandLinkButtonLog = new QCommandLinkButton(tabRetInfo);
        commandLinkButtonLog->setObjectName(QStringLiteral("commandLinkButtonLog"));

        verticalLayout_5->addWidget(commandLinkButtonLog);

        frame = new QFrame(tabRetInfo);
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
        commandLinkButtonEdit->setMinimumSize(QSize(200, 0));
        commandLinkButtonEdit->setMaximumSize(QSize(120, 16777215));
        commandLinkButtonEdit->setStyleSheet(QStringLiteral("background-color: transparent;"));

        horizontalLayout_8->addWidget(commandLinkButtonEdit);


        verticalLayout_8->addLayout(horizontalLayout_8);


        verticalLayout_5->addWidget(frame);

        tableWidgetRetInfo = new QTableWidget(tabRetInfo);
        if (tableWidgetRetInfo->columnCount() < 5)
            tableWidgetRetInfo->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetRetInfo->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidgetRetInfo->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidgetRetInfo->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidgetRetInfo->setHorizontalHeaderItem(3, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidgetRetInfo->setHorizontalHeaderItem(4, __qtablewidgetitem8);
        tableWidgetRetInfo->setObjectName(QStringLiteral("tableWidgetRetInfo"));

        verticalLayout_5->addWidget(tableWidgetRetInfo);

        pushButtonRetMatInfo = new QPushButton(tabRetInfo);
        pushButtonRetMatInfo->setObjectName(QStringLiteral("pushButtonRetMatInfo"));
        pushButtonRetMatInfo->setMinimumSize(QSize(0, 0));
        pushButtonRetMatInfo->setIcon(icon);

        verticalLayout_5->addWidget(pushButtonRetMatInfo);

        pushButtonStartSureInfo = new QPushButton(tabRetInfo);
        pushButtonStartSureInfo->setObjectName(QStringLiteral("pushButtonStartSureInfo"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/image/image/\347\241\256\350\256\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonStartSureInfo->setIcon(icon5);

        verticalLayout_5->addWidget(pushButtonStartSureInfo);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        pushButtonSaveInfo = new QPushButton(tabRetInfo);
        pushButtonSaveInfo->setObjectName(QStringLiteral("pushButtonSaveInfo"));
        pushButtonSaveInfo->setIcon(icon3);

        horizontalLayout_17->addWidget(pushButtonSaveInfo);

        pushButtonDeleteInfo = new QPushButton(tabRetInfo);
        pushButtonDeleteInfo->setObjectName(QStringLiteral("pushButtonDeleteInfo"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/image/image/\345\210\240 \351\231\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonDeleteInfo->setIcon(icon6);

        horizontalLayout_17->addWidget(pushButtonDeleteInfo);

        pushButtonCancelInfo = new QPushButton(tabRetInfo);
        pushButtonCancelInfo->setObjectName(QStringLiteral("pushButtonCancelInfo"));
        pushButtonCancelInfo->setIcon(icon4);

        horizontalLayout_17->addWidget(pushButtonCancelInfo);


        verticalLayout_5->addLayout(horizontalLayout_17);

        tabWidgetReturns->addTab(tabRetInfo, QString());

        horizontalLayout_2->addWidget(tabWidgetReturns);

        horizontalLayout_2->setStretch(0, 6);
        horizontalLayout_2->setStretch(1, 4);

        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(PurReturnGood);

        tabWidgetReturns->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(PurReturnGood);
    } // setupUi

    void retranslateUi(QWidget *PurReturnGood)
    {
        PurReturnGood->setWindowTitle(QApplication::translate("PurReturnGood", "Form", 0));
        pushButtonAdd->setText(QApplication::translate("PurReturnGood", "\346\267\273\345\212\240", 0));
        labelState->setText(QApplication::translate("PurReturnGood", " \347\212\266\346\200\201\357\274\232", 0));
        labelSup->setText(QApplication::translate("PurReturnGood", " \344\276\233\345\272\224\345\225\206\357\274\232", 0));
        labelReturnDate->setText(QApplication::translate("PurReturnGood", " \351\200\200\350\264\247\346\227\245\346\234\237\357\274\232", 0));
        pushButtonSelect->setText(QApplication::translate("PurReturnGood", "\346\237\245\350\257\242", 0));
        labelSize->setText(QString());
        pushButtonExtend->setText(QApplication::translate("PurReturnGood", "\345\257\274\345\207\272", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetReturn->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("PurReturnGood", "\344\276\233\345\272\224\345\225\206", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetReturn->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("PurReturnGood", "\351\200\200\350\264\247\345\215\225\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetReturn->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("PurReturnGood", "\351\200\200\350\264\247\346\227\245\346\234\237", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetReturn->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("PurReturnGood", "\347\212\266\346\200\201", 0));
        commandLinkButtonImport->setText(QApplication::translate("PurReturnGood", "\344\273\216\345\216\206\345\217\262\351\200\200\350\264\247\350\256\242\345\215\225\345\257\274\345\205\245", 0));
        label_7->setText(QApplication::translate("PurReturnGood", " \345\237\272\346\234\254\344\277\241\346\201\257", 0));
        label->setText(QApplication::translate("PurReturnGood", "\344\276\233\345\272\224\345\225\206\357\274\232", 0));
        label_2->setText(QApplication::translate("PurReturnGood", "\351\200\200\350\264\247\346\227\245\346\234\237\357\274\232", 0));
        label_6->setText(QApplication::translate("PurReturnGood", "\351\200\200\350\264\247\346\227\266\351\227\264\357\274\232", 0));
        label_3->setText(QApplication::translate("PurReturnGood", "\351\207\207\350\264\255\344\273\223\345\272\223\357\274\232", 0));
#ifndef QT_NO_TOOLTIP
        comboBoxRetWarHse->setToolTip(QApplication::translate("PurReturnGood", "\345\217\257\344\270\215\345\241\253", 0));
#endif // QT_NO_TOOLTIP
        comboBoxRetWarHse->setCurrentText(QString());
        label_4->setText(QApplication::translate("PurReturnGood", "\345\244\207\346\263\250\357\274\232", 0));
        lineEditRemark->setPlaceholderText(QApplication::translate("PurReturnGood", "\345\217\257\344\270\215\345\241\253", 0));
        label_8->setText(QApplication::translate("PurReturnGood", " \351\200\200\350\264\247\345\216\237\346\226\231", 0));
        pushButtonAddRetMat->setText(QApplication::translate("PurReturnGood", " \346\267\273\345\212\240\351\200\200\350\264\247\345\216\237\346\226\231...", 0));
        pushButtonSave->setText(QApplication::translate("PurReturnGood", "  \344\277\235\345\255\230", 0));
        pushButtonCancel->setText(QApplication::translate("PurReturnGood", " \345\217\226\346\266\210", 0));
        tabWidgetReturns->setTabText(tabWidgetReturns->indexOf(tabAddRet), QApplication::translate("PurReturnGood", "\346\267\273\345\212\240\351\200\200\350\264\247\345\215\225", 0));
        label_18->setText(QApplication::translate("PurReturnGood", " \345\237\272\346\234\254\344\277\241\346\201\257", 0));
        label_19->setText(QApplication::translate("PurReturnGood", "\351\200\200\350\264\247\345\215\225\345\217\267\357\274\232", 0));
        label_20->setText(QApplication::translate("PurReturnGood", "\347\212\266\346\200\201\357\274\232", 0));
        label_13->setText(QApplication::translate("PurReturnGood", "\344\276\233\345\272\224\345\225\206\357\274\232", 0));
        label_16->setText(QApplication::translate("PurReturnGood", "\351\200\200\350\264\247\344\273\223\345\272\223\357\274\232", 0));
#ifndef QT_NO_TOOLTIP
        comboBoxRetWarHseInfo->setToolTip(QApplication::translate("PurReturnGood", "\345\217\257\344\270\215\345\241\253", 0));
#endif // QT_NO_TOOLTIP
        comboBoxRetWarHseInfo->setCurrentText(QString());
        label_15->setText(QApplication::translate("PurReturnGood", "\351\200\200\350\264\247\346\227\245\346\234\237\357\274\232", 0));
        label_21->setText(QApplication::translate("PurReturnGood", "\351\200\200\350\264\247\346\227\266\351\227\264\357\274\232", 0));
        label_17->setText(QApplication::translate("PurReturnGood", "\345\244\207\346\263\250\357\274\232", 0));
        lineEditRemarkInfo->setPlaceholderText(QApplication::translate("PurReturnGood", "\345\217\257\344\270\215\345\241\253", 0));
        commandLinkButtonLog->setText(QApplication::translate("PurReturnGood", " \345\244\204\347\220\206\350\256\260\345\275\225", 0));
        label_5->setText(QApplication::translate("PurReturnGood", " \351\200\200\350\264\247\345\216\237\346\226\231", 0));
        labelTotalCount->setText(QString());
        commandLinkButtonEdit->setText(QApplication::translate("PurReturnGood", " \347\274\226\350\276\221\351\200\200\350\264\247\345\216\237\346\226\231", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetRetInfo->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("PurReturnGood", "\345\216\237\346\226\231\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetRetInfo->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("PurReturnGood", "\346\235\241\345\275\242\347\240\201", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetRetInfo->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("PurReturnGood", "\345\215\225\344\275\215", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidgetRetInfo->horizontalHeaderItem(3);
        ___qtablewidgetitem7->setText(QApplication::translate("PurReturnGood", "\345\215\225\344\273\267", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidgetRetInfo->horizontalHeaderItem(4);
        ___qtablewidgetitem8->setText(QApplication::translate("PurReturnGood", "\346\225\260\351\207\217", 0));
        pushButtonRetMatInfo->setText(QApplication::translate("PurReturnGood", " \346\267\273\345\212\240\351\200\200\350\264\247\345\216\237\346\226\231", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonStartSureInfo->setToolTip(QApplication::translate("PurReturnGood", "\345\274\200\345\247\213\347\241\256\350\256\244\351\207\207\350\264\255\345\216\237\346\226\231", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        pushButtonStartSureInfo->setWhatsThis(QApplication::translate("PurReturnGood", "\345\274\200\345\247\213\347\241\256\350\256\244\351\207\207\350\264\255\345\216\237\346\226\231", 0));
#endif // QT_NO_WHATSTHIS
        pushButtonStartSureInfo->setText(QApplication::translate("PurReturnGood", " \347\241\256\350\256\244\351\200\200\350\264\247", 0));
        pushButtonSaveInfo->setText(QApplication::translate("PurReturnGood", " \344\277\235\345\255\230", 0));
        pushButtonDeleteInfo->setText(QApplication::translate("PurReturnGood", " \345\210\240\351\231\244", 0));
        pushButtonCancelInfo->setText(QApplication::translate("PurReturnGood", " \345\217\226\346\266\210", 0));
        tabWidgetReturns->setTabText(tabWidgetReturns->indexOf(tabRetInfo), QApplication::translate("PurReturnGood", "\351\200\200\350\264\247\345\215\225\350\257\246\346\203\205", 0));
    } // retranslateUi

};

namespace Ui {
    class PurReturnGood: public Ui_PurReturnGood {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PURRETURNGOOD_H
