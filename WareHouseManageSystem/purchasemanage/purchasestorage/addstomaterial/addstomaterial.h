#ifndef ADDSTOMATRIAL_H
#define ADDSTOMATRIAL_H

/***************************************************************
   功能:添加入库原料

   创建人:殷宇辰

   创建时间:2017-12-20
**************************************************************/

#include <QWidget>
#include "titlebar/titlebar.h"

namespace Ui {
class addstomaterial;
}

class AddStoMaterial : public QWidget
{
    Q_OBJECT

public:
    enum WIDGETTYPE{EDITTYPE, ADDTYPE};           //编辑类型，添加类型
    explicit AddStoMaterial(QWidget *parent = 0); //构造函数
    ~AddStoMaterial();                            //析构函数

    void clearInfo();                             //清空信息
    void showWidget(int type);                    //显示窗口
    void setMapMatList(const MapList &value);     //设置数据列表
    MapList getMapMatList() const;                //获取原料数据
    MapList getMapSelectList() const;             //获取选择的列表
    void setTableEidiData();                      //设置表格数据
    void setMapSelectList(const MapList &value);  //设置数据
    Map getMapData() const;                       //设置数据
    void setMapData(const Map &value);            //获取数据
    void setStorageState(const QString &value);   //设置状态

private slots:
    void on_pushButtonSave_clicked();             //保存事件
    void on_pushButtonCancel_clicked();           //取消事件
    void on_tableWidgetData_clicked(const QModelIndex &index); //单击选中
    void on_pushButtonDel_clicked();              //删除数据
    void on_checkBoxAllSelect_clicked();          //选择

private:
    Ui::addstomaterial *ui;
    TitleBar * titleBar;                        //标题栏
    int widgetType;                             //窗口类型

    QString storageState;                       //状态
    void initControl();                         //初始化控件
    void resizeEvent(QResizeEvent *event);      //重置窗口大小
    MapList mapMatList;                         //原料数据
    MapList mapSelectList;                      //选中的数据
    Map mapData;                                //数据
};

#endif // ADDPURMATRIAL_H
