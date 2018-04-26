#include "materialsupplier.h"
#include "ui_materialsupplier.h"
#include "messagebox/messagedialog.h"
#include "httpclient/httpkey.h"

/************************   构造函数         ********************/
MaterialSupplier::MaterialSupplier(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MaterialSupplier)
{
    ui->setupUi(this);

    this->initControl();
}

/************************   析构函数         ********************/
MaterialSupplier::~MaterialSupplier()
{
    delete ui;
}

/************************   显示窗口         ********************/
void MaterialSupplier::showWidget()
{
    this->show();
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_DEFAULT_SEL), PROTOCOL::URL_DEFAULT_SEL);
}

/*********************  解析json       *********************/
void MaterialSupplier::readJson(QNetworkReply *reply, int type)
{
    if(NULL == reply || reply->error() != QNetworkReply::NoError)
    {
        MAINWINDOW->setStatusInfo();
        return;
    }

    int codeValue = -1;
    if(reply->error() == QNetworkReply::NoError)
    {
        QByteArray arrayData = reply->readAll();

        QJsonParseError err;
        QJsonDocument jsonDom = QJsonDocument::fromJson(QString(arrayData).toUtf8(), &err);

        qDebug()<<QString(arrayData);
        if(err.error == QJsonParseError::NoError)
        {
            QJsonObject jsonObject = jsonDom.object();

            if(jsonObject.contains(HTTPKEY::CODE))  codeValue = jsonObject.value(HTTPKEY::CODE).toInt();

            QString errorMsg;
            if(jsonObject.contains(HTTPKEY::MSG))
            {
                if(ISERROR(codeValue))
                {
                    if(codeValue == SUBONE)        errorMsg = MESSAGE::NOTSHOPLOGIN;
                    else if(codeValue == SUBTWO)   errorMsg = MESSAGE::NOTADMINLOGIN;
                    else if(codeValue == SUBTHREE) errorMsg = MESSAGE::NOPRIORITY;

                    if(codeValue == SUBONE || codeValue == SUBTWO || codeValue == SUBTHREE)
                    {
                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        this->setHidden(true);
                        return;
                    }
                }

                QJsonObject jsonNextObj = jsonObject.value(HTTPKEY::MSG).toObject();

                if(type == PROTOCOL::URL_DEFAULT_SEL)
                {
                    if(ISERROR(codeValue))
                    {
                        ui->tableWidget->clearContents();
                        ui->tableWidget->setRowCount(0);
                        mapListMat.clear();
                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, mapListMat);

                    this->setControlData();
                }
                else if(type == PROTOCOL::URL_DEFAULT_GET_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    defaultMatInfo->showWidget();

                    Map mapData;
                    HTTPCLIENT->readJsonMap(jsonNextObj, HTTPKEY::MATERIAL, mapData);
                    defaultMatInfo->setMapMatData(mapData);

                    MapList mapListData;
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::SUPPLIER_LIST, mapListData);
                    defaultMatInfo->setMapListSupplier(mapListData);
                }
                else if(type == PROTOCOL::URL_DEFAULT_UPDATE_SUP)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::EDITERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;
                        else if(codeValue == THREE) errorMsg = MESSAGE::SUPNOTGIVEMAT;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    showWidget();
                }
                else if(type == PROTOCOL::URL_DEFAULT_GET_SUP)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO) errorMsg = MESSAGE::ERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    MapList mapListData;
                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, mapListData);
                    setDefaultSup->setMapListSupplier(mapListData);
                }
            }
        }
        reply->close();
    }
}

/************************   初始化控件         ********************/
void MaterialSupplier::initControl()
{
    SETTABLEWIDGET(ui->tableWidget);

    defaultMatInfo = new DefaultMatInfo(this);
    setDefaultSup = new SetDefaultSup(this);

    ui->tableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);

    //根据分辨率适配
    QDesktopWidget *desktop = QApplication::desktop();

    if(desktop->height() >= GLOBALDEF::DESKTOPHEIGHT)
    {
        this->setStyleSheet(GLOBALDEF::THISSTYLE);
    }
    else
    {
        this->setStyleSheet(GLOBALDEF::SMALLSTYLE);
    }
}

/************************   设置控件数据         ********************/
void MaterialSupplier::setControlData()
{
    ui->labelSize->setText(GLOBALDEF::TOTALONUMBER.arg(mapListMat.size()));
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(mapListMat.size());

    bool flage = CONFIGJSON->getLanguage().toInt() > 0 ? true : false;

    for(int i = 0; i < mapListMat.size(); i ++)
    {
        ui->tableWidget->setItem(i, ZERO, DATA(mapListMat.at(i).value(HTTPKEY::NAME)));
        ui->tableWidget->setItem(i, ONE,  DATA(mapListMat.at(i).value(HTTPKEY::BARCODE)));

        if(mapListMat.at(i).value(HTTPKEY::DEFAULTSUPPLIERID) == "0")
        {
            QString supName = mapListMat.at(i).value(HTTPKEY::SUPPLIERNAME);

            if(flage) supName = "Not Set";

            ui->tableWidget->setItem(i, TWO,  DATA(supName));

            ui->tableWidget->item(i, TWO)->setTextColor(Qt::darkRed);
        }
        else
        {
            ui->tableWidget->setItem(i, TWO,  DATA(mapListMat.at(i).value(HTTPKEY::SUPPLIERNAME)));
            ui->tableWidget->item(i, TWO)->setTextColor(Qt::darkGreen);
        }
        ui->tableWidget->item(i, TWO)->setFont(QFont("ZYSong", 12, QFont::Bold));

        SETTABLECENTER(ui->tableWidget->item(i, ZERO));
        SETTABLECENTER(ui->tableWidget->item(i, ONE));
        SETTABLECENTER(ui->tableWidget->item(i, TWO));
    }

    ui->tableWidget->scrollToBottom();
}

/************************   双击控件         ********************/
void MaterialSupplier::on_tableWidget_doubleClicked(const QModelIndex &index)
{
    if(index.row() >= mapListMat.size()) return;

    QString materialId = mapListMat.at(index.row()).value(HTTPKEY::MATERIALID);

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_DEFAULT_GET_MAT).arg(materialId), PROTOCOL::URL_DEFAULT_GET_MAT);
}

/************************   全选         ********************/
void MaterialSupplier::on_pushButtonAllSelect_clicked()
{
    ui->tableWidget->selectAll();
}

/************************   全不选         ********************/
void MaterialSupplier::on_pushButtonNoSelect_clicked()
{
    for(int i = 0; i < ui->tableWidget->selectedItems().size(); i++)
    {
        ui->tableWidget->selectedItems().at(i)->setSelected(false);
    }

    setControlData();
}

/************************   批量设置         ********************/
void MaterialSupplier::on_pushButtonSetUp_clicked()
{
    int rowSelectCount = ui->tableWidget->selectedItems().size() / ui->tableWidget->columnCount();

    if(rowSelectCount != 0)
    {
        int ok = MESSAGEBOX->showMessageBox(this, MESSAGE::SETSUPPLIER.arg(rowSelectCount), true, false);

        if(ok == QDialog::Accepted)
        {
            HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_DEFAULT_GET_SUP), PROTOCOL::URL_DEFAULT_GET_SUP);
            setDefaultSup->setMatNumber(QString::number(rowSelectCount));
            setDefaultSup->showWidget();

            MapList mapListData;
            for(int i = 0; i < ui->tableWidget->selectedItems().size(); i ++)
            {
                if(i % ui->tableWidget->columnCount() == 0)
                {
                    int currentIndex = ui->tableWidget->selectedItems().at(i)->row();
                    if(currentIndex >= mapListMat.size()) return;

                    Map mapData;

                    mapData[HTTPKEY::MATERIALID] = mapListMat.at(currentIndex).value(HTTPKEY::MATERIALID);
                    mapListData.append(mapData);
                }
            }

            setDefaultSup->setMapListMat(mapListData);
        }
    }
    else
    {
        MESSAGEBOX->showMessageBox(this, MESSAGE::PLEASESETSUP);
    }
}
