#ifndef COSTPRICE_H
#define COSTPRICE_H

/***************************************************************
   功能:成本价一览

   创建人:YYC

   创建时间:2017-1-02
**************************************************************/

#include <QWidget>
#include "titlebar/titlebar.h"

namespace Ui {
class CostPrice;
}

class CostPrice : public QWidget
{
    Q_OBJECT

public:
    explicit CostPrice(QWidget *parent = 0);   //构造函数
    ~CostPrice();                              //析构函数
    void showWidget();                         //显示窗口
    void setMapCostList(const MapList &value); //设置数据

private:
    Ui::CostPrice *ui;

    TitleBar * titleBar;                     //标题栏
    void initControl();                      //初始化控件
    void resizeEvent(QResizeEvent *event);   //重置窗口大小

    MapList mapCostList;
};

#endif // COSTPRICE_H
