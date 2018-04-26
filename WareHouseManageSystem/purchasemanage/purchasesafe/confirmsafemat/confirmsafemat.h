#ifndef CONFIRMSAFEMAT_H
#define CONFIRMSAFEMAT_H

/***************************************************************
   功能:确认采购原料

   创建人:YYC

   创建时间:2017-12-20
**************************************************************/

#include <QWidget>
#include "titlebar/titlebar.h"

namespace Ui {
class ConfirmSafeMat;
}

class ConfirmSafeMat : public QWidget
{
    Q_OBJECT

public:
    explicit ConfirmSafeMat(QWidget *parent = 0); //构造函数
    ~ConfirmSafeMat();                            //析构函数

    void setMapListMat(const MapList &value);     //设置原料列表
    void showWidget();                            //显示窗口

private slots:
    void on_pushButtonConfirm_clicked();          //确认采购
    void on_pushButtonCancel_clicked();           //取消采购

private:
    Ui::ConfirmSafeMat *ui;
    TitleBar * titleBar;                          //标题栏
    void initControl();                           //初始化控件
    void resizeEvent(QResizeEvent *event);        //重置窗口大小

    MapList mapListMat;                           //原料列表
};

#endif // CONFIRMSAFEMAT_H
