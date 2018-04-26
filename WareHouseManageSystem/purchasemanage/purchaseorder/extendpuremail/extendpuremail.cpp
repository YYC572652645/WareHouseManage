#include "extendpuremail.h"
#include "ui_extendpuremail.h"
#include "httpclient/httpkey.h"
#include "messagebox/messagedialog.h"
#include <QRegExp>

/*********************  构造函数       *********************/
ExtendPurEmail::ExtendPurEmail(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExtendPurEmail)
  ,titleBar(NULL)
{
    ui->setupUi(this);
    this->initControl();
}

/*********************  析构函数       *********************/
ExtendPurEmail::~ExtendPurEmail()
{
    delete ui;
}

/*********************  显示窗口       *********************/
void ExtendPurEmail::showWidget()
{
    titleBar->setTitle(GLOBALDEF::EXPORTEMAIL);
    ui->checkBoxAllSelect->setChecked(false);
    ui->checkBoxAllSelect->setText(tr("全选"));
    ui->lineEditEmail->setText(CONFIGJSON->getEmailText());

    this->show();
}

/*********************  初始化控件       *********************/
void ExtendPurEmail::initControl()
{
    titleBar = new TitleBar(this);

    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    SETTABLEWIDGET(ui->tableWidgetData);
}

/*********************  改变事件        *********************/
void ExtendPurEmail::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  设置订单列表      *********************/
void ExtendPurEmail::setDataMapList(const MapList &value)
{
    ui->tableWidgetData->clearContents();
    dataMapList = value;

    ui->tableWidgetData->setRowCount(dataMapList.size());

    for(int i = 0; i < dataMapList.size(); i ++)
    {
        ui->tableWidgetData->setItem(i, ZERO,  DATA(dataMapList.at(i).value(HTTPKEY::SUPPLIERNAME)));
        ui->tableWidgetData->setItem(i, ONE,   DATA(dataMapList.at(i).value(HTTPKEY::PURCHASENUMBER)));
        ui->tableWidgetData->setItem(i, TWO,   DATA(QDateTime::fromTime_t(dataMapList.at(i).value(HTTPKEY::ARRIVALTIME).toUInt()).toString("yyyy-MM-dd")));
        ui->tableWidgetData->setItem(i, THREE, DATA(dataMapList.at(i).value(HTTPKEY::PURCHASESTATE) == "0" ? tr("未提交") : tr("采购完成")));

        ui->tableWidgetData->item(i, THREE)->setFont(QFont("ZYSong", 12, QFont::Bold));
        if(dataMapList.at(i).value(HTTPKEY::PURCHASESTATE) == "0")
        {
            ui->tableWidgetData->item(i, THREE)->setTextColor(Qt::darkBlue);
        }
        else
        {
            ui->tableWidgetData->item(i, THREE)->setTextColor(Qt::darkGreen);
        }

        ui->tableWidgetData->item(i, ZERO)->setCheckState(Qt::Unchecked);

        SETTABLECENTER(ui->tableWidgetData->item(i, ZERO));
        SETTABLECENTER(ui->tableWidgetData->item(i, ONE));
        SETTABLECENTER(ui->tableWidgetData->item(i, TWO));
        SETTABLECENTER(ui->tableWidgetData->item(i, THREE));
    }
    ui->tableWidgetData->scrollToBottom();
}

/*********************  导出到邮箱      *********************/
void ExtendPurEmail::on_pushButtonExport_clicked()
{
    QRegExp rx;
    rx.setPatternSyntax(QRegExp::RegExp);
    rx.setCaseSensitivity(Qt::CaseSensitive);
    rx.setPattern(GLOBALDEF::EMAILREG);            //匹配邮箱字符串
    if(!rx.exactMatch(ui->lineEditEmail->text()))
    {
        MESSAGEBOX->showMessageBox(this, MESSAGE::EMAILISWRONG);
        return;
    }

    QByteArray byteArray;

    List listData;
    for(int i = 0; i < ui->tableWidgetData->rowCount(); i ++)
    {
        if(ui->tableWidgetData->item(i, ZERO)->checkState() == Qt::Checked)
        {
            listData.append(dataMapList.at(i).value(HTTPKEY::PURCHASENUMBER));
        }
    }

    CONFIGJSON->setEmailText(ui->lineEditEmail->text());
    byteArray.append(POSTARG::PUREXPORTEMAIL.arg(ui->lineEditEmail->text(), HTTPCLIENT->makeJson(listData)));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_PUR_EXTEND), byteArray, PROTOCOL::URL_PUR_EXTEND);

    this->close();
}

/*********************  单击选中      *********************/
void ExtendPurEmail::on_tableWidgetData_clicked(const QModelIndex &index)
{
    if(ui->tableWidgetData->item(index.row(), 0)->checkState() == Qt::Checked)
    {
        ui->tableWidgetData->item(index.row(), 0)->setCheckState(Qt::Unchecked);
    }
    else
    {
        ui->tableWidgetData->item(index.row(), 0)->setCheckState(Qt::Checked);
    }

    int dataCount = 0;
    for(int i = 0; i < ui->tableWidgetData->rowCount(); i ++)
    {
        if(ui->tableWidgetData->item(i, ZERO)->checkState() == Qt::Checked)
        {
            dataCount ++;
        }
    }

    if(dataCount == ui->tableWidgetData->rowCount())
    {
        ui->checkBoxAllSelect->setText(tr("全选"));
        ui->checkBoxAllSelect->setChecked(true);
    }
    else
    {
        ui->checkBoxAllSelect->setChecked(false);
    }
}

/*********************  全选      *********************/
void ExtendPurEmail::on_checkBoxAllSelect_clicked()
{
    if(ui->checkBoxAllSelect->isChecked())
    {
        for(int i = 0; i < ui->tableWidgetData->rowCount(); i ++)
        {
            ui->tableWidgetData->item(i, 0)->setCheckState(Qt::Checked);
        }

        ui->checkBoxAllSelect->setText(tr("全不选"));
    }
    else
    {
        for(int i = 0; i < ui->tableWidgetData->rowCount(); i ++)
        {
            ui->tableWidgetData->item(i, 0)->setCheckState(Qt::Unchecked);
        }
        ui->checkBoxAllSelect->setText(tr("全选"));
    }
}
