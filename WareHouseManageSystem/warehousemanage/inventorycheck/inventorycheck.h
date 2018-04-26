#ifndef INVENTORYCHECK_H
#define INVENTORYCHECK_H

/***************************************************************
   功能:仓库盘存

   创建人:YYC

   创建时间:2018-1-10
**************************************************************/

#include <QWidget>
#include "global/globaldef.h"
#include "materialcheckinfo/materialcheckinfo.h"
#include "purchasemanage/loginfo/loginfo.h"
#include "exportemail/exportemail.h"
#include "importcheckhistory/importcheckhistory.h"
#include "extendcheckemail/extendcheckemail.h"

namespace Ui {
class InventoryCheck;
}

class InventoryCheck : public QWidget
{
    Q_OBJECT

public:
    enum SHOWTYPE{SHOW, NOTSHOW};
    explicit InventoryCheck(QWidget *parent = 0);    //构造函数
    ~InventoryCheck();                               //析构函数

    void showWidget();                               //显示窗口
    void readJson(QNetworkReply *reply, int type);   //解析JSON

private slots:
    void on_tableWidgetCheck_clicked(const QModelIndex &index); //点击控件
    void on_pushButtonAdd_clicked();                            //添加盘存单
    void on_pushButtonDeleteInfo_clicked();                     //删除信息
    void on_pushButtonSaveInfo_clicked();                       //更新信息
    void on_pushButtonCancelInfo_clicked();                     //取消按钮
    void on_pushButtonSave_clicked();                           //添加盘存单
    void on_commandLinkButtonMatList_clicked();                 //选择原料
    void on_commandLinkButtonMatListInfo_clicked();             //选择原料
    void on_commandLinkButtonLog_clicked();                     //处理记录
    void on_pushButtonExtend_clicked();                         //导出EMAIL
    void on_pushButtonCheckFinishInfo_clicked();                //盘存完成
    void on_pushButtonCancelCheckInfo_clicked();                //取消盘存
    void on_pushButtonCancel_clicked();                         //取消按钮
    void on_commandLinkButtonImport_clicked();                  //导入历史盘存单
    void on_pushButtonSelect_clicked();                         //查询盘存单

private:
    Ui::InventoryCheck *ui;

    void initControl();                      //初始化控件
    void setTableData();                     //设置表格数据
    void setControlData();                   //设置控件数据
    void setAddControlData();                //设置添加控件数据

    int showType;
    bool importFlage;
    bool saveFlage;
    bool selectFlage;
    MapList mapCheckList;
    MapList mapWareHouseList;
    MapList warHseSelectMapList;
    MapList staSelectMapList;
    Map mapCheckData;
    QString wareHouseCheckId;

    MaterialCheckInfo *materialCheckInfo;
    ImportCheckHistory*importCheckHistory;
    LogInfo *logInfo;
    ExtendCheckEmail *extendCheckEmail;
};

#endif // INVENTORYCHECK_H
