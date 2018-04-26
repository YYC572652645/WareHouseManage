#include "addcheckmat.h"
#include "ui_addcheckmat.h"
#include "httpclient/httpkey.h"

/*********************  构造函数       *********************/
AddCheckMat::AddCheckMat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddCheckMat)
{
    ui->setupUi(this);

    this->initControl();
}

/*********************  析构函数       *********************/
AddCheckMat::~AddCheckMat()
{
    delete ui;
}

/*********************  显示窗口       *********************/
void AddCheckMat::showWidget()
{
    titleBar->setTitle(GLOBALDEF::ADDCHECKMATERIAL);
    ui->checkBoxAllSelect->setChecked(false);
    ui->checkBoxAllSelect->setText(tr("全选"));
    ui->checkBoxAllSelect->setIcon(QIcon(GLOBALDEF::ALLSELECTIMAGE));
    this->show();
}

/*********************  初始化控件       *********************/
void AddCheckMat::initControl()
{
    titleBar = new TitleBar(this);

    titleBar->setTitle(GLOBALDEF::ADDCHECKMATERIAL);
    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    SETTABLEWIDGET(ui->tableWidgetData);
}

/*********************  改变事件        *********************/
void AddCheckMat::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  设置单号        *********************/
void AddCheckMat::setCheckNumber(const QString &value)
{
    checkNumber = value;
}

/*********************  设置仓库ID        *********************/
void AddCheckMat::setWareHouseId(const QString &value)
{
    wareHouseId = value;
}

/*********************  设置原料列表        *********************/
void AddCheckMat::setMapMatList(const MapList &value)
{
    mapMatList = value;

    ui->tableWidgetData->setRowCount(mapMatList.size());

    for(int i = 0; i < mapMatList.size(); i ++)
    {
        ui->tableWidgetData->setItem(i, ZERO,  DATA(mapMatList.at(i).value(HTTPKEY::NAME)));
        ui->tableWidgetData->setItem(i, ONE,   DATA(mapMatList.at(i).value(HTTPKEY::BARCODE)));

        ui->tableWidgetData->item(i, ZERO)->setCheckState(Qt::Unchecked);
        SETTABLECENTER(ui->tableWidgetData->item(i, ZERO));
        SETTABLECENTER(ui->tableWidgetData->item(i, ONE));
    }

    ui->tableWidgetData->scrollToBottom();
}

/*********************  保存数据        *********************/
void AddCheckMat::on_pushButtonSave_clicked()
{
    QByteArray byteArray;

    List listData;

    for(int i = 0; i < ui->tableWidgetData->rowCount(); i ++)
    {
        if(ui->tableWidgetData->item(i, ZERO)->checkState() == Qt::Checked)
        {
            listData.append(mapMatList.at(i).value(HTTPKEY::MATERIALID));
        }
    }

    byteArray.append(POSTARG::ADDCHECKMAT.arg(checkNumber, HTTPCLIENT->makeJson(listData), wareHouseId));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_CHECK_ADD_MAT), byteArray, PROTOCOL::URL_CHECK_ADD_MAT);

    this->close();
}

/*********************  取消按钮        *********************/
void AddCheckMat::on_pushButtonCancel_clicked()
{
    this->close();
}

/*********************  全选        *********************/
void AddCheckMat::on_checkBoxAllSelect_clicked()
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
        ui->tableWidgetData->item(i, ZERO)->setCheckState(checkState);
    }
}

/*********************  单击控件        *********************/
void AddCheckMat::on_tableWidgetData_clicked(const QModelIndex &index)
{
    if(ui->tableWidgetData->item(index.row(), ZERO)->checkState() == Qt::Unchecked)
    {
        ui->tableWidgetData->item(index.row(), ZERO)->setCheckState(Qt::Checked);
    }
    else
    {
        ui->tableWidgetData->item(index.row(), ZERO)->setCheckState(Qt::Unchecked);
    }
}
