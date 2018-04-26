#ifndef MATERIALTRANDET_H
#define MATERIALTRANDET_H

/***************************************************************
   功能:原料信息

   创建人:YYC

   创建时间:2018-2-10
**************************************************************/

#include <QWidget>
#include "titlebar/titlebar.h"

namespace Ui {
class materialtrandet;
}

class MaterialTranDet : public QWidget
{
    Q_OBJECT

public:
    explicit MaterialTranDet(QWidget *parent = 0); //构造函数
    ~MaterialTranDet();                            //析构函数
    void showWidget();                             //显示窗口
    void setControlData();                         //设置控件数据

    void setHide();                                //设置隐藏
    void setShow();                                //设置显示
    void setMapNumber(const Map &mapData);         //设置数据
    void setUnitMapList(const MapList &value);     //设置单位列表
    void setMatMap(const Map &value);              //设置原料
    void setControlEnable(bool flage);             //设置控件是否可用

private slots:
    void on_pushButtonSave_clicked();              //保存数据
    void on_pushButtonCancel_clicked();            //取消事件
    void on_comboBoxUnit_activated(const QString &arg1); //单位点击
    void on_pushButtonDel_clicked();               //删除原料

private:
    Ui::materialtrandet *ui;
    TitleBar * titleBar;                     //标题栏
    void initControl();                      //初始化控件

    void resizeEvent(QResizeEvent *event);   //重置窗口大小
    MapList unitMapList;                     //单元信息
    Map matMap;                              //原料信息
};

#endif // MATERIALCHECKDET_H
