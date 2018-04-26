#ifndef SETDEFAULTSUP_H
#define SETDEFAULTSUP_H

/***************************************************************
   功能:设置默认供应商

   创建人:YYC

   创建时间:2017-11-22
**************************************************************/

#include <QWidget>
#include "titlebar/titlebar.h"

namespace Ui {
class SetDefaultSup;
}

class SetDefaultSup : public QWidget
{
    Q_OBJECT

public:
    explicit SetDefaultSup(QWidget *parent = 0);   //构造函数
    ~SetDefaultSup();                              //析构函数
    void showWidget();                             //显示窗口
    void setMapListSupplier(const MapList &value); //设置数据列表
    void setMatNumber(const QString &value);       //设置原料个数
    void setMapListMat(const MapList &value);      //设置原料列表

private slots:
    void on_pushButtonSave_clicked();              //保存按钮
    void on_pushButtonCancel_clicked();            //取消按钮

private:
    Ui::SetDefaultSup *ui;

    TitleBar * titleBar;                           //标题栏
    void initControl();                            //初始化控件
    void resizeEvent(QResizeEvent *event);         //重置窗口大小

    MapList mapListSupplier;
    QString matNumber;
    MapList mapListMat;
};

#endif // DEFAULTMATINFO_H
