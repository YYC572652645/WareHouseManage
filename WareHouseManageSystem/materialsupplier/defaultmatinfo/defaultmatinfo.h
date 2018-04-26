#ifndef DEFAULTMATINFO_H
#define DEFAULTMATINFO_H

/***************************************************************
   功能:原料信息

   创建人:YYC

   创建时间:2017-11-22
**************************************************************/

#include <QWidget>
#include "titlebar/titlebar.h"

namespace Ui {
class DefaultMatInfo;
}

class DefaultMatInfo : public QWidget
{
    Q_OBJECT

public:
    explicit DefaultMatInfo(QWidget *parent = 0);  //构造函数
    ~DefaultMatInfo();                             //析构函数
    void setMapMatData(const Map &value);          //设置数据
    void showWidget();                             //显示窗口
    void setMapListSupplier(const MapList &value); //设置供应商列表

private slots:
    void on_pushButtonSave_clicked();              //保存按钮
    void on_pushButtonCancel_clicked();            //取消按钮

private:
    Ui::DefaultMatInfo *ui;

    TitleBar * titleBar;                           //标题栏
    void initControl();                            //初始化控件
    void resizeEvent(QResizeEvent *event);         //重置窗口大小

    Map mapMatData;
    MapList mapListSupplier;
};

#endif // DEFAULTMATINFO_H
