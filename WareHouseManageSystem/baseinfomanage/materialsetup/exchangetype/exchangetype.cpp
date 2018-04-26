#include "exchangetype.h"
#include "ui_exchangetype.h"
#include "httpclient/httpkey.h"

/*********************  构造函数        *********************/
ExchangeType::ExchangeType(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExchangeType)
{
    ui->setupUi(this);

    this->initControl();
}

/*********************  析构函数        *********************/
ExchangeType::~ExchangeType()
{
    delete ui;
}

/*********************  确定事件        *********************/
void ExchangeType::on_pushButtonOk_clicked()
{
    emit sendExchangeType(ui->comboBoxType->currentIndex());
    this->close();
}

/*********************  取消事件        *********************/
void ExchangeType::on_pushButtonCancel_clicked()
{
     this->close();
}

/*********************  初始化控件      *********************/
void ExchangeType::initControl()
{
    titleBar = new TitleBar(this);

    titleBar->setTitle(GLOBALDEF::EXCHANGETYPEMORE);
    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    ui->comboBoxType->setView(new QListView());

    ui->comboBoxType->setFocusPolicy(Qt::NoFocus);
}

/*********************  改变事件        *********************/
void ExchangeType::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  获取改变数据    *********************/
MapList ExchangeType::getMapExchangeData() const
{
    return mapExchangeData;
}

/*********************  设置改变数据    *********************/
void ExchangeType::setMapExchangeData(const MapList &value)
{
    mapExchangeData = value;

    ui->comboBoxType->clear();
    for(int i = 0; i < mapExchangeData.size(); i ++)
    {
        ui->comboBoxType->addItem(mapExchangeData.at(i).value(HTTPKEY::NAME));
    }
}
