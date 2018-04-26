#include "warehousemanage.h"
#include "ui_warehousemanage.h"

/************************   构造函数            ********************/
WareHouseManage::WareHouseManage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::warehousemanage)
  ,currentRow(-1)
{
    ui->setupUi(this);

    this->initControl();
}

/************************   析构函数            ********************/
WareHouseManage::~WareHouseManage()
{
    delete ui;
}

/************************   初始化控件            ********************/
void WareHouseManage::initControl()
{
    ui->tabWidget->tabBar()->hide();

    ui->tabWidget->addTab(&realTimeInventory, NULL);
    ui->tabWidget->addTab(&inventoryAdjust, NULL);
    ui->tabWidget->addTab(&inventoryCheck, NULL);
    ui->tabWidget->addTab(&inventoryChange, NULL);
    ui->tabWidget->addTab(&costAdjustment, NULL);
    ui->tabWidget->addTab(&inventoryLimit, NULL);
    ui->tabWidget->addTab(&inventoryTransfer, NULL);

    listTab.append(&realTimeInventory);
    listTab.append(&inventoryAdjust);
    listTab.append(&inventoryCheck);
    listTab.append(&inventoryChange);
    listTab.append(&costAdjustment);
    listTab.append(&inventoryLimit);
    listTab.append(&inventoryTransfer);

    for(int i = 0; i < listTab.size(); i++)
    {
        listTab.at(i)->hide();
    }

    SETTREEWIDGET(ui->treeWidget);
}

/************************   界面改变       ********************/
void WareHouseManage::resizeEvent(QResizeEvent *event)
{
    if(currentRow != -1 && currentRow < listTab.size())
        listTab.at(currentRow)->resize(ui->tabWidget->size());
}

/************************   获取库存调拨    ********************/
InventoryTransfer &WareHouseManage::getInventoryTransfer()
{
    return inventoryTransfer;
}

/************************   获取库存上下限    ********************/
InventoryLimit &WareHouseManage::getInventoryLimit()
{
    return inventoryLimit;
}

/************************   获取成本调价       ********************/
CostAdjustment &WareHouseManage::getCostAdjustment()
{
    return costAdjustment;
}

/************************   获取库存变更       ********************/
InventoryChange &WareHouseManage::getInventoryChange()
{
    return inventoryChange;
}

/************************   获取库存盘点       ********************/
InventoryCheck &WareHouseManage::getInventoryCheck()
{
    return inventoryCheck;
}

/************************   获取库存调整       ********************/
InventoryAdjust &WareHouseManage::getInventoryAdjust()
{
    return inventoryAdjust;
}

/************************   获取实时库存       ********************/
RealTimeInventory &WareHouseManage::getRealTimeInventory()
{
    return realTimeInventory;
}

/************************   单击响应       ********************/
void WareHouseManage::on_treeWidget_clicked(const QModelIndex &index)
{
    if(index.row() >= listTab.size()) return;

    currentRow = index.row();

    for(int i = 0; i < listTab.size(); i ++)
    {
        if(index.row() != i)
        {
            listTab.at(i)->hide();
        }
    }

    listTab.at(index.row())->showMaximized();
    listTab.at(index.row())->resize(ui->tabWidget->size());

    switch(index.row())
    {
    case ZERO:  realTimeInventory.showWidget();   break;
    case ONE:   inventoryAdjust.showWidget();     break;
    case TWO:   inventoryCheck.showWidget();      break;
    case THREE: inventoryChange.showWidget();     break;
    case FOUR:  costAdjustment.showWidget();      break;
    case FIVE:  inventoryLimit.showWidget();      break;
    case SIX:   inventoryTransfer.showWidget();      break;
    }
}
