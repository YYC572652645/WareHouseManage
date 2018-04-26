#include "RefuseWidget.h"
#include "ui_RefuseWidget.h"

/*********************  构造函数        *********************/
RefuseWidget::RefuseWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RefuseWidget)
  ,type(0)
{
    ui->setupUi(this);

    this->initControl();
}

/*********************  析构函数        *********************/
RefuseWidget::~RefuseWidget()
{
    delete ui;
}

/*********************  显示窗口     *********************/
void RefuseWidget::showWidget()
{
    ui->textEditContent->clear();
    this->show();
}

/*********************  点击确定事件     *********************/
void RefuseWidget::on_pushButtonOk_clicked()
{
    if(ui->textEditContent->toPlainText().isEmpty()) return;

    QByteArray byteArray;

    byteArray.append(POSTARG::REFUSE.arg(storageNumber, ui->textEditContent->toPlainText()));

    if(type == REFUSE)
    {
        HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_STO_REFUSE), byteArray, PROTOCOL::URL_STO_REFUSE);
    }
    else
    {
        HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_STO_RECONFIRM), byteArray, PROTOCOL::URL_STO_RECONFIRM);
    }

    this->close();
}

/*********************  取消事件        *********************/
void RefuseWidget::on_pushButtonCancel_clicked()
{
    storageNumber.clear();
    this->close();
}

/*********************  设置类型        *********************/
void RefuseWidget::setType(int value)
{
    type = value;

    if(type == REFUSE)
    {
        titleBar->setTitle(GLOBALDEF::REFUSEREASON);
    }
    else
    {
        titleBar->setTitle(GLOBALDEF::RECONFIRMREASON);
    }
}

/*********************  设置入库单号      *********************/
void RefuseWidget::setStorageNumber(const QString &value)
{
    storageNumber = value;
}

/*********************  初始化控件      *********************/
void RefuseWidget::initControl()
{
    titleBar = new TitleBar(this);

    titleBar->setTitle(GLOBALDEF::REFUSEREASON);
    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);
}

/*********************  改变事件        *********************/
void RefuseWidget::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}
