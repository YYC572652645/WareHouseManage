/********************************************************************************
** Form generated from reading UI file 'checkupdate.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKUPDATE_H
#define UI_CHECKUPDATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CheckUpdate
{
public:
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelImage;
    QHBoxLayout *horizontalLayout;
    QLabel *labelContent;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButtonUpdate;

    void setupUi(QDialog *CheckUpdate)
    {
        if (CheckUpdate->objectName().isEmpty())
            CheckUpdate->setObjectName(QStringLiteral("CheckUpdate"));
        CheckUpdate->resize(703, 489);
        CheckUpdate->setStyleSheet(QStringLiteral(""));
        verticalLayout_3 = new QVBoxLayout(CheckUpdate);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_2);

        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer);

        frame = new QFrame(CheckUpdate);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        labelImage = new QLabel(frame);
        labelImage->setObjectName(QStringLiteral("labelImage"));
        labelImage->setStyleSheet(QStringLiteral("image: url(:/image/image/login.jpg);"));

        horizontalLayout_2->addWidget(labelImage);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelContent = new QLabel(frame);
        labelContent->setObjectName(QStringLiteral("labelContent"));
        labelContent->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        labelContent->setWordWrap(true);

        horizontalLayout->addWidget(labelContent);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButtonUpdate = new QPushButton(frame);
        pushButtonUpdate->setObjectName(QStringLiteral("pushButtonUpdate"));
        pushButtonUpdate->setStyleSheet(QLatin1String("QPushButton:hover\n"
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
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\347\211\210\346\234\254\346\233\264\346\226\260.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonUpdate->setIcon(icon);

        verticalLayout->addWidget(pushButtonUpdate);


        horizontalLayout->addLayout(verticalLayout);

        horizontalLayout->setStretch(0, 4);
        horizontalLayout->setStretch(1, 2);

        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2->setStretch(0, 4);
        horizontalLayout_2->setStretch(1, 4);

        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_3->addWidget(frame);


        retranslateUi(CheckUpdate);

        QMetaObject::connectSlotsByName(CheckUpdate);
    } // setupUi

    void retranslateUi(QDialog *CheckUpdate)
    {
        CheckUpdate->setWindowTitle(QApplication::translate("CheckUpdate", "Form", 0));
        labelImage->setText(QString());
        labelContent->setText(QString());
        pushButtonUpdate->setText(QApplication::translate("CheckUpdate", " \345\220\257\345\212\250\346\233\264\346\226\260", 0));
    } // retranslateUi

};

namespace Ui {
    class CheckUpdate: public Ui_CheckUpdate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKUPDATE_H
