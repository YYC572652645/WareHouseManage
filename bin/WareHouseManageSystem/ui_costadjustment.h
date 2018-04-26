/********************************************************************************
** Form generated from reading UI file 'costadjustment.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COSTADJUSTMENT_H
#define UI_COSTADJUSTMENT_H

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

class Ui_CostAdjustment
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QWidget *widgetControl;
    QLabel *labelState;
    QComboBox *comboBoxStateSelect;
    QLabel *labelDate;
    QDateEdit *dateEditSelect;
    QPushButton *pushButtonSelect;
    QPushButton *pushButtonSee;
    QPushButton *pushButtonAdd;
    QLabel *labelSize;
    QTableWidget *tableWidgetCost;
    QTabWidget *tabWidgetCost;
    QWidget *tabAddCost;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_7;
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
    QWidget *tabCostInfo;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_18;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_19;
    QLineEdit *lineEditNumberInfo;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_16;
    QLineEdit *lineEditStateInfo;
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
    QTableWidget *tableWidgetCostInfo;
    QPushButton *pushButtonAddCostMatInfo;
    QPushButton *pushButtonConfirmInfo;
    QPushButton *pushButtonSubmitInfo;
    QHBoxLayout *horizontalLayout_17;
    QPushButton *pushButtonSaveInfo;
    QPushButton *pushButtonDeleteInfo;
    QPushButton *pushButtonCancelInfo;

    void setupUi(QWidget *CostAdjustment)
    {
        if (CostAdjustment->objectName().isEmpty())
            CostAdjustment->setObjectName(QStringLiteral("CostAdjustment"));
        CostAdjustment->resize(402, 400);
        CostAdjustment->setStyleSheet(QLatin1String("QComboBox \n"
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
        verticalLayout_2 = new QVBoxLayout(CostAdjustment);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widgetControl = new QWidget(CostAdjustment);
        widgetControl->setObjectName(QStringLiteral("widgetControl"));
        widgetControl->setMinimumSize(QSize(0, 20));
        labelState = new QLabel(widgetControl);
        labelState->setObjectName(QStringLiteral("labelState"));
        labelState->setGeometry(QRect(1, 1, 39, 39));
        comboBoxStateSelect = new QComboBox(widgetControl);
        comboBoxStateSelect->setObjectName(QStringLiteral("comboBoxStateSelect"));
        comboBoxStateSelect->setGeometry(QRect(46, 9, 39, 22));
        comboBoxStateSelect->setMinimumSize(QSize(0, 0));
        labelDate = new QLabel(widgetControl);
        labelDate->setObjectName(QStringLiteral("labelDate"));
        labelDate->setGeometry(QRect(91, 1, 39, 39));
        dateEditSelect = new QDateEdit(widgetControl);
        dateEditSelect->setObjectName(QStringLiteral("dateEditSelect"));
        dateEditSelect->setGeometry(QRect(136, 9, 39, 22));
        dateEditSelect->setMinimumSize(QSize(0, 0));
        pushButtonSelect = new QPushButton(widgetControl);
        pushButtonSelect->setObjectName(QStringLiteral("pushButtonSelect"));
        pushButtonSelect->setGeometry(QRect(181, 12, 39, 16));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\346\237\245\350\257\242.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSelect->setIcon(icon);
        pushButtonSee = new QPushButton(widgetControl);
        pushButtonSee->setObjectName(QStringLiteral("pushButtonSee"));
        pushButtonSee->setGeometry(QRect(226, 12, 39, 16));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/image/\351\242\204\350\247\210.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSee->setIcon(icon1);
        pushButtonAdd = new QPushButton(widgetControl);
        pushButtonAdd->setObjectName(QStringLiteral("pushButtonAdd"));
        pushButtonAdd->setGeometry(QRect(271, 12, 38, 16));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/image/addfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonAdd->setIcon(icon2);
        labelSize = new QLabel(widgetControl);
        labelSize->setObjectName(QStringLiteral("labelSize"));
        labelSize->setGeometry(QRect(315, 1, 16, 18));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        labelSize->setFont(font);

        verticalLayout->addWidget(widgetControl);

        tableWidgetCost = new QTableWidget(CostAdjustment);
        if (tableWidgetCost->columnCount() < 4)
            tableWidgetCost->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetCost->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetCost->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetCost->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetCost->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidgetCost->setObjectName(QStringLiteral("tableWidgetCost"));

        verticalLayout->addWidget(tableWidgetCost);


        horizontalLayout_2->addLayout(verticalLayout);

        tabWidgetCost = new QTabWidget(CostAdjustment);
        tabWidgetCost->setObjectName(QStringLiteral("tabWidgetCost"));
        tabAddCost = new QWidget();
        tabAddCost->setObjectName(QStringLiteral("tabAddCost"));
        verticalLayout_3 = new QVBoxLayout(tabAddCost);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(2, 0, 2, 0);
        label_7 = new QLabel(tabAddCost);
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

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_4 = new QLabel(tabAddCost);
        label_4->setObjectName(QStringLiteral("label_4"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        label_4->setFont(font1);

        horizontalLayout_6->addWidget(label_4);

        lineEditRemark = new QLineEdit(tabAddCost);
        lineEditRemark->setObjectName(QStringLiteral("lineEditRemark"));
        lineEditRemark->setMinimumSize(QSize(200, 0));
        lineEditRemark->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_6->addWidget(lineEditRemark);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalSpacer_6 = new QSpacerItem(40, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_6);

        label_8 = new QLabel(tabAddCost);
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

        pushButtonAddAdjustMat = new QPushButton(tabAddCost);
        pushButtonAddAdjustMat->setObjectName(QStringLiteral("pushButtonAddAdjustMat"));
        pushButtonAddAdjustMat->setMinimumSize(QSize(0, 60));
        pushButtonAddAdjustMat->setIcon(icon2);

        verticalLayout_3->addWidget(pushButtonAddAdjustMat);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        pushButtonSave = new QPushButton(tabAddCost);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSave->setIcon(icon3);

        horizontalLayout_7->addWidget(pushButtonSave);

        pushButtonCancel = new QPushButton(tabAddCost);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/image/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon4);

        horizontalLayout_7->addWidget(pushButtonCancel);


        verticalLayout_3->addLayout(horizontalLayout_7);

        tabWidgetCost->addTab(tabAddCost, QString());
        tabCostInfo = new QWidget();
        tabCostInfo->setObjectName(QStringLiteral("tabCostInfo"));
        verticalLayout_5 = new QVBoxLayout(tabCostInfo);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(2, 0, 2, 0);
        label_18 = new QLabel(tabCostInfo);
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
        label_19 = new QLabel(tabCostInfo);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setFont(font1);

        horizontalLayout_15->addWidget(label_19);

        lineEditNumberInfo = new QLineEdit(tabCostInfo);
        lineEditNumberInfo->setObjectName(QStringLiteral("lineEditNumberInfo"));
        lineEditNumberInfo->setEnabled(false);
        lineEditNumberInfo->setMinimumSize(QSize(200, 0));
        lineEditNumberInfo->setMaximumSize(QSize(200, 16777215));
        lineEditNumberInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_15->addWidget(lineEditNumberInfo);


        verticalLayout_5->addLayout(horizontalLayout_15);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_16 = new QLabel(tabCostInfo);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font1);

        horizontalLayout_13->addWidget(label_16);

        lineEditStateInfo = new QLineEdit(tabCostInfo);
        lineEditStateInfo->setObjectName(QStringLiteral("lineEditStateInfo"));
        lineEditStateInfo->setEnabled(false);
        lineEditStateInfo->setMinimumSize(QSize(200, 0));
        lineEditStateInfo->setMaximumSize(QSize(200, 16777215));
        lineEditStateInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_13->addWidget(lineEditStateInfo);


        verticalLayout_5->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_17 = new QLabel(tabCostInfo);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setFont(font1);

        horizontalLayout_14->addWidget(label_17);

        lineEditRemarkInfo = new QLineEdit(tabCostInfo);
        lineEditRemarkInfo->setObjectName(QStringLiteral("lineEditRemarkInfo"));
        lineEditRemarkInfo->setMinimumSize(QSize(200, 0));
        lineEditRemarkInfo->setMaximumSize(QSize(200, 16777215));
        lineEditRemarkInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_14->addWidget(lineEditRemarkInfo);


        verticalLayout_5->addLayout(horizontalLayout_14);

        commandLinkButtonLog = new QCommandLinkButton(tabCostInfo);
        commandLinkButtonLog->setObjectName(QStringLiteral("commandLinkButtonLog"));

        verticalLayout_5->addWidget(commandLinkButtonLog);

        frame = new QFrame(tabCostInfo);
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
        commandLinkButtonEdit->setMaximumSize(QSize(160, 16777215));
        commandLinkButtonEdit->setStyleSheet(QStringLiteral("background-color: transparent;"));

        horizontalLayout_8->addWidget(commandLinkButtonEdit);


        verticalLayout_8->addLayout(horizontalLayout_8);


        verticalLayout_5->addWidget(frame);

        tableWidgetCostInfo = new QTableWidget(tabCostInfo);
        if (tableWidgetCostInfo->columnCount() < 5)
            tableWidgetCostInfo->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetCostInfo->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidgetCostInfo->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidgetCostInfo->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidgetCostInfo->setHorizontalHeaderItem(3, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidgetCostInfo->setHorizontalHeaderItem(4, __qtablewidgetitem8);
        tableWidgetCostInfo->setObjectName(QStringLiteral("tableWidgetCostInfo"));

        verticalLayout_5->addWidget(tableWidgetCostInfo);

        pushButtonAddCostMatInfo = new QPushButton(tabCostInfo);
        pushButtonAddCostMatInfo->setObjectName(QStringLiteral("pushButtonAddCostMatInfo"));
        pushButtonAddCostMatInfo->setMinimumSize(QSize(0, 0));
        pushButtonAddCostMatInfo->setIcon(icon2);

        verticalLayout_5->addWidget(pushButtonAddCostMatInfo);

        pushButtonConfirmInfo = new QPushButton(tabCostInfo);
        pushButtonConfirmInfo->setObjectName(QStringLiteral("pushButtonConfirmInfo"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/image/image/\347\241\256\350\256\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonConfirmInfo->setIcon(icon5);

        verticalLayout_5->addWidget(pushButtonConfirmInfo);

        pushButtonSubmitInfo = new QPushButton(tabCostInfo);
        pushButtonSubmitInfo->setObjectName(QStringLiteral("pushButtonSubmitInfo"));
        pushButtonSubmitInfo->setIcon(icon5);

        verticalLayout_5->addWidget(pushButtonSubmitInfo);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        pushButtonSaveInfo = new QPushButton(tabCostInfo);
        pushButtonSaveInfo->setObjectName(QStringLiteral("pushButtonSaveInfo"));
        pushButtonSaveInfo->setIcon(icon3);

        horizontalLayout_17->addWidget(pushButtonSaveInfo);

        pushButtonDeleteInfo = new QPushButton(tabCostInfo);
        pushButtonDeleteInfo->setObjectName(QStringLiteral("pushButtonDeleteInfo"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/image/image/\345\210\240 \351\231\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonDeleteInfo->setIcon(icon6);

        horizontalLayout_17->addWidget(pushButtonDeleteInfo);

        pushButtonCancelInfo = new QPushButton(tabCostInfo);
        pushButtonCancelInfo->setObjectName(QStringLiteral("pushButtonCancelInfo"));
        pushButtonCancelInfo->setIcon(icon4);

        horizontalLayout_17->addWidget(pushButtonCancelInfo);


        verticalLayout_5->addLayout(horizontalLayout_17);

        tabWidgetCost->addTab(tabCostInfo, QString());

        horizontalLayout_2->addWidget(tabWidgetCost);

        horizontalLayout_2->setStretch(0, 6);
        horizontalLayout_2->setStretch(1, 4);

        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(CostAdjustment);

        tabWidgetCost->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(CostAdjustment);
    } // setupUi

    void retranslateUi(QWidget *CostAdjustment)
    {
        CostAdjustment->setWindowTitle(QApplication::translate("CostAdjustment", "Form", 0));
        labelState->setText(QApplication::translate("CostAdjustment", " \347\212\266\346\200\201\357\274\232", 0));
        labelDate->setText(QApplication::translate("CostAdjustment", " \350\260\203\344\273\267\346\227\245\346\234\237\357\274\232", 0));
        pushButtonSelect->setText(QApplication::translate("CostAdjustment", "\346\237\245\350\257\242", 0));
        pushButtonSee->setText(QApplication::translate("CostAdjustment", "\346\210\220\346\234\254\344\273\267\344\270\200\350\247\210", 0));
        pushButtonAdd->setText(QApplication::translate("CostAdjustment", "\346\267\273\345\212\240", 0));
        labelSize->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidgetCost->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("CostAdjustment", "\350\260\203\344\273\267\345\215\225\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetCost->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("CostAdjustment", "\350\260\203\344\273\267\345\216\237\346\226\231", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetCost->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("CostAdjustment", "\350\260\203\344\273\267\346\227\245\346\234\237", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetCost->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("CostAdjustment", "\347\212\266\346\200\201", 0));
        label_7->setText(QApplication::translate("CostAdjustment", " \345\237\272\346\234\254\344\277\241\346\201\257", 0));
        label_4->setText(QApplication::translate("CostAdjustment", "\345\244\207\346\263\250\357\274\232", 0));
        lineEditRemark->setPlaceholderText(QApplication::translate("CostAdjustment", "\345\217\257\344\270\215\345\241\253", 0));
        label_8->setText(QApplication::translate("CostAdjustment", " \350\260\203\344\273\267\345\216\237\346\226\231", 0));
        pushButtonAddAdjustMat->setText(QApplication::translate("CostAdjustment", " \346\267\273\345\212\240\350\260\203\346\225\264\345\216\237\346\226\231...", 0));
        pushButtonSave->setText(QApplication::translate("CostAdjustment", "  \344\277\235\345\255\230", 0));
        pushButtonCancel->setText(QApplication::translate("CostAdjustment", " \345\217\226\346\266\210", 0));
        tabWidgetCost->setTabText(tabWidgetCost->indexOf(tabAddCost), QApplication::translate("CostAdjustment", "\346\267\273\345\212\240\346\210\220\346\234\254\350\260\203\344\273\267\345\215\225", 0));
        label_18->setText(QApplication::translate("CostAdjustment", " \345\237\272\346\234\254\344\277\241\346\201\257", 0));
        label_19->setText(QApplication::translate("CostAdjustment", "\350\260\203\344\273\267\345\215\225\345\217\267\357\274\232", 0));
        label_16->setText(QApplication::translate("CostAdjustment", "\347\212\266\346\200\201\357\274\232", 0));
        label_17->setText(QApplication::translate("CostAdjustment", "\345\244\207\346\263\250\357\274\232", 0));
        lineEditRemarkInfo->setPlaceholderText(QApplication::translate("CostAdjustment", "\345\217\257\344\270\215\345\241\253", 0));
        commandLinkButtonLog->setText(QApplication::translate("CostAdjustment", " \345\244\204\347\220\206\350\256\260\345\275\225", 0));
        label_5->setText(QApplication::translate("CostAdjustment", " \350\260\203\344\273\267\345\216\237\346\226\231", 0));
        labelTotalCount->setText(QString());
        commandLinkButtonEdit->setText(QApplication::translate("CostAdjustment", " \347\274\226\350\276\221\350\260\203\344\273\267\345\216\237\346\226\231", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetCostInfo->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("CostAdjustment", "\345\216\237\346\226\231\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetCostInfo->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("CostAdjustment", "\346\235\241\345\275\242\347\240\201", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetCostInfo->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("CostAdjustment", "\350\260\203\344\273\267\345\211\215\346\210\220\346\234\254\344\273\267", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidgetCostInfo->horizontalHeaderItem(3);
        ___qtablewidgetitem7->setText(QApplication::translate("CostAdjustment", "\350\260\203\344\273\267\345\220\216\346\210\220\346\234\254\344\273\267", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidgetCostInfo->horizontalHeaderItem(4);
        ___qtablewidgetitem8->setText(QApplication::translate("CostAdjustment", "\350\256\241\344\273\267\345\215\225\344\275\215", 0));
        pushButtonAddCostMatInfo->setText(QApplication::translate("CostAdjustment", " \346\267\273\345\212\240\350\260\203\344\273\267\345\216\237\346\226\231", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonConfirmInfo->setToolTip(QApplication::translate("CostAdjustment", "\345\274\200\345\247\213\347\241\256\350\256\244\351\207\207\350\264\255\345\216\237\346\226\231", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        pushButtonConfirmInfo->setWhatsThis(QApplication::translate("CostAdjustment", "\345\274\200\345\247\213\347\241\256\350\256\244\351\207\207\350\264\255\345\216\237\346\226\231", 0));
#endif // QT_NO_WHATSTHIS
        pushButtonConfirmInfo->setText(QApplication::translate("CostAdjustment", " \347\241\256\350\256\244\350\260\203\344\273\267", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonSubmitInfo->setToolTip(QApplication::translate("CostAdjustment", "\345\274\200\345\247\213\347\241\256\350\256\244\351\207\207\350\264\255\345\216\237\346\226\231", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        pushButtonSubmitInfo->setWhatsThis(QApplication::translate("CostAdjustment", "\345\274\200\345\247\213\347\241\256\350\256\244\351\207\207\350\264\255\345\216\237\346\226\231", 0));
#endif // QT_NO_WHATSTHIS
        pushButtonSubmitInfo->setText(QApplication::translate("CostAdjustment", " \346\217\220\344\272\244", 0));
        pushButtonSaveInfo->setText(QApplication::translate("CostAdjustment", " \344\277\235\345\255\230", 0));
        pushButtonDeleteInfo->setText(QApplication::translate("CostAdjustment", " \345\210\240\351\231\244", 0));
        pushButtonCancelInfo->setText(QApplication::translate("CostAdjustment", " \345\217\226\346\266\210", 0));
        tabWidgetCost->setTabText(tabWidgetCost->indexOf(tabCostInfo), QApplication::translate("CostAdjustment", "\346\210\220\346\234\254\350\260\203\344\273\267\345\215\225\350\257\246\346\203\205", 0));
    } // retranslateUi

};

namespace Ui {
    class CostAdjustment: public Ui_CostAdjustment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COSTADJUSTMENT_H
