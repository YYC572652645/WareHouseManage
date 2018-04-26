#include "addauthority.h"
#include "ui_addauthority.h"

/*********************  构造函数      *********************/
AddAuthority::AddAuthority(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddAuthority)
{
    ui->setupUi(this);

    this->initControl();
}

/*********************  析构函数     *********************/
AddAuthority::~AddAuthority()
{
    delete ui;
}

/*********************  显示窗口     *********************/
void AddAuthority::showWidget()
{
    this->activateWindow();
    this->show();
}

/*********************  改变事件     *********************/
void AddAuthority::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  初始化控件   *********************/
void AddAuthority::initControl()
{
    titleBar = new TitleBar(this);
    titleBar->setIcon(GLOBALDEF::APPLOGO);
    titleBar->setTitle(tr("添加权限"));

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);
}

/*********************  确定        *********************/
void AddAuthority::on_pushButtonOk_clicked()
{
    QByteArray byteArray;

    QString strPost = POSTARG::ADDUSER.arg(ui->lineEditUserName->text());

    strPost = strPost.arg(ui->lineEditPassWord->text());

    byteArray.append(strPost);

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_USER_ADD), byteArray, PROTOCOL::URL_USER_ADD);

    this->close();
}

/*********************  取消        *********************/
void AddAuthority::on_pushButtonCancel_clicked()
{
    this->close();
}
