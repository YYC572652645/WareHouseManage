#include "baseinfomanage.h"
#include "ui_baseinfomanage.h"
#include "global/globaldef.h"

/************************   构造函数            ********************/
BaseInfoManage::BaseInfoManage(QWidget *parent) :
    QWidget(parent),ui(new Ui::baseinfomanage)
  ,currentRow(-1)
{
    ui->setupUi(this);
    this->initControl();
}

/************************   析构函数            ********************/
BaseInfoManage::~BaseInfoManage()
{
    delete ui;
}

/************************   初始化控件            ********************/
void BaseInfoManage::initControl()
{
    SETTREEWIDGET(ui->treeWidget);

    ui->tabWidget->tabBar()->hide();

    ui->tabWidget->addTab(&materialWidget, NULL);
    ui->tabWidget->addTab(&wareHouseWidget, NULL);
    ui->tabWidget->addTab(&supplierWidget, NULL);
    ui->tabWidget->addTab(&templateWidget, NULL);
    ui->tabWidget->addTab(&materialRatioWidget, NULL);

    listTab.append(&materialWidget);
    listTab.append(&wareHouseWidget);
    listTab.append(&supplierWidget);
    listTab.append(&templateWidget);
    listTab.append(&materialRatioWidget);

    for(int i = 0; i < listTab.size(); i++)
    {
        listTab.at(i)->hide();
    }
}

/************************   初始化控件            ********************/
MaterialWidget &BaseInfoManage::getMaterialWidget()
{
    return materialWidget;
}

/************************   获取供应商窗口对象       ********************/
SupplierWidget &BaseInfoManage::getSupplierWidget()
{
    return supplierWidget;
}

/************************   仓库窗口对象            ********************/
WareHouseWidget &BaseInfoManage::getWareHouseWidget()
{
    return wareHouseWidget;
}

/************************   获取模板窗口对象       ********************/
TemplateWidget &BaseInfoManage::getTemplateWidget()
{
    return templateWidget;
}

/************************   获取材料配比窗口对象       ********************/
MaterialRatioWidget &BaseInfoManage::getMaterialRatioWidget()
{
    return materialRatioWidget;
}

void BaseInfoManage::resizeEvent(QResizeEvent *event)
{
    if(currentRow != -1 && currentRow < listTab.size())
        listTab.at(currentRow)->resize(ui->tabWidget->size());
}

/************************   单击响应       ********************/
void BaseInfoManage::on_treeWidget_clicked(const QModelIndex &index)
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
    case ZERO:  materialWidget.showWidget();      break;
    case ONE:   wareHouseWidget.showWidget();     break;
    case TWO:   supplierWidget.showWidget();      break;
    case THREE: templateWidget.showWidget();      break;
    case FOUR:  materialRatioWidget.showWidget(); break;
    }
}
