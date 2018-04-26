#include "importrethistory.h"
#include "ui_importrethistory.h"
#include "httpclient/httpkey.h"

/*********************  构造函数       *********************/
ImportRetHistory::ImportRetHistory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImportRetHistory)
{
    ui->setupUi(this);
    this->initControl();
}

/*********************  析构函数       *********************/
ImportRetHistory::~ImportRetHistory()
{
    delete ui;
}

/*********************  显示窗口       *********************/
void ImportRetHistory::showWidget()
{
    titleBar->setTitle(GLOBALDEF::IMPORTHISTORY);
    this->show();
}

/*********************  初始化控件       *********************/
void ImportRetHistory::initControl()
{
    titleBar = new TitleBar(this);
    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    SETTABLEWIDGET(ui->tableWidgetData);
}

/*********************  改变事件        *********************/
void ImportRetHistory::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  设置订单列表      *********************/
void ImportRetHistory::setPurMapList(const MapList &value)
{
    purMapList = value;

    ui->tableWidgetData->setRowCount(purMapList.size());

    for(int i = 0; i < purMapList.size(); i ++)
    {
        ui->tableWidgetData->setItem(i, ZERO,  DATA(purMapList.at(i).value(HTTPKEY::SUPPLIERNAME)));
        ui->tableWidgetData->setItem(i, ONE,   DATA(purMapList.at(i).value(HTTPKEY::RETURNSNUMBER)));
        ui->tableWidgetData->setItem(i, TWO,   DATA(QDateTime::fromTime_t(purMapList.at(i).value(HTTPKEY::ARRIVALTIME).toUInt()).toString("yyyy-MM-dd")));
        ui->tableWidgetData->setItem(i, THREE, DATA(purMapList.at(i).value(HTTPKEY::RETURNSSTATE) == "0" ? tr("未提交") : tr("退货完成")));

        ui->tableWidgetData->item(i, THREE)->setFont(QFont("ZYSong", 12, QFont::Bold));
        switch(purMapList.at(i).value(HTTPKEY::RETURNSSTATE).toInt())
        {
        case ZERO:  ui->tableWidgetData->item(i, THREE)->setTextColor(Qt::darkBlue); break;
        case ONE:   ui->tableWidgetData->item(i, THREE)->setTextColor(Qt::darkGreen); break;
        }

        SETTABLECENTER(ui->tableWidgetData->item(i, 0));
        SETTABLECENTER(ui->tableWidgetData->item(i, ONE));
        SETTABLECENTER(ui->tableWidgetData->item(i, TWO));
        SETTABLECENTER(ui->tableWidgetData->item(i, THREE));
    }
    ui->tableWidgetData->scrollToBottom();
}

/*********************  导入历史订单      *********************/
void ImportRetHistory::on_pushButtonImport_clicked()
{
    if(NULL == ui->tableWidgetData->currentItem()) return;
    int currentRow = ui->tableWidgetData->currentRow();
    if(currentRow >= purMapList.size()) return;

    QByteArray byteArray;

    byteArray.append(POSTARG::COPYRET.arg(purMapList.at(currentRow).value(HTTPKEY::RETURNSNUMBER)));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_RETURN_COPY_ORDER), byteArray, PROTOCOL::URL_RETURN_COPY_ORDER);

    this->close();
}

/*********************  取消按钮      *********************/
void ImportRetHistory::on_pushButtonCancel_clicked()
{
    this->close();
}
