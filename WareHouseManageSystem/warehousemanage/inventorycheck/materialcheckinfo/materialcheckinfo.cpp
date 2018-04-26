#include "materialcheckinfo.h"
#include "ui_materialcheckinfo.h"
#include "httpclient/httpkey.h"

/*********************  构造函数       *********************/
MaterialCheckInfo::MaterialCheckInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MaterialCheckInfo)
  ,titleBar(NULL)
  ,showFalge(false)
{
    ui->setupUi(this);

    this->initControl();
}

/*********************  析构函数       *********************/
MaterialCheckInfo::~MaterialCheckInfo()
{
    delete ui;

    SAFEDELETE(titleBar);
}

/*********************  显示窗口       *********************/
void MaterialCheckInfo::showWidget()
{
    titleBar->setTitle(GLOBALDEF::CHECKMATERIAL);
    this->show();
}

/*********************  初始化控件       *********************/
void MaterialCheckInfo::initControl()
{
    titleBar = new TitleBar(this);
    addCheckMat = new AddCheckMat(this);
    materialCheckDet = new MaterialCheckDet(this);


    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    SETTABLEWIDGET(ui->tableWidgetData);
}

/*********************  改变事件        *********************/
void MaterialCheckInfo::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  设置单号        *********************/
void MaterialCheckInfo::setCheckNumber(const QString &value)
{
    checkNumber = value;
}

/*********************  设置隐藏        *********************/
void MaterialCheckInfo::setHide()
{
    ui->pushButtonAdd->setHidden(true);
    ui->pushButtonCancel->setHidden(true);
    ui->pushButtonSave->setHidden(true);
    materialCheckDet->setHide();

    showFalge = false;
}

/*********************  设置显示        *********************/
void MaterialCheckInfo::setShow()
{
    ui->pushButtonAdd->show();
    materialCheckDet->setShow();
    ui->pushButtonCancel->show();
    ui->pushButtonSave->show();

    showFalge = true;
}

/*********************  设置仓库ID        *********************/
void MaterialCheckInfo::setWareHouseId(const QString &value)
{
    wareHouseId = value;
    addCheckMat->setWareHouseId(value);
}

/*********************  设置原料列表        *********************/
void MaterialCheckInfo::setMapMatList(const MapList &value)
{
    mapMatList = value;

    ui->tableWidgetData->setRowCount(mapMatList.size());

    for(int i = 0; i < spinBoxList.size(); i ++)
    {
        SAFEDELETE(spinBoxList[i]);
    }

    spinBoxList.clear();

    for(int i = 0; i < mapMatList.size(); i ++)
    {
        ui->tableWidgetData->setItem(i, ZERO,  DATA(mapMatList.at(i).value(HTTPKEY::MATERIALNAME)));
        ui->tableWidgetData->setItem(i, ONE,   DATA(mapMatList.at(i).value(HTTPKEY::BARCODE)));
        ui->tableWidgetData->setItem(i, TWO,   DATA(mapMatList.at(i).value(HTTPKEY::PRICE)));

        {
            QWidget * widget = new QWidget(this);
            QHBoxLayout *hBoxLayout =  new QHBoxLayout(widget);
            QDoubleSpinBox *spinBox = new QDoubleSpinBox(this);

            hBoxLayout->addWidget(spinBox);
            widget->setLayout(hBoxLayout);
            spinBox->setValue(mapMatList.at(i).value(HTTPKEY::REALITYNUMBER).toDouble());
            hBoxLayout->setMargin(0);
            spinBox->setFixedSize(ui->tableWidgetData->columnWidth(THREE), ui->tableWidgetData->rowHeight(ZERO));
            spinBox->setFocusPolicy(Qt::NoFocus);

            ui->tableWidgetData->setCellWidget(i, THREE, widget);

            spinBoxList.append(spinBox);
        }

        ui->tableWidgetData->setItem(i, FOUR,  DATA(mapMatList.at(i).value(HTTPKEY::UNITNAME)));

        SETTABLECENTER(ui->tableWidgetData->item(i, ZERO));
        SETTABLECENTER(ui->tableWidgetData->item(i, ONE));
        SETTABLECENTER(ui->tableWidgetData->item(i, TWO));
        SETTABLECENTER(ui->tableWidgetData->item(i, FOUR));
    }

    if(!showFalge)
    {
        for(int i = 0; i < spinBoxList.size(); i ++)
        {
            spinBoxList.at(i)->setEnabled(false);
            spinBoxList.at(i)->setStyleSheet("color:black");
        }
    }
    ui->tableWidgetData->scrollToBottom();
}

/*********************  双击控件        *********************/
void MaterialCheckInfo::on_tableWidgetData_doubleClicked(const QModelIndex &index)
{
    if(index.row() < 0 || index.row() >= mapMatList.size()) return;

    QString wareHouseMatId = mapMatList.at(index.row()).value(HTTPKEY::WAREHOUSECHECKMATID);

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_CHECK_UPDATE_MAT_PAGE).arg(wareHouseMatId), PROTOCOL::URL_CHECK_UPDATE_MAT_PAGE);
    materialCheckDet->showWidget();
}

/*********************  添加原料        *********************/
void MaterialCheckInfo::on_pushButtonAdd_clicked()
{
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_CHECK_ADD_MAT_PAGE).arg(checkNumber), PROTOCOL::URL_CHECK_ADD_MAT_PAGE);
}

/*********************  获取原料详情对象        *********************/
MaterialCheckDet *MaterialCheckInfo::getMaterialCheckDet()
{
    return materialCheckDet;
}

/*********************  获取添加原料对象        *********************/
AddCheckMat *MaterialCheckInfo::getAddCheckMat()
{
    return addCheckMat;
}

/*********************  保存按钮        *********************/
void MaterialCheckInfo::on_pushButtonSave_clicked()
{
    MapList mapListData;

    for(int i = 0; i < mapMatList.size(); i ++)
    {
        Map mapData;

        mapData[HTTPKEY::WAREHOUSECHECKMATID] = mapMatList.at(i).value(HTTPKEY::WAREHOUSECHECKMATID);
        mapData[HTTPKEY::PAPERNUMBER]         = mapMatList.at(i).value(HTTPKEY::PAPERNUMBER);

        if(NULL != spinBoxList.at(i))
        {
            mapData[HTTPKEY::REALITYNUMBER]       = QString::number(spinBoxList.at(i)->value());
        }

        mapListData.append(mapData);
    }

    if(mapListData.size() <= 0) return;

    QByteArray byteArray;

    byteArray.append(POSTARG::MATERIALDATE.arg(HTTPCLIENT->makeJson(mapListData)));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_CHECK_UPDATE_NUM), byteArray, PROTOCOL::URL_CHECK_UPDATE_NUM);

    this->close();
}

/*********************  取消按钮        *********************/
void MaterialCheckInfo::on_pushButtonCancel_clicked()
{
    this->close();
}
