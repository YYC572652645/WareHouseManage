#include "supplierwidget.h"
#include "ui_supplierwidget.h"
#include "messagebox/messagedialog.h"
#include "httpclient/httpkey.h"
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>

/*********************  构造函数             *********************/
SupplierWidget::SupplierWidget(QWidget *parent) :
    QWidget(parent),ui(new Ui::SupplierWidget)
  ,saveType(BUTTONTYPE), selectFalge(false)
{
    ui->setupUi(this);
    this->initControl();
}

/*********************  析构函数           *********************/
SupplierWidget::~SupplierWidget()
{
    delete ui;
}

/*********************  初始化控件         *********************/
void SupplierWidget::initControl()
{
    SETTABLEWIDGET(ui->tableWidgetSupplier);
    SETTABLEWIDGET(ui->tableWidgetSupType);

    ui->comboBoxSupplierType->setView(new QListView());
    ui->comboBoxSupplierTypeInfo->setView(new QListView());
    ui->lineEditTaxRateInfo->setHidden(true);
    ui->labelTaxRateInfo->setHidden(true);
    ui->lineEditTaxRate->setHidden(true);
    ui->labelTaxRate->setHidden(true);
    ui->comboBoxSupplierType->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxSupplierTypeInfo->setFocusPolicy(Qt::NoFocus);

    supMaterial = new SupMaterial(this);
    addType = new AddType(this);
    updateType = new AddType(this);
    exportEmail = new ExportEmail(this);

    connect(addType,    SIGNAL(sendOk()), this, SLOT(slotReceiveAddType()));
    connect(updateType, SIGNAL(sendOk()), this, SLOT(slotReceiveUpdateType()));
    connect(supMaterial, SIGNAL(sendCount(int)), this, SLOT(slotRefreshCount(int)));
    connect(exportEmail, SIGNAL(sendEmail(QString)), this, SLOT(receiveEmailText(QString)));


    QRegExp regExpAdd("[0-9a-zA-Z]+$");
    QValidator *validatorAdd = new QRegExpValidator(regExpAdd, ui->lineEditSupplierNumber);
    ui->lineEditSupplierNumber->setValidator(validatorAdd);

    QRegExp regExpInfo("[0-9a-zA-Z]+$");
    QValidator *validatorInfo = new QRegExpValidator(regExpInfo, ui->lineEditSupplierNumberInfo);
    ui->lineEditSupplierNumberInfo->setValidator(validatorInfo);


    QRegExp regExpTaxRateAdd("[0-9]+$");
    QValidator *validatorTaxRateAdd = new QRegExpValidator(regExpTaxRateAdd, ui->lineEditTaxRate);
    ui->lineEditTaxRate->setValidator(validatorTaxRateAdd);

    QRegExp regExpTaxRateInfo("[0-9]+$");
    QValidator *validatorTaxRateInfo = new QRegExpValidator(regExpTaxRateInfo, ui->lineEditTaxRateInfo);
    ui->lineEditTaxRateInfo->setValidator(validatorTaxRateInfo);

    //根据分辨率适配
    QDesktopWidget *desktop = QApplication::desktop();

    if(desktop->height() >= GLOBALDEF::DESKTOPHEIGHT)
    {
        ui->labelSize->setMinimumHeight(30);
        this->setStyleSheet(GLOBALDEF::THISSTYLE);
    }
    else
    {
        ui->labelSize->setMinimumHeight(20);
        this->setStyleSheet(GLOBALDEF::SMALLSTYLE);
    }

    FlowLayout *flowLayout = new FlowLayout(ui->widgetControl);

    flowLayout->addWidget(ui->pushButtonExtend);
    flowLayout->addWidget(ui->pushButtonAddSupplier);
    flowLayout->addWidget(ui->labelSize);

    ui->widgetControl->setLayout(flowLayout);
}

/*********************  显示窗口           *********************/
void SupplierWidget::showWidget()
{
    this->show();
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_SUP_GET_SUP_CAT), PROTOCOL::URL_SUP_GET_SUP_CAT);
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_SUP_GET_SUP_LIST), PROTOCOL::URL_SUP_GET_SUP_LIST);
    ui->tabWidgetSupplier->setHidden(true);
}

/*********************  解析JSON          *********************/
void SupplierWidget::readJson(QNetworkReply *reply, int type)
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

                if(type == PROTOCOL::URL_SUP_ADD_SUP_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;
                        MESSAGEBOX->showMessageBox(supMaterial, errorMsg);

                        return;
                    }

                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_SUP_SEL_MATERIAL).arg(supMaterial->getSupplierId()), PROTOCOL::URL_SUP_SEL_MATERIAL);
                    MESSAGEBOX->showMessageBox(supMaterial, GLOBALDEF::ADDSUCCESS, true);
                }
                else if(type == PROTOCOL::URL_SUP_ADD_SUP_CAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;
                        else if(codeValue == THREE) errorMsg = MESSAGE::SUPCATEXIST;

                        MESSAGEBOX->showMessageBox(this, errorMsg);

                        return;
                    }

                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_SUP_GET_SUP_CAT), PROTOCOL::URL_SUP_GET_SUP_CAT);
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::ADDSUCCESS, true);
                }
                else if(type == PROTOCOL::URL_SUP_GET_SUP_CAT)
                {
                    if(ISERROR(codeValue))
                    {
                        ui->tableWidgetSupType->clearContents();
                        ui->tableWidgetSupType->setRowCount(0);
                        typeMapList.clear();
                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, typeMapList);

                    ui->comboBoxSupplierType->clear();
                    ui->comboBoxSupplierTypeInfo->clear();

                    ui->tableWidgetSupType->setRowCount(typeMapList.size());
                    for(int i = 0; i < typeMapList.size(); i ++)
                    {
                        ui->comboBoxSupplierType->addItem(typeMapList.at(i).value(HTTPKEY::SUPPLIERCATEGORYNAME));
                        ui->comboBoxSupplierTypeInfo->addItem(typeMapList.at(i).value(HTTPKEY::SUPPLIERCATEGORYNAME));
                        ui->tableWidgetSupType->setItem(i, 0, DATA(typeMapList.at(i).value(HTTPKEY::SUPPLIERCATEGORYNAME)));

                        SETTABLECENTER(ui->tableWidgetSupType->item(i, ZERO));
                    }
                    ui->tableWidgetSupType->scrollToBottom();
                }
                else if(type == PROTOCOL::URL_SUP_UPDATE_SUP_CAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::EDITERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;
                        MESSAGEBOX->showMessageBox(this, errorMsg);

                        return;
                    }

                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_SUP_GET_SUP_CAT), PROTOCOL::URL_SUP_GET_SUP_CAT);
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::EDITSUCCESS, true);
                }
                else if(type == PROTOCOL::URL_SUP_DEL_SUP_CAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::DELERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;
                        else if(codeValue == THREE) errorMsg = MESSAGE::SUPEXISTOTHERCAT;
                        MESSAGEBOX->showMessageBox(this, errorMsg);

                        return;
                    }

                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_SUP_GET_SUP_CAT), PROTOCOL::URL_SUP_GET_SUP_CAT);
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::DELSUCCESS, true);
                }
                else if(type == PROTOCOL::URL_SUP_GET_SUP_LIST)
                {
                    if(ISERROR(codeValue))
                    {
                        ui->tableWidgetSupplier->clearContents();
                        ui->tableWidgetSupplier->setRowCount(0);
                        supMapList.clear();
                        ui->labelSize->setText(GLOBALDEF::TOTALONUMBER.arg(0));

                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, supMapList);

                    this->setTableSupData();
                }
                else if(type == PROTOCOL::URL_SUP_DETAILS)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;
                        MESSAGEBOX->showMessageBox(this, errorMsg);

                        return;
                    }

                    HTTPCLIENT->readJsonMap(jsonObject, HTTPKEY::MSG, supDetailsMap);
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::MATERIAL, materialMapList);
                    supMaterial->setSupplierId(supDetailsMap.value(HTTPKEY::SUPPLIERID));

                    this->setSupplierInfo();
                }
                else if(type == PROTOCOL::URL_SUP_UPDATE_SUP)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::EDITERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;
                        else if(codeValue == THREE) errorMsg = MESSAGE::PHONEERROR;
                        else if(codeValue == FOUR)  errorMsg = MESSAGE::INVPHONEERROR;
                        else if(codeValue == FIVE)  errorMsg = MESSAGE::EMAILERROR;
                        else if(codeValue == SIX)   errorMsg = MESSAGE::SUPEXIST;
                        else if(codeValue == SEVEN) errorMsg = MESSAGE::SUPNUMBEREXIST;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    ui->tabWidgetSupplier->setHidden(true);
                    selectFalge = false;
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_SUP_GET_SUP_LIST), PROTOCOL::URL_SUP_GET_SUP_LIST);
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::EDITSUCCESS, true);
                }
                else if(type == PROTOCOL::URL_SUP_DEL_SUP_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        supMaterial->setClear(true);
                        return;
                    }

                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_SUP_SEL_MATERIAL).arg(supMaterial->getSupplierId()), PROTOCOL::URL_SUP_SEL_MATERIAL);
                    MESSAGEBOX->showMessageBox(supMaterial, GLOBALDEF::DELSUCCESS, true);
                }
                else if(type == PROTOCOL::URL_SUP_DEL_SUP)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::DELERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;
                        MESSAGEBOX->showMessageBox(this, errorMsg);

                        return;
                    }

                    selectFalge = true;

                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_SUP_GET_SUP_LIST), PROTOCOL::URL_SUP_GET_SUP_LIST);
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::DELSUCCESS, true);

                    ui->tabWidgetSupplier->setHidden(true);
                }
                else if(type == PROTOCOL::URL_SUP_SEL_MATERIAL)
                {
                    if(ISERROR(codeValue))
                    {
                        supMaterial->setClear(true);
                        return;
                    }

                    MapList mapList;
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::MATERIAL, mapList);
                    supMaterial->setMaterialMapList(mapList);

                    mapList.clear();
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::CATEGORYLIST, mapList);
                    supMaterial->setCatMapList(mapList);

                    supMaterial->setTableMatData();
                }
                else if(type == PROTOCOL::URL_SUP_GET_MATERIAL)
                {
                    if(ISERROR(codeValue))
                    {
                        supMaterial->setClear(false);
                        return;
                    }

                    MapList mapList;
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::MATERIAL, mapList);
                    supMaterial->setAllMaterialMapList(mapList);

                    supMaterial->setAllTableMatData();
                }
            }

            if(type == PROTOCOL::URL_SUP_ADD_SUP)
            {
                if(ISERROR(codeValue))
                {
                    if(codeValue == ZERO)       errorMsg = MESSAGE::ADDERROR;
                    else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;
                    else if(codeValue == THREE) errorMsg = MESSAGE::PHONEERROR;
                    else if(codeValue == FOUR)  errorMsg = MESSAGE::INVPHONEERROR;
                    else if(codeValue == FIVE)  errorMsg = MESSAGE::EMAILERROR;
                    else if(codeValue == SIX)   errorMsg = MESSAGE::SUPEXIST;

                    MESSAGEBOX->showMessageBox(this, errorMsg);
                    return;
                }

                selectFalge = true;

                if(jsonObject.contains(HTTPKEY::SUPPLIERID))
                {
                    supMaterial->setSupplierId(jsonObject.value(HTTPKEY::SUPPLIERID).toString());
                }

                HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_SUP_GET_SUP_LIST), PROTOCOL::URL_SUP_GET_SUP_LIST);

                if(LINKTYPE == saveType)
                {
                    supMaterial->showWidget();
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_SUP_SEL_MATERIAL).arg(supMaterial->getSupplierId()), PROTOCOL::URL_SUP_SEL_MATERIAL);
                }
                else
                {
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::ADDSUCCESS, true);
                }

                ui->tabWidgetSupplier->setHidden(true);
            }
            else if(type == PROTOCOL::URL_SUP_SEL_MATERIAL)
            {
                if(ISERROR(codeValue))
                {
                    if(codeValue == ZERO)       errorMsg = MESSAGE::ERROR;
                    else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;
                    MESSAGEBOX->showMessageBox(this, errorMsg);

                    return;
                }

                if(jsonObject.contains(HTTPKEY::SUPPLIERID))
                {
                    supMaterial->setSupplierId(jsonObject.value(HTTPKEY::SUPPLIERID).toString());
                }
            }
            else if(type == PROTOCOL::URL_SUP_EXTEND)
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
        reply->close();
    }
}

/*********************  添加表格数据       *********************/
void SupplierWidget::setTableSupData()
{
    ui->labelSize->setText(GLOBALDEF::TOTALONUMBER.arg(supMapList.size()));
    ui->tableWidgetSupplier->setRowCount(supMapList.size());

    for(int i = 0; i < supMapList.size(); i ++)
    {
        ui->tableWidgetSupplier->setItem(i, ZERO, DATA(supMapList.at(i).value(HTTPKEY::SUPPLIERNAME)));
        ui->tableWidgetSupplier->setItem(i, ONE, DATA(supMapList.at(i).value(HTTPKEY::NUMBER)));
        ui->tableWidgetSupplier->setItem(i, TWO, DATA(supMapList.at(i).value(HTTPKEY::LINKMAN)));
        ui->tableWidgetSupplier->setItem(i, THREE, DATA(supMapList.at(i).value(HTTPKEY::PHONE)));

        SETTABLECENTER(ui->tableWidgetSupplier->item(i, ZERO));
        SETTABLECENTER(ui->tableWidgetSupplier->item(i, ONE));
        SETTABLECENTER(ui->tableWidgetSupplier->item(i, TWO));
        SETTABLECENTER(ui->tableWidgetSupplier->item(i, THREE));
    }

    if(selectFalge)
    {
        ui->tableWidgetSupplier->scrollToBottom();
        ui->tableWidgetSupplier->selectRow(ui->tableWidgetSupplier->rowCount() - 1);
    }
}

/*********************  设置数据          *********************/
void SupplierWidget::setSupplierInfo()
{
    ui->lineEditSupplierNameInfo->setText(supDetailsMap.value(HTTPKEY::SUPPLIERNAME));
    ui->lineEditSupplierNumberInfo->setText(supDetailsMap.value(HTTPKEY::NUMBER));
    ui->lineEditPeopleInfo->setText(supDetailsMap.value(HTTPKEY::LINKMAN));
    ui->lineEditPhoneNumberInfo->setText(supDetailsMap.value(HTTPKEY::PHONE));
    ui->lineEditEmailInfo->setText(supDetailsMap.value(HTTPKEY::EMAIL));
    ui->comboBoxSupplierTypeInfo->setCurrentText(supDetailsMap.value(HTTPKEY::SUPPLIERCATEGORY));

    if(supDetailsMap.value(HTTPKEY::INVOICE) != "0")
    {
        ui->checkBoxInvoiceInfo->setChecked(true);
        ui->lineEditTaxRateInfo->setText(supDetailsMap.value(HTTPKEY::TAXRATE));
        ui->lineEditTaxRateInfo->show();
        ui->labelTaxRateInfo->show();
    }
    else
    {
        ui->checkBoxInvoiceInfo->setChecked(false);
        ui->lineEditTaxRateInfo->setHidden(true);
        ui->labelTaxRateInfo->setHidden(true);
        ui->lineEditTaxRateInfo->clear();
    }

    ui->lineEditPhoneInfo->setText(supDetailsMap.value(HTTPKEY::INVOICEPHONE));
    ui->lineEditWeiChatInfo->setText(supDetailsMap.value(HTTPKEY::WECHAT));
    ui->lineEditFaxNumberInfo->setText(supDetailsMap.value(HTTPKEY::FAXNUMBER));
    ui->lineEditAddressInfo->setText(supDetailsMap.value(HTTPKEY::CONTACTADDRESS));
    ui->lineEditBankNameInfo->setText(supDetailsMap.value(HTTPKEY::BANKDEPOSIT));
    ui->lineEditBankNumberInfo->setText(supDetailsMap.value(HTTPKEY::BANKACCOUNT));
    ui->lineEditYourNameInfo->setText(supDetailsMap.value(HTTPKEY::BANKNAME));
    if(supDetailsMap.value(HTTPKEY::COUNT) != "0")
    {
        ui->commandLinkButtonSupplyMatInfo->setText(GLOBALDEF::SUPPLYMATINFO.arg(supDetailsMap.value(HTTPKEY::COUNT)));
    }
    else
    {
        ui->commandLinkButtonSupplyMatInfo->setText(GLOBALDEF::PLEASESELECT);
    }
}

/*********************  清空信息          *********************/
void SupplierWidget::clearInfo()
{
    ui->comboBoxSupplierType->clear();
    ui->lineEditSupplierName->clear();
    ui->lineEditSupplierNumber->clear();
    ui->lineEditPeople->clear();
    ui->lineEditPhoneNumber->clear();
    ui->lineEditEmail->clear();
    ui->checkBoxInvoice->setChecked(false);
    ui->lineEditTaxRate->setHidden(true);
    ui->labelTaxRate->setHidden(true);
    ui->lineEditPhone->clear();
    ui->lineEditWeiChat->clear();
    ui->lineEditFaxNumber->clear();
    ui->lineEditAddress->clear();
    ui->lineEditBankName->clear();
    ui->lineEditBankNumber->clear();
    ui->lineEditYourName->clear();
    ui->commandLinkButtonSupplyMat->setText(GLOBALDEF::PLEASESELECT);

}

/*********************  添加供应商        *********************/
void SupplierWidget::on_pushButtonAddSupplier_clicked()
{
    this->clearInfo();
    ui->tabWidgetSupplier->addTab(ui->tabAddSupplier, GLOBALDEF::ADDSUPPLIER);
    ui->tabWidgetSupplier->removeTab(ui->tabWidgetSupplier->indexOf(ui->tabSupplierInfo));
    ui->tabWidgetSupplier->setCurrentWidget(ui->tabAddSupplier);
    ui->tabWidgetSupplier->show();

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_SUP_GET_SUP_CAT), PROTOCOL::URL_SUP_GET_SUP_CAT);
}

/*********************  单击列表          *********************/
void SupplierWidget::on_tableWidgetSupplier_clicked(const QModelIndex &index)
{
    if(index.row() >= supMapList.size()) return;
    ui->tabWidgetSupplier->addTab(ui->tabSupplierInfo, GLOBALDEF::SUPPLIERINFO);
    ui->tabWidgetSupplier->removeTab(ui->tabWidgetSupplier->indexOf(ui->tabAddSupplier));
    ui->tabWidgetSupplier->setCurrentWidget(ui->tabSupplierInfo);
    ui->tabWidgetSupplier->show();

    QByteArray byteArray;
    byteArray.append(POSTARG::SUPPLIERID.arg(supMapList.at(index.row()).value(HTTPKEY::SUPPLIERID)));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_SUP_DETAILS), byteArray, PROTOCOL::URL_SUP_DETAILS);
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_SUP_GET_SUP_CAT), PROTOCOL::URL_SUP_GET_SUP_CAT);
}

/*********************  信息使用发票      *********************/
void SupplierWidget::on_checkBoxInvoice_clicked()
{
    if(ui->checkBoxInvoice->isChecked())
    {
        ui->lineEditTaxRate->show();
        ui->labelTaxRate->show();
    }
    else
    {
        ui->lineEditTaxRate->setHidden(true);
        ui->labelTaxRate->setHidden(true);
    }
}

/*********************  信息使用发票      *********************/
void SupplierWidget::on_checkBoxInvoiceInfo_clicked()
{
    if(ui->checkBoxInvoiceInfo->isChecked())
    {
        ui->lineEditTaxRateInfo->show();
        ui->labelTaxRateInfo->show();
    }
    else
    {
        ui->lineEditTaxRateInfo->setHidden(true);
        ui->labelTaxRateInfo->setHidden(true);
    }
}

/*********************  更新信息         *********************/
void SupplierWidget::on_pushButtonSaveInfo_clicked()
{
    if(ui->lineEditSupplierNameInfo->text().isEmpty())
    {
        MESSAGEBOX->showMessageBox(this, MESSAGE::SUPNAMEISNULL);
        return;
    }
    else if(ui->lineEditSupplierNumberInfo->text().isEmpty())
    {
        MESSAGEBOX->showMessageBox(this, MESSAGE::SUPNUMBERISNULL);
        return;
    }
    else if(ui->lineEditPeopleInfo->text().isEmpty())
    {
        MESSAGEBOX->showMessageBox(this, MESSAGE::SUPPEOISNULL);
        return;
    }
    else if(ui->lineEditPhoneNumberInfo->text().isEmpty())
    {
        MESSAGEBOX->showMessageBox(this, MESSAGE::SUPPHONEISNULL);
        return;
    }
    if(ui->checkBoxInvoiceInfo->isChecked())
    {
        if(ui->lineEditTaxRateInfo->text().isEmpty())
        {
            MESSAGEBOX->showMessageBox(this, MESSAGE::SUPTAXISNULL);
            return;
        }
    }

    QByteArray byteArray;

    QString strPost = POSTARG::UPDATESUPPLIER.arg(ui->lineEditSupplierNameInfo->text());

    strPost = strPost.arg(ui->lineEditSupplierNumberInfo->text(), ui->lineEditPeopleInfo->text());

    strPost = strPost.arg(typeMapList.at(ui->comboBoxSupplierTypeInfo->currentIndex()).value(HTTPKEY::SUPPLIERCATEGORYID));

    strPost = strPost.arg(ui->lineEditPhoneNumberInfo->text(), ui->lineEditEmailInfo->text());

    strPost = ui->checkBoxInvoiceInfo->isChecked() ? strPost.arg("1", ui->lineEditTaxRateInfo->text()) : strPost = strPost.arg("0", "");

    strPost = strPost.arg(ui->lineEditPhoneInfo->text(), ui->lineEditWeiChatInfo->text());

    strPost = strPost.arg(ui->lineEditFaxNumberInfo->text(), ui->lineEditAddressInfo->text());

    strPost = strPost.arg(ui->lineEditBankNameInfo->text(), ui->lineEditBankNumberInfo->text());

    strPost = strPost.arg(ui->lineEditYourNameInfo->text(), supDetailsMap.value(HTTPKEY::SUPPLIERID));

    byteArray.append(strPost);

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_SUP_UPDATE_SUP), byteArray, PROTOCOL::URL_SUP_UPDATE_SUP);
}

/*********************  删除供应商       *********************/
void SupplierWidget::on_pushButtonDelInfo_clicked()
{
    QByteArray byteArray;
    byteArray.append(POSTARG::DELETESUP.arg(supDetailsMap.value(HTTPKEY::SUPPLIERID)));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_SUP_DEL_SUP), byteArray, PROTOCOL::URL_SUP_DEL_SUP);
}

/*********************  取消按钮         *********************/
void SupplierWidget::on_pushButtonCancelInfo_clicked()
{
    ui->tabWidgetSupplier->setHidden(true);
}

/*********************  链接按钮         *********************/
void SupplierWidget::on_commandLinkButtonSupplyMatInfo_clicked()
{
    supMaterial->showWidget();

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_SUP_SEL_MATERIAL).arg(supDetailsMap.value(HTTPKEY::SUPPLIERID)), PROTOCOL::URL_SUP_SEL_MATERIAL);
}

/*********************  添加类别         *********************/
void SupplierWidget::on_pushButtonAddType_clicked()
{
    addType->setTitleName(GLOBALDEF::ADDSUPTYPE);
    addType->showWidget();
}

/*********************  删除类别        *********************/
void SupplierWidget::on_pushButtonDelType_clicked()
{
    if(NULL == ui->tableWidgetSupType->currentItem()) return;

    int currentRow = ui->tableWidgetSupType->currentRow();
    if(currentRow < 0 || currentRow >= typeMapList.size()) return;
    QByteArray byteArray;

    byteArray.append(POSTARG::DELETESUPCAT.arg(typeMapList.at(currentRow).value(HTTPKEY::SUPPLIERCATEGORYID)));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_SUP_DEL_SUP_CAT), byteArray, PROTOCOL::URL_SUP_DEL_SUP_CAT);
}

/*********************  添加类别        *********************/
void SupplierWidget::slotReceiveAddType()
{
    QByteArray byteArray;
    byteArray.append(POSTARG::ADDSUPCAT.arg(addType->getTypeName()));
    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_SUP_ADD_SUP_CAT), byteArray, PROTOCOL::URL_SUP_ADD_SUP_CAT);
}

/*********************  保存供应商      *********************/
void SupplierWidget::on_pushButtonSave_clicked()
{
    if(ui->lineEditSupplierName->text().isEmpty())
    {
        MESSAGEBOX->showMessageBox(this, MESSAGE::SUPNAMEISNULL);
        return;
    }
    else if(ui->lineEditSupplierNumber->text().isEmpty())
    {
        MESSAGEBOX->showMessageBox(this, MESSAGE::SUPNUMBERISNULL);
        return;
    }
    else if(ui->lineEditPeople->text().isEmpty())
    {
        MESSAGEBOX->showMessageBox(this, MESSAGE::SUPPEOISNULL);
        return;
    }
    else if(ui->lineEditPhoneNumber->text().isEmpty())
    {
        MESSAGEBOX->showMessageBox(this, MESSAGE::SUPPHONEISNULL);
        return;
    }
    else if(ui->comboBoxSupplierType->currentIndex() < 0 || ui->comboBoxSupplierType->currentIndex() >= typeMapList.size())
    {
        MESSAGEBOX->showMessageBox(this, MESSAGE::TYPECANNOTNULL);
        return;
    }

    if(ui->checkBoxInvoice->isChecked())
    {
        if(ui->lineEditPhoneNumber->text().isEmpty())
        {
            MESSAGEBOX->showMessageBox(this, MESSAGE::SUPTAXISNULL);
            return;
        }
    }

    QByteArray byteArray;

    QString strPost = POSTARG::ADDSUPPLIER.arg(ui->lineEditSupplierName->text());

    strPost = strPost.arg(ui->lineEditSupplierNumber->text(), ui->lineEditPeople->text());

    strPost = strPost.arg(typeMapList.at(ui->comboBoxSupplierType->currentIndex()).value(HTTPKEY::SUPPLIERCATEGORYID));

    strPost = strPost.arg(ui->lineEditPhoneNumber->text(), ui->lineEditEmail->text());

    strPost = ui->checkBoxInvoice->isChecked() ? strPost.arg("1", ui->lineEditTaxRate->text()) : strPost = strPost.arg("0", "");

    strPost = strPost.arg(ui->lineEditPhone->text(), ui->lineEditWeiChat->text());

    strPost = strPost.arg(ui->lineEditFaxNumber->text(), ui->lineEditAddress->text());

    strPost = strPost.arg(ui->lineEditBankName->text(), ui->lineEditBankNumber->text());

    strPost = strPost.arg(ui->lineEditYourName->text());

    byteArray.append(strPost);

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_SUP_ADD_SUP), byteArray, PROTOCOL::URL_SUP_ADD_SUP);

    saveType = BUTTONTYPE;
}

/*********************  选择供应商原料   *********************/
void SupplierWidget::on_commandLinkButtonSupplyMat_clicked()
{
    on_pushButtonSave_clicked();
    saveType = LINKTYPE;
}

/*********************  修改类别        *********************/
void SupplierWidget::on_pushButtonUpdateType_clicked()
{
    if(NULL == ui->tableWidgetSupType->currentItem()) return;
    int currentRow = ui->tableWidgetSupType->currentRow();
    updateType->setTitleName(GLOBALDEF::UPDATESUPTYPE);

    updateType->showWidget(ui->tableWidgetSupType->item(currentRow, 0)->text());
}

/*********************  更改类别        *********************/
void SupplierWidget::slotReceiveUpdateType()
{
    int currentRow = ui->tableWidgetSupType->currentRow();
    if(currentRow >= typeMapList.size()) return;

    QByteArray byteArray;
    byteArray.append(POSTARG::UPDATESUPCAT.arg(typeMapList.at(currentRow).value(HTTPKEY::SUPPLIERCATEGORYID), updateType->getTypeName()));
    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_SUP_UPDATE_SUP_CAT), byteArray, PROTOCOL::URL_SUP_UPDATE_SUP_CAT);
}

/*********************  取消按钮       *********************/
void SupplierWidget::on_pushButtonCancel_clicked()
{
    ui->tabWidgetSupplier->setHidden(true);
}

/*********************  刷新提供的原料  *********************/
void SupplierWidget::slotRefreshCount(int count)
{
    if(count != 0)
    {
        ui->commandLinkButtonSupplyMatInfo->setText(GLOBALDEF::SUPPLYMATINFO.arg(count));
    }
    else
    {
        ui->commandLinkButtonSupplyMatInfo->setText(GLOBALDEF::PLEASESELECT);
    }
}

/*********************  编辑  *********************/
void SupplierWidget::on_lineEditTaxRateInfo_textEdited(const QString &arg1)
{
    if(arg1.size() > TWO)
    {
        ui->lineEditTaxRateInfo->setText(arg1.left(TWO));
    }
}

/*********************  编辑  *********************/
void SupplierWidget::on_lineEditTaxRate_textEdited(const QString &arg1)
{
    if(arg1.size() > TWO)
    {
        ui->lineEditTaxRate->setText(arg1.left(TWO));
    }
}

/*********************  接收邮箱账号  *********************/
void SupplierWidget::receiveEmailText(QString emailText)
{
    QByteArray byteArray;

    byteArray.append(POSTARG::EXTENDEMAIL.arg(emailText));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_SUP_EXTEND), byteArray, PROTOCOL::URL_SUP_EXTEND);
}

/*********************  导出到邮箱  *********************/
void SupplierWidget::on_pushButtonExtend_clicked()
{
    exportEmail->showWidget();
}
