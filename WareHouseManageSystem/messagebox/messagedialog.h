#ifndef MESSAGEDIALOG_H
#define MESSAGEDIALOG_H

/***************************************************************
   功能:自封装使用的MessageBox

   创建人:殷宇辰

   创建时间:2017-11-20
**************************************************************/

#include <QDialog>
#include <QToolButton>
#include <QPushButton>
#include <QLabel>
#include <QCheckBox>
#include <QPainter>
#include <QPaintEvent>
#include <QPixmap>
#include <QBitmap>
#include <QMouseEvent>
#include <QStyle>

#define MESSAGEBOX MessageBox::getInstance()

namespace Ui {
class MessageDialog;
}

class MessageDialog : public QDialog
{
    Q_OBJECT

public:
    /*************      构造函数           *************/
    explicit MessageDialog(QWidget *parent = 0);

    /*************      析构函数           *************/
    ~MessageDialog();

    /*************      设置函数           *************/
    int setInfo(QString info, bool imageFlage = false, bool isOkHidden = true);

public slots:
    void okOperate();                         //确定操作
    void cancelOperate();                     //取消操作

private:
    Ui::MessageDialog *ui;
    bool mousePress;                           //按钮是否被点击
    QPoint movePoint;                          //鼠标移动
    QLabel *titleLabel;                        //标题框
    QLabel *imgLabel;                          //图片框
    QLabel *msgLabel;                          //消息框
    QPushButton*cancelButton;                  //取消按钮
    QPushButton*okButton;                      //确定按钮
    QString okText;
    QString cancelText;

    void paintEvent(QPaintEvent *event);       //画图函数
    void mousePressEvent(QMouseEvent*event);   //鼠标点击
    void mouseReleaseEvent(QMouseEvent *event);//鼠标释放
    void mouseMoveEvent(QMouseEvent *event);   //鼠标移动
};

class MessageBox
{
public:
    static MessageBox *getInstance();

    int showMessageBox(QWidget *parent,QString info,
                       bool imageFlage = false, bool isOkHidden = true);

private:
    MessageBox();                   //构造函数
    static MessageBox * instance;   //单例对象
};

#endif // MESSAGEDIALOG_H
