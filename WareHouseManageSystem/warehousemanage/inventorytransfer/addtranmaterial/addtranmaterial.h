#ifndef ADDTRANMATRIAL_H
#define ADDTRANMATRIAL_H

/***************************************************************
   功能:添加原料

   创建人:YYC

   创建时间:2018-2-10
**************************************************************/

#include <QWidget>
#include "titlebar/titlebar.h"
#include <QDoubleSpinBox>

namespace Ui {
class addtranmaterial;
}

class AddTranMaterial : public QWidget
{
    Q_OBJECT

public:
    enum WIDGETTYPE{EDITTYPE, ADDTYPE};
    explicit AddTranMaterial(QWidget *parent = 0);  //构造函数
    ~AddTranMaterial();                             //析构函数
    void showWidget(int type);                      //显示窗口
    void setMapMatList(const MapList &value);       //设置数据列表
    MapList getMapMatList() const;                  //获取原料数据
    MapList getMapSelectList() const;               //获取选择的列表
    void setTableEidiData();                        //设置表格数据
    void setMapSelectList(const MapList &value);    //设置数据

private slots:
    void on_pushButtonSave_clicked();               //保存事件
    void on_pushButtonCancel_clicked();             //取消事件
    void on_tableWidgetData_clicked(const QModelIndex &index); //单击选中
    void on_pushButtonDel_clicked();                //删除数据
    void on_checkBoxAllSelect_clicked();            //选择

private:
    Ui::addtranmaterial *ui;
    TitleBar * titleBar;                        //标题栏
    int widgetType;                             //窗口类型

    void initControl();                         //初始化控件
    void resizeEvent(QResizeEvent *event);      //重置窗口大小
    MapList mapMatList;                         //原料数据
    MapList mapSelectList;                      //选中的数据
    QList<QDoubleSpinBox*>spinBoxList;          //调价后

    List delListData;
};

#endif // ADDPURMATRIAL_H
