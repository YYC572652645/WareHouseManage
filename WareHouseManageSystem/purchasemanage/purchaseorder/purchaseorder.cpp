#include "purchaseorder.h"
#include "ui_purchaseorder.h"
#include "messagebox/messagedialog.h"
#include "httpclient/httpkey.h"
#include <QCalendarWidget>

/*********************  构造函数       *********************/
PurchaseOrder::PurchaseOrder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PurchaseOrder)
  ,addPurMaterial(NULL)
  ,editPurMaterial(NULL), materialPurInfo(NULL)
  ,confirmMat(NULL),  showType(SHOWSUCCESS)
  ,importFlage(false), saveFlage(false), selectFlage(true)
{
    ui->setupUi(this);

    this->initControl();
}

/*********************  析构函数       *********************/
PurchaseOrder::~PurchaseOrder()
{
    delete ui;
}

/*********************  显示窗口       *********************/
void PurchaseOrder::showWidget()
{
    this->show();
    importFlage = false;
    ui->tabWidgetPurchase->setHidden(true);
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_PUR_SELECT_PAGE), PROTOCOL::URL_PUR_SELECT_PAGE);
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_PUR_SEL_ALL), PROTOCOL::URL_PUR_SEL_ALL);
}

/*********************  初始化控件       *********************/
void PurchaseOrder::initControl()
{
    SETTABLEWIDGET(ui->tableWidgetPur);
    SETTABLEWIDGET(ui->tableWidgetPurInfo);

    ui->tabWidgetPurchase->setHidden(true);
    ui->dateEditArriveTime->setCalendarPopup(true);
    ui->dateEditArriveTimeInfo->setCalendarPopup(true);
    ui->dateEditSelect->setCalendarPopup(true);

    ui->comboBoxPurWarHse->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxPurWarHseInfo->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxSupplier->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxSupplierInfo->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxStateSelect->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxSupplierSelect->setFocusPolicy(Qt::NoFocus);

    ui->comboBoxPurWarHse->setView(new QListView());
    ui->comboBoxPurWarHseInfo->setView(new QListView());
    ui->comboBoxSupplier->setView(new QListView());
    ui->comboBoxSupplierInfo->setView(new QListView());
    ui->comboBoxStateSelect->setView(new QListView());
    ui->comboBoxSupplierSelect->setView(new QListView());

    ui->comboBoxStateSelect->view()->setMinimumWidth(200);
    ui->comboBoxSupplierSelect->view()->setMinimumWidth(200);

    ui->dateEditSelect->setDate(QDate::currentDate());
    ui->dateEditArriveTime->setDate(QDate::currentDate());

    if(CONFIGJSON->getLanguage().toInt())
    {
        ui->dateEditSelect->calendarWidget()->setLocale(QLocale(QLocale::English));
        ui->dateEditArriveTime->calendarWidget()->setLocale(QLocale(QLocale::English));
        ui->dateEditArriveTimeInfo->calendarWidget()->setLocale(QLocale(QLocale::English));
    }

    addPurMaterial  = new AddPurMaterial(this);
    editPurMaterial = new AddPurMaterial(this);
    materialPurInfo = new MaterialPurInfo(this);
    confirmMat      = new ConfirmMat(this);
    importHistory   = new ImportHistory(this);
    templatePur     = new TemplatePur(this);
    logInfo         = new LogInfo(this);
    extendPurEmail  = new ExtendPurEmail(this);

    //根据分辨率适配
    QDesktopWidget *desktop = QApplication::desktop();

    if(desktop->height() >= GLOBALDEF::DESKTOPHEIGHT)
    {
        ui->tabPurInfo->layout()->setSpacing(6);
        this->setStyleSheet(GLOBALDEF::THISSTYLE);

        ui->labelState->setMinimumHeight(30);
        ui->labelSup->setMinimumHeight(30);
        ui->labelArrive->setMinimumHeight(30);
        ui->labelSize->setMinimumHeight(30);
    }
    else
    {
        this->setStyleSheet(GLOBALDEF::SMALLSTYLE);

        ui->labelState->setMinimumHeight(20);
        ui->labelSup->setMinimumHeight(20);
        ui->labelArrive->setMinimumHeight(20);
        ui->labelSize->setMinimumHeight(20);
    }

    FlowLayout *flowLayout = new FlowLayout(ui->widgetControl);

    flowLayout->addWidget(ui->labelState);
    flowLayout->addWidget(ui->comboBoxStateSelect);
    flowLayout->addWidget(ui->labelSup);
    flowLayout->addWidget(ui->comboBoxSupplierSelect);
    flowLayout->addWidget(ui->labelArrive);
    flowLayout->addWidget(ui->dateEditSelect);
    flowLayout->addWidget(ui->pushButtonSelect);
    flowLayout->addWidget(ui->pushButtonTemplate);
    flowLayout->addWidget(ui->pushButtonExtend);
    flowLayout->addWidget(ui->pushButtonAdd);
    flowLayout->addWidget(ui->labelSize);

    ui->widgetControl->setLayout(flowLayout);
}

/*********************  解析json       *********************/
void PurchaseOrder::readJson(QNetworkReply *reply, int type)
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

                if(type == PROTOCOL::URL_PUR_SEL_ALL || type == PROTOCOL::URL_PUR_SELECT)
                {
                    if(ISERROR(codeValue))
                    {
                        ui->tableWidgetPur->clearContents();
                        ui->tableWidgetPur->setRowCount(0);
                        purMapList.clear();
                        ui->labelSize->setText(GLOBALDEF::TOTALONUMBER.arg(0));
                        extendPurEmail->setDataMapList(purMapList);
                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, purMapList);

                    if(!importFlage)
                    {
                        extendPurEmail->setDataMapList(purMapList);
                        this->setPurTableData();
                    }
                    else
                    {
                        importHistory->setPurMapList(purMapList);
                        importFlage = false;
                    }
                }
                else if(type == PROTOCOL::URL_PUR_INDENT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO) errorMsg = MESSAGE::ERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::SUPPLIERLIST, supMapList);
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::WAREHOUSELIST, wareHpuseMapList);

                    this->setAddControlData();
                }
                else if(type == PROTOCOL::URL_PUR_ADD_INDENT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ADDERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectFlage = true;
                    saveFlage = true;
                    if(showType == SHOWSUCCESS) MESSAGEBOX->showMessageBox(this, GLOBALDEF::ADDSUCCESS, true);
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_PUR_SEL_ALL), PROTOCOL::URL_PUR_SEL_ALL);

                    Map mapData;
                    HTTPCLIENT->readJsonMap(jsonObject, HTTPKEY::MSG, mapData);

                    puchaseNumber = mapData.value(HTTPKEY::PURCHASENUMBER);
                    addPurMaterial->setPurchaseNumber(mapData.value(HTTPKEY::PURCHASENUMBER));
                    addPurMaterial->setSupplierId(mapData.value(HTTPKEY::SUPPLIERID));

                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_PUR_GET_MAT).arg(mapData.value(HTTPKEY::PURCHASENUMBER),
                                                                                    mapData.value(HTTPKEY::SUPPLIERID)), PROTOCOL::URL_PUR_GET_MAT);
                }
                else if(type == PROTOCOL::URL_PUR_SEL)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::SELECTERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    HTTPCLIENT->readJsonMap(jsonNextObj, HTTPKEY::PURCHASEDATA, mapPurchaseInfo);
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::MATERIALLIST, purMatMapList);

                    if(jsonNextObj.contains(HTTPKEY::STORAGEID))
                    {
                        mapPurchaseInfo[HTTPKEY::STORAGEID] = QString::number(jsonNextObj.value(HTTPKEY::STORAGEID).toInt());
                    }

                    puchaseNumber = mapPurchaseInfo.value(HTTPKEY::PURCHASENUMBER);
                    editPurMaterial->setPurchaseNumber(mapPurchaseInfo.value(HTTPKEY::PURCHASENUMBER));
                    editPurMaterial->setSupplierId(mapPurchaseInfo.value(HTTPKEY::SUPPLIERID));

                    editPurMaterial->setMapSelectList(purMatMapList);
                    ui->tabWidgetPurchase->addTab(ui->tabPurInfo, GLOBALDEF::PURINFO);
                    ui->tabWidgetPurchase->setCurrentWidget(ui->tabPurInfo);
                    ui->tabWidgetPurchase->removeTab(ui->tabWidgetPurchase->indexOf(ui->tabAddPur));
                    ui->tabWidgetPurchase->show();

                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_PUR_INDENT), PROTOCOL::URL_PUR_INDENT);

                    this->setControlData();
                }
                else if(type == PROTOCOL::URL_PUR_GET_MAT)
                {
                    MapList mapList;
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        addPurMaterial->setMapMatList(mapList);
                        editPurMaterial->setMapMatList(mapList);
                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::MATERIALLIST, mapList);

                    addPurMaterial->setMapMatList(mapList);
                    editPurMaterial->setMapMatList(mapList);
                }
                else if(type == PROTOCOL::URL_PUR_UPDATE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::EDITERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectFlage = false;
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_PUR_SEL_ALL), PROTOCOL::URL_PUR_SEL_ALL);
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::EDITSUCCESS, true);
                    ui->tabWidgetPurchase->setHidden(true);
                }
                else if(type == PROTOCOL::URL_PUR_ADD_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ADDERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::ADDSUCCESS, true);
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_PUR_SEL).arg(puchaseNumber), PROTOCOL::URL_PUR_SEL);
                }
                else if(type == PROTOCOL::URL_PUR_DEL_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::DELERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(editPurMaterial, errorMsg);
                        return;
                    }

                    MESSAGEBOX->showMessageBox(editPurMaterial, GLOBALDEF::DELSUCCESS, true);
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_PUR_SEL).arg(puchaseNumber), PROTOCOL::URL_PUR_SEL);
                }
                else if(type == PROTOCOL::URL_PUR_SEL_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    materialPurInfo->showWidget();

                    Map mapData;
                    HTTPCLIENT->readJsonMap(jsonObject, HTTPKEY::MSG, mapData);

                    MapList mapListData;
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::UNITLIST, mapListData);

                    materialPurInfo->setMatMap(mapData);
                    materialPurInfo->setUnitMapList(mapListData);

                    materialPurInfo->setControlData();
                }
                else if(type == PROTOCOL::URL_PUR_UPDATE_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::EDITERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::EDITSUCCESS, true);
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_PUR_SEL).arg(puchaseNumber), PROTOCOL::URL_PUR_SEL);
                }
                else if(type == PROTOCOL::URL_PUR_EXAMINE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == THREE)
                        {
                            int ok = MESSAGEBOX->showMessageBox(this, MESSAGE::PURMATMSG, true, false);

                            if(ok == QDialog::Accepted) HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_PUR_AFFIRMPAGE).arg(puchaseNumber), PROTOCOL::URL_PUR_AFFIRMPAGE);
                        }
                        else
                        {
                            if(codeValue == ZERO)     errorMsg = MESSAGE::SUPNOTEXIST;
                            else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                            MESSAGEBOX->showMessageBox(this, errorMsg);
                        }
                        return;
                    }

                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_PUR_AFFIRMPAGE).arg(puchaseNumber), PROTOCOL::URL_PUR_AFFIRMPAGE);
                }
                else if(type == PROTOCOL::URL_PUR_AFFIRMPAGE)
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

                    confirmMat->setMapListMat(mapListData);
                    confirmMat->setPurNumber(puchaseNumber);
                    confirmMat->showWidget();
                }
                else if(type == PROTOCOL::URL_PUR_AFFIRM)
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
                else if(type == PROTOCOL::URL_PUR_COPY)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectFlage = true;
                    this->showWidget();
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::IMPORTSUCCESS, true);
                }
                else if(type == PROTOCOL::URL_PUR_DEL)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::DELERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectFlage = false;
                    this->showWidget();
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::DELSUCCESS, true);
                }
                else if(type == PROTOCOL::URL_PUR_SEL_TEMPLATE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)      errorMsg = MESSAGE::ERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    MapList mapListData;
                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, mapListData);
                    templatePur->setMapListTemplate(mapListData);

                    templatePur->showWidget();
                }
                else if(type == PROTOCOL::URL_PUR_NUMBER)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::TEMPLATEMATNULL;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        templatePur->setHide();
                        MESSAGEBOX->showMessageBox(templatePur, errorMsg);
                        return;
                    }

                    templatePur->setShow();
                    MapList mapListData;
                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, mapListData);

                    templatePur->setPurMapList(mapListData);
                }
                else if(type == PROTOCOL::URL_PUR_TEMPLATE_ADD)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    templatePur->close();
                    this->showWidget();
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::MAKESUCCESS, true);
                }
                else if(type == PROTOCOL::URL_PUR_SEL_DISPOSE)
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
                else if(type == PROTOCOL::URL_PUR_SELECT_PAGE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

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
                            else if(stateName == GLOBALDEF::CHIPURFINISH) stateName = GLOBALDEF::ENGPURFINISH;
                        }

                        ui->comboBoxStateSelect->addItem(stateName);
                    }

                    ui->comboBoxSupplierSelect->clear();
                    for(int i = 0; i < supSelectMapList.size(); i ++)
                    {
                        QString supName = supSelectMapList.at(i).value(HTTPKEY::SUPPLIERNAME);

                        if(CONFIGJSON->getLanguage().toInt())
                        {
                            if(supName == GLOBALDEF::CHIALL) supName = GLOBALDEF::ENGALL;
                        }

                        ui->comboBoxSupplierSelect->addItem(supName);
                    }
                }
                else if(type == PROTOCOL::URL_PUR_EXTEND)
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

/*********************  设置表格数据        *********************/
void PurchaseOrder::setPurTableData()
{
    ui->labelSize->setText(GLOBALDEF::TOTALONUMBER.arg(purMapList.size()));
    ui->tableWidgetPur->setRowCount(purMapList.size());

    for(int i = 0; i < purMapList.size(); i ++)
    {
        ui->tableWidgetPur->setItem(i, ZERO,  DATA(purMapList.at(i).value(HTTPKEY::SUPPLIERNAME)));
        ui->tableWidgetPur->setItem(i, ONE,   DATA(purMapList.at(i).value(HTTPKEY::PURCHASENUMBER)));
        ui->tableWidgetPur->setItem(i, TWO,   DATA(QDateTime::fromTime_t(purMapList.at(i).value(HTTPKEY::ARRIVALTIME).toUInt()).toString("yyyy-MM-dd")));
        ui->tableWidgetPur->setItem(i, THREE, DATA(purMapList.at(i).value(HTTPKEY::PURCHASESTATE) == "0" ? tr("未提交") : tr("采购完成")));

        ui->tableWidgetPur->item(i, THREE)->setFont(QFont("ZYSong", 12, QFont::Bold));
        if(purMapList.at(i).value(HTTPKEY::PURCHASESTATE) == "0")
        {
            ui->tableWidgetPur->item(i, THREE)->setTextColor(Qt::darkBlue);
        }
        else
        {
            ui->tableWidgetPur->item(i, THREE)->setTextColor(Qt::darkGreen);
        }
        SETTABLECENTER(ui->tableWidgetPur->item(i, 0));
        SETTABLECENTER(ui->tableWidgetPur->item(i, ONE));
        SETTABLECENTER(ui->tableWidgetPur->item(i, TWO));
        SETTABLECENTER(ui->tableWidgetPur->item(i, THREE));
    }

    if(selectFlage)
    {
        ui->tableWidgetPur->scrollToBottom();
        ui->tableWidgetPur->selectRow(ui->tableWidgetPur->rowCount() - 1);
    }
}

/*********************  清空信息        *********************/
void PurchaseOrder::clearInfo()
{
    ui->comboBoxPurWarHse->clear();
    ui->lineEditRemark->clear();
    ui->comboBoxSupplier->clear();
}

/*********************  设置控件数据        *********************/
void PurchaseOrder::setControlData()
{
    ui->lineEditNumberInfo->setText(mapPurchaseInfo.value(HTTPKEY::PURCHASENUMBER));
    ui->lineEditRemarkInfo->setText(mapPurchaseInfo.value(HTTPKEY::PURCHASEREMARK));
    ui->lineEditStateInfo->setText(mapPurchaseInfo.value(HTTPKEY::PURCHASESTATE) == "0" ? tr("未提交") : tr("采购完成"));
    ui->dateEditArriveTimeInfo->setDateTime(QDateTime::fromTime_t(mapPurchaseInfo.value(HTTPKEY::ARRIVALTIME).toUInt()));
    ui->labelTotalCount->setText(tr("合计%1项").arg(purMatMapList.size()));

    ui->tableWidgetPurInfo->setRowCount(purMatMapList.size());
    for(int i = 0; i < purMatMapList.size(); i ++)
    {
        ui->tableWidgetPurInfo->setItem(i, ZERO,  DATA(purMatMapList.at(i).value(HTTPKEY::MATERIALNAME)));
        ui->tableWidgetPurInfo->setItem(i, ONE,   DATA(purMatMapList.at(i).value(HTTPKEY::BARCODE)));
        ui->tableWidgetPurInfo->setItem(i, TWO,   DATA(purMatMapList.at(i).value(HTTPKEY::PURCHASEUNITNAME)));
        ui->tableWidgetPurInfo->setItem(i, THREE, DATA(purMatMapList.at(i).value(HTTPKEY::PURCHASEPRICE)));
        ui->tableWidgetPurInfo->setItem(i, FOUR,  DATA(purMatMapList.at(i).value(HTTPKEY::PURCHASEAMOUNT)));
        ui->tableWidgetPurInfo->setItem(i, FIVE,  DATA(purMatMapList.at(i).value(HTTPKEY::INVENTORY)));

        SETTABLECENTER(ui->tableWidgetPurInfo->item(i, ZERO));
        SETTABLECENTER(ui->tableWidgetPurInfo->item(i, ONE));
        SETTABLECENTER(ui->tableWidgetPurInfo->item(i, TWO));
        SETTABLECENTER(ui->tableWidgetPurInfo->item(i, THREE));
        SETTABLECENTER(ui->tableWidgetPurInfo->item(i, FOUR));
        SETTABLECENTER(ui->tableWidgetPurInfo->item(i, FIVE));
    }
    ui->tableWidgetPurInfo->scrollToBottom();

    purchaseState = mapPurchaseInfo.value(HTTPKEY::PURCHASESTATE);
    if(purchaseState.toInt())
    {
        ui->comboBoxPurWarHseInfo->setEnabled(false);
        ui->dateEditArriveTimeInfo->setEnabled(false);
        ui->lineEditRemarkInfo->setEnabled(false);
        ui->comboBoxSupplierInfo->setEnabled(false);
        ui->pushButtonPurMatInfo->setHidden(true);
        ui->pushButtonSaveInfo->setHidden(true);
        ui->pushButtonCancelInfo->setHidden(true);
        ui->commandLinkButtonEdit->setHidden(true);
        ui->pushButtonDeleteInfo->setHidden(true);
        ui->pushButtonStartSureInfo->setHidden(true);
        ui->pushButtonLookInfo->show();
        materialPurInfo->setControlEnable(false);

    }
    else
    {
        ui->comboBoxPurWarHseInfo->setEnabled(true);
        ui->dateEditArriveTimeInfo->setEnabled(true);
        ui->lineEditRemarkInfo->setEnabled(true);
        ui->comboBoxSupplierInfo->setEnabled(true);
        ui->pushButtonLookInfo->setHidden(true);
        materialPurInfo->setControlEnable(true);
        ui->pushButtonPurMatInfo->show();
        ui->pushButtonSaveInfo->show();
        ui->pushButtonCancelInfo->show();
        ui->commandLinkButtonEdit->show();
        ui->pushButtonDeleteInfo->show();
        purMatMapList.size() != 0 ?  ui->pushButtonStartSureInfo->show() :
                                     ui->pushButtonStartSureInfo->setHidden(true);
    }
}

/*********************  设置控件数据        *********************/
void PurchaseOrder::setAddControlData()
{
    ui->comboBoxSupplier->clear();
    ui->comboBoxPurWarHse->clear();
    ui->comboBoxPurWarHseInfo->clear();
    ui->comboBoxSupplierInfo->clear();

    for(int i = 0; i < supMapList.size(); i ++)
    {
        ui->comboBoxSupplier->addItem(supMapList.at(i).value(HTTPKEY::SUPPLIERNAME));
    }

    for(int i = 0; i < wareHpuseMapList.size(); i ++)
    {
        ui->comboBoxPurWarHse->addItem(wareHpuseMapList.at(i).value(HTTPKEY::WAREHOUSENAME));
    }

    for(int i = 0; i < supMapList.size(); i ++)
    {
        ui->comboBoxSupplierInfo->addItem(supMapList.at(i).value(HTTPKEY::SUPPLIERNAME));

        if(mapPurchaseInfo.value(HTTPKEY::SUPPLIERID) == supMapList.at(i).value(HTTPKEY::SUPPLIERID))
        {
            ui->comboBoxSupplierInfo->setCurrentIndex(i);
        }
    }

    bool flage = false;
    for(int i = 0; i < wareHpuseMapList.size(); i ++)
    {
        ui->comboBoxPurWarHseInfo->addItem(wareHpuseMapList.at(i).value(HTTPKEY::WAREHOUSENAME));

        if(mapPurchaseInfo.value(HTTPKEY::PURWAREHOUSE) == wareHpuseMapList.at(i).value(HTTPKEY::WAREHOUSEID))
        {
            ui->comboBoxPurWarHseInfo->setCurrentIndex(i);
            flage = true;
        }
    }

    if(!flage)
    {
        ui->comboBoxPurWarHseInfo->setCurrentIndex(-1);
    }

    ui->comboBoxPurWarHse->setCurrentIndex(-1);
}

/*********************  添加采购订单        *********************/
void PurchaseOrder::on_pushButtonAdd_clicked()
{
    saveFlage = false;
    this->clearInfo();
    ui->tabWidgetPurchase->addTab(ui->tabAddPur, GLOBALDEF::ADDPURCHASE);
    ui->tabWidgetPurchase->setCurrentWidget(ui->tabAddPur);
    ui->tabWidgetPurchase->removeTab(ui->tabWidgetPurchase->indexOf(ui->tabPurInfo));
    ui->tabWidgetPurchase->show();

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_PUR_INDENT), PROTOCOL::URL_PUR_INDENT);
}

/*********************  采购订单详情        *********************/
void PurchaseOrder::on_tableWidgetPur_clicked(const QModelIndex &index)
{
    if(index.row() >= purMapList.size()) return;

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_PUR_SEL).arg(purMapList.at(index.row()).value(HTTPKEY::PURCHASENUMBER)), PROTOCOL::URL_PUR_SEL);

    purchaseState = purMapList.at(index.row()).value(HTTPKEY::PURCHASESTATE);
}

/*********************  保存采购订单        *********************/
void PurchaseOrder::on_pushButtonSave_clicked()
{
    showType = SHOWSUCCESS;

    if(ui->comboBoxSupplier->currentIndex() < 0)
    {
        MESSAGEBOX->showMessageBox(this, MESSAGE::SUPCANNOTNULL);
        return;
    }

    if(ui->comboBoxSupplier->currentIndex() >= supMapList.size()) return;
    if(ui->comboBoxPurWarHse->currentIndex() >= wareHpuseMapList.size()) return;

    QByteArray byteArray;

    QString strPost = POSTARG::ADDPURINDENT.arg(supMapList.at(ui->comboBoxSupplier->currentIndex()).value(HTTPKEY::SUPPLIERID));

    strPost = strPost.arg(ui->comboBoxPurWarHse->currentIndex() < 0 ? "" : wareHpuseMapList.at(ui->comboBoxPurWarHse->currentIndex()).value(HTTPKEY::WAREHOUSEID));

    strPost = strPost.arg(ui->lineEditRemark->text(), QString::number(ui->dateEditArriveTime->dateTime().toTime_t()));

    byteArray.append(strPost);

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_PUR_ADD_INDENT), byteArray, PROTOCOL::URL_PUR_ADD_INDENT);
}

/*********************  取消添加        *********************/
void PurchaseOrder::on_pushButtonCancel_clicked()
{
    ui->tabWidgetPurchase->setHidden(true);
}

/*********************  添加采购原料        *********************/
void PurchaseOrder::on_pushButtonAddPurMat_clicked()
{
    if(!saveFlage)
    {
        on_pushButtonSave_clicked();
    }

    addPurMaterial->showWidget(AddPurMaterial::ADDTYPE);

    showType = NOTSHOW;
}

/*********************  编辑采购原料        *********************/
void PurchaseOrder::on_commandLinkButtonEdit_clicked()
{
    editPurMaterial->showWidget(AddPurMaterial::EDITTYPE);
    editPurMaterial->setTableEidiData();
}

/*********************  添加采购原料        *********************/
void PurchaseOrder::on_pushButtonPurMatInfo_clicked()
{
    editPurMaterial->showWidget(AddPurMaterial::ADDTYPE);
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_PUR_GET_MAT).arg(editPurMaterial->getPurchaseNumber(),
                                                                    editPurMaterial->getSupplierId()), PROTOCOL::URL_PUR_GET_MAT);
}

/*********************  删除数据        *********************/
void PurchaseOrder::on_pushButtonDeleteInfo_clicked()
{
    QByteArray byteArray;

    byteArray.append(POSTARG::DELPUR.arg(puchaseNumber));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_PUR_DEL), byteArray, PROTOCOL::URL_PUR_DEL);
}

/*********************  更新数据        *********************/
void PurchaseOrder::on_pushButtonSaveInfo_clicked()
{
    if(ui->comboBoxSupplierInfo->currentIndex() < 0)
    {
        MESSAGEBOX->showMessageBox(this, MESSAGE::SUPCANNOTNULL);
        return;
    }

    if(ui->comboBoxSupplierInfo->currentIndex() >= supMapList.size()) return;
    if(ui->comboBoxPurWarHseInfo->currentIndex() >= wareHpuseMapList.size()) return;

    QByteArray byteArray;

    QString strPost = POSTARG::UPDATEPUR.arg(puchaseNumber, supMapList.at(ui->comboBoxSupplierInfo->currentIndex()).value(HTTPKEY::SUPPLIERID));

    strPost = strPost.arg(ui->comboBoxPurWarHseInfo->currentIndex() < 0 ? "" : wareHpuseMapList.at(ui->comboBoxPurWarHseInfo->currentIndex()).value(HTTPKEY::WAREHOUSEID));

    strPost = strPost.arg(QString::number(ui->dateEditArriveTimeInfo->dateTime().toTime_t()), ui->lineEditRemarkInfo->text());

    byteArray.append(strPost);

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_PUR_UPDATE), byteArray, PROTOCOL::URL_PUR_UPDATE);
}

/*********************  双击查询原料信息        *********************/
void PurchaseOrder::on_tableWidgetPurInfo_doubleClicked(const QModelIndex &index)
{
    if(index.row() >= purMatMapList.size()) return;

    QString MaterialId = purMatMapList.at(index.row()).value(HTTPKEY::MATERIALID);
    QString purchaseState = mapPurchaseInfo.value(HTTPKEY::PURCHASESTATE);

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_PUR_SEL_MAT).arg(MaterialId, puchaseNumber, purchaseState), PROTOCOL::URL_PUR_SEL_MAT);
}

/*********************  取消事件        *********************/
void PurchaseOrder::on_pushButtonCancelInfo_clicked()
{
    ui->tabWidgetPurchase->setHidden(true);
}

/*********************  确认采购原料        *********************/
void PurchaseOrder::on_pushButtonStartSureInfo_clicked()
{
    List listData;

    for(int i = 0; i < purMatMapList.size(); i ++)
    {
        listData.append(purMatMapList.at(i).value(HTTPKEY::MATERIALID));
    }

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_PUR_EXAMINE).arg(mapPurchaseInfo.value(HTTPKEY::SUPPLIERID),
                                                                    addPurMaterial->makeJson(listData)), PROTOCOL::URL_PUR_EXAMINE);
}

/*********************  查看整体入库单        *********************/
void PurchaseOrder::on_pushButtonLookInfo_clicked()
{
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STO_GET_ID).arg(mapPurchaseInfo.value(HTTPKEY::STORAGEID)), PROTOCOL::URL_STO_GET_ID);
}

/*********************  从历史订单中导入        *********************/
void PurchaseOrder::on_commandLinkButtonImport_clicked()
{
    importFlage = true;
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_PUR_SEL_ALL), PROTOCOL::URL_PUR_SEL_ALL);
    importHistory->showWidget();
}

/*********************  模板采购        *********************/
void PurchaseOrder::on_pushButtonTemplate_clicked()
{
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_PUR_SEL_TEMPLATE), PROTOCOL::URL_PUR_SEL_TEMPLATE);
}

/*********************  处理记录        *********************/
void PurchaseOrder::on_commandLinkButtonLog_clicked()
{
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_PUR_SEL_DISPOSE).arg(puchaseNumber), PROTOCOL::URL_PUR_SEL_DISPOSE);
}

/*********************  查询数据        *********************/
void PurchaseOrder::on_pushButtonSelect_clicked()
{
    ui->tabWidgetPurchase->setHidden(true);
    int currentStaIndex = ui->comboBoxStateSelect->currentIndex();
    if(currentStaIndex < 0 ||currentStaIndex >= staSelectMapList.size()) return;

    int currentSupIndex = ui->comboBoxSupplierSelect->currentIndex();
    if(currentSupIndex < 0 ||currentSupIndex >= supSelectMapList.size()) return;

    QString stateId = staSelectMapList.at(currentStaIndex).value(HTTPKEY::STATEID);
    QString supId = supSelectMapList.at(currentSupIndex).value(HTTPKEY::SUPPLIERID);
    QString time  = QString::number(ui->dateEditSelect->dateTime().toTime_t());

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_PUR_SELECT).arg(stateId, supId, time), PROTOCOL::URL_PUR_SELECT);
}

/*********************  导出邮箱        *********************/
void PurchaseOrder::on_pushButtonExtend_clicked()
{
    extendPurEmail->showWidget();
}

