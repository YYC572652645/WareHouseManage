#include "addtype.h"
#include "ui_addtype.h"


/*********************  构造函数        *********************/
AddType::AddType(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddType)
{
    ui->setupUi(this);
    this->initControl();
}

/*********************  析构函数        *********************/
AddType::~AddType()
{
    delete ui;
}

void AddType::showWidget()
{
    ui->lineEdit->clear();
    this->show();
}

/*********************  点击确定事件     *********************/
void AddType::on_pushButtonOk_clicked()
{
    if(ui->lineEdit->text().isEmpty()) return;
    typeName = ui->lineEdit->text();

    emit sendOk();
    this->close();
}

/*********************  取消事件        *********************/
void AddType::on_pushButtonCancel_clicked()
{
    typeName.clear();

    this->close();
}

/*********************  获取类别名称     *********************/
QString AddType::getTypeName() const
{
    return typeName;
}

/*********************  设置标题名       *********************/
void AddType::setTitleName(QString title)
{
    titleBar->setTitle(title);
}

/*********************  显示窗口       *********************/
void AddType::showWidget(QString lineText)
{
    ui->lineEdit->setText(lineText);
    this->show();
}

/*********************  初始化控件       *********************/
void AddType::initControl()
{
    titleBar = new TitleBar(this);

    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);
}

/*********************  改变事件        *********************/
void AddType::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}
