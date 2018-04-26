#include "materialinfo.h"
#include "ui_materialinfo.h"
#include "httpclient/httpkey.h"
#include "messagebox/messagedialog.h"

/*********************  构造函数       *********************/
MaterialInfo::MaterialInfo(int type, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MaterialInfo)
{
    ui->setupUi(this);

    widgetType = type;
    this->initControl();
}

/*********************  析构函数       *********************/
MaterialInfo::~MaterialInfo()
{
    delete ui;
}

/*********************  显示窗口       *********************/
void MaterialInfo::showWidget()
{
    titleBar->setTitle(GLOBALDEF::TABMATERIALINFO);
    this->show();
}

/*********************  设置数据       *********************/
void MaterialInfo::setUpData()
{
    ui->comboBoxUnit->clear();
    for(int i = 0; i < unitMapList.size(); i ++)
    {
        ui->comboBoxUnit->addItem(unitMapList.at(i).value(HTTPKEY::NAME));
        if(unitMapList.at(i).value(HTTPKEY::UNITID) == mapItem.value(HTTPKEY::UNITID))
        {
            ui->comboBoxUnit->setCurrentText(unitMapList.at(i).value(HTTPKEY::NAME));
        }
    }

    ui->comboBoxWareHouse->clear();
    for(int i = 0; i < productMapList.size(); i ++)
    {
        ui->comboBoxWareHouse->addItem(productMapList.at(i).value(HTTPKEY::WAREHOUSENAME));

        if(productMapList.at(i).value(HTTPKEY::WAREHOUSEID) == mapItem.value(HTTPKEY::WAREHOUSEID))
        {
            ui->comboBoxWareHouse->setCurrentText(productMapList.at(i).value(HTTPKEY::WAREHOUSENAME));
        }
    }

    ui->lineEditName->setText(matName);
    ui->lineEditBarCode->setText(barCode);
    ui->lineEditNumber->setText(expendNumber);
}

/*********************  初始化控件      *********************/
void MaterialInfo::initControl()
{
    titleBar = new TitleBar(this);


    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    ui->comboBoxUnit->setView(new QListView());
    ui->comboBoxWareHouse->setView(new QListView());

    ui->comboBoxUnit->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxWareHouse->setFocusPolicy(Qt::NoFocus);

    if(widgetType == ADDTYPE)
    {
        ui->pushButtonDel->setHidden(true);
    }
}

/*********************  改变事件        *********************/
void MaterialInfo::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  清空信息        *********************/
void MaterialInfo::clearInfo()
{
    ui->comboBoxUnit->clear();
    ui->comboBoxWareHouse->clear();
    ui->lineEditBarCode->clear();
    ui->lineEditName->clear();
    ui->lineEditNumber->clear();
}

/*********************  设置食品ID      *********************/
void MaterialInfo::setFoodId(const QString &value)
{
    foodId = value;
}

/*********************  设置消耗数量     *********************/
void MaterialInfo::setExpendNumber(const QString &value)
{
    expendNumber = value;
}

/*********************  设置编码        *********************/
void MaterialInfo::setBarCode(const QString &value)
{
    barCode = value;
}

/*********************  设置原料名称     *********************/
void MaterialInfo::setMatName(const QString &value)
{
    matName = value;
}

/*********************  设置单元列表     *********************/
void MaterialInfo::setUnitMapList(const MapList &value)
{
    unitMapList = value;
}

/*********************  设置仓库列表     *********************/
void MaterialInfo::setProductMapList(const MapList &value)
{
    productMapList = value;
}

/*********************  设置Map数据     *********************/
void MaterialInfo::setMapItem(const Map &value)
{
    mapItem = value;
}

/*********************  保存信息        *********************/
void MaterialInfo::on_pushButtonSave_clicked()
{
    if(ui->lineEditNumber->text().isEmpty())
    {
        MESSAGEBOX->showMessageBox(this, GLOBALDEF::NUMBERISNOTNULL);
        return;
    }

    QByteArray byteArray;
    if(widgetType == ADDTYPE)
    {
        qDebug()<<foodId;
        QString strPost = POSTARG::FOODADDMAT.arg(foodId);
        strPost = strPost.arg(mapItem.value(HTTPKEY::MATERIALID));
        strPost = strPost.arg(productMapList.at(ui->comboBoxWareHouse->currentIndex()).value(HTTPKEY::WAREHOUSEID));
        strPost = strPost.arg(unitMapList.at(ui->comboBoxUnit->currentIndex()).value(HTTPKEY::UNITID));
        strPost = strPost.arg(ui->lineEditNumber->text());

        byteArray.append(strPost);

        HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_BOM_MAT_ADD), byteArray, PROTOCOL::URL_BOM_MAT_ADD);
    }
    else
    {
        QString strPost = POSTARG::FOODEDITMAT.arg(mapItem.value(HTTPKEY::BOMMATERIALID));
        strPost = strPost.arg(unitMapList.at(ui->comboBoxUnit->currentIndex()).value(HTTPKEY::UNITID));
        strPost = strPost.arg(ui->lineEditNumber->text());
        strPost = strPost.arg(productMapList.at(ui->comboBoxWareHouse->currentIndex()).value(HTTPKEY::WAREHOUSEID));

        byteArray.append(strPost);

        HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_BOM_MAT_UPDATE), byteArray, PROTOCOL::URL_BOM_MAT_UPDATE);
    }

    this->close();
}

/*********************  删除信息        *********************/
void MaterialInfo::on_pushButtonDel_clicked()
{
    QByteArray byteArray;

    byteArray.append(POSTARG::FOODDELMAT.arg(mapItem.value(HTTPKEY::BOMMATERIALID)));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_BOM_MAT_DEL), byteArray, PROTOCOL::URL_BOM_MAT_DEL);
    this->close();
}

/*********************  取消按钮        *********************/
void MaterialInfo::on_pushButtonCancel_clicked()
{
    this->close();
}
