#include "warehousewidget.h"
#include "ui_warehousewidget.h"
#include "messagebox/messagedialog.h"
#include "httpclient/httpkey.h"
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>

/*********************  构造函数       *********************/
WareHouseWidget::WareHouseWidget(QWidget *parent) :
    QWidget(parent),ui(new Ui::WareHouseWidget)
  ,titleBar(NULL),addCommodity(NULL)
{
    ui->setupUi(this);

    this->initControl();
}

/*********************  析构函数       *********************/
WareHouseWidget::~WareHouseWidget()
{
    delete ui;
}

/*********************  初始化控件      *********************/
void WareHouseWidget::initControl()
{
    SETTABLEWIDGET(ui->tableWidgetWareHouse);

    ui->listWidgetMaterialInfo->clear();
    ui->listWidgetExtenInfo->clear();

    addCommodity = new AddCommodity(this);

    //初始化信号与槽
    connect(addCommodity, SIGNAL(sendAdd()), this, SLOT(slotReceiveAdd()));
    connect(addCommodity, SIGNAL(sendType()), this, SLOT(slotReceiveType()));


    ui->pushButtonAddSpType->setHidden(true);
    ui->listWidgetAddMaterial->setHidden(true);
    ui->listWidgetMaterialInfo->setHidden(true);
    ui->pushButtonAddSpTypeInfo->setHidden(true);
    ui->labelAddType->setHidden(true);
    ui->labelTypeInfo->setHidden(true);

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

    flowLayout->addWidget(ui->pushButtonAddWareHouse);
    flowLayout->addWidget(ui->labelSize);

    ui->widgetControl->setLayout(flowLayout);
}

/*********************  显示窗口       *********************/
void WareHouseWidget::showWidget()
{
    this->show();
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_WARHOS_LIST), PROTOCOL::URL_WARHOS_LIST);
    ui->tabWidgetWareHouse->hide();
}

/*********************  解析json       *********************/
void WareHouseWidget::readJson(QNetworkReply *reply, int type)
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

                if(type == PROTOCOL::URL_WARHOS_LIST)
                {
                    if(ISERROR(codeValue))
                    {
                        ui->tableWidgetWareHouse->clearContents();
                        ui->tableWidgetWareHouse->setRowCount(0);
                        mapWarHosList.clear();
                        ui->labelSize->setText(GLOBALDEF::TOTALONUMBER.arg(0));

                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, mapWarHosList);
                    this->setTableWarHosData();
                }
                else if(type == PROTOCOL::URL_WARHOS_DETAILS)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    ui->lineEditNameInfo->setText(jsonNextObj.value(HTTPKEY::NAME).toString());
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::FOODCATEGORY, mapFoodCategoryList);
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::FOOD, mapFoodList);

                    selectTableMap.clear();
                    for(int i = 0; i < mapFoodCategoryList.size(); i ++)
                    {
                        selectTableMap[mapFoodCategoryList.at(i).value(HTTPKEY::FOODCATEGORYID)] = mapFoodCategoryList.at(i).value(HTTPKEY::FOODCATEGORYNAME);
                    }
                    addCommodity->setTableItemSelectMap(selectTableMap);

                    selectTreeMap.clear();
                    for(int i = 0; i < mapFoodList.size(); i ++)
                    {
                        selectTreeMap[mapFoodList.at(i).value(HTTPKEY::FOODID)] = mapFoodList.at(i).value(HTTPKEY::FOODNAME);
                    }

                    addCommodity->setTreeItemSelectMap(selectTreeMap);

                    this->setListFoodData();
                }
                else if(type == PROTOCOL::URL_WARHOS_GOODS_TYPE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO) errorMsg = MESSAGE::ERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    MapList mapList;
                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, mapList);

                    addCommodity->setMapFoodCategoryList(mapList);

                    addCommodity->showWidget(AddCommodity::ADDCOMMODITYTYPE);
                }
                else if(type == PROTOCOL::URL_WARHOS_GOODS_LIST)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO) errorMsg = MESSAGE::ERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    MapList mapList;
                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, mapList);

                    addCommodity->setMapFoodList(mapList);

                    addCommodity->showWidget(AddCommodity::ADDCOMMODITY);
                }
                else if(type == PROTOCOL::URL_WARHOS_ADD)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ADDERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;
                        else if(codeValue == THREE) errorMsg = MESSAGE::WARNAMEEXIST;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::ADDSUCCESS, true);
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_WARHOS_LIST), PROTOCOL::URL_WARHOS_LIST);
                    ui->tabWidgetWareHouse->setHidden(true);
                }
                else if(type == PROTOCOL::URL_WARHOS_EDIT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::EDITERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    ui->tabWidgetWareHouse->setHidden(true);
                    QByteArray byteArray;
                    byteArray.append(POSTARG::WARHOSID.arg(wareHouseId));
                    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_WARHOS_DETAILS), byteArray, PROTOCOL::URL_WARHOS_DETAILS);

                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::EDITSUCCESS, true);
                }
                else if(type == PROTOCOL::URL_WARHOS_DEL)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::DELERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;
                        else if(codeValue == THREE) errorMsg = MESSAGE::FIRSTREMOVEWARNAT;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::DELSUCCESS, true);
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_WARHOS_LIST), PROTOCOL::URL_WARHOS_LIST);
                    ui->tabWidgetWareHouse->removeTab(ui->tabWidgetWareHouse->indexOf(ui->tabWareHouseInfo));
                    ui->tabWidgetWareHouse->setHidden(true);
                }
                else if(type == PROTOCOL::URL_WARHOS_SEARCH)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::SELECTERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(addCommodity, errorMsg);
                        return;
                    }

                    MapList mapList;
                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, mapList);
                    addCommodity->setFoodList(mapList);
                }
            }
        }
        reply->close();
    }
}

/*********************  添加表格数据    *********************/
void WareHouseWidget::setTableWarHosData()
{
    ui->labelSize->setText(GLOBALDEF::TOTALONUMBER.arg(mapWarHosList.size()));
    ui->tableWidgetWareHouse->setRowCount(mapWarHosList.size());

    for(int i = 0; i < mapWarHosList.size(); i ++)
    {
        ui->tableWidgetWareHouse->setItem(i, 0, DATA(mapWarHosList.at(i).value(HTTPKEY::NAME)));
        SETTABLECENTER(ui->tableWidgetWareHouse->item(i, 0));
    }

    ui->tableWidgetWareHouse->scrollToBottom();
    ui->tableWidgetWareHouse->selectRow(ui->tableWidgetWareHouse->rowCount() - 1);
}

/*********************  添加列表数据    *********************/
void WareHouseWidget::setListFoodData()
{
    ui->listWidgetMaterialInfo->clear();
    ui->listWidgetExtenInfo->clear();

    for(int i = 0; i < mapFoodCategoryList.size(); i ++)
    {
        ui->listWidgetMaterialInfo->addItem(mapFoodCategoryList.at(i).value(HTTPKEY::FOODCATEGORYNAME));
    }

    for(int i = 0; i < mapFoodList.size(); i ++)
    {
        ui->listWidgetExtenInfo->addItem(mapFoodList.at(i).value(HTTPKEY::FOODNAME));
    }
}

/*********************  双击列表        *********************/
void WareHouseWidget::on_tableWidgetWareHouse_clicked(const QModelIndex &index)
{
    if(NULL == ui->tableWidgetWareHouse->currentItem()) return;
    if(index.row() >= mapWarHosList.size()) return;
    wareHouseId = mapWarHosList.at(index.row()).value(HTTPKEY::WAREHOUSEID);

    QByteArray byteArray;
    byteArray.append(POSTARG::WARHOSID.arg(wareHouseId));
    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_WARHOS_DETAILS), byteArray, PROTOCOL::URL_WARHOS_DETAILS);

    ui->tabWidgetWareHouse->addTab(ui->tabWareHouseInfo, GLOBALDEF::WARHOSINFO);
    ui->tabWidgetWareHouse->removeTab(ui->tabWidgetWareHouse->indexOf(ui->tabAddWareHouse));
    ui->tabWidgetWareHouse->setCurrentWidget(ui->tabWareHouseInfo);
    ui->tabWidgetWareHouse->show();
}

/*********************  添加商品分类     *********************/
void WareHouseWidget::on_pushButtonAddSpTypeInfo_clicked()
{
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_WARHOS_GOODS_TYPE), PROTOCOL::URL_WARHOS_GOODS_TYPE);
}

/*********************  添加商品        *********************/
void WareHouseWidget::on_pushButtonAddSpInfo_clicked()
{
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_WARHOS_GOODS_LIST), PROTOCOL::URL_WARHOS_GOODS_LIST);
}

/*********************  添加商品分类     *********************/
void WareHouseWidget::on_pushButtonAddSpType_clicked()
{
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_WARHOS_GOODS_TYPE), PROTOCOL::URL_WARHOS_GOODS_TYPE);
}

/*********************  添加商品        *********************/
void WareHouseWidget::on_pushButtonAddSp_clicked()
{
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_WARHOS_GOODS_LIST), PROTOCOL::URL_WARHOS_GOODS_LIST);
}

/*********************  接收添加分类     *********************/
void WareHouseWidget::slotReceiveType()
{
    if(ui->tabWidgetWareHouse->currentWidget() == ui->tabAddWareHouse)
    {
        ui->listWidgetAddMaterial->clear();
        const QMap<QString, QString>mapData = addCommodity->getTableItemSelectMap();

        for(auto iter = mapData.begin(); iter != mapData.end(); iter ++)
        {
            ui->listWidgetAddMaterial->addItem(mapData[iter.key()]);
        }
    }
    else
    {
        ui->listWidgetMaterialInfo->clear();
        const QMap<QString, QString>mapData = addCommodity->getTableItemSelectMap();

        for(auto iter = mapData.begin(); iter != mapData.end(); iter ++)
        {
            ui->listWidgetMaterialInfo->addItem(mapData[iter.key()]);
        }
    }
}

/*********************  接收添加商品     *********************/
void WareHouseWidget::slotReceiveAdd()
{
    if(ui->tabWidgetWareHouse->currentWidget() == ui->tabAddWareHouse)
    {
        ui->listWidgetAddExten->clear();

        const QMap<QString, QString>mapData = addCommodity->getTreeItemSelectMap();

        for(auto iter = mapData.begin(); iter != mapData.end(); iter ++)
        {
            ui->listWidgetAddExten->addItem(mapData[iter.key()]);
        }
    }
    else
    {
        ui->listWidgetExtenInfo->clear();
        const QMap<QString, QString>mapData = addCommodity->getTreeItemSelectMap();
        for(auto iter = mapData.begin(); iter != mapData.end(); iter ++)
        {
            ui->listWidgetExtenInfo->addItem(mapData[iter.key()]);
        }
    }
}

/*********************  添加仓库        *********************/
void WareHouseWidget::on_pushButtonAddWareHouse_clicked()
{
    ui->tabWidgetWareHouse->addTab(ui->tabAddWareHouse, GLOBALDEF::ADDWARHOS);
    ui->tabWidgetWareHouse->removeTab(ui->tabWidgetWareHouse->indexOf(ui->tabWareHouseInfo));
    ui->tabWidgetWareHouse->setCurrentWidget(ui->tabAddWareHouse);
    ui->tabWidgetWareHouse->show();

    ui->lineEditName->clear();
    ui->listWidgetAddExten->clear();
    ui->listWidgetAddMaterial->clear();
    addCommodity->clearInfo();
}

/*********************  仓库信息保存     *********************/
void WareHouseWidget::on_pushButtonSave_clicked()
{
    if(ui->lineEditName->text().isEmpty())
    {
        MESSAGEBOX->showMessageBox(this, GLOBALDEF::WARHOSISNOTNULL);
        return;
    }

    QByteArray byteArray;

    byteArray.append(POSTARG::ADDWAREHOUSE.arg(ui->lineEditName->text(),
                                               makeJson(addCommodity->getTableItemSelectMap()),
                                               makeJson(addCommodity->getTreeItemSelectMap())));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_WARHOS_ADD), byteArray, PROTOCOL::URL_WARHOS_ADD);
}

/*********************  组合json        *********************/
QString WareHouseWidget::makeJson(Map mapData)
{
    QJsonObject jsonTotal;
    QJsonObject jsonData;

    int count = 0;
    for(auto iter = mapData.begin(); iter != mapData.end(); iter ++)
    {
        jsonData.insert(QString::number(count), iter.key());

        count ++;
    }

    jsonTotal.insert("listId", jsonData);

    QJsonDocument document;
    document.setObject(jsonTotal);

    return document.toJson();
}

/*********************  仓库信息更新     *********************/
void WareHouseWidget::on_pushButtonSaveInfo_clicked()
{
    if(ui->lineEditNameInfo->text().isEmpty())
    {
        MESSAGEBOX->showMessageBox(this, GLOBALDEF::WARHOSISNOTNULL);
        return;
    }

    QByteArray byteArray;

    QString strPost = POSTARG::UPDATEWAREHOUSE.arg(wareHouseId, ui->lineEditNameInfo->text());

    QMap<QString, QString>mapDataAdd = addCommodity->getTableItemSelectMap();

    for(auto iter = mapDataAdd.begin(); iter != mapDataAdd.end(); iter ++)
    {
        for(auto iterTable = selectTableMap.begin(); iterTable != selectTableMap.end(); iterTable ++)
        {
            if(iter.key() == iterTable.key())
            {
                mapDataAdd.erase(iter);
                selectTableMap.erase(iterTable);
            }
        }
    }

    QMap<QString, QString>mapTreeAdd = addCommodity->getTreeItemSelectMap();

    for(auto iter = mapTreeAdd.begin(); iter != mapTreeAdd.end(); iter ++)
    {
        for(auto iterTree = selectTreeMap.begin(); iterTree != selectTreeMap.end(); iterTree ++)
        {
            if(iter.key() == iterTree.key())
            {
                selectTreeMap.erase(iterTree);
                mapTreeAdd.erase(iter);
            }
        }
    }

    strPost = strPost.arg(makeJson(mapDataAdd), makeJson(mapTreeAdd), makeJson(selectTableMap), makeJson(selectTreeMap));

    byteArray.append(strPost);

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_WARHOS_EDIT), byteArray, PROTOCOL::URL_WARHOS_EDIT);
}

/*********************  删除仓库        *********************/
void WareHouseWidget::on_pushButtonDelWareHouse_clicked()
{
    if(NULL == ui->tableWidgetWareHouse->currentItem()) return;
    QByteArray byteArray;
    byteArray.append(POSTARG::WARHOSID.arg(wareHouseId));
    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_WARHOS_DEL), byteArray, PROTOCOL::URL_WARHOS_DEL);
}

/*********************   取消事件        *********************/
void WareHouseWidget::on_pushButtonCancel_clicked()
{
    ui->tabWidgetWareHouse->removeTab(ui->tabWidgetWareHouse->indexOf(ui->tabAddWareHouse));
    ui->tabWidgetWareHouse->setHidden(true);
}

/*********************  取消事件        *********************/
void WareHouseWidget::on_pushButtonCancelInfo_clicked()
{
    ui->tabWidgetWareHouse->removeTab(ui->tabWidgetWareHouse->indexOf(ui->tabWareHouseInfo));
    ui->tabWidgetWareHouse->setHidden(true);
}
