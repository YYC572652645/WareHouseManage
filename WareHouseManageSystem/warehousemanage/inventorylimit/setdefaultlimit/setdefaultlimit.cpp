#include "setdefaultlimit.h"
#include "ui_setdefaultlimit.h"
#include "httpclient/httpkey.h"
#include "messagebox/messagedialog.h"

/*********************  构造函数        *********************/
SetDefaultLimit::SetDefaultLimit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetDefaultLimit)
{
    ui->setupUi(this);

    this->initControl();
}

/*********************  析构函数        *********************/
SetDefaultLimit::~SetDefaultLimit()
{
    delete ui;
}

/*********************  初始化控件       *********************/
void SetDefaultLimit::initControl()
{
    titleBar = new TitleBar(this);

    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    //设置只能输入数字
    QRegExp regExp("[0-9]+$");
    QValidator *validatorLower = new QRegExpValidator(regExp,  ui->lineEditLower);
    ui->lineEditLower->setValidator(validatorLower);

    //设置只能输入数字
    QValidator *validatorUpper = new QRegExpValidator(regExp,  ui->lineEditUpper);
    ui->lineEditUpper->setValidator(validatorUpper);
}

/*********************  改变事件        *********************/
void SetDefaultLimit::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  设置原料列表    *********************/
void SetDefaultLimit::setMapListMat(const MapList &value)
{
    mapListMat = value;
}

/*********************  设置原料个数    *********************/
void SetDefaultLimit::setMatNumber(const QString &value)
{
    matNumber = value;
    ui->lineEditMatNumber->setText(value);
}

/********************* 显示窗口        *********************/
void SetDefaultLimit::showWidget()
{
    titleBar->setTitle(GLOBALDEF::SETDEFAULTLIMIT);
    this->show();
}

/*********************  保存按钮        *********************/
void SetDefaultLimit::on_pushButtonSave_clicked()
{
    if(ui->lineEditUpper->text().toInt() <= ui->lineEditLower->text().toInt()
            && !ui->lineEditLower->text().isEmpty()
            && !ui->lineEditUpper->text().isEmpty())
    {
        MESSAGEBOX->showMessageBox(this, MESSAGE::RESTCANNOT);
        return;
    }


    QByteArray byteArray;

    List listData;

    for(int i = 0; i < mapListMat.size(); i ++)
    {
        listData.append(mapListMat.at(i).value(HTTPKEY::MATERIALID));
    }

    QString strPost = POSTARG::UPDATERESTLIST.arg(HTTPCLIENT->makeJson(listData));

    strPost = strPost.arg(ui->lineEditUpper->text().isEmpty() ? "0" : ui->lineEditUpper->text());

    strPost = strPost.arg(ui->lineEditLower->text().isEmpty() ? "0" : ui->lineEditLower->text());

    byteArray.append(strPost);

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_REST_UPDATE_MAT), byteArray, PROTOCOL::URL_REST_UPDATE_MAT);

    this->close();
}

/*********************  取消按钮        *********************/
void SetDefaultLimit::on_pushButtonCancel_clicked()
{
    this->close();
}
