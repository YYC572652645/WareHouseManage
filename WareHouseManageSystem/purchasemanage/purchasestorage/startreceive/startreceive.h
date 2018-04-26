#ifndef STARTRECEIVE_H
#define STARTRECEIVE_H

/***************************************************************
   功能:开始验收

   创建人:YYC

   创建时间:2017-11-04
**************************************************************/

#include <QWidget>
#include <QCheckBox>
#include <QDoubleSpinBox>
#include "titlebar/titlebar.h"

namespace Ui {
class StartReceive;
}

class StartReceive : public QWidget
{
    Q_OBJECT

public:
    explicit StartReceive(QWidget *parent = 0);               //构造函数
    ~StartReceive();                                          //析构函数

    void setMapListMat(const MapList &value);                 //设置原料列表
    void showWidget();                                        //显示窗口
    void setStoNumber(const QString &value);                  //设置入库单号
    void setMapListListWshe(const QList<MapList> &value);     //设置仓库

private slots:
    void on_pushButtonConfirm_clicked();                      //确认采购
    void on_checkBoxAllSelect_clicked();                      //全选
    void on_listWidgetData_clicked(const QModelIndex &index); //单击选中

private:
    Ui::StartReceive *ui;
    TitleBar * titleBar;                     //标题栏
    void initControl();                      //初始化控件
    void resizeEvent(QResizeEvent *event);   //重置窗口大小
    QWidget *createWidget(QString matName, QString barCode, QString number, MapList mapListData); //创建信息面板

    QList<QCheckBox *>checkBoxList;                 //选中按钮列表
    QList<QList<QDoubleSpinBox *>>spinBoxListList;
    QList<MapList> mapListListWshe;
    MapList mapListMat;
    QString stoNumber;
};

#endif // STARTRECEIVE_H
