#include "importallhistory.h"
#include "ui_importallhistory.h"
#include "httpclient/httpkey.h"
#include "messagebox/messagedialog.h"
#include <QRegExp>

/*********************  构造函数       *********************/
ImportAllHistory::ImportAllHistory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImportAllHistory)
  ,titleBar(NULL), importType(0)
{
    ui->setupUi(this);
    this->initControl();
}

/*********************  析构函数       *********************/
ImportAllHistory::~ImportAllHistory()
{
    delete ui;
}

/*********************  显示窗口       *********************/
void ImportAllHistory::showWidget()
{
    titleBar->setTitle(GLOBALDEF::IMPORTHISTORY);
    this->show();
}

/*********************  初始化控件       *********************/
void ImportAllHistory::initControl()
{
    titleBar = new TitleBar(this);
    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    SETTABLEWIDGET(ui->tableWidgetData);
}

/*********************  改变事件        *********************/
void ImportAllHistory::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  设置订单列表      *********************/
void ImportAllHistory::setDataMapList(const MapList &value)
{
    ui->tableWidgetData->clearContents();
    dataMapList = value;

    ui->tableWidgetData->setRowCount(dataMapList.size());
    if(importType == PURTYPE)
    {
        ui->tableWidgetData->setHorizontalHeaderItem(TWO, DATA(tr("要求到货日")));
        for(int i = 0; i < dataMapList.size(); i ++)
        {
            ui->tableWidgetData->setItem(i, ZERO,  DATA(dataMapList.at(i).value(HTTPKEY::SUPPLIERNAME)));
            ui->tableWidgetData->setItem(i, ONE,   DATA(dataMapList.at(i).value(HTTPKEY::PURCHASENUMBER)));
            ui->tableWidgetData->setItem(i, TWO,   DATA(QDateTime::fromTime_t(dataMapList.at(i).value(HTTPKEY::ARRIVALTIME).toUInt()).toString("yyyy-MM-dd")));
            ui->tableWidgetData->setItem(i, THREE, DATA(dataMapList.at(i).value(HTTPKEY::PURCHASESTATE) == "0" ? tr("未提交") : tr("采购完成")));

            ui->tableWidgetData->item(i, THREE)->setFont(QFont("ZYSong", 12, QFont::Bold));

            switch(dataMapList.at(i).value(HTTPKEY::PURCHASESTATE).toInt())
            {
            case ZERO:  ui->tableWidgetData->item(i, THREE)->setTextColor(Qt::darkBlue); break;
            case ONE:   ui->tableWidgetData->item(i, THREE)->setTextColor(Qt::darkGreen); break;
            }

            SETTABLECENTER(ui->tableWidgetData->item(i, ZERO));
            SETTABLECENTER(ui->tableWidgetData->item(i, ONE));
            SETTABLECENTER(ui->tableWidgetData->item(i, TWO));
            SETTABLECENTER(ui->tableWidgetData->item(i, THREE));
        }
    }
    else
    {
        ui->tableWidgetData->setHorizontalHeaderItem(TWO, DATA(tr("入库日期")));
        for(int i = 0; i < dataMapList.size(); i ++)
        {
            ui->tableWidgetData->setItem(i, ZERO, DATA(dataMapList.at(i).value(HTTPKEY::SUPPLIERNAME)));
            ui->tableWidgetData->setItem(i, ONE,  DATA(dataMapList.at(i).value(HTTPKEY::STORAGENUMBER)));
            ui->tableWidgetData->setItem(i, TWO,  DATA(QDateTime::fromTime_t(dataMapList.at(i).value(HTTPKEY::ARRIVALTIME).toUInt()).toString("yyyy-MM-dd")));

            QString statusStr;

            switch(dataMapList.at(i).value(HTTPKEY::STORAGESTATE).toInt())
            {
            case ZERO:  statusStr = tr("配送中"); break;
            case ONE:   statusStr = tr("已收货"); break;
            case TWO:   statusStr = tr("已拒绝"); break;
            case THREE: statusStr = tr("未提交"); break;
            case FOUR:  statusStr = tr("验收中"); break;
            }

            ui->tableWidgetData->setItem(i, THREE, DATA(statusStr));

            ui->tableWidgetData->item(i, THREE)->setFont(QFont("ZYSong", 12, QFont::Bold));

            switch(dataMapList.at(i).value(HTTPKEY::STORAGESTATE).toInt())
            {
            case ZERO:  ui->tableWidgetData->item(i, THREE)->setTextColor(Qt::darkBlue); break;
            case ONE:   ui->tableWidgetData->item(i, THREE)->setTextColor(Qt::darkGreen); break;
            case TWO:   ui->tableWidgetData->item(i, THREE)->setTextColor(Qt::darkRed); break;
            case THREE: ui->tableWidgetData->item(i, THREE)->setTextColor(Qt::darkBlue); break;
            case FOUR:  ui->tableWidgetData->item(i, THREE)->setTextColor(Qt::darkGreen); break;
            }

            SETTABLECENTER(ui->tableWidgetData->item(i, ZERO));
            SETTABLECENTER(ui->tableWidgetData->item(i, ONE));
            SETTABLECENTER(ui->tableWidgetData->item(i, TWO));
            SETTABLECENTER(ui->tableWidgetData->item(i, THREE));
        }
    }

    ui->tableWidgetData->scrollToBottom();
}

/*********************  导入历史订单      *********************/
void ImportAllHistory::on_pushButtonImport_clicked()
{
    if(NULL == ui->tableWidgetData->currentItem()) return;
    int currentRow = ui->tableWidgetData->currentRow();
    if(currentRow >= dataMapList.size()) return;

    QByteArray byteArray;

    if(importType == PURTYPE)
    {
        byteArray.append(POSTARG::IMPORTPUR.arg(dataMapList.at(currentRow).value(HTTPKEY::PURCHASENUMBER)));

        HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_STO_COPY_ORDER), byteArray, PROTOCOL::URL_STO_COPY_ORDER);
    }
    else if(importType == STOTYPE)
    {
        byteArray.append(POSTARG::IMPORTSTO.arg(dataMapList.at(currentRow).value(HTTPKEY::STORAGENUMBER)));
        HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_STO_COPY_ORDER), byteArray, PROTOCOL::URL_STO_COPY_ORDER);
    }

    this->close();
}

/*********************  取消按钮      *********************/
void ImportAllHistory::on_pushButtonCancel_clicked()
{
    this->close();
}

/*********************  设置导入类型      *********************/
void ImportAllHistory::setImportType(int value)
{
    importType = value;
}
