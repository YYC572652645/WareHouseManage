#include "materialtype.h"
#include "ui_materialtype.h"
#include "httpclient/httpkey.h"
#include "httpclient/httpclient.h"
#include "messagebox/messagedialog.h"

/*********************  构造函数            *********************/
MaterialType::MaterialType(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MaterialType)
  , titleBar(NULL)
{
    ui->setupUi(this);

    ui->labelParent->hide();
    ui->comboBoxParentType->hide();
    ui->comboBoxParentType->setView(new QListView());

    this->initControl();
}

/*********************  析构函数            *********************/
MaterialType::~MaterialType()
{
    delete ui;
}

/*********************  初始化控件          *********************/
void MaterialType::initControl()
{
    titleBar = new TitleBar(this);

    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    ui->comboBoxParentType->setFocusPolicy(Qt::NoFocus);
}

/*********************  设置添加分类数据列表  *********************/
void MaterialType::setMapList(MapList &mapList)
{
    mapDataList = mapList;
    ui->comboBoxParentType->clear();
    for(int i = 0; i < mapList.size(); i++)
    {
        ui->comboBoxParentType->addItem(mapList.at(i).value(HTTPKEY::NAME));
    }

    ui->pushButtonSave->setText(GLOBALDEF::SAVETEXT);
    ui->pushButtonDelete->hide();
}

/*********************  显示窗口            *********************/
void MaterialType::showWidget()
{
    titleBar->setTitle(GLOBALDEF::MATERIALTYPE);
    ui->lineEditMaterialCode->clear();
    ui->lineEditMaterialTypeName->clear();
    ui->comboBoxParentType->clear();
    ui->checkBoxIsHaveParent->setChecked(false);
    ui->comboBoxParentType->setHidden(true);
    ui->labelParent->setHidden(true);
    this->show();
}

/*********************  设置编辑分类列表     *********************/
void MaterialType::setData(MapList &mapList)
{
    ui->pushButtonSave->setText(GLOBALDEF::OKUPDATE);
    ui->pushButtonDelete->show();

    if(mapList.size() == 0) return;

    ui->lineEditMaterialTypeName->setText(mapList.at(0).value(HTTPKEY::NAME));
    ui->lineEditMaterialCode->setText(mapList.at(0).value(HTTPKEY::ENCODING));

    if(mapList.at(0).value(HTTPKEY::PID) == "0")
    {
        ui->checkBoxIsHaveParent->setChecked(false);
        ui->labelParent->hide();
        ui->comboBoxParentType->hide();
    }
    else
    {
        ui->checkBoxIsHaveParent->setChecked(true);
        ui->labelParent->show();
        ui->comboBoxParentType->show();
    }

    for(int i = 0; i < mapDataList.size(); i ++)
    {
        if(mapDataList.at(i).value(HTTPKEY::CATEGORYID) ==  mapList.at(0).value(HTTPKEY::PID))
        {
            ui->comboBoxParentType->setCurrentIndex(i);
        }
    }
}

/*********************  重置事件            *********************/
void MaterialType::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  是否有上级          *********************/
void MaterialType::on_checkBoxIsHaveParent_clicked()
{
    if(ui->checkBoxIsHaveParent->isChecked())
    {
        ui->labelParent->show();
        ui->comboBoxParentType->show();
    }
    else
    {
        ui->labelParent->hide();
        ui->comboBoxParentType->hide();
    }
}

/*********************  保存按钮            *********************/
void MaterialType::on_pushButtonSave_clicked()
{
    if(ui->lineEditMaterialTypeName->text().isEmpty()) return;

    QString materialTypeName = ui->lineEditMaterialTypeName->text();

    QString pId = "0";
    if(ui->checkBoxIsHaveParent->isChecked())
    {
        int index = ui->comboBoxParentType->currentIndex();
        if(index < 0) return;

        if(ui->checkBoxIsHaveParent->isChecked() && index < mapDataList.size())
        {
            pId = mapDataList.at(index).value(HTTPKEY::CATEGORYID);
        }
    }

    QByteArray byteArray;

    //保存数据
    if(ui->pushButtonSave->text() == GLOBALDEF::SAVETEXT)
    {
        byteArray.append(POSTARG::MATERIALTYPEADD.arg(materialTypeName, pId, ui->lineEditMaterialCode->text()));
        HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_CATEGORY_ADD), byteArray, PROTOCOL::URL_CATEGORY_ADD);
    }
    //修改数据
    else
    {
        if(pId == categoryId)
        {
            MESSAGEBOX->showMessageBox(this, MESSAGE::CANNOTMYSELF);
            return;
        }

        byteArray.append(POSTARG::MATERIALTYPEEDIT.arg(materialTypeName, pId, ui->lineEditMaterialCode->text(), categoryId));
        HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_CATEGORY_EDIT), byteArray, PROTOCOL::URL_CATEGORY_EDIT);
    }

    this->close();
}

/*********************  取消按钮            *********************/
void MaterialType::on_pushButtonCancel_clicked()
{
    this->close();
}

/*********************  删除按钮            *********************/
void MaterialType::on_pushButtonDelete_clicked()
{
    QByteArray byteArray;
    byteArray.append(POSTARG::MATERIALTYPEDEL.arg(categoryId));
    HTTPCLIENT->postUrlReq(MESSAGEURL(PROTOCOL::URL_CATEGORY_DEL), byteArray, PROTOCOL::URL_CATEGORY_DEL);

    this->close();
}

/*********************  设置分类ID          *********************/
void MaterialType::setCategoryId(const QString &value)
{
    categoryId = value;
}
