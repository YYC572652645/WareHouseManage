#ifndef INVENTORYADJUST_H
#define INVENTORYADJUST_H

/***************************************************************
   功能:库存调整

   创建人:YYC

   创建时间:2017-1-02
**************************************************************/

#include <QWidget>
#include "global/globaldef.h"
#include "warehousemanage/inventoryadjust/materialadjinfo/materialadjinfo.h"
#include "warehousemanage/inventoryadjust/addadjmaterial/addadjmaterial.h"
#include "warehousemanage/inventoryadjust/extendadjemail/extendadjemail.h"
#include "purchasemanage/loginfo/loginfo.h"
#include "exportemail/exportemail.h"

namespace Ui {
class InventoryAdjust;
}

class InventoryAdjust : public QWidget
{
    Q_OBJECT

public:
    enum SHOWTYPE{SHOWSUCCESS, NOTSHOW};
    explicit InventoryAdjust(QWidget *parent = 0);     //构造函数
    ~InventoryAdjust();                                //析构函数
    void showWidget();                                 //显示窗口
    void readJson(QNetworkReply *reply, int type);     //解析json

private slots:
    void on_tableWidgetAdjust_clicked(const QModelIndex &index);           //单击响应
    void on_tableWidgetAdjustInfo_doubleClicked(const QModelIndex &index); //双击查询
    void on_pushButtonAdd_clicked();                                       //添加调整单
    void on_pushButtonAdjMatInfo_clicked();                                //添加原料
    void on_pushButtonAddAdjustMat_clicked();                              //添加原料
    void on_pushButtonSave_clicked();                                      //保存数据
    void on_pushButtonCancel_clicked();                                    //取消按钮
    void on_pushButtonSaveInfo_clicked();                                  //更新数据
    void on_pushButtonDeleteInfo_clicked();                                //删除调整单
    void on_pushButtonExtend_clicked();                                    //导出到邮箱
    void on_commandLinkButtonEdit_clicked();                               //编辑原料
    void on_commandLinkButtonLog_clicked();                                //处理记录
    void on_pushButtonSubmit_clicked();                                    //提交
    void on_pushButtonCancelInfo_clicked();                                //取消按钮
    void on_pushButtonSelect_clicked();                                    //查询数据

private:
    Ui::InventoryAdjust *ui;
    MaterialAdjInfo *materialAdjInfo;
    AddAdjMaterial *addAdjMaterial;
    AddAdjMaterial *editAdjMaterial;
    LogInfo *logInfo;
    ExtendAdjEmail *extendEmailEmail;

    int showType;
    bool selectFlage;
    bool saveFlage;
    void initControl();
    void setAdjustTableData();
    void setControlData();

    MapList mapListAdjust;
    MapList adjMatMapList;
    MapList wareHouseMapList;
    MapList typeMapList;
    MapList typeSelectMapList;
    MapList warHseSelectMapList;
    MapList staSelectMapList;
    Map adjMapData;
    QString oddNumber;
    QString adjustMentId;
};

#endif // INVENTORYADJUST_H
