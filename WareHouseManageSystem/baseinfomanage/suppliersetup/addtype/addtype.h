#ifndef ADDTYPE_H
#define ADDTYPE_H

#include <QWidget>
#include <titlebar/titlebar.h>

/***************************************************************
   功能:添加类别

   创建人:YYC

   创建时间:2017-12-21
**************************************************************/

namespace Ui {
class AddType;
}

class AddType : public QWidget
{
    Q_OBJECT

public:
    explicit AddType(QWidget *parent = 0);   //构造函数
    ~AddType();                              //析构函数
    void showWidget();                       //显示窗口

    QString getTypeName() const;             //获取类别名称
    void setTitleName(QString title);        //设置标题名
    void showWidget(QString lineText);       //显示窗口
private slots:
    void on_pushButtonOk_clicked();          //确定按钮
    void on_pushButtonCancel_clicked();      //取消按钮
signals:
    void sendOk();                           //发送事件
private:
    Ui::AddType *ui;
    QString typeName;                        //类别名称
    TitleBar *titleBar;                      //标题栏
    void initControl();                      //初始化控件
    void resizeEvent(QResizeEvent *event);   //重置窗口大小
};

#endif // AddType_H
