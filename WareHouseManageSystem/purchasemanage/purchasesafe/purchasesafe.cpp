#include "purchasesafe.h"
#include "ui_purchasesafe.h"
#include "httpclient/httpkey.h"
#include "messagebox/messagedialog.h"

/*********************  构造函数       *********************/
PurchaseSafe::PurchaseSafe(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PurchaseSafe)
{
    ui->setupUi(this);

    SETTABLEWIDGET(ui->tableWidget);

    confirmSafeMat = new ConfirmSafeMat(this);

    //根据分辨率适配
    QDesktopWidget *desktop = QApplication::desktop();

    int minHeight = 0;
    if(desktop->height() >= GLOBALDEF::DESKTOPHEIGHT)
    {
        minHeight = 30;
        this->setStyleSheet(GLOBALDEF::THISSTYLE);
        ui->labelContents->setWordWrap(false);
    }
    else
    {
        minHeight = 20;
        this->setStyleSheet(GLOBALDEF::SMALLSTYLE);
        ui->labelContents->setWordWrap(true);
    }

    ui->labelSize->setMinimumHeight(minHeight);
    ui->labelContents->setMinimumHeight(minHeight);

    FlowLayout *flowLayout = new FlowLayout(ui->widgetControl);

    flowLayout->addWidget(ui->pushButtonAllSelect);
    flowLayout->addWidget(ui->pushButtonNoSelect);
    flowLayout->addWidget(ui->pushButtonSure);
    flowLayout->addWidget(ui->labelSize);
    flowLayout->addWidget(ui->labelContents);

    ui->widgetControl->setLayout(flowLayout);
}

/*********************  析构函数       *********************/
PurchaseSafe::~PurchaseSafe()
{
    delete ui;
}

/*********************  解析json       *********************/
void PurchaseSafe::readJson(QNetworkReply *reply, int type)
{
    if(NULL == reply || reply->error() != QNetworkReply::NoError)
    {
        MAINWINDOW->setStatusInfo();
        return;
    }

    int codeValue = -1;
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

            QString errorMsg;
            if(jsonObject.contains(HTTPKEY::MSG))
            {
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

                if(type == PROTOCOL::URL_SAFETY_SEL)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }
                    HTTPCLIENT->readJsonList(jsonObject, HTTPKEY::MSG, selMatMapList);

                    this->setSelMatMapData();
                }
                else if(type == PROTOCOL::URL_SAFETY_AFFIRM)
                {
                    if(ISERROR(codeValue))
                    {
                        if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                        else if(codeValue == TWO) errorMsg = MESSAGE::DATAERROR;

                        MESSAGEBOX->showMessageBox(this, errorMsg);
                        return;
                    }

                    ui->tabWidgetSuggestPur->setHidden(true);

                    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_SAFETY_SEL), PROTOCOL::URL_SAFETY_SEL);
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::SUCCESS, true);
                }
            }
        }
        reply->close();
    }
}


/*********************  显示窗口       *********************/
void PurchaseSafe::showWidget()
{
    this->show();
    ui->tabWidgetSuggestPur->setHidden(true);

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_SAFETY_SEL), PROTOCOL::URL_SAFETY_SEL);
}

/*********************  全选       *********************/
void PurchaseSafe::on_pushButtonAllSelect_clicked()
{
    for(int i = 0; i < ui->tableWidget->rowCount(); i ++)
    {
        ui->tableWidget->item(i, 0)->setCheckState(Qt::Checked);
    }
}

/*********************  全不选       *********************/
void PurchaseSafe::on_pushButtonNoSelect_clicked()
{
    for(int i = 0; i < ui->tableWidget->rowCount(); i ++)
    {
        ui->tableWidget->item(i, 0)->setCheckState(Qt::Unchecked);
    }
}

/*********************  确认采购       *********************/
void PurchaseSafe::on_pushButtonSure_clicked()
{
    bool flage = false;
    for(int i = 0; i < ui->tableWidget->rowCount(); i ++)
    {
        if(ui->tableWidget->item(i, 0)->checkState() == Qt::Checked)
        {
            flage = true;
        }
    }

    if(!flage)
    {
        MESSAGEBOX->showMessageBox(this, MESSAGE::PLEASESELECTMAT);

        return;
    }

    MapList mapListData;
    for(int i = 0; i < ui->tableWidget->rowCount(); i ++)
    {
        if(ui->tableWidget->item(i, 0)->checkState() == Qt::Checked)
        {
            if(i >= selMatMapList.size()) return;
            mapListData.append(selMatMapList.at(i));
        }
    }

    confirmSafeMat->setMapListMat(mapListData);
    confirmSafeMat->showWidget();
}

/*********************  设置控件数据       *********************/
void PurchaseSafe::setControlData(int index)
{
    if(index < 0 || index >= selMatMapList.size()) return;

    ui->lineEditMatName->setText(selMatMapList.at(index).value(HTTPKEY::MATERIALNAME));
    ui->lineEditBarCode->setText(selMatMapList.at(index).value(HTTPKEY::BARCODE));
    ui->lineEditSafeTop->setText(selMatMapList.at(index).value(HTTPKEY::UPPERLIMIT));
    ui->lineEditNowInv->setText(selMatMapList.at(index).value(HTTPKEY::INVENTORY));
    ui->lineEditStorageNumber->setText(selMatMapList.at(index).value(HTTPKEY::STORAGE));
    ui->lineEditSuggestNumber->setText(selMatMapList.at(index).value(HTTPKEY::NUMBER));
    ui->lineEditUnit->setText(selMatMapList.at(index).value(HTTPKEY::UNITNAME));
    ui->lineEditSpec->setText(selMatMapList.at(index).value(HTTPKEY::STANDARD));
    ui->lineEditDefaultSupplier->setText(selMatMapList.at(index).value(HTTPKEY::SUPPLIERNAME));
    ui->lineEditPurNumber->setText(selMatMapList.at(index).value(HTTPKEY::PURCHASE));
    ui->lineEditSafeLower->setText(selMatMapList.at(index).value(HTTPKEY::LOWERLIMIT));
}

/*********************  设置数据       *********************/
void PurchaseSafe::setSelMatMapData()
{
    ui->labelSize->setText(GLOBALDEF::TOTALONUMBER.arg(selMatMapList.size()));

    selMatMapList.size() > 0 ? ui->labelContents->setHidden(true) : ui->labelContents->show();

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(selMatMapList.size());
    for(int i = 0; i < selMatMapList.size(); i ++)
    {
        ui->tableWidget->setItem(i, ZERO,  DATA(selMatMapList.at(i).value(HTTPKEY::MATERIALNAME)));
        ui->tableWidget->setItem(i, ONE,   DATA(selMatMapList.at(i).value(HTTPKEY::NUMBER)));
        ui->tableWidget->setItem(i, TWO,   DATA(selMatMapList.at(i).value(HTTPKEY::UNITNAME)));

        SETTABLECENTER(ui->tableWidget->item(i, ZERO));
        SETTABLECENTER(ui->tableWidget->item(i, ONE));
        SETTABLECENTER(ui->tableWidget->item(i, TWO));

        ui->tableWidget->item(i, ZERO)->setCheckState(Qt::Unchecked);
    }

    ui->tableWidget->scrollToBottom();
}

/*********************  单击事件       *********************/
void PurchaseSafe::on_tableWidget_clicked(const QModelIndex &index)
{
    ui->tabWidgetSuggestPur->show();
    this->setControlData(index.row());

    if(ui->tableWidget->item(index.row(), 0)->checkState() == Qt::Checked)
    {
        ui->tableWidget->item(index.row(), 0)->setCheckState(Qt::Unchecked);
    }
    else
    {
        ui->tableWidget->item(index.row(), 0)->setCheckState(Qt::Checked);
    }

    if(index.row() >= selMatMapList.size()) return;
    if(selMatMapList.at(index.row()).value(HTTPKEY::SUPPLIERNAME).isEmpty())
    {
        MESSAGEBOX->showMessageBox(this, tr("未设置默认供应商！"));
        return;
    }
}
