#include "costprice.h"
#include "ui_costprice.h"
#include "httpclient/httpkey.h"

/*********************  构造函数       *********************/
CostPrice::CostPrice(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CostPrice)
{
    ui->setupUi(this);

    this->initControl();
}

/*********************  析构函数       *********************/
CostPrice::~CostPrice()
{
    delete ui;
}

/*********************  显示窗口       *********************/
void CostPrice::showWidget()
{
    titleBar->setTitle(GLOBALDEF::COSTPRICESEE);
    this->show();
}

/*********************  初始化控件       *********************/
void CostPrice::initControl()
{
    titleBar = new TitleBar(this);
    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    SETTABLEWIDGET(ui->tableWidget);

    ui->tableWidget->setFocusPolicy(Qt::NoFocus);
}

/*********************  改变事件        *********************/
void CostPrice::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  设置数据        *********************/
void CostPrice::setMapCostList(const MapList &value)
{
    mapCostList = value;

    ui->tableWidget->setRowCount(mapCostList.size());
    for(int i = 0; i < mapCostList.size(); i ++)
    {
        ui->tableWidget->setItem(i, ZERO, DATA(mapCostList.at(i).value(HTTPKEY::MATERIALNAME)));
        ui->tableWidget->setItem(i, ONE,  DATA(mapCostList.at(i).value(HTTPKEY::BARCODE)));
        ui->tableWidget->setItem(i, TWO,  DATA(mapCostList.at(i).value(HTTPKEY::COSTPRICE) + tr("元/") + mapCostList.at(i).value(HTTPKEY::UNITNAME)));

        ui->tableWidget->item(i, TWO)->setFont(QFont("ZYSong", 12, QFont::Bold));
        ui->tableWidget->item(i, TWO)->setTextColor(Qt::darkRed);
        SETTABLECENTER(ui->tableWidget->item(i, ZERO));
        SETTABLECENTER(ui->tableWidget->item(i, ONE));
        SETTABLECENTER(ui->tableWidget->item(i, TWO));
    }

    ui->tableWidget->scrollToBottom();
}
