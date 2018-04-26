#include "lookimage.h"
#include "ui_lookimage.h"
#include <QPixmap>
#include <QDesktopWidget>

/************************   构造函数           ************************/
LookImage::LookImage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LookImage)
  ,titleBar(NULL)
  ,scaledValue(1)
{
    ui->setupUi(this);

    this->initControl();
}

/************************   析构函数           ************************/
LookImage::~LookImage()
{
    delete ui;
}

/************************   显示窗口           ************************/
void LookImage::showWidget(QPixmap pixmap, QString imagePath)
{
    qDebug()<<"1111111111111";

    const static int ADDWIDTH = 20;
    const static int RESIZEWIDTH = 500;
    const static int RECESIZEHEIGHT = 700;

    QDesktopWidget *desktop = QApplication::desktop();
    const static int DESKTOPWIDTH = desktop->width();
    const static int DESKTOPHEIGHT = desktop->height();

    titleBar->setTitle(GLOBALDEF::LOOKIMAGE);
    ui->labelImage->clear();
    if(imagePath.isEmpty() && pixmap.isNull())
    {
        this->resize(RESIZEWIDTH, RECESIZEHEIGHT);
        ui->labelImage->setText(tr("暂无图片可以预览！"));
    }
    else
    {
        sourceImage = imagePath.isEmpty() ? pixmap.toImage() : QImage(imagePath);

        QImage scaleImage = sourceImage;
        float scaleFactor = 1;

        if(sourceImage.width() > RESIZEWIDTH || sourceImage.height() > RECESIZEHEIGHT)
        {
            if(sourceImage.height() + titleBar->getTitleBarHeight() > DESKTOPHEIGHT)
            {
                scaleFactor = sourceImage.height() * 1.2 / (DESKTOPHEIGHT * 1.);
            }
            else if(sourceImage.width() > DESKTOPWIDTH)
            {
                scaleFactor = sourceImage.width() * 1.2 / (DESKTOPWIDTH * 1.);
            }

            this->resize(sourceImage.width() / scaleFactor , (sourceImage.height() / scaleFactor + titleBar->getTitleBarHeight()));

            scaleImage = scaleImage.scaled(sourceImage.width() / scaleFactor - ADDWIDTH, sourceImage.height() / scaleFactor - ADDWIDTH);
        }
        else
        {
            this->resize(RESIZEWIDTH, RECESIZEHEIGHT);
        }

        if(!sourceImage.isNull()) ui->labelImage->setPixmap(QPixmap::fromImage(scaleImage));
    }

    this->move((DESKTOPWIDTH - this->width()) / 2, (DESKTOPHEIGHT - this->height()) / 2);

    this->show();
}

/************************   初始化控件         ************************/
void LookImage::initControl()
{
    titleBar = new TitleBar(this);
    titleBar->setIcon(GLOBALDEF::APPLOGO);
    titleBar->subButton(TITLEBAR::MAXMINWIDGET);

    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    ui->scrollAreaWidgetContents->installEventFilter(this);
    ui->labelImage->installEventFilter(this);
}

/************************   过滤事件           ************************/
bool LookImage::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->scrollAreaWidgetContents && event->type()==QEvent::Paint)
    {
        return QWidget::eventFilter(watched,event);
    }
    else if(watched == ui->labelImage && event->type() == QEvent::Wheel)
    {
        QWheelEvent * wheelEvent = static_cast<QWheelEvent *>(event);
        if(wheelEvent->delta() > 0)
        {
            if(scaledValue >= 5) QWidget::eventFilter(watched, event);

            scaledValue += 0.1;
        }
        else
        {
            if(scaledValue <= 0) QWidget::eventFilter(watched, event);

            scaledValue -= 0.1;
        }

        if(!sourceImage.isNull())
        {
            float width =  sourceImage.width() * scaledValue;
            float height = sourceImage.height() * scaledValue;

            QImage imageScaled = sourceImage.scaled(width, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

            ui->labelImage->setPixmap(QPixmap::fromImage(imageScaled));
        }
    }

    return QWidget::eventFilter(watched, event);
}

/************************   改变事件           ************************/
void LookImage::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), titleBar->getTitleBarHeight());
}
