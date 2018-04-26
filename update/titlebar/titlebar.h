#ifndef TITLEBAR_H
#define TITLEBAR_H

/***************************************************************
   功能:读取配置INI文件

   创建人:YYC

   创建时间:2018-03-14
**************************************************************/
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QMouseEvent>
#include <QComboBox>
#include <QVBoxLayout>

namespace TITLEBAR
{
enum WIDGETBYTTONTYPE
{
    MAXWIDGET,
    MINWIDGET,
    MAXMINWIDGET,
    ALLWIDGET,
};
}

class TitleBar : public QWidget
{
    Q_OBJECT
public:
    explicit TitleBar(QWidget *parentWidget = 0);

    void setBackGround();
    void setTitle(const QString &title);         //设置标题
    void setIcon(const QString &icon);           //设置图标
    void subButton(const int &type);             //设置按钮
    const static int CONTROLWIDTH   = 30;        //控件宽度

    int getTitleBarHeight() const;               //获取高度
    void setTitleBarHeight(int value);           //设置高度

public slots:
    void slotButton();

private:
    bool        mousePress;                      //按钮点击标志位
    QPoint      movePoint;                       //鼠标移动
    QPushButton *maxButton;                      //最大化按钮
    QPushButton *minButton;                      //最小化按钮
    QPushButton *closeButton;                    //关闭按钮
    QLabel      *imgLabel;                       //图片框
    QWidget     *parentWidget;                   //父窗口
    QLabel      *titleLabel;                     //标题名
    int titleBarHeight;                          //标题栏高度
    void initValue();                            //初始化值
    void mousePressEvent(QMouseEvent * event);   //鼠标点击事件
    void mouseReleaseEvent(QMouseEvent * event); //鼠标释放事件
    void mouseMoveEvent(QMouseEvent * event);    //鼠标移动事件
};

#endif // TITLEBAR_H
