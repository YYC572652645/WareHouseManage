﻿#include "materialretinfo.h"
#include "ui_materialretinfo.h"
#include "httpclient/httpkey.h"
#include "messagebox/messagedialog.h"


/*********************  构造函数        *********************/
MaterialRetInfo::MaterialRetInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::materialretinfo)
  ,usefulNumber(0)
  ,hideFlage(false)

{
    ui->setupUi(this);
    this->initControl();
}

/*********************  析构函数        *********************/
MaterialRetInfo::~MaterialRetInfo()
{
    delete ui;
}

/*********************  显示窗口        *********************/
void MaterialRetInfo::showWidget()
{
    titleBar->setTitle(GLOBALDEF::MATERIALINFO);
    this->show();
}

/*********************  设置控件数据        *********************/
void MaterialRetInfo::setControlData()
{
    for(int i = 0; i < widgetList.size(); i ++)
    {
        for(int j = 0; j < widgetList.at(i).size(); j ++)
        {
            mainLayout->removeWidget(widgetList.at(i).at(j));
            SAFEDELETE(widgetList[i][j]);
        }
    }

    widgetList.clear();
    labelMainList.clear();
    labelSideList.clear();
    delButtonList.clear();
    mainSpinList.clear();
    sideSpinList.clear();
    mainLineEditList.clear();
    sideLineEditList.clear();

    usefulNumber = matMap.value(HTTPKEY::RETURNSAMOUNT).toDouble();
    if(assistantMapList.size() > ONE)
    {
        for(int i = 0; i < assistantMapList.size(); i ++)
        {
            ListWidget listWidgetData = this->createControl(i);

            if(listWidgetData.size() >= 0)
            {
                widgetList.append(listWidgetData);
            }
        }
    }

    ui->comboBoxUnit->clear();
    for(int i = 0; i < unitMapList.size(); i ++)
    {
        QString unitName = unitMapList.at(i).value(HTTPKEY::NAME);
        ui->comboBoxUnit->addItem(unitName);

        if(unitMapList.at(i).value(HTTPKEY::UNITID) == matMap.value(HTTPKEY::RETURNSUNIT))
        {
            ui->comboBoxUnit->setCurrentText(unitName);
            ui->labelNumber->setText(tr("退货数量(%1)").arg(unitName));

            for(int i = 0; i < labelSideList.size(); i ++)
            {
                labelSideList.at(i)->setText(tr("退货数量(%1)").arg(unitName));
            }
        }
    }

    for(int i = 0; i < delButtonList.size(); i ++)
    {
        connect(delButtonList[i], SIGNAL(clicked()), this, SLOT(delWareHouse()));
    }

    for(int i = 0; i < sideSpinList.size(); i ++)
    {
        connect(sideSpinList[i], SIGNAL(valueChanged(double)), this, SLOT(valueChange(double)));
    }

    ui->lineEditBarCode->setText(matMap.value(HTTPKEY::BARCODE));
    ui->lineEditWareHouse->setText(matMap.value(HTTPKEY::WAREHOUSENAME));
    ui->lineEditMatName->setText(matMap.value(HTTPKEY::MATERIALNAME));
    ui->spinBoxPrice->setValue(matMap.value(HTTPKEY::RETURNSPRICE).toDouble());
    ui->spinBoxNumber->setValue(matMap.value(HTTPKEY::RETURNSAMOUNT).toDouble());
    ui->lineEditTotalMoney->setText(matMap.value(HTTPKEY::TOTALMONEY));
    ui->lineEditReason->setText(matMap.value(HTTPKEY::RETURNSCAUSE));

    if(hideFlage)
    {
        for(int i = 0; i < delButtonList.size(); i ++)
        {
            delButtonList.at(i)->setHidden(true);
        }

        for(int i = 0; i < mainSpinList.size(); i ++)
        {
            mainSpinList.at(i)->setEnabled(false);
        }

        for(int i = 0; i < sideSpinList.size(); i ++)
        {
            sideSpinList.at(i)->setEnabled(false);
        }
    }
}

/*********************  设置隐藏        *********************/
void MaterialRetInfo::setHide()
{
    ui->pushButtonDel->setHidden(true);
    ui->pushButtonCancel->setHidden(true);
    ui->pushButtonSave->setHidden(true);
    ui->pushButtonAddNew->setHidden(true);

    ui->comboBoxUnit->setEnabled(false);
    ui->spinBoxNumber->setEnabled(false);
    ui->spinBoxPrice->setEnabled(false);
    ui->lineEditReason->setEnabled(false);

    hideFlage = true;
}

/*********************  设置显示        *********************/
void MaterialRetInfo::setShow()
{
    ui->pushButtonDel->show();
    ui->pushButtonCancel->show();
    ui->pushButtonSave->show();
    ui->pushButtonAddNew->show();

    ui->comboBoxUnit->setEnabled(true);
    ui->spinBoxNumber->setEnabled(true);
    ui->spinBoxPrice->setEnabled(true);
    ui->lineEditReason->setEnabled(true);

    hideFlage = false;
}

/*********************  可以分仓        *********************/
void MaterialRetInfo::canSubOpstion()
{
    QByteArray byteArray;

    QString strPost = POSTARG::UPDATERETSIDE.arg(subPosition->getWareHouseId());

    strPost = strPost.arg(subPosition->getNumberCount(), subPosition->getTotalMoney());

    strPost = strPost.arg(matMap.value(HTTPKEY::RETURNSMATERIALID));

    byteArray.append(strPost);

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_RETURN_UPDATE_SIDE), byteArray, PROTOCOL::URL_RETURN_UPDATE_SIDE);
}

/*********************  保存数据        *********************/
void MaterialRetInfo::on_pushButtonSave_clicked()
{
    if(ui->comboBoxUnit->currentIndex() >= unitMapList.size()) return;

    for(int i = 0; i < sideSpinList.size(); i ++)
    {
        if(sideSpinList.at(i)->value() <= 0)
        {
            MESSAGEBOX->showMessageBox(this, MESSAGE::NUMBERNOTZERO);
            return;
        }
    }

    QByteArray byteArray;

    QString strPost = POSTARG::UPDATERETMAT.arg(matMap.value(HTTPKEY::RETURNSMATERIALID));

    strPost = strPost.arg(unitMapList.at(ui->comboBoxUnit->currentIndex()).value(HTTPKEY::UNITID), QString::number(ui->spinBoxPrice->value()));

    strPost = strPost.arg(QString::number(ui->spinBoxNumber->value()), ui->lineEditTotalMoney->text());

    QString reasonText = ui->lineEditReason->text().isEmpty() ? "0" : ui->lineEditReason->text();
    strPost = strPost.arg(reasonText, HTTPCLIENT->makeJson(updateAssMapList));

    byteArray.append(strPost);

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_RETURN_UPDATE_MAT), byteArray, PROTOCOL::URL_RETURN_UPDATE_MAT);

    this->close();
}

/*********************  取消事件        *********************/
void MaterialRetInfo::on_pushButtonCancel_clicked()
{
    this->close();
}

/*********************  初始化控件       *********************/
void MaterialRetInfo::initControl()
{
    titleBar = new TitleBar(this);
    mainWidget = ui->scrollAreaWidgetContents;

    mainLayout = ui->verticalLayout;

    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    ui->comboBoxUnit->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxUnit->setView(new QListView());

    subPosition = new SubRetPosition(this);
}

/*********************  创建控件        *********************/
ListWidget MaterialRetInfo::createControl(int index)
{
    ListWidget listWidgetData;
    if(index < 0 || index >= assistantMapList.size()) return listWidgetData;

    mainLayout->removeWidget(ui->pushButtonAddNew);
    mainLayout->removeWidget(ui->widgetControl);
    if(index != 0)
    {
        QFrame *line = new QFrame(this);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line->raise();

        QPalette palette = line->palette();
        palette.setColor(QPalette::Dark, Qt::darkRed);
        line->setPalette(palette);

        listWidgetData.append(line);
        mainLayout->addWidget(line);

        QWidget *widgetSide = new QWidget(this);
        QHBoxLayout *hboxLayoutSide = new QHBoxLayout(widgetSide);
        QLabel *labelSide = new QLabel(this);
        QPushButton *pushButtonDel = new QPushButton(this);
        delButtonList.append(pushButtonDel);
        pushButtonDel->setIcon(QIcon(":/image/image/删 除.png"));
        pushButtonDel->setFixedSize(20,20);

        labelSide->setText(tr("分仓退货仓库：  %1  ").arg(assistantMapList.at(index).value(HTTPKEY::WAREHOUSENAME)));
        labelSide->setAlignment(Qt::AlignCenter);

        hboxLayoutSide->addWidget(labelSide);
        hboxLayoutSide->addWidget(pushButtonDel);
        widgetSide->setLayout(hboxLayoutSide);
        mainLayout->addWidget(widgetSide);
        listWidgetData.append(widgetSide);
        labelSide->setStyleSheet("QLabel{background-color:white;font-size:14px;font-weight:bold;}");

        QLabel *labelSideNumber = new QLabel(this);
        QDoubleSpinBox *spinBoxSideNumber = new QDoubleSpinBox(this);
        QWidget *widgetSideNumber = new QWidget(this);
        QHBoxLayout *hboxLayoutSideNumber = new QHBoxLayout(widgetSideNumber);

        labelSideNumber->setText(tr("退货数量"));
        labelSideList.append(labelSideNumber);
        spinBoxSideNumber->setMaximum(100000);
        spinBoxSideNumber->setFixedSize(220, 30);
        spinBoxSideNumber->setValue(assistantMapList.at(index).value(HTTPKEY::NUMBER).toDouble());
        hboxLayoutSideNumber->addWidget(labelSideNumber);
        hboxLayoutSideNumber->addWidget(spinBoxSideNumber);
        widgetSideNumber->setLayout(hboxLayoutSideNumber);
        mainLayout->addWidget(widgetSideNumber);
        listWidgetData.append(widgetSideNumber);
        sideSpinList.append(spinBoxSideNumber);

        QLabel *labelSideMoney = new QLabel(this);
        QLineEdit *lineEditSideMoney = new QLineEdit(this);
        QWidget *widgetSideMoney = new QWidget(this);
        QHBoxLayout *hboxLayoutSideMoney = new QHBoxLayout(widgetSideMoney);

        labelSideMoney->setText(tr("金额(元)"));
        lineEditSideMoney->setFixedSize(220, 30);
        lineEditSideMoney->setText(assistantMapList.at(index).value(HTTPKEY::TOTALMONEY));
        lineEditSideMoney->setEnabled(false);
        hboxLayoutSideMoney->addWidget(labelSideMoney);
        hboxLayoutSideMoney->addWidget(lineEditSideMoney);
        widgetSideMoney->setLayout(hboxLayoutSideMoney);
        mainLayout->addWidget(widgetSideMoney);
        listWidgetData.append(widgetSideMoney);
        sideLineEditList.append(lineEditSideMoney);
        mainLayout->addWidget(ui->pushButtonAddNew);
        mainLayout->addWidget(ui->widgetControl);
        mainWidget->setLayout(mainLayout);
        ui->scrollAreaSide->setWidget(mainWidget);
    }
    else
    {
        QLabel *labelMain = new QLabel(this);
        labelMain->setText(tr("主退货仓库：  %1  ").arg(matMap.value(HTTPKEY::WAREHOUSENAME)));
        labelMain->setAlignment(Qt::AlignCenter);
        mainLayout->addWidget(labelMain);
        listWidgetData.append(labelMain);
        labelMain->setStyleSheet("QLabel{background-color:white;font-size:14px;font-weight:bold;}");

        QLabel *labelMainNumber = new QLabel(this);
        QDoubleSpinBox *spinBoxMainNumber = new QDoubleSpinBox(this);
        QWidget *widgetMainNumber = new QWidget(this);
        QHBoxLayout *hboxLayoutMainNumber = new QHBoxLayout(widgetMainNumber);

        labelMainList.append(labelMainNumber);
        labelMainNumber->setText(tr("退货数量"));
        spinBoxMainNumber->setFixedSize(220, 30);
        spinBoxMainNumber->setEnabled(false);
        spinBoxMainNumber->setMaximum(100000);

        double tempValue = matMap.value(HTTPKEY::RETURNSAMOUNT).toDouble();
        for(int i = 1; i < assistantMapList.size(); i ++)
        {
            tempValue -= assistantMapList.at(i).value(HTTPKEY::NUMBER).toDouble();
        }

        usefulNumber = tempValue;
        spinBoxMainNumber->setValue(tempValue);

        hboxLayoutMainNumber->addWidget(labelMainNumber);
        hboxLayoutMainNumber->addWidget(spinBoxMainNumber);
        widgetMainNumber->setLayout(hboxLayoutMainNumber);
        mainLayout->addWidget(widgetMainNumber);
        listWidgetData.append(widgetMainNumber);
        mainSpinList.append(spinBoxMainNumber);

        QWidget *widgetMainMoney = new QWidget(this);
        QHBoxLayout *hboxLayoutMainMoney = new QHBoxLayout(widgetMainMoney);
        QLabel *labelMainMoney = new QLabel(this);
        QLineEdit *lineEditMainMoney = new QLineEdit(this);

        labelMainMoney->setText(tr("金额(元)"));
        lineEditMainMoney->setFixedSize(220, 30);
        lineEditMainMoney->setEnabled(false);
        lineEditMainMoney->setText(assistantMapList.at(index).value(HTTPKEY::TOTALMONEY));
        hboxLayoutMainMoney->addWidget(labelMainMoney);
        hboxLayoutMainMoney->addWidget(lineEditMainMoney);
        widgetMainMoney->setLayout(hboxLayoutMainMoney);
        mainLayout->addWidget(widgetMainMoney);
        listWidgetData.append(widgetMainMoney);
        mainLineEditList.append(lineEditMainMoney);
    }

    return listWidgetData;
}

/*********************  改变事件        *********************/
void MaterialRetInfo::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  设置分仓库        *********************/
void MaterialRetInfo::setAssistantMapList(const MapList &value)
{
    assistantMapList = value;
    updateAssMapList = assistantMapList;
}

/*********************  删除仓库        *********************/
void MaterialRetInfo::delWareHouse()
{
    QPushButton *pButton = qobject_cast<QPushButton *>(sender());

    for(int i = 0; i < delButtonList.size(); i ++)
    {
        if(pButton == delButtonList[i])
        {
            if(i + 1 < assistantMapList.size())
            {
                QByteArray byteArray;

                QString strPost = POSTARG::DELETESIDERET.arg(matMap.value(HTTPKEY::RETURNSMATERIALID));

                strPost = strPost.arg(matMap.value(HTTPKEY::WAREHOUSEID));

                strPost = strPost.arg(assistantMapList.at(i + 1).value(HTTPKEY::RETURNSWAREHOUSEID));

                strPost = strPost.arg(assistantMapList.at(i + 1).value(HTTPKEY::NUMBER));

                if(i < sideLineEditList.size())
                strPost = strPost.arg(sideLineEditList.at(i)->text());

                byteArray.append(strPost);

                HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_RETURN_DEL_SIDE), byteArray, PROTOCOL::URL_RETURN_DEL_SIDE);
            }
        }
    }
}

/*********************  数值改变        *********************/
void MaterialRetInfo::valueChange(double value)
{
    QDoubleSpinBox *pSpinBox = qobject_cast<QDoubleSpinBox *>(sender());

    for(int i = 0; i < sideSpinList.size(); i ++)
    {
        if(pSpinBox == sideSpinList[i])
        {
            double totalSum = 0;
            double otherSum = 0;
            for(int j = 0; j < sideSpinList.size(); j ++)
            {
                totalSum += sideSpinList.at(j)->value();

                if(j != i) otherSum += sideSpinList.at(j)->value();
            }

            if(ui->spinBoxNumber->value() >= totalSum)
            {
                mainSpinList.at(0)->setValue(ui->spinBoxNumber->value() - totalSum);
            }
            else
            {
                sideSpinList.at(i)->setValue(ui->spinBoxNumber->value() - otherSum);
            }

            for(int i = 0; i < sideLineEditList.size(); i ++)
            {
                sideLineEditList.at(i)->setText(QString::number(sideSpinList.at(i)->value() * ui->spinBoxPrice->value()));

                if(i + 1 < updateAssMapList.size())
                {
                    updateAssMapList[i + 1][HTTPKEY::NUMBER] = QString::number(sideSpinList.at(i)->value());
                    updateAssMapList[i + 1][HTTPKEY::TOTALMONEY] = QString::number(sideSpinList.at(i)->value() * ui->spinBoxPrice->value());
                }
            }

            for(int i = 0; i < mainLineEditList.size(); i ++)
            {
                mainLineEditList.at(i)->setText(QString::number(mainSpinList.at(i)->value() * ui->spinBoxPrice->value()));
                updateAssMapList[i][HTTPKEY::NUMBER] = QString::number(mainSpinList.at(i)->value());
                updateAssMapList[i][HTTPKEY::TOTALMONEY] = QString::number(mainSpinList.at(i)->value() * ui->spinBoxPrice->value());
            }
        }
    }
}

/*********************  设置原料        *********************/
void MaterialRetInfo::setMatMap(const Map &value)
{
    matMap = value;
}

/*********************  设置控件是否可用        *********************/
void MaterialRetInfo::setControlEnable(bool flage)
{
    ui->spinBoxNumber->setEnabled(flage);
    ui->spinBoxPrice->setEnabled(flage);
    ui->comboBoxUnit->setEnabled(flage);
}

/*********************  设置单位列表        *********************/
void MaterialRetInfo::setUnitMapList(const MapList &value)
{
    unitMapList = value;
}

/*********************  单位点击        *********************/
void MaterialRetInfo::on_comboBoxUnit_activated(const QString &arg1)
{
    ui->labelNumber->setText(tr("退货数量(%1)").arg(arg1));

    for(int i = 0; i < labelMainList.size(); i ++)
    {
        labelMainList.at(i)->setText(tr("退货数量(%1)").arg(arg1));
    }

    for(int i = 0; i < labelSideList.size(); i ++)
    {
        labelSideList.at(i)->setText(tr("退货数量(%1)").arg(arg1));
    }
}

/*********************  数量改变        *********************/
void MaterialRetInfo::on_spinBoxNumber_valueChanged(double arg1)
{
    QString totalMoney = QString::number(ui->spinBoxPrice->value() * arg1);

    ui->lineEditTotalMoney->setText(totalMoney);

    for(int i = 0; i < mainSpinList.size(); i ++)
    {
        mainSpinList.at(i)->setValue(arg1 - sideSpinList.at(i)->value());
    }

    for(int i = 0; i < sideLineEditList.size(); i ++)
    {
        sideLineEditList.at(i)->setText(QString::number(sideSpinList.at(i)->value() * ui->spinBoxPrice->value()));

        if(i + 1 < updateAssMapList.size())
        {
            updateAssMapList[i + 1][HTTPKEY::NUMBER] = QString::number(sideSpinList.at(i)->value());
            updateAssMapList[i + 1][HTTPKEY::TOTALMONEY] = QString::number(sideSpinList.at(i)->value() * ui->spinBoxPrice->value());
        }
    }

    if(mainLineEditList.size() != 0)
    {
        for(int i = 0; i < mainLineEditList.size(); i ++)
        {
            mainLineEditList.at(i)->setText(QString::number(mainSpinList.at(i)->value() * ui->spinBoxPrice->value()));
            updateAssMapList[i][HTTPKEY::NUMBER] = QString::number(mainSpinList.at(i)->value());
            updateAssMapList[i][HTTPKEY::TOTALMONEY] = QString::number(mainSpinList.at(i)->value() * ui->spinBoxPrice->value());
        }
    }
    else
    {
        if(updateAssMapList.size() != 0)
        {
            updateAssMapList[ZERO][HTTPKEY::NUMBER] = QString::number(ui->spinBoxNumber->value());
            updateAssMapList[ZERO][HTTPKEY::TOTALMONEY] = ui->lineEditTotalMoney->text();
        }
    }
}

/*********************  删除原料        *********************/
void MaterialRetInfo::on_pushButtonDel_clicked()
{
    QByteArray byteArray;

    List listId;

    listId.append(matMap.value(HTTPKEY::RETURNSMATERIALID));

    byteArray.append(POSTARG::RETDELMAT.arg(HTTPCLIENT->makeJson(listId)));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_RETURN_DEL_MAT), byteArray, PROTOCOL::URL_RETURN_DEL_MAT);

    this->close();
}

/*********************  添加分仓        *********************/
void MaterialRetInfo::on_pushButtonAddNew_clicked()
{
    QString unitName = ui->comboBoxUnit->currentText();

    qDebug()<<"usefulNumber"<<usefulNumber;
    if(usefulNumber <= 0)
    {
        MESSAGEBOX->showMessageBox(this, MESSAGE::NOSTOERROR);

        return;
    }

    QString numberCount = QString::number(usefulNumber);

    QString priceName = QString::number(ui->spinBoxPrice->value());
    QString returnsMatId = matMap.value(HTTPKEY::RETURNSMATERIALID);

    subPosition->setUnitName(unitName);
    subPosition->setNumberCount(numberCount);
    subPosition->setPriceName(priceName);
    subPosition->setStoMatId(returnsMatId);

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_RETURN_SEL_SIDE).arg(unitName, numberCount, priceName, returnsMatId), PROTOCOL::URL_RETURN_SEL_SIDE);
}

/*********************  获取添加仓库对象        *********************/
SubRetPosition *MaterialRetInfo::getSubPosition() const
{
    return subPosition;
}

/*********************  单价改变        *********************/
void MaterialRetInfo::on_spinBoxPrice_valueChanged(double arg1)
{
    QString totalMoney = QString::number(ui->spinBoxNumber->value() * arg1);
    ui->lineEditTotalMoney->setText(totalMoney);

    for(int i = 0; i < sideLineEditList.size(); i ++)
    {
        sideLineEditList.at(i)->setText(QString::number(sideSpinList.at(i)->value() * arg1));

        if(i + 1 < updateAssMapList.size())
        {
            updateAssMapList[i + 1][HTTPKEY::NUMBER] = QString::number(sideSpinList.at(i)->value());
            updateAssMapList[i + 1][HTTPKEY::TOTALMONEY] = QString::number(sideSpinList.at(i)->value() * ui->spinBoxPrice->value());
        }
    }

    if(mainLineEditList.size() != 0)
    {
        for(int i = 0; i < mainLineEditList.size(); i ++)
        {
            mainLineEditList.at(i)->setText(QString::number(mainSpinList.at(i)->value() * ui->spinBoxPrice->value()));
            updateAssMapList[i][HTTPKEY::NUMBER] = QString::number(mainSpinList.at(i)->value());
            updateAssMapList[i][HTTPKEY::TOTALMONEY] = QString::number(mainSpinList.at(i)->value() * ui->spinBoxPrice->value());
        }
    }
    else
    {
        if(updateAssMapList.size() != 0)
        {
            updateAssMapList[ZERO][HTTPKEY::NUMBER] = QString::number(ui->spinBoxNumber->value());
            updateAssMapList[ZERO][HTTPKEY::TOTALMONEY] = ui->lineEditTotalMoney->text();
        }
    }


}