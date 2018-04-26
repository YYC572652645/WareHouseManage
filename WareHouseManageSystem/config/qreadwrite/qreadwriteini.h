
#ifndef QREADWRITEINI_H
#define QREADWRITEINI_H
#include<QSettings>

/***************************************************************
   功能:读取配置INI文件

   创建人:殷宇辰

   创建时间:2018-03-14
**************************************************************/

#define CONFIGINI QReadWriteIni::getInstance()

class QReadWriteIni
{
public:

    static QReadWriteIni * getInstance();      //单例模式
    void readIni();                            //读取配置文件
    void writeIni(QString key, QString value); //写入配置
    void writeLanguage(QString language);      //写入语言
    void writeVersion(QString version);        //写入版本号

    QString getLanguage() const;               //获取语言
    QString getVersion() const;                //获取版本

private:
    static QReadWriteIni *instance;            //静态对象
    QReadWriteIni();                           //构造函数
    QString language;                          //语言
    QString version;                           //版本号

};

#endif // QREADWRITEINI_H
