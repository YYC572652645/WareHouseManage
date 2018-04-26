#include "pushmessage.h"
#include "ui_pushmessage.h"

/************************   构造函数            ************************/
PushMessage::PushMessage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pushmessage)
  ,titleBar(NULL)
  ,timer(NULL)
{
    ui->setupUi(this);

    this->initControl();
}

/************************   析构函数            ************************/
PushMessage::~PushMessage()
{
    delete ui;
}

/************************   显示界面            ************************/
void PushMessage::showWidget(bool language)
{
    this->resize(260, 166);
    ui->frame->setHidden(true);

    if(language)
    {
        ui->labelContent->setPixmap(QPixmap(GLOBALDEF::EERRORIMAGE));
    }
    else
    {
        ui->labelContent->setPixmap(QPixmap(GLOBALDEF::CERRORIMAGE));
    }

    deskRect = QApplication::desktop()->availableGeometry();

    normalPoint.setX(deskRect.width() -  rect().width());

    normalPoint.setY(deskRect.height());

    this->move(normalPoint);

    this->show();

    timer->start();
}

/************************   显示界面            ************************/
void PushMessage::showUpdateWidget()
{
    this->resize(260, 178);
    ui->frame->show();

    ui->labelContent->setPixmap(QPixmap(GLOBALDEF::UPDATEIMAGE));

    deskRect = QApplication::desktop()->availableGeometry();

    normalPoint.setX(deskRect.width() -  rect().width());

    normalPoint.setY(deskRect.height());

    this->move(normalPoint);

    this->show();

    timer->start();
}

/************************   界面改变事件            ************************/
void PushMessage::updateTimer()
{
    if(normalPoint.y() <= deskRect.height() -  rect().height())
    {
        timer->stop();

        return;
    }

    normalPoint = QPoint(normalPoint.x(), normalPoint.y() - GLOBALDEF::MOVEPOINT);

    this->move(normalPoint);
}

/************************   初始化控件            ************************/
void PushMessage::initControl()
{
    timer = new QTimer(this);
    timer->setInterval(GLOBALDEF::WIDGETINTERNAL);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTimer()));

    titleBar = new TitleBar(this);

    titleBar->subButton(TITLEBAR::MAXMINWIDGET);
    titleBar->setTitleBarHeight(35);
    titleBar->setBackGround();
    ui->labelContent->setScaledContents(true);

    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
}

/************************   界面改变事件            ************************/
void PushMessage::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}

/************************   确认更新            ************************/
void PushMessage::on_pushButtonLook_clicked()
{
    emit updateClient();
}
