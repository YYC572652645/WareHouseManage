#ifndef IMPORTRETHISTORY_H
#define IMPORTRETHISTORY_H

/***************************************************************
   功能:导入历史订单

   创建人:YYC

   创建时间:2017-11-02
**************************************************************/

#include <QWidget>
#include "titlebar/titlebar.h"

namespace Ui {
class ImportRetHistory;
}

class ImportRetHistory : public QWidget
{
    Q_OBJECT

public:
    explicit ImportRetHistory(QWidget *parent = 0);  //构造函数
    ~ImportRetHistory();                             //析构函数

    void showWidget();                               //显示窗口
    void setPurMapList(const MapList &value);        //设置订单列表

private slots:
    void on_pushButtonImport_clicked();              //设置订单列表
    void on_pushButtonCancel_clicked();              //取消按钮

private:
    Ui::ImportRetHistory *ui;
    TitleBar * titleBar;                     //标题栏
    void initControl();                      //初始化控件
    void resizeEvent(QResizeEvent *event);   //重置窗口大小
    MapList purMapList;                      //订单列表
};

#endif // IMPORTRETHISTORY_H
