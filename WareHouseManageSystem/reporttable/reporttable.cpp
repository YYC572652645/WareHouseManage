#include "reporttable.h"
#include "ui_reporttable.h"
#include "messagebox/messagedialog.h"
#include "httpclient/httpkey.h"

#include <QToolTip>

/*********************  构造函数       *********************/
ReportTable::ReportTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::reporttable)
{
    ui->setupUi(this);
    this->initControl();
}

/*********************  析构函数       *********************/
ReportTable::~ReportTable()
{
    delete ui;
}

/*********************  显示窗口       *********************/
void ReportTable::showWidget()
{
    this->show();
}

/*********************  解析json       *********************/
void ReportTable::readJson(QNetworkReply *reply, int type)
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

            if(jsonObject.contains(HTTPKEY::CODE)) codeValue = jsonObject.value(HTTPKEY::CODE).toInt();

            QString errorMsg;
            if(jsonObject.contains(HTTPKEY::MSG))
            {
                QJsonObject jsonNextObj = jsonObject.value(HTTPKEY::MSG).toObject();

                ui->tabWidgetData->show();
                if(type == PROTOCOL::URL_STATE_STO_PAGE || type == PROTOCOL::URL_STATE_STO_GATHER_PAGE
                        || type == PROTOCOL::URL_STATE_RET_PAGE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    if(type == PROTOCOL::URL_STATE_STO_PAGE)
                    {
                        selectWidget.showWidget(SelectWidget::STO_PAGE);

                        ui->tabWidgetData->setTabText(0, tr("采购入库明细报表"));
                    }
                    else if(type == PROTOCOL::URL_STATE_STO_GATHER_PAGE)
                    {
                        ui->tabWidgetData->setTabText(0, tr("采购入库汇总报表"));
                        selectWidget.showWidget(SelectWidget::STO_GATHER_PAGE);

                        MapList mapListMatCat;
                        HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::MATERIALCATEGORY, mapListMatCat);
                        selectWidget.setMapListMatCat(mapListMatCat);
                    }
                    else
                    {
                        ui->tabWidgetData->setTabText(0, tr("采购退货明细报表"));
                        selectWidget.showWidget(SelectWidget::RET_PAGE);
                    }

                    MapList mapListState;
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::STATE, mapListState);
                    selectWidget.setMapListState(mapListState);

                    MapList mapListSupplier;
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::SUPPLIER, mapListSupplier);
                    selectWidget.setMapListSupplier(mapListSupplier);

                    MapList mapListWareHouse;
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::WAREHOUSE, mapListWareHouse);
                    selectWidget.setMapListWareHouse(mapListWareHouse);

                    MapList mapListTime;
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::TIMEFRAME, mapListTime);
                    selectWidget.setMapListTime(mapListTime);

                    List listTypeData;
                    QJsonArray jsonArray = jsonNextObj.value(HTTPKEY::TIMETYPE).toArray();

                    for(int i = 0; i < jsonArray.size(); i ++)
                    {
                        listTypeData.append(jsonArray.at(i).toString());
                    }
                    selectWidget.setTypeList(listTypeData);

                    selectWidget.setControlData();
                }
                else if(type == PROTOCOL::URL_STATE_ADJ_PAGE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    ui->tabWidgetData->setTabText(0, tr("调整单明细报表"));
                    selectWidget.showWidget(SelectWidget::ADJ_PAGE);

                    MapList mapListState;
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::TYPE, mapListState);
                    selectWidget.setMapListState(mapListState);

                    MapList mapListWareHouse;
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::WAREHOUSE, mapListWareHouse);
                    selectWidget.setMapListWareHouse(mapListWareHouse);

                    List listTypeData;
                    QJsonArray jsonArray = jsonNextObj.value(HTTPKEY::TIMETYPE).toArray();

                    for(int i = 0; i < jsonArray.size(); i ++)
                    {
                        listTypeData.append(jsonArray.at(i).toString());
                    }
                    selectWidget.setTypeList(listTypeData);

                    selectWidget.setControlData();
                }
                else if(type == PROTOCOL::URL_STATE_CHECK_PAGE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    ui->tabWidgetData->setTabText(0, tr("盘存单明细报表"));
                    selectWidget.showWidget(SelectWidget::CHECK_PAGE);

                    MapList mapListState;
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::STATE, mapListState);
                    selectWidget.setMapListState(mapListState);

                    MapList mapListWareHouse;
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::WAREHOUSE, mapListWareHouse);
                    selectWidget.setMapListWareHouse(mapListWareHouse);

                    selectWidget.setControlData();
                }

                else if(type == PROTOCOL::URL_STATE_CHK_GATHER_PAGE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    ui->tabWidgetData->setTabText(0, tr("盘存单汇总报表"));
                    selectWidget.showWidget(SelectWidget::CHECK_GATHER_PAGE);

                    MapList mapListMatCat;
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::MATERIALCATEGORY, mapListMatCat);
                    selectWidget.setMapListMatCat(mapListMatCat);

                    MapList mapListWareHouse;
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::WAREHOUSE, mapListWareHouse);
                    selectWidget.setMapListWareHouse(mapListWareHouse);

                    selectWidget.setControlData();
                }
                else if(type == PROTOCOL::URL_STATE_SUP_PAGE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    ui->tabWidgetData->setTabText(0, tr("供应商供货明细报表"));
                    selectWidget.showWidget(SelectWidget::SUP_PAGE);

                    MapList mapListState;
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::OPERATION, mapListState);
                    selectWidget.setMapListState(mapListState);

                    MapList mapListSupplier;
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::SUPPLIER, mapListSupplier);
                    selectWidget.setMapListSupplier(mapListSupplier);

                    MapList mapListTime;
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::TIMEFRAME, mapListTime);
                    selectWidget.setMapListTime(mapListTime);

                    selectWidget.setControlData();
                }
                else if(type == PROTOCOL::URL_STATE_SUP_GATHER_PAGE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    ui->tabWidgetData->setTabText(0, tr("供应商供货汇总报表"));
                    selectWidget.showWidget(SelectWidget::SUP_GATHER_PAGE);

                    MapList mapListState;
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::OPERATION, mapListState);
                    selectWidget.setMapListState(mapListState);

                    MapList mapListSupplier;
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::SUPPLIER, mapListSupplier);
                    selectWidget.setMapListSupplier(mapListSupplier);

                    MapList mapListTime;
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::TIMEFRAME, mapListTime);
                    selectWidget.setMapListTime(mapListTime);

                    MapList mapListMatCat;
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::MATERIALCATEGORY, mapListMatCat);
                    selectWidget.setMapListMatCat(mapListMatCat);

                    selectWidget.setControlData();
                }
                else if(type == PROTOCOL::URL_STATE_SELECT_MAT_PAGE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)       errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO)   errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    ui->tabWidgetData->setTabText(0, tr("原料销售报表"));
                    selectWidget.showWidget(SelectWidget::MAT_SELECT_PAGE);

                    MapList mapListTime;
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::TIMEFRAME, mapListTime);
                    selectWidget.setMapListTime(mapListTime);

                    selectWidget.setControlData();
                }
                else if(type == PROTOCOL::URL_STATE_STORAGE_EXTEND  ||
                        type == PROTOCOL::URL_STATE_STO_GAT_EXTEND  ||
                        type == PROTOCOL::URL_STATE_RETURNS_EXTEND  ||
                        type == PROTOCOL::URL_STATE_ADJUST_EXTEND   ||
                        type == PROTOCOL::URL_STATE_CHECK_EXTEND    ||
                        type == PROTOCOL::URL_STATE_CHK_GAT_EXTEND  ||
                        type == PROTOCOL::URL_STATE_SUPPLIER_EXTEND ||
                        type == PROTOCOL::URL_STATE_SUP_GAT_EXTEND  ||
                        type == PROTOCOL::URL_STATE_SEL_MAT_EXTEND)
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
                else
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
                    selectWidget.setMapListData(mapListData);

                    selectWidget.setTableData();
                }
            }
        }
        reply->close();
    }
}

/*********************  初始化控件       *********************/
void ReportTable::initControl()
{
    ui->tabWidgetData->addTab(&selectWidget, tr("报表"));
    ui->tabWidgetData->setHidden(true);

    SETTREEWIDGET(ui->treeWidget);
    ui->treeWidget->expandAll();

    ui->splitter->setStretchFactor(0, 1);
    ui->splitter->setStretchFactor(1, 30);
}

/*********************  单击树形控件       *********************/
void ReportTable::on_treeWidget_clicked(const QModelIndex &index)
{
    if(NULL == ui->treeWidget->currentItem()->parent()) return;
    if(NULL == ui->treeWidget->currentItem()) return;

    QTreeWidgetItem * currentItem = ui->treeWidget->currentItem();
    if(currentItem->text(ZERO) == tr("采购入库明细报表"))
    {
        HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STATE_STO_PAGE), PROTOCOL::URL_STATE_STO_PAGE);
    }
    else if(currentItem->text(ZERO) == tr("采购入库汇总报表"))
    {
        HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STATE_STO_GATHER_PAGE), PROTOCOL::URL_STATE_STO_GATHER_PAGE);
    }
    else if(currentItem->text(ZERO) == tr("采购退货明细报表"))
    {
        HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STATE_RET_PAGE), PROTOCOL::URL_STATE_RET_PAGE);
    }
    else if(currentItem->text(ZERO) == tr("调整单明细报表"))
    {
        HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STATE_ADJ_PAGE), PROTOCOL::URL_STATE_ADJ_PAGE);
    }
    else if(currentItem->text(ZERO) == tr("盘存单明细报表"))
    {
        HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STATE_CHECK_PAGE), PROTOCOL::URL_STATE_CHECK_PAGE);
    }
    else if(currentItem->text(ZERO) == tr("盘存单汇总报表"))
    {
        HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STATE_CHK_GATHER_PAGE), PROTOCOL::URL_STATE_CHK_GATHER_PAGE);
    }
    else if(currentItem->text(ZERO) == tr("供应商供货明细报表"))
    {
        HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STATE_SUP_PAGE), PROTOCOL::URL_STATE_SUP_PAGE);
    }
    else if(currentItem->text(ZERO) == tr("供应商供货汇总报表"))
    {
        HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STATE_SUP_GATHER_PAGE), PROTOCOL::URL_STATE_SUP_GATHER_PAGE);
    }
    else if(currentItem->text(ZERO) == tr("原料销售报表"))
    {
        HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STATE_SELECT_MAT_PAGE), PROTOCOL::URL_STATE_SELECT_MAT_PAGE);
    }
}

/*********************  设置提示       *********************/
void ReportTable::on_treeWidget_pressed(const QModelIndex &index)
{
    QToolTip::showText(QCursor::pos(), ui->treeWidget->currentItem()->text(0));
}
