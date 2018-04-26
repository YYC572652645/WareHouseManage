#ifndef IMPORTALLHISTORY_H
#define IMPORTALLHISTORY_H

/***************************************************************
   功能:导入历史订单

   创建人:殷宇辰

   创建时间:2017-12-20
**************************************************************/

#include <QWidget>
#include "titlebar/titlebar.h"

namespace Ui {
class ImportAllHistory;
}

class ImportAllHistory : public QWidget
{
    Q_OBJECT

public:
    enum IMPORTTYPE{PURTYPE, STOTYPE};
    explicit ImportAllHistory(QWidget *parent = 0); //构造函数
    ~ImportAllHistory();                            //析构函数

    void showWidget();                              //显示窗口
    void setDataMapList(const MapList &value);      //设置订单列表
    void setImportType(int value);                  //设置导入类型

private slots:
    void on_pushButtonImport_clicked();             //导入历史订单
    void on_pushButtonCancel_clicked();             //取消按钮

private:
    Ui::ImportAllHistory *ui;
    TitleBar * titleBar;                      //标题栏
    int importType;                           //导入类型
    void initControl();                       //初始化控件
    void resizeEvent(QResizeEvent *event);    //重置窗口大小
    MapList dataMapList;                      //订单列表
};

#endif // IMPORTALLHISTORY_H
