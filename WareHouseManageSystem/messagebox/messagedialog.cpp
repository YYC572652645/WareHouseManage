#include "messagedialog.h"
#include "ui_messagedialog.h"
#include "global/globaldef.h"

/****************          构造函数              ***************/
MessageDialog::MessageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MessageDialog)
  ,mousePress(false)
  ,titleLabel(NULL)
  ,imgLabel(NULL)
  ,msgLabel(NULL)
  ,cancelButton(NULL)
  ,okButton(NULL)
{
    ui->setupUi(this);

    okText     = tr("确定");
    cancelText = tr("取消");

    this->setWindowTitle(tr("系统提示"));             //设置标题
    this->resize(320, 160);                         //重定义界面大小
    int width = this->width();                      //获取界面宽度
    int height = this->height();                    //获取界面高度
    this->setWindowFlags(Qt::FramelessWindowHint);

    //设置标题
    titleLabel = new QLabel(this);
    titleLabel->setObjectName(QString::fromUtf8("labelOne"));
    QFont font = titleLabel->font();
    font.setBold(true);
    titleLabel->setFont(font);
    titleLabel->setGeometry(0, 0, width - 50, 30);

    //设置图片
    imgLabel=new QLabel(this);
    imgLabel->setGeometry(20, 50, 36, 36);
    imgLabel->setScaledContents(true);

    //设置消息
    msgLabel=new QLabel(this);
    msgLabel->setGeometry(65, 60, width - 100, 50);
    msgLabel->setWordWrap(true);
    msgLabel->setAlignment(Qt::AlignTop);

    //取消按钮
    cancelButton = new QPushButton(this);
    cancelButton->resize(100, 25);
    cancelButton->move(width - cancelButton->width() - 10, height - 35);

    //确定按钮
    okButton = new QPushButton(this);
    okButton->resize(100,25);
    okButton->move(width - okButton->width() - cancelButton->width() - 20, height - 35);

    //连接信号与槽
    connect(okButton,     SIGNAL(clicked(bool)), this, SLOT(okOperate()));
    connect(cancelButton, SIGNAL(clicked(bool)), this, SLOT(cancelOperate()));

    this->move(parent->width() / 2 - this->width() / 2, parent->height() / 2 - this->height() / 2);

    this->setWindowModality(Qt::ApplicationModal);

    QDialog::setTabOrder(okButton, cancelButton);
}

/****************          析构函数              ***************/
MessageDialog::~MessageDialog()
{
    delete ui;
}

/****************          设置函数              ***************/
int MessageDialog::setInfo(QString info, bool imageFlage, bool isOkHidden)
{
    //设置标题
    titleLabel->setText(" " + GLOBALDEF::SYSTEMPORT);


    //设置提示信息
    msgLabel->setText(info);

    //设置图标
    if(imageFlage)
    {
        imgLabel->setPixmap(QPixmap(":/image/image/ok.png"));
    }
    else
    {
        imgLabel->setPixmap(QPixmap(":/image/image/failure.png"));
    }

    //是否隐藏确定按钮
    okButton->setHidden(isOkHidden);
    if(isOkHidden)
    {
        cancelButton->setText(okText);
    }
    else
    {
        okButton->setText(okText);
        cancelButton->setText(cancelText);
    }

    return this->exec();
}

/****************          画图函数              ***************/
void MessageDialog::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.drawPixmap(rect(),QPixmap(":/image/image/messagebackground.png"));
    QBitmap bitmap(this->size());

    QPainter painterSecond(&bitmap);
    painterSecond.fillRect(bitmap.rect(),Qt::white);
    painterSecond.setBrush(QColor(0, 0, 0));
    painterSecond.drawRoundedRect(rect(), 4, 4);
    setMask(bitmap);
}

/****************          鼠标点击              ***************/
void MessageDialog::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) mousePress = true;

    movePoint = event->globalPos()-pos();
}

/****************          鼠标释放              ***************/
void MessageDialog::mouseReleaseEvent(QMouseEvent *event)
{
    mousePress = false;
}

/****************          鼠标移动              ***************/
void MessageDialog::mouseMoveEvent(QMouseEvent *event)
{
    if( mousePress)
    {
        QPoint movePos = event->globalPos();
        move(movePos - movePoint);
    }
}

/****************          确定函数              ***************/
void MessageDialog::okOperate()
{
    this->accept();
}

/****************          取消函数              ***************/
void MessageDialog::cancelOperate()
{
    this->reject();
}


MessageBox * MessageBox::instance  = NULL;

/****************          单例模式              ***************/
MessageBox *MessageBox::getInstance()
{
    if(NULL == instance)
    {
        instance = new MessageBox();
    }

    return instance;
}

/****************          显示窗口              ***************/
int MessageBox::showMessageBox(QWidget *parent, QString info, bool imageFlage, bool isOkHidden)
{
    MessageDialog messageDialog(parent);

    return messageDialog.setInfo(info, imageFlage, isOkHidden);
}

/****************          构造函数              ***************/
MessageBox::MessageBox()
{

}
