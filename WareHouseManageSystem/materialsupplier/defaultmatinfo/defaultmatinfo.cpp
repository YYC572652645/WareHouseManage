#include "defaultmatinfo.h"
#include "ui_defaultmatinfo.h"
#include "httpclient/httpkey.h"
#include "messagebox/messagedialog.h"

/*********************  构造函数        *********************/
DefaultMatInfo::DefaultMatInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DefaultMatInfo)
{
    ui->setupUi(this);

    this->initControl();
}

/*********************  析构函数        *********************/
DefaultMatInfo::~DefaultMatInfo()
{
    delete ui;
}

/*********************  初始化控件       *********************/
void DefaultMatInfo::initControl()
{
    titleBar = new TitleBar(this);
    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    ui->comboBoxSupplier->setView(new QListView());
    ui->comboBoxSupplier->setFocusPolicy(Qt::NoFocus);
}

/*********************  改变事件        *********************/
void DefaultMatInfo::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  设置供应商列表    *********************/
void DefaultMatInfo::setMapListSupplier(const MapList &value)
{
    mapListSupplier = value;

    ui->comboBoxSupplier->clear();
    for(int i = 0; i < mapListSupplier.size(); i ++)
    {
        ui->comboBoxSupplier->addItem(mapListSupplier.at(i).value(HTTPKEY::SUPPLIERNAME));

        if(mapMatData.value(HTTPKEY::DEFAULTSUPPLIERID) == mapListSupplier.at(i).value(HTTPKEY::SUPPLIERID))
        {
            ui->comboBoxSupplier->setCurrentIndex(i);
        }
    }


    if(mapMatData.value(HTTPKEY::DEFAULTSUPPLIERID) == "0")
    {
        ui->comboBoxSupplier->setCurrentIndex(-1);
    }
}

/********************* 设置数据        *********************/
void DefaultMatInfo::setMapMatData(const Map &value)
{
    mapMatData = value;

    ui->lineEditMatName->setText(mapMatData.value(HTTPKEY::NAME));
    ui->lineEditBarCode->setText(mapMatData.value(HTTPKEY::BARCODE));
    ui->lineEditSpec->setText(mapMatData.value(HTTPKEY::STANDARD));
}

/********************* 显示窗口        *********************/
void DefaultMatInfo::showWidget()
{
    titleBar->setTitle(GLOBALDEF::TABMATERIALINFO);
    this->show();
}

/*********************  保存按钮        *********************/
void DefaultMatInfo::on_pushButtonSave_clicked()
{
    int ok = MESSAGEBOX->showMessageBox(this, MESSAGE::SUPCANNOTSET, true, false);

    if(ok == QDialog::Accepted)
    {
        if(ui->comboBoxSupplier->currentIndex() >= 0 && ui->comboBoxSupplier->currentIndex() < mapListSupplier.size())
        {
            QByteArray byteArray;

            List listData;

            listData.append(mapMatData.value(HTTPKEY::MATERIALID));
            QString supplierId = mapListSupplier.at(ui->comboBoxSupplier->currentIndex()).value(HTTPKEY::SUPPLIERID);

            byteArray.append(POSTARG::UPDATESUPLIST.arg(HTTPCLIENT->makeJson(listData), supplierId));
            HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_DEFAULT_UPDATE_SUP), byteArray, PROTOCOL::URL_DEFAULT_UPDATE_SUP);
        }
        this->close();
    }
}

/*********************  取消按钮        *********************/
void DefaultMatInfo::on_pushButtonCancel_clicked()
{
    this->close();
}
