#ifndef REFUSEWIDGET_H
#define REFUSEWIDGET_H
#include "titlebar/titlebar.h"
#include <QWidget>

/***************************************************************
   功能:拒绝原因

   创建人:YYC

   创建时间:2017-11-04
**************************************************************/

namespace Ui {
class RefuseWidget;
}

class RefuseWidget : public QWidget
{
    Q_OBJECT

public:
    enum TYPE{REFUSE, RECONFIRM};
    explicit RefuseWidget(QWidget *parent = 0);  //构造函数
    ~RefuseWidget();                             //析构函数

    void showWidget();                           //显示窗口
    void setStorageNumber(const QString &value);

    void setType(int value);

private slots:
    void on_pushButtonOk_clicked();             //确定按钮
    void on_pushButtonCancel_clicked();         //取消按钮

private:
    Ui::RefuseWidget *ui;
    QString storageNumber;                      //入库单号
    int type;                                   //类型
    TitleBar * titleBar;                        //标题栏
    void initControl();                         //初始化控件
    void resizeEvent(QResizeEvent *event);      //重置窗口大小
};

#endif // REFUSEWIDGET_H
