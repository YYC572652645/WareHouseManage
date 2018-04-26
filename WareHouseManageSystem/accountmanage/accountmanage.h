#ifndef ACCOUNTMANAGE_H
#define ACCOUNTMANAGE_H

/***************************************************************
   功能:支出结算

   创建人:YYC

   创建时间:2018-2-28
**************************************************************/

#include <QWidget>
#include "global/globaldef.h"

class MaterialStoInfo;
class MaterialRetInfo;
class AccountExport;
class LogInfo;


namespace Ui {
class AccountManage;
}

class AccountManage : public QWidget
{
    Q_OBJECT

public:
    explicit AccountManage(QWidget *parent = 0);   //构造函数
    ~AccountManage();                              //析构函数
    void readJson(QNetworkReply *reply, int type); //读取数据
    void showWidget();                             //显示窗口

private slots:
    void on_tableWidgetAccount_clicked(const QModelIndex &index);    //单击控件
    void on_commandLinkButtonSure_clicked();                         //确定按钮
    void on_commandLinkButtonLog_clicked();                          //操作记录
    void on_tableWidgetInfo_doubleClicked(const QModelIndex &index); //双击列表
    void on_pushButtonSelect_clicked();                              //查询按钮
    void on_comboBoxTimeType_activated(const QString &arg1);         //点击列表框
    void on_pushButtonExport_clicked();                              //导出按钮

private:
    Ui::AccountManage *ui;
    void initControl();                //初始化控件
    void setTableData();               //设置表格数据
    void setControlStoData();          //设置入库数据
    void setControlRetData();          //设置退货数据
    void setFiltrateData();            //设置筛选数据

    MaterialStoInfo *materialStoInfo;  //入库详情
    MaterialRetInfo *materialRetInfo;  //退货详情
    AccountExport *accountExport;      //导出到邮箱
    LogInfo *logInfo;                  //操作记录
    MapList accountMapList;            //支出结算信息
    MapList materialMapList;           //原料信息

    MapList mapListState;
    MapList mapListSupplier;
    MapList mapListType;
    MapList mapListTime;

    Map stoMapData;
    Map retMapData;
    QString number;
    QString state;
    QString realityTime;
};

#endif // ACCOUNTMANAGE_H
