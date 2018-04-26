#ifndef PURCHASESTORAGE_H
#define PURCHASESTORAGE_H

/***************************************************************
   功能:采购入库

   创建人:YYC

   创建时间:2017-11-02
**************************************************************/

#include <QWidget>
#include "purchasemanage/purchasestorage/addstomaterial/addstomaterial.h"
#include "purchasemanage/purchasestorage/materialstoinfo/materialstoinfo.h"
#include "purchasemanage/purchasestorage/importallhistory/importallhistory.h"
#include "purchasemanage/purchasestorage/refusewidget/refusewidget.h"
#include "purchasemanage/purchasestorage/startreceive/startreceive.h"
#include "purchasemanage/loginfo/loginfo.h"
#include "purchasemanage/purchasestorage/extendstorage/extendstorage.h"

namespace Ui {
class purchasestorage;
}

class PurchaseStorage : public QWidget
{
    Q_OBJECT

public:
    enum SHOWTYPE{SHOWSUCCESS, NOTSHOW};
    explicit PurchaseStorage(QWidget *parent = 0); //构造函数
    ~PurchaseStorage();                            //析构函数
    void showWidget();                             //显示窗口
    void readJson(QNetworkReply *reply, int type); //解析JSON

private slots:
    void on_tableWidgetPur_clicked(const QModelIndex &index);           //入库订单详情
    void on_commandLinkButtonEdit_clicked();                            //编辑入库原料
    void on_pushButtonPurMatInfo_clicked();                             //添加入库原料
    void on_pushButtonSaveInfo_clicked();                               //更新数据
    void on_tableWidgetPurInfo_doubleClicked(const QModelIndex &index); //双击查询原料信息
    void on_pushButtonCancelInfo_clicked();                             //取消事件
    void on_pushButtonAdd_clicked();                                    //添加入库单
    void on_pushButtonSave_clicked();                                   //保存入库单
    void on_pushButtonAddPurMat_clicked();                              //添加入库原料
    void on_pushButtonCancel_clicked();                                 //取消按钮
    void on_commandLinkButtonPurHistory_clicked();                      //导入历史采购订单
    void on_commandLinkButtonStoHistory_clicked();                      //导入历史入库订单
    void on_pushButtonRefuse_clicked();                                 //拒绝收货
    void on_pushButtonStart_clicked();                                  //开始验收
    void on_pushButtonReConfirm_clicked();                              //反确认
    void on_pushButtonDel_clicked();                                    //删除入库单
    void on_pushButtonExtend_clicked();                                 //导出邮箱
    void on_pushButtonClose_clicked();                                  //关闭窗口
    void on_commandLinkButtonLog_clicked();                             //处理记录
    void on_pushButtonSelect_clicked();                                 //查询数据
    void on_comboBoxTimeSelect_activated(const QString &arg1);          //点击下拉框
    void on_pushButtonFinish_clicked();                                 //验收完成
    void on_pushButtonStartCarry_clicked();                             //继续验收

signals:
    void signalShow();   //显示信号
    void signalClose();  //关闭信号

private:
    Ui::purchasestorage *ui;
    AddStoMaterial * addStoMaterial;         //添加入库原料
    AddStoMaterial * editStoMaterial;        //编辑入库原料
    MaterialStoInfo* materialStoInfo;        //原料信息
    ImportAllHistory *importAllHistory;      //导入所有历史
    ExtendStorage *extendStorage;            //导出入库单
    RefuseWidget *refuseWidget;              //拒绝原因
    StartReceive *startReceive;              //开始验收
    LogInfo *logInfo;
    QString storageNumber;                   //订单号
    QString storageId;                       //入库ID
    QString storageState;                    //入库标志
    QString stoMatId;                        //入库单ID
    int showType;                            //显示类型
    bool slectFlage;                         //查询标志位
    bool saveFlage;                          //保存类型
    bool selectType;                         //选中类型
    void initControl();                      //初始化控件
    void setPurTableData();                  //设置表格数据
    void setControlData();                   //设置控件数据
    void setAddControlData();                //设置添加入库
    void clearAddInfo();                     //清空添加入库

    MapList stoMapList;                      //入库入库列表
    MapList stoMatMapList;                   //入库原料列表
    MapList wareHouseMapList;                //仓库列表
    MapList supMapList;                      //供应商列表
    MapList supSelectMapList;                //供应商查询列表
    MapList staSelectMapList;                //状态查询列表
    MapList warHseSelectMapList;             //仓库查询列表
    MapList timeSelectMapList;               //时间查询列表
    Map mapPurchaseInfo;                     //入库订单详情
};

#endif // PURCHASESTORAGE_H
