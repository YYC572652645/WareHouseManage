#include "addunitsite.h"
#include "ui_addunitsite.h"
#include <QListView>
#include "httpclient/httpkey.h"
#include "messagebox/messagedialog.h"


/************************   构造函数                  *******************/
AddUnitSite::AddUnitSite(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddUnitSite)
{
    ui->setupUi(this);

    this->initControl();
}

/************************   析构函数                  *******************/
AddUnitSite::~AddUnitSite()
{
    delete ui;
}

/************************   显示窗口                  *******************/
void AddUnitSite::showWidget(bool widgetType, int index)
{
    titleBar->setTitle(GLOBALDEF::ADDUNITSIDE);
    if(index != -1)
    {
        if(index >= siteUnitDataList.size()) return;

        ui->lineEditMainUnit->setText(siteUnitDataList.at(index).mainUnitName);
        ui->comboBoxSiteUnit->setCurrentText(siteUnitDataList.at(index).siteUnitName);
        ui->lineEditRight->setText(siteUnitDataList.at(index).mainConver);
        ui->lineEditLeft->setText(siteUnitDataList.at(index).viceConver);
        ui->checkBoxWareHouse->setChecked(siteUnitDataList.at(index).wareHouseFlage);
        ui->checkBoxPrice->setChecked(siteUnitDataList.at(index).priceFlage);
        ui->checkBoxSupply->setChecked(siteUnitDataList.at(index).supplyFlage);

        siteUnitId = siteUnitDataList.at(index).siteUnitId;
        siteId = siteUnitDataList.at(index).siteId;

        ui->pushButtonDel->show();
    }
    else
    {
        ui->lineEditMainUnit->setText(mainUnit);

        ui->comboBoxSiteUnit->clear();
        ui->lineEditLeft->clear();
        ui->lineEditRight->clear();
        ui->labelLeft->clear();
        ui->labelRight->clear();
        ui->checkBoxWareHouse->setChecked(false);
        ui->checkBoxPrice->setChecked(false);
        ui->checkBoxSupply->setChecked(false);

        for(int i = 0; i < mapUnitList.size(); i ++)
        {
            ui->comboBoxSiteUnit->addItem(mapUnitList.at(i).value(HTTPKEY::NAME));
        }

        ui->pushButtonDel->hide();
    }

    this->show();

    ui->lineEditLeft->setEnabled(true);
    ui->lineEditRight->setEnabled(true);

    this->widgetType  = widgetType;
    this->widgetIndex = index;
}

/************************   清空信息                  *******************/
void AddUnitSite::clearControlInfo()
{
    ui->lineEditMainUnit->clear();
    ui->comboBoxSiteUnit->clear();
    ui->lineEditRight->clear();
    ui->lineEditLeft->clear();
    ui->checkBoxWareHouse->setChecked(false);
    ui->checkBoxPrice->setChecked(false);
    ui->checkBoxSupply->setChecked(false);
    siteUnitDataList.clear();
    siteUnitDataDelList.clear();
    mapUnitList.clear();

}

/************************   初始化控件                *******************/
void AddUnitSite::initControl()
{
    titleBar = new TitleBar(this);

    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    ui->comboBoxSiteUnit->setView(new QListView());
    ui->comboBoxSiteUnit->setFocusPolicy(Qt::NoFocus);

    QRegExp regLeftExp("[0-9].[1-9]+$");
    QValidator *validatorLeft = new QRegExpValidator(regLeftExp, ui->lineEditLeft);
    ui->lineEditLeft->setValidator(validatorLeft);

    QRegExp regRightExp("[0-9].[1-9]+$");
    QValidator *validatorRight = new QRegExpValidator(regRightExp, ui->lineEditRight);
    ui->lineEditRight->setValidator(validatorRight);
}

/************************   重置界面                  *******************/
void AddUnitSite::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/************************   设置主单元                *******************/
void AddUnitSite::setMainUnit(const QString &value)
{
    mainUnit = value;
    ui->lineEditMainUnit->setText(mainUnit);
    ui->labelRight->setText(mainUnit);
}

/************************   设置主单元列表            *******************/
void AddUnitSite::setMapUnitList(const MapList &value)
{
    mapUnitList = value;

    ui->comboBoxSiteUnit->clear();
    for(int i = 0; i < mapUnitList.size(); i ++)
    {
        ui->comboBoxSiteUnit->addItem(mapUnitList.at(i).value(HTTPKEY::NAME));
    }

    ui->comboBoxSiteUnit->setCurrentIndex(-1);

    if(mapUnitList.size() <= 0) return;
    ui->labelLeft->setText(mapUnitList.at(0).value(HTTPKEY::NAME) + " = ");
}

/************************   保存按钮                 *******************/
void AddUnitSite::on_pushButtonSave_clicked()
{
    if(ui->comboBoxSiteUnit->currentIndex() < 0)
    {
        MESSAGEBOX->showMessageBox(this, MESSAGE::PLEASESELECT);
        return;
    }

    if(ui->lineEditLeft->text().isEmpty() || ui->lineEditRight->text().isEmpty())
    {
        MESSAGEBOX->showMessageBox(this, MESSAGE::CONVERNOTNULL);
        return;
    }

    if(ui->lineEditMainUnit->text() ==  ui->comboBoxSiteUnit->currentText())
    {
        MESSAGEBOX->showMessageBox(this, MESSAGE::MAINSITENOTSAME);
        return;
    }



    if(ui->comboBoxSiteUnit->currentIndex() >= mapUnitList.size()) return;

    if(!widgetType)
    {
        if(siteUnitDataList.size() >= FOUR)
        {
            MESSAGEBOX->showMessageBox(this, GLOBALDEF::MAXLIMITPOT);
            return;
        }

        for(int i = 0; i < siteUnitDataList.size(); i ++)
        {
            if(ui->comboBoxSiteUnit->currentText() == siteUnitDataList.at(i).siteUnitName)
            {
                MESSAGEBOX->showMessageBox(this, MESSAGE::SITEISEXIST);
                return;
            }
        }

        SitUnitData siteUnitData;

        siteUnitData.mainUnitName   = ui->lineEditMainUnit->text();
        siteUnitData.siteUnitName   = ui->comboBoxSiteUnit->currentText();
        siteUnitData.siteId         = mapUnitList.at(ui->comboBoxSiteUnit->currentIndex()).value(HTTPKEY::UNITID);
        siteUnitData.mainConver     = ui->lineEditRight->text();
        siteUnitData.viceConver     = ui->lineEditLeft->text();
        siteUnitData.wareHouseFlage = ui->checkBoxWareHouse->isChecked();
        siteUnitData.priceFlage     = ui->checkBoxPrice->isChecked();
        siteUnitData.supplyFlage    = ui->checkBoxSupply->isChecked();
        siteUnitData.materialId     = materialId;
        siteUnitData.code           = "1";

        if(ui->checkBoxWareHouse->isChecked()) isWarehouseUnit = mapUnitList.at(ui->comboBoxSiteUnit->currentIndex()).value(HTTPKEY::UNITID);
        if(ui->checkBoxPrice->isChecked())     isPriceUnit     = mapUnitList.at(ui->comboBoxSiteUnit->currentIndex()).value(HTTPKEY::UNITID);
        if(ui->checkBoxSupply->isChecked())    isSupplyUnit    = mapUnitList.at(ui->comboBoxSiteUnit->currentIndex()).value(HTTPKEY::UNITID);

        siteUnitDataList.append(siteUnitData);

        emit sendAddSave();
    }
    else
    { 
        for(int i = 0; i < siteUnitDataList.size(); i ++)
        {
            if(i != widgetIndex)
            {
                if(ui->comboBoxSiteUnit->currentText() == siteUnitDataList.at(i).siteUnitName)
                {
                    MESSAGEBOX->showMessageBox(this, MESSAGE::SITEISEXIST);
                    return;
                }
            }
        }

        if(widgetIndex < 0 || widgetIndex >= siteUnitDataList.size()) return;

        siteUnitDataList[widgetIndex].mainUnitName   = ui->lineEditMainUnit->text();
        siteUnitDataList[widgetIndex].siteUnitName   = ui->comboBoxSiteUnit->currentText();
        siteUnitDataList[widgetIndex].mainConver     = ui->lineEditRight->text();
        siteUnitDataList[widgetIndex].viceConver     = ui->lineEditLeft->text();
        siteUnitDataList[widgetIndex].wareHouseFlage = ui->checkBoxWareHouse->isChecked();
        siteUnitDataList[widgetIndex].priceFlage     = ui->checkBoxPrice->isChecked();
        siteUnitDataList[widgetIndex].supplyFlage    = ui->checkBoxSupply->isChecked();
        siteUnitDataList[widgetIndex].materialId     = materialId;
        siteUnitDataList[widgetIndex].siteId         = mapUnitList.at(ui->comboBoxSiteUnit->currentIndex()).value(HTTPKEY::UNITID);

        if(siteUnitDataList[widgetIndex].code.isEmpty())
        {
            siteUnitDataList[widgetIndex].code = "0";
        }

        emit sendInfoSave(widgetIndex);
    }

    this->close();
}

/************************   取消按钮                 *******************/
void AddUnitSite::on_pushButtonCancel_clicked()
{
    this->close();
}

/************************   数据改变                 *******************/
void AddUnitSite::on_comboBoxSiteUnit_currentIndexChanged(const QString &arg1)
{
    ui->labelLeft->setText(arg1 + "=");
    ui->labelRight->setText(ui->lineEditMainUnit->text());

    siteUnitName = arg1;
}

/************************   获取副单位列表            *******************/
const SitUnitData *AddUnitSite::getDataListIndex(int index)
{
    if(index >= siteUnitDataList.size()) return NULL;
    return &siteUnitDataList.at(index);
}

/************************   库存单位                 *******************/
void AddUnitSite::on_checkBoxWareHouse_clicked()
{
    if(ui->checkBoxWareHouse->isChecked())
    {
        for(int i = 0; i < siteUnitDataList.size(); i ++)
        {
            if(i != widgetIndex)
            {
                siteUnitDataList[i].wareHouseFlage = false;
            }
        }

        isWarehouseUnit = mapUnitList.at(ui->comboBoxSiteUnit->currentIndex()).value(HTTPKEY::UNITID);
    }
    else
    {
        isWarehouseUnit.clear();
    }
}

/************************   计价单位                 *******************/
void AddUnitSite::on_checkBoxPrice_clicked()
{
    if(ui->checkBoxPrice->isChecked())
    {
        for(int i = 0; i < siteUnitDataList.size(); i ++)
        {
            if(i != widgetIndex)
            {
                siteUnitDataList[i].priceFlage = false;
            }
        }

        isPriceUnit = mapUnitList.at(ui->comboBoxSiteUnit->currentIndex()).value(HTTPKEY::UNITID);
    }
    else
    {
        isPriceUnit.clear();
    }
}

/************************   供货单位                 *******************/
void AddUnitSite::on_checkBoxSupply_clicked()
{
    if(ui->checkBoxSupply->isChecked())
    {
        for(int i = 0; i < siteUnitDataList.size(); i ++)
        {
            if(i != widgetIndex)
            {
                siteUnitDataList[i].supplyFlage = false;
            }
        }

        isSupplyUnit = mapUnitList.at(ui->comboBoxSiteUnit->currentIndex()).value(HTTPKEY::UNITID);
    }
    else
    {
        isSupplyUnit.clear();
    }
}

/************************   编辑响应                 *******************/
void AddUnitSite::on_lineEditLeft_textEdited(const QString &arg1)
{
    if(ui->lineEditLeft->text().toDouble() > 0)
    {
        ui->lineEditRight->setText("1.00");
    }
}

/************************   编辑响应                 *******************/
void AddUnitSite::on_lineEditRight_textEdited(const QString &arg1)
{
    if(ui->lineEditRight->text().toDouble() > 0)
    {
        ui->lineEditLeft->setText("1.00");
    }
}

/************************   删除按钮                 *******************/
void AddUnitSite::on_pushButtonDel_clicked()
{
    if(widgetIndex < 0 || widgetIndex >= siteUnitDataList.size()) return;

    emit sendDelSave(widgetIndex);

    this->close();

    if(widgetIndex >= mapSideList.size())
    {
        siteUnitDataList.removeAt(widgetIndex);

        return;
    }

    if(siteUnitDataDelList.size() < mapSideList.size())
    {
        siteUnitDataList[widgetIndex].code = "2";

        siteUnitDataList[widgetIndex].materialId = materialId;

        siteUnitDataList[widgetIndex].siteUnitId = siteUnitId;

        siteUnitDataList[widgetIndex].siteId = siteId;

        siteUnitDataDelList.append(siteUnitDataList.at(widgetIndex));

        siteUnitDataList.removeAt(widgetIndex);
    }
}

/************************   设置供货单位              *******************/
void AddUnitSite::setIsSupplyUnit(const QString &value)
{
    isSupplyUnit = value;
}

/************************   设置计价单位              *******************/
void AddUnitSite::setIsPriceUnit(const QString &value)
{
    isPriceUnit = value;
}

/************************   设置仓库单位              *******************/
void AddUnitSite::setIsWarehouseUnit(const QString &value)
{
    isWarehouseUnit = value;
}

/************************   获取删除的副单位列表       *******************/
QList<SitUnitData> AddUnitSite::getSiteUnitDataDelList() const
{
    return siteUnitDataDelList;
}

/************************   设置原料ID               *******************/
void AddUnitSite::setMaterialId(const QString &value)
{
    materialId = value;
}

/************************   设置副单位列表            *******************/
void AddUnitSite::setMapSideList(const MapList &value)
{
    mapSideList = value;
}

/************************   设置副单位列表            *******************/
void AddUnitSite::setSiteUnitDataList(const QList<SitUnitData> &value)
{
    siteUnitDataList = value;
}

/************************   获取副单位列表            *******************/
QList<SitUnitData> AddUnitSite::getSiteUnitDataList() const
{
    return siteUnitDataList;
}

/************************   获取供货单位              *******************/
QString AddUnitSite::getIsSupplyUnit() const
{
    return isSupplyUnit;
}

/************************   获取计价单位              *******************/
QString AddUnitSite::getIsPriceUnit() const
{
    return isPriceUnit;
}

/************************   获取库存单位              *******************/
QString AddUnitSite::getIsWarehouseUnit() const
{
    return isWarehouseUnit;
}
