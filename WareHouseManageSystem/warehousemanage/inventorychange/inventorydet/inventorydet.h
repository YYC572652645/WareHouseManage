#ifndef INVENTORYDET_H
#define INVENTORYDET_H

/***************************************************************
   功能:原料详情

   创建人:YYC

   创建时间:2017-1-02
**************************************************************/

#include <QWidget>
#include "titlebar/titlebar.h"

namespace Ui {
class InventoryDet;
}

class InventoryDet : public QWidget
{
    Q_OBJECT

public:
    explicit InventoryDet(QWidget *parent = 0);  //构造函数
    ~InventoryDet();                             //析构函数
    void setControlData();                       //设置控件数据
    void setMapData(const Map &value);           //设置数据

private:
    Ui::InventoryDet *ui;

    TitleBar * titleBar;                         //标题栏
    void initControl();                          //初始化控件
    void resizeEvent(QResizeEvent *event);       //重置窗口大小

    Map mapData;
};

#endif // INVENTORYDET_H
