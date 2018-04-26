#ifndef WAREHOUSEMANAGE_H
#define WAREHOUSEMANAGE_H

/***************************************************************
   功能:仓库管理

   创建人:YYC

   创建时间:2017-11-22
**************************************************************/

#include <QWidget>
#include "global/globaldef.h"
#include "warehousemanage/realtimeinventory/realtimeinventory.h"
#include "warehousemanage/inventoryadjust/inventoryadjust.h"
#include "warehousemanage/inventorycheck/inventorycheck.h"
#include "warehousemanage/inventorychange/inventorychange.h"
#include "warehousemanage/costadjustment/costadjustment.h"
#include "warehousemanage/inventorylimit/inventorylimit.h"
#include "warehousemanage/inventorytransfer/inventorytransfer.h"

namespace Ui {
class warehousemanage;
}

class WareHouseManage : public QWidget
{
    Q_OBJECT

public:
    explicit WareHouseManage(QWidget *parent = 0);   //构造函数
    ~WareHouseManage();                              //析构函数
    RealTimeInventory &getRealTimeInventory();       //获取实时库存
    InventoryAdjust &getInventoryAdjust();           //获取库存调整
    InventoryCheck &getInventoryCheck();             //获取库存盘点
    InventoryChange &getInventoryChange();           //获取库存变更
    CostAdjustment &getCostAdjustment();             //获取成本调价
    InventoryLimit &getInventoryLimit();             //获取库存上下限
    InventoryTransfer &getInventoryTransfer();       //获取库存调拨

private slots:
    void on_treeWidget_clicked(const QModelIndex &index); //单击响应

private:
    Ui::warehousemanage *ui;

    void initControl();                     //初始化控件
    void resizeEvent(QResizeEvent *event);  //界面改变

    RealTimeInventory realTimeInventory;
    InventoryAdjust inventoryAdjust;
    InventoryCheck  inventoryCheck;
    InventoryChange inventoryChange;
    CostAdjustment costAdjustment;
    InventoryLimit inventoryLimit;
    InventoryTransfer inventoryTransfer;

    int currentRow;
    QList<QWidget*>listTab;
};

#endif // WAREHOUSEMANAGE_H
