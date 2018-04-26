#include "costadjustment.h"
#include "ui_costadjustment.h"
#include "httpclient/httpkey.h"
#include "messagebox/messagedialog.h"

/*********************  构造函数       *********************/
CostAdjustment::CostAdjustment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CostAdjustment),showType(SHOWSUCCESS),
    saveFlage(false), selectFlage(true)
{
    ui->setupUi(this);

    this->initControl();
}

/*********************  析构函数       *********************/
CostAdjustment::~CostAdjustment()
{
    delete ui;
}

/*********************  显示窗口       *********************/
void CostAdjustment::showWidget()
{
    this->show();
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_COST_SEL_ALL), PROTOCOL::URL_COST_SEL_ALL);
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_COST_SELECT_PAGE), PROTOCOL::URL_COST_SELECT_PAGE);

    ui->tabWidgetCost->setHidden(true);
}

/*********************  解析json       *********************/
void CostAdjustment::readJson(QNetworkReply *reply, int type)
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

                if(type == PROTOCOL::URL_COST_SEL_ALL || type == PROTOCOL::URL_COST_SELECT)
                {
                    if(ISERROR(codeValue))
                    {
                        ui->tableWidgetCost->clearContents();
                        ui->tableWidgetCost->setRowCount(0);
                        mapCostList.clear();

                        ui->labelSize->setText(GLOBALDEF::TOTALONUMBER.arg(0));
                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, mapCostList);
                    this->setTableData();
                }
                else if(type == PROTOCOL::URL_COST_PRICE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)errorMsg = MESSAGE::ERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    costPrice->showWidget();

                    MapList mapListData;
                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, mapListData);

                    costPrice->setMapCostList(mapListData);
                }
                else if(type == PROTOCOL::URL_COST_ADD)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO) errorMsg = MESSAGE::ADDERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectFlage = true;
                    saveFlage = true;

                    readjustNumber = jsonObject.value(HTTPKEY::MSG).toString();
                    rejustId = jsonObject.value(HTTPKEY::READJUSTID).toString();

                    if(showType == SHOWSUCCESS)
                    {
                        ui->tabWidgetCost->setHidden(true);
                        MESSAGEBOX->showMessageBox(this, GLOBALDEF::ADDSUCCESS, true);
                    }
                    else if(saveFlage == true)
                    {
                        HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_COST_SEL_MAT).arg(readjustNumber), PROTOCOL::URL_COST_SEL_MAT);
                    }

                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_COST_SEL_ALL), PROTOCOL::URL_COST_SEL_ALL);
                }
                else if(type == PROTOCOL::URL_COST_SEL_MAT)
                {
                    MapList mapListData;

                    if(ISERROR(codeValue))
                    {
                        addCostMaterial->setMapMatList(mapListData);
                        editCostMaterial->setMapMatList(mapListData);
                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, mapListData);

                    addCostMaterial->setMapMatList(mapListData);
                    editCostMaterial->setMapMatList(mapListData);

                    if(mapListData.size() != 0)
                    {
                        readjustNumber = mapListData.at(ZERO).value(HTTPKEY::READJUSTNUMBER);
                    }
                }
                else if(type == PROTOCOL::URL_COST_ADD_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ADDERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::ADDSUCCESS, true);
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_COST_SEL).arg(rejustId), PROTOCOL::URL_COST_SEL);
                }
                else if(type == PROTOCOL::URL_COST_SEL)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    ui->tabWidgetCost->addTab(ui->tabCostInfo, GLOBALDEF::COSTINFO);
                    ui->tabWidgetCost->setCurrentWidget(ui->tabCostInfo);
                    ui->tabWidgetCost->removeTab(ui->tabWidgetCost->indexOf(ui->tabAddCost));
                    ui->tabWidgetCost->show();

                    HTTPCLIENT->readJsonMap(jsonNextObj, HTTPKEY::READJUST, mapCostData);
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::MATERIAL, mapMatList);

                    readjustNumber = mapCostData.value(HTTPKEY::READJUSTNUMBER);

                    this->setControlData();
                }
                else if(type == PROTOCOL::URL_COST_UPDATE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::EDITERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectFlage = false;
                    this->showWidget();
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::EDITSUCCESS, true);
                }
                else if(type == PROTOCOL::URL_COST_DEL)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::DELERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectFlage = true;
                    this->showWidget();
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::DELSUCCESS, true);
                }
                else if(type == PROTOCOL::URL_COST_GET_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectFlage = false;
                    Map mapData;
                    HTTPCLIENT->readJsonMap(jsonObject, HTTPKEY::MSG, mapData);

                    materialCostInfo->setMatMap(mapData);
                    materialCostInfo->setControlData();
                    materialCostInfo->showWidget();
                }
                else if(type == PROTOCOL::URL_COST_UPDATE_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::EDITERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_COST_SEL).arg(rejustId), PROTOCOL::URL_COST_SEL);
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::EDITSUCCESS, true);
                }
                else if(type == PROTOCOL::URL_COST_UPDATE_PAGE)
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

                    editCostMaterial->showWidget(AddAdjMaterial::EDITTYPE);
                    editCostMaterial->setMapSelectList(mapListData);
                }
                else if(type == PROTOCOL::URL_COST_UPDATE_ALL_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_COST_SEL).arg(rejustId), PROTOCOL::URL_COST_SEL);
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::EDITSUCCESS, true);
                }
                else if(type == PROTOCOL::URL_COST_DEL_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::DELERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_COST_SEL).arg(rejustId), PROTOCOL::URL_COST_SEL);
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::DELSUCCESS, true);
                }
                else if(type == PROTOCOL::URL_COST_PRESENT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectFlage = false;
                    this->showWidget();
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::SUCCESS, true);
                }
                else if(type == PROTOCOL::URL_COST_AFFIRM)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectFlage = false;
                    this->showWidget();
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::SUCCESS, true);
                }
                else if(type == PROTOCOL::URL_COST_SEL_DISPOSE)
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
                else if(type == PROTOCOL::URL_COST_SELECT_PAGE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO) errorMsg = MESSAGE::ERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::STATE, staSelectMapList);

                    ui->comboBoxStateSelect->clear();
                    for(int i = 0; i < staSelectMapList.size(); i ++)
                    {
                        QString stateName = staSelectMapList.at(i).value(HTTPKEY::STATENAME);

                        if(CONFIGJSON->getLanguage().toInt())
                        {
                            if(stateName == GLOBALDEF::CHIALL)           stateName = GLOBALDEF::ENGALL;
                            else if(stateName == GLOBALDEF::CHIUNSUBMIT) stateName = GLOBALDEF::ENGUNSUBMIT;
                            else if(stateName == GLOBALDEF::CHICHECK)    stateName = GLOBALDEF::ENGCHECK;
                            else if(stateName == GLOBALDEF::CHICOSTADJ)  stateName = GLOBALDEF::ENGCOSTADJ;
                        }

                        ui->comboBoxStateSelect->addItem(stateName);
                    }
                }
            }
        }
        reply->close();
    }
}

/*********************  初始化控件       *********************/
void CostAdjustment::initControl()
{
    costPrice = new CostPrice(this);

    SETTABLEWIDGET(ui->tableWidgetCost);
    SETTABLEWIDGET(ui->tableWidgetCostInfo);

    ui->comboBoxStateSelect->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxStateSelect->setView(new QListView());

    ui->comboBoxStateSelect->view()->setMinimumWidth(200);

    ui->dateEditSelect->setCalendarPopup(true);
    ui->dateEditSelect->setDate(QDate::currentDate());

    if(CONFIGJSON->getLanguage().toInt())
    {
        ui->dateEditSelect->calendarWidget()->setLocale(QLocale(QLocale::English));
    }

    addCostMaterial = new AddCostMaterial(this);
    editCostMaterial = new AddCostMaterial(this);
    materialCostInfo = new MaterialCostInfo(this);
    logInfo = new LogInfo(this);

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

    ui->labelState->setMinimumHeight(minHeight);
    ui->labelDate->setMinimumHeight(minHeight);
    ui->labelSize->setMinimumHeight(minHeight);

    FlowLayout *flowLayout = new FlowLayout(ui->widgetControl);

    flowLayout->addWidget(ui->labelState);
    flowLayout->addWidget(ui->comboBoxStateSelect);
    flowLayout->addWidget(ui->labelDate);
    flowLayout->addWidget(ui->dateEditSelect);
    flowLayout->addWidget(ui->pushButtonSelect);
    flowLayout->addWidget(ui->pushButtonSee);
    flowLayout->addWidget(ui->pushButtonAdd);
    flowLayout->addWidget(ui->labelSize);

    ui->widgetControl->setLayout(flowLayout);
}

/*********************  设置数据       *********************/
void CostAdjustment::setTableData()
{
    ui->labelSize->setText(GLOBALDEF::TOTALONUMBER.arg(mapCostList.size()));
    ui->tableWidgetCost->setRowCount(mapCostList.size());

    for(int i = 0; i < mapCostList.size(); i ++)
    {
        ui->tableWidgetCost->setItem(i, ZERO,  DATA(mapCostList.at(i).value(HTTPKEY::READJUSTNUMBER)));
        ui->tableWidgetCost->setItem(i, ONE,   DATA(mapCostList.at(i).value(HTTPKEY::NUM) + tr("项")));
        ui->tableWidgetCost->setItem(i, TWO,   DATA(QDateTime::fromTime_t(mapCostList.at(i).value(HTTPKEY::READJUSTTIME).toUInt()).toString("yyyy-MM-dd")));

        int state = mapCostList.at(i).value(HTTPKEY::STATE).toInt();
        QString strState;
        switch (state)
        {
        case ZERO: strState = tr("未提交"); break;
        case ONE:  strState = tr("待审核"); break;
        case TWO:  strState = tr("已调价"); break;
        }

        ui->tableWidgetCost->setItem(i, THREE, DATA(strState));

        ui->tableWidgetCost->item(i, THREE)->setFont(QFont("ZYSong", 12, QFont::Bold));
        switch(state)
        {
        case ZERO:  ui->tableWidgetCost->item(i, THREE)->setTextColor(Qt::darkBlue); break;
        case ONE:   ui->tableWidgetCost->item(i, THREE)->setTextColor(Qt::darkMagenta); break;
        case TWO:   ui->tableWidgetCost->item(i, THREE)->setTextColor(Qt::darkGreen); break;
        }

        SETTABLECENTER(ui->tableWidgetCost->item(i, ZERO));
        SETTABLECENTER(ui->tableWidgetCost->item(i, ONE));
        SETTABLECENTER(ui->tableWidgetCost->item(i, TWO));
        SETTABLECENTER(ui->tableWidgetCost->item(i, THREE));
    }

    if(selectFlage)
    {
        ui->tableWidgetCost->scrollToBottom();
        ui->tableWidgetCost->selectRow(ui->tableWidgetCost->rowCount() - 1);
    }
}

/*********************  设置控件数据       *********************/
void CostAdjustment::setControlData()
{
    ui->lineEditNumberInfo->setText(mapCostData.value(HTTPKEY::READJUSTNUMBER));
    ui->lineEditRemarkInfo->setText(mapCostData.value(HTTPKEY::REMARK));

    int state = mapCostData.value(HTTPKEY::STATE).toInt();
    QString strState;
    switch (state)
    {
    case ZERO: strState = tr("未提交"); break;
    case ONE:  strState = tr("待审核"); break;
    case TWO:  strState = tr("已调价"); break;
    }

    if(state == TWO)
    {
        ui->pushButtonCancelInfo->setHidden(true);
        ui->pushButtonAddCostMatInfo->setHidden(true);
        ui->pushButtonDeleteInfo->setHidden(true);
        ui->pushButtonSaveInfo->setHidden(true);
        ui->pushButtonConfirmInfo->setHidden(true);
        ui->pushButtonSubmitInfo->setHidden(true);
        ui->commandLinkButtonEdit->setHidden(true);

        materialCostInfo->setHide();
    }
    else
    {
        ui->commandLinkButtonEdit->show();
        ui->pushButtonCancelInfo->show();
        ui->pushButtonAddCostMatInfo->show();
        ui->pushButtonSaveInfo->show();
        materialCostInfo->setShow();
        if(state == ZERO)
        {
            ui->pushButtonDeleteInfo->show();
            ui->pushButtonConfirmInfo->setHidden(true);
            ui->pushButtonSubmitInfo->show();

            if(mapMatList.size() <= 0)
            {
                ui->pushButtonSubmitInfo->setHidden(true);
            }
        }
        else
        {
            ui->pushButtonDeleteInfo->setHidden(true);
            ui->pushButtonConfirmInfo->show();
            ui->pushButtonSubmitInfo->setHidden(true);
        }
    }

    ui->lineEditStateInfo->setText(strState);

    ui->tableWidgetCostInfo->setRowCount(mapMatList.size());
    for(int i = 0; i < mapMatList.size(); i ++)
    {
        ui->tableWidgetCostInfo->setItem(i, ZERO,  DATA(mapMatList.at(i).value(HTTPKEY::MATERIALNAME)));
        ui->tableWidgetCostInfo->setItem(i, ONE,   DATA(mapMatList.at(i).value(HTTPKEY::BARCODE)));
        ui->tableWidgetCostInfo->setItem(i, TWO,   DATA(mapMatList.at(i).value(HTTPKEY::OLDPRICE)));
        ui->tableWidgetCostInfo->setItem(i, THREE, DATA(mapMatList.at(i).value(HTTPKEY::NEWPRICE)));
        ui->tableWidgetCostInfo->setItem(i, FOUR,  DATA(mapMatList.at(i).value(HTTPKEY::UNITNAME)));

        SETTABLECENTER(ui->tableWidgetCostInfo->item(i, ZERO));
        SETTABLECENTER(ui->tableWidgetCostInfo->item(i, ONE));
        SETTABLECENTER(ui->tableWidgetCostInfo->item(i, TWO));
        SETTABLECENTER(ui->tableWidgetCostInfo->item(i, THREE));
        SETTABLECENTER(ui->tableWidgetCostInfo->item(i, FOUR));
    }

    ui->tableWidgetCostInfo->scrollToBottom();
}

/*********************  单击控件       *********************/
void CostAdjustment::on_tableWidgetCost_clicked(const QModelIndex &index)
{
    if(index.row() < 0 || index.row() >= mapCostList.size()) return;

    rejustId = mapCostList.at(index.row()).value(HTTPKEY::READJUSTID);

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_COST_SEL).arg(rejustId), PROTOCOL::URL_COST_SEL);
}

/*********************  添加调价单       *********************/
void CostAdjustment::on_pushButtonAdd_clicked()
{
    saveFlage = false;
    ui->tabWidgetCost->addTab(ui->tabAddCost, GLOBALDEF::ADDCOST);
    ui->tabWidgetCost->setCurrentWidget(ui->tabAddCost);
    ui->tabWidgetCost->removeTab(ui->tabWidgetCost->indexOf(ui->tabCostInfo));
    ui->tabWidgetCost->show();
}

/*********************  保存调价单       *********************/
void CostAdjustment::on_pushButtonSave_clicked()
{
    QByteArray byteArry;

    byteArry.append(POSTARG::ADDCOST.arg(ui->lineEditRemarkInfo->text()));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_COST_ADD), byteArry, PROTOCOL::URL_COST_ADD);
}

/*********************  成本价一览       *********************/
void CostAdjustment::on_pushButtonSee_clicked()
{
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_COST_PRICE), PROTOCOL::URL_COST_PRICE);
}

/*********************  确认调价       *********************/
void CostAdjustment::on_pushButtonConfirmInfo_clicked()
{
    QByteArray byteArry;

    byteArry.append(POSTARG::CONFIRMCOST.arg(mapCostData.value(HTTPKEY::READJUSTNUMBER)));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_COST_AFFIRM), byteArry, PROTOCOL::URL_COST_AFFIRM);
}

/*********************  提交       *********************/
void CostAdjustment::on_pushButtonSubmitInfo_clicked()
{
    QByteArray byteArry;

    byteArry.append(POSTARG::SUBMITCOST.arg(mapCostData.value(HTTPKEY::READJUSTNUMBER)));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_COST_PRESENT), byteArry, PROTOCOL::URL_COST_PRESENT);
}

/*********************  添加原料       *********************/
void CostAdjustment::on_pushButtonAddAdjustMat_clicked()
{
    showType = NOTSHOW;
    if(!saveFlage)
    {
        on_pushButtonSave_clicked();
    }

    addCostMaterial->showWidget(AddCostMaterial::ADDTYPE);
}

/*********************  双击控件       *********************/
void CostAdjustment::on_tableWidgetCostInfo_doubleClicked(const QModelIndex &index)
{
    if(index.row() < 0 || index.row() >= mapMatList.size()) return;

    QString state = mapCostData.value(HTTPKEY::STATE);
    QString rejustMatId = mapMatList.at(index.row()).value(HTTPKEY::READJUSTMATID);

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_COST_GET_MAT).arg(rejustMatId, state), PROTOCOL::URL_COST_GET_MAT);
}

/*********************  更新调价单信息       *********************/
void CostAdjustment::on_pushButtonSaveInfo_clicked()
{
    QByteArray byteArry;

    byteArry.append(POSTARG::UPDATEREADJUST.arg(rejustId, ui->lineEditRemarkInfo->text()));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_COST_UPDATE), byteArry, PROTOCOL::URL_COST_UPDATE);
}

/*********************  删除调价单       *********************/
void CostAdjustment::on_pushButtonDeleteInfo_clicked()
{
    QByteArray byteArry;

    byteArry.append(POSTARG::DELCOST.arg(mapCostData.value(HTTPKEY::READJUSTNUMBER)));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_COST_DEL), byteArry, PROTOCOL::URL_COST_DEL);
}

/*********************  取消按钮       *********************/
void CostAdjustment::on_pushButtonCancelInfo_clicked()
{
    ui->tabWidgetCost->setHidden(true);
}

/*********************  取消按钮       *********************/
void CostAdjustment::on_pushButtonCancel_clicked()
{
    ui->tabWidgetCost->setHidden(true);
}

/*********************  添加原料       *********************/
void CostAdjustment::on_pushButtonAddCostMatInfo_clicked()
{
    showType = SHOWSUCCESS;
    saveFlage = false;
    editCostMaterial->showWidget(AddAdjMaterial::ADDTYPE);

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_COST_SEL_MAT).arg(readjustNumber), PROTOCOL::URL_COST_SEL_MAT);
}

/*********************  编辑原料       *********************/
void CostAdjustment::on_commandLinkButtonEdit_clicked()
{
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_COST_UPDATE_PAGE).arg(readjustNumber), PROTOCOL::URL_COST_UPDATE_PAGE);
}

/*********************  处理记录       *********************/
void CostAdjustment::on_commandLinkButtonLog_clicked()
{
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_COST_SEL_DISPOSE).arg(readjustNumber), PROTOCOL::URL_COST_SEL_DISPOSE);
}

/*********************  查询调价单       *********************/
void CostAdjustment::on_pushButtonSelect_clicked()
{
    ui->tabWidgetCost->setHidden(true);

    int staIndex = ui->comboBoxStateSelect->currentIndex();
    if(staIndex < 0 || staIndex >= staSelectMapList.size()) return;

    QString stateId  = staSelectMapList.at(staIndex).value(HTTPKEY::STATEID);
    QString strTime = QString::number(ui->dateEditSelect->dateTime().toTime_t());

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_COST_SELECT).
                          arg(stateId, strTime), PROTOCOL::URL_COST_SELECT);
}
