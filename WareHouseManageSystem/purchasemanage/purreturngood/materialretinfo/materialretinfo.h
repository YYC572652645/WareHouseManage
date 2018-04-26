#ifndef MATERIALRETINFO_H
#define MATERIALRETINFO_H

/***************************************************************
   功能:退货原料信息

   创建人:YYC

   创建时间:2017-11-02
**************************************************************/

#include <QWidget>
#include <QDoubleSpinBox>
#include "titlebar/titlebar.h"
#include "purchasemanage/purreturngood/subretposition/subretposition.h"

namespace Ui {
class materialretinfo;
}

typedef QList<QWidget*> ListWidget;

class MaterialRetInfo : public QWidget
{
    Q_OBJECT

public:
    explicit MaterialRetInfo(QWidget *parent = 0);  //构造函数
    ~MaterialRetInfo();                             //析构函数
    void showWidget();                              //显示窗口
    void setControlData();                          //设置控件数据

    void setHide();                                 //设置隐藏
    void setShow();                                 //设置显示
    void canSubOpstion();                           //可以分仓
    void setUnitMapList(const MapList &value);      //设置单位列表
    void setMatMap(const Map &value);               //设置原料
    void setControlEnable(bool flage);              //设置控件是否可用
    void setAssistantMapList(const MapList &value); //设置分仓库
    SubRetPosition *getSubPosition() const;         //获取添加仓库对象

private slots:
    void delWareHouse();                            //删除仓库
    void valueChange(double value);                 //数值改变
    void on_pushButtonSave_clicked();               //保存数据
    void on_pushButtonCancel_clicked();             //取消事件
    void on_comboBoxUnit_activated(const QString &arg1); //单位点击
    void on_spinBoxNumber_valueChanged(double arg1);     //数量改变
    void on_pushButtonDel_clicked();                     //删除原料
    void on_pushButtonAddNew_clicked();                  //添加分仓
    void on_spinBoxPrice_valueChanged(double arg1);      //单价改变

private:
    Ui::materialretinfo *ui;
    SubRetPosition*subPosition;              //添加分仓
    TitleBar * titleBar;                     //标题栏
    QWidget *mainWidget;                     //主界面
    QVBoxLayout *mainLayout;                 //主布局
    void initControl();                      //初始化控件

    ListWidget createControl(int index);     //创建控件
    void resizeEvent(QResizeEvent *event);   //重置窗口大小
    MapList unitMapList;                     //单元信息
    MapList assistantMapList;                //分仓仓库
    Map matMap;                              //原料信息
    MapList updateAssMapList;                //更新的分仓仓库
    double usefulNumber;                     //可用数量
    bool hideFlage;
    QList<QLabel*> labelMainList;
    QList<QLabel*> labelSideList;
    QList<QPushButton*> delButtonList;
    QList<QDoubleSpinBox*> mainSpinList;
    QList<QDoubleSpinBox*> sideSpinList;
    QList<QLineEdit*> sideLineEditList;
    QList<QLineEdit*> mainLineEditList;
    QList<ListWidget> widgetList;
};

#endif // MaterialRetInfo_H
