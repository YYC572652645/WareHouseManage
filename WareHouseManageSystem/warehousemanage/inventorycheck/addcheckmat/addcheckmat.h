#ifndef ADDCHECKMAT_H
#define ADDCHECKMAT_H

/***************************************************************
   功能:添加原料

   创建人:YYC

   创建时间:2018-1-10
**************************************************************/

#include <QWidget>
#include "titlebar/titlebar.h"

namespace Ui {
class AddCheckMat;
}

class AddCheckMat : public QWidget
{
    Q_OBJECT

public:
    explicit AddCheckMat(QWidget *parent = 0);  //构造函数
    ~AddCheckMat();                             //析构函数
    void showWidget();                          //显示窗口
    void setMapMatList(const MapList &value);   //设置原料列表
    void setWareHouseId(const QString &value);  //设置仓库ID
    void setCheckNumber(const QString &value);  //设置单号

private slots:
    void on_pushButtonSave_clicked();                          //保存数据
    void on_pushButtonCancel_clicked();                        //取消按钮
    void on_checkBoxAllSelect_clicked();                       //全选
    void on_tableWidgetData_clicked(const QModelIndex &index); //单击控件

private:
    Ui::AddCheckMat *ui;

    TitleBar * titleBar;                     //标题栏
    void initControl();                      //初始化控件
    void resizeEvent(QResizeEvent *event);   //重置窗口大小
    QString wareHouseId;                     //仓库ID
    QString checkNumber;                     //单号
    MapList mapMatList;                      //原料列表
};

#endif // ADDCHECKMAT_H
