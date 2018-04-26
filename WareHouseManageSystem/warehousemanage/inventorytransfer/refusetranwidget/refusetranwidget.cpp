#include "RefuseTranWidget.h"
#include "ui_RefuseTranWidget.h"

/*********************  构造函数        *********************/
RefuseTranWidget::RefuseTranWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RefuseTranWidget)
  ,type(0)
{
    ui->setupUi(this);

    this->initControl();
}

/*********************  析构函数        *********************/
RefuseTranWidget::~RefuseTranWidget()
{
    delete ui;
}

/*********************  显示窗口     *********************/
void RefuseTranWidget::showWidget()
{
    ui->textEditContent->clear();
    this->show();
}

/*********************  点击确定事件     *********************/
void RefuseTranWidget::on_pushButtonOk_clicked()
{
    if(ui->textEditContent->toPlainText().isEmpty()) return;

    QByteArray byteArray;

    byteArray.append(POSTARG::REFUSETRAN.arg(number, ui->textEditContent->toPlainText()));

    if(type == REFUSE)
    {
        HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_ALLOT_CANCEL), byteArray, PROTOCOL::URL_ALLOT_CANCEL);
    }
    else
    {
        HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_ALLOT_RECONFIRM), byteArray, PROTOCOL::URL_ALLOT_RECONFIRM);
    }

    this->close();
}

/*********************  取消事件        *********************/
void RefuseTranWidget::on_pushButtonCancel_clicked()
{
    number.clear();
    this->close();
}

/*********************  设置类型        *********************/
void RefuseTranWidget::setType(int value)
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
void RefuseTranWidget::setNumber(const QString &value)
{
    number = value;
}

/*********************  初始化控件      *********************/
void RefuseTranWidget::initControl()
{
    titleBar = new TitleBar(this);

    titleBar->setTitle(GLOBALDEF::REFUSEREASON);
    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);
}

/*********************  改变事件        *********************/
void RefuseTranWidget::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}
