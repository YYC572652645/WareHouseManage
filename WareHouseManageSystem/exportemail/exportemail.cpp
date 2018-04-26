#include "exportemail.h"
#include "ui_exportemail.h"
#include "messagebox/messagedialog.h"

/*********************  构造函数        *********************/
ExportEmail::ExportEmail(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExportEmail)
{
    ui->setupUi(this);

    this->initControl();
}

/*********************  析构函数        *********************/
ExportEmail::~ExportEmail()
{
    delete ui;
}

/*********************  设置标题     *********************/
void ExportEmail::setTitle(QString text)
{
    titleBar->setTitle(text);
    ui->lineEdit->setPlaceholderText(text);
}

/*********************  显示窗口     *********************/
void ExportEmail::showWidget()
{
    titleBar->setTitle(GLOBALDEF::EXPORTEMAIL);
    ui->lineEdit->setText(CONFIGJSON->getEmailText());
    this->activateWindow();
    this->show();
}

/*********************  点击确定事件     *********************/
void ExportEmail::on_pushButtonOk_clicked()
{
    if(ui->lineEdit->text().isEmpty()) return;

    this->close();

    emit sendEmail(ui->lineEdit->text());

    QRegExp rx;
    rx.setPatternSyntax(QRegExp::RegExp);
    rx.setCaseSensitivity(Qt::CaseSensitive);
    rx.setPattern(GLOBALDEF::EMAILREG);            //匹配邮箱字符串
    if(rx.exactMatch(ui->lineEdit->text()))
    {
        CONFIGJSON->setEmailText(ui->lineEdit->text());
    }
}

/*********************  取消事件        *********************/
void ExportEmail::on_pushButtonCancel_clicked()
{
    this->close();
}

/*********************  初始化控件      *********************/
void ExportEmail::initControl()
{
    titleBar = new TitleBar(this);

    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);
}

/*********************  改变事件        *********************/
void ExportEmail::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}
