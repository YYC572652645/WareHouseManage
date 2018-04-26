#include "AddPurMaterial.h"
#include "ui_addpurmaterial.h"
#include "httpclient/httpkey.h"

/*********************  构造函数       *********************/
AddPurMaterial::AddPurMaterial(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddPurMaterial)
   ,widgetType(0)
{
    ui->setupUi(this);
    this->initControl();
}

/*********************  析构函数       *********************/
AddPurMaterial::~AddPurMaterial()
{
    delete ui;
}

/*********************  显示窗口       *********************/
void AddPurMaterial::showWidget(int type)
{
    if(type == EDITTYPE)
    {
        titleBar->setTitle(GLOBALDEF::EDITPURMATERIAL);
        ui->checkBoxAllSelect->setHidden(true);
        ui->pushButtonDel->show();
        ui->tableWidgetEditData->show();
        ui->tableWidgetData->setHidden(true);
        ui->pushButtonSave->setHidden(true);
        ui->pushButtonCancel->setHidden(true);
    }
    else
    {
        titleBar->setTitle(GLOBALDEF::ADDPURMATERIAL);

        ui->tableWidgetEditData->setHidden(true);
        ui->tableWidgetData->show();
        ui->checkBoxAllSelect->show();
        ui->pushButtonDel->setHidden(true);
        ui->pushButtonSave->show();
        ui->pushButtonCancel->show();
    }

    ui->checkBoxAllSelect->setChecked(false);
    ui->checkBoxAllSelect->setText(tr("全选"));
    ui->checkBoxAllSelect->setIcon(QIcon(GLOBALDEF::ALLSELECTIMAGE));

    widgetType = type;
    this->show();
}

/*********************  初始化控件       *********************/
void AddPurMaterial::initControl()
{
    titleBar = new TitleBar(this);
    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    SETTABLEWIDGET(ui->tableWidgetData);
    SETTABLEWIDGET(ui->tableWidgetEditData);

    //设置多行选中
    ui->tableWidgetEditData->setSelectionMode(QAbstractItemView::ExtendedSelection);
}

/*********************  改变事件        *********************/
void AddPurMaterial::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  获取原料数据        *********************/
MapList AddPurMaterial::getMapMatList() const
{
    return mapMatList;
}

/*********************  设置数据列表        *********************/
void AddPurMaterial::setMapMatList(const MapList &value)
{
    mapMatList = value;

    ui->tableWidgetData->clearContents();
    ui->tableWidgetData->setRowCount(mapMatList.size());

    for(int i = 0; i < mapMatList.size(); i ++)
    {
        ui->tableWidgetData->setItem(i, ZERO, DATA(mapMatList.at(i).value(HTTPKEY::MATERIALNAME)));
        ui->tableWidgetData->setItem(i, ONE, DATA(mapMatList.at(i).value(HTTPKEY::BARCODE)));
        ui->tableWidgetData->item(i, ZERO)->setCheckState(Qt::Unchecked);

        SETTABLECENTER(ui->tableWidgetData->item(i, ZERO));
        SETTABLECENTER(ui->tableWidgetData->item(i, ONE));
    }
    ui->tableWidgetData->scrollToBottom();
}

/*********************  保存事件        *********************/
void AddPurMaterial::on_pushButtonSave_clicked()
{
    for(int i = ui->tableWidgetData->rowCount() - 1; i >= 0  ; i --)
    {
        if(ui->tableWidgetData->item(i, 0)->checkState() == Qt::Unchecked)
        {
            mapMatList.removeAt(i);
        }
    }
    mapSelectList = mapMatList;

    List listId;
    for(int i = 0; i < mapMatList.size(); i ++)
    {
        listId.append(mapMatList.at(i).value(HTTPKEY::MATERIALID));
    }

    if(listId.isEmpty()) return;

    QByteArray byteArray;
    byteArray.append(POSTARG::ADDPURMAT.arg(makeJson(listId), purchaseNumber, supplierId));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_PUR_ADD_MAT), byteArray, PROTOCOL::URL_PUR_ADD_MAT);

    this->close();
}

/*********************  取消事件        *********************/
void AddPurMaterial::on_pushButtonCancel_clicked()
{
    this->close();
}

/*********************  单击选中        *********************/
void AddPurMaterial::on_tableWidgetData_clicked(const QModelIndex &index)
{
    if( ui->tableWidgetData->item(index.row(), 0)->checkState() == Qt::Checked)
    {
        ui->tableWidgetData->item(index.row(), 0)->setCheckState(Qt::Unchecked);
    }
    else
    {
        ui->tableWidgetData->item(index.row(), 0)->setCheckState(Qt::Checked);
    }
}

/************************   组合JSON            ********************/
QString AddPurMaterial::makeJson(List data)
{
    QJsonObject jsonTotal;
    QJsonObject jsonData;

    for(int i = 0; i < data.size(); i ++)
    {
        jsonData.insert(QString::number(i), data.at(i));
    }

    jsonTotal.insert("listId", jsonData);

    QJsonDocument document;
    document.setObject(jsonTotal);

    return document.toJson();
}

/************************   设置数据列表       ********************/
void AddPurMaterial::setMapSelectList(const MapList &value)
{
    mapSelectList = value;

    setTableEidiData();
}

/************************   获取选择的列表       ********************/
MapList AddPurMaterial::getMapSelectList() const
{
    return mapSelectList;
}

/************************   删除数据            ********************/
void AddPurMaterial::on_pushButtonDel_clicked()
{
    if(NULL == ui->tableWidgetEditData->currentItem()) return;

    List listId;
    for(int i = 0; i < ui->tableWidgetEditData->selectedItems().size(); i ++)
    {
        if(i % ui->tableWidgetEditData->columnCount())
        {
            int currentRow = ui->tableWidgetEditData->selectedItems().at(i)->row();

            listId.append(mapSelectList.at(currentRow).value(HTTPKEY::PURCHASEMATERIALID));
        }
    }

    QByteArray byteArray;
    byteArray.append(POSTARG::DELPURMAT.arg(makeJson(listId)));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_PUR_DEL_MAT), byteArray, PROTOCOL::URL_PUR_DEL_MAT);
}


/************************   选择         ********************/
void AddPurMaterial::on_checkBoxAllSelect_clicked()
{
    bool checkFlage = ui->checkBoxAllSelect->isChecked();

    if(checkFlage)
    {
        ui->checkBoxAllSelect->setText(tr("全不选"));
        ui->checkBoxAllSelect->setIcon(QIcon(GLOBALDEF::NOTSELECTIMAGE));
    }
    else
    {
        ui->checkBoxAllSelect->setText(tr("全选"));
        ui->checkBoxAllSelect->setIcon(QIcon(GLOBALDEF::ALLSELECTIMAGE));
    }

    Qt::CheckState checkState = ui->checkBoxAllSelect->isChecked() ? Qt::Checked : Qt::Unchecked;

    for(int i = 0; i <  ui->tableWidgetData->rowCount(); i ++)
    {
        ui->tableWidgetData->item(i, 0)->setCheckState(checkState);
    }
}

/************************   获取供应商ID         ********************/
QString AddPurMaterial::getSupplierId() const
{
    return supplierId;
}

/************************   获取采购订单号        ********************/
QString AddPurMaterial::getPurchaseNumber() const
{
    return purchaseNumber;
}

/************************   设置供应商ID         ********************/
void AddPurMaterial::setSupplierId(const QString &value)
{
    supplierId = value;
}

/************************   设置采购订单号         ********************/
void AddPurMaterial::setPurchaseNumber(const QString &value)
{
    purchaseNumber = value;
}

/************************   设置表格数据         ********************/
void AddPurMaterial::setTableEidiData()
{
    ui->tableWidgetEditData->clearContents();
    ui->tableWidgetEditData->setRowCount(mapSelectList.size());

    for(int i = 0; i < mapSelectList.size(); i ++)
    {
        ui->tableWidgetEditData->setItem(i, ZERO, DATA(mapSelectList.at(i).value(HTTPKEY::MATERIALNAME)));
        ui->tableWidgetEditData->setItem(i, ONE,  DATA(mapSelectList.at(i).value(HTTPKEY::BARCODE)));

        SETTABLECENTER(ui->tableWidgetEditData->item(i, ZERO));
        SETTABLECENTER(ui->tableWidgetEditData->item(i, ONE));
    }
    ui->tableWidgetEditData->scrollToBottom();
}
