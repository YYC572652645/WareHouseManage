#include "inventorytransfer.h"
#include "ui_inventorytransfer.h"
#include "messagebox/messagedialog.h"
#include "httpclient/httpkey.h"

/*********************  构造函数       *********************/
InventoryTransfer::InventoryTransfer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::inventorytransfer)
  ,addTranMaterial(NULL),
    editTranMaterial(NULL), materialTranDet(NULL)
  ,showType(SHOWSUCCESS), selectFlage(true), saveFlage(false)
{
    ui->setupUi(this);

    this->initControl();
}

/*********************  析构函数       *********************/
InventoryTransfer::~InventoryTransfer()
{
    delete ui;
}

/*********************  显示窗口       *********************/
void InventoryTransfer::showWidget()
{      
    this->show();
    ui->tabWidgetAllot->setHidden(true);
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ALLOT_SEL_ALL), PROTOCOL::URL_ALLOT_SEL_ALL);
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ALLOT_SELECT_PAGE), PROTOCOL::URL_ALLOT_SELECT_PAGE);
}

/*********************  初始化控件       *********************/
void InventoryTransfer::initControl()
{
    SETTABLEWIDGET(ui->tableWidgetAllot);
    SETTABLEWIDGET(ui->tableWidgetAllotInfo);

    ui->tabWidgetAllot->setHidden(true);
    ui->dateEditArriveTimeInfo->setCalendarPopup(true);
    ui->dateEditArriveTime->setCalendarPopup(true);
    ui->dateEditSelect->setCalendarPopup(true);
    ui->dateEditSelect->setDate(QDate::currentDate());

    ui->comboBoxWarHseOut->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxWarHseIn->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxStateSelect->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxWarHseOutSelect->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxWarHseInSelect->setFocusPolicy(Qt::NoFocus);

    ui->dateEditArriveTimeInfo->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxWarHseIn->setView(new QListView());
    ui->comboBoxWarHseOut->setView(new QListView());
    ui->comboBoxStateSelect->setView(new QListView());
    ui->comboBoxWarHseOutSelect->setView(new QListView());
    ui->comboBoxWarHseInSelect->setView(new QListView());
    ui->comboBoxWarHseInSelect->setView(new QListView());

    ui->comboBoxStateSelect->view()->setMinimumWidth(200);
    ui->comboBoxWarHseOutSelect->view()->setMinimumWidth(200);
    ui->comboBoxWarHseInSelect->view()->setMinimumWidth(200);

    if(CONFIGJSON->getLanguage().toInt())
    {
        ui->dateEditSelect->calendarWidget()->setLocale(QLocale(QLocale::English));
        ui->dateEditArriveTime->calendarWidget()->setLocale(QLocale(QLocale::English));
        ui->dateEditArriveTimeInfo->calendarWidget()->setLocale(QLocale(QLocale::English));
    }

    addTranMaterial = new AddTranMaterial(this);
    editTranMaterial = new AddTranMaterial(this);
    materialTranDet = new MaterialTranDet(this);
    refuseTranWidget = new RefuseTranWidget(this);
    logInfo = new LogInfo(this);
    extendEmail = new ExtendTranEmail(this);

    //根据分辨率适配
    QDesktopWidget *desktop = QApplication::desktop();

    int minHeight = 0;
    if(desktop->height() >= GLOBALDEF::DESKTOPHEIGHT)
    {
        minHeight = 30;
        ui->tabAllotInfo->layout()->setSpacing(6);
        this->setStyleSheet(GLOBALDEF::THISSTYLE);
    }
    else
    {
        minHeight = 20;
        this->setStyleSheet(GLOBALDEF::SMALLSTYLE);
    }

    ui->labelState->setMinimumHeight(minHeight);
    ui->labelOutWhse->setMinimumHeight(minHeight);
    ui->labelInWhse->setMinimumHeight(minHeight);
    ui->labelDate->setMinimumHeight(minHeight);
    ui->labelSize->setMinimumHeight(minHeight);

    FlowLayout *flowLayout = new FlowLayout(ui->widgetControl);

    flowLayout->addWidget(ui->labelState);
    flowLayout->addWidget(ui->comboBoxStateSelect);
    flowLayout->addWidget(ui->labelOutWhse);
    flowLayout->addWidget(ui->comboBoxWarHseOutSelect);
    flowLayout->addWidget(ui->labelInWhse);
    flowLayout->addWidget(ui->comboBoxWarHseInSelect);
    flowLayout->addWidget(ui->labelDate);
    flowLayout->addWidget(ui->dateEditSelect);
    flowLayout->addWidget(ui->pushButtonSelect);
    flowLayout->addWidget(ui->pushButtonExtend);
    flowLayout->addWidget(ui->pushButtonAdd);
    flowLayout->addWidget(ui->labelSize);

    ui->widgetControl->setLayout(flowLayout);
}

/*********************  解析json       *********************/
void InventoryTransfer::readJson(QNetworkReply *reply, int type)
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
                QJsonObject jsonNextObj = jsonObject.value(HTTPKEY::MSG).toObject();

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

                if(type == PROTOCOL::URL_ALLOT_SEL_ALL || type == PROTOCOL::URL_ALLOT_SELECT)
                {
                    if(ISERROR(codeValue))
                    {
                        ui->tableWidgetAllot->clearContents();
                        ui->tableWidgetAllot->setRowCount(0);
                        allotMapList.clear();

                        extendEmail->setDataMapList(allotMapList);
                        ui->labelSize->setText(GLOBALDEF::TOTALONUMBER.arg(0));
                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, allotMapList);
                    extendEmail->setDataMapList(allotMapList);
                    this->setAllotTableData();
                }
                else if(type == PROTOCOL::URL_ALLOT_SEL)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    HTTPCLIENT->readJsonMap(jsonNextObj,  HTTPKEY::ALLOT, mapAllotInfo);
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::MATERIAL, allotMatMapList);

                    allotNumber = mapAllotInfo.value(HTTPKEY::ALLOTNUMBER);

                    ui->tabWidgetAllot->show();
                    this->setControlData();
                }
                else if(type == PROTOCOL::URL_ALLOT_SEL_MAT)
                {
                    MapList mapList;
                    if(ISERROR(codeValue))
                    {
                        addTranMaterial->setMapMatList(mapList);
                        editTranMaterial->setMapMatList(mapList);
                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, mapList);

                    addTranMaterial->setMapMatList(mapList);
                    editTranMaterial->setMapMatList(mapList);
                }
                else if(type == PROTOCOL::URL_ALLOT_ADD_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;
                        else if(codeValue == THREE) errorMsg = MESSAGE::WARMAYDEL;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::ADDSUCCESS, true);
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ALLOT_SEL).arg(allotNumber), PROTOCOL::URL_ALLOT_SEL);

                    ui->tabWidgetAllot->addTab(ui->tabAllotInfo, GLOBALDEF::TRANINFO);
                    ui->tabWidgetAllot->setCurrentWidget(ui->tabAllotInfo);
                    ui->tabWidgetAllot->removeTab(ui->tabWidgetAllot->indexOf(ui->tabAddAllot));
                    ui->tabWidgetAllot->show();
                }
                else if(type == PROTOCOL::URL_ALLOT_GET_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    materialTranDet->showWidget();

                    Map mapData;
                    HTTPCLIENT->readJsonMap(jsonNextObj, HTTPKEY::MATERIAL, mapData);

                    MapList mapListData;
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::UNIT_LIST, mapListData);

                    materialTranDet->setMatMap(mapData);
                    materialTranDet->setUnitMapList(mapListData);

                    materialTranDet->setControlData();
                }
                else if(type == PROTOCOL::URL_ALLOT_UPDATE_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;
                        else if(codeValue == THREE) errorMsg = MESSAGE::WARMAYDEL;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::EDITSUCCESS, true);
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ALLOT_SEL).arg(allotNumber), PROTOCOL::URL_ALLOT_SEL);
                }
                else if(type == PROTOCOL::URL_ALLOT_DEL_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::DELERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::DELSUCCESS, true);
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ALLOT_SEL).arg(allotNumber), PROTOCOL::URL_ALLOT_SEL);
                }
                else if(type == PROTOCOL::URL_ALLOT_ADD_PAGE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, wareHouseMapList);
                    this->setAddControlData();
                }
                else if(type == PROTOCOL::URL_ALLOT_ADD)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ADDERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    saveFlage = true;
                    selectFlage = true;

                    allotNumber = jsonObject.value(HTTPKEY::MSG).toString();

                    if(showType == SHOWSUCCESS)
                    {
                        MESSAGEBOX->showMessageBox(this, GLOBALDEF::ADDSUCCESS, true);
                        this->showWidget();
                    }
                    else
                    {
                        HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ALLOT_SEL_ALL), PROTOCOL::URL_ALLOT_SEL_ALL);
                        HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ALLOT_SEL_MAT).arg(allotNumber), PROTOCOL::URL_ALLOT_SEL_MAT);
                    }
                }
                else if(type == PROTOCOL::URL_ALLOT_UPDATE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::EDITERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;
                        else if(codeValue == THREE) errorMsg = MESSAGE::WARMAYDEL;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::EDITSUCCESS, true);
                    ui->tabWidgetAllot->setHidden(true);
                }
                else if(type == PROTOCOL::URL_ALLOT_CANCEL)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;
                        else if(codeValue == THREE) errorMsg = MESSAGE::WARMAYDEL;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectFlage = false;
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::SUCCESS, true);
                    this->showWidget();
                }
                else if(type == PROTOCOL::URL_ALLOT_AFFIRM)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;
                        else if(codeValue == THREE) errorMsg = MESSAGE::WARMAYDEL;
                        else if(codeValue == FOUR) errorMsg = MESSAGE::TRANSFERING;


                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectFlage = false;
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::CONFIRMSUCCESS, true);
                    this->showWidget();
                }
                else if(type == PROTOCOL::URL_ALLOT_DEL)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::DELERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectFlage = true;
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::DELSUCCESS, true);
                    this->showWidget();
                }
                else if(type == PROTOCOL::URL_ALLOT_RECONFIRM)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;
                        else if(codeValue == THREE) errorMsg = MESSAGE::WARMAYDEL;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectFlage = false;
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::RECONFIRMSUCCESS, true);
                    this->showWidget();
                }
                else if(type == PROTOCOL::URL_ALLOT_UPDATE_ALL_PAGE)
                {
                    if(ISERROR(codeValue)) return;

                    MapList mapListData;

                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, mapListData);
                    editTranMaterial->setMapSelectList(mapListData);
                }
                else if(type == PROTOCOL::URL_ALLOT_UPDATE_ALL_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::EDITERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;
                        else if(codeValue == THREE) errorMsg = MESSAGE::WARMAYDEL;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::EDITSUCCESS, true);
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ALLOT_SEL).arg(allotNumber), PROTOCOL::URL_ALLOT_SEL);
                }
                else if(type == PROTOCOL::URL_ALLOT_SEND_EMAIL)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::EXTENDERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::SUCCESS, true);
                }
                else if(type == PROTOCOL::URL_ALLOT_SEL_DISPOSE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    MapList mapListData;
                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, mapListData);

                    logInfo->setMapDataList(mapListData);

                    logInfo->showWidget();
                }
                else if(type == PROTOCOL::URL_ALLOT_PRESEND)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;
                        else if(codeValue == THREE) errorMsg = MESSAGE::WARMAYDEL;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectFlage = false;
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::SUBMITSUCCESS, true);
                    this->showWidget();
                }
                else if(type == PROTOCOL::URL_ALLOT_SELECT_PAGE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::WAREHOUSE, warHseSelectMapList);
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::STATE, staSelectMapList);

                    ui->comboBoxStateSelect->clear();
                    for(int i = 0; i < staSelectMapList.size(); i ++)
                    {
                        QString stateName = staSelectMapList.at(i).value(HTTPKEY::STATENAME);

                        if(CONFIGJSON->getLanguage().toInt())
                        {
                            if(stateName == GLOBALDEF::CHIALL)            stateName = GLOBALDEF::ENGALL;
                            else if(stateName == GLOBALDEF::CHIUNSUBMIT)  stateName = GLOBALDEF::ENGUNSUBMIT;
                            else if(stateName == GLOBALDEF::CHIREJECT)    stateName = GLOBALDEF::ENGREJECT;
                            else if(stateName == GLOBALDEF::CHIFINISH)    stateName = GLOBALDEF::ENGFINISH;
                            else if(stateName == GLOBALDEF::CHITRANS)     stateName = GLOBALDEF::ENGTRANS;
                        }

                        ui->comboBoxStateSelect->addItem(stateName);
                    }

                    ui->comboBoxWarHseOutSelect->clear();
                    ui->comboBoxWarHseInSelect->clear();
                    for(int i = 0; i < warHseSelectMapList.size(); i ++)
                    {
                        QString whseName = warHseSelectMapList.at(i).value(HTTPKEY::WAREHOUSENAME);

                        if(CONFIGJSON->getLanguage().toInt())
                        {
                            if(whseName == GLOBALDEF::CHIALL) whseName = GLOBALDEF::ENGALL;
                        }

                        ui->comboBoxWarHseOutSelect->addItem(whseName);
                        ui->comboBoxWarHseInSelect->addItem(whseName);
                    }
                }
            }
        }
        reply->close();
    }
}

/*********************  设置表格数据        *********************/
void InventoryTransfer::setAllotTableData()
{
    ui->labelSize->setText(GLOBALDEF::TOTALONUMBER.arg(allotMapList.size()));
    ui->tableWidgetAllot->setRowCount(allotMapList.size());

    for(int i = 0; i < allotMapList.size(); i ++)
    {
        ui->tableWidgetAllot->setItem(i, ZERO, DATA(allotMapList.at(i).value(HTTPKEY::ENTERNAME)));
        ui->tableWidgetAllot->setItem(i, ONE, DATA(allotMapList.at(i).value(HTTPKEY::OUTNAME)));
        ui->tableWidgetAllot->setItem(i, TWO, DATA(allotMapList.at(i).value(HTTPKEY::ALLOTNUMBER)));
        ui->tableWidgetAllot->setItem(i, THREE, DATA(QDateTime::fromTime_t(allotMapList.at(i).value(HTTPKEY::ALLOTTIME).toUInt()).toString("yyyy-MM-dd")));

        QString statusStr;
        switch(allotMapList.at(i).value(HTTPKEY::STATE).toInt())
        {
        case ZERO:  statusStr = tr("未提交"); break;
        case ONE:   statusStr = tr("调拨中"); break;
        case TWO:   statusStr = tr("已完成"); break;
        case THREE: statusStr = tr("已拒绝"); break;
        }
        ui->tableWidgetAllot->setItem(i, FOUR, DATA(statusStr));
        ui->tableWidgetAllot->item(i, FOUR)->setFont(QFont("ZYSong", 12, QFont::Bold));

        switch(allotMapList.at(i).value(HTTPKEY::STATE).toInt())
        {
        case ZERO:  ui->tableWidgetAllot->item(i, FOUR)->setTextColor(Qt::darkBlue); break;
        case ONE:   ui->tableWidgetAllot->item(i, FOUR)->setTextColor(Qt::darkBlue); break;
        case TWO:   ui->tableWidgetAllot->item(i, FOUR)->setTextColor(Qt::darkGreen); break;
        case THREE: ui->tableWidgetAllot->item(i, FOUR)->setTextColor(Qt::darkRed); break;
        }

        SETTABLECENTER(ui->tableWidgetAllot->item(i, ZERO));
        SETTABLECENTER(ui->tableWidgetAllot->item(i, ONE));
        SETTABLECENTER(ui->tableWidgetAllot->item(i, TWO));
        SETTABLECENTER(ui->tableWidgetAllot->item(i, THREE));
        SETTABLECENTER(ui->tableWidgetAllot->item(i, FOUR));
    }

    if(selectFlage)
    {
        ui->tableWidgetAllot->scrollToBottom();
        ui->tableWidgetAllot->selectRow(ui->tableWidgetAllot->rowCount() - 1);
    }
}

/*********************  设置控件数据        *********************/
void InventoryTransfer::setControlData()
{
    ui->lineEditNumberInfo->setText(mapAllotInfo.value(HTTPKEY::ALLOTNUMBER));
    ui->lineEditRemarkInfo->setText(mapAllotInfo.value(HTTPKEY::REMARK));
    ui->lineEditWareHseInInfo->setText(mapAllotInfo.value(HTTPKEY::ENTERNAME));
    ui->lineEditWareHseOutInfo->setText(mapAllotInfo.value(HTTPKEY::OUTNAME));

    int allotType = mapAllotInfo.value(HTTPKEY::STATE).toInt();

    QString statusStr;
    switch(allotType)
    {
    case ZERO:  statusStr = tr("未提交"); break;
    case ONE:   statusStr = tr("调拨中"); break;
    case TWO:   statusStr = tr("已完成"); break;
    case THREE: statusStr = tr("已拒绝"); break;
    }

    if(ZERO == allotType)
    {
        if(allotMatMapList.size() != 0)
        {
            ui->pushButtonSubmit->show();
        }
        else
        {
            ui->pushButtonSubmit->setHidden(true);
        }

        ui->commandLinkButtonEdit->show();
        ui->pushButtonAllotMatInfo->show();
        ui->pushButtonDel->show();
        ui->pushButtonSaveInfo->show();
        ui->pushButtonCancelInfo->show();
        ui->pushButtonReConfirm->setHidden(true);
        ui->pushButtonRefuse->setHidden(true);
        ui->pushButtonFinish->setHidden(true);

        ui->dateEditArriveTimeInfo->setEnabled(true);
        ui->timeEditTimeInfo->setEnabled(true);
        ui->lineEditRemarkInfo->setEnabled(true);
        materialTranDet->setShow();
    }
    else if(ONE == allotType)
    {
        ui->pushButtonAllotMatInfo->setHidden(true);
        ui->commandLinkButtonEdit->show();
        ui->pushButtonSubmit->setHidden(true);
        ui->pushButtonReConfirm->setHidden(true);

        ui->dateEditArriveTimeInfo->setEnabled(true);
        ui->timeEditTimeInfo->setEnabled(true);
        ui->lineEditRemarkInfo->setEnabled(true);

        ui->pushButtonRefuse->show();
        ui->pushButtonFinish->show();
        ui->pushButtonDel->show();
        ui->pushButtonSaveInfo->show();
        ui->pushButtonCancelInfo->show();

        materialTranDet->setShow();
    }
    else
    {
        ui->pushButtonDel->setHidden(true);
        ui->pushButtonSaveInfo->setHidden(true);
        ui->pushButtonAllotMatInfo->setHidden(true);
        ui->pushButtonRefuse->setHidden(true);
        ui->pushButtonFinish->setHidden(true);
        ui->pushButtonCancelInfo->setHidden(true);
        ui->pushButtonReConfirm->setHidden(true);
        ui->commandLinkButtonEdit->setHidden(true);
        ui->dateEditArriveTimeInfo->setEnabled(false);
        ui->timeEditTimeInfo->setEnabled(false);
        ui->lineEditRemarkInfo->setEnabled(false);
        ui->pushButtonSubmit->setHidden(true);

        if(TWO == allotType) ui->pushButtonReConfirm->show();

        materialTranDet->setHide();
    }

    QDateTime dateTime = QDateTime::fromTime_t(mapAllotInfo.value(HTTPKEY::ALLOTTIME).toUInt());

    ui->dateEditArriveTimeInfo->setDateTime(dateTime);
    ui->timeEditTimeInfo->setTime(dateTime.time());

    ui->labelTotalCount->setText(tr("合计%1项").arg(allotMatMapList.size()));

    ui->tableWidgetAllotInfo->setRowCount(allotMatMapList.size());
    for(int i = 0; i < allotMatMapList.size(); i ++)
    {
        ui->tableWidgetAllotInfo->setItem(i, ZERO,  DATA(allotMatMapList.at(i).value(HTTPKEY::MATERIALNAME)));
        ui->tableWidgetAllotInfo->setItem(i, ONE,   DATA(allotMatMapList.at(i).value(HTTPKEY::BARCODE)));
        ui->tableWidgetAllotInfo->setItem(i, TWO,   DATA(allotMatMapList.at(i).value(HTTPKEY::UNITNAME)));
        ui->tableWidgetAllotInfo->setItem(i, THREE, DATA(allotMatMapList.at(i).value(HTTPKEY::COSTPRICE)));
        ui->tableWidgetAllotInfo->setItem(i, FOUR,  DATA(allotMatMapList.at(i).value(HTTPKEY::NUMBER)));

        SETTABLECENTER(ui->tableWidgetAllotInfo->item(i, ZERO));
        SETTABLECENTER(ui->tableWidgetAllotInfo->item(i, ONE));
        SETTABLECENTER(ui->tableWidgetAllotInfo->item(i, TWO));
        SETTABLECENTER(ui->tableWidgetAllotInfo->item(i, THREE));
        SETTABLECENTER(ui->tableWidgetAllotInfo->item(i, FOUR));
    }
    ui->tableWidgetAllotInfo->scrollToBottom();
}

/*********************  设置添加调拨数据        *********************/
void InventoryTransfer::setAddControlData()
{
    ui->comboBoxWarHseIn->clear();
    ui->comboBoxWarHseOut->clear();
    for(int i = 0; i < wareHouseMapList.size(); i ++)
    {
        ui->comboBoxWarHseIn->addItem(wareHouseMapList.at(i).value(HTTPKEY::NAME));
        ui->comboBoxWarHseOut->addItem(wareHouseMapList.at(i).value(HTTPKEY::NAME));
    }
}

/*********************  清空添加数据        *********************/
void InventoryTransfer::clearAddInfo()
{
    ui->lineEditRemark->clear();

    ui->dateEditArriveTime->setDate(QDate::currentDate());
    ui->timeEditAddTime->setDateTime(QDateTime::currentDateTime());
}

/*********************  编辑调拨原料        *********************/
void InventoryTransfer::on_commandLinkButtonEdit_clicked()
{
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ALLOT_UPDATE_ALL_PAGE).arg(allotNumber), PROTOCOL::URL_ALLOT_UPDATE_ALL_PAGE);
    editTranMaterial->showWidget(AddStoMaterial::EDITTYPE);
    editTranMaterial->setTableEidiData();
}

/*********************  添加调拨原料        *********************/
void InventoryTransfer::on_pushButtonAllotMatInfo_clicked()
{
    editTranMaterial->showWidget(AddStoMaterial::ADDTYPE);
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ALLOT_SEL_MAT).arg(allotNumber), PROTOCOL::URL_ALLOT_SEL_MAT);
}

/*********************  更新数据        *********************/
void InventoryTransfer::on_pushButtonSaveInfo_clicked()
{
    QByteArray byteArray;

    QString strPost = POSTARG::UPDATETRAN.arg(mapAllotInfo.value(HTTPKEY::ALLOTID));

    unsigned int timeInt = GETTIMET(ui->timeEditTimeInfo->time()) + GETDATATIMET(ui->dateEditArriveTimeInfo->dateTime());

    strPost = strPost.arg(QString::number(timeInt), ui->lineEditRemarkInfo->text());

    byteArray.append(strPost);

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_ALLOT_UPDATE), byteArray, PROTOCOL::URL_ALLOT_UPDATE);
}

/*********************  双击查询原料信息        *********************/
void InventoryTransfer::on_tableWidgetAllotInfo_doubleClicked(const QModelIndex &index)
{
    if(index.row() >= allotMatMapList.size()) return;

    allotMatId = allotMatMapList.at(index.row()).value(HTTPKEY::ALLOTMATERIALID);

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ALLOT_GET_MAT).arg(allotMatId), PROTOCOL::URL_ALLOT_GET_MAT);
}

/*********************  取消事件        *********************/
void InventoryTransfer::on_pushButtonCancelInfo_clicked()
{
    ui->tabWidgetAllot->setHidden(true);
}

/*********************   添加调拨单        *********************/
void InventoryTransfer::on_pushButtonAdd_clicked()
{
    saveFlage = false;
    this->clearAddInfo();
    ui->tabWidgetAllot->addTab(ui->tabAddAllot, GLOBALDEF::TRANADD);
    ui->tabWidgetAllot->setCurrentWidget(ui->tabAddAllot);
    ui->tabWidgetAllot->removeTab(ui->tabWidgetAllot->indexOf(ui->tabAllotInfo));
    ui->tabWidgetAllot->show();

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ALLOT_ADD_PAGE), PROTOCOL::URL_ALLOT_ADD_PAGE);
}

/*********************   保存调拨单        *********************/
void InventoryTransfer::on_pushButtonSave_clicked()
{
    int inCurrentIndex = ui->comboBoxWarHseIn->currentIndex();
    if(inCurrentIndex < 0 || inCurrentIndex >= wareHouseMapList.size()) return;

    int outCurrentIndex = ui->comboBoxWarHseOut->currentIndex();
    if(outCurrentIndex < 0 || outCurrentIndex >= wareHouseMapList.size()) return;

    if(inCurrentIndex == outCurrentIndex)
    {
        MESSAGEBOX->showMessageBox(this, MESSAGE::TRANCANOTSAME);
        return;
    }

    showType = SHOWSUCCESS;

    QByteArray byteArray;

    QString strPost = POSTARG::ADDTRAN.arg(wareHouseMapList.at(inCurrentIndex).value(HTTPKEY::WAREHOUSEID));

    strPost = strPost.arg(wareHouseMapList.at(outCurrentIndex).value(HTTPKEY::WAREHOUSEID));

    strPost = strPost.arg(QString::number(ui->timeEditAddTime->dateTime().toTime_t()), ui->lineEditRemark->text());

    byteArray.append(strPost);

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_ALLOT_ADD), byteArray, PROTOCOL::URL_ALLOT_ADD);
}

/*********************   添加调拨原料        *********************/
void InventoryTransfer::on_pushButtonAddAllotMat_clicked()
{
    if(!saveFlage)
    {
        on_pushButtonSave_clicked();
    }

    if(ui->comboBoxWarHseIn->currentIndex() == ui->comboBoxWarHseOut->currentIndex()) return;

    addTranMaterial->showWidget(AddStoMaterial::ADDTYPE);
    showType = NOTSHOW;
}

/*********************   取消按钮          *********************/
void InventoryTransfer::on_pushButtonCancel_clicked()
{
    ui->tabWidgetAllot->setHidden(true);
}

/*********************   拒绝收货        *********************/
void InventoryTransfer::on_pushButtonRefuse_clicked()
{
    refuseTranWidget->setNumber(mapAllotInfo.value(HTTPKEY::ALLOTNUMBER));
    refuseTranWidget->setType(RefuseTranWidget::REFUSE);
    refuseTranWidget->showWidget();
}

/*********************   调拨完成        *********************/
void InventoryTransfer::on_pushButtonFinish_clicked()
{
    QByteArray byteArray;

    byteArray.append(POSTARG::FINISHTRAN.arg(allotNumber));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_ALLOT_AFFIRM), byteArray, PROTOCOL::URL_ALLOT_AFFIRM);
}

/*********************   反确认        *********************/
void InventoryTransfer::on_pushButtonReConfirm_clicked()
{
    refuseTranWidget->setNumber(mapAllotInfo.value(HTTPKEY::ALLOTNUMBER));
    refuseTranWidget->setType(RefuseTranWidget::RECONFIRM);
    refuseTranWidget->showWidget();
}

/*********************   删除调拨单        *********************/
void InventoryTransfer::on_pushButtonDel_clicked()
{
    QByteArray byteArray;

    byteArray.append(POSTARG::DELTRAN.arg(mapAllotInfo.value(HTTPKEY::ALLOTNUMBER)));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_ALLOT_DEL), byteArray, PROTOCOL::URL_ALLOT_DEL);
}

/*********************   导出邮箱        *********************/
void InventoryTransfer::on_pushButtonExtend_clicked()
{
    extendEmail->showWidget();
}

/*********************   处理记录        *********************/
void InventoryTransfer::on_commandLinkButtonLog_clicked()
{
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ALLOT_SEL_DISPOSE).arg(allotNumber), PROTOCOL::URL_ALLOT_SEL_DISPOSE);
}

/*********************  调拨订单详情        *********************/
void InventoryTransfer::on_tableWidgetAllot_clicked(const QModelIndex &index)
{
    if(index.row() >= allotMapList.size()) return;

    ui->tabWidgetAllot->addTab(ui->tabAllotInfo, GLOBALDEF::TRANINFO);
    ui->tabWidgetAllot->setCurrentWidget(ui->tabAllotInfo);
    ui->tabWidgetAllot->removeTab(ui->tabWidgetAllot->indexOf(ui->tabAddAllot));
    ui->tabWidgetAllot->show();

    allotState = allotMapList.at(index.row()).value(HTTPKEY::STATE);
    allotId = allotMapList.at(index.row()).value(HTTPKEY::ALLOTID);
    allotNumber = allotMapList.at(index.row()).value(HTTPKEY::ALLOTNUMBER);

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ALLOT_SEL).arg(allotNumber), PROTOCOL::URL_ALLOT_SEL);
}

/*********************  提交调拨单        *********************/
void InventoryTransfer::on_pushButtonSubmit_clicked()
{
    QByteArray byteArray;

    byteArray.append(POSTARG::SUBMITTRAN.arg(mapAllotInfo.value(HTTPKEY::ALLOTNUMBER)));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_ALLOT_PRESEND), byteArray, PROTOCOL::URL_ALLOT_PRESEND);
}

/*********************  查询调拨单        *********************/
void InventoryTransfer::on_pushButtonSelect_clicked()
{
    ui->tabWidgetAllot->setHidden(true);
    int warHseOutIndex = ui->comboBoxWarHseOutSelect->currentIndex();
    if(warHseOutIndex < 0 || warHseOutIndex >= warHseSelectMapList.size()) return;

    int warHseInIndex = ui->comboBoxWarHseInSelect->currentIndex();
    if(warHseInIndex < 0 || warHseInIndex >= warHseSelectMapList.size()) return;

    int staIndex = ui->comboBoxStateSelect->currentIndex();
    if(staIndex < 0 || staIndex >= staSelectMapList.size()) return;

    QString stateId  = staSelectMapList.at(staIndex).value(HTTPKEY::STATEID);
    QString warHseOutId = warHseSelectMapList.at(warHseOutIndex).value(HTTPKEY::WAREHOUSEID);
    QString warHseInId = warHseSelectMapList.at(warHseInIndex).value(HTTPKEY::WAREHOUSEID);
    QString strTime = QString::number(ui->dateEditSelect->dateTime().toTime_t());

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ALLOT_SELECT).
                          arg(stateId, warHseOutId, warHseInId, strTime), PROTOCOL::URL_ALLOT_SELECT);
}
