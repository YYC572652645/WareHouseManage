#include "importcheckhistory.h"
#include "ui_importcheckhistory.h"
#include "httpclient/httpkey.h"

/*********************  构造函数       *********************/
ImportCheckHistory::ImportCheckHistory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImportCheckHistory)
{
    ui->setupUi(this);
    this->initControl();
}

/*********************  析构函数       *********************/
ImportCheckHistory::~ImportCheckHistory()
{
    delete ui;
}

/*********************  显示窗口       *********************/
void ImportCheckHistory::showWidget()
{
    titleBar->setTitle(GLOBALDEF::IMPORTHISTORY);
    this->show();
}

/*********************  初始化控件       *********************/
void ImportCheckHistory::initControl()
{
    titleBar = new TitleBar(this);

    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    SETTABLEWIDGET(ui->tableWidgetData);
}

/*********************  改变事件        *********************/
void ImportCheckHistory::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  设置订单列表      *********************/
void ImportCheckHistory::setPurMapList(const MapList &value)
{
    purMapList = value;

    ui->tableWidgetData->setRowCount(purMapList.size());

    for(int i = 0; i < purMapList.size(); i ++)
    {
        ui->tableWidgetData->setItem(i, ZERO,  DATA(purMapList.at(i).value(HTTPKEY::WAREHOUSENAME)));
        ui->tableWidgetData->setItem(i, ONE,   DATA(purMapList.at(i).value(HTTPKEY::CHECKNUMBER)));
        ui->tableWidgetData->setItem(i, TWO,   DATA(QDateTime::fromTime_t(purMapList.at(i).value(HTTPKEY::CHECKTIME).toUInt()).toString("yyyy-MM-dd")));
        ui->tableWidgetData->setItem(i, THREE, DATA(""));

        QTableWidgetItem * itemThree = ui->tableWidgetData->item(i, THREE);
        ui->tableWidgetData->item(i, THREE)->setFont(QFont("ZYSong", 12, QFont::Bold));
        switch(purMapList.at(i).value(HTTPKEY::CHECKSTATE).toInt())
        {
        case ZERO:  itemThree->setTextColor(Qt::darkBlue);  itemThree->setText(tr("盘存中"));   break;
        case ONE:   itemThree->setTextColor(Qt::darkGreen); itemThree->setText(tr("已完成"));   break;
        case TWO:   itemThree->setTextColor(Qt::darkRed);   itemThree->setText(tr("取消盘存")); break;
        }

        SETTABLECENTER(ui->tableWidgetData->item(i, ZERO));
        SETTABLECENTER(ui->tableWidgetData->item(i, ONE));
        SETTABLECENTER(ui->tableWidgetData->item(i, TWO));
        SETTABLECENTER(ui->tableWidgetData->item(i, THREE));
    }

    ui->tableWidgetData->scrollToBottom();
}

/*********************  导入历史订单      *********************/
void ImportCheckHistory::on_pushButtonImport_clicked()
{
    if(NULL == ui->tableWidgetData->currentItem()) return;
    int currentRow = ui->tableWidgetData->currentRow();
    if(currentRow >= purMapList.size()) return;

    QByteArray byteArray;

    byteArray.append(POSTARG::COPYCHECK.arg(purMapList.at(currentRow).value(HTTPKEY::CHECKNUMBER)));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_CHECK_IMPORT), byteArray, PROTOCOL::URL_CHECK_IMPORT);

    this->close();
}

/*********************  取消按钮      *********************/
void ImportCheckHistory::on_pushButtonCancel_clicked()
{
    this->close();
}
