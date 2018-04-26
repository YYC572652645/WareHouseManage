#include "todayhousemoney.h"
#include "ui_todayhousemoney.h"
#include "httpclient/httpkey.h"
#include <QDateTime>
#include "messagebox/messagedialog.h"

/*********************     构造函数     ********************/
TodayHouseMoney::TodayHouseMoney(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::todayhousemoney), currentIndex(-1)
  , xUpper(0), xLower(0) , yUpper(0), yLower(0)
{
    ui->setupUi(this);

    this->initControl();

    ui->widgetCustomPlot->installEventFilter(this);
}

/*********************     析构函数     ********************/
TodayHouseMoney::~TodayHouseMoney()
{
    delete ui;
}

/*********************     初始化控件   ********************/
void TodayHouseMoney::initControl()
{
    //可放大缩小
    ui->widgetCustomPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    //设置坐标轴
    ui->widgetCustomPlot->xAxis->setLabel(tr("时间"));
    ui->widgetCustomPlot->xAxis->setLabelColor(QColor(40,150,120));
    ui->widgetCustomPlot->xAxis->setLabelFont(QFont("ZYSong", 12));

    //设置时间类型的坐标轴
    ui->widgetCustomPlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->widgetCustomPlot->xAxis->setDateTimeFormat("MM.d");
    ui->widgetCustomPlot->xAxis->setDateTimeSpec(Qt::UTC);

    //设置一天为固定的一个刻度
    ui->widgetCustomPlot->xAxis->setAutoTickStep(false);
    ui->widgetCustomPlot->xAxis->setTickStep(GLOBALDEF::ONEDAY);
    ui->widgetCustomPlot->xAxis->setSubTickCount(1);

    //画笔宽度
    const static int PEN_WIDTH = 2;

    //第一个图
    ui->widgetCustomPlot->addGraph();

    QPen firstPen;
    firstPen.setWidth(PEN_WIDTH);
    firstPen.setColor(FIRST_LIN_COLOR);

    ui->widgetCustomPlot->graph(ZERO)->setPen(firstPen);
    ui->widgetCustomPlot->graph(ZERO)->setLineStyle(QCPGraph::LineStyle::lsLine);

    //第二个图
    ui->widgetCustomPlot->addGraph();

    QPen secondPen;
    secondPen.setWidth(PEN_WIDTH);
    secondPen.setColor(SECOND_LIN_COLOR);

    ui->widgetCustomPlot->graph(ONE)->setPen(secondPen);
    ui->widgetCustomPlot->graph(ONE)->setLineStyle(QCPGraph::LineStyle::lsLine);

    //第三个图
    ui->widgetCustomPlot->addGraph();

    QPen thirdPen;
    thirdPen.setWidth(PEN_WIDTH);
    thirdPen.setColor(THIRD_LIN_COLOR);

    ui->widgetCustomPlot->graph(TWO)->setPen(thirdPen);
    ui->widgetCustomPlot->graph(TWO)->setLineStyle(QCPGraph::LineStyle::lsLine);

    //第四个图
    ui->widgetCustomPlot->addGraph();

    QPen fourthPen;
    fourthPen.setWidth(PEN_WIDTH);
    fourthPen.setColor(FOURTH_LIN_COLOR);

    ui->widgetCustomPlot->graph(THREE)->setPen(fourthPen);
    ui->widgetCustomPlot->graph(THREE)->setLineStyle(QCPGraph::LineStyle::lsLine);

    //第五个图
    ui->widgetCustomPlot->addGraph();

    QPen fifthPen;
    fifthPen.setWidth(PEN_WIDTH);
    fifthPen.setColor(FIFTH_LIN_COLOR);

    ui->widgetCustomPlot->graph(FOUR)->setPen(fifthPen);
    ui->widgetCustomPlot->graph(FOUR)->setLineStyle(QCPGraph::LineStyle::lsLine);

    //设置第一个点
    ui->widgetCustomPlot->addGraph();
    ui->widgetCustomPlot->graph(FIVE)->setPen(QPen(Qt::darkRed));
    ui->widgetCustomPlot->graph(FIVE)->setLineStyle(QCPGraph::lsNone);
    ui->widgetCustomPlot->graph(FIVE)->setScatterStyle(QCPScatterStyle::ssDisc);

    //设置第二个点
    ui->widgetCustomPlot->addGraph();
    ui->widgetCustomPlot->graph(SIX)->setPen(QPen(Qt::darkRed));
    ui->widgetCustomPlot->graph(SIX)->setLineStyle(QCPGraph::lsNone);
    ui->widgetCustomPlot->graph(SIX)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 12));


    //设置图例图标大小
    ui->widgetCustomPlot->legend->setIconSize(20, 20);

    //设置图例文字颜色
    ui->widgetCustomPlot->legend->setTextColor(TEXT_COLOR);

    //设置字体
    ui->widgetCustomPlot->legend->setFont(QFont("ZYSong", 11, QFont::Bold));

    //设置图例是否可用
    ui->widgetCustomPlot->legend->setVisible(true);

    //在图例中添加线
    ui->widgetCustomPlot->axisRect()->setupFullAxesBox();

    //将图例矩形域放到右上角
    ui->widgetCustomPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop | Qt::AlignRight);

    //设置图例背景色
    ui->widgetCustomPlot->legend->setBrush(BRUSH_COLOR);

    //加曲线名称
    ui->widgetCustomPlot->graph(ZERO)->setName(tr("入库金额"));
    ui->widgetCustomPlot->graph(ONE)->setName(tr("销售毛利润"));
    ui->widgetCustomPlot->graph(TWO)->setName(tr("实际消耗金额"));
    ui->widgetCustomPlot->graph(THREE)->setName(tr("退货出货金额"));
    ui->widgetCustomPlot->graph(FOUR)->setName(tr("销售金额"));
    ui->widgetCustomPlot->graph(FIVE)->setName(tr("点"));
    ui->widgetCustomPlot->graph(SIX)->setName(tr("选中点"));
}

/*********************     解析json   *********************/
void TodayHouseMoney::readJson(QNetworkReply *reply, int type)
{
    if(NULL == reply || reply->error() != QNetworkReply::NoError)
    {
        MAINWINDOW->setStatusInfo();
        return;
    }

    QString code;
    if(reply->error() == QNetworkReply::NoError)
    {
        QByteArray arrayData = reply->readAll();

        QJsonParseError err;
        QJsonDocument jsonDom = QJsonDocument::fromJson(QString(arrayData).toUtf8(), &err);

        qDebug()<<QString(arrayData);
        if(err.error == QJsonParseError::NoError)
        {
            QJsonObject jsonObject = jsonDom.object();

            if(jsonObject.contains(HTTPKEY::CODE))  code = QString::number(jsonObject.value(HTTPKEY::CODE).toInt());

            QString errorMsg;
            if(jsonObject.contains(HTTPKEY::MSG))
            {
                int codeValue = code.toInt();
                if(ISERROR(codeValue))
                {
                    if(codeValue == SUBONE)        errorMsg = MESSAGE::NOTSHOPLOGIN;
                    else if(codeValue == SUBTWO)   errorMsg = MESSAGE::NOTADMINLOGIN;
                    else if(codeValue == SUBTHREE) errorMsg = MESSAGE::NOPRIORITY;

                    if(codeValue == SUBONE || codeValue == SUBTWO || codeValue == SUBTHREE)
                    {
                        MAINWINDOW->showError(errorMsg);
                        this->setHidden(true);
                        return;
                    }
                }

                if(code.toInt() != GLOBALDEF::SUCCESSINTONE)
                {
                    reply->close();
                    return;
                }

                if(type == PROTOCOL::URL_TODAY_SEL_TODAY)
                {
                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, mapListData);

                    this->setControlData();
                }
            }
        }
        reply->close();
    }
}

/*********************     显示窗口    ********************/
void TodayHouseMoney::showWidget()
{
    this->show();
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_TODAY_SEL_TODAY), PROTOCOL::URL_TODAY_SEL_TODAY);
}

/*********************     设置控件数据    ********************/
void TodayHouseMoney::setControlData()
{
    mapCoorData[HTTPKEY::STORAGEPRICE].dataX.clear();
    mapCoorData[HTTPKEY::STORAGEPRICE].dataY.clear();

    for(int i = 0; i < mapListData.size(); i ++)
    {
        unsigned int currentTime = this->getTime(mapListData.at(i).value(HTTPKEY::TIME)) + 8 * 3600;

        mapCoorData[HTTPKEY::STORAGEPRICE].dataX.append(currentTime);
        mapCoorData[HTTPKEY::STORAGEPRICE].dataY.append(mapListData.at(i).value(HTTPKEY::STORAGEPRICE).toFloat());

        mapCoorData[HTTPKEY::PROFIT].dataX.append(currentTime);
        mapCoorData[HTTPKEY::PROFIT].dataY.append(mapListData.at(i).value(HTTPKEY::PROFIT).toFloat());

        mapCoorData[HTTPKEY::MATERIALPRICE].dataX.append(currentTime);
        mapCoorData[HTTPKEY::MATERIALPRICE].dataY.append(mapListData.at(i).value(HTTPKEY::MATERIALPRICE).toFloat());

        mapCoorData[HTTPKEY::RETURNSPRICE].dataX.append(currentTime);
        mapCoorData[HTTPKEY::RETURNSPRICE].dataY.append(mapListData.at(i).value(HTTPKEY::RETURNSPRICE).toFloat());

        mapCoorData[HTTPKEY::MARKETPEICE].dataX.append(currentTime);
        mapCoorData[HTTPKEY::MARKETPEICE].dataY.append(mapListData.at(i).value(HTTPKEY::MARKETPEICE).toFloat());
    }

    smallPointData.dataX.append(mapCoorData[HTTPKEY::STORAGEPRICE].dataX);
    smallPointData.dataY.append(mapCoorData[HTTPKEY::STORAGEPRICE].dataY);

    smallPointData.dataX.append(mapCoorData[HTTPKEY::PROFIT].dataX);
    smallPointData.dataY.append(mapCoorData[HTTPKEY::PROFIT].dataY);

    smallPointData.dataX.append(mapCoorData[HTTPKEY::MATERIALPRICE].dataX);
    smallPointData.dataY.append(mapCoorData[HTTPKEY::MATERIALPRICE].dataY);

    smallPointData.dataX.append(mapCoorData[HTTPKEY::RETURNSPRICE].dataX);
    smallPointData.dataY.append(mapCoorData[HTTPKEY::RETURNSPRICE].dataY);

    smallPointData.dataX.append(mapCoorData[HTTPKEY::MARKETPEICE].dataX);
    smallPointData.dataY.append(mapCoorData[HTTPKEY::MARKETPEICE].dataY);

    if(mapListData.size() != 0)
    {


        unsigned int minValue = this->getTime(mapListData.at(ZERO).value(HTTPKEY::TIME));
        for(int i = 0; i < mapListData.size(); i ++)
        {
            QString time = mapListData.at(i).value(HTTPKEY::TIME);
            if(getTime(time) < minValue) minValue = this->getTime(time);
        }

        ui->widgetCustomPlot->xAxis->setRange(minValue, minValue + GLOBALDEF::ONEDAY * 15);

        //得到所有数据的纵坐标中的最大值和最小值， 设置上下限
        float maxYData = this->getMaxData();
        float minYData = this->getMinData();

        float incValue = maxYData == 0 ? 10 : maxYData * 0.1;
        float subValue = maxYData == 0 ? 0.3 : maxYData * 0.1;

        ui->widgetCustomPlot->yAxis->setRange(minYData - subValue, maxYData + incValue);
    }

    ui->widgetCustomPlot->graph(ZERO)->setData(mapCoorData[HTTPKEY::STORAGEPRICE].dataX, mapCoorData[HTTPKEY::STORAGEPRICE].dataY);
    ui->widgetCustomPlot->graph(ONE)->setData(mapCoorData[HTTPKEY::PROFIT].dataX, mapCoorData[HTTPKEY::PROFIT].dataY);
    ui->widgetCustomPlot->graph(TWO)->setData(mapCoorData[HTTPKEY::MATERIALPRICE].dataX, mapCoorData[HTTPKEY::MATERIALPRICE].dataY);
    ui->widgetCustomPlot->graph(THREE)->setData(mapCoorData[HTTPKEY::RETURNSPRICE].dataX, mapCoorData[HTTPKEY::RETURNSPRICE].dataY);
    ui->widgetCustomPlot->graph(FOUR)->setData(mapCoorData[HTTPKEY::MARKETPEICE].dataX, mapCoorData[HTTPKEY::MARKETPEICE].dataY);
    ui->widgetCustomPlot->graph(FIVE)->setData(smallPointData.dataX, smallPointData.dataY);

    ui->widgetCustomPlot->replot();
}

/*********************     获取最大值    ********************/
float TodayHouseMoney::getMaxData()
{
    QList<float>stoPriceList;
    QList<float>profitList;
    QList<float>matPriceList;
    QList<float>retPriceList;
    QList<float>marPriceList;
    QList<float>maxDataList;

    for(int i = 0; i < mapListData.size(); i ++)
    {
        stoPriceList.append(mapListData.at(i).value(HTTPKEY::STORAGEPRICE).toFloat());
        profitList.append(mapListData.at(i).value(HTTPKEY::PROFIT).toFloat());
        matPriceList.append(mapListData.at(i).value(HTTPKEY::MATERIALPRICE).toFloat());
        retPriceList.append(mapListData.at(i).value(HTTPKEY::RETURNSPRICE).toFloat());
        marPriceList.append(mapListData.at(i).value(HTTPKEY::MARKETPEICE).toFloat());
    }

    maxDataList.append(getMaxData(stoPriceList));
    maxDataList.append(getMaxData(profitList));
    maxDataList.append(getMaxData(matPriceList));
    maxDataList.append(getMaxData(retPriceList));
    maxDataList.append(getMaxData(marPriceList));

    return getMaxData(maxDataList);
}

/*********************     获取列表最大值     ********************/
float TodayHouseMoney::getMaxData(QList<float> listData)
{
    float dataMax = 0;
    if(listData.size() != 0)
    {
        dataMax = listData.at(ZERO);
        for(int i = 0; i < listData.size(); i ++)
        {
            if(listData.at(i) > dataMax) dataMax = listData.at(i);
        }
    }

    return dataMax;
}

/*********************     获取最小值    ********************/
float TodayHouseMoney::getMinData()
{
    QList<float>stoPriceList;
    QList<float>profitList;
    QList<float>matPriceList;
    QList<float>retPriceList;
    QList<float>marPriceList;
    QList<float>minDataList;

    for(int i = 0; i < mapListData.size(); i ++)
    {
        stoPriceList.append(mapListData.at(i).value(HTTPKEY::STORAGEPRICE).toFloat());
        profitList.append(mapListData.at(i).value(HTTPKEY::PROFIT).toFloat());
        matPriceList.append(mapListData.at(i).value(HTTPKEY::MATERIALPRICE).toFloat());
        retPriceList.append(mapListData.at(i).value(HTTPKEY::RETURNSPRICE).toFloat());
        marPriceList.append(mapListData.at(i).value(HTTPKEY::MARKETPEICE).toFloat());
    }

    minDataList.append(getMinData(stoPriceList));
    minDataList.append(getMinData(profitList));
    minDataList.append(getMinData(matPriceList));
    minDataList.append(getMinData(retPriceList));
    minDataList.append(getMinData(marPriceList));

    return getMinData(minDataList);
}

/*********************     获取最小值    ********************/
float TodayHouseMoney::getMinData(QList<float> listData)
{
    float dataMin = 0;
    if(listData.size() != 0)
    {
        dataMin = listData.at(ZERO);
        for(int i = 0; i < listData.size(); i ++)
        {
            if(listData.at(i) < dataMin) dataMin = listData.at(i);
        }
    }

    return dataMin;
}

/*********************     获取时间    ********************/
unsigned int TodayHouseMoney::getTime(QString timeText)
{
    return QDateTime::fromString(timeText, "yyyy-MM-dd").toTime_t();
}

/*********************     鼠标移动    ********************/
bool TodayHouseMoney::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->widgetCustomPlot && event->type() == QEvent::MouseMove)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        int xPos = mouseEvent->pos().x();
        int yPos = mouseEvent->pos().y();

        float xValue = ui->widgetCustomPlot->xAxis->pixelToCoord(xPos);
        float yValue = ui->widgetCustomPlot->yAxis->pixelToCoord(yPos);

        QPoint pointMatch = matchPoint(QPoint(xValue, yValue));

        if(pointMatch.x() != 0)
        {
            bigPointData.dataX.clear();
            bigPointData.dataY.clear();

            if(currentIndex >= 0 && currentIndex < mapCoorData[HTTPKEY::STORAGEPRICE].dataX.size())
            {
                bigPointData.dataX.append(mapCoorData[HTTPKEY::STORAGEPRICE].dataX.at(currentIndex));
                bigPointData.dataY.append(mapCoorData[HTTPKEY::STORAGEPRICE].dataY.at(currentIndex));

                bigPointData.dataX.append(mapCoorData[HTTPKEY::PROFIT].dataX.at(currentIndex));
                bigPointData.dataY.append(mapCoorData[HTTPKEY::PROFIT].dataY.at(currentIndex));

                bigPointData.dataX.append(mapCoorData[HTTPKEY::MATERIALPRICE].dataX.at(currentIndex));
                bigPointData.dataY.append(mapCoorData[HTTPKEY::MATERIALPRICE].dataY.at(currentIndex));

                bigPointData.dataX.append(mapCoorData[HTTPKEY::RETURNSPRICE].dataX.at(currentIndex));
                bigPointData.dataY.append(mapCoorData[HTTPKEY::RETURNSPRICE].dataY.at(currentIndex));

                bigPointData.dataX.append(mapCoorData[HTTPKEY::MARKETPEICE].dataX.at(currentIndex));
                bigPointData.dataY.append(mapCoorData[HTTPKEY::MARKETPEICE].dataY.at(currentIndex));
            }

            ui->widgetCustomPlot->graph(SIX)->setData(bigPointData.dataX, bigPointData.dataY);
        }

        ui->widgetCustomPlot->replot();
    }
    if(watched == ui->widgetCustomPlot && event->type() == QEvent::Wheel)
    {
        //滚动鼠标缩小最多缩小三倍，防止缩小太多，卡死
        QWheelEvent *wheelEvent = static_cast<QWheelEvent*>(event);

        if(wheelEvent->delta() < 0)
        {
            double balanceValue = ui->widgetCustomPlot->xAxis->range().upper - ui->widgetCustomPlot->xAxis->range().lower;
            if(balanceValue / GLOBALDEF::ONEDAY >= 45)
            {
                ui->widgetCustomPlot->xAxis->setRange(xLower, xUpper);
                ui->widgetCustomPlot->yAxis->setRange(yLower, yUpper);
            }
            else
            {
                xUpper =  ui->widgetCustomPlot->xAxis->range().upper;
                xLower =  ui->widgetCustomPlot->xAxis->range().lower;
                yUpper =  ui->widgetCustomPlot->yAxis->range().upper;
                yLower =  ui->widgetCustomPlot->yAxis->range().lower;
            }
        }
    }

    return QWidget::eventFilter(watched, event);
}


/*********************     匹配点算法    ********************/
QPoint TodayHouseMoney::matchPoint(QPoint point)
{
    /******************************************
     * 思路：
     * 鼠标当前的点与实际坐标相比较，
     * 离哪个点比较近，返回当前比较近的点的坐标
     * *****************************************/

    QList<QPoint> pointList;
    QList<float> compareompareList;
    QList<int> indexList;
    for(int i = 0; i < mapCoorData[HTTPKEY::STORAGEPRICE].dataX.size(); i ++)
    {
        float diffValue = point.x() - mapCoorData[HTTPKEY::STORAGEPRICE].dataX.at(i);
        if(diffValue > -1 * GLOBALDEF::ONEDAY && diffValue < GLOBALDEF::ONEDAY)
        {
            pointList.append(QPoint(mapCoorData[HTTPKEY::STORAGEPRICE].dataX.at(i), mapCoorData[HTTPKEY::STORAGEPRICE].dataY.at(i)));

            compareompareList.append(std::abs(mapCoorData[HTTPKEY::STORAGEPRICE].dataX.at(i) - point.x()));

            indexList.append(i);
        }
    }

    if(compareompareList.size() != 0)
    {
        int minIndex = 0;
        float minValoe = compareompareList.at(0);
        for(int i = 0; i < compareompareList.size(); i ++)
        {
            if(compareompareList.at(i) < minValoe)
            {
                minValoe = compareompareList.at(i);
                minIndex = i;
            }
        }

        if(minIndex < mapListData.size())
        {
            int index = indexList.at(minIndex);
            ui->labelStorageMoney->setText(QString::number(mapListData.at(index).value(HTTPKEY::STORAGEPRICE).toFloat(), 'f', 2) + tr("元"));
            ui->labelProfitMoney->setText(QString::number(mapListData.at(index).value(HTTPKEY::PROFIT).toFloat(), 'f', 2) + tr("元"));
            ui->labelRealMoney->setText(QString::number(mapListData.at(index).value(HTTPKEY::MATERIALPRICE).toFloat(), 'f', 2) + tr("元"));
            ui->labelReturnsMoney->setText(QString::number(mapListData.at(index).value(HTTPKEY::RETURNSPRICE).toFloat(), 'f', 2) + tr("元"));
            ui->labelPurchaseMoney->setText(QString::number(mapListData.at(index).value(HTTPKEY::MARKETPEICE).toFloat(), 'f', 2) + tr("元"));
        }

        for(int i = 0; i < mapCoorData[HTTPKEY::STORAGEPRICE].dataX.size(); i ++)
        {
            if(pointList.at(minIndex).x() == mapCoorData[HTTPKEY::STORAGEPRICE].dataX.at(i))
            {
                currentIndex = i;
            }
        }

        return pointList.at(minIndex);
    }

    currentIndex = - 1;
    return QPoint(0, 0);
}
