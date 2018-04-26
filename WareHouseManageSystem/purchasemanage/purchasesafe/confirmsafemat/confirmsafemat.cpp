#include "confirmsafemat.h"
#include "ui_confirmsafemat.h"
#include "messagebox/messagedialog.h"
#include "httpclient/httpkey.h"

/*********************  构造函数       *********************/
ConfirmSafeMat::ConfirmSafeMat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConfirmSafeMat)
{
    ui->setupUi(this);
    this->initControl();
}

/*********************  析构函数       *********************/
ConfirmSafeMat::~ConfirmSafeMat()
{
    delete ui;
}

/*********************  初始化控件       *********************/
void ConfirmSafeMat::initControl()
{
    titleBar = new TitleBar(this);
    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    SETTABLEWIDGET(ui->tableWidgetData);
}

/*********************  改变事件        *********************/
void ConfirmSafeMat::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  设置原料列表       *********************/
void ConfirmSafeMat::setMapListMat(const MapList &value)
{
    mapListMat = value;

    ui->tableWidgetData->setRowCount(mapListMat.size());
    for(int i = 0; i < mapListMat.size(); i ++)
    {
        ui->tableWidgetData->setItem(i, ZERO,  DATA(mapListMat.at(i).value(HTTPKEY::MATERIALNAME)));
        ui->tableWidgetData->setItem(i, ONE,   DATA(mapListMat.at(i).value(HTTPKEY::BARCODE)));
        ui->tableWidgetData->setItem(i, TWO,   DATA(mapListMat.at(i).value(HTTPKEY::NUMBER)));
        ui->tableWidgetData->setItem(i, THREE, DATA(mapListMat.at(i).value(HTTPKEY::UNITNAME)));

        SETTABLECENTER(ui->tableWidgetData->item(i, 0));
        SETTABLECENTER(ui->tableWidgetData->item(i, ONE));
        SETTABLECENTER(ui->tableWidgetData->item(i, TWO));
        SETTABLECENTER(ui->tableWidgetData->item(i, THREE));
    }

    ui->tableWidgetData->scrollToBottom();
}

/*********************  显示窗口       *********************/
void ConfirmSafeMat::showWidget()
{
    titleBar->setTitle(GLOBALDEF::CONFIRMMAT);
    this->show();
}

/*********************  确认采购       *********************/
void ConfirmSafeMat::on_pushButtonConfirm_clicked()
{
    QByteArray byteArray;

    MapList mapListData;

    for(int i = 0; i < mapListMat.size(); i ++)
    {
        Map mapData;

        mapData[HTTPKEY::MATERIALID] = mapListMat.at(i).value(HTTPKEY::MATERIALID);
        mapData[HTTPKEY::SUPPLIERID] = mapListMat.at(i).value(HTTPKEY::SUPPLIERID);
        mapData[HTTPKEY::NUMBER]     = mapListMat.at(i).value(HTTPKEY::NUMBER);
        mapData[HTTPKEY::UNITID]     = mapListMat.at(i).value(HTTPKEY::UNITID);
        mapData[HTTPKEY::UNITPRICE]  = mapListMat.at(i).value(HTTPKEY::UNITPRICE);

        mapListData.append(mapData);
    }

    byteArray.append( POSTARG::SAFETYAFFIRM.arg(HTTPCLIENT->makeJson(mapListData)));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_SAFETY_AFFIRM), byteArray, PROTOCOL::URL_SAFETY_AFFIRM);

    this->close();
}

/*********************  取消按钮       *********************/
void ConfirmSafeMat::on_pushButtonCancel_clicked()
{
    this->close();
}
