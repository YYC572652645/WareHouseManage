#include "inventorylog.h"
#include "ui_inventorylog.h"
#include "httpclient/httpkey.h"

/*********************  构造函数       *********************/
InventoryLog::InventoryLog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InventoryLog)
{
    ui->setupUi(this);

    this->initControl();
}

/*********************  析构函数       *********************/
InventoryLog::~InventoryLog()
{
    delete ui;

    SAFEDELETE(titleBar);
}

/*********************  显示窗口       *********************/
void InventoryLog::showWidget()
{
    titleBar->setTitle(GLOBALDEF::INVENLOG);
    this->show();
}

/*********************  初始化控件       *********************/
void InventoryLog::initControl()
{
    titleBar = new TitleBar(this);
    inventoryDet = new InventoryDet(this);

    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    SETTABLEWIDGET(ui->tableWidget);
}

/*********************  改变事件        *********************/
void InventoryLog::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  设置时间        *********************/
void InventoryLog::setListData(const List &value)
{
    listData = value;
}

/*********************  设置控件数据        *********************/
void InventoryLog::setControlData()
{
    ui->lineEditMatName->setText(mapData.value(HTTPKEY::NAME));
    ui->lineEditBarCode->setText(mapData.value(HTTPKEY::BARCODE));

    if(listData.size() >= 2)
    {
        ui->lineEditStartTime->setText(QDateTime::fromTime_t(listData.at(ZERO).toUInt()).toString("yyyy-MM-dd"));
        ui->lineEditEndTime->setText(QDateTime::fromTime_t(listData.at(ONE).toUInt()).toString("yyyy-MM-dd"));
    }

    ui->tableWidget->setRowCount(orderMapList.size());

    for(int i = 0; i < orderMapList.size(); i ++)
    {
        ui->tableWidget->setItem(i, ZERO,  DATA(orderMapList.at(i).value(HTTPKEY::CODE)));
        ui->tableWidget->setItem(i, ONE,   DATA(orderMapList.at(i).value(HTTPKEY::WAREHOUSENAME)));
        ui->tableWidget->setItem(i, TWO,   DATA(orderMapList.at(i).value(HTTPKEY::NUMBER) + orderMapList.at(i).value(HTTPKEY::UNITNAME)));
        ui->tableWidget->setItem(i, THREE, DATA(QDateTime::fromTime_t(orderMapList.at(i).value(HTTPKEY::REALITYTIME).toUInt()).toString("yyyy-MM-dd hh:mm:ss")));


        SETTABLECENTER(ui->tableWidget->item(i, ZERO));
        SETTABLECENTER(ui->tableWidget->item(i, ONE));
        SETTABLECENTER(ui->tableWidget->item(i, TWO));
        SETTABLECENTER(ui->tableWidget->item(i, THREE));
    }
}


/*********************  设置原料数据        *********************/
void InventoryLog::setMapData(const Map &value)
{
    mapData = value;
}

/*********************  设置库存单数据        *********************/
void InventoryLog::setOrderMapList(const MapList &value)
{
    orderMapList = value;
}

/*********************  双击控件        *********************/
void InventoryLog::on_tableWidget_doubleClicked(const QModelIndex &index)
{
    if(index.row() < 0 || index.row() >= orderMapList.size()) return;

    QString wareHouseId = orderMapList.at(index.row()).value(HTTPKEY::WAREHOUSEID);
    QString materialId = mapData.value(HTTPKEY::MATERIALID);
    QString number = orderMapList.at(index.row()).value(HTTPKEY::ORDERNUMBER);
    QString realityTime = orderMapList.at(index.row()).value(HTTPKEY::REALITYTIME);

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_CHANCE_GET_MAT).arg(wareHouseId, materialId, number, realityTime), PROTOCOL::URL_CHANCE_GET_MAT);
}

/*********************  获取详情        *********************/
InventoryDet *InventoryLog::getInventoryDet()
{
    return inventoryDet;
}
