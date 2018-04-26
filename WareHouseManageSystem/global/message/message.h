#ifndef MESSAGE_H
#define MESSAGE_H
#include <QString>

/***************************************************************
   功能:提示信息

   创建人:YYC

   创建时间:2017-11-21
**************************************************************/

namespace MESSAGE
{
extern QString NONET;
extern QString LOGINFAILMSG;
extern QString SITEISEXIST;
extern QString CONVERNOTNULL;
extern QString PLEASESELECT;
extern QString MAINSITENOTSAME;
extern QString SUPNAMEISNULL;
extern QString SUPNUMBERISNULL;
extern QString SUPPEOISNULL;
extern QString SUPPHONEISNULL;
extern QString SUPTAXISNULL;
extern QString TEMNAMEISNULL;
extern QString TOTOLERROR;
extern QString PURMATMSG;
extern QString EMAILISWRONG;
extern QString NOSTOERROR;
extern QString NOPURMAT;
extern QString MAKEPURMAT;
extern QString PLEASESELECTMAT;
extern QString SETSUPPLIER;
extern QString PLEASESETSUP;
extern QString SUPCANNOTSET;
extern QString ISPRESENT;
extern QString STARTNOTEND;
extern QString RESTCANNOT;
extern QString RESTUPNULL;
extern QString RESTLONULL;
extern QString TRANCANOTSAME;
extern QString CATCANNOTNULL;
extern QString MAINNOTNULL;
extern QString CANNOTMYSELF;
extern QString SUPCANNOTNULL;
extern QString TYPECANNOTNULL;
extern QString NODATA;
extern QString SUPNOTNULL;
extern QString WARHSENOTNULL;

/**********************************************
 * 错误提示：
 * 根据服务端错误码进行翻译
 * *********************************************/
extern QString DATAERROR;
extern QString ADDERROR;
extern QString DELERROR;
extern QString EDITERROR;
extern QString SELECTERROR;
extern QString MATISEXSIT;
extern QString CATEXSITERROR;
extern QString FIRSTDELCATMAT;
extern QString FIRSTDELCATCHILD;
extern QString MOVETHISCAT;
extern QString REMOVECATMAT;
extern QString REMOVEWARHSEMAT;
extern QString UNITISEXIST;
extern QString UNITICANNOTDEL;
extern QString EXTENDERROR;
extern QString WARNAMENOTEXIST;
extern QString WARNAMEEXIST;
extern QString FIRSTREMOVEWARNAT;
extern QString SUPCATEXIST;
extern QString SUPEXISTOTHERCAT;
extern QString PHONEERROR;
extern QString INVPHONEERROR;
extern QString EMAILERROR;
extern QString SUPEXIST;
extern QString SUPNUMBEREXIST;
extern QString TEMNOTNULL;
extern QString TEMEXIST;
extern QString MATEXIST;
extern QString FIRSTSETWAR;
extern QString PRICENOTZERO;
extern QString SUBWAREXIST;
extern QString SUBWARSAME;
extern QString WARINVING;
extern QString WARNOTEXIST;
extern QString SUPNOTEXIST;
extern QString RECONFIRMNOTNULL;
extern QString NOWWARINVING;
extern QString WARMAYDEL;
extern QString SUPNOTGIVEMAT;
extern QString CHECKISEXIST;
extern QString TEMPLATEMATNULL;
extern QString INCOMINGNOTEXIST;
extern QString MATERIALNOTEXIST;
extern QString TRANSFERING;
extern QString BARCODEEXIST;
extern QString NUMBERNOTZERO;
extern QString NOTSHOPLOGIN;
extern QString NOTADMINLOGIN;
extern QString NOPRIORITY;
extern QString ADMINSTEREXIST;
extern QString MATNOTFINISH;
extern QString ORDERNOMAT;
extern QString OPERATEFAILED;
extern QString ERROR;

typedef struct ErrorData
{
    QString errorText;
}ErrorData;

extern ErrorData errorData[4];

typedef struct OperData
{
    QString operText;
}OperData;

extern OperData operType[14];

}


#endif // MESSAGE_H
