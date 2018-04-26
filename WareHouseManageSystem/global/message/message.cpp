#include "message.h"

namespace MESSAGE
{
QString NONET           = "当前无网络";
QString LOGINFAILMSG    = "登录失败";
QString SITEISEXIST     = "副单位已存在，请重新选择!";
QString CONVERNOTNULL   = "换算关系不能为空，请确认!";
QString PLEASESELECT    = "请选择副单位!";
QString MAINSITENOTSAME = "副单位不能与主单位相同，请重新选择!";
QString SUPNAMEISNULL   = "供应商名称为空!";
QString SUPNUMBERISNULL = "供应商编号为空!";
QString SUPPEOISNULL    = "联系人为空!";
QString SUPPHONEISNULL  = "手机号码为空!";
QString SUPTAXISNULL    = "税率为空!";
QString TEMNAMEISNULL   = "模板名称为空!";
QString TOTOLERROR      = "比例的总和要等于100!";
QString PURMATMSG       = "存在供应商不能供应的原料，要继续吗？";
QString EMAILISWRONG    = "邮箱格式不正确！";
QString NOSTOERROR      = "已经没有可分仓原料，不能再添加分仓！";
QString NOPURMAT        = "没有要采购的原料，不能生成采购订单！";
QString MAKEPURMAT      = "确认要生成采购订单吗？";
QString PLEASESELECTMAT = "请先选择原料！";
QString SETSUPPLIER     = "已选中%1个原料，确认要统一设置默认供应商吗？";
QString PLEASESETSUP    = "请先选择需要批量操作的原料！";
QString SUPCANNOTSET    = "如果设置的供应商不供应当前的原料，则无法设置，确认要继续吗？";
QString ISPRESENT       = "提交后将进行相应库存调整，确认要提交吗？";
QString STARTNOTEND     = "开始日期不能大于结束日期！";
QString RESTCANNOT      = "上限必须大于下限！";
QString RESTUPNULL      = "已设置上限后不可再设置为空！";
QString RESTLONULL      = "已设置下限后不可再设置为空！";
QString TRANCANOTSAME   = "调出仓库和调入仓库不能相同！";
QString CATCANNOTNULL   = "原料分类不能为空！";
QString MAINNOTNULL     = "主单位不能为空！";
QString CANNOTMYSELF    = "上级分类不能是自身！";
QString SUPCANNOTNULL   = "供应商必填！";
QString TYPECANNOTNULL  = "类型必填！";
QString NODATA          = "当前无数据！";
QString SUPNOTNULL      = "供应商不能为空！";
QString WARHSENOTNULL   = "仓库不能为空！";

/**********************************************
 * 错误提示：
 * 根据服务端错误码进行翻译
 * *********************************************/
QString DATAERROR         = "数据错误！";
QString ADDERROR          = "添加失败！";
QString DELERROR          = "删除失败！";
QString EDITERROR         = "修改失败！";
QString SELECTERROR       = "查询失败！";
QString MATISEXSIT        = "已经存在相同原料名称！";
QString CATEXSITERROR     = "该分类已存在！";
QString FIRSTDELCATMAT    = "请先删除该含有该分类的原料或仓库！";
QString FIRSTDELCATCHILD  = "请先删除该分类的子分类！";
QString MOVETHISCAT       = "上级分类下已存在原料将全部移到本分类下！";
QString REMOVECATMAT      = "请先移除菜品原料配比中的该原料！";
QString REMOVEWARHSEMAT   = "请先移除仓库中的该原料，强行删除将清除仓库原料！";
QString UNITISEXIST       = "该单位已存在！";
QString UNITICANNOTDEL    = "该单位正在使用中，不能删除！";
QString EXTENDERROR       = "导出失败！";
QString WARNAMENOTEXIST   = "仓库名称不存在！";
QString WARNAMEEXIST      = "仓库名称已存在！";
QString FIRSTREMOVEWARNAT = "请先移除仓库中的原料！";
QString SUPCATEXIST       = "供应商分类名称已存在！";
QString SUPEXISTOTHERCAT  = "该供应商下存在别的供应商，不允许删除！";
QString PHONEERROR        = "手机号格式不正确！";
QString INVPHONEERROR     = "发票联系手机号格式不正确！";
QString EMAILERROR        = "邮箱格式不正确！";
QString SUPEXIST          = "当前供应商名称已存在！";
QString SUPNUMBEREXIST    = "供应商编号已存在！";
QString TEMNOTNULL        = "模板名称不能为空！";
QString TEMEXIST          = "已经存在相同的采购模板名称！";
QString MATEXIST          = "不能配置重复原料！";
QString FIRSTSETWAR       = "请先设置出品仓库！";
QString PRICENOTZERO      = "手动设置成本价不能为0！";
QString SUBWAREXIST       = "已经添加该分仓，请重新选择！";
QString SUBWARSAME        = "分仓不能与主仓重复，请重新选择！";
QString WARINVING         = "仓库正在盘存，结束或取消盘存才能完成调拨！";
QString WARNOTEXIST       = "仓库不存在！";
QString SUPNOTEXIST       = "供应商不存在！";
QString RECONFIRMNOTNULL  = "反确认理由不能为空！";
QString NOWWARINVING      = "当前仓库盘存中！";
QString WARMAYDEL         = "调入仓库已被删除/调出仓库已被删除！";
QString SUPNOTGIVEMAT     = "该供应商不供应该原料，不能设置！";
QString CHECKISEXIST      = "该仓库已存在盘存中的盘存单！";
QString TEMPLATEMATNULL   = "该模板原料为空不能使用，请到 首页-采购模板设置页面 确认模板信息！";
QString INCOMINGNOTEXIST  = "当前采购单或入库单不存在！";
QString MATERIALNOTEXIST  = "该原料不存在！";
QString TRANSFERING       = "仓库正在盘存，结束或取消盘存才能完成调拨！";
QString BARCODEEXIST      = "条形码已存在！";
QString NUMBERNOTZERO     = "入库数量不能为0！";
QString NOTSHOPLOGIN      = "店家未登录或者登录失效！";
QString NOTADMINLOGIN     = "管理员未登录或者登录失效！";
QString NOPRIORITY        = "无权限访问！";
QString ADMINSTEREXIST    = "管理员名称已存在！";
QString MATNOTFINISH      = "当前入库订单有未完全验收原料！";
QString ORDERNOMAT        = "当前订单没有原料！";
QString OPERATEFAILED     = "操作失败或原料分类未修改！";
QString ERROR             = "错误！";

ErrorData errorData[] =
{
    {"登录失败"},
    {"登录成功"},
    {"数据错误"},
    {"店铺不存在"}
};

OperData operType[] =
{
    {"制单"},
    {"提交"},
    {"反确认"},
    {"采购完成"},
    {"确认采购自动创建"},
    {"已收货"},
    {"拒绝收货"},
    {"退货完成"},
    {"调整完成"},
    {"盘存完成"},
    {"取消盘存"},
    {"确认调价"},
    {"拒绝调拨"},
    {"调拨完成"}
};
}
