#include "extendretemail.h"
#include "ui_extendretemail.h"
#include "httpclient/httpkey.h"
#include "messagebox/messagedialog.h"
#include <QRegExp>

/*********************  构造函数       *********************/
ExtendRetEmail::ExtendRetEmail(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExtendRetEmail)
  ,titleBar(NULL)
{
    ui->setupUi(this);
    this->initControl();
}

/*********************  析构函数       *********************/
ExtendRetEmail::~ExtendRetEmail()
{
    delete ui;
}

/*********************  显示窗口       *********************/
void ExtendRetEmail::showWidget()
{
    titleBar->setTitle(GLOBALDEF::EXPORTEMAIL);
    ui->checkBoxAllSelect->setChecked(false);
    ui->checkBoxAllSelect->setText(tr("全选"));
    ui->lineEditEmail->setText(CONFIGJSON->getEmailText());

    this->show();
}

/*********************  初始化控件       *********************/
void ExtendRetEmail::initControl()
{
    titleBar = new TitleBar(this);

    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    SETTABLEWIDGET(ui->tableWidgetData);
}

/*********************  改变事件        *********************/
void ExtendRetEmail::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  设置订单列表      *********************/
void ExtendRetEmail::setDataMapList(const MapList &value)
{
    ui->tableWidgetData->clearContents();
    dataMapList = value;

    ui->tableWidgetData->setRowCount(dataMapList.size());

    for(int i = 0; i < dataMapList.size(); i ++)
    {
        ui->tableWidgetData->setItem(i, ZERO,  DATA(dataMapList.at(i).value(HTTPKEY::SUPPLIERNAME)));
        ui->tableWidgetData->setItem(i, ONE,   DATA(dataMapList.at(i).value(HTTPKEY::RETURNSNUMBER)));
        ui->tableWidgetData->setItem(i, TWO,   DATA(QDateTime::fromTime_t(dataMapList.at(i).value(HTTPKEY::RETURNSTIME).toUInt()).toString("yyyy-MM-dd")));
        ui->tableWidgetData->setItem(i, THREE, DATA(dataMapList.at(i).value(HTTPKEY::RETURNSSTATE) == "0" ? tr("未提交") : tr("退货完成")));

        ui->tableWidgetData->item(i, THREE)->setFont(QFont("ZYSong", 12, QFont::Bold));
        switch(dataMapList.at(i).value(HTTPKEY::RETURNSSTATE).toInt())
        {
        case ZERO: ui->tableWidgetData->item(i, THREE)->setTextColor(Qt::darkBlue); break;
        case ONE:  ui->tableWidgetData->item(i, THREE)->setTextColor(Qt::darkGreen); break;
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
void ExtendRetEmail::on_pushButtonExport_clicked()
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
            listData.append(dataMapList.at(i).value(HTTPKEY::RETURNSNUMBER));
        }
    }

    CONFIGJSON->setEmailText(ui->lineEditEmail->text());
    byteArray.append(POSTARG::RETEXPORTEMAIL.arg(ui->lineEditEmail->text(), HTTPCLIENT->makeJson(listData)));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_RETURN_EXTEND), byteArray, PROTOCOL::URL_RETURN_EXTEND);

    this->close();
}

/*********************  单击选中      *********************/
void ExtendRetEmail::on_tableWidgetData_clicked(const QModelIndex &index)
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
void ExtendRetEmail::on_checkBoxAllSelect_clicked()
{
    bool checkFlage = ui->checkBoxAllSelect->isChecked();

    if(checkFlage)
    {
        ui->checkBoxAllSelect->setText(tr("全不选"));
        ui->checkBoxAllSelect->setIcon(QIcon(GLOBALDEF::NOTSELECTIMAGE));
    }
    else
    {
        ui->checkBoxAllSelect->setText(tr("全选"));
        ui->checkBoxAllSelect->setIcon(QIcon(GLOBALDEF::ALLSELECTIMAGE));
    }

    Qt::CheckState checkState = ui->checkBoxAllSelect->isChecked() ? Qt::Checked : Qt::Unchecked;

    for(int i = 0; i < ui->tableWidgetData->rowCount(); i ++)
    {
        ui->tableWidgetData->item(i, 0)->setCheckState(checkState);
    }

}
