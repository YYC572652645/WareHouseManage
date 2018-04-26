#ifndef ADDPURMATRIAL_H
#define ADDPURMATRIAL_H

/***************************************************************
   功能:添加原料

   创建人:YYC

   创建时间:2017-11-22
**************************************************************/

#include <QWidget>
#include "titlebar/titlebar.h"

namespace Ui {
class AddPurMaterial;
}

class AddPurMaterial : public QWidget
{
    Q_OBJECT

public:
    enum WIDGETTYPE{EDITTYPE, ADDTYPE};           //添加类型，编辑类型
    explicit AddPurMaterial(QWidget *parent = 0); //构造函数
    ~AddPurMaterial();                            //析构函数
    void showWidget(int type);                    //显示窗口
    void setMapMatList(const MapList &value);     //设置数据列表
    MapList getMapMatList() const;                //获取原料数据
    MapList getMapSelectList() const;             //获取选择的列表
    void setTableEidiData();                      //设置表格数据
    void setMapSelectList(const MapList &value);  //设置数据列表
    void setPurchaseNumber(const QString &value); //设置采购订单号
    void setSupplierId(const QString &value);     //设置供应商ID
    QString getPurchaseNumber() const;            //获取采购订单号
    QString getSupplierId() const;                //获取供应商ID
    QString makeJson(List data);                  //组合JSON

private slots:
    void on_pushButtonSave_clicked();             //保存事件
    void on_pushButtonCancel_clicked();           //取消事件
    void on_tableWidgetData_clicked(const QModelIndex &index);
    void on_pushButtonDel_clicked();              //删除数据
    void on_checkBoxAllSelect_clicked();          //选择

private:
    Ui::AddPurMaterial *ui;
    TitleBar * titleBar;                        //标题栏
    int widgetType;                             //窗口类型
    QString purchaseNumber;                     //采购订单号
    QString supplierId;                         //供应商ID
    void initControl();                         //初始化控件
    void resizeEvent(QResizeEvent *event);      //重置窗口大小
    MapList mapMatList;                         //原料数据
    MapList mapSelectList;                      //选中的数据
};

#endif // ADDPURMATRIAL_H
