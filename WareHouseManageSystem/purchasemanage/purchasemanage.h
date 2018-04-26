#ifndef PURCHASEMANAGE_H
#define PURCHASEMANAGE_H

/***************************************************************
   功能:采购管理

   创建人:YYC

   创建时间:2017-11-22
**************************************************************/

#include <QWidget>
#include "purchasemanage/purchaseorder/purchaseorder.h"
#include "purchasestorage/purchasestorage.h"
#include "purreturngood/purreturngood.h"
#include "purchasesafe/purchasesafe.h"

namespace Ui {
class purchasemanage;
}

class PurchaseManage : public QWidget
{
    Q_OBJECT

public:
    explicit PurchaseManage(QWidget *parent = 0);  //构造函数
    ~PurchaseManage();                             //析构函数
    PurchaseOrder &getPurchaseOrder();             //获取采购订单对象
    PurchaseStorage &getPurchaseStorage();         //获取采购入库对象
    PurReturnGood &getPurReturnGood();             //获取退货订单对象
    PurchaseSafe &getPurchaseSafe();               //获取安全库存对象

private slots:
    void on_treeWidget_clicked(const QModelIndex &index); //单击控件
    void receiveShow();                                   //显示窗口
    void receiveClose();                                  //关闭窗口

private:
    Ui::purchasemanage *ui;

    int currentRow;                           //当前行
    void initControl();                       //初始化控件
    void resizeEvent(QResizeEvent*event);     //界面改变
    PurchaseOrder purchaseOrder;              //采购订单对象
    PurchaseStorage purchaseStorage;          //采购入库
    PurReturnGood purReturnGood;              //采购退货
    PurchaseSafe purchaseSafe;                //安全库存采购

    QList<QWidget*>listTab;
};

#endif // PURCHASEMANAGE_H
