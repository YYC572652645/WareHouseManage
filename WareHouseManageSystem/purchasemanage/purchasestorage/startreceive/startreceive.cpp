#include "startreceive.h"
#include "ui_startreceive.h"
#include "messagebox/messagedialog.h"
#include "httpclient/httpkey.h"

/*********************  构造函数       *********************/
StartReceive::StartReceive(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartReceive)
{
    ui->setupUi(this);
    this->initControl();
}

/*********************  析构函数       *********************/
StartReceive::~StartReceive()
{
    delete ui;
}

/*********************  初始化控件       *********************/
void StartReceive::initControl()
{
    titleBar = new TitleBar(this);

    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);
}

/*********************  改变事件        *********************/
void StartReceive::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  设置入库单号     *********************/
void StartReceive::setStoNumber(const QString &value)
{
    stoNumber = value;
}

/*********************  设置原料列表       *********************/
void StartReceive::setMapListMat(const MapList &value)
{
    mapListMat = value;

    SAFEDELLIST(checkBoxList);
    checkBoxList.clear();
    ui->listWidgetData->clear();

    spinBoxListList.clear();

    for(int i = 0; i < mapListMat.size(); i ++)
    {
        QString matName = mapListMat.at(i).value(HTTPKEY::MATERIALNAME);
        QString barCode =  mapListMat.at(i).value(HTTPKEY::BARCODE);

        QString number =  mapListMat.at(i).value(HTTPKEY::STORAGEAMOUNT) + mapListMat.at(i).value(HTTPKEY::UNITNAME);

        if(i < mapListListWshe.size())
        {
            QWidget *widget = createWidget(matName, barCode, number, mapListListWshe.at(i));

            QListWidgetItem *lisItem = new QListWidgetItem(ui->listWidgetData);

            lisItem->setSizeHint(QSize(0, 70));

            ui->listWidgetData->addItem(lisItem);

            ui->listWidgetData->setItemWidget(lisItem, widget);
        }
    }


    ui->labelContent->setText(tr("共%1项原料 已确认0项").arg(mapListMat.size()));
}

/*********************  显示窗口       *********************/
void StartReceive::showWidget()
{
    titleBar->setTitle(GLOBALDEF::STARTRECEIVE);
    ui->checkBoxAllSelect->setChecked(false);
    ui->checkBoxAllSelect->setText(tr("全选"));
    ui->checkBoxAllSelect->setIcon(QIcon(GLOBALDEF::ALLSELECTIMAGE));
    this->show();
}

/*********************  确认采购       *********************/
void StartReceive::on_pushButtonConfirm_clicked()
{
    int dataCount = 0;

    for(int i = 0; i < checkBoxList.size(); i ++)
    {
        if(!checkBoxList.at(i)->isChecked())
        {
            dataCount ++;
        }
    }

    MapList mapListData;

    for(int i = 0; i < checkBoxList.size(); i ++)
    {
        if(checkBoxList.at(i)->isChecked())
        {
            if(i < spinBoxListList.size() && i < mapListListWshe.size())
            {
                for(int j = 0; j < spinBoxListList.at(i).size(); j ++)
                {
                    Map mapData;
                    if(j < mapListListWshe.at(i).size() && i < mapListMat.size())
                    {
                        if(spinBoxListList.at(i).at(j)->value() != 0)
                        {
                            mapData[HTTPKEY::NUMBER]      = QString::number(spinBoxListList.at(i).at(j)->value());
                            mapData[HTTPKEY::MATERIALID]  = mapListMat.at(i).value(HTTPKEY::MATERIALID);
                            mapData[HTTPKEY::WAREHOUSEID] = mapListListWshe.at(i).at(j).value(HTTPKEY::WAREHOUSEID);
                        }
                    }
                    if(!mapData.isEmpty()) mapListData.append(mapData);
                }
            }
        }
    }

    if(mapListData.size() <= 0)
    {
        MESSAGEBOX->showMessageBox(this, tr("请至少输入一个数量！"));
        return;
    }

    QByteArray byteArray;
    byteArray.append(POSTARG::STOAFFIRM.arg(stoNumber, HTTPCLIENT->makeJson(mapListData)));

    if(dataCount != 0)
    {
        int ok =  MESSAGEBOX->showMessageBox(this, tr("还有%1项原料未确认，要继续吗？").arg(dataCount), true, false);

        if(ok == QDialog::Accepted)
        {
            HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_STO_CONFIRM), byteArray, PROTOCOL::URL_STO_CONFIRM);
        }
    }
    else
    {
        HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_STO_CONFIRM) , byteArray, PROTOCOL::URL_STO_CONFIRM);
    }

    this->close();
}

/*********************  全选       *********************/
void StartReceive::on_checkBoxAllSelect_clicked()
{
    bool checkFlage = ui->checkBoxAllSelect->isChecked();

    if(checkFlage)
    {
        ui->checkBoxAllSelect->setText(tr("全不选"));
        ui->checkBoxAllSelect->setIcon(QIcon(GLOBALDEF::NOTSELECTIMAGE));

        ui->labelContent->setText(tr("共%1项原料 已确认%1项").arg(mapListMat.size()));


    }
    else
    {
        ui->checkBoxAllSelect->setText(tr("全选"));
        ui->checkBoxAllSelect->setIcon(QIcon(GLOBALDEF::ALLSELECTIMAGE));

        ui->labelContent->setText(tr("共%1项原料 已确认0项").arg(mapListMat.size()));
    }

    for(int i = 0; i < checkBoxList.size(); i ++)
    {
        checkBoxList.at(i)->setChecked(checkFlage);
    }
}

/*********************  创建信息面板     *********************/
QWidget *StartReceive::createWidget(QString matName, QString barCode, QString number, MapList mapListData)
{
    QList<QDoubleSpinBox *>spinBoxList;

    QWidget *widget = new QWidget(this);

    QHBoxLayout *hBoxLayout = new QHBoxLayout(widget);
    QVBoxLayout *vBoxLayout = new QVBoxLayout();

    QCheckBox *checkBox = new QCheckBox(this);
    QLabel *labelMatName = new QLabel(this);
    QLabel *labelBarCode = new QLabel(this);
    QLabel *labelNumber = new QLabel(this);
    QLabel *labelWhse = new QLabel(this);
    QComboBox *comboBoxWhse = new QComboBox(this);
    comboBoxWhse->setFocusPolicy(Qt::NoFocus);

    labelWhse->setText(tr("仓库设置："));
    checkBox->setMaximumSize(50, 50);
    checkBoxList.append(checkBox);
    labelMatName->setText(matName);
    labelBarCode->setText(barCode);
    labelNumber->setText(number);

    labelMatName->setFont(QFont(GLOBALDEF::FONTNAME, TWELEVE, QFont::Bold));
    labelBarCode->setFont(QFont(GLOBALDEF::FONTNAME, ELEVEN));
    labelNumber->setFont(QFont(GLOBALDEF::FONTNAME,  ELEVEN));
    labelWhse->setFont(QFont(GLOBALDEF::FONTNAME,    ELEVEN));

    vBoxLayout->addWidget(labelBarCode);
    vBoxLayout->addWidget(labelNumber);

    QVBoxLayout *vBoxLayoutBox = new QVBoxLayout();
    vBoxLayoutBox->addWidget(labelWhse);
    vBoxLayoutBox->addWidget(comboBoxWhse);

    hBoxLayout->addWidget(checkBox);
    hBoxLayout->addWidget(labelMatName);
    hBoxLayout->addLayout(vBoxLayout);
    hBoxLayout->addLayout(vBoxLayoutBox);

    QListWidget *listWhseWidget = new QListWidget(this);
    comboBoxWhse->setModel(listWhseWidget->model());
    comboBoxWhse->setView(listWhseWidget);
    comboBoxWhse->view()->setMinimumWidth(400);

    for(int i = 0; i < mapListData.size(); i ++)
    {
        QWidget *widgetItem = new QWidget(this);
        QLabel *labelName = new QLabel(this);
        QHBoxLayout *hBoxLayoutItem = new QHBoxLayout(widgetItem);
        QVBoxLayout *vBoxLayoutItem = new QVBoxLayout();
        labelName->setMinimumWidth(100);

        //分配数量
        QHBoxLayout *hBoxLayoutNumber = new QHBoxLayout();
        QLabel *labelNumber = new QLabel(this);
        labelNumber->setText(tr("分配数量："));
        labelNumber->setMinimumWidth(60);

        QLabel *labelDataNumber = new QLabel(this);
        labelDataNumber->setMinimumWidth(150);
        labelDataNumber->setMinimumHeight(30);

        hBoxLayoutNumber->addWidget(labelNumber);
        hBoxLayoutNumber->addWidget(labelDataNumber);

        //收货数量
        QHBoxLayout *hBoxLayoutRealNumber = new QHBoxLayout();
        QLabel *labelRealNumber = new QLabel(this);
        labelRealNumber->setText(tr("收货数量："));
        labelRealNumber->setMinimumWidth(60);

        QLabel *labelDataRealNumber = new QLabel(this);
        labelDataRealNumber->setMinimumWidth(150);
        labelDataRealNumber->setMinimumHeight(30);

        hBoxLayoutRealNumber->addWidget(labelRealNumber);
        hBoxLayoutRealNumber->addWidget(labelDataRealNumber);

        //输入数量
        QHBoxLayout *hBoxLayoutUserNumber = new QHBoxLayout();
        QLabel *labelUserNumber = new QLabel(this);
        labelUserNumber->setText(tr("输入数量："));
        labelUserNumber->setMinimumWidth(60);

        QDoubleSpinBox *spinBoxUserNumber = new QDoubleSpinBox(this);
        spinBoxUserNumber->setMinimumWidth(150);
        spinBoxUserNumber->setMinimumHeight(30);

        hBoxLayoutUserNumber->addWidget(labelUserNumber);
        hBoxLayoutUserNumber->addWidget(spinBoxUserNumber);

        spinBoxList.append(spinBoxUserNumber);

        vBoxLayoutItem->addLayout(hBoxLayoutNumber);
        vBoxLayoutItem->addLayout(hBoxLayoutRealNumber);
        vBoxLayoutItem->addLayout(hBoxLayoutUserNumber);

        labelName->setFont(QFont(GLOBALDEF::FONTNAME,  TWELEVE, QFont::Bold));

        labelName->setText(mapListData.at(i).value(HTTPKEY::NAME));
        labelDataNumber->setText(mapListData.at(i).value(HTTPKEY::NUMBER));
        labelDataRealNumber->setText(mapListData.at(i).value(HTTPKEY::REALITYNUMBER));

        double number = mapListData.at(i).value(HTTPKEY::NUMBER).toDouble();
        double realNumber = mapListData.at(i).value(HTTPKEY::REALITYNUMBER).toDouble();

        spinBoxUserNumber->setMaximum(number - realNumber);

        hBoxLayoutItem->addWidget(labelName);
        hBoxLayoutItem->addLayout(vBoxLayoutItem);

        QListWidgetItem *listWidgetItem = new QListWidgetItem(listWhseWidget);
        listWidgetItem->setSizeHint(QSize(0, 120));
        listWhseWidget->setItemWidget(listWidgetItem, widgetItem);
    }

    spinBoxListList.append(spinBoxList);
    return widget;
}

/*********************  设置仓库     *********************/
void StartReceive::setMapListListWshe(const QList<MapList> &value)
{
    mapListListWshe = value;
}

/*********************  单击选中     *********************/
void StartReceive::on_listWidgetData_clicked(const QModelIndex &index)
{
    if(index.row() > checkBoxList.size()) return;

    bool flage = checkBoxList.at(index.row())->isChecked() ? false : true;

    checkBoxList.at(index.row())->setChecked(flage);


    int dataCount = 0;

    for(int i = 0; i < checkBoxList.size(); i ++)
    {
        if(checkBoxList.at(i)->isChecked())
        {
            dataCount ++;
        }
    }

    ui->labelContent->setText(tr("共%1项原料 已确认%2项").arg(mapListMat.size()).arg(dataCount));
}
