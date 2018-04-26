#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "globaldef.hpp"
#include <QFileInfo>
#include "qreadwrite/qreadwriteini.h"
#include <QProcess>
#include <QProgressBar>

/*********************     构造函数           *********************/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
  ,currentIndex(0)
{
    ui->setupUi(this);

    this->initControl();
}

/*********************     析构函数           *********************/
MainWindow::~MainWindow()
{
    delete ui;
}

/*********************     初始化控件         *********************/
void MainWindow::initControl()
{
    titleBar = new TitleBar(this);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::FramelessWindowHint);

    titleBar->setBackGround();

    connect(&downLoadJsonManager, &QNetworkAccessManager::finished, this, readJson);

    QNetworkRequest request;

    request.setUrl(QUrl(GLOBALDEF::STANDARDJSONPATH));

    downLoadJsonManager.get(request);
}

/*********************     改变事件           *********************/
void MainWindow::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************     更新客户端          *********************/
void MainWindow::on_pushButtonUpdate_clicked()
{
    if(ui->pushButtonUpdate->text() == tr("更新中...")) return;

    if(ui->pushButtonUpdate->text() != tr("更新"))
    {
        this->close();

        QStringList strList = this->exeName.split('\\');
        QString updatePath = this->exeName.remove(strList.last()) + CLIENTNAME;

        QProcess process;
        process.startDetached(updatePath, QStringList());
    }
    else if(ui->pushButtonUpdate->text() == tr("更新"))
    {
        if(currentIndex >= 0 && currentIndex < downLoadMapList.size())
        {
            QFileInfo fileInfo = downLoadMapList.at(currentIndex).value(PATH);
            fileWrite = new QFile(fileInfo.fileName());

            if(!fileWrite->open(QIODevice::WriteOnly)) return;

            ui->pushButtonUpdate->setText(tr("更新中..."));
            titleBar->subButton(TITLEBAR::ALLWIDGET);

            if(currentIndex < netWorList.size())
            {
                this->getUrlReq(downLoadMapList.at(currentIndex).value(PATH), netWorList[currentIndex]);
            }
        }
    }
}

/*********************     更新进度条          *********************/
void MainWindow::updateProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    if(NULL == replyDownLoad || replyDownLoad->error() != QNetworkReply::NoError)
    {
        return;
    }

    if(currentIndex >= 0 && currentIndex < progressBarList.size())
    {
        progressBarList.at(currentIndex)->setMaximum(bytesTotal);
        progressBarList.at(currentIndex)->setValue(bytesReceived);
    }


    if(replyDownLoad->error() == QNetworkReply::NoError)
    {
        QByteArray arrayData = replyDownLoad->readAll();

        if(NULL != fileWrite) fileWrite->write(arrayData);

        if(bytesReceived == bytesTotal)
        {
            currentIndex ++;

            if(NULL != fileWrite) fileWrite->close();

            if(currentIndex >= 0 && currentIndex < downLoadMapList.size())
            {
                QFileInfo fileInfo = downLoadMapList.at(currentIndex).value(PATH);

                if(NULL == fileWrite) fileWrite = new QFile(fileInfo.fileName());

                fileWrite->setFileName(fileInfo.fileName());

                if(!fileWrite->open(QIODevice::WriteOnly)) return;

                if(currentIndex < netWorList.size())
                {
                    this->getUrlReq(downLoadMapList.at(currentIndex).value(PATH), netWorList[currentIndex]);
                }
            }
            else
            {
                ui->pushButtonUpdate->setText(tr("完成，点击重启"));
                ui->labelInfo->setText(tr("当前版本为最新版本！"));
                CONFIGINI->writeVersion(strVersion);
            }
        }
    }
}

/*********************     get请求            *********************/
void MainWindow::getUrlReq(const QString &urlStr, QNetworkAccessManager* manager)
{
    QNetworkRequest request;

    request.setUrl(QUrl(urlStr));

    replyDownLoad = manager->get(request);

    connect(replyDownLoad, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(updateProgress(qint64, qint64)));
}

/*********************     解析json           *********************/
void MainWindow::readJson(QNetworkReply *reply)
{
    if(NULL == reply || reply->error() != QNetworkReply::NoError)
    {
        ui->labelInfo->setText(tr("网络连接失败！"));
        ui->pushButtonUpdate->setHidden(true);
        return;
    }

    if(reply->error() == QNetworkReply::NoError)
    {
        QByteArray arrayData = reply->readAll();

        QJsonParseError err;
        QJsonDocument jsonDom = QJsonDocument::fromJson(QString(arrayData).toUtf8(), &err);

        if(err.error == QJsonParseError::NoError)
        {
            netWorList.clear();

            QJsonObject jsonObject = jsonDom.object();

            strVersion = jsonObject.value(VERSION).toString();



            this->readJsonList(jsonObject, FILELIST, downLoadMapList);

            progressBarList.clear();
            ui->listWidgetData->clear();
            {
                QListWidgetItem *lisItem = new QListWidgetItem(ui->listWidgetData);
                lisItem->setText(tr("更新列表"));
                lisItem->setSizeHint(QSize(0, 40));
                lisItem->setFont(QFont("ZYSong", 12, QFont::Bold));
                lisItem->setBackgroundColor(QColor(70, 130, 180, 30));
                lisItem->setTextAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
            }

            if(strVersion.toDouble() > CONFIGINI->getVersion().toDouble())
            {
                ui->labelInfo->setText(tr("当前版本为%1, 可更新！").arg(CONFIGINI->getVersion()));
                ui->pushButtonUpdate->show();
            }
            else
            {
                ui->labelInfo->setText(tr("当前版本为最新版本！"));
                ui->pushButtonUpdate->setHidden(true);
                return;
            }

            for(int i = 0; i < downLoadMapList.size(); i ++)
            {
                QNetworkAccessManager *manager =  new QNetworkAccessManager(this);

                netWorList.append(manager);

                QStringList strList = downLoadMapList.at(i).value(PATH).split('/');

                QWidget *widget = createWidget(strList.last());
                QListWidgetItem *lisItem = new QListWidgetItem(ui->listWidgetData);

                lisItem->setSizeHint(QSize(0, 70));

                ui->listWidgetData->addItem(lisItem);

                ui->listWidgetData->setItemWidget(lisItem, widget);
            }
        }
    }

    reply->close();

}

/*********************     读取JSon列表        *********************/
void MainWindow::readJsonList(QJsonObject jsonObject, QString itemName, MapList &mapList)
{
    if(jsonObject.contains(itemName))
    {
        mapList.clear();

        QJsonValue jsonValue = jsonObject.value(itemName);
        QJsonArray jsonArray = jsonValue.toArray();

        for(int i = 0; i < jsonArray.size(); i ++)
        {
            QMap<QString, QString>mapData;

            QJsonObject objectItem = jsonArray.at(i).toObject();
            QStringList stringList = objectItem.keys();

            for(int i = 0; i < stringList.size(); i ++)
            {
                if(!objectItem[stringList[i]].isNull())
                {
                    if(objectItem[stringList[i]].isString())
                    {
                        mapData[stringList[i]] = objectItem[stringList[i]].toString();
                    }
                    else if(objectItem[stringList[i]].isDouble())
                    {
                        mapData[stringList[i]] = QString::number(objectItem[stringList[i]].toDouble());
                    }
                    else
                    {
                        mapData[stringList[i]] = QString::number(objectItem[stringList[i]].toInt());
                    }
                }
            }

            mapList.append(mapData);
        }
    }
}

/*********************     设置软件名称         *********************/
void MainWindow::setExeName(const QString &value)
{
    exeName = value;
}

/*********************  创建信息面板       *********************/
QWidget *MainWindow::createWidget(QString infoName)
{
    QWidget *widget = new QWidget(this);

    QHBoxLayout *hBoxLayout = new QHBoxLayout(widget);
    QProgressBar *progressBar = new QProgressBar(this);

    progressBarList.append(progressBar);
    QLabel *labelName = new QLabel(this);

    labelName->setText(infoName);
    progressBar->setMaximumHeight(20);
    progressBar->setMinimumWidth(220);
    progressBar->setMaximumWidth(220);

    hBoxLayout->addWidget(labelName);
    hBoxLayout->addWidget(progressBar);

    return widget;
}
