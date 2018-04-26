#include "logindialog.h"
#include "ui_logindialog.h"
#include "global/globaldef.h"
#include "httpclient/httpkey.h"
#include "pushbutton/pushbutton.h"
#include <QDebug>

LoginDialog *LoginDialog::instance = NULL;

/************************   构造函数              ************************/
LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::logindialog)
  ,userListWidget(NULL)
{
    ui->setupUi(this);

    titleBar = new TitleBar(this);
    titleBar->subButton(TITLEBAR::MAXWIDGET);
    userListWidget = new QListWidget(this);
    shopListWidget = new QListWidget(this);
    ui->comboBoxUserName->setModel(userListWidget->model());
    ui->comboBoxUserName->setView(userListWidget);

    ui->comboBoxShopCode->setModel(shopListWidget->model());
    ui->comboBoxShopCode->setView(shopListWidget);

    this->setWindowFlags(Qt::FramelessWindowHint);

    this->initControl();
}

/************************   析构函数              ************************/
LoginDialog::~LoginDialog()
{
    delete ui;
}

/************************   单例模式              ************************/
LoginDialog *LoginDialog::getInstance()
{
    if(NULL == instance)
    {
        instance = new LoginDialog();
    }

    return instance;
}

/************************   初始化控件            ************************/
void LoginDialog::initControl()
{
    CONFIGJSON->readConfig();

    {
        ui->comboBoxUserName->clear();
        ui->comboBoxShopCode->clear();
        userListWidget->clear();
        shopListWidget->clear();
    }

    for(int i = 0; i < CONFIGJSON->getMapDataList().size(); i ++)
    {
        QWidget *widget = new QWidget(this);
        QHBoxLayout*hBoxLayout = new QHBoxLayout(widget);
        PushButton *closeButton = new PushButton(this, i);

        QPixmap pixMap = this->style()->standardPixmap(QStyle::SP_TitleBarCloseButton);

        closeButton->setIcon(QIcon(pixMap));
        closeButton->setFixedSize(20,20);
        closeButton->setObjectName("comboxCloseButton");
        connect(closeButton, SIGNAL(clicked(int)),this, SLOT(deleteUserName(int)));

        hBoxLayout->addStretch();
        hBoxLayout->addWidget(closeButton);
        widget->setLayout(hBoxLayout);

        QListWidgetItem *userWidgetItem = new QListWidgetItem(userListWidget);
        userWidgetItem->setText(CONFIGJSON->getMapDataList().at(i).value(GLOBALDEF::JSONUSERNAME));
        userListWidget->setItemWidget(userWidgetItem, widget);

        QListWidgetItem *shopWidgetItem = new QListWidgetItem(shopListWidget);
        shopWidgetItem->setText(CONFIGJSON->getMapDataList().at(i).value(GLOBALDEF::JSONSHOPNUMBER));
        shopListWidget->setItemWidget(shopWidgetItem, widget);
    }

    if(CONFIGJSON->getMapDataList().size() != 0)
    {
        if(CONFIGJSON->getMapDataList().at(0).value(GLOBALDEF::JSONREMEMBER).toInt())
        {
            ui->checkBoxRememberPsd->setChecked(true);
            ui->lineEditPassWord->setText(CONFIGJSON->getMapDataList().at(0).value(GLOBALDEF::JSONPASSWORD));
        }
        else
        {
            ui->checkBoxRememberPsd->setChecked(false);
            ui->lineEditPassWord->clear();
        }
    }

    for(int i = 0; i < CONFIGJSON->getMapDataList().size(); i ++)
    {
        if(CONFIGJSON->getMapDataList().at(i).value(GLOBALDEF::JSONSHOPNUMBER) == CONFIGJSON->getCurrentUser())
        {
            ui->comboBoxShopCode->setCurrentIndex(i);
            ui->comboBoxUserName->setCurrentIndex(i);
            if(CONFIGJSON->getMapDataList().at(i).value(GLOBALDEF::JSONREMEMBER).toInt())
            {
                ui->checkBoxRememberPsd->setChecked(true);
                ui->lineEditPassWord->setText(CONFIGJSON->getMapDataList().at(i).value(GLOBALDEF::JSONPASSWORD));
            }
            else
            {
                ui->checkBoxRememberPsd->setChecked(false);
                ui->lineEditPassWord->clear();
            }
        }
    }

    titleBar->setBackGround();
}

/************************   改变事件              ************************/
void LoginDialog::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/************************   登录按钮              ************************/
void LoginDialog::on_pushButtonLogin_clicked()
{
    QString shopCode = ui->comboBoxShopCode->currentText();
    QString userName = ui->comboBoxUserName->currentText();
    QString passWord = ui->lineEditPassWord->text();

    QByteArray byteArray;
    byteArray.append(POSTARG::LOGINARG.arg(shopCode, userName, passWord));

    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_USER_LOGIN), byteArray, PROTOCOL::URL_USER_LOGIN);
}

/************************   删除用户名              ************************/
void LoginDialog::deleteUserName(int index)
{
    MapList mapList = CONFIGJSON->getMapDataList();

    if(index < 0 || index >= mapList.size()) return;

    mapList.removeAt(index);

    CONFIGJSON->writeConfig(mapList);

    this->initControl();
}

/************************   店铺登录信息           ************************/
void LoginDialog::userLoginInfo(const Map &mapData)
{
    if(mapData.size() <= 0)
    {
        ui->pushButtonInfo->setIcon(QIcon(GLOBALDEF::LOGINFAILIMG));
        ui->pushButtonInfo->setText(MESSAGE::LOGINFAILMSG);
        return;
    }

    int type = mapData.value(HTTPKEY::CODE).toInt();

    if(ONE == type)
    {
        if(type >= ARRAYITEMCOUNT(MESSAGE::errorData)) return;
        ui->pushButtonInfo->setIcon(QIcon(GLOBALDEF::LOGINSUCCESSIMG));
        ui->pushButtonInfo->setText(MESSAGE::errorData[type].errorText);

        MapList mapList = CONFIGJSON->getMapDataList();

        bool flage = false;
        for(int i = 0; i < mapList.size(); i ++)
        {
            if(ui->comboBoxUserName->currentText() == mapList.at(i).value(GLOBALDEF::JSONUSERNAME)
                    || ui->comboBoxUserName->currentText() == mapList.at(i).value(GLOBALDEF::JSONSHOPNUMBER))
            {
                flage = true;
            }
        }

        QMap<QString, QString>mapData;
        mapData[GLOBALDEF::JSONUSERNAME]   = ui->comboBoxUserName->currentText();
        mapData[GLOBALDEF::JSONSHOPNUMBER] = ui->comboBoxShopCode->currentText();
        mapData[GLOBALDEF::JSONPASSWORD]   = ui->lineEditPassWord->text();
        mapData[GLOBALDEF::JSONREMEMBER]   = QString::number(ui->checkBoxRememberPsd->isChecked());
        CONFIGJSON->setCurrentUser(ui->comboBoxShopCode->currentText());

        if(!flage)
        {
            mapList.append(mapData);

            CONFIGJSON->writeConfig(mapList);
        }
        else
        {
            int currentIndex = ui->comboBoxShopCode->currentIndex();
            if(currentIndex >= 0 && currentIndex < mapList.size())
            {
                mapList[currentIndex] = mapData;
                CONFIGJSON->writeConfig(mapList);
            }
        }

        accept();
    }
    else
    {
        if(type >= ARRAYITEMCOUNT(MESSAGE::errorData)) return;
        ui->pushButtonInfo->setIcon(QIcon(GLOBALDEF::LOGINFAILIMG));
        ui->pushButtonInfo->setText(MESSAGE::errorData[type].errorText);
    }
}

/************************   选中下拉框           ************************/
void LoginDialog::on_comboBoxShopCode_activated(int index)
{
    ui->comboBoxUserName->setCurrentIndex(index);

    MapList mapListData = CONFIGJSON->getMapDataList();
    if(index >= 0 && index < mapListData.size())
    {
        if(mapListData.at(index).value(GLOBALDEF::JSONREMEMBER).toInt())
        {
            ui->checkBoxRememberPsd->setChecked(true);
            ui->lineEditPassWord->setText(mapListData.at(index).value(GLOBALDEF::JSONPASSWORD));
        }
        else
        {
            ui->checkBoxRememberPsd->setChecked(false);
            ui->lineEditPassWord->clear();
        }
    }
}

/************************   更改文本           ************************/
void LoginDialog::on_comboBoxShopCode_editTextChanged(const QString &arg1)
{
    if(ui->comboBoxShopCode->findText(arg1) < 0)
    {
        ui->checkBoxRememberPsd->setChecked(false);
        ui->lineEditPassWord->clear();
    }
}
