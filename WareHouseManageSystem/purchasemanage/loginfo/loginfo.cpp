#include "loginfo.h"
#include "ui_loginfo.h"
#include "httpclient/httpkey.h"

/*********************  构造函数       *********************/
LogInfo::LogInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogInfo)
{
    ui->setupUi(this);
    this->initControl();
}

/*********************  析构函数       *********************/
LogInfo::~LogInfo()
{
    delete ui;
}

/*********************  显示窗口       *********************/
void LogInfo::showWidget()
{
    titleBar->setTitle(GLOBALDEF::LOGINFO);
    this->show();
}

/*********************  初始化控件       *********************/
void LogInfo::initControl()
{
    titleBar = new TitleBar(this);
    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    SETTABLEWIDGET(ui->tableWidget);

    ui->tableWidget->setFocusPolicy(Qt::NoFocus);

    //设置不能选择
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
}

/*********************  改变事件        *********************/
void LogInfo::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  设置数据        *********************/
void LogInfo::setMapDataList(const MapList &value)
{
    mapDataList = value;

    ui->tableWidget->setRowCount(mapDataList.size());
    for(int i = 0; i < mapDataList.size(); i ++)
    {
        int type = mapDataList.at(i).value(HTTPKEY::OPERATIONID).toInt();

        if(type <= 0 || type >= ARRAYITEMCOUNT(MESSAGE::operType)) continue;
        ui->tableWidget->setItem(i, ZERO,  DATA(MESSAGE::operType[type - 1].operText));

        QString time = QDateTime::fromTime_t(mapDataList.at(i).value(HTTPKEY::OPERATIONTIME).toUInt()).toString("yyyy-MM-dd hh:mm:ss");
        ui->tableWidget->setItem(i, ONE,   DATA(time));
        ui->tableWidget->setItem(i, TWO,   DATA(mapDataList.at(i).value(HTTPKEY::USERNAME)));
        ui->tableWidget->setItem(i, THREE, DATA(mapDataList.at(i).value(HTTPKEY::CAUSE)));

        SETTABLECENTER(ui->tableWidget->item(i, ZERO));
        SETTABLECENTER(ui->tableWidget->item(i, ONE));
        SETTABLECENTER(ui->tableWidget->item(i, TWO));
        SETTABLECENTER(ui->tableWidget->item(i, THREE));
    }
}
