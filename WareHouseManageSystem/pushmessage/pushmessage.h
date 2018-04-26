#ifndef PUSHMESSAGE_H
#define PUSHMESSAGE_H

/***************************************************************
   功能:信息推送，用于更新和接口请求失败的错误提示

   创建人:YYC

   创建时间:2017-11-22
**************************************************************/

#include <QWidget>
#include <QDesktopWidget>
#include <QResizeEvent>
#include "titlebar/titlebar.h"
#include <QTimer>
#include "global/globaldef.h"

namespace Ui {
class pushmessage;
}

class PushMessage : public QWidget
{
    Q_OBJECT

public:
    explicit PushMessage(QWidget *parent = 0);  //构造函数
    ~PushMessage();                             //析构函数
    void showWidget(bool language);             //显示窗口
    void showUpdateWidget();                    //显示更新窗口

private slots:
    void updateTimer();                         //定时器槽函数
    void on_pushButtonLook_clicked();           //确认更新

signals:
    void updateClient();                        //更新信号

private:
    Ui::pushmessage *ui;
    TitleBar *titleBar;
    QTimer *timer;
    QPoint normalPoint;
    QRect deskRect;                             //当前屏幕的矩形区域

    void initControl();                         //初始化控件
    void resizeEvent(QResizeEvent *event);      //界面更改事件
};

#endif // PUSHMESSAGE_H
