#ifndef BASEINFOMANAGE_H
#define BASEINFOMANAGE_H

/***************************************************************
   功能:基本功能

   创建人:YYC

   创建时间:2017-11-22
**************************************************************/

#include <QWidget>
#include <QEvent>
#include "materialsetup/materwidget/materialwidget.h"
#include "warehousesetup/warehousewidget/warehousewidget.h"
#include "suppliersetup/supplierwidget/supplierwidget.h"
#include "templatesetup/templatewidget/templatewidget.h"
#include "materialratiosetup/materialratiowidget/materialratiowidget.h"

namespace Ui {
class baseinfomanage;
}

class BaseInfoManage : public QWidget
{
    Q_OBJECT

public:
    explicit BaseInfoManage(QWidget *parent = 0);   //构造函数
    ~BaseInfoManage();                              //析构函数

    MaterialWidget &getMaterialWidget() ;           //获取原料窗口对象
    WareHouseWidget &getWareHouseWidget() ;         //获取仓库窗口对象
    SupplierWidget &getSupplierWidget() ;           //获取供应商窗口对象
    TemplateWidget &getTemplateWidget() ;           //获取模板窗口对象
    MaterialRatioWidget &getMaterialRatioWidget() ; //获取材料配比窗口对象

private slots:
    void on_treeWidget_clicked(const QModelIndex &index); //单击控件

private:
    Ui::baseinfomanage *ui;

    QTranslator translater;
    MaterialWidget materialWidget;               //原料窗口对象
    WareHouseWidget wareHouseWidget;             //仓库窗口对象
    SupplierWidget supplierWidget;               //供应商窗口对象
    TemplateWidget templateWidget;               //模板窗口对象
    MaterialRatioWidget materialRatioWidget;     //材料配比窗口对象

    void initControl();                          //初始化控件
    void resizeEvent(QResizeEvent *event);       //改变事件
    int currentRow;                              //当前行
    QList<QWidget*>listTab;                      //功能列表
};

#endif // BASEINFOMANAGE_H
