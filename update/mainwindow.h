#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/***************************************************************
   功能:更新客户端主类

   创建人:殷宇辰

   创建时间:2018-03-14
**************************************************************/

#include <QMainWindow>
#include "titlebar/titlebar.h"
#include <QNetworkAccessManager>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include <QNetworkReply>

class QProgressBar;
typedef QList<QMap<QString, QString>> MapList;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setExeName(const QString &value);          //设置EXE全路径

private slots:
    void on_pushButtonUpdate_clicked();             //更新按钮
    void updateProgress(qint64 bytesReceived,
                        qint64 bytesTotal);         //更新进度条

private:
    Ui::MainWindow *ui;

    TitleBar * titleBar;                            //标题栏
    void initControl();                             //初始化控件
    void resizeEvent(QResizeEvent *event);          //重置窗口大小

    void getUrlReq(const QString &urlStr,
                   QNetworkAccessManager *manager); //get请求
    void readJson(QNetworkReply *reply);            //读取JSON
    void readJsonList(QJsonObject jsonObject,
                      QString itemName,
                      MapList &mapList);            //读取JSON列表

    QList<QNetworkAccessManager*>netWorList;        //更新请求列表
    MapList downLoadMapList;                        //可更新的链接
    QNetworkAccessManager downLoadJsonManager;      //下载JSON文件
    QNetworkReply *replyDownLoad;                   //下载响应
    QFile *fileWrite;                               //文件写入
    QString exeName;                                //当前EXE全路径
    int currentIndex;                               //当前下载文件到第几个
    QString strVersion;                             //服务器上版本
    QWidget *createWidget(QString infoName);        //创建信息面板
    QList<QProgressBar*>progressBarList;            //进度条列表

    const QString PATH       = "path";
    const QString VERSION    = "version";
    const QString FILELIST   = "fileList";
    const QString CLIENTNAME = "WareHouseManageSystem.exe";
};

#endif // MAINWINDOW_H
