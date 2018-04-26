#include "defaultlimitinfo.h"
#include "ui_defaultlimitinfo.h"
#include "httpclient/httpkey.h"
#include "messagebox/messagedialog.h"

/*********************  构造函数        *********************/
DefaultLimitInfo::DefaultLimitInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DefaultLimitInfo)
{
    ui->setupUi(this);

    this->initControl();
}

/*********************  析构函数        *********************/
DefaultLimitInfo::~DefaultLimitInfo()
{
    delete ui;
}

/*********************  初始化控件       *********************/
void DefaultLimitInfo::initControl()
{
    titleBar = new TitleBar(this);
    titleBar->setTitle(GLOBALDEF::TABMATERIALINFO);
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
void DefaultLimitInfo::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/********************* 设置数据        *********************/
void DefaultLimitInfo::setMapMatData(const Map &value)
{
    mapMatData = value;

    ui->lineEditMatName->setText(mapMatData.value(HTTPKEY::NAME));
    ui->lineEditBarCode->setText(mapMatData.value(HTTPKEY::BARCODE));
    ui->lineEditSpec->setText(mapMatData.value(HTTPKEY::STANDARD));
    ui->lineEditUnit->setText(mapMatData.value(HTTPKEY::WAREHOUSEUNITNAME));

    if(mapMatData.value(HTTPKEY::UPPERLIMIT) != "0")
    {
        ui->lineEditUpper->setText(mapMatData.value(HTTPKEY::UPPERLIMIT));
    }
    else
    {
        ui->lineEditUpper->setText(NULL);
    }

    if(mapMatData.value(HTTPKEY::LOWERLIMIT) != "0")
    {
        ui->lineEditLower->setText(mapMatData.value(HTTPKEY::LOWERLIMIT));
    }
    else
    {
        ui->lineEditLower->setText(NULL);
    }
}

/********************* 显示窗口        *********************/
void DefaultLimitInfo::showWidget()
{
    this->show();
}

/*********************  保存按钮        *********************/
void DefaultLimitInfo::on_pushButtonSave_clicked()
{
    if(ui->lineEditUpper->text().toInt() <= ui->lineEditLower->text().toInt()
            || ui->lineEditLower->text().isEmpty()
            || ui->lineEditUpper->text().isEmpty())
    {
        MESSAGEBOX->showMessageBox(this, MESSAGE::RESTCANNOT);
        return;
    }

    QByteArray byteArray;

    List listData;

    listData.append(mapMatData.value(HTTPKEY::MATERIALID));

    QString strPost = POSTARG::UPDATERESTLIST.arg(HTTPCLIENT->makeJson(listData));

    strPost = strPost.arg(ui->lineEditUpper->text());

    strPost = strPost.arg(ui->lineEditLower->text());

    byteArray.append(strPost);

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_REST_UPDATE_MAT), byteArray, PROTOCOL::URL_REST_UPDATE_MAT);

    this->close();
}

/*********************  取消按钮        *********************/
void DefaultLimitInfo::on_pushButtonCancel_clicked()
{
    this->close();
}

/*********************  编辑        *********************/
void DefaultLimitInfo::on_lineEditUpper_textEdited(const QString &arg1)
{
    if((arg1.isEmpty() || arg1.toInt() == 0) && mapMatData.value(HTTPKEY::UPPERLIMIT).toInt() != 0)
    {
        ui->lineEditUpper->setText(mapMatData.value(HTTPKEY::UPPERLIMIT));
        MESSAGEBOX->showMessageBox(this, MESSAGE::RESTUPNULL);
    }
}

/*********************  编辑        *********************/
void DefaultLimitInfo::on_lineEditLower_textChanged(const QString &arg1)
{
    if((arg1.isEmpty() || arg1.toInt() == 0) && mapMatData.value(HTTPKEY::LOWERLIMIT).toInt() != 0)
    {
        ui->lineEditLower->setText(mapMatData.value(HTTPKEY::LOWERLIMIT));
        MESSAGEBOX->showMessageBox(this, MESSAGE::RESTLONULL);
    }
}
