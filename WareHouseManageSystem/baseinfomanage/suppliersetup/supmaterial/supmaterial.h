#ifndef SUPMATERIAL_H
#define SUPMATERIAL_H

/***************************************************************
   功能:原料信息

   创建人:YYC

   创建时间:2017-12-21
**************************************************************/

#include <QWidget>
#include "titlebar/titlebar.h"

namespace Ui {
class SupMaterial;
}

class SupMaterial : public QWidget
{
    Q_OBJECT

public:
    explicit SupMaterial(QWidget *parent = 0);
    ~SupMaterial();
    void showWidget();                                //显示窗口

    void setClear(bool falge);                        //清空数据
    void setTableMatData();                           //设置当前选择原料表格数据
    void setAllTableMatData();                        //设置可供选择原料表格数据
    void setMaterialMapList(const MapList &value);    //设置原料列表
    void setCatMapList(const MapList &value);         //设置原料分类列表
    void setAllMaterialMapList(const MapList &value); //设置所有原料列表
    void setSupplierId(const QString &value);         //设置供应商ID
    QString getSupplierId() const;                    //获取原料ID

signals:
    void sendCount(int);                              //原料数量信号

private slots:
    void on_pushButtonSave_clicked();                 //保存事件
    void on_pushButtonCancel_clicked();               //取消事件
    void on_pushButtonAdd_clicked();                  //添加事件
    void on_tableWidgetAllMaterial_clicked(const QModelIndex &index); //单击选择
    void on_pushButtonDel_clicked();                  //删除事件

private:
    Ui::SupMaterial *ui;
    TitleBar * titleBar;                              //标题栏
    void initControl();                               //初始化控件
    void resizeEvent(QResizeEvent *event);            //重置窗口大小
    QString supplierId;                               //供应商ID

    QList<Map>materialMapList;                        //原料列表
    QList<Map>catMapList;                             //原料分类列表
    QList<Map>allMaterialMapList;                     //原料列表
    QString makeJson(List listData);                  //组合JSON
};

#endif // SUPMATERIAL_H
