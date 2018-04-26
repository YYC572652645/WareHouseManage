#include "materialpurinfo.h"
#include "ui_materialpurinfo.h"
#include "httpclient/httpkey.h"


/*********************  构造函数        *********************/
MaterialPurInfo::MaterialPurInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MaterialPurInfo)
{
    ui->setupUi(this);
    this->initControl();
}


/*********************  析构函数        *********************/
MaterialPurInfo::~MaterialPurInfo()
{
    delete ui;
}

/*********************  显示窗口        *********************/
void MaterialPurInfo::showWidget()
{
    titleBar->setTitle(GLOBALDEF::MATERIALINFO);
    this->show();
}

/*********************  设置控件数据        *********************/
void MaterialPurInfo::setControlData()
{
    ui->comboBoxUnit->clear();
    for(int i = 0; i < unitMapList.size(); i ++)
    {
        QString unitName = unitMapList.at(i).value(HTTPKEY::NAME);
        ui->comboBoxUnit->addItem(unitName);

        if(unitMapList.at(i).value(HTTPKEY::UNITID) == matMap.value(HTTPKEY::PURCHASEUNIT))
        {
            ui->comboBoxUnit->setCurrentText(unitName);
            ui->labelUnitPrice->setText(tr("单价(元/%1)").arg(unitName));
            ui->labelNowNumber->setText(tr("现有库存(%1)").arg(unitName));
            ui->labelNumber->setText(tr("数量(%1)").arg(unitName));
        }
    }

    ui->lineEditBarCode->setText(matMap.value(HTTPKEY::BARCODE));
    ui->lineEditInventory->setText(matMap.value(HTTPKEY::INVENTORY));
    ui->lineEditMatName->setText(matMap.value(HTTPKEY::MATERIALNAME));
    ui->spinBoxPrice->setValue(matMap.value(HTTPKEY::PURCHASEPRICE).toDouble());
    ui->spinBoxNumber->setValue(matMap.value(HTTPKEY::PURCHASEAMOUNT).toDouble());
    ui->lineEditTotalMoney->setText(matMap.value(HTTPKEY::TOTALMONEY));
}

/*********************  保存数据        *********************/
void MaterialPurInfo::on_pushButtonSave_clicked()
{
    int currentIndex = ui->comboBoxUnit->currentIndex();
    if(currentIndex < 0 || currentIndex >=  unitMapList.size()) return;

    QByteArray byteArray;

    QString strPost = POSTARG::UPDATEMAT.arg(matMap.value(HTTPKEY::PURCHASEMATERIALID));

    QString purchaseUnit = unitMapList.at(currentIndex).value(HTTPKEY::UNITID);

    strPost = strPost.arg(QString::number(ui->spinBoxPrice->value()), purchaseUnit);

    strPost = strPost.arg(QString::number(ui->spinBoxNumber->value()), ui->lineEditTotalMoney->text());

    byteArray.append(strPost);

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_PUR_UPDATE_MAT), byteArray, PROTOCOL::URL_PUR_UPDATE_MAT);

    this->close();
}

/*********************  取消事件        *********************/
void MaterialPurInfo::on_pushButtonCancel_clicked()
{
    this->close();
}

/*********************  初始化控件       *********************/
void MaterialPurInfo::initControl()
{
    titleBar = new TitleBar(this);
    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    ui->comboBoxUnit->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxUnit->setView(new QListView());
}

/*********************  改变事件        *********************/
void MaterialPurInfo::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  设置原料        *********************/
void MaterialPurInfo::setMatMap(const Map &value)
{
    matMap = value;
}

/*********************  设置控件是否可用        *********************/
void MaterialPurInfo::setControlEnable(bool flage)
{
    ui->spinBoxNumber->setEnabled(flage);
    ui->spinBoxPrice->setEnabled(flage);
    ui->comboBoxUnit->setEnabled(flage);

    ui->pushButtonSave->setHidden(!flage);
    ui->pushButtonCancel->setHidden(!flage);
}

/*********************  设置单位列表        *********************/
void MaterialPurInfo::setUnitMapList(const MapList &value)
{
    unitMapList = value;
}

/*********************  单位点击        *********************/
void MaterialPurInfo::on_comboBoxUnit_activated(const QString &arg1)
{
    ui->labelUnitPrice->setText(tr("单价(元/%1)").arg(arg1));
    ui->labelNowNumber->setText(tr("现有库存(%1)").arg(arg1));
    ui->labelNumber->setText(tr("数量(%1)").arg(arg1));
}

/*********************  数量改变        *********************/
void MaterialPurInfo::on_spinBoxNumber_valueChanged(double arg1)
{
    QString totalMoney = QString::number(ui->spinBoxPrice->value() * arg1);

    ui->lineEditTotalMoney->setText(totalMoney);
}

/*********************  单价改变        *********************/
void MaterialPurInfo::on_spinBoxPrice_valueChanged(double arg1)
{
    QString totalMoney = QString::number(ui->spinBoxNumber->value() * arg1);

    ui->lineEditTotalMoney->setText(totalMoney);
}

