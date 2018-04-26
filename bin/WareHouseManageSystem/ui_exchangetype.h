/********************************************************************************
** Form generated from reading UI file 'exchangetype.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXCHANGETYPE_H
#define UI_EXCHANGETYPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExchangeType
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBoxType;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButtonOk;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButtonCancel;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *ExchangeType)
    {
        if (ExchangeType->objectName().isEmpty())
            ExchangeType->setObjectName(QStringLiteral("ExchangeType"));
        ExchangeType->resize(322, 244);
        verticalLayout = new QVBoxLayout(ExchangeType);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(ExchangeType);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        comboBoxType = new QComboBox(ExchangeType);
        comboBoxType->setObjectName(QStringLiteral("comboBoxType"));
        comboBoxType->setMinimumSize(QSize(200, 30));

        horizontalLayout->addWidget(comboBoxType);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        pushButtonOk = new QPushButton(ExchangeType);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));
        pushButtonOk->setMinimumSize(QSize(102, 30));
        pushButtonOk->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\347\241\256\350\256\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonOk->setIcon(icon);

        horizontalLayout_2->addWidget(pushButtonOk);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        pushButtonCancel = new QPushButton(ExchangeType);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setMinimumSize(QSize(102, 30));
        pushButtonCancel->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon1);

        horizontalLayout_2->addWidget(pushButtonCancel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(ExchangeType);

        QMetaObject::connectSlotsByName(ExchangeType);
    } // setupUi

    void retranslateUi(QWidget *ExchangeType)
    {
        ExchangeType->setWindowTitle(QApplication::translate("ExchangeType", "Form", 0));
        label->setText(QApplication::translate("ExchangeType", "\345\210\206\347\261\273\345\210\227\350\241\250:", 0));
        pushButtonOk->setText(QApplication::translate("ExchangeType", " \347\241\256\345\256\232", 0));
        pushButtonCancel->setText(QApplication::translate("ExchangeType", " \345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class ExchangeType: public Ui_ExchangeType {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXCHANGETYPE_H
