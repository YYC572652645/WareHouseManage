#ifndef JSONCONFIG_H
#define JSONCONFIG_H
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include <QFile>
#include "global/globaldef.h"

/***************************************************************
   功能:读取配置文件

   创建人:YYC

   创建时间:2017-11-22
**************************************************************/

#define CONFIGJSON JsonConfig::getInstance()

class JsonConfig
{
public:
    static JsonConfig *getInstance();         //单例模式

    void readConfig();                        //读取配置
    void writeConfig(const MapList &mapList); //写入配置

    MapList getMapDataList() const;           //获取信息
    void setEmailText(const QString &value);  //设置邮箱
    QString getEmailText() const;             //获取邮箱
    void setCurrentUser(const QString &value);//设置当前用户名
    QString getCurrentUser() const;           //获取当前用户名
    void setLanguage(const QString &value);   //设置语言
    QString getLanguage() const;              //获取语言

private:
    JsonConfig();
    MapList mapDataList;
    QString emailText;
    QString currentUser;
    QString language;
    static JsonConfig *instance;
};

#endif // JSONCONFIG_H
