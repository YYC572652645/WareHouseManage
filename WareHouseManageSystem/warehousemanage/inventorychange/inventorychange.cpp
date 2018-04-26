#include "inventorychange.h"
#include "ui_inventorychange.h"
#include <QListView>
#include "httpclient/httpkey.h"
#include "messagebox/messagedialog.h"

/*********************  构造函数        *********************/
InventoryChange::InventoryChange(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InventoryChange)
{
    ui->setupUi(this);

    this->initControl();
}

/*********************  析构函数        *********************/
InventoryChange::~InventoryChange()
{
    delete ui;
}

/*********************  显示窗口        *********************/
void InventoryChange::showWidget()
{
    this->show();
    ui->dateEditStartTime->setDate(QDate::currentDate());
    ui->dateEditEndTime->setDate(QDate::currentDate());

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_CHANCE_SEL_MAT), PROTOCOL::URL_CHANCE_SEL_MAT);
}

/*********************  初始化控件        *********************/
void InventoryChange::initControl()
{
    inventoryLog = new InventoryLog(this);
    exportEmail = new ExportEmail(this);
    ui->comboBoxTime->setView(new QListView());
    ui->comboBoxWareHouse->setView(new QListView());
    ui->pushButtonExport->setHidden(true);

    ui->comboBoxTime->view()->setMinimumWidth(200);
    ui->comboBoxWareHouse->view()->setMinimumWidth(200);

    ui->comboBoxTime->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxWareHouse->setFocusPolicy(Qt::NoFocus);

    ui->dateEditEndTime->setCalendarPopup(true);
    ui->dateEditStartTime->setCalendarPopup(true);

    SETTABLEWIDGET(ui->tableWidgetData);

    ui->labelStart->setHidden(true);
    ui->labelEnd->setHidden(true);
    ui->dateEditEndTime->setHidden(true);
    ui->dateEditStartTime->setHidden(true);

    if(CONFIGJSON->getLanguage().toInt())
    {
        ui->dateEditEndTime->calendarWidget()->setLocale(QLocale(QLocale::English));
        ui->dateEditStartTime->calendarWidget()->setLocale(QLocale(QLocale::English));
    }

    connect(exportEmail, SIGNAL(sendEmail(QString)), this, SLOT(receiveEmail(QString)));


    //根据分辨率适配
    QDesktopWidget *desktop = QApplication::desktop();

    int minHeight = 0;
    if(desktop->height() >= GLOBALDEF::DESKTOPHEIGHT)
    {
        minHeight = 30;
        this->setStyleSheet(GLOBALDEF::THISSTYLE);
    }
    else
    {
        minHeight = 20;
        this->setStyleSheet(GLOBALDEF::SMALLSTYLE);
    }

    ui->labelWshe->setMinimumHeight(minHeight);
    ui->labelTime->setMinimumHeight(minHeight);
    ui->labelStart->setMinimumHeight(minHeight);
    ui->labelEnd->setMinimumHeight(minHeight);
    ui->labelSelect->setMinimumHeight(minHeight);

    FlowLayout *flowLayout = new FlowLayout(ui->widgetControl);

    flowLayout->addWidget(ui->labelWshe);
    flowLayout->addWidget(ui->comboBoxWareHouse);
    flowLayout->addWidget(ui->labelTime);
    flowLayout->addWidget(ui->comboBoxTime);
    flowLayout->addWidget(ui->labelStart);
    flowLayout->addWidget(ui->dateEditStartTime);
    flowLayout->addWidget(ui->labelEnd);
    flowLayout->addWidget(ui->dateEditEndTime);
    flowLayout->addWidget(ui->labelSelect);
    flowLayout->addWidget(ui->lineEditCondition);
    flowLayout->addWidget(ui->pushButtonSelect);
    flowLayout->addWidget(ui->pushButtonExport);

    ui->widgetControl->setLayout(flowLayout);
}

/*********************  设置表格数据       *********************/
void InventoryChange::setTableData()
{
    ui->tableWidgetData->setRowCount(matMapList.size());

    for(int i = 0; i < matMapList.size(); i ++)
    {
        ui->tableWidgetData->setItem(i, ZERO, DATA(matMapList.at(i).value(HTTPKEY::NAME)));
        ui->tableWidgetData->setItem(i, ONE,  DATA(matMapList.at(i).value(HTTPKEY::BARCODE)));

        SETTABLECENTER(ui->tableWidgetData->item(i, ZERO));
        SETTABLECENTER(ui->tableWidgetData->item(i, ONE));
    }

    ui->tableWidgetData->scrollToBottom();
}

/*********************  设置控件数据       *********************/
void InventoryChange::setControlData()
{
    ui->comboBoxWareHouse->clear();

    for(int i = 0; i < wareHouseMapList.size(); i ++)
    {
        ui->comboBoxWareHouse->addItem(wareHouseMapList.at(i).value(HTTPKEY::NAME));
    }
    ui->comboBoxWareHouse->addItem(tr("全部"));

    ui->comboBoxTime->clear();

    for(int i = 0; i < timeMapList.size(); i ++)
    {
        QString timeName = timeMapList.at(i).value(HTTPKEY::NAME);

        if(CONFIGJSON->getLanguage().toInt())
        {
            if(timeName == GLOBALDEF::CHIYESTERDAY) timeName = GLOBALDEF::ENGYESTERDAY;
            else if(timeName == GLOBALDEF::CHITODAY)     timeName = GLOBALDEF::ENGTODAY;
            else if(timeName == GLOBALDEF::CHITHISWEEK)  timeName = GLOBALDEF::ENGTHISWEEK;
            else if(timeName == GLOBALDEF::CHILASTWEEK)  timeName = GLOBALDEF::ENGLASTWEEK;
            else if(timeName == GLOBALDEF::CHITHISMONTH) timeName = GLOBALDEF::ENGTHISMONTH;
            else if(timeName == GLOBALDEF::CHILASTMONTH) timeName = GLOBALDEF::ENGLASTMONTH;
            else if(timeName == GLOBALDEF::CHICUSTOMIZE) timeName = GLOBALDEF::ENGCUSTOMIZE;
        }

        ui->comboBoxTime->addItem(timeName);
    }
}

/*********************  解析json       *********************/
void InventoryChange::readJson(QNetworkReply *reply, int type)
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

                if(type == PROTOCOL::URL_CHANCE_SEL_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        ui->tableWidgetData->clearContents();
                        ui->tableWidgetData->setRowCount(0);
                        matMapList.clear();
                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::WAREHOUSE, wareHouseMapList);
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::DATE, timeMapList);

                    this->setControlData();
                }
                else if(type == PROTOCOL::URL_CHANCE_MAT_LIST)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    matMapList.clear();

                    HTTPCLIENT->readJsonMap(jsonObject, HTTPKEY::MSG, mapChangeData);

                    Map mapMaData;
                    HTTPCLIENT->readJsonMap(jsonNextObj, HTTPKEY::MATERIAL, mapMaData);

                    QJsonObject jsonNextNextObject = jsonNextObj.value(HTTPKEY::MATERIAL).toObject();

                    for(auto iter = mapMaData.begin(); iter != mapMaData.end(); iter ++)
                    {
                        Map mapData;

                        HTTPCLIENT->readJsonMap(jsonNextNextObject, iter.key(), mapData);

                        matMapList.append(mapData);
                    }

                    this->setTableData();
                }
                else if(type == PROTOCOL::URL_CHANCE_ALL_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    Map mapMaData;
                    HTTPCLIENT->readJsonMap(jsonNextObj, HTTPKEY::MATERIAL, mapMaData);
                    inventoryLog->setMapData(mapMaData);

                    QJsonValue jsonValue = jsonNextObj.value(HTTPKEY::TIME);
                    QJsonArray jsonArray = jsonValue.toArray();
                    List listData;
                    for(int i = 0; i < jsonArray.size(); i ++)
                    {
                        listData.append(jsonArray.at(i).toString());
                    }
                    inventoryLog->setListData(listData);


                    MapList mapListData;
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::ORDER, mapListData);
                    inventoryLog->setOrderMapList(mapListData);

                    inventoryLog->setControlData();
                    inventoryLog->showWidget();
                }
                else if(type == PROTOCOL::URL_CHANCE_GET_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(inventoryLog, errorMsg);
                        return;
                    }

                    Map mapData;
                    HTTPCLIENT->readJsonMap(jsonObject, HTTPKEY::MSG, mapData);
                    inventoryLog->getInventoryDet()->setMapData(mapData);
                    inventoryLog->getInventoryDet()->setControlData();
                    inventoryLog->getInventoryDet()->show();
                }
                else if(type == PROTOCOL::URL_CHANCE_EXTEND)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::EXTENDERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }
                    MESSAGEBOX->showMessageBox(inventoryLog, GLOBALDEF::EXPORTSUCCESS, true);
                }
            }
        }
        reply->close();
    }
}

/*********************  下拉框数据改变        *********************/
void InventoryChange::on_comboBoxTime_currentIndexChanged(const QString &arg1)
{
    if(arg1 == tr("自定义"))
    {
        ui->labelStart->show();
        ui->labelEnd->show();
        ui->dateEditEndTime->show();
        ui->dateEditStartTime->show();
    }
    else
    {
        ui->labelStart->setHidden(true);
        ui->labelEnd->setHidden(true);
        ui->dateEditEndTime->setHidden(true);
        ui->dateEditStartTime->setHidden(true);
    }
}

/*********************  查询        *********************/
void InventoryChange::on_pushButtonSelect_clicked()
{
    QString wareHouseId;
    QString time;
    if(ui->comboBoxWareHouse->currentIndex() >= wareHouseMapList.size())
    {
        wareHouseId = "0";
    }
    else
    {
        wareHouseId = wareHouseMapList.at(ui->comboBoxWareHouse->currentIndex()).value(HTTPKEY::WAREHOUSEID);
    }

    if(ui->comboBoxTime->currentText() != tr("自定义"))
    {
        time = timeMapList.at(ui->comboBoxTime->currentIndex()).value(HTTPKEY::TIME);
    }
    else
    {
        if(ui->dateEditStartTime->dateTime().toTime_t() > ui->dateEditEndTime->dateTime().toTime_t())
        {
            MESSAGEBOX->showMessageBox(this, MESSAGE::STARTNOTEND);
            return;
        }

        time = QString::number(ui->dateEditStartTime->dateTime().toTime_t()) + ",";
        time += QString::number(ui->dateEditEndTime->dateTime().toTime_t());
    }

    QString material = ui->lineEditCondition->text();

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_CHANCE_MAT_LIST).arg(wareHouseId, time, material), PROTOCOL::URL_CHANCE_MAT_LIST);
}

/*********************  导出        *********************/
void InventoryChange::on_pushButtonExport_clicked()
{
    exportEmail->showWidget();
}

/*********************  双击控件        *********************/
void InventoryChange::on_tableWidgetData_doubleClicked(const QModelIndex &index)
{
    if(index.row() < 0  || index.row() >= matMapList.size()) return;

    QString wareHouseId = mapChangeData.value(HTTPKEY::WAREHOUSEID);
    QString time = mapChangeData.value(HTTPKEY::TIME);
    QString materialId = matMapList.at(index.row()).value(HTTPKEY::MATERIALID);

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_CHANCE_ALL_MAT).arg(wareHouseId, time, materialId), PROTOCOL::URL_CHANCE_ALL_MAT);
}

/*********************  接收邮件        *********************/
void InventoryChange::receiveEmail(QString emailText)
{
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_CHANCE_EXTEND), PROTOCOL::URL_CHANCE_EXTEND);
}
