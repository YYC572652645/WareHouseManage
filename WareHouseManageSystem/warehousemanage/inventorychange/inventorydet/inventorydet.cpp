#include "inventorydet.h"
#include "ui_inventorydet.h"
#include "httpclient/httpkey.h"

/*********************  构造函数        *********************/
InventoryDet::InventoryDet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InventoryDet)
{
    ui->setupUi(this);

    this->initControl();
}

/*********************  析构函数        *********************/
InventoryDet::~InventoryDet()
{
    delete ui;
    SAFEDELETE(titleBar);
}

/*********************  设置控件数据       *********************/
void InventoryDet::setControlData()
{
    ui->lineEditWareHouseName->setText(mapData.value(HTTPKEY::WAREHOUSENAME));
    ui->lineEditMatName->setText(mapData.value(HTTPKEY::MATERIALNAME));
    ui->lineEditBarCode->setText(mapData.value(HTTPKEY::BARCODE));
    ui->lineEditOperType->setText(mapData.value(HTTPKEY::OPERATIONNAME));
    ui->lineEditNumber->setText(mapData.value(HTTPKEY::ODDNUMBERS));
    ui->lineEditChangeCount->setText(mapData.value(HTTPKEY::NUMBER));
    ui->lineEditOperPeople->setText(mapData.value(HTTPKEY::USERNAME));
    ui->lineEditOperTime->setText(QDateTime::fromTime_t(mapData.value(HTTPKEY::TIME1).toUInt()).toString("yyyy-MM-dd hh:mm:ss"));
    ui->lineEditInvChangeTime->setText(QDateTime::fromTime_t(mapData.value(HTTPKEY::TIME2).toUInt()).toString("yyyy-MM-dd hh:mm:ss"));
}

/*********************  初始化控件       *********************/
void InventoryDet::initControl()
{
    titleBar = new TitleBar(this);

    titleBar->setTitle(GLOBALDEF::INVENCHANGE);
    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);
}

/*********************  改变事件        *********************/
void InventoryDet::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  设置数据       *********************/
void InventoryDet::setMapData(const Map &value)
{
    mapData = value;
}
