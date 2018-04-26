#ifndef MESSAGEURL_H
#define MESSAGEURL_H

/***************************************************************
   功能:http链接

   创建人:YYC

   创建时间:2017-11-28
**************************************************************/

#include <QString>
#include <QList>

#define MESSAGESIZE 500

#define MESSAGEURL(type) MessageUrl::getInstance()->getUrl(type)

class MessageUrl
{
public:
    static MessageUrl * getInstance();

    QString getUrl(int type);
    void initMessageUrl(QString strDomain);
    void initTestMessageUrl();    //测试服务器路径
    void initStandardMsgUrl();    //正式服务器路径

private:
    MessageUrl();
    static MessageUrl * instance;

    QString *urlList;
};

#endif // MESSAGEURL_H
