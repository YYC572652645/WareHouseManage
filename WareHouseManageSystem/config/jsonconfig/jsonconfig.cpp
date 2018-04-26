#include "jsonconfig.h"
#include <QDebug>

JsonConfig *JsonConfig::instance = new JsonConfig();

/************************   构造函数            ********************/
JsonConfig::JsonConfig()
{
}

/************************   单例模式            ********************/
JsonConfig *JsonConfig::getInstance()
{
    return instance;
}

/************************   读取配置            ********************/
void JsonConfig::readConfig()
{
    QFile file(GLOBALDEF::JSONCONFIG);
    if(!file.open(QIODevice::ReadOnly)) return;

    mapDataList.clear();
    QString arrayData = QByteArray::fromBase64(QByteArray::fromBase64(file.readAll()));

    QJsonParseError err;
    QJsonDocument jsonDom = QJsonDocument::fromJson(arrayData.toUtf8(), &err);

    if(err.error == QJsonParseError::NoError)
    {
        QJsonObject jsonObject = jsonDom.object();
        QJsonValue jsonValue = jsonObject.value(QString("userList"));

        if(jsonObject.contains(GLOBALDEF::EMAILTEXT))
        {
            emailText = jsonObject.value(GLOBALDEF::EMAILTEXT).toString();
        }
        if(jsonObject.contains(GLOBALDEF::CURRENTUSER))
        {
            currentUser = jsonObject.value(GLOBALDEF::CURRENTUSER).toString();
        }
        if(jsonObject.contains(GLOBALDEF::LANGUAGE))
        {
            language = jsonObject.value(GLOBALDEF::LANGUAGE).toString();
        }

        QJsonArray jsonArray = jsonValue.toArray();

        for(int i = 0; i < jsonArray.size(); i ++)
        {
            QMap<QString, QString>mapData;

            QJsonObject objectItem = jsonArray.at(i).toObject();
            QStringList stringList = objectItem.keys();

            for(int i = 0; i < stringList.size(); i ++)
            {
                mapData[stringList[i]] = objectItem[stringList[i]].toString();
            }

            mapDataList.append(mapData);
        }
    }

    file.close();
}

/************************   写入配置            ********************/
void JsonConfig::writeConfig(const MapList &mapList)
{
    QFile file(GLOBALDEF::JSONCONFIG);
    if(!file.open(QIODevice::WriteOnly)) return;

    mapDataList = mapList;
    QJsonObject jsonTotal;
    QJsonArray  jsonArray;

    for(int i = 0; i < mapList.size(); i ++)
    {
        QJsonObject jsonData;
        for(auto iter = mapList.at(i).begin(); iter != mapList.at(i).end(); iter ++)
        {
            jsonData.insert(iter.key(), iter.value());
        }

        jsonArray.insert(i, jsonData);
    }

    jsonTotal.insert("userList", jsonArray);
    jsonTotal.insert(GLOBALDEF::CURRENTUSER, currentUser);
    jsonTotal.insert(GLOBALDEF::EMAILTEXT, emailText);
    jsonTotal.insert(GLOBALDEF::LANGUAGE, language);

    QJsonDocument document;
    document.setObject(jsonTotal);

    QByteArray arrayData = document.toJson();

    file.write(arrayData.toBase64().toBase64());

    file.close();
}

/************************   获取信息            ********************/
MapList JsonConfig::getMapDataList() const
{
    return mapDataList;
}

/************************   设置邮箱            ********************/
void JsonConfig::setEmailText(const QString &value)
{
    emailText = value;

    this->writeConfig(mapDataList);
}

/************************   获取邮箱            ********************/
QString JsonConfig::getEmailText() const
{
    return emailText;
}

/************************   设置当前用户名       ********************/
void JsonConfig::setCurrentUser(const QString &value)
{
    currentUser = value;
}

/************************   获取当前用户名       ********************/
QString JsonConfig::getCurrentUser() const
{
    return currentUser;
}

/************************   设置语言            ********************/
void JsonConfig::setLanguage(const QString &value)
{
    language = value;
    this->writeConfig(mapDataList);
}

/************************   获取语言            ********************/
QString JsonConfig::getLanguage() const
{
    return language;
}


