#include "materialcostinfo.h"
#include "ui_materialcostinfo.h"
#include "httpclient/httpkey.h"
#include "messagebox/messagedialog.h"
#include <QRegExp>


/*********************  构造函数        *********************/
MaterialCostInfo::MaterialCostInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::materialcostinfo)
{
    ui->setupUi(this);
    this->initControl();
}

/*********************  析构函数        *********************/
MaterialCostInfo::~MaterialCostInfo()
{
    delete ui;
}

/*********************  显示窗口        *********************/
void MaterialCostInfo::showWidget()
{
    titleBar->setTitle(GLOBALDEF::MATERIALINFO);
    this->show();
}

/*********************  设置控件数据        *********************/
void MaterialCostInfo::setControlData()
{
    ui->lineEditMatName->setText(matMap.value(HTTPKEY::MATERIALNAME));
    ui->lineEditBarCode->setText(matMap.value(HTTPKEY::BARCODE));
    ui->lineEditPriceBefore->setText(matMap.value(HTTPKEY::OLDPRICE));
    ui->lineEditSpec->setText(matMap.value(HTTPKEY::STANDARD));
    ui->lineEditDifference->setText(matMap.value(HTTPKEY::DIFFERENCEPRICE));
    ui->lineEditUnitName->setText(matMap.value(HTTPKEY::UNITNAME));
    ui->spinBoxPriceAfter->setValue(matMap.value(HTTPKEY::NEWPRICE).toDouble());
}

/*********************  设置隐藏        *********************/
void MaterialCostInfo::setHide()
{
    ui->pushButtonDel->setHidden(true);
    ui->pushButtonCancel->setHidden(true);
    ui->pushButtonSave->setHidden(true);
    ui->spinBoxPriceAfter->setEnabled(false);
}

/*********************  设置显示        *********************/
void MaterialCostInfo::setShow()
{
    ui->pushButtonDel->show();
    ui->pushButtonCancel->show();
    ui->pushButtonSave->show();

    ui->spinBoxPriceAfter->setEnabled(true);
}

/*********************  保存数据        *********************/
void MaterialCostInfo::on_pushButtonSave_clicked()
{
    QByteArray byteArray;

    QString strPost = POSTARG::UPDATECOSTMAT.arg(matMap.value(HTTPKEY::READJUSTMATID));

    strPost = strPost.arg(ui->lineEditDifference->text(), ui->lineEditPriceBefore->text());

    strPost = strPost.arg(ui->spinBoxPriceAfter->value());

    byteArray.append(strPost);

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_COST_UPDATE_MAT), byteArray, PROTOCOL::URL_COST_UPDATE_MAT);

    this->close();
}

/*********************  取消事件        *********************/
void MaterialCostInfo::on_pushButtonCancel_clicked()
{
    this->close();
}

/*********************  初始化控件       *********************/
void MaterialCostInfo::initControl()
{
    titleBar = new TitleBar(this);

    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

}

/*********************  改变事件        *********************/
void MaterialCostInfo::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  设置原料        *********************/
void MaterialCostInfo::setMatMap(const Map &value)
{
    matMap = value;
}

/*********************  删除原料        *********************/
void MaterialCostInfo::on_pushButtonDel_clicked()
{
    QByteArray byteArray;

    byteArray.append(POSTARG::DELCOSTMAT.arg(matMap.value(HTTPKEY::READJUSTMATID)));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_COST_DEL_MAT), byteArray, PROTOCOL::URL_COST_DEL_MAT);

    this->close();
}

/*********************  数据改变        *********************/
void MaterialCostInfo::on_spinBoxPriceAfter_valueChanged(double arg1)
{
    ui->lineEditDifference->setText(QString::number(arg1 + matMap.value(HTTPKEY::NUMBER).toDouble()));
}
