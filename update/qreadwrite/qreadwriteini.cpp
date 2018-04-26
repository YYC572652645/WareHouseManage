#include "qreadwriteini.h"

QReadWriteIni *QReadWriteIni::instance = NULL;

/****************   构造函数        ***************/
QReadWriteIni::QReadWriteIni()
{
    this->readIni();
}

/****************   单例模式        ***************/
QReadWriteIni *QReadWriteIni::getInstance()
{
    if(NULL == instance)
    {
        instance = new QReadWriteIni();
    }

    return instance;
}

/****************   读取配置文件    ***************/
void QReadWriteIni::readIni()
{
    QSettings *configIniRead = new QSettings("config.ini", QSettings::IniFormat);

    language = configIniRead->value("config/language").toString();
    version = configIniRead->value("config/version").toString();

    delete configIniRead;
}

/****************   写入配置文件    ***************/
void QReadWriteIni::writeIni(QString key, QString value)
{
    if(key.isEmpty()) return;

    QSettings * configIniWrite = new QSettings("config.ini", QSettings::IniFormat);

    configIniWrite->setValue(key, value);

    delete configIniWrite;
}

/****************   写入语言配置    ***************/
void QReadWriteIni::writeLanguage(QString language)
{
    writeIni("config/language", language);
}

/****************   写入版本配置    ***************/
void QReadWriteIni::writeVersion(QString version)
{
    writeIni("config/version", version);
}

/****************   获取语言       ***************/
QString QReadWriteIni::getLanguage() const
{
    return language;
}

/****************   获取版本       ***************/
QString QReadWriteIni::getVersion() const
{
    return version;
}

