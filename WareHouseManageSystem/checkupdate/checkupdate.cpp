#include "checkupdate.h"
#include "ui_checkupdate.h"

/*********************  构造函数      *********************/
CheckUpdate::CheckUpdate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckUpdate)
{
    ui->setupUi(this);
    this->initControl();
}

/*********************  析构函数      *********************/
CheckUpdate::~CheckUpdate()
{
    delete ui;
}

/*********************  显示窗口      *********************/
void CheckUpdate::showWidget(QString dataInfo, bool flage)
{
    if(flage)
    {
        ui->labelContent->setText(tr("当前版本为最新版本！"));
        ui->pushButtonUpdate->setEnabled(false);
        ui->labelContent->setFont(QFont("ZYSong", 14, QFont::Bold));
    }
    else
    {
        ui->labelContent->setText(dataInfo);
        ui->pushButtonUpdate->setEnabled(true);
        ui->labelContent->setFont(QFont("ZYSong", 12));
    }

    this->activateWindow();
    this->show();
}

/*********************  初始化控件      *********************/
void CheckUpdate::initControl()
{
    titleBar = new TitleBar(this);
    titleBar->setTitle(tr("检查更新"));

    titleBar->setIcon(GLOBALDEF::APPLOGO);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);
}

/*********************  改变事件        *********************/
void CheckUpdate::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/*********************  确定更新        *********************/
void CheckUpdate::on_pushButtonUpdate_clicked()
{
    emit okUpdate();
}
