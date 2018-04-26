/********************************************************************************
** Form generated from reading UI file 'addunitsite.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDUNITSITE_H
#define UI_ADDUNITSITE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddUnitSite
{
public:
    QVBoxLayout *verticalLayout_8;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditMainUnit;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBoxSiteUnit;
    QFrame *line_5;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_10;
    QLineEdit *lineEditLeft;
    QLabel *labelLeft;
    QLineEdit *lineEditRight;
    QLabel *labelRight;
    QLabel *label_10;
    QFrame *line;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QCheckBox *checkBoxWareHouse;
    QLabel *label_6;
    QFrame *line_2;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QCheckBox *checkBoxPrice;
    QLabel *label_7;
    QFrame *line_3;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QCheckBox *checkBoxSupply;
    QLabel *label_8;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButtonSave;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButtonDel;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *pushButtonCancel;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *AddUnitSite)
    {
        if (AddUnitSite->objectName().isEmpty())
            AddUnitSite->setObjectName(QStringLiteral("AddUnitSite"));
        AddUnitSite->resize(424, 633);
        AddUnitSite->setMaximumSize(QSize(424, 16777215));
        AddUnitSite->setStyleSheet(QLatin1String("QComboBox {  \n"
"background-color:white;\n"
"font-size-9px;\n"
"		   \n"
" }\n"
""));
        verticalLayout_8 = new QVBoxLayout(AddUnitSite);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_8->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_8->addItem(horizontalSpacer_2);

        frame_4 = new QFrame(AddUnitSite);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout_7 = new QVBoxLayout(frame_4);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(frame_4);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        lineEditMainUnit = new QLineEdit(frame_4);
        lineEditMainUnit->setObjectName(QStringLiteral("lineEditMainUnit"));
        lineEditMainUnit->setEnabled(false);
        lineEditMainUnit->setMinimumSize(QSize(100, 24));
        lineEditMainUnit->setMaximumSize(QSize(100, 16777215));
        lineEditMainUnit->setFont(font);
        lineEditMainUnit->setStyleSheet(QLatin1String("background-color:white;\n"
"font-size-9px;\n"
"color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(lineEditMainUnit);


        verticalLayout_7->addLayout(horizontalLayout);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_7->addItem(horizontalSpacer_8);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(frame_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(68, 0));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        comboBoxSiteUnit = new QComboBox(frame_4);
        comboBoxSiteUnit->setObjectName(QStringLiteral("comboBoxSiteUnit"));
        comboBoxSiteUnit->setMinimumSize(QSize(100, 24));
        comboBoxSiteUnit->setMaximumSize(QSize(100, 16777215));
        comboBoxSiteUnit->setFont(font);

        horizontalLayout_2->addWidget(comboBoxSiteUnit);


        verticalLayout_7->addLayout(horizontalLayout_2);


        verticalLayout_8->addWidget(frame_4);

        line_5 = new QFrame(AddUnitSite);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(line_5);

        frame_5 = new QFrame(AddUnitSite);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setMinimumSize(QSize(0, 0));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        verticalLayout_10 = new QVBoxLayout(frame_5);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_9 = new QLabel(frame_5);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);

        horizontalLayout_7->addWidget(label_9);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_10);

        lineEditLeft = new QLineEdit(frame_5);
        lineEditLeft->setObjectName(QStringLiteral("lineEditLeft"));
        lineEditLeft->setMinimumSize(QSize(50, 0));
        lineEditLeft->setMaximumSize(QSize(100, 16777215));
        lineEditLeft->setFont(font);
        lineEditLeft->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_7->addWidget(lineEditLeft);

        labelLeft = new QLabel(frame_5);
        labelLeft->setObjectName(QStringLiteral("labelLeft"));
        labelLeft->setFont(font);

        horizontalLayout_7->addWidget(labelLeft);

        lineEditRight = new QLineEdit(frame_5);
        lineEditRight->setObjectName(QStringLiteral("lineEditRight"));
        lineEditRight->setMinimumSize(QSize(50, 0));
        lineEditRight->setMaximumSize(QSize(100, 16777215));
        lineEditRight->setFont(font);
        lineEditRight->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_7->addWidget(lineEditRight);

        labelRight = new QLabel(frame_5);
        labelRight->setObjectName(QStringLiteral("labelRight"));
        labelRight->setFont(font);

        horizontalLayout_7->addWidget(labelRight);


        verticalLayout_9->addLayout(horizontalLayout_7);

        label_10 = new QLabel(frame_5);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setScaledContents(true);

        verticalLayout_9->addWidget(label_10);


        verticalLayout_10->addLayout(verticalLayout_9);


        verticalLayout_8->addWidget(frame_5);

        line = new QFrame(AddUnitSite);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(line);

        frame = new QFrame(AddUnitSite);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        checkBoxWareHouse = new QCheckBox(frame);
        checkBoxWareHouse->setObjectName(QStringLiteral("checkBoxWareHouse"));
        checkBoxWareHouse->setMinimumSize(QSize(100, 0));
        checkBoxWareHouse->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(checkBoxWareHouse);


        verticalLayout->addLayout(horizontalLayout_3);

        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setScaledContents(true);
        label_6->setWordWrap(true);

        verticalLayout->addWidget(label_6);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_8->addWidget(frame);

        line_2 = new QFrame(AddUnitSite);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(line_2);

        frame_2 = new QFrame(AddUnitSite);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_2);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        horizontalLayout_4->addWidget(label_4);

        checkBoxPrice = new QCheckBox(frame_2);
        checkBoxPrice->setObjectName(QStringLiteral("checkBoxPrice"));
        checkBoxPrice->setMinimumSize(QSize(100, 0));
        checkBoxPrice->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_4->addWidget(checkBoxPrice);


        verticalLayout_3->addLayout(horizontalLayout_4);

        label_7 = new QLabel(frame_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setScaledContents(true);
        label_7->setWordWrap(true);

        verticalLayout_3->addWidget(label_7);


        verticalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_8->addWidget(frame_2);

        line_3 = new QFrame(AddUnitSite);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(line_3);

        frame_3 = new QFrame(AddUnitSite);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_6 = new QVBoxLayout(frame_3);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(frame_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        horizontalLayout_5->addWidget(label_5);

        checkBoxSupply = new QCheckBox(frame_3);
        checkBoxSupply->setObjectName(QStringLiteral("checkBoxSupply"));
        checkBoxSupply->setMinimumSize(QSize(100, 0));
        checkBoxSupply->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_5->addWidget(checkBoxSupply);


        verticalLayout_5->addLayout(horizontalLayout_5);

        label_8 = new QLabel(frame_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setLayoutDirection(Qt::LeftToRight);
        label_8->setTextFormat(Qt::AutoText);
        label_8->setScaledContents(false);
        label_8->setWordWrap(true);

        verticalLayout_5->addWidget(label_8);


        verticalLayout_6->addLayout(verticalLayout_5);


        verticalLayout_8->addWidget(frame_3);

        line_4 = new QFrame(AddUnitSite);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(line_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        pushButtonSave = new QPushButton(AddUnitSite);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        pushButtonSave->setMinimumSize(QSize(100, 30));
        pushButtonSave->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSave->setIcon(icon);

        horizontalLayout_6->addWidget(pushButtonSave);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);

        pushButtonDel = new QPushButton(AddUnitSite);
        pushButtonDel->setObjectName(QStringLiteral("pushButtonDel"));
        pushButtonDel->setMinimumSize(QSize(100, 30));
        pushButtonDel->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/image/\345\210\240 \351\231\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonDel->setIcon(icon1);

        horizontalLayout_6->addWidget(pushButtonDel);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_11);

        pushButtonCancel = new QPushButton(AddUnitSite);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setMinimumSize(QSize(100, 30));
        pushButtonCancel->setMaximumSize(QSize(16777215, 30));
        pushButtonCancel->setStyleSheet(QStringLiteral(""));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon2);

        horizontalLayout_6->addWidget(pushButtonCancel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        verticalLayout_8->addLayout(horizontalLayout_6);


        retranslateUi(AddUnitSite);

        QMetaObject::connectSlotsByName(AddUnitSite);
    } // setupUi

    void retranslateUi(QWidget *AddUnitSite)
    {
        AddUnitSite->setWindowTitle(QApplication::translate("AddUnitSite", "Form", 0));
        label->setText(QApplication::translate("AddUnitSite", "\344\270\273\345\215\225\344\275\215", 0));
        label_2->setText(QApplication::translate("AddUnitSite", "\345\211\257\345\215\225\344\275\215", 0));
        label_9->setText(QApplication::translate("AddUnitSite", "\346\215\242\347\256\227\345\205\263\347\263\273", 0));
        lineEditLeft->setPlaceholderText(QApplication::translate("AddUnitSite", "\345\277\205\345\241\253", 0));
        labelLeft->setText(QString());
        lineEditRight->setPlaceholderText(QApplication::translate("AddUnitSite", "\345\277\205\345\241\253", 0));
        labelRight->setText(QString());
        label_10->setText(QApplication::translate("AddUnitSite", "\346\263\250\357\274\232\344\270\273\345\215\225\344\275\215\345\273\272\350\256\256\350\256\276\347\275\256\345\216\237\346\226\231\347\232\204\346\234\200\345\260\217\350\247\204\346\240\274\345\215\225\344\275\215\343\200\202\n"
"\344\276\213\345\246\202\344\270\273\345\215\225\344\275\215\346\230\257ml\357\274\214\345\211\257\345\215\225\344\275\215\346\230\257\347\223\266\357\274\2141\347\223\266=500ml\357\274\214\346\255\244\346\227\266\346\215\242\347\256\227\345\205\263\347\263\273\345\272\224\346\230\2571\347\223\266=500ml", 0));
        label_3->setText(QApplication::translate("AddUnitSite", "\350\256\276\347\275\256\344\270\272\345\272\223\345\255\230\346\237\245\347\234\213\346\227\266\347\232\204\345\215\225\344\275\215", 0));
        checkBoxWareHouse->setText(QString());
        label_6->setText(QApplication::translate("AddUnitSite", "\345\275\223\344\270\215\350\256\276\347\275\256\345\272\223\345\255\230\346\237\245\347\234\213\345\215\225\344\275\215\346\227\266\357\274\214\351\273\230\350\256\244\345\215\225\344\275\215\344\270\272\345\272\223\345\255\230\346\237\245\347\234\213\345\215\225\344\275\215\357\274\214\344\270\224\345\217\252\350\203\275\350\256\276\347\275\256\344\270\200\344\270\252\345\272\223\345\255\230\346\237\245\347\234\213\345\215\225\344\275\215\357\274\201", 0));
        label_4->setText(QApplication::translate("AddUnitSite", "\350\256\276\347\275\256\344\270\272\350\256\241\344\273\267\345\215\225\344\275\215", 0));
        checkBoxPrice->setText(QString());
        label_7->setText(QApplication::translate("AddUnitSite", "\345\275\223\344\270\215\350\256\276\347\275\256\350\256\241\344\273\267\345\215\225\344\275\215\346\227\266\357\274\214\351\273\230\350\256\244\344\270\273\345\215\225\344\275\215\344\270\272\350\256\241\344\273\267\345\215\225\344\275\215\357\274\214\344\270\224\345\217\252\350\203\275\350\256\276\347\275\256\344\270\200\344\270\252\350\256\241\344\273\267\345\215\225\344\275\215\357\274\201", 0));
        label_5->setText(QApplication::translate("AddUnitSite", "\350\256\276\347\275\256\344\270\272\344\276\233\350\264\247\345\215\225\344\275\215", 0));
        checkBoxSupply->setText(QString());
        label_8->setText(QApplication::translate("AddUnitSite", "\350\256\276\347\275\256\344\270\272\344\276\233\350\264\247\345\215\225\344\275\215\346\227\266\357\274\214\345\257\271\345\244\226\344\276\233\350\264\247\351\207\207\347\224\250\346\255\244\345\215\225\344\275\215\343\200\202\345\275\223\344\270\215\350\256\276\347\275\256\344\276\233\350\264\247\345\215\225\344\275\215\346\227\266\357\274\214\351\273\230\350\256\244\344\270\273\345\215\225\344\275\215\344\270\272\344\276\233\350\264\247\345\215\225\344\275\215\357\274\214\344\270\224\345\217\252\350\203\275\350\256\276\347\275\256\344\270\200\344\270\252\350\256\241\344\273\267\345\215\225\344\275\215\357\274\201", 0));
        pushButtonSave->setText(QApplication::translate("AddUnitSite", " \344\277\235\345\255\230", 0));
        pushButtonDel->setText(QApplication::translate("AddUnitSite", " \345\210\240\351\231\244", 0));
        pushButtonCancel->setText(QApplication::translate("AddUnitSite", " \345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class AddUnitSite: public Ui_AddUnitSite {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDUNITSITE_H
