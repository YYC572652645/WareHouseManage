#ifndef ADDCOMMODITY_H
#define ADDCOMMODITY_H

#include <QWidget>
#include "titlebar/titlebar.h"
#include <QTreeWidgetItem>


/***************************************************************
   功能:添加商品

   创建人:YYC

   创建时间:2017-12-19
**************************************************************/

namespace Ui {
class AddCommodity;
}

class AddCommodity : public QWidget
{
    Q_OBJECT

public:
    enum WIDGETTYPE{ADDCOMMODITY, ADDCOMMODITYTYPE};
    explicit AddCommodity(QWidget *parent = 0);  //构造函数
    ~AddCommodity();                             //析构函数
    void showWidget(int type);                   //显示窗口
    void clearInfo();                            //清空信息

    //获取数据
    MapList getMapFoodList() const;
    MapList getMapFoodCategoryList() const;
    Map getTableItemSelectMap() const;
    Map getTreeItemSelectMap() const;
    Map getTreeItemNotSelectMap() const;

    //设置数据
    void setMapFoodCategoryList(const MapList &value);
    void setMapFoodList(const MapList &value);
    void setTreeItemSelectMap(const Map &value);
    void setFoodList(const MapList &value);
    void setTableItemSelectMap(const Map &value);


private slots:
    void on_pushButtonSave_clicked();                         //保存按钮
    void on_pushButtonCancel_clicked();                       //取消
    void on_pushButtonSearch_clicked();                       //搜索商品
    void on_tableWidgetData_clicked(const QModelIndex &index);//单击表格控件
    void on_treeWidgetData_clicked(const QModelIndex &index); //单击树形控件
    void on_checkBoxSelect_clicked();                         //选中

signals:
    void sendAdd();                                           //树形添加信号
    void sendType();                                          //表格添加信号

private:
    Ui::AddCommodity *ui;
    TitleBar * titleBar;                                      //标题栏
    bool serachFlage;                                         //查询标志位
    int widgetType;                                           //窗口类型
    MapList foodList;                                         //商品列表
    void initControl();                                       //初始化控件
    void resizeEvent(QResizeEvent *event);                    //界面大小改变事件
    QString findIdByItem(QTreeWidgetItem * item);             //通过Item找ID

    MapList mapFoodCategoryList;                              //商品分类列表
    MapList mapFoodList;                                      //商品列表
    QMap<QTreeWidgetItem*,QString> mapItemList;               //ID和item的map映射
    QMap<QString, QString>tableItemSelectMap;                 //表格选中映射
    QMap<QString, QString>treeItemSelectMap;                  //树形选中映射
    QMap<QString, QString>treeItemNotSelectMap;               //树形未选中映射
};

#endif // ADDCOMMODITY_H
