#ifndef EXTENDTRANEMAIL_H
#define EXTENDTRANEMAIL_H

/***************************************************************
   功能:导出邮箱

   创建人:YYC

   创建时间:2018-2-10
**************************************************************/

#include <QWidget>
#include "titlebar/titlebar.h"

namespace Ui {
class ExtendTranEmail;
}

class ExtendTranEmail : public QWidget
{
    Q_OBJECT

public:
    explicit ExtendTranEmail(QWidget *parent = 0);  //构造函数
    ~ExtendTranEmail();                             //析构函数

    void showWidget();                              //显示窗口
    void setDataMapList(const MapList &value);      //设置订单列表

private slots:
    void on_pushButtonExport_clicked();             //导出到邮箱
    void on_tableWidgetData_clicked(const QModelIndex &index); //单击选中
    void on_checkBoxAllSelect_clicked();            //全选

private:
    Ui::ExtendTranEmail *ui;
    TitleBar * titleBar;                      //标题栏
    void initControl();                       //初始化控件
    void resizeEvent(QResizeEvent *event);    //重置窗口大小
    MapList dataMapList;                      //订单列表
};

#endif // IMPORTALLHISTORY_H
