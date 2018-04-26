#ifndef CHECKUPDATE_H
#define CHECKUPDATE_H

/***************************************************************
   功能:检查更新

   创建人:YYC

   创建时间:2018-03-20
**************************************************************/

#include <QDialog>
#include "titlebar/titlebar.h"

namespace Ui {
class CheckUpdate;
}

class CheckUpdate : public QDialog
{
    Q_OBJECT

public:
    explicit CheckUpdate(QWidget *parent = 0);            //构造函数
    ~CheckUpdate();                                       //析构函数
    void showWidget(QString dataInfo, bool flage = false);//显示窗口

signals:
    void okUpdate();                     //确定更新

private slots:
    void on_pushButtonUpdate_clicked();  //更新按钮

private:
    Ui::CheckUpdate *ui;

    TitleBar * titleBar;                        //标题栏
    void initControl();                         //初始化控件
    void resizeEvent(QResizeEvent *event);      //重置窗口大小
};

#endif // CHECKUPDATE_H
