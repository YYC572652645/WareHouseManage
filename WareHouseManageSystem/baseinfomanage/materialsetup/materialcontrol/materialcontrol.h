#ifndef MATERIALCONTROL_H
#define MATERIALCONTROL_H

#include <QWidget>
#include "baseinfomanage/materialsetup/lookimage/lookimage.h"
#include "baseinfomanage/materialsetup/addunitsite/addunitsite.h"

/***************************************************************
   功能:原料信息

   创建人:YYC

   创建时间:2017-12-06
**************************************************************/

class QTableWidget;
class QLabel;
class QLineEdit;
class QComboBox;
class QListWidgetItem;
class QPushButton;

namespace Ui {
class MaterialControl;
}

class MaterialControl : public QWidget
{
    Q_OBJECT

public:
    explicit MaterialControl(QWidget *parent = 0);  //构造函数
    ~MaterialControl();                             //析构函数
    void setType(int type);                         //设置窗口类型
    void clearControlInfo();                        //清空控件信息
    void setPixMapImage(const QPixmap &value);      //设置显示图片
    void setMaterialId(const QString &value);       //设置原料ID
    void addSideList();                             //添加副单元

    /*******基本信息控件*******/
    QList<QListWidgetItem*>baseItemList;            //item列表
    QList<QWidget*>baseWidgetList;                  //widget列表
    QLineEdit *lineEditName;                        //名称
    QComboBox *comboxType;                          //类型
    QLineEdit *lineEditBarCode;                     //条码
    QComboBox *comboBoxMainUnit;                    //主单元
    QPushButton *pushButtonAdd;                     //添加副单元

    /*******扩展信息控件*******/
    QList<QListWidgetItem*>externItemList;          //item列表
    QList<QWidget*>externWidgetList;                //widget列表
    QLineEdit *lineEditSpec;                        //规格
    QLineEdit *lineEditShelf;                       //保质期
    QPushButton *pushButtonImage;                   //显示图片

    const static int CONTROLWIDGET = 200;           //控件宽度
    const static int CONTROLHIGHT  = 30;            //控件高度
    const static int IMAGEWIDGH    = 100;           //图片高度


    void setMapUnitList(const MapList &value);      //设置主单元列表
    void setCategoryList(const MapList &value);     //设置原料列表
    void setMapSideList(const MapList &value);      //设置副单元列表
    void setWareHouseFlage(const QString &value);   //设置库存单位
    void setPriceFlage(const QString &value);       //设置计价单位
    void setSupplyFlage(const QString &value);      //设置供货单位
    void setMapSideUnitList(const MapList &value);  //设置副单元列表
    void setSideMainUnit(const QString &value);     //设置副单位中的主单元
    void setCurrentText(const QString &value);      //设置当前文本
    AddUnitSite *getAddUnitSite();                  //获取副单位

private slots:
    void openImage();                               //打开图片
    void on_pushButtonSave_clicked();               //保存数据
    void on_pushButtonCancel_clicked();             //取消保存
    void on_pushButtonLookImage_clicked();          //图片预览
    void slotAddUnitSite();                         //添加副单元
    void receiveAddSave();                          //添加事件
    void receiveInfoSave(int index);                //查看事件
    void receiveDelSave(int index);                 //删除事件
    void slotComboxClick();                         //选择类型
    void on_listWidgetAddMaterialInfo_doubleClicked(const QModelIndex &index);
    void on_pushButtonDelImage_clicked();           //删除图片

private:
    Ui::MaterialControl *ui;
    int widgetType;                                 //窗口类型
    QPixmap pixMapImage;                            //图片
    LookImage *lookImage;                           //预览图片窗口
    QString filePath;                               //本地图片路径
    QString materialId;                             //原料ID
    QString wareHouseFlage;                         //仓库单位
    QString priceFlage;                             //计价单位
    QString supplyFlage;                            //供货单位
    QString currentText;                            //当前内容
    AddUnitSite *addUnitSite;                       //添加副单位
    QList<Map>mapUnitList;                          //主单元列表
    QList<Map>mapSideList;                          //副单元列表
    QList<Map>categoryList;                         //修改原料
    QList<QLabel *>labelSiteList;                   //副单元列表
    void initControl();                             //初始化控件
    void setWidget(QList<QWidget*>listWidget, QWidget*widget, int type, bool flage);  //设置widget
    QByteArray makeJson(QString unitId);                                              //组合JSON

};

#endif // MATERIALCONTROL_H
