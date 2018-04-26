#ifndef LOGINFO_H
#define LOGINFO_H

/***************************************************************
   功能:操作记录

   创建人:YYC

   创建时间:2017-11-22
**************************************************************/

#include <QWidget>
#include "titlebar/titlebar.h"

namespace Ui {
class LogInfo;
}

class LogInfo : public QWidget
{
    Q_OBJECT

public:
    explicit LogInfo(QWidget *parent = 0);     //构造函数
    ~LogInfo();                                //析构函数

    void showWidget();                         //显示窗口
    void setMapDataList(const MapList &value); //设置数据列表

private:
    Ui::LogInfo *ui;
    TitleBar * titleBar;                       //标题栏
    void initControl();                        //初始化控件
    void resizeEvent(QResizeEvent *event);     //重置窗口大小

    MapList mapDataList;                       //设置数据列表
};

#endif // LOGINFO_H
