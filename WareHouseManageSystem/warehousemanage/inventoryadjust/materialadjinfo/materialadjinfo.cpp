#include "materialadjinfo.h"
#include "ui_materialadjinfo.h"
#include "httpclient/httpkey.h"
#include "messagebox/messagedialog.h"

/*********************  构造函数        *********************/
MaterialAdjInfo::MaterialAdjInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::materialadjinfo)
{
    ui->setupUi(this);
    this->initControl();
}

/*********************  析构函数        *********************/
MaterialAdjInfo::~MaterialAdjInfo()
{
    delete ui;
}

/*********************  显示窗口        *********************/
void MaterialAdjInfo::showWidget()
{
    titleBar->setTitle(GLOBALDEF::MATERIALINFO);
    this->show();
}

/*********************  设置控件数据        *********************/
void MaterialAdjInfo::setControlData()
{
    ui->comboBoxUnit->clear();
    for(int i = 0; i < unitMapList.size(); i ++)
    {
        QString unitName = unitMapList.at(i).value(HTTPKEY::NAME);
        ui->comboBoxUnit->addItem(unitName);
    }

    QString unitName = matMap.value(HTTPKEY::UNITNAME);
    ui->comboBoxUnit->setCurrentText(unitName);

    ui->comboBoxUnit->setCurrentText(unitName);
    ui->labelUnitPrice->setText(tr("单价(元/%1)：").arg(matMap.value(HTTPKEY::ISPRICENAME)));
    ui->labelNumber->setText(tr("账面数量(%1)：").arg(unitName));
    ui->labelAdjustNumber->setText(tr("调整数量(%1)：").arg(unitName));
    ui->labelLaterNumber->setText(tr("调整后数量(%1)：").arg(unitName));

    ui->lineEditBarCode->setText(matMap.value(HTTPKEY::BARCODE));
    ui->lineEditMatName->setText(matMap.value(HTTPKEY::MATERIALNAME));
    ui->lineEditPrice->setText(matMap.value(HTTPKEY::UNITPRICE));
    ui->lineEditNumber->setText(matMap.value(HTTPKEY::NUMBER));
    ui->lineEditReason->setText(matMap.value(HTTPKEY::REASON));
    ui->spinBoxAdjustNumber->setValue(matMap.value(HTTPKEY::ADJUSTQUANTITY).toDouble());
    ui->lineEditLateNumber->setText(matMap.value(HTTPKEY::LASTNUMBER));
}

/*********************  设置隐藏        *********************/
void MaterialAdjInfo::setHide()
{
    ui->pushButtonDel->setHidden(true);
    ui->pushButtonCancel->setHidden(true);
    ui->pushButtonSave->setHidden(true);

    ui->comboBoxUnit->setEnabled(false);
    ui->spinBoxAdjustNumber->setEnabled(false);
    ui->pushButtonSelectReason->setEnabled(false);
}

/*********************  设置显示        *********************/
void MaterialAdjInfo::setShow()
{
    ui->pushButtonDel->show();
    ui->pushButtonCancel->show();
    ui->pushButtonSave->show();

    ui->comboBoxUnit->setEnabled(true);
    ui->spinBoxAdjustNumber->setEnabled(true);
    ui->pushButtonSelectReason->setEnabled(true);
}

/*********************  保存数据        *********************/
void MaterialAdjInfo::on_pushButtonSave_clicked()
{
    if(ui->comboBoxUnit->currentIndex() < 0 || ui->comboBoxUnit->currentIndex() >= unitMapList.size()) return;

    QByteArray byteArray;

    QString strPost = POSTARG::ADJUPDATEMAT.arg(ui->spinBoxAdjustNumber->value());

    strPost = strPost.arg(oddNumber, matMap.value(HTTPKEY::MATERIALID));

    QString reasonText = ui->lineEditReason->text();

    strPost = strPost.arg(reasonText, unitMapList.at(ui->comboBoxUnit->currentIndex()).value(HTTPKEY::UNITID));

    strPost = strPost.arg(wareHouseId);

    byteArray.append(strPost);

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_ADJ_UPDATE_MAT), byteArray, PROTOCOL::URL_ADJ_UPDATE_MAT);

    this->close();
}

/*********************  取消事件        *********************/
void MaterialAdjInfo::on_pushButtonCancel_clicked()
{
    this->close();
}

/*********************  初始化控件       *********************/
void MaterialAdjInfo::initControl()
{
    titleBar = new TitleBar(this);
    reasonWidget = new ReasonWidget(this);

    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    ui->comboBoxUnit->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxUnit->setView(new QListView());

    connect(reasonWidget, SIGNAL(sendString(QString)), this, SLOT(receiveString(QString)));
}

/*********************  改变事件        *********************/
void MaterialAdjInfo::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  设置仓库ID        *********************/
void MaterialAdjInfo::setWareHouseId(const QString &value)
{
    wareHouseId = value;
}

/*********************  设置转换        *********************/
void MaterialAdjInfo::setConvert(const Map &mapItem)
{
    ui->lineEditNumber->setText(mapItem.value(HTTPKEY::NUMBER));
    ui->lineEditLateNumber->setText(mapItem.value(HTTPKEY::LASTNUMBER));
}

/*********************  设置单号        *********************/
void MaterialAdjInfo::setOddNumber(const QString &value)
{
    oddNumber = value;
}

/*********************  设置原料        *********************/
void MaterialAdjInfo::setMatMap(const Map &value)
{
    matMap = value;
}

/*********************  设置控件是否可用        *********************/
void MaterialAdjInfo::setControlEnable(bool flage)
{
    ui->lineEditNumber->setEnabled(flage);
    ui->lineEditPrice->setEnabled(flage);
    ui->comboBoxUnit->setEnabled(flage);
}

/*********************  设置单位列表        *********************/
void MaterialAdjInfo::setUnitMapList(const MapList &value)
{
    unitMapList = value;
}

/*********************  单位点击        *********************/
void MaterialAdjInfo::on_comboBoxUnit_activated(const QString &arg1)
{
    ui->labelNumber->setText(tr("账面数量(%1)：").arg(arg1));
    ui->labelAdjustNumber->setText(tr("调整数量(%1)：").arg(arg1));
    ui->labelLaterNumber->setText(tr("调整后数量(%1)：").arg(arg1));

    if(ui->comboBoxUnit->currentIndex() < 0 || ui->comboBoxUnit->currentIndex() >= unitMapList.size()) return;

    QString matId = matMap.value(HTTPKEY::MATERIALID);
    QString unitId = unitMapList.at(ui->comboBoxUnit->currentIndex()).value(HTTPKEY::UNITID);
    QString number = matMap.value(HTTPKEY::ADJUSTQUANTITY);

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ADJ_CONVERT).arg(matId, wareHouseId, unitId, number), PROTOCOL::URL_ADJ_CONVERT);
}

/*********************  删除原料        *********************/
void MaterialAdjInfo::on_pushButtonDel_clicked()
{
    QByteArray byteArray;

    List listId;

    listId.append(matMap.value(HTTPKEY::RELATIONSHIPID));

    byteArray.append(POSTARG::DELINVMAT.arg(HTTPCLIENT->makeJson(listId)));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_ADJ_DEL_MAT), byteArray, PROTOCOL::URL_ADJ_DEL_MAT);

    this->close();
}

/*********************  数据改变        *********************/
void MaterialAdjInfo::on_spinBoxAdjustNumber_valueChanged(double arg1)
{
    ui->lineEditLateNumber->setText(QString::number(arg1 + matMap.value(HTTPKEY::NUMBER).toDouble()));
}

/*********************  选择原因        *********************/
void MaterialAdjInfo::on_pushButtonSelectReason_clicked()
{
    reasonWidget->showWidget();

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_ADJ_GET_REASON), PROTOCOL::URL_ADJ_GET_REASON);
}

/*********************  接收数据        *********************/
void MaterialAdjInfo::receiveString(QString text)
{
    ui->lineEditReason->setText(text);
}

/*********************  获取原因窗口        *********************/
ReasonWidget *MaterialAdjInfo::getReasonWidget()
{
    return reasonWidget;
}
