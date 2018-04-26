#include "addcommodity.h"
#include "ui_addcommodity.h"
#include "httpclient/httpkey.h"

/************************   构造函数         ************************/
AddCommodity::AddCommodity(QWidget *parent) :
    QWidget(parent),ui(new Ui::AddCommodity)
  ,serachFlage(false)
{
    ui->setupUi(this);
    this->initControl();
}

/************************   析构函数         ************************/
AddCommodity::~AddCommodity()
{
    delete ui;
}

/************************   显示窗口         ************************/
void AddCommodity::showWidget(int type)
{
    widgetType = type;
    serachFlage = false;
    if(type == ADDCOMMODITY)
    {
        titleBar->setTitle(GLOBALDEF::ADDCOMMODITY);
        ui->tableWidgetData->setHidden(true);
        ui->treeWidgetData->show();
        ui->lineEditSearch->show();
        ui->pushButtonSearch->show();
    }
    else
    {
        titleBar->setTitle(GLOBALDEF::ADDCOMMODITYTYPE);
        ui->treeWidgetData->setHidden(true);
        ui->lineEditSearch->setHidden(true);
        ui->pushButtonSearch->setHidden(true);
        ui->tableWidgetData->show();
    }

    ui->checkBoxSelect->setChecked(false);
    ui->checkBoxSelect->setText(tr("全选"));
    ui->checkBoxSelect->setIcon(QIcon(GLOBALDEF::ALLSELECTIMAGE));

    this->show();
}

/************************   初始化控件        ************************/
void AddCommodity::initControl()
{
    titleBar = new TitleBar(this);

    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    SETTABLEWIDGET(ui->tableWidgetData);

    ui->tableWidgetData->horizontalHeader()->setHidden(true);

    //设置为不可编辑
    ui->treeWidgetData->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //设置表头点击禁止塌陷
    ui->treeWidgetData->header()->setHighlightSections(false);

    //设置双击不收缩
    ui->treeWidgetData->setExpandsOnDoubleClick(false);

    //表头隐藏
    ui->treeWidgetData->header()->setHidden(true);

    //去除点击的虚线
    ui->tableWidgetData->setFocusPolicy(Qt::NoFocus);
    ui->treeWidgetData->setFocusPolicy(Qt::NoFocus);
}

/************************   改变事件          ************************/
void AddCommodity::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/************************   通过Item找ID     ************************/
QString AddCommodity::findIdByItem(QTreeWidgetItem *item)
{
    auto iter = mapItemList.find(item);

    if(iter != mapItemList.end()) return iter.value();

    return NULL;
}

/************************   获取未选中映射   ************************/
Map AddCommodity::getTreeItemNotSelectMap() const
{
    return treeItemNotSelectMap;
}

/************************   获取表格选中映射   ************************/
void AddCommodity::setTableItemSelectMap(const Map &value)
{
    tableItemSelectMap = value;
}

/************************   获取树形选中映射   ************************/
Map AddCommodity::getTreeItemSelectMap() const
{
    return treeItemSelectMap;
}

/************************   设置树形映射      ************************/
void AddCommodity::setTreeItemSelectMap(const Map &value)
{
    treeItemSelectMap = value;
}

/************************   清空信息         ************************/
void AddCommodity::clearInfo()
{
    tableItemSelectMap.clear();
    treeItemSelectMap.clear();
}

/************************   获取表格选中列表  ************************/
Map AddCommodity::getTableItemSelectMap() const
{
    return tableItemSelectMap;
}

/************************   获取商品分类列表  ************************/
MapList AddCommodity::getMapFoodCategoryList() const
{
    return mapFoodCategoryList;
}

/************************   获取商品列表     ************************/
MapList AddCommodity::getMapFoodList() const
{
    return mapFoodList;
}

/************************   设置商品列表     ************************/
void AddCommodity::setMapFoodList(const MapList &value)
{
    mapFoodList = value;

    ui->treeWidgetData->clear();

    for(int i = 0; i < mapFoodList.size(); i ++)
    {
        if(mapFoodList.at(i).value(HTTPKEY::LEVEL) == "0")
        {
            QTreeWidgetItem* parentItem = TREEDATA(ui->treeWidgetData);

            parentItem->setText(0, mapFoodList.at(i).value(HTTPKEY::FOODNAME));

            for(int j = 0; j < mapFoodList.size(); j ++)
            {
                if(mapFoodList.at(j).value(HTTPKEY::PID) == mapFoodList.at(i).value(HTTPKEY::FOODID))
                {
                    QTreeWidgetItem* childItem = TREEITEM();
                    parentItem->addChild(childItem);

                    childItem->setText(0, mapFoodList.at(j).value(HTTPKEY::FOODNAME));
                    childItem->setCheckState(0, Qt::Unchecked);

                    if(NULL != childItem) mapItemList[childItem] = mapFoodList.at(j).value(HTTPKEY::FOODID);
                }
            }
        }
    }

    for(auto iterItem = mapItemList.begin(); iterItem != mapItemList.end(); iterItem ++)
    {
        for(auto iter = treeItemSelectMap.begin(); iter != treeItemSelectMap.end(); iter ++)
        {
            if(NULL == iter.key() || NULL == iterItem.value()) continue;
            if(iter.key() == iterItem.value())
            {
                for(int i = 0; i < ui->treeWidgetData->topLevelItemCount(); i ++)
                {
                    QTreeWidgetItem* parentItem = ui->treeWidgetData->topLevelItem(i);

                    for(int i = 0; i < parentItem->childCount(); i ++)
                    {
                        if(iter.value() == parentItem->child(i)->text(0))
                        {
                            parentItem->child(i)->setCheckState(0, Qt::Checked);
                        }
                    }
                }
            }
        }
    }

    ui->treeWidgetData->expandAll();
}

/************************   设置商品分类列表 ************************/
void AddCommodity::setMapFoodCategoryList(const MapList &value)
{
    mapFoodCategoryList = value;

    ui->tableWidgetData->clear();
    ui->tableWidgetData->setRowCount(mapFoodCategoryList.size());
    for(int i = 0; i < mapFoodCategoryList.size(); i ++)
    {
        ui->tableWidgetData->setItem(i, 0, DATA(mapFoodCategoryList.at(i).value(HTTPKEY::FOODCATEGORYNAME)));
        ui->tableWidgetData->item(i, 0)->setCheckState(Qt::Unchecked);
        SETTABLECENTER(ui->tableWidgetData->item(i, 0));
    }

    for(auto iter = tableItemSelectMap.begin(); iter != tableItemSelectMap.end(); iter ++)
    {
        for(int i = 0; i < mapFoodCategoryList.size(); i ++)
        {
            if(iter.value() == mapFoodCategoryList.at(i).value(HTTPKEY::FOODCATEGORYNAME))
            {
                ui->tableWidgetData->item(i, 0)->setCheckState(Qt::Checked);
                SETTABLECENTER(ui->tableWidgetData->item(i, 0));
            }
        }
    }
}

/************************   保存           ************************/
void AddCommodity::on_pushButtonSave_clicked()
{
    if(widgetType == ADDCOMMODITY)
    {
        if(!serachFlage) treeItemSelectMap.clear();
        for(int i = 0; i < ui->treeWidgetData->topLevelItemCount(); i ++)
        {
            QTreeWidgetItem* parentItem = ui->treeWidgetData->topLevelItem(i);

            for(int j = 0; j < parentItem->childCount(); j ++)
            {
                QString itemId = findIdByItem(parentItem->child(j));
                if(parentItem->child(j)->checkState(0) == Qt::Checked)
                {
                    if(!itemId.isEmpty()) treeItemSelectMap[itemId] = parentItem->child(j)->text(0);
                }
                else
                {
                    if(!itemId.isEmpty()) treeItemNotSelectMap[itemId] = parentItem->child(j)->text(0);
                }
            }
        }
        emit sendAdd();
    }
    else
    {
        tableItemSelectMap.clear();
        for(int i = 0; i < ui->tableWidgetData->rowCount(); i ++)
        {
            if(ui->tableWidgetData->item(i,0)->checkState() == Qt::Checked)
            {
                tableItemSelectMap[mapFoodCategoryList.at(i).value(HTTPKEY::FOODCATEGORYID)] = ui->tableWidgetData->item(i,0)->text();
            }
        }
        emit sendType();
    }

    this->close();
}

/************************   取消           ************************/
void AddCommodity::on_pushButtonCancel_clicked()
{
    this->close();
}

/************************   搜索           ************************/
void AddCommodity::on_pushButtonSearch_clicked()
{
    serachFlage = true;
    QByteArray byteArray;
    byteArray.append(POSTARG::WAREHOUSESEARCH.arg(ui->lineEditSearch->text()));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_WARHOS_SEARCH), byteArray, PROTOCOL::URL_WARHOS_SEARCH);
}

/************************   设置商品列表     ************************/
void AddCommodity::setFoodList(const MapList &value)
{
    foodList = value;

    ui->treeWidgetData->clear();

    for(int j = 0; j < mapFoodList.size(); j ++)
    {
        if(mapFoodList.at(j).value(HTTPKEY::LEVEL) == "0")
        {
            QTreeWidgetItem* parentItem = TREEDATA(ui->treeWidgetData);

            parentItem->setText(0, mapFoodList.at(j).value(HTTPKEY::FOODNAME));
            for(int i = 0; i < foodList.size(); i ++)
            {
                for(int k = 0; k < mapFoodList.size(); k ++)
                {
                    if(foodList.at(i).value(HTTPKEY::FOODID) == mapFoodList.at(k).value(HTTPKEY::FOODID))
                    {
                        if(mapFoodList.at(k).value(HTTPKEY::PID) == mapFoodList.at(j).value(HTTPKEY::FOODID))
                        {
                            QTreeWidgetItem* childItem = TREEITEM();
                            parentItem->addChild(childItem);

                            childItem->setText(0, mapFoodList.at(k).value(HTTPKEY::FOODNAME));
                            childItem->setCheckState(0, Qt::Unchecked);

                            if(NULL != childItem) mapItemList[childItem] = mapFoodList.at(k).value(HTTPKEY::FOODID);
                        }
                    }
                }
            }

            if(parentItem->childCount() <= 0) SAFEDELETE(parentItem);
        }
    }

    ui->treeWidgetData->expandAll();
}

/************************    单击表格控件    ************************/
void AddCommodity::on_tableWidgetData_clicked(const QModelIndex &index)
{
    if(NULL == ui->tableWidgetData->currentItem()) return;

    if(index.row() != ui->tableWidgetData->currentItem()->row()) return;

    if(ui->tableWidgetData->currentItem()->checkState() == Qt::Checked)
    {
        ui->tableWidgetData->currentItem()->setCheckState(Qt::Unchecked);
    }
    else
    {
        ui->tableWidgetData->currentItem()->setCheckState(Qt::Checked);
    }
}

/************************   单击树形控件     ************************/
void AddCommodity::on_treeWidgetData_clicked(const QModelIndex &index)
{
    if(NULL == ui->treeWidgetData->currentItem()) return;
    if(NULL == ui->treeWidgetData->currentItem()->parent()) return;

    if(ui->treeWidgetData->currentItem()->text(0) != index.data().toString())
    {
        return;
    }

    Qt::CheckState checkState = ui->treeWidgetData->currentItem()->checkState(0);

    checkState = checkState == Qt::Checked ? Qt::Unchecked : Qt::Checked;

    QString idText = findIdByItem(ui->treeWidgetData->currentItem());
    for(int i = 0; i < ui->treeWidgetData->topLevelItemCount(); i ++)
    {
        QTreeWidgetItem* parentItem = ui->treeWidgetData->topLevelItem(i);

        for(int i = 0; i < parentItem->childCount(); i ++)
        {
            if(idText == findIdByItem(parentItem->child(i)))
            {
                parentItem->child(i)->setCheckState(0, checkState);
            }
        }
    }
}

/************************   选择     ************************/
void AddCommodity::on_checkBoxSelect_clicked()
{
    bool checkFlage = ui->checkBoxSelect->isChecked();

    if(checkFlage)
    {
        ui->checkBoxSelect->setText(tr("全不选"));
        ui->checkBoxSelect->setIcon(QIcon(GLOBALDEF::NOTSELECTIMAGE));
    }
    else
    {
        ui->checkBoxSelect->setText(tr("全选"));
        ui->checkBoxSelect->setIcon(QIcon(GLOBALDEF::ALLSELECTIMAGE));
    }

    Qt::CheckState checkState = ui->checkBoxSelect->isChecked() ? Qt::Checked : Qt::Unchecked;

    if(widgetType == ADDCOMMODITY)
    {
        for(int i = 0; i < ui->treeWidgetData->topLevelItemCount(); i ++)
        {
            QTreeWidgetItem* parentItem = ui->treeWidgetData->topLevelItem(i);

            for(int i = 0; i < parentItem->childCount(); i ++)
            {
                parentItem->child(i)->setCheckState(0, checkState);
            }
        }
    }
    else
    {
        for(int i = 0; i < ui->tableWidgetData->rowCount(); i ++)
        {
            ui->tableWidgetData->item(i, 0)->setCheckState(checkState);
        }
    }

    ui->tableWidgetData->setFocusPolicy(Qt::NoFocus);
    ui->treeWidgetData->setFocusPolicy(Qt::NoFocus);
}
