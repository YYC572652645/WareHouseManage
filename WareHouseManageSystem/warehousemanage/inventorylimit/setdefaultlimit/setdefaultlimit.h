#ifndef SETDEFAULTLIMIT_H
#define SETDEFAULTLIMIT_H

/***************************************************************
   功能:设置上下限

   创建人:YYC

   创建时间:2018-2-10
**************************************************************/

#include <QWidget>
#include "titlebar/titlebar.h"

namespace Ui {
class SetDefaultLimit;
}

class SetDefaultLimit : public QWidget
{
    Q_OBJECT

public:
    explicit SetDefaultLimit(QWidget *parent = 0); //构造函数
    ~SetDefaultLimit();                            //析构函数
    void showWidget();                             //显示窗口
    void setMatNumber(const QString &value);       //设置原料个数
    void setMapListMat(const MapList &value);      //设置原料列表

private slots:
    void on_pushButtonSave_clicked();              //保存按钮
    void on_pushButtonCancel_clicked();            //取消按钮

private:
    Ui::SetDefaultLimit *ui;

    TitleBar * titleBar;                     //标题栏
    void initControl();                      //初始化控件
    void resizeEvent(QResizeEvent *event);   //重置窗口大小

    QString matNumber;
    MapList mapListMat;
};

#endif // DEFAULTMATINFO_H
