#ifndef TIMEMATINFO_H
#define TIMEMATINFO_H

/***************************************************************
   功能:库存详情

   创建人:YYC

   创建时间:2017-1-02
**************************************************************/

#include <QWidget>
#include "titlebar/titlebar.h"

namespace Ui {
class TimeMatInfo;
}

class TimeMatInfo : public QWidget
{
    Q_OBJECT

public:
    explicit TimeMatInfo(QWidget *parent = 0);   //构造函数
    ~TimeMatInfo();                              //析构函数
    void showWidget();                           //显示窗口
    void setMapListData(const MapList &value);   //设置控件数据
    void setMaterialName(const QString &value);  //设置原料名称

private:
    Ui::TimeMatInfo *ui;

    TitleBar * titleBar;                         //标题栏
    void setControlData();                       //设置控件数据
    void initControl();                          //初始化控件
    void resizeEvent(QResizeEvent *event);       //重置窗口大小

    MapList mapListData;
    QString materialName;
};

#endif // TIMEMATINFO_H
