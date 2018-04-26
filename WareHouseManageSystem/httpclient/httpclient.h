#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QObject>

/***************************************************************
   功能:HTTP客户端

   创建人:YYC

   创建时间:2017-11-21
**************************************************************/
#define URLMAXSIZE 500

#define HTTPCLIENT HttpClient::getInstance()

typedef QList<QMap<QString, QString>> MapList;
typedef QMap<QString, QString> Map;

class HttpClient : public QObject
{
    Q_OBJECT
public:
    static HttpClient * getInstance();

    void getUrlReq(const QString &urlStr, int type);
    void postUrlReq(QString urlStr, QByteArray &data, int type);
    void readJsonList(QJsonObject jsonObject, QString itemName, MapList &mapList);
    void readJsonMap(QJsonObject jsonObject, QString itemName, Map &mapItem);
    QString findMapValue(QList<Map>mapList, QString keyName, QString key);
    QString makeJson(QList<QString> data);
    QString makeJson(MapList mapListData);

    Map getMapHttpData() const;
public slots:

    //登录接口
    void userLoginFinished(QNetworkReply *reply);
    void outLoginFinished(QNetworkReply *reply);
    void userListFinished(QNetworkReply *reply);
    void userAddFinished(QNetworkReply *reply);
    void userEditFinished(QNetworkReply *reply);
    void userDelFinished(QNetworkReply *reply);

    //权限接口
    void ruleListFinished(QNetworkReply *reply);
    void ruleAddFinished(QNetworkReply *reply);
    void ruleEditFinished(QNetworkReply *reply);
    void ruleDelFinished(QNetworkReply *reply);

    //用户组接口
    void groupListFinished(QNetworkReply *reply);
    void groupAddFinished(QNetworkReply *reply);
    void groupEditFinished(QNetworkReply *reply);
    void groupDelFinished(QNetworkReply *reply);

    //原料设置接口
    void materialListFinished(QNetworkReply *reply);
    void materialDetailsFinished(QNetworkReply *reply);
    void matDownLoadImageFinished(QNetworkReply *reply);
    void matAddMatShowFinished(QNetworkReply *reply);
    void matAddMatFinished(QNetworkReply *reply);
    void matEditMatFinished(QNetworkReply *reply);
    void matMatDelFinished(QNetworkReply *reply);
    void matDelMatFinished(QNetworkReply *reply);
    void matFinallyCatFinished(QNetworkReply *reply);
    void matMatExgTypeFinished(QNetworkReply *reply);
    void matExtendEmailFinished(QNetworkReply *reply);

    //分类接口
    void matCatListFinished(QNetworkReply *reply);
    void matCatListShowFinished(QNetworkReply *reply);
    void matAddTypeFinished(QNetworkReply *reply);
    void matEditTypeShowFinished(QNetworkReply *reply);
    void matEditTypeFinished(QNetworkReply *reply);
    void matDelTypeFinished(QNetworkReply *reply);

    //单位接口
    void matUnitListFinished(QNetworkReply *reply);
    void matUnitAddFinished(QNetworkReply *reply);
    void matUnitDelFinished(QNetworkReply *reply);
    void matUnitSelSideFinished(QNetworkReply *reply);

    //仓库接口
    void warHosListFinish(QNetworkReply *reply);
    void warHosDetailsFinish(QNetworkReply *reply);
    void warHosGoodsTypeFinish(QNetworkReply *reply);
    void warHosGoodsListFinish(QNetworkReply *reply);
    void warHosAddFinish(QNetworkReply *reply);
    void warHosEditFinish(QNetworkReply *reply);
    void warHosDelFinish(QNetworkReply *reply);
    void warHosSearchFinish(QNetworkReply *reply);

    //供应商接口
    void supAddFinish(QNetworkReply *reply);
    void supAddMatFinish(QNetworkReply *reply);
    void supAddCatFinish(QNetworkReply *reply);
    void supGetCatFinish(QNetworkReply *reply);
    void supUpdateCatFinish(QNetworkReply *reply);
    void supDelCatFinish(QNetworkReply *reply);
    void supGetListFinish(QNetworkReply *reply);
    void supDetailsFinish(QNetworkReply *reply);
    void supUpdateFinish(QNetworkReply *reply);
    void supDelMatFinish(QNetworkReply *reply);
    void supDelFinish(QNetworkReply *reply);
    void supSelMatFinish(QNetworkReply *reply);
    void supGetMatFinish(QNetworkReply *reply);
    void supExtendFinish(QNetworkReply *reply);

    //模板接口
    void temMatListFinish(QNetworkReply *reply);
    void temAddFinish(QNetworkReply *reply);
    void temAddMatFinish(QNetworkReply *reply);
    void temListFinish(QNetworkReply *reply);
    void temDetailsFinish(QNetworkReply *reply);
    void temUpdateFinish(QNetworkReply *reply);
    void temDelMatFinish(QNetworkReply *reply);
    void temDeleteFinish(QNetworkReply *reply);
    void temGetMatListFinish(QNetworkReply *reply);
    void temMatTypeListFinish(QNetworkReply *reply);

    //菜品原料配比接口
    void bomFoodListFinish(QNetworkReply *reply);
    void bomFoodGetIdFinish(QNetworkReply *reply);
    void bomMatOldFinish(QNetworkReply *reply);
    void bomMatDelFinish(QNetworkReply *reply);
    void bomMatUpdateFinish(QNetworkReply *reply);
    void bomMatAddFinish(QNetworkReply *reply);
    void bomMatNewFinish(QNetworkReply *reply);
    void bomSaveUpdateFinish(QNetworkReply *reply);
    void bomMatListFinish(QNetworkReply *reply);

    //采购订单接口
    void purSelAllFinish(QNetworkReply *reply);
    void purIndentFinish(QNetworkReply *reply);
    void purAddIndentFinish(QNetworkReply *reply);
    void purSelFinish(QNetworkReply *reply);
    void purGetMatFinish(QNetworkReply *reply);
    void purUpdateFinish(QNetworkReply *reply);
    void purAddMatFinish(QNetworkReply *reply);
    void purDelMatFinish(QNetworkReply *reply);
    void purSelMatFinish(QNetworkReply *reply);
    void purUpdateMatFinish(QNetworkReply *reply);
    void purExamineFinish(QNetworkReply *reply);
    void purAffirmPageFinish(QNetworkReply *reply);
    void purAffirmFinish(QNetworkReply *reply);
    void purCopyFinish(QNetworkReply *reply);
    void purDelFinish(QNetworkReply *reply);
    void purSelTemplateFinish(QNetworkReply *reply);
    void purNumberFinish(QNetworkReply *reply);
    void purTemplateAddFinish(QNetworkReply *reply);
    void purSelDisposeFinish(QNetworkReply *reply);
    void purSelectPageFinish(QNetworkReply *reply);
    void purSelectFinish(QNetworkReply *reply);
    void purExtendFinish(QNetworkReply *reply);


    //采购入库接口
    void stoSelFinish(QNetworkReply *reply);
    void stoGetIdFinish(QNetworkReply *reply);
    void stoSelDataFinish(QNetworkReply *reply);
    void stoSelMatFinish(QNetworkReply *reply);
    void stoAddMatFinish(QNetworkReply *reply);
    void stoGetMatFinish(QNetworkReply *reply);
    void stoUpdateMatFinish(QNetworkReply *reply);
    void stoDelMatFinish(QNetworkReply *reply);
    void stoSelSideFinish(QNetworkReply *reply);
    void stoJudgeFinish(QNetworkReply *reply);
    void stoUpdateSideFinish(QNetworkReply *reply);
    void stoDelSideFinish(QNetworkReply *reply);
    void stoCopyOrderFinish(QNetworkReply *reply);
    void stoAddStoPageFinish(QNetworkReply *reply);
    void stoAddFinish(QNetworkReply *reply);
    void stoUpdateFinish(QNetworkReply *reply);
    void stoRefuseFinish(QNetworkReply *reply);
    void stoConfirmPageFinish(QNetworkReply *reply);
    void stoConfirmFinish(QNetworkReply *reply);
    void stoDelFinish(QNetworkReply *reply);
    void stoReConfirmFinish(QNetworkReply *reply);
    void stoDelPageFinish(QNetworkReply *reply);
    void stoSelectPurFinish(QNetworkReply *reply);
    void stoExpendEmailFinish(QNetworkReply *reply);
    void stoSelDisposeFinish(QNetworkReply *reply);
    void stoSelectPageFinish(QNetworkReply *reply);
    void stoSelectFinish(QNetworkReply *reply);
    void stoStorageFinish(QNetworkReply *reply);
    void stoStorageHintFinish(QNetworkReply *reply);

    //采购退货接口
    void retSelFinish(QNetworkReply *reply);
    void retDataFinish(QNetworkReply *reply);
    void retUpdateFinish(QNetworkReply *reply);
    void retAddPageFinish(QNetworkReply *reply);
    void retAddFinish(QNetworkReply *reply);
    void retSelMatFinish(QNetworkReply *reply);
    void retAddMatFinish(QNetworkReply *reply);
    void retGatMatFinish(QNetworkReply *reply);
    void retUpdateMatFinish(QNetworkReply *reply);
    void retDelMatFinish(QNetworkReply *reply);
    void retSelSideFinish(QNetworkReply *reply);
    void retJudgeFinish(QNetworkReply *reply);
    void retUpdateSideFinish(QNetworkReply *reply);
    void retDelSideFinish(QNetworkReply *reply);
    void retCopyOrderFinish(QNetworkReply *reply);
    void retConfirmFinish(QNetworkReply *reply);
    void retDelStoFinish(QNetworkReply *reply);
    void retSelDisposeFinish(QNetworkReply *reply);
    void retDelMatShowFinish(QNetworkReply *reply);
    void retSelectPageFinish(QNetworkReply *reply);
    void retSelectFinish(QNetworkReply *reply);
    void retExtendFinish(QNetworkReply *reply);

    //安全库存采购接口
    void safSelMatShowFinish(QNetworkReply *reply);
    void safAffirmFinish(QNetworkReply *reply);

    //原料供应商接口
    void defaultSelMatFinish(QNetworkReply *reply);
    void defaultGetMatFinish(QNetworkReply *reply);
    void defaultUpdateSupFinish(QNetworkReply *reply);
    void defaultGetSupFinish(QNetworkReply *reply);

    //实时库存查询接口
    void timeMatListFinish(QNetworkReply *reply);
    void timeSelMatFinish(QNetworkReply *reply);
    void timeSendEmailFinish(QNetworkReply *reply);

    //库存调整接口
    void adjAddInvFinish(QNetworkReply *reply);
    void adjTypeFinish(QNetworkReply *reply);
    void adjGetMatFinish(QNetworkReply *reply);
    void adjAddMatFinish(QNetworkReply *reply);
    void adjGetInvListFinish(QNetworkReply *reply);
    void adjGetDetFinish(QNetworkReply *reply);
    void adjGetMatDetFinish(QNetworkReply *reply);
    void adjUpdateDasicFinish(QNetworkReply *reply);
    void adjUpdateMatFinish(QNetworkReply *reply);
    void adjAddReasonFinish(QNetworkReply *reply);
    void adjGetReasonFinish(QNetworkReply *reply);
    void adjDelReasonFinish(QNetworkReply *reply);
    void adjDelMatFinish(QNetworkReply *reply);
    void adjSendEmailFinish(QNetworkReply *reply);
    void adjWareHouseFinish(QNetworkReply *reply);
    void adjDelInvFinish(QNetworkReply *reply);
    void adjSelectLogFinish(QNetworkReply *reply);
    void adjPresendFinish(QNetworkReply *reply);
    void adjSelectPageFinish(QNetworkReply *reply);
    void adjSelectFinish(QNetworkReply *reply);
    void adjConvertFinish(QNetworkReply *reply);

    //仓库盘存接口
    void checkSelAllFinish(QNetworkReply *reply);
    void checkSelFinish(QNetworkReply *reply);
    void checkAddPageFinish(QNetworkReply *reply);
    void checkAddFinish(QNetworkReply *reply);
    void checkUpdateFinish(QNetworkReply *reply);
    void checkMatPageFinish(QNetworkReply *reply);
    void checkAddMatPageFinish(QNetworkReply *reply);
    void checkAddMatFinish(QNetworkReply *reply);
    void checkUpdateMatPageFinish(QNetworkReply *reply);
    void checkUpdateMatFinish(QNetworkReply *reply);
    void checkUnitUpdateNumFinish(QNetworkReply *reply);
    void checkUpdateNumFinish(QNetworkReply *reply);
    void checkCancelFinish(QNetworkReply *reply);
    void checkDelFinish(QNetworkReply *reply);
    void checkImportFinish(QNetworkReply *reply);
    void checkAffirmFinish(QNetworkReply *reply);
    void checkSendEmailFinish(QNetworkReply *reply);
    void checkSelDisposeFinish(QNetworkReply *reply);
    void checkDelMatFinish(QNetworkReply *reply);
    void checkSelectPageFinish(QNetworkReply *reply);
    void checkSelectFinish(QNetworkReply *reply);


    //库存变更记录接口
    void changeSelMatFinish(QNetworkReply *reply);
    void changeMatListFinish(QNetworkReply *reply);
    void changeAllMatFinish(QNetworkReply *reply);
    void changeGetMatFinish(QNetworkReply *reply);
    void changeExtendFinish(QNetworkReply *reply);

    //成本调价接口
    void costSelAllFinish(QNetworkReply *reply);
    void costPriceFinish(QNetworkReply *reply);
    void costAddFinish(QNetworkReply *reply);
    void costSelMatFinish(QNetworkReply *reply);
    void costAddMatFinish(QNetworkReply *reply);
    void costSelFinish(QNetworkReply *reply);
    void costUpdateFinish(QNetworkReply *reply);
    void costDelFinish(QNetworkReply *reply);
    void costGetMatFinish(QNetworkReply *reply);
    void costUpdateMatFinish(QNetworkReply *reply);
    void costUpdatePageFinish(QNetworkReply *reply);
    void costUpdateAllMatFinish(QNetworkReply *reply);
    void costDelMatFinish(QNetworkReply *reply);
    void costPresentFinish(QNetworkReply *reply);
    void costAffirmFinish(QNetworkReply *reply);
    void costSelDisposeFinish(QNetworkReply *reply);
    void costSelectPageFinish(QNetworkReply *reply);
    void costSelectFinish(QNetworkReply *reply);


    //库存上下限接口
    void restSelMatFinish(QNetworkReply *reply);
    void restGetMatFinish(QNetworkReply *reply);
    void restUpdateMatFinish(QNetworkReply *reply);

    //店内调拨接口
    void allotSelAllFinish(QNetworkReply *reply);
    void allotAddPageFinish(QNetworkReply *reply);
    void allotAddFinish(QNetworkReply *reply);
    void allotSelFinish(QNetworkReply *reply);
    void allotUpdateFinish(QNetworkReply *reply);
    void allotDelFinish(QNetworkReply *reply);
    void allotSelMatFinish(QNetworkReply *reply);
    void allotAddMatFinish(QNetworkReply *reply);
    void allotGetMatFinish(QNetworkReply *reply);
    void allotUpdateMatFinish(QNetworkReply *reply);
    void allotDelMatFinish(QNetworkReply *reply);
    void allotUpdateAllPageFinish(QNetworkReply *reply);
    void allotUpdateAllMatFinish(QNetworkReply *reply);
    void allotPresendFinish(QNetworkReply *reply);
    void allotCancelFinish(QNetworkReply *reply);
    void allotAffirmFinish(QNetworkReply *reply);
    void allotReconfirmFinish(QNetworkReply *reply);
    void allotSendEmailFinish(QNetworkReply *reply);
    void allotSelDisposeFinish(QNetworkReply *reply);
    void allotSelectPageFinish(QNetworkReply *reply);
    void allotSelectFinish(QNetworkReply *reply);


    //报表中心接口
    void stateStoPageFinish(QNetworkReply *reply);
    void stateStorageFinish(QNetworkReply *reply);
    void stateStorageExtendFinish(QNetworkReply *reply);
    void stateStoGatherPageFinish(QNetworkReply *reply);
    void stateStoGatherFinish(QNetworkReply *reply);
    void stateStoGatherExtendFinish(QNetworkReply *reply);
    void stateRetPageFinish(QNetworkReply *reply);
    void stateReturnsFinish(QNetworkReply *reply);
    void stateReturnsExtendFinish(QNetworkReply *reply);
    void stateAdjPageFinish(QNetworkReply *reply);
    void stateAdjustFinish(QNetworkReply *reply);
    void stateAdjustExtendFinish(QNetworkReply *reply);
    void stateCheckPageFinish(QNetworkReply *reply);
    void stateCheckFinish(QNetworkReply *reply);
    void stateCheckExtendFinish(QNetworkReply *reply);
    void stateCheckGatherPageFinish(QNetworkReply *reply);
    void stateCheckGatherFinish(QNetworkReply *reply);
    void stateCheckGatherExtendFinish(QNetworkReply *reply);
    void stateSupPageFinish(QNetworkReply *reply);
    void stateSupplierFinish(QNetworkReply *reply);
    void stateSupplierExtendFinish(QNetworkReply *reply);
    void stateSupGatherPageFinish(QNetworkReply *reply);
    void stateSupGatherFinish(QNetworkReply *reply);
    void stateSupGatherExtendFinish(QNetworkReply *reply);
    void stateSelectMatPageFinish(QNetworkReply *reply);
    void stateSelectMatFinish(QNetworkReply *reply);
    void stateSelMatExtendFinish(QNetworkReply *reply);

    //支出结算接口
    void accountAllFinish(QNetworkReply *reply);
    void accountStoUpdateFinish(QNetworkReply *reply);
    void accountRetUpdateFinish(QNetworkReply *reply);
    void accountAffirmProFinish(QNetworkReply *reply);
    void accountAffirmAccFinish(QNetworkReply *reply);
    void accountSelDisposeFinish(QNetworkReply *reply);
    void accountSelStoMatFinish(QNetworkReply *reply);
    void accountSelRetMatFinish(QNetworkReply *reply);
    void accountFiltratePageFinish(QNetworkReply *reply);
    void accountFiltrateFinish(QNetworkReply *reply);
    void accountSendEmailFinish(QNetworkReply *reply);

    //销售接口
    void todaySelTodayFinish(QNetworkReply *reply);

    //更新接口
    void updateClientFinish(QNetworkReply *reply);

private:
    HttpClient();                                         //构造函数
    void initValue();                                     //初始化函数
    static HttpClient *instance;                          //单例对象
    QString publicToken;                                  //密钥
    QString publicUsrId;                                  //用户ID

    QVector<QNetworkAccessManager*>netWorVector;          //网络对象容器

    //使用函数指针
    typedef void (HttpClient::*CommandFunc)(QNetworkReply *reply);
    CommandFunc DataFunc[URLMAXSIZE];

    void readJson(QNetworkReply *reply);
    Map mapHttpData;
};

#endif // HTTPCLIENT_H
