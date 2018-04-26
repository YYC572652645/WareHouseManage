/********************************************************************************
** Form generated from reading UI file 'lookimage.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOOKIMAGE_H
#define UI_LOOKIMAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LookImage
{
public:
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QLabel *labelImage;

    void setupUi(QWidget *LookImage)
    {
        if (LookImage->objectName().isEmpty())
            LookImage->setObjectName(QStringLiteral("LookImage"));
        LookImage->resize(551, 660);
        verticalLayout_2 = new QVBoxLayout(LookImage);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_2);

        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer);

        scrollArea = new QScrollArea(LookImage);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 549, 608));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        labelImage = new QLabel(scrollAreaWidgetContents);
        labelImage->setObjectName(QStringLiteral("labelImage"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        labelImage->setFont(font);
        labelImage->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelImage);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);


        retranslateUi(LookImage);

        QMetaObject::connectSlotsByName(LookImage);
    } // setupUi

    void retranslateUi(QWidget *LookImage)
    {
        LookImage->setWindowTitle(QApplication::translate("LookImage", "Form", 0));
        labelImage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LookImage: public Ui_LookImage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOOKIMAGE_H
