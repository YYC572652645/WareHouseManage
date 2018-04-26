#ifndef EDITAUTHORITY_H
#define EDITAUTHORITY_H

/***************************************************************
   功能:编辑权限

   创建人:YYC

   创建时间:2018-2-28
**************************************************************/

#include <QWidget>
#include <QCheckBox>
#include "titlebar/titlebar.h"

namespace Ui {
class EditAuthority;
}

class EditAuthority : public QWidget
{
    Q_OBJECT

public:
    explicit EditAuthority(QWidget *parent = 0); //构造函数
    ~EditAuthority();                            //析构函数
    void showWidget(bool flage);                 //显示窗口
    void setCheck(List listData);                //设置选中
    void setMapUsrData(const Map &value);        //设置用户数据

private slots:
    void on_pushButtonOk_clicked();              //确定按钮
    void on_pushButtonCancel_clicked();          //取消按钮

private:
    Ui::EditAuthority *ui;

    TitleBar * titleBar;                     //标题栏
    void initControl();                      //初始化控件
    void resizeEvent(QResizeEvent *event);   //重置窗口大小
    void setCheck(bool falge);               //设置选中
    QMap<QString, QCheckBox*>checkBoxMap;    //控件映射
    QMap<QCheckBox*, QString>mapCheckBox;    //控件映射
    Map mapUsrData;                          //用户数据
};

#endif // EDITAUTHORITY_H
