#ifndef WAREHOUSEWIDGET_H
#define WAREHOUSEWIDGET_H

#include <QWidget>
#include "titlebar/titlebar.h"
#include "baseinfomanage/warehousesetup/addcommodity/addcommodity.h"
#include <QTableWidget>

/***************************************************************
   功能:仓库设置

   创建人:YYC

   创建时间:2017-12-19
**************************************************************/


namespace Ui {
class WareHouseWidget;
}

class WareHouseWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WareHouseWidget(QWidget *parent = 0);    //构造函数
    ~WareHouseWidget();                               //析构函数

    void showWidget();                                //显示窗口
    void readJson(QNetworkReply *reply, int type);    //解析JSON
    void setTableWarHosData();                        //向表格中添加数据
    void setListFoodData();                           //向列表中添加数据
private slots:
    void on_tableWidgetWareHouse_clicked(const QModelIndex &index); //双击仓库列表
    void on_pushButtonAddSpTypeInfo_clicked();         //添加商品分类
    void on_pushButtonAddSpInfo_clicked();             //添加商品
    void on_pushButtonAddSpType_clicked();             //添加商品分类
    void on_pushButtonAddSp_clicked();                 //添加商品
    void slotReceiveType();                            //表格添加
    void slotReceiveAdd();                             //树形添加
    void on_pushButtonAddWareHouse_clicked();          //添加仓库
    void on_pushButtonSave_clicked();                  //保存数据
    void on_pushButtonSaveInfo_clicked();              //更新数据
    void on_pushButtonDelWareHouse_clicked();          //删除仓库
    void on_pushButtonCancel_clicked();
    void on_pushButtonCancelInfo_clicked();

private:
    Ui::WareHouseWidget *ui;
    TitleBar * titleBar;                               //标题栏
    AddCommodity *addCommodity;                        //添加商品
    QString wareHouseId;                               //仓库ID
    void initControl();                                //初始化控件
    QString makeJson(Map mapData);                     //组合JSON
    QMap<QString, QString>selectTableMap;              //表格选中项
    QMap<QString, QString>selectTreeMap;               //树形选中项
    MapList mapWarHosList;                             //仓库列表
    MapList mapFoodCategoryList;                       //商品分类列表
    MapList mapFoodList;                               //商品列表
};

#endif // WAREHOUSEWIDGET_H
