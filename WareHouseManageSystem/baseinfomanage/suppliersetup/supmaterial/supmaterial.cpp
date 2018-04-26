#include "supmaterial.h"
#include "ui_supmaterial.h"
#include "httpclient/httpkey.h"

/*********************  构造函数            *********************/
SupMaterial::SupMaterial(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SupMaterial)
{
    ui->setupUi(this);

    this->initControl();
}

/*********************  析构函数           *********************/
SupMaterial::~SupMaterial()
{
    delete ui;
}

/*********************  显示窗口           *********************/
void SupMaterial::showWidget()
{
    titleBar->setTitle(GLOBALDEF::SUPMATERIAL);
    ui->groupBoxSelect->hide();
    ui->tableWidget->clearContents();
    this->show();
}

/*********************  清空数据           *********************/
void SupMaterial::setClear(bool falge)
{
    if(falge)
    {
        ui->tableWidget->clearContents();
        ui->tableWidget->setRowCount(0);
        materialMapList.clear();
    }
    else
    {
        ui->tableWidgetAllMaterial->clearContents();
        ui->tableWidgetAllMaterial->setRowCount(0);
        allMaterialMapList.clear();
    }
}

/*********************  初始化控件          *********************/
void SupMaterial::initControl()
{
    titleBar = new TitleBar(this);
    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    SETTABLEWIDGET(ui->tableWidget);
    SETTABLEWIDGET(ui->tableWidgetAllMaterial);

    ui->tableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
}

/*********************  改变事件            *********************/
void SupMaterial::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  获取原料ID          *********************/
QString SupMaterial::getSupplierId() const
{
    return supplierId;
}

/*********************  设置供应商ID         *********************/
void SupMaterial::setSupplierId(const QString &value)
{
    supplierId = value;
}

/*********************  设置所有原料列表      *********************/
void SupMaterial::setAllMaterialMapList(const MapList &value)
{
    allMaterialMapList = value;
}

/*********************  设置原料分类列表      *********************/
void SupMaterial::setCatMapList(const MapList &value)
{
    catMapList = value;
}

/*********************  设置原料列表         *********************/
void SupMaterial::setMaterialMapList(const MapList &value)
{
    materialMapList = value;
}

/*********************  设置表格数据         *********************/
void SupMaterial::setTableMatData()
{
    ui->tableWidget->setRowCount(materialMapList.size());

    emit sendCount(materialMapList.size());

    for(int i = 0; i < materialMapList.size(); i ++)
    {
        ui->tableWidget->setItem(i, ZERO, DATA(materialMapList.at(i).value(HTTPKEY::NAME)));
        ui->tableWidget->setItem(i, ONE, DATA(materialMapList.at(i).value(HTTPKEY::BARCODE)));

        for(int j = 0; j < catMapList.size(); j++)
        {
            if(materialMapList.at(i).value(HTTPKEY::CATEGORYID) == catMapList.at(j).value(HTTPKEY::CATEGORYID))
            {
                ui->tableWidget->setItem(i, TWO, DATA(catMapList.at(j).value(HTTPKEY::NAME)));
            }
        }

        SETTABLECENTER(ui->tableWidget->item(i, ZERO));
        SETTABLECENTER(ui->tableWidget->item(i, ONE));
        SETTABLECENTER(ui->tableWidget->item(i, TWO));
    }
    ui->tableWidget->scrollToBottom();

    ui->tableWidget->selectRow(ui->tableWidget->rowCount() - 1);
}

/*********************  设置可供选择原料数据  *********************/
void SupMaterial::setAllTableMatData()
{
    ui->tableWidgetAllMaterial->setRowCount(allMaterialMapList.size());

    for(int i = 0; i < allMaterialMapList.size(); i ++)
    {
        ui->tableWidgetAllMaterial->setItem(i, ZERO, DATA(allMaterialMapList.at(i).value(HTTPKEY::NAME)));
        ui->tableWidgetAllMaterial->setItem(i, ONE,  DATA(allMaterialMapList.at(i).value(HTTPKEY::BARCODE)));

        ui->tableWidgetAllMaterial->item(i, ZERO)->setCheckState(Qt::Unchecked);

        SETTABLECENTER(ui->tableWidgetAllMaterial->item(i, ZERO));
        SETTABLECENTER(ui->tableWidgetAllMaterial->item(i, ONE));
    }
    ui->tableWidgetAllMaterial->scrollToBottom();
}

/*********************  保存按钮            *********************/
void SupMaterial::on_pushButtonSave_clicked()
{
    List listData;
    for(int i = 0; i < ui->tableWidgetAllMaterial->rowCount(); i ++)
    {
        if(ui->tableWidgetAllMaterial->item(i, 0)->checkState() == Qt::Checked)
        {
            listData.append(allMaterialMapList.at(i).value(HTTPKEY::MATERIALID));
        }
    }
    if(listData.isEmpty()) return;

    QByteArray byteArray;
    byteArray.append(POSTARG::ADDSUPMATERIAL.arg(makeJson(listData), supplierId));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_SUP_ADD_SUP_MAT), byteArray, PROTOCOL::URL_SUP_ADD_SUP_MAT);
    ui->groupBoxSelect->hide();
}

/*********************  取消按钮            *********************/
void SupMaterial::on_pushButtonCancel_clicked()
{
    ui->groupBoxSelect->hide();
}

/*********************  添加按钮            *********************/
void SupMaterial::on_pushButtonAdd_clicked()
{
    ui->groupBoxSelect->show();
    ui->tableWidgetAllMaterial->clearContents();

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_SUP_GET_MATERIAL).arg(supplierId), PROTOCOL::URL_SUP_GET_MATERIAL);
}

/*********************  点击选中            *********************/
void SupMaterial::on_tableWidgetAllMaterial_clicked(const QModelIndex &index)
{
    if(NULL == ui->tableWidgetAllMaterial->item(index.row(), 0)) return;

    if( ui->tableWidgetAllMaterial->item(index.row(), 0)->checkState() == Qt::Checked)
    {
        ui->tableWidgetAllMaterial->item(index.row(), 0)->setCheckState(Qt::Unchecked);
    }
    else
    {
        ui->tableWidgetAllMaterial->item(index.row(), 0)->setCheckState(Qt::Checked);
    }
}

/*********************  组合json           *********************/
QString SupMaterial::makeJson(List listData)
{
    QJsonObject jsonTotal;
    QJsonObject jsonData;

    for(int i = 0; i < listData.size(); i ++)
    {
        jsonData.insert(QString::number(i), listData.at(i));
    }

    jsonTotal.insert("listId", jsonData);

    QJsonDocument document;
    document.setObject(jsonTotal);

    return document.toJson();
}

/*********************  删除               *********************/
void SupMaterial::on_pushButtonDel_clicked()
{
    if(NULL == ui->tableWidget->currentItem()) return;

    List listData;
    for(int i = 0; i < ui->tableWidget->selectedItems().size(); i ++)
    {
        if(i % ui->tableWidget->columnCount() == 0)
        {
            int currentRow = ui->tableWidget->selectedItems().at(i)->row();

            if(currentRow >= materialMapList.size()) continue;

            listData.append(materialMapList.at(currentRow).value(HTTPKEY::MATERIALID));
        }
    }

    QByteArray byteArray;
    byteArray.append(POSTARG::DELSUPMATERIAL.arg(makeJson(listData), supplierId));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_SUP_DEL_SUP_MAT), byteArray, PROTOCOL::URL_SUP_DEL_SUP_MAT);
    ui->groupBoxSelect->hide();
}
