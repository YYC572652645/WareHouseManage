#include "httpclient.h"
#include "global/globaldef.h"
#include "httpkey.h"
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include <QNetworkCookieJar>
#include <QNetworkCookie>
#include <QDebug>

HttpClient *HttpClient::instance = new HttpClient();

/*********************     构造函数                 *******************/
HttpClient::HttpClient()
{
    this->initValue();
}

/*********************     初始化函数               *******************/
void HttpClient::initValue()
{
    netWorVector.resize(PROTOCOL::URLMAX);

    //新建HTTP响应对象
    {
        /***************   登录接口   ***************/
        netWorVector[PROTOCOL::URL_USER_LOGIN]    = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_LOGIN_OUT]     = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_USER_LIST]     = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_USER_ADD]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_USER_EDIT]     = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_USER_DEL]      = new QNetworkAccessManager(this);

        /***************   权限接口   ***************/
        netWorVector[PROTOCOL::URL_RULE_LIST]  = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_RULE_ADD]   = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_RULE_EDIT]  = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_RULE_DEL]   = new QNetworkAccessManager(this);

        /***************   用户组接口   ***************/
        netWorVector[PROTOCOL::URL_GROUP_LIST] = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_GROUP_ADD]  = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_GROUP_EDIT] = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_GROUP_DEL]  = new QNetworkAccessManager(this);

        /***************   原料设置接口   ***************/
        netWorVector[PROTOCOL::URL_MAT_LIST]       = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_MAT_DETAILS]    = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_MAT_IMAGE]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ADD_MAT_SHOW]   = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_MAT_ADD]        = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_CATE_EDIT_SHOW] = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_MAT_EDIT]       = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_MAT_DEL]        = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_DEL_MAT]        = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_FINALLY_CAT]    = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_MAT_EXG_TYPE]   = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_MAT_EMAIL]      = new QNetworkAccessManager(this);

        /***************   原料设置接口   ***************/
        netWorVector[PROTOCOL::URL_MAT_CAT_LIST]  = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_MAT_LIST_SHOW] = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_CATEGORY_ADD]  = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_CATEGORY_EDIT] = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_CATEGORY_DEL]  = new QNetworkAccessManager(this);

        /***************   原料设置接口   ***************/
        netWorVector[PROTOCOL::URL_UNIT_LIST]     = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ADD_UNIT]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_DEL_UNIT]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_SEL_SIDE]      = new QNetworkAccessManager(this);

        /***************   仓库接口   ***************/
        netWorVector[PROTOCOL::URL_WARHOS_LIST]       = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_WARHOS_DETAILS]    = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_WARHOS_GOODS_TYPE] = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_WARHOS_GOODS_LIST] = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_WARHOS_ADD]        = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_WARHOS_EDIT]       = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_WARHOS_DEL]        = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_WARHOS_SEARCH]     = new QNetworkAccessManager(this);

        /***************   供应商接口   ***************/
        netWorVector[PROTOCOL::URL_SUP_ADD_SUP]        = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_SUP_ADD_SUP_MAT]    = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_SUP_ADD_SUP_CAT]    = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_SUP_GET_SUP_CAT]    = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_SUP_UPDATE_SUP_CAT] = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_SUP_DEL_SUP_CAT]    = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_SUP_GET_SUP_LIST]   = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_SUP_DETAILS]        = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_SUP_UPDATE_SUP]     = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_SUP_DEL_SUP_MAT]    = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_SUP_DEL_SUP]        = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_SUP_SEL_MATERIAL]   = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_SUP_GET_MATERIAL]   = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_SUP_EXTEND]         = new QNetworkAccessManager(this);

        /***************   模板接口   ***************/
        netWorVector[PROTOCOL::URL_TEM_MAT_LIST]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_TEM_ADD_TEM]       = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_TEM_ADD_MAT]       = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_TEM_LIST]          = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_TEM_DETAILS]       = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_TEM_UPDATE]        = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_TEM_DEL_MAT]       = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_TEM_DELETE]        = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_TEM_GET_MAT_LIST]  = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_TEM_MAT_TYPE_LIST] = new QNetworkAccessManager(this);

        /***************   菜品原料配比接口   ***************/
        netWorVector[PROTOCOL::URL_BOM_FOOD_LIST]    = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_BOM_FOOD_GETID]   = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_BOM_MAT_OLD]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_BOM_MAT_DEL]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_BOM_MAT_UPDATE]   = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_BOM_MAT_ADD]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_BOM_MAT_NEW]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_BOM_SAVE_UPDATE]  = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_BOM_MAT_LIST]     = new QNetworkAccessManager(this);

        /***************  采购订单接口  ***************/
        netWorVector[PROTOCOL::URL_PUR_SEL_ALL]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_PUR_INDENT]       = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_PUR_ADD_INDENT]   = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_PUR_SEL]          = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_PUR_GET_MAT]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_PUR_UPDATE]       = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_PUR_ADD_MAT]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_PUR_DEL_MAT]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_PUR_SEL_MAT]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_PUR_UPDATE_MAT]   = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_PUR_EXAMINE]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_PUR_AFFIRMPAGE]   = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_PUR_AFFIRM]       = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_PUR_COPY]         = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_PUR_DEL]          = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_PUR_SEL_TEMPLATE] = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_PUR_NUMBER]       = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_PUR_TEMPLATE_ADD] = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_PUR_SEL_DISPOSE]  = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_PUR_SELECT_PAGE]  = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_PUR_SELECT]       = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_PUR_EXTEND]       = new QNetworkAccessManager(this);

        /***************  采购入库接口  ***************/
        netWorVector[PROTOCOL::URL_STO_SEL]          = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STO_GET_ID]       = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STO_SEL_DATA]     = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STO_SEL_MAT]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STO_ADD_MAT]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STO_GET_MAT]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STO_UPDATE_MAT]   = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STO_DEL_MAT]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STO_SEL_SIDE]     = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STO_JUDGE]        = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STO_UPDATE_SIDE]  = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STO_DEL_SIDE]     = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STO_COPY_ORDER]   = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STO_ADD_STO_PAGE] = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STO_ADD]          = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STO_UPDATE]       = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STO_REFUSE]       = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STO_CONFIRM_PAGE] = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STO_CONFIRM]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STO_DEL]          = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STO_RECONFIRM]    = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STO_DEL_PAGE]     = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STO_SELECT_PUR]   = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STO_EXPORT_EMAIL] = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STO_SEL_DISPOSE]  = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STO_SELECT_PAGE]  = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STO_SELECT]       = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STO_FINISH]       = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STO_FINISH_HINT]  = new QNetworkAccessManager(this);

        /***************  采购退货接口  ***************/
        netWorVector[PROTOCOL::URL_RETURN_SEL]          = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_RETURN_DATA]         = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_RETURN_UPDATE]       = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_RETURN_ADD_PAGE]     = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_RETURN_ADD]          = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_RETURN_SEL_MAT]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_RETURN_ADD_MAT]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_RETURN_GET_MAT]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_RETURN_UPDATE_MAT]   = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_RETURN_DEL_MAT]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_RETURN_SEL_SIDE]     = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_RETURN_JUDGE]        = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_RETURN_UPDATE_SIDE]  = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_RETURN_DEL_SIDE]     = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_RETURN_COPY_ORDER]   = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_RETURN_CONFIRM]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_RETURN_DEL_STO]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_RETURN_SEL_DISPOSE]  = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_RETURN_DEL_MAT_SHOW] = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_RETURN_SELECT_PAGE]  = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_RETURN_SELECT]       = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_RETURN_EXTEND]       = new QNetworkAccessManager(this);

        /***************  安全库存采购接口  ***************/
        netWorVector[PROTOCOL::URL_SAFETY_SEL]    = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_SAFETY_AFFIRM] = new QNetworkAccessManager(this);

        /***************  原料供应商接口  ***************/
        netWorVector[PROTOCOL::URL_DEFAULT_SEL]        = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_DEFAULT_GET_MAT]    = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_DEFAULT_UPDATE_SUP] = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_DEFAULT_GET_SUP]    = new QNetworkAccessManager(this);

        /***************  实时库存查询接口  ***************/
        netWorVector[PROTOCOL::URL_TIME_MAT_LIST]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_TIME_SEL_MAT]       = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_TIME_SEND_EMAIL]    = new QNetworkAccessManager(this);

        /***************  库存调整接口  ***************/
        netWorVector[PROTOCOL::URL_ADJ_ADD_INV]        = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ADJ_TYPE]           = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ADJ_GET_MAT]        = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ADJ_ADD_MAT]        = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ADJ_GET_INV_LIST]   = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ADJ_GET_DET]        = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ADJ_GET_MAT_DET]    = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ADJ_UPDATE_DASIC]   = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ADJ_UPDATE_MAT]     = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ADJ_ADD_REASON]     = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ADJ_GET_REASON]     = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ADJ_DEL_REASON]     = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ADJ_DEL_MAT]        = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ADJ_SEND_EMAIL]     = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ADJ_WAREHOUSE]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ADJ_DEL]            = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ADJ_SEL_DISPOSE]    = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ADJ_PRESENT]        = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ADJ_SELECT_PAGE]    = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ADJ_SELECT]         = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ADJ_CONVERT]        = new QNetworkAccessManager(this);

        /***************  仓库盘存接口  ***************/
        netWorVector[PROTOCOL::URL_CHECK_SEL_ALL]         = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_CHECK_SEL]             = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_CHECK_ADD_PAGE]        = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_CHECK_ADD]             = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_CHECK_UPDATE]          = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_CHECK_MAT_PAGE]        = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_CHECK_ADD_MAT_PAGE]    = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_CHECK_ADD_MAT]         = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_CHECK_UPDATE_MAT_PAGE] = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_CHECK_UPDATE_MAT]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_CHECK_UNIT_UPDATE_NUM] = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_CHECK_UPDATE_NUM]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_CHECK_CANCEL]          = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_CHECK_DEL]             = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_CHECK_IMPORT]          = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_CHECK_AFFIRM]          = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_CHECK_SEND_EMAIL]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_CHECK_SEL_DISPOSE]     = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_CHECK_DEL_MAT]         = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_CHECK_SELECT_PAGE]     = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_CHECK_SELECT]          = new QNetworkAccessManager(this);


        /***************  库存变更记录接口  ***************/
        netWorVector[PROTOCOL::URL_CHANCE_SEL_MAT]        = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_CHANCE_MAT_LIST]       = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_CHANCE_ALL_MAT]        = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_CHANCE_GET_MAT]        = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_CHANCE_EXTEND]         = new QNetworkAccessManager(this);

        /***************  成本调价接口  ***************/
        netWorVector[PROTOCOL::URL_COST_SEL_ALL]          = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_COST_PRICE]            = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_COST_ADD]              = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_COST_SEL_MAT]          = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_COST_ADD_MAT]          = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_COST_SEL]              = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_COST_UPDATE]           = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_COST_DEL]              = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_COST_GET_MAT]          = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_COST_UPDATE_MAT]       = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_COST_UPDATE_PAGE]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_COST_UPDATE_ALL_MAT]   = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_COST_DEL_MAT]          = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_COST_PRESENT]          = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_COST_AFFIRM]           = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_COST_SEL_DISPOSE]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_COST_SELECT_PAGE]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_COST_SELECT]           = new QNetworkAccessManager(this);


        /***************  库存上下限接口  ***************/
        netWorVector[PROTOCOL::URL_REST_SEL_MAT]          = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_REST_GET_MAT]          = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_REST_UPDATE_MAT]       = new QNetworkAccessManager(this);

        /***************  店内调拨接口  ***************/
        netWorVector[PROTOCOL::URL_ALLOT_SEL_ALL]         = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ALLOT_ADD_PAGE]        = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ALLOT_ADD]             = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ALLOT_SEL]             = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ALLOT_UPDATE]          = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ALLOT_DEL]             = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ALLOT_SEL_MAT]         = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ALLOT_ADD_MAT]         = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ALLOT_GET_MAT]         = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ALLOT_UPDATE_MAT]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ALLOT_DEL_MAT]         = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ALLOT_UPDATE_ALL_PAGE] = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ALLOT_UPDATE_ALL_MAT]  = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ALLOT_PRESEND]         = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ALLOT_CANCEL]          = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ALLOT_AFFIRM]          = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ALLOT_RECONFIRM]       = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ALLOT_SEND_EMAIL]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ALLOT_SEL_DISPOSE]     = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ALLOT_SELECT_PAGE]     = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ALLOT_SELECT]          = new QNetworkAccessManager(this);

        /***************  报表中心接口  ***************/
        netWorVector[PROTOCOL::URL_STATE_STO_PAGE]        = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STATE_STORAGE]         = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STATE_STORAGE_EXTEND]         = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STATE_STO_GATHER_PAGE] = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STATE_STORAGE_GATHER]  = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STATE_STO_GAT_EXTEND]  = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STATE_RET_PAGE]        = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STATE_RETURNS]         = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STATE_RETURNS_EXTEND]  = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STATE_ADJ_PAGE]        = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STATE_ADJUST]          = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STATE_ADJUST_EXTEND]   = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STATE_CHECK_PAGE]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STATE_CHECK]           = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STATE_CHECK_EXTEND]    = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STATE_CHK_GATHER_PAGE] = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STATE_CHECK_GATHER]    = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STATE_CHK_GAT_EXTEND]  = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STATE_SUP_PAGE]        = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STATE_SUPPLIER]        = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STATE_SUPPLIER_EXTEND] = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STATE_SUP_GATHER_PAGE] = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STATE_SUP_GATHER]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STATE_SUP_GAT_EXTEND]  = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STATE_SELECT_MAT_PAGE] = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STATE_SELECT_MAT]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_STATE_SEL_MAT_EXTEND]  = new QNetworkAccessManager(this);

        /***************  支出结算接口  ***************/
        netWorVector[PROTOCOL::URL_ACCOUNT_ALL_NUMBER]    = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ACCOUNT_STO_PAGE]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ACCOUNT_RET_PAGE]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ACCOUNT_AFFIRM_PRO]    = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ACCOUNT_AFFIRM_ACC]    = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ACCOUNT_SEL_DISPOSE]   = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ACCOUNT_STO_MAT_INFO]  = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ACCOUNT_RET_MAT_INFO]  = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ACCOUNT_FILTRATE_PAGE] = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ACCOUNT_FILTRATE]      = new QNetworkAccessManager(this);
        netWorVector[PROTOCOL::URL_ACCOUNT_EXTEND]        = new QNetworkAccessManager(this);

        /***************  销售接口  ***************/
        netWorVector[PROTOCOL::URL_TODAY_SEL_TODAY]  = new QNetworkAccessManager(this);

        /***************  更新接口      ***************/
        netWorVector[PROTOCOL::URL_UPDATE_CLIENT]     = new QNetworkAccessManager(this);
    }

    //将HTTP响应函数存储到容器
    {
        /***************   登录接口   ***************/
        DataFunc[PROTOCOL::URL_USER_LOGIN]    = userLoginFinished;
        DataFunc[PROTOCOL::URL_LOGIN_OUT]     = outLoginFinished;
        DataFunc[PROTOCOL::URL_USER_LIST]     = userListFinished;
        DataFunc[PROTOCOL::URL_USER_ADD]      = userAddFinished;
        DataFunc[PROTOCOL::URL_USER_EDIT]     = userEditFinished;
        DataFunc[PROTOCOL::URL_USER_DEL]      = userDelFinished;

        /***************   权限接口   ***************/
        DataFunc[PROTOCOL::URL_RULE_LIST] = ruleListFinished;
        DataFunc[PROTOCOL::URL_RULE_ADD]  = ruleAddFinished;
        DataFunc[PROTOCOL::URL_RULE_EDIT] = ruleEditFinished;
        DataFunc[PROTOCOL::URL_RULE_DEL]  = ruleDelFinished;

        /***************   用户组接口   ***************/
        DataFunc[PROTOCOL::URL_GROUP_LIST] = groupListFinished;
        DataFunc[PROTOCOL::URL_GROUP_ADD]  = groupAddFinished;
        DataFunc[PROTOCOL::URL_GROUP_EDIT] = groupEditFinished;
        DataFunc[PROTOCOL::URL_GROUP_DEL]  = groupDelFinished;

        /***************   原料设置接口   ***************/
        DataFunc[PROTOCOL::URL_MAT_LIST]       = materialListFinished;
        DataFunc[PROTOCOL::URL_MAT_DETAILS]    = materialDetailsFinished;
        DataFunc[PROTOCOL::URL_MAT_IMAGE]      = matDownLoadImageFinished;
        DataFunc[PROTOCOL::URL_ADD_MAT_SHOW]   = matAddMatShowFinished;
        DataFunc[PROTOCOL::URL_MAT_ADD]        = matAddMatFinished;
        DataFunc[PROTOCOL::URL_CATE_EDIT_SHOW] = matEditTypeShowFinished;
        DataFunc[PROTOCOL::URL_MAT_EDIT]       = matEditMatFinished;
        DataFunc[PROTOCOL::URL_MAT_DEL]        = matMatDelFinished;
        DataFunc[PROTOCOL::URL_DEL_MAT]        = matDelMatFinished;
        DataFunc[PROTOCOL::URL_FINALLY_CAT]    = matFinallyCatFinished;
        DataFunc[PROTOCOL::URL_MAT_EXG_TYPE]   = matMatExgTypeFinished;
        DataFunc[PROTOCOL::URL_MAT_EMAIL]      = matExtendEmailFinished;

        /***************   分类接口   ***************/
        DataFunc[PROTOCOL::URL_MAT_CAT_LIST]  = matCatListFinished;
        DataFunc[PROTOCOL::URL_MAT_LIST_SHOW] = matCatListShowFinished;
        DataFunc[PROTOCOL::URL_CATEGORY_ADD]  = matAddTypeFinished;
        DataFunc[PROTOCOL::URL_CATEGORY_EDIT] = matEditTypeFinished;
        DataFunc[PROTOCOL::URL_CATEGORY_DEL]  = matDelTypeFinished;

        /***************   单位接口   ***************/
        DataFunc[PROTOCOL::URL_UNIT_LIST]     = matUnitListFinished;
        DataFunc[PROTOCOL::URL_ADD_UNIT]      = matUnitAddFinished;
        DataFunc[PROTOCOL::URL_DEL_UNIT]      = matUnitDelFinished;
        DataFunc[PROTOCOL::URL_SEL_SIDE]      = matUnitSelSideFinished;

        /***************   仓库接口   ***************/
        DataFunc[PROTOCOL::URL_WARHOS_LIST]       = warHosListFinish;
        DataFunc[PROTOCOL::URL_WARHOS_DETAILS]    = warHosDetailsFinish;
        DataFunc[PROTOCOL::URL_WARHOS_GOODS_TYPE] = warHosGoodsTypeFinish;
        DataFunc[PROTOCOL::URL_WARHOS_GOODS_LIST] = warHosGoodsListFinish;
        DataFunc[PROTOCOL::URL_WARHOS_ADD]        = warHosAddFinish;
        DataFunc[PROTOCOL::URL_WARHOS_EDIT]       = warHosEditFinish;
        DataFunc[PROTOCOL::URL_WARHOS_DEL]        = warHosDelFinish;
        DataFunc[PROTOCOL::URL_WARHOS_SEARCH]     = warHosSearchFinish;

        /***************   供应商接口   ***************/
        DataFunc[PROTOCOL::URL_SUP_ADD_SUP]        = supAddFinish;
        DataFunc[PROTOCOL::URL_SUP_ADD_SUP_MAT]    = supAddMatFinish;
        DataFunc[PROTOCOL::URL_SUP_ADD_SUP_CAT]    = supAddCatFinish;
        DataFunc[PROTOCOL::URL_SUP_GET_SUP_CAT]    = supGetCatFinish;
        DataFunc[PROTOCOL::URL_SUP_UPDATE_SUP_CAT] = supUpdateCatFinish;
        DataFunc[PROTOCOL::URL_SUP_DEL_SUP_CAT]    = supDelCatFinish;
        DataFunc[PROTOCOL::URL_SUP_GET_SUP_LIST]   = supGetListFinish;
        DataFunc[PROTOCOL::URL_SUP_DETAILS]        = supDetailsFinish;
        DataFunc[PROTOCOL::URL_SUP_UPDATE_SUP]     = supUpdateFinish;
        DataFunc[PROTOCOL::URL_SUP_DEL_SUP_MAT]    = supDelMatFinish;
        DataFunc[PROTOCOL::URL_SUP_DEL_SUP]        = supDelFinish;
        DataFunc[PROTOCOL::URL_SUP_SEL_MATERIAL]   = supSelMatFinish;
        DataFunc[PROTOCOL::URL_SUP_GET_MATERIAL]   = supGetMatFinish;
        DataFunc[PROTOCOL::URL_SUP_EXTEND]         = supExtendFinish;

        /***************   模板接口   ***************/
        DataFunc[PROTOCOL::URL_TEM_MAT_LIST]      = temMatListFinish;
        DataFunc[PROTOCOL::URL_TEM_ADD_TEM]       = temAddFinish;
        DataFunc[PROTOCOL::URL_TEM_ADD_MAT]       = temAddMatFinish;
        DataFunc[PROTOCOL::URL_TEM_LIST]          = temListFinish;
        DataFunc[PROTOCOL::URL_TEM_DETAILS]       = temDetailsFinish;
        DataFunc[PROTOCOL::URL_TEM_UPDATE]        = temUpdateFinish;
        DataFunc[PROTOCOL::URL_TEM_DEL_MAT]       = temDelMatFinish;
        DataFunc[PROTOCOL::URL_TEM_DELETE]        = temDeleteFinish;
        DataFunc[PROTOCOL::URL_TEM_GET_MAT_LIST]  = temGetMatListFinish;
        DataFunc[PROTOCOL::URL_TEM_MAT_TYPE_LIST] = temMatTypeListFinish;

        /***************  菜品原料配比接口  ***************/
        DataFunc[PROTOCOL::URL_BOM_FOOD_LIST]   = bomFoodListFinish;
        DataFunc[PROTOCOL::URL_BOM_FOOD_GETID]  = bomFoodGetIdFinish;
        DataFunc[PROTOCOL::URL_BOM_MAT_OLD]     = bomMatOldFinish;
        DataFunc[PROTOCOL::URL_BOM_MAT_DEL]     = bomMatDelFinish;
        DataFunc[PROTOCOL::URL_BOM_MAT_UPDATE]  = bomMatUpdateFinish;
        DataFunc[PROTOCOL::URL_BOM_MAT_ADD]     = bomMatAddFinish;
        DataFunc[PROTOCOL::URL_BOM_MAT_NEW]     = bomMatNewFinish;
        DataFunc[PROTOCOL::URL_BOM_SAVE_UPDATE] = bomSaveUpdateFinish;
        DataFunc[PROTOCOL::URL_BOM_MAT_LIST]    = bomMatListFinish;

        /***************  采购订单接口  ***************/
        DataFunc[PROTOCOL::URL_PUR_SEL_ALL]      = purSelAllFinish;
        DataFunc[PROTOCOL::URL_PUR_INDENT]       = purIndentFinish;
        DataFunc[PROTOCOL::URL_PUR_ADD_INDENT]   = purAddIndentFinish;
        DataFunc[PROTOCOL::URL_PUR_SEL]          = purSelFinish;
        DataFunc[PROTOCOL::URL_PUR_GET_MAT]      = purGetMatFinish;
        DataFunc[PROTOCOL::URL_PUR_UPDATE]       = purUpdateFinish;
        DataFunc[PROTOCOL::URL_PUR_ADD_MAT]      = purAddMatFinish;
        DataFunc[PROTOCOL::URL_PUR_DEL_MAT]      = purDelMatFinish;
        DataFunc[PROTOCOL::URL_PUR_SEL_MAT]      = purSelMatFinish;
        DataFunc[PROTOCOL::URL_PUR_UPDATE_MAT]   = purUpdateMatFinish;
        DataFunc[PROTOCOL::URL_PUR_EXAMINE]      = purExamineFinish;
        DataFunc[PROTOCOL::URL_PUR_AFFIRMPAGE]   = purAffirmPageFinish;
        DataFunc[PROTOCOL::URL_PUR_AFFIRM]       = purAffirmFinish;
        DataFunc[PROTOCOL::URL_PUR_COPY]         = purCopyFinish;
        DataFunc[PROTOCOL::URL_PUR_DEL]          = purDelFinish;
        DataFunc[PROTOCOL::URL_PUR_SEL_TEMPLATE] = purSelTemplateFinish;
        DataFunc[PROTOCOL::URL_PUR_NUMBER]       = purNumberFinish;
        DataFunc[PROTOCOL::URL_PUR_TEMPLATE_ADD] = purTemplateAddFinish;
        DataFunc[PROTOCOL::URL_PUR_SEL_DISPOSE]  = purSelDisposeFinish;
        DataFunc[PROTOCOL::URL_PUR_SELECT_PAGE]  = purSelectPageFinish;
        DataFunc[PROTOCOL::URL_PUR_SELECT]       = purSelectFinish;
        DataFunc[PROTOCOL::URL_PUR_EXTEND]       = purExtendFinish;

        /***************  采购入库接口  ***************/
        DataFunc[PROTOCOL::URL_STO_SEL]          = stoSelFinish;
        DataFunc[PROTOCOL::URL_STO_GET_ID]       = stoGetIdFinish;
        DataFunc[PROTOCOL::URL_STO_SEL_DATA]     = stoSelDataFinish;
        DataFunc[PROTOCOL::URL_STO_SEL_MAT]      = stoSelMatFinish;
        DataFunc[PROTOCOL::URL_STO_ADD_MAT]      = stoAddMatFinish;
        DataFunc[PROTOCOL::URL_STO_GET_MAT]      = stoGetMatFinish;
        DataFunc[PROTOCOL::URL_STO_UPDATE_MAT]   = stoUpdateMatFinish;
        DataFunc[PROTOCOL::URL_STO_DEL_MAT]      = stoDelMatFinish;
        DataFunc[PROTOCOL::URL_STO_SEL_SIDE]     = stoSelSideFinish;
        DataFunc[PROTOCOL::URL_STO_JUDGE]        = stoJudgeFinish;
        DataFunc[PROTOCOL::URL_STO_UPDATE_SIDE]  = stoUpdateSideFinish;
        DataFunc[PROTOCOL::URL_STO_DEL_SIDE]     = stoDelSideFinish;
        DataFunc[PROTOCOL::URL_STO_COPY_ORDER]   = stoCopyOrderFinish;
        DataFunc[PROTOCOL::URL_STO_ADD_STO_PAGE] = stoAddStoPageFinish;
        DataFunc[PROTOCOL::URL_STO_ADD]          = stoAddFinish;
        DataFunc[PROTOCOL::URL_STO_UPDATE]       = stoUpdateFinish;
        DataFunc[PROTOCOL::URL_STO_REFUSE]       = stoRefuseFinish;
        DataFunc[PROTOCOL::URL_STO_CONFIRM_PAGE] = stoConfirmPageFinish;
        DataFunc[PROTOCOL::URL_STO_CONFIRM]      = stoConfirmFinish;
        DataFunc[PROTOCOL::URL_STO_DEL]          = stoDelFinish;
        DataFunc[PROTOCOL::URL_STO_RECONFIRM]    = stoReConfirmFinish;
        DataFunc[PROTOCOL::URL_STO_DEL_PAGE]     = stoDelPageFinish;
        DataFunc[PROTOCOL::URL_STO_SELECT_PUR]   = stoSelectPurFinish;
        DataFunc[PROTOCOL::URL_STO_EXPORT_EMAIL] = stoExpendEmailFinish;
        DataFunc[PROTOCOL::URL_STO_SEL_DISPOSE]  = stoSelDisposeFinish;
        DataFunc[PROTOCOL::URL_STO_SELECT_PAGE]  = stoSelectPageFinish;
        DataFunc[PROTOCOL::URL_STO_SELECT]       = stoSelectFinish;
        DataFunc[PROTOCOL::URL_STO_FINISH]       = stoStorageFinish;
        DataFunc[PROTOCOL::URL_STO_FINISH_HINT]  = stoStorageHintFinish;

        /***************  采购退货接口  ***************/
        DataFunc[PROTOCOL::URL_RETURN_SEL]          = retSelFinish;
        DataFunc[PROTOCOL::URL_RETURN_DATA]         = retDataFinish;
        DataFunc[PROTOCOL::URL_RETURN_UPDATE]       = retUpdateFinish;
        DataFunc[PROTOCOL::URL_RETURN_ADD_PAGE]     = retAddPageFinish;
        DataFunc[PROTOCOL::URL_RETURN_ADD]          = retAddFinish;
        DataFunc[PROTOCOL::URL_RETURN_SEL_MAT]      = retSelMatFinish;
        DataFunc[PROTOCOL::URL_RETURN_ADD_MAT]      = retAddMatFinish;
        DataFunc[PROTOCOL::URL_RETURN_GET_MAT]      = retGatMatFinish;
        DataFunc[PROTOCOL::URL_RETURN_UPDATE_MAT]   = retUpdateMatFinish;
        DataFunc[PROTOCOL::URL_RETURN_DEL_MAT]      = retDelMatFinish;
        DataFunc[PROTOCOL::URL_RETURN_SEL_SIDE]     = retSelSideFinish;
        DataFunc[PROTOCOL::URL_RETURN_JUDGE]        = retJudgeFinish;
        DataFunc[PROTOCOL::URL_RETURN_UPDATE_SIDE]  = retUpdateSideFinish;
        DataFunc[PROTOCOL::URL_RETURN_DEL_SIDE]     = retDelSideFinish;
        DataFunc[PROTOCOL::URL_RETURN_COPY_ORDER]   = retCopyOrderFinish;
        DataFunc[PROTOCOL::URL_RETURN_CONFIRM]      = retConfirmFinish;
        DataFunc[PROTOCOL::URL_RETURN_DEL_STO]      = retDelStoFinish;
        DataFunc[PROTOCOL::URL_RETURN_SEL_DISPOSE]  = retSelDisposeFinish;
        DataFunc[PROTOCOL::URL_RETURN_DEL_MAT_SHOW] = retDelMatShowFinish;
        DataFunc[PROTOCOL::URL_RETURN_SELECT_PAGE]  = retSelectPageFinish;
        DataFunc[PROTOCOL::URL_RETURN_SELECT]       = retSelectFinish;
        DataFunc[PROTOCOL::URL_RETURN_EXTEND]       = retExtendFinish;

        /***************  安全库存采购接口  ***************/
        DataFunc[PROTOCOL::URL_SAFETY_SEL]    = safSelMatShowFinish;
        DataFunc[PROTOCOL::URL_SAFETY_AFFIRM] = safAffirmFinish;

        /***************  原料供应商接口  ***************/
        DataFunc[PROTOCOL::URL_DEFAULT_SEL]        = defaultSelMatFinish;
        DataFunc[PROTOCOL::URL_DEFAULT_GET_MAT]    = defaultGetMatFinish;
        DataFunc[PROTOCOL::URL_DEFAULT_UPDATE_SUP] = defaultUpdateSupFinish;
        DataFunc[PROTOCOL::URL_DEFAULT_GET_SUP]    = defaultGetSupFinish;

        /***************  原料供应商接口  ***************/
        DataFunc[PROTOCOL::URL_TIME_MAT_LIST]      = timeMatListFinish;
        DataFunc[PROTOCOL::URL_TIME_SEL_MAT]       = timeSelMatFinish;
        DataFunc[PROTOCOL::URL_TIME_SEND_EMAIL]    = timeSendEmailFinish;

        /***************  库存调整接口  ***************/
        DataFunc[PROTOCOL::URL_ADJ_ADD_INV]        = adjAddInvFinish;
        DataFunc[PROTOCOL::URL_ADJ_TYPE]           = adjTypeFinish;
        DataFunc[PROTOCOL::URL_ADJ_GET_MAT]        = adjGetMatFinish;
        DataFunc[PROTOCOL::URL_ADJ_ADD_MAT]        = adjAddMatFinish;
        DataFunc[PROTOCOL::URL_ADJ_GET_INV_LIST]   = adjGetInvListFinish;
        DataFunc[PROTOCOL::URL_ADJ_GET_DET]        = adjGetDetFinish;
        DataFunc[PROTOCOL::URL_ADJ_GET_MAT_DET]    = adjGetMatDetFinish;
        DataFunc[PROTOCOL::URL_ADJ_UPDATE_DASIC]   = adjUpdateDasicFinish;
        DataFunc[PROTOCOL::URL_ADJ_UPDATE_MAT]     = adjUpdateMatFinish;
        DataFunc[PROTOCOL::URL_ADJ_ADD_REASON]     = adjAddReasonFinish;
        DataFunc[PROTOCOL::URL_ADJ_GET_REASON]     = adjGetReasonFinish;
        DataFunc[PROTOCOL::URL_ADJ_DEL_REASON]     = adjDelReasonFinish;
        DataFunc[PROTOCOL::URL_ADJ_DEL_MAT]        = adjDelMatFinish;
        DataFunc[PROTOCOL::URL_ADJ_SEND_EMAIL]     = adjSendEmailFinish;
        DataFunc[PROTOCOL::URL_ADJ_WAREHOUSE]      = adjWareHouseFinish;
        DataFunc[PROTOCOL::URL_ADJ_DEL]            = adjDelInvFinish;
        DataFunc[PROTOCOL::URL_ADJ_SEL_DISPOSE]    = adjSelectLogFinish;
        DataFunc[PROTOCOL::URL_ADJ_PRESENT]        = adjPresendFinish;
        DataFunc[PROTOCOL::URL_ADJ_SELECT_PAGE]    = adjSelectPageFinish;
        DataFunc[PROTOCOL::URL_ADJ_SELECT]         = adjSelectFinish;
        DataFunc[PROTOCOL::URL_ADJ_CONVERT]        = adjConvertFinish;

        /***************  仓库盘存接口  ***************/
        DataFunc[PROTOCOL::URL_CHECK_SEL_ALL]         = checkSelAllFinish;
        DataFunc[PROTOCOL::URL_CHECK_SEL]             = checkSelFinish;
        DataFunc[PROTOCOL::URL_CHECK_ADD_PAGE]        = checkAddPageFinish;
        DataFunc[PROTOCOL::URL_CHECK_ADD]             = checkAddFinish;
        DataFunc[PROTOCOL::URL_CHECK_UPDATE]          = checkUpdateFinish;
        DataFunc[PROTOCOL::URL_CHECK_MAT_PAGE]        = checkMatPageFinish;
        DataFunc[PROTOCOL::URL_CHECK_ADD_MAT_PAGE]    = checkAddMatPageFinish;
        DataFunc[PROTOCOL::URL_CHECK_ADD_MAT]         = checkAddMatFinish;
        DataFunc[PROTOCOL::URL_CHECK_UPDATE_MAT_PAGE] = checkUpdateMatPageFinish;
        DataFunc[PROTOCOL::URL_CHECK_UPDATE_MAT]      = checkUpdateMatFinish;
        DataFunc[PROTOCOL::URL_CHECK_UNIT_UPDATE_NUM] = checkUnitUpdateNumFinish;
        DataFunc[PROTOCOL::URL_CHECK_UPDATE_NUM]      = checkUpdateNumFinish;
        DataFunc[PROTOCOL::URL_CHECK_CANCEL]          = checkCancelFinish;
        DataFunc[PROTOCOL::URL_CHECK_DEL]             = checkDelFinish;
        DataFunc[PROTOCOL::URL_CHECK_IMPORT]          = checkImportFinish;
        DataFunc[PROTOCOL::URL_CHECK_AFFIRM]          = checkAffirmFinish;
        DataFunc[PROTOCOL::URL_CHECK_SEND_EMAIL]      = checkSendEmailFinish;
        DataFunc[PROTOCOL::URL_CHECK_SEL_DISPOSE]     = checkSelDisposeFinish;
        DataFunc[PROTOCOL::URL_CHECK_DEL_MAT]         = checkDelMatFinish;
        DataFunc[PROTOCOL::URL_CHECK_SELECT_PAGE]     = checkSelectPageFinish;
        DataFunc[PROTOCOL::URL_CHECK_SELECT]          = checkSelectFinish;


        /***************  库存变更记录接口  ***************/
        DataFunc[PROTOCOL::URL_CHANCE_SEL_MAT]        = changeSelMatFinish;
        DataFunc[PROTOCOL::URL_CHANCE_MAT_LIST]       = changeMatListFinish;
        DataFunc[PROTOCOL::URL_CHANCE_ALL_MAT]        = changeAllMatFinish;
        DataFunc[PROTOCOL::URL_CHANCE_GET_MAT]        = changeGetMatFinish;
        DataFunc[PROTOCOL::URL_CHANCE_EXTEND]         = changeExtendFinish;

        /***************  成本调价接口  ***************/
        DataFunc[PROTOCOL::URL_COST_SEL_ALL]          = costSelAllFinish;
        DataFunc[PROTOCOL::URL_COST_PRICE]            = costPriceFinish;
        DataFunc[PROTOCOL::URL_COST_ADD]              = costAddFinish;
        DataFunc[PROTOCOL::URL_COST_SEL_MAT]          = costSelMatFinish;
        DataFunc[PROTOCOL::URL_COST_ADD_MAT]          = costAddMatFinish;
        DataFunc[PROTOCOL::URL_COST_SEL]              = costSelFinish;
        DataFunc[PROTOCOL::URL_COST_UPDATE]           = costUpdateFinish;
        DataFunc[PROTOCOL::URL_COST_DEL]              = costDelFinish;
        DataFunc[PROTOCOL::URL_COST_GET_MAT]          = costGetMatFinish;
        DataFunc[PROTOCOL::URL_COST_UPDATE_MAT]       = costUpdateMatFinish;
        DataFunc[PROTOCOL::URL_COST_UPDATE_PAGE]      = costUpdatePageFinish;
        DataFunc[PROTOCOL::URL_COST_UPDATE_ALL_MAT]   = costUpdateAllMatFinish;
        DataFunc[PROTOCOL::URL_COST_DEL_MAT]          = costDelMatFinish;
        DataFunc[PROTOCOL::URL_COST_PRESENT]          = costPresentFinish;
        DataFunc[PROTOCOL::URL_COST_AFFIRM]           = costAffirmFinish;
        DataFunc[PROTOCOL::URL_COST_SEL_DISPOSE]      = costSelDisposeFinish;
        DataFunc[PROTOCOL::URL_COST_SELECT_PAGE]      = costSelectPageFinish;
        DataFunc[PROTOCOL::URL_COST_SELECT]           = costSelectFinish;

        /***************  库存上下限接口  ***************/
        DataFunc[PROTOCOL::URL_REST_SEL_MAT]          = restSelMatFinish;
        DataFunc[PROTOCOL::URL_REST_GET_MAT]          = restGetMatFinish;
        DataFunc[PROTOCOL::URL_REST_UPDATE_MAT]       = restUpdateMatFinish;

        /***************  店内调拨接口  ***************/
        DataFunc[PROTOCOL::URL_ALLOT_SEL_ALL]         = allotSelAllFinish;
        DataFunc[PROTOCOL::URL_ALLOT_ADD_PAGE]        = allotAddPageFinish;
        DataFunc[PROTOCOL::URL_ALLOT_ADD]             = allotAddFinish;
        DataFunc[PROTOCOL::URL_ALLOT_SEL]             = allotSelFinish;
        DataFunc[PROTOCOL::URL_ALLOT_UPDATE]          = allotUpdateFinish;
        DataFunc[PROTOCOL::URL_ALLOT_DEL]             = allotDelFinish;
        DataFunc[PROTOCOL::URL_ALLOT_SEL_MAT]         = allotSelMatFinish;
        DataFunc[PROTOCOL::URL_ALLOT_ADD_MAT]         = allotAddMatFinish;
        DataFunc[PROTOCOL::URL_ALLOT_GET_MAT]         = allotGetMatFinish;
        DataFunc[PROTOCOL::URL_ALLOT_UPDATE_MAT]      = allotUpdateMatFinish;
        DataFunc[PROTOCOL::URL_ALLOT_DEL_MAT]         = allotDelMatFinish;
        DataFunc[PROTOCOL::URL_ALLOT_UPDATE_ALL_PAGE] = allotUpdateAllPageFinish;
        DataFunc[PROTOCOL::URL_ALLOT_UPDATE_ALL_MAT]  = allotUpdateAllMatFinish;
        DataFunc[PROTOCOL::URL_ALLOT_PRESEND]         = allotPresendFinish;
        DataFunc[PROTOCOL::URL_ALLOT_CANCEL]          = allotCancelFinish;
        DataFunc[PROTOCOL::URL_ALLOT_AFFIRM]          = allotAffirmFinish;
        DataFunc[PROTOCOL::URL_ALLOT_RECONFIRM]       = allotReconfirmFinish;
        DataFunc[PROTOCOL::URL_ALLOT_SEND_EMAIL]      = allotSendEmailFinish;
        DataFunc[PROTOCOL::URL_ALLOT_SEL_DISPOSE]     = allotSelDisposeFinish;
        DataFunc[PROTOCOL::URL_ALLOT_SELECT_PAGE]     = allotSelectPageFinish;
        DataFunc[PROTOCOL::URL_ALLOT_SELECT]          = allotSelectFinish;

        /***************  报表中心接口  ***************/
        DataFunc[PROTOCOL::URL_STATE_STO_PAGE]        = stateStoPageFinish;
        DataFunc[PROTOCOL::URL_STATE_STORAGE]         = stateStorageFinish;
        DataFunc[PROTOCOL::URL_STATE_STORAGE_EXTEND]  = stateStorageExtendFinish;
        DataFunc[PROTOCOL::URL_STATE_STO_GATHER_PAGE] = stateStoGatherPageFinish;
        DataFunc[PROTOCOL::URL_STATE_STORAGE_GATHER]  = stateStoGatherFinish;
        DataFunc[PROTOCOL::URL_STATE_STO_GAT_EXTEND]  = stateStoGatherExtendFinish;
        DataFunc[PROTOCOL::URL_STATE_RET_PAGE]        = stateRetPageFinish;
        DataFunc[PROTOCOL::URL_STATE_RETURNS]         = stateReturnsFinish;
        DataFunc[PROTOCOL::URL_STATE_RETURNS_EXTEND]  = stateReturnsExtendFinish;
        DataFunc[PROTOCOL::URL_STATE_ADJ_PAGE]        = stateAdjPageFinish;
        DataFunc[PROTOCOL::URL_STATE_ADJUST]          = stateAdjustFinish;
        DataFunc[PROTOCOL::URL_STATE_ADJUST_EXTEND]   = stateAdjustExtendFinish;
        DataFunc[PROTOCOL::URL_STATE_CHECK_PAGE]      = stateCheckPageFinish;
        DataFunc[PROTOCOL::URL_STATE_CHECK]           = stateCheckFinish;
        DataFunc[PROTOCOL::URL_STATE_CHECK_EXTEND]    = stateCheckExtendFinish;
        DataFunc[PROTOCOL::URL_STATE_CHK_GATHER_PAGE] = stateCheckGatherPageFinish;
        DataFunc[PROTOCOL::URL_STATE_CHECK_GATHER]    = stateCheckGatherFinish;
        DataFunc[PROTOCOL::URL_STATE_CHK_GAT_EXTEND]  = stateCheckGatherExtendFinish;
        DataFunc[PROTOCOL::URL_STATE_SUP_PAGE]        = stateSupPageFinish;
        DataFunc[PROTOCOL::URL_STATE_SUPPLIER]        = stateSupplierFinish;
        DataFunc[PROTOCOL::URL_STATE_SUPPLIER_EXTEND] = stateSupplierExtendFinish;
        DataFunc[PROTOCOL::URL_STATE_SUP_GATHER_PAGE] = stateSupGatherPageFinish;
        DataFunc[PROTOCOL::URL_STATE_SUP_GATHER]      = stateSupGatherFinish;
        DataFunc[PROTOCOL::URL_STATE_SUP_GAT_EXTEND]  = stateSupGatherExtendFinish;
        DataFunc[PROTOCOL::URL_STATE_SELECT_MAT_PAGE] = stateSelectMatPageFinish;
        DataFunc[PROTOCOL::URL_STATE_SELECT_MAT]      = stateSelectMatFinish;
        DataFunc[PROTOCOL::URL_STATE_SEL_MAT_EXTEND]  = stateSelMatExtendFinish;

        /***************  支出结算接口  ***************/
        DataFunc[PROTOCOL::URL_ACCOUNT_ALL_NUMBER]    = accountAllFinish;
        DataFunc[PROTOCOL::URL_ACCOUNT_STO_PAGE]      = accountStoUpdateFinish;
        DataFunc[PROTOCOL::URL_ACCOUNT_RET_PAGE]      = accountRetUpdateFinish;
        DataFunc[PROTOCOL::URL_ACCOUNT_AFFIRM_PRO]    = accountAffirmProFinish;
        DataFunc[PROTOCOL::URL_ACCOUNT_AFFIRM_ACC]    = accountAffirmAccFinish;
        DataFunc[PROTOCOL::URL_ACCOUNT_SEL_DISPOSE]   = accountSelDisposeFinish;
        DataFunc[PROTOCOL::URL_ACCOUNT_STO_MAT_INFO]  = accountSelStoMatFinish;
        DataFunc[PROTOCOL::URL_ACCOUNT_RET_MAT_INFO]  = accountSelRetMatFinish;
        DataFunc[PROTOCOL::URL_ACCOUNT_FILTRATE_PAGE] = accountFiltratePageFinish;
        DataFunc[PROTOCOL::URL_ACCOUNT_FILTRATE]      = accountFiltrateFinish;
        DataFunc[PROTOCOL::URL_ACCOUNT_EXTEND]        = accountSendEmailFinish;

        /***************  销售接口  ***************/
        DataFunc[PROTOCOL::URL_TODAY_SEL_TODAY]       = todaySelTodayFinish;

        /***************  更新接口      ***************/
        DataFunc[PROTOCOL::URL_UPDATE_CLIENT]         = updateClientFinish;
    }

    for(int i = 0; i < PROTOCOL::URLMAX; i ++)
    {
        if(NULL != netWorVector[i] &&  NULL != DataFunc[i])
        {
            QObject::connect(netWorVector.at(i), &QNetworkAccessManager::finished, this, DataFunc[i]);
        }
    }
}

/*********************     单例模式                 *******************/
HttpClient *HttpClient::getInstance()
{
    return instance;
}

/*********************     get请求                 *******************/
void HttpClient::getUrlReq(const QString &urlStr, int type)
{
    QNetworkRequest request;

    request.setUrl(QUrl(urlStr));

    if(urlStr.contains('%')) request.setUrl(QUrl(urlStr.arg(publicToken, publicUsrId)));

    qDebug()<<urlStr.arg(publicToken, publicUsrId);

    netWorVector.at(type)->get(request);
}

/*********************     post请求                *******************/
void HttpClient::postUrlReq(QString urlStr, QByteArray &data, int type)
{
    QNetworkRequest request;

    request.setUrl(QUrl(urlStr));

    if(urlStr.contains('%')) request.setUrl(QUrl(urlStr.arg(publicToken, publicUsrId)));

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded;charset=utf-8;");

    netWorVector.at(type)->post(request, data);
}

/*********************     管理员登录               *******************/
void HttpClient::userLoginFinished(QNetworkReply *reply)
{
    readJson(reply);
    LOGINDIALOG->userLoginInfo(this->mapHttpData);
}

/*********************     退出登录                *******************/
void HttpClient::outLoginFinished(QNetworkReply *reply)
{
    this->readJson(reply);
    MAINWINDOW->exitExe(this->mapHttpData);
}

/*********************     管理员列表              *******************/
void HttpClient::userListFinished(QNetworkReply *reply)
{
    ADMINISTERMANAGE.readJson(reply, PROTOCOL::URL_USER_LIST);
}

/*********************     新增管理员              *******************/
void HttpClient::userAddFinished(QNetworkReply *reply)
{
    ADMINISTERMANAGE.readJson(reply, PROTOCOL::URL_USER_ADD);
}

/*********************     修改管理员              *******************/
void HttpClient::userEditFinished(QNetworkReply *reply)
{
    ADMINISTERMANAGE.readJson(reply, PROTOCOL::URL_USER_EDIT);
}

/*********************     删除管理员              *******************/
void HttpClient::userDelFinished(QNetworkReply *reply)
{
    ADMINISTERMANAGE.readJson(reply, PROTOCOL::URL_USER_DEL);
}

/*********************     权限列表                *******************/
void HttpClient::ruleListFinished(QNetworkReply *reply)
{
    this->readJson(reply);
}

/*********************     添加权限                *******************/
void HttpClient::ruleAddFinished(QNetworkReply *reply)
{
    this->readJson(reply);
}

/*********************     修改权限                *******************/
void HttpClient::ruleEditFinished(QNetworkReply *reply)
{
    this->readJson(reply);
}

/*********************     删除权限                *******************/
void HttpClient::ruleDelFinished(QNetworkReply *reply)
{
    this->readJson(reply);
}

/*********************     用户组列表               *******************/
void HttpClient::groupListFinished(QNetworkReply *reply)
{
    this->readJson(reply);
}

/*********************     添加用户组               *******************/
void HttpClient::groupAddFinished(QNetworkReply *reply)
{
    this->readJson(reply);
}

/*********************     修改用户组               *******************/
void HttpClient::groupEditFinished(QNetworkReply *reply)
{
    this->readJson(reply);
}

/*********************     删除用户组               *******************/
void HttpClient::groupDelFinished(QNetworkReply *reply)
{
    this->readJson(reply);
}

/*********************     原料列表                 *******************/
void HttpClient::materialListFinished(QNetworkReply *reply)
{
    MATERIALWIDGET.readJson(reply, PROTOCOL::URL_MAT_LIST);
}

/*********************     原料详情                 *******************/
void HttpClient::materialDetailsFinished(QNetworkReply *reply)
{
    MATERIALWIDGET.readJson(reply, PROTOCOL::URL_MAT_DETAILS);
}

/*********************     下载图片                 *******************/
void HttpClient::matDownLoadImageFinished(QNetworkReply *reply)
{
    MATERIALWIDGET.downLoadImage(reply);
}

/*********************     添加原料前显示            *******************/
void HttpClient::matAddMatShowFinished(QNetworkReply *reply)
{
    MATERIALWIDGET.readJson(reply, PROTOCOL::URL_ADD_MAT_SHOW);
}

/*********************     添加原料                 *******************/
void HttpClient::matAddMatFinished(QNetworkReply *reply)
{
    MATERIALWIDGET.readJson(reply, PROTOCOL::URL_MAT_ADD);
}

/*********************     修改原料                 *******************/
void HttpClient::matEditMatFinished(QNetworkReply *reply)
{
    MATERIALWIDGET.readJson(reply, PROTOCOL::URL_MAT_EDIT);
}

/*********************     删除前提示               *******************/
void HttpClient::matMatDelFinished(QNetworkReply *reply)
{
    MATERIALWIDGET.readJson(reply, PROTOCOL::URL_MAT_DEL);
}

/*********************     删除原料                 *******************/
void HttpClient::matDelMatFinished(QNetworkReply *reply)
{
    MATERIALWIDGET.readJson(reply, PROTOCOL::URL_DEL_MAT);
}

/*********************     最后一级分类             *******************/
void HttpClient::matFinallyCatFinished(QNetworkReply *reply)
{
    MATERIALWIDGET.readJson(reply, PROTOCOL::URL_FINALLY_CAT);
}

/*********************     批量修改分类             *******************/
void HttpClient::matMatExgTypeFinished(QNetworkReply *reply)
{
    MATERIALWIDGET.readJson(reply, PROTOCOL::URL_MAT_EXG_TYPE);
}

/*********************     导出到邮箱                 *******************/
void HttpClient::matExtendEmailFinished(QNetworkReply *reply)
{
    MATERIALWIDGET.readJson(reply, PROTOCOL::URL_MAT_EMAIL);
}

/*********************     查询分类                 *******************/
void HttpClient::matCatListFinished(QNetworkReply *reply)
{
    MATERIALWIDGET.readJson(reply, PROTOCOL::URL_MAT_CAT_LIST);
}

/*********************     查询分类显示页                 *******************/
void HttpClient::matCatListShowFinished(QNetworkReply *reply)
{
    MATERIALWIDGET.readJson(reply, PROTOCOL::URL_MAT_LIST_SHOW);
}

/*********************     添加原料类型                 *******************/
void HttpClient::matAddTypeFinished(QNetworkReply *reply)
{
    MATERIALWIDGET.readJson(reply, PROTOCOL::URL_CATEGORY_ADD);
}

/*********************     编辑原料显示                 *******************/
void HttpClient::matEditTypeShowFinished(QNetworkReply *reply)
{
    MATERIALWIDGET.readJson(reply, PROTOCOL::URL_CATE_EDIT_SHOW);
}

/*********************     编辑原料类型                 *******************/
void HttpClient::matEditTypeFinished(QNetworkReply *reply)
{
    MATERIALWIDGET.readJson(reply, PROTOCOL::URL_CATEGORY_EDIT);
}

/*********************     删除原料类型                 *******************/
void HttpClient::matDelTypeFinished(QNetworkReply *reply)
{
    MATERIALWIDGET.readJson(reply, PROTOCOL::URL_CATEGORY_DEL);
}

/*********************     获取单位接口                 *******************/
void HttpClient::matUnitListFinished(QNetworkReply *reply)
{
    MATERIALWIDGET.readJson(reply, PROTOCOL::URL_UNIT_LIST);
}

/*********************     添加单位接口                 *******************/
void HttpClient::matUnitAddFinished(QNetworkReply *reply)
{
    MATERIALWIDGET.readJson(reply,  PROTOCOL::URL_ADD_UNIT);
}

/*********************     删除单位接口                 *******************/
void HttpClient::matUnitDelFinished(QNetworkReply *reply)
{
    MATERIALWIDGET.readJson(reply,  PROTOCOL::URL_DEL_UNIT);
}

/*********************     副单位显示页                 *******************/
void HttpClient::matUnitSelSideFinished(QNetworkReply *reply)
{
    MATERIALWIDGET.readJson(reply,  PROTOCOL::URL_SEL_SIDE);
}

/*********************     获取仓库列表                 *******************/
void HttpClient::warHosListFinish(QNetworkReply *reply)
{
    WARHSEWIDGET.readJson(reply, PROTOCOL::URL_WARHOS_LIST);
}

/*********************     仓库详情                 *******************/
void HttpClient::warHosDetailsFinish(QNetworkReply *reply)
{
    WARHSEWIDGET.readJson(reply, PROTOCOL::URL_WARHOS_DETAILS);
}

/*********************     获取分类                 *******************/
void HttpClient::warHosGoodsTypeFinish(QNetworkReply *reply)
{
    WARHSEWIDGET.readJson(reply, PROTOCOL::URL_WARHOS_GOODS_TYPE);
}

/*********************     获取商品列表                 *******************/
void HttpClient::warHosGoodsListFinish(QNetworkReply *reply)
{
    WARHSEWIDGET.readJson(reply, PROTOCOL::URL_WARHOS_GOODS_LIST);
}

/*********************     添加仓库                 *******************/
void HttpClient::warHosAddFinish(QNetworkReply *reply)
{
    WARHSEWIDGET.readJson(reply, PROTOCOL::URL_WARHOS_ADD);
}

/*********************     修改仓库                 *******************/
void HttpClient::warHosEditFinish(QNetworkReply *reply)
{
    WARHSEWIDGET.readJson(reply, PROTOCOL::URL_WARHOS_EDIT);
}

/*********************     删除仓库                 *******************/
void HttpClient::warHosDelFinish(QNetworkReply *reply)
{
    WARHSEWIDGET.readJson(reply, PROTOCOL::URL_WARHOS_DEL);
}

/*********************     商品搜索框                 *******************/
void HttpClient::warHosSearchFinish(QNetworkReply *reply)
{
    WARHSEWIDGET.readJson(reply, PROTOCOL::URL_WARHOS_SEARCH);
}

/*********************     添加供应商                 *******************/
void HttpClient::supAddFinish(QNetworkReply *reply)
{
    SUPWIDGET.readJson(reply, PROTOCOL::URL_SUP_ADD_SUP);
}

/*********************     保存供应商原料接口           ******************/
void HttpClient::supAddMatFinish(QNetworkReply *reply)
{
    SUPWIDGET.readJson(reply, PROTOCOL::URL_SUP_ADD_SUP_MAT);
}

/*********************     供应商添加类别               *******************/
void HttpClient::supAddCatFinish(QNetworkReply *reply)
{
    SUPWIDGET.readJson(reply, PROTOCOL::URL_SUP_ADD_SUP_CAT);
}

/*********************     获取所有类别                 *******************/
void HttpClient::supGetCatFinish(QNetworkReply *reply)
{
    SUPWIDGET.readJson(reply, PROTOCOL::URL_SUP_GET_SUP_CAT);
}

/*********************     修改供应商类别名称            *******************/
void HttpClient::supUpdateCatFinish(QNetworkReply *reply)
{
    SUPWIDGET.readJson(reply, PROTOCOL::URL_SUP_UPDATE_SUP_CAT);
}

/*********************     删除类别                     *******************/
void HttpClient::supDelCatFinish(QNetworkReply *reply)
{
    SUPWIDGET.readJson(reply, PROTOCOL::URL_SUP_DEL_SUP_CAT);
}

/*********************     获取供应商列表                *******************/
void HttpClient::supGetListFinish(QNetworkReply *reply)
{
    SUPWIDGET.readJson(reply, PROTOCOL::URL_SUP_GET_SUP_LIST);
}

/*********************     获取供应商详情                *******************/
void HttpClient::supDetailsFinish(QNetworkReply *reply)
{
    SUPWIDGET.readJson(reply, PROTOCOL::URL_SUP_DETAILS);
}

/*********************     修改供应商                    *******************/
void HttpClient::supUpdateFinish(QNetworkReply *reply)
{
    SUPWIDGET.readJson(reply, PROTOCOL::URL_SUP_UPDATE_SUP);
}

/*********************     删除供应商原料                 *******************/
void HttpClient::supDelMatFinish(QNetworkReply *reply)
{
    SUPWIDGET.readJson(reply, PROTOCOL::URL_SUP_DEL_SUP_MAT);
}

/*********************     删除供应商                     *******************/
void HttpClient::supDelFinish(QNetworkReply *reply)
{
    SUPWIDGET.readJson(reply, PROTOCOL::URL_SUP_DEL_SUP);
}

/*********************     查询当前供应商供应原料           *******************/
void HttpClient::supSelMatFinish(QNetworkReply *reply)
{
    SUPWIDGET.readJson(reply, PROTOCOL::URL_SUP_SEL_MATERIAL);
}

/*********************     查询当前供应商可供应的原料        *******************/
void HttpClient::supGetMatFinish(QNetworkReply *reply)
{
    SUPWIDGET.readJson(reply, PROTOCOL::URL_SUP_GET_MATERIAL);
}

/*********************     导出到邮箱                 *******************/
void HttpClient::supExtendFinish(QNetworkReply *reply)
{
    SUPWIDGET.readJson(reply, PROTOCOL::URL_SUP_EXTEND);
}

/*********************     获取所有原料列表                 *******************/
void HttpClient::temMatListFinish(QNetworkReply *reply)
{
    TEMWIDGET.readJson(reply, PROTOCOL::URL_TEM_MAT_LIST);
}

/*********************     添加模板                 *******************/
void HttpClient::temAddFinish(QNetworkReply *reply)
{
    TEMWIDGET.readJson(reply, PROTOCOL::URL_TEM_ADD_TEM);
}

/*********************     添加原料                 *******************/
void HttpClient::temAddMatFinish(QNetworkReply *reply)
{
    TEMWIDGET.readJson(reply, PROTOCOL::URL_TEM_ADD_MAT);
}

/*********************     获取模板列表                 *******************/
void HttpClient::temListFinish(QNetworkReply *reply)
{
    TEMWIDGET.readJson(reply, PROTOCOL::URL_TEM_LIST);
}

/*********************     模板详情列表                 *******************/
void HttpClient::temDetailsFinish(QNetworkReply *reply)
{
    TEMWIDGET.readJson(reply, PROTOCOL::URL_TEM_DETAILS);
}

/*********************     修改模板                 *******************/
void HttpClient::temUpdateFinish(QNetworkReply *reply)
{
    TEMWIDGET.readJson(reply, PROTOCOL::URL_TEM_UPDATE);
}

/*********************     删除原料                 *******************/
void HttpClient::temDelMatFinish(QNetworkReply *reply)
{
    TEMWIDGET.readJson(reply, PROTOCOL::URL_TEM_DEL_MAT);
}

/*********************     删除模板列表                *******************/
void HttpClient::temDeleteFinish(QNetworkReply *reply)
{
    TEMWIDGET.readJson(reply, PROTOCOL::URL_TEM_DELETE);
}

/*********************     根据分类获取原料模板          *******************/
void HttpClient::temGetMatListFinish(QNetworkReply *reply)
{
    TEMWIDGET.readJson(reply, PROTOCOL::URL_TEM_GET_MAT_LIST);
}

/*********************     获取原料分类                  *******************/
void HttpClient::temMatTypeListFinish(QNetworkReply *reply)
{
    TEMWIDGET.readJson(reply, PROTOCOL::URL_TEM_MAT_TYPE_LIST);
}

/*********************     显示所有菜品分类和菜品          *******************/
void HttpClient::bomFoodListFinish(QNetworkReply *reply)
{
    MATRATIOWIDGET.readJson(reply, PROTOCOL::URL_BOM_FOOD_LIST);
}

/*********************     查询菜品信息                   *******************/
void HttpClient::bomFoodGetIdFinish(QNetworkReply *reply)
{
    MATRATIOWIDGET.readJson(reply, PROTOCOL::URL_BOM_FOOD_GETID);
}

/*********************     删除菜品原料                   *******************/
void HttpClient::bomMatOldFinish(QNetworkReply *reply)
{
    MATRATIOWIDGET.readJson(reply, PROTOCOL::URL_BOM_MAT_OLD);
}

/*********************     修改原料                       *******************/
void HttpClient::bomMatDelFinish(QNetworkReply *reply)
{
    MATRATIOWIDGET.readJson(reply, PROTOCOL::URL_BOM_MAT_DEL);
}

/*********************     添加原料                       *******************/
void HttpClient::bomMatUpdateFinish(QNetworkReply *reply)
{
    MATRATIOWIDGET.readJson(reply, PROTOCOL::URL_BOM_MAT_UPDATE);
}

/*********************     查询新添加原料                  *******************/
void HttpClient::bomMatAddFinish(QNetworkReply *reply)
{
    MATRATIOWIDGET.readJson(reply, PROTOCOL::URL_BOM_MAT_ADD);
}

/*********************     查询新添加原料页                 *******************/
void HttpClient::bomMatNewFinish(QNetworkReply *reply)
{
    MATRATIOWIDGET.readJson(reply, PROTOCOL::URL_BOM_MAT_NEW);
}

/*********************     修改菜品                       *******************/
void HttpClient::bomSaveUpdateFinish(QNetworkReply *reply)
{
    MATRATIOWIDGET.readJson(reply, PROTOCOL::URL_BOM_SAVE_UPDATE);
}

/*********************     获取原料列表                    *******************/
void HttpClient::bomMatListFinish(QNetworkReply *reply)
{
    MATRATIOWIDGET.readJson(reply, PROTOCOL::URL_BOM_MAT_LIST);
}

/*********************     显示所有采购订单                 *******************/
void HttpClient::purSelAllFinish(QNetworkReply *reply)
{
    PURORDERWIDGET.readJson(reply, PROTOCOL::URL_PUR_SEL_ALL);
}

/*********************     添加采购订单页                   *******************/
void HttpClient::purIndentFinish(QNetworkReply *reply)
{
    PURORDERWIDGET.readJson(reply, PROTOCOL::URL_PUR_INDENT);
}

/*********************     添加采购订单                     *******************/
void HttpClient::purAddIndentFinish(QNetworkReply *reply)
{
    PURORDERWIDGET.readJson(reply, PROTOCOL::URL_PUR_ADD_INDENT);
}

/*********************     查询采购订单信息                 *******************/
void HttpClient::purSelFinish(QNetworkReply *reply)
{
    PURORDERWIDGET.readJson(reply, PROTOCOL::URL_PUR_SEL);
}

/*********************     查询供应商原料信息               *******************/
void HttpClient::purGetMatFinish(QNetworkReply *reply)
{
    PURORDERWIDGET.readJson(reply, PROTOCOL::URL_PUR_GET_MAT);
}

/*********************     修改采购订单                    *******************/
void HttpClient::purUpdateFinish(QNetworkReply *reply)
{
    PURORDERWIDGET.readJson(reply, PROTOCOL::URL_PUR_UPDATE);
}

/*********************     添加采购原料                    *******************/
void HttpClient::purAddMatFinish(QNetworkReply *reply)
{
    PURORDERWIDGET.readJson(reply, PROTOCOL::URL_PUR_ADD_MAT);
}

/*********************     删除采购原料                    *******************/
void HttpClient::purDelMatFinish(QNetworkReply *reply)
{
    PURORDERWIDGET.readJson(reply, PROTOCOL::URL_PUR_DEL_MAT);
}

/*********************     查询采购原料信息                *******************/
void HttpClient::purSelMatFinish(QNetworkReply *reply)
{
    PURORDERWIDGET.readJson(reply, PROTOCOL::URL_PUR_SEL_MAT);
}

/*********************     修改采购原料                   *******************/
void HttpClient::purUpdateMatFinish(QNetworkReply *reply)
{
    PURORDERWIDGET.readJson(reply, PROTOCOL::URL_PUR_UPDATE_MAT);
}

/*********************     确认供应商和原料                *******************/
void HttpClient::purExamineFinish(QNetworkReply *reply)
{
    PURORDERWIDGET.readJson(reply, PROTOCOL::URL_PUR_EXAMINE);
}

/*********************     确认采购页                     *******************/
void HttpClient::purAffirmPageFinish(QNetworkReply *reply)
{
    PURORDERWIDGET.readJson(reply, PROTOCOL::URL_PUR_AFFIRMPAGE);
}

/*********************     确认采购                       *******************/
void HttpClient::purAffirmFinish(QNetworkReply *reply)
{
    PURORDERWIDGET.readJson(reply, PROTOCOL::URL_PUR_AFFIRM);
}

/*********************     历史采购订单复制                *******************/
void HttpClient::purCopyFinish(QNetworkReply *reply)
{
    PURORDERWIDGET.readJson(reply, PROTOCOL::URL_PUR_COPY);
}

/*********************     删除订单                       *******************/
void HttpClient::purDelFinish(QNetworkReply *reply)
{
    PURORDERWIDGET.readJson(reply, PROTOCOL::URL_PUR_DEL);
}

/*********************     查询所有采购模板                 *******************/
void HttpClient::purSelTemplateFinish(QNetworkReply *reply)
{
    PURORDERWIDGET.readJson(reply, PROTOCOL::URL_PUR_SEL_TEMPLATE);
}

/*********************     设置采购数量页                   *******************/
void HttpClient::purNumberFinish(QNetworkReply *reply)
{
    PURORDERWIDGET.readJson(reply, PROTOCOL::URL_PUR_NUMBER);
}

/*********************     通过模板生成采购订单              *******************/
void HttpClient::purTemplateAddFinish(QNetworkReply *reply)
{
    PURORDERWIDGET.readJson(reply, PROTOCOL::URL_PUR_TEMPLATE_ADD);
}

/*********************     查询操作记录              *******************/
void HttpClient::purSelDisposeFinish(QNetworkReply *reply)
{
    PURORDERWIDGET.readJson(reply, PROTOCOL::URL_PUR_SEL_DISPOSE);
}

/*********************     筛选采购单页              *******************/
void HttpClient::purSelectPageFinish(QNetworkReply *reply)
{
    PURORDERWIDGET.readJson(reply, PROTOCOL::URL_PUR_SELECT_PAGE);
}

/*********************     筛选采购单结果              *******************/
void HttpClient::purSelectFinish(QNetworkReply *reply)
{
    PURORDERWIDGET.readJson(reply, PROTOCOL::URL_PUR_SELECT);
}

/*********************     导出采购单              *******************/
void HttpClient::purExtendFinish(QNetworkReply *reply)
{
    PURORDERWIDGET.readJson(reply, PROTOCOL::URL_PUR_EXTEND);
}

/*********************     查询单个入库单                  *******************/
void HttpClient::stoGetIdFinish(QNetworkReply *reply)
{
    PURSTOWIDGET.readJson(reply, PROTOCOL::URL_STO_GET_ID);
}

/*********************     显示所有入库订单                 *******************/
void HttpClient::stoSelFinish(QNetworkReply *reply)
{
    PURSTOWIDGET.readJson(reply, PROTOCOL::URL_STO_SEL);
}

/*********************     查询入库单信息                  *******************/
void HttpClient::stoSelDataFinish(QNetworkReply *reply)
{
    PURSTOWIDGET.readJson(reply, PROTOCOL::URL_STO_SEL_DATA);
}

/*********************     查询供应商原料信息               *******************/
void HttpClient::stoSelMatFinish(QNetworkReply *reply)
{
    PURSTOWIDGET.readJson(reply, PROTOCOL::URL_STO_SEL_MAT);
}

/*********************     添加原料                       *******************/
void HttpClient::stoAddMatFinish(QNetworkReply *reply)
{
    PURSTOWIDGET.readJson(reply, PROTOCOL::URL_STO_ADD_MAT);
}

/*********************     查询原料                       *******************/
void HttpClient::stoGetMatFinish(QNetworkReply *reply)
{
    PURSTOWIDGET.readJson(reply, PROTOCOL::URL_STO_GET_MAT);
}

/*********************     修改原料                       *******************/
void HttpClient::stoUpdateMatFinish(QNetworkReply *reply)
{
    PURSTOWIDGET.readJson(reply, PROTOCOL::URL_STO_UPDATE_MAT);
}

/*********************     删除原料                       *******************/
void HttpClient::stoDelMatFinish(QNetworkReply *reply)
{
    PURSTOWIDGET.readJson(reply, PROTOCOL::URL_STO_DEL_MAT);
}

/*********************     显示副仓库页                     *******************/
void HttpClient::stoSelSideFinish(QNetworkReply *reply)
{
    PURSTOWIDGET.readJson(reply, PROTOCOL::URL_STO_SEL_SIDE);
}

/*********************     判断仓库是否可以设置分仓           *******************/
void HttpClient::stoJudgeFinish(QNetworkReply *reply)
{
    PURSTOWIDGET.readJson(reply, PROTOCOL::URL_STO_JUDGE);
}

/*********************     添加副仓库                       *******************/
void HttpClient::stoUpdateSideFinish(QNetworkReply *reply)
{
    PURSTOWIDGET.readJson(reply, PROTOCOL::URL_STO_UPDATE_SIDE);
}

/*********************     删除副仓库                       *******************/
void HttpClient::stoDelSideFinish(QNetworkReply *reply)
{
    PURSTOWIDGET.readJson(reply, PROTOCOL::URL_STO_DEL_SIDE);
}

/*********************     历史采购订单导入                       *******************/
void HttpClient::stoCopyOrderFinish(QNetworkReply *reply)
{
    PURSTOWIDGET.readJson(reply, PROTOCOL::URL_STO_COPY_ORDER);
}

/*********************     添加入库单页面                       *******************/
void HttpClient::stoAddStoPageFinish(QNetworkReply *reply)
{
    PURSTOWIDGET.readJson(reply, PROTOCOL::URL_STO_ADD_STO_PAGE);
}

/*********************     添加入库单                       *******************/
void HttpClient::stoAddFinish(QNetworkReply *reply)
{
    PURSTOWIDGET.readJson(reply, PROTOCOL::URL_STO_ADD);
}

/*********************     修改入库单                       *******************/
void HttpClient::stoUpdateFinish(QNetworkReply *reply)
{
    PURSTOWIDGET.readJson(reply, PROTOCOL::URL_STO_UPDATE);
}

/*********************     拒绝收货                       *******************/
void HttpClient::stoRefuseFinish(QNetworkReply *reply)
{
    PURSTOWIDGET.readJson(reply, PROTOCOL::URL_STO_REFUSE);
}

/*********************     确认收货页                       *******************/
void HttpClient::stoConfirmPageFinish(QNetworkReply *reply)
{
    PURSTOWIDGET.readJson(reply, PROTOCOL::URL_STO_CONFIRM_PAGE);
}

/*********************     确认收货                       *******************/
void HttpClient::stoConfirmFinish(QNetworkReply *reply)
{
    PURSTOWIDGET.readJson(reply, PROTOCOL::URL_STO_CONFIRM);
}

/*********************     删除入库单                       *******************/
void HttpClient::stoDelFinish(QNetworkReply *reply)
{
    PURSTOWIDGET.readJson(reply, PROTOCOL::URL_STO_DEL);
}

/*********************     反确认                       *******************/
void HttpClient::stoReConfirmFinish(QNetworkReply *reply)
{
    PURSTOWIDGET.readJson(reply, PROTOCOL::URL_STO_RECONFIRM);
}

/*********************     删除原料页                       *******************/
void HttpClient::stoDelPageFinish(QNetworkReply *reply)
{
    PURSTOWIDGET.readJson(reply, PROTOCOL::URL_STO_DEL_PAGE);
}

/*********************     查询采购订单                       *******************/
void HttpClient::stoSelectPurFinish(QNetworkReply *reply)
{
    PURSTOWIDGET.readJson(reply, PROTOCOL::URL_STO_SELECT_PUR);
}

/*********************     导出到邮箱                       *******************/
void HttpClient::stoExpendEmailFinish(QNetworkReply *reply)
{
    PURSTOWIDGET.readJson(reply, PROTOCOL::URL_STO_EXPORT_EMAIL);
}

/*********************     查询操作记录                       *******************/
void HttpClient::stoSelDisposeFinish(QNetworkReply *reply)
{
    PURSTOWIDGET.readJson(reply, PROTOCOL::URL_STO_SEL_DISPOSE);
}

/*********************     筛选入库单页                       *******************/
void HttpClient::stoSelectPageFinish(QNetworkReply *reply)
{
    PURSTOWIDGET.readJson(reply, PROTOCOL::URL_STO_SELECT_PAGE);
}

/*********************     筛选入库单结果                      *******************/
void HttpClient::stoSelectFinish(QNetworkReply *reply)
{
    PURSTOWIDGET.readJson(reply, PROTOCOL::URL_STO_SELECT);
}

/*********************     入库完成                      *******************/
void HttpClient::stoStorageFinish(QNetworkReply *reply)
{
    PURSTOWIDGET.readJson(reply, PROTOCOL::URL_STO_FINISH);
}

/*********************     入库完成前提示                      *******************/
void HttpClient::stoStorageHintFinish(QNetworkReply *reply)
{
    PURSTOWIDGET.readJson(reply, PROTOCOL::URL_STO_FINISH_HINT);
}

/*********************     显示所有退货订单                     *******************/
void HttpClient::retSelFinish(QNetworkReply *reply)
{
    PURRETWIDGET.readJson(reply, PROTOCOL::URL_RETURN_SEL);
}

/*********************     查询退货单信息                       *******************/
void HttpClient::retDataFinish(QNetworkReply *reply)
{
    PURRETWIDGET.readJson(reply, PROTOCOL::URL_RETURN_DATA);
}

/*********************     修改退货单                       *******************/
void HttpClient::retUpdateFinish(QNetworkReply *reply)
{
    PURRETWIDGET.readJson(reply, PROTOCOL::URL_RETURN_UPDATE);
}

/*********************     添加退货订单页                       *******************/
void HttpClient::retAddPageFinish(QNetworkReply *reply)
{
    PURRETWIDGET.readJson(reply, PROTOCOL::URL_RETURN_ADD_PAGE);
}

/*********************     添加退货单                       *******************/
void HttpClient::retAddFinish(QNetworkReply *reply)
{
    PURRETWIDGET.readJson(reply, PROTOCOL::URL_RETURN_ADD);
}

/*********************     查询供应商原料信息                       *******************/
void HttpClient::retSelMatFinish(QNetworkReply *reply)
{
    PURRETWIDGET.readJson(reply, PROTOCOL::URL_RETURN_SEL_MAT);
}

/*********************     添加原料                       *******************/
void HttpClient::retAddMatFinish(QNetworkReply *reply)
{
    PURRETWIDGET.readJson(reply, PROTOCOL::URL_RETURN_ADD_MAT);
}

/*********************     查询原料                       *******************/
void HttpClient::retGatMatFinish(QNetworkReply *reply)
{
    PURRETWIDGET.readJson(reply, PROTOCOL::URL_RETURN_GET_MAT);
}

/*********************     修改原料                       *******************/
void HttpClient::retUpdateMatFinish(QNetworkReply *reply)
{
    PURRETWIDGET.readJson(reply, PROTOCOL::URL_RETURN_UPDATE_MAT);
}

/*********************     删除原料                       *******************/
void HttpClient::retDelMatFinish(QNetworkReply *reply)
{
    PURRETWIDGET.readJson(reply, PROTOCOL::URL_RETURN_DEL_MAT);
}

/*********************     显示副仓库页                       *******************/
void HttpClient::retSelSideFinish(QNetworkReply *reply)
{
    PURRETWIDGET.readJson(reply, PROTOCOL::URL_RETURN_SEL_SIDE);
}

/*********************     判断仓库是否可以设置分仓                       *******************/
void HttpClient::retJudgeFinish(QNetworkReply *reply)
{
    PURRETWIDGET.readJson(reply, PROTOCOL::URL_RETURN_JUDGE);
}

/*********************     添加副仓库                       *******************/
void HttpClient::retUpdateSideFinish(QNetworkReply *reply)
{
    PURRETWIDGET.readJson(reply, PROTOCOL::URL_RETURN_UPDATE_SIDE);
}

/*********************     删除副仓库                       *******************/
void HttpClient::retDelSideFinish(QNetworkReply *reply)
{
    PURRETWIDGET.readJson(reply, PROTOCOL::URL_RETURN_DEL_SIDE);
}

/*********************     历史退货单导入                       *******************/
void HttpClient::retCopyOrderFinish(QNetworkReply *reply)
{
    PURRETWIDGET.readJson(reply, PROTOCOL::URL_RETURN_COPY_ORDER);
}

/*********************     确认退货                       *******************/
void HttpClient::retConfirmFinish(QNetworkReply *reply)
{
    PURRETWIDGET.readJson(reply, PROTOCOL::URL_RETURN_CONFIRM);
}

/*********************     删除退货单                       *******************/
void HttpClient::retDelStoFinish(QNetworkReply *reply)
{
    PURRETWIDGET.readJson(reply, PROTOCOL::URL_RETURN_DEL_STO);
}

/*********************     查询操作记录                     *******************/
void HttpClient::retSelDisposeFinish(QNetworkReply *reply)
{
    PURRETWIDGET.readJson(reply, PROTOCOL::URL_RETURN_SEL_DISPOSE);
}

/*********************     删除原料显示页                   *******************/
void HttpClient::retDelMatShowFinish(QNetworkReply *reply)
{
    PURRETWIDGET.readJson(reply, PROTOCOL::URL_RETURN_DEL_MAT_SHOW);
}

/*********************     筛选退货单页                    *******************/
void HttpClient::retSelectPageFinish(QNetworkReply *reply)
{
    PURRETWIDGET.readJson(reply, PROTOCOL::URL_RETURN_SELECT_PAGE);
}

/*********************     筛选退货单结果                  *******************/
void HttpClient::retSelectFinish(QNetworkReply *reply)
{
    PURRETWIDGET.readJson(reply, PROTOCOL::URL_RETURN_SELECT);
}

/*********************     导出退货单                  *******************/
void HttpClient::retExtendFinish(QNetworkReply *reply)
{
    PURRETWIDGET.readJson(reply, PROTOCOL::URL_RETURN_EXTEND);
}

/*********************     显示已设置上下限原料              *******************/
void HttpClient::safSelMatShowFinish(QNetworkReply *reply)
{
    SAFRETWIDGET.readJson(reply, PROTOCOL::URL_SAFETY_SEL);
}

/*********************     确认采购                       *******************/
void HttpClient::safAffirmFinish(QNetworkReply *reply)
{
    SAFRETWIDGET.readJson(reply, PROTOCOL::URL_SAFETY_AFFIRM);
}

/*********************     显示原料                       *******************/
void HttpClient::defaultSelMatFinish(QNetworkReply *reply)
{
    DEFAULTWIDGET.readJson(reply, PROTOCOL::URL_DEFAULT_SEL);
}

/*********************     原料详情                       *******************/
void HttpClient::defaultGetMatFinish(QNetworkReply *reply)
{
    DEFAULTWIDGET.readJson(reply, PROTOCOL::URL_DEFAULT_GET_MAT);
}

/*********************     修改默认供应商                  *******************/
void HttpClient::defaultUpdateSupFinish(QNetworkReply *reply)
{
    DEFAULTWIDGET.readJson(reply, PROTOCOL::URL_DEFAULT_UPDATE_SUP);
}

/*********************     获取供应商                       *******************/
void HttpClient::defaultGetSupFinish(QNetworkReply *reply)
{
    DEFAULTWIDGET.readJson(reply, PROTOCOL::URL_DEFAULT_GET_SUP);
}

/*********************     实时库存查询列表                       *******************/
void HttpClient::timeMatListFinish(QNetworkReply *reply)
{
    WAREHOUSEWIDGET.readJson(reply, PROTOCOL::URL_TIME_MAT_LIST);
}

/*********************     查询原料库存详情                       *******************/
void HttpClient::timeSelMatFinish(QNetworkReply *reply)
{
    WAREHOUSEWIDGET.readJson(reply, PROTOCOL::URL_TIME_SEL_MAT);
}

/*********************     导出实时库存                       *******************/
void HttpClient::timeSendEmailFinish(QNetworkReply *reply)
{
    WAREHOUSEWIDGET.readJson(reply, PROTOCOL::URL_TIME_SEND_EMAIL);
}

/*********************     添加基本信息                       *******************/
void HttpClient::adjAddInvFinish(QNetworkReply *reply)
{
    ADJUSTWIDGET.readJson(reply, PROTOCOL::URL_ADJ_ADD_INV);
}

/*********************     获取调整单类型                       *******************/
void HttpClient::adjTypeFinish(QNetworkReply *reply)
{
    ADJUSTWIDGET.readJson(reply, PROTOCOL::URL_ADJ_TYPE);
}

/*********************     获取原料                       *******************/
void HttpClient::adjGetMatFinish(QNetworkReply *reply)
{
    ADJUSTWIDGET.readJson(reply, PROTOCOL::URL_ADJ_GET_MAT);
}

/*********************     添加原料                       *******************/
void HttpClient::adjAddMatFinish(QNetworkReply *reply)
{
    ADJUSTWIDGET.readJson(reply, PROTOCOL::URL_ADJ_ADD_MAT);
}

/*********************     获取库存调整列表                       *******************/
void HttpClient::adjGetInvListFinish(QNetworkReply *reply)
{
    ADJUSTWIDGET.readJson(reply, PROTOCOL::URL_ADJ_GET_INV_LIST);
}

/*********************     获取调整单详情                       *******************/
void HttpClient::adjGetDetFinish(QNetworkReply *reply)
{
    ADJUSTWIDGET.readJson(reply, PROTOCOL::URL_ADJ_GET_DET);
}

/*********************     获取原料详情                       *******************/
void HttpClient::adjGetMatDetFinish(QNetworkReply *reply)
{
    ADJUSTWIDGET.readJson(reply, PROTOCOL::URL_ADJ_GET_MAT_DET);
}

/*********************     修改调整单的基本信息                       *******************/
void HttpClient::adjUpdateDasicFinish(QNetworkReply *reply)
{
    ADJUSTWIDGET.readJson(reply, PROTOCOL::URL_ADJ_UPDATE_DASIC);
}

/*********************     修改调整原料                       *******************/
void HttpClient::adjUpdateMatFinish(QNetworkReply *reply)
{
    ADJUSTWIDGET.readJson(reply, PROTOCOL::URL_ADJ_UPDATE_MAT);
}

/*********************     添加调整原因                       *******************/
void HttpClient::adjAddReasonFinish(QNetworkReply *reply)
{
    ADJUSTWIDGET.readJson(reply, PROTOCOL::URL_ADJ_ADD_REASON);
}

/*********************     获取调整原因列表                       *******************/
void HttpClient::adjGetReasonFinish(QNetworkReply *reply)
{
    ADJUSTWIDGET.readJson(reply, PROTOCOL::URL_ADJ_GET_REASON);
}

/*********************     删除调整原因                       *******************/
void HttpClient::adjDelReasonFinish(QNetworkReply *reply)
{
    ADJUSTWIDGET.readJson(reply, PROTOCOL::URL_ADJ_DEL_REASON);
}

/*********************     删除调整原料                       *******************/
void HttpClient::adjDelMatFinish(QNetworkReply *reply)
{
    ADJUSTWIDGET.readJson(reply, PROTOCOL::URL_ADJ_DEL_MAT);
}

/*********************     导出库存调整单                       *******************/
void HttpClient::adjSendEmailFinish(QNetworkReply *reply)
{
    ADJUSTWIDGET.readJson(reply, PROTOCOL::URL_ADJ_SEND_EMAIL);
}

/*********************     获取仓库列表                       *******************/
void HttpClient::adjWareHouseFinish(QNetworkReply *reply)
{
    ADJUSTWIDGET.readJson(reply, PROTOCOL::URL_ADJ_WAREHOUSE);
}

/*********************     删除调整单                       *******************/
void HttpClient::adjDelInvFinish(QNetworkReply *reply)
{
    ADJUSTWIDGET.readJson(reply, PROTOCOL::URL_ADJ_DEL);
}

/*********************     查询操作记录                     *******************/
void HttpClient::adjSelectLogFinish(QNetworkReply *reply)
{
    ADJUSTWIDGET.readJson(reply, PROTOCOL::URL_ADJ_SEL_DISPOSE);
}

/*********************     提交订单                        *******************/
void HttpClient::adjPresendFinish(QNetworkReply *reply)
{
    ADJUSTWIDGET.readJson(reply, PROTOCOL::URL_ADJ_PRESENT);
}

/*********************     筛选调整单页                *******************/
void HttpClient::adjSelectPageFinish(QNetworkReply *reply)
{
    ADJUSTWIDGET.readJson(reply, PROTOCOL::URL_ADJ_SELECT_PAGE);
}

/*********************     筛选调整单结果                *******************/
void HttpClient::adjSelectFinish(QNetworkReply *reply)
{
    ADJUSTWIDGET.readJson(reply, PROTOCOL::URL_ADJ_SELECT);
}

/*********************     单位转换                *******************/
void HttpClient::adjConvertFinish(QNetworkReply *reply)
{
    ADJUSTWIDGET.readJson(reply, PROTOCOL::URL_ADJ_CONVERT);
}

/*********************     显示所有仓库盘存单                *******************/
void HttpClient::checkSelAllFinish(QNetworkReply *reply)
{
    CHECKWIDGET.readJson(reply, PROTOCOL::URL_CHECK_SEL_ALL);
}

/*********************     查询盘存单信息                   *******************/
void HttpClient::checkSelFinish(QNetworkReply *reply)
{
    CHECKWIDGET.readJson(reply, PROTOCOL::URL_CHECK_SEL);
}

/*********************     添加盘存单页                     *******************/
void HttpClient::checkAddPageFinish(QNetworkReply *reply)
{
    CHECKWIDGET.readJson(reply, PROTOCOL::URL_CHECK_ADD_PAGE);
}

/*********************     添加盘存单                       *******************/
void HttpClient::checkAddFinish(QNetworkReply *reply)
{
    CHECKWIDGET.readJson(reply, PROTOCOL::URL_CHECK_ADD);
}

/*********************     修改盘存单                       *******************/
void HttpClient::checkUpdateFinish(QNetworkReply *reply)
{
    CHECKWIDGET.readJson(reply, PROTOCOL::URL_CHECK_UPDATE);
}

/*********************     显示盘存原料页                    *******************/
void HttpClient::checkMatPageFinish(QNetworkReply *reply)
{
    CHECKWIDGET.readJson(reply, PROTOCOL::URL_CHECK_MAT_PAGE);
}

/*********************     添加盘存原料页                    *******************/
void HttpClient::checkAddMatPageFinish(QNetworkReply *reply)
{
    CHECKWIDGET.readJson(reply, PROTOCOL::URL_CHECK_ADD_MAT_PAGE);
}

/*********************     添加盘存原料                      *******************/
void HttpClient::checkAddMatFinish(QNetworkReply *reply)
{
    CHECKWIDGET.readJson(reply, PROTOCOL::URL_CHECK_ADD_MAT);
}

/*********************     修改盘存原料页                    *******************/
void HttpClient::checkUpdateMatPageFinish(QNetworkReply *reply)
{
    CHECKWIDGET.readJson(reply, PROTOCOL::URL_CHECK_UPDATE_MAT_PAGE);
}

/*********************     修改盘存原料                      *******************/
void HttpClient::checkUpdateMatFinish(QNetworkReply *reply)
{
    CHECKWIDGET.readJson(reply, PROTOCOL::URL_CHECK_UPDATE_MAT);
}

/*********************     修改单位，改变原料数量              *******************/
void HttpClient::checkUnitUpdateNumFinish(QNetworkReply *reply)
{
    CHECKWIDGET.readJson(reply, PROTOCOL::URL_CHECK_UNIT_UPDATE_NUM);
}

/*********************     修改盘存原料数量（批量修改）         *******************/
void HttpClient::checkUpdateNumFinish(QNetworkReply *reply)
{
    CHECKWIDGET.readJson(reply, PROTOCOL::URL_CHECK_UPDATE_NUM);
}

/*********************     取消盘存                         *******************/
void HttpClient::checkCancelFinish(QNetworkReply *reply)
{
    CHECKWIDGET.readJson(reply, PROTOCOL::URL_CHECK_CANCEL);
}

/*********************     删除盘存                         *******************/
void HttpClient::checkDelFinish(QNetworkReply *reply)
{
    CHECKWIDGET.readJson(reply, PROTOCOL::URL_CHECK_DEL);
}

/*********************     历史盘存单导入                    *******************/
void HttpClient::checkImportFinish(QNetworkReply *reply)
{
    CHECKWIDGET.readJson(reply, PROTOCOL::URL_CHECK_IMPORT);
}

/*********************     确认盘存                         *******************/
void HttpClient::checkAffirmFinish(QNetworkReply *reply)
{
    CHECKWIDGET.readJson(reply, PROTOCOL::URL_CHECK_AFFIRM);
}

/*********************     导出仓库盘存单                    *******************/
void HttpClient::checkSendEmailFinish(QNetworkReply *reply)
{
    CHECKWIDGET.readJson(reply, PROTOCOL::URL_CHECK_SEND_EMAIL);
}

/*********************     查询操作记录                     *******************/
void HttpClient::checkSelDisposeFinish(QNetworkReply *reply)
{
    CHECKWIDGET.readJson(reply, PROTOCOL::URL_CHECK_SEL_DISPOSE);
}

/*********************     删除原料                     *******************/
void HttpClient::checkDelMatFinish(QNetworkReply *reply)
{
    CHECKWIDGET.readJson(reply, PROTOCOL::URL_CHECK_DEL_MAT);
}

/*********************     筛选盘存单页                   *******************/
void HttpClient::checkSelectPageFinish(QNetworkReply *reply)
{
    CHECKWIDGET.readJson(reply, PROTOCOL::URL_CHECK_SELECT_PAGE);
}

/*********************     筛选盘存单结果                *******************/
void HttpClient::checkSelectFinish(QNetworkReply *reply)
{
    CHECKWIDGET.readJson(reply, PROTOCOL::URL_CHECK_SELECT);
}

/*********************     查询页面                     *******************/
void HttpClient::changeSelMatFinish(QNetworkReply *reply)
{
    CHANGEWIDGET.readJson(reply, PROTOCOL::URL_CHANCE_SEL_MAT);
}

/*********************     查询结果页                     *******************/
void HttpClient::changeMatListFinish(QNetworkReply *reply)
{
    CHANGEWIDGET.readJson(reply, PROTOCOL::URL_CHANCE_MAT_LIST);
}

/*********************     查询结果页                     *******************/
void HttpClient::changeAllMatFinish(QNetworkReply *reply)
{
    CHANGEWIDGET.readJson(reply, PROTOCOL::URL_CHANCE_ALL_MAT);
}

/*********************     查询结果页                     *******************/
void HttpClient::changeGetMatFinish(QNetworkReply *reply)
{
    CHANGEWIDGET.readJson(reply, PROTOCOL::URL_CHANCE_GET_MAT);
}

/*********************     导出库存变更                     *******************/
void HttpClient::changeExtendFinish(QNetworkReply *reply)
{
    CHANGEWIDGET.readJson(reply, PROTOCOL::URL_CHANCE_EXTEND);
}

/*********************     查询所有调价单                       *******************/
void HttpClient::costSelAllFinish(QNetworkReply *reply)
{
    COSTWIDGET.readJson(reply, PROTOCOL::URL_COST_SEL_ALL);
}

/*********************     入库原料成本价列表                       *******************/
void HttpClient::costPriceFinish(QNetworkReply *reply)
{
    COSTWIDGET.readJson(reply, PROTOCOL::URL_COST_PRICE);
}

/*********************     添加调价单                       *******************/
void HttpClient::costAddFinish(QNetworkReply *reply)
{
    COSTWIDGET.readJson(reply, PROTOCOL::URL_COST_ADD);
}

/*********************     显示调价原料页                       *******************/
void HttpClient::costSelMatFinish(QNetworkReply *reply)
{
    COSTWIDGET.readJson(reply, PROTOCOL::URL_COST_SEL_MAT);
}

/*********************     添加调价原料                       *******************/
void HttpClient::costAddMatFinish(QNetworkReply *reply)
{
    COSTWIDGET.readJson(reply, PROTOCOL::URL_COST_ADD_MAT);
}

/*********************     查询调价单信息                       *******************/
void HttpClient::costSelFinish(QNetworkReply *reply)
{
    COSTWIDGET.readJson(reply, PROTOCOL::URL_COST_SEL);
}

/*********************     修改调价单                       *******************/
void HttpClient::costUpdateFinish(QNetworkReply *reply)
{
    COSTWIDGET.readJson(reply, PROTOCOL::URL_COST_UPDATE);
}

/*********************     删除调价单                       *******************/
void HttpClient::costDelFinish(QNetworkReply *reply)
{
    COSTWIDGET.readJson(reply, PROTOCOL::URL_COST_DEL);
}

/*********************     查询调价原料信息                       *******************/
void HttpClient::costGetMatFinish(QNetworkReply *reply)
{
    COSTWIDGET.readJson(reply, PROTOCOL::URL_COST_GET_MAT);
}

/*********************     修改调价原料                       *******************/
void HttpClient::costUpdateMatFinish(QNetworkReply *reply)
{
    COSTWIDGET.readJson(reply, PROTOCOL::URL_COST_UPDATE_MAT);
}

/*********************     批量修改页                       *******************/
void HttpClient::costUpdatePageFinish(QNetworkReply *reply)
{
    COSTWIDGET.readJson(reply, PROTOCOL::URL_COST_UPDATE_PAGE);
}

/*********************     批量修改                       *******************/
void HttpClient::costUpdateAllMatFinish(QNetworkReply *reply)
{
    COSTWIDGET.readJson(reply, PROTOCOL::URL_COST_UPDATE_ALL_MAT);
}

/*********************     删除调价原料                       *******************/
void HttpClient::costDelMatFinish(QNetworkReply *reply)
{
    COSTWIDGET.readJson(reply, PROTOCOL::URL_COST_DEL_MAT);
}

/*********************     提交调价单（提交过后不能删除）                       *******************/
void HttpClient::costPresentFinish(QNetworkReply *reply)
{
    COSTWIDGET.readJson(reply, PROTOCOL::URL_COST_PRESENT);
}

/*********************     确认调价                       *******************/
void HttpClient::costAffirmFinish(QNetworkReply *reply)
{
    COSTWIDGET.readJson(reply, PROTOCOL::URL_COST_AFFIRM);
}

/*********************     获取数据                       *******************/
void HttpClient::costSelDisposeFinish(QNetworkReply *reply)
{
    COSTWIDGET.readJson(reply, PROTOCOL::URL_COST_SEL_DISPOSE);
}

/*********************     筛选调价单页                  *******************/
void HttpClient::costSelectPageFinish(QNetworkReply *reply)
{
    COSTWIDGET.readJson(reply, PROTOCOL::URL_COST_SELECT_PAGE);
}

/*********************     筛选调价单结果                  *******************/
void HttpClient::costSelectFinish(QNetworkReply *reply)
{
    COSTWIDGET.readJson(reply, PROTOCOL::URL_COST_SELECT);
}

/*********************     显示所有原料页面                  *******************/
void HttpClient::restSelMatFinish(QNetworkReply *reply)
{
    RESTWIDGET.readJson(reply, PROTOCOL::URL_REST_SEL_MAT);
}

/*********************     设置原料上下限页面                 *******************/
void HttpClient::restGetMatFinish(QNetworkReply *reply)
{
    RESTWIDGET.readJson(reply, PROTOCOL::URL_REST_GET_MAT);
}

/*********************     修改原料上下限支持批量修改           *******************/
void HttpClient::restUpdateMatFinish(QNetworkReply *reply)
{
    RESTWIDGET.readJson(reply, PROTOCOL::URL_REST_UPDATE_MAT);
}

/*********************     查询所有调拨单           *******************/
void HttpClient::allotSelAllFinish(QNetworkReply *reply)
{
    TRANWIDGET.readJson(reply, PROTOCOL::URL_ALLOT_SEL_ALL);
}

/*********************     添加调拨单页           *******************/
void HttpClient::allotAddPageFinish(QNetworkReply *reply)
{
    TRANWIDGET.readJson(reply, PROTOCOL::URL_ALLOT_ADD_PAGE);
}

/*********************     添加调拨单           *******************/
void HttpClient::allotAddFinish(QNetworkReply *reply)
{
    TRANWIDGET.readJson(reply, PROTOCOL::URL_ALLOT_ADD);
}

/*********************     查询调拨单           *******************/
void HttpClient::allotSelFinish(QNetworkReply *reply)
{
    TRANWIDGET.readJson(reply, PROTOCOL::URL_ALLOT_SEL);
}

/*********************     修改调拨单           *******************/
void HttpClient::allotUpdateFinish(QNetworkReply *reply)
{
    TRANWIDGET.readJson(reply, PROTOCOL::URL_ALLOT_UPDATE);
}

/*********************     删除调拨单           *******************/
void HttpClient::allotDelFinish(QNetworkReply *reply)
{
    TRANWIDGET.readJson(reply, PROTOCOL::URL_ALLOT_DEL);
}

/*********************     添加调拨原料页           *******************/
void HttpClient::allotSelMatFinish(QNetworkReply *reply)
{
    TRANWIDGET.readJson(reply, PROTOCOL::URL_ALLOT_SEL_MAT);
}

/*********************     添加调拨原料           *******************/
void HttpClient::allotAddMatFinish(QNetworkReply *reply)
{
    TRANWIDGET.readJson(reply, PROTOCOL::URL_ALLOT_ADD_MAT);
}

/*********************     查询调拨原料           *******************/
void HttpClient::allotGetMatFinish(QNetworkReply *reply)
{
    TRANWIDGET.readJson(reply, PROTOCOL::URL_ALLOT_GET_MAT);
}

/*********************     修改调拨原料           *******************/
void HttpClient::allotUpdateMatFinish(QNetworkReply *reply)
{
    TRANWIDGET.readJson(reply, PROTOCOL::URL_ALLOT_UPDATE_MAT);
}

/*********************     删除调拨原料           *******************/
void HttpClient::allotDelMatFinish(QNetworkReply *reply)
{
    TRANWIDGET.readJson(reply, PROTOCOL::URL_ALLOT_DEL_MAT);
}

/*********************     批量修改页           *******************/
void HttpClient::allotUpdateAllPageFinish(QNetworkReply *reply)
{
    TRANWIDGET.readJson(reply, PROTOCOL::URL_ALLOT_UPDATE_ALL_PAGE);
}

/*********************     批量修改           *******************/
void HttpClient::allotUpdateAllMatFinish(QNetworkReply *reply)
{
    TRANWIDGET.readJson(reply, PROTOCOL::URL_ALLOT_UPDATE_ALL_MAT);
}

/*********************     确认提交           *******************/
void HttpClient::allotPresendFinish(QNetworkReply *reply)
{
    TRANWIDGET.readJson(reply, PROTOCOL::URL_ALLOT_PRESEND);
}

/*********************     拒绝调拨           *******************/
void HttpClient::allotCancelFinish(QNetworkReply *reply)
{
    TRANWIDGET.readJson(reply, PROTOCOL::URL_ALLOT_CANCEL);
}

/*********************     调拨完成           *******************/
void HttpClient::allotAffirmFinish(QNetworkReply *reply)
{
    TRANWIDGET.readJson(reply, PROTOCOL::URL_ALLOT_AFFIRM);
}

/*********************     反确认           *******************/
void HttpClient::allotReconfirmFinish(QNetworkReply *reply)
{
    TRANWIDGET.readJson(reply, PROTOCOL::URL_ALLOT_RECONFIRM);
}

/*********************     导出调拨单           *******************/
void HttpClient::allotSendEmailFinish(QNetworkReply *reply)
{
    TRANWIDGET.readJson(reply, PROTOCOL::URL_ALLOT_SEND_EMAIL);
}

/*********************     查询操作记录           *******************/
void HttpClient::allotSelDisposeFinish(QNetworkReply *reply)
{
    TRANWIDGET.readJson(reply, PROTOCOL::URL_ALLOT_SEL_DISPOSE);
}

/*********************     筛选调拨单页           *******************/
void HttpClient::allotSelectPageFinish(QNetworkReply *reply)
{
    TRANWIDGET.readJson(reply, PROTOCOL::URL_ALLOT_SELECT_PAGE);
}

/*********************     筛选调拨单结果           *******************/
void HttpClient::allotSelectFinish(QNetworkReply *reply)
{
    TRANWIDGET.readJson(reply, PROTOCOL::URL_ALLOT_SELECT);
}

/*********************     采购入库明细报表--查询页           *******************/
void HttpClient::stateStoPageFinish(QNetworkReply *reply)
{
    REPORTWIDGET.readJson(reply, PROTOCOL::URL_STATE_STO_PAGE);
}

/*********************     采购入库明细报表           *******************/
void HttpClient::stateStorageFinish(QNetworkReply *reply)
{
    REPORTWIDGET.readJson(reply, PROTOCOL::URL_STATE_STORAGE);
}

/*********************     导出采购入库明细报表           *******************/
void HttpClient::stateStorageExtendFinish(QNetworkReply *reply)
{
    REPORTWIDGET.readJson(reply, PROTOCOL::URL_STATE_STORAGE_EXTEND);
}

/*********************     采购入库汇总报表--查询页           *******************/
void HttpClient::stateStoGatherPageFinish(QNetworkReply *reply)
{
    REPORTWIDGET.readJson(reply, PROTOCOL::URL_STATE_STO_GATHER_PAGE);
}

/*********************     采购入库汇总报表           *******************/
void HttpClient::stateStoGatherFinish(QNetworkReply *reply)
{
    REPORTWIDGET.readJson(reply, PROTOCOL::URL_STATE_STORAGE_GATHER);
}

/*********************     导出采购入库汇总报表           *******************/
void HttpClient::stateStoGatherExtendFinish(QNetworkReply *reply)
{
    REPORTWIDGET.readJson(reply, PROTOCOL::URL_STATE_STO_GAT_EXTEND);
}

/*********************     采购退货明细报表--查询页           *******************/
void HttpClient::stateRetPageFinish(QNetworkReply *reply)
{
    REPORTWIDGET.readJson(reply, PROTOCOL::URL_STATE_RET_PAGE);
}

/*********************     采购退货明细报表           *******************/
void HttpClient::stateReturnsFinish(QNetworkReply *reply)
{
    REPORTWIDGET.readJson(reply, PROTOCOL::URL_STATE_RETURNS);
}

/*********************     导出采购退货明细报表           *******************/
void HttpClient::stateReturnsExtendFinish(QNetworkReply *reply)
{
    REPORTWIDGET.readJson(reply, PROTOCOL::URL_STATE_RETURNS_EXTEND);
}

/*********************     调整单明细报表--查询页           *******************/
void HttpClient::stateAdjPageFinish(QNetworkReply *reply)
{
    REPORTWIDGET.readJson(reply, PROTOCOL::URL_STATE_ADJ_PAGE);
}

/*********************     调整单明细报表           *******************/
void HttpClient::stateAdjustFinish(QNetworkReply *reply)
{
    REPORTWIDGET.readJson(reply, PROTOCOL::URL_STATE_ADJUST);
}

/*********************     导出调整单明细报表           *******************/
void HttpClient::stateAdjustExtendFinish(QNetworkReply *reply)
{
    REPORTWIDGET.readJson(reply, PROTOCOL::URL_STATE_ADJUST_EXTEND);
}

/*********************     盘存单明细报表--查询页           *******************/
void HttpClient::stateCheckPageFinish(QNetworkReply *reply)
{
    REPORTWIDGET.readJson(reply, PROTOCOL::URL_STATE_CHECK_PAGE);
}

/*********************     盘存单明细报表           *******************/
void HttpClient::stateCheckFinish(QNetworkReply *reply)
{
    REPORTWIDGET.readJson(reply, PROTOCOL::URL_STATE_CHECK);
}

/*********************     导出盘存单明细报表           *******************/
void HttpClient::stateCheckExtendFinish(QNetworkReply *reply)
{
    REPORTWIDGET.readJson(reply, PROTOCOL::URL_STATE_CHECK_EXTEND);
}

/*********************     盘存单汇总报表--查询页           *******************/
void HttpClient::stateCheckGatherPageFinish(QNetworkReply *reply)
{
    REPORTWIDGET.readJson(reply, PROTOCOL::URL_STATE_CHK_GATHER_PAGE);
}

/*********************     盘存单汇总报表           *******************/
void HttpClient::stateCheckGatherFinish(QNetworkReply *reply)
{
    REPORTWIDGET.readJson(reply, PROTOCOL::URL_STATE_CHECK_GATHER);
}

/*********************     导出盘存单汇总报表           *******************/
void HttpClient::stateCheckGatherExtendFinish(QNetworkReply *reply)
{
    REPORTWIDGET.readJson(reply, PROTOCOL::URL_STATE_CHK_GAT_EXTEND);
}

/*********************     供应商供货明细报表--查询页           *******************/
void HttpClient::stateSupPageFinish(QNetworkReply *reply)
{
    REPORTWIDGET.readJson(reply, PROTOCOL::URL_STATE_SUP_PAGE);
}

/*********************     供应商供货明细报表           *******************/
void HttpClient::stateSupplierFinish(QNetworkReply *reply)
{
    REPORTWIDGET.readJson(reply, PROTOCOL::URL_STATE_SUPPLIER);
}

/*********************     导出供应商供货明细报表           *******************/
void HttpClient::stateSupplierExtendFinish(QNetworkReply *reply)
{
    REPORTWIDGET.readJson(reply, PROTOCOL::URL_STATE_SUPPLIER_EXTEND);
}

/*********************     供应商供货汇总报表--查询页    *******************/
void HttpClient::stateSupGatherPageFinish(QNetworkReply *reply)
{
    REPORTWIDGET.readJson(reply, PROTOCOL::URL_STATE_SUP_GATHER_PAGE);
}

/*********************     供应商供货汇总报表       *******************/
void HttpClient::stateSupGatherFinish(QNetworkReply *reply)
{
    REPORTWIDGET.readJson(reply, PROTOCOL::URL_STATE_SUP_GATHER);
}

/*********************     导出供应商供货汇总报表    *******************/
void HttpClient::stateSupGatherExtendFinish(QNetworkReply *reply)
{
    REPORTWIDGET.readJson(reply, PROTOCOL::URL_STATE_SUP_GAT_EXTEND);
}

/*********************     原料销售报表 -- 查询页    *******************/
void HttpClient::stateSelectMatPageFinish(QNetworkReply *reply)
{
    REPORTWIDGET.readJson(reply, PROTOCOL::URL_STATE_SELECT_MAT_PAGE);
}

/*********************     原料销售报表     *******************/
void HttpClient::stateSelectMatFinish(QNetworkReply *reply)
{
    REPORTWIDGET.readJson(reply, PROTOCOL::URL_STATE_SELECT_MAT);
}

/*********************     原料销售报表    *******************/
void HttpClient::stateSelMatExtendFinish(QNetworkReply *reply)
{
    REPORTWIDGET.readJson(reply, PROTOCOL::URL_STATE_SEL_MAT_EXTEND);
}

/*********************     显示所有入库和退货单      *******************/
void HttpClient::accountAllFinish(QNetworkReply *reply)
{
    ACCOUNTWIDGET.readJson(reply, PROTOCOL::URL_ACCOUNT_ALL_NUMBER);
}

/*********************     入库单修改页面           *******************/
void HttpClient::accountStoUpdateFinish(QNetworkReply *reply)
{
    ACCOUNTWIDGET.readJson(reply, PROTOCOL::URL_ACCOUNT_STO_PAGE);
}

/*********************     退货单修改页面           *******************/
void HttpClient::accountRetUpdateFinish(QNetworkReply *reply)
{
    ACCOUNTWIDGET.readJson(reply, PROTOCOL::URL_ACCOUNT_RET_PAGE);
}

/*********************     确认对账           *******************/
void HttpClient::accountAffirmProFinish(QNetworkReply *reply)
{
    ACCOUNTWIDGET.readJson(reply, PROTOCOL::URL_ACCOUNT_AFFIRM_PRO);
}

/*********************     确认结算           *******************/
void HttpClient::accountAffirmAccFinish(QNetworkReply *reply)
{
    ACCOUNTWIDGET.readJson(reply, PROTOCOL::URL_ACCOUNT_AFFIRM_ACC);
}

/*********************     查询操作记录           *******************/
void HttpClient::accountSelDisposeFinish(QNetworkReply *reply)
{
    ACCOUNTWIDGET.readJson(reply, PROTOCOL::URL_ACCOUNT_SEL_DISPOSE);
}

/*********************     查询入库原料信息           *******************/
void HttpClient::accountSelStoMatFinish(QNetworkReply *reply)
{
    ACCOUNTWIDGET.readJson(reply, PROTOCOL::URL_ACCOUNT_STO_MAT_INFO);
}

/*********************     查询退货原料信息           *******************/
void HttpClient::accountSelRetMatFinish(QNetworkReply *reply)
{
    ACCOUNTWIDGET.readJson(reply, PROTOCOL::URL_ACCOUNT_RET_MAT_INFO);
}

/*********************     支出结算筛选页             *******************/
void HttpClient::accountFiltratePageFinish(QNetworkReply *reply)
{
    ACCOUNTWIDGET.readJson(reply, PROTOCOL::URL_ACCOUNT_FILTRATE_PAGE);
}

/*********************     查询页                   *******************/
void HttpClient::accountFiltrateFinish(QNetworkReply *reply)
{
    ACCOUNTWIDGET.readJson(reply, PROTOCOL::URL_ACCOUNT_FILTRATE);
}

/*********************     发送邮件                   *******************/
void HttpClient::accountSendEmailFinish(QNetworkReply *reply)
{
    ACCOUNTWIDGET.readJson(reply, PROTOCOL::URL_ACCOUNT_EXTEND);
}

/*********************     当天营业数据               *******************/
void HttpClient::todaySelTodayFinish(QNetworkReply *reply)
{
    TODAYWIDGET.readJson(reply, PROTOCOL::URL_TODAY_SEL_TODAY);
}

/*********************     检查更新                   *******************/
void HttpClient::updateClientFinish(QNetworkReply *reply)
{
    MAINWINDOW->readJson(reply, PROTOCOL::URL_UPDATE_CLIENT);
}

/*********************     获取数据                   *******************/
void HttpClient::readJson(QNetworkReply *reply)
{
    mapHttpData.clear();

    if(NULL == reply) return;

    if(reply->error() == QNetworkReply::NoError)
    {
        QByteArray arrayData = reply->readAll();

        QJsonParseError err;
        QJsonDocument jsonDom = QJsonDocument::fromJson(QString(arrayData).toUtf8(), &err);

        if(err.error == QJsonParseError::NoError)
        {
            QJsonObject jsonObject = jsonDom.object();

            if(jsonObject.contains(HTTPKEY::CODE))  mapHttpData[HTTPKEY::CODE] = QString::number(jsonObject.value(HTTPKEY::CODE).toInt());
            if(jsonObject.contains(HTTPKEY::MSG))   mapHttpData[HTTPKEY::MSG]  = jsonObject.value(HTTPKEY::MSG).toString();
            if(jsonObject.contains(HTTPKEY::TOKEN)) publicToken = jsonObject.value(HTTPKEY::TOKEN).toString();
            if(jsonObject.contains(HTTPKEY::USRID)) publicUsrId = QString::number(jsonObject.value(HTTPKEY::USRID).toInt());
        }
    }

    reply->close();
}

/*********************     读取JSon列表                   *******************/
void HttpClient::readJsonList(QJsonObject jsonObject, QString itemName, MapList &mapList)
{
    if(jsonObject.contains(itemName))
    {
        mapList.clear();

        QJsonValue jsonValue = jsonObject.value(itemName);
        QJsonArray jsonArray = jsonValue.toArray();

        for(int i = 0; i < jsonArray.size(); i ++)
        {
            QMap<QString, QString>mapData;

            QJsonObject objectItem = jsonArray.at(i).toObject();
            QStringList stringList = objectItem.keys();

            for(int j = 0; j < stringList.size(); j ++)
            {
                if(!objectItem[stringList[j]].isNull())
                {
                    if(objectItem[stringList[j]].isString())
                    {
                        mapData[stringList[j]] = objectItem[stringList[j]].toString();
                    }
                    else if(objectItem[stringList[j]].isDouble())
                    {
                        mapData[stringList[j]] = QString::number(objectItem[stringList[j]].toDouble());
                    }
                    else
                    {
                        mapData[stringList[j]] = QString::number(objectItem[stringList[j]].toInt());
                    }
                }
            }

            mapList.append(mapData);
        }
    }
}

/*********************     读取单个json                       *******************/
void HttpClient::readJsonMap(QJsonObject jsonObject, QString itemName, Map &mapItem)
{
    if(jsonObject.contains(itemName))
    {
        mapItem.clear();

        QJsonObject objectItem = jsonObject.value(itemName).toObject();

        QStringList stringList = objectItem.keys();

        for(int i = 0; i < stringList.size(); i ++)
        {
            if(!objectItem[stringList[i]].isNull())
            {
                if(objectItem[stringList[i]].isString())
                {
                    mapItem[stringList[i]] = objectItem[stringList[i]].toString();
                }
                else if(objectItem[stringList[i]].isDouble())
                {
                    mapItem[stringList[i]] = QString::number(objectItem[stringList[i]].toDouble());
                }
                else
                {
                    mapItem[stringList[i]] = QString::number(objectItem[stringList[i]].toInt());
                }
            }
        }
    }
}

/************************   组合JSON            ********************/
QString HttpClient::makeJson(QList<QString> data)
{
    QJsonObject jsonTotal;
    QJsonObject jsonData;

    for(int i = 0; i < data.size(); i ++)
    {
        jsonData.insert(QString::number(i), data.at(i));
    }

    jsonTotal.insert("listId", jsonData);

    QJsonDocument document;
    document.setObject(jsonTotal);

    return document.toJson();
}

/************************   组合JSON            ********************/
QString HttpClient::makeJson(MapList mapListData)
{
    QJsonArray  jsonArray;

    for(int i = 0; i < mapListData.size(); i ++)
    {
        QJsonObject jsonData;

        for(auto iter = mapListData.at(i).begin(); iter != mapListData.at(i).end(); iter ++)
        {
            jsonData.insert(iter.key(), iter.value());
        }

        jsonArray.insert(i, jsonData);
    }

    QJsonDocument document;
    document.setArray(jsonArray);

    return document.toJson();
}

/*********************     获取数据                       *******************/
Map HttpClient::getMapHttpData() const
{
    return mapHttpData;
}

/*********************     查找map中的值                   *******************/
QString HttpClient::findMapValue(MapList mapList, QString keyName, QString key)
{
    for(int i = 0; i < mapList.size(); i ++)
    {
        auto iter = mapList.at(i).find(HTTPKEY::NAME);

        if(iter.value() == keyName)
        {
            return mapList.at(i).value(key);
        }
    }

    return NULL;
}
