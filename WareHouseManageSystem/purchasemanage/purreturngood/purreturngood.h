#ifndef PURRETURNGOOD_H
#define PURRETURNGOOD_H

/***************************************************************
   功能:采购退货

   创建人:YYC

   创建时间:2017-11-02
**************************************************************/

#include <QWidget>
#include "global/globaldef.h"
#include "purchasemanage/purreturngood/addretmaterial/addretmaterial.h"
#include "purchasemanage/purreturngood/materialretinfo/materialretinfo.h"
#include "purchasemanage/purreturngood/subretposition/subretposition.h"
#include "purchasemanage/purreturngood/importrethistory/importrethistory.h"
#include "purchasemanage/purreturngood/extendretemail/extendretemail.h"
#include "purchasemanage/loginfo/loginfo.h"

namespace Ui {
class PurReturnGood;
}

class PurReturnGood : public QWidget
{
    Q_OBJECT

public:
    enum SHOWTYPE{SHOWSUCCESS, NOTSHOW};
    explicit PurReturnGood(QWidget *parent = 0);                        //构造函数
    ~PurReturnGood();                                                   //析构函数

    void showWidget();                                                  //显示窗口
    void readJson(QNetworkReply *reply, int type);                      //解析JSON
private slots:
    void on_pushButtonAdd_clicked();                                    //添加退货单
    void on_tableWidgetReturn_clicked(const QModelIndex &index);        //单击事件
    void on_pushButtonAddRetMat_clicked();                              //添加退货原料
    void on_pushButtonSave_clicked();                                   //保存数据
    void on_pushButtonSaveInfo_clicked();                               //更新数据
    void on_pushButtonRetMatInfo_clicked();                             //添加原料信息
    void on_pushButtonCancel_clicked();                                 //取消按钮
    void on_commandLinkButtonLog_clicked();                             //处理记录
    void on_pushButtonDeleteInfo_clicked();                             //删除退货单
    void on_commandLinkButtonEdit_clicked();                            //编辑退货原料
    void on_tableWidgetRetInfo_doubleClicked(const QModelIndex &index); //双击查询数据
    void on_pushButtonStartSureInfo_clicked();                          //确认退货
    void on_commandLinkButtonImport_clicked();                          //从历史退货订单导入
    void on_pushButtonCancelInfo_clicked();                             //取消按钮
    void on_pushButtonSelect_clicked();                                 //查询
    void on_pushButtonExtend_clicked();                                 //导出到邮箱

private:
    Ui::PurReturnGood *ui;
    AddRetMaterial * addRetMaterial;         //添加退货单
    AddRetMaterial * editRetMaterial;        //编辑退货单
    MaterialRetInfo* materialRetInfo;        //原料信息
    ImportRetHistory *importRetHistory;      //导入历史订单
    LogInfo *logInfo;                        //开始验收
    ExtendRetEmail *extendRetEmail;          //导出到邮箱

    int showType;                            //显示类型
    bool importFlage;
    bool saveFlage;                          //保存类型
    bool selectFlage;                        //选中类型
    QString returnId;                        //退货单ID
    QString returnNumber;                    //退货单单号
    QString returnState;                     //入库单状态
    QString retMatId;                        //原料ID
    MapList retMapList;                      //退货信息
    MapList retMatMapList;                   //原料列表
    MapList wareHouseMapList;                //仓库列表
    MapList supMapList;                      //供应商列表
    MapList staSelectMapList;                //查询状态列表
    MapList supSelectMapList;                //查询供应商列表
    Map retMapData;                          //退货数据

    void initControl();                      //初始化控件
    void clearInfo();                        //清空信息
    void setControlData();                   //设置控件数据
    void setAddControlData();                //设置添加数据
    void setReturnTableData();               //设置退货表格数据
};

#endif // PURRETURNGOOD_H
