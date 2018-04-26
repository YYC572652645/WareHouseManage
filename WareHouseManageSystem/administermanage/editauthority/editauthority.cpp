#include "editauthority.h"
#include "ui_editauthority.h"
#include "httpclient/httpkey.h"

/*********************  构造函数       *********************/
EditAuthority::EditAuthority(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditAuthority)
{
    ui->setupUi(this);

    this->initControl();
}

/*********************  析构函数       *********************/
EditAuthority::~EditAuthority()
{
    delete ui;
}

/*********************  显示窗口       *********************/
void EditAuthority::showWidget(bool flage)
{
    ui->groupBoxBasic->setEnabled(flage);
    ui->groupBoxCommon->setEnabled(flage);
    ui->groupBoxOther->setEnabled(flage);
    ui->groupBoxWhse->setEnabled(flage);

    titleBar->setTitle(tr("修改权限"));
    ui->lineEditUserName->setText(mapUsrData.value(HTTPKEY::USERNAME));
    ui->lineEditPassWord->setText(mapUsrData.value(HTTPKEY::PASSWORD));

    this->setCheck(false);
    this->activateWindow();
    this->show();
}

/*********************  初始化控件       *********************/
void EditAuthority::initControl()
{
    titleBar = new TitleBar(this);

    titleBar->setIcon(GLOBALDEF::APPLOGO);


    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    checkBoxMap[HTTPKEY::MATERIAL]        = ui->checkBoxMaterial;
    checkBoxMap[HTTPKEY::WAREHOUSE]       = ui->checkBoxWarehouse;
    checkBoxMap[HTTPKEY::SUPPLIER]        = ui->checkBoxSupplier;
    checkBoxMap[HTTPKEY::TEMPLATE]        = ui->checkBoxTemplate;
    checkBoxMap[HTTPKEY::BOM]             = ui->checkBoxBom;
    checkBoxMap[HTTPKEY::PURCHASE]        = ui->checkBoxPurchase;
    checkBoxMap[HTTPKEY::STORAGE]         = ui->checkBoxStorage;
    checkBoxMap[HTTPKEY::RETURNS]         = ui->checkBoxReturns;
    checkBoxMap[HTTPKEY::SAFETY]          = ui->checkBoxSafety;
    checkBoxMap[HTTPKEY::TIMEINVENTORY]   = ui->checkBoxTimeinventory;
    checkBoxMap[HTTPKEY::ADJUSTMENT]      = ui->checkBoxAdjustment;
    checkBoxMap[HTTPKEY::CHECK]           = ui->checkBoxCheck;
    checkBoxMap[HTTPKEY::CHANGE]          = ui->checkBoxChange;
    checkBoxMap[HTTPKEY::READJUST]        = ui->checkBoxReadjust;
    checkBoxMap[HTTPKEY::RESTRICTIONS]    = ui->checkBoxRestrictions;
    checkBoxMap[HTTPKEY::ALLOT]           = ui->checkBoxAllot;
    checkBoxMap[HTTPKEY::DEFAULTSUPPLIER] = ui->checkBoxDefaultSupplier;
    checkBoxMap[HTTPKEY::ACCOUNT]         = ui->checkBoxAccount;
    checkBoxMap[HTTPKEY::TODAY]           = ui->checkBoxToday;
    checkBoxMap[HTTPKEY::USER]            = ui->checkBoxUser;
    checkBoxMap[HTTPKEY::RULE]            = ui->checkBoxRule;


    for(auto iter = checkBoxMap.begin(); iter != checkBoxMap.end(); iter ++)
    {
        mapCheckBox[iter.value()] = iter.key();
    }
}

/*********************  改变事件        *********************/
void EditAuthority::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  清空选中        *********************/
void EditAuthority::setCheck(bool falge)
{
    for(auto iter = checkBoxMap.begin(); iter != checkBoxMap.end(); iter ++)
    {
        iter.value()->setChecked(falge);
    }
}

/*********************  设置用户数据    *********************/
void EditAuthority::setMapUsrData(const Map &value)
{
    mapUsrData = value;
}

/*********************  设置选中       *********************/
void EditAuthority::setCheck(List listData)
{
    if(listData.size())
    {
        for(int i = 0; i < listData.size(); i ++)
        {
            if(NULL != checkBoxMap.value(listData.at(i)))
            {
                checkBoxMap.value(listData.at(i))->setChecked(true);
            }
        }
    }
    else
    {
        this->setCheck(true);
    }
}

/*********************  确定事件        *********************/
void EditAuthority::on_pushButtonOk_clicked()
{
    QByteArray byteArray;

    QString strPost = POSTARG::EDITUSER.arg(mapUsrData.value(HTTPKEY::USERID));

    strPost = strPost.arg(ui->lineEditUserName->text());
    strPost = strPost.arg(ui->lineEditPassWord->text());

    QString ruleStr;
    for(auto iter = mapCheckBox.begin(); iter != mapCheckBox.end(); iter ++)
    {
        if(iter.key()->isChecked())
        {
            if(!ruleStr.isEmpty()) ruleStr += ",";
            ruleStr += iter.value();
        }
    }

    strPost = strPost.arg(ruleStr);

    byteArray.append(strPost);

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_USER_EDIT), byteArray, PROTOCOL::URL_USER_EDIT);

    this->close();
}

/*********************  取消事件        *********************/
void EditAuthority::on_pushButtonCancel_clicked()
{
    this->close();
}

