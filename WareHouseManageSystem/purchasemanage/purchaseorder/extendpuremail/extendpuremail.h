#ifndef EXTENDPUREMAIL_H
#define EXTENDPUREMAIL_H

/***************************************************************
   功能:导出到邮箱

   创建人:YYC

   创建时间:2017-11-22
**************************************************************/

#include <QWidget>
#include "titlebar/titlebar.h"

namespace Ui {
class ExtendPurEmail;
}

class ExtendPurEmail : public QWidget
{
    Q_OBJECT

public:
    explicit ExtendPurEmail(QWidget *parent = 0);  //构造函数
    ~ExtendPurEmail();                             //析构函数

    void showWidget();                             //显示窗口
    void setDataMapList(const MapList &value);     //设置订单列表

private slots:
    void on_pushButtonExport_clicked();            //导出到邮箱
    void on_tableWidgetData_clicked(const QModelIndex &index);
    void on_checkBoxAllSelect_clicked();           //选中

private:
    Ui::ExtendPurEmail *ui;
    TitleBar * titleBar;                      //标题栏
    void initControl();                       //初始化控件
    void resizeEvent(QResizeEvent *event);    //重置窗口大小
    MapList dataMapList;                      //订单列表
};

#endif // IMPORTALLHISTORY_H
