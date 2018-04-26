#include "purchasemanage.h"
#include "ui_purchasemanage.h"

/************************   构造函数            ********************/
PurchaseManage::PurchaseManage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::purchasemanage)
  ,currentRow(-1)
{
    ui->setupUi(this);
    this->initControl();
}

/************************   析构函数            ********************/
PurchaseManage::~PurchaseManage()
{
    delete ui;
}

/************************   初始化控件            ********************/
void PurchaseManage::initControl()
{
    ui->tabWidget->tabBar()->hide();

    ui->tabWidget->addTab(&purchaseOrder, NULL);
    ui->tabWidget->addTab(&purchaseStorage, NULL);
    ui->tabWidget->addTab(&purReturnGood, NULL);
    ui->tabWidget->addTab(&purchaseSafe, NULL);

    listTab.append(&purchaseOrder);
    listTab.append(&purchaseStorage);
    listTab.append(&purReturnGood);
    listTab.append(&purchaseSafe);

    for(int i = 0; i < listTab.size(); i++)
    {
        listTab.at(i)->hide();
    }

    SETTREEWIDGET(ui->treeWidget);

    connect(&purchaseStorage, SIGNAL(signalShow()), this, SLOT(receiveShow()));
    connect(&purchaseStorage, SIGNAL(signalClose()), this, SLOT(receiveClose()));
}

/************************   界面改变       ********************/
void PurchaseManage::resizeEvent(QResizeEvent *event)
{
    if(currentRow != -1 && currentRow < listTab.size())
        listTab.at(currentRow)->resize(ui->tabWidget->size());
}

/************************   获取安全库存对象       ********************/
PurchaseSafe &PurchaseManage::getPurchaseSafe()
{
    return purchaseSafe;
}

/************************   获取退货订单对象       ********************/
PurReturnGood &PurchaseManage::getPurReturnGood()
{
    return purReturnGood;
}

/************************   获取采购入库对象       ********************/
PurchaseStorage &PurchaseManage::getPurchaseStorage()
{
    return purchaseStorage;
}

/************************   获取采购订单对象       ********************/
PurchaseOrder &PurchaseManage::getPurchaseOrder()
{
    return purchaseOrder;
}

/************************   单击控件            ********************/
void PurchaseManage::on_treeWidget_clicked(const QModelIndex &index)
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
    case ZERO:  purchaseOrder.showWidget();     break;
    case ONE:   purchaseStorage.showWidget();   break;
    case TWO:   purReturnGood.showWidget();     break;
    case THREE: purchaseSafe.showWidget();     break;
    }
}

/************************   显示窗口            ********************/
void PurchaseManage::receiveShow()
{
    if(ONE >= listTab.size()) return;

    for(int i = 0; i < listTab.size(); i ++)
    {
        if(ONE != i)
        {
            listTab.at(i)->hide();
        }
    }

    listTab.at(ONE)->showMaximized();
    listTab.at(ONE)->resize(ui->tabWidget->size());
}

/************************   关闭窗口            ********************/
void PurchaseManage::receiveClose()
{
    if(ZERO >= listTab.size()) return;

    for(int i = 0; i < listTab.size(); i ++)
    {
        if(ZERO != i)
        {
            listTab.at(i)->hide();
        }
    }

    listTab.at(ZERO)->showMaximized();
    listTab.at(ZERO)->resize(ui->tabWidget->size());
}
