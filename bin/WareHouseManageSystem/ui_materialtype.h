/********************************************************************************
** Form generated from reading UI file 'materialtype.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATERIALTYPE_H
#define UI_MATERIALTYPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MaterialType
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditMaterialTypeName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditMaterialCode;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QCheckBox *checkBoxIsHaveParent;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelParent;
    QComboBox *comboBoxParentType;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonDelete;
    QPushButton *pushButtonCancel;

    void setupUi(QWidget *MaterialType)
    {
        if (MaterialType->objectName().isEmpty())
            MaterialType->setObjectName(QStringLiteral("MaterialType"));
        MaterialType->resize(378, 379);
        MaterialType->setStyleSheet(QLatin1String("QComboBox {  \n"
"background-color:white;\n"
"font-size-9px;\n"
"		   \n"
" }\n"
""));
        verticalLayout = new QVBoxLayout(MaterialType);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(MaterialType);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEditMaterialTypeName = new QLineEdit(MaterialType);
        lineEditMaterialTypeName->setObjectName(QStringLiteral("lineEditMaterialTypeName"));
        lineEditMaterialTypeName->setMinimumSize(QSize(180, 25));
        lineEditMaterialTypeName->setMaximumSize(QSize(180, 16777215));

        horizontalLayout->addWidget(lineEditMaterialTypeName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(MaterialType);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEditMaterialCode = new QLineEdit(MaterialType);
        lineEditMaterialCode->setObjectName(QStringLiteral("lineEditMaterialCode"));
        lineEditMaterialCode->setMinimumSize(QSize(180, 25));
        lineEditMaterialCode->setMaximumSize(QSize(180, 16777215));
        lineEditMaterialCode->setFrame(true);
        lineEditMaterialCode->setDragEnabled(false);

        horizontalLayout_2->addWidget(lineEditMaterialCode);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(MaterialType);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        checkBoxIsHaveParent = new QCheckBox(MaterialType);
        checkBoxIsHaveParent->setObjectName(QStringLiteral("checkBoxIsHaveParent"));
        checkBoxIsHaveParent->setMinimumSize(QSize(180, 25));
        checkBoxIsHaveParent->setMaximumSize(QSize(180, 16777215));

        horizontalLayout_3->addWidget(checkBoxIsHaveParent);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        labelParent = new QLabel(MaterialType);
        labelParent->setObjectName(QStringLiteral("labelParent"));

        horizontalLayout_4->addWidget(labelParent);

        comboBoxParentType = new QComboBox(MaterialType);
        comboBoxParentType->setObjectName(QStringLiteral("comboBoxParentType"));
        comboBoxParentType->setMinimumSize(QSize(180, 25));
        comboBoxParentType->setMaximumSize(QSize(180, 16777215));

        horizontalLayout_4->addWidget(comboBoxParentType);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButtonSave = new QPushButton(MaterialType);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        pushButtonSave->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSave->setIcon(icon);

        horizontalLayout_5->addWidget(pushButtonSave);

        pushButtonDelete = new QPushButton(MaterialType);
        pushButtonDelete->setObjectName(QStringLiteral("pushButtonDelete"));
        pushButtonDelete->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/image/\345\210\240 \351\231\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonDelete->setIcon(icon1);

        horizontalLayout_5->addWidget(pushButtonDelete);

        pushButtonCancel = new QPushButton(MaterialType);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setStyleSheet(QStringLiteral(""));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCancel->setIcon(icon2);

        horizontalLayout_5->addWidget(pushButtonCancel);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(MaterialType);

        QMetaObject::connectSlotsByName(MaterialType);
    } // setupUi

    void retranslateUi(QWidget *MaterialType)
    {
        MaterialType->setWindowTitle(QApplication::translate("MaterialType", "Form", 0));
        label->setText(QApplication::translate("MaterialType", "\345\216\237\346\226\231\345\210\206\347\261\273\345\220\215\347\247\260\357\274\232", 0));
        label_2->setText(QApplication::translate("MaterialType", "\345\216\237\346\226\231\345\210\206\347\261\273\347\274\226\347\240\201\357\274\232", 0));
        lineEditMaterialCode->setInputMask(QString());
        lineEditMaterialCode->setText(QString());
        lineEditMaterialCode->setPlaceholderText(QApplication::translate("MaterialType", "\345\217\257\344\270\215\345\241\253", 0));
        label_3->setText(QApplication::translate("MaterialType", "\346\255\244\345\210\206\347\261\273\346\234\211\344\270\212\347\272\247\357\274\232", 0));
        checkBoxIsHaveParent->setText(QString());
        labelParent->setText(QApplication::translate("MaterialType", "\344\270\212\347\272\247\345\210\206\347\261\273\357\274\232", 0));
        pushButtonSave->setText(QApplication::translate("MaterialType", " \344\277\235\345\255\230", 0));
        pushButtonDelete->setText(QApplication::translate("MaterialType", " \345\210\240\351\231\244", 0));
        pushButtonCancel->setText(QApplication::translate("MaterialType", " \345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class MaterialType: public Ui_MaterialType {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATERIALTYPE_H
