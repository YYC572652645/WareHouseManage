#ifndef MATERIALCHECKINFO_H
#define MATERIALCHECKINFO_H

/***************************************************************
   功能:原料信息

   创建人:YYC

   创建时间:2018-1-10
**************************************************************/

#include <QWidget>
#include "titlebar/titlebar.h"
#include <QDoubleSpinBox>
#include "warehousemanage/inventorycheck/addcheckmat/addcheckmat.h"
#include "warehousemanage/inventorycheck/materialchectdet/materialcheckdet.h"

namespace Ui {
class MaterialCheckInfo;
}

class MaterialCheckInfo : public QWidget
{
    Q_OBJECT

public:
    explicit MaterialCheckInfo(QWidget *parent = 0);  //构造函数
    ~MaterialCheckInfo();                             //析构函数
    void showWidget();                                //显示窗口

    void setMapMatList(const MapList &value);         //设置原料列表

    AddCheckMat *getAddCheckMat();                    //获取添加原料对象
    void setWareHouseId(const QString &value);        //设置仓库ID
    void setCheckNumber(const QString &value);        //设置单号

    void setHide();                                   //设置隐藏
    void setShow();                                   //设置显示
    MaterialCheckDet *getMaterialCheckDet();          //获取原料详情对象

private slots:
    void on_tableWidgetData_doubleClicked(const QModelIndex &index); //双击控件
    void on_pushButtonAdd_clicked();                                 //添加原料
    void on_pushButtonSave_clicked();                                //保存按钮
    void on_pushButtonCancel_clicked();                              //取消按钮

private:
    Ui::MaterialCheckInfo *ui;

    TitleBar * titleBar;                     //标题栏
    AddCheckMat * addCheckMat;               //添加原料
    MaterialCheckDet *materialCheckDet;      //原料详情
    void initControl();                      //初始化控件
    void resizeEvent(QResizeEvent *event);   //重置窗口大小

    MapList mapMatList;
    QString wareHouseId;
    QString checkNumber;
    bool showFalge;
    QList<QDoubleSpinBox*>spinBoxList;
};

#endif // MATERIALCHECKINFO_H
