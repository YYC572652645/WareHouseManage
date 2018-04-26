#ifndef PURCHASESAFE_H
#define PURCHASESAFE_H

/***************************************************************
   功能:安全库存采购

   创建人:殷宇辰

   创建时间:2017-6-20
**************************************************************/

#include <QWidget>
#include "global/globaldef.h"
#include "confirmsafemat/confirmsafemat.h"

namespace Ui {
class PurchaseSafe;
}

class PurchaseSafe : public QWidget
{
    Q_OBJECT

public:
    explicit PurchaseSafe(QWidget *parent = 0);            //构造函数
    ~PurchaseSafe();                                       //析构函数

    void showWidget();                                     //显示窗口
    void readJson(QNetworkReply *reply, int type);         //读取JSON
    void setSelMatMapData();                               //设置原料数据

private slots:
    void on_pushButtonAllSelect_clicked();                 //全选
    void on_pushButtonNoSelect_clicked();                  //全不选
    void on_pushButtonSure_clicked();                      //确认采购
    void on_tableWidget_clicked(const QModelIndex &index); //单击事件

private:
    Ui::PurchaseSafe *ui;

    ConfirmSafeMat *confirmSafeMat;     //确认采购原料
    MapList selMatMapList;              //原料
    void setControlData(int index);     //设置控件数据
};

#endif // PURCHASESAFE_H
