#include "purreturngood.h"
#include "ui_purreturngood.h"
#include "httpclient/httpclient.h"
#include "httpclient/httpkey.h"
#include "httpclient/protocol.h"
#include "messagebox/messagedialog.h"

/*********************  构造函数       *********************/
PurReturnGood::PurReturnGood(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PurReturnGood)
  ,showType(SHOWSUCCESS), importFlage(false), saveFlage(false), selectFlage(true)
{
    ui->setupUi(this);

    this->initControl();
}

/*********************  析构函数       *********************/
PurReturnGood::~PurReturnGood()
{
    delete ui;
}

/*********************  显示窗口       *********************/
void PurReturnGood::showWidget()
{
    this->show();
    importFlage = false;
    ui->tabWidgetReturns->setHidden(true);
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_RETURN_SEL), PROTOCOL::URL_RETURN_SEL);
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_RETURN_SELECT_PAGE), PROTOCOL::URL_RETURN_SELECT_PAGE);
}

/*********************  初始化控件       *********************/
void PurReturnGood::initControl()
{
    SETTABLEWIDGET(ui->tableWidgetReturn);
    SETTABLEWIDGET(ui->tableWidgetRetInfo);

    ui->tabWidgetReturns->setHidden(true);
    ui->dateEditArriveTime->setCalendarPopup(true);
    ui->dateEditArriveTimeInfo->setCalendarPopup(true);

    ui->comboBoxRetWarHse->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxRetWarHseInfo->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxSupplier->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxSupplierInfo->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxSupSelect->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxStateSelect->setFocusPolicy(Qt::NoFocus);

    ui->comboBoxRetWarHse->setView(new QListView());
    ui->comboBoxRetWarHseInfo->setView(new QListView());
    ui->comboBoxSupplier->setView(new QListView());
    ui->comboBoxSupplierInfo->setView(new QListView());
    ui->comboBoxSupSelect->setView(new QListView());
    ui->comboBoxStateSelect->setView(new QListView());

    ui->comboBoxSupSelect->view()->setMinimumWidth(200);
    ui->comboBoxStateSelect->view()->setMinimumWidth(200);

    ui->dateEditSelect->setCalendarPopup(true);
    ui->dateEditArriveTime->setDate(QDate::currentDate());
    ui->dateEditSelect->setDate(QDate::currentDate());

    if(CONFIGJSON->getLanguage().toInt())
    {
        ui->dateEditSelect->calendarWidget()->setLocale(QLocale(QLocale::English));
        ui->dateEditArriveTime->calendarWidget()->setLocale(QLocale(QLocale::English));
        ui->dateEditArriveTimeInfo->calendarWidget()->setLocale(QLocale(QLocale::English));
    }

    addRetMaterial   = new AddRetMaterial(this);
    editRetMaterial  = new AddRetMaterial(this);
    materialRetInfo  = new MaterialRetInfo(this);
    importRetHistory = new ImportRetHistory(this);
    logInfo          = new LogInfo(this);
    extendRetEmail   = new ExtendRetEmail(this);


    //根据分辨率适配
    QDesktopWidget *desktop = QApplication::desktop();

    int minHeight = 0;
    if(desktop->height() >= GLOBALDEF::DESKTOPHEIGHT)
    {
        minHeight = 30;
        ui->tabRetInfo->layout()->setSpacing(6);
        this->setStyleSheet(GLOBALDEF::THISSTYLE);
    }
    else
    {
        minHeight = 20;
        this->setStyleSheet(GLOBALDEF::SMALLSTYLE);
    }

    ui->labelState->setMinimumHeight(minHeight);
    ui->labelSup->setMinimumHeight(minHeight);
    ui->labelReturnDate->setMinimumHeight(minHeight);
    ui->labelSize->setMinimumHeight(minHeight);

    FlowLayout *flowLayout = new FlowLayout(ui->widgetControl);

    flowLayout->addWidget(ui->labelState);
    flowLayout->addWidget(ui->comboBoxStateSelect);
    flowLayout->addWidget(ui->labelSup);
    flowLayout->addWidget(ui->comboBoxSupSelect);
    flowLayout->addWidget(ui->labelReturnDate);
    flowLayout->addWidget(ui->dateEditSelect);
    flowLayout->addWidget(ui->pushButtonSelect);
    flowLayout->addWidget(ui->pushButtonExtend);
    flowLayout->addWidget(ui->pushButtonAdd);
    flowLayout->addWidget(ui->labelSize);

    ui->widgetControl->setLayout(flowLayout);
}

/*********************  解析json       *********************/
void PurReturnGood::readJson(QNetworkReply *reply, int type)
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

                if(type == PROTOCOL::URL_RETURN_SEL || type == PROTOCOL::URL_RETURN_SELECT)
                {
                    if(ISERROR(codeValue))
                    {
                        ui->tableWidgetReturn->clearContents();
                        ui->tableWidgetReturn->setRowCount(0);
                        retMapList.clear();
                        extendRetEmail->setDataMapList(retMapList);
                        ui->labelSize->setText(GLOBALDEF::TOTALONUMBER.arg(0));
                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, retMapList);

                    if(!importFlage)
                    {
                        extendRetEmail->setDataMapList(retMapList);
                        this->setReturnTableData();
                    }
                    else
                    {
                        importRetHistory->setPurMapList(retMapList);
                        importFlage = false;
                    }
                }
                else if(type == PROTOCOL::URL_RETURN_DATA)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    HTTPCLIENT->readJsonMap(jsonNextObj,  HTTPKEY::RETURNSDATA,   retMapData);
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::MATERIALLIST,  retMatMapList);
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::WAREHOUSELIST, wareHouseMapList);
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::SUPPLIERLIST,  supMapList);

                    returnNumber = retMapData.value(HTTPKEY::RETURNSNUMBER);
                    returnState = retMapData.value(HTTPKEY::RETURNSSTATE);
                    editRetMaterial->setMapData(retMapData);
                    editRetMaterial->setMapSelectList(retMatMapList);

                    this->setControlData();
                }
                else if(type == PROTOCOL::URL_RETURN_UPDATE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectFlage = false;
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_RETURN_SEL), PROTOCOL::URL_RETURN_SEL);
                    ui->tabWidgetReturns->setHidden(true);
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::EDITSUCCESS, true);
                }
                else if(type == PROTOCOL::URL_RETURN_ADD_PAGE)
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
                else if(type == PROTOCOL::URL_RETURN_ADD)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    saveFlage = true;
                    selectFlage = true;

                    Map mapData;
                    HTTPCLIENT->readJsonMap(jsonObject, HTTPKEY::MSG, mapData);

                    addRetMaterial->setMapData(mapData);
                    editRetMaterial->setMapData(mapData);
                    returnNumber = mapData.value(HTTPKEY::RETURNSNUMBER);
                    returnId = mapData.value(HTTPKEY::RETURNSID);

                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_RETURN_SEL), PROTOCOL::URL_RETURN_SEL);
                    if(showType == SHOWSUCCESS)
                    {
                        ui->tabWidgetReturns->setHidden(true);
                        MESSAGEBOX->showMessageBox(this, GLOBALDEF::ADDSUCCESS, true);
                    }
                    else
                    {
                        int currentIndex = ui->comboBoxSupplier->currentIndex();
                        if(currentIndex < 0 || currentIndex >= supMapList.size()) return;

                        QString supId = supMapList.at(ui->comboBoxSupplier->currentIndex()).value(HTTPKEY::SUPPLIERID);

                        addRetMaterial->setSupplierId(supId);
                        HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_RETURN_SEL_MAT).arg(returnNumber, supId), PROTOCOL::URL_RETURN_SEL_MAT);
                    }
                }
                else if(type == PROTOCOL::URL_RETURN_SEL_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        addRetMaterial->clearInfo();
                        editRetMaterial->clearInfo();
                        return;
                    }

                    MapList mapList;

                    if(jsonNextObj.contains(HTTPKEY::MATERIALLIST))
                    {
                        HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::MATERIALLIST, mapList);
                    }
                    else
                    {
                        HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, mapList);
                    }

                    addRetMaterial->setMapMatList(mapList);
                    editRetMaterial->setMapMatList(mapList);
                }
                else if(type == PROTOCOL::URL_RETURN_ADD_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ADDERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectFlage = false;
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_RETURN_SEL), PROTOCOL::URL_RETURN_SEL);
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_RETURN_DATA).arg(returnId), PROTOCOL::URL_RETURN_DATA);
                    ui->tabWidgetReturns->addTab(ui->tabRetInfo, GLOBALDEF::RETURNINFO);
                    ui->tabWidgetReturns->setCurrentWidget(ui->tabRetInfo);
                    ui->tabWidgetReturns->removeTab(ui->tabWidgetReturns->indexOf(ui->tabAddRet));
                    ui->tabWidgetReturns->show();

                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::ADDSUCCESS, true);
                }
                else if(type == PROTOCOL::URL_RETURN_GET_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    materialRetInfo->showWidget();

                    Map mapData;
                    HTTPCLIENT->readJsonMap(jsonNextObj, HTTPKEY::MATERIALDATA, mapData);

                    MapList mapListData;
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::UNIT_LIST, mapListData);

                    MapList mapListWareHouse;
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::ASSISTANTWAREHOUSE, mapListWareHouse);

                    materialRetInfo->setMatMap(mapData);
                    materialRetInfo->setUnitMapList(mapListData);
                    materialRetInfo->setAssistantMapList(mapListWareHouse);

                    materialRetInfo->setControlData();
                }
                else if(type == PROTOCOL::URL_RETURN_UPDATE_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::EDITERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_RETURN_DATA).arg(returnId), PROTOCOL::URL_RETURN_DATA);
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::EDITSUCCESS, true);
                }
                else if(type == PROTOCOL::URL_RETURN_DEL_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::DELERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_RETURN_DATA).arg(returnId), PROTOCOL::URL_RETURN_DATA);
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::DELSUCCESS, true);
                }
                else if(type == PROTOCOL::URL_RETURN_SEL_SIDE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(materialRetInfo, errorMsg);
                        return;
                    }

                    Map mapData;
                    HTTPCLIENT->readJsonMap(jsonObject, HTTPKEY::MSG, mapData);

                    MapList mapListData;
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::WAREHOUSELIST, mapListData);

                    materialRetInfo->getSubPosition()->setMapData(mapData);
                    materialRetInfo->getSubPosition()->setWareHouseMapList(mapListData);

                    materialRetInfo->getSubPosition()->showWidget();
                }
                else if(type == PROTOCOL::URL_RETURN_JUDGE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::SUBWAREXIST;
                        else if(codeValue == TWO) errorMsg = MESSAGE::SUBWARSAME;

                        MESSAGEBOX->showMessageBox(materialRetInfo->getSubPosition(), errorMsg);
                        return;
                    }

                    materialRetInfo->getSubPosition()->close();
                    materialRetInfo->canSubOpstion();
                }
                else if(type == PROTOCOL::URL_RETURN_UPDATE_SIDE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ADDERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(materialRetInfo, errorMsg);
                        return;
                    }

                    QString warHouseId = retMapData.value(HTTPKEY::WAREHOUSEID);

                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_RETURN_GET_MAT).arg(retMatId, returnState, warHouseId), PROTOCOL::URL_RETURN_GET_MAT);
                }
                else if(type == PROTOCOL::URL_RETURN_DEL_SIDE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::DELERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(materialRetInfo, errorMsg);
                        return;
                    }

                    QString warHouseId = retMapData.value(HTTPKEY::WAREHOUSEID);

                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_RETURN_GET_MAT).arg(retMatId, returnState, warHouseId), PROTOCOL::URL_RETURN_GET_MAT);
                }
                else if(type == PROTOCOL::URL_RETURN_COPY_ORDER)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectFlage = true;
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_RETURN_SEL), PROTOCOL::URL_RETURN_SEL);
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::IMPORTSUCCESS, true);

                    ui->tabWidgetReturns->setHidden(true);
                }
                else if(type == PROTOCOL::URL_RETURN_CONFIRM)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;
                        else if(codeValue == THREE) errorMsg = MESSAGE::WARINVING;
                        else if(codeValue == FOUR)  errorMsg = MESSAGE::WARNOTEXIST;
                        else if(codeValue == FIVE)  errorMsg = MESSAGE::SUPNOTEXIST;
                        else if(codeValue == SIX)   errorMsg = MESSAGE::MATERIALNOTEXIST;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectFlage = false;
                    ui->tabWidgetReturns->setHidden(true);
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_RETURN_SEL), PROTOCOL::URL_RETURN_SEL);
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::EXITSUCCESS, true);
                }
                else if(type == PROTOCOL::URL_RETURN_DEL_STO)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectFlage = true;
                    ui->tabWidgetReturns->setHidden(true);
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_RETURN_SEL), PROTOCOL::URL_RETURN_SEL);
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::DELSUCCESS, true);
                }
                else if(type == PROTOCOL::URL_RETURN_SEL_DISPOSE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    MapList mapListData;
                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, mapListData);

                    logInfo->setMapDataList(mapListData);

                    logInfo->showWidget();
                }
                else if(type == PROTOCOL::URL_RETURN_DEL_MAT_SHOW)
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
                    editRetMaterial->setMapSelectList(mapListData);
                }
                else if(type == PROTOCOL::URL_RETURN_SELECT_PAGE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::STATE, staSelectMapList);
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::SUPPLIER, supSelectMapList);

                    ui->comboBoxStateSelect->clear();
                    for(int i = 0; i < staSelectMapList.size(); i ++)
                    {
                        QString stateName = staSelectMapList.at(i).value(HTTPKEY::STATENAME);

                        if(CONFIGJSON->getLanguage().toInt())
                        {
                            if(stateName == GLOBALDEF::CHIALL)            stateName = GLOBALDEF::ENGALL;
                            else if(stateName == GLOBALDEF::CHIUNSUBMIT)  stateName = GLOBALDEF::ENGUNSUBMIT;
                            else if(stateName == GLOBALDEF::CHIRETURN)    stateName = GLOBALDEF::ENGRETURN;
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
                }
                else if(type == PROTOCOL::URL_RETURN_EXTEND)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::EXTENDERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::EXPORTSUCCESS, true);
                }
            }
        }
        reply->close();
    }
}

/*********************  清空添加入库       *********************/
void PurReturnGood::clearInfo()
{
    ui->comboBoxRetWarHse->clear();
    ui->lineEditRemark->clear();
    ui->comboBoxSupplier->clear();

    ui->dateEditArriveTime->setDate(QDate::currentDate());
    ui->timeEditReturn->setDateTime(QDateTime::currentDateTime());
}

/*********************  设置控件数据       *********************/
void PurReturnGood::setControlData()
{
    ui->lineEditNumberInfo->setText(retMapData.value(HTTPKEY::RETURNSNUMBER));
    ui->lineEditRemarkInfo->setText(retMapData.value(HTTPKEY::RETURNSREMARK));

    QString statusStr;
    switch(retMapData.value(HTTPKEY::RETURNSSTATE).toInt())
    {
    case ZERO: statusStr = tr("未提交"); break;
    case ONE:  statusStr = tr("退货完成"); break;
    }

    if(retMapData.value(HTTPKEY::RETURNSSTATE).toInt() == ZERO)
    {
        ui->pushButtonRetMatInfo->show();
        ui->pushButtonCancelInfo->show();
        ui->pushButtonSaveInfo->show();
        ui->pushButtonDeleteInfo->show();
        ui->timeEditReturnInfo->setEnabled(true);
        ui->dateEditArriveTimeInfo->setEnabled(true);
        ui->comboBoxSupplierInfo->setEnabled(true);
        ui->comboBoxRetWarHseInfo->setEnabled(true);
        ui->lineEditRemarkInfo->setEnabled(true);

        materialRetInfo->setShow();

        if(retMatMapList.size() != 0)
        {
            ui->pushButtonStartSureInfo->show();
        }
        else
        {
            ui->pushButtonStartSureInfo->setHidden(true);
        }
    }
    else
    {
        ui->pushButtonCancelInfo->setHidden(true);
        ui->pushButtonSaveInfo->setHidden(true);
        ui->pushButtonDeleteInfo->setHidden(true);
        ui->pushButtonStartSureInfo->setHidden(true);
        ui->pushButtonRetMatInfo->setHidden(true);
        ui->comboBoxSupplierInfo->setEnabled(false);
        ui->comboBoxRetWarHseInfo->setEnabled(false);
        ui->lineEditRemarkInfo->setEnabled(false);
        ui->timeEditReturnInfo->setEnabled(false);
        ui->dateEditArriveTimeInfo->setEnabled(false);

        materialRetInfo->setHide();
    }

    ui->lineEditStateInfo->setText(statusStr);

    QDateTime dateTime = QDateTime::fromTime_t(retMapData.value(HTTPKEY::RETURNSTIME).toUInt());

    ui->dateEditArriveTimeInfo->setDateTime(dateTime);
    ui->timeEditReturnInfo->setTime(dateTime.time());

    ui->labelTotalCount->setText(tr("合计%1项").arg(retMatMapList.size()));

    ui->comboBoxSupplierInfo->clear();
    for(int i = 0; i < supMapList.size(); i ++)
    {
        ui->comboBoxSupplierInfo->addItem(supMapList.at(i).value(HTTPKEY::SUPPLIERNAME));
    }
    ui->comboBoxSupplierInfo->setCurrentText(retMapData.value(HTTPKEY::SUPPLIERNAME));

    bool flage = false;
    ui->comboBoxRetWarHseInfo->clear();
    for(int i = 0; i < wareHouseMapList.size(); i ++)
    {
        ui->comboBoxRetWarHseInfo->addItem(wareHouseMapList.at(i).value(HTTPKEY::WAREHOUSENAME));

        if(wareHouseMapList.at(i).value(HTTPKEY::WAREHOUSEID) == retMapData.value(HTTPKEY::WAREHOUSEID))
        {
            flage = true;
            ui->comboBoxRetWarHseInfo->setCurrentIndex(i);
        }
    }

    if(!flage)
    {
        ui->comboBoxRetWarHseInfo->setCurrentIndex(-1);
    }

    ui->tableWidgetRetInfo->setRowCount(retMatMapList.size());
    for(int i = 0; i < retMatMapList.size(); i ++)
    {
        ui->tableWidgetRetInfo->setItem(i, ZERO,  DATA(retMatMapList.at(i).value(HTTPKEY::MATERIALNAME)));
        ui->tableWidgetRetInfo->setItem(i, ONE,   DATA(retMatMapList.at(i).value(HTTPKEY::BARCODE)));
        ui->tableWidgetRetInfo->setItem(i, TWO,   DATA(retMatMapList.at(i).value(HTTPKEY::UNITNAME)));
        ui->tableWidgetRetInfo->setItem(i, THREE, DATA(retMatMapList.at(i).value(HTTPKEY::RETURNSPRICE)));
        ui->tableWidgetRetInfo->setItem(i, FOUR,  DATA(retMatMapList.at(i).value(HTTPKEY::RETURNSAMOUNT)));

        SETTABLECENTER(ui->tableWidgetRetInfo->item(i, ZERO));
        SETTABLECENTER(ui->tableWidgetRetInfo->item(i, ONE));
        SETTABLECENTER(ui->tableWidgetRetInfo->item(i, TWO));
        SETTABLECENTER(ui->tableWidgetRetInfo->item(i, THREE));
        SETTABLECENTER(ui->tableWidgetRetInfo->item(i, FOUR));
    }
    ui->tableWidgetRetInfo->scrollToBottom();
}

/*********************  设置添加入库数据        *********************/
void PurReturnGood::setAddControlData()
{
    ui->comboBoxRetWarHse->clear();
    for(int i = 0; i < wareHouseMapList.size(); i ++)
    {
        ui->comboBoxRetWarHse->addItem(wareHouseMapList.at(i).value(HTTPKEY::WAREHOUSENAME));
    }

    ui->comboBoxSupplier->clear();
    for(int i = 0; i < supMapList.size(); i ++)
    {
        ui->comboBoxSupplier->addItem(supMapList.at(i).value(HTTPKEY::SUPPLIERNAME));
    }
}

/*********************  添加退货单       *********************/
void PurReturnGood::on_pushButtonAdd_clicked()
{
    saveFlage = false;
    this->clearInfo();
    ui->tabWidgetReturns->addTab(ui->tabAddRet, GLOBALDEF::ADDRETURN);
    ui->tabWidgetReturns->setCurrentWidget(ui->tabAddRet);
    ui->tabWidgetReturns->removeTab(ui->tabWidgetReturns->indexOf(ui->tabRetInfo));
    ui->tabWidgetReturns->show();

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_RETURN_ADD_PAGE), PROTOCOL::URL_RETURN_ADD_PAGE);
}

/*********************  设置表格数据        *********************/
void PurReturnGood::setReturnTableData()
{
    ui->labelSize->setText(GLOBALDEF::TOTALONUMBER.arg(retMapList.size()));
    ui->tableWidgetReturn->setRowCount(retMapList.size());

    for(int i = 0; i < retMapList.size(); i ++)
    {
        ui->tableWidgetReturn->setItem(i, ZERO,  DATA(retMapList.at(i).value(HTTPKEY::SUPPLIERNAME)));
        ui->tableWidgetReturn->setItem(i, ONE,   DATA(retMapList.at(i).value(HTTPKEY::RETURNSNUMBER)));
        ui->tableWidgetReturn->setItem(i, TWO,   DATA(QDateTime::fromTime_t(retMapList.at(i).value(HTTPKEY::RETURNSTIME).toUInt()).toString("yyyy-MM-dd")));
        ui->tableWidgetReturn->setItem(i, THREE, DATA(retMapList.at(i).value(HTTPKEY::RETURNSSTATE) == "0" ? tr("未提交") : tr("退货完成")));

        ui->tableWidgetReturn->item(i, THREE)->setFont(QFont("ZYSong", 12, QFont::Bold));
        switch(retMapList.at(i).value(HTTPKEY::RETURNSSTATE).toInt())
        {
        case ZERO: ui->tableWidgetReturn->item(i, THREE)->setTextColor(Qt::darkBlue); break;
        case ONE:  ui->tableWidgetReturn->item(i, THREE)->setTextColor(Qt::darkGreen); break;
        }

        SETTABLECENTER(ui->tableWidgetReturn->item(i, ZERO));
        SETTABLECENTER(ui->tableWidgetReturn->item(i, ONE));
        SETTABLECENTER(ui->tableWidgetReturn->item(i, TWO));
        SETTABLECENTER(ui->tableWidgetReturn->item(i, THREE));
    }


    if(selectFlage)
    {
        ui->tableWidgetReturn->scrollToBottom();
        ui->tableWidgetReturn->selectRow(ui->tableWidgetReturn->rowCount() - 1);
    }
}

/*********************  单击事件        *********************/
void PurReturnGood::on_tableWidgetReturn_clicked(const QModelIndex &index)
{
    if(index.row() >= retMapList.size()) return;

    ui->tabWidgetReturns->addTab(ui->tabRetInfo, GLOBALDEF::RETURNINFO);
    ui->tabWidgetReturns->setCurrentWidget(ui->tabRetInfo);
    ui->tabWidgetReturns->removeTab(ui->tabWidgetReturns->indexOf(ui->tabAddRet));
    ui->tabWidgetReturns->show();

    returnId = retMapList.at(index.row()).value(HTTPKEY::RETURNSID);
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_RETURN_DATA).arg(returnId), PROTOCOL::URL_RETURN_DATA);
}

/*********************  添加退货原料        *********************/
void PurReturnGood::on_pushButtonAddRetMat_clicked()
{
    int currentRow = ui->comboBoxRetWarHse->currentIndex();
    if(currentRow >= 0 && currentRow < wareHouseMapList.size())
    {

        QString wareHouseId = wareHouseMapList.at(currentRow).value(HTTPKEY::WAREHOUSEID);
        addRetMaterial->setWareHouseId(wareHouseId);
    }

    if(!saveFlage)
    {
        on_pushButtonSave_clicked();
    }

    addRetMaterial->showWidget(AddRetMaterial::ADDTYPE);
    showType = NOTSHOW;
}

/*********************  保存数据        *********************/
void PurReturnGood::on_pushButtonSave_clicked()
{
    showType = SHOWSUCCESS;
    int indexRow = ui->comboBoxSupplier->currentIndex();
    if(indexRow < 0 || indexRow >= supMapList.size()) return;

    int indexWarRow = ui->comboBoxRetWarHse->currentIndex();
    if(indexWarRow < 0 || indexWarRow >= wareHouseMapList.size()) return;

    QByteArray byteArray;

    QString strPost = POSTARG::ADDRET.arg(supMapList.at(indexRow).value(HTTPKEY::SUPPLIERID));

    strPost = strPost.arg(wareHouseMapList.at(indexWarRow).value(HTTPKEY::WAREHOUSEID));

    unsigned int timeInt = GETTIMET(ui->timeEditReturn->time()) + GETDATATIMET(ui->dateEditArriveTime->dateTime());

    strPost = strPost.arg(QString::number(timeInt), ui->lineEditRemark->text());

    byteArray.append(strPost);

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_RETURN_ADD), byteArray, PROTOCOL::URL_RETURN_ADD);
}

/*********************  更新数据        *********************/
void PurReturnGood::on_pushButtonSaveInfo_clicked()
{
    if(ui->comboBoxRetWarHseInfo->currentIndex() >= wareHouseMapList.size()) return;
    if(ui->comboBoxSupplierInfo->currentIndex() >= supMapList.size()) return;

    QByteArray byteArray;

    QString strPost = POSTARG::UPDATERET.arg(returnNumber);

    strPost = strPost.arg(wareHouseMapList.at(ui->comboBoxRetWarHseInfo->currentIndex()).value(HTTPKEY::WAREHOUSEID));

    unsigned int timeInt = GETTIMET(ui->timeEditReturnInfo->time()) + GETDATATIMET(ui->dateEditArriveTimeInfo->dateTime());

    strPost = strPost.arg(QString::number(timeInt), ui->lineEditRemarkInfo->text());

    strPost = strPost.arg(supMapList.at(ui->comboBoxSupplierInfo->currentIndex()).value(HTTPKEY::SUPPLIERID));

    strPost = strPost.arg(returnState);

    byteArray.append(strPost);

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_RETURN_UPDATE), byteArray, PROTOCOL::URL_RETURN_UPDATE);
}

/*********************   添加原料信息        *********************/
void PurReturnGood::on_pushButtonRetMatInfo_clicked()
{
    int currentIndex = ui->comboBoxSupplierInfo->currentIndex();
    if(currentIndex < 0 || currentIndex >= supMapList.size()) return;

    editRetMaterial->showWidget(AddRetMaterial::ADDTYPE);
    QString supId = supMapList.at(ui->comboBoxSupplierInfo->currentIndex()).value(HTTPKEY::SUPPLIERID);

    editRetMaterial->setSupplierId(supId);
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_RETURN_SEL_MAT).arg(returnNumber, supId), PROTOCOL::URL_RETURN_SEL_MAT);
}

/*********************   取消按钮          *********************/
void PurReturnGood::on_pushButtonCancel_clicked()
{
    ui->tabWidgetReturns->setHidden(true);
}

/*********************   处理记录        *********************/
void PurReturnGood::on_commandLinkButtonLog_clicked()
{
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_RETURN_SEL_DISPOSE).arg(returnNumber), PROTOCOL::URL_RETURN_SEL_DISPOSE);
}

/*********************   删除退货单        *********************/
void PurReturnGood::on_pushButtonDeleteInfo_clicked()
{
    QByteArray byteArray;

    byteArray.append(POSTARG::DELRET.arg(retMapData.value(HTTPKEY::RETURNSNUMBER)));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_RETURN_DEL_STO), byteArray, PROTOCOL::URL_RETURN_DEL_STO);
}

/*********************   编辑退货原料        *********************/
void PurReturnGood::on_commandLinkButtonEdit_clicked()
{
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_RETURN_DEL_MAT_SHOW).arg(returnNumber), PROTOCOL::URL_RETURN_DEL_MAT_SHOW);
    editRetMaterial->showWidget(AddRetMaterial::EDITTYPE);
    editRetMaterial->setTableEidiData();
}

/*********************   双击查询数据        *********************/
void PurReturnGood::on_tableWidgetRetInfo_doubleClicked(const QModelIndex &index)
{
    if(index.row() >= retMatMapList.size()) return;

    retMatId = retMatMapList.at(index.row()).value(HTTPKEY::RETURNSMATERIALID);
    QString warHouseId = retMapData.value(HTTPKEY::WAREHOUSEID);

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_RETURN_GET_MAT).arg(retMatId, returnState, warHouseId), PROTOCOL::URL_RETURN_GET_MAT);
}

/*********************   确认退货        *********************/
void PurReturnGood::on_pushButtonStartSureInfo_clicked()
{
    QByteArray byteArray;

    byteArray.append(POSTARG::CONFIRMRET.arg(retMapData.value(HTTPKEY::RETURNSNUMBER)));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_RETURN_CONFIRM), byteArray, PROTOCOL::URL_RETURN_CONFIRM);
}

/*********************   从历史退货订单导入        *********************/
void PurReturnGood::on_commandLinkButtonImport_clicked()
{
    importFlage = true;
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_RETURN_SEL), PROTOCOL::URL_RETURN_SEL);
    importRetHistory->showWidget();
}

/*********************   取消按钮        *********************/
void PurReturnGood::on_pushButtonCancelInfo_clicked()
{
    ui->tabWidgetReturns->setHidden(true);
}

/*********************   查询        *********************/
void PurReturnGood::on_pushButtonSelect_clicked()
{
    ui->tabWidgetReturns->setHidden(true);
    int currentStaIndex = ui->comboBoxStateSelect->currentIndex();
    if(currentStaIndex < 0 ||currentStaIndex >= staSelectMapList.size()) return;

    int currentSupIndex = ui->comboBoxSupSelect->currentIndex();
    if(currentSupIndex < 0 ||currentSupIndex >= supSelectMapList.size()) return;

    QString stateId = staSelectMapList.at(currentStaIndex).value(HTTPKEY::STATEID);
    QString supId = supSelectMapList.at(currentSupIndex).value(HTTPKEY::SUPPLIERID);
    QString time  = QString::number(ui->dateEditSelect->dateTime().toTime_t());

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_RETURN_SELECT).arg(stateId, supId, time), PROTOCOL::URL_RETURN_SELECT);
}

/*********************   导出到邮箱        *********************/
void PurReturnGood::on_pushButtonExtend_clicked()
{
    extendRetEmail->showWidget();
}
