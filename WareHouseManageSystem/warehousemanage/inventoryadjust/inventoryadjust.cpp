#include "inventoryadjust.h"
#include "ui_inventoryadjust.h"
#include "httpclient/httpkey.h"
#include "messagebox/messagedialog.h"

/************************   构造函数       ********************/
InventoryAdjust::InventoryAdjust(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InventoryAdjust)
  ,showType(SHOWSUCCESS)
  ,selectFlage(true)
  ,saveFlage(false)
{
    ui->setupUi(this);

    this->initControl();
}

/************************   析构函数       ********************/
InventoryAdjust::~InventoryAdjust()
{
    delete ui;
}

/************************   显示窗口       ********************/
void InventoryAdjust::showWidget()
{
    this->show();
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ADJ_SELECT_PAGE), PROTOCOL::URL_ADJ_SELECT_PAGE);
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ADJ_GET_INV_LIST), PROTOCOL::URL_ADJ_GET_INV_LIST);
    ui->tabWidgetAdjust->setHidden(true);
}

/*********************  解析json       *********************/
void InventoryAdjust::readJson(QNetworkReply *reply, int type)
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

            if(type == PROTOCOL::URL_ADJ_ADD_INV)
            {
                selectFlage = true;
                saveFlage = true;
                oddNumber = jsonObject.value(HTTPKEY::ODDNUMBERS).toString();

                HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ADJ_GET_INV_LIST), PROTOCOL::URL_ADJ_GET_INV_LIST);
                if(showType == SHOWSUCCESS)
                {
                    ui->tabWidgetAdjust->setHidden(true);
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::ADDSUCCESS, true);
                }
                else
                {
                    addAdjMaterial->setOddNumber(oddNumber);
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ADJ_GET_MAT).arg(oddNumber), PROTOCOL::URL_ADJ_GET_MAT);
                }
            }

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

                if(type == PROTOCOL::URL_ADJ_WAREHOUSE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, wareHouseMapList);

                    ui->comboBoxWarHse->clear();
                    for(int i = 0; i < wareHouseMapList.size(); i ++)
                    {
                        ui->comboBoxWarHse->addItem(wareHouseMapList.at(i).value(HTTPKEY::NAME));
                    }
                }
                else if(type == PROTOCOL::URL_ADJ_TYPE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, typeMapList);

                    ui->comboBoxAdjustTypeInfo->clear();
                    ui->comboBoxAdjustType->clear();
                    for(int i = 0; i < typeMapList.size(); i ++)
                    {
                        ui->comboBoxAdjustTypeInfo->addItem(typeMapList.at(i).value(HTTPKEY::TYPENAME));
                        ui->comboBoxAdjustType->addItem(typeMapList.at(i).value(HTTPKEY::TYPENAME));
                    }
                    if(adjMapData.value(HTTPKEY::TYPENAME).isEmpty())
                    {
                        ui->comboBoxAdjustTypeInfo->setCurrentIndex(-1);
                    }
                    else
                    {
                        ui->comboBoxAdjustTypeInfo->setCurrentText(adjMapData.value(HTTPKEY::TYPENAME));
                    }

                    ui->comboBoxAdjustType->setCurrentIndex(-1);
                }
                else if(type == PROTOCOL::URL_ADJ_GET_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    MapList mapListData;

                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::MATERIALLIST, mapListData);

                    addAdjMaterial->setMapMatList(mapListData);
                    editAdjMaterial->setMapMatList(mapListData);

                    if(jsonNextObj.contains(HTTPKEY::ODDNUMBERS))
                    {
                        oddNumber = jsonNextObj.value(HTTPKEY::ODDNUMBERS).toString();
                    }

                    editAdjMaterial->setOddNumber(oddNumber);
                    addAdjMaterial->setOddNumber(oddNumber);
                }
                else if(type == PROTOCOL::URL_ADJ_ADD_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ADDERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectFlage = false;
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ADJ_GET_INV_LIST), PROTOCOL::URL_ADJ_GET_INV_LIST);
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ADJ_GET_DET).arg(oddNumber), PROTOCOL::URL_ADJ_GET_DET);
                    ui->tabWidgetAdjust->addTab(ui->tabAdjustInfo, GLOBALDEF::ADJUSTINFO);
                    ui->tabWidgetAdjust->setCurrentWidget(ui->tabAdjustInfo);
                    ui->tabWidgetAdjust->removeTab(ui->tabWidgetAdjust->indexOf(ui->tabAddAdjust));
                    ui->tabWidgetAdjust->show();

                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::ADDSUCCESS, true);
                }
                else if(type == PROTOCOL::URL_ADJ_GET_INV_LIST || type == PROTOCOL::URL_ADJ_SELECT)
                {
                    if(ISERROR(codeValue))
                    {
                        ui->tableWidgetAdjust->clearContents();
                        ui->tableWidgetAdjust->setRowCount(0);
                        mapListAdjust.clear();

                        extendEmailEmail->setDataMapList(mapListAdjust);
                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, mapListAdjust);

                    this->setAdjustTableData();

                    extendEmailEmail->setDataMapList(mapListAdjust);
                }
                else if(type == PROTOCOL::URL_ADJ_GET_DET)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::MATERIAL, adjMatMapList);
                    HTTPCLIENT->readJsonMap(jsonNextObj, HTTPKEY::JIBEN, adjMapData);
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::WAREHOUSELIST, wareHouseMapList);

                    materialAdjInfo->setWareHouseId(adjMapData.value(HTTPKEY::WAREHOUSEID));
                    addAdjMaterial->setWareHouseId(adjMapData.value(HTTPKEY::WAREHOUSEID));
                    editAdjMaterial->setWareHouseId(adjMapData.value(HTTPKEY::WAREHOUSEID));
                    editAdjMaterial->setMapSelectList(adjMatMapList);
                    editAdjMaterial->setOddNumber(adjMapData.value(HTTPKEY::ODDNUMBERS));

                    this->setControlData();
                }
                else if(type == PROTOCOL::URL_ADJ_GET_MAT_DET)
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

                    MapList mapListData;
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::UNIT, mapListData);

                    materialAdjInfo->setMatMap(mapData);
                    materialAdjInfo->setUnitMapList(mapListData);
                    materialAdjInfo->showWidget();
                    materialAdjInfo->setOddNumber(oddNumber);

                    materialAdjInfo->setControlData();
                }
                else if(type == PROTOCOL::URL_ADJ_UPDATE_DASIC)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::EDITERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    ui->tabWidgetAdjust->setHidden(true);
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ADJ_GET_DET).arg(oddNumber), PROTOCOL::URL_ADJ_GET_DET);
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::EDITSUCCESS, true);
                }
                else if(type == PROTOCOL::URL_ADJ_UPDATE_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::EDITERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::EDITSUCCESS, true);
                }
                else if(type == PROTOCOL::URL_ADJ_ADD_REASON)
                {
                    if(ISERROR(codeValue)) return;
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ADJ_GET_REASON), PROTOCOL::URL_ADJ_GET_REASON);
                }
                else if(type == PROTOCOL::URL_ADJ_GET_REASON)
                {
                    if(ISERROR(codeValue))
                    {
                        materialAdjInfo->getReasonWidget()->clearInfo();
                        return;
                    }

                    MapList mapListData;
                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, mapListData);

                    materialAdjInfo->getReasonWidget()->setReasonMapList(mapListData);
                }
                else if(type == PROTOCOL::URL_ADJ_DEL_REASON)
                {
                    if(ISERROR(codeValue)) return;
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ADJ_GET_REASON), PROTOCOL::URL_ADJ_GET_REASON);
                }
                else if(type == PROTOCOL::URL_ADJ_DEL_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::DELERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ADJ_GET_DET).arg(oddNumber), PROTOCOL::URL_ADJ_GET_DET);
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::DELSUCCESS, true);
                }
                else if(type == PROTOCOL::URL_ADJ_SEND_EMAIL)
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
                else if(type == PROTOCOL::URL_ADJ_DEL)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::DELERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    showWidget();
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::DELSUCCESS, true);
                }
                else if(type == PROTOCOL::URL_ADJ_SEL_DISPOSE)
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
                else if(type == PROTOCOL::URL_ADJ_PRESENT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;
                        else if(codeValue == THREE) errorMsg = MESSAGE::WARINVING;
                        else if(codeValue == FOUR)  errorMsg = MESSAGE::WARNOTEXIST;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectFlage = false;
                    showWidget();
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::SUCCESS, true);
                }
                else if(type == PROTOCOL::URL_ADJ_SELECT_PAGE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::ADJUSTMENTTYPE, typeSelectMapList);
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
                            else if(stateName == GLOBALDEF::CHIADJUST)    stateName = GLOBALDEF::ENGADJUST;
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

                    ui->comboBoxTypeSelect->clear();
                    for(int i = 0; i < typeSelectMapList.size(); i ++)
                    {
                        QString typeName = typeSelectMapList.at(i).value(HTTPKEY::TYPENAME);

                        if(CONFIGJSON->getLanguage().toInt())
                        {
                            if(typeName == GLOBALDEF::CHIALL) typeName = GLOBALDEF::ENGALL;
                        }

                        ui->comboBoxTypeSelect->addItem(typeName);
                    }
                }
                else if(type == PROTOCOL::URL_ADJ_CONVERT)
                {
                    if(ISERROR(codeValue)) return;

                    Map mapItem;

                    HTTPCLIENT->readJsonMap(jsonObject, HTTPKEY::MSG, mapItem);

                    materialAdjInfo->setConvert(mapItem);
                }
            }
        }
        reply->close();
    }
}

/*********************  设置表格数据        *********************/
void InventoryAdjust::setAdjustTableData()
{
    ui->labelSize->setText(GLOBALDEF::TOTALONUMBER.arg(mapListAdjust.size()));
    ui->tableWidgetAdjust->setRowCount(mapListAdjust.size());

    for(int i = 0; i < mapListAdjust.size(); i ++)
    {
        ui->tableWidgetAdjust->setItem(i, ZERO,  DATA(mapListAdjust.at(i).value(HTTPKEY::NAME)));
        ui->tableWidgetAdjust->setItem(i, ONE,   DATA(mapListAdjust.at(i).value(HTTPKEY::ODDNUMBERS)));
        ui->tableWidgetAdjust->setItem(i, TWO,   DATA(QDateTime::fromTime_t(mapListAdjust.at(i).value(HTTPKEY::TIME).toUInt()).toString("yyyy-MM-dd")));
        ui->tableWidgetAdjust->setItem(i, THREE, DATA(mapListAdjust.at(i).value(HTTPKEY::WHETHERSUBMIT) == "0" ? tr("未提交") : tr("已调整")));

        ui->tableWidgetAdjust->item(i, THREE)->setFont(QFont("ZYSong", 12, QFont::Bold));
        switch(mapListAdjust.at(i).value(HTTPKEY::WHETHERSUBMIT).toInt())
        {
        case ZERO:  ui->tableWidgetAdjust->item(i, THREE)->setTextColor(Qt::darkBlue); break;
        case ONE:   ui->tableWidgetAdjust->item(i, THREE)->setTextColor(Qt::darkGreen); break;
        }

        SETTABLECENTER(ui->tableWidgetAdjust->item(i, ZERO));
        SETTABLECENTER(ui->tableWidgetAdjust->item(i, ONE));
        SETTABLECENTER(ui->tableWidgetAdjust->item(i, TWO));
        SETTABLECENTER(ui->tableWidgetAdjust->item(i, THREE));
    }

    if(selectFlage)
    {
        ui->tableWidgetAdjust->scrollToBottom();
        ui->tableWidgetAdjust->selectRow(ui->tableWidgetAdjust->rowCount() - 1);
    }
}

/*********************  设置控件数据       *********************/
void InventoryAdjust::setControlData()
{
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ADJ_TYPE), PROTOCOL::URL_ADJ_TYPE);
    ui->lineEditNumberInfo->setText(adjMapData.value(HTTPKEY::ODDNUMBERS));
    ui->lineEditRemarkInfo->setText(adjMapData.value(HTTPKEY::REMARKS));

    if(!adjMapData.value(HTTPKEY::ODDNUMBERS).isEmpty())
    {
        oddNumber = adjMapData.value(HTTPKEY::ODDNUMBERS);
    }

    QString statusStr;
    switch(adjMapData.value(HTTPKEY::RETURNSSTATE).toInt())
    {
    case ZERO: statusStr = tr("未提交"); break;
    case ONE:  statusStr = tr("已调整"); break;
    }

    if(adjMapData.value(HTTPKEY::WHETHERSUBMIT).toInt() == ZERO)
    {
        ui->pushButtonSubmit->show();
        ui->pushButtonAdjMatInfo->show();
        ui->pushButtonCancelInfo->show();
        ui->pushButtonSaveInfo->show();
        ui->pushButtonDeleteInfo->show();
        ui->timeEditTimeInfo->setEnabled(true);
        ui->dateEditAdjustTimeInfo->setEnabled(true);
        ui->comboBoxAdjustTypeInfo->setEnabled(true);
        ui->comboBoxWarHseInfo->setEnabled(true);
        ui->lineEditRemarkInfo->setEnabled(true);
        ui->commandLinkButtonEdit->show();

        materialAdjInfo->setShow();

        adjMatMapList.size() <= 0 ? ui->pushButtonSubmit->setHidden(true) : ui->pushButtonSubmit->show();
    }
    else
    {
        ui->commandLinkButtonEdit->setHidden(true);
        ui->pushButtonCancelInfo->setHidden(true);
        ui->pushButtonSaveInfo->setHidden(true);
        ui->pushButtonDeleteInfo->setHidden(true);
        ui->pushButtonSubmit->setHidden(true);
        ui->pushButtonAdjMatInfo->setHidden(true);
        ui->comboBoxAdjustTypeInfo->setEnabled(false);
        ui->comboBoxWarHseInfo->setEnabled(false);
        ui->lineEditRemarkInfo->setEnabled(false);
        ui->timeEditTimeInfo->setEnabled(false);
        ui->dateEditAdjustTimeInfo->setEnabled(false);

        materialAdjInfo->setHide();
    }

    QDateTime dateTime = QDateTime::fromTime_t(adjMapData.value(HTTPKEY::TIME).toUInt());

    ui->dateEditAdjustTimeInfo->setDateTime(dateTime);
    ui->timeEditTimeInfo->setTime(dateTime.time());

    ui->labelTotalCount->setText(tr("合计%1项").arg(adjMatMapList.size()));

    ui->comboBoxWarHseInfo->clear();
    for(int i = 0; i < wareHouseMapList.size(); i ++)
    {
        ui->comboBoxWarHseInfo->addItem(wareHouseMapList.at(i).value(HTTPKEY::WAREHOUSENAME));

        if(wareHouseMapList.at(i).value(HTTPKEY::WAREHOUSEID) == adjMapData.value(HTTPKEY::WAREHOUSEID))
        {
            ui->comboBoxWarHseInfo->setCurrentIndex(i);
        }
    }

    ui->tableWidgetAdjustInfo->setRowCount(adjMatMapList.size());
    for(int i = 0; i < adjMatMapList.size(); i ++)
    {
        ui->tableWidgetAdjustInfo->setItem(i, ZERO,  DATA(adjMatMapList.at(i).value(HTTPKEY::MATERIALNAME)));
        ui->tableWidgetAdjustInfo->setItem(i, ONE,   DATA(adjMatMapList.at(i).value(HTTPKEY::BARCODE)));
        ui->tableWidgetAdjustInfo->setItem(i, TWO,   DATA(adjMatMapList.at(i).value(HTTPKEY::UNITPRICE)));
        ui->tableWidgetAdjustInfo->setItem(i, THREE, DATA(adjMatMapList.at(i).value(HTTPKEY::UNITNAME)));

        SETTABLECENTER(ui->tableWidgetAdjustInfo->item(i, ZERO));
        SETTABLECENTER(ui->tableWidgetAdjustInfo->item(i, ONE));
        SETTABLECENTER(ui->tableWidgetAdjustInfo->item(i, TWO));
        SETTABLECENTER(ui->tableWidgetAdjustInfo->item(i, THREE));
    }
    ui->tableWidgetAdjustInfo->scrollToBottom();
}

/************************   单击响应       ********************/
void InventoryAdjust::on_tableWidgetAdjust_clicked(const QModelIndex &index)
{
    if(index.row() >= mapListAdjust.size()) return;

    ui->tabWidgetAdjust->addTab(ui->tabAdjustInfo, GLOBALDEF::ADJUSTINFO);
    ui->tabWidgetAdjust->setCurrentWidget(ui->tabAdjustInfo);
    ui->tabWidgetAdjust->removeTab(ui->tabWidgetAdjust->indexOf(ui->tabAddAdjust));
    ui->tabWidgetAdjust->show();

    adjustMentId = mapListAdjust.at(index.row()).value(HTTPKEY::ADJUSTMENTID);
    oddNumber = mapListAdjust.at(index.row()).value(HTTPKEY::ODDNUMBERS);
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ADJ_GET_DET).arg(oddNumber), PROTOCOL::URL_ADJ_GET_DET);
}

/************************   双击查询       ********************/
void InventoryAdjust::on_tableWidgetAdjustInfo_doubleClicked(const QModelIndex &index)
{
    if(index.row() < 0 || index.row() >= adjMatMapList.size()) return;

    QByteArray byteArray;

    QString strPost = POSTARG::ADJGETMATDET.arg(adjMatMapList.at(index.row()).value(HTTPKEY::MATERIALID));

    strPost = strPost.arg(oddNumber, adjMapData.value(HTTPKEY::WAREHOUSEID));

    strPost = strPost.arg(adjMapData.value(HTTPKEY::WHETHERSUBMIT));

    byteArray.append(strPost);

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_ADJ_GET_MAT_DET), byteArray, PROTOCOL::URL_ADJ_GET_MAT_DET);
}

/************************   初始化控件       ********************/
void InventoryAdjust::initControl()
{
    materialAdjInfo = new MaterialAdjInfo(this);
    addAdjMaterial = new AddAdjMaterial(this);
    editAdjMaterial = new AddAdjMaterial(this);;
    logInfo = new LogInfo(this);
    extendEmailEmail = new ExtendAdjEmail(this);

    SETTABLEWIDGET(ui->tableWidgetAdjust);
    SETTABLEWIDGET(ui->tableWidgetAdjustInfo);

    ui->comboBoxAdjustType->setView(new QListView());
    ui->comboBoxAdjustTypeInfo->setView(new QListView());
    ui->comboBoxType->setView(new QListView());
    ui->comboBoxWarHse->setView(new QListView());
    ui->comboBoxWarHseInfo->setView(new QListView());
    ui->comboBoxStateSelect->setView(new QListView());
    ui->comboBoxWarHseSelect->setView(new QListView());
    ui->comboBoxTypeSelect->setView(new QListView());

    ui->comboBoxStateSelect->view()->setMinimumWidth(200);
    ui->comboBoxWarHseSelect->view()->setMinimumWidth(200);
    ui->comboBoxTypeSelect->view()->setMinimumWidth(200);

    ui->comboBoxAdjustType->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxAdjustTypeInfo->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxType->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxWarHse->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxWarHseInfo->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxStateSelect->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxWarHseSelect->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxTypeSelect->setFocusPolicy(Qt::NoFocus);

    ui->tabWidgetAdjust->setHidden(true);

    ui->dateEditSelect->setCalendarPopup(true);
    ui->dateEditAdjustTime->setCalendarPopup(true);
    ui->dateEditAdjustTimeInfo->setCalendarPopup(true);

    ui->dateEditSelect->setDate(QDate::currentDate());

    if(CONFIGJSON->getLanguage().toInt())
    {
        ui->dateEditSelect->calendarWidget()->setLocale(QLocale(QLocale::English));
        ui->dateEditAdjustTime->calendarWidget()->setLocale(QLocale(QLocale::English));
        ui->dateEditAdjustTimeInfo->calendarWidget()->setLocale(QLocale(QLocale::English));
    }


    //根据分辨率适配
    QDesktopWidget *desktop = QApplication::desktop();

    int minHeight = 0;
    if(desktop->height() >= GLOBALDEF::DESKTOPHEIGHT)
    {
        minHeight = 30;
        ui->tabAdjustInfo->layout()->setSpacing(6);
        this->setStyleSheet(GLOBALDEF::THISSTYLE);
    }
    else
    {
        minHeight = 20;
        this->setStyleSheet(GLOBALDEF::SMALLSTYLE);
    }

    ui->labelState->setMinimumHeight(minHeight);
    ui->labelWshe->setMinimumHeight(minHeight);
    ui->labelDate->setMinimumHeight(minHeight);
    ui->labelSize->setMinimumHeight(minHeight);
    ui->labelType->setMinimumHeight(minHeight);

    FlowLayout *flowLayout = new FlowLayout(ui->widgetControl);

    flowLayout->addWidget(ui->labelState);
    flowLayout->addWidget(ui->comboBoxStateSelect);
    flowLayout->addWidget(ui->labelWshe);
    flowLayout->addWidget(ui->comboBoxWarHseSelect);
    flowLayout->addWidget(ui->labelType);
    flowLayout->addWidget(ui->comboBoxTypeSelect);
    flowLayout->addWidget(ui->labelDate);
    flowLayout->addWidget(ui->dateEditSelect);
    flowLayout->addWidget(ui->pushButtonSelect);
    flowLayout->addWidget(ui->pushButtonExtend);
    flowLayout->addWidget(ui->pushButtonAdd);
    flowLayout->addWidget(ui->labelSize);

    ui->widgetControl->setLayout(flowLayout);
}

/************************   添加调整单       ********************/
void InventoryAdjust::on_pushButtonAdd_clicked()
{
    saveFlage = false;
    ui->dateEditAdjustTime->setDate(QDate::currentDate());
    ui->timeEditAdjust->setTime(QTime::currentTime());
    ui->tabWidgetAdjust->addTab(ui->tabAddAdjust, GLOBALDEF::ADDADJUST);
    ui->tabWidgetAdjust->setCurrentWidget(ui->tabAddAdjust);
    ui->tabWidgetAdjust->removeTab(ui->tabWidgetAdjust->indexOf(ui->tabAdjustInfo));
    ui->tabWidgetAdjust->show();

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ADJ_TYPE), PROTOCOL::URL_ADJ_TYPE);
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ADJ_WAREHOUSE), PROTOCOL::URL_ADJ_WAREHOUSE);
}

/************************   添加原料       ********************/
void InventoryAdjust::on_pushButtonAdjMatInfo_clicked()
{
    addAdjMaterial->setOddNumber(oddNumber);
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ADJ_GET_MAT).arg(oddNumber), PROTOCOL::URL_ADJ_GET_MAT);

    editAdjMaterial->showWidget(AddAdjMaterial::ADDTYPE);
}

/************************   添加原料       ********************/
void InventoryAdjust::on_pushButtonAddAdjustMat_clicked()
{
    if(!saveFlage)
    {
        on_pushButtonSave_clicked();
    }
    addAdjMaterial->showWidget(AddRetMaterial::ADDTYPE);
    showType = NOTSHOW;
}

/************************   保存数据       ********************/
void InventoryAdjust::on_pushButtonSave_clicked()
{
    showType = SHOWSUCCESS;

    int indexWarRow = ui->comboBoxWarHse->currentIndex();
    if(indexWarRow < 0 || indexWarRow >= wareHouseMapList.size()) return;

    int indexRow = ui->comboBoxAdjustType->currentIndex();

    QString typeId =  NULL;
    if(indexRow > 0 && indexRow < typeMapList.size())
    {
        typeId = typeMapList.at(indexRow).value(HTTPKEY::TYPEID);
    }

    QByteArray byteArray;

    QString strPost = POSTARG::ADDINVENTORY.arg(typeId);

    strPost = strPost.arg(wareHouseMapList.at(indexWarRow).value(HTTPKEY::WAREHOUSEID));

    unsigned int timeInt = GETTIMET(ui->timeEditAdjust->time()) + GETDATATIMET(ui->dateEditAdjustTime->dateTime());

    strPost = strPost.arg(QString::number(timeInt), ui->lineEditRemark->text());

    byteArray.append(strPost);

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_ADJ_ADD_INV), byteArray, PROTOCOL::URL_ADJ_ADD_INV);
}

/************************   取消按钮       ********************/
void InventoryAdjust::on_pushButtonCancel_clicked()
{
    ui->tabWidgetAdjust->setHidden(true);
}

/************************   更新数据       ********************/
void InventoryAdjust::on_pushButtonSaveInfo_clicked()
{
    int indexWarRow = ui->comboBoxWarHseInfo->currentIndex();
    if(indexWarRow < 0 || indexWarRow >= wareHouseMapList.size()) return;

    QString typeName = NULL;
    int indexTypeRow = ui->comboBoxAdjustTypeInfo->currentIndex();
    if(indexTypeRow >= 0 && indexTypeRow < typeMapList.size())
    {
        typeName = typeMapList.at(indexTypeRow).value(HTTPKEY::TYPEID);
    }

    QByteArray byteArray;

    QString strPost = POSTARG::UPDATEDASIC.arg(oddNumber);

    strPost = strPost.arg(ui->lineEditRemarkInfo->text(), wareHouseMapList.at(indexWarRow).value(HTTPKEY::WAREHOUSEID));

    strPost = strPost.arg(typeName);

    unsigned int timeInt = GETTIMET(ui->timeEditTimeInfo->time()) + GETDATATIMET(ui->dateEditAdjustTimeInfo->dateTime());

    strPost = strPost.arg(QString::number(timeInt));

    byteArray.append(strPost);

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_ADJ_UPDATE_DASIC), byteArray, PROTOCOL::URL_ADJ_UPDATE_DASIC);
}

/************************   删除调整单       ********************/
void InventoryAdjust::on_pushButtonDeleteInfo_clicked()
{
    QByteArray byteArray;

    byteArray.append(POSTARG::DELINVENTORY.arg(oddNumber));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_ADJ_DEL), byteArray, PROTOCOL::URL_ADJ_DEL);
}

/************************   导出到邮箱       ********************/
void InventoryAdjust::on_pushButtonExtend_clicked()
{
    selectFlage = true;
    extendEmailEmail->showWidget();
}

/************************   编辑原料       ********************/
void InventoryAdjust::on_commandLinkButtonEdit_clicked()
{
    editAdjMaterial->showWidget(AddAdjMaterial::EDITTYPE);
    editAdjMaterial->setTableEidiData();
}

/************************   处理记录       ********************/
void InventoryAdjust::on_commandLinkButtonLog_clicked()
{
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ADJ_SEL_DISPOSE).arg(oddNumber), PROTOCOL::URL_ADJ_SEL_DISPOSE);
}

/************************   提交       ********************/
void InventoryAdjust::on_pushButtonSubmit_clicked()
{
    int ok = MESSAGEBOX->showMessageBox(this, MESSAGE::ISPRESENT, true, false);

    if(ok == QDialog::Accepted)
    {
        QByteArray byteArray;

        byteArray.append(POSTARG::PRESENT.arg(oddNumber));

        HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_ADJ_PRESENT), byteArray, PROTOCOL::URL_ADJ_PRESENT);
    }
}

/************************   取消按钮       ********************/
void InventoryAdjust::on_pushButtonCancelInfo_clicked()
{
    ui->tabWidgetAdjust->setHidden(true);
}

/************************   查询数据       ********************/
void InventoryAdjust::on_pushButtonSelect_clicked()
{
    ui->tabWidgetAdjust->setHidden(true);
    int typeIndex = ui->comboBoxTypeSelect->currentIndex();
    if(typeIndex < 0 || typeIndex >= typeSelectMapList.size()) return;

    int warHseIndex = ui->comboBoxWarHseSelect->currentIndex();
    if(warHseIndex < 0 || warHseIndex >= warHseSelectMapList.size()) return;

    int staIndex = ui->comboBoxStateSelect->currentIndex();
    if(staIndex < 0 || staIndex >= staSelectMapList.size()) return;

    QString stateId  = staSelectMapList.at(staIndex).value(HTTPKEY::STATEID);
    QString typeId   = typeSelectMapList.at(typeIndex).value(HTTPKEY::TYPEID);
    QString warHseId = warHseSelectMapList.at(warHseIndex).value(HTTPKEY::WAREHOUSEID);
    QString strTime = QString::number(ui->dateEditSelect->dateTime().toTime_t());

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ADJ_SELECT).
                          arg(stateId, typeId, warHseId, strTime), PROTOCOL::URL_ADJ_SELECT);
}
