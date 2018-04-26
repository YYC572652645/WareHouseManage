#ifndef MATERIALRATIOWIDGET_H
#define MATERIALRATIOWIDGET_H

/***************************************************************
   功能:商品原料设置

   创建人:YYC

   创建时间:2017-11-20
**************************************************************/

#include <QWidget>
#include <QTreeWidgetItem>
#include "titlebar/titlebar.h"
#include "baseinfomanage/materialratiosetup/selectmaterial/selectmaterial.h"
#include "baseinfomanage/materialratiosetup/materialinfo/materialinfo.h"

namespace Ui {
class MaterialRatioWidget;
}

typedef struct TreeData
{
    QString foodId;
    QString pId;
    QString foodName;

}TreeData;

typedef List List;

class MaterialRatioWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MaterialRatioWidget(QWidget *parent = 0);                        //构造函数
    ~MaterialRatioWidget();                                                   //析构函数

    void showWidget();                                                        //显示窗口
    void readJson(QNetworkReply *reply, int type);                            //解析JSON

private slots:
    void on_treeWidgetData_clicked(const QModelIndex &index);                 //单击列表
    void on_pushButtonSaveInfo_clicked();                                     //保存信息
    void on_pushButtonCancelInfo_clicked();                                   //取消
    void on_pushButtonAddNewMat_clicked();                                    //添加新原料
    void on_listWidgetData_doubleClicked(const QModelIndex &index);           //双击列表

    void on_checkBox_clicked();

private:
    Ui::MaterialRatioWidget *ui;
    void initControl();                                                       //初始化控件
    void setTreeData();                                                       //设置数据
    void setControlData();                                                    //设置控件数据

    SelectMaterial *selectMaterial;                                           //选择原料
    MaterialInfo *materialInfo;                                               //原料信息
    MapList mapListTree;                                                      //树形数据
    QMap<QTreeWidgetItem*,TreeData> mapItemList;                              //ID和item的map映射
    QMap<QString,QString>matMap;                                              //菜品详情
    MapList mapListBomMaterial;                                               //仓库原料映射
    MapList mapListProductWare;                                               //仓库映射
    MapList mapListMat;                                                       //原料映射
    TreeData treeProData;                                                     //当前菜品
    QList<QLineEdit*>lineEditList;                                            //编辑框列表
    QString makeJson(List dataList, List ratioList);                          //组合JSON
    QWidget *createWidget(QString matName, QString whseName, QString number); //创建信息面板
    QWidget *createWidget(QString whseName, QString number);                  //创建信息面板
};

#endif // MATERIALRATIOWIDGET_H
