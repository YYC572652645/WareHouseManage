#include "materialcontrol.h"
#include "ui_materialcontrol.h"
#include "global/globaldef.h"
#include <QLineEdit>
#include <QComboBox>
#include <QListWidget>
#include <QFileDialog>
#include <QBuffer>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include "messagebox/messagedialog.h"
#include "httpclient/httpkey.h"

/*********************  构造函数              *********************/
MaterialControl::MaterialControl(QWidget *parent) :
    QWidget(parent),lineEditName(NULL),comboxType(NULL),lineEditBarCode(NULL), comboBoxMainUnit(NULL),
    lineEditSpec(NULL),lineEditShelf(NULL),pushButtonImage(NULL), ui(new Ui::MaterialControl),widgetType(0)
{
    ui->setupUi(this);

    this->initControl();
}

/*********************  析构函数              *********************/
MaterialControl::~MaterialControl()
{
    delete ui;
}

/*********************  初始化控件            *********************/
void MaterialControl::initControl()
{
    //基本信息
    {
        for(int i = 0; i < GLOBALDEF::MATMAX; i ++)
        {
            QWidget *widget = new QWidget(this);
            QListWidgetItem *item = new QListWidgetItem(ui->listWidgetAddMaterialInfo);

            baseWidgetList.append(widget);
            baseItemList.append(item);
            baseItemList.at(i)->setFont(QFont("宋体", 11, QFont::Bold));
        }

        baseItemList.at(GLOBALDEF::MATNAME)->setText(tr("原料名称"));
        baseItemList.at(GLOBALDEF::MATTYPE)->setText(tr("原料分类"));
        baseItemList.at(GLOBALDEF::MATBARCODE)->setText(tr("条形码"));
        baseItemList.at(GLOBALDEF::MATMAINUNIT)->setText(tr("主单位"));

        lineEditName       = new QLineEdit(this);
        comboxType         = new QComboBox(this);
        lineEditBarCode    = new QLineEdit(this);
        comboBoxMainUnit   = new QComboBox(this);
        pushButtonAdd      = new QPushButton(this);
        lineEditBarCode->setPlaceholderText(tr("建议输入5-13位数字，可不填"));
        comboBoxMainUnit->setView(new QListView());

        pushButtonAdd->setText(tr(" 添加新的副单位"));
        comboxType->setView(new QListView());

        lineEditName->setFixedSize(QSize(MaterialControl::CONTROLWIDGET, MaterialControl::CONTROLHIGHT));
        comboxType->setFixedSize(QSize(MaterialControl::CONTROLWIDGET, MaterialControl::CONTROLHIGHT));
        lineEditBarCode->setFixedSize(QSize(MaterialControl::CONTROLWIDGET, MaterialControl::CONTROLHIGHT));
        comboBoxMainUnit->setFixedSize(QSize(MaterialControl::CONTROLWIDGET, MaterialControl::CONTROLHIGHT));
        pushButtonAdd->setFixedHeight(MaterialControl::CONTROLHIGHT);
        pushButtonAdd->setIcon(QIcon(":/image/image/addfile.png"));

        this->setWidget(baseWidgetList, lineEditName,     GLOBALDEF::MATNAME,     true);
        this->setWidget(baseWidgetList, comboxType,       GLOBALDEF::MATTYPE,     true);
        this->setWidget(baseWidgetList, lineEditBarCode,  GLOBALDEF::MATBARCODE,  true);
        this->setWidget(baseWidgetList, comboBoxMainUnit, GLOBALDEF::MATMAINUNIT, true);
        this->setWidget(baseWidgetList, pushButtonAdd,    GLOBALDEF::MATADDUNIT,  false);

        for(int i = 0; i < GLOBALDEF::MATMAX; i ++)
        {
            ui->listWidgetAddMaterialInfo->setItemWidget(baseItemList.at(i), baseWidgetList.at(i));
        }
    }

    //扩展信息
    {
        for(int i = 0; i < GLOBALDEF::EXTERNMAX; i ++)
        {
            QWidget *widget = new QWidget(this);
            QListWidgetItem *item = new QListWidgetItem(ui->listWidgetExtenInfo);

            externWidgetList.append(widget);
            externItemList.append(item);
            externItemList.at(i)->setFont(QFont("宋体", 11, QFont::Bold));
        }

        externItemList.at(GLOBALDEF::EXTERNSPEC)->setText(tr("规格"));
        externItemList.at(GLOBALDEF::EXTERNSHELF)->setText(tr("保质期(天)"));
        externItemList.at(GLOBALDEF::EXTERNIMAGE)->setText(tr("原料图片"));

        lineEditSpec = new QLineEdit(this);
        lineEditShelf  = new QLineEdit(this);
        pushButtonImage = new QPushButton(this);
        lineEditSpec->setPlaceholderText(tr("可不填"));
        lineEditShelf->setPlaceholderText(tr("可不填"));

        pushButtonImage->setIcon(QIcon(GLOBALDEF::ADDIMG));
        pushButtonImage->setIconSize(QSize(MaterialControl::IMAGEWIDGH, MaterialControl::IMAGEWIDGH));
        pushButtonImage->setText(GLOBALDEF::SELECTIMAGE);
        pushButtonImage->setToolTip(GLOBALDEF::IMAGETOOLTIP);

        lineEditSpec->setFixedSize(QSize(MaterialControl::CONTROLWIDGET, MaterialControl::CONTROLHIGHT));
        lineEditShelf->setFixedSize(QSize(MaterialControl::CONTROLWIDGET, MaterialControl::CONTROLHIGHT));
        pushButtonImage->setFixedSize(QSize(MaterialControl::CONTROLWIDGET, MaterialControl::CONTROLWIDGET));

        connect(pushButtonImage, SIGNAL(clicked(bool)), this, SLOT(openImage()));

        this->setWidget(externWidgetList, lineEditSpec,    GLOBALDEF::EXTERNSPEC,   true);
        this->setWidget(externWidgetList, lineEditShelf,   GLOBALDEF::EXTERNSHELF,  true);
        this->setWidget(externWidgetList, pushButtonImage, GLOBALDEF::EXTERNIMAGE,  true);
        externItemList.at(GLOBALDEF::EXTERNIMAGE)->setSizeHint(QSize(MaterialControl::CONTROLWIDGET, MaterialControl::CONTROLWIDGET));

        for(int i = 0; i < GLOBALDEF::EXTERNMAX; i ++)
        {
            ui->listWidgetExtenInfo->setItemWidget(externItemList.at(i), externWidgetList.at(i));
        }
    }

    //设置只能输入数字
    QRegExp regExp("[0-9]+$");
    QValidator *validatorTop = new QRegExpValidator(regExp, lineEditBarCode);
    lineEditBarCode->setValidator(validatorTop);

    QValidator *validatorBottom = new QRegExpValidator(regExp, lineEditShelf);
    lineEditShelf->setValidator(validatorBottom);

    comboBoxMainUnit->setFocusPolicy(Qt::NoFocus);
    comboxType->setFocusPolicy(Qt::NoFocus);


    lookImage = new LookImage(this);
    addUnitSite = new AddUnitSite(this);

    //初始化信号与槽
    connect(pushButtonAdd, SIGNAL(clicked(bool)),    this, SLOT(slotAddUnitSite()));
    connect(addUnitSite,   SIGNAL(sendAddSave()),     this, SLOT(receiveAddSave()));
    connect(addUnitSite,   SIGNAL(sendInfoSave(int)), this, SLOT(receiveInfoSave(int)));
    connect(addUnitSite,   SIGNAL(sendDelSave(int)),  this, SLOT(receiveDelSave(int)));
    connect(comboBoxMainUnit, SIGNAL(activated(int)), this, SLOT(slotComboxClick()));
}

/*********************  设置窗口类型          *********************/
void MaterialControl::setType(int type)
{
    widgetType = type;
}

/*********************  清空信息             *********************/
void MaterialControl::clearControlInfo()
{
    lineEditName->clear();
    comboxType->clear();
    lineEditBarCode->clear();
    comboBoxMainUnit->clear();
    lineEditSpec->clear();
    lineEditShelf->clear();
    labelSiteList.clear();
    on_pushButtonDelImage_clicked();

    if(baseItemList.size() > GLOBALDEF::MATMAX)
    {
        int size = baseItemList.size();
        for(int i = 0; i < size; i ++)
        {
            if(i >= GLOBALDEF::MATMAX - ONE)
            {
                int totalCount = baseItemList.size() - TWO;

                ui->listWidgetAddMaterialInfo->removeItemWidget(baseItemList.at(totalCount));
                SAFEDELETE(baseItemList[totalCount]);
                baseWidgetList.removeAt(totalCount);
                baseItemList.removeAt(totalCount);

                if(baseItemList.size() <= GLOBALDEF::MATMAX) break;
            }
        }
    }
    addUnitSite->clearControlInfo();
}

/*********************  上传图片             *********************/
void MaterialControl::openImage()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("打开图片"), ".", "Image(*.jpg *.png *.ico *.jpeg *.bmp)");

    if(fileName.isNull()) return;

    filePath = fileName;

    pushButtonImage->setIcon(QIcon(filePath));
    pushButtonImage->setText(NULL);
    pushButtonImage->setIconSize(QSize(MaterialControl::CONTROLWIDGET, MaterialControl::CONTROLWIDGET));
}

/*********************  设置控件             *********************/
void MaterialControl::setWidget(QList<QWidget*> listWidget, QWidget *widget, int type, bool flage)
{
    if(type >= listWidget.size()) return;

    QHBoxLayout *hboxLayout = new QHBoxLayout(listWidget.at(type));

    widget->setContentsMargins(0,0,0,0);
    hboxLayout->setContentsMargins(0,0,6,0);

    if(flage) hboxLayout->addStretch();
    hboxLayout->addWidget(widget);

    listWidget.at(type)->setLayout(hboxLayout);
}

/*********************  保存数据             *********************/
void MaterialControl::on_pushButtonSave_clicked()
{
    QByteArray byteArray;
    QByteArray imageData;

    if(comboxType->currentText().isEmpty())
    {
        MESSAGEBOX->showMessageBox(this, MESSAGE::CATCANNOTNULL);
        return;
    }

    if(comboBoxMainUnit->currentText().isEmpty())
    {
        MESSAGEBOX->showMessageBox(this, MESSAGE::MAINNOTNULL);
        return;
    }

    if(!filePath.isEmpty())
    {
        QFile file(filePath);
        if(file.open(QIODevice::ReadOnly))
        {
            imageData = file.readAll();
            file.close();
        }

        file.close();

        if(imageData.size() / 1024 > 200)
        {
            MESSAGEBOX->showMessageBox(this, GLOBALDEF::IMAGETOOLTIP);
            return;
        }
    }
    else
    {
        QImage image = pixMapImage.toImage();
        QBuffer buffer(&imageData);

        image.save(&buffer, "png");
        buffer.close();
    }

    QString strPost;
    if(GLOBALDEF::ADDMATERIAL == widgetType)
    {
        strPost = POSTARG::MATERIALADD.arg(lineEditName->text(), HTTPCLIENT->findMapValue(categoryList, comboxType->currentText(), HTTPKEY::CATEGORYID));
    }
    else
    {
        strPost = POSTARG::MATERIALEDIT.arg(materialId, lineEditName->text(), HTTPCLIENT->findMapValue(categoryList, comboxType->currentText(), HTTPKEY::CATEGORYID));
    }

    strPost = strPost.arg(lineEditBarCode->text(), HTTPCLIENT->findMapValue(mapUnitList, comboBoxMainUnit->currentText(), HTTPKEY::UNITID));

    strPost = strPost.arg(lineEditSpec->text(), lineEditShelf->text());

    if(0 == addUnitSite->getSiteUnitDataList().size())
    {
        addUnitSite->setIsWarehouseUnit(NULL);
        addUnitSite->setIsPriceUnit(NULL);
        addUnitSite->setIsSupplyUnit(NULL);
    }

    strPost = addUnitSite->getIsWarehouseUnit().isEmpty() ? strPost.arg("0") : strPost.arg(addUnitSite->getIsWarehouseUnit());

    strPost = addUnitSite->getIsPriceUnit().isEmpty()     ? strPost.arg("0") : strPost.arg(addUnitSite->getIsPriceUnit());

    strPost = addUnitSite->getIsSupplyUnit().isEmpty()    ? strPost.arg("0") : strPost.arg(addUnitSite->getIsSupplyUnit());

    strPost = strPost.arg(QString::fromLatin1(imageData.toBase64()));

    strPost = strPost.arg(QString(makeJson(HTTPCLIENT->findMapValue(mapUnitList, comboBoxMainUnit->currentText(), HTTPKEY::UNITID))));

    byteArray.append(strPost);

    if(GLOBALDEF::ADDMATERIAL == widgetType)
    {
        HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_MAT_ADD), byteArray, PROTOCOL::URL_MAT_ADD);
    }
    else
    {
        HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_MAT_EDIT), byteArray, PROTOCOL::URL_MAT_EDIT);
    }
}

/*********************  组合JSON             ********************/
QByteArray MaterialControl::makeJson(QString unitId)
{
    QJsonObject jsonTotal;
    QJsonArray  jsonArray;

    {
        QList<SitUnitData> data = addUnitSite->getSiteUnitDataList();
        for(int i = FOUR; i < data.size(); i ++)
        {
            data.removeAt(i);
        }

        for(int i = 0; i < addUnitSite->getSiteUnitDataDelList().size(); i ++)
        {
            data.append(addUnitSite->getSiteUnitDataDelList().at(i));
        }

        for(int i = 0; i < data.size(); i ++)
        {
            QJsonObject jsonData;

            if(GLOBALDEF::LOOKMATERIAL == widgetType)
            {
                jsonData.insert(HTTPKEY::SIDEUNITID, data.at(i).siteUnitId);
                jsonData.insert(HTTPKEY::MATERIALID, data.at(i).materialId);
                jsonData.insert(HTTPKEY::CODE,       data.at(i).code);
            }

            jsonData.insert(HTTPKEY::SIDEID,     data.at(i).siteId);
            jsonData.insert(HTTPKEY::UNITID,     unitId);
            jsonData.insert(HTTPKEY::MAIN,       data.at(i).mainConver);
            jsonData.insert(HTTPKEY::VICE,       data.at(i).viceConver);

            jsonArray.insert(i, jsonData);
        }
    }

    jsonTotal.insert("sideList", jsonArray);

    QJsonDocument document;
    document.setObject(jsonTotal);

    return document.toJson();
}

/*********************  取消                *********************/
void MaterialControl::on_pushButtonCancel_clicked()
{
    if(GLOBALDEF::LOOKMATERIAL == widgetType)
    {
        HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_MAT_DETAILS).arg(materialId), PROTOCOL::URL_MAT_DETAILS);
    }
    else
    {
        this->clearControlInfo();
    }
}

/*********************  预览图片             *********************/
void MaterialControl::on_pushButtonLookImage_clicked()
{
    lookImage->showWidget(pixMapImage, filePath);
}

/*********************  添加副单元           *********************/
void MaterialControl::slotAddUnitSite()
{
    QString unitId = NULL;
    for(int i = 0; i < mapUnitList.size(); i ++)
    {
        if(mapUnitList.at(i).value(HTTPKEY::NAME) == comboBoxMainUnit->currentText())
        {
            unitId = mapUnitList.at(i).value(HTTPKEY::UNITID);
        }
    }

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_SEL_SIDE).arg(unitId), PROTOCOL::URL_SEL_SIDE);
}

/*********************  保存信息             *********************/
void MaterialControl::receiveInfoSave(int index)
{
    const static int INDEX = TWO;

    if(NULL == addUnitSite->getDataListIndex(index)) return;

    //左侧文字
    QString itemText = tr("副单位%1 : %2").arg(index + ONE).arg(addUnitSite->getDataListIndex(index)->siteUnitName);
    baseItemList.at(baseItemList.size() - INDEX - labelSiteList.size() + index + 1)->setText(itemText);

    //右侧文字
    QString labelText = addUnitSite->getDataListIndex(index)->viceConver + addUnitSite->getDataListIndex(index)->siteUnitName + " = ";
    labelText        += addUnitSite->getDataListIndex(index)->mainConver + addUnitSite->getDataListIndex(index)->mainUnitName;

    if(index >= labelSiteList.size()) return;
    labelSiteList.at(index)->setText(labelText);
}

/*********************  删除事件             *********************/
void MaterialControl::receiveDelSave(int index)
{
    int countIndex = index + GLOBALDEF::MATMAX - ONE;

    if(index < 0 || countIndex >= baseItemList.size() || index >= labelSiteList.size()) return;

    ui->listWidgetAddMaterialInfo->removeItemWidget(baseItemList.at(countIndex));
    SAFEDELETE(baseItemList[countIndex]);

    baseItemList.removeAt(countIndex);
    baseWidgetList.removeAt(countIndex);
    labelSiteList.removeAt(index);

    int startIndex = GLOBALDEF::MATMAX - ONE;
    for(int i = startIndex; i < baseItemList.size() - 1; i ++)
    {
        QString itemText = baseItemList.at(i)->text();
        itemText.remove(itemText.left(4));
        itemText.insert(0, tr("副单位%1").arg(i - startIndex + 1));
        baseItemList.at(i)->setText(itemText);
    }
}

/*********************  选择类型             *********************/
void MaterialControl::slotComboxClick()
{
    if(labelSiteList.size() != 0)
    {
        int success = MESSAGEBOX->showMessageBox(this, GLOBALDEF::CLEARSITEUNIT, true, false);

        if(success == QDialog::Accepted)
        {
            if(baseItemList.size() > GLOBALDEF::MATMAX)
            {
                int size = baseItemList.size();
                for(int i = 0; i < size; i ++)
                {
                    if(i >= GLOBALDEF::MATMAX - ONE)
                    {
                        int totalCount = baseItemList.size() - TWO;

                        ui->listWidgetAddMaterialInfo->removeItemWidget(baseItemList.at(totalCount));
                        SAFEDELETE(baseItemList[totalCount]);
                        baseWidgetList.removeAt(totalCount);
                        baseItemList.removeAt(totalCount);

                        if(baseItemList.size() <= GLOBALDEF::MATMAX) break;
                    }
                }
            }
            labelSiteList.clear();
            addUnitSite->clearControlInfo();
        }
        else
        {
            comboBoxMainUnit->setCurrentText(currentText);
        }
    }

    currentText = comboBoxMainUnit->currentText();
}

/*********************  添加事件             *********************/
void MaterialControl::receiveAddSave()
{
    const static int INDEX = TWO;
    const static int MAXTYPE = GLOBALDEF::MATMAX + 4;

    if(baseItemList.size() >= MAXTYPE)
    {
        MESSAGEBOX->showMessageBox(this, GLOBALDEF::MAXLIMITPOT);
        return;
    }

    ui->listWidgetAddMaterialInfo->removeItemWidget(baseItemList.last());
    SAFEDELETE(baseItemList.last());

    baseWidgetList.removeLast();
    baseItemList.removeLast();

    QLabel *labelSiteUnit = new QLabel(this);
    labelSiteUnit->setFixedSize(QSize(MaterialControl::CONTROLWIDGET, MaterialControl::CONTROLHIGHT));

    for(int i = 0; i < INDEX; i ++)
    {
        QWidget *widget = new QWidget(this);
        QListWidgetItem *item = new QListWidgetItem(ui->listWidgetAddMaterialInfo);

        baseWidgetList.append(widget);
        baseItemList.append(item);
    }

    this->setWidget(baseWidgetList, labelSiteUnit, baseItemList.size() - INDEX,true);
    this->setWidget(baseWidgetList, pushButtonAdd, baseItemList.size() - ONE, false);

    //左侧文字
    int indexList = baseItemList.size() - GLOBALDEF::MATMAX - ONE;

    if(NULL == addUnitSite->getDataListIndex(indexList)) return;
    QString itemText = tr("副单位%1 : %2").arg(indexList + ONE).arg(addUnitSite->getDataListIndex(indexList)->siteUnitName);

    baseItemList.at(baseItemList.size() - INDEX)->setText(itemText);
    baseItemList.at(baseItemList.size() - INDEX)->setFont(QFont("宋体", 11, QFont::Bold));

    //右侧文字
    QString labelText = addUnitSite->getDataListIndex(indexList)->viceConver + addUnitSite->getDataListIndex(indexList)->siteUnitName + " = ";
    labelText        += addUnitSite->getDataListIndex(indexList)->mainConver + addUnitSite->getDataListIndex(indexList)->mainUnitName;

    labelSiteUnit->setText(labelText);
    labelSiteList.append(labelSiteUnit);

    ui->listWidgetAddMaterialInfo->setItemWidget(baseItemList.at(baseItemList.size() - INDEX), baseWidgetList.at(baseWidgetList.size() - INDEX));
    ui->listWidgetAddMaterialInfo->setItemWidget(baseItemList.last(), baseWidgetList.last());
}

/*********************  设置单元列表         *********************/
void MaterialControl::setMapUnitList(const MapList &value)
{
    mapUnitList = value;
}

/*********************  设置原料ID           *********************/
void MaterialControl::setMaterialId(const QString &value)
{
    materialId = value;
}

/*********************  添加副单元           *********************/
void MaterialControl::addSideList()
{
    QList<SitUnitData> dataList;
    for(int i = 0; i < mapSideList.size(); i ++)
    {
        SitUnitData data;

        data.mainUnitName   = comboBoxMainUnit->currentText();
        data.siteUnitName   = mapSideList.at(i).value(HTTPKEY::SIDENAME);
        data.code           = mapSideList.at(i).value(HTTPKEY::CODE);
        data.siteId         = mapSideList.at(i).value(HTTPKEY::SIDEID);
        data.siteUnitId     = mapSideList.at(i).value(HTTPKEY::SIDEUNITID);
        data.materialId     = mapSideList.at(i).value(HTTPKEY::MATERIALID);
        data.mainConver     = mapSideList.at(i).value(HTTPKEY::MAIN);
        data.viceConver     = mapSideList.at(i).value(HTTPKEY::VICE);
        data.wareHouseFlage = false;
        data.priceFlage     = false;
        data.supplyFlage    = false;

        if(wareHouseFlage == data.siteId) data.wareHouseFlage = true;
        if(priceFlage     == data.siteId) data.priceFlage     = true;
        if(supplyFlage    == data.siteId) data.supplyFlage    = true;

        dataList.append(data);
    }

    addUnitSite->setSiteUnitDataList(dataList);
    addUnitSite->setMapUnitList(mapUnitList);
    addUnitSite->setMainUnit(comboBoxMainUnit->currentText());

    for(int i = 0; i < dataList.size(); i ++)
    {
        receiveAddSave();
    }
}

/*********************  设置图片             *********************/
void MaterialControl::setPixMapImage(const QPixmap &value)
{
    pixMapImage = value;
    filePath.clear();
}

/*********************  查看副单位           *********************/
void MaterialControl::on_listWidgetAddMaterialInfo_doubleClicked(const QModelIndex &index)
{
    if(ui->listWidgetAddMaterialInfo->currentItem()->text().contains(GLOBALDEF::SIDETEXT))
    {
        addUnitSite->showWidget(true, index.row() - GLOBALDEF::MATMAX + ONE);
    }
}

/*********************  设置当前文本         *********************/
void MaterialControl::setCurrentText(const QString &value)
{
    currentText = value;
}

/*********************  设置供货单位         *********************/
void MaterialControl::setSupplyFlage(const QString &value)
{
    addUnitSite->setIsSupplyUnit(value);
    supplyFlage = value;
}

/*********************  设置副单元列表        *********************/
void MaterialControl::setMapSideUnitList(const MapList &value)
{
    addUnitSite->setMapUnitList(value);
}

/*********************  设置副单位中的主单元   *********************/
void MaterialControl::setSideMainUnit(const QString &value)
{
    addUnitSite->setMainUnit(value);
}

/*********************  设置计价单位          *********************/
void MaterialControl::setPriceFlage(const QString &value)
{
    addUnitSite->setIsPriceUnit(value);
    priceFlage = value;
}

/*********************  设置库存单位          *********************/
void MaterialControl::setWareHouseFlage(const QString &value)
{
    addUnitSite->setIsWarehouseUnit(value);
    wareHouseFlage = value;
}

/*********************  设置副单位列表        *********************/
void MaterialControl::setMapSideList(const MapList &value)
{
    mapSideList = value;
    addUnitSite->setMapSideList(mapSideList);
    addUnitSite->setMaterialId(materialId);
}

/*********************  设置单元列表          *********************/
void MaterialControl::setCategoryList(const MapList &value)
{
    categoryList = value;
}

/*********************  删除图片          *********************/
void MaterialControl::on_pushButtonDelImage_clicked()
{
    filePath.clear();
    pixMapImage = QPixmap();
    pushButtonImage->setIcon(QIcon(GLOBALDEF::ADDIMG));
    pushButtonImage->setIconSize(QSize(MaterialControl::IMAGEWIDGH, MaterialControl::IMAGEWIDGH));
    pushButtonImage->setText(GLOBALDEF::SELECTIMAGE);
}

/*********************  获取副单位          *********************/
AddUnitSite *MaterialControl::getAddUnitSite()
{
    return addUnitSite;
}
