#include "confirmmat.h"
#include "ui_confirmmat.h"
#include "messagebox/messagedialog.h"
#include "httpclient/httpkey.h"

/*********************  构造函数       *********************/
ConfirmMat::ConfirmMat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConfirmMat)
{
    ui->setupUi(this);
    this->initControl();
}

/*********************  析构函数       *********************/
ConfirmMat::~ConfirmMat()
{
    delete ui;
}

/*********************  初始化控件       *********************/
void ConfirmMat::initControl()
{
    titleBar = new TitleBar(this);

    titleBar->setTitle(GLOBALDEF::CONFIRMMAT);
    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    SETTABLEWIDGET(ui->tableWidgetData);
}

/*********************  改变事件        *********************/
void ConfirmMat::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  设置采购单号        *********************/
void ConfirmMat::setPurNumber(const QString &value)
{
    purNumber = value;
}

/*********************  设置原料列表       *********************/
void ConfirmMat::setMapListMat(const MapList &value)
{
    mapListMat = value;

    ui->tableWidgetData->setRowCount(mapListMat.size());
    for(int i = 0; i < mapListMat.size(); i ++)
    {
        ui->tableWidgetData->setItem(i, ZERO,  DATA(mapListMat.at(i).value(HTTPKEY::MATERIALNAME)));
        ui->tableWidgetData->setItem(i, ONE,   DATA(mapListMat.at(i).value(HTTPKEY::BARCODE)));
        ui->tableWidgetData->setItem(i, TWO,   DATA(mapListMat.at(i).value(HTTPKEY::PURCHASEAMOUNT)));
        ui->tableWidgetData->setItem(i, THREE, DATA(mapListMat.at(i).value(HTTPKEY::PURCHASEUNITNAME)));

        ui->tableWidgetData->item(i, ZERO)->setCheckState(Qt::Unchecked);

        SETTABLECENTER(ui->tableWidgetData->item(i, ZERO));
        SETTABLECENTER(ui->tableWidgetData->item(i, ONE));
        SETTABLECENTER(ui->tableWidgetData->item(i, TWO));
        SETTABLECENTER(ui->tableWidgetData->item(i, THREE));
    }

    ui->tableWidgetData->scrollToBottom();

    ui->labelContent->setText(tr("共%1项原料 已确认0项").arg(mapListMat.size()));
}

/*********************  显示窗口       *********************/
void ConfirmMat::showWidget()
{
    ui->checkBoxAllSelect->setChecked(false);
    ui->checkBoxAllSelect->setText(tr("全选"));
    ui->checkBoxAllSelect->setIcon(QIcon(GLOBALDEF::ALLSELECTIMAGE));
    this->show();
}

/*********************  确认采购       *********************/
void ConfirmMat::on_pushButtonConfirm_clicked()
{
    int dataCount = 0;
    for(int i = 0; i < ui->tableWidgetData->rowCount(); i ++)
    {
        if(ui->tableWidgetData->item(i, 0)->checkState() == Qt::Unchecked)
        {
            dataCount ++;
        }
    }

    QByteArray byteArray;
    byteArray.append(POSTARG::AFFIRM.arg(purNumber));

    if(dataCount != 0)
    {
        int ok =  MESSAGEBOX->showMessageBox(this, tr("还有%1项原料未确认，要继续吗？").arg(dataCount), true, false);

        if(ok == QDialog::Accepted)
        {
            HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_PUR_AFFIRM), byteArray, PROTOCOL::URL_PUR_AFFIRM);
        }
    }
    else
    {
        HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_PUR_AFFIRM) , byteArray, PROTOCOL::URL_PUR_AFFIRM);
    }

    this->close();
}

/*********************  全选       *********************/
void ConfirmMat::on_checkBoxAllSelect_clicked()
{
    bool checkFlage = ui->checkBoxAllSelect->isChecked();

    if(checkFlage)
    {
        ui->checkBoxAllSelect->setText(tr("全不选"));
        ui->checkBoxAllSelect->setIcon(QIcon(GLOBALDEF::NOTSELECTIMAGE));

        ui->labelContent->setText(tr("共%1项原料 已确认%1项").arg(mapListMat.size()));
    }
    else
    {
        ui->checkBoxAllSelect->setText(tr("全选"));
        ui->checkBoxAllSelect->setIcon(QIcon(GLOBALDEF::ALLSELECTIMAGE));

        ui->labelContent->setText(tr("共%1项原料 已确认0项").arg(mapListMat.size()));
    }

    Qt::CheckState checkState = ui->checkBoxAllSelect->isChecked() ? Qt::Checked : Qt::Unchecked;

    for(int i = 0; i < ui->tableWidgetData->rowCount(); i ++)
    {
        ui->tableWidgetData->item(i, 0)->setCheckState(checkState);
    }
}

/*********************  选中       *********************/
void ConfirmMat::on_tableWidgetData_clicked(const QModelIndex &index)
{
    if(ui->tableWidgetData->item(index.row(), 0)->checkState() == Qt::Unchecked)
    {
        ui->tableWidgetData->item(index.row(), 0)->setCheckState(Qt::Checked);
    }
    else
    {
        ui->tableWidgetData->item(index.row(), 0)->setCheckState(Qt::Unchecked);
    }
    int dataCount = 0;

    for(int i = 0; i < ui->tableWidgetData->rowCount(); i ++)
    {
        if(ui->tableWidgetData->item(i, 0)->checkState() == Qt::Checked)
        {
            dataCount ++;
        }
    }

    ui->labelContent->setText(tr("共%1项原料 已确认%2项").arg(mapListMat.size()).arg(dataCount));
}
