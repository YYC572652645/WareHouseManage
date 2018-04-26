/********************************************************************************
** Form generated from reading UI file 'purchaseorder.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PURCHASEORDER_H
#define UI_PURCHASEORDER_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PurchaseOrder
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QWidget *widgetControl;
    QLabel *labelState;
    QComboBox *comboBoxStateSelect;
    QLabel *labelSup;
    QComboBox *comboBoxSupplierSelect;
    QLabel *labelArrive;
    QPushButton *pushButtonSelect;
    QDateEdit *dateEditSelect;
    QPushButton *pushButtonTemplate;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonExtend;
    QLabel *labelSize;
    QTableWidget *tableWidgetPur;
    QTabWidget *tabWidgetPurchase;
    QWidget *tabAddPur;
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
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QComboBox *comboBoxPurWarHse;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLineEdit *lineEditRemark;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_8;
    QPushButton *pushButtonAddPurMat;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonCancel;
    QWidget *tabPurInfo;
    QVBoxLayout *verticalLayoutPur;
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
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_15;
    QDateEdit *dateEditArriveTimeInfo;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_16;
    QComboBox *comboBoxPurWarHseInfo;
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
    QPushButton *pushButtonLookInfo;
    QPushButton *pushButtonStartSureInfo;
    QHBoxLayout *horizontalLayout_17;
    QPushButton *pushButtonSaveInfo;
    QPushButton *pushButtonDeleteInfo;
    QPushButton *pushButtonCancelInfo;

    void setupUi(QWidget *PurchaseOrder)
    {
        if (PurchaseOrder->objectName().isEmpty())
            PurchaseOrder->setObjectName(QStringLiteral("PurchaseOrder"));
        PurchaseOrder->resize(398, 462);
        PurchaseOrder->setStyleSheet(QLatin1String("QComboBox \n"
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
        verticalLayout_2 = new QVBoxLayout(PurchaseOrder);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widgetControl = new QWidget(PurchaseOrder);
        widgetControl->setObjectName(QStringLiteral("widgetControl"));
        widgetControl->setMinimumSize(QSize(0, 20));
        labelState = new QLabel(widgetControl);
        labelState->setObjectName(QStringLiteral("labelState"));
        labelState->setGeometry(QRect(0, 10, 42, 16));
        comboBoxStateSelect = new QComboBox(widgetControl);
        comboBoxStateSelect->setObjectName(QStringLiteral("comboBoxStateSelect"));
        comboBoxStateSelect->setGeometry(QRect(40, 10, 31, 22));
        comboBoxStateSelect->setMinimumSize(QSize(0, 0));
        labelSup = new QLabel(widgetControl);
        labelSup->setObjectName(QStringLiteral("labelSup"));
        labelSup->setGeometry(QRect(80, 10, 21, 16));
        comboBoxSupplierSelect = new QComboBox(widgetControl);
        comboBoxSupplierSelect->setObjectName(QStringLiteral("comboBoxSupplierSelect"));
        comboBoxSupplierSelect->setGeometry(QRect(110, 10, 72, 22));
        comboBoxSupplierSelect->setMinimumSize(QSize(0, 0));
        labelArrive = new QLabel(widgetControl);
        labelArrive->setObjectName(QStringLiteral("labelArrive"));
        labelArrive->setGeometry(QRect(190, 10, 78, 16));
        pushButtonSelect = new QPushButton(widgetControl);
        pushButtonSelect->setObjectName(QStringLiteral("pushButtonSelect"));
        pushButtonSelect->setGeometry(QRect(370, 10, 51, 16));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\346\237\245\350\257\242.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSelect->setIcon(icon);
        dateEditSelect = new QDateEdit(widgetControl);
        dateEditSelect->setObjectName(QStringLiteral("dateEditSelect"));
        dateEditSelect->setGeometry(QRect(270, 10, 90, 22));
        dateEditSelect->setMinimumSize(QSize(0, 0));
        pushButtonTemplate = new QPushButton(widgetControl);
        pushButtonTemplate->setObjectName(QStringLiteral("pushButtonTemplate"));
        pushButtonTemplate->setGeometry(QRect(420, 10, 41, 16));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/image/\351\207\207\350\264\255\346\250\241\346\235\277.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonTemplate->setIcon(icon1);
        pushButtonAdd = new QPushButton(widgetControl);
        pushButtonAdd->setObjectName(QStringLiteral("pushButtonAdd"));
        pushButtonAdd->setGeometry(QRect(540, 10, 41, 16));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/image/addfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonAdd->setIcon(icon2);
        pushButtonExtend = new QPushButton(widgetControl);
        pushButtonExtend->setObjectName(QStringLiteral("pushButtonExtend"));
        pushButtonExtend->setGeometry(QRect(470, 10, 41, 16));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/image/export.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonExtend->setIcon(icon3);
        labelSize = new QLabel(widgetControl);
        labelSize->setObjectName(QStringLiteral("labelSize"));
        labelSize->setGeometry(QRect(819, 41, 16, 18));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        labelSize->setFont(font);

        verticalLayout->addWidget(widgetControl);

        tableWidgetPur = new QTableWidget(PurchaseOrder);
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
        tableWidgetPur->setMinimumSize(QSize(0, 0));

        verticalLayout->addWidget(tableWidgetPur);


        horizontalLayout_2->addLayout(verticalLayout);

        tabWidgetPurchase = new QTabWidget(PurchaseOrder);
        tabWidgetPurchase->setObjectName(QStringLiteral("tabWidgetPurchase"));
        tabAddPur = new QWidget();
        tabAddPur->setObjectName(QStringLiteral("tabAddPur"));
        verticalLayout_3 = new QVBoxLayout(tabAddPur);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(2, 0, 2, 0);
        commandLinkButtonImport = new QCommandLinkButton(tabAddPur);
        commandLinkButtonImport->setObjectName(QStringLiteral("commandLinkButtonImport"));

        verticalLayout_3->addWidget(commandLinkButtonImport);

        label_7 = new QLabel(tabAddPur);
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

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(tabAddPur);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);

        horizontalLayout_3->addWidget(label);

        comboBoxSupplier = new QComboBox(tabAddPur);
        comboBoxSupplier->setObjectName(QStringLiteral("comboBoxSupplier"));
        comboBoxSupplier->setMinimumSize(QSize(200, 30));
        comboBoxSupplier->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_3->addWidget(comboBoxSupplier);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalSpacer_3 = new QSpacerItem(40, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(tabAddPur);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        horizontalLayout_4->addWidget(label_2);

        dateEditArriveTime = new QDateEdit(tabAddPur);
        dateEditArriveTime->setObjectName(QStringLiteral("dateEditArriveTime"));
        dateEditArriveTime->setMinimumSize(QSize(200, 30));
        dateEditArriveTime->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_4->addWidget(dateEditArriveTime);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalSpacer_4 = new QSpacerItem(40, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_3 = new QLabel(tabAddPur);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        horizontalLayout_5->addWidget(label_3);

        comboBoxPurWarHse = new QComboBox(tabAddPur);
        comboBoxPurWarHse->setObjectName(QStringLiteral("comboBoxPurWarHse"));
        comboBoxPurWarHse->setMinimumSize(QSize(200, 30));
        comboBoxPurWarHse->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_5->addWidget(comboBoxPurWarHse);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalSpacer_5 = new QSpacerItem(40, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_4 = new QLabel(tabAddPur);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        horizontalLayout_6->addWidget(label_4);

        lineEditRemark = new QLineEdit(tabAddPur);
        lineEditRemark->setObjectName(QStringLiteral("lineEditRemark"));
        lineEditRemark->setMinimumSize(QSize(200, 30));
        lineEditRemark->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_6->addWidget(lineEditRemark);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalSpacer_6 = new QSpacerItem(40, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_6);

        label_8 = new QLabel(tabAddPur);
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

        pushButtonAddPurMat = new QPushButton(tabAddPur);
        pushButtonAddPurMat->setObjectName(QStringLiteral("pushButtonAddPurMat"));
        pushButtonAddPurMat->setMinimumSize(QSize(0, 60));
        pushButtonAddPurMat->setIcon(icon2);

        verticalLayout_3->addWidget(pushButtonAddPurMat);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        pushButtonSave = new QPushButton(tabAddPur);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/image/image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSave->setIcon(icon4);

        horizontalLayout_7->addWidget(pushButtonSave);

        pushButtonCancel = new QPushButton(tabAddPur);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/image/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon5);

        horizontalLayout_7->addWidget(pushButtonCancel);


        verticalLayout_3->addLayout(horizontalLayout_7);

        tabWidgetPurchase->addTab(tabAddPur, QString());
        tabPurInfo = new QWidget();
        tabPurInfo->setObjectName(QStringLiteral("tabPurInfo"));
        verticalLayoutPur = new QVBoxLayout(tabPurInfo);
        verticalLayoutPur->setSpacing(2);
        verticalLayoutPur->setObjectName(QStringLiteral("verticalLayoutPur"));
        verticalLayoutPur->setContentsMargins(2, 0, 2, 0);
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

        verticalLayoutPur->addWidget(label_18);

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


        verticalLayoutPur->addLayout(horizontalLayout_15);

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


        verticalLayoutPur->addLayout(horizontalLayout_16);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_13 = new QLabel(tabPurInfo);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font1);

        horizontalLayout_11->addWidget(label_13);

        comboBoxSupplierInfo = new QComboBox(tabPurInfo);
        comboBoxSupplierInfo->setObjectName(QStringLiteral("comboBoxSupplierInfo"));
        comboBoxSupplierInfo->setMinimumSize(QSize(200, 0));
        comboBoxSupplierInfo->setMaximumSize(QSize(200, 16777215));
        comboBoxSupplierInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_11->addWidget(comboBoxSupplierInfo);


        verticalLayoutPur->addLayout(horizontalLayout_11);

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


        verticalLayoutPur->addLayout(horizontalLayout_12);

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


        verticalLayoutPur->addLayout(horizontalLayout_13);

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


        verticalLayoutPur->addLayout(horizontalLayout_14);

        commandLinkButtonLog = new QCommandLinkButton(tabPurInfo);
        commandLinkButtonLog->setObjectName(QStringLiteral("commandLinkButtonLog"));

        verticalLayoutPur->addWidget(commandLinkButtonLog);

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


        verticalLayoutPur->addWidget(frame);

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

        verticalLayoutPur->addWidget(tableWidgetPurInfo);

        pushButtonPurMatInfo = new QPushButton(tabPurInfo);
        pushButtonPurMatInfo->setObjectName(QStringLiteral("pushButtonPurMatInfo"));
        pushButtonPurMatInfo->setMinimumSize(QSize(0, 0));
        pushButtonPurMatInfo->setIcon(icon2);

        verticalLayoutPur->addWidget(pushButtonPurMatInfo);

        pushButtonLookInfo = new QPushButton(tabPurInfo);
        pushButtonLookInfo->setObjectName(QStringLiteral("pushButtonLookInfo"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/image/image/\351\242\204\350\247\210.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonLookInfo->setIcon(icon6);

        verticalLayoutPur->addWidget(pushButtonLookInfo);

        pushButtonStartSureInfo = new QPushButton(tabPurInfo);
        pushButtonStartSureInfo->setObjectName(QStringLiteral("pushButtonStartSureInfo"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/image/image/\347\241\256\350\256\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonStartSureInfo->setIcon(icon7);

        verticalLayoutPur->addWidget(pushButtonStartSureInfo);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        pushButtonSaveInfo = new QPushButton(tabPurInfo);
        pushButtonSaveInfo->setObjectName(QStringLiteral("pushButtonSaveInfo"));
        pushButtonSaveInfo->setIcon(icon4);

        horizontalLayout_17->addWidget(pushButtonSaveInfo);

        pushButtonDeleteInfo = new QPushButton(tabPurInfo);
        pushButtonDeleteInfo->setObjectName(QStringLiteral("pushButtonDeleteInfo"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/image/image/\345\210\240 \351\231\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonDeleteInfo->setIcon(icon8);

        horizontalLayout_17->addWidget(pushButtonDeleteInfo);

        pushButtonCancelInfo = new QPushButton(tabPurInfo);
        pushButtonCancelInfo->setObjectName(QStringLiteral("pushButtonCancelInfo"));
        pushButtonCancelInfo->setIcon(icon5);

        horizontalLayout_17->addWidget(pushButtonCancelInfo);


        verticalLayoutPur->addLayout(horizontalLayout_17);

        tabWidgetPurchase->addTab(tabPurInfo, QString());

        horizontalLayout_2->addWidget(tabWidgetPurchase);

        horizontalLayout_2->setStretch(0, 6);
        horizontalLayout_2->setStretch(1, 4);

        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(PurchaseOrder);

        tabWidgetPurchase->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(PurchaseOrder);
    } // setupUi

    void retranslateUi(QWidget *PurchaseOrder)
    {
        PurchaseOrder->setWindowTitle(QApplication::translate("PurchaseOrder", "Form", 0));
        labelState->setText(QApplication::translate("PurchaseOrder", " \347\212\266\346\200\201\357\274\232", 0));
        labelSup->setText(QApplication::translate("PurchaseOrder", " \344\276\233\345\272\224\345\225\206\357\274\232", 0));
        labelArrive->setText(QApplication::translate("PurchaseOrder", " \350\246\201\346\261\202\345\210\260\350\264\247\346\227\245\357\274\232", 0));
        pushButtonSelect->setText(QApplication::translate("PurchaseOrder", " \346\237\245\350\257\242", 0));
        pushButtonTemplate->setText(QApplication::translate("PurchaseOrder", " \346\250\241\346\235\277\351\207\207\350\264\255", 0));
        pushButtonAdd->setText(QApplication::translate("PurchaseOrder", " \346\267\273\345\212\240", 0));
        pushButtonExtend->setText(QApplication::translate("PurchaseOrder", " \345\257\274\345\207\272", 0));
        labelSize->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidgetPur->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("PurchaseOrder", "\344\276\233\345\272\224\345\225\206", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetPur->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("PurchaseOrder", "\351\207\207\350\264\255\345\215\225\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetPur->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("PurchaseOrder", "\350\246\201\346\261\202\345\210\260\350\264\247\346\227\245", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetPur->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("PurchaseOrder", "\347\212\266\346\200\201", 0));
        commandLinkButtonImport->setText(QApplication::translate("PurchaseOrder", "\344\273\216\345\216\206\345\217\262\351\207\207\350\264\255\350\256\242\345\215\225\345\257\274\345\205\245", 0));
        label_7->setText(QApplication::translate("PurchaseOrder", " \345\237\272\346\234\254\344\277\241\346\201\257", 0));
        label->setText(QApplication::translate("PurchaseOrder", "\344\276\233\345\272\224\345\225\206\357\274\232", 0));
        label_2->setText(QApplication::translate("PurchaseOrder", "\350\246\201\346\261\202\345\210\260\350\264\247\346\227\245\357\274\232", 0));
        label_3->setText(QApplication::translate("PurchaseOrder", "\351\207\207\350\264\255\344\273\223\345\272\223\357\274\232", 0));
#ifndef QT_NO_TOOLTIP
        comboBoxPurWarHse->setToolTip(QApplication::translate("PurchaseOrder", "\345\217\257\344\270\215\345\241\253", 0));
#endif // QT_NO_TOOLTIP
        comboBoxPurWarHse->setCurrentText(QString());
        label_4->setText(QApplication::translate("PurchaseOrder", "\345\244\207\346\263\250\357\274\232", 0));
        lineEditRemark->setPlaceholderText(QApplication::translate("PurchaseOrder", "\345\217\257\344\270\215\345\241\253", 0));
        label_8->setText(QApplication::translate("PurchaseOrder", " \351\207\207\350\264\255\345\216\237\346\226\231", 0));
        pushButtonAddPurMat->setText(QApplication::translate("PurchaseOrder", " \346\267\273\345\212\240\351\207\207\350\264\255\345\216\237\346\226\231...", 0));
        pushButtonSave->setText(QApplication::translate("PurchaseOrder", "  \344\277\235\345\255\230", 0));
        pushButtonCancel->setText(QApplication::translate("PurchaseOrder", " \345\217\226\346\266\210", 0));
        tabWidgetPurchase->setTabText(tabWidgetPurchase->indexOf(tabAddPur), QApplication::translate("PurchaseOrder", "\346\267\273\345\212\240\351\207\207\350\264\255\350\256\242\345\215\225", 0));
        label_18->setText(QApplication::translate("PurchaseOrder", " \345\237\272\346\234\254\344\277\241\346\201\257", 0));
        label_19->setText(QApplication::translate("PurchaseOrder", "\351\207\207\350\264\255\345\215\225\345\217\267\357\274\232", 0));
        label_20->setText(QApplication::translate("PurchaseOrder", "\347\212\266\346\200\201\357\274\232", 0));
        label_13->setText(QApplication::translate("PurchaseOrder", "\344\276\233\345\272\224\345\225\206\357\274\232", 0));
        label_15->setText(QApplication::translate("PurchaseOrder", "\350\246\201\346\261\202\345\210\260\350\264\247\346\227\245\357\274\232", 0));
        label_16->setText(QApplication::translate("PurchaseOrder", "\351\207\207\350\264\255\344\273\223\345\272\223\357\274\232", 0));
#ifndef QT_NO_TOOLTIP
        comboBoxPurWarHseInfo->setToolTip(QApplication::translate("PurchaseOrder", "\345\217\257\344\270\215\345\241\253", 0));
#endif // QT_NO_TOOLTIP
        comboBoxPurWarHseInfo->setCurrentText(QString());
        label_17->setText(QApplication::translate("PurchaseOrder", "\345\244\207\346\263\250\357\274\232", 0));
        lineEditRemarkInfo->setPlaceholderText(QApplication::translate("PurchaseOrder", "\345\217\257\344\270\215\345\241\253", 0));
        commandLinkButtonLog->setText(QApplication::translate("PurchaseOrder", " \345\244\204\347\220\206\350\256\260\345\275\225", 0));
        label_5->setText(QApplication::translate("PurchaseOrder", " \351\207\207\350\264\255\345\216\237\346\226\231", 0));
        labelTotalCount->setText(QString());
        commandLinkButtonEdit->setText(QApplication::translate("PurchaseOrder", " \347\274\226\350\276\221\351\207\207\350\264\255\345\216\237\346\226\231", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetPurInfo->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("PurchaseOrder", "\345\216\237\346\226\231\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetPurInfo->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("PurchaseOrder", "\346\235\241\345\275\242\347\240\201", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetPurInfo->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("PurchaseOrder", "\345\215\225\344\275\215", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidgetPurInfo->horizontalHeaderItem(3);
        ___qtablewidgetitem7->setText(QApplication::translate("PurchaseOrder", "\345\215\225\344\273\267", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidgetPurInfo->horizontalHeaderItem(4);
        ___qtablewidgetitem8->setText(QApplication::translate("PurchaseOrder", "\346\225\260\351\207\217", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidgetPurInfo->horizontalHeaderItem(5);
        ___qtablewidgetitem9->setText(QApplication::translate("PurchaseOrder", "\345\272\223\345\255\230", 0));
        pushButtonPurMatInfo->setText(QApplication::translate("PurchaseOrder", " \346\267\273\345\212\240\351\207\207\350\264\255\345\216\237\346\226\231", 0));
        pushButtonLookInfo->setText(QApplication::translate("PurchaseOrder", " \346\237\245\347\234\213\346\225\264\344\275\223\345\205\245\345\272\223\345\215\225", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonStartSureInfo->setToolTip(QApplication::translate("PurchaseOrder", "\345\274\200\345\247\213\347\241\256\350\256\244\351\207\207\350\264\255\345\216\237\346\226\231", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        pushButtonStartSureInfo->setWhatsThis(QApplication::translate("PurchaseOrder", "\345\274\200\345\247\213\347\241\256\350\256\244\351\207\207\350\264\255\345\216\237\346\226\231", 0));
#endif // QT_NO_WHATSTHIS
        pushButtonStartSureInfo->setText(QApplication::translate("PurchaseOrder", " \345\274\200\345\247\213\347\241\256\350\256\244\351\207\207\350\264\255\345\216\237\346\226\231", 0));
        pushButtonSaveInfo->setText(QApplication::translate("PurchaseOrder", " \344\277\235\345\255\230", 0));
        pushButtonDeleteInfo->setText(QApplication::translate("PurchaseOrder", " \345\210\240\351\231\244", 0));
        pushButtonCancelInfo->setText(QApplication::translate("PurchaseOrder", " \345\217\226\346\266\210", 0));
        tabWidgetPurchase->setTabText(tabWidgetPurchase->indexOf(tabPurInfo), QApplication::translate("PurchaseOrder", "\351\207\207\350\264\255\350\256\242\345\215\225\350\257\246\346\203\205", 0));
    } // retranslateUi

};

namespace Ui {
    class PurchaseOrder: public Ui_PurchaseOrder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PURCHASEORDER_H
