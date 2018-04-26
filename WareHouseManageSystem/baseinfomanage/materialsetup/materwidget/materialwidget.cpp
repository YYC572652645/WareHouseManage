#include "materialwidget.h"
#include "ui_materialwidget.h"
#include "global/globaldef.h"
#include "httpclient/httpkey.h"
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include <QNetworkCookieJar>
#include <QNetworkCookie>
#include <QLineEdit>
#include <QComboBox>
#include <QListWidget>
#include <QFileDialog>
#include <QInputDialog>
#include <QPropertyAnimation>
#include "messagebox/messagedialog.h"

/************************    构造函数          *********************/
MaterialWidget::MaterialWidget(QWidget *parent) :
    QWidget(parent),ui(new Ui::MaterialWidget)
  ,addMaterial(NULL),materialType(NULL)
  ,addUnit(NULL), exchangeTypeWidget(NULL)
  ,widgetFlage(false), selectType(true)
{
    ui->setupUi(this);

    this->initControl();
}

/************************    析构函数          *********************/
MaterialWidget::~MaterialWidget()
{
    delete ui;
}

/************************    初始化控件         *********************/
void MaterialWidget::initControl()
{
    SETTABLEWIDGET(ui->tableWidget);
    SETTABLEWIDGET(ui->tableWidgetUnitLibrary);

    //设置窗口类型
    ui->tabAddMaterial->setType(GLOBALDEF::ADDMATERIAL);
    ui->tabMaterialInfo->setType(GLOBALDEF::LOOKMATERIAL);

    //设置多行选中
    ui->tableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);

    SETTREEWIDGET(ui->treeWidgetCateGory, true);

    //设置双击不收缩
    ui->treeWidgetCateGory->setExpandsOnDoubleClick(false);

    addMaterial = new AddMaterial(this);
    materialType = new MaterialType(this);
    addUnit = new AddUnit(this);
    exchangeTypeWidget = new ExchangeType(this);
    exportEmail = new ExportEmail(this);

    //连接信号与槽
    connect(exportEmail,        SIGNAL(sendEmail(QString)),    this, SLOT(receiveEmailText(QString)));
    connect(exchangeTypeWidget, SIGNAL(sendExchangeType(int)), this, SLOT(slotReceiveExchangeType(int)));
    connect(addMaterial,        SIGNAL(sendOk()),              this, SLOT(receiveAddMaterial()));
    connect(addUnit,            SIGNAL(sendOk()),              this, SLOT(receiveAddUnit()));

    //去除添加原料和原料详情
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->tabAddMaterial));
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->tabMaterialInfo));


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

    flowLayout->addWidget(ui->pushButtonChangeType);
    flowLayout->addWidget(ui->pushButtonDeleteMat);
    flowLayout->addWidget(ui->pushButtonExtend);
    flowLayout->addWidget(ui->pushButtonAddMaterial);
    flowLayout->addWidget(ui->labelSize);

    ui->widgetControl->setLayout(flowLayout);
}

/************************   显示窗口            *********************/
void MaterialWidget::showWidget()
{
    this->show();
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_MAT_LIST), PROTOCOL::URL_MAT_LIST);
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_UNIT_LIST), PROTOCOL::URL_UNIT_LIST);
    ui->tabWidget->setHidden(true);
}

/************************   设置主表格数据       *********************/
void MaterialWidget::setTableData()
{
    ui->tableWidget->setRowCount(mapDataList.size());
    ui->labelSize->setText(GLOBALDEF::TOTALONUMBER.arg(mapDataList.size()));

    for(int i = 0; i < mapDataList.size(); i ++)
    {
        ui->tableWidget->setItem(i, ZERO, DATA(mapDataList.at(i).value(HTTPKEY::MATERIALID)));  //原料ID
        ui->tableWidget->setItem(i, ONE, DATA(mapDataList.at(i).value(HTTPKEY::NAME)));        //原料名称
        ui->tableWidget->setItem(i, TWO, DATA(mapDataList.at(i).value(HTTPKEY::BARCODE)));     //原料条码

        SETTABLECENTER(ui->tableWidget->item(i, ZERO));
        SETTABLECENTER(ui->tableWidget->item(i, ONE));
        SETTABLECENTER(ui->tableWidget->item(i, TWO));
    }

    if(selectType)
    {
        ui->tableWidget->scrollToBottom();
        ui->tableWidget->selectRow(ui->tableWidget->rowCount() - 1);
    }
}

/************************   设置单元表格数据     *********************/
void MaterialWidget::setTableUnitData()
{
    ui->tableWidgetUnitLibrary->setRowCount(unitMapList.size());

    for(int i = 0; i < unitMapList.size(); i ++)
    {
        ui->tableWidgetUnitLibrary->setItem(i, 0, DATA(unitMapList.at(i).value(HTTPKEY::NAME)));

        SETTABLECENTER(ui->tableWidgetUnitLibrary->item(i, 0));
    }
}

/************************   设置表格类型数据     *********************/
void MaterialWidget::setTableTypeData()
{
    ui->treeWidgetCateGory->clear();

    for(int i = 0; i < cateGoryTypeMapList.size(); i ++)
    {
        if(cateGoryTypeMapList.at(i).value(HTTPKEY::PID) == "0")
        {
            QTreeWidgetItem* parentItem = TREEDATA(ui->treeWidgetCateGory);

            parentItem->setText(0, cateGoryTypeMapList.at(i).value(HTTPKEY::NAME));

            for(int j = 0; j < cateGoryTypeMapList.size(); j ++)
            {
                if(cateGoryTypeMapList.at(j).value(HTTPKEY::PID) == cateGoryTypeMapList.at(i).value(HTTPKEY::CATEGORYID))
                {
                    QTreeWidgetItem* childItem = TREEITEM();
                    parentItem->addChild(childItem);

                    childItem->setText(0, cateGoryTypeMapList.at(j).value(HTTPKEY::NAME));

                    for(int k = 0; k < cateGoryTypeMapList.size(); k ++)
                    {
                        if(cateGoryTypeMapList.at(k).value(HTTPKEY::PID) == cateGoryTypeMapList.at(j).value(HTTPKEY::CATEGORYID))
                        {
                            QTreeWidgetItem* childChildItem = TREEITEM();
                            childItem->addChild(childChildItem);

                            childChildItem->setText(0, cateGoryTypeMapList.at(k).value(HTTPKEY::NAME));

                            for(int l = 0; l < cateGoryTypeMapList.size(); l ++)
                            {
                                if(cateGoryTypeMapList.at(l).value(HTTPKEY::PID) == cateGoryTypeMapList.at(k).value(HTTPKEY::CATEGORYID))
                                {
                                    QTreeWidgetItem* childChildChildItem = TREEITEM();
                                    childChildItem->addChild(childChildChildItem);

                                    childChildChildItem->setText(0, cateGoryTypeMapList.at(l).value(HTTPKEY::NAME));
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    ui->treeWidgetCateGory->expandAll();
}

/************************   下载图片            *********************/
void MaterialWidget::downLoadImage(QNetworkReply *reply)
{
    if(NULL == reply) return;

    if (reply->error() == QNetworkReply::NoError)
    {
        QByteArray byteArray = reply->readAll();
        ui->tabMaterialInfo->pushButtonImage->setText(NULL);
        ui->tabMaterialInfo->pushButtonImage->setIconSize(QSize(MaterialControl::CONTROLWIDGET, MaterialControl::CONTROLWIDGET));

        QPixmap pixmapImage;
        pixmapImage.loadFromData(byteArray);
        ui->tabMaterialInfo->setPixMapImage(pixmapImage);
        ui->tabMaterialInfo->pushButtonImage->setIcon(pixmapImage);
    }

    reply->close();
}

/************************   解析JSON            *********************/
void MaterialWidget::readJson(QNetworkReply *reply, int type)
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

                HTTPCLIENT->readJsonMap(jsonNextObj, HTTPKEY::RES, resMapData);

                //原料列表
                if(type == PROTOCOL::URL_MAT_LIST)
                {
                    if(ISERROR(codeValue))
                    {
                        ui->tableWidget->clearContents();
                        ui->tableWidget->setRowCount(0);
                        mapDataList.clear();
                        ui->labelSize->setText(GLOBALDEF::TOTALONUMBER.arg(0));

                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, mapDataList);

                    this->setTableData();
                }
                //原料详情
                else if(type == PROTOCOL::URL_MAT_DETAILS)
                {
                    if(ISERROR(codeValue))
                    {

                        if(codeValue == ZERO)     errorMsg = MESSAGE::SELECTERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::CATEGORY, cateGoryMapList);
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::UNIT,     unitMapList);
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::SIDEUNIT, sideUnitMapList);

                    ui->tabMaterialInfo->setMapUnitList(unitMapList);
                    ui->tabMaterialInfo->setCategoryList(cateGoryMapList);
                    ui->tabMaterialInfo->setMapSideList(sideUnitMapList);

                    ui->tabMaterialInfo->setWareHouseFlage(resMapData.value(HTTPKEY::ISWAREHOUSEUNIT));
                    ui->tabMaterialInfo->setPriceFlage(resMapData.value(HTTPKEY::ISPRICEUNIT));
                    ui->tabMaterialInfo->setSupplyFlage(resMapData.value(HTTPKEY::ISSUPPLYUNIT));

                    this->setControlMaterialInfo();
                }

                //添加原料显示页
                else if(type == PROTOCOL::URL_ADD_MAT_SHOW)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::CATEGORYLIST, cateGoryMapListAdd);

                    this->setControlAddMaterial();

                    ui->tabMaterialInfo->setPixMapImage(QPixmap());
                    ui->tabMaterialInfo->pushButtonImage->setIcon(QIcon(GLOBALDEF::ADDIMG));
                    ui->tabMaterialInfo->pushButtonImage->setIconSize(QSize(MaterialControl::IMAGEWIDGH, MaterialControl::IMAGEWIDGH));
                    ui->tabMaterialInfo->pushButtonImage->setText(GLOBALDEF::SELECTIMAGE);
                }

                //添加原料
                else if(type == PROTOCOL::URL_MAT_ADD)
                {

                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ADDERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;
                        else if(codeValue == THREE) errorMsg = MESSAGE::MATISEXSIT;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectType = true;
                    this->showWidget();
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::ADDSUCCESS, true);
                }

                //分类列表
                else if(type == PROTOCOL::URL_MAT_CAT_LIST)
                {
                    if(ISERROR(codeValue)) return;

                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, cateGoryTypeMapList);
                    this->setTableTypeData();
                }

                //分类列表显示
                else if(type == PROTOCOL::URL_MAT_LIST_SHOW)
                {
                    if(ISERROR(codeValue)) return;

                    MapList cateGoryTypeShowMapList;

                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, cateGoryTypeShowMapList);

                    materialType->setMapList(cateGoryTypeShowMapList);

                    if(!categoryId.isEmpty())
                    {
                        HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_CATE_EDIT_SHOW).arg(categoryId), PROTOCOL::URL_CATE_EDIT_SHOW);
                        categoryId.clear();
                    }
                }

                //编辑分类显示页
                else if(type == PROTOCOL::URL_CATE_EDIT_SHOW)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    MapList cateGoryTypeShowMapList;
                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, cateGoryTypeShowMapList);
                    materialType->setData(cateGoryTypeShowMapList);
                }

                //修改原料
                else if(type == PROTOCOL::URL_MAT_EDIT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::EDITERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;
                        else if(codeValue == THREE) errorMsg = MESSAGE::CATEXSITERROR;
                        else if(codeValue == FOUR)  errorMsg = MESSAGE::BARCODEEXIST;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectType = false;
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_MAT_LIST), PROTOCOL::URL_MAT_LIST);

                    MESSAGEBOX->showMessageBox(this,GLOBALDEF::EDITSUCCESS, true);

                    ui->tabWidget->setHidden(true);
                }

                //删除原料前提示
                else if(type == PROTOCOL::URL_MAT_DEL)
                {

                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::REMOVECATMAT;
                        else if(codeValue == THREE) errorMsg = MESSAGE::REMOVEWARHSEMAT;
                        MESSAGEBOX->showMessageBox(this, errorMsg);
                    }

                    if(codeValue == ONE)
                    {
                        int okFlage = MESSAGEBOX->showMessageBox(this, GLOBALDEF::CONFIRMDEL, true, false);
                        if(okFlage == QDialog::Accepted)
                        {
                            List listId;
                            for(int i = 0; i < ui->tableWidget->selectedItems().size(); i ++)
                            {
                                if(i % ui->tableWidget->columnCount() == 0)
                                {
                                    listId.append(ui->tableWidget->selectedItems().at(i)->text());
                                }
                            }

                            QByteArray arrayData = QString("listId=%1").arg(QString(makeJson(listId))).toLatin1();

                            HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_DEL_MAT), arrayData, PROTOCOL::URL_DEL_MAT);
                        }
                    }


                }

                //删除原料
                else if(type == PROTOCOL::URL_DEL_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::DELERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectType = false;
                    this->showWidget();
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::DELSUCCESS, true);
                }

                //分类添加
                else if(type == PROTOCOL::URL_CATEGORY_ADD)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ADDERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;
                        else if(codeValue == THREE) errorMsg = MESSAGE::CATEXSITERROR;
                        else if(codeValue == FOUR)  errorMsg = MESSAGE::MOVETHISCAT;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    addMaterialType();

                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::ADDSUCCESS, true);
                }

                //分类删除
                else if(type == PROTOCOL::URL_CATEGORY_DEL)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::DELERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;
                        else if(codeValue == THREE) errorMsg = MESSAGE::FIRSTDELCATMAT;
                        else if(codeValue == FOUR)  errorMsg = MESSAGE::FIRSTDELCATCHILD;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    addMaterialType();

                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::DELSUCCESS, true);
                }

                //分类修改
                else if(type == PROTOCOL::URL_CATEGORY_EDIT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::EDITERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;
                        else if(codeValue == THREE) errorMsg = MESSAGE::CATEXSITERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    addMaterialType();
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::EDITSUCCESS, true);
                }

                //单元查询
                else if(type == PROTOCOL::URL_UNIT_LIST)
                {
                    if(ISERROR(codeValue))
                    {
                        ui->tableWidgetUnitLibrary->clearContents();
                        ui->tableWidgetUnitLibrary->setRowCount(0);
                        unitMapList.clear();

                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, unitMapList);
                    this->setTableUnitData();
                    this->setControlAddMaterial();
                }

                //单元添加
                else if(type ==  PROTOCOL::URL_ADD_UNIT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ADDERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;
                        else if(codeValue == THREE) errorMsg = MESSAGE::UNITISEXIST;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, unitMapList);
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_UNIT_LIST), PROTOCOL::URL_UNIT_LIST);

                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::ADDSUCCESS, true);
                }

                //单元删除
                else if(type == PROTOCOL::URL_DEL_UNIT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::DELERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;
                        else if(codeValue == THREE) errorMsg = MESSAGE::UNITICANNOTDEL;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, unitMapList);
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_UNIT_LIST), PROTOCOL::URL_UNIT_LIST);

                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::DELSUCCESS, true);
                }

                //添加副单元显示页
                else if(type == PROTOCOL::URL_SEL_SIDE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    QJsonObject jsonValue = jsonNextObj.value(HTTPKEY::UNIT).toObject();

                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::UNITLIST, unitMapList);

                    ui->tabAddMaterial->setMapSideUnitList(unitMapList);
                    ui->tabAddMaterial->setSideMainUnit(jsonValue[HTTPKEY::NAME].toString());

                    ui->tabMaterialInfo->setMapSideUnitList(unitMapList);
                    ui->tabMaterialInfo->setSideMainUnit(jsonValue[HTTPKEY::NAME].toString());

                    widgetFlage == true ? ui->tabAddMaterial->getAddUnitSite()->showWidget() :
                                          ui->tabMaterialInfo->getAddUnitSite()->showWidget();
                }

                //最后一级分类
                else if(type == PROTOCOL::URL_FINALLY_CAT)
                {
                    if(ISERROR(codeValue)) return;

                    MapList mapList;
                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, mapList);

                    exchangeTypeWidget->setMapExchangeData(mapList);
                    exchangeTypeWidget->show();
                }

                //原料批量修改分类
                else if(type == PROTOCOL::URL_MAT_EXG_TYPE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::OPERATEFAILED;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }
                    ui->tabWidget->setHidden(true);
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::EDITSUCCESS, true);
                }

                //导出到邮箱
                else if(type == PROTOCOL::URL_MAT_EMAIL)
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
    }
    reply->close();
}

/************************   设置控件信息         *********************/
void MaterialWidget::setControlMaterialInfo()
{
    if(resMapData.value(HTTPKEY::IMAGE).isEmpty() || resMapData.value(HTTPKEY::IMAGE) == "0")
    {
        ui->tabMaterialInfo->setPixMapImage(QPixmap());
        ui->tabMaterialInfo->pushButtonImage->setIcon(QIcon(GLOBALDEF::ADDIMG));
        ui->tabMaterialInfo->pushButtonImage->setIconSize(QSize(MaterialControl::IMAGEWIDGH, MaterialControl::IMAGEWIDGH));
        ui->tabMaterialInfo->pushButtonImage->setText(GLOBALDEF::SELECTIMAGE);
    }
    else
    {
        HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_MAT_IMAGE).arg(resMapData.value(HTTPKEY::IMAGE)), PROTOCOL::URL_MAT_IMAGE);
    }

    ui->tabMaterialInfo->clearControlInfo();

    ui->tabMaterialInfo->lineEditName->setText(resMapData.value(HTTPKEY::NAME));
    ui->tabMaterialInfo->lineEditBarCode->setText(resMapData.value(HTTPKEY::BARCODE));
    ui->tabMaterialInfo->lineEditSpec->setText(resMapData.value(HTTPKEY::STANDARD));
    ui->tabMaterialInfo->lineEditShelf->setText(resMapData.value(HTTPKEY::TERM));

    for(int i = 0; i < unitMapList.size(); i ++)
    {
        ui->tabMaterialInfo->comboBoxMainUnit->addItem(unitMapList.at(i).value(HTTPKEY::NAME));

        if(unitMapList.at(i).value(HTTPKEY::UNITID) == resMapData.value(HTTPKEY::UNITID))
        {
            ui->tabMaterialInfo->comboBoxMainUnit->setCurrentIndex(i);
        }
    }
    ui->tabMaterialInfo->comboBoxMainUnit->setEnabled(false);

    for(int i = 0; i < cateGoryMapList.size(); i ++)
    {
        ui->tabMaterialInfo->comboxType->addItem(cateGoryMapList.at(i).value(HTTPKEY::NAME));

        if(cateGoryMapList.at(i).value(HTTPKEY::CATEGORYID) == resMapData.value(HTTPKEY::CATEGORYID))
        {
            ui->tabMaterialInfo->comboxType->setCurrentIndex(i);
        }
    }

    ui->tabMaterialInfo->addSideList();
}

/************************   设置控件信息         *********************/
void MaterialWidget::setControlAddMaterial()
{
    ui->tabAddMaterial->comboBoxMainUnit->clear();
    ui->tabAddMaterial->comboxType->clear();

    for(int i = 0; i < unitMapList.size(); i ++)
    {
        ui->tabAddMaterial->comboBoxMainUnit->addItem(unitMapList.at(i).value(HTTPKEY::NAME));
    }

    if( unitMapList.size() != 0)
    {
        ui->tabAddMaterial->setCurrentText(unitMapList.at(0).value(HTTPKEY::NAME));
    }

    for(int i = 0; i < cateGoryMapListAdd.size(); i ++)
    {
        ui->tabAddMaterial->comboxType->addItem(cateGoryMapListAdd.at(i).value(HTTPKEY::NAME));
    }

    ui->tabAddMaterial->setMapUnitList(unitMapList);
    ui->tabAddMaterial->setCategoryList(cateGoryMapListAdd);
}

/************************   添加原料             *********************/
void MaterialWidget::on_pushButtonAddMaterial_clicked()
{
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->tabAddMaterial));
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->tabMaterialInfo));
    addMaterial->showWidget();
}

/************************   添加类型             *********************/
void MaterialWidget::addMaterialType()
{
    ui->tabWidget->setCurrentWidget(ui->tabAddType);

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_MAT_CAT_LIST), PROTOCOL::URL_MAT_CAT_LIST);
}

/************************   确定事件             *********************/
void MaterialWidget::receiveAddMaterial()
{
    if(addMaterial->getMaterialName().isEmpty()) return;

    widgetFlage = true;
    ui->tabAddMaterial->clearControlInfo();
    ui->tabWidget->show();

    ui->tabWidget->addTab(ui->tabAddMaterial, GLOBALDEF::TABADDMATERIAL);
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->tabMaterialInfo));
    ui->tabWidget->setCurrentWidget(ui->tabAddMaterial);
    ui->tabAddMaterial->lineEditName->setText(addMaterial->getMaterialName());

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ADD_MAT_SHOW).arg(addMaterial->getMaterialName()), PROTOCOL::URL_ADD_MAT_SHOW);
}

/************************   添加单元             *********************/
void MaterialWidget::receiveAddUnit()
{
    if(addUnit->getUnitName().isEmpty()) return;

    ui->tabWidget->setCurrentWidget(ui->tableWidgetUnitLibrary);

    QByteArray byteArray;

    byteArray.append(POSTARG::UNITNAME.arg(addUnit->getUnitName()));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_ADD_UNIT), byteArray, PROTOCOL::URL_ADD_UNIT);
}

/************************   查看原料信息         *********************/
void MaterialWidget::on_tableWidget_clicked(const QModelIndex &index)
{
    widgetFlage = false;
    ui->tabWidget->addTab(ui->tabMaterialInfo, GLOBALDEF::TABMATERIALINFO);
    ui->tabWidget->setCurrentWidget(ui->tabMaterialInfo);
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->tabAddMaterial));

    QString materialId = ui->tableWidget->item(index.row(), 0)->text();
    ui->tabWidget->show();
    ui->tabMaterialInfo->setMaterialId(materialId);

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_MAT_DETAILS).arg(materialId), PROTOCOL::URL_MAT_DETAILS);
}

/************************   点击窗口            *********************/
void MaterialWidget::on_tabWidget_tabBarClicked(int index)
{
    if(0 == index) addMaterialType();
    if(1 == index) HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_UNIT_LIST), PROTOCOL::URL_UNIT_LIST);
}

/************************   添加按钮            *********************/
void MaterialWidget::on_pushButtonAdd_clicked()
{
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_MAT_LIST_SHOW), PROTOCOL::URL_MAT_LIST_SHOW);

    materialType->showWidget();
}

/************************   查看类型信息        *********************/
void MaterialWidget::on_treeWidgetCateGory_doubleClicked(const QModelIndex &index)
{
    if(NULL == ui->treeWidgetCateGory->currentItem()) return;
    QString keyName = ui->treeWidgetCateGory->currentItem()->text(0);

    for(int i = 0; i < cateGoryTypeMapList.size(); i ++)
    {
        if(keyName == cateGoryTypeMapList.at(i).value(HTTPKEY::NAME))
        {
            HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_MAT_LIST_SHOW), PROTOCOL::URL_MAT_LIST_SHOW);
            categoryId = cateGoryTypeMapList.at(i).value(HTTPKEY::CATEGORYID);
            materialType->setCategoryId(categoryId);
            materialType->showWidget();
        }
    }
}

/************************   添加单元            *********************/
void MaterialWidget::on_pushButtonAddUnit_clicked()
{
    addUnit->showWidget();
}

/************************   删除单元            *********************/
void MaterialWidget::on_pushButtonDelUnit_clicked()
{
    if(NULL == ui->tableWidgetUnitLibrary->currentItem()) return;

    QString keyText  = ui->tableWidgetUnitLibrary->currentItem()->text();
    QString keyValue = HTTPCLIENT->findMapValue(unitMapList, keyText, HTTPKEY::UNITID);

    if(!keyValue.isEmpty())
    {
        QByteArray byteArray;
        byteArray.append(POSTARG::UNITID.arg(keyValue));
        HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_DEL_UNIT), byteArray, PROTOCOL::URL_DEL_UNIT);
    }
}

/************************   接收修改分类         ********************/
void MaterialWidget::slotReceiveExchangeType(int index)
{
    if(ui->tableWidget->selectedItems().size() <= 0) return;
    if(index < 0 || index >= exchangeTypeWidget->getMapExchangeData().size()) return;

    QString tempCatId = exchangeTypeWidget->getMapExchangeData().at(index).value(HTTPKEY::CATEGORYID);

    List listId;
    for(int i = 0; i < ui->tableWidget->selectedItems().size(); i ++)
    {
        if(i % ui->tableWidget->columnCount() == 0)
        {
            listId.append(ui->tableWidget->selectedItems().at(i)->text());
        }
    }

    QString strPost = POSTARG::UPDATECAT.arg(QString(makeJson(listId)).toLatin1(), tempCatId);

    QByteArray arrayData = strPost.toLatin1();

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_MAT_EXG_TYPE), arrayData, PROTOCOL::URL_MAT_EXG_TYPE);
}

/************************   组合JSON            ********************/
QByteArray MaterialWidget::makeJson(List data)
{
    QJsonObject jsonTotal;
    QJsonObject jsonData;

    for(int i = 0; i < data.size(); i ++)
    {
        jsonData.insert(QString::number(i), data.at(i));
    }

    jsonTotal.insert("materialList", jsonData);

    QJsonDocument document;
    document.setObject(jsonTotal);

    return document.toJson();
}

/************************   导出到邮箱            ********************/
void MaterialWidget::on_pushButtonExtend_clicked()
{
    exportEmail->showWidget();
}

/************************   接收邮箱号            ********************/
void MaterialWidget::receiveEmailText(QString emailText)
{
    QByteArray byteArray;

    byteArray.append(POSTARG::EXTENDEMAIL.arg(emailText));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_MAT_EMAIL), byteArray, PROTOCOL::URL_MAT_EMAIL);
}

/************************   删除原料            ********************/
void MaterialWidget::on_pushButtonDeleteMat_clicked()
{
    if(ui->tableWidget->selectedItems().size() <= 0) return;

    List listId;
    for(int i = 0; i < ui->tableWidget->selectedItems().size(); i ++)
    {
        if(i % ui->tableWidget->columnCount() == 0)
        {
            listId.append(ui->tableWidget->selectedItems().at(i)->text());
        }
    }

    QByteArray arrayData = QString("listId=%1").arg(QString(makeJson(listId))).toLatin1();

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_MAT_DEL), arrayData, PROTOCOL::URL_MAT_DEL);
}

/************************   切换分类            ********************/
void MaterialWidget::on_pushButtonChangeType_clicked()
{
    if(ui->tableWidget->selectedItems().size() <= 0) return;

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_FINALLY_CAT), PROTOCOL::URL_FINALLY_CAT);
}
