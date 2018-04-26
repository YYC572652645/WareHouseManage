#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

/***************************************************************
   功能:自定义按钮

   创建人:YYC

   创建时间:2017-11-22
**************************************************************/

#include <QObject>
#include <QPushButton>

class PushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit PushButton(QWidget *parent = 0, int type = 0);  //构造函数

signals:
    void clicked(int);   //点击按钮
private:
    int type;            //按钮类型
    void mousePressEvent(QMouseEvent * event); //点击事件
};

#endif // PUSHBUTTON_H
