#ifndef MATERIALCOSTINFO_H
#define MATERIALCOSTINFO_H

/***************************************************************
   功能:成本调价原料信息

   创建人:YYC

   创建时间:2017-1-02
**************************************************************/

#include <QWidget>
#include "titlebar/titlebar.h"

namespace Ui {
class materialcostinfo;
}

class MaterialCostInfo : public QWidget
{
    Q_OBJECT

public:
    explicit MaterialCostInfo(QWidget *parent = 0);  //构造函数
    ~MaterialCostInfo();                             //析构函数
    void showWidget();                               //显示窗口
    void setControlData();                           //设置控件数据

    void setHide();                                  //设置隐藏
    void setShow();                                  //设置显示
    void setMatMap(const Map &value);                //设置原料

private slots:
    void on_pushButtonSave_clicked();                //保存数据
    void on_pushButtonCancel_clicked();              //取消事件
    void on_pushButtonDel_clicked();                 //删除原料
    void on_spinBoxPriceAfter_valueChanged(double arg1); //数据改变

private:
    Ui::materialcostinfo *ui;
    TitleBar * titleBar;                     //标题栏
    void initControl();                      //初始化控件

    void resizeEvent(QResizeEvent *event);   //重置窗口大小
    Map matMap;                              //原料信息
};

#endif // MaterialRetInfo_H
