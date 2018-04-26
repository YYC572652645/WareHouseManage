/********************************************************************************
** Form generated from reading UI file 'pushmessage.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PUSHMESSAGE_H
#define UI_PUSHMESSAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pushmessage
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QLabel *labelContent;
    QFrame *frame;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *labelInfo;
    QPushButton *pushButtonLook;

    void setupUi(QWidget *pushmessage)
    {
        if (pushmessage->objectName().isEmpty())
            pushmessage->setObjectName(QStringLiteral("pushmessage"));
        pushmessage->resize(259, 178);
        pushmessage->setStyleSheet(QLatin1String("QWidget\n"
"{\n"
"background-color: rgb(255, 255, 255);\n"
"image: url(:/image/image/loginbackground.png);\n"
"border-radius:5px;\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(pushmessage);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 15, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_3);

        horizontalSpacer_4 = new QSpacerItem(40, 15, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(verticalLayout);

        labelContent = new QLabel(pushmessage);
        labelContent->setObjectName(QStringLiteral("labelContent"));
        labelContent->setMinimumSize(QSize(257, 103));
        labelContent->setMaximumSize(QSize(257, 103));
        labelContent->setStyleSheet(QStringLiteral("image: url(:/image/image/login.jpg);"));
        labelContent->setScaledContents(false);
        labelContent->setAlignment(Qt::AlignCenter);
        labelContent->setWordWrap(false);

        verticalLayout_2->addWidget(labelContent);

        frame = new QFrame(pushmessage);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelInfo = new QLabel(frame);
        labelInfo->setObjectName(QStringLiteral("labelInfo"));
        labelInfo->setWordWrap(true);

        horizontalLayout->addWidget(labelInfo);

        pushButtonLook = new QPushButton(frame);
        pushButtonLook->setObjectName(QStringLiteral("pushButtonLook"));
        pushButtonLook->setMinimumSize(QSize(0, 25));
        pushButtonLook->setMaximumSize(QSize(80, 16777215));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        pushButtonLook->setFont(font);
        pushButtonLook->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"image:none;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"background-color: rgb(180, 85, 100);\n"
"color:white;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\347\241\256\350\256\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonLook->setIcon(icon);

        horizontalLayout->addWidget(pushButtonLook);


        verticalLayout_4->addLayout(horizontalLayout);


        verticalLayout_2->addWidget(frame);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(pushmessage);

        QMetaObject::connectSlotsByName(pushmessage);
    } // setupUi

    void retranslateUi(QWidget *pushmessage)
    {
        pushmessage->setWindowTitle(QApplication::translate("pushmessage", "Form", 0));
        labelContent->setText(QString());
        labelInfo->setText(QApplication::translate("pushmessage", "\346\243\200\346\265\213\345\210\260\346\234\211\346\226\260\347\211\210\346\234\254\357\274\214\347\241\256\345\256\232\346\233\264\346\226\260\345\220\227\357\274\237", 0));
        pushButtonLook->setText(QApplication::translate("pushmessage", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class pushmessage: public Ui_pushmessage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUSHMESSAGE_H
