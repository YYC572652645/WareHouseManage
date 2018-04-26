#include "versiondialog.h"
#include "ui_versiondialog.h"
#include <QDesktopWidget>
#include "global/globaldef.h"

/*********************  构造函数      *********************/
VersionDialog::VersionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VersionDialog)
{
    ui->setupUi(this);
    this->initControl();
}

/*********************  析构函数      *********************/
VersionDialog::~VersionDialog()
{
    delete ui;
}

/*********************  显示窗口      *********************/
void VersionDialog::showWidget(QString dataInfo)
{
    this->activateWindow();
    this->show();

    ui->labelContent->setText(dataInfo);
}

/*********************  初始化控件    *********************/
void VersionDialog::initControl()
{
    titleBar = new TitleBar(this);

    titleBar->setIcon(GLOBALDEF::APPLOGO);
    titleBar->setTitle(tr("版本信息"));

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    ui->lineEditVersion->setText(tr("仓库管理系统%1").arg(GLOBALDEF::VERSION));
}
