#include "accountmanage.h"
#include "ui_accountmanage.h"
#include "purchasemanage/loginfo/loginfo.h"
#include "purchasemanage/purchasestorage/materialstoinfo/materialstoinfo.h"
#include "purchasemanage/purreturngood/materialretinfo/materialretinfo.h"
#include "accountexport/accountexport.h"
#include "messagebox/messagedialog.h"
#include "httpclient/httpkey.h"
#include "flowlayout/flowlayout.h"

/************************   构造函数            ********************/
AccountManage::AccountManage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AccountManage)
{
    ui->setupUi(this);

    this->initControl();
}

/************************   析构函数        ********************/
AccountManage::~AccountManage()
{
    delete ui;
}

/************************   初始化控件      ********************/
void AccountManage::initControl()
{
    SETTABLEWIDGET(ui->tableWidgetAccount);
    SETTABLEWIDGET(ui->tableWidgetInfo);

    logInfo = new LogInfo(this);
    materialStoInfo = new MaterialStoInfo(this);
    materialRetInfo = new MaterialRetInfo(this);
    accountExport = new AccountExport(this);

    materialStoInfo->setHide();
    materialRetInfo->setHide();

    ui->dateEditEndTime->setHidden(true);
    ui->dateEditStartTime->setHidden(true);
    ui->labelEndTime->setHidden(true);
    ui->labelBeginTime->setHidden(true);

    ui->comboBoxState->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxSupplier->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxType->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxTimeType->setFocusPolicy(Qt::NoFocus);

    ui->comboBoxState->setView(new QListView());
    ui->comboBoxSupplier->setView(new QListView());
    ui->comboBoxType->setView(new QListView());
    ui->comboBoxTimeType->setView(new QListView());

    ui->comboBoxState->view()->setMinimumWidth(200);
    ui->comboBoxSupplier->view()->setMinimumWidth(200);
    ui->comboBoxType->view()->setMinimumWidth(200);
    ui->comboBoxTimeType->view()->setMinimumWidth(200);

    ui->dateEditEndTime->setDate(QDate::currentDate());
    ui->dateEditStartTime->setDate(QDate::currentDate());

    ui->dateEditEndTime->setCalendarPopup(true);
    ui->dateEditStartTime->setCalendarPopup(true);

    ui->dateEditEndTime->setFocusPolicy(Qt::NoFocus);
    ui->dateEditStartTime->setFocusPolicy(Qt::NoFocus);

    if(CONFIGJSON->getLanguage().toInt())
    {
        ui->dateEditStartTime->calendarWidget()->setLocale(QLocale(QLocale::English));
        ui->dateEditEndTime->calendarWidget()->setLocale(QLocale(QLocale::English));
    }

    //根据分辨率适配
    QDesktopWidget *desktop = QApplication::desktop();
    int height = 30;
    if(desktop->height() >= GLOBALDEF::DESKTOPHEIGHT)
    {
        this->setStyleSheet(GLOBALDEF::THISSTYLE);

        height = 30;
    }
    else
    {
        this->setStyleSheet(GLOBALDEF::SMALLSTYLE);
        height = 20;
    }

    ui->labelState->setMinimumHeight(height);
    ui->labelSup->setMinimumHeight(height);
    ui->labelType->setMinimumHeight(height);
    ui->labelDateType->setMinimumHeight(height);
    ui->labelBeginTime->setMinimumHeight(height);
    ui->labelEndTime->setMinimumHeight(height);

    FlowLayout *flowLayout = new FlowLayout(ui->widgetControl);

    flowLayout->addWidget(ui->labelState);
    flowLayout->addWidget(ui->comboBoxState);
    flowLayout->addWidget(ui->labelSup);
    flowLayout->addWidget(ui->comboBoxSupplier);
    flowLayout->addWidget(ui->labelType);
    flowLayout->addWidget(ui->comboBoxType);
    flowLayout->addWidget(ui->labelDateType);
    flowLayout->addWidget(ui->comboBoxTimeType);
    flowLayout->addWidget(ui->labelBeginTime);
    flowLayout->addWidget(ui->dateEditStartTime);
    flowLayout->addWidget(ui->labelEndTime);
    flowLayout->addWidget(ui->dateEditEndTime);
    flowLayout->addWidget(ui->pushButtonSelect);
    flowLayout->addWidget(ui->pushButtonExport);

    ui->widgetControl->setLayout(flowLayout);
}

/************************   设置数据        ********************/
void AccountManage::setTableData()
{
    ui->tableWidgetAccount->setRowCount(accountMapList.size());

    for(int i = 0; i < accountMapList.size(); i ++)
    {
        ui->tableWidgetAccount->setItem(i, ZERO,  DATA(accountMapList.at(i).value(HTTPKEY::SUPPLIERNAME)));
        ui->tableWidgetAccount->setItem(i, ONE,   DATA(accountMapList.at(i).value(HTTPKEY::NUMBER)));

        if(accountMapList.at(i).value(HTTPKEY::NUMBER).contains("STO"))
        {
            ui->tableWidgetAccount->setItem(i, TWO,   DATA(tr("入库单")));
        }
        else
        {
            ui->tableWidgetAccount->setItem(i, TWO,   DATA(tr("退货单")));
        }

        ui->tableWidgetAccount->setItem(i, THREE, DATA(QDateTime::fromTime_t(accountMapList.at(i).value(HTTPKEY::TIME).toUInt()).toString("yyyy-MM-dd")));

        switch(accountMapList.at(i).value(HTTPKEY::ACCOUNTSTATE).toInt())
        {
        case ZERO:
        {
            ui->tableWidgetAccount->setItem(i, FOUR,  DATA(tr("待对账")));
            ui->tableWidgetAccount->item(i, FOUR)->setTextColor(Qt::darkBlue);
        }break;
        case ONE:
        {
            ui->tableWidgetAccount->setItem(i, FOUR,  DATA(tr("已结算")));
            ui->tableWidgetAccount->item(i, FOUR)->setTextColor(Qt::darkGreen);
        }break;
        case TWO:
        {
            ui->tableWidgetAccount->setItem(i, FOUR,  DATA(tr("待结算")));
            ui->tableWidgetAccount->item(i, FOUR)->setTextColor(Qt::darkMagenta);
        }break;
        }

        ui->tableWidgetAccount->item(i, FOUR)->setFont(QFont("ZYSong", 12, QFont::Bold));

        SETTABLECENTER(ui->tableWidgetAccount->item(i, ZERO));
        SETTABLECENTER(ui->tableWidgetAccount->item(i, ONE));
        SETTABLECENTER(ui->tableWidgetAccount->item(i, TWO));
        SETTABLECENTER(ui->tableWidgetAccount->item(i, THREE));
        SETTABLECENTER(ui->tableWidgetAccount->item(i, FOUR));
    }
    ui->tableWidgetAccount->scrollToBottom();
}

/************************   设置入库控件数据  ********************/
void AccountManage::setControlStoData()
{
    ui->lineEditNumberInfo->setText(stoMapData.value(HTTPKEY::STORAGENUMBER));
    ui->lineEditWareHouseInfo->setText(stoMapData.value(HTTPKEY::WAREHOUSENAME));
    ui->lineEditSupplierInfo->setText(stoMapData.value(HTTPKEY::SUPPLIERNAME));
    ui->lineEditRemarkInfo->setText(stoMapData.value(HTTPKEY::STORAGEREMARK));

    QDateTime dateTime = QDateTime::fromTime_t(stoMapData.value(HTTPKEY::STORAGETIME).toUInt());

    ui->lineEditDate->setText(dateTime.toString("yyyy-MM-dd"));
    ui->lineEditTime->setText(dateTime.toString("hh:mm:ss"));

    QString stateText;
    switch(stoMapData.value(HTTPKEY::ACCOUNTSTATE).toInt())
    {
    case ZERO:
    {
        stateText = tr("待对账");
        ui->commandLinkButtonSure->setText(tr("确认对账"));
        ui->commandLinkButtonSure->show();
        ui->commandLinkButtonLog->show();
    }break;
    case ONE:
    {
        stateText = tr("已结算");
        ui->commandLinkButtonSure->setHidden(true);
        ui->commandLinkButtonLog->setHidden(true);
        ui->labelDate->setText(tr("对账时间"));
        ui->labelTime->setText(tr("结算时间"));

        QDateTime dateTime = QDateTime::fromTime_t(stoMapData.value(HTTPKEY::PROOFREADTIME).toUInt());
        ui->lineEditDate->setText(dateTime.toString("yyyy-MM-dd hh:mm:ss"));

        dateTime = QDateTime::fromTime_t(stoMapData.value(HTTPKEY::ACCOUNTTIME).toUInt());
        ui->lineEditTime->setText(dateTime.toString("yyyy-MM-dd hh:mm:ss"));
    }break;
    case TWO:
    {
        stateText = tr("待结算");
        ui->commandLinkButtonSure->setText(tr("确认结算"));
        ui->commandLinkButtonSure->show();
        ui->commandLinkButtonLog->show();
    }break;

    }
    ui->lineEditStateInfo->setText(stateText);

    ui->labelTotalCount->setText("  " + GLOBALDEF::TOTALCOUNT.arg(materialMapList.size()));
    ui->tableWidgetInfo->setRowCount(materialMapList.size());

    double totalMoney = 0;
    for(int i = 0; i < materialMapList.size(); i ++)
    {
        QString unitName = materialMapList.at(i).value(HTTPKEY::UNITNAME);
        ui->tableWidgetInfo->setItem(i, ZERO,   DATA(materialMapList.at(i).value(HTTPKEY::MATERIALNAME)));
        ui->tableWidgetInfo->setItem(i, ONE,    DATA(materialMapList.at(i).value(HTTPKEY::BARCODE)));
        ui->tableWidgetInfo->setItem(i, TWO,    DATA(materialMapList.at(i).value(HTTPKEY::STORAGEPRICE) + tr("元/") + unitName));
        ui->tableWidgetInfo->setItem(i, THREE,  DATA(materialMapList.at(i).value(HTTPKEY::STORAGEAMOUNT) + unitName));

        totalMoney += materialMapList.at(i).value(HTTPKEY::TOTALMONEY).toDouble();
        SETTABLECENTER(ui->tableWidgetInfo->item(i, ZERO));
        SETTABLECENTER(ui->tableWidgetInfo->item(i, ONE));
        SETTABLECENTER(ui->tableWidgetInfo->item(i, TWO));
        SETTABLECENTER(ui->tableWidgetInfo->item(i, THREE));
    }

    ui->labelMoney->setText(tr("总计：%1元").arg(totalMoney));
}

/************************   设置退货控件数据  ********************/
void AccountManage::setControlRetData()
{
    ui->lineEditNumberInfo->setText(retMapData.value(HTTPKEY::RETURNSNUMBER));
    ui->lineEditWareHouseInfo->setText(retMapData.value(HTTPKEY::WAREHOUSENAME));
    ui->lineEditSupplierInfo->setText(retMapData.value(HTTPKEY::SUPPLIERNAME));
    ui->lineEditRemarkInfo->setText(retMapData.value(HTTPKEY::RETURNSREMARK));

    QString stateText;
    switch(retMapData.value(HTTPKEY::ACCOUNTSTATE).toInt())
    {
    case ZERO:stateText = tr("待对账"); ui->commandLinkButtonSure->setText(tr("确认对账"));ui->commandLinkButtonSure->show();break;
    case ONE: stateText = tr("已结算");ui->commandLinkButtonSure->setHidden(true);break;
    case TWO: stateText = tr("待结算");ui->commandLinkButtonSure->setText(tr("确认结算"));ui->commandLinkButtonSure->show();break;
    }
    ui->lineEditStateInfo->setText(stateText);

    QDateTime dateTime = QDateTime::fromTime_t(retMapData.value(HTTPKEY::RETURNSTIME).toUInt());

    ui->lineEditDate->setText(dateTime.toString("yyyy-MM-dd"));
    ui->lineEditTime->setText(dateTime.toString("hh:mm:ss"));

    ui->tableWidgetInfo->setRowCount(materialMapList.size());

    double totalMoney = 0;
    for(int i = 0; i < materialMapList.size(); i ++)
    {
        QString unitName = materialMapList.at(i).value(HTTPKEY::UNITNAME);
        ui->tableWidgetInfo->setItem(i, ZERO,  DATA(materialMapList.at(i).value(HTTPKEY::MATERIALNAME)));
        ui->tableWidgetInfo->setItem(i, ONE,   DATA(materialMapList.at(i).value(HTTPKEY::BARCODE)));
        ui->tableWidgetInfo->setItem(i, TWO,   DATA(materialMapList.at(i).value(HTTPKEY::RETURNSPRICE) + "元/" + unitName));
        ui->tableWidgetInfo->setItem(i, THREE, DATA(materialMapList.at(i).value(HTTPKEY::RETURNSAMOUNT) + unitName));

        totalMoney += materialMapList.at(i).value(HTTPKEY::TOTALMONEY).toDouble();
        SETTABLECENTER(ui->tableWidgetInfo->item(i, ZERO));
        SETTABLECENTER(ui->tableWidgetInfo->item(i, ONE));
        SETTABLECENTER(ui->tableWidgetInfo->item(i, TWO));
        SETTABLECENTER(ui->tableWidgetInfo->item(i, THREE));
    }

    ui->labelTotalCount->setText("  " + GLOBALDEF::TOTALCOUNT.arg(materialMapList.size()));
    ui->labelMoney->setText(tr("总计：%1元").arg(totalMoney));
}

/************************   设置筛选数据     ********************/
void AccountManage::setFiltrateData()
{
    ui->comboBoxState->clear();
    for(int i = 0; i < mapListState.size(); i ++)
    {
        QString stateName = mapListState.at(i).value(HTTPKEY::STATENAME);

        if(CONFIGJSON->getLanguage().toInt())
        {
            if(stateName == GLOBALDEF::CHIALL)         stateName = GLOBALDEF::ENGALL;
            else if(stateName == GLOBALDEF::CHIRECO)   stateName = GLOBALDEF::ENGRECO;
            else if(stateName == GLOBALDEF::CHITOSETT) stateName = GLOBALDEF::ENGTOSETT;
            else if(stateName == GLOBALDEF::CHISETT)   stateName = GLOBALDEF::ENGSETT;
        }

        ui->comboBoxState->addItem(stateName);
    }

    ui->comboBoxSupplier->clear();
    for(int i = 0; i < mapListSupplier.size(); i ++)
    {
        QString supName = mapListSupplier.at(i).value(HTTPKEY::SUPPLIERNAME);

        if(CONFIGJSON->getLanguage().toInt())
        {
            if(supName == GLOBALDEF::CHIALL)          supName = GLOBALDEF::ENGALL;
        }
        ui->comboBoxSupplier->addItem(supName);
    }

    ui->comboBoxType->clear();
    for(int i = 0; i < mapListType.size(); i ++)
    {
        QString typeName = mapListType.at(i).value(HTTPKEY::TYPENAME);

        if(CONFIGJSON->getLanguage().toInt())
        {
            if(typeName == GLOBALDEF::CHIALL)          typeName = GLOBALDEF::ENGALL;
            else if(typeName == GLOBALDEF::CHISTORAGE) typeName = GLOBALDEF::ENGSTORAGE;
            else if(typeName == GLOBALDEF::CHIRETURNS) typeName = GLOBALDEF::ENGRETURNS;
        }

        ui->comboBoxType->addItem(typeName);
    }

    ui->comboBoxTimeType->clear();
    for(int i = 0; i < mapListTime.size(); i ++)
    {
        QString timeName = mapListTime.at(i).value(HTTPKEY::NAME);

        if(CONFIGJSON->getLanguage().toInt())
        {
            if(timeName == GLOBALDEF::CHIALL)            timeName = GLOBALDEF::ENGALL;
            else if(timeName == GLOBALDEF::CHIYESTERDAY) timeName = GLOBALDEF::ENGYESTERDAY;
            else if(timeName == GLOBALDEF::CHITODAY)     timeName = GLOBALDEF::ENGTODAY;
            else if(timeName == GLOBALDEF::CHITHISWEEK)  timeName = GLOBALDEF::ENGTHISWEEK;
            else if(timeName == GLOBALDEF::CHILASTWEEK)  timeName = GLOBALDEF::ENGLASTWEEK;
            else if(timeName == GLOBALDEF::CHITHISMONTH) timeName = GLOBALDEF::ENGTHISMONTH;
            else if(timeName == GLOBALDEF::CHILASTMONTH) timeName = GLOBALDEF::ENGLASTMONTH;
            else if(timeName == GLOBALDEF::CHICUSTOMIZE) timeName = GLOBALDEF::ENGCUSTOMIZE;
        }
        ui->comboBoxTimeType->addItem(timeName);
    }
}

/************************   显示窗口        ********************/
void AccountManage::showWidget()
{
    this->show();
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ACCOUNT_ALL_NUMBER), PROTOCOL::URL_ACCOUNT_ALL_NUMBER);
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ACCOUNT_FILTRATE_PAGE), PROTOCOL::URL_ACCOUNT_FILTRATE_PAGE);
    ui->tabWidgetAccount->setHidden(true);
}

/************************  解析json       *********************/
void AccountManage::readJson(QNetworkReply *reply, int type)
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

                if(type == PROTOCOL::URL_ACCOUNT_ALL_NUMBER || type == PROTOCOL::URL_ACCOUNT_FILTRATE)
                {
                    if(ISERROR(codeValue))
                    {
                        ui->tableWidgetAccount->clearContents();
                        ui->tableWidgetAccount->setRowCount(0);
                        accountMapList.clear();
                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, accountMapList);
                    accountExport->setAccountMapList(accountMapList);
                    this->setTableData();
                }
                else if(type == PROTOCOL::URL_ACCOUNT_STO_PAGE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::SELECTERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }
                    HTTPCLIENT->readJsonMap(jsonNextObj,  HTTPKEY::STORAGEDATA,  stoMapData);
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::MATERIALLIST, materialMapList);

                    realityTime = stoMapData.value(HTTPKEY::REALITYTIME);
                    this->setControlStoData();
                }
                else if(type == PROTOCOL::URL_ACCOUNT_RET_PAGE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::SELECTERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    HTTPCLIENT->readJsonMap(jsonNextObj,  HTTPKEY::DATADATA,  retMapData);
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::MATERIALLIST, materialMapList);

                    realityTime = retMapData.value(HTTPKEY::REALITYTIME);

                    this->setControlRetData();
                }
                else if(type == PROTOCOL::URL_ACCOUNT_AFFIRM_PRO)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    this->showWidget();
                    MESSAGEBOX->showMessageBox(this, tr("对账成功"), true);
                }
                else if(type == PROTOCOL::URL_ACCOUNT_AFFIRM_ACC)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    this->showWidget();

                    MESSAGEBOX->showMessageBox(this, tr("结算成功"), true);
                }
                else if(type == PROTOCOL::URL_ACCOUNT_SEL_DISPOSE)
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

                else if(type == PROTOCOL::URL_ACCOUNT_STO_MAT_INFO)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    materialStoInfo->showWidget();

                    Map mapData;
                    HTTPCLIENT->readJsonMap(jsonObject, HTTPKEY::MSG, mapData);

                    materialStoInfo->setMatMap(mapData);

                    materialStoInfo->setAccountData();
                }
                else if(type == PROTOCOL::URL_ACCOUNT_RET_MAT_INFO)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;

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
                else if(type == PROTOCOL::URL_ACCOUNT_FILTRATE_PAGE)
                {
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::TIMEFRAME, mapListTime);
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::SUPPLIER,  mapListSupplier);
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::TYPE,      mapListType);
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::STATE,     mapListState);

                    this->setFiltrateData();
                }
                else if(type == PROTOCOL::URL_ACCOUNT_EXTEND)
                {
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::EXPORTSUCCESS, true);
                }
            }
        }
        reply->close();
    }
}

/************************  单击事件       *********************/
void AccountManage::on_tableWidgetAccount_clicked(const QModelIndex &index)
{
    if(index.row() < 0 || index.row() >= accountMapList.size()) return;

    number = accountMapList.at(index.row()).value(HTTPKEY::NUMBER);
    if(accountMapList.at(index.row()).value(HTTPKEY::NUMBER).contains("STO"))
    {
        QString accountTime = accountMapList.at(index.row()).value(HTTPKEY::ACCOUNTTIME);
        HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ACCOUNT_STO_PAGE).
                              arg(number, accountTime), PROTOCOL::URL_ACCOUNT_STO_PAGE);

        ui->labelNumber->setText(tr("入库单号"));
        ui->labelWareHouse->setText(tr("入库仓库"));
        ui->labelDate->setText(tr("入库日期"));
        ui->labelTime->setText(tr("入库时间"));
        ui->labelMaterial->setText(tr(" 入库原料"));
    }
    else
    {
        HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ACCOUNT_RET_PAGE).
                              arg(accountMapList.at(index.row()).value(HTTPKEY::NUMBER)), PROTOCOL::URL_ACCOUNT_RET_PAGE);

        ui->labelNumber->setText(tr("退货单号"));
        ui->labelWareHouse->setText(tr("退货仓库"));
        ui->labelDate->setText(tr("退货日期"));
        ui->labelTime->setText(tr("退货时间"));
        ui->labelMaterial->setText(tr(" 退货原料"));
    }

    ui->tabWidgetAccount->show();
}

/************************  确认事件       *********************/
void AccountManage::on_commandLinkButtonSure_clicked()
{
    QByteArray byteArray;

    byteArray.append(POSTARG::AFFIRMACCOUNT.arg(number, realityTime));
    if(ui->commandLinkButtonSure->text() == tr("确认结算"))
    {
        HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_ACCOUNT_AFFIRM_ACC), byteArray, PROTOCOL::URL_ACCOUNT_AFFIRM_ACC);
    }
    else
    {
        HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_ACCOUNT_AFFIRM_PRO), byteArray, PROTOCOL::URL_ACCOUNT_AFFIRM_PRO);
    }
}

/************************  查询操作记录    *********************/
void AccountManage::on_commandLinkButtonLog_clicked()
{
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ACCOUNT_SEL_DISPOSE).arg(number), PROTOCOL::URL_ACCOUNT_SEL_DISPOSE);
}

/************************  双击事件       *********************/
void AccountManage::on_tableWidgetInfo_doubleClicked(const QModelIndex &index)
{
    if(index.row() < 0  || index.row() >= materialMapList.size()) return;

    if(number.contains("STO"))
    {
        QString stoMatId    = materialMapList.at(index.row()).value(HTTPKEY::STORAGEDELIVERYID);

        HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ACCOUNT_STO_MAT_INFO).arg(stoMatId), PROTOCOL::URL_ACCOUNT_STO_MAT_INFO);
    }
    else
    {
        QString retMatId = materialMapList.at(index.row()).value(HTTPKEY::RETURNSMATERIALID);
        QString wareHouseId = retMapData.value(HTTPKEY::WAREHOUSEID);

        HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ACCOUNT_RET_MAT_INFO)
                              .arg(retMatId, "", wareHouseId), PROTOCOL::URL_ACCOUNT_RET_MAT_INFO);
    }
}

/************************  筛选          *********************/
void AccountManage::on_pushButtonSelect_clicked()
{
    int stateIndex = ui->comboBoxState->currentIndex();
    if(stateIndex < 0 || stateIndex >= mapListState.size()) return;

    int typeIndex = ui->comboBoxType->currentIndex();
    if(typeIndex < 0 || typeIndex >= mapListType.size()) return;

    int supIndex = ui->comboBoxSupplier->currentIndex();
    if(supIndex < 0 || supIndex >= mapListSupplier.size()) return;

    int timeIndex = ui->comboBoxTimeType->currentIndex();
    if(timeIndex < 0 || timeIndex >= mapListTime.size()) return;

    QString strPost = MESSAGEURL(PROTOCOL::URL_ACCOUNT_FILTRATE).arg(mapListState.at(stateIndex).value(HTTPKEY::STATEID));

    strPost = strPost.arg(mapListSupplier.at(supIndex).value(HTTPKEY::SUPPLIERID));

    strPost = strPost.arg(mapListType.at(typeIndex).value(HTTPKEY::TYPEID));

    if(mapListTime.at(timeIndex).value(HTTPKEY::NAME) == "自定义")
    {
        QString strTime = QString::number(ui->dateEditStartTime->dateTime().toTime_t()) + "," +
                QString::number(ui->dateEditEndTime->dateTime().toTime_t());

        strPost = strPost.arg(strTime);
    }
    else
    {
        strPost = strPost.arg(mapListTime.at(timeIndex).value(HTTPKEY::TIME));
    }

    HTTPCLIENT->getUrlReq(strPost, PROTOCOL::URL_ACCOUNT_FILTRATE);
}

/************************  设置时间       *********************/
void AccountManage::on_comboBoxTimeType_activated(const QString &arg1)
{
    if(arg1 == "自定义")
    {
        ui->labelEndTime->show();
        ui->labelBeginTime->show();
        ui->dateEditEndTime->show();
        ui->dateEditStartTime->show();
    }
    else
    {
        ui->dateEditEndTime->setHidden(true);
        ui->dateEditStartTime->setHidden(true);
        ui->labelEndTime->setHidden(true);
        ui->labelBeginTime->setHidden(true);
    }
}

/************************  导出到邮箱     *********************/
void AccountManage::on_pushButtonExport_clicked()
{
    accountExport->showWidget();
}
