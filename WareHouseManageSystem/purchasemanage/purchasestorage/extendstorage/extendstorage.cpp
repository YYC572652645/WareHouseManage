#include "extendstorage.h"
#include "ui_extendstorage.h"
#include "httpclient/httpkey.h"
#include "messagebox/messagedialog.h"
#include <QRegExp>

/*********************  构造函数       *********************/
ExtendStorage::ExtendStorage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExtendStorage)
{
    ui->setupUi(this);
    this->initControl();
}

/*********************  析构函数       *********************/
ExtendStorage::~ExtendStorage()
{
    delete ui;
}

/*********************  显示窗口       *********************/
void ExtendStorage::showWidget()
{
    titleBar->setTitle(GLOBALDEF::EXPORTEMAIL);
    ui->checkBoxAllSelect->setText(tr("全选"));
    ui->checkBoxAllSelect->setChecked(false);
    ui->lineEditEmail->setText(CONFIGJSON->getEmailText());
    this->show();
}

/*********************  初始化控件       *********************/
void ExtendStorage::initControl()
{
    titleBar = new TitleBar(this);
    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    SETTABLEWIDGET(ui->tableWidgetData);
}

/*********************  改变事件        *********************/
void ExtendStorage::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  设置订单列表      *********************/
void ExtendStorage::setDataMapList(const MapList &value)
{
    dataMapList = value;
    ui->tableWidgetData->clearContents();
    ui->tableWidgetData->setHorizontalHeaderItem(TWO, DATA(tr("入库日期")));

    ui->tableWidgetData->setRowCount(dataMapList.size());
    for(int i = 0; i < dataMapList.size(); i ++)
    {
        ui->tableWidgetData->setItem(i, ZERO, DATA(dataMapList.at(i).value(HTTPKEY::SUPPLIERNAME)));
        ui->tableWidgetData->setItem(i, ONE,  DATA(dataMapList.at(i).value(HTTPKEY::STORAGENUMBER)));
        ui->tableWidgetData->setItem(i, TWO,  DATA(QDateTime::fromTime_t(dataMapList.at(i).value(HTTPKEY::ARRIVALTIME).toUInt()).toString("yyyy-MM-dd")));

        QString statusStr;

        switch(dataMapList.at(i).value(HTTPKEY::STORAGESTATE).toInt())
        {
        case ZERO:  statusStr = tr("配送中"); break;
        case ONE:   statusStr = tr("已收货"); break;
        case TWO:   statusStr = tr("已拒绝"); break;
        case THREE: statusStr = tr("未提交"); break;
        case FOUR:  statusStr = tr("验收中"); break;
        }

        ui->tableWidgetData->setItem(i, THREE, DATA(statusStr));

        ui->tableWidgetData->item(i, THREE)->setFont(QFont("ZYSong", 12, QFont::Bold));

        switch(dataMapList.at(i).value(HTTPKEY::STORAGESTATE).toInt())
        {
        case ZERO:  ui->tableWidgetData->item(i, THREE)->setTextColor(Qt::darkBlue); break;
        case ONE:   ui->tableWidgetData->item(i, THREE)->setTextColor(Qt::darkGreen); break;
        case TWO:   ui->tableWidgetData->item(i, THREE)->setTextColor(Qt::darkRed); break;
        case THREE: ui->tableWidgetData->item(i, THREE)->setTextColor(Qt::darkBlue); break;
        case FOUR:  ui->tableWidgetData->item(i, THREE)->setTextColor(Qt::darkGreen); break;
        }

        SETTABLECENTER(ui->tableWidgetData->item(i, ZERO));
        SETTABLECENTER(ui->tableWidgetData->item(i, ONE));
        SETTABLECENTER(ui->tableWidgetData->item(i, TWO));
        SETTABLECENTER(ui->tableWidgetData->item(i, THREE));

        ui->tableWidgetData->item(i, ZERO)->setCheckState(Qt::Unchecked);
    }

    ui->tableWidgetData->scrollToBottom();
}

/*********************  导出到邮箱      *********************/
void ExtendStorage::on_pushButtonExport_clicked()
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
            listData.append(dataMapList.at(i).value(HTTPKEY::STORAGENUMBER));
        }
    }

    CONFIGJSON->setEmailText(ui->lineEditEmail->text());

    byteArray.append(POSTARG::SENDEMAIL.arg(ui->lineEditEmail->text(), HTTPCLIENT->makeJson(listData)));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_STO_EXPORT_EMAIL), byteArray, PROTOCOL::URL_STO_EXPORT_EMAIL);

    this->close();
}

/*********************  单击选中      *********************/
void ExtendStorage::on_tableWidgetData_clicked(const QModelIndex &index)
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
void ExtendStorage::on_checkBoxAllSelect_clicked()
{
    if(ui->checkBoxAllSelect->isChecked())
    {
        ui->checkBoxAllSelect->setText(tr("全不选"));
        for(int i = 0; i < ui->tableWidgetData->rowCount(); i ++)
        {
            ui->tableWidgetData->item(i, 0)->setCheckState(Qt::Checked);
        }
    }
    else
    {
        ui->checkBoxAllSelect->setText(tr("全选"));
        for(int i = 0; i < ui->tableWidgetData->rowCount(); i ++)
        {
            ui->tableWidgetData->item(i, 0)->setCheckState(Qt::Unchecked);
        }
    }
}
