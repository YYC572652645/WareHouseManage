#ifndef SubRetPosition_H
#define SubRetPosition_H

/***************************************************************
   功能:设置分仓

   创建人:YYC

   创建时间:2017-11-02
**************************************************************/

#include <QWidget>
#include "titlebar/titlebar.h"

namespace Ui {
class SubRetPosition;
}

class SubRetPosition : public QWidget
{
    Q_OBJECT

public:
    explicit SubRetPosition(QWidget *parent = 0);       //构造函数
    ~SubRetPosition();                                  //析构函数
    void showWidget();                                  //显示窗口
    void setWareHouseMapList(const MapList &value);     //设置仓库列表
    void setMapData(const Map &value);                  //设置数据
    void setPriceName(const QString &value);            //设置价格
    void setUnitName(const QString &value);             //设置单位
    void setNumberCount(const QString &value);          //设置数量
    void setStoMatId(const QString &value);             //设置入库单ID

    QString getTotalMoney() const;                      //获取总价钱
    QString getNumberCount() const;                     //获取总数量
    QString getWareHouseId() const;                     //获取仓库名称

private slots:
    void on_pushButtonSave_clicked();                   //保存数据
    void on_pushButtonCancel_clicked();                 //取消按钮
    void on_doubleSpinBoxNumber_valueChanged(double arg1); //数字改变
private:
    Ui::SubRetPosition *ui;

    Map mapData;                             //数据
    MapList wareHouseMapList;                //仓库列表
    QString priceName;                       //单价
    QString unitName;                        //单位
    QString numberCount;                     //数量
    QString stoMatId;                        //单ID
    QString totalMoney;                      //总价钱
    TitleBar * titleBar;                     //标题栏
    void initControl();                      //初始化控件
    void resizeEvent(QResizeEvent *event);   //重置窗口大小
};

#endif // SubRetPosition_H
