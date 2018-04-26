/********************************************************************************
** Form generated from reading UI file 'inventorytransfer.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVENTORYTRANSFER_H
#define UI_INVENTORYTRANSFER_H

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

class Ui_inventorytransfer
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_20;
    QWidget *widgetControl;
    QLabel *labelState;
    QComboBox *comboBoxStateSelect;
    QComboBox *comboBoxWarHseOutSelect;
    QLabel *labelOutWhse;
    QLabel *labelInWhse;
    QComboBox *comboBoxWarHseInSelect;
    QDateEdit *dateEditSelect;
    QPushButton *pushButtonSelect;
    QLabel *labelDate;
    QPushButton *pushButtonExtend;
    QPushButton *pushButtonAdd;
    QLabel *labelSize;
    QTableWidget *tableWidgetAllot;
    QTabWidget *tabWidgetAllot;
    QWidget *tabAddAllot;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QComboBox *comboBoxWarHseOut;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QComboBox *comboBoxWarHseIn;
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
    QPushButton *pushButtonAddAllotMat;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonCancel;
    QWidget *tabAllotInfo;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_18;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_19;
    QLineEdit *lineEditNumberInfo;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_22;
    QLineEdit *lineEditWareHseOutInfo;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_23;
    QLineEdit *lineEditWareHseInInfo;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_15;
    QDateEdit *dateEditArriveTimeInfo;
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
    QCommandLinkButton *commandLinkButtonEdit;
    QTableWidget *tableWidgetAllotInfo;
    QPushButton *pushButtonAllotMatInfo;
    QPushButton *pushButtonSubmit;
    QPushButton *pushButtonReConfirm;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonRefuse;
    QPushButton *pushButtonFinish;
    QHBoxLayout *horizontalLayout_17;
    QPushButton *pushButtonSaveInfo;
    QPushButton *pushButtonDel;
    QPushButton *pushButtonCancelInfo;

    void setupUi(QWidget *inventorytransfer)
    {
        if (inventorytransfer->objectName().isEmpty())
            inventorytransfer->setObjectName(QStringLiteral("inventorytransfer"));
        inventorytransfer->resize(402, 458);
        inventorytransfer->setStyleSheet(QLatin1String("QComboBox \n"
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
        verticalLayout_2 = new QVBoxLayout(inventorytransfer);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));

        verticalLayout->addLayout(horizontalLayout_20);

        widgetControl = new QWidget(inventorytransfer);
        widgetControl->setObjectName(QStringLiteral("widgetControl"));
        widgetControl->setMinimumSize(QSize(0, 20));
        labelState = new QLabel(widgetControl);
        labelState->setObjectName(QStringLiteral("labelState"));
        labelState->setGeometry(QRect(11, 11, 42, 16));
        comboBoxStateSelect = new QComboBox(widgetControl);
        comboBoxStateSelect->setObjectName(QStringLiteral("comboBoxStateSelect"));
        comboBoxStateSelect->setGeometry(QRect(59, 21, 44, 22));
        comboBoxStateSelect->setMinimumSize(QSize(0, 0));
        comboBoxWarHseOutSelect = new QComboBox(widgetControl);
        comboBoxWarHseOutSelect->setObjectName(QStringLiteral("comboBoxWarHseOutSelect"));
        comboBoxWarHseOutSelect->setGeometry(QRect(158, 21, 44, 22));
        comboBoxWarHseOutSelect->setMinimumSize(QSize(0, 0));
        labelOutWhse = new QLabel(widgetControl);
        labelOutWhse->setObjectName(QStringLiteral("labelOutWhse"));
        labelOutWhse->setGeometry(QRect(109, 11, 43, 42));
        labelInWhse = new QLabel(widgetControl);
        labelInWhse->setObjectName(QStringLiteral("labelInWhse"));
        labelInWhse->setGeometry(QRect(208, 11, 43, 42));
        comboBoxWarHseInSelect = new QComboBox(widgetControl);
        comboBoxWarHseInSelect->setObjectName(QStringLiteral("comboBoxWarHseInSelect"));
        comboBoxWarHseInSelect->setGeometry(QRect(257, 21, 44, 22));
        comboBoxWarHseInSelect->setMinimumSize(QSize(0, 0));
        dateEditSelect = new QDateEdit(widgetControl);
        dateEditSelect->setObjectName(QStringLiteral("dateEditSelect"));
        dateEditSelect->setGeometry(QRect(357, 17, 43, 30));
        pushButtonSelect = new QPushButton(widgetControl);
        pushButtonSelect->setObjectName(QStringLiteral("pushButtonSelect"));
        pushButtonSelect->setGeometry(QRect(406, 24, 44, 16));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\346\237\245\350\257\242.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSelect->setIcon(icon);
        labelDate = new QLabel(widgetControl);
        labelDate->setObjectName(QStringLiteral("labelDate"));
        labelDate->setGeometry(QRect(307, 11, 44, 42));
        pushButtonExtend = new QPushButton(widgetControl);
        pushButtonExtend->setObjectName(QStringLiteral("pushButtonExtend"));
        pushButtonExtend->setGeometry(QRect(456, 24, 43, 16));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/export.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonExtend->setIcon(icon1);
        pushButtonAdd = new QPushButton(widgetControl);
        pushButtonAdd->setObjectName(QStringLiteral("pushButtonAdd"));
        pushButtonAdd->setGeometry(QRect(505, 24, 44, 16));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/image/addfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonAdd->setIcon(icon2);
        labelSize = new QLabel(widgetControl);
        labelSize->setObjectName(QStringLiteral("labelSize"));
        labelSize->setGeometry(QRect(555, 11, 16, 18));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        labelSize->setFont(font);

        verticalLayout->addWidget(widgetControl);

        tableWidgetAllot = new QTableWidget(inventorytransfer);
        if (tableWidgetAllot->columnCount() < 5)
            tableWidgetAllot->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetAllot->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetAllot->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetAllot->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetAllot->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetAllot->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidgetAllot->setObjectName(QStringLiteral("tableWidgetAllot"));

        verticalLayout->addWidget(tableWidgetAllot);


        horizontalLayout_2->addLayout(verticalLayout);

        tabWidgetAllot = new QTabWidget(inventorytransfer);
        tabWidgetAllot->setObjectName(QStringLiteral("tabWidgetAllot"));
        tabAddAllot = new QWidget();
        tabAddAllot->setObjectName(QStringLiteral("tabAddAllot"));
        verticalLayout_3 = new QVBoxLayout(tabAddAllot);
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(tabAddAllot);
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

        horizontalSpacer_4 = new QSpacerItem(40, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_3 = new QLabel(tabAddAllot);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);

        horizontalLayout_6->addWidget(label_3);

        comboBoxWarHseOut = new QComboBox(tabAddAllot);
        comboBoxWarHseOut->setObjectName(QStringLiteral("comboBoxWarHseOut"));
        comboBoxWarHseOut->setMinimumSize(QSize(200, 0));
        comboBoxWarHseOut->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_6->addWidget(comboBoxWarHseOut);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalSpacer_3 = new QSpacerItem(40, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label = new QLabel(tabAddAllot);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);

        horizontalLayout_4->addWidget(label);

        comboBoxWarHseIn = new QComboBox(tabAddAllot);
        comboBoxWarHseIn->setObjectName(QStringLiteral("comboBoxWarHseIn"));
        comboBoxWarHseIn->setMinimumSize(QSize(200, 0));
        comboBoxWarHseIn->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_4->addWidget(comboBoxWarHseIn);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalSpacer_5 = new QSpacerItem(40, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_5);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_2 = new QLabel(tabAddAllot);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        horizontalLayout_5->addWidget(label_2);

        dateEditArriveTime = new QDateEdit(tabAddAllot);
        dateEditArriveTime->setObjectName(QStringLiteral("dateEditArriveTime"));
        dateEditArriveTime->setMinimumSize(QSize(200, 0));
        dateEditArriveTime->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_5->addWidget(dateEditArriveTime);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalSpacer_6 = new QSpacerItem(40, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_6);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_6 = new QLabel(tabAddAllot);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);

        horizontalLayout_10->addWidget(label_6);

        timeEditAddTime = new QTimeEdit(tabAddAllot);
        timeEditAddTime->setObjectName(QStringLiteral("timeEditAddTime"));
        timeEditAddTime->setMinimumSize(QSize(200, 0));
        timeEditAddTime->setMaximumSize(QSize(200, 30));
        timeEditAddTime->setStyleSheet(QStringLiteral(""));

        horizontalLayout_10->addWidget(timeEditAddTime);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalSpacer_9 = new QSpacerItem(40, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_9);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_4 = new QLabel(tabAddAllot);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        horizontalLayout_7->addWidget(label_4);

        lineEditRemark = new QLineEdit(tabAddAllot);
        lineEditRemark->setObjectName(QStringLiteral("lineEditRemark"));
        lineEditRemark->setMinimumSize(QSize(200, 0));
        lineEditRemark->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_7->addWidget(lineEditRemark);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalSpacer_7 = new QSpacerItem(40, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_7);

        label_8 = new QLabel(tabAddAllot);
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

        pushButtonAddAllotMat = new QPushButton(tabAddAllot);
        pushButtonAddAllotMat->setObjectName(QStringLiteral("pushButtonAddAllotMat"));
        pushButtonAddAllotMat->setMinimumSize(QSize(0, 60));
        pushButtonAddAllotMat->setIcon(icon2);

        verticalLayout_3->addWidget(pushButtonAddAllotMat);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        pushButtonSave = new QPushButton(tabAddAllot);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSave->setIcon(icon3);

        horizontalLayout_9->addWidget(pushButtonSave);

        pushButtonCancel = new QPushButton(tabAddAllot);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/image/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon4);

        horizontalLayout_9->addWidget(pushButtonCancel);


        verticalLayout_3->addLayout(horizontalLayout_9);

        tabWidgetAllot->addTab(tabAddAllot, QString());
        tabAllotInfo = new QWidget();
        tabAllotInfo->setObjectName(QStringLiteral("tabAllotInfo"));
        verticalLayout_5 = new QVBoxLayout(tabAllotInfo);
        verticalLayout_5->setSpacing(2);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(2, 0, 2, 0);
        label_18 = new QLabel(tabAllotInfo);
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
        label_19 = new QLabel(tabAllotInfo);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setFont(font1);

        horizontalLayout_15->addWidget(label_19);

        lineEditNumberInfo = new QLineEdit(tabAllotInfo);
        lineEditNumberInfo->setObjectName(QStringLiteral("lineEditNumberInfo"));
        lineEditNumberInfo->setEnabled(false);
        lineEditNumberInfo->setMinimumSize(QSize(200, 0));
        lineEditNumberInfo->setMaximumSize(QSize(200, 16777215));
        lineEditNumberInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_15->addWidget(lineEditNumberInfo);


        verticalLayout_5->addLayout(horizontalLayout_15);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        label_22 = new QLabel(tabAllotInfo);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setFont(font1);

        horizontalLayout_19->addWidget(label_22);

        lineEditWareHseOutInfo = new QLineEdit(tabAllotInfo);
        lineEditWareHseOutInfo->setObjectName(QStringLiteral("lineEditWareHseOutInfo"));
        lineEditWareHseOutInfo->setEnabled(false);
        lineEditWareHseOutInfo->setMinimumSize(QSize(200, 0));
        lineEditWareHseOutInfo->setMaximumSize(QSize(200, 16777215));
        lineEditWareHseOutInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_19->addWidget(lineEditWareHseOutInfo);


        verticalLayout_5->addLayout(horizontalLayout_19);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        label_23 = new QLabel(tabAllotInfo);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setFont(font1);

        horizontalLayout_21->addWidget(label_23);

        lineEditWareHseInInfo = new QLineEdit(tabAllotInfo);
        lineEditWareHseInInfo->setObjectName(QStringLiteral("lineEditWareHseInInfo"));
        lineEditWareHseInInfo->setEnabled(false);
        lineEditWareHseInInfo->setMinimumSize(QSize(200, 0));
        lineEditWareHseInInfo->setMaximumSize(QSize(200, 16777215));
        lineEditWareHseInInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_21->addWidget(lineEditWareHseInInfo);


        verticalLayout_5->addLayout(horizontalLayout_21);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_15 = new QLabel(tabAllotInfo);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font1);

        horizontalLayout_12->addWidget(label_15);

        dateEditArriveTimeInfo = new QDateEdit(tabAllotInfo);
        dateEditArriveTimeInfo->setObjectName(QStringLiteral("dateEditArriveTimeInfo"));
        dateEditArriveTimeInfo->setMinimumSize(QSize(200, 0));
        dateEditArriveTimeInfo->setMaximumSize(QSize(200, 16777215));
        dateEditArriveTimeInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_12->addWidget(dateEditArriveTimeInfo);


        verticalLayout_5->addLayout(horizontalLayout_12);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        label_21 = new QLabel(tabAllotInfo);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setFont(font1);

        horizontalLayout_18->addWidget(label_21);

        timeEditTimeInfo = new QTimeEdit(tabAllotInfo);
        timeEditTimeInfo->setObjectName(QStringLiteral("timeEditTimeInfo"));
        timeEditTimeInfo->setMinimumSize(QSize(200, 0));
        timeEditTimeInfo->setMaximumSize(QSize(200, 30));
        timeEditTimeInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_18->addWidget(timeEditTimeInfo);


        verticalLayout_5->addLayout(horizontalLayout_18);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_17 = new QLabel(tabAllotInfo);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setFont(font1);

        horizontalLayout_14->addWidget(label_17);

        lineEditRemarkInfo = new QLineEdit(tabAllotInfo);
        lineEditRemarkInfo->setObjectName(QStringLiteral("lineEditRemarkInfo"));
        lineEditRemarkInfo->setMinimumSize(QSize(200, 0));
        lineEditRemarkInfo->setMaximumSize(QSize(200, 16777215));
        lineEditRemarkInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_14->addWidget(lineEditRemarkInfo);


        verticalLayout_5->addLayout(horizontalLayout_14);

        commandLinkButtonLog = new QCommandLinkButton(tabAllotInfo);
        commandLinkButtonLog->setObjectName(QStringLiteral("commandLinkButtonLog"));

        verticalLayout_5->addWidget(commandLinkButtonLog);

        frame = new QFrame(tabAllotInfo);
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
        commandLinkButtonEdit->setMaximumSize(QSize(120, 16777215));
        commandLinkButtonEdit->setStyleSheet(QStringLiteral("background-color: transparent;"));

        horizontalLayout_8->addWidget(commandLinkButtonEdit);


        verticalLayout_8->addLayout(horizontalLayout_8);


        verticalLayout_5->addWidget(frame);

        tableWidgetAllotInfo = new QTableWidget(tabAllotInfo);
        if (tableWidgetAllotInfo->columnCount() < 5)
            tableWidgetAllotInfo->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidgetAllotInfo->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidgetAllotInfo->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidgetAllotInfo->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidgetAllotInfo->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidgetAllotInfo->setHorizontalHeaderItem(4, __qtablewidgetitem9);
        tableWidgetAllotInfo->setObjectName(QStringLiteral("tableWidgetAllotInfo"));

        verticalLayout_5->addWidget(tableWidgetAllotInfo);

        pushButtonAllotMatInfo = new QPushButton(tabAllotInfo);
        pushButtonAllotMatInfo->setObjectName(QStringLiteral("pushButtonAllotMatInfo"));
        pushButtonAllotMatInfo->setMinimumSize(QSize(0, 0));
        pushButtonAllotMatInfo->setIcon(icon2);

        verticalLayout_5->addWidget(pushButtonAllotMatInfo);

        pushButtonSubmit = new QPushButton(tabAllotInfo);
        pushButtonSubmit->setObjectName(QStringLiteral("pushButtonSubmit"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/image/image/\347\241\256\350\256\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSubmit->setIcon(icon5);

        verticalLayout_5->addWidget(pushButtonSubmit);

        pushButtonReConfirm = new QPushButton(tabAllotInfo);
        pushButtonReConfirm->setObjectName(QStringLiteral("pushButtonReConfirm"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/image/image/\345\217\215\347\241\256\350\256\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonReConfirm->setIcon(icon6);

        verticalLayout_5->addWidget(pushButtonReConfirm);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButtonRefuse = new QPushButton(tabAllotInfo);
        pushButtonRefuse->setObjectName(QStringLiteral("pushButtonRefuse"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/image/image/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonRefuse->setIcon(icon7);

        horizontalLayout_3->addWidget(pushButtonRefuse);

        pushButtonFinish = new QPushButton(tabAllotInfo);
        pushButtonFinish->setObjectName(QStringLiteral("pushButtonFinish"));
        pushButtonFinish->setIcon(icon5);

        horizontalLayout_3->addWidget(pushButtonFinish);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        pushButtonSaveInfo = new QPushButton(tabAllotInfo);
        pushButtonSaveInfo->setObjectName(QStringLiteral("pushButtonSaveInfo"));
        pushButtonSaveInfo->setIcon(icon3);

        horizontalLayout_17->addWidget(pushButtonSaveInfo);

        pushButtonDel = new QPushButton(tabAllotInfo);
        pushButtonDel->setObjectName(QStringLiteral("pushButtonDel"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/image/image/\345\210\240 \351\231\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonDel->setIcon(icon8);

        horizontalLayout_17->addWidget(pushButtonDel);

        pushButtonCancelInfo = new QPushButton(tabAllotInfo);
        pushButtonCancelInfo->setObjectName(QStringLiteral("pushButtonCancelInfo"));
        pushButtonCancelInfo->setIcon(icon4);

        horizontalLayout_17->addWidget(pushButtonCancelInfo);


        verticalLayout_5->addLayout(horizontalLayout_17);

        tabWidgetAllot->addTab(tabAllotInfo, QString());

        horizontalLayout_2->addWidget(tabWidgetAllot);

        horizontalLayout_2->setStretch(0, 6);
        horizontalLayout_2->setStretch(1, 4);

        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(inventorytransfer);

        tabWidgetAllot->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(inventorytransfer);
    } // setupUi

    void retranslateUi(QWidget *inventorytransfer)
    {
        inventorytransfer->setWindowTitle(QApplication::translate("inventorytransfer", "Form", 0));
        labelState->setText(QApplication::translate("inventorytransfer", " \347\212\266\346\200\201\357\274\232", 0));
        labelOutWhse->setText(QApplication::translate("inventorytransfer", " \350\260\203\345\207\272\344\273\223\345\272\223\357\274\232", 0));
        labelInWhse->setText(QApplication::translate("inventorytransfer", " \350\260\203\345\205\245\344\273\223\345\272\223\357\274\232", 0));
        pushButtonSelect->setText(QApplication::translate("inventorytransfer", "\346\237\245\350\257\242", 0));
        labelDate->setText(QApplication::translate("inventorytransfer", " \350\260\203\346\213\250\346\227\245\346\234\237\357\274\232", 0));
        pushButtonExtend->setText(QApplication::translate("inventorytransfer", "\345\257\274\345\207\272", 0));
        pushButtonAdd->setText(QApplication::translate("inventorytransfer", "\346\267\273\345\212\240", 0));
        labelSize->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidgetAllot->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("inventorytransfer", "\350\260\203\345\207\272\344\273\223\345\272\223", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetAllot->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("inventorytransfer", "\350\260\203\345\205\245\344\273\223\345\272\223", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetAllot->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("inventorytransfer", "\350\260\203\346\213\250\345\215\225\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetAllot->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("inventorytransfer", "\350\260\203\346\213\250\346\227\245\346\234\237", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetAllot->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("inventorytransfer", "\347\212\266\346\200\201", 0));
        label_7->setText(QApplication::translate("inventorytransfer", " \345\237\272\346\234\254\344\277\241\346\201\257", 0));
        label_3->setText(QApplication::translate("inventorytransfer", "\350\260\203\345\207\272\344\273\223\345\272\223\357\274\232", 0));
#ifndef QT_NO_TOOLTIP
        comboBoxWarHseOut->setToolTip(QApplication::translate("inventorytransfer", "\345\217\257\344\270\215\345\241\253", 0));
#endif // QT_NO_TOOLTIP
        comboBoxWarHseOut->setCurrentText(QString());
        label->setText(QApplication::translate("inventorytransfer", "\350\260\203\345\205\245\344\273\223\345\272\223\357\274\232", 0));
        label_2->setText(QApplication::translate("inventorytransfer", "\350\260\203\346\213\250\346\227\245\346\234\237\357\274\232", 0));
        label_6->setText(QApplication::translate("inventorytransfer", "\350\260\203\346\213\250\346\227\266\351\227\264\357\274\232", 0));
        label_4->setText(QApplication::translate("inventorytransfer", "\345\244\207\346\263\250\357\274\232", 0));
        lineEditRemark->setPlaceholderText(QApplication::translate("inventorytransfer", "\345\217\257\344\270\215\345\241\253", 0));
        label_8->setText(QApplication::translate("inventorytransfer", " \350\260\203\346\213\250\345\216\237\346\226\231", 0));
        pushButtonAddAllotMat->setText(QApplication::translate("inventorytransfer", " \346\267\273\345\212\240\350\260\203\346\213\250\345\216\237\346\226\231...", 0));
        pushButtonSave->setText(QApplication::translate("inventorytransfer", "  \344\277\235\345\255\230", 0));
        pushButtonCancel->setText(QApplication::translate("inventorytransfer", " \345\217\226\346\266\210", 0));
        tabWidgetAllot->setTabText(tabWidgetAllot->indexOf(tabAddAllot), QApplication::translate("inventorytransfer", "\346\267\273\345\212\240\350\260\203\346\213\250\345\215\225", 0));
        label_18->setText(QApplication::translate("inventorytransfer", " \345\237\272\346\234\254\344\277\241\346\201\257", 0));
        label_19->setText(QApplication::translate("inventorytransfer", "\350\260\203\346\213\250\345\215\225\345\217\267\357\274\232", 0));
        label_22->setText(QApplication::translate("inventorytransfer", "\350\260\203\345\207\272\344\273\223\345\272\223\357\274\232", 0));
        label_23->setText(QApplication::translate("inventorytransfer", "\350\260\203\345\205\245\344\273\223\345\272\223\357\274\232", 0));
        label_15->setText(QApplication::translate("inventorytransfer", "\350\260\203\346\213\250\346\227\245\346\234\237\357\274\232", 0));
        label_21->setText(QApplication::translate("inventorytransfer", "\350\260\203\346\213\250\346\227\266\351\227\264\357\274\232", 0));
        label_17->setText(QApplication::translate("inventorytransfer", "\345\244\207\346\263\250\357\274\232", 0));
        lineEditRemarkInfo->setPlaceholderText(QApplication::translate("inventorytransfer", "\345\217\257\344\270\215\345\241\253", 0));
        commandLinkButtonLog->setText(QApplication::translate("inventorytransfer", " \345\244\204\347\220\206\350\256\260\345\275\225", 0));
        label_5->setText(QApplication::translate("inventorytransfer", "  \350\260\203\346\213\250\345\216\237\346\226\231", 0));
        labelTotalCount->setText(QString());
        commandLinkButtonEdit->setText(QApplication::translate("inventorytransfer", " \347\274\226\350\276\221\350\260\203\346\213\250\345\216\237\346\226\231", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetAllotInfo->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("inventorytransfer", "\345\216\237\346\226\231\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetAllotInfo->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("inventorytransfer", "\346\235\241\345\275\242\347\240\201", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidgetAllotInfo->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QApplication::translate("inventorytransfer", "\345\215\225\344\275\215", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidgetAllotInfo->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QApplication::translate("inventorytransfer", "\345\215\225\344\273\267", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidgetAllotInfo->horizontalHeaderItem(4);
        ___qtablewidgetitem9->setText(QApplication::translate("inventorytransfer", "\346\225\260\351\207\217", 0));
        pushButtonAllotMatInfo->setText(QApplication::translate("inventorytransfer", " \346\267\273\345\212\240\350\260\203\346\213\250\345\216\237\346\226\231", 0));
        pushButtonSubmit->setText(QApplication::translate("inventorytransfer", " \346\217\220\344\272\244", 0));
        pushButtonReConfirm->setText(QApplication::translate("inventorytransfer", " \345\217\215\347\241\256\350\256\244", 0));
        pushButtonRefuse->setText(QApplication::translate("inventorytransfer", " \346\213\222\347\273\235\350\260\203\346\213\250", 0));
        pushButtonFinish->setText(QApplication::translate("inventorytransfer", " \350\260\203\346\213\250\345\256\214\346\210\220", 0));
        pushButtonSaveInfo->setText(QApplication::translate("inventorytransfer", " \344\277\235\345\255\230", 0));
        pushButtonDel->setText(QApplication::translate("inventorytransfer", " \345\210\240\351\231\244", 0));
        pushButtonCancelInfo->setText(QApplication::translate("inventorytransfer", " \345\217\226\346\266\210", 0));
        tabWidgetAllot->setTabText(tabWidgetAllot->indexOf(tabAllotInfo), QApplication::translate("inventorytransfer", "\350\260\203\346\213\250\345\215\225\350\257\246\346\203\205", 0));
    } // retranslateUi

};

namespace Ui {
    class inventorytransfer: public Ui_inventorytransfer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVENTORYTRANSFER_H
