/********************************************************************************
** Form generated from reading UI file 'accountmanage.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTMANAGE_H
#define UI_ACCOUNTMANAGE_H

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

class Ui_AccountManage
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_3;
    QWidget *widgetControl;
    QPushButton *pushButtonSelect;
    QLabel *labelSup;
    QComboBox *comboBoxState;
    QLabel *labelState;
    QComboBox *comboBoxSupplier;
    QLabel *labelType;
    QComboBox *comboBoxType;
    QLabel *labelDateType;
    QComboBox *comboBoxTimeType;
    QLabel *labelBeginTime;
    QLabel *labelEndTime;
    QDateEdit *dateEditEndTime;
    QDateEdit *dateEditStartTime;
    QPushButton *pushButtonExport;
    QTableWidget *tableWidgetAccount;
    QTabWidget *tabWidgetAccount;
    QWidget *tabAccountInfo;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_18;
    QHBoxLayout *horizontalLayout_15;
    QLabel *labelNumber;
    QLineEdit *lineEditNumberInfo;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_20;
    QLineEdit *lineEditStateInfo;
    QHBoxLayout *horizontalLayout_11;
    QLabel *labelSupplier;
    QLineEdit *lineEditSupplierInfo;
    QHBoxLayout *horizontalLayout_19;
    QLabel *labelWareHouse;
    QLineEdit *lineEditWareHouseInfo;
    QHBoxLayout *horizontalLayout_12;
    QLabel *labelDate;
    QLineEdit *lineEditDate;
    QHBoxLayout *horizontalLayout_18;
    QLabel *labelTime;
    QLineEdit *lineEditTime;
    QHBoxLayout *horizontalLayout_14;
    QLabel *labelRemark;
    QLineEdit *lineEditRemarkInfo;
    QCommandLinkButton *commandLinkButtonLog;
    QLabel *labelMaterial;
    QTableWidget *tableWidgetInfo;
    QFrame *frame;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_8;
    QLabel *labelTotalCount;
    QLabel *labelMoney;
    QSpacerItem *horizontalSpacer_8;
    QCommandLinkButton *commandLinkButtonSure;
    QHBoxLayout *horizontalLayout_17;

    void setupUi(QWidget *AccountManage)
    {
        if (AccountManage->objectName().isEmpty())
            AccountManage->setObjectName(QStringLiteral("AccountManage"));
        AccountManage->resize(463, 510);
        AccountManage->setStyleSheet(QLatin1String("QPushButton:hover\n"
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
        verticalLayout_2 = new QVBoxLayout(AccountManage);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, -1, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, -1, 9);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        widgetControl = new QWidget(AccountManage);
        widgetControl->setObjectName(QStringLiteral("widgetControl"));
        widgetControl->setMinimumSize(QSize(0, 20));
        pushButtonSelect = new QPushButton(widgetControl);
        pushButtonSelect->setObjectName(QStringLiteral("pushButtonSelect"));
        pushButtonSelect->setGeometry(QRect(1266, 10, 80, 30));
        pushButtonSelect->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\346\237\245\350\257\242.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSelect->setIcon(icon);
        labelSup = new QLabel(widgetControl);
        labelSup->setObjectName(QStringLiteral("labelSup"));
        labelSup->setGeometry(QRect(116, 12, 54, 16));
        comboBoxState = new QComboBox(widgetControl);
        comboBoxState->setObjectName(QStringLiteral("comboBoxState"));
        comboBoxState->setGeometry(QRect(70, 30, 60, 22));
        comboBoxState->setMinimumSize(QSize(0, 0));
        comboBoxState->setMaximumSize(QSize(80, 16777215));
        labelState = new QLabel(widgetControl);
        labelState->setObjectName(QStringLiteral("labelState"));
        labelState->setGeometry(QRect(0, 30, 66, 16));
        comboBoxSupplier = new QComboBox(widgetControl);
        comboBoxSupplier->setObjectName(QStringLiteral("comboBoxSupplier"));
        comboBoxSupplier->setGeometry(QRect(174, 12, 60, 22));
        comboBoxSupplier->setMinimumSize(QSize(0, 0));
        comboBoxSupplier->setMaximumSize(QSize(80, 16777215));
        labelType = new QLabel(widgetControl);
        labelType->setObjectName(QStringLiteral("labelType"));
        labelType->setGeometry(QRect(238, 12, 66, 16));
        comboBoxType = new QComboBox(widgetControl);
        comboBoxType->setObjectName(QStringLiteral("comboBoxType"));
        comboBoxType->setGeometry(QRect(308, 12, 60, 22));
        comboBoxType->setMinimumSize(QSize(0, 0));
        comboBoxType->setMaximumSize(QSize(80, 16777215));
        labelDateType = new QLabel(widgetControl);
        labelDateType->setObjectName(QStringLiteral("labelDateType"));
        labelDateType->setGeometry(QRect(390, 12, 66, 16));
        comboBoxTimeType = new QComboBox(widgetControl);
        comboBoxTimeType->setObjectName(QStringLiteral("comboBoxTimeType"));
        comboBoxTimeType->setGeometry(QRect(440, 12, 70, 22));
        comboBoxTimeType->setMinimumSize(QSize(0, 0));
        comboBoxTimeType->setMaximumSize(QSize(80, 16777215));
        labelBeginTime = new QLabel(widgetControl);
        labelBeginTime->setObjectName(QStringLiteral("labelBeginTime"));
        labelBeginTime->setGeometry(QRect(510, 12, 66, 16));
        labelEndTime = new QLabel(widgetControl);
        labelEndTime->setObjectName(QStringLiteral("labelEndTime"));
        labelEndTime->setGeometry(QRect(690, 20, 66, 16));
        dateEditEndTime = new QDateEdit(widgetControl);
        dateEditEndTime->setObjectName(QStringLiteral("dateEditEndTime"));
        dateEditEndTime->setGeometry(QRect(780, 20, 90, 22));
        dateEditEndTime->setMinimumSize(QSize(0, 0));
        dateEditStartTime = new QDateEdit(widgetControl);
        dateEditStartTime->setObjectName(QStringLiteral("dateEditStartTime"));
        dateEditStartTime->setGeometry(QRect(580, 12, 90, 22));
        dateEditStartTime->setMinimumSize(QSize(0, 0));
        pushButtonExport = new QPushButton(widgetControl);
        pushButtonExport->setObjectName(QStringLiteral("pushButtonExport"));
        pushButtonExport->setGeometry(QRect(20, 10, 80, 20));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/export.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonExport->setIcon(icon1);

        verticalLayout_3->addWidget(widgetControl);


        verticalLayout->addLayout(verticalLayout_3);

        tableWidgetAccount = new QTableWidget(AccountManage);
        if (tableWidgetAccount->columnCount() < 5)
            tableWidgetAccount->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetAccount->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetAccount->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetAccount->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetAccount->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetAccount->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidgetAccount->setObjectName(QStringLiteral("tableWidgetAccount"));

        verticalLayout->addWidget(tableWidgetAccount);


        horizontalLayout_2->addLayout(verticalLayout);

        tabWidgetAccount = new QTabWidget(AccountManage);
        tabWidgetAccount->setObjectName(QStringLiteral("tabWidgetAccount"));
        tabAccountInfo = new QWidget();
        tabAccountInfo->setObjectName(QStringLiteral("tabAccountInfo"));
        verticalLayout_5 = new QVBoxLayout(tabAccountInfo);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(2, 0, 2, 0);
        label_18 = new QLabel(tabAccountInfo);
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
        labelNumber = new QLabel(tabAccountInfo);
        labelNumber->setObjectName(QStringLiteral("labelNumber"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        labelNumber->setFont(font);

        horizontalLayout_15->addWidget(labelNumber);

        lineEditNumberInfo = new QLineEdit(tabAccountInfo);
        lineEditNumberInfo->setObjectName(QStringLiteral("lineEditNumberInfo"));
        lineEditNumberInfo->setEnabled(false);
        lineEditNumberInfo->setMinimumSize(QSize(200, 0));
        lineEditNumberInfo->setMaximumSize(QSize(200, 16777215));
        lineEditNumberInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_15->addWidget(lineEditNumberInfo);


        verticalLayout_5->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_20 = new QLabel(tabAccountInfo);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setFont(font);

        horizontalLayout_16->addWidget(label_20);

        lineEditStateInfo = new QLineEdit(tabAccountInfo);
        lineEditStateInfo->setObjectName(QStringLiteral("lineEditStateInfo"));
        lineEditStateInfo->setEnabled(false);
        lineEditStateInfo->setMinimumSize(QSize(200, 0));
        lineEditStateInfo->setMaximumSize(QSize(200, 16777215));
        lineEditStateInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_16->addWidget(lineEditStateInfo);


        verticalLayout_5->addLayout(horizontalLayout_16);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        labelSupplier = new QLabel(tabAccountInfo);
        labelSupplier->setObjectName(QStringLiteral("labelSupplier"));
        labelSupplier->setFont(font);

        horizontalLayout_11->addWidget(labelSupplier);

        lineEditSupplierInfo = new QLineEdit(tabAccountInfo);
        lineEditSupplierInfo->setObjectName(QStringLiteral("lineEditSupplierInfo"));
        lineEditSupplierInfo->setEnabled(false);
        lineEditSupplierInfo->setMinimumSize(QSize(200, 0));
        lineEditSupplierInfo->setMaximumSize(QSize(200, 16777215));
        lineEditSupplierInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_11->addWidget(lineEditSupplierInfo);


        verticalLayout_5->addLayout(horizontalLayout_11);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        labelWareHouse = new QLabel(tabAccountInfo);
        labelWareHouse->setObjectName(QStringLiteral("labelWareHouse"));
        labelWareHouse->setFont(font);

        horizontalLayout_19->addWidget(labelWareHouse);

        lineEditWareHouseInfo = new QLineEdit(tabAccountInfo);
        lineEditWareHouseInfo->setObjectName(QStringLiteral("lineEditWareHouseInfo"));
        lineEditWareHouseInfo->setEnabled(false);
        lineEditWareHouseInfo->setMinimumSize(QSize(200, 0));
        lineEditWareHouseInfo->setMaximumSize(QSize(200, 16777215));
        lineEditWareHouseInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_19->addWidget(lineEditWareHouseInfo);


        verticalLayout_5->addLayout(horizontalLayout_19);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        labelDate = new QLabel(tabAccountInfo);
        labelDate->setObjectName(QStringLiteral("labelDate"));
        labelDate->setFont(font);

        horizontalLayout_12->addWidget(labelDate);

        lineEditDate = new QLineEdit(tabAccountInfo);
        lineEditDate->setObjectName(QStringLiteral("lineEditDate"));
        lineEditDate->setEnabled(false);
        lineEditDate->setMinimumSize(QSize(200, 0));
        lineEditDate->setMaximumSize(QSize(200, 16777215));
        lineEditDate->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_12->addWidget(lineEditDate);


        verticalLayout_5->addLayout(horizontalLayout_12);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        labelTime = new QLabel(tabAccountInfo);
        labelTime->setObjectName(QStringLiteral("labelTime"));
        labelTime->setFont(font);

        horizontalLayout_18->addWidget(labelTime);

        lineEditTime = new QLineEdit(tabAccountInfo);
        lineEditTime->setObjectName(QStringLiteral("lineEditTime"));
        lineEditTime->setEnabled(false);
        lineEditTime->setMinimumSize(QSize(200, 0));
        lineEditTime->setMaximumSize(QSize(200, 16777215));
        lineEditTime->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_18->addWidget(lineEditTime);


        verticalLayout_5->addLayout(horizontalLayout_18);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        labelRemark = new QLabel(tabAccountInfo);
        labelRemark->setObjectName(QStringLiteral("labelRemark"));
        labelRemark->setFont(font);

        horizontalLayout_14->addWidget(labelRemark);

        lineEditRemarkInfo = new QLineEdit(tabAccountInfo);
        lineEditRemarkInfo->setObjectName(QStringLiteral("lineEditRemarkInfo"));
        lineEditRemarkInfo->setEnabled(false);
        lineEditRemarkInfo->setMinimumSize(QSize(200, 0));
        lineEditRemarkInfo->setMaximumSize(QSize(200, 16777215));
        lineEditRemarkInfo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_14->addWidget(lineEditRemarkInfo);


        verticalLayout_5->addLayout(horizontalLayout_14);

        commandLinkButtonLog = new QCommandLinkButton(tabAccountInfo);
        commandLinkButtonLog->setObjectName(QStringLiteral("commandLinkButtonLog"));

        verticalLayout_5->addWidget(commandLinkButtonLog);

        labelMaterial = new QLabel(tabAccountInfo);
        labelMaterial->setObjectName(QStringLiteral("labelMaterial"));
        labelMaterial->setMinimumSize(QSize(0, 30));
        labelMaterial->setMaximumSize(QSize(16777215, 30));
        labelMaterial->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"background-color:rgb(180, 85, 100);\n"
"color:white;\n"
"font-size:14px;\n"
"font-weight:bold;\n"
"}"));
        labelMaterial->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_5->addWidget(labelMaterial);

        tableWidgetInfo = new QTableWidget(tabAccountInfo);
        if (tableWidgetInfo->columnCount() < 4)
            tableWidgetInfo->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidgetInfo->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidgetInfo->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidgetInfo->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidgetInfo->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        tableWidgetInfo->setObjectName(QStringLiteral("tableWidgetInfo"));

        verticalLayout_5->addWidget(tableWidgetInfo);

        frame = new QFrame(tabAccountInfo);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(0, 40));
        frame->setMaximumSize(QSize(16777215, 40));
        frame->setStyleSheet(QStringLiteral(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_8 = new QVBoxLayout(frame);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        labelTotalCount = new QLabel(frame);
        labelTotalCount->setObjectName(QStringLiteral("labelTotalCount"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        labelTotalCount->setFont(font1);

        horizontalLayout_8->addWidget(labelTotalCount);

        labelMoney = new QLabel(frame);
        labelMoney->setObjectName(QStringLiteral("labelMoney"));
        labelMoney->setFont(font1);

        horizontalLayout_8->addWidget(labelMoney);

        horizontalSpacer_8 = new QSpacerItem(5, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);

        commandLinkButtonSure = new QCommandLinkButton(frame);
        commandLinkButtonSure->setObjectName(QStringLiteral("commandLinkButtonSure"));
        commandLinkButtonSure->setMaximumSize(QSize(200, 16777215));
        commandLinkButtonSure->setStyleSheet(QStringLiteral(""));

        horizontalLayout_8->addWidget(commandLinkButtonSure);


        verticalLayout_8->addLayout(horizontalLayout_8);


        verticalLayout_5->addWidget(frame);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));

        verticalLayout_5->addLayout(horizontalLayout_17);

        tabWidgetAccount->addTab(tabAccountInfo, QString());

        horizontalLayout_2->addWidget(tabWidgetAccount);

        horizontalLayout_2->setStretch(0, 6);
        horizontalLayout_2->setStretch(1, 4);

        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(AccountManage);

        tabWidgetAccount->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AccountManage);
    } // setupUi

    void retranslateUi(QWidget *AccountManage)
    {
        AccountManage->setWindowTitle(QApplication::translate("AccountManage", "Form", 0));
        pushButtonSelect->setText(QApplication::translate("AccountManage", "\346\237\245\350\257\242\346\212\245\350\241\250", 0));
        labelSup->setText(QApplication::translate("AccountManage", " \344\276\233\345\272\224\345\225\206\357\274\232", 0));
        labelState->setText(QApplication::translate("AccountManage", " \345\215\225\346\215\256\347\212\266\346\200\201\357\274\232", 0));
        labelType->setText(QApplication::translate("AccountManage", " \345\215\225\346\215\256\347\261\273\345\236\213\357\274\232", 0));
        labelDateType->setText(QApplication::translate("AccountManage", " \346\227\245\346\234\237\347\261\273\345\236\213\357\274\232", 0));
        labelBeginTime->setText(QApplication::translate("AccountManage", " \345\274\200\345\247\213\346\227\266\351\227\264\357\274\232", 0));
        labelEndTime->setText(QApplication::translate("AccountManage", " \347\273\223\346\235\237\346\227\266\351\227\264\357\274\232", 0));
        pushButtonExport->setText(QApplication::translate("AccountManage", "\345\257\274\345\207\272", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetAccount->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("AccountManage", "\344\276\233\345\272\224\345\225\206", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetAccount->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("AccountManage", "\345\215\225\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetAccount->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("AccountManage", "\347\261\273\345\236\213", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetAccount->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("AccountManage", "\346\223\215\344\275\234\346\227\266\351\227\264", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetAccount->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("AccountManage", "\347\212\266\346\200\201", 0));
        label_18->setText(QApplication::translate("AccountManage", " \345\237\272\346\234\254\344\277\241\346\201\257", 0));
        labelNumber->setText(QApplication::translate("AccountManage", "\345\215\225\345\217\267\357\274\232", 0));
        label_20->setText(QApplication::translate("AccountManage", "\347\212\266\346\200\201\357\274\232", 0));
        labelSupplier->setText(QApplication::translate("AccountManage", "\344\276\233\345\272\224\345\225\206\357\274\232", 0));
        labelWareHouse->setText(QApplication::translate("AccountManage", "\344\273\223\345\272\223\357\274\232", 0));
        labelDate->setText(QApplication::translate("AccountManage", "\346\227\245\346\234\237\357\274\232", 0));
        labelTime->setText(QApplication::translate("AccountManage", "\346\227\266\351\227\264\357\274\232", 0));
        labelRemark->setText(QApplication::translate("AccountManage", "\345\244\207\346\263\250\357\274\232", 0));
        lineEditRemarkInfo->setPlaceholderText(QString());
        commandLinkButtonLog->setText(QApplication::translate("AccountManage", " \345\244\204\347\220\206\350\256\260\345\275\225", 0));
        labelMaterial->setText(QApplication::translate("AccountManage", "\345\216\237\346\226\231", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetInfo->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("AccountManage", "\345\216\237\346\226\231\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetInfo->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("AccountManage", "\346\235\241\345\275\242\347\240\201", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidgetInfo->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QApplication::translate("AccountManage", "\345\215\225\344\273\267", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidgetInfo->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QApplication::translate("AccountManage", "\346\225\260\351\207\217", 0));
        labelTotalCount->setText(QString());
        labelMoney->setText(QString());
        commandLinkButtonSure->setText(QString());
        tabWidgetAccount->setTabText(tabWidgetAccount->indexOf(tabAccountInfo), QApplication::translate("AccountManage", "\350\256\242\345\215\225\350\257\246\346\203\205", 0));
    } // retranslateUi

};

namespace Ui {
    class AccountManage: public Ui_AccountManage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTMANAGE_H
