#ifndef PURCHASEORDER_H
#define PURCHASEORDER_H

/***************************************************************
   功能:采购订单

   创建人:YYC

   创建时间:2017-11-22
**************************************************************/

#include <QWidget>
#include "purchasemanage/purchaseorder/addpurmaterial/addpurmaterial.h"
#include "purchasemanage/purchaseorder/materialpurinfo/materialpurinfo.h"
#include "purchasemanage/purchaseorder/confirmmat/confirmmat.h"
#include "purchasemanage/purchaseorder/importhistory/importhistory.h"
#include "purchasemanage/purchaseorder/templatepur/templatepur.h"
#include "purchasemanage/loginfo/loginfo.h"
#include "purchasemanage/purchaseorder/extendpuremail/extendpuremail.h"

namespace Ui {
class PurchaseOrder;
}

class PurchaseOrder : public QWidget
{
    Q_OBJECT

public:
    enum SHOWTYPE{SHOWSUCCESS, NOTSHOW};              //显示提示和不显示
    explicit PurchaseOrder(QWidget *parent = 0);      //构造函数
    ~PurchaseOrder();                                 //析构函数
    void showWidget();                                //显示窗口
    void readJson(QNetworkReply *reply, int type);    //解析JSON

private slots:
    void on_pushButtonAdd_clicked();                           //添加采购订单
    void on_tableWidgetPur_clicked(const QModelIndex &index);  //采购订单详情
    void on_pushButtonSave_clicked();                          //保存采购订单
    void on_pushButtonCancel_clicked();                        //取消添加
    void on_pushButtonAddPurMat_clicked();                     //添加采购原料
    void on_commandLinkButtonEdit_clicked();                   //编辑采购原料
    void on_pushButtonPurMatInfo_clicked();                    //添加采购原料
    void on_pushButtonDeleteInfo_clicked();                    //删除数据
    void on_pushButtonSaveInfo_clicked();                      //更新数据
    void on_tableWidgetPurInfo_doubleClicked(const QModelIndex &index);
    void on_pushButtonCancelInfo_clicked();                    //取消事件
    void on_pushButtonStartSureInfo_clicked();                 //确认采购原料
    void on_pushButtonLookInfo_clicked();                      //查看整体入库单
    void on_commandLinkButtonImport_clicked();                 //从历史订单中导入
    void on_pushButtonTemplate_clicked();                      //模板采购
    void on_commandLinkButtonLog_clicked();                    //处理记录
    void on_pushButtonSelect_clicked();                        //查询数据
    void on_pushButtonExtend_clicked();                        //导出邮箱

private:
    Ui::PurchaseOrder *ui;
    AddPurMaterial * addPurMaterial;         //添加采购原料
    AddPurMaterial * editPurMaterial;        //编辑采购原料
    MaterialPurInfo*materialPurInfo;         //原料信息
    ConfirmMat *confirmMat;                  //确认采购原料
    ImportHistory *importHistory;            //导入历史订单
    ExtendPurEmail *extendPurEmail;          //导出到邮箱
    TemplatePur *templatePur;                //模板设置
    LogInfo *logInfo;                        //操作记录
    QString puchaseNumber;                   //采购单号
    QString purchaseState;                   //采购标志
    int showType;                            //显示类型
    bool importFlage;                        //导入类型
    bool saveFlage;                          //保存类型
    bool selectFlage;                        //选择类型
    void initControl();                      //初始化控件
    void setPurTableData();                  //设置表格数据
    void clearInfo();                        //清空信息
    void setControlData();                   //设置控件数据
    void setAddControlData();                //设置控件数据

    MapList purMapList;                      //采购订单列表
    MapList purMatMapList;                   //采购原料列表
    MapList supMapList;                      //供应商列表
    MapList wareHpuseMapList;                //仓库列表
    MapList staSelectMapList;                //查询状态列表
    MapList supSelectMapList;                //查询供应商列表
    Map mapPurchaseInfo;                     //采购订单详情
};

#endif // PURCHASEORDER_H
