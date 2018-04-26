#include "inventorycheck.h"
#include "ui_inventorycheck.h"
#include "httpclient/httpkey.h"
#include "messagebox/messagedialog.h"

/***************       构造函数     *****************/
InventoryCheck::InventoryCheck(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InventoryCheck)
  ,showType(NOTSHOW), importFlage(false), saveFlage(false), selectFlage(true)
{
    ui->setupUi(this);

    this->initControl();
}

/***************       析构函数     *****************/
InventoryCheck::~InventoryCheck()
{
    delete ui;
}

/***************       显示窗口     *****************/
void InventoryCheck::showWidget()
{
    this->show();
    importFlage = false;
    ui->tabWidgetCheck->setHidden(true);

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_CHECK_SEL_ALL), PROTOCOL::URL_CHECK_SEL_ALL);
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_CHECK_SELECT_PAGE), PROTOCOL::URL_CHECK_SELECT_PAGE);
}

/*********************  初始化控件       *********************/
void InventoryCheck::initControl()
{
    SETTABLEWIDGET(ui->tableWidgetCheck);

    ui->dateEditSelect->setCalendarPopup(true);
    ui->dateEditCheckTimeInfo->setCalendarPopup(true);
    ui->dateEditSelect->setDate(QDate::currentDate());
    ui->comboBoxWarHse->setView(new QListView());
    ui->comboBoxWarHseInfo->setView(new QListView());
    ui->comboBoxStateSelect->setView(new QListView());
    ui->comboBoxWarHseSelect->setView(new QListView());

    ui->comboBoxStateSelect->view()->setMinimumWidth(200);
    ui->comboBoxWarHseSelect->view()->setMinimumWidth(200);

    ui->comboBoxWarHse->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxWarHseInfo->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxStateSelect->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxWarHseSelect->setFocusPolicy(Qt::NoFocus);

    if(CONFIGJSON->getLanguage().toInt())
    {
        ui->dateEditSelect->calendarWidget()->setLocale(QLocale(QLocale::English));
        ui->dateEditCheckTimeInfo->calendarWidget()->setLocale(QLocale(QLocale::English));
    }

    materialCheckInfo  = new MaterialCheckInfo(this);
    logInfo            = new LogInfo(this);
    extendCheckEmail   = new ExtendCheckEmail(this);
    importCheckHistory = new ImportCheckHistory(this);

    //根据分辨率适配
    QDesktopWidget *desktop = QApplication::desktop();

    int minHeight = 0;
    if(desktop->height() >= GLOBALDEF::DESKTOPHEIGHT)
    {
        minHeight = 30;
        ui->tabCheckInfo->layout()->setSpacing(6);
        ui->tabAddCheck->layout()->setSpacing(6);
        this->setStyleSheet(GLOBALDEF::THISSTYLE);
    }
    else
    {
        minHeight = 20;
        this->setStyleSheet(GLOBALDEF::SMALLSTYLE);
    }

    ui->labelState->setMinimumHeight(minHeight);
    ui->labelWhse->setMinimumHeight(minHeight);
    ui->labelDateTime->setMinimumHeight(minHeight);
    ui->labelSize->setMinimumHeight(minHeight);

    FlowLayout *flowLayout = new FlowLayout(ui->widgetControl);

    flowLayout->addWidget(ui->labelState);
    flowLayout->addWidget(ui->comboBoxStateSelect);
    flowLayout->addWidget(ui->labelWhse);
    flowLayout->addWidget(ui->comboBoxWarHseSelect);
    flowLayout->addWidget(ui->labelDateTime);
    flowLayout->addWidget(ui->dateEditSelect);
    flowLayout->addWidget(ui->pushButtonSelect);
    flowLayout->addWidget(ui->pushButtonExtend);
    flowLayout->addWidget(ui->pushButtonAdd);
    flowLayout->addWidget(ui->labelSize);

    ui->widgetControl->setLayout(flowLayout);
}

/*********************  解析json       *********************/
void InventoryCheck::readJson(QNetworkReply *reply, int type)
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

                if(type == PROTOCOL::URL_CHECK_SEL_ALL || type == PROTOCOL::URL_CHECK_SELECT)
                {
                    if(ISERROR(codeValue))
                    {
                        ui->tableWidgetCheck->clearContents();
                        ui->tableWidgetCheck->setRowCount(0);
                        mapCheckList.clear();

                        extendCheckEmail->setDataMapList(mapCheckList);
                        ui->labelSize->setText(GLOBALDEF::TOTALONUMBER.arg(0));
                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, mapCheckList);

                    if(!importFlage)
                    {
                        this->setTableData();
                        extendCheckEmail->setDataMapList(mapCheckList);
                    }
                    else
                    {
                        importCheckHistory->setPurMapList(mapCheckList);
                        importFlage = false;
                    }

                }
                else if(type == PROTOCOL::URL_CHECK_SEL)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::WAREHOUSE_LIST, mapWareHouseList);
                    HTTPCLIENT->readJsonMap(jsonNextObj, HTTPKEY::CHECKDATA, mapCheckData);

                    this->setControlData();

                    materialCheckInfo->setWareHouseId(mapCheckData.value(HTTPKEY::WAREHOUSEID));
                    materialCheckInfo->setCheckNumber(mapCheckData.value(HTTPKEY::CHECKNUMBER));
                    materialCheckInfo->getAddCheckMat()->setCheckNumber(mapCheckData.value(HTTPKEY::CHECKNUMBER));
                }
                else if(type == PROTOCOL::URL_CHECK_ADD_PAGE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO) errorMsg = MESSAGE::ERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, mapWareHouseList);
                    this->setAddControlData();
                }
                else if(type == PROTOCOL::URL_CHECK_ADD)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ADDERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;
                        else if(codeValue == THREE) errorMsg = MESSAGE::CHECKISEXIST;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectFlage = true;
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_CHECK_SEL_ALL), PROTOCOL::URL_CHECK_SEL_ALL);

                    if(!saveFlage &&  showType == SHOW)
                    {
                        materialCheckInfo->showWidget();

                        QString checkNumber = jsonNextObj.value(HTTPKEY::CHECKNUMBER).toString();
                        QString checkState =  "0";

                        HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_CHECK_MAT_PAGE).arg(checkNumber, checkState), PROTOCOL::URL_CHECK_MAT_PAGE);

                        wareHouseCheckId = jsonNextObj.value(HTTPKEY::WAREHOUSECHECKID).toString();

                        HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_CHECK_SEL).arg(wareHouseCheckId), PROTOCOL::URL_CHECK_SEL);

                        ui->tabWidgetCheck->addTab(ui->tabCheckInfo, GLOBALDEF::CHECKINFO);
                        ui->tabWidgetCheck->setCurrentWidget(ui->tabCheckInfo);
                        ui->tabWidgetCheck->removeTab(ui->tabWidgetCheck->indexOf(ui->tabAddCheck));
                        ui->tabWidgetCheck->show();
                    }
                    else
                    {
                        ui->tabWidgetCheck->setHidden(true);
                    }
                    saveFlage = true;
                }
                else if(type == PROTOCOL::URL_CHECK_UPDATE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::EDITERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;
                        else if(codeValue == THREE) errorMsg = MESSAGE::CHECKISEXIST;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectFlage = false;
                    showWidget();
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::EDITSUCCESS, true);
                }
                else if(type == PROTOCOL::URL_CHECK_MAT_PAGE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO) errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    materialCheckInfo->showWidget();

                    MapList mapListData;

                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::MATERIAL, mapListData);

                    materialCheckInfo->setMapMatList(mapListData);
                }
                else if(type == PROTOCOL::URL_CHECK_ADD_MAT_PAGE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO) errorMsg = MESSAGE::ERROR;

                        MESSAGEBOX->showMessageBox(materialCheckInfo, errorMsg);
                        return;
                    }

                    materialCheckInfo->getAddCheckMat()->showWidget();

                    Map mapData;

                    HTTPCLIENT->readJsonMap(jsonObject, HTTPKEY::MSG, mapData);

                    MapList mapListData;
                    for(auto iter = mapData.begin(); iter != mapData.end(); iter ++)
                    {
                        Map mapIter;
                        HTTPCLIENT->readJsonMap(jsonNextObj, iter.key(), mapIter);

                        if(!mapIter.isEmpty()) mapListData.append(mapIter);
                    }

                    materialCheckInfo->getAddCheckMat()->setMapMatList(mapListData);
                }
                else if(type == PROTOCOL::URL_CHECK_ADD_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO) errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(materialCheckInfo->getAddCheckMat(), errorMsg);
                        return;
                    }

                    QString checkNumber = mapCheckData.value(HTTPKEY::CHECKNUMBER);
                    QString checkState =  mapCheckData.value(HTTPKEY::CHECKSTATE);

                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_CHECK_SEL).arg(wareHouseCheckId), PROTOCOL::URL_CHECK_SEL);
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_CHECK_MAT_PAGE).arg(checkNumber, checkState), PROTOCOL::URL_CHECK_MAT_PAGE);
                }
                else if(type == PROTOCOL::URL_CHECK_UPDATE_MAT_PAGE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    Map mapData;
                    HTTPCLIENT->readJsonMap(jsonNextObj, HTTPKEY::MATERIAL, mapData);

                    MapList mapListData;
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::UNITLIST, mapListData);

                    materialCheckInfo->getMaterialCheckDet()->setMatMap(mapData);
                    materialCheckInfo->getMaterialCheckDet()->setUnitMapList(mapListData);
                    materialCheckInfo->getMaterialCheckDet()->showWidget();

                    materialCheckInfo->getMaterialCheckDet()->setControlData();
                }
                else if(type == PROTOCOL::URL_CHECK_UPDATE_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    QString checkNumber = mapCheckData.value(HTTPKEY::CHECKNUMBER);
                    QString checkState =  mapCheckData.value(HTTPKEY::CHECKSTATE);

                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_CHECK_MAT_PAGE).arg(checkNumber, checkState), PROTOCOL::URL_CHECK_MAT_PAGE);
                }
                else if(type == PROTOCOL::URL_CHECK_UNIT_UPDATE_NUM)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    Map mapData;

                    HTTPCLIENT->readJsonMap(jsonObject, HTTPKEY::MSG, mapData);

                    materialCheckInfo->getMaterialCheckDet()->setMapNumber(mapData);
                }
                else if(type == PROTOCOL::URL_CHECK_UPDATE_NUM)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::EDITSUCCESS, true);
                }
                else if(type == PROTOCOL::URL_CHECK_CANCEL)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectFlage = false;
                    showWidget();
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::SUCCESS, true);
                }
                else if(type == PROTOCOL::URL_CHECK_DEL)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::DELERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectFlage = true;
                    showWidget();
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::DELSUCCESS, true);
                }
                else if(type == PROTOCOL::URL_CHECK_IMPORT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;
                        else if(codeValue == THREE) errorMsg = MESSAGE::NOWWARINVING;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectFlage = true;
                    showWidget();
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::IMPORTSUCCESS, true);
                }
                else if(type == PROTOCOL::URL_CHECK_AFFIRM)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectFlage = false;
                    showWidget();
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::SUCCESS, true);
                }
                else if(type == PROTOCOL::URL_CHECK_SEND_EMAIL)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::EXTENDERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::EXPORTSUCCESS, true);
                }
                else if(type == PROTOCOL::URL_CHECK_SEL_DISPOSE)
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
                else if(type == PROTOCOL::URL_CHECK_DEL_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::DELERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    QString checkNumber = mapCheckData.value(HTTPKEY::CHECKNUMBER);
                    QString checkState =  mapCheckData.value(HTTPKEY::CHECKSTATE);

                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_CHECK_SEL).arg(wareHouseCheckId), PROTOCOL::URL_CHECK_SEL);
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_CHECK_MAT_PAGE).arg(checkNumber, checkState), PROTOCOL::URL_CHECK_MAT_PAGE);
                }
                else if(type == PROTOCOL::URL_CHECK_SELECT_PAGE)
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
                            if(stateName == GLOBALDEF::CHIALL)               stateName = GLOBALDEF::ENGALL;
                            else if(stateName == GLOBALDEF::CHIINVENT)       stateName = GLOBALDEF::ENGINVENT;
                            else if(stateName == GLOBALDEF::CHICOMPLETE)     stateName = GLOBALDEF::ENGCOMPLETE;
                            else if(stateName == GLOBALDEF::CHICANCELINVENT) stateName = GLOBALDEF::ENGCANCELINVENT;
                        }

                        ui->comboBoxStateSelect->addItem(stateName);
                    }

                    ui->comboBoxWarHseSelect->clear();
                    for(int i = 0; i < warHseSelectMapList.size(); i ++)
                    {
                        QString whseName = warHseSelectMapList.at(i).value(HTTPKEY::WAREHOUSENAME);

                        if(CONFIGJSON->getLanguage().toInt())
                        {
                            if(whseName == GLOBALDEF::CHIALL) whseName = GLOBALDEF::ENGALL;
                        }

                        ui->comboBoxWarHseSelect->addItem(whseName);
                    }
                }
            }
        }
        reply->close();
    }
}

/*********************  设置表格数据       *********************/
void InventoryCheck::setTableData()
{
    ui->tableWidgetCheck->setRowCount(mapCheckList.size());
    ui->labelSize->setText(GLOBALDEF::TOTALONUMBER.arg(mapCheckList.size()));

    for(int i = 0; i < mapCheckList.size(); i ++)
    {
        ui->tableWidgetCheck->setItem(i, ZERO,  DATA(mapCheckList.at(i).value(HTTPKEY::WAREHOUSENAME)));
        ui->tableWidgetCheck->setItem(i, ONE,   DATA(mapCheckList.at(i).value(HTTPKEY::CHECKNUMBER)));
        ui->tableWidgetCheck->setItem(i, TWO,   DATA(QDateTime::fromTime_t(mapCheckList.at(i).value(HTTPKEY::CHECKTIME).toUInt()).toString("yyyy-MM-dd")));
        ui->tableWidgetCheck->setItem(i, THREE, DATA(""));

        QTableWidgetItem * itemThree = ui->tableWidgetCheck->item(i, THREE);
        ui->tableWidgetCheck->item(i, THREE)->setFont(QFont("ZYSong", 12, QFont::Bold));
        switch(mapCheckList.at(i).value(HTTPKEY::CHECKSTATE).toInt())
        {
        case ZERO:  itemThree->setTextColor(Qt::darkBlue);  itemThree->setText(tr("盘存中"));   break;
        case ONE:   itemThree->setTextColor(Qt::darkGreen); itemThree->setText(tr("已完成"));   break;
        case TWO:   itemThree->setTextColor(Qt::darkRed);   itemThree->setText(tr("取消盘存")); break;
        }

        SETTABLECENTER(ui->tableWidgetCheck->item(i, ZERO));
        SETTABLECENTER(ui->tableWidgetCheck->item(i, ONE));
        SETTABLECENTER(ui->tableWidgetCheck->item(i, TWO));
        SETTABLECENTER(ui->tableWidgetCheck->item(i, THREE));
    }

    if(selectFlage)
    {
        ui->tableWidgetCheck->scrollToBottom();
        ui->tableWidgetCheck->selectRow(ui->tableWidgetCheck->rowCount() - 1);
    }
}

/*********************  设置控件数据       *********************/
void InventoryCheck::setControlData()
{
    ui->lineEditNumberInfo->setText(mapCheckData.value(HTTPKEY::CHECKNUMBER));
    ui->commandLinkButtonMatListInfo->setText(mapCheckData.value(HTTPKEY::MATERIALNUMBER) + tr("项原料"));

    QDateTime dateTime = QDateTime::fromTime_t(mapCheckData.value(HTTPKEY::CHECKTIME).toUInt());

    ui->dateEditCheckTimeInfo->setDate(dateTime.date());
    ui->timeEditCheckTimeInfo->setTime(dateTime.time());

    ui->comboBoxWarHseInfo->clear();
    for(int i = 0; i < mapWareHouseList.size(); i ++)
    {
        ui->comboBoxWarHseInfo->addItem(mapWareHouseList.at(i).value(HTTPKEY::NAME));

        if(mapWareHouseList.at(i).value(HTTPKEY::WAREHOUSEID) == mapCheckData.value(HTTPKEY::WAREHOUSEID))
        {
            ui->comboBoxWarHseInfo->setCurrentIndex(i);
        }
    }

    switch(mapCheckData.value(HTTPKEY::CHECKSTATE).toInt())
    {
    case ZERO: ui->lineEditCheckState->setText(tr("盘存中"));   break;
    case ONE:  ui->lineEditCheckState->setText(tr("已完成"));   break;
    case TWO:  ui->lineEditCheckState->setText(tr("取消盘存")); break;
    }

    if(mapCheckData.value(HTTPKEY::CHECKSTATE).toInt() == 0)
    {
        ui->labelDate->setHidden(true);
        ui->labelTime->setHidden(true);
        ui->dateEditCheckTimeInfo->setHidden(true);
        ui->timeEditCheckTimeInfo->setHidden(true);

        ui->pushButtonCancelInfo->show();

        ui->pushButtonDeleteInfo->show();
        ui->pushButtonSaveInfo->show();


        ui->comboBoxWarHseInfo->setEnabled(true);

        materialCheckInfo->setShow();

        if(mapCheckData.value(HTTPKEY::MATERIALNUMBER).toInt() <= 0)
        {
            ui->pushButtonCancelCheckInfo->setHidden(true);
            ui->pushButtonCheckFinishInfo->setHidden(true);
        }
        else
        {
            ui->pushButtonCancelCheckInfo->show();
            ui->pushButtonCheckFinishInfo->show();
        }
    }
    else
    {
        ui->labelDate->show();
        ui->labelTime->show();
        ui->dateEditCheckTimeInfo->show();
        ui->timeEditCheckTimeInfo->show();
        ui->pushButtonCancelInfo->setHidden(true);
        ui->pushButtonCancelCheckInfo->setHidden(true);
        ui->pushButtonDeleteInfo->setHidden(true);
        ui->pushButtonSaveInfo->setHidden(true);
        ui->pushButtonCheckFinishInfo->setHidden(true);

        ui->comboBoxWarHseInfo->setEnabled(false);

        materialCheckInfo->setHide();

        if(mapCheckData.value(HTTPKEY::CHECKSTATE).toInt() == TWO)
        {
            ui->labelDate->setHidden(true);
            ui->labelTime->setHidden(true);
            ui->dateEditCheckTimeInfo->setHidden(true);
            ui->timeEditCheckTimeInfo->setHidden(true);
        }
    }
}

/*********************  设置添加控件数据       *********************/
void InventoryCheck::setAddControlData()
{
    ui->comboBoxWarHse->clear();
    for(int i = 0; i < mapWareHouseList.size(); i ++)
    {
        ui->comboBoxWarHse->addItem(mapWareHouseList.at(i).value(HTTPKEY::NAME));
    }
}

/*********************  点击控件       *********************/
void InventoryCheck::on_tableWidgetCheck_clicked(const QModelIndex &index)
{
    if(index.row() < 0 || index.row() >= mapCheckList.size()) return;

    ui->tabWidgetCheck->addTab(ui->tabCheckInfo, GLOBALDEF::CHECKINFO);
    ui->tabWidgetCheck->setCurrentWidget(ui->tabCheckInfo);
    ui->tabWidgetCheck->removeTab(ui->tabWidgetCheck->indexOf(ui->tabAddCheck));
    ui->tabWidgetCheck->show();

    wareHouseCheckId = mapCheckList.at(index.row()).value(HTTPKEY::WAREHOUSECHECKID);

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_CHECK_SEL).arg(wareHouseCheckId), PROTOCOL::URL_CHECK_SEL);
}

/*********************  添加盘存单       *********************/
void InventoryCheck::on_pushButtonAdd_clicked()
{
    saveFlage = false;
    ui->tabWidgetCheck->addTab(ui->tabAddCheck, GLOBALDEF::ADDCHECK);
    ui->tabWidgetCheck->setCurrentWidget(ui->tabAddCheck);
    ui->tabWidgetCheck->removeTab(ui->tabWidgetCheck->indexOf(ui->tabCheckInfo));
    ui->tabWidgetCheck->show();

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_CHECK_ADD_PAGE), PROTOCOL::URL_CHECK_ADD_PAGE);
}

/*********************  删除信息       *********************/
void InventoryCheck::on_pushButtonDeleteInfo_clicked()
{
    QByteArray byteArray;

    byteArray.append(POSTARG::DELCHECK.arg(mapCheckData.value(HTTPKEY::CHECKNUMBER)));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_CHECK_DEL), byteArray, PROTOCOL::URL_CHECK_DEL);
}

/*********************  更新信息       *********************/
void InventoryCheck::on_pushButtonSaveInfo_clicked()
{
    int currentRow = ui->comboBoxWarHseInfo->currentIndex();

    if(currentRow < 0 || currentRow >= mapWareHouseList.size()) return;

    QString checkNumber = mapCheckData.value(HTTPKEY::CHECKNUMBER);

    QByteArray byteArray;

    QString wareHouseId = mapWareHouseList.at(currentRow).value(HTTPKEY::WAREHOUSEID);

    byteArray.append(POSTARG::UPDATECHECK.arg(checkNumber, wareHouseId));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_CHECK_UPDATE), byteArray, PROTOCOL::URL_CHECK_UPDATE);
}

/*********************  取消按钮       *********************/
void InventoryCheck::on_pushButtonCancelInfo_clicked()
{
    ui->tabWidgetCheck->setHidden(true);
}

/*********************  添加盘存单      *********************/
void InventoryCheck::on_pushButtonSave_clicked()
{
    showType = NOTSHOW;
    saveFlage = false;
    int currentRow = ui->comboBoxWarHse->currentIndex();

    if(currentRow < 0 || currentRow >= mapWareHouseList.size()) return;

    QByteArray byteArray;

    QString wareHouseId = mapWareHouseList.at(currentRow).value(HTTPKEY::WAREHOUSEID);

    byteArray.append(POSTARG::ADDCHECK.arg(wareHouseId));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_CHECK_ADD), byteArray, PROTOCOL::URL_CHECK_ADD);
}

/*********************  选择原料      *********************/
void InventoryCheck::on_commandLinkButtonMatList_clicked()
{
    if(!saveFlage)
    {
        on_pushButtonSave_clicked();
    }

    showType = SHOW;
}

/*********************  选择原料      *********************/
void InventoryCheck::on_commandLinkButtonMatListInfo_clicked()
{
    QString checkNumber = mapCheckData.value(HTTPKEY::CHECKNUMBER);
    QString checkState =  mapCheckData.value(HTTPKEY::CHECKSTATE);

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_CHECK_MAT_PAGE).arg(checkNumber, checkState), PROTOCOL::URL_CHECK_MAT_PAGE);
}

/*********************  处理记录      *********************/
void InventoryCheck::on_commandLinkButtonLog_clicked()
{
    QString checkNumber = mapCheckData.value(HTTPKEY::CHECKNUMBER);
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_CHECK_SEL_DISPOSE).arg(checkNumber), PROTOCOL::URL_CHECK_SEL_DISPOSE);
}

/*********************  导出EMAIL      *********************/
void InventoryCheck::on_pushButtonExtend_clicked()
{
    extendCheckEmail->showWidget();
}

/*********************  盘存完成      *********************/
void InventoryCheck::on_pushButtonCheckFinishInfo_clicked()
{
    QByteArray byteArray;

    QString checkNumber = mapCheckData.value(HTTPKEY::CHECKNUMBER);
    QString wareHouseId =  mapCheckData.value(HTTPKEY::WAREHOUSEID);

    byteArray.append(POSTARG::AFFIRMCHECK.arg(checkNumber, wareHouseId));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_CHECK_AFFIRM), byteArray, PROTOCOL::URL_CHECK_AFFIRM);
}

/*********************  取消盘存      *********************/
void InventoryCheck::on_pushButtonCancelCheckInfo_clicked()
{
    QByteArray byteArray;

    QString checkNumber = mapCheckData.value(HTTPKEY::CHECKNUMBER);

    byteArray.append(POSTARG::CANCELCHECK.arg(checkNumber));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_CHECK_CANCEL), byteArray, PROTOCOL::URL_CHECK_CANCEL);
}

/*********************  取消按钮      *********************/
void InventoryCheck::on_pushButtonCancel_clicked()
{
    ui->tabWidgetCheck->setHidden(true);
}

/*********************  导入历史盘存单  *********************/
void InventoryCheck::on_commandLinkButtonImport_clicked()
{
    importFlage = true;
    importCheckHistory->showWidget();
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_CHECK_SEL_ALL), PROTOCOL::URL_CHECK_SEL_ALL);
}

/*********************  查询盘存单  *********************/
void InventoryCheck::on_pushButtonSelect_clicked()
{
    ui->tabWidgetCheck->setHidden(true);
    int warHseIndex = ui->comboBoxWarHseSelect->currentIndex();
    if(warHseIndex < 0 || warHseIndex >= warHseSelectMapList.size()) return;

    int staIndex = ui->comboBoxStateSelect->currentIndex();
    if(staIndex < 0 || staIndex >= staSelectMapList.size()) return;

    QString stateId  = staSelectMapList.at(staIndex).value(HTTPKEY::STATEID);
    QString warHseId = warHseSelectMapList.at(warHseIndex).value(HTTPKEY::WAREHOUSEID);
    QString strTime = QString::number(ui->dateEditSelect->dateTime().toTime_t());

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_CHECK_SELECT).
                          arg(stateId, warHseId, strTime), PROTOCOL::URL_CHECK_SELECT);
}
