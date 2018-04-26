#ifndef GLOBALDEF_HPP
#define GLOBALDEF_HPP

/***************************************************************
   功能:全局命名空间

   创建人:YYC

   创建时间:2018-03-14
**************************************************************/

#include <QString>

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
const static QString CLOSEBTNNAME     = "closeButton";
const static QString APPLOGO          = ":/image/image/app.png";
const static QString TESTJSONPATH     = "http://erp.cloudabull.com/WindowsClient/update.json";  //测试服务器路径
const static QString STANDARDJSONPATH = "http://erp.yeaytvshop.com/WindowsClient/update.json";  //正式服务器路径
const static QString ENGLISH          = ":/qm/qm/english.qm";
const static QString CHINESE          = ":/qm/qm/chinese.qm";

}
#endif // GLOBALDEF_HPP
