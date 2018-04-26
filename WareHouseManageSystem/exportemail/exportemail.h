#ifndef EXPORTEAMIL_H
#define EXPORTEAMIL_H
#include "titlebar/titlebar.h"
#include <QWidget>

/***************************************************************
   功能:导出到邮箱

   创建人:YYC

   创建时间:2017-11-15
**************************************************************/

namespace Ui {
class ExportEmail;
}

class ExportEmail : public QWidget
{
    Q_OBJECT

public:
    explicit ExportEmail(QWidget *parent = 0);  //构造函数
    ~ExportEmail();                             //析构函数
    void setTitle(QString text);                //设置标题
    void showWidget();                          //显示窗口
private slots:
    void on_pushButtonOk_clicked();             //确定按钮
    void on_pushButtonCancel_clicked();         //取消按钮

signals:
    void sendEmail(QString);                    //发送按钮

private:
    Ui::ExportEmail *ui;

    TitleBar * titleBar;                        //标题栏
    void initControl();                         //初始化控件
    void resizeEvent(QResizeEvent *event);      //重置窗口大小
};

#endif // ADDMATERIAL_H
