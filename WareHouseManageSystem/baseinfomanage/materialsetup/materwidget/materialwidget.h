#ifndef MATERIALWIDGET_H
#define MATERIALWIDGET_H

#include <QWidget>
#include <QMenu>
#include <QAction>
#include <QContextMenuEvent>
#include "baseinfomanage/materialsetup/materialcontrol/materialcontrol.h"
#include "baseinfomanage/materialsetup/addmaterial/addmaterial.h"
#include "baseinfomanage/materialsetup/materialtype/materialtype.h"
#include "baseinfomanage/materialsetup/addunit/addunit.h"
#include "baseinfomanage/materialsetup/exchangetype/exchangetype.h"
#include "exportemail/exportemail.h"

/***************************************************************
   功能:原料设置

   创建人:YYC

   创建时间:2017-12-06
**************************************************************/

namespace Ui {
class MaterialWidget;
}

class MaterialWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MaterialWidget(QWidget *parent = 0);                //构造函数
    ~MaterialWidget();                                           //析构函数

    void showWidget();                                           //显示窗口
    void setTableData();                                         //设置主表格数据
    void setTableUnitData();                                     //设置单元表格数据
    void setTableTypeData();                                     //设置类型表格数据
    void downLoadImage(QNetworkReply *reply);                    //下载图片
    void readJson(QNetworkReply *reply, int type);               //解析JSON

private slots:
    void on_pushButtonAddMaterial_clicked();                     //添加原料
    void on_tableWidget_clicked(const QModelIndex &index);       //点击表格
    void on_tabWidget_tabBarClicked(int index);                  //点击Tab
    void receiveAddMaterial();                                   //点击了确定按钮
    void receiveAddUnit();                                       //点击了确定按钮
    void on_pushButtonAdd_clicked();                             //添加类型
    void on_treeWidgetCateGory_doubleClicked(const QModelIndex &index);
    void on_pushButtonAddUnit_clicked();                         //添加单位
    void on_pushButtonDelUnit_clicked();                         //删除单位
    void slotReceiveExchangeType(int index);                     //批量操作切换分类
    void on_pushButtonExtend_clicked();                          //导出到邮箱
    void receiveEmailText(QString emailText);                    //接收邮箱号
    void on_pushButtonDeleteMat_clicked();                       //删除原料
    void on_pushButtonChangeType_clicked();                      //切换分类

private:
    Ui::MaterialWidget *ui;
    QString categoryId;                                          //分类ID
    AddMaterial *addMaterial;                                    //添加原料
    MaterialType *materialType;                                  //添加类型
    AddUnit *addUnit;                                            //添加单元
    ExchangeType *exchangeTypeWidget;                            //修改类型
    ExportEmail *exportEmail;                                    //导出到邮箱
    MapList mapDataList;                                         //表格数据列表
    Map resMapData;                                              //原料信息
    MapList cateGoryMapList;                                     //用于存储类型
    MapList unitMapList;                                         //存储主单元
    MapList sideUnitMapList;                                     //存储副单元
    MapList cateGoryMapListAdd;                                  //添加原料的类型
    MapList cateGoryTypeMapList;                                 //添加类型中的原料类型
    bool widgetFlage;                                            //窗口标志位
    bool selectType;                                             //选中类型
    QTranslator translater;

    void initControl();                                          //初始化控件
    void setControlMaterialInfo();                               //设置控件信息
    void setControlAddMaterial();                                //设置控件信息
    void addMaterialType();                                      //添加类型
    QByteArray makeJson(List data);                              //组合JSON
};

#endif // MATERIALWIDGET_H
