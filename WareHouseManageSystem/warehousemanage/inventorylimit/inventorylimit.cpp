#include "inventorylimit.h"
#include "ui_inventorylimit.h"
#include "messagebox/messagedialog.h"
#include "httpclient/httpkey.h"
#include <stdio.h>

/************************   构造函数         ********************/
InventoryLimit::InventoryLimit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InventoryLimit)
{
    ui->setupUi(this);

    this->initControl();
}

/************************   析构函数         ********************/
InventoryLimit::~InventoryLimit()
{
    delete ui;
}

/************************   显示窗口         ********************/
void InventoryLimit::showWidget()
{
    this->show();
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_REST_SEL_MAT), PROTOCOL::URL_REST_SEL_MAT);
}

/*********************  解析json       *********************/
void InventoryLimit::readJson(QNetworkReply *reply, int type)
{
    if(NULL == reply || reply->error() != QNetworkReply::NoError)
    {
        MAINWINDOW->setStatusInfo();
        return;
    }

    int codeValue = -1;
    if(reply->error() == QNetworkReply::NoError)
    {
        QByteArray arrayData = reply->readAll();

        QJsonParseError err;
        QJsonDocument jsonDom = QJsonDocument::fromJson(QString(arrayData).toUtf8(), &err);

        qDebug()<<"11111"<<type<<QString(arrayData);
        if(err.error == QJsonParseError::NoError)
        {
            QJsonObject jsonObject = jsonDom.object();

            if(jsonObject.contains(HTTPKEY::CODE))  codeValue = jsonObject.value(HTTPKEY::CODE).toInt();

            QString errorMsg;

            if(jsonObject.contains(HTTPKEY::MSG))
            {
                if(ISERROR(codeValue))
                {
                    if(codeValue == SUBONE)        errorMsg = MESSAGE::NOTSHOPLOGIN;
                    else if(codeValue == SUBTWO)   errorMsg = MESSAGE::NOTADMINLOGIN;
                    else if(codeValue == SUBTHREE) errorMsg = MESSAGE::NOPRIORITY;

                    if(codeValue == SUBONE || codeValue == SUBTWO || codeValue == SUBTHREE)
                    {
                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        this->setHidden(true);
                        return;
                    }
                }

                if(type == PROTOCOL::URL_REST_SEL_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        ui->tableWidget->clearContents();
                        ui->tableWidget->setRowCount(0);
                        mapListMat.clear();
                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, mapListMat);

                    this->setControlData();
                }
                else if(type == PROTOCOL::URL_REST_GET_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    Map mapData;
                    HTTPCLIENT->readJsonMap(jsonObject, HTTPKEY::MSG, mapData);
                    defaultLimitInfo->setMapMatData(mapData);
                }
                else if(type == PROTOCOL::URL_REST_UPDATE_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)      errorMsg = MESSAGE::EDITERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    showWidget();
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::EDITSUCCESS, true);
                }
            }
        }
        reply->close();
    }
}

/************************   初始化控件         ********************/
void InventoryLimit::initControl()
{
    SETTABLEWIDGET(ui->tableWidget);

    defaultLimitInfo = new DefaultLimitInfo(this);
    setDefaultLimit = new SetDefaultLimit(this);

    ui->tableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);

    //根据分辨率适配
    QDesktopWidget *desktop = QApplication::desktop();

    int minHeight = 0;
    if(desktop->height() >= GLOBALDEF::DESKTOPHEIGHT)
    {
        minHeight = 30;
        this->setStyleSheet(GLOBALDEF::THISSTYLE);
    }
    else
    {
        minHeight = 20;
        this->setStyleSheet(GLOBALDEF::SMALLSTYLE);
    }

    ui->labelSize->setMinimumHeight(minHeight);

    FlowLayout *flowLayout = new FlowLayout(ui->widgetControl);

    flowLayout->addWidget(ui->pushButtonAllSelect);
    flowLayout->addWidget(ui->pushButtonNoSelect);
    flowLayout->addWidget(ui->pushButtonSetUp);
    flowLayout->addWidget(ui->labelSize);

    ui->widgetControl->setLayout(flowLayout);
}

/************************   设置控件数据         ********************/
void InventoryLimit::setControlData()
{
    ui->labelSize->setText(GLOBALDEF::TOTALONUMBER.arg(mapListMat.size()));
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(mapListMat.size());
    for(int i = 0; i < mapListMat.size(); i ++)
    {
        ui->tableWidget->setItem(i, ZERO,  DATA(mapListMat.at(i).value(HTTPKEY::NAME)));
        ui->tableWidget->setItem(i, ONE,   DATA(mapListMat.at(i).value(HTTPKEY::BARCODE)));
        ui->tableWidget->setItem(i, TWO,   DATA(mapListMat.at(i).value(HTTPKEY::UNITNAME)));
        ui->tableWidget->setItem(i, THREE, DATA(mapListMat.at(i).value(HTTPKEY::UPPERLIMIT) == "0" ? tr("未设置") : mapListMat.at(i).value(HTTPKEY::UPPERLIMIT)));
        ui->tableWidget->setItem(i, FOUR,  DATA(mapListMat.at(i).value(HTTPKEY::LOWERLIMIT) == "0" ? tr("未设置") : mapListMat.at(i).value(HTTPKEY::LOWERLIMIT)));

        ui->tableWidget->item(i, THREE)->setFont(QFont("ZYSong", 12, QFont::Bold));
        ui->tableWidget->item(i, FOUR)->setFont(QFont("ZYSong", 12, QFont::Bold));

        if(mapListMat.at(i).value(HTTPKEY::UPPERLIMIT) == "0")
        {
            ui->tableWidget->item(i, THREE)->setTextColor(Qt::darkRed);
        }
        else
        {
            ui->tableWidget->item(i, THREE)->setTextColor(Qt::darkGreen);
        }


        if(mapListMat.at(i).value(HTTPKEY::LOWERLIMIT) == "0")
        {
            ui->tableWidget->item(i, FOUR)->setTextColor(Qt::darkRed);
        }
        else
        {
            ui->tableWidget->item(i, FOUR)->setTextColor(Qt::darkGreen);
        }

        SETTABLECENTER(ui->tableWidget->item(i, ZERO));
        SETTABLECENTER(ui->tableWidget->item(i, ONE));
        SETTABLECENTER(ui->tableWidget->item(i, TWO));
        SETTABLECENTER(ui->tableWidget->item(i, THREE));
        SETTABLECENTER(ui->tableWidget->item(i, FOUR));
    }

    ui->tableWidget->scrollToBottom();
}

/************************   双击控件         ********************/
void InventoryLimit::on_tableWidget_doubleClicked(const QModelIndex &index)
{
    if(index.row() >= mapListMat.size()) return;

    QString materialId = mapListMat.at(index.row()).value(HTTPKEY::MATERIALID);

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_REST_GET_MAT).arg(materialId), PROTOCOL::URL_REST_GET_MAT);

    defaultLimitInfo->showWidget();
}

/************************   全选         ********************/
void InventoryLimit::on_pushButtonAllSelect_clicked()
{
    ui->tableWidget->selectAll();
}

/************************   全不选         ********************/
void InventoryLimit::on_pushButtonNoSelect_clicked()
{
    for(int i = 0; i < ui->tableWidget->selectedItems().size(); i++)
    {
        ui->tableWidget->selectedItems().at(i)->setSelected(false);
    }

    setControlData();
}

/************************   批量设置         ********************/
void InventoryLimit::on_pushButtonSetUp_clicked()
{
    int rowSelectCount = ui->tableWidget->selectedItems().size() / ui->tableWidget->columnCount();

    if(rowSelectCount != 0)
    {
        int ok = MESSAGEBOX->showMessageBox(this, MESSAGE::SETSUPPLIER.arg(rowSelectCount), true, false);

        if(ok == QDialog::Accepted)
        {
            HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_DEFAULT_GET_SUP), PROTOCOL::URL_DEFAULT_GET_SUP);
            setDefaultLimit->setMatNumber(QString::number(rowSelectCount));
            setDefaultLimit->showWidget();

            MapList mapListData;
            for(int i = 0; i < ui->tableWidget->selectedItems().size(); i ++)
            {
                if(i % ui->tableWidget->columnCount() == 0)
                {
                    int currentIndex = ui->tableWidget->selectedItems().at(i)->row();
                    if(currentIndex >= mapListMat.size()) return;

                    Map mapData;

                    mapData[HTTPKEY::MATERIALID] = mapListMat.at(currentIndex).value(HTTPKEY::MATERIALID);
                    mapListData.append(mapData);
                }
            }

            setDefaultLimit->setMapListMat(mapListData);
        }
    }
    else
    {
        MESSAGEBOX->showMessageBox(this, MESSAGE::PLEASESETSUP);
    }
}

