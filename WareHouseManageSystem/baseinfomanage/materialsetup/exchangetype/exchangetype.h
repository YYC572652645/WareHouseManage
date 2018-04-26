#ifndef EXCHANGETYPE_H
#define EXCHANGETYPE_H

#include <QWidget>
#include "titlebar/titlebar.h"
#include <QResizeEvent>

/***************************************************************
   功能:批量修改原料分类

   创建人:YYC

   创建时间:2017-12-16
**************************************************************/

namespace Ui {
class ExchangeType;
}

class ExchangeType : public QWidget
{
    Q_OBJECT

public:
    explicit ExchangeType(QWidget *parent = 0);    //构造函数
    ~ExchangeType();                               //析构函数
    void setMapExchangeData(const MapList &value); //设置改变数据
    MapList getMapExchangeData() const;            //获取改变数据

public slots:
    void on_pushButtonOk_clicked();                //确定按钮
    void on_pushButtonCancel_clicked();            //取消按钮

signals:
    void sendExchangeType(int);                    //发送事件

private:
    Ui::ExchangeType *ui;

    TitleBar * titleBar;                           //标题栏
    void initControl();                            //初始化控件
    void resizeEvent(QResizeEvent *event);         //重置窗口大小
    MapList mapExchangeData;                       //改变的数据
};

#endif // EXCHANGETYPE_H
