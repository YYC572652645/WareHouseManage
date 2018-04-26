#include "templatewidget.h"
#include "ui_templatewidget.h"
#include "global/globaldef.h"
#include "httpclient/httpkey.h"
#include "messagebox/messagedialog.h"

/*********************   构造函数        *********************/
TemplateWidget::TemplateWidget(QWidget *parent) :
    QWidget(parent),ui(new Ui::TemplateWidget)
  ,clickType(0),saveType(NOSAVE), selectType(true)
{
    ui->setupUi(this);
    this->initControl();
}

/*********************   析构函数        *********************/
TemplateWidget::~TemplateWidget()
{
    delete ui;
}

/*********************  初始化控件       *********************/
void TemplateWidget::initControl()
{
    SETTABLEWIDGET(ui->tableWidgetTemplate);

    editTemnplate = new EditTemplate(this);
    addTemnplate = new EditTemplate(this);

    //根据分辨率适配
    QDesktopWidget *desktop = QApplication::desktop();

    if(desktop->height() >= GLOBALDEF::DESKTOPHEIGHT)
    {
        ui->labelSize->setMinimumHeight(30);
        this->setStyleSheet(GLOBALDEF::THISSTYLE);
    }
    else
    {
        ui->labelSize->setMinimumHeight(20);
        this->setStyleSheet(GLOBALDEF::SMALLSTYLE);
    }

    FlowLayout *flowLayout = new FlowLayout(ui->widgetControl);

    flowLayout->addWidget(ui->pushButtonAddTem);
    flowLayout->addWidget(ui->labelSize);

    ui->widgetControl->setLayout(flowLayout);
}

/*********************   显示窗口        *********************/
void TemplateWidget::showWidget()
{
    this->show();
    selectType = true;
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_TEM_LIST), PROTOCOL::URL_TEM_LIST);
    ui->tabWidgetTemplate->setHidden(true);
}

/*********************   解析JSON       *********************/
void TemplateWidget::readJson(QNetworkReply *reply, int type)
{
    if(NULL == reply || reply->error() != QNetworkReply::NoError)
    {
        MAINWINDOW->setStatusInfo();
        return;
    }

    int codeValue = 0;

    if(reply->error() == QNetworkReply::NoError)
    {
        QByteArray arrayData = reply->readAll();

        QJsonParseError err;
        QJsonDocument jsonDom = QJsonDocument::fromJson(QString(arrayData).toUtf8(), &err);

        qDebug()<<QString(arrayData);
        if(err.error == QJsonParseError::NoError)
        {
            QJsonObject jsonObject = jsonDom.object();

            if(jsonObject.contains(HTTPKEY::CODE))  codeValue = jsonObject.value(HTTPKEY::CODE).toInt();

            if(type == PROTOCOL::URL_TEM_ADD_TEM)
            {
                if(jsonObject.contains(HTTPKEY::TEMPLATEID))
                {
                    QString temId = jsonObject.value(HTTPKEY::TEMPLATEID).toString();
                    templateId = temId;
                    addTemnplate->setTemplateId(temId);
                    editTemnplate->setTemplateId(temId);
                }
            }

            QString errorMsg;
            if(jsonObject.contains(HTTPKEY::MSG))
            {
                QJsonObject jsonNextObj = jsonObject.value(HTTPKEY::MSG).toObject();

                if(ISERROR(codeValue))
                {
                    if(codeValue == SUBONE)        errorMsg = MESSAGE::NOTSHOPLOGIN;
                    else if(codeValue == SUBTWO)   errorMsg = MESSAGE::NOTADMINLOGIN;
                    else if(codeValue == SUBTHREE) errorMsg = MESSAGE::NOPRIORITY;

                    if(codeValue == SUBONE || codeValue == SUBTWO || codeValue == SUBTHREE)
                    {
                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        this->setHidden(true);
                        return;
                    }
                }

                if(type == PROTOCOL::URL_TEM_MAT_LIST)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO) errorMsg = MESSAGE::ERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    MapList mapList;
                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, mapList);

                    addTemnplate->setMapMatList(mapList);
                    editTemnplate->setMapMatList(mapList);
                }
                else if(type == PROTOCOL::URL_TEM_ADD_TEM)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)  errorMsg = MESSAGE::ADDERROR;
                        if(codeValue == TWO)   errorMsg = MESSAGE::TEMNOTNULL;
                        if(codeValue == THREE) errorMsg = MESSAGE::TEMEXIST;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectType = true;
                    if(clickType != CICKTYPE)
                    {
                        ui->tabWidgetTemplate->setHidden(true);
                        MESSAGEBOX->showMessageBox(this, GLOBALDEF::ADDSUCCESS, true);
                    }

                    saveType = HAVESAVE;

                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_TEM_LIST), PROTOCOL::URL_TEM_LIST);
                }
                else if(type == PROTOCOL::URL_TEM_ADD_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)  errorMsg = MESSAGE::ERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectType = false;
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::ADDSUCCESS, true);

                    QByteArray byteArray;
                    byteArray.append(POSTARG::TEMDETAIL.arg(templateId));

                    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_TEM_DETAILS), byteArray, PROTOCOL::URL_TEM_DETAILS);
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_TEM_MAT_TYPE_LIST), PROTOCOL::URL_TEM_MAT_TYPE_LIST);
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_TEM_LIST), PROTOCOL::URL_TEM_LIST);
                }
                else if(type == PROTOCOL::URL_TEM_LIST)
                {
                    if(ISERROR(codeValue))
                    {
                        ui->tableWidgetTemplate->clearContents();
                        ui->tableWidgetTemplate->setRowCount(0);
                        mapTemplateList.clear();
                        ui->labelSize->setText(GLOBALDEF::TOTALONUMBER.arg(0));
                        return;
                    }

                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, mapTemplateList);

                    this->setTableTemplateData();
                }
                else if(type == PROTOCOL::URL_TEM_DETAILS)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)  errorMsg = MESSAGE::ERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    ui->tabWidgetTemplate->addTab(ui->tabTemplateInfo, GLOBALDEF::TEMPLATEINFO);
                    ui->tabWidgetTemplate->removeTab(ui->tabWidgetTemplate->indexOf(ui->tabAddTemplate));
                    ui->tabWidgetTemplate->setCurrentWidget(ui->tabTemplateInfo);
                    ui->tabWidgetTemplate->show();

                    mapTemDetail.clear();

                    HTTPCLIENT->readJsonMap(jsonNextObj, HTTPKEY::RES, mapTemDetail);

                    if(jsonNextObj.contains(HTTPKEY::COUNT))
                    {
                        mapTemDetail[HTTPKEY::COUNT] = QString::number(jsonNextObj.value(HTTPKEY::COUNT).toInt());
                    }

                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::ITEM, mapItemList);

                    editTemnplate->setTemplateId(mapTemDetail.value(HTTPKEY::TEMPLATEID));
                    editTemnplate->setMapSelectList(mapItemList);

                    this->setControlInfoData();
                }
                else if(type == PROTOCOL::URL_TEM_UPDATE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)  errorMsg = MESSAGE::EDITERROR;
                        if(codeValue == TWO)   errorMsg = MESSAGE::TEMNOTNULL;
                        if(codeValue == THREE) errorMsg = MESSAGE::TEMEXIST;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectType = false;
                    ui->tabWidgetTemplate->setHidden(true);
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_TEM_LIST), PROTOCOL::URL_TEM_LIST);
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::EDITSUCCESS, true);
                }
                else if(type == PROTOCOL::URL_TEM_DEL_MAT)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::DELERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectType = false;
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::DELSUCCESS, true);

                    QByteArray byteArray;
                    byteArray.append(POSTARG::TEMDETAIL.arg(templateId));

                    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_TEM_DETAILS), byteArray, PROTOCOL::URL_TEM_DETAILS);
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_TEM_MAT_TYPE_LIST), PROTOCOL::URL_TEM_MAT_TYPE_LIST);
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_TEM_LIST), PROTOCOL::URL_TEM_LIST);
                }
                else if(type == PROTOCOL::URL_TEM_DELETE)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)  errorMsg = MESSAGE::DELERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    selectType = true;
                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_TEM_LIST), PROTOCOL::URL_TEM_LIST);
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::DELSUCCESS, true);

                    ui->tabWidgetTemplate->setHidden(true);
                }
                else if(type == PROTOCOL::URL_TEM_GET_MAT_LIST)
                {

                }
                else if(type == PROTOCOL::URL_TEM_MAT_TYPE_LIST)
                {

                }
            }
        }
    }
    reply->close();
}

/*********************  设置模板表格     *********************/
void TemplateWidget::setTableTemplateData()
{
    ui->labelSize->setText(GLOBALDEF::TOTALONUMBER.arg(mapTemplateList.size()));
    ui->tableWidgetTemplate->setRowCount(mapTemplateList.size());

    for(int i = 0; i < mapTemplateList.size(); i ++)
    {
        ui->tableWidgetTemplate->setItem(i, ZERO, DATA(mapTemplateList.at(i).value(HTTPKEY::TEMPLATENAME)));
        ui->tableWidgetTemplate->setItem(i, ONE,  DATA(mapTemplateList.at(i).value(HTTPKEY::COUNT)));

        SETTABLECENTER(ui->tableWidgetTemplate->item(i, ZERO));
        SETTABLECENTER(ui->tableWidgetTemplate->item(i, ONE));
    }

    if(selectType)
    {
        ui->tableWidgetTemplate->scrollToBottom();
        ui->tableWidgetTemplate->selectRow(ui->tableWidgetTemplate->rowCount() - 1);
    }
}

/*********************  设置模板详情     *********************/
void TemplateWidget::setControlInfoData()
{
    ui->lineEditTemplateNameInfo->setText(mapTemDetail.value(HTTPKEY::TEMPLATENAME));
    ui->lineEditRemarkInfo->setText(mapTemDetail.value(HTTPKEY::TEMPLATEREMARK));
    ui->labelTotalCountInfo->setText(GLOBALDEF::TOTALCOUNT.arg(mapTemDetail.value(HTTPKEY::COUNT)));

    ui->listWidgetData->clear();
    SAFEDELLIST(pushButtonList);
    pushButtonList.clear();

    for(int i = 0; i < mapItemList.size(); i ++)
    {
        QString matName = mapItemList.at(i).value(HTTPKEY::NAME);
        QString barCode =  mapItemList.at(i).value(HTTPKEY::BARCODE);

        QWidget *widget =  createWidget(matName, barCode);
        QListWidgetItem *lisItem = new QListWidgetItem(ui->listWidgetData);

        lisItem->setSizeHint(QSize(0, 70));

        ui->listWidgetData->addItem(lisItem);

        ui->listWidgetData->setItemWidget(lisItem, widget);
    }

}

/*********************  清空信息     *********************/
void TemplateWidget::clearInfo()
{
    ui->lineEditRemark->clear();
    ui->lineEditTemplateName->clear();
}

/*********************  创建信息面板     *********************/
QWidget * TemplateWidget::createWidget(QString matName, QString barCode)
{
    QWidget *widget = new QWidget(this);

    QHBoxLayout *hBoxLayout = new QHBoxLayout(widget);
    QVBoxLayout *vBoxLayout = new QVBoxLayout();
    QLabel *labelMatName = new QLabel(this);
    QLabel *labelBarCode = new QLabel(this);
    QPushButton *pushButtonDelete = new QPushButton(this);

    pushButtonDelete->setFixedSize(QSize(36, 36));

    connect(pushButtonDelete, SIGNAL(clicked(bool)), this, SLOT(deleteMaterial()));

    pushButtonList.append(pushButtonDelete);

    labelMatName->setText(matName);
    labelBarCode->setText(barCode);

    labelMatName->setFont(QFont(GLOBALDEF::FONTNAME, ELEVEN, QFont::Bold));
    labelBarCode->setFont(QFont(GLOBALDEF::FONTNAME, ELEVEN));

    vBoxLayout->addWidget(labelMatName);
    vBoxLayout->addWidget(labelBarCode);

    hBoxLayout->addLayout(vBoxLayout);
    hBoxLayout->addWidget(pushButtonDelete);

    return widget;
}

/*********************  添加模板     *********************/
void TemplateWidget::on_pushButtonAddTem_clicked()
{
    saveType = NOSAVE;
    this->clearInfo();
    ui->tabWidgetTemplate->addTab(ui->tabAddTemplate, GLOBALDEF::ADDTEMPLATE);
    ui->tabWidgetTemplate->removeTab(ui->tabWidgetTemplate->indexOf(ui->tabTemplateInfo));
    ui->tabWidgetTemplate->setCurrentWidget(ui->tabAddTemplate);
    ui->tabWidgetTemplate->show();

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_TEM_MAT_TYPE_LIST), PROTOCOL::URL_TEM_MAT_TYPE_LIST);
}

/*********************  模板信息     *********************/
void TemplateWidget::on_tableWidgetTemplate_clicked(const QModelIndex &index)
{
    if(index.row() >= mapTemplateList.size()) return;
    templateId = mapTemplateList.at(index.row()).value(HTTPKEY::TEMPLATEID);

    QByteArray byteArray;
    byteArray.append(POSTARG::TEMDETAIL.arg(templateId));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_TEM_DETAILS), byteArray, PROTOCOL::URL_TEM_DETAILS);
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_TEM_MAT_TYPE_LIST), PROTOCOL::URL_TEM_MAT_TYPE_LIST);
}

/*********************  保存     *********************/
void TemplateWidget::on_pushButtonSave_clicked()
{
    if(saveType == HAVESAVE) return;
    clickType = SELECTTYPE;
    if(ui->lineEditTemplateName->text().isEmpty())
    {
        MESSAGEBOX->showMessageBox(this, MESSAGE::TEMNAMEISNULL);
        return;
    }

    QByteArray byteArray;
    byteArray.append(POSTARG::ADDTEMPLATE.arg(ui->lineEditTemplateName->text(), ui->lineEditRemark->text()));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_TEM_ADD_TEM), byteArray, PROTOCOL::URL_TEM_ADD_TEM);
}

/*********************  删除模板     *********************/
void TemplateWidget::on_pushButtonDelTem_clicked()
{
    QByteArray byteArray;
    byteArray.append(POSTARG::TEMDELETE.arg(mapTemDetail.value(HTTPKEY::TEMPLATEID)));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_TEM_DELETE), byteArray, PROTOCOL::URL_TEM_DELETE);
}

/*********************  添加原料模板     *********************/
void TemplateWidget::on_pushButtonAddTemMatInfo_clicked()
{
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_TEM_MAT_LIST), PROTOCOL::URL_TEM_MAT_LIST);
    editTemnplate->showWidget();
}


/*********************  添加原料模板     *********************/
void TemplateWidget::on_pushButtonAddTemMat_clicked()
{
    if(saveType != HAVESAVE) on_pushButtonSave_clicked();

    if(ui->lineEditTemplateName->text().isEmpty()) return;

    MapList mapListData;
    addTemnplate->setMapSelectList(mapListData);

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_TEM_MAT_LIST), PROTOCOL::URL_TEM_MAT_LIST);
    addTemnplate->showWidget();
    clickType = CICKTYPE;
}

/*********************  更新信息     *********************/
void TemplateWidget::on_pushButtonSaveInfo_clicked()
{
    QByteArray byteArray;
    byteArray.append(POSTARG::TEMUPDATE.arg(templateId, ui->lineEditTemplateNameInfo->text(), ui->lineEditRemarkInfo->text()));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_TEM_UPDATE), byteArray, PROTOCOL::URL_TEM_UPDATE);
}

/*********************  取消函数     *********************/
void TemplateWidget::on_pushButtonCancelInfo_clicked()
{
    ui->tabWidgetTemplate->setHidden(true);
}

/*********************  取消函数     *********************/
void TemplateWidget::on_pushButtonCancel_clicked()
{
    ui->tabWidgetTemplate->setHidden(true);
}

/*********************  删除原料     *********************/
void TemplateWidget::deleteMaterial()
{
    QPushButton *pButton = qobject_cast<QPushButton *>(sender());

    for(int i = 0; i < pushButtonList.size(); i ++)
    {
        if(pButton == pushButtonList.at(i))
        {
            if(i < mapItemList.size())
            {
                List listId;

                listId.append(mapItemList.at(i).value(HTTPKEY::MATERIALID));

                QByteArray byteArray;
                byteArray.append(POSTARG::TEMDELMATERIAL.arg(templateId, HTTPCLIENT->makeJson(listId)));

                HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_TEM_DEL_MAT), byteArray, PROTOCOL::URL_TEM_DEL_MAT);

            }
        }
    }
}
