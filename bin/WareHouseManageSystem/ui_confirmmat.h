/********************************************************************************
** Form generated from reading UI file 'confirmmat.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRMMAT_H
#define UI_CONFIRMMAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfirmMat
{
public:
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidgetData;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBoxAllSelect;
    QLabel *labelContent;
    QPushButton *pushButtonConfirm;

    void setupUi(QWidget *ConfirmMat)
    {
        if (ConfirmMat->objectName().isEmpty())
            ConfirmMat->setObjectName(QStringLiteral("ConfirmMat"));
        ConfirmMat->resize(624, 485);
        verticalLayout_2 = new QVBoxLayout(ConfirmMat);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(3, 3, 3, 3);
        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableWidgetData = new QTableWidget(ConfirmMat);
        if (tableWidgetData->columnCount() < 4)
            tableWidgetData->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidgetData->setObjectName(QStringLiteral("tableWidgetData"));

        verticalLayout->addWidget(tableWidgetData);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        checkBoxAllSelect = new QCheckBox(ConfirmMat);
        checkBoxAllSelect->setObjectName(QStringLiteral("checkBoxAllSelect"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\345\205\250\351\200\211.png"), QSize(), QIcon::Normal, QIcon::Off);
        checkBoxAllSelect->setIcon(icon);

        horizontalLayout->addWidget(checkBoxAllSelect);

        labelContent = new QLabel(ConfirmMat);
        labelContent->setObjectName(QStringLiteral("labelContent"));

        horizontalLayout->addWidget(labelContent);

        pushButtonConfirm = new QPushButton(ConfirmMat);
        pushButtonConfirm->setObjectName(QStringLiteral("pushButtonConfirm"));
        pushButtonConfirm->setMinimumSize(QSize(200, 0));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/image/\347\241\256\350\256\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonConfirm->setIcon(icon1);

        horizontalLayout->addWidget(pushButtonConfirm);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(ConfirmMat);

        QMetaObject::connectSlotsByName(ConfirmMat);
    } // setupUi

    void retranslateUi(QWidget *ConfirmMat)
    {
        ConfirmMat->setWindowTitle(QApplication::translate("ConfirmMat", "Form", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetData->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ConfirmMat", "\345\216\237\346\226\231\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetData->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ConfirmMat", "\345\216\237\346\226\231\347\274\226\347\240\201", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetData->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ConfirmMat", "\346\225\260\351\207\217", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetData->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ConfirmMat", "\345\215\225\344\275\215", 0));
        checkBoxAllSelect->setText(QApplication::translate("ConfirmMat", "\345\205\250\351\200\211", 0));
        labelContent->setText(QString());
        pushButtonConfirm->setText(QApplication::translate("ConfirmMat", " \347\241\256\350\256\244\351\207\207\350\264\255", 0));
    } // retranslateUi

};

namespace Ui {
    class ConfirmMat: public Ui_ConfirmMat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRMMAT_H
