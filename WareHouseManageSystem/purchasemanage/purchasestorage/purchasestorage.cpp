#include "purchasestorage.h"
#include "ui_purchasestorage.h"
#include "messagebox/messagedialog.h"
#include "httpclient/httpkey.h"

/*********************  构造函数       *********************/
PurchaseStorage::PurchaseStorage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::purchasestorage)
  ,addStoMaterial(NULL),
    editStoMaterial(NULL), materialStoInfo(NULL)
  ,showType(SHOWSUCCESS), slectFlage(false), saveFlage(false), selectType(true)
{
    ui->setupUi(this);

    this->initControl();
}

/*********************  析构函数       *********************/
PurchaseStorage::~PurchaseStorage()
{
    delete ui;
}

/*********************  显示窗口       *********************/
void PurchaseStorage::showWidget()
{
    slectFlage = false;
    ui->pushButtonAdd->show();
    ui->pushButtonExtend->show();
    ui->pushButtonDel->show();
    ui->labelState->show();
    ui->comboBoxStateSelect->show();
    ui->labelSupplier->show();
    ui->comboBoxSupSelect->show();
    ui->labelWareHouse->show();
    ui->comboBoxWareHouseSelect->show();
    ui->labelTime->show();
    ui->comboBoxTimeSelect->show();
    ui->pushButtonSelect->show();
    ui->labelSize->show();

    ui->tabWidgetPurchase->setHidden(true);
    ui->pushButtonClose->setHidden(true);
    ui->labelEndTime->setHidden(true);
    ui->labelStartTime->setHidden(true);
    ui->dateEditEndTime->setHidden(true);
    ui->dateEditStartTime->setHidden(true);
    this->show();
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STO_SEL), PROTOCOL::URL_STO_SEL);
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STO_SELECT_PAGE), PROTOCOL::URL_STO_SELECT_PAGE);
}

/*********************  初始化控件       *********************/
void PurchaseStorage::initControl()
{
    SETTABLEWIDGET(ui->tableWidgetPur);
    SETTABLEWIDGET(ui->tableWidgetPurInfo);

    ui->tabWidgetPurchase->setHidden(true);
    ui->dateEditArriveTimeInfo->setCalendarPopup(true);
    ui->dateEditArriveTime->setCalendarPopup(true);
    ui->dateEditStartTime->setCalendarPopup(true);
    ui->dateEditEndTime->setCalendarPopup(true);
    ui->dateEditStartTime->setDate(QDate::currentDate());
    ui->dateEditEndTime->setDate(QDate::currentDate());

    ui->comboBoxPurWarHseInfo->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxPurWarHse->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxSupplier->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxStateSelect->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxSupSelect->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxTimeSelect->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxWareHouseSelect->setFocusPolicy(Qt::NoFocus);
    ui->dateEditArriveTimeInfo->setFocusPolicy(Qt::NoFocus);
    ui->dateEditStartTime->setFocusPolicy(Qt::NoFocus);
    ui->dateEditEndTime->setFocusPolicy(Qt::NoFocus);

    ui->comboBoxPurWarHseInfo->setView(new QListView());
    ui->comboBoxPurWarHse->setView(new QListView());
    ui->comboBoxSupplier->setView(new QListView());
    ui->comboBoxSupSelect->setView(new QListView());
    ui->comboBoxTimeSelect->setView(new QListView());
    ui->comboBoxWareHouseSelect->setView(new QListView());
    ui->comboBoxStateSelect->setView(new QListView());

    ui->comboBoxSupSelect->view()->setMinimumWidth(200);
    ui->comboBoxTimeSelect->view()->setMinimumWidth(200);
    ui->comboBoxWareHouseSelect->view()->setMinimumWidth(200);
    ui->comboBoxStateSelect->view()->setMinimumWidth(200);

    addStoMaterial = new AddStoMaterial(this);
    editStoMaterial = new AddStoMaterial(this);
    materialStoInfo = new MaterialStoInfo(this);
    importAllHistory = new ImportAllHistory(this);
    extendStorage = new ExtendStorage(this);
    refuseWidget = new RefuseWidget(this);
    startReceive = new StartReceive(this);
    logInfo = new LogInfo(this);


    if(CONFIGJSON->getLanguage().toInt())
    {
        ui->dateEditStartTime->calendarWidget()->setLocale(QLocale(QLocale::English));
        ui->dateEditEndTime->calendarWidget()->setLocale(QLocale(QLocale::English));
        ui->dateEditArriveTime->calendarWidget()->setLocale(QLocale(QLocale::English));
        ui->dateEditArriveTimeInfo->calendarWidget()->setLocale(QLocale(QLocale::English));
    }

    //根据分辨率适配
    QDesktopWidget *desktop = QApplication::desktop();

    int minHeight = 0;
    if(desktop->height() >= GLOBALDEF::DESKTOPHEIGHT)
    {
        minHeight = 30;

        ui->tabPurInfo->layout()->setSpacing(6);
        this->setStyleSheet(GLOBALDEF::THISSTYLE);
    }
    else
    {
        minHeight = 20;

        this->setStyleSheet(GLOBALDEF::SMALLSTYLE);
    }

    ui->labelState->setMinimumHeight(minHeight);
    ui->labelWareHouse->setMinimumHeight(minHeight);
    ui->labelSupplier->setMinimumHeight(minHeight);
    ui->labelTime->setMinimumHeight(minHeight);
    ui->labelStartTime->setMinimumHeight(minHeight);
    ui->labelEndTime->setMinimumHeight(minHeight);
    ui->labelSize->setMinimumHeight(minHeight);


    FlowLayout *flowLayout = new FlowLayout(ui->widgetControl);

    flowLayout->addWidget(ui->pushButtonClose);
    flowLayout->addWidget(ui->labelState);
    flowLayout->addWidget(ui->comboBoxStateSelect);
    flowLayout->addWidget(ui->labelWareHouse);
    flowLayout->addWidget(ui->comboBoxWareHouseSelect);
    flowLayout->addWidget(ui->labelSupplier);
    flowLayout->addWidget(ui->comboBoxSupSelect);
    flowLayout->addWidget(ui->labelTime);
    flowLayout->addWidget(ui->comboBoxTimeSelect);
    flowLayout->addWidget(ui->labelStartTime);
    flowLayout->addWidget(ui->dateEditStartTime);
    flowLayout->addWidget(ui->labelEndTime);
    flowLayout->addWidget(ui->dateEditEndTime);
    flowLayout->addWidget(ui->pushButtonSelect);
    flowLayout->addWidget(ui->pushButtonExtend);
    flowLayout->addWidget(ui->pushButtonAdd);
    flowLayout->addWidget(ui->labelSize);

    ui->widgetControl->setLayout(flowLayout);
}

/*********************  解析json       *********************/
void PurchaseStorage::readJson(QNetworkReply *reply, int type)
{
    if(NULL == reply || reply->error() != QNetworkReply::NoError)
    {
        MAINWINDOW->setStatusInfo();
        return;
    }

    int codeValue = 0;
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

                if(type == PROTOCOL::URL_STO_SEL || type == PROTOCOL::URL_STO_SELECT)
                {
                    if(ISERROR(codeValue))
                    {
                        ui->tableWidgetPur->clearContents();
                        ui->tableWidgetPur->setRowCount(0);
                        stoMapList.clear();
                        ui->labelSize->setText(GLOBALDEF::TOTALONUMBER.arg(stoMapList.size()));

                        extendStorage->setDataMapList(stoMapList);

                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, stoMapList);

                    if(!slectFlage)
                    {
                        this->setPurTableData();
                        extendStorage->setDataMapList(stoMapList);
                    }
                    else
                    {
                        importAllHistory->setDataMapList(stoMapList);
                        slectFlage = false;
                    }
                }
                else if(type == PROTOCOL::URL_STO_SEL_DATA)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    HTTPCLIENT->readJsonMap(jsonNextObj,  HTTPKEY::STORAGEDATA, mapPurchaseInfo);
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::MATERIALLIST, stoMatMapList);
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::WAREHOUSELIST, wareHouseMapList);
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::SUPPLIERLIST, supMapList);

                    storageNumber = mapPurchaseInfo.value(HTTPKEY::STORAGENUMBER);
                    editStoMaterial->setMapData(mapPurchaseInfo);
                    editStoMaterial->setMapSelectList(stoMatMapList);

                    ui->tabWidgetPurchase->show();
                    this->setControlData();
                }
                else if(type == PROTOCOL::URL_STO_SEL_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        editStoMaterial->clearInfo();
                        addStoMaterial->clearInfo();
                        return;
                    }

                    MapList mapList;
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::MATERIALLIST, mapList);

                    addStoMaterial->setMapMatList(mapList);
                    editStoMaterial->setMapMatList(mapList);
                }
                else if(type == PROTOCOL::URL_STO_ADD_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ADDERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::ADDSUCCESS, true);
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STO_SEL_DATA).arg(storageId), PROTOCOL::URL_STO_SEL_DATA);

                    ui->tabWidgetPurchase->addTab(ui->tabPurInfo, GLOBALDEF::STORAGEINFO);
                    ui->tabWidgetPurchase->setCurrentWidget(ui->tabPurInfo);
                    ui->tabWidgetPurchase->removeTab(ui->tabWidgetPurchase->indexOf(ui->tabAddSto));
                    ui->tabWidgetPurchase->show();
                }
                else if(type == PROTOCOL::URL_STO_GET_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    materialStoInfo->showWidget();

                    Map mapData;
                    HTTPCLIENT->readJsonMap(jsonNextObj, HTTPKEY::MATERIALDATA, mapData);

                    MapList mapListData;
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::UNIT_LIST, mapListData);

                    MapList mapListWareHouse;
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::ASSISTANTWAREHOUSE, mapListWareHouse);

                    materialStoInfo->setMatMap(mapData);
                    materialStoInfo->setUnitMapList(mapListData);
                    materialStoInfo->setAssistantMapList(mapListWareHouse);

                    materialStoInfo->setControlData();
                }
                else if(type == PROTOCOL::URL_STO_UPDATE_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::EDITERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::EDITSUCCESS, true);

                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STO_SEL_DATA).arg(storageId), PROTOCOL::URL_STO_SEL_DATA);

                }
                else if(type == PROTOCOL::URL_STO_DEL_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::DELERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::DELSUCCESS, true);
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STO_SEL_DATA).arg(storageId), PROTOCOL::URL_STO_SEL_DATA);
                }
                else if(type == PROTOCOL::URL_STO_SEL_SIDE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(materialStoInfo, errorMsg);
                        return;
                    }

                    Map mapData;
                    HTTPCLIENT->readJsonMap(jsonObject, HTTPKEY::MSG, mapData);

                    MapList mapListData;
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::WAREHOUSELIST, mapListData);

                    materialStoInfo->getSubPosition()->setMapData(mapData);
                    materialStoInfo->getSubPosition()->setWareHouseMapList(mapListData);
                    materialStoInfo->getSubPosition()->showWidget();
                }
                else if(type == PROTOCOL::URL_STO_JUDGE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::SUBWAREXIST;
                        else if(codeValue == TWO) errorMsg = MESSAGE::SUBWARSAME;

                        MESSAGEBOX->showMessageBox(materialStoInfo->getSubPosition(), errorMsg);
                        return;
                    }

                    materialStoInfo->getSubPosition()->close();
                    materialStoInfo->canSubOpstion();
                }
                else if(type == PROTOCOL::URL_STO_UPDATE_SIDE)
                {
                    if(ISERROR(codeValue)) return;

                    QString warHouseId = mapPurchaseInfo.value(HTTPKEY::WAREHOUSEID);

                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STO_GET_MAT).arg(stoMatId, storageState, warHouseId), PROTOCOL::URL_STO_GET_MAT);
                }
                else if(type == PROTOCOL::URL_STO_DEL_SIDE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::DELERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(materialStoInfo, errorMsg);
                        return;
                    }

                    QString warHouseId = mapPurchaseInfo.value(HTTPKEY::WAREHOUSEID);

                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STO_GET_MAT).arg(stoMatId, storageState, warHouseId), PROTOCOL::URL_STO_GET_MAT);
                }
                else if(type == PROTOCOL::URL_STO_COPY_ORDER)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;
                        else if(codeValue == THREE) errorMsg = MESSAGE::INCOMINGNOTEXIST;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::IMPORTSUCCESS, true);
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STO_SEL), PROTOCOL::URL_STO_SEL);
                    selectType = true;

                    ui->tabWidgetPurchase->setHidden(true);
                }
                else if(type == PROTOCOL::URL_STO_ADD_STO_PAGE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::WAREHOUSELIST, wareHouseMapList);
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::SUPPLIERLIST, supMapList);

                    this->setAddControlData();
                }
                else if(type == PROTOCOL::URL_STO_ADD)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ADDERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    saveFlage = true;

                    Map mapData;
                    HTTPCLIENT->readJsonMap(jsonObject, HTTPKEY::MSG, mapData);

                    addStoMaterial->setMapData(mapData);
                    editStoMaterial->setMapData(mapData);
                    storageId = mapData.value(HTTPKEY::STORAGEID);
                    storageNumber = mapData.value(HTTPKEY::STORAGENUMBER);

                    if(showType == SHOWSUCCESS)
                    {
                        MESSAGEBOX->showMessageBox(this, GLOBALDEF::ADDSUCCESS, true);
                        ui->tabWidgetPurchase->setHidden(true);
                    }
                    else
                    {
                        HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STO_SEL_MAT).
                                              arg(storageNumber, mapData.value(HTTPKEY::SUPPLIERID)),
                                              PROTOCOL::URL_STO_SEL_MAT);
                    }

                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STO_SEL), PROTOCOL::URL_STO_SEL);

                    selectType = true;
                }
                else if(type == PROTOCOL::URL_STO_UPDATE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::EDITERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectType = false;
                    ui->tabWidgetPurchase->setHidden(true);

                    if(ui->pushButtonClose->isHidden())
                    {
                        HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STO_SEL), PROTOCOL::URL_STO_SEL);
                    }
                    else
                    {
                        HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STO_GET_ID).arg(storageId), PROTOCOL::URL_STO_GET_ID);
                    }

                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::EDITSUCCESS, true);
                }
                else if(type == PROTOCOL::URL_STO_REFUSE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectType = false;
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::EXITSUCCESS, true);

                    if(ui->pushButtonClose->isHidden())
                    {
                        HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STO_SEL), PROTOCOL::URL_STO_SEL);
                    }
                    else
                    {
                        HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STO_GET_ID).arg(storageId), PROTOCOL::URL_STO_GET_ID);
                    }

                    ui->tabWidgetPurchase->setHidden(true);
                }
                else if(type == PROTOCOL::URL_STO_CONFIRM_PAGE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    MapList mapListData;

                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, mapListData);


                    QJsonValue jsonValue = jsonObject.value(HTTPKEY::MSG);
                    QJsonArray jsonArray = jsonValue.toArray();

                    QList<MapList> mapListList;
                    for(int i = 0; i < jsonArray.size(); i ++)
                    {
                        QJsonObject objectItem = jsonArray.at(i).toObject();

                        QJsonValue jsonSecondValue = objectItem.value(HTTPKEY::MATERIALWAREHOUSE);
                        QJsonArray jsonSecondArray = jsonSecondValue.toArray();

                        MapList mapList;
                        for(int j = 0; j < jsonSecondArray.size(); j ++)
                        {
                            QMap<QString, QString>mapData;

                            QJsonObject objectSecondItem = jsonSecondArray.at(j).toObject();

                            QStringList stringList = objectSecondItem.keys();

                            for(int k = 0; k < stringList.size(); k ++)
                            {
                                if(!objectSecondItem[stringList[k]].isNull())
                                {
                                    if(objectSecondItem[stringList[k]].isString())
                                    {
                                        mapData[stringList[k]] = objectSecondItem[stringList[k]].toString();
                                    }
                                    else if(objectSecondItem[stringList[k]].isDouble())
                                    {
                                        mapData[stringList[k]] = QString::number(objectSecondItem[stringList[k]].toDouble());
                                    }
                                    else
                                    {
                                        mapData[stringList[k]] = QString::number(objectSecondItem[stringList[k]].toInt());
                                    }
                                }
                            }
                            mapList.append(mapData);
                        }
                        mapListList.append(mapList);
                    }

                    startReceive->setMapListListWshe(mapListList);
                    startReceive->setMapListMat(mapListData);

                    startReceive->showWidget();
                }
                else if(type == PROTOCOL::URL_STO_CONFIRM || type == PROTOCOL::URL_STO_FINISH)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;
                        else if(codeValue == THREE) errorMsg = MESSAGE::WARINVING;
                        else if(codeValue == FOUR)  errorMsg = MESSAGE::WARNOTEXIST;
                        else if(codeValue == FIVE)  errorMsg = MESSAGE::SUPNOTEXIST;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectType = false;
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::CONFIRMSUCCESS, true);
                    if(ui->pushButtonClose->isHidden())
                    {
                        HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STO_SEL), PROTOCOL::URL_STO_SEL);
                    }
                    else
                    {
                        HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STO_GET_ID).arg(storageId), PROTOCOL::URL_STO_GET_ID);
                    }

                    ui->tabWidgetPurchase->setHidden(true);
                }
                else if(type == PROTOCOL::URL_STO_DEL)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::DELERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectType = true;
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::DELSUCCESS, true);
                    if(ui->pushButtonClose->isHidden())
                    {
                        HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STO_SEL), PROTOCOL::URL_STO_SEL);
                    }
                    else
                    {
                        HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STO_GET_ID).arg(storageId), PROTOCOL::URL_STO_GET_ID);
                    }
                    ui->tabWidgetPurchase->setHidden(true);
                }
                else if(type == PROTOCOL::URL_STO_RECONFIRM)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;
                        else if(codeValue == THREE) errorMsg = MESSAGE::WARINVING;
                        else if(codeValue == FOUR)  errorMsg = MESSAGE::RECONFIRMNOTNULL;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectType = false;
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::RECONFIRMSUCCESS, true);
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STO_SEL), PROTOCOL::URL_STO_SEL);
                    ui->tabWidgetPurchase->setHidden(true);
                }
                else if(type == PROTOCOL::URL_STO_DEL_PAGE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    MapList mapListData;

                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, mapListData);
                    editStoMaterial->setMapSelectList(mapListData);
                }
                else if(type == PROTOCOL::URL_STO_SELECT_PUR)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::SELECTERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    MapList mapListData;
                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, mapListData);
                    importAllHistory->setDataMapList(mapListData);
                }
                else if(type == PROTOCOL::URL_STO_EXPORT_EMAIL)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::EXTENDERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::SUCCESS, true);
                }
                else if(type == PROTOCOL::URL_STO_GET_ID)
                {
                    if(ISERROR(codeValue))
                    {
                        ui->tableWidgetPur->setRowCount(0);
                        ui->tableWidgetPur->clearContents();
                        return;
                    }

                    emit signalShow();

                    ui->pushButtonAdd->setHidden(true);
                    ui->pushButtonExtend->setHidden(true);
                    ui->pushButtonDel->setHidden(true);
                    ui->labelEndTime->setHidden(true);
                    ui->labelStartTime->setHidden(true);
                    ui->dateEditEndTime->setHidden(true);
                    ui->dateEditStartTime->setHidden(true);
                    ui->labelState->setHidden(true);
                    ui->comboBoxStateSelect->setHidden(true);
                    ui->labelSupplier->setHidden(true);
                    ui->comboBoxSupSelect->setHidden(true);
                    ui->labelWareHouse->setHidden(true);
                    ui->comboBoxWareHouseSelect->setHidden(true);
                    ui->labelTime->setHidden(true);
                    ui->comboBoxTimeSelect->setHidden(true);
                    ui->pushButtonSelect->setHidden(true);
                    ui->labelSize->setHidden(true);

                    ui->tabWidgetPurchase->setHidden(true);
                    ui->pushButtonClose->show();

                    Map mapData;
                    HTTPCLIENT->readJsonMap(jsonObject, HTTPKEY::MSG, mapData);

                    MapList mapListData;
                    mapListData.append(mapData);

                    stoMapList = mapListData;
                    this->setPurTableData();
                }
                else if(type == PROTOCOL::URL_STO_SEL_DISPOSE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    MapList mapListData;
                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, mapListData);

                    logInfo->setMapDataList(mapListData);

                    logInfo->showWidget();
                }
                else if(type == PROTOCOL::URL_STO_SELECT_PAGE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::SUPPLIER,  supSelectMapList);
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::WAREHOUSE, warHseSelectMapList);
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::STATE,     staSelectMapList);
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::TIMEFRAME, timeSelectMapList);

                    ui->comboBoxStateSelect->clear();
                    for(int i = 0; i < staSelectMapList.size(); i ++)
                    {
                        QString stateName = staSelectMapList.at(i).value(HTTPKEY::STATENAME);

                        if(CONFIGJSON->getLanguage().toInt())
                        {
                            if(stateName == GLOBALDEF::CHIALL)             stateName = GLOBALDEF::ENGALL;
                            else if(stateName == GLOBALDEF::CHIDISTRIBUTE) stateName = GLOBALDEF::ENGDISTRIBUTE;
                            else if(stateName == GLOBALDEF::CHIRECEIVED)   stateName = GLOBALDEF::ENGRECEIVED;
                            else if(stateName == GLOBALDEF::CHIREJECT)     stateName = GLOBALDEF::ENGREJECT;
                            else if(stateName == GLOBALDEF::CHIUNSUBMIT)   stateName = GLOBALDEF::ENGUNSUBMIT;
                        }

                        ui->comboBoxStateSelect->addItem(stateName);
                    }

                    ui->comboBoxSupSelect->clear();
                    for(int i = 0; i < supSelectMapList.size(); i ++)
                    {
                        QString supName = supSelectMapList.at(i).value(HTTPKEY::SUPPLIERNAME);

                        if(CONFIGJSON->getLanguage().toInt())
                        {
                            if(supName == GLOBALDEF::CHIALL) supName = GLOBALDEF::ENGALL;
                        }


                        ui->comboBoxSupSelect->addItem(supName);
                    }

                    ui->comboBoxWareHouseSelect->clear();
                    for(int i = 0; i < warHseSelectMapList.size(); i ++)
                    {
                        QString whseName = warHseSelectMapList.at(i).value(HTTPKEY::WAREHOUSENAME);

                        if(CONFIGJSON->getLanguage().toInt())
                        {
                            if(whseName == GLOBALDEF::CHIALL) whseName = GLOBALDEF::ENGALL;
                        }

                        ui->comboBoxWareHouseSelect->addItem(whseName);
                    }

                    ui->comboBoxTimeSelect->clear();
                    for(int i = 0; i < timeSelectMapList.size(); i ++)
                    {
                        QString timeName = timeSelectMapList.at(i).value(HTTPKEY::NAME);

                        if(CONFIGJSON->getLanguage().toInt())
                        {
                            if(timeName == GLOBALDEF::CHIALL) timeName = GLOBALDEF::ENGALL;

                            else if(timeName == GLOBALDEF::CHIYESTERDAY) timeName = GLOBALDEF::ENGYESTERDAY;
                            else if(timeName == GLOBALDEF::CHITODAY)     timeName = GLOBALDEF::ENGTODAY;
                            else if(timeName == GLOBALDEF::CHITHISWEEK)  timeName = GLOBALDEF::ENGTHISWEEK;
                            else if(timeName == GLOBALDEF::CHILASTWEEK)  timeName = GLOBALDEF::ENGLASTWEEK;
                            else if(timeName == GLOBALDEF::CHITHISMONTH) timeName = GLOBALDEF::ENGTHISMONTH;
                            else if(timeName == GLOBALDEF::CHILASTMONTH) timeName = GLOBALDEF::ENGLASTMONTH;
                            else if(timeName == GLOBALDEF::CHICUSTOMIZE) timeName = GLOBALDEF::ENGCUSTOMIZE;
                        }

                        ui->comboBoxTimeSelect->addItem(timeName);
                    }
                }
                else if(type == PROTOCOL::URL_STO_FINISH_HINT)
                {
                    int okFlage = ZERO;
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)        errorMsg = MESSAGE::MATNOTFINISH;
                        else if(codeValue == TWO)    errorMsg = MESSAGE::DATAERROR;
                        else if(codeValue == THREE)  errorMsg = MESSAGE::ORDERNOMAT;

                        okFlage = MESSAGEBOX->showMessageBox(this, errorMsg, true, false);
                    }

                    if(okFlage == QDialog::Accepted || okFlage == ZERO)
                    {
                        QByteArray byteArray;

                        byteArray.append(POSTARG::STOFINISH.arg(storageNumber));

                        HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_STO_FINISH), byteArray, PROTOCOL::URL_STO_FINISH);
                    }
                }
            }
        }
        reply->close();
    }
}

/*********************  设置表格数据        *********************/
void PurchaseStorage::setPurTableData()
{
    ui->labelSize->setText(GLOBALDEF::TOTALONUMBER.arg(stoMapList.size()));
    ui->tableWidgetPur->setRowCount(stoMapList.size());

    for(int i = 0; i < stoMapList.size(); i ++)
    {
        ui->tableWidgetPur->setItem(i, ZERO, DATA(stoMapList.at(i).value(HTTPKEY::SUPPLIERNAME)));
        ui->tableWidgetPur->setItem(i, ONE,  DATA(stoMapList.at(i).value(HTTPKEY::STORAGENUMBER)));
        ui->tableWidgetPur->setItem(i, TWO,  DATA(QDateTime::fromTime_t(stoMapList.at(i).value(HTTPKEY::STORAGETIME).toUInt()).toString("yyyy-MM-dd")));

        QString statusStr;
        switch(stoMapList.at(i).value(HTTPKEY::STORAGESTATE).toInt())
        {
        case ZERO:  statusStr = tr("配送中"); break;
        case ONE:   statusStr = tr("已收货"); break;
        case TWO:   statusStr = tr("已拒绝"); break;
        case THREE: statusStr = tr("未提交"); break;
        case FOUR:  statusStr = tr("验收中"); break;
        }
        ui->tableWidgetPur->setItem(i, THREE, DATA(statusStr));

        ui->tableWidgetPur->item(i, THREE)->setFont(QFont("ZYSong", 12, QFont::Bold));

        switch(stoMapList.at(i).value(HTTPKEY::STORAGESTATE).toInt())
        {
        case ZERO:  ui->tableWidgetPur->item(i, THREE)->setTextColor(Qt::darkBlue); break;
        case ONE:   ui->tableWidgetPur->item(i, THREE)->setTextColor(Qt::darkGreen); break;
        case TWO:   ui->tableWidgetPur->item(i, THREE)->setTextColor(Qt::darkRed); break;
        case THREE: ui->tableWidgetPur->item(i, THREE)->setTextColor(Qt::darkBlue); break;
        case FOUR:  ui->tableWidgetPur->item(i, THREE)->setTextColor(Qt::darkGreen); break;
        }

        SETTABLECENTER(ui->tableWidgetPur->item(i, ZERO));
        SETTABLECENTER(ui->tableWidgetPur->item(i, ONE));
        SETTABLECENTER(ui->tableWidgetPur->item(i, TWO));
        SETTABLECENTER(ui->tableWidgetPur->item(i, THREE));
    }

    if(selectType)
    {
        ui->tableWidgetPur->scrollToBottom();
        ui->tableWidgetPur->selectRow(ui->tableWidgetPur->rowCount() - 1);
    }
}

/*********************  设置控件数据        *********************/
void PurchaseStorage::setControlData()
{
    ui->lineEditNumberInfo->setText(mapPurchaseInfo.value(HTTPKEY::STORAGENUMBER));
    ui->lineEditRemarkInfo->setText(mapPurchaseInfo.value(HTTPKEY::STORAGEREMARK));

    QString statusStr;
    switch(mapPurchaseInfo.value(HTTPKEY::STORAGESTATE).toInt())
    {
    case ZERO:  statusStr = tr("配送中"); break;
    case ONE:   statusStr = tr("已收货"); break;
    case TWO:   statusStr = tr("已拒绝"); break;
    case THREE: statusStr = tr("未提交"); break;
    case FOUR:  statusStr = tr("验收中"); break;
    }

    int purType = mapPurchaseInfo.value(HTTPKEY::STORAGESTATE).toInt();
    if(ONE == purType || TWO == purType || FOUR == purType)
    {
        ui->pushButtonDel->setHidden(true);
        ui->pushButtonSaveInfo->setHidden(true);
        ui->pushButtonPurMatInfo->setHidden(true);
        ui->pushButtonRefuse->setHidden(true);
        ui->pushButtonCancelInfo->setHidden(true);
        ui->commandLinkButtonEdit->setHidden(true);

        ui->comboBoxPurWarHseInfo->setEnabled(false);
        ui->dateEditArriveTimeInfo->setEnabled(false);
        ui->timeEditStorageTime->setEnabled(false);
        ui->lineEditRemarkInfo->setEnabled(false);
        ui->pushButtonStart->setHidden(true);
        ui->pushButtonReConfirm->setHidden(true);

        materialStoInfo->setHide();

        if(ONE == purType)
        {
            ui->pushButtonStartCarry->setHidden(true);
            ui->pushButtonFinish->setHidden(true);
        }
        else if(TWO == purType)
        {
            ui->pushButtonStartCarry->setHidden(true);
            ui->pushButtonFinish->setHidden(true);
        }
        else if(FOUR == purType)
        {
            ui->pushButtonStartCarry->show();
            ui->pushButtonFinish->show();
        }
    }
    else
    {
        ui->pushButtonReConfirm->setHidden(true);
        ui->pushButtonDel->show();
        ui->pushButtonSaveInfo->show();
        ui->pushButtonPurMatInfo->show();
        ui->pushButtonRefuse->show();
        ui->pushButtonStart->show();
        ui->pushButtonCancelInfo->show();
        ui->commandLinkButtonEdit->show();

        ui->comboBoxPurWarHseInfo->setEnabled(true);
        ui->dateEditArriveTimeInfo->setEnabled(true);
        ui->timeEditStorageTime->setEnabled(true);
        ui->lineEditRemarkInfo->setEnabled(true);
        ui->pushButtonStartCarry->setHidden(true);
        ui->pushButtonFinish->setHidden(true);

        materialStoInfo->setShow();

        if(THREE == purType || ZERO == purType)
        {
            if(stoMatMapList.size() != 0)
            {
                ui->pushButtonStart->show();
                ui->pushButtonRefuse->show();
            }
            else
            {
                ui->pushButtonStart->setHidden(true);
                ui->pushButtonRefuse->setHidden(true);
            }
        }
    }

    ui->lineEditStateInfo->setText(statusStr);

    QDateTime dateTime = QDateTime::fromTime_t(mapPurchaseInfo.value(HTTPKEY::STORAGETIME).toUInt());

    ui->dateEditArriveTimeInfo->setDateTime(dateTime);
    ui->timeEditStorageTime->setTime(dateTime.time());

    ui->labelTotalCount->setText(tr("合计%1项").arg(stoMatMapList.size()));
    ui->lineEditSupplierInfo->setText(mapPurchaseInfo.value(HTTPKEY::SUPPLIERNAME));

    bool flage = false;
    ui->comboBoxPurWarHseInfo->clear();
    for(int i = 0; i < wareHouseMapList.size(); i ++)
    {
        ui->comboBoxPurWarHseInfo->addItem(wareHouseMapList.at(i).value(HTTPKEY::WAREHOUSENAME));

        if(wareHouseMapList.at(i).value(HTTPKEY::WAREHOUSEID) == mapPurchaseInfo.value(HTTPKEY::WAREHOUSEID))
        {
            flage = true;
            ui->comboBoxPurWarHseInfo->setCurrentIndex(i);
        }
    }

    if(!flage)
    {
        ui->comboBoxPurWarHseInfo->setCurrentIndex(-1);
    }

    ui->tableWidgetPurInfo->setRowCount(stoMatMapList.size());
    for(int i = 0; i < stoMatMapList.size(); i ++)
    {
        ui->tableWidgetPurInfo->setItem(i, ZERO,  DATA(stoMatMapList.at(i).value(HTTPKEY::MATERIALNAME)));
        ui->tableWidgetPurInfo->setItem(i, ONE,   DATA(stoMatMapList.at(i).value(HTTPKEY::BARCODE)));
        ui->tableWidgetPurInfo->setItem(i, TWO,   DATA(stoMatMapList.at(i).value(HTTPKEY::UNITNAME)));
        ui->tableWidgetPurInfo->setItem(i, THREE, DATA(stoMatMapList.at(i).value(HTTPKEY::STORAGEPRICE)));
        ui->tableWidgetPurInfo->setItem(i, FOUR,  DATA(stoMatMapList.at(i).value(HTTPKEY::STORAGEAMOUNT)));
        ui->tableWidgetPurInfo->setItem(i, FIVE,  DATA(stoMatMapList.at(i).value(HTTPKEY::REALITYNUMBER)));

        SETTABLECENTER(ui->tableWidgetPurInfo->item(i, ZERO));
        SETTABLECENTER(ui->tableWidgetPurInfo->item(i, ONE));
        SETTABLECENTER(ui->tableWidgetPurInfo->item(i, TWO));
        SETTABLECENTER(ui->tableWidgetPurInfo->item(i, THREE));
        SETTABLECENTER(ui->tableWidgetPurInfo->item(i, FOUR));
        SETTABLECENTER(ui->tableWidgetPurInfo->item(i, FIVE));
    }
    ui->tableWidgetPurInfo->scrollToBottom();
}

/*********************  设置添加入库数据        *********************/
void PurchaseStorage::setAddControlData()
{
    ui->comboBoxPurWarHse->clear();
    for(int i = 0; i < wareHouseMapList.size(); i ++)
    {
        ui->comboBoxPurWarHse->addItem(wareHouseMapList.at(i).value(HTTPKEY::WAREHOUSENAME));
    }

    ui->comboBoxSupplier->clear();
    for(int i = 0; i < supMapList.size(); i ++)
    {
        ui->comboBoxSupplier->addItem(supMapList.at(i).value(HTTPKEY::SUPPLIERNAME));
    }
}

/*********************  清空添加入库        *********************/
void PurchaseStorage::clearAddInfo()
{
    ui->lineEditRemark->clear();
    ui->comboBoxPurWarHse->clear();
    ui->comboBoxSupplier->clear();
    ui->dateEditArriveTime->setDate(QDate::currentDate());
    ui->timeEditAddTime->setDateTime(QDateTime::currentDateTime());
}

/*********************  入库订单详情        *********************/
void PurchaseStorage::on_tableWidgetPur_clicked(const QModelIndex &index)
{
    if(index.row() >= stoMapList.size()) return;

    ui->tabWidgetPurchase->addTab(ui->tabPurInfo, GLOBALDEF::STORAGEINFO);
    ui->tabWidgetPurchase->setCurrentWidget(ui->tabPurInfo);
    ui->tabWidgetPurchase->removeTab(ui->tabWidgetPurchase->indexOf(ui->tabAddSto));
    ui->tabWidgetPurchase->show();

    storageState = stoMapList.at(index.row()).value(HTTPKEY::STORAGESTATE);
    editStoMaterial->setStorageState(storageState);
    addStoMaterial->setStorageState(storageState);
    materialStoInfo->setStorageState(storageState);
    storageId     = stoMapList.at(index.row()).value(HTTPKEY::STORAGEID);

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STO_SEL_DATA).arg(storageId), PROTOCOL::URL_STO_SEL_DATA);
}

/*********************  编辑入库原料        *********************/
void PurchaseStorage::on_commandLinkButtonEdit_clicked()
{
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STO_DEL_PAGE).arg(storageNumber), PROTOCOL::URL_STO_DEL_PAGE);
    editStoMaterial->showWidget(AddStoMaterial::EDITTYPE);
    editStoMaterial->setTableEidiData();
}

/*********************  添加入库原料        *********************/
void PurchaseStorage::on_pushButtonPurMatInfo_clicked()
{
    editStoMaterial->showWidget(AddStoMaterial::ADDTYPE);
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STO_SEL_MAT).arg(storageNumber, editStoMaterial->getMapData().value(HTTPKEY::SUPPLIERID)), PROTOCOL::URL_STO_SEL_MAT);
}

/*********************  更新数据        *********************/
void PurchaseStorage::on_pushButtonSaveInfo_clicked()
{
    if(ui->comboBoxPurWarHseInfo->currentIndex() >= wareHouseMapList.size()) return;

    QByteArray byteArray;

    QString strPost = POSTARG::UPDATESTO.arg(storageNumber);

    strPost = strPost.arg(wareHouseMapList.at(ui->comboBoxPurWarHseInfo->currentIndex()).value(HTTPKEY::WAREHOUSEID));

    unsigned int timeInt = GETTIMET(ui->timeEditStorageTime->time()) + GETDATATIMET(ui->dateEditArriveTimeInfo->dateTime());

    strPost = strPost.arg(QString::number(timeInt), ui->lineEditRemarkInfo->text());

    strPost = strPost.arg(mapPurchaseInfo.value(HTTPKEY::SUPPLIERID), storageState);

    byteArray.append(strPost);

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_STO_UPDATE), byteArray, PROTOCOL::URL_STO_UPDATE);
}

/*********************  双击查询原料信息        *********************/
void PurchaseStorage::on_tableWidgetPurInfo_doubleClicked(const QModelIndex &index)
{
    if(index.row() >= stoMatMapList.size()) return;

    stoMatId = stoMatMapList.at(index.row()).value(HTTPKEY::STORAGEMATTERIALID);
    QString warHouseId = mapPurchaseInfo.value(HTTPKEY::WAREHOUSEID);

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STO_GET_MAT).arg(stoMatId, storageState, warHouseId), PROTOCOL::URL_STO_GET_MAT);
}

/*********************  取消事件        *********************/
void PurchaseStorage::on_pushButtonCancelInfo_clicked()
{
    ui->tabWidgetPurchase->setHidden(true);
}

/*********************   添加入库单        *********************/
void PurchaseStorage::on_pushButtonAdd_clicked()
{
    saveFlage = false;
    this->clearAddInfo();
    ui->tabWidgetPurchase->addTab(ui->tabAddSto, GLOBALDEF::ADDSTORAGE);
    ui->tabWidgetPurchase->setCurrentWidget(ui->tabAddSto);
    ui->tabWidgetPurchase->removeTab(ui->tabWidgetPurchase->indexOf(ui->tabPurInfo));
    ui->tabWidgetPurchase->show();

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STO_ADD_STO_PAGE), PROTOCOL::URL_STO_ADD_STO_PAGE);
}

/*********************   保存入库单        *********************/
void PurchaseStorage::on_pushButtonSave_clicked()
{
    showType = SHOWSUCCESS;
    int indexSupRow = ui->comboBoxSupplier->currentIndex();
    if(indexSupRow < 0 || indexSupRow >= supMapList.size()) return;

    int indexWarRow = ui->comboBoxPurWarHse->currentIndex();
    if(indexWarRow < 0 || indexWarRow >= wareHouseMapList.size()) return;

    QByteArray byteArray;

    QString strPost = POSTARG::ADDSTORAGE.arg(supMapList.at(indexSupRow).value(HTTPKEY::SUPPLIERID));

    strPost = strPost.arg(wareHouseMapList.at(indexWarRow).value(HTTPKEY::WAREHOUSEID));

    qDebug()<<GETDATATIMET(ui->dateEditArriveTime->dateTime());
    unsigned int timeInt = GETTIMET(ui->timeEditAddTime->time()) + GETDATATIMET(ui->dateEditArriveTime->dateTime());

    strPost = strPost.arg(QString::number(timeInt), ui->lineEditRemark->text());

    byteArray.append(strPost);

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_STO_ADD), byteArray, PROTOCOL::URL_STO_ADD);
}

/*********************   添加入库原料        *********************/
void PurchaseStorage::on_pushButtonAddPurMat_clicked()
{
    if(ui->comboBoxSupplier->currentIndex() < 0)
    {
        MESSAGEBOX->showMessageBox(this, MESSAGE::SUPNOTNULL);
        return;
    }

    if(ui->comboBoxPurWarHse->currentIndex() < 0)
    {
        MESSAGEBOX->showMessageBox(this, MESSAGE::WARHSENOTNULL);
        return;
    }

    if(!saveFlage)
    {
        on_pushButtonSave_clicked();
    }

    addStoMaterial->showWidget(AddStoMaterial::ADDTYPE);
    showType = NOTSHOW;
}

/*********************   取消按钮          *********************/
void PurchaseStorage::on_pushButtonCancel_clicked()
{
    ui->tabWidgetPurchase->setHidden(true);
}

/*********************   导入历史采购订单    *********************/
void PurchaseStorage::on_commandLinkButtonPurHistory_clicked()
{
    slectFlage = true;
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STO_SELECT_PUR), PROTOCOL::URL_STO_SELECT_PUR);
    importAllHistory->showWidget();
    importAllHistory->setImportType(ImportAllHistory::PURTYPE);
}

/*********************   导入历史入库订单   *********************/
void PurchaseStorage::on_commandLinkButtonStoHistory_clicked()
{
    slectFlage = true;
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STO_SEL), PROTOCOL::URL_STO_SEL);
    importAllHistory->showWidget();
    importAllHistory->setImportType(ImportAllHistory::STOTYPE);
}

/*********************   拒绝收货        *********************/
void PurchaseStorage::on_pushButtonRefuse_clicked()
{
    refuseWidget->setStorageNumber(mapPurchaseInfo.value(HTTPKEY::STORAGENUMBER));
    refuseWidget->setType(RefuseWidget::REFUSE);
    refuseWidget->showWidget();
}

/*********************   开始验收        *********************/
void PurchaseStorage::on_pushButtonStart_clicked()
{
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STO_CONFIRM_PAGE).arg(mapPurchaseInfo.value(HTTPKEY::STORAGENUMBER)), PROTOCOL::URL_STO_CONFIRM_PAGE);
    startReceive->setStoNumber(storageNumber);
}

/*********************   反确认        *********************/
void PurchaseStorage::on_pushButtonReConfirm_clicked()
{
    refuseWidget->setStorageNumber(mapPurchaseInfo.value(HTTPKEY::STORAGENUMBER));
    refuseWidget->setType(RefuseWidget::RECONFIRM);
    refuseWidget->showWidget();
}

/*********************   删除入库单        *********************/
void PurchaseStorage::on_pushButtonDel_clicked()
{
    QByteArray byteArray;

    byteArray.append(POSTARG::DELSTO.arg(mapPurchaseInfo.value(HTTPKEY::STORAGENUMBER)));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_STO_DEL), byteArray, PROTOCOL::URL_STO_DEL);
}

/*********************   导出邮箱        *********************/
void PurchaseStorage::on_pushButtonExtend_clicked()
{
    extendStorage->showWidget();
}

/*********************   关闭窗口        *********************/
void PurchaseStorage::on_pushButtonClose_clicked()
{
    emit signalClose();
}

/*********************   处理记录        *********************/
void PurchaseStorage::on_commandLinkButtonLog_clicked()
{
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STO_SEL_DISPOSE).arg(storageNumber), PROTOCOL::URL_STO_SEL_DISPOSE);
}

/*********************   查询数据        *********************/
void PurchaseStorage::on_pushButtonSelect_clicked()
{
    ui->tabWidgetPurchase->setHidden(true);
    int supIndex = ui->comboBoxSupSelect->currentIndex();
    if(supIndex < 0 || supIndex >= supSelectMapList.size()) return;

    int timeIndex = ui->comboBoxTimeSelect->currentIndex();
    if(timeIndex < 0 || timeIndex >= timeSelectMapList.size()) return;

    int warHseIndex = ui->comboBoxWareHouseSelect->currentIndex();
    if(warHseIndex < 0 || warHseIndex >= warHseSelectMapList.size()) return;

    int staIndex = ui->comboBoxStateSelect->currentIndex();
    if(staIndex < 0 || staIndex >= staSelectMapList.size()) return;

    QString stateId  = staSelectMapList.at(staIndex).value(HTTPKEY::STATEID);
    QString supId    = supSelectMapList.at(supIndex).value(HTTPKEY::SUPPLIERID);
    QString warHseId = warHseSelectMapList.at(warHseIndex).value(HTTPKEY::WAREHOUSEID);

    QString strTime;
    if(ui->comboBoxTimeSelect->currentText() != tr("自定义"))
    {
        strTime = timeSelectMapList.at(timeIndex).value(HTTPKEY::TIME);
    }
    else
    {
        strTime = QString::number(ui->dateEditStartTime->dateTime().toTime_t()) + "," +
                QString::number(ui->dateEditEndTime->dateTime().toTime_t());
    }

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STO_SELECT).
                          arg(stateId, supId, warHseId, strTime), PROTOCOL::URL_STO_SELECT);
}

/*********************   点击下拉框        *********************/
void PurchaseStorage::on_comboBoxTimeSelect_activated(const QString &arg1)
{
    if(arg1 == tr("自定义"))
    {
        ui->labelEndTime->show();
        ui->labelStartTime->show();
        ui->dateEditEndTime->show();
        ui->dateEditStartTime->show();

        ui->dateEditStartTime->setDate(QDate::currentDate());
        ui->dateEditEndTime->setDate(QDate::currentDate());
    }
    else
    {
        ui->labelEndTime->setHidden(true);
        ui->labelStartTime->setHidden(true);
        ui->dateEditEndTime->setHidden(true);
        ui->dateEditStartTime->setHidden(true);
    }
}

/*********************   验收完成        *********************/
void PurchaseStorage::on_pushButtonFinish_clicked()
{
    QByteArray byteArray;

    byteArray.append(POSTARG::STOFINISH.arg(storageNumber));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_STO_FINISH_HINT), byteArray, PROTOCOL::URL_STO_FINISH_HINT);
}

/*********************   继续验收        *********************/
void PurchaseStorage::on_pushButtonStartCarry_clicked()
{
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STO_CONFIRM_PAGE).arg(storageNumber), PROTOCOL::URL_STO_CONFIRM_PAGE);
    startReceive->setStoNumber(storageNumber);
}
