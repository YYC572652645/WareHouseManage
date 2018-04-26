#ifndef ADDUNITSITE_H
#define ADDUNITSITE_H

#include <QWidget>
#include "titlebar/titlebar.h"
#include <QResizeEvent>

/***************************************************************
   功能:添加副单元

   创建人:YYC

   创建时间:2017-12-16
**************************************************************/

namespace Ui {
class AddUnitSite;
}

typedef struct SitUnitData
{
    QString mainUnitName;
    QString siteUnitName;
    QString siteId;
    QString mainConver;
    QString viceConver;
    QString siteUnitId;
    QString materialId;
    QString code;
    bool wareHouseFlage;
    bool priceFlage;
    bool supplyFlage;
}SitUnitData;

class AddUnitSite : public QWidget
{
    Q_OBJECT

public:
    explicit AddUnitSite(QWidget *parent = 0);
    ~AddUnitSite();
    void showWidget(bool widgetType = false, int index = -1);           //显示窗口
    void clearControlInfo();                                            //清空控件信息


    void setMapUnitList(const MapList &value);                          //设置单位列表
    void setMainUnit(const QString &value);                             //设置主单位
    void setSiteUnitDataList(const QList<SitUnitData> &value);          //设置副单位列表
    void setMapSideList(const MapList &value);                          //设置副单位列表
    void setMaterialId(const QString &value);                           //设置原料ID
    void setIsWarehouseUnit(const QString &value);                      //设置库存单位
    void setIsPriceUnit(const QString &value);                          //设置计价单位
    void setIsSupplyUnit(const QString &value);                         //设置供货单位

    QString getIsWarehouseUnit() const;                                 //获取库存单位
    QString getIsPriceUnit() const;                                     //获取计价单位
    QString getIsSupplyUnit() const;                                    //获取供货单位
    QList<SitUnitData> getSiteUnitDataDelList() const;                  //获取删除的副单位列表
    const SitUnitData *getDataListIndex(int index);                     //根据下标获取数据
    QList<SitUnitData> getSiteUnitDataList() const;                     //获取副单位列表

private slots:
    void on_pushButtonSave_clicked();                                   //保存按钮
    void on_pushButtonCancel_clicked();                                 //取消按钮
    void on_comboBoxSiteUnit_currentIndexChanged(const QString &arg1);  //下拉选中改变
    void on_checkBoxWareHouse_clicked();                                //仓库单位
    void on_checkBoxPrice_clicked();                                    //计价单位
    void on_checkBoxSupply_clicked();                                   //供货单位
    void on_lineEditLeft_textEdited(const QString &arg1);               //编辑响应
    void on_lineEditRight_textEdited(const QString &arg1);              //编辑响应
    void on_pushButtonDel_clicked();

signals:
    void sendAddSave();                                                 //添加事件
    void sendInfoSave(int);                                             //查看事件
    void sendDelSave(int);                                              //删除事件

private:
    Ui::AddUnitSite *ui;

    TitleBar * titleBar;                                                //标题栏
    QString mainUnit;                                                   //主单位
    QString siteUnitName;                                               //副单元名称
    bool widgetType;                                                    //false为添加，true为查看更改
    int widgetIndex;                                                    //下标
    QList<SitUnitData>siteUnitDataList;                                 //副单位结构体
    QList<SitUnitData>siteUnitDataDelList;                              //删除的副单元结构体
    QList<Map>mapSideList;                                              //副单元列表
    QList<Map>mapUnitList;                                              //单位列表
    QString isWarehouseUnit;                                            //仓库单位
    QString isPriceUnit;                                                //计价单位
    QString isSupplyUnit;                                               //供货单位
    QString materialId;                                                 //原料ID
    QString siteUnitId;                                                 //副单位ID
    QString siteId;                                                     //副ID

    void initControl();                                                 //初始化控件
    void resizeEvent(QResizeEvent *event);                              //界面大小改变事件
};

#endif // ADDUNITSITE_H
