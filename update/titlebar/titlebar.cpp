#include "titlebar.h"
#include <QStyle>
#include <QHBoxLayout>
#include <QDebug>
#include <QListView>
#include "globaldef.hpp"


/***************************            构造函数              ***************************/
TitleBar::TitleBar(QWidget *parent) : QWidget(parent),titleBarHeight(50)
{
    //最大化按钮设置图标
    QPixmap pixMap = this->style()->standardPixmap(QStyle::SP_TitleBarMaxButton);
    maxButton = new QPushButton(this);
    maxButton->setIcon(pixMap);
    maxButton->setObjectName(GLOBALDEF::CLOSEBTNNAME);

    //最小化按钮设置图标
    pixMap = this->style()->standardPixmap(QStyle::SP_TitleBarMinButton);
    minButton = new QPushButton(this);
    minButton->setIcon(pixMap);
    minButton->setObjectName(GLOBALDEF::CLOSEBTNNAME);

    //关闭按钮设置图标
    pixMap = this->style()->standardPixmap(QStyle::SP_TitleBarCloseButton);
    closeButton = new QPushButton(this);
    closeButton->setIcon(pixMap);
    closeButton->setObjectName(GLOBALDEF::CLOSEBTNNAME);

    closeButton->setStyleSheet("QPushButton:hover"
                               "{background-color: darkred;border-radius:5px;"
                               "color:white;}QPushButton:hover:pressed"
                               "{background-color:darkred;border-radius:5px;"
                               "color:white;}QPushButton{"
                               "background-color:rgb(100,100,100);color:white;"
                               "border-radius:5px;height: 15px;max-width: 25px;"
                               "spacing: 10px;padding: 0px 0px;}");

    closeButton->setMinimumWidth(25);
    closeButton->setMaximumWidth(25);

    //设置标签
    imgLabel = new QLabel(this);
    titleLabel = new QLabel(this);
    titleLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    titleLabel->setStyleSheet("color:white");

    //设置控件大小
    imgLabel->setFixedSize(CONTROLWIDTH, CONTROLWIDTH);
    imgLabel->setScaledContents(true);

    //设置控件大小
    minButton->setFixedSize(CONTROLWIDTH, CONTROLWIDTH);
    maxButton->setFixedSize(CONTROLWIDTH, CONTROLWIDTH);
    closeButton->setFixedSize(CONTROLWIDTH, CONTROLWIDTH);

    //设置布局
    QHBoxLayout *hBoxLayout = new QHBoxLayout(this);
    hBoxLayout->addWidget(imgLabel);
    hBoxLayout->addSpacing(5);
    hBoxLayout->addWidget(titleLabel);
    hBoxLayout->addWidget(minButton);
    hBoxLayout->addWidget(maxButton);
    hBoxLayout->addWidget(closeButton);
    hBoxLayout->setSpacing(0);
    hBoxLayout->setContentsMargins(5, 0, 5, 0);
    this->setLayout(hBoxLayout);

    //设置背景色
    QPalette paletteColor(palette());
    paletteColor.setColor(QPalette::Background, QColor(44, 62, 80));
    this->setAutoFillBackground(true);
    this->setPalette(paletteColor);

    //重置窗口大小
    this->resize(parent->width(), titleBarHeight);

    //设置父类窗口
    parentWidget = parent;

    this->initValue();
}

/***************************            设置背景色              ***************************/
void TitleBar::setBackGround()
{
    if(NULL != minButton)
    {
        minButton->setStyleSheet("QPushButton:hover{background-color: darkred;border-radius:5px; image:none;}");
    }
    closeButton->setStyleSheet("QPushButton:hover{background-color: darkred;border-radius:5px; image:none;}");
    this->setStyleSheet("QWidget{background-color: rgb(255, 255, 255);image: url(:/image/image/loginbackground.png);}");
}

/***************************            设置标题              ***************************/
void TitleBar::setTitle(const QString &title)
{
    titleLabel->setText(title);
}

/***************************            设置图标              ***************************/
void TitleBar::setIcon(const QString &icon)
{
    imgLabel->setPixmap(QPixmap(icon));
}

/***************************            设置按钮              ***************************/
void TitleBar::subButton(const int &type)
{
    if(type == TITLEBAR::MINWIDGET)
    {
        SAFEDELETE(minButton);
    }
    else if(type == TITLEBAR::MAXWIDGET)
    {
        SAFEDELETE(maxButton);
    }
    else if(type == TITLEBAR::MAXMINWIDGET)
    {
        SAFEDELETE(minButton);
        SAFEDELETE(maxButton);
    }
    else
    {
        SAFEDELETE(minButton);
        SAFEDELETE(maxButton);
        SAFEDELETE(closeButton);
    }
}

/***************************            初始化              ***************************/
void TitleBar::initValue()
{
    //连接信号与槽
    connect(minButton,   SIGNAL(clicked(bool)), this, SLOT(slotButton()));
    connect(maxButton,   SIGNAL(clicked(bool)), this, SLOT(slotButton()));
    connect(closeButton, SIGNAL(clicked(bool)), this, SLOT(slotButton()));

    //按钮点击标志位
    mousePress = false;
}

/***************************            标题栏按钮                 ***************************/
void TitleBar::slotButton()
{
    QPushButton *pButton = qobject_cast<QPushButton *>(sender());
    QWidget *pWindow = this->window();
    if(pWindow->isTopLevel())
    {
        if (pButton == minButton)
        {
            pWindow->showMinimized();
        }
        else if (pButton == maxButton)
        {
            pWindow->isMaximized() ? pWindow->showNormal() : pWindow->showMaximized();

            static int count = 0;

            if(count % 2 == 0)
            {
                QPixmap normalPix = style()->standardPixmap(QStyle::SP_TitleBarNormalButton);
                maxButton->setIcon(normalPix);
            }
            else
            {
                QPixmap maxPix = style()->standardPixmap(QStyle::SP_TitleBarMaxButton);
                maxButton->setIcon(maxPix);
            }

            count ++;
        }
        else if (pButton == closeButton)
        {
            pWindow->close();
        }
    }
}

/***************************            获取高度              ***************************/
int TitleBar::getTitleBarHeight() const
{
    return titleBarHeight;
}

/***************************            设置高度              ***************************/
void TitleBar::setTitleBarHeight(int value)
{
    titleBarHeight = value;
}

/***************************            鼠标点击              ***************************/
void TitleBar::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        mousePress = true;
    }
    movePoint = event->globalPos() - parentWidget->pos();
}

/**************************             鼠标释放              ***************************/
void TitleBar::mouseReleaseEvent(QMouseEvent *event)
{
    mousePress = false;
}

/**************************             鼠标移动              **************************/
void TitleBar::mouseMoveEvent(QMouseEvent *event)
{
    if(mousePress)
    {
        QPoint movePos = event->globalPos();
        parentWidget->move(movePos - movePoint);
    }
}
