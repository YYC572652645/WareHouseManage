#include "templatepur.h"
#include "ui_templatepur.h"
#include "messagebox/messagedialog.h"
#include "httpclient/httpkey.h"

/*********************  构造函数       *********************/
TemplatePur::TemplatePur(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TemplatePur)
{
    ui->setupUi(this);
    this->initControl();
}

/*********************  析构函数       *********************/
TemplatePur::~TemplatePur()
{
    delete ui;
}

/*********************  初始化控件       *********************/
void TemplatePur::initControl()
{
    titleBar = new TitleBar(this);
    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    SETTABLEWIDGET(ui->tableWidgetSetNumber);
}

/*********************  改变事件        *********************/
void TemplatePur::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  设置采购订单列表        *********************/
void TemplatePur::setPurMapList(const MapList &value)
{
    purMapList = value;
    spinBoxMap.clear();

    SAFEDELLIST(widgetList);
    ui->tableWidgetSetNumber->clearContents();
    ui->tableWidgetSetNumber->clearSpans();

    ui->tableWidgetSetNumber->setRowCount(purMapList.size());
    for(int i = 0; i < purMapList.size(); i ++)
    {
        ui->tableWidgetSetNumber->setItem(i, ZERO, DATA(purMapList.at(i).value(HTTPKEY::MATERIALNAME)));
        ui->tableWidgetSetNumber->setItem(i, ONE,  DATA(purMapList.at(i).value(HTTPKEY::BARCODE)));
        ui->tableWidgetSetNumber->setItem(i, TWO,  DATA(purMapList.at(i).value(HTTPKEY::INVENTORY) + purMapList.at(i).value(HTTPKEY::ISWAREHOUSEUNITNAME)));

        if(purMapList.at(i).value(HTTPKEY::SUPPLIERID) != "0")
        {
            QWidget *widget = new QWidget(this);
            QHBoxLayout *hboxLayout = new QHBoxLayout(widget);
            QDoubleSpinBox *spinBoxNumber = new QDoubleSpinBox(this);
            hboxLayout->addWidget(spinBoxNumber);
            widget->setLayout(hboxLayout);
            hboxLayout->setContentsMargins(0, 0, 0, 0);
            ui->tableWidgetSetNumber->setCellWidget(i, THREE, widget);
            spinBoxMap[i] = spinBoxNumber;
            widgetList.append(widget);

            spinBoxNumber->setMinimumHeight(ui->tableWidgetSetNumber->rowHeight(i));

            ui->tableWidgetSetNumber->setItem(i, FOUR, DATA(purMapList.at(i).value(HTTPKEY::ISPRICEUNITNAME)));
            SETTABLECENTER(ui->tableWidgetSetNumber->item(i, FOUR));
        }
        else
        {
            ui->tableWidgetSetNumber->setItem(i, THREE, DATA(tr("未设置供应商")));
            ui->tableWidgetSetNumber->setSpan(i, THREE, ONE, TWO);
            ui->tableWidgetSetNumber->item(i, THREE)->setTextColor(Qt::red);

            ui->tableWidgetSetNumber->item(i, THREE)->setTextAlignment(Qt::AlignCenter);
            ui->tableWidgetSetNumber->item(i, THREE)->setFont(QFont("ZYSong", 12, QFont::Bold));
        }


        SETTABLECENTER(ui->tableWidgetSetNumber->item(i, 0));
        SETTABLECENTER(ui->tableWidgetSetNumber->item(i, ONE));
        SETTABLECENTER(ui->tableWidgetSetNumber->item(i, TWO));
    }

    ui->tableWidgetSetNumber->scrollToBottom();
}

/*********************  设置模板列表       *********************/
void TemplatePur::setMapListTemplate(const MapList &value)
{
    mapListTemplate = value;

    ui->listWidgetData->clear();
    for(int i = 0; i < mapListTemplate.size(); i ++)
    {
        QString templateName = mapListTemplate.at(i).value(HTTPKEY::TEMPLATENAME);
        QString number =  mapListTemplate.at(i).value(HTTPKEY::MATERIALNUMBER);

        QWidget *widget =  createWidget(templateName, number);
        QListWidgetItem *lisItem = new QListWidgetItem(ui->listWidgetData);

        lisItem->setSizeHint(QSize(0, 70));

        ui->listWidgetData->addItem(lisItem);

        ui->listWidgetData->setItemWidget(lisItem, widget);
    }
}

/*********************  显示窗口       *********************/
void TemplatePur::showWidget()
{
    titleBar->setTitle(GLOBALDEF::TEMPLATEPUR);
    ui->tableWidgetSetNumber->setHidden(true);
    ui->commandLinkButtonOrder->setHidden(true);
    ui->labelSize->setHidden(true);
    this->show();
}

/*********************  隐藏窗口       *********************/
void TemplatePur::setHide()
{
    ui->tableWidgetSetNumber->setHidden(true);
    ui->commandLinkButtonOrder->setHidden(true);
    ui->labelSize->setHidden(true);
}

/*********************  显示窗口       *********************/
void TemplatePur::setShow()
{
    ui->tableWidgetSetNumber->show();
    ui->commandLinkButtonOrder->show();
    ui->labelSize->show();
}

/*********************  生成采购订单       *********************/
void TemplatePur::on_commandLinkButtonOrder_clicked()
{
    QByteArray byteArray;
    MapList mapListData;

    for(int i = 0; i < purMapList.size(); i ++)
    {
        if(purMapList.at(i).value(HTTPKEY::SUPPLIERID) != "0")
        {
            Map mapData;

            mapData[HTTPKEY::MATERIALID]     = purMapList.at(i).value(HTTPKEY::MATERIALID);
            mapData[HTTPKEY::PURCHASEUNIT]   = purMapList.at(i).value(HTTPKEY::ISPRICEUNIT);
            mapData[HTTPKEY::SUPPLIERID]     = purMapList.at(i).value(HTTPKEY::SUPPLIERID);
            mapData[HTTPKEY::PURCHASEAMOUNT] = QString::number(spinBoxMap.value(i)->value());
            mapData[HTTPKEY::PURCHASEPRICE]  = purMapList.at(i).value(HTTPKEY::PURCHASEPRICE);

            mapListData.append(mapData);
        }
    }

    byteArray.append(POSTARG::EXPORTPUR.arg(HTTPCLIENT->makeJson(mapListData)));

    bool flage = false;
    for(auto iter = spinBoxMap.begin(); iter != spinBoxMap.end(); iter ++)
    {
        if(iter.value()->value() != 0)
        {
            flage = true;
        }
    }

    if(flage)
    {
        int ok = MESSAGEBOX->showMessageBox(this, MESSAGE::MAKEPURMAT, true, false);

        if(ok == QDialog::Accepted)
        {
            HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_PUR_TEMPLATE_ADD), byteArray, PROTOCOL::URL_PUR_TEMPLATE_ADD);
        }
    }
    else
    {
        MESSAGEBOX->showMessageBox(this, MESSAGE::NOPURMAT, false, true);
    }
}

/*********************  创建信息面板     *********************/
QWidget *TemplatePur::createWidget(QString templateName, QString number)
{
    QWidget *widget = new QWidget(this);

    QHBoxLayout *hBoxLayout = new QHBoxLayout(widget);
    QLabel *labelTempalteName = new QLabel(this);
    QLabel *labelNumber = new QLabel(this);

    labelTempalteName->setText(templateName);
    labelNumber->setText(number);

    labelTempalteName->setFont(QFont(GLOBALDEF::FONTNAME, ELEVEN, QFont::Bold));
    labelNumber->setFont(QFont(GLOBALDEF::FONTNAME, ELEVEN));

    hBoxLayout->addWidget(labelTempalteName);
    hBoxLayout->addWidget(labelNumber);

    return widget;
}

/*********************  双击击控件       *********************/
void TemplatePur::on_listWidgetData_doubleClicked(const QModelIndex &index)
{
    qDebug()<<index.row()<<mapListTemplate.size();
    if(index.row() >= mapListTemplate.size()) return;

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_PUR_NUMBER).arg(mapListTemplate.at(index.row()).value(HTTPKEY::TEMPLATEID)), PROTOCOL::URL_PUR_NUMBER);
}
