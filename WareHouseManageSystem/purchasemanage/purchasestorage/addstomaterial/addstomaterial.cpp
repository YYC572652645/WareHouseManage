#include "addstomaterial.h"
#include "ui_addstomaterial.h"
#include "httpclient/httpkey.h"

/*********************  构造函数       *********************/
AddStoMaterial::AddStoMaterial(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addstomaterial)
   ,widgetType(0)
{
    ui->setupUi(this);
    this->initControl();
}

/*********************  析构函数       *********************/
AddStoMaterial::~AddStoMaterial()
{
    delete ui;
}

/*********************  清空信息       *********************/
void AddStoMaterial::clearInfo()
{
    ui->tableWidgetData->clearContents();
    ui->tableWidgetData->setRowCount(0);
    mapMatList.clear();
}

/*********************  显示窗口       *********************/
void AddStoMaterial::showWidget(int type)
{
    if(type == EDITTYPE)
    {
        titleBar->setTitle(GLOBALDEF::EDITSTOMATERIAL);
        ui->checkBoxAllSelect->setHidden(true);
        ui->pushButtonDel->show();
        ui->tableWidgetEditData->show();
        ui->tableWidgetData->setHidden(true);
        ui->pushButtonSave->setHidden(true);
        ui->pushButtonCancel->setHidden(true);
    }
    else
    {
        titleBar->setTitle(GLOBALDEF::ADDSTOMATERIAL);

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
void AddStoMaterial::initControl()
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
void AddStoMaterial::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  设置数据        *********************/
Map AddStoMaterial::getMapData() const
{
    return mapData;
}

/*********************  获取数据        *********************/
void AddStoMaterial::setMapData(const Map &value)
{
    mapData = value;
}

/*********************  获取原料数据        *********************/
MapList AddStoMaterial::getMapMatList() const
{
    return mapMatList;
}

/*********************  设置数据列表        *********************/
void AddStoMaterial::setMapMatList(const MapList &value)
{
    mapMatList = value;

    ui->tableWidgetData->clearContents();
    ui->tableWidgetData->setRowCount(mapMatList.size());

    for(int i = 0; i < mapMatList.size(); i ++)
    {
        ui->tableWidgetData->setItem(i, ZERO, DATA(mapMatList.at(i).value(HTTPKEY::MATERIALNAME)));
        ui->tableWidgetData->setItem(i, ONE,  DATA(mapMatList.at(i).value(HTTPKEY::BARCODE)));
        ui->tableWidgetData->item(i, ZERO)->setCheckState(Qt::Unchecked);

        SETTABLECENTER(ui->tableWidgetData->item(i, ZERO));
        SETTABLECENTER(ui->tableWidgetData->item(i, ONE));
    }
    ui->tableWidgetData->scrollToBottom();
}

/*********************  保存事件        *********************/
void AddStoMaterial::on_pushButtonSave_clicked()
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

    QByteArray byteArray;

    QString strPost = POSTARG::STOADDMAT.arg(HTTPCLIENT->makeJson(listId), mapData.value(HTTPKEY::STORAGENUMBER));

    strPost = strPost.arg(mapData.value(HTTPKEY::SUPPLIERID), mapData.value(HTTPKEY::WAREHOUSEID), storageState);

    byteArray.append(strPost);

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_STO_ADD_MAT), byteArray, PROTOCOL::URL_STO_ADD_MAT);

    this->close();
}

/*********************  取消事件        *********************/
void AddStoMaterial::on_pushButtonCancel_clicked()
{
    this->close();
}

/*********************  单击选中        *********************/
void AddStoMaterial::on_tableWidgetData_clicked(const QModelIndex &index)
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

/************************   设置数据       ********************/
void AddStoMaterial::setMapSelectList(const MapList &value)
{
    mapSelectList = value;

    setTableEidiData();
}

/************************   获取选择的列表       ********************/
MapList AddStoMaterial::getMapSelectList() const
{
    return mapSelectList;
}

/************************   删除数据            ********************/
void AddStoMaterial::on_pushButtonDel_clicked()
{
    if(NULL == ui->tableWidgetEditData->currentItem()) return;

    List listId;
    for(int i = 0; i < ui->tableWidgetEditData->selectedItems().size(); i ++)
    {
        if(i % ui->tableWidgetEditData->columnCount())
        {
            int currentRow = ui->tableWidgetEditData->selectedItems().at(i)->row();

            listId.append(mapSelectList.at(currentRow).value(HTTPKEY::STORAGEMATTERIALID));
        }
    }

    QByteArray byteArray;
    byteArray.append(POSTARG::STODELMAT.arg(HTTPCLIENT->makeJson(listId)));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_STO_DEL_MAT), byteArray, PROTOCOL::URL_STO_DEL_MAT);

    this->close();
}


/************************   设置状态         ********************/
void AddStoMaterial::setStorageState(const QString &value)
{
    storageState = value;
}

/************************   设置表格数据         ********************/
void AddStoMaterial::setTableEidiData()
{
    ui->tableWidgetEditData->clearContents();
    ui->tableWidgetEditData->setRowCount(mapSelectList.size());

    for(int i = 0; i < mapSelectList.size(); i ++)
    {
        ui->tableWidgetEditData->setItem(i, 0, DATA(mapSelectList.at(i).value(HTTPKEY::MATERIALNAME)));
        ui->tableWidgetEditData->setItem(i, 1, DATA(mapSelectList.at(i).value(HTTPKEY::BARCODE)));
        SETTABLECENTER(ui->tableWidgetEditData->item(i, 0));
        SETTABLECENTER(ui->tableWidgetEditData->item(i, ONE));
    }
    ui->tableWidgetEditData->scrollToBottom();
}

/************************   选择         ********************/
void AddStoMaterial::on_checkBoxAllSelect_clicked()
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
