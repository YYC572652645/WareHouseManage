#ifndef REALTIMEINVENTORY_H
#define REALTIMEINVENTORY_H

/***************************************************************
   功能:实时库存

   创建人:YYC

   创建时间:2017-1-02
**************************************************************/

#include <QWidget>
#include "global/globaldef.h"
#include "warehousemanage/timematinfo/timematinfo.h"
#include "exportemail/exportemail.h"

namespace Ui {
class RealTimeInventory;
}

class RealTimeInventory : public QWidget
{
    Q_OBJECT

public:
    explicit RealTimeInventory(QWidget *parent = 0);        //构造函数
    ~RealTimeInventory();                                   //析构函数
    void showWidget();                                      //显示窗口
    void readJson(QNetworkReply *reply, int type);          //读取JSON
private slots:
    void on_tableWidgetData_doubleClicked(const QModelIndex &index); //双击事件
    void on_pushButtonExport_clicked();                     //导出到邮箱
    void receiveEmail(QString emailText);                   //接收邮箱地址
private:
    Ui::RealTimeInventory *ui;

    TimeMatInfo *timeMatInfo;
    ExportEmail *exportEmail;

    void initControl();                      //初始化控件
    void setControlData();                   //设置控件数据
    MapList matMapList;
};

#endif // REALTIMEINVENTORY_H
