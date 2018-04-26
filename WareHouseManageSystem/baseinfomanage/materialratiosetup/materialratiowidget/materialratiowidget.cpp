#include "materialratiowidget.h"
#include "ui_materialratiowidget.h"
#include "httpclient/httpkey.h"
#include "messagebox/messagedialog.h"

/*********************  构造函数        *********************/
MaterialRatioWidget::MaterialRatioWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MaterialRatioWidget)
{
    ui->setupUi(this);
    this->initControl();
}

/*********************  析构函数        *********************/
MaterialRatioWidget::~MaterialRatioWidget()
{
    delete ui;
}

/*********************  显示窗口        *********************/
void MaterialRatioWidget::showWidget()
{
    this->show();
    ui->tabWidgetMaterialRatio->setHidden(true);
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_BOM_FOOD_LIST), PROTOCOL::URL_BOM_FOOD_LIST);
}

/*********************  初始化控件       *********************/
void MaterialRatioWidget::initControl()
{
    //设置为不可编辑
    ui->treeWidgetData->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //设置表头点击禁止塌陷
    ui->treeWidgetData->header()->setHighlightSections(false);

    //设置双击不收缩
    ui->treeWidgetData->setExpandsOnDoubleClick(false);

    //表头隐藏
    ui->treeWidgetData->header()->setHidden(true);

    ui->listWidgetWhse->setFocusPolicy(Qt::NoFocus);

    materialInfo = new MaterialInfo(MaterialInfo::EDITTYPE, this);
    selectMaterial = new SelectMaterial(this);

    //设置只能输入数字
    QRegExp regExp("(([1-9][0-9]*)\\.([0-9]{2}))|[0]\\.([0-9]{2})");
    QValidator *validatorTop = new QRegExpValidator(regExp,  ui->lineEditPrice);
    ui->lineEditPrice->setValidator(validatorTop);

    //根据分辨率适配
    QDesktopWidget *desktop = QApplication::desktop();

    if(desktop->height() >= GLOBALDEF::DESKTOPHEIGHT)
    {
        this->setStyleSheet(GLOBALDEF::THISSTYLE);
    }
    else
    {
        this->setStyleSheet(GLOBALDEF::SMALLSTYLE);
    }
}

/*********************  解析json        *********************/
void MaterialRatioWidget::readJson(QNetworkReply *reply, int type)
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

                if(type == PROTOCOL::URL_BOM_FOOD_LIST)
                {
                    if(ISERROR(codeValue))
                    {
                        ui->treeWidgetData->clear();
                        mapListTree.clear();
                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, mapListTree);
                    this->setTreeData();
                }
                else if(type == PROTOCOL::URL_BOM_FOOD_GETID)
                {
                    if(ISERROR(codeValue))
                    {
                        ui->tabWidgetMaterialRatio->setHidden(true);
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;
                        else if(codeValue == THREE) errorMsg = MESSAGE::FIRSTSETWAR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    HTTPCLIENT->readJsonMap(jsonObject, HTTPKEY::MSG, matMap);
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::MATERIALLIST,     mapListBomMaterial);
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::PRODUCTWAREHOUSE, mapListProductWare);

                    this->setControlData();

                    selectMaterial->setMapFood(matMap);

                    ui->tabWidgetMaterialRatio->show();
                }
                else if(type == PROTOCOL::URL_BOM_MAT_DEL)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::DELERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::DELSUCCESS, true);
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_BOM_FOOD_GETID).arg(treeProData.foodId, treeProData.pId, treeProData.foodName), PROTOCOL::URL_BOM_FOOD_GETID);
                }
                else if(type == PROTOCOL::URL_BOM_MAT_UPDATE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::EDITERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::EDITSUCCESS, true);
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_BOM_FOOD_GETID).arg(treeProData.foodId, treeProData.pId, treeProData.foodName), PROTOCOL::URL_BOM_FOOD_GETID);
                }
                else if(type == PROTOCOL::URL_BOM_MAT_ADD)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ADDERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;
                        else if(codeValue == THREE) errorMsg = MESSAGE::MATEXIST;

                        MESSAGEBOX->showMessageBox(selectMaterial, errorMsg);
                        return;
                    }

                    selectMaterial->close();

                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_BOM_FOOD_GETID).arg(treeProData.foodId, treeProData.pId, treeProData.foodName), PROTOCOL::URL_BOM_FOOD_GETID);
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::ADDSUCCESS, true);
                }
                else if(type == PROTOCOL::URL_BOM_MAT_NEW || type == PROTOCOL::URL_BOM_MAT_OLD)
                {
                    MapList mapList;
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::UNITLIST, mapList);

                    Map mapItem;
                    HTTPCLIENT->readJsonMap(jsonObject, HTTPKEY::MSG, mapItem);

                    MapList mapItemList;
                    if(type == PROTOCOL::URL_BOM_MAT_NEW)
                    {
                        if(ISERROR(codeValue)) return;

                        HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::PRODUCTWAREHOUSE, mapItemList);

                        selectMaterial->getMaterialInfo()->setUnitMapList(mapList);
                        selectMaterial->getMaterialInfo()->setProductMapList(mapItemList);
                        selectMaterial->getMaterialInfo()->setMapItem(mapItem);
                        selectMaterial->getMaterialInfo()->setUpData();

                        selectMaterial->getMaterialInfo()->showWidget();
                    }
                    else
                    {
                        if(ISERROR(codeValue))
                        {
                            if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                            else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                            MESSAGEBOX->showMessageBox(this, errorMsg);
                            return;
                        }

                        HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::WAREHOUSE, mapItemList);
                        materialInfo->setBarCode(mapItem.value(HTTPKEY::BARCODE));
                        materialInfo->setUnitMapList(mapList);
                        materialInfo->setProductMapList(mapItemList);
                        materialInfo->setMapItem(mapItem);
                        materialInfo->setUpData();
                    }
                }
                else if(type == PROTOCOL::URL_BOM_SAVE_UPDATE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::EDITERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;
                        else if(codeValue == THREE) errorMsg = MESSAGE::PRICENOTZERO;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    ui->tabWidgetMaterialRatio->setHidden(true);
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::EDITSUCCESS, true);
                }
                else if(type == PROTOCOL::URL_BOM_MAT_LIST)
                {
                    if(ISERROR(codeValue)) return;

                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, mapListMat);

                    selectMaterial->setMapListMaterial(mapListMat);

                    selectMaterial->showWidget();
                }
            }
        }
        reply->close();
    }
}

/*********************  设置数据         *********************/
void MaterialRatioWidget::setTreeData()
{
    ui->treeWidgetData->clear();

    for(int i = 0; i < mapListTree.size(); i ++)
    {
        if(mapListTree.at(i).value(HTTPKEY::LEVEL) == "1")
        {
            QTreeWidgetItem* parentItem = TREEDATA(ui->treeWidgetData);

            parentItem->setText(0, mapListTree.at(i).value(HTTPKEY::FOODNAME));

            for(int j = 0; j < mapListTree.size(); j ++)
            {
                if(mapListTree.at(j).value(HTTPKEY::PID) == mapListTree.at(i).value(HTTPKEY::FOODID))
                {
                    QTreeWidgetItem* childItem = TREEITEM();
                    parentItem->addChild(childItem);

                    childItem->setText(0, mapListTree.at(j).value(HTTPKEY::FOODNAME));

                    TreeData treeData;
                    treeData.foodId   = mapListTree.at(j).value(HTTPKEY::FOODID);
                    treeData.pId      = mapListTree.at(j).value(HTTPKEY::PID);
                    treeData.foodName = mapListTree.at(j).value(HTTPKEY::FOODNAME);

                    if(NULL != childItem) mapItemList[childItem] = treeData;
                }
            }
        }
    }
    ui->treeWidgetData->expandAll();
}

/*********************  设置控件数据      *********************/
void MaterialRatioWidget::setControlData()
{
    if(mapListProductWare.size() == ONE)
    {
        ui->listWidgetWhse->setHidden(true);
        ui->lineEditWareHouse->show();
        ui->lineEditWareHouse->setText(mapListProductWare.at(0).value(HTTPKEY::WAREHOUSENAME));
    }
    else
    {
        lineEditList.clear();
        ui->listWidgetWhse->clear();
        for(int i = 0; i < mapListProductWare.size(); i ++)
        {
            QString whseName = mapListProductWare.at(i).value(HTTPKEY::WAREHOUSENAME);
            QString number = mapListProductWare.at(i).value(HTTPKEY::RATIO);

            QWidget *widget =  createWidget(whseName, number);
            QListWidgetItem *lisItem = new QListWidgetItem(ui->listWidgetWhse);

            lisItem->setSizeHint(QSize(0, 70));
            lisItem->setFlags(lisItem->flags() & ~Qt::ItemIsSelectable);

            ui->listWidgetWhse->addItem(lisItem);

            ui->listWidgetWhse->setItemWidget(lisItem, widget);
        }

        ui->lineEditWareHouse->setHidden(true);
        ui->listWidgetWhse->show();
    }

    if(matMap.value(HTTPKEY::COST) == "0")
    {
        ui->checkBox->setChecked(true);
    }
    else
    {
        ui->checkBox->setChecked(false);
    }

    ui->lineEditNameInfo->setText(matMap.value(HTTPKEY::FOODNAME));
    ui->lineEditPrice->setText(matMap.value(HTTPKEY::COSTPRICE));

    ui->listWidgetData->clear();

    for(int i = 0; i < mapListBomMaterial.size(); i ++)
    {
        QString matName = mapListBomMaterial.at(i).value(HTTPKEY::MATERIALNAME);
        QString whseName;
        for(int j = 0; j < mapListProductWare.size(); j ++)
        {
            if(mapListProductWare.at(j).value(HTTPKEY::WAREHOUSEID) == mapListBomMaterial.at(i).value(HTTPKEY::WAREHOUSEID))
            {
                whseName = mapListProductWare.at(j).value(HTTPKEY::WAREHOUSENAME);
            }
        }

        QString number =  mapListBomMaterial.at(i).value(HTTPKEY::EXPENDNUMBER) + mapListBomMaterial.at(i).value(HTTPKEY::UNITNAME);

        QWidget *widget =  createWidget(matName, whseName, number);
        QListWidgetItem *lisItem = new QListWidgetItem(ui->listWidgetData);

        lisItem->setSizeHint(QSize(0, 70));

        ui->listWidgetData->addItem(lisItem);

        ui->listWidgetData->setItemWidget(lisItem, widget);
    }
}

/*********************  单击列表         *********************/
void MaterialRatioWidget::on_treeWidgetData_clicked(const QModelIndex &index)
{
    auto iter = mapItemList.find(ui->treeWidgetData->currentItem());

    if(iter != mapItemList.end())
    {
        treeProData.foodId   = iter.value().foodId;
        treeProData.pId      = iter.value().pId;
        treeProData.foodName = iter.value().foodName;

        selectMaterial->getMaterialInfo()->setFoodId(treeProData.foodId);
        HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_BOM_FOOD_GETID).arg(treeProData.foodId, treeProData.pId, treeProData.foodName), PROTOCOL::URL_BOM_FOOD_GETID);
    }
}

/*********************  保存信息         *********************/
void MaterialRatioWidget::on_pushButtonSaveInfo_clicked()
{
    QByteArray byteArray;

    QString strPost = POSTARG::FOODADDID.arg(matMap.value(HTTPKEY::BOMID));

    QString cost = ui->checkBox->isChecked() ? "0" : "1";

    strPost = strPost.arg(cost, ui->lineEditPrice->text());


    List listData;
    for(int i = 0; i < mapListProductWare.size(); i ++)
    {
        listData.append(mapListProductWare.at(i).value(HTTPKEY::CLASSIFICATIONID));
    }

    List listRatio;
    int totalCount = 0;
    for(int i = 0; i < lineEditList.size(); i ++)
    {
        listRatio.append(lineEditList.at(i)->text());
        totalCount += lineEditList.at(i)->text().toInt();
    }

    strPost = strPost.arg(makeJson(listData, listRatio));

    if(mapListProductWare.size() > ONE)
    {
        if(totalCount != 100)
        {
            MESSAGEBOX->showMessageBox(this, MESSAGE::TOTOLERROR);
            return;
        }
    }


    byteArray.append(strPost);

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_BOM_SAVE_UPDATE), byteArray, PROTOCOL::URL_BOM_SAVE_UPDATE);
}

/*********************  取消             *********************/
void MaterialRatioWidget::on_pushButtonCancelInfo_clicked()
{
    ui->tabWidgetMaterialRatio->setHidden(true);
}

/*********************  添加新原料        *********************/
void MaterialRatioWidget::on_pushButtonAddNewMat_clicked()
{
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_BOM_MAT_LIST), PROTOCOL::URL_BOM_MAT_LIST);
}

/*********************  组合JSON         ********************/
QString MaterialRatioWidget::makeJson(List dataList, List ratioList)
{
    QJsonArray  jsonArray;

    for(int i = 0; i < dataList.size(); i ++)
    {
        QJsonObject jsonData;

        jsonData.insert(HTTPKEY::CLASSIFICATIONID, dataList.at(i));

        if(i >= ratioList.size()) continue;
        jsonData.insert(HTTPKEY::RATIO, ratioList.at(i));

        jsonArray.insert(i, jsonData);
    }

    QJsonDocument document;
    document.setArray(jsonArray);

    return document.toJson();
}

/*********************  创建信息面板       *********************/
QWidget *MaterialRatioWidget::createWidget(QString matName, QString whseName, QString number)
{
    QWidget *widget = new QWidget(this);

    QHBoxLayout *hBoxLayout = new QHBoxLayout(widget);
    QVBoxLayout *vBoxLayout = new QVBoxLayout();
    QLabel *labelMatName = new QLabel(this);
    QLabel *labelWhseName = new QLabel(this);
    QLabel *labelNumber = new QLabel(this);

    labelMatName->setText(matName);
    labelWhseName->setText(whseName);
    labelNumber->setText(number);

    labelMatName->setFont(QFont(GLOBALDEF::FONTNAME,  ELEVEN, QFont::Bold));
    labelWhseName->setFont(QFont(GLOBALDEF::FONTNAME, ELEVEN));
    labelNumber->setFont(QFont(GLOBALDEF::FONTNAME,   ELEVEN));

    vBoxLayout->addWidget(labelWhseName);
    vBoxLayout->addWidget(labelNumber);

    hBoxLayout->addWidget(labelMatName);
    hBoxLayout->addLayout(vBoxLayout);

    return widget;
}

/*********************  创建信息面板       *********************/
QWidget *MaterialRatioWidget::createWidget(QString whseName, QString number)
{
    QWidget *widget = new QWidget(this);

    QHBoxLayout *hBoxLayout = new QHBoxLayout(widget);
    QVBoxLayout *vBoxLayout = new QVBoxLayout();
    QLabel *labelWhseName = new QLabel(this);

    QLabel *labelName = new QLabel(this);
    QLineEdit *lineEditNumber = new QLineEdit(this);

    labelName->setText(tr("百分比（可修改）"));
    labelWhseName->setText(whseName);
    lineEditNumber->setText(number);

    labelWhseName->setFont(QFont(GLOBALDEF::FONTNAME,  ELEVEN, QFont::Bold));
    lineEditNumber->setFont(QFont(GLOBALDEF::FONTNAME, ELEVEN, QFont::Bold));
    labelName->setFont(QFont(GLOBALDEF::FONTNAME,   ELEVEN));

    lineEditNumber->setStyleSheet("background-color:transparent");
    lineEditNumber->setAlignment( Qt::AlignCenter | Qt::AlignHCenter);

    //设置只能输入数字
    QRegExp regExp("[0-9]+$");
    QValidator *validatorTop = new QRegExpValidator(regExp, lineEditNumber);
    lineEditNumber->setValidator(validatorTop);

    lineEditList.append(lineEditNumber);
    labelName->setMaximumWidth(200);
    lineEditNumber->setMaximumWidth(200);

    vBoxLayout->addWidget(labelName);
    vBoxLayout->addWidget(lineEditNumber);

    hBoxLayout->addWidget(labelWhseName);
    hBoxLayout->addLayout(vBoxLayout);

    return widget;
}

/*********************  双击列表          *********************/
void MaterialRatioWidget::on_listWidgetData_doubleClicked(const QModelIndex &index)
{
    if(index.row() >= mapListBomMaterial.size()) return;

    QString bomMatId = mapListBomMaterial.at(index.row()).value(HTTPKEY::BOMMATERIALID);
    QString foodId   = matMap.value(HTTPKEY::FOODID);
    QString catId    = matMap.value(HTTPKEY::CATEGORYID);

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_BOM_MAT_OLD).arg(bomMatId, foodId, catId), PROTOCOL::URL_BOM_MAT_OLD);

    materialInfo->setMatName(mapListBomMaterial.at(index.row()).value(HTTPKEY::MATERIALNAME));
    materialInfo->setExpendNumber(mapListBomMaterial.at(index.row()).value(HTTPKEY::EXPENDNUMBER));

    materialInfo->showWidget();
}

/*********************  点击选中          *********************/
void MaterialRatioWidget::on_checkBox_clicked()
{
    if(ui->checkBox->isChecked())
    {
        ui->lineEditPrice->setEnabled(false);
        ui->lineEditPrice->setText("0");
    }
    else
    {
        ui->lineEditPrice->setEnabled(true);
        ui->lineEditPrice->setText(matMap.value(HTTPKEY::COSTPRICE));
    }
}
