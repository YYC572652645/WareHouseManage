#include "realtimeinventory.h"
#include "ui_realtimeinventory.h"
#include "httpclient/httpkey.h"
#include "messagebox/messagedialog.h"

/************************   构造函数            ********************/
RealTimeInventory::RealTimeInventory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RealTimeInventory)
{
    ui->setupUi(this);

    this->initControl();
}

/************************   析构函数            ********************/
RealTimeInventory::~RealTimeInventory()
{
    delete ui;
}

/*********************  显示窗口       *********************/
void RealTimeInventory::showWidget()
{
    this->show();
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_TIME_MAT_LIST), PROTOCOL::URL_TIME_MAT_LIST);
}

/*********************  初始化控件       *********************/
void RealTimeInventory::initControl()
{
    SETTABLEWIDGET(ui->tableWidgetData);

    timeMatInfo = new TimeMatInfo(this);

    exportEmail = new ExportEmail(this);

    connect(exportEmail, SIGNAL(sendEmail(QString)), this, SLOT(receiveEmail(QString)));

    //根据分辨率适配
    QDesktopWidget *desktop = QApplication::desktop();

    if(desktop->height() >= GLOBALDEF::DESKTOPHEIGHT)
    {
        this->setStyleSheet(GLOBALDEF::THISSTYLE);
    }
    else
    {
        this->setStyleSheet(GLOBALDEF::SMALLSTYLE);
    }
}

/************************   解析JSON            *********************/
void RealTimeInventory::readJson(QNetworkReply *reply, int type)
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

        qDebug()<<QString(arrayData);
        if(err.error == QJsonParseError::NoError)
        {
            QJsonObject jsonObject = jsonDom.object();

            if(jsonObject.contains(HTTPKEY::CODE))  codeValue = jsonObject.value(HTTPKEY::CODE).toInt();

            QString errorMsg;
            if(jsonObject.contains(HTTPKEY::MSG))
            {
                QJsonObject jsonNextObj = jsonObject.value(HTTPKEY::MSG).toObject();

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

                if(type == PROTOCOL::URL_TIME_MAT_LIST)
                {
                    if(ISERROR(codeValue))
                    {
                        ui->tableWidgetData->clearContents();
                        ui->tableWidgetData->setRowCount(0);
                        matMapList.clear();
                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, matMapList);

                    this->setControlData();
                }
                else if(type == PROTOCOL::URL_TIME_SEL_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }


                    MapList mapListData;
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::LIST, mapListData);
                    timeMatInfo->setMapListData(mapListData);

                    Map mapData;
                    HTTPCLIENT->readJsonMap(jsonObject, HTTPKEY::MSG, mapData);
                    timeMatInfo->setMaterialName(mapData.value(HTTPKEY::MATERIALNAME));

                    timeMatInfo->showWidget();
                }
                else if(type == PROTOCOL::URL_TIME_SEND_EMAIL)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::EXTENDERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::EXPORTSUCCESS, true);
                }
            }
        }
    }
    reply->close();
}


/************************   设置控件数据            *********************/
void RealTimeInventory::setControlData()
{
    ui->labelSize->setText(GLOBALDEF::TOTALONUMBER.arg(matMapList.size()));
    ui->tableWidgetData->clearContents();
    ui->tableWidgetData->setRowCount(matMapList.size());
    for(int i = 0; i < matMapList.size(); i ++)
    {
        ui->tableWidgetData->setItem(i, ZERO,  DATA(matMapList.at(i).value(HTTPKEY::MATERIALNAME)));
        ui->tableWidgetData->setItem(i, ONE,   DATA(matMapList.at(i).value(HTTPKEY::BARCODE)));
        ui->tableWidgetData->setItem(i, TWO,   DATA(matMapList.at(i).value(HTTPKEY::SUMTOTALMONEY) + tr("元")));
        ui->tableWidgetData->setItem(i, THREE, DATA(matMapList.at(i).value(HTTPKEY::SUMNUMBER)));
        ui->tableWidgetData->setItem(i, FOUR,  DATA(matMapList.at(i).value(HTTPKEY::UNITNAME)));
        ui->tableWidgetData->setItem(i, FIVE,  DATA(matMapList.at(i).value(HTTPKEY::HINT)));

        ui->tableWidgetData->item(i, FIVE)->setFont(QFont("ZYSong", 12, QFont::Bold));
        ui->tableWidgetData->item(i, FIVE)->setTextColor(Qt::darkRed);

        SETTABLECENTER(ui->tableWidgetData->item(i, ZERO));
        SETTABLECENTER(ui->tableWidgetData->item(i, ONE));
        SETTABLECENTER(ui->tableWidgetData->item(i, TWO));
        SETTABLECENTER(ui->tableWidgetData->item(i, THREE));
        SETTABLECENTER(ui->tableWidgetData->item(i, FOUR));
        SETTABLECENTER(ui->tableWidgetData->item(i, FIVE));
    }
    ui->tableWidgetData->scrollToBottom();
}

/************************   双击事件            *********************/
void RealTimeInventory::on_tableWidgetData_doubleClicked(const QModelIndex &index)
{
    if(index.row() >= matMapList.size()) return;

    QString materialId = matMapList.at(index.row()).value(HTTPKEY::MATERIALID);

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_TIME_SEL_MAT).arg(materialId), PROTOCOL::URL_TIME_SEL_MAT);
}

/************************   导出到邮箱           *********************/
void RealTimeInventory::on_pushButtonExport_clicked()
{
    exportEmail->showWidget();
}

/************************   接收邮箱地址           *********************/
void RealTimeInventory::receiveEmail(QString emailText)
{
    QByteArray byteArray;

    byteArray.append(POSTARG::EXPORTEMAIL.arg(emailText));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_TIME_SEND_EMAIL), byteArray, PROTOCOL::URL_TIME_SEND_EMAIL);
}
