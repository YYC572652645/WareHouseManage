#ifndef MATERIALSUPPLIER_H
#define MATERIALSUPPLIER_H

/***************************************************************
   功能:原料供应商

   创建人:YYC

   创建时间:2017-11-22
**************************************************************/

#include <QWidget>
#include "global/globaldef.h"
#include "materialsupplier/defaultmatinfo/defaultmatinfo.h"
#include "materialsupplier/setdefaultsup/setdefaultsup.h"

namespace Ui {
class MaterialSupplier;
}

class MaterialSupplier : public QWidget
{
    Q_OBJECT

public:
    explicit MaterialSupplier(QWidget *parent = 0);  //构造函数
    ~MaterialSupplier();                             //析构函数
    void showWidget();                               //显示窗口
    void readJson(QNetworkReply *reply, int type);   //解析JSON

private slots:
    void on_tableWidget_doubleClicked(const QModelIndex &index); //双击控件
    void on_pushButtonAllSelect_clicked();                       //全选
    void on_pushButtonNoSelect_clicked();                        //全不选
    void on_pushButtonSetUp_clicked();                           //批量设置

private:
    Ui::MaterialSupplier *ui;

    void initControl();               //初始化控件
    void setControlData();            //设置控件数据

    MapList mapListMat;               //原料列表
    DefaultMatInfo *defaultMatInfo;   //默认原料信息
    SetDefaultSup *setDefaultSup;     //设置默认供应商
};

#endif // MATERIALSUPPLIER_H
