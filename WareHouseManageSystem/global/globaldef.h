#ifndef GLOBALDEF_H
#define GLOBALDEF_H

/***************************************************************
   功能:全局定义

   创建人:YYC

   创建时间:2017-11-21
**************************************************************/

#include <QFile>
#include <QTableWidget>
#include <QHeaderView>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include <QNetworkReply>
#include "httpclient/messageurl/messageurl.h"
#include "httpclient/httpclient.h"
#include "httpclient/protocol.h"
#include <QTreeWidget>
#include <QDate>
#include <QObject>
#include <QTranslator>
#include <QCalendarWidget>
#include "config/jsonconfig/jsonconfig.h"
#include "config/qreadwrite/qreadwriteini.h"
#include "flowlayout/flowlayout.h"
#include "message/message.h"
#include "postarg/postarg.h"

#define SUBONE      -1
#define SUBTWO      -2
#define SUBTHREE    -3

#define ZERO         0
#define ONE          1
#define TWO          2
#define THREE        3
#define FOUR         4
#define FIVE         5
#define SIX          6
#define SEVEN        7
#define EIGHT        8
#define NINE         9
#define TEN          10
#define ELEVEN       11
#define TWELEVE      12
#define THIRTHTEEN   13
#define FOURTHTEEN   14
#define FIFTHTEEN    15

#ifndef DATA
#define  DATA(str)          new QTableWidgetItem(str)
#endif

#ifndef TREEDATA
#define  TREEDATA(widget)   new QTreeWidgetItem(widget)
#endif

#ifndef TREEITEM
#define  TREEITEM()         new QTreeWidgetItem()
#endif

#ifndef ARRAYITEMCOUNT
#define ARRAYITEMCOUNT(array) (static_cast<int>(sizeof(array) / sizeof(*array)))
#endif

#ifndef SAFEDELLIST
#define  SAFEDELLIST(listData)                \
{                                             \
    for(int i = 0; i < listData.size(); i ++) \
{                                         \
    SAFEDELETE(listData[i]);              \
    }                                         \
    listData.clear();                         \
    }
#endif

typedef QList<Map> MapList;
typedef QMap<QString, QString> Map;
typedef QList<QString> List;

#ifndef LOADQSS
#define LOADQSS(qssFile)                      \
{                                             \
    QString strQss;                           \
    QFile file(qssFile);                      \
    file.open(QFile::ReadOnly);               \
    if(file.isOpen())                         \
{                                         \
    strQss=QLatin1String(file.readAll()); \
    qApp->setStyleSheet(strQss);          \
    file.close();                         \
    }                                     \
    }
#endif

#ifndef SAFEDELETE
#define SAFEDELETE(pointer) \
{                           \
    if(pointer)             \
{                           \
    delete pointer;         \
    }                       \
    pointer = NULL;         \
    }
#endif

namespace GLOBALDEF
{
const static QString QSSPATH          = ":/qss/qss/style.qss";
const static QString CLOSEBTNNAME     = "closeButton";
const static QString COMBOBOXMENU     = "comboBoxMenu";
const static QString APPLOGO          = ":/image/image/app.png";
const static QString LOGINSUCCESSIMG  = ":/image/image/success.png";
const static QString LOGINFAILIMG     = ":/image/image/fail.png";
const static QString ADDIMG           = ":/image/image/add.png";
const static QString MESSAGEOK        = ":/image/image/ok.png";
const static QString MESSAGEFAIL      = ":/image/image/failure.png";
const static QString EXTENDIMAGE      = ":/image/image/export.png";
const static QString ADDIMAGE         = ":/image/image/addfile.png";
const static QString EERRORIMAGE      = ":/image/image/eError.png";
const static QString UPDATEIMAGE      = ":/image/image/loign.jpg";
const static QString CERRORIMAGE      = ":/image/image/cError.png";
const static QString DELIMAGE         = ":/image/image/删 除.png";
const static QString EDITIMAGE        = ":/image/image/修改.png";
const static QString JUMPIMAGE        = ":/image/image/跳转.png";
const static QString ALLSELECTIMAGE   = ":/image/image/全选.png";
const static QString NOTSELECTIMAGE   = ":/image/image/全不选.png";
const static QString JSONUSERNAME     = "userName";
const static QString JSONSHOPNUMBER   = "shopNumber";
const static QString JSONPASSWORD     = "passWord";
const static QString EMAILTEXT        = "emailText";
const static QString JSONREMEMBER     = "rememberPsd";
const static QString CURRENTUSER      = "currentUser";
const static QString LANGUAGE         = "language";
const static QString ENGLISH          = ":/qm/qm/english.qm";
const static QString CHINESE          = ":/qm/qm/chinese.qm";
const static QString JSONCONFIG       = "config.json";
const static QString PUTDOWN          = "QPushButton{background-color:transparent;border-image: url(:/image/image/putdown.png);color:white;}";
const static QString PUTON            = "QPushButton{background-color:transparent;border-image: url(:/image/image/puton.png);color:black;}";
const static QString THISSTYLE        = "QLineEdit,QDateEdit,QTimeEdit{height:30px}QComboBox{height:30px;background-color:white;}"
                                        "QPushButton{background-color:rgb(84, 115, 135);color:white;font-size:12px;width:150px;height:30px;border-radius:2px;spacing:2px;padding: 0px 0px;}"
                                        "QPushButton:hover{background-color: rgb(180, 85, 100);color:white;}QPushButton:hover:pressed{background-color:rgb(180, 85, 100);color:white;}";
const static QString SMALLSTYLE       = "QComboBox{background-color:white;}QPushButton{background-color:rgb(84, 115, 135);color:white;font-size:12px;width:150px;height:20px;border-radius:2px;spacing:2px;padding: 0px 0px;}"
                                        "QPushButton:hover{background-color: rgb(180, 85, 100);color:white;}QPushButton:hover:pressed{background-color:rgb(180, 85, 100);color:white;}";
const static QString EMAILREG         = "^[a-z0-9]+([._\\-]*[a-z0-9])*@([a-z0-9]+[-a-z0-9]*[a-z0-9]+.){1,63}[a-z0-9]+$";
const static QString FONTNAME         = "ZYSong";
const static QString SUCCESSSTRING    = "1";
const static int     SUCCESSINTONE    = 1;
const static int     SUCCESSINTZERO   = 0;
const static int     BIGFONTSIZE      = 12;
const static int     WIDGETINTERNAL   = 15;
const static int     MOVEPOINT        = 10;
const static int     ONEDAY           = 24 * 3600;
const static int     DESKTOPHEIGHT    = 900;

//版本号，服务器JSON文件与此保持一致
const static QString VERSION          = "1.5";

//翻译服务端信息
const static QString CHIALL          = "全部";
const static QString ENGALL          = "All";
const static QString CHIUNSUBMIT     = "未提交";
const static QString ENGUNSUBMIT     = "Unsubmitted";
const static QString CHIPURFINISH    = "采购完成";
const static QString ENGPURFINISH    = "Purchase completed";
const static QString CHICUSTOMIZE    = "自定义";
const static QString ENGCUSTOMIZE    = "Customize";
const static QString CHIDISTRIBUTE   = "配送中";
const static QString ENGDISTRIBUTE   = "Distribution";
const static QString CHIRECEIVED     = "已收货";
const static QString ENGRECEIVED     = "Received";
const static QString CHIREJECT       = "已拒绝";
const static QString ENGREJECT       = "Rejected";
const static QString CHIRETURN       = "退货完成";
const static QString ENGRETURN       = "Return completed";

const static QString CHIYESTERDAY    = "昨天";
const static QString ENGYESTERDAY    = "Yesterday";
const static QString CHITODAY        = "今天";
const static QString ENGTODAY        = "Today";
const static QString CHITHISWEEK     = "本周";
const static QString ENGTHISWEEK     = "This week";
const static QString CHILASTWEEK     = "上周";
const static QString ENGLASTWEEK     = "Last week";
const static QString CHITHISMONTH    = "本月";
const static QString ENGTHISMONTH    = "This month";
const static QString CHILASTMONTH    = "上月";
const static QString ENGLASTMONTH    = "Last month";
const static QString CHIADJUST       = "已调整";
const static QString ENGADJUST       = "Adjusted";
const static QString CHIINVENT       = "盘存中";
const static QString ENGINVENT       = "Being invented";
const static QString CHICOMPLETE     = "已完成";
const static QString ENGCOMPLETE     = "Completed";
const static QString CHICANCELINVENT = "取消盘存";
const static QString ENGCANCELINVENT = "Cancel inventory";
const static QString CHICHECK        = "待审核";
const static QString ENGCHECK        = "Waiting for review";
const static QString CHICOSTADJ      = "已调价";
const static QString ENGCOSTADJ      = "Adjusted the price";
const static QString CHIFINISH       = "已完成";
const static QString ENGFINISH       = "Completed";
const static QString CHITRANS        = "调拨中";
const static QString ENGTRANS        = "Transferring";
const static QString CHISTORAGE      = "入库";
const static QString ENGSTORAGE      = "Storage";
const static QString CHIRETURNS      = "退货";
const static QString ENGRETURNS      = "Returns";
const static QString CHIBUSINESS     = "单据业务日期";
const static QString ENGBUSINESS     = "Document business date";
const static QString CHIOPERATION    = "单据操作日期";
const static QString ENGOPERATION    = "Document operation date";
const static QString CHIINVENTD      = "已盘存";
const static QString ENGINVENTD      = "Invented";
const static QString CHIRECO         = "待对账";
const static QString ENGRECO         = "To reconciliation";
const static QString CHITOSETT       = "待结算";
const static QString ENGTOSETT       = "To be settled";
const static QString CHISETT         = "已结算";
const static QString ENGSETT         = "Settled";


extern QString APPNAME;
extern QString SYSTEMPORT;
extern QString NUMBERISNOTNULL;
extern QString WARHOSISNOTNULL;
extern QString CONFIRMDEL;
extern QString CLEARSITEUNIT;
extern QString NETWORKERROR;
extern QString ADDSUCCESS;
extern QString DELSUCCESS;
extern QString EDITSUCCESS;
extern QString SUBMITSUCCESS;
extern QString IMPORTSUCCESS;
extern QString EXPORTSUCCESS;
extern QString EXITSUCCESS;
extern QString CONFIRMSUCCESS;
extern QString MAKESUCCESS;
extern QString RECONFIRMSUCCESS;
extern QString SUCCESS;
extern QString BASEINFO;
extern QString WAREHOUSEINFO;
extern QString PURCHASEINFO;
extern QString CALESINFO;
extern QString FINANCEINFO;
extern QString MATERIALSUPPLIER;
extern QString USERINFO;
extern QString PERMISSIONINFO;
extern QString TODAYHOUSEMONEY;
extern QString REPORTTABLE;
extern QString ACCOUNTMANAGE;
extern QString MATERIALSETUP;
extern QString LOOKIMAGE;
extern QString ADDUNITSIDE;
extern QString ADDMATERIALNAME;
extern QString SUPMATERIAL;
extern QString TABADDMATERIAL;
extern QString TABMATERIALINFO;
extern QString ADDUNITNAME;
extern QString SELECTMATERIAL;
extern QString MATRATIOSETUP;
extern QString TEMPLATESETUP;
extern QString ADDTEMMATERIAL;
extern QString EDITTEMMATERIAL;
extern QString EXCHANGETYPEMORE;
extern QString DELMATERIAL;
extern QString EXCHANGETYPE;
extern QString DELETEDATA;
extern QString MATERIALTYPE;
extern QString SELECTIMAGE;
extern QString IMAGETOOLTIP;
extern QString SAVETEXT;
extern QString OKUPDATE;
extern QString SIDETEXT;
extern QString MAXLIMITPOT;
extern QString WAREHOUSEMANAGE;
extern QString SUPPLIERMANAGE;
extern QString ADDCOMMODITY;
extern QString ADDCOMMODITYTYPE;
extern QString ADDWARHOS;
extern QString WARHOSINFO;
extern QString ADDSUPPLIER;
extern QString SUPPLIERINFO;
extern QString ADDTEMPLATE;
extern QString TEMPLATEINFO;
extern QString SUPPLYMATINFO;
extern QString PLEASESELECT;
extern QString ADDSUPTYPE;
extern QString UPDATESUPTYPE;
extern QString TOTALCOUNT;
extern QString ALLTYPE;
extern QString PURCHASEORDER;
extern QString ADDPURCHASE;
extern QString PURINFO;
extern QString ADDPURMATERIAL;
extern QString EDITPURMATERIAL;
extern QString ADDSTOMATERIAL;
extern QString EDITSTOMATERIAL;
extern QString MATERIALINFO;
extern QString CONFIRMMAT;
extern QString IMPORTHISTORY;
extern QString TEMPLATEPUR;
extern QString PURCHASESTORAGE;
extern QString ADDSTORAGE;
extern QString STORAGEINFO;
extern QString REFUSEREASON;
extern QString RECONFIRMREASON;
extern QString STARTRECEIVE;
extern QString STOEXTEND;
extern QString SUBPOSITION;
extern QString LOGINFO;
extern QString ADDRETURN;
extern QString RETURNINFO;
extern QString SETDEFAULTSUP;
extern QString WAREHOUSESELECT;
extern QString EXTEND;
extern QString TIMEINFO;
extern QString EXPORTEMAIL;
extern QString ADDADJUST;
extern QString ADJUSTINFO;
extern QString CHECKINFO;
extern QString ADDCHECK;
extern QString ADJREASON;
extern QString CHECKMATERIAL;
extern QString ADDCHECKMATERIAL;
extern QString INVENLOG;
extern QString INVENCHANGE;
extern QString COSTINFO;
extern QString ADDCOST;
extern QString TOTALONUMBER;
extern QString COSTPRICESEE;
extern QString SETDEFAULTLIMIT;
extern QString TRANINFO;
extern QString TRANADD;
extern QString SELECTTABLE;
extern QString ADDRETURNMAT;
extern QString EDIDRETURNMAT;
extern QString AUTHORITYMANAGE;

enum MATERIALLABELTYPE
{
    MATNAME,
    MATTYPE,
    MATBARCODE,
    MATMAINUNIT,
    MATADDUNIT,
    MATMAX,
};

enum MATERIALEXTENTYPE
{
    EXTERNSPEC,
    EXTERNSHELF,
    EXTERNIMAGE,
    EXTERNMAX,
};

//窗口类型
enum WIDGETTYPE
{
    LOOKMATERIAL,
    ADDMATERIAL,
};
}

inline void SETTABLEWIDGET(QTableWidget *tableWidget)
{
    //设置单行选中
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    //纵向隐藏序号
    tableWidget->verticalHeader()->setHidden(true);

    //设置为不可编辑
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //设置表头点击禁止塌陷
    tableWidget->horizontalHeader()->setHighlightSections(false);

    //去除点击的虚线
    tableWidget->setFocusPolicy(Qt::NoFocus);

    //设置字体
    tableWidget->setFont(QFont("宋体", 11));

    //设置根据内容调整列宽
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

inline void SETTABLECENTER(QTableWidgetItem *tableWidgetItem)
{
    tableWidgetItem->setTextAlignment(Qt::AlignCenter);
}


inline void SETTREECENTER(QTreeWidgetItem *treeWidgetItem, int index)
{
    treeWidgetItem->setTextAlignment(index, Qt::AlignCenter);
}

inline void SETTREEWIDGET(QTreeWidget *treeWidget, bool flage = false)
{
    //设置单行选中
    treeWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    //设置为不可编辑
    treeWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //去掉表头
    treeWidget->setHeaderHidden(true);

    //设置字体
    if(!flage)
    {
        treeWidget->setFont(QFont("宋体", 11, QFont::Bold));
    }
    else
    {
        treeWidget->setFont(QFont("宋体", 11));
    }
}

inline unsigned int GETTIMET(QTime time)
{
    return time.hour() * 3600 + time.minute() * 60 + time.second();
}

inline unsigned int GETDATATIMET(QDateTime dateTime)
{
    dateTime.setTime(QTime(0, 0, 0));
    return dateTime.toTime_t();
}

inline bool ISERROR(int value)
{
    if(value == GLOBALDEF::SUCCESSINTONE) return false;

    return true;
}

#endif // GLOBALDEF_H
