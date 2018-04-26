/********************************************************************************
** Form generated from reading UI file 'materialcontrol.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATERIALCONTROL_H
#define UI_MATERIALCONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MaterialControl
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QListWidget *listWidgetAddMaterialInfo;
    QLabel *label_4;
    QListWidget *listWidgetExtenInfo;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonLookImage;
    QPushButton *pushButtonDelImage;
    QPushButton *pushButtonCancel;

    void setupUi(QWidget *MaterialControl)
    {
        if (MaterialControl->objectName().isEmpty())
            MaterialControl->setObjectName(QStringLiteral("MaterialControl"));
        MaterialControl->resize(315, 285);
        MaterialControl->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(MaterialControl);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(2);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(3, 3, 3, 3);
        label_3 = new QLabel(MaterialControl);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(0, 30));
        label_3->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);
        label_3->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"background-color:rgb(180, 85, 100);\n"
"color:white;\n"
"font-size:14px;\n"
"font-weight:bold;\n"
"}"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_4->addWidget(label_3);

        listWidgetAddMaterialInfo = new QListWidget(MaterialControl);
        listWidgetAddMaterialInfo->setObjectName(QStringLiteral("listWidgetAddMaterialInfo"));
        listWidgetAddMaterialInfo->setStyleSheet(QStringLiteral(""));
        listWidgetAddMaterialInfo->setAutoScrollMargin(16);
        listWidgetAddMaterialInfo->setResizeMode(QListView::Adjust);

        verticalLayout_4->addWidget(listWidgetAddMaterialInfo);

        label_4 = new QLabel(MaterialControl);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(0, 30));
        label_4->setMaximumSize(QSize(16777215, 30));
        label_4->setFont(font);
        label_4->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"background-color:rgb(180, 85, 100);\n"
"color:white;\n"
"font-size:14px;\n"
"font-weight:bold;\n"
"}"));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_4->addWidget(label_4);

        listWidgetExtenInfo = new QListWidget(MaterialControl);
        listWidgetExtenInfo->setObjectName(QStringLiteral("listWidgetExtenInfo"));
        listWidgetExtenInfo->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-color:transparent;\n"
"color:black;\n"
"}"));

        verticalLayout_4->addWidget(listWidgetExtenInfo);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButtonSave = new QPushButton(MaterialControl);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        pushButtonSave->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSave->setIcon(icon);

        horizontalLayout_2->addWidget(pushButtonSave);

        pushButtonLookImage = new QPushButton(MaterialControl);
        pushButtonLookImage->setObjectName(QStringLiteral("pushButtonLookImage"));
        pushButtonLookImage->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/image/\351\242\204\350\247\210.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonLookImage->setIcon(icon1);

        horizontalLayout_2->addWidget(pushButtonLookImage);

        pushButtonDelImage = new QPushButton(MaterialControl);
        pushButtonDelImage->setObjectName(QStringLiteral("pushButtonDelImage"));
        pushButtonDelImage->setStyleSheet(QStringLiteral(""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/image/\345\210\240\351\231\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonDelImage->setIcon(icon2);

        horizontalLayout_2->addWidget(pushButtonDelImage);

        pushButtonCancel = new QPushButton(MaterialControl);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setStyleSheet(QStringLiteral(""));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon3);

        horizontalLayout_2->addWidget(pushButtonCancel);


        verticalLayout_4->addLayout(horizontalLayout_2);

        verticalLayout_4->setStretch(1, 10);
        verticalLayout_4->setStretch(3, 12);

        verticalLayout->addLayout(verticalLayout_4);


        retranslateUi(MaterialControl);

        QMetaObject::connectSlotsByName(MaterialControl);
    } // setupUi

    void retranslateUi(QWidget *MaterialControl)
    {
        MaterialControl->setWindowTitle(QApplication::translate("MaterialControl", "Form", 0));
        label_3->setText(QApplication::translate("MaterialControl", " \345\237\272\346\234\254\344\277\241\346\201\257", 0));
        label_4->setText(QApplication::translate("MaterialControl", " \346\211\251\345\261\225\344\277\241\346\201\257", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonSave->setToolTip(QApplication::translate("MaterialControl", " \344\277\235\345\255\230", 0));
#endif // QT_NO_TOOLTIP
        pushButtonSave->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButtonLookImage->setToolTip(QApplication::translate("MaterialControl", " \345\233\276\347\211\207\351\242\204\350\247\210", 0));
#endif // QT_NO_TOOLTIP
        pushButtonLookImage->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButtonDelImage->setToolTip(QApplication::translate("MaterialControl", " \345\210\240\351\231\244\345\233\276\347\211\207", 0));
#endif // QT_NO_TOOLTIP
        pushButtonDelImage->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButtonCancel->setToolTip(QApplication::translate("MaterialControl", " \345\217\226\346\266\210", 0));
#endif // QT_NO_TOOLTIP
        pushButtonCancel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MaterialControl: public Ui_MaterialControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATERIALCONTROL_H
