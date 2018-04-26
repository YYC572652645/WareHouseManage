#ifndef REASONWIDGET_H
#define REASONWIDGET_H

/***************************************************************
   功能:设置原因

   创建人:YYC

   创建时间:2017-1-02
**************************************************************/

#include <QWidget>
#include "titlebar/titlebar.h"
#include "exportemail/exportemail.h"

namespace Ui {
class ReasonWidget;
}

class ReasonWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ReasonWidget(QWidget *parent = 0);  //构造函数
    ~ReasonWidget();                             //析构函数

    void showWidget();                           //显示窗口
    void clearInfo();                            //清空信息
    void setReasonMapList(const MapList &value); //设置原因列表

private slots:
    void on_pushButtonAdd_clicked();             //添加原因
    void on_pushButtonDel_clicked();             //删除原因
    void on_tableWidget_clicked(const QModelIndex &index);  //单击事件
    void receiveText(QString text);              //接收信息
    void on_pushButtonOk_clicked();              //确定按钮
    void on_pushButtonCancel_clicked();          //取消按钮

signals:
    void sendString(QString);

private:
    Ui::ReasonWidget *ui;

    TitleBar * titleBar;                     //标题栏
    void initControl();                      //初始化控件
    void resizeEvent(QResizeEvent *event);   //重置窗口大小

    MapList reasonMapList;                   //原因列表
    ExportEmail *addReason;                  //添加原因
};

#endif // REASONWIDGET_H
