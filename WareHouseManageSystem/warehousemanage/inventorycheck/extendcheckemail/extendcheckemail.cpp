#include "extendcheckemail.h"
#include "ui_extendcheckemail.h"
#include "httpclient/httpkey.h"
#include "messagebox/messagedialog.h"
#include <QRegExp>

/*********************  构造函数       *********************/
ExtendCheckEmail::ExtendCheckEmail(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExtendCheckEmail)
  ,titleBar(NULL)
{
    ui->setupUi(this);
    this->initControl();
}

/*********************  析构函数       *********************/
ExtendCheckEmail::~ExtendCheckEmail()
{
    delete ui;
}

/*********************  显示窗口       *********************/
void ExtendCheckEmail::showWidget()
{
    titleBar->setTitle(GLOBALDEF::EXPORTEMAIL);
    ui->checkBoxAllSelect->setChecked(false);
    ui->checkBoxAllSelect->setText(tr("全选"));
    ui->lineEditEmail->setText(CONFIGJSON->getEmailText());
    this->show();
}

/*********************  初始化控件       *********************/
void ExtendCheckEmail::initControl()
{
    titleBar = new TitleBar(this);

    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    SETTABLEWIDGET(ui->tableWidgetData);
}

/*********************  改变事件        *********************/
void ExtendCheckEmail::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  设置订单列表      *********************/
void ExtendCheckEmail::setDataMapList(const MapList &value)
{
    ui->tableWidgetData->clearContents();
    dataMapList = value;

    ui->tableWidgetData->setRowCount(dataMapList.size());

    for(int i = 0; i < dataMapList.size(); i ++)
    {
        ui->tableWidgetData->setItem(i, ZERO,  DATA(dataMapList.at(i).value(HTTPKEY::WAREHOUSENAME)));
        ui->tableWidgetData->setItem(i, ONE,   DATA(dataMapList.at(i).value(HTTPKEY::CHECKNUMBER)));
        ui->tableWidgetData->setItem(i, TWO,   DATA(QDateTime::fromTime_t(dataMapList.at(i).value(HTTPKEY::CHECKTIME).toUInt()).toString("yyyy-MM-dd")));
        ui->tableWidgetData->setItem(i, THREE, DATA(""));

        ui->tableWidgetData->item(i, ZERO)->setCheckState(Qt::Unchecked);
        QTableWidgetItem * itemThree = ui->tableWidgetData->item(i, THREE);
        ui->tableWidgetData->item(i, THREE)->setFont(QFont("ZYSong", 12, QFont::Bold));
        switch(dataMapList.at(i).value(HTTPKEY::CHECKSTATE).toInt())
        {
        case ZERO:  itemThree->setTextColor(Qt::darkBlue);  itemThree->setText(tr("盘存中"));   break;
        case ONE:   itemThree->setTextColor(Qt::darkGreen); itemThree->setText(tr("已完成"));   break;
        case TWO:   itemThree->setTextColor(Qt::darkRed);   itemThree->setText(tr("取消盘存")); break;
        }

        SETTABLECENTER(ui->tableWidgetData->item(i, ZERO));
        SETTABLECENTER(ui->tableWidgetData->item(i, ONE));
        SETTABLECENTER(ui->tableWidgetData->item(i, TWO));
        SETTABLECENTER(ui->tableWidgetData->item(i, THREE));
    }

    ui->tableWidgetData->scrollToBottom();
}

/*********************  导出到邮箱      *********************/
void ExtendCheckEmail::on_pushButtonExport_clicked()
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
            listData.append(dataMapList.at(i).value(HTTPKEY::CHECKNUMBER));
        }
    }

    CONFIGJSON->setEmailText(ui->lineEditEmail->text());
    byteArray.append(POSTARG::CHECKEMAIL.arg(ui->lineEditEmail->text(), HTTPCLIENT->makeJson(listData)));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_CHECK_SEND_EMAIL), byteArray, PROTOCOL::URL_CHECK_SEND_EMAIL);

    this->close();
}

/*********************  单击选中      *********************/
void ExtendCheckEmail::on_tableWidgetData_clicked(const QModelIndex &index)
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
void ExtendCheckEmail::on_checkBoxAllSelect_clicked()
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
