#ifndef SELECTWIDGET_H
#define SELECTWIDGET_H

/***************************************************************
   功能:报表窗口

   创建人:YYC

   创建时间:2017-1-02
**************************************************************/

#include <QWidget>
#include "global/globaldef.h"
#include "titlebar/titlebar.h"
#include "exportemail/exportemail.h"
#include <QPushButton>

namespace Ui {
class SelectWidget;
}

class SelectWidget : public QWidget
{
    Q_OBJECT

public:
    enum SHOWTYPE
    {
        STO_PAGE,
        STO_GATHER_PAGE,
        RET_PAGE,
        ADJ_PAGE,
        CHECK_PAGE,
        CHECK_GATHER_PAGE,
        SUP_PAGE,
        SUP_GATHER_PAGE,
        MAT_SELECT_PAGE,
    };

    explicit SelectWidget(QWidget *parent = 0);  //构造函数
    ~SelectWidget();                             //析构函数
    void showWidget(int type);                   //显示窗口
    void setControlData();                       //设置控件数据
    void setTableData();                         //设置表格数据
    void setMapListState(const MapList &value);
    void setMapListSupplier(const MapList &value);
    void setMapListWareHouse(const MapList &value);
    void setMapListTime(const MapList &value);
    void setTypeList(const List &value);
    void setMapListData(const MapList &value);
    void setMapListMatCat(const MapList &value);

private slots:
    void on_pushButtonYesterday_clicked();   //昨日
    void on_pushButtonThisWeek_clicked();    //本周
    void on_pushButtonLastWeek_clicked();    //上周
    void on_pushButtonThisMonth_clicked();   //本月
    void on_pushButtonLastMonth_clicked();   //上月
    void on_pushButtonSelect_clicked();      //查询报表
    void on_pushButtonExtendEmail_clicked(); //导出到邮箱
    void receiveEmailText(QString emailText);//接收邮箱号

private:
    Ui::SelectWidget *ui;

    void clearInfo();                          //清空信息
    void initControl();                        //初始化控件
    void setCheckButton(QPushButton * button); //设置选中
    void selectExtend(bool typeFlage);         //查询或导出
    void setDateTime(QString name);            //设置时间
    QList<QPushButton *>buttonList;

    ExportEmail exportEmail;
    MapList mapListState;
    MapList mapListSupplier;
    MapList mapListWareHouse;
    MapList mapListTime;
    MapList mapListData;
    MapList mapListMatCat;
    List    typeList;

    QString matCatId;
    QString stateId;
    QString supplierId;
    QString wareHouseID;
    QString timeType;
    QString strTime;
    QString materialText;
    QString operationId;
    QString typeId;
    QString emailText;

    int widgetType;
};

#endif // SELECTWIDGET_H
