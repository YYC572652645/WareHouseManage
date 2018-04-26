#include "materialtrandet.h"
#include "ui_materialtrandet.h"
#include "httpclient/httpkey.h"
#include "messagebox/messagedialog.h"


/*********************  构造函数        *********************/
MaterialTranDet::MaterialTranDet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::materialtrandet)
{
    ui->setupUi(this);
    this->initControl();
}

/*********************  析构函数        *********************/
MaterialTranDet::~MaterialTranDet()
{
    delete ui;
}

/*********************  显示窗口        *********************/
void MaterialTranDet::showWidget()
{
    titleBar->setTitle(GLOBALDEF::MATERIALINFO);
    this->show();
}

/*********************  设置控件数据        *********************/
void MaterialTranDet::setControlData()
{
    ui->comboBoxUnit->clear();
    for(int i = 0; i < unitMapList.size(); i ++)
    {
        QString unitName = unitMapList.at(i).value(HTTPKEY::NAME);
        ui->comboBoxUnit->addItem(unitName);
    }

    ui->comboBoxUnit->setCurrentText(matMap.value(HTTPKEY::UNITNAME));
    ui->labelNumber->setText(tr("调拨数量(%1)：").arg(matMap.value(HTTPKEY::UNITNAME)));
    ui->labelUnitPrice->setText(tr("单价(元/%1)：").arg(matMap.value(HTTPKEY::ISPRICENAME)));

    ui->lineEditBarCode->setText(matMap.value(HTTPKEY::BARCODE));
    ui->lineEditMatName->setText(matMap.value(HTTPKEY::NAME));
    ui->lineEditPrice->setText(matMap.value(HTTPKEY::COSTPRICE));
    ui->spinBoxNumber->setValue(matMap.value(HTTPKEY::NUMBER).toDouble());
}

/*********************  设置隐藏        *********************/
void MaterialTranDet::setHide()
{
    ui->pushButtonDel->setHidden(true);
    ui->pushButtonCancel->setHidden(true);
    ui->pushButtonSave->setHidden(true);

    ui->comboBoxUnit->setEnabled(false);
    ui->spinBoxNumber->setEnabled(false);
}

/*********************  设置显示        *********************/
void MaterialTranDet::setShow()
{
    ui->pushButtonDel->show();
    ui->pushButtonCancel->show();
    ui->pushButtonSave->show();

    ui->comboBoxUnit->setEnabled(true);
    ui->spinBoxNumber->setEnabled(true);
}

/*********************  设置数据        *********************/
void MaterialTranDet::setMapNumber(const Map &mapData)
{
    ui->spinBoxNumber->setValue(mapData.value(HTTPKEY::REALITYNUMBER).toDouble());
}

/*********************  保存数据        *********************/
void MaterialTranDet::on_pushButtonSave_clicked()
{
    if(ui->comboBoxUnit->currentIndex() >= unitMapList.size()) return;
    if(ui->spinBoxNumber->value() <= 0) return;

    QByteArray byteArray;

    QString strPost = POSTARG::UPDATETRANONEMAT.arg(matMap.value(HTTPKEY::ALLOTMATERIALID));

    strPost = strPost.arg(unitMapList.at(ui->comboBoxUnit->currentIndex()).value(HTTPKEY::UNITID));

    strPost = strPost.arg(ui->spinBoxNumber->value());

    byteArray.append(strPost);

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_ALLOT_UPDATE_MAT), byteArray, PROTOCOL::URL_ALLOT_UPDATE_MAT);

    this->close();
}

/*********************  取消事件        *********************/
void MaterialTranDet::on_pushButtonCancel_clicked()
{
    this->close();
}

/*********************  初始化控件       *********************/
void MaterialTranDet::initControl()
{
    titleBar = new TitleBar(this);

    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    ui->comboBoxUnit->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxUnit->setView(new QListView());
}

/*********************  改变事件        *********************/
void MaterialTranDet::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  设置原料        *********************/
void MaterialTranDet::setMatMap(const Map &value)
{
    matMap = value;
}

/*********************  设置控件是否可用        *********************/
void MaterialTranDet::setControlEnable(bool flage)
{
    ui->spinBoxNumber->setEnabled(flage);
    ui->lineEditPrice->setEnabled(flage);
    ui->comboBoxUnit->setEnabled(flage);
}

/*********************  设置单位列表        *********************/
void MaterialTranDet::setUnitMapList(const MapList &value)
{
    unitMapList = value;
}

/*********************  单位点击        *********************/
void MaterialTranDet::on_comboBoxUnit_activated(const QString &arg1)
{
    ui->labelNumber->setText(tr("调拨数量(%1)：").arg(arg1));
}

/*********************  删除原料        *********************/
void MaterialTranDet::on_pushButtonDel_clicked()
{
    QByteArray byteArray;

    byteArray.append(POSTARG::DELTRANMAT.arg(matMap.value(HTTPKEY::ALLOTMATERIALID)));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_ALLOT_DEL_MAT), byteArray, PROTOCOL::URL_ALLOT_DEL_MAT);

    this->close();
}
