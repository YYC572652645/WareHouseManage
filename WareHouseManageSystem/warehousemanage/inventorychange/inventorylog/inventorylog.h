#ifndef INVENTORYLOG_H
#define INVENTORYLOG_H

/***************************************************************
   功能:操作记录

   创建人:YYC

   创建时间:2017-1-02
**************************************************************/

#include <QWidget>
#include "titlebar/titlebar.h"
#include "warehousemanage/inventorychange/inventorydet/inventorydet.h"

namespace Ui {
class InventoryLog;
}

class InventoryLog : public QWidget
{
    Q_OBJECT

public:
    explicit InventoryLog(QWidget *parent = 0); //构造函数
    ~InventoryLog();                            //析构函数

    void showWidget();                          //显示窗口
    void setOrderMapList(const MapList &value); //设置库存单数据
    void setMapData(const Map &value);          //设置原料数据
    void setListData(const List &value);        //设置时间
    void setControlData();                      //设置控件数据
    InventoryDet *getInventoryDet();            //获取详情

private slots:
    void on_tableWidget_doubleClicked(const QModelIndex &index); //双击控件

private:
    Ui::InventoryLog *ui;

    TitleBar * titleBar;                     //标题栏
    InventoryDet *inventoryDet;              //详情
    void initControl();                      //初始化控件
    void resizeEvent(QResizeEvent *event);   //重置窗口大小

    MapList orderMapList;
    Map mapData;
    List listData;
};

#endif // INVENTORYLOG_H
