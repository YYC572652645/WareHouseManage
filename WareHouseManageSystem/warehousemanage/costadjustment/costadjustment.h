#ifndef COSTADJUSTMENT_H
#define COSTADJUSTMENT_H

/***************************************************************
   功能:成本调价单

   创建人:YYC

   创建时间:2017-1-02
**************************************************************/

#include <QWidget>
#include "global/globaldef.h"
#include "costprice/costprice.h"
#include "warehousemanage/costadjustment/addcostmaterial/addcostmaterial.h"
#include "warehousemanage/costadjustment/materialcostinfo/materialcostinfo.h"
#include "purchasemanage/loginfo/loginfo.h"

namespace Ui {
class CostAdjustment;
}

class CostAdjustment : public QWidget
{
    Q_OBJECT

public:
    enum SHOWTYPE{SHOWSUCCESS, NOTSHOW};
    explicit CostAdjustment(QWidget *parent = 0);          //构造函数
    ~CostAdjustment();                                     //析构函数
    void showWidget();                                     //显示窗口
    void readJson(QNetworkReply *reply, int type);         //解析json
private slots:
    void on_tableWidgetCost_clicked(const QModelIndex &index); //单击控件
    void on_pushButtonAdd_clicked();                           //添加调价单
    void on_pushButtonSave_clicked();                          //保存调价单
    void on_pushButtonSee_clicked();                           //成本价一览
    void on_pushButtonSubmitInfo_clicked();                    //提交
    void on_pushButtonConfirmInfo_clicked();                   //确认调价
    void on_pushButtonAddAdjustMat_clicked();                  //添加原料
    void on_tableWidgetCostInfo_doubleClicked(const QModelIndex &index); //双击控件
    void on_pushButtonSaveInfo_clicked();                      //更新调价单信息
    void on_pushButtonDeleteInfo_clicked();                    //删除调价单
    void on_pushButtonCancelInfo_clicked();                    //取消按钮
    void on_pushButtonCancel_clicked();                        //取消按钮
    void on_pushButtonAddCostMatInfo_clicked();                //添加原料
    void on_commandLinkButtonEdit_clicked();                   //编辑原料
    void on_commandLinkButtonLog_clicked();                    //处理记录
    void on_pushButtonSelect_clicked();                        //查询调价单

private:
    Ui::CostAdjustment *ui;

    int showType;                   //显示类型
    bool saveFlage;                 //保存类型
    bool selectFlage;               //是否查询
    void initControl();             //初始化控件
    void setTableData();            //设置数据
    void setControlData();          //设置控件数据

    LogInfo *logInfo;
    AddCostMaterial *addCostMaterial;
    AddCostMaterial *editCostMaterial;
    MaterialCostInfo *materialCostInfo;
    MapList mapCostList;
    MapList mapMatList;
    MapList staSelectMapList;
    Map mapCostData;
    QString rejustId;
    QString readjustNumber;
    CostPrice *costPrice;
};

#endif // COSTADJUSTMENT_H
