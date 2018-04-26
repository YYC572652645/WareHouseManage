#ifndef TODAYHOUSEMONEY_H
#define TODAYHOUSEMONEY_H

/***************************************************************
   功能:今日报表

   创建人:YYC

   创建时间:2017-1-02
**************************************************************/

#include <QWidget>
#include "global/globaldef.h"

#define FIRST_LIN_COLOR  QColor(0,   107, 176)
#define SECOND_LIN_COLOR QColor(239, 169, 13)
#define THIRD_LIN_COLOR  QColor(29,  24,  21)
#define FOURTH_LIN_COLOR QColor(5,   147, 65)
#define FIFTH_LIN_COLOR  QColor(220,  47, 31)
#define TEXT_COLOR       QColor(0,   0, 0)
#define BRUSH_COLOR      QColor(255, 255, 255, 0)

namespace Ui {
class todayhousemoney;
}

typedef struct CoorData
{
    QVector<double>dataX;  //横坐标
    QVector<double>dataY;  //纵坐标
}CoorData;

class TodayHouseMoney : public QWidget
{
    Q_OBJECT

public:
    explicit TodayHouseMoney(QWidget *parent = 0);  //构造函数
    ~TodayHouseMoney();                             //析构函数
    void showWidget();                              //显示窗口
    void readJson(QNetworkReply *reply, int type);  //解析json

private:
    Ui::todayhousemoney *ui;

    void initControl();                          //初始化控件
    void setControlData();                       //设置控件数据
    float getMaxData();                          //获取最大值
    float getMaxData(QList<float>listData);      //获取最大值
    float getMinData();                          //获取最小值
    float getMinData(QList<float>listData);      //获取最小值
    unsigned int getTime(QString timeText);      //获取时间
    QPoint matchPoint(QPoint point);             //匹配点算法
    bool eventFilter(QObject *watched, QEvent *event); //鼠标移动

    QMap<QString, CoorData> mapCoorData;
    CoorData smallPointData;
    CoorData bigPointData;
    MapList mapListData;
    int currentIndex;
    double xUpper;
    double xLower;
    double yUpper;
    double yLower;
};

#endif // TODAYHOUSEMONEY_H
