#include "timematinfo.h"
#include "ui_timematinfo.h"
#include "httpclient/httpkey.h"
/*********************  构造函数       *********************/
TimeMatInfo::TimeMatInfo(QWidget *parent) : QWidget(parent), ui(new Ui::TimeMatInfo)
{
    ui->setupUi(this);

    this->initControl();
}

/*********************  析构函数       *********************/
TimeMatInfo::~TimeMatInfo()
{
    delete ui;
}

/*********************  显示窗口       *********************/
void TimeMatInfo::showWidget()
{
    titleBar->setTitle(GLOBALDEF::TIMEINFO);
    this->show();
}

/*********************  初始化控件       *********************/
void TimeMatInfo::initControl()
{
    titleBar = new TitleBar(this);
    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    SETTABLEWIDGET(ui->tableWidgetData);
}

/*********************  改变事件        *********************/
void TimeMatInfo::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/************************   设置原料名称        *********************/
void TimeMatInfo::setMaterialName(const QString &value)
{
    materialName = value;

    ui->lineEditMatInfo->setText(materialName);
}

/************************   设置控件数据         *********************/
void TimeMatInfo::setMapListData(const MapList &value)
{
    mapListData = value;

    ui->tableWidgetData->clearContents();
    ui->tableWidgetData->setRowCount(mapListData.size());

    double totalMoney = 0;
    double totalNumber = 0;
    QString unitName;
    for(int i = 0; i < mapListData.size(); i ++)
    {
        ui->tableWidgetData->setItem(i, ZERO,  DATA(mapListData.at(i).value(HTTPKEY::WAREHOUSENAME)));
        ui->tableWidgetData->setItem(i, ONE,   DATA(mapListData.at(i).value(HTTPKEY::TOTALMONEY) + tr("元")));
        ui->tableWidgetData->setItem(i, TWO,   DATA(mapListData.at(i).value(HTTPKEY::NUMBER)));
        ui->tableWidgetData->setItem(i, THREE, DATA(mapListData.at(i).value(HTTPKEY::UNITNAME)));

        totalMoney += mapListData.at(i).value(HTTPKEY::TOTALMONEY).toDouble();
        totalNumber += mapListData.at(i).value(HTTPKEY::NUMBER).toDouble();
        unitName = mapListData.at(i).value(HTTPKEY::UNITNAME);


        SETTABLECENTER(ui->tableWidgetData->item(i, ZERO));
        SETTABLECENTER(ui->tableWidgetData->item(i, ONE));
        SETTABLECENTER(ui->tableWidgetData->item(i, TWO));
        SETTABLECENTER(ui->tableWidgetData->item(i, THREE));
    }

    ui->labelInfo->setText(tr("合计： %1%2  ¥%3").arg(QString::number(totalNumber, 'f', 2), unitName, QString::number(totalMoney, 'f', 2)));
    ui->tableWidgetData->scrollToBottom();
}
