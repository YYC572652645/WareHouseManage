#ifndef VERSIONDIALOG_H
#define VERSIONDIALOG_H

#include <QDialog>
#include "titlebar/titlebar.h"

/***************************************************************
   功能:版本信息窗口

   创建人:YYC

   创建时间:2018-2-28
**************************************************************/

namespace Ui {
class VersionDialog;
}

class VersionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit VersionDialog(QWidget *parent = 0);  //构造函数
    ~VersionDialog();                             //析构函数
    void showWidget(QString dataInfo);            //显示窗口

private:
    Ui::VersionDialog *ui;
    TitleBar * titleBar;                          //标题栏
    void initControl();                           //初始化控件
};

#endif // VERSIONDIALOG_H
