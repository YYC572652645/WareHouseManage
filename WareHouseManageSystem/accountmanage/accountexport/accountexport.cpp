#include "accountexport.h"
#include "ui_accountexport.h"
#include "httpclient/httpkey.h"
#include "messagebox/messagedialog.h"
#include <QRegExp>

/*********************  构造函数        *********************/
AccountExport::AccountExport(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AccountExport)
{
    ui->setupUi(this);
    this->initControl();
}


/*********************  析构函数        *********************/
AccountExport::~AccountExport()
{
    delete ui;
}

/*********************  显示窗口        *********************/
void AccountExport::showWidget()
{
    titleBar->setTitle(GLOBALDEF::EXPORTEMAIL);
    ui->checkBoxAllSelect->setChecked(false);
    ui->checkBoxAllSelect->setText(tr("全选"));
    ui->lineEditEmail->setText(CONFIGJSON->getEmailText());

    this->show();
}

/*********************  初始化控件      *********************/
void AccountExport::initControl()
{
    titleBar = new TitleBar(this);

    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    SETTABLEWIDGET(ui->tableWidgetAccount);
}

/*********************  改变事件        *********************/
void AccountExport::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  设置数据        *********************/
void AccountExport::setAccountMapList(const MapList &value)
{
    accountMapList = value;

    ui->tableWidgetAccount->clearContents();
    ui->tableWidgetAccount->setRowCount(accountMapList.size());

    for(int i = 0; i < accountMapList.size(); i ++)
    {
        ui->tableWidgetAccount->setItem(i, ZERO,  DATA(accountMapList.at(i).value(HTTPKEY::SUPPLIERNAME)));
        ui->tableWidgetAccount->setItem(i, ONE,   DATA(accountMapList.at(i).value(HTTPKEY::NUMBER)));

        if(accountMapList.at(i).value(HTTPKEY::NUMBER).contains("STO"))
        {
            ui->tableWidgetAccount->setItem(i, TWO,   DATA(tr("入库单")));
        }
        else
        {
            ui->tableWidgetAccount->setItem(i, TWO,   DATA(tr("退货单")));
        }

        ui->tableWidgetAccount->setItem(i, THREE, DATA(QDateTime::fromTime_t(accountMapList.at(i).value(HTTPKEY::TIME).toUInt()).toString("yyyy-MM-dd")));

        switch(accountMapList.at(i).value(HTTPKEY::ACCOUNTSTATE).toInt())
        {
        case ZERO:
        {
            ui->tableWidgetAccount->setItem(i, FOUR,  DATA(tr("待对账")));
            ui->tableWidgetAccount->item(i, FOUR)->setTextColor(Qt::darkBlue);
        }break;
        case ONE:
        {
            ui->tableWidgetAccount->setItem(i, FOUR,  DATA(tr("已结算")));
            ui->tableWidgetAccount->item(i, FOUR)->setTextColor(Qt::darkGreen);
        }break;
        case TWO:
        {
            ui->tableWidgetAccount->setItem(i, FOUR,  DATA(tr("待结算")));
            ui->tableWidgetAccount->item(i, FOUR)->setTextColor(Qt::darkMagenta);
        }break;
        }

        ui->tableWidgetAccount->item(i, FOUR)->setFont(QFont("ZYSong", 12, QFont::Bold));

        SETTABLECENTER(ui->tableWidgetAccount->item(i, ZERO));
        SETTABLECENTER(ui->tableWidgetAccount->item(i, ONE));
        SETTABLECENTER(ui->tableWidgetAccount->item(i, TWO));
        SETTABLECENTER(ui->tableWidgetAccount->item(i, THREE));
        SETTABLECENTER(ui->tableWidgetAccount->item(i, FOUR));

        ui->tableWidgetAccount->item(i, ZERO)->setCheckState(Qt::Unchecked);
    }
    ui->tableWidgetAccount->scrollToBottom();
}

/*********************  导出到邮箱      *********************/
void AccountExport::on_pushButtonExport_clicked()
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

    MapList mapListData;
    for(int i = 0; i < ui->tableWidgetAccount->rowCount(); i ++)
    {
        if(ui->tableWidgetAccount->item(i, ZERO)->checkState() == Qt::Checked)
        {
            Map mapData;
            mapData[HTTPKEY::NUMBER] = accountMapList.at(i).value(HTTPKEY::NUMBER);
            mapData[HTTPKEY::ACCOUNTTIME] = accountMapList.at(i).value(HTTPKEY::ACCOUNTTIME);

            mapListData.append(mapData);
        }
    }

    CONFIGJSON->setEmailText(ui->lineEditEmail->text());
    byteArray.append(POSTARG::ACCOUNTEXTEND.arg(ui->lineEditEmail->text(), HTTPCLIENT->makeJson(mapListData)));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_ACCOUNT_EXTEND), byteArray, PROTOCOL::URL_ACCOUNT_EXTEND);

    this->close();
}

/*********************  单击选中       *********************/
void AccountExport::on_tableWidgetAccount_clicked(const QModelIndex &index)
{
    if(ui->tableWidgetAccount->item(index.row(), 0)->checkState() == Qt::Checked)
    {
        ui->tableWidgetAccount->item(index.row(), 0)->setCheckState(Qt::Unchecked);
    }
    else
    {
        ui->tableWidgetAccount->item(index.row(), 0)->setCheckState(Qt::Checked);
    }

    int dataCount = 0;
    for(int i = 0; i < ui->tableWidgetAccount->rowCount(); i ++)
    {
        if(ui->tableWidgetAccount->item(i, ZERO)->checkState() == Qt::Checked)
        {
            dataCount ++;
        }
    }

    if(dataCount == ui->tableWidgetAccount->rowCount())
    {
        ui->checkBoxAllSelect->setText(tr("全选"));
        ui->checkBoxAllSelect->setChecked(true);
    }
    else
    {
        ui->checkBoxAllSelect->setChecked(false);
    }
}

/*********************  全选          *********************/
void AccountExport::on_checkBoxAllSelect_clicked()
{
    if(ui->checkBoxAllSelect->isChecked())
    {
        for(int i = 0; i < ui->tableWidgetAccount->rowCount(); i ++)
        {
            ui->tableWidgetAccount->item(i, 0)->setCheckState(Qt::Checked);
        }

        ui->checkBoxAllSelect->setText(tr("全不选"));
    }
    else
    {
        for(int i = 0; i < ui->tableWidgetAccount->rowCount(); i ++)
        {
            ui->tableWidgetAccount->item(i, 0)->setCheckState(Qt::Unchecked);
        }
        ui->checkBoxAllSelect->setText(tr("全选"));
    }
}
