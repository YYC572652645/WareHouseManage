#ifndef EXTENDSTORAGE_H
#define EXTENDSTORAGE_H

/***************************************************************
   功能:导出入库订单

   创建人:殷宇辰

   创建时间:2017-12-20
**************************************************************/

#include <QWidget>
#include "titlebar/titlebar.h"

namespace Ui {
class ExtendStorage;
}

class ExtendStorage : public QWidget
{
    Q_OBJECT

public:
    explicit ExtendStorage(QWidget *parent = 0);  //构造函数
    ~ExtendStorage();                             //析构函数

    void showWidget();                            //显示窗口
    void setDataMapList(const MapList &value);    //设置订单列表

private slots:
    void on_pushButtonExport_clicked();           //导出到邮箱
    void on_tableWidgetData_clicked(const QModelIndex &index); //单击选中
    void on_checkBoxAllSelect_clicked();          //全选

private:
    Ui::ExtendStorage *ui;
    TitleBar * titleBar;                      //标题栏
    void initControl();                       //初始化控件
    void resizeEvent(QResizeEvent *event);    //重置窗口大小
    MapList dataMapList;                      //订单列表
};

#endif // EXTENDSTORAGE_H
