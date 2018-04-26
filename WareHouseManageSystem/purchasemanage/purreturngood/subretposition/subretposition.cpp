#include "subretposition.h"
#include "ui_subretposition.h"
#include <QListView>
#include <httpclient/httpkey.h>

/*********************  构造函数       *********************/
SubRetPosition::SubRetPosition(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SubRetPosition)
{
    ui->setupUi(this);
    this->initControl();
}

/*********************  析构函数       *********************/
SubRetPosition::~SubRetPosition()
{
    delete ui;
}

/*********************  显示窗口       *********************/
void SubRetPosition::showWidget()
{
    titleBar->setTitle(GLOBALDEF::SUBPOSITION);
    ui->doubleSpinBoxNumber->setMaximum(numberCount.toDouble());
    ui->labelNumber->setText(tr("数量：(%1)").arg(unitName));
    ui->lineEditTotalMoney->setText(QString::number(numberCount.toDouble() * priceName.toDouble()));
    ui->doubleSpinBoxNumber->setValue(numberCount.toDouble());

    totalMoney =  ui->lineEditTotalMoney->text();
    this->show();
}

/*********************  保存数据       *********************/
void SubRetPosition::on_pushButtonSave_clicked()
{
    if(ui->comboBoxWareHouse->currentIndex() >= wareHouseMapList.size()) return;
    QString wareHouseId = wareHouseMapList.at(ui->comboBoxWareHouse->currentIndex()).value(HTTPKEY::WAREHOUSEID);
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_RETURN_JUDGE).arg(stoMatId, wareHouseId), PROTOCOL::URL_RETURN_JUDGE);
}

/*********************  取消按钮       *********************/
void SubRetPosition::on_pushButtonCancel_clicked()
{
    this->close();
}

/*********************  数字改变       *********************/
void SubRetPosition::on_doubleSpinBoxNumber_valueChanged(double arg1)
{
    numberCount = QString::number(arg1);
    ui->lineEditTotalMoney->setText(QString::number(priceName.toDouble() * arg1));

    totalMoney = QString::number(priceName.toDouble() * arg1);
}

/*********************  获取总数量       *********************/
QString SubRetPosition::getNumberCount() const
{
    return numberCount;
}

/*********************  获取仓库名称       *********************/
QString SubRetPosition::getWareHouseId() const
{
    if(ui->comboBoxWareHouse->currentIndex() >= wareHouseMapList.size()) return NULL;
    QString wareHouseId = wareHouseMapList.at(ui->comboBoxWareHouse->currentIndex()).value(HTTPKEY::WAREHOUSEID);

    return wareHouseId;
}

/*********************  获取总价钱       *********************/
QString SubRetPosition::getTotalMoney() const
{
    return totalMoney;
}

/*********************  设置入库单ID       *********************/
void SubRetPosition::setStoMatId(const QString &value)
{
    stoMatId = value;
}

/*********************  设置数据       *********************/
void SubRetPosition::setMapData(const Map &value)
{
    mapData = value;
}

/*********************  设置仓库列表       *********************/
void SubRetPosition::setWareHouseMapList(const MapList &value)
{
    wareHouseMapList = value;

    ui->comboBoxWareHouse->clear();
    for(int i = 0; i < wareHouseMapList.size(); i ++)
    {
        ui->comboBoxWareHouse->addItem(wareHouseMapList.at(i).value(HTTPKEY::NAME));
    }
}

/*********************  设置数量       *********************/
void SubRetPosition::setNumberCount(const QString &value)
{
    numberCount = value;
}

/*********************  设置单位       *********************/
void SubRetPosition::setUnitName(const QString &value)
{
    unitName = value;
}

/*********************  设置价格       *********************/
void SubRetPosition::setPriceName(const QString &value)
{
    priceName = value;
}

/*********************  初始化控件       *********************/
void SubRetPosition::initControl()
{
    titleBar = new TitleBar(this);
    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    ui->comboBoxWareHouse->setView(new QListView());
    ui->comboBoxWareHouse->setFocusPolicy(Qt::NoFocus);
}

/*********************  改变事件        *********************/
void SubRetPosition::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}
