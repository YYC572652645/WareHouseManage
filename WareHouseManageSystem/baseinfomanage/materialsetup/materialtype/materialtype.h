#ifndef MATERIALTYPE_H
#define MATERIALTYPE_H

#include <QWidget>
#include "titlebar/titlebar.h"

/***************************************************************
   功能:原料分类

   创建人:YYC

   创建时间:2017-12-06
**************************************************************/

namespace Ui {
class MaterialType;
}

class MaterialType : public QWidget
{
    Q_OBJECT

public:
    explicit MaterialType(QWidget *parent = 0); //构造函数
    ~MaterialType();                            //析构函数

    void setMapList(MapList &mapList);          //设置数据列表
    void showWidget();                          //显示窗口
    void setData(MapList &mapList);             //设置数据列表
    void setCategoryId(const QString &value);   //设置分类ID

private slots:
    void on_checkBoxIsHaveParent_clicked();     //是否有上级
    void on_pushButtonSave_clicked();           //保存按钮
    void on_pushButtonCancel_clicked();         //取消按钮
    void on_pushButtonDelete_clicked();         //删除按钮

private:
    Ui::MaterialType *ui;
    QString categoryId;                         //分类ID
    TitleBar * titleBar;                        //标题栏
    void initControl();                         //初始化控件
    void resizeEvent(QResizeEvent *event);      //界面大小改变事件
    MapList mapDataList;                        //数据列表
};

#endif // MATERIALTYPE_H
