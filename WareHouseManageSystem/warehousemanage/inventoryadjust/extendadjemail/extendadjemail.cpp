#include "extendadjemail.h"
#include "ui_extendadjemail.h"
#include "httpclient/httpkey.h"
#include "messagebox/messagedialog.h"
#include <QRegExp>

/*********************  构造函数       *********************/
ExtendAdjEmail::ExtendAdjEmail(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExtendAdjEmail)
  ,titleBar(NULL)
{
    ui->setupUi(this);
    this->initControl();
}

/*********************  析构函数       *********************/
ExtendAdjEmail::~ExtendAdjEmail()
{
    delete ui;
}

/*********************  显示窗口       *********************/
void ExtendAdjEmail::showWidget()
{
    titleBar->setTitle(GLOBALDEF::EXPORTEMAIL);
    ui->checkBoxAllSelect->setChecked(false);
    ui->checkBoxAllSelect->setText(tr("全选"));
    ui->lineEditEmail->setText(CONFIGJSON->getEmailText());

    this->show();
}

/*********************  初始化控件       *********************/
void ExtendAdjEmail::initControl()
{
    titleBar = new TitleBar(this);

    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    SETTABLEWIDGET(ui->tableWidgetData);
}

/*********************  改变事件        *********************/
void ExtendAdjEmail::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  设置订单列表      *********************/
void ExtendAdjEmail::setDataMapList(const MapList &value)
{
    ui->tableWidgetData->clearContents();
    dataMapList = value;

    ui->tableWidgetData->setRowCount(dataMapList.size());

    for(int i = 0; i < dataMapList.size(); i ++)
    {
        ui->tableWidgetData->setItem(i, ZERO,  DATA(dataMapList.at(i).value(HTTPKEY::NAME)));
        ui->tableWidgetData->setItem(i, ONE,   DATA(dataMapList.at(i).value(HTTPKEY::ODDNUMBERS)));
        ui->tableWidgetData->setItem(i, TWO,   DATA(QDateTime::fromTime_t(dataMapList.at(i).value(HTTPKEY::TIME).toUInt()).toString("yyyy-MM-dd")));
        ui->tableWidgetData->setItem(i, THREE, DATA(dataMapList.at(i).value(HTTPKEY::WHETHERSUBMIT) == "0" ? tr("未提交") : tr("已调整")));

        ui->tableWidgetData->item(i, ZERO)->setCheckState(Qt::Unchecked);
        ui->tableWidgetData->item(i, THREE)->setFont(QFont("ZYSong", 12, QFont::Bold));
        switch(dataMapList.at(i).value(HTTPKEY::WHETHERSUBMIT).toInt())
        {
        case ZERO:  ui->tableWidgetData->item(i, THREE)->setTextColor(Qt::darkBlue); break;
        case ONE:   ui->tableWidgetData->item(i, THREE)->setTextColor(Qt::darkGreen); break;
        }

        SETTABLECENTER(ui->tableWidgetData->item(i, ZERO));
        SETTABLECENTER(ui->tableWidgetData->item(i, ONE));
        SETTABLECENTER(ui->tableWidgetData->item(i, TWO));
        SETTABLECENTER(ui->tableWidgetData->item(i, THREE));
    }
    ui->tableWidgetData->scrollToBottom();
}

/*********************  导出到邮箱      *********************/
void ExtendAdjEmail::on_pushButtonExport_clicked()
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
        if(ui->tableWidgetData->item(i, 0)->checkState() == Qt::Checked)
        {
            listData.append(dataMapList.at(i).value(HTTPKEY::ODDNUMBERS));
        }
    }

    CONFIGJSON->setEmailText(ui->lineEditEmail->text());
    byteArray.append(POSTARG::ADJEXPORTEMAIL.arg(ui->lineEditEmail->text(), HTTPCLIENT->makeJson(listData)));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_ADJ_SEND_EMAIL), byteArray, PROTOCOL::URL_ADJ_SEND_EMAIL);

    this->close();
}

/*********************  单击选中      *********************/
void ExtendAdjEmail::on_tableWidgetData_clicked(const QModelIndex &index)
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
void ExtendAdjEmail::on_checkBoxAllSelect_clicked()
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
