#ifndef INVENTORYTRANSFER_H
#define INVENTORYTRANSFER_H

/***************************************************************
   功能:店内调拨

   创建人:YYC

   创建时间:2018-2-10
**************************************************************/

#include <QWidget>
#include "warehousemanage/inventorytransfer/addtranmaterial/addtranmaterial.h"
#include "warehousemanage/inventorytransfer/materialtrandet/materialtrandet.h"
#include "warehousemanage/inventorytransfer/refusetranwidget/refusetranwidget.h"
#include "extendtranemail/extendtranemail.h"
#include "purchasemanage/loginfo/loginfo.h"

namespace Ui {
class inventorytransfer;
}

class InventoryTransfer : public QWidget
{
    Q_OBJECT

public:
    enum SHOWTYPE{SHOWSUCCESS, NOTSHOW};
    explicit InventoryTransfer(QWidget *parent = 0);     //构造函数
    ~InventoryTransfer();                                //析构函数
    void showWidget();                                   //显示窗口
    void readJson(QNetworkReply *reply, int type);       //解析json

private slots:
    void on_commandLinkButtonEdit_clicked();             //编辑调拨原料
    void on_pushButtonAllotMatInfo_clicked();            //添加调拨原料
    void on_pushButtonSaveInfo_clicked();                //更新数据
    void on_tableWidgetAllotInfo_doubleClicked(const QModelIndex &index); //双击查询原料信息
    void on_pushButtonCancelInfo_clicked();              //取消事件
    void on_pushButtonAdd_clicked();                     //添加调拨单
    void on_pushButtonSave_clicked();                    //保存调拨单
    void on_pushButtonAddAllotMat_clicked();             //添加调拨原料
    void on_pushButtonCancel_clicked();                  //取消按钮
    void on_pushButtonRefuse_clicked();                  //拒绝收货
    void on_pushButtonFinish_clicked();                  //调拨完成
    void on_pushButtonReConfirm_clicked();               //反确认
    void on_pushButtonDel_clicked();                     //删除调拨单
    void on_pushButtonExtend_clicked();                  //导出邮箱
    void on_commandLinkButtonLog_clicked();              //处理记录
    void on_tableWidgetAllot_clicked(const QModelIndex &index); //调拨订单详情
    void on_pushButtonSubmit_clicked();                  //提交调拨单
    void on_pushButtonSelect_clicked();                  //查询调拨单

private:
    Ui::inventorytransfer *ui;
    AddTranMaterial * addTranMaterial;       //添加调拨原料
    AddTranMaterial * editTranMaterial;      //编辑调拨原料
    MaterialTranDet* materialTranDet;        //原料信息
    RefuseTranWidget *refuseTranWidget;      //拒绝原因
    LogInfo *logInfo;                        //处理记录
    ExtendTranEmail *extendEmail;            //导出到邮箱
    QString allotNumber;                     //订单号
    QString allotId;                         //调拨ID
    QString allotState;                      //调拨标志
    QString allotMatId;                      //调拨单ID
    int showType;                            //显示类型
    bool selectFlage;                        //选中类型
    bool saveFlage;                          //保存类型
    void initControl();                      //初始化控件
    void setAllotTableData();                //设置表格数据
    void setControlData();                   //设置控件数据
    void setAddControlData();                //设置添加调拨
    void clearAddInfo();                     //清空添加调拨

    MapList allotMapList;                    //调拨调拨列表
    MapList allotMatMapList;                 //调拨原料列表
    MapList wareHouseMapList;                //仓库列表
    MapList warHseSelectMapList;             //仓库查询列表
    MapList staSelectMapList;                //状态查询列表
    Map mapAllotInfo;                        //调拨订单详情
};

#endif
