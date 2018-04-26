#ifndef CONFIRMMAT_H
#define CONFIRMMAT_H

/***************************************************************
   功能:确认采购原料

   创建人:YYC

   创建时间:2017-11-22
**************************************************************/

#include <QWidget>
#include "titlebar/titlebar.h"

namespace Ui {
class ConfirmMat;
}

class ConfirmMat : public QWidget
{
    Q_OBJECT

public:
    explicit ConfirmMat(QWidget *parent = 0); //构造函数
    ~ConfirmMat();                            //析构函数

    void setMapListMat(const MapList &value); //设置原料列表
    void showWidget();                        //显示窗口
    void setPurNumber(const QString &value);  //设置采购单号

private slots:
    void on_pushButtonConfirm_clicked();      //确认采购
    void on_checkBoxAllSelect_clicked();      //全选
    void on_tableWidgetData_clicked(const QModelIndex &index);

private:
    Ui::ConfirmMat *ui;
    TitleBar * titleBar;                     //标题栏
    void initControl();                      //初始化控件
    void resizeEvent(QResizeEvent *event);   //重置窗口大小

    MapList mapListMat;
    QString purNumber;
};

#endif // CONFIRMMAT_H
