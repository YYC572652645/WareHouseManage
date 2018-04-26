#ifndef SELECTMATERIAL_H
#define SELECTMATERIAL_H

/***************************************************************
   功能:商品原料设置

   创建人:YYC

   创建时间:2017-11-20
**************************************************************/

#include <QWidget>
#include "titlebar/titlebar.h"
#include "baseinfomanage/materialratiosetup/materialinfo/materialinfo.h"

namespace Ui {
class SelectMaterial;
}

class SelectMaterial : public QWidget
{
    Q_OBJECT

public:
    explicit SelectMaterial(QWidget *parent = 0);  //构造函数
    ~SelectMaterial();                             //析构函数
    void showWidget();                             //显示窗口
    void setMapListMaterial(const MapList &value); //设置数据
    void setTableData();                           //设置表格数据
    void setMapFood(const Map &value);             //设置菜品列表
    MaterialInfo *getMaterialInfo();               //原料信息对象

private slots:
    void on_tableWidget_doubleClicked(const QModelIndex &index); //双击列表

private:
    Ui::SelectMaterial *ui;
    TitleBar * titleBar;                          //标题栏
    void initControl();                           //初始化控件
    void resizeEvent(QResizeEvent *event);        //重置窗口大小

    MaterialInfo *materialInfo;                   //原料信息
    MapList mapListMaterial;                      //原料列表
    QMap<QString, QString>mapFood;                //菜品信息
};

#endif // SELECTMATERIAL_H
