#ifndef DEFAULTLIMITINFO_H
#define DEFAULTLIMITINFO_H

/***************************************************************
   功能:库存上下限信息

   创建人:YYC

   创建时间:2018-2-10
**************************************************************/

#include <QWidget>
#include "titlebar/titlebar.h"

namespace Ui {
class DefaultLimitInfo;
}

class DefaultLimitInfo : public QWidget
{
    Q_OBJECT

public:
    explicit DefaultLimitInfo(QWidget *parent = 0);         //构造函数
    ~DefaultLimitInfo();                                    //析构函数
    void setMapMatData(const Map &value);                   //设置数据
    void showWidget();                                      //显示窗口
private slots:
    void on_pushButtonSave_clicked();                       //保存按钮
    void on_pushButtonCancel_clicked();                     //取消按钮
    void on_lineEditUpper_textEdited(const QString &arg1);  //编辑
    void on_lineEditLower_textChanged(const QString &arg1); //编辑

private:
    Ui::DefaultLimitInfo *ui;

    TitleBar * titleBar;                     //标题栏
    void initControl();                      //初始化控件
    void resizeEvent(QResizeEvent *event);   //重置窗口大小

    Map mapMatData;
};

#endif // DEFAULTMATINFO_H
