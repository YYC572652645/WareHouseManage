#ifndef LOOKIMAGE_H
#define LOOKIMAGE_H

#include <QWidget>
#include "titlebar/titlebar.h"
#include <QResizeEvent>

/***************************************************************
   功能:等比例查看图片

   创建人:YYC

   创建时间:2017-12-16
**************************************************************/

namespace Ui {
class LookImage;
}

class LookImage : public QWidget
{
    Q_OBJECT

public:
    explicit LookImage(QWidget *parent = 0);                    //构造函数
    ~LookImage();                                               //析构函数
    void showWidget(QPixmap pixmap, QString imagePath = NULL);  //显示窗口
private:
    Ui::LookImage *ui;
    TitleBar * titleBar;                                        //标题栏
    void initControl();                                         //初始化控件

    bool eventFilter(QObject *watched, QEvent * event);         //过滤事件
    void resizeEvent(QResizeEvent *event);                      //界面大小改变事件

    QImage sourceImage;     //原图像
    float scaledValue;      //缩放因子
};

#endif // LOOKIMAGE_H
