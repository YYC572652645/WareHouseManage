#include "subposition.h"
#include "ui_subposition.h"
#include <QListView>
#include <httpclient/httpkey.h>

/*********************  构造函数       *********************/
SubPosition::SubPosition(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SubPosition)
{
    ui->setupUi(this);
    this->initControl();
}

/*********************  析构函数       *********************/
SubPosition::~SubPosition()
{
    delete ui;
}

/*********************  显示窗口       *********************/
void SubPosition::showWidget()
{
    titleBar->setTitle(GLOBALDEF::SUBPOSITION);
    ui->doubleSpinBoxNumber->setMaximum(numberCount.toDouble());
    ui->labelNumber->setText(tr("数量：(%1)").arg(unitName));
    ui->lineEditTotalMoney->setText(QString::number(numberCount.toDouble() * priceName.toDouble()));
    ui->doubleSpinBoxNumber->setValue(numberCount.toDouble());

    totalMoney = ui->lineEditTotalMoney->text();
    this->show();
}

/*********************  保存数据       *********************/
void SubPosition::on_pushButtonSave_clicked()
{
    if(ui->comboBoxWareHouse->currentIndex() >= wareHouseMapList.size()) return;
    QString wareHouseId = wareHouseMapList.at(ui->comboBoxWareHouse->currentIndex()).value(HTTPKEY::WAREHOUSEID);
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STO_JUDGE).arg(stoMatId, wareHouseId), PROTOCOL::URL_STO_JUDGE);
}

/*********************  取消按钮       *********************/
void SubPosition::on_pushButtonCancel_clicked()
{
    this->close();
}

/*********************  数字改变       *********************/
void SubPosition::on_doubleSpinBoxNumber_valueChanged(double arg1)
{
    numberCount = QString::number(arg1);
    ui->lineEditTotalMoney->setText(QString::number(priceName.toDouble() * arg1));

    totalMoney = QString::number(priceName.toDouble() * arg1);
}

/*********************  获取总数量       *********************/
QString SubPosition::getNumberCount() const
{
    return numberCount;
}

/*********************  获取仓库名称       *********************/
QString SubPosition::getWareHouseId() const
{
    if(ui->comboBoxWareHouse->currentIndex() >= wareHouseMapList.size()) return NULL;
    QString wareHouseId = wareHouseMapList.at(ui->comboBoxWareHouse->currentIndex()).value(HTTPKEY::WAREHOUSEID);

    return wareHouseId;
}

/*********************  获取总价钱       *********************/
QString SubPosition::getTotalMoney() const
{
    return totalMoney;
}

/*********************  设置入库单ID       *********************/
void SubPosition::setStoMatId(const QString &value)
{
    stoMatId = value;
}

/*********************  设置数据       *********************/
void SubPosition::setMapData(const Map &value)
{
    mapData = value;
}

/*********************  设置仓库列表       *********************/
void SubPosition::setWareHouseMapList(const MapList &value)
{
    wareHouseMapList = value;

    ui->comboBoxWareHouse->clear();
    for(int i = 0; i < wareHouseMapList.size(); i ++)
    {
        ui->comboBoxWareHouse->addItem(wareHouseMapList.at(i).value(HTTPKEY::NAME));
    }
}

/*********************  设置数量       *********************/
void SubPosition::setNumberCount(const QString &value)
{
    numberCount = value;
}

/*********************  设置单位       *********************/
void SubPosition::setUnitName(const QString &value)
{
    unitName = value;
}

/*********************  设置价格       *********************/
void SubPosition::setPriceName(const QString &value)
{
    priceName = value;
}

/*********************  初始化控件       *********************/
void SubPosition::initControl()
{
    titleBar = new TitleBar(this);
    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    ui->comboBoxWareHouse->setView(new QListView());
    ui->comboBoxWareHouse->setFocusPolicy(Qt::NoFocus);
}

/*********************  改变事件        *********************/
void SubPosition::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}
