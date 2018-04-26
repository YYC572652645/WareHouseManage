/********************************************************************************
** Form generated from reading UI file 'subposition.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBPOSITION_H
#define UI_SUBPOSITION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SubPosition
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBoxWareHouse;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelNumber;
    QDoubleSpinBox *doubleSpinBoxNumber;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEditTotalMoney;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonCancel;

    void setupUi(QWidget *SubPosition)
    {
        if (SubPosition->objectName().isEmpty())
            SubPosition->setObjectName(QStringLiteral("SubPosition"));
        SubPosition->resize(400, 300);
        verticalLayout = new QVBoxLayout(SubPosition);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(SubPosition);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        comboBoxWareHouse = new QComboBox(SubPosition);
        comboBoxWareHouse->setObjectName(QStringLiteral("comboBoxWareHouse"));
        comboBoxWareHouse->setMinimumSize(QSize(200, 30));
        comboBoxWareHouse->setMaximumSize(QSize(200, 30));

        horizontalLayout->addWidget(comboBoxWareHouse);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        labelNumber = new QLabel(SubPosition);
        labelNumber->setObjectName(QStringLiteral("labelNumber"));

        horizontalLayout_2->addWidget(labelNumber);

        doubleSpinBoxNumber = new QDoubleSpinBox(SubPosition);
        doubleSpinBoxNumber->setObjectName(QStringLiteral("doubleSpinBoxNumber"));
        doubleSpinBoxNumber->setMinimumSize(QSize(200, 30));
        doubleSpinBoxNumber->setMaximumSize(QSize(200, 30));
        doubleSpinBoxNumber->setMinimum(1);
        doubleSpinBoxNumber->setMaximum(100000);

        horizontalLayout_2->addWidget(doubleSpinBoxNumber);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(SubPosition);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEditTotalMoney = new QLineEdit(SubPosition);
        lineEditTotalMoney->setObjectName(QStringLiteral("lineEditTotalMoney"));
        lineEditTotalMoney->setEnabled(false);
        lineEditTotalMoney->setMinimumSize(QSize(200, 30));
        lineEditTotalMoney->setMaximumSize(QSize(200, 30));
        lineEditTotalMoney->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        horizontalLayout_3->addWidget(lineEditTotalMoney);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButtonSave = new QPushButton(SubPosition);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/\347\241\256\350\256\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSave->setIcon(icon);

        horizontalLayout_4->addWidget(pushButtonSave);

        pushButtonCancel = new QPushButton(SubPosition);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon1);

        horizontalLayout_4->addWidget(pushButtonCancel);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(SubPosition);

        QMetaObject::connectSlotsByName(SubPosition);
    } // setupUi

    void retranslateUi(QWidget *SubPosition)
    {
        SubPosition->setWindowTitle(QApplication::translate("SubPosition", "Form", 0));
        label->setText(QApplication::translate("SubPosition", "\345\205\245\345\272\223\344\273\223\345\272\223\357\274\232", 0));
        labelNumber->setText(QApplication::translate("SubPosition", "\346\225\260\351\207\217\357\274\232", 0));
        label_3->setText(QApplication::translate("SubPosition", "\351\207\221\351\242\235(\345\205\203)\357\274\232", 0));
        pushButtonSave->setText(QApplication::translate("SubPosition", " \344\277\235\345\255\230", 0));
        pushButtonCancel->setText(QApplication::translate("SubPosition", " \345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class SubPosition: public Ui_SubPosition {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBPOSITION_H
