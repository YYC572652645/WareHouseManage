#ifndef ADDUNIT_H
#define ADDUNIT_H

#include <QWidget>
#include <titlebar/titlebar.h>

/***************************************************************
   功能:添加单位

   创建人:YYC

   创建时间:2017-12-16
**************************************************************/

namespace Ui {
class AddUnit;
}

class AddUnit : public QWidget
{
    Q_OBJECT

public:
    explicit AddUnit(QWidget *parent = 0);   //构造函数
    ~AddUnit();                              //析构函数
    void showWidget();                       //显示窗口
    QString getUnitName() const;             //获取单元名称

private slots:
    void on_pushButtonOk_clicked();          //确定按钮
    void on_pushButtonCancel_clicked();      //取消按钮
signals:
    void sendOk();                           //发送事件
private:
    Ui::AddUnit *ui;
    QString unitName;                        //单元名称
    TitleBar * titleBar;                     //标题栏
    void initControl();                      //初始化控件
    void resizeEvent(QResizeEvent *event);   //重置窗口大小
};

#endif // ADDUNIT_H
