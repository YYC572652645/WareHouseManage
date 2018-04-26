/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_logindialog
{
public:
    QPushButton *pushButtonLogin;
    QLabel *label_3;
    QPushButton *pushButtonInfo;
    QLabel *label_5;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEditPassWord;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *comboBoxUserName;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QComboBox *comboBoxShopCode;
    QCheckBox *checkBoxRememberPsd;

    void setupUi(QDialog *logindialog)
    {
        if (logindialog->objectName().isEmpty())
            logindialog->setObjectName(QStringLiteral("logindialog"));
        logindialog->resize(885, 530);
        logindialog->setMinimumSize(QSize(600, 400));
        logindialog->setAutoFillBackground(false);
        logindialog->setStyleSheet(QLatin1String("QDialog\n"
"{\n"
"background-color: rgb(255, 255, 255);\n"
"image: url(:/image/image/loginbackground.png);\n"
"border-radius:5px;\n"
"}\n"
"\n"
"QComboBox\n"
"{\n"
"color:black;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item\n"
"{\n"
"min-height: 40px;\n"
"min-width: 60px;\n"
"}\n"
"QListWidget::item\n"
"{\n"
"height:40px;\n"
"background-color:transparent;\n"
"padding:1px 1px;\n"
"margin:0px 1px;\n"
"border-bottom:1px solid #DBDBDB\n"
"}\n"
"\n"
"QListWidget::item:selected\n"
"{\n"
"    color: white;\n"
"    background-color: #528B8B;\n"
"}\n"
"\n"
"QListWidget::item:checked\n"
"{\n"
"    background-color: darkcyan;\n"
"    border:1px solid #C8C8C8;\n"
"    border-radius:1px;\n"
"    color:black;\n"
"}"));
        pushButtonLogin = new QPushButton(logindialog);
        pushButtonLogin->setObjectName(QStringLiteral("pushButtonLogin"));
        pushButtonLogin->setGeometry(QRect(454, 420, 391, 41));
        pushButtonLogin->setMinimumSize(QSize(170, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(11);
        font.setBold(false);
        font.setWeight(50);
        pushButtonLogin->setFont(font);
        pushButtonLogin->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border-image: url(:/image/image/logincolor.png);\n"
"color: rgb(255, 255, 255);\n"
"border-radius:5px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"color: rgb(255, 255, 255);\n"
"border-radius:5px;\n"
"color:white;\n"
"font-size:16px;\n"
"font-weight:500\n"
"}"));
        label_3 = new QLabel(logindialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 30, 431, 51));
        QFont font1;
        font1.setFamily(QStringLiteral("Aharoni"));
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        label_3->setFont(font1);
        label_3->setStyleSheet(QLatin1String("background-color:transparent;\n"
"color: rgb(0, 130, 200);\n"
"image: none;"));
        label_3->setAlignment(Qt::AlignCenter);
        label_3->setWordWrap(false);
        pushButtonInfo = new QPushButton(logindialog);
        pushButtonInfo->setObjectName(QStringLiteral("pushButtonInfo"));
        pushButtonInfo->setEnabled(true);
        pushButtonInfo->setGeometry(QRect(440, 490, 441, 41));
        pushButtonInfo->setStyleSheet(QLatin1String("background-color: transparent;\n"
"color:red;"));
        label_5 = new QLabel(logindialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 70, 431, 471));
        label_5->setStyleSheet(QStringLiteral("image: url(:/image/image/login.jpg);"));
        layoutWidget = new QWidget(logindialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(450, 270, 408, 42));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(100, 0));
        label->setMaximumSize(QSize(100, 16777215));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        label->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"image: none;"));

        horizontalLayout_2->addWidget(label);

        lineEditPassWord = new QLineEdit(layoutWidget);
        lineEditPassWord->setObjectName(QStringLiteral("lineEditPassWord"));
        lineEditPassWord->setMinimumSize(QSize(300, 40));
        lineEditPassWord->setMaximumSize(QSize(300, 30));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font3.setPointSize(14);
        font3.setBold(false);
        font3.setWeight(50);
        lineEditPassWord->setFont(font3);
        lineEditPassWord->setAutoFillBackground(false);
        lineEditPassWord->setStyleSheet(QStringLiteral("image:none;"));
        lineEditPassWord->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(lineEditPassWord);

        layoutWidget1 = new QWidget(logindialog);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(450, 180, 408, 42));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(100, 0));
        label_2->setMaximumSize(QSize(100, 16777215));
        label_2->setFont(font2);
        label_2->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"image: none;"));

        horizontalLayout->addWidget(label_2);

        comboBoxUserName = new QComboBox(layoutWidget1);
        comboBoxUserName->setObjectName(QStringLiteral("comboBoxUserName"));
        comboBoxUserName->setEnabled(true);
        comboBoxUserName->setMinimumSize(QSize(300, 40));
        comboBoxUserName->setMaximumSize(QSize(300, 30));
        comboBoxUserName->setFont(font3);
        comboBoxUserName->setAutoFillBackground(false);
        comboBoxUserName->setStyleSheet(QStringLiteral(""));
        comboBoxUserName->setEditable(true);

        horizontalLayout->addWidget(comboBoxUserName);

        layoutWidget2 = new QWidget(logindialog);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(450, 90, 411, 42));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(100, 0));
        label_6->setMaximumSize(QSize(100, 16777215));
        label_6->setFont(font2);
        label_6->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"image: none;"));

        horizontalLayout_4->addWidget(label_6);

        comboBoxShopCode = new QComboBox(layoutWidget2);
        comboBoxShopCode->setObjectName(QStringLiteral("comboBoxShopCode"));
        comboBoxShopCode->setMinimumSize(QSize(300, 40));
        comboBoxShopCode->setMaximumSize(QSize(300, 30));
        comboBoxShopCode->setFont(font3);
        comboBoxShopCode->setStyleSheet(QStringLiteral(""));
        comboBoxShopCode->setEditable(true);

        horizontalLayout_4->addWidget(comboBoxShopCode);

        checkBoxRememberPsd = new QCheckBox(logindialog);
        checkBoxRememberPsd->setObjectName(QStringLiteral("checkBoxRememberPsd"));
        checkBoxRememberPsd->setGeometry(QRect(460, 380, 311, 31));
        checkBoxRememberPsd->setStyleSheet(QString::fromUtf8("color:gray;\n"
"font: 10pt \"\345\256\213\344\275\223\";"));
        QWidget::setTabOrder(pushButtonLogin, comboBoxShopCode);
        QWidget::setTabOrder(comboBoxShopCode, comboBoxUserName);
        QWidget::setTabOrder(comboBoxUserName, lineEditPassWord);
        QWidget::setTabOrder(lineEditPassWord, checkBoxRememberPsd);
        QWidget::setTabOrder(checkBoxRememberPsd, pushButtonInfo);

        retranslateUi(logindialog);

        QMetaObject::connectSlotsByName(logindialog);
    } // setupUi

    void retranslateUi(QDialog *logindialog)
    {
        logindialog->setWindowTitle(QApplication::translate("logindialog", "\347\224\250\346\210\267\347\231\273\345\275\225", 0));
        pushButtonLogin->setText(QApplication::translate("logindialog", "\347\231\273\345\275\225", 0));
        label_3->setText(QApplication::translate("logindialog", "\344\273\223\345\272\223\347\256\241\347\220\206\347\263\273\347\273\237", 0));
        pushButtonInfo->setText(QString());
        label_5->setText(QString());
        label->setText(QApplication::translate("logindialog", "\345\257\206\347\240\201\357\274\232", 0));
        lineEditPassWord->setText(QString());
        label_2->setText(QApplication::translate("logindialog", "\347\224\250\346\210\267\345\220\215\357\274\232", 0));
        label_6->setText(QApplication::translate("logindialog", "\345\272\227\351\223\272\347\274\226\347\240\201\357\274\232", 0));
        checkBoxRememberPsd->setText(QApplication::translate("logindialog", "\350\256\260\344\275\217\345\257\206\347\240\201", 0));
    } // retranslateUi

};

namespace Ui {
    class logindialog: public Ui_logindialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
