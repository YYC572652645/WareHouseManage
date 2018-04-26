#ifndef ADDADJMATRIAL_H
#define ADDADJMATRIAL_H

/***************************************************************
   功能:添加原料

   创建人:YYC

   创建时间:2017-1-02
**************************************************************/

#include <QWidget>
#include "titlebar/titlebar.h"

namespace Ui {
class addadjmaterial;
}

class AddAdjMaterial : public QWidget
{
    Q_OBJECT

public:
    enum WIDGETTYPE{EDITTYPE, ADDTYPE};
    explicit AddAdjMaterial(QWidget *parent = 0);   //构造函数
    ~AddAdjMaterial();                              //析构函数
    void showWidget(int type);                      //显示窗口
    void setMapMatList(const MapList &value);       //设置数据列表
    MapList getMapMatList() const;                  //获取原料数据
    MapList getMapSelectList() const;               //获取选择的列表
    void setTableEidiData();                        //设置表格数据
    void setMapSelectList(const MapList &value);    //设置数据

    Map getMapData() const;                         //设置数据
    void setMapData(const Map &value);              //获取数据

    void setOddNumber(const QString &value);        //设置调整单号
    void setWareHouseId(const QString &value);      //设置仓库ID

private slots:
    void on_pushButtonSave_clicked();               //保存事件
    void on_pushButtonCancel_clicked();             //取消事件
    void on_tableWidgetData_clicked(const QModelIndex &index); //单击选中
    void on_pushButtonDel_clicked();                //删除数据
    void on_checkBoxAllSelect_clicked();            //选择

private:
    Ui::addadjmaterial *ui;
    TitleBar * titleBar;                        //标题栏
    int widgetType;                             //窗口类型

    QString oddNumber;                          //调整单号
    void initControl();                         //初始化控件
    void resizeEvent(QResizeEvent *event);      //重置窗口大小
    MapList mapMatList;                         //原料数据
    MapList mapSelectList;                      //选中的数据
    Map mapData;                                //数据
    QString wareHouseId;                        //仓库ID
};

#endif // ADDADJMATRIAL_H
