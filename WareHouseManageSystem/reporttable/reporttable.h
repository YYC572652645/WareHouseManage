#ifndef REPORTTABLE_H
#define REPORTTABLE_H

/***************************************************************
   功能:报表中心

   创建人:YYC

   创建时间:2017-1-02
**************************************************************/

#include <QWidget>
#include "global/globaldef.h"
#include "selectwidget/selectwidget.h"

namespace Ui {
class reporttable;
}

class ReportTable : public QWidget
{
    Q_OBJECT

public:
    explicit ReportTable(QWidget *parent = 0);        //构造函数
    ~ReportTable();                                   //析构函数
    void showWidget();                                //显示窗口
    void readJson(QNetworkReply *reply, int type);    //解析json

private slots:
    void on_treeWidget_clicked(const QModelIndex &index); //单击树形控件
    void on_treeWidget_pressed(const QModelIndex &index); //设置提示

private:
    Ui::reporttable *ui;
    void initControl();          //初始化控件
    SelectWidget selectWidget;   //选择窗口
};

#endif // REPORTTABLE_H
