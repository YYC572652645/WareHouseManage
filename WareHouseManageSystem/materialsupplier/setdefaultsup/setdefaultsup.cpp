#include "setdefaultsup.h"
#include "ui_setdefaultsup.h"
#include "httpclient/httpkey.h"
#include "messagebox/messagedialog.h"

/*********************  构造函数        *********************/
SetDefaultSup::SetDefaultSup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetDefaultSup)
{
    ui->setupUi(this);

    this->initControl();
}

/*********************  析构函数        *********************/
SetDefaultSup::~SetDefaultSup()
{
    delete ui;
}

/*********************  初始化控件       *********************/
void SetDefaultSup::initControl()
{
    titleBar = new TitleBar(this);
    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    ui->comboBoxSupplier->setView(new QListView());
    ui->comboBoxSupplier->setFocusPolicy(Qt::NoFocus);
}

/*********************  改变事件        *********************/
void SetDefaultSup::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  设置原料列表    *********************/
void SetDefaultSup::setMapListMat(const MapList &value)
{
    mapListMat = value;
}

/*********************  设置原料个数    *********************/
void SetDefaultSup::setMatNumber(const QString &value)
{
    matNumber = value;
    ui->lineEditMatNumber->setText(value);
}

/*********************  设置供应商列表    *********************/
void SetDefaultSup::setMapListSupplier(const MapList &value)
{
    mapListSupplier = value;

    ui->comboBoxSupplier->clear();
    for(int i = 0; i < mapListSupplier.size(); i ++)
    {
        ui->comboBoxSupplier->addItem(mapListSupplier.at(i).value(HTTPKEY::SUPPLIERNAME));

    }

    ui->comboBoxSupplier->setCurrentIndex(-1);
}

/********************* 显示窗口        *********************/
void SetDefaultSup::showWidget()
{
    titleBar->setTitle(GLOBALDEF::SETDEFAULTSUP);
    this->show();
}

/*********************  保存按钮        *********************/
void SetDefaultSup::on_pushButtonSave_clicked()
{
    int ok = MESSAGEBOX->showMessageBox(this, MESSAGE::SUPCANNOTSET, true, false);

    if(ok == QDialog::Accepted)
    {
        if(ui->comboBoxSupplier->currentIndex() >= 0 && ui->comboBoxSupplier->currentIndex() < mapListSupplier.size())
        {
            QByteArray byteArray;

            List listData;

            for(int i = 0; i < mapListMat.size(); i ++)
            {
                listData.append(mapListMat.at(i).value(HTTPKEY::MATERIALID));
            }

            QString supplierId = mapListSupplier.at(ui->comboBoxSupplier->currentIndex()).value(HTTPKEY::SUPPLIERID);
            byteArray.append(POSTARG::UPDATESUPLIST.arg(HTTPCLIENT->makeJson(listData), supplierId));
            HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_DEFAULT_UPDATE_SUP), byteArray, PROTOCOL::URL_DEFAULT_UPDATE_SUP);
        }
        this->close();
    }
}

/*********************  取消按钮        *********************/
void SetDefaultSup::on_pushButtonCancel_clicked()
{
    this->close();
}
