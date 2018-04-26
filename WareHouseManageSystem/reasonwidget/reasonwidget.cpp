#include "reasonwidget.h"
#include "ui_reasonwidget.h"
#include "httpclient/httpkey.h"

/*********************  构造函数       *********************/
ReasonWidget::ReasonWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReasonWidget)
{
    ui->setupUi(this);

    this->initControl();
}

/*********************  析构函数       *********************/
ReasonWidget::~ReasonWidget()
{
    delete ui;
}

/*********************  显示窗口       *********************/
void ReasonWidget::showWidget()
{
    titleBar->setTitle(GLOBALDEF::ADJREASON);
    this->show();
}

/*********************  清空信息       *********************/
void ReasonWidget::clearInfo()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    reasonMapList.clear();
}

/*********************  初始化控件       *********************/
void ReasonWidget::initControl()
{
    titleBar = new TitleBar(this);
    addReason = new ExportEmail(this);
    addReason->setTitle(tr("添加原因"));
    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    SETTABLEWIDGET(ui->tableWidget);

    connect(addReason, SIGNAL(sendEmail(QString)), this, SLOT(receiveText(QString)));
}

/*********************  改变事件        *********************/
void ReasonWidget::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  设置原因列表        *********************/
void ReasonWidget::setReasonMapList(const MapList &value)
{
    reasonMapList = value;

    ui->tableWidget->setRowCount(reasonMapList.size());

    for(int i = 0; i < reasonMapList.size(); i ++)
    {
        ui->tableWidget->setItem(i, 0, DATA(reasonMapList.at(i).value(HTTPKEY::REASON)));
        SETTABLECENTER(ui->tableWidget->item(i, 0));

        ui->tableWidget->item(i, 0)->setCheckState(Qt::Unchecked);
    }

    ui->tableWidget->scrollToBottom();
}

/*********************  添加原因       *********************/
void ReasonWidget::on_pushButtonAdd_clicked()
{
    addReason->show();
}

/*********************  删除原因       *********************/
void ReasonWidget::on_pushButtonDel_clicked()
{
    int currentRow = ui->tableWidget->currentRow();

    if(currentRow < 0 || currentRow >= reasonMapList.size()) return;

    QByteArray byteArray;

    byteArray.append(POSTARG::DELREASON.arg(reasonMapList.at(currentRow).value(HTTPKEY::REASONID)));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_ADJ_DEL_REASON), byteArray, PROTOCOL::URL_ADJ_DEL_REASON);
}

/*********************  单击事件       *********************/
void ReasonWidget::on_tableWidget_clicked(const QModelIndex &index)
{
    if(index.row() != ui->tableWidget->currentRow())
    {
        ui->tableWidget->item(index.row(), 0)->setCheckState(Qt::Unchecked);
        return;
    }

    if(ui->tableWidget->item(index.row(), 0)->checkState() != Qt::Checked)
    {
        ui->tableWidget->item(index.row(), 0)->setCheckState(Qt::Checked);
    }

    for(int i = 0; i < ui->tableWidget->rowCount(); i ++)
    {
        if(i != index.row())
        {
            ui->tableWidget->item(i, 0)->setCheckState(Qt::Unchecked);
        }
    }
}

/*********************  接收信息       *********************/
void ReasonWidget::receiveText(QString text)
{
    QByteArray byteArray;

    byteArray.append(POSTARG::ADDREASON.arg(text));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_ADJ_ADD_REASON), byteArray, PROTOCOL::URL_ADJ_ADD_REASON);
}

/*********************  确定按钮       *********************/
void ReasonWidget::on_pushButtonOk_clicked()
{
    if(NULL == ui->tableWidget->currentItem())
    {
        emit sendString(NULL);
        this->close();
        return;
    }

    if(ui->tableWidget->currentItem()->checkState() == Qt::Checked)
    {
        emit sendString(ui->tableWidget->currentItem()->text());
        this->close();
    }
}

/*********************  取消按钮       *********************/
void ReasonWidget::on_pushButtonCancel_clicked()
{
    this->close();
}
