/********************************************************************************
** Form generated from reading UI file 'purchasesafe.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PURCHASESAFE_H
#define UI_PURCHASESAFE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PurchaseSafe
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QWidget *widgetControl;
    QPushButton *pushButtonAllSelect;
    QPushButton *pushButtonNoSelect;
    QPushButton *pushButtonSure;
    QLabel *labelSize;
    QLabel *labelContents;
    QTableWidget *tableWidget;
    QTabWidget *tabWidgetSuggestPur;
    QWidget *tabRetInfo;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_18;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_19;
    QLineEdit *lineEditMatName;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_25;
    QLineEdit *lineEditBarCode;
    QHBoxLayout *horizontalLayout_29;
    QLabel *label_34;
    QLineEdit *lineEditSpec;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_24;
    QLineEdit *lineEditUnit;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_23;
    QLineEdit *lineEditSafeTop;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_26;
    QLineEdit *lineEditSafeLower;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_22;
    QLineEdit *lineEditNowInv;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_21;
    QLineEdit *lineEditPurNumber;
    QHBoxLayout *horizontalLayout_31;
    QLabel *label_36;
    QLineEdit *lineEditStorageNumber;
    QHBoxLayout *horizontalLayout_30;
    QLabel *label_35;
    QLineEdit *lineEditSuggestNumber;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_20;
    QLineEdit *lineEditDefaultSupplier;

    void setupUi(QWidget *PurchaseSafe)
    {
        if (PurchaseSafe->objectName().isEmpty())
            PurchaseSafe->setObjectName(QStringLiteral("PurchaseSafe"));
        PurchaseSafe->resize(410, 390);
        PurchaseSafe->setStyleSheet(QLatin1String("QComboBox \n"
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
"spacing:2px;\n"
"padding: 0px 0px;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(PurchaseSafe);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, -1, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 0, -1, -1);
        widgetControl = new QWidget(PurchaseSafe);
        widgetControl->setObjectName(QStringLiteral("widgetControl"));
        widgetControl->setMinimumSize(QSize(0, 20));
        pushButtonAllSelect = new QPushButton(widgetControl);
        pushButtonAllSelect->setObjectName(QStringLiteral("pushButtonAllSelect"));
        pushButtonAllSelect->setGeometry(QRect(15, 14, 64, 16));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\345\205\250\351\200\211.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonAllSelect->setIcon(icon);
        pushButtonNoSelect = new QPushButton(widgetControl);
        pushButtonNoSelect->setObjectName(QStringLiteral("pushButtonNoSelect"));
        pushButtonNoSelect->setGeometry(QRect(85, 14, 63, 16));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/image/\345\205\250\344\270\215\351\200\211.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonNoSelect->setIcon(icon1);
        pushButtonSure = new QPushButton(widgetControl);
        pushButtonSure->setObjectName(QStringLiteral("pushButtonSure"));
        pushButtonSure->setGeometry(QRect(154, 14, 64, 16));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/image/\347\241\256\350\256\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSure->setIcon(icon2);
        labelSize = new QLabel(widgetControl);
        labelSize->setObjectName(QStringLiteral("labelSize"));
        labelSize->setGeometry(QRect(230, 10, 16, 18));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        labelSize->setFont(font);
        labelContents = new QLabel(widgetControl);
        labelContents->setObjectName(QStringLiteral("labelContents"));
        labelContents->setGeometry(QRect(251, 10, 51, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        labelContents->setFont(font1);
        labelContents->setStyleSheet(QStringLiteral("color: rgb(170, 0, 0);"));
        labelContents->setScaledContents(true);
        labelContents->setWordWrap(false);

        verticalLayout->addWidget(widgetControl);

        tableWidget = new QTableWidget(PurchaseSafe);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);


        horizontalLayout_2->addLayout(verticalLayout);

        tabWidgetSuggestPur = new QTabWidget(PurchaseSafe);
        tabWidgetSuggestPur->setObjectName(QStringLiteral("tabWidgetSuggestPur"));
        tabRetInfo = new QWidget();
        tabRetInfo->setObjectName(QStringLiteral("tabRetInfo"));
        verticalLayout_5 = new QVBoxLayout(tabRetInfo);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(3, 0, 3, 0);
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

        lineEditMatName = new QLineEdit(tabRetInfo);
        lineEditMatName->setObjectName(QStringLiteral("lineEditMatName"));
        lineEditMatName->setEnabled(false);
        lineEditMatName->setMinimumSize(QSize(200, 0));
        lineEditMatName->setMaximumSize(QSize(200, 16777215));
        lineEditMatName->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_15->addWidget(lineEditMatName);


        verticalLayout_5->addLayout(horizontalLayout_15);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        label_25 = new QLabel(tabRetInfo);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setFont(font1);

        horizontalLayout_21->addWidget(label_25);

        lineEditBarCode = new QLineEdit(tabRetInfo);
        lineEditBarCode->setObjectName(QStringLiteral("lineEditBarCode"));
        lineEditBarCode->setEnabled(false);
        lineEditBarCode->setMinimumSize(QSize(200, 0));
        lineEditBarCode->setMaximumSize(QSize(200, 16777215));
        lineEditBarCode->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_21->addWidget(lineEditBarCode);


        verticalLayout_5->addLayout(horizontalLayout_21);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setObjectName(QStringLiteral("horizontalLayout_29"));
        label_34 = new QLabel(tabRetInfo);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setFont(font1);

        horizontalLayout_29->addWidget(label_34);

        lineEditSpec = new QLineEdit(tabRetInfo);
        lineEditSpec->setObjectName(QStringLiteral("lineEditSpec"));
        lineEditSpec->setEnabled(false);
        lineEditSpec->setMinimumSize(QSize(200, 0));
        lineEditSpec->setMaximumSize(QSize(200, 16777215));
        lineEditSpec->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_29->addWidget(lineEditSpec);


        verticalLayout_5->addLayout(horizontalLayout_29);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        label_24 = new QLabel(tabRetInfo);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setFont(font1);

        horizontalLayout_20->addWidget(label_24);

        lineEditUnit = new QLineEdit(tabRetInfo);
        lineEditUnit->setObjectName(QStringLiteral("lineEditUnit"));
        lineEditUnit->setEnabled(false);
        lineEditUnit->setMinimumSize(QSize(200, 0));
        lineEditUnit->setMaximumSize(QSize(200, 16777215));
        lineEditUnit->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_20->addWidget(lineEditUnit);


        verticalLayout_5->addLayout(horizontalLayout_20);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        label_23 = new QLabel(tabRetInfo);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setFont(font1);

        horizontalLayout_19->addWidget(label_23);

        lineEditSafeTop = new QLineEdit(tabRetInfo);
        lineEditSafeTop->setObjectName(QStringLiteral("lineEditSafeTop"));
        lineEditSafeTop->setEnabled(false);
        lineEditSafeTop->setMinimumSize(QSize(200, 0));
        lineEditSafeTop->setMaximumSize(QSize(200, 16777215));
        lineEditSafeTop->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_19->addWidget(lineEditSafeTop);


        verticalLayout_5->addLayout(horizontalLayout_19);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        label_26 = new QLabel(tabRetInfo);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setFont(font1);

        horizontalLayout_22->addWidget(label_26);

        lineEditSafeLower = new QLineEdit(tabRetInfo);
        lineEditSafeLower->setObjectName(QStringLiteral("lineEditSafeLower"));
        lineEditSafeLower->setEnabled(false);
        lineEditSafeLower->setMinimumSize(QSize(200, 0));
        lineEditSafeLower->setMaximumSize(QSize(200, 16777215));
        lineEditSafeLower->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_22->addWidget(lineEditSafeLower);


        verticalLayout_5->addLayout(horizontalLayout_22);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        label_22 = new QLabel(tabRetInfo);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setFont(font1);

        horizontalLayout_18->addWidget(label_22);

        lineEditNowInv = new QLineEdit(tabRetInfo);
        lineEditNowInv->setObjectName(QStringLiteral("lineEditNowInv"));
        lineEditNowInv->setEnabled(false);
        lineEditNowInv->setMinimumSize(QSize(200, 0));
        lineEditNowInv->setMaximumSize(QSize(200, 16777215));
        lineEditNowInv->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_18->addWidget(lineEditNowInv);


        verticalLayout_5->addLayout(horizontalLayout_18);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        label_21 = new QLabel(tabRetInfo);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setFont(font1);

        horizontalLayout_17->addWidget(label_21);

        lineEditPurNumber = new QLineEdit(tabRetInfo);
        lineEditPurNumber->setObjectName(QStringLiteral("lineEditPurNumber"));
        lineEditPurNumber->setEnabled(false);
        lineEditPurNumber->setMinimumSize(QSize(200, 0));
        lineEditPurNumber->setMaximumSize(QSize(200, 16777215));
        lineEditPurNumber->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_17->addWidget(lineEditPurNumber);


        verticalLayout_5->addLayout(horizontalLayout_17);

        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setObjectName(QStringLiteral("horizontalLayout_31"));
        label_36 = new QLabel(tabRetInfo);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setFont(font1);

        horizontalLayout_31->addWidget(label_36);

        lineEditStorageNumber = new QLineEdit(tabRetInfo);
        lineEditStorageNumber->setObjectName(QStringLiteral("lineEditStorageNumber"));
        lineEditStorageNumber->setEnabled(false);
        lineEditStorageNumber->setMinimumSize(QSize(200, 0));
        lineEditStorageNumber->setMaximumSize(QSize(200, 16777215));
        lineEditStorageNumber->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_31->addWidget(lineEditStorageNumber);


        verticalLayout_5->addLayout(horizontalLayout_31);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setObjectName(QStringLiteral("horizontalLayout_30"));
        label_35 = new QLabel(tabRetInfo);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setFont(font1);

        horizontalLayout_30->addWidget(label_35);

        lineEditSuggestNumber = new QLineEdit(tabRetInfo);
        lineEditSuggestNumber->setObjectName(QStringLiteral("lineEditSuggestNumber"));
        lineEditSuggestNumber->setEnabled(false);
        lineEditSuggestNumber->setMinimumSize(QSize(200, 0));
        lineEditSuggestNumber->setMaximumSize(QSize(200, 16777215));
        lineEditSuggestNumber->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_30->addWidget(lineEditSuggestNumber);


        verticalLayout_5->addLayout(horizontalLayout_30);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_20 = new QLabel(tabRetInfo);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setFont(font1);

        horizontalLayout_16->addWidget(label_20);

        lineEditDefaultSupplier = new QLineEdit(tabRetInfo);
        lineEditDefaultSupplier->setObjectName(QStringLiteral("lineEditDefaultSupplier"));
        lineEditDefaultSupplier->setEnabled(false);
        lineEditDefaultSupplier->setMinimumSize(QSize(200, 0));
        lineEditDefaultSupplier->setMaximumSize(QSize(200, 16777215));
        lineEditDefaultSupplier->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_16->addWidget(lineEditDefaultSupplier);


        verticalLayout_5->addLayout(horizontalLayout_16);

        tabWidgetSuggestPur->addTab(tabRetInfo, QString());

        horizontalLayout_2->addWidget(tabWidgetSuggestPur);

        horizontalLayout_2->setStretch(0, 6);
        horizontalLayout_2->setStretch(1, 4);

        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(PurchaseSafe);

        tabWidgetSuggestPur->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PurchaseSafe);
    } // setupUi

    void retranslateUi(QWidget *PurchaseSafe)
    {
        PurchaseSafe->setWindowTitle(QApplication::translate("PurchaseSafe", "Form", 0));
        pushButtonAllSelect->setText(QApplication::translate("PurchaseSafe", " \345\205\250\351\200\211", 0));
        pushButtonNoSelect->setText(QApplication::translate("PurchaseSafe", " \345\205\250\344\270\215\351\200\211", 0));
        pushButtonSure->setText(QApplication::translate("PurchaseSafe", " \347\241\256\350\256\244\351\207\207\350\264\255", 0));
        labelSize->setText(QString());
        labelContents->setText(QApplication::translate("PurchaseSafe", "\346\240\271\346\215\256\345\272\223\345\255\230\344\270\212\344\270\213\351\231\220\345\200\274\357\274\214\347\233\256\345\211\215\346\262\241\346\234\211\351\234\200\350\246\201\351\207\207\350\264\255\347\232\204\345\216\237\346\226\231", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("PurchaseSafe", "\345\216\237\346\226\231\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("PurchaseSafe", "\345\273\272\350\256\256\351\207\207\350\264\255\351\207\217", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("PurchaseSafe", "\345\215\225\344\275\215", 0));
        label_18->setText(QApplication::translate("PurchaseSafe", " \345\237\272\346\234\254\344\277\241\346\201\257", 0));
        label_19->setText(QApplication::translate("PurchaseSafe", "\345\216\237\346\226\231\345\220\215\347\247\260\357\274\232", 0));
        label_25->setText(QApplication::translate("PurchaseSafe", "\346\235\241\345\275\242\347\240\201\357\274\232", 0));
        label_34->setText(QApplication::translate("PurchaseSafe", "\350\247\204\346\240\274\357\274\232", 0));
        label_24->setText(QApplication::translate("PurchaseSafe", "\345\215\225\344\275\215\357\274\232", 0));
        label_23->setText(QApplication::translate("PurchaseSafe", "\345\256\211\345\205\250\345\272\223\345\255\230\344\270\212\351\231\220\357\274\232", 0));
        label_26->setText(QApplication::translate("PurchaseSafe", "\345\256\211\345\205\250\345\272\223\345\255\230\344\270\213\351\231\220\357\274\232", 0));
        label_22->setText(QApplication::translate("PurchaseSafe", "\347\216\260\346\234\211\345\272\223\345\255\230\357\274\232", 0));
        label_21->setText(QApplication::translate("PurchaseSafe", "\351\207\207\350\264\255\344\270\255\346\225\260\351\207\217\357\274\232", 0));
        label_36->setText(QApplication::translate("PurchaseSafe", "\345\276\205\345\205\245\345\272\223\346\225\260\351\207\217\357\274\232", 0));
        label_35->setText(QApplication::translate("PurchaseSafe", "\345\273\272\350\256\256\351\207\207\350\264\255\351\207\217\357\274\232", 0));
        label_20->setText(QApplication::translate("PurchaseSafe", "\351\273\230\350\256\244\344\276\233\345\272\224\345\225\206\357\274\232", 0));
        tabWidgetSuggestPur->setTabText(tabWidgetSuggestPur->indexOf(tabRetInfo), QApplication::translate("PurchaseSafe", "\345\273\272\350\256\256\351\207\207\350\264\255\351\207\217\350\257\246\346\203\205", 0));
    } // retranslateUi

};

namespace Ui {
    class PurchaseSafe: public Ui_PurchaseSafe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PURCHASESAFE_H
