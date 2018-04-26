#ifndef MATERIALINFO_H
#define MATERIALINFO_H

/***************************************************************
   功能:原料信息

   创建人:YYC

   创建时间:2018-2-28
**************************************************************/

#include <QWidget>
#include "titlebar/titlebar.h"

namespace Ui {
class MaterialInfo;
}

class MaterialInfo : public QWidget
{
    Q_OBJECT

public:
    enum WIDGETTYPE{ADDTYPE, EDITTYPE};                    //类型，添加，编辑
    explicit MaterialInfo(int type, QWidget *parent = 0);  //构造函数
    ~MaterialInfo();                                       //析构函数
    void showWidget();                                     //显示窗口
    void setUpData();                                      //设置数据
    void setMapItem(const Map &value);                     //设置Map数据
    void setProductMapList(const MapList &value);          //设置仓库列表
    void setUnitMapList(const MapList &value);             //设置单元列表
    void setMatName(const QString &value);                 //设置原料名称
    void setBarCode(const QString &value);                 //设置编码
    void setExpendNumber(const QString &value);            //设置消耗数量
    void setFoodId(const QString &value);                  //设置食品ID

private slots:
    void on_pushButtonSave_clicked();        //保存按钮
    void on_pushButtonDel_clicked();         //删除按钮
    void on_pushButtonCancel_clicked();      //取消按钮

private:
    Ui::MaterialInfo *ui;
    TitleBar * titleBar;                     //标题栏
    void initControl();                      //初始化控件
    void resizeEvent(QResizeEvent *event);   //重置窗口大小
    void clearInfo();                        //清空信息
    int widgetType;                          //窗口类型
    MapList unitMapList;                     //单元列表
    MapList productMapList;                  //仓库列表
    QMap<QString, QString>mapItem;           //数据
    QString matName;                         //原料名称
    QString barCode;                         //条形码
    QString expendNumber;                    //消费数量
    QString foodId;                          //食品ID

};

#endif // MATERIALINFO_H
