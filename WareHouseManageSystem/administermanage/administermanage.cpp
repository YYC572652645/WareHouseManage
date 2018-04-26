#include "administermanage.h"
#include "ui_administermanage.h"
#include "httpclient/httpkey.h"
#include "messagebox/messagedialog.h"
#include "administermanage/editauthority/editauthority.h"
#include "administermanage/addauthority/addauthority.h"
#include <QHBoxLayout>

/*********************   构造函数         ********************/
AdministerManage::AdministerManage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdministerManage)
  ,adminFlage(false)
{
    ui->setupUi(this);

    this->initControl();
}

/*********************  析构函数          ********************/
AdministerManage::~AdministerManage()
{
    delete ui;
}

/*********************  初始化控件        ********************/
void AdministerManage::initControl()
{
    SETTABLEWIDGET(ui->tableWidgetData);
    ui->tableWidgetData->setSelectionMode(QAbstractItemView::NoSelection);

    editAuthority = new EditAuthority(this);
    addAuthority = new AddAuthority(this);
}

/*********************  设置表格数据      *********************/
void AdministerManage::setTableData()
{
    SAFEDELLIST(editButtonList);
    SAFEDELLIST(delButtonList);

    delButtonList.clear();
    editButtonList.clear();

    ui->tableWidgetData->setRowCount(userMapList.size());

    for(int i = 0; i < userMapList.size(); i ++)
    {
        ui->tableWidgetData->setItem(i, ZERO,  DATA(userMapList.at(i).value(HTTPKEY::USERID)));
        ui->tableWidgetData->setItem(i, ONE,   DATA(userMapList.at(i).value(HTTPKEY::USERNAME)));

        QString groupId = userMapList.at(i).value(HTTPKEY::GROUPID);
        QString strText = groupId == "1" ? tr("管理员") : tr("普通用户");

        ui->tableWidgetData->setItem(i, TWO,   DATA(strText));

        {
            QWidget *widgetControl = new QWidget(this);
            QHBoxLayout *hBoxLayout = new QHBoxLayout(widgetControl);

            QPushButton *editButton = new QPushButton(this);
            QPushButton *delButton = new QPushButton(this);

            editButton->setIcon(QIcon(GLOBALDEF::EDITIMAGE));
            delButton->setIcon(QIcon(GLOBALDEF::DELIMAGE));

            editButton->setText(tr("修改"));
            delButton->setText(tr("删除"));

            if(groupId.toInt() != 0) delButton->setEnabled(false);

            hBoxLayout->addWidget(editButton);
            hBoxLayout->addWidget(delButton);

            hBoxLayout->setMargin(0);
            widgetControl->setLayout(hBoxLayout);

            ui->tableWidgetData->setCellWidget(i, THREE, widgetControl);

            editButtonList.append(editButton);
            delButtonList.append(delButton);

            connect(editButton, SIGNAL(clicked()), this, SLOT(editUser()));
            connect(delButton,  SIGNAL(clicked()), this, SLOT(deleteUser()));
        }

        SETTABLECENTER(ui->tableWidgetData->item(i, ZERO));
        SETTABLECENTER(ui->tableWidgetData->item(i, ONE));
        SETTABLECENTER(ui->tableWidgetData->item(i, TWO));
    }
    ui->tableWidgetData->scrollToBottom();
}

/*********************  显示窗口         *********************/
void AdministerManage::showWidget()
{
    this->show();
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_USER_LIST), PROTOCOL::URL_USER_LIST);
}

/*********************  删除用户         *********************/
void AdministerManage::deleteUser()
{
    QPushButton *pButton = qobject_cast<QPushButton *>(sender());

    for(int i = 0; i < delButtonList.size(); i ++)
    {
        if(pButton == delButtonList.at(i))
        {
            if(i < userRuleList.size())
            {
                QByteArray byteArray;

                byteArray.append(POSTARG::DELETEUSER.arg(userMapList.at(i).value(HTTPKEY::USERID)));

                HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_USER_DEL), byteArray, PROTOCOL::URL_USER_DEL);
            }
        }
    }
}

/*********************  修改用户         *********************/
void AdministerManage::editUser()
{
    QPushButton *pButton = qobject_cast<QPushButton *>(sender());

    for(int i = 0; i < editButtonList.size(); i ++)
    {
        if(pButton == editButtonList.at(i))
        {
            if(i < userRuleList.size())
            {
                editAuthority->setMapUsrData(userMapList.at(i));
            }

            int groupId = userMapList.at(i).value(HTTPKEY::GROUPID).toInt();;
            adminFlage = groupId == 0 ? true : false;

            editAuthority->showWidget(adminFlage);

            if(i < userRuleList.size())
            {
                editAuthority->setCheck(userRuleList.at(i));
            }
        }
    }
}

/*********************  添加权限         *********************/
void AdministerManage::on_pushButtonAdd_clicked()
{
    addAuthority->showWidget();
}

/*********************  解析json        *********************/
void AdministerManage::readJson(QNetworkReply *reply, int type)
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
            if(ISERROR(codeValue))
            {
                if(codeValue == SUBONE)        errorMsg = MESSAGE::NOTSHOPLOGIN;
                else if(codeValue == SUBTWO)   errorMsg = MESSAGE::NOTADMINLOGIN;
                else if(codeValue == SUBTHREE) errorMsg = MESSAGE::NOPRIORITY;
                else if(codeValue == ZERO)     errorMsg = MESSAGE::ERROR;
                else if(codeValue == TWO)      errorMsg = MESSAGE::DATAERROR;
                else if(codeValue == THREE)    errorMsg = MESSAGE::ADMINSTEREXIST;

                if(codeValue == SUBONE || codeValue == SUBTWO || codeValue == SUBTHREE)
                {
                    MESSAGEBOX->showMessageBox(this, errorMsg);
                    this->setHidden(true);
                    return;
                }
            }

            if(jsonObject.contains(HTTPKEY::MSG))
            {
                QJsonObject jsonNextObj = jsonObject.value(HTTPKEY::MSG).toObject();

                if(type == PROTOCOL::URL_USER_LIST)
                {
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::USERLIST, userMapList);
                    HTTPCLIENT->readJsonList(jsonNextObj, HTTPKEY::RULELIST, ruleMapList);

                    QJsonValue jsonValue = jsonNextObj.value(HTTPKEY::USERLIST);
                    QJsonArray jsonArray = jsonValue.toArray();

                    userRuleList.clear();
                    for(int i = 0; i < jsonArray.size(); i ++)
                    {
                        QJsonObject objectItem = jsonArray.at(i).toObject();

                        QJsonArray authorityArray = objectItem.value(HTTPKEY::RULE).toArray();

                        List listData;
                        for(int i = 0; i < authorityArray.size(); i ++)
                        {
                            listData.append(authorityArray.at(i).toString());
                        }

                        userRuleList.append(listData);
                    }

                    this->setTableData();
                }
                else if(type == PROTOCOL::URL_USER_ADD)
                {
                    this->showWidget();
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::ADDSUCCESS, true);
                }
                else if(type == PROTOCOL::URL_USER_EDIT)
                {
                    this->showWidget();
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::EDITSUCCESS, true);
                }
                else if(type == PROTOCOL::URL_USER_DEL)
                {
                    this->showWidget();
                    MESSAGEBOX->showMessageBox(this, GLOBALDEF::DELSUCCESS, true);
                }
            }
        }
        reply->close();
    }
}
