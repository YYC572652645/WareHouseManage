#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

/***************************************************************
   功能:登录窗口

   创建人:YYC

   创建时间:2017-11-22
**************************************************************/

#include <QDialog>
#include "titlebar/titlebar.h"
#include <QResizeEvent>
#include <QComboBox>
#include <QListWidget>
#include <QAbstractItemDelegate>
#include <QNetworkConfigurationManager>

namespace Ui {
class logindialog;
}

#define LOGINDIALOG LoginDialog::getInstance()

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0); //构造函数
    ~LoginDialog();                            //析构函数

    static LoginDialog *getInstance();         //单例模式
    void userLoginInfo(const Map &mapData);    //店家登录

private slots:
    void on_pushButtonLogin_clicked();         //登录响应事件
    void deleteUserName(int index);            //删除用户名
    void on_comboBoxShopCode_activated(int index);
    void on_comboBoxShopCode_editTextChanged(const QString &arg1);

private:
    Ui::logindialog *ui;

    static LoginDialog *instance;
    TitleBar *titleBar;                        //标题栏
    QListWidget *userListWidget;
    QListWidget *shopListWidget;

    void initControl();                        //初始化控件
    void resizeEvent(QResizeEvent *event);     //界面改变事件
};

#endif // LOGINDIALOG_H
