#ifndef SUPPLIERWIDGET_H
#define SUPPLIERWIDGET_H

/***************************************************************
   功能:供应商设置

   创建人:YYC

   创建时间:2017-12-21
**************************************************************/

#include <QWidget>
#include "titlebar/titlebar.h"
#include "baseinfomanage/suppliersetup/supmaterial/supmaterial.h"
#include "baseinfomanage/suppliersetup/addtype/addtype.h"
#include "exportemail/exportemail.h"

namespace Ui {
class SupplierWidget;
}

class SupplierWidget : public QWidget
{
    Q_OBJECT

public:
    enum SAVETYPE{BUTTONTYPE, LINKTYPE};
    explicit SupplierWidget(QWidget *parent = 0);     //构造函数
    ~SupplierWidget();                                //析构函数

    void setTableSupData();                           //设置表格数据
    void setSupplierInfo();                           //设置数据
    void showWidget();                                //显示窗口
    void readJson(QNetworkReply *reply, int type);    //解析JSON

private slots:
    void on_pushButtonAddSupplier_clicked();          //添加供应商
    void on_tableWidgetSupplier_clicked(const QModelIndex &index); //单击列表
    void on_checkBoxInvoice_clicked();                //添加中的税率事件
    void on_checkBoxInvoiceInfo_clicked();            //信息中的税率事件
    void on_pushButtonSaveInfo_clicked();             //信息中的保存事件
    void on_pushButtonDelInfo_clicked();              //信息中的删除事件
    void on_pushButtonCancelInfo_clicked();           //信息中的取消事件
    void on_commandLinkButtonSupplyMatInfo_clicked(); //信息中的选择原料事件
    void on_pushButtonAddType_clicked();              //添加类型
    void on_pushButtonDelType_clicked();              //删除类型
    void slotReceiveAddType();                        //接收添加类型
    void slotReceiveUpdateType();                     //接收更新类型
    void on_pushButtonSave_clicked();                 //添加中的保存事件
    void on_commandLinkButtonSupplyMat_clicked();     //添加中的选择原料
    void on_pushButtonUpdateType_clicked();           //更新类型
    void on_pushButtonCancel_clicked();               //取消事件
    void slotRefreshCount(int count);                 //接收选择原料的个数
    void on_lineEditTaxRateInfo_textEdited(const QString &arg1);
    void on_lineEditTaxRate_textEdited(const QString &arg1);
    void receiveEmailText(QString emailText);         //接收邮箱号
    void on_pushButtonExtend_clicked();

private:
    Ui::SupplierWidget *ui;

    int saveType;                                      //保存类型
    bool selectFalge;                                  //是否选中
    SupMaterial *supMaterial;                          //供应商原料
    AddType *addType;                                  //添加类别
    AddType *updateType;                               //更新类别
    ExportEmail *exportEmail;                          //导出到邮箱
    void initControl();                                //初始化控件
    void clearInfo();                                  //清空信息

    MapList supMapList;                                //供应商列表
    MapList materialMapList;                           //原料列表
    MapList typeMapList;                               //类别列表
    QMap<QString, QString>supDetailsMap;               //供应商详情
};

#endif // SUPPLIERWIDGET_H
