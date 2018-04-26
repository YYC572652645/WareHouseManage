#include "selectmaterial.h"
#include "ui_selectmaterial.h"
#include "httpclient/httpkey.h"

/*********************  构造函数       *********************/
SelectMaterial::SelectMaterial(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelectMaterial)
{
    ui->setupUi(this);
    this->initControl();
}

/*********************  析构函数       *********************/
SelectMaterial::~SelectMaterial()
{
    delete ui;
}

/*********************  显示窗口       *********************/
void SelectMaterial::showWidget()
{
    titleBar->setTitle(GLOBALDEF::SELECTMATERIAL);
    this->show();
}

/*********************  双击列表       *********************/
void SelectMaterial::on_tableWidget_doubleClicked(const QModelIndex &index)
{
    if(index.row() >= mapListMaterial.size()) return;

    QString boomId = mapFood.value(HTTPKEY::BOMID);
    QString materialId = mapListMaterial.at(index.row()).value(HTTPKEY::MATERIALID);
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_BOM_MAT_NEW).arg(boomId, materialId), PROTOCOL::URL_BOM_MAT_NEW);

    materialInfo->setMatName(ui->tableWidget->item(index.row(), ZERO)->text());
    materialInfo->setBarCode(ui->tableWidget->item(index.row(), ONE)->text());
}

/*********************  初始化控件     *********************/
void SelectMaterial::initControl()
{
    titleBar = new TitleBar(this);

    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    materialInfo = new MaterialInfo(MaterialInfo::ADDTYPE, this);
    SETTABLEWIDGET(ui->tableWidget);
}

/*********************  改变事件       *********************/
void SelectMaterial::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  获取原料信息对象 *********************/
MaterialInfo *SelectMaterial::getMaterialInfo()
{
    return materialInfo;
}

/*********************  设置菜品列表    *********************/
void SelectMaterial::setMapFood(const Map &value)
{
    mapFood = value;
}

/*********************  设置数据        *********************/
void SelectMaterial::setMapListMaterial(const MapList &value)
{
    mapListMaterial = value;

    setTableData();
}

/*********************  设置表格数据     *********************/
void SelectMaterial::setTableData()
{
    ui->tableWidget->setRowCount(mapListMaterial.size());

    for(int i = 0; i < mapListMaterial.size(); i ++)
    {
        ui->tableWidget->setItem(i, ZERO, DATA(mapListMaterial.at(i).value(HTTPKEY::NAME)));    //原料名称
        ui->tableWidget->setItem(i, ONE, DATA(mapListMaterial.at(i).value(HTTPKEY::BARCODE)));  //原料条码

        SETTABLECENTER(ui->tableWidget->item(i, ZERO));
        SETTABLECENTER(ui->tableWidget->item(i, ONE));
    }
    ui->tableWidget->scrollToBottom();
}
