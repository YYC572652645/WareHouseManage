/********************************************************************************
** Form generated from reading UI file 'templatewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEMPLATEWIDGET_H
#define UI_TEMPLATEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TemplateWidget
{
public:
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QWidget *widgetControl;
    QPushButton *pushButtonAddTem;
    QLabel *labelSize;
    QTableWidget *tableWidgetTemplate;
    QTabWidget *tabWidgetTemplate;
    QWidget *tabAddTemplate;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *lineEditTemplateName;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_9;
    QLineEdit *lineEditRemark;
    QFrame *frame;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButtonAddTemMat;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonCancel;
    QWidget *tabTemplateInfo;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_10;
    QLineEdit *lineEditTemplateNameInfo;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_11;
    QLineEdit *lineEditRemarkInfo;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_12;
    QLabel *labelTotalCountInfo;
    QSpacerItem *horizontalSpacer_4;
    QListWidget *listWidgetData;
    QPushButton *pushButtonAddTemMatInfo;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *pushButtonSaveInfo;
    QPushButton *pushButtonDelTem;
    QPushButton *pushButtonCancelInfo;

    void setupUi(QWidget *TemplateWidget)
    {
        if (TemplateWidget->objectName().isEmpty())
            TemplateWidget->setObjectName(QStringLiteral("TemplateWidget"));
        TemplateWidget->resize(562, 376);
        TemplateWidget->setStyleSheet(QLatin1String("QComboBox {  \n"
"background-color:transparent;\n"
"font-size:12px;\n"
"color:white;\n"
"		   \n"
" }\n"
"QComboBox QAbstractItemView\n"
"{\n"
"selection-color:white;\n"
"selection-background-color:rgb(44, 62, 80);\n"
"background-color:rgb(44, 62, 80);\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item\n"
"{\n"
"min-height: 35px;\n"
"min-width: 60px;\n"
"color:white;\n"
"}\n"
"\n"
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
"width: 150px;\n"
"padding: 0px 0px;\n"
"}\n"
""));
        verticalLayout_7 = new QVBoxLayout(TemplateWidget);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(-1, -1, -1, 0);
        groupBox = new QGroupBox(TemplateWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setStyleSheet(QStringLiteral(""));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 0, -1, -1);
        widgetControl = new QWidget(groupBox);
        widgetControl->setObjectName(QStringLiteral("widgetControl"));
        widgetControl->setMinimumSize(QSize(0, 20));
        pushButtonAddTem = new QPushButton(widgetControl);
        pushButtonAddTem->setObjectName(QStringLiteral("pushButtonAddTem"));
        pushButtonAddTem->setGeometry(QRect(5, 10, 150, 16));
        pushButtonAddTem->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/image/addfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonAddTem->setIcon(icon);
        labelSize = new QLabel(widgetControl);
        labelSize->setObjectName(QStringLiteral("labelSize"));
        labelSize->setGeometry(QRect(200, 10, 16, 18));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        labelSize->setFont(font);

        verticalLayout->addWidget(widgetControl);

        tableWidgetTemplate = new QTableWidget(groupBox);
        if (tableWidgetTemplate->columnCount() < 2)
            tableWidgetTemplate->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetTemplate->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetTemplate->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidgetTemplate->setObjectName(QStringLiteral("tableWidgetTemplate"));
        tableWidgetTemplate->setTextElideMode(Qt::ElideRight);

        verticalLayout->addWidget(tableWidgetTemplate);


        verticalLayout_4->addLayout(verticalLayout);


        horizontalLayout_6->addWidget(groupBox);

        tabWidgetTemplate = new QTabWidget(TemplateWidget);
        tabWidgetTemplate->setObjectName(QStringLiteral("tabWidgetTemplate"));
        tabAddTemplate = new QWidget();
        tabAddTemplate->setObjectName(QStringLiteral("tabAddTemplate"));
        verticalLayout_3 = new QVBoxLayout(tabAddTemplate);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(3, 0, 3, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_3 = new QLabel(tabAddTemplate);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(0, 40));
        label_3->setMaximumSize(QSize(16777215, 40));
        QFont font1;
        font1.setFamily(QStringLiteral("Aharoni"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);
        label_3->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"background-color:rgb(180, 85, 100);\n"
"color:white;\n"
"}"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(tabAddTemplate);
        label->setObjectName(QStringLiteral("label"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label);

        lineEditTemplateName = new QLineEdit(tabAddTemplate);
        lineEditTemplateName->setObjectName(QStringLiteral("lineEditTemplateName"));
        lineEditTemplateName->setMinimumSize(QSize(200, 0));
        lineEditTemplateName->setMaximumSize(QSize(200, 30));

        horizontalLayout_3->addWidget(lineEditTemplateName);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_9 = new QLabel(tabAddTemplate);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font2);
        label_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(label_9);

        lineEditRemark = new QLineEdit(tabAddTemplate);
        lineEditRemark->setObjectName(QStringLiteral("lineEditRemark"));
        lineEditRemark->setMinimumSize(QSize(200, 0));
        lineEditRemark->setMaximumSize(QSize(200, 30));

        horizontalLayout_7->addWidget(lineEditRemark);


        verticalLayout_2->addLayout(horizontalLayout_7);

        frame = new QFrame(tabAddTemplate);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(0, 40));
        frame->setMaximumSize(QSize(16777215, 40));
        frame->setStyleSheet(QLatin1String("QFrame\n"
"{\n"
"background-color:rgb(180, 85, 100);\n"
"color:white;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_8 = new QVBoxLayout(frame);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(0, 30));
        label_5->setMaximumSize(QSize(16777215, 30));
        label_5->setFont(font1);
        label_5->setStyleSheet(QStringLiteral(""));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_8->addWidget(label_5);

        horizontalSpacer_3 = new QSpacerItem(5, 5, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);


        verticalLayout_8->addLayout(horizontalLayout_8);


        verticalLayout_2->addWidget(frame);

        pushButtonAddTemMat = new QPushButton(tabAddTemplate);
        pushButtonAddTemMat->setObjectName(QStringLiteral("pushButtonAddTemMat"));
        pushButtonAddTemMat->setMinimumSize(QSize(0, 60));
        pushButtonAddTemMat->setStyleSheet(QStringLiteral(""));
        pushButtonAddTemMat->setIcon(icon);

        verticalLayout_2->addWidget(pushButtonAddTemMat);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButtonSave = new QPushButton(tabAddTemplate);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        pushButtonSave->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSave->setIcon(icon1);

        horizontalLayout_2->addWidget(pushButtonSave);

        pushButtonCancel = new QPushButton(tabAddTemplate);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setStyleSheet(QStringLiteral(""));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon2);

        horizontalLayout_2->addWidget(pushButtonCancel);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout_2);

        tabWidgetTemplate->addTab(tabAddTemplate, QString());
        tabTemplateInfo = new QWidget();
        tabTemplateInfo->setObjectName(QStringLiteral("tabTemplateInfo"));
        verticalLayout_6 = new QVBoxLayout(tabTemplateInfo);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(3, 0, 3, 0);
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        label_4 = new QLabel(tabTemplateInfo);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(0, 40));
        label_4->setMaximumSize(QSize(16777215, 40));
        label_4->setFont(font1);
        label_4->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"background-color:rgb(180, 85, 100);\n"
"color:white;\n"
"}"));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_9->addWidget(label_4);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_10 = new QLabel(tabTemplateInfo);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font2);
        label_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_10->setMargin(0);

        horizontalLayout_9->addWidget(label_10);

        lineEditTemplateNameInfo = new QLineEdit(tabTemplateInfo);
        lineEditTemplateNameInfo->setObjectName(QStringLiteral("lineEditTemplateNameInfo"));
        lineEditTemplateNameInfo->setMinimumSize(QSize(200, 0));
        lineEditTemplateNameInfo->setMaximumSize(QSize(200, 30));

        horizontalLayout_9->addWidget(lineEditTemplateNameInfo);


        verticalLayout_9->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_11 = new QLabel(tabTemplateInfo);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font2);
        label_11->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_10->addWidget(label_11);

        lineEditRemarkInfo = new QLineEdit(tabTemplateInfo);
        lineEditRemarkInfo->setObjectName(QStringLiteral("lineEditRemarkInfo"));
        lineEditRemarkInfo->setMinimumSize(QSize(200, 0));
        lineEditRemarkInfo->setMaximumSize(QSize(200, 30));

        horizontalLayout_10->addWidget(lineEditRemarkInfo);


        verticalLayout_9->addLayout(horizontalLayout_10);

        frame_2 = new QFrame(tabTemplateInfo);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setMinimumSize(QSize(0, 40));
        frame_2->setMaximumSize(QSize(16777215, 40));
        frame_2->setStyleSheet(QLatin1String("QFrame\n"
"{\n"
"background-color:rgb(180, 85, 100);\n"
"color:white;\n"
"}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_10 = new QVBoxLayout(frame_2);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_12 = new QLabel(frame_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMinimumSize(QSize(0, 30));
        label_12->setMaximumSize(QSize(16777215, 30));
        label_12->setFont(font1);
        label_12->setStyleSheet(QStringLiteral(""));
        label_12->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_11->addWidget(label_12);

        labelTotalCountInfo = new QLabel(frame_2);
        labelTotalCountInfo->setObjectName(QStringLiteral("labelTotalCountInfo"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        labelTotalCountInfo->setFont(font3);

        horizontalLayout_11->addWidget(labelTotalCountInfo);

        horizontalSpacer_4 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_4);


        verticalLayout_10->addLayout(horizontalLayout_11);


        verticalLayout_9->addWidget(frame_2);

        listWidgetData = new QListWidget(tabTemplateInfo);
        listWidgetData->setObjectName(QStringLiteral("listWidgetData"));
        listWidgetData->setStyleSheet(QString::fromUtf8("QPushButton:hover\n"
"{\n"
"image: url(:/image/image/\345\210\240\351\231\244\351\200\211\344\270\255.png);\n"
"background-color: transparent;\n"
"}\n"
"\n"
"QPushButton:hover:pressed\n"
"{\n"
"image: url(:/image/image/\345\210\240\351\231\244\351\200\211\344\270\255.png);\n"
"background-color: transparent;\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"image: url(:/image/image/\345\210\240\351\231\244.png);\n"
"background-color: transparent;\n"
"}\n"
""));

        verticalLayout_9->addWidget(listWidgetData);

        pushButtonAddTemMatInfo = new QPushButton(tabTemplateInfo);
        pushButtonAddTemMatInfo->setObjectName(QStringLiteral("pushButtonAddTemMatInfo"));
        pushButtonAddTemMatInfo->setStyleSheet(QStringLiteral(""));
        pushButtonAddTemMatInfo->setIcon(icon);

        verticalLayout_9->addWidget(pushButtonAddTemMatInfo);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        pushButtonSaveInfo = new QPushButton(tabTemplateInfo);
        pushButtonSaveInfo->setObjectName(QStringLiteral("pushButtonSaveInfo"));
        pushButtonSaveInfo->setStyleSheet(QStringLiteral(""));
        pushButtonSaveInfo->setIcon(icon1);

        horizontalLayout_12->addWidget(pushButtonSaveInfo);

        pushButtonDelTem = new QPushButton(tabTemplateInfo);
        pushButtonDelTem->setObjectName(QStringLiteral("pushButtonDelTem"));
        pushButtonDelTem->setStyleSheet(QStringLiteral(""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/image/\345\210\240 \351\231\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonDelTem->setIcon(icon3);

        horizontalLayout_12->addWidget(pushButtonDelTem);

        pushButtonCancelInfo = new QPushButton(tabTemplateInfo);
        pushButtonCancelInfo->setObjectName(QStringLiteral("pushButtonCancelInfo"));
        pushButtonCancelInfo->setStyleSheet(QStringLiteral(""));
        pushButtonCancelInfo->setIcon(icon2);

        horizontalLayout_12->addWidget(pushButtonCancelInfo);


        verticalLayout_9->addLayout(horizontalLayout_12);


        verticalLayout_6->addLayout(verticalLayout_9);

        tabWidgetTemplate->addTab(tabTemplateInfo, QString());

        horizontalLayout_6->addWidget(tabWidgetTemplate);

        horizontalLayout_6->setStretch(0, 6);
        horizontalLayout_6->setStretch(1, 4);

        verticalLayout_7->addLayout(horizontalLayout_6);


        retranslateUi(TemplateWidget);

        tabWidgetTemplate->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TemplateWidget);
    } // setupUi

    void retranslateUi(QWidget *TemplateWidget)
    {
        TemplateWidget->setWindowTitle(QApplication::translate("TemplateWidget", "Form", 0));
        groupBox->setTitle(QString());
        pushButtonAddTem->setText(QApplication::translate("TemplateWidget", " \346\267\273\345\212\240\346\250\241\346\235\277", 0));
        labelSize->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidgetTemplate->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("TemplateWidget", "\346\250\241\346\235\277\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetTemplate->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("TemplateWidget", "\345\216\237\346\226\231\346\225\260", 0));
        label_3->setText(QApplication::translate("TemplateWidget", " \345\237\272\346\234\254\344\277\241\346\201\257", 0));
        label->setText(QApplication::translate("TemplateWidget", " \346\250\241\346\235\277\345\220\215\347\247\260\357\274\232", 0));
        lineEditTemplateName->setPlaceholderText(QApplication::translate("TemplateWidget", "\345\277\205\345\241\253", 0));
        label_9->setText(QApplication::translate("TemplateWidget", " \345\244\207\346\263\250\357\274\232", 0));
        lineEditRemark->setPlaceholderText(QApplication::translate("TemplateWidget", "\345\217\257\344\270\215\345\241\253", 0));
        label_5->setText(QApplication::translate("TemplateWidget", " \345\216\237\346\226\231", 0));
        pushButtonAddTemMat->setText(QApplication::translate("TemplateWidget", " \346\267\273\345\212\240\346\250\241\346\235\277\345\216\237\346\226\231", 0));
        pushButtonSave->setText(QApplication::translate("TemplateWidget", " \344\277\235\345\255\230", 0));
        pushButtonCancel->setText(QApplication::translate("TemplateWidget", " \345\217\226\346\266\210", 0));
        tabWidgetTemplate->setTabText(tabWidgetTemplate->indexOf(tabAddTemplate), QApplication::translate("TemplateWidget", "\346\267\273\345\212\240\346\250\241\346\235\277", 0));
        label_4->setText(QApplication::translate("TemplateWidget", " \345\237\272\346\234\254\344\277\241\346\201\257", 0));
        label_10->setText(QApplication::translate("TemplateWidget", " \346\250\241\346\235\277\345\220\215\347\247\260\357\274\232", 0));
        lineEditTemplateNameInfo->setPlaceholderText(QApplication::translate("TemplateWidget", "\345\277\205\345\241\253", 0));
        label_11->setText(QApplication::translate("TemplateWidget", " \345\244\207\346\263\250\357\274\232", 0));
        lineEditRemarkInfo->setPlaceholderText(QApplication::translate("TemplateWidget", "\345\217\257\344\270\215\345\241\253", 0));
        label_12->setText(QApplication::translate("TemplateWidget", " \345\216\237\346\226\231", 0));
        labelTotalCountInfo->setText(QString());
        pushButtonAddTemMatInfo->setText(QApplication::translate("TemplateWidget", " \346\267\273\345\212\240\346\250\241\346\235\277\345\216\237\346\226\231", 0));
        pushButtonSaveInfo->setText(QApplication::translate("TemplateWidget", " \344\277\235\345\255\230", 0));
        pushButtonDelTem->setText(QApplication::translate("TemplateWidget", " \345\210\240\351\231\244", 0));
        pushButtonCancelInfo->setText(QApplication::translate("TemplateWidget", " \345\217\226\346\266\210", 0));
        tabWidgetTemplate->setTabText(tabWidgetTemplate->indexOf(tabTemplateInfo), QApplication::translate("TemplateWidget", "\346\250\241\346\235\277\344\277\241\346\201\257", 0));
    } // retranslateUi

};

namespace Ui {
    class TemplateWidget: public Ui_TemplateWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEMPLATEWIDGET_H
