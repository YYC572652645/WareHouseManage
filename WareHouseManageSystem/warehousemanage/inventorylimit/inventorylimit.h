#ifndef InventoryLimit_H
#define InventoryLimit_H

/***************************************************************
   功能:库存上下限信息

   创建人:YYC

   创建时间:2018-2-10
**************************************************************/


#include <QWidget>
#include "global/globaldef.h"
#include "warehousemanage/inventorylimit/limitmatinfo/defaultlimitinfo.h"
#include "warehousemanage/inventorylimit/setdefaultlimit/setdefaultlimit.h"

namespace Ui {
class InventoryLimit;
}

class InventoryLimit : public QWidget
{
    Q_OBJECT

public:
    explicit InventoryLimit(QWidget *parent = 0);  //构造函数
    ~InventoryLimit();                             //析构函数
    void showWidget();                             //显示窗口
    void readJson(QNetworkReply *reply, int type); //解析json

private slots:
    void on_tableWidget_doubleClicked(const QModelIndex &index); //双击控件
    void on_pushButtonAllSelect_clicked();                       //全选
    void on_pushButtonNoSelect_clicked();                        //全不选
    void on_pushButtonSetUp_clicked();                           //批量设置

private:
    Ui::InventoryLimit *ui;

    void initControl();        //初始化控件
    void setControlData();     //设置控件数据

    MapList mapListMat;

    DefaultLimitInfo *defaultLimitInfo;
    SetDefaultLimit *setDefaultLimit;
};

#endif // MATERIALSUPPLIER_H
