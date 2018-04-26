/********************************************************************************
** Form generated from reading UI file 'inventoryadjust.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVENTORYADJUST_H
#define UI_INVENTORYADJUST_H

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

class Ui_InventoryAdjust
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QWidget *widgetControl;
    QLabel *labelWshe;
    QLabel *labelState;
    QComboBox *comboBoxStateSelect;
    QLabel *labelType;
    QComboBox *comboBoxWarHseSelect;
    QLabel *labelDate;
    QDateEdit *dateEditSelect;
    QComboBox *comboBoxTypeSelect;
    QPushButton *pushButtonSelect;
    QPushButton *pushButtonExtend;
    QPushButton *pushButtonAdd;
    QLabel *labelSize;
    QTableWidget *tableWidgetAdjust;
    QTabWidget *tabWidgetAdjust;
    QWidget *tabAddAdjust;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QComboBox *comboBoxWarHse;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QComboBox *comboBoxAdjustType;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QDateEdit *dateEditAdjustTime;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_6;
    QTimeEdit *timeEditAdjust;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLineEdit *lineEditRemark;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_8;
    QPushButton *pushButtonAddAdjustMat;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonCancel;
    QWidget *tabAdjustInfo;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_18;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_19;
    QLineEdit *lineEditNumberInfo;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_16;
    QComboBox *comboBoxWarHseInfo;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_13;
    QComboBox *comboBoxAdjustTypeInfo;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_15;
    QDateEdit *dateEditAdjustTimeInfo;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_21;
    QTimeEdit *timeEditTimeInfo;
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
    QComboBox *comboBoxType;
    QCommandLinkButton *commandLinkButtonEdit;
    QTableWidget *tableWidgetAdjustInfo;
    QPushButton *pushButtonAdjMatInfo;
    QPushButton *pushButtonSubmit;
    QHBoxLayout *horizontalLayout_17;
    QPushButton *pushButtonSaveInfo;
    QPushButton *pushButtonDeleteInfo;
    QPushButton *pushButtonCancelInfo;

    void setupUi(QWidget *InventoryAdjust)
    {
        if (InventoryAdjust->objectName().isEmpty())
            InventoryAdjust->setObjectName(QStringLiteral("InventoryAdjust"));
        InventoryAdjust->resize(437, 420);
        InventoryAdjust->setStyleSheet(QLatin1String("QComboBox \n"
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
        verticalLayout_2 = new QVBoxLayout(InventoryAdjust);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widgetControl = new QWidget(InventoryAdjust);
        widgetControl->setObjectName(QStringLiteral("widgetControl"));
        widgetControl->setMinimumSize(QSize(0, 20));
        labelWshe = new QLabel(widgetControl);
        labelWshe->setObjectName(QStringLiteral("labelWshe"));
        labelWshe->setGeometry(QRect(42, 1, 16, 42));
        labelState = new QLabel(widgetControl);
        labelState->setObjectName(QStringLiteral("labelState"));
        labelState->setGeometry(QRect(1, 1, 16, 42));
        comboBoxStateSelect = new QComboBox(widgetControl);
        comboBoxStateSelect->setObjectName(QStringLiteral("comboBoxStateSelect"));
        comboBoxStateSelect->setGeometry(QRect(22, 11, 16, 22));
        comboBoxStateSelect->setMinimumSize(QSize(0, 0));
        labelType = new QLabel(widgetControl);
        labelType->setObjectName(QStringLiteral("labelType"));
        labelType->setGeometry(QRect(83, 1, 16, 42));
        comboBoxWarHseSelect = new QComboBox(widgetControl);
        comboBoxWarHseSelect->setObjectName(QStringLiteral("comboBoxWarHseSelect"));
        comboBoxWarHseSelect->setGeometry(QRect(63, 11, 16, 22));
        comboBoxWarHseSelect->setMinimumSize(QSize(0, 0));
        labelDate = new QLabel(widgetControl);
        labelDate->setObjectName(QStringLiteral("labelDate"));
        labelDate->setGeometry(QRect(124, 1, 16, 42));
        dateEditSelect = new QDateEdit(widgetControl);
        dateEditSelect->setObjectName(QStringLiteral("dateEditSelect"));
        dateEditSelect->setGeometry(QRect(144, 11, 16, 22));
        dateEditSelect->setMinimumSize(QSize(0, 0));
        comboBoxTypeSelect = new QComboBox(widgetControl);
        comboBoxTypeSelect->setObjectName(QStringLiteral("comboBoxTypeSelect"));
        comboBoxTypeSelect->setGeometry(QRect(103, 11, 16, 22));
        comboBoxTypeSelect->setMinimumSize(QSize(0, 0));
        pushButtonSelect = new QPushButton(widgetControl);
        pushButtonSelect->setObjectName(QStringLiteral("pushButtonSelect"));
        pushButtonSelect->setGeometry(QRect(164, 14, 16, 16));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\346\237\245\350\257\242.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSelect->setIcon(icon);
        pushButtonExtend = new QPushButton(widgetControl);
        pushButtonExtend->setObjectName(QStringLiteral("pushButtonExtend"));
        pushButtonExtend->setGeometry(QRect(185, 14, 16, 16));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/export.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonExtend->setIcon(icon1);
        pushButtonAdd = new QPushButton(widgetControl);
        pushButtonAdd->setObjectName(QStringLiteral("pushButtonAdd"));
        pushButtonAdd->setGeometry(QRect(205, 14, 16, 16));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/image/addfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonAdd->setIcon(icon2);
        labelSize = new QLabel(widgetControl);
        labelSize->setObjectName(QStringLiteral("labelSize"));
        labelSize->setGeometry(QRect(225, 1, 16, 18));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        labelSize->setFont(font);

        verticalLayout->addWidget(widgetControl);

        tableWidgetAdjust = new QTableWidget(InventoryAdjust);
        if (tableWidgetAdjust->columnCount() < 4)
            tableWidgetAdjust->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetAdjust->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetAdjust->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetAdjust->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetAdjust->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidgetAdjust->setObjectName(QStringLiteral("tableWidgetAdjust"));

        verticalLayout->addWidget(tableWidgetAdjust);


        horizontalLayout_2->addLayout(verticalLayout);

        tabWidgetAdjust = new QTabWidget(InventoryAdjust);
        tabWidgetAdjust->setObjectName(QStringLiteral("tabWidgetAdjust"));
        tabAddAdjust = new QWidget();
        tabAddAdjust->setObjectName(QStringLiteral("tabAddAdjust"));
        verticalLayout_3 = new QVBoxLayout(tabAddAdjust);
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(2, 0, 2, 0);
        label_7 = new QLabel(tabAddAdjust);
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
        label_3 = new QLabel(tabAddAdjust);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);

        horizontalLayout_5->addWidget(label_3);

        comboBoxWarHse = new QComboBox(tabAddAdjust);
        comboBoxWarHse->setObjectName(QStringLiteral("comboBoxWarHse"));
        comboBoxWarHse->setMinimumSize(QSize(200, 0));
        comboBoxWarHse->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_5->addWidget(comboBoxWarHse);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(tabAddAdjust);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);

        horizontalLayout_3->addWidget(label);

        comboBoxAdjustType = new QComboBox(tabAddAdjust);
        comboBoxAdjustType->setObjectName(QStringLiteral("comboBoxAdjustType"));
        comboBoxAdjustType->setMinimumSize(QSize(200, 0));
        comboBoxAdjustType->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_3->addWidget(comboBoxAdjustType);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalSpacer_3 = new QSpacerItem(40, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(tabAddAdjust);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        horizontalLayout_4->addWidget(label_2);

        dateEditAdjustTime = new QDateEdit(tabAddAdjust);
        dateEditAdjustTime->setObjectName(QStringLiteral("dateEditAdjustTime"));
        dateEditAdjustTime->setMinimumSize(QSize(200, 0));
        dateEditAdjustTime->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_4->addWidget(dateEditAdjustTime);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalSpacer_4 = new QSpacerItem(40, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_4);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_6 = new QLabel(tabAddAdjust);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);

        horizontalLayout_9->addWidget(label_6);

        timeEditAdjust = new QTimeEdit(tabAddAdjust);
        timeEditAdjust->setObjectName(QStringLiteral("timeEditAdjust"));
        timeEditAdjust->setMinimumSize(QSize(200, 0));
        timeEditAdjust->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_9->addWidget(timeEditAdjust);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalSpacer_5 = new QSpacerItem(40, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_4 = new QLabel(tabAddAdjust);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        horizontalLayout_6->addWidget(label_4);

        lineEditRemark = new QLineEdit(tabAddAdjust);
        lineEditRemark->setObjectName(QStringLiteral("lineEditRemark"));
        lineEditRemark->setMinimumSize(QSize(200, 0));
        lineEditRemark->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_6->addWidget(lineEditRemark);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalSpacer_6 = new QSpacerItem(40, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_6);

        label_8 = new QLabel(tabAddAdjust);
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

        pushButtonAddAdjustMat = new QPushButton(tabAddAdjust);
        pushButtonAddAdjustMat->setObjectName(QStringLiteral("pushButtonAddAdjustMat"));
        pushButtonAddAdjustMat->setMinimumSize(QSize(0, 60));
        pushButtonAddAdjustMat->setIcon(icon2);

        verticalLayout_3->addWidget(pushButtonAddAdjustMat);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        pushButtonSave = new QPushButton(tabAddAdjust);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSave->setIcon(icon3);

        horizontalLayout_7->addWidget(pushButtonSave);

        pushButtonCancel = new QPushButton(tabAddAdjust);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/image/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon4);

        horizontalLayout_7->addWidget(pushButtonCancel);


        verticalLayout_3->addLayout(horizontalLayout_7);

        tabWidgetAdjust->addTab(tabAddAdjust, QString());
        tabAdjustInfo = new QWidget();
        tabAdjustInfo->setObjectName(QStringLiteral("tabAdjustInfo"));
        verticalLayout_5 = new QVBoxLayout(tabAdjustInfo);
        verticalLayout_5->setSpacing(2);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(2, 0, 2, 0);
        label_18 = new QLabel(tabAdjustInfo);
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
        label_19 = new QLabel(tabAdjustInfo);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setFont(font1);

        horizontalLayout_15->addWidget(label_19);

        lineEditNumberInfo = new QLineEdit(tabAdjustInfo);
        lineEditNumberInfo->setObjectName(QStringLiteral("lineEditNumberInfo"));
        lineEditNumberInfo->setEnabled(false);
        lineEditNumberInfo->setMinimumSize(QSize(200, 0));
        lineEditNumberInfo->setMaximumSize(QSize(200, 16777215));
        lineEditNumberInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_15->addWidget(lineEditNumberInfo);


        verticalLayout_5->addLayout(horizontalLayout_15);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_16 = new QLabel(tabAdjustInfo);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font1);

        horizontalLayout_13->addWidget(label_16);

        comboBoxWarHseInfo = new QComboBox(tabAdjustInfo);
        comboBoxWarHseInfo->setObjectName(QStringLiteral("comboBoxWarHseInfo"));
        comboBoxWarHseInfo->setMinimumSize(QSize(200, 0));
        comboBoxWarHseInfo->setMaximumSize(QSize(200, 16777215));
        comboBoxWarHseInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_13->addWidget(comboBoxWarHseInfo);


        verticalLayout_5->addLayout(horizontalLayout_13);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_13 = new QLabel(tabAdjustInfo);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font1);

        horizontalLayout_11->addWidget(label_13);

        comboBoxAdjustTypeInfo = new QComboBox(tabAdjustInfo);
        comboBoxAdjustTypeInfo->setObjectName(QStringLiteral("comboBoxAdjustTypeInfo"));
        comboBoxAdjustTypeInfo->setMinimumSize(QSize(200, 0));
        comboBoxAdjustTypeInfo->setMaximumSize(QSize(200, 16777215));
        comboBoxAdjustTypeInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_11->addWidget(comboBoxAdjustTypeInfo);


        verticalLayout_5->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_15 = new QLabel(tabAdjustInfo);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font1);

        horizontalLayout_12->addWidget(label_15);

        dateEditAdjustTimeInfo = new QDateEdit(tabAdjustInfo);
        dateEditAdjustTimeInfo->setObjectName(QStringLiteral("dateEditAdjustTimeInfo"));
        dateEditAdjustTimeInfo->setMinimumSize(QSize(200, 0));
        dateEditAdjustTimeInfo->setMaximumSize(QSize(200, 16777215));
        dateEditAdjustTimeInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_12->addWidget(dateEditAdjustTimeInfo);


        verticalLayout_5->addLayout(horizontalLayout_12);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        label_21 = new QLabel(tabAdjustInfo);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setFont(font1);

        horizontalLayout_18->addWidget(label_21);

        timeEditTimeInfo = new QTimeEdit(tabAdjustInfo);
        timeEditTimeInfo->setObjectName(QStringLiteral("timeEditTimeInfo"));
        timeEditTimeInfo->setMinimumSize(QSize(200, 0));
        timeEditTimeInfo->setMaximumSize(QSize(200, 16777215));
        timeEditTimeInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_18->addWidget(timeEditTimeInfo);


        verticalLayout_5->addLayout(horizontalLayout_18);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_17 = new QLabel(tabAdjustInfo);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setFont(font1);

        horizontalLayout_14->addWidget(label_17);

        lineEditRemarkInfo = new QLineEdit(tabAdjustInfo);
        lineEditRemarkInfo->setObjectName(QStringLiteral("lineEditRemarkInfo"));
        lineEditRemarkInfo->setMinimumSize(QSize(200, 0));
        lineEditRemarkInfo->setMaximumSize(QSize(200, 16777215));
        lineEditRemarkInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_14->addWidget(lineEditRemarkInfo);


        verticalLayout_5->addLayout(horizontalLayout_14);

        commandLinkButtonLog = new QCommandLinkButton(tabAdjustInfo);
        commandLinkButtonLog->setObjectName(QStringLiteral("commandLinkButtonLog"));

        verticalLayout_5->addWidget(commandLinkButtonLog);

        frame = new QFrame(tabAdjustInfo);
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

        comboBoxType = new QComboBox(frame);
        comboBoxType->setObjectName(QStringLiteral("comboBoxType"));
        comboBoxType->setMinimumSize(QSize(120, 40));
        comboBoxType->setMaximumSize(QSize(16777215, 40));
        comboBoxType->setLayoutDirection(Qt::LeftToRight);
        comboBoxType->setStyleSheet(QStringLiteral("background-color:transparent;"));

        horizontalLayout_8->addWidget(comboBoxType);

        commandLinkButtonEdit = new QCommandLinkButton(frame);
        commandLinkButtonEdit->setObjectName(QStringLiteral("commandLinkButtonEdit"));
        commandLinkButtonEdit->setMaximumSize(QSize(120, 16777215));
        commandLinkButtonEdit->setStyleSheet(QStringLiteral("background-color: transparent;"));

        horizontalLayout_8->addWidget(commandLinkButtonEdit);


        verticalLayout_8->addLayout(horizontalLayout_8);


        verticalLayout_5->addWidget(frame);

        tableWidgetAdjustInfo = new QTableWidget(tabAdjustInfo);
        if (tableWidgetAdjustInfo->columnCount() < 4)
            tableWidgetAdjustInfo->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetAdjustInfo->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidgetAdjustInfo->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidgetAdjustInfo->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidgetAdjustInfo->setHorizontalHeaderItem(3, __qtablewidgetitem7);
        tableWidgetAdjustInfo->setObjectName(QStringLiteral("tableWidgetAdjustInfo"));

        verticalLayout_5->addWidget(tableWidgetAdjustInfo);

        pushButtonAdjMatInfo = new QPushButton(tabAdjustInfo);
        pushButtonAdjMatInfo->setObjectName(QStringLiteral("pushButtonAdjMatInfo"));
        pushButtonAdjMatInfo->setMinimumSize(QSize(0, 0));
        pushButtonAdjMatInfo->setIcon(icon2);

        verticalLayout_5->addWidget(pushButtonAdjMatInfo);

        pushButtonSubmit = new QPushButton(tabAdjustInfo);
        pushButtonSubmit->setObjectName(QStringLiteral("pushButtonSubmit"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/image/image/\347\241\256\350\256\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSubmit->setIcon(icon5);

        verticalLayout_5->addWidget(pushButtonSubmit);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        pushButtonSaveInfo = new QPushButton(tabAdjustInfo);
        pushButtonSaveInfo->setObjectName(QStringLiteral("pushButtonSaveInfo"));
        pushButtonSaveInfo->setIcon(icon3);

        horizontalLayout_17->addWidget(pushButtonSaveInfo);

        pushButtonDeleteInfo = new QPushButton(tabAdjustInfo);
        pushButtonDeleteInfo->setObjectName(QStringLiteral("pushButtonDeleteInfo"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/image/image/\345\210\240 \351\231\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonDeleteInfo->setIcon(icon6);

        horizontalLayout_17->addWidget(pushButtonDeleteInfo);

        pushButtonCancelInfo = new QPushButton(tabAdjustInfo);
        pushButtonCancelInfo->setObjectName(QStringLiteral("pushButtonCancelInfo"));
        pushButtonCancelInfo->setIcon(icon4);

        horizontalLayout_17->addWidget(pushButtonCancelInfo);


        verticalLayout_5->addLayout(horizontalLayout_17);

        tabWidgetAdjust->addTab(tabAdjustInfo, QString());

        horizontalLayout_2->addWidget(tabWidgetAdjust);

        horizontalLayout_2->setStretch(0, 6);
        horizontalLayout_2->setStretch(1, 4);

        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(InventoryAdjust);

        tabWidgetAdjust->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(InventoryAdjust);
    } // setupUi

    void retranslateUi(QWidget *InventoryAdjust)
    {
        InventoryAdjust->setWindowTitle(QApplication::translate("InventoryAdjust", "Form", 0));
        labelWshe->setText(QApplication::translate("InventoryAdjust", "\344\273\223\345\272\223\357\274\232", 0));
        labelState->setText(QApplication::translate("InventoryAdjust", " \347\212\266\346\200\201\357\274\232", 0));
        labelType->setText(QApplication::translate("InventoryAdjust", " \347\261\273\345\236\213\357\274\232", 0));
        labelDate->setText(QApplication::translate("InventoryAdjust", " \350\260\203\346\225\264\346\227\245\346\234\237\357\274\232", 0));
        pushButtonSelect->setText(QApplication::translate("InventoryAdjust", "\346\237\245\350\257\242", 0));
        pushButtonExtend->setText(QApplication::translate("InventoryAdjust", "\345\257\274\345\207\272", 0));
        pushButtonAdd->setText(QApplication::translate("InventoryAdjust", "\346\267\273\345\212\240", 0));
        labelSize->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidgetAdjust->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("InventoryAdjust", "\344\273\223\345\272\223\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetAdjust->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("InventoryAdjust", "\350\260\203\346\225\264\345\215\225\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetAdjust->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("InventoryAdjust", "\350\260\203\346\225\264\346\227\245\346\234\237", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetAdjust->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("InventoryAdjust", "\347\212\266\346\200\201", 0));
        label_7->setText(QApplication::translate("InventoryAdjust", " \345\237\272\346\234\254\344\277\241\346\201\257", 0));
        label_3->setText(QApplication::translate("InventoryAdjust", "\344\273\223\345\272\223\357\274\232", 0));
#ifndef QT_NO_TOOLTIP
        comboBoxWarHse->setToolTip(QApplication::translate("InventoryAdjust", "\345\217\257\344\270\215\345\241\253", 0));
#endif // QT_NO_TOOLTIP
        comboBoxWarHse->setCurrentText(QString());
        label->setText(QApplication::translate("InventoryAdjust", "\350\260\203\346\225\264\345\215\225\347\261\273\345\236\213\357\274\232", 0));
        label_2->setText(QApplication::translate("InventoryAdjust", "\350\260\203\346\225\264\346\227\245\346\234\237\357\274\232", 0));
        label_6->setText(QApplication::translate("InventoryAdjust", "\350\260\203\346\225\264\346\227\266\351\227\264\357\274\232", 0));
        label_4->setText(QApplication::translate("InventoryAdjust", "\345\244\207\346\263\250\357\274\232", 0));
        lineEditRemark->setPlaceholderText(QApplication::translate("InventoryAdjust", "\345\217\257\344\270\215\345\241\253", 0));
        label_8->setText(QApplication::translate("InventoryAdjust", " \350\260\203\346\225\264\345\216\237\346\226\231", 0));
        pushButtonAddAdjustMat->setText(QApplication::translate("InventoryAdjust", " \346\267\273\345\212\240\350\260\203\346\225\264\345\216\237\346\226\231...", 0));
        pushButtonSave->setText(QApplication::translate("InventoryAdjust", "  \344\277\235\345\255\230", 0));
        pushButtonCancel->setText(QApplication::translate("InventoryAdjust", " \345\217\226\346\266\210", 0));
        tabWidgetAdjust->setTabText(tabWidgetAdjust->indexOf(tabAddAdjust), QApplication::translate("InventoryAdjust", "\346\267\273\345\212\240\350\260\203\346\225\264\345\215\225", 0));
        label_18->setText(QApplication::translate("InventoryAdjust", " \345\237\272\346\234\254\344\277\241\346\201\257", 0));
        label_19->setText(QApplication::translate("InventoryAdjust", "\350\260\203\346\225\264\345\215\225\345\217\267\357\274\232", 0));
        label_16->setText(QApplication::translate("InventoryAdjust", "\344\273\223\345\272\223\357\274\232", 0));
#ifndef QT_NO_TOOLTIP
        comboBoxWarHseInfo->setToolTip(QApplication::translate("InventoryAdjust", "\345\217\257\344\270\215\345\241\253", 0));
#endif // QT_NO_TOOLTIP
        comboBoxWarHseInfo->setCurrentText(QString());
        label_13->setText(QApplication::translate("InventoryAdjust", "\350\260\203\346\225\264\345\215\225\347\261\273\345\236\213\357\274\232", 0));
        label_15->setText(QApplication::translate("InventoryAdjust", "\350\260\203\346\225\264\346\227\245\346\234\237\357\274\232", 0));
        label_21->setText(QApplication::translate("InventoryAdjust", "\350\260\203\346\225\264\346\227\266\351\227\264\357\274\232", 0));
        label_17->setText(QApplication::translate("InventoryAdjust", "\345\244\207\346\263\250\357\274\232", 0));
        lineEditRemarkInfo->setPlaceholderText(QApplication::translate("InventoryAdjust", "\345\217\257\344\270\215\345\241\253", 0));
        commandLinkButtonLog->setText(QApplication::translate("InventoryAdjust", " \345\244\204\347\220\206\350\256\260\345\275\225", 0));
        label_5->setText(QApplication::translate("InventoryAdjust", " \350\260\203\346\225\264\345\216\237\346\226\231", 0));
        labelTotalCount->setText(QString());
        commandLinkButtonEdit->setText(QApplication::translate("InventoryAdjust", " \347\274\226\350\276\221\350\260\203\346\225\264\345\216\237\346\226\231", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetAdjustInfo->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("InventoryAdjust", "\345\216\237\346\226\231\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetAdjustInfo->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("InventoryAdjust", "\346\235\241\345\275\242\347\240\201", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetAdjustInfo->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("InventoryAdjust", "\345\215\225\344\273\267", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidgetAdjustInfo->horizontalHeaderItem(3);
        ___qtablewidgetitem7->setText(QApplication::translate("InventoryAdjust", "\345\215\225\344\275\215", 0));
        pushButtonAdjMatInfo->setText(QApplication::translate("InventoryAdjust", " \346\267\273\345\212\240\350\260\203\346\225\264\345\216\237\346\226\231", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonSubmit->setToolTip(QApplication::translate("InventoryAdjust", "\345\274\200\345\247\213\347\241\256\350\256\244\351\207\207\350\264\255\345\216\237\346\226\231", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        pushButtonSubmit->setWhatsThis(QApplication::translate("InventoryAdjust", "\345\274\200\345\247\213\347\241\256\350\256\244\351\207\207\350\264\255\345\216\237\346\226\231", 0));
#endif // QT_NO_WHATSTHIS
        pushButtonSubmit->setText(QApplication::translate("InventoryAdjust", " \346\217\220\344\272\244", 0));
        pushButtonSaveInfo->setText(QApplication::translate("InventoryAdjust", " \344\277\235\345\255\230", 0));
        pushButtonDeleteInfo->setText(QApplication::translate("InventoryAdjust", " \345\210\240\351\231\244", 0));
        pushButtonCancelInfo->setText(QApplication::translate("InventoryAdjust", " \345\217\226\346\266\210", 0));
        tabWidgetAdjust->setTabText(tabWidgetAdjust->indexOf(tabAdjustInfo), QApplication::translate("InventoryAdjust", "\350\260\203\346\225\264\345\215\225\350\257\246\346\203\205", 0));
    } // retranslateUi

};

namespace Ui {
    class InventoryAdjust: public Ui_InventoryAdjust {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVENTORYADJUST_H
