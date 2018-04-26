#ifndef TEMPLATEPUR_H
#define TEMPLATEPUR_H

/***************************************************************
   功能:模板采购

   创建人:YYC

   创建时间:2017-11-22
**************************************************************/

#include <QWidget>
#include <QDoubleSpinBox>
#include "titlebar/titlebar.h"

namespace Ui {
class TemplatePur;
}

class TemplatePur : public QWidget
{
    Q_OBJECT

public:
    explicit TemplatePur(QWidget *parent = 0);     //构造函数
    ~TemplatePur();                                //析构函数
    void showWidget();                             //显示窗口
    void setHide();                                //隐藏窗口
    void setShow();                                //显示窗口
    void setMapListTemplate(const MapList &value); //设置模板列表
    void setPurMapList(const MapList &value);      //设置采购订单列表

private slots:
    void on_commandLinkButtonOrder_clicked();      //生成采购订单
    void on_listWidgetData_doubleClicked(const QModelIndex &index);//双击击控件

private:
    Ui::TemplatePur *ui;
    TitleBar * titleBar;                     //标题栏
    void initControl();                      //初始化控件
    void resizeEvent(QResizeEvent *event);   //重置窗口大小

    MapList mapListTemplate;
    MapList purMapList;
    QMap<int, QDoubleSpinBox*>spinBoxMap;
    QList<QWidget*>widgetList;
    QWidget * createWidget(QString templateName, QString number); //创建信息面板
};

#endif // TEMPLATEPUR_H
