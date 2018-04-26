/********************************************************************************
** Form generated from reading UI file 'versiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERSIONDIALOG_H
#define UI_VERSIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_VersionDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelVersionImage;
    QLabel *labelContent;
    QLineEdit *lineEditVersion;

    void setupUi(QDialog *VersionDialog)
    {
        if (VersionDialog->objectName().isEmpty())
            VersionDialog->setObjectName(QStringLiteral("VersionDialog"));
        VersionDialog->resize(526, 421);
        VersionDialog->setStyleSheet(QStringLiteral(""));
        verticalLayout_3 = new QVBoxLayout(VersionDialog);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(VersionDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(6, 6, 6, 6);
        horizontalSpacer = new QSpacerItem(509, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(509, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelVersionImage = new QLabel(frame);
        labelVersionImage->setObjectName(QStringLiteral("labelVersionImage"));
        labelVersionImage->setStyleSheet(QStringLiteral("image: url(:/image/image/version.png);"));
        labelVersionImage->setScaledContents(true);
        labelVersionImage->setWordWrap(true);

        horizontalLayout->addWidget(labelVersionImage);

        labelContent = new QLabel(frame);
        labelContent->setObjectName(QStringLiteral("labelContent"));
        QFont font;
        font.setPointSize(10);
        labelContent->setFont(font);
        labelContent->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        labelContent->setScaledContents(true);
        labelContent->setWordWrap(true);

        horizontalLayout->addWidget(labelContent);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 5);

        verticalLayout->addLayout(horizontalLayout);

        lineEditVersion = new QLineEdit(frame);
        lineEditVersion->setObjectName(QStringLiteral("lineEditVersion"));
        lineEditVersion->setEnabled(false);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        lineEditVersion->setFont(font1);
        lineEditVersion->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        lineEditVersion->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(lineEditVersion);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addWidget(frame);


        retranslateUi(VersionDialog);

        QMetaObject::connectSlotsByName(VersionDialog);
    } // setupUi

    void retranslateUi(QDialog *VersionDialog)
    {
        VersionDialog->setWindowTitle(QApplication::translate("VersionDialog", "Dialog", 0));
        labelVersionImage->setText(QString());
        labelContent->setText(QString());
        lineEditVersion->setText(QApplication::translate("VersionDialog", "\344\273\223\345\272\223\347\256\241\347\220\206\347\263\273\347\273\2371.0", 0));
    } // retranslateUi

};

namespace Ui {
    class VersionDialog: public Ui_VersionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERSIONDIALOG_H
