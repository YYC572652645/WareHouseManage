#include "addmaterial.h"
#include "ui_addmaterial.h"

/*********************  构造函数        *********************/
AddMaterial::AddMaterial(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddMaterial)
{
    ui->setupUi(this);

    this->initControl();
}

/*********************  析构函数        *********************/
AddMaterial::~AddMaterial()
{
    delete ui;
}

/*********************  显示窗口        *********************/
void AddMaterial::showWidget()
{
    titleBar->setTitle(GLOBALDEF::ADDMATERIALNAME);
    ui->lineEdit->clear();
    this->show();
}

/*********************  点击确定事件     *********************/
void AddMaterial::on_pushButtonOk_clicked()
{
    if(ui->lineEdit->text().isEmpty()) return;

    materialName = ui->lineEdit->text();

    emit sendOk();

    this->close();
}

/*********************  取消事件        *********************/
void AddMaterial::on_pushButtonCancel_clicked()
{
     materialName.clear();

     this->close();
}

/*********************  初始化控件      *********************/
void AddMaterial::initControl()
{
    titleBar = new TitleBar(this);

    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);
}

/*********************  改变事件        *********************/
void AddMaterial::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  获取原料名称    *********************/
QString AddMaterial::getMaterialName() const
{
    return materialName;
}
