#ifndef ACCOUNTEXPORT_H
#define ACCOUNTEXPORT_H

/***************************************************************
   功能:导出到邮箱

   创建人:YYC

   创建时间:2018-2-28
**************************************************************/

#include <QWidget>
#include "global/globaldef.h"
#include "titlebar/titlebar.h"

namespace Ui {
class AccountExport;
}

class AccountExport : public QWidget
{
    Q_OBJECT

public:
    explicit AccountExport(QWidget *parent = 0);    //构造函数
    ~AccountExport();                               //析构函数
    void showWidget();                              //显示窗口
    void initControl();                             //初始化控件
    void setAccountMapList(const MapList &value);   //设置数据列表

private slots:
    void on_pushButtonExport_clicked();             //导出
    void on_checkBoxAllSelect_clicked();            //全选
    void on_tableWidgetAccount_clicked(const QModelIndex &index); //单击选中

private:
    Ui::AccountExport *ui;
    void resizeEvent(QResizeEvent *event);  //改变事件
    MapList accountMapList;                 //数据列表
    TitleBar *titleBar;                     //标题栏
};

#endif // ACCOUNTEXPORT_H
