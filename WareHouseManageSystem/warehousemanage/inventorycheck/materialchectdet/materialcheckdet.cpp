#include "materialcheckdet.h"
#include "ui_materialcheckdet.h"
#include "httpclient/httpkey.h"
#include "messagebox/messagedialog.h"


/*********************  构造函数        *********************/
MaterialCheckDet::MaterialCheckDet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::materialcheckdet)
{
    ui->setupUi(this);
    this->initControl();
}

/*********************  析构函数        *********************/
MaterialCheckDet::~MaterialCheckDet()
{
    delete ui;
}

/*********************  显示窗口        *********************/
void MaterialCheckDet::showWidget()
{
    titleBar->setTitle(GLOBALDEF::MATERIALINFO);
    this->show();
}

/*********************  设置控件数据        *********************/
void MaterialCheckDet::setControlData()
{
    ui->comboBoxUnit->clear();
    for(int i = 0; i < unitMapList.size(); i ++)
    {
        QString unitName = unitMapList.at(i).value(HTTPKEY::NAME);
        ui->comboBoxUnit->addItem(unitName);

        if(unitMapList.at(i).value(HTTPKEY::UNITID) == matMap.value(HTTPKEY::UNITID))
        {
            oldNumber = unitMapList.at(i).value(HTTPKEY::UNITID);
            ui->comboBoxUnit->setCurrentText(unitName);

            ui->comboBoxUnit->setCurrentText(unitName);
            ui->labelUnitPrice->setText(tr("单价(元/%1)：").arg(unitName));
            ui->labelNumber->setText(tr("账面数量(%1)：").arg(unitName));
            ui->labelAdjustNumber->setText(tr("实际数量(%1)：").arg(unitName));
            ui->labelLaterNumber->setText(tr("差异数量(%1)：").arg(unitName));
        }
    }

    ui->lineEditBarCode->setText(matMap.value(HTTPKEY::BARCODE));
    ui->lineEditMatName->setText(matMap.value(HTTPKEY::MATERIALNAME));
    ui->lineEditPrice->setText(matMap.value(HTTPKEY::PRICE));
    ui->lineEditNumber->setText(matMap.value(HTTPKEY::PAPERNUMBER));
    ui->spinBoxAdjustNumber->setValue(matMap.value(HTTPKEY::REALITYNUMBER).toDouble());
    ui->lineEditLateNumber->setText(matMap.value(HTTPKEY::DIFFERENCENUMBER));
}

/*********************  设置隐藏        *********************/
void MaterialCheckDet::setHide()
{
    ui->pushButtonDel->setHidden(true);
    ui->pushButtonCancel->setHidden(true);
    ui->pushButtonSave->setHidden(true);

    ui->comboBoxUnit->setEnabled(false);
    ui->spinBoxAdjustNumber->setEnabled(false);
}

/*********************  设置显示        *********************/
void MaterialCheckDet::setShow()
{
    ui->pushButtonDel->show();
    ui->pushButtonCancel->show();
    ui->pushButtonSave->show();

    ui->comboBoxUnit->setEnabled(true);
    ui->spinBoxAdjustNumber->setEnabled(true);
}

/*********************  设置数据        *********************/
void MaterialCheckDet::setMapNumber(const Map &mapData)
{
    ui->lineEditLateNumber->setText(mapData.value(HTTPKEY::DIFFERENCENUMBER));
    ui->lineEditNumber->setText(mapData.value(HTTPKEY::PAPERNUMBER));
}

/*********************  保存数据        *********************/
void MaterialCheckDet::on_pushButtonSave_clicked()
{
    if(ui->spinBoxAdjustNumber->value() <= 0) return;
    if(ui->comboBoxUnit->currentIndex() >= unitMapList.size()) return;

    QByteArray byteArray;

    QString strPost = POSTARG::UPDATECHECKMAT.arg(matMap.value(HTTPKEY::WAREHOUSECHECKMATID));

    strPost = strPost.arg(unitMapList.at(ui->comboBoxUnit->currentIndex()).value(HTTPKEY::UNITID));

    strPost = strPost.arg(ui->lineEditNumber->text().toDouble());

    strPost = strPost.arg(ui->spinBoxAdjustNumber->value());

    strPost = strPost.arg(ui->lineEditLateNumber->text().toDouble());

    byteArray.append(strPost);

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_CHECK_UPDATE_MAT), byteArray, PROTOCOL::URL_CHECK_UPDATE_MAT);

    this->close();
}

/*********************  取消事件        *********************/
void MaterialCheckDet::on_pushButtonCancel_clicked()
{
    this->close();
}

/*********************  初始化控件       *********************/
void MaterialCheckDet::initControl()
{
    titleBar = new TitleBar(this);

    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    ui->comboBoxUnit->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxUnit->setView(new QListView());
}

/*********************  改变事件        *********************/
void MaterialCheckDet::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  设置原料        *********************/
void MaterialCheckDet::setMatMap(const Map &value)
{
    matMap = value;
}

/*********************  设置控件是否可用        *********************/
void MaterialCheckDet::setControlEnable(bool flage)
{
    ui->lineEditNumber->setEnabled(flage);
    ui->lineEditPrice->setEnabled(flage);
    ui->comboBoxUnit->setEnabled(flage);
}

/*********************  设置单位列表        *********************/
void MaterialCheckDet::setUnitMapList(const MapList &value)
{
    unitMapList = value;
}

/*********************  单位点击        *********************/
void MaterialCheckDet::on_comboBoxUnit_activated(const QString &arg1)
{
    ui->labelUnitPrice->setText(tr("单价(元/%1)：").arg(arg1));
    ui->labelNumber->setText(tr("账面数量(%1)：").arg(arg1));
    ui->labelAdjustNumber->setText(tr("实际数量(%1)：").arg(arg1));
    ui->labelLaterNumber->setText(tr("差异数量(%1)：").arg(arg1));
}

/*********************  删除原料        *********************/
void MaterialCheckDet::on_pushButtonDel_clicked()
{
    QByteArray byteArray;

    byteArray.append(POSTARG::DELCHECKMAT.arg(matMap.value(HTTPKEY::WAREHOUSECHECKMATID)));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_CHECK_DEL_MAT), byteArray, PROTOCOL::URL_CHECK_DEL_MAT);

    this->close();
}

/*********************  数据改变        *********************/
void MaterialCheckDet::on_spinBoxAdjustNumber_valueChanged(double arg1)
{
    ui->lineEditLateNumber->setText(QString::number(arg1 + matMap.value(HTTPKEY::NUMBER).toDouble()));
}

/*********************  点击        *********************/
void MaterialCheckDet::on_comboBoxUnit_activated(int index)
{
    if(index < 0 || index >= unitMapList.size()) return;

    if(oldNumber != unitMapList.at(index).value(HTTPKEY::UNITID))
    {

        QString strPost = MESSAGEURL(PROTOCOL::URL_CHECK_UNIT_UPDATE_NUM).arg(matMap.value(HTTPKEY::MATERIALID));

        strPost = strPost.arg(oldNumber, unitMapList.at(index).value(HTTPKEY::UNITID));

        strPost = strPost.arg(ui->lineEditNumber->text().toInt());

        strPost = strPost.arg(ui->spinBoxAdjustNumber->value());

        HTTPCLIENT->getUrlReq(strPost, PROTOCOL::URL_CHECK_UNIT_UPDATE_NUM);

        oldNumber = unitMapList.at(index).value(HTTPKEY::UNITID);
    }

}
