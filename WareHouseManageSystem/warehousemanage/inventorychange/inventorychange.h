#ifndef INVENTORYCHANGE_H
#define INVENTORYCHANGE_H

/***************************************************************
   功能:库存变更记录

   创建人:YYC

   创建时间:2017-1-02
**************************************************************/

#include <QWidget>
#include "global/globaldef.h"
#include "inventorylog/inventorylog.h"
#include "exportemail/exportemail.h"

namespace Ui {
class InventoryChange;
}

class InventoryChange : public QWidget
{
    Q_OBJECT

public:
    explicit InventoryChange(QWidget *parent = 0);     //构造函数
    ~InventoryChange();                                //析构函数
    void showWidget();                                 //显示窗口
    void readJson(QNetworkReply *reply, int type);     //解析JSON

private slots:
    void on_comboBoxTime_currentIndexChanged(const QString &arg1);   //下拉框数据改变
    void on_pushButtonSelect_clicked();                              //查询
    void on_pushButtonExport_clicked();                              //导出
    void on_tableWidgetData_doubleClicked(const QModelIndex &index); //双击控件
    void receiveEmail(QString emailText);                            //接收邮箱

private:
    Ui::InventoryChange *ui;
    void initControl();       //初始化控件
    void setTableData();      //设置表格数据
    void setControlData();    //设置控件数据

    InventoryLog *inventoryLog;
    ExportEmail *exportEmail;
    MapList matMapList;
    MapList wareHouseMapList;
    MapList timeMapList;

    Map mapChangeData;
};

#endif // INVENTORYCHANGE_H
