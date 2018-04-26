#include "addtranmaterial.h"
#include "ui_addtranmaterial.h"
#include "httpclient/httpkey.h"

/*********************  构造函数       *********************/
AddTranMaterial::AddTranMaterial(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addtranmaterial)
  ,titleBar(NULL)
  ,widgetType(0)
{
    ui->setupUi(this);
    this->initControl();
}

/*********************  析构函数       *********************/
AddTranMaterial::~AddTranMaterial()
{
    delete ui;

    SAFEDELETE(titleBar);
}

/*********************  显示窗口       *********************/
void AddTranMaterial::showWidget(int type)
{
    if(type == EDITTYPE)
    {
        titleBar->setTitle(GLOBALDEF::EDITSTOMATERIAL);
        ui->checkBoxAllSelect->setHidden(true);
        ui->pushButtonDel->show();
        ui->tableWidgetEditData->show();
        ui->tableWidgetData->setHidden(true);
    }
    else
    {
        titleBar->setTitle(GLOBALDEF::ADDMATERIALNAME);

        ui->tableWidgetEditData->setHidden(true);
        ui->tableWidgetData->show();
        ui->checkBoxAllSelect->show();
        ui->pushButtonDel->setHidden(true);
    }

    ui->checkBoxAllSelect->setChecked(false);
    ui->checkBoxAllSelect->setText(tr("全选"));
    ui->checkBoxAllSelect->setIcon(QIcon(GLOBALDEF::ALLSELECTIMAGE));

    widgetType = type;
    this->show();
}

/*********************  初始化控件       *********************/
void AddTranMaterial::initControl()
{
    titleBar = new TitleBar(this);
    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    SETTABLEWIDGET(ui->tableWidgetData);
    SETTABLEWIDGET(ui->tableWidgetEditData);
}

/*********************  改变事件        *********************/
void AddTranMaterial::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  获取原料数据        *********************/
MapList AddTranMaterial::getMapMatList() const
{
    return mapMatList;
}

/*********************  设置数据列表        *********************/
void AddTranMaterial::setMapMatList(const MapList &value)
{
    mapMatList = value;

    for(int i = 0; i < spinBoxList.size(); i ++)
    {
        SAFEDELETE(spinBoxList[i]);
    }

    spinBoxList.clear();

    ui->tableWidgetData->clearContents();
    ui->tableWidgetData->setRowCount(mapMatList.size());

    for(int i = 0; i < mapMatList.size(); i ++)
    {
        ui->tableWidgetData->setItem(i, ZERO, DATA(mapMatList.at(i).value(HTTPKEY::NAME)));
        ui->tableWidgetData->setItem(i, ONE, DATA(mapMatList.at(i).value(HTTPKEY::BARCODE)));
        ui->tableWidgetData->item(i, 0)->setCheckState(Qt::Unchecked);
        ui->tableWidgetData->setItem(i, TWO, DATA(mapMatList.at(i).value(HTTPKEY::COSTPRICE)));
        {
            QWidget * widget = new QWidget(this);
            QHBoxLayout *hBoxLayout =  new QHBoxLayout(widget);
            QDoubleSpinBox *spinBox = new QDoubleSpinBox(this);

            hBoxLayout->addWidget(spinBox);
            widget->setLayout(hBoxLayout);
            spinBox->setValue(ONE);
            hBoxLayout->setMargin(0);
            spinBox->setFixedSize(ui->tableWidgetData->columnWidth(THREE), ui->tableWidgetData->rowHeight(ZERO));
            spinBox->setFocusPolicy(Qt::NoFocus);

            ui->tableWidgetData->setCellWidget(i, THREE, widget);

            spinBoxList.append(spinBox);
        }

        ui->tableWidgetData->setItem(i, FOUR, DATA(tr("元/") + mapMatList.at(i).value(HTTPKEY::UNITNAME)));

        SETTABLECENTER(ui->tableWidgetData->item(i, ZERO));
        SETTABLECENTER(ui->tableWidgetData->item(i, ONE));
        SETTABLECENTER(ui->tableWidgetData->item(i, TWO));
        SETTABLECENTER(ui->tableWidgetData->item(i, FOUR));

    }
    ui->tableWidgetData->scrollToBottom();
}

/*********************  保存事件        *********************/
void AddTranMaterial::on_pushButtonSave_clicked()
{
    MapList mapListData;
    QByteArray byteArray;

    if(widgetType == EDITTYPE)
    {
        for(int i = 0; i < mapSelectList.size(); i ++)
        {
            Map mapData;

            if(i < spinBoxList.size())
            {
                if(spinBoxList.at(i)->value() <= 0) return;
                mapData[HTTPKEY::NUMBER] = QString::number(spinBoxList.at(i)->value());
            }

            mapData[HTTPKEY::ALLOTMATERIALID]  = mapSelectList.at(i).value(HTTPKEY::ALLOTMATERIALID);

            mapListData.append(mapData);
        }

        if(delListData.size() != 0)
        {
            byteArray.append(POSTARG::UPDATEALLMAT.arg(HTTPCLIENT->makeJson(delListData), HTTPCLIENT->makeJson(mapListData)));
        }
        else
        {
            byteArray.append(POSTARG::UPDATETRANMAT.arg(HTTPCLIENT->makeJson(mapListData)));
        }

        HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_ALLOT_UPDATE_ALL_MAT), byteArray, PROTOCOL::URL_ALLOT_UPDATE_ALL_MAT);
    }
    else
    {
        for(int i = ui->tableWidgetData->rowCount() - 1; i >= 0  ; i --)
        {
            if(ui->tableWidgetData->item(i, 0)->checkState() == Qt::Unchecked)
            {
                mapMatList.removeAt(i);
            }
            else
            {
                Map mapData;

                if(i < spinBoxList.size())
                {
                    if(spinBoxList.at(i)->value() <= 0) return;
                    mapData[HTTPKEY::NUMBER] = QString::number(spinBoxList.at(i)->value());
                }

                mapData[HTTPKEY::MATERIALID]     = mapMatList.at(i).value(HTTPKEY::MATERIALID);
                mapData[HTTPKEY::ALLOTNUMBER]    = mapMatList.at(i).value(HTTPKEY::ALLOTNUMBER);
                mapData[HTTPKEY::UNITID]         = mapMatList.at(i).value(HTTPKEY::UNITID);
                mapData[HTTPKEY::STOREID]        = mapMatList.at(i).value(HTTPKEY::STOREID);
                mapData[HTTPKEY::COSTPRICE]      = mapMatList.at(i).value(HTTPKEY::COSTPRICE);

                mapListData.append(mapData);
            }
        }

        QString strPost = POSTARG::ADDTRANMAT.arg(HTTPCLIENT->makeJson(mapListData));

        byteArray.append(strPost);

        HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_ALLOT_ADD_MAT), byteArray, PROTOCOL::URL_ALLOT_ADD_MAT);
    }
    this->close();
}

/*********************  取消事件        *********************/
void AddTranMaterial::on_pushButtonCancel_clicked()
{
    this->close();
}

/*********************  单击选中        *********************/
void AddTranMaterial::on_tableWidgetData_clicked(const QModelIndex &index)
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
void AddTranMaterial::setMapSelectList(const MapList &value)
{
    mapSelectList = value;
    delListData.clear();

    setTableEidiData();
}

/************************   获取选择的列表       ********************/
MapList AddTranMaterial::getMapSelectList() const
{
    return mapSelectList;
}

/************************   删除数据            ********************/
void AddTranMaterial::on_pushButtonDel_clicked()
{
    if(NULL == ui->tableWidgetEditData->currentItem()) return;
    if(ui->tableWidgetEditData->currentRow() >= mapSelectList.size()) return;
    int currentRow = ui->tableWidgetEditData->currentRow();

    delListData.append(mapSelectList.at(currentRow).value(HTTPKEY::ALLOTMATERIALID));
    mapSelectList.removeAt(ui->tableWidgetEditData->currentRow());

    if(currentRow < spinBoxList.size())
    {
        SAFEDELETE(spinBoxList[currentRow])
    }

    spinBoxList.removeAt(currentRow);

    ui->tableWidgetEditData->removeRow(currentRow);
}

/************************   设置表格数据         ********************/
void AddTranMaterial::setTableEidiData()
{
    for(int i = 0; i < spinBoxList.size(); i ++)
    {
        SAFEDELETE(spinBoxList[i]);
    }

    spinBoxList.clear();

    ui->tableWidgetEditData->clearContents();
    ui->tableWidgetEditData->setRowCount(mapSelectList.size());

    for(int i = 0; i < mapSelectList.size(); i ++)
    {
        ui->tableWidgetEditData->setItem(i, ZERO, DATA(mapSelectList.at(i).value(HTTPKEY::MATERIALNAME)));
        ui->tableWidgetEditData->setItem(i, ONE, DATA(mapSelectList.at(i).value(HTTPKEY::BARCODE)));
        ui->tableWidgetEditData->setItem(i, TWO, DATA(mapSelectList.at(i).value(HTTPKEY::COSTPRICE)));
        {
            QWidget * widget = new QWidget(this);
            QHBoxLayout *hBoxLayout =  new QHBoxLayout(widget);
            QDoubleSpinBox *spinBox = new QDoubleSpinBox(this);

            hBoxLayout->addWidget(spinBox);
            widget->setLayout(hBoxLayout);
            spinBox->setValue(mapSelectList.at(i).value(HTTPKEY::NUMBER).toDouble());
            hBoxLayout->setMargin(0);
            spinBox->setFixedSize(ui->tableWidgetEditData->columnWidth(THREE), ui->tableWidgetEditData->rowHeight(ZERO));
            spinBox->setFocusPolicy(Qt::NoFocus);

            ui->tableWidgetEditData->setCellWidget(i, THREE, widget);

            spinBoxList.append(spinBox);
        }

        ui->tableWidgetEditData->setItem(i, FOUR, DATA(tr("元/") + mapSelectList.at(i).value(HTTPKEY::UNITNAME)));

        SETTABLECENTER(ui->tableWidgetEditData->item(i, ZERO));
        SETTABLECENTER(ui->tableWidgetEditData->item(i, ONE));
        SETTABLECENTER(ui->tableWidgetEditData->item(i, TWO));
        SETTABLECENTER(ui->tableWidgetEditData->item(i, FOUR));
    }
    ui->tableWidgetEditData->scrollToBottom();
}

/************************   选择         ********************/
void AddTranMaterial::on_checkBoxAllSelect_clicked()
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
