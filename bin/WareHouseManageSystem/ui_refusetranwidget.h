/********************************************************************************
** Form generated from reading UI file 'refusetranwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REFUSETRANWIDGET_H
#define UI_REFUSETRANWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RefuseTranWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *textEditContent;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButtonOk;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButtonCancel;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QWidget *RefuseTranWidget)
    {
        if (RefuseTranWidget->objectName().isEmpty())
            RefuseTranWidget->setObjectName(QStringLiteral("RefuseTranWidget"));
        RefuseTranWidget->resize(378, 263);
        verticalLayout_2 = new QVBoxLayout(RefuseTranWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        textEditContent = new QTextEdit(RefuseTranWidget);
        textEditContent->setObjectName(QStringLiteral("textEditContent"));

        verticalLayout->addWidget(textEditContent);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pushButtonOk = new QPushButton(RefuseTranWidget);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));
        pushButtonOk->setMinimumSize(QSize(100, 30));
        pushButtonOk->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\347\241\256\350\256\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonOk->setIcon(icon);

        horizontalLayout->addWidget(pushButtonOk);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        pushButtonCancel = new QPushButton(RefuseTranWidget);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setMinimumSize(QSize(100, 30));
        pushButtonCancel->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon1);

        horizontalLayout->addWidget(pushButtonCancel);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(RefuseTranWidget);

        QMetaObject::connectSlotsByName(RefuseTranWidget);
    } // setupUi

    void retranslateUi(QWidget *RefuseTranWidget)
    {
        RefuseTranWidget->setWindowTitle(QApplication::translate("RefuseTranWidget", "Form", 0));
        pushButtonOk->setText(QApplication::translate("RefuseTranWidget", " \347\241\256\345\256\232", 0));
        pushButtonCancel->setText(QApplication::translate("RefuseTranWidget", " \345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class RefuseTranWidget: public Ui_RefuseTranWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REFUSETRANWIDGET_H
