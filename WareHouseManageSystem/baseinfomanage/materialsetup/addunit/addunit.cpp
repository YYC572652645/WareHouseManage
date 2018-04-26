#include "addunit.h"
#include "ui_addunit.h"

/*********************  构造函数        *********************/
AddUnit::AddUnit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddUnit)
{
    ui->setupUi(this);
    this->initControl();
}

/*********************  析构函数        *********************/
AddUnit::~AddUnit()
{
    delete ui;
}

/*********************  显示窗口        *********************/
void AddUnit::showWidget()
{
    titleBar->setTitle(GLOBALDEF::ADDUNITNAME);
    ui->lineEdit->clear();
    this->show();
}

/*********************  点击确定事件     *********************/
void AddUnit::on_pushButtonOk_clicked()
{
    if(ui->lineEdit->text().isEmpty()) return;
    unitName = ui->lineEdit->text();

    emit sendOk();
    this->close();
}

/*********************  取消事件        *********************/
void AddUnit::on_pushButtonCancel_clicked()
{
    unitName.clear();

    this->close();
}

/*********************  获取单元名称     *********************/
QString AddUnit::getUnitName() const
{
    return unitName;
}

/*********************  初始化控件       *********************/
void AddUnit::initControl()
{
    titleBar = new TitleBar(this);

    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);
}

/*********************  改变事件        *********************/
void AddUnit::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}
