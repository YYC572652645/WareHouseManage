#ifndef ADDAUTHORITY_H
#define ADDAUTHORITY_H

/***************************************************************
   功能:添加权限

   创建人:YYC

   创建时间:2018-2-28
**************************************************************/

#include <QWidget>
#include "titlebar/titlebar.h"

namespace Ui {
class AddAuthority;
}

class AddAuthority : public QWidget
{
    Q_OBJECT

public:
    explicit AddAuthority(QWidget *parent = 0);  //构造函数
    ~AddAuthority();                             //析构函数
    void showWidget();                           //显示窗口

private slots:
    void on_pushButtonOk_clicked();              //确定按钮
    void on_pushButtonCancel_clicked();          //取消按钮

private:
    Ui::AddAuthority *ui;

    TitleBar * titleBar;                        //标题栏
    void initControl();                         //初始化控件
    void resizeEvent(QResizeEvent *event);      //重置窗口大小
};

#endif // ADDAUTHORITY_H
