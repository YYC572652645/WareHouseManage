#include "edittemplate.h"
#include "ui_edittemplate.h"
#include "httpclient/httpkey.h"

/*********************  构造函数       *********************/
EditTemplate::EditTemplate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditTemplate)
{
    ui->setupUi(this);
    this->initControl();
}

/*********************  析构函数       *********************/
EditTemplate::~EditTemplate()
{
    delete ui;
}

/*********************  显示窗口       *********************/
void EditTemplate::showWidget()
{
    titleBar->setTitle(GLOBALDEF::ADDTEMMATERIAL);

    ui->tableWidgetData->show();
    ui->pushButtonSave->show();
    ui->pushButtonCancel->show();

    ui->checkBoxAllSelect->setChecked(false);
    ui->checkBoxAllSelect->setText(tr("全选"));
    ui->checkBoxAllSelect->setIcon(QIcon(GLOBALDEF::ALLSELECTIMAGE));

    this->show();
}

/*********************  初始化控件       *********************/
void EditTemplate::initControl()
{
    titleBar = new TitleBar(this);
    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    SETTABLEWIDGET(ui->tableWidgetData);
}

/*********************  改变事件        *********************/
void EditTemplate::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  获取原料数据        *********************/
MapList EditTemplate::getMapMatList() const
{
    return mapMatList;
}

/*********************  设置数据列表        *********************/
void EditTemplate::setMapMatList(const MapList &value)
{
    mapMatList = value;

    for(int i = mapMatList.size() - 1; i >= 0; i --)
    {
        for(int j = 0; j < mapSelectList.size(); j ++)
        {
            if(mapMatList.at(i).value(HTTPKEY::MATERIALID) == mapSelectList.at(j).value(HTTPKEY::MATERIALID))
            {
                mapMatList.removeAt(i);
            }
        }
    }

    ui->tableWidgetData->clearContents();
    ui->tableWidgetData->setRowCount(mapMatList.size());

    for(int i = 0; i < mapMatList.size(); i ++)
    {
        ui->tableWidgetData->setItem(i, ZERO, DATA(mapMatList.at(i).value(HTTPKEY::NAME)));
        ui->tableWidgetData->setItem(i, ONE,  DATA(mapMatList.at(i).value(HTTPKEY::BARCODE)));
        ui->tableWidgetData->item(i, ZERO)->setCheckState(Qt::Unchecked);
        SETTABLECENTER(ui->tableWidgetData->item(i, ZERO));
        SETTABLECENTER(ui->tableWidgetData->item(i, ONE));
    }
    ui->tableWidgetData->scrollToBottom();
}

/*********************  保存事件        *********************/
void EditTemplate::on_pushButtonSave_clicked()
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
    byteArray.append(POSTARG::TEMADDMATERIAL.arg(templateId, HTTPCLIENT->makeJson(listId)));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_TEM_ADD_MAT), byteArray, PROTOCOL::URL_TEM_ADD_MAT);

    this->close();
}

/*********************  取消事件        *********************/
void EditTemplate::on_pushButtonCancel_clicked()
{
    this->close();
}

/*********************  单击选中        *********************/
void EditTemplate::on_tableWidgetData_clicked(const QModelIndex &index)
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

/************************   设置选中原料       ********************/
void EditTemplate::setMapSelectList(const MapList &value)
{
    mapSelectList = value;
}

/************************   获取选择的列表       ********************/
MapList EditTemplate::getMapSelectList() const
{
    return mapSelectList;
}

/************************   设置模板ID         ********************/
void EditTemplate::setTemplateId(const QString &value)
{
    templateId = value;
}

/************************   设置全选         ********************/
void EditTemplate::on_checkBoxAllSelect_clicked()
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
