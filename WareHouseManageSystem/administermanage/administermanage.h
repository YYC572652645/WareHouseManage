#ifndef ADMINISTERMANAGE_H
#define ADMINISTERMANAGE_H

/***************************************************************
   功能:用户管理

   创建人:YYC

   创建时间:2018-2-28
**************************************************************/

#include <QWidget>
#include <QPushButton>
#include "global/globaldef.h"

class EditAuthority;
class AddAuthority;

namespace Ui {
class AdministerManage;
}

class AdministerManage : public QWidget
{
    Q_OBJECT

public:
    explicit AdministerManage(QWidget *parent = 0);  //构造函数
    ~AdministerManage();                             //析构函数
    void readJson(QNetworkReply *reply, int type);   //读取数据
    void showWidget();                               //显示窗口

private slots:
    void deleteUser();                  //删除用户
    void editUser();                    //编辑用户
    void on_pushButtonAdd_clicked();    //添加用户

private:
    Ui::AdministerManage *ui;

    void initControl();                 //初始化控件
    void setTableData();                //设置表格数据
    MapList userMapList;                //用户列表
    QList<List> userRuleList;           //用户权限列表
    MapList ruleMapList;                //权限列表
    bool adminFlage;

    QList<QPushButton *>editButtonList;
    QList<QPushButton *>delButtonList;

    EditAuthority *editAuthority;
    AddAuthority *addAuthority;
};

#endif // ADMINISTERMANAGE_H
