#ifndef PROTOCOL_H
#define PROTOCOL_H

/***************************************************************
   功能:根据枚举回调函数

   创建人:YYC

   创建时间:2017-11-21
**************************************************************/

namespace PROTOCOL
{
enum MESSAGETYPE
{
    /***************   登录接口   ***************/
    URL_USER_LOGIN    = 0,       //用户登录
    URL_LOGIN_OUT     = 1,       //退出登录
    URL_USER_LIST     = 2,       //管理员列表
    URL_USER_ADD      = 3,       //新增管理员
    URL_USER_EDIT     = 4,       //修改管理员
    URL_USER_DEL      = 5,       //删除管理员


    /***************   权限接口   ***************/
    URL_RULE_LIST  = 10,         //权限列表
    URL_RULE_ADD   = 11,         //添加权限
    URL_RULE_EDIT  = 12,         //修改权限
    URL_RULE_DEL   = 13,         //删除权限


    /***************   用户组接口 （未实现）  ***************/
    URL_GROUP_LIST  = 15,        //用户组列表
    URL_GROUP_ADD   = 16,        //添加用户组
    URL_GROUP_EDIT  = 17,        //修改用户组
    URL_GROUP_DEL   = 18,        //删除用户组

    /***************   原料设置   ***************/
    URL_MAT_LIST       = 20,     //原料列表
    URL_MAT_DETAILS    = 21,     //原料详情
    URL_MAT_IMAGE      = 22,     //下载图片
    URL_ADD_MAT_SHOW   = 23,     //添加原料前显示
    URL_MAT_ADD        = 24,     //添加原料
    URL_CATE_EDIT_SHOW = 25,     //修改分类显示
    URL_MAT_EDIT       = 26,     //修改原料
    URL_MAT_DEL        = 27,     //删除原料提示
    URL_DEL_MAT        = 28,     //删除原料
    URL_FINALLY_CAT    = 29,     //查询最后一级分类
    URL_MAT_EXG_TYPE   = 30,     //原料修改类型
    URL_MAT_EMAIL      = 31,     //导出到邮箱


    /***************   分类接口   ***************/
    URL_MAT_CAT_LIST   = 35,     //查询分类
    URL_MAT_LIST_SHOW  = 36,     //添加分类显示
    URL_CATEGORY_ADD   = 37,     //添加原料分类
    URL_CATEGORY_EDIT  = 38,     //修改原料分类
    URL_CATEGORY_DEL   = 39,     //删除原料分类

    /***************   单位接口   ***************/
    URL_UNIT_LIST      = 40,      //查询单位列表
    URL_ADD_UNIT       = 41,      //添加单位
    URL_DEL_UNIT       = 42,      //删除单位
    URL_SEL_SIDE       = 43,      //副单位显示页

    /***************   仓库接口   ***************/
    URL_WARHOS_LIST       = 45,   //获取仓库列表
    URL_WARHOS_DETAILS    = 46,   //仓库详情
    URL_WARHOS_GOODS_TYPE = 47,   //获取分类
    URL_WARHOS_GOODS_LIST = 48,   //获取商品列表
    URL_WARHOS_ADD        = 49,   //添加仓库
    URL_WARHOS_EDIT       = 50,   //修改仓库
    URL_WARHOS_DEL        = 51,   //删除仓库
    URL_WARHOS_SEARCH     = 52,   //商品搜索框

    /***************   供应商接口   ***************/
    URL_SUP_ADD_SUP        = 55,   //添加供应商
    URL_SUP_ADD_SUP_MAT    = 56,   //添加供应商原料
    URL_SUP_ADD_SUP_CAT    = 57,   //供应商添加类别
    URL_SUP_GET_SUP_CAT    = 58,   //获取所有类别
    URL_SUP_UPDATE_SUP_CAT = 59,   //修改供应商类别名称
    URL_SUP_DEL_SUP_CAT    = 60,   //删除类别
    URL_SUP_GET_SUP_LIST   = 61,   //获取供应商列表
    URL_SUP_DETAILS        = 62,   //获取供应商详情
    URL_SUP_UPDATE_SUP     = 63,   //修改供应商
    URL_SUP_DEL_SUP_MAT    = 64,   //删除供应商原料
    URL_SUP_DEL_SUP        = 65,   //删除供应商
    URL_SUP_SEL_MATERIAL   = 66,   //查询当前供应商供应原料
    URL_SUP_GET_MATERIAL   = 67,   //查询当前供应商可供应的原料
    URL_SUP_EXTEND         = 68,   //导出到邮箱

    /***************   模板接口   ***************/
    URL_TEM_MAT_LIST       = 70,   //获取所有原料列表
    URL_TEM_ADD_TEM        = 71,   //添加模板
    URL_TEM_ADD_MAT        = 72,   //添加原料
    URL_TEM_LIST           = 73,   //获取模板列表
    URL_TEM_DETAILS        = 74,   //模板详情
    URL_TEM_UPDATE         = 75,   //修改模板
    URL_TEM_DEL_MAT        = 76,   //删除原料
    URL_TEM_DELETE         = 77,   //删除模板列表
    URL_TEM_GET_MAT_LIST   = 78,   //根据分类获取原料模板
    URL_TEM_MAT_TYPE_LIST  = 79,   //获取原料分类

    /***************  菜品原料配比接口  ***************/
    URL_BOM_FOOD_LIST        = 85,   //显示所有菜品分类和菜品
    URL_BOM_FOOD_GETID       = 86,   //查询菜品信息
    URL_BOM_MAT_OLD          = 87,   //查询已添加原料
    URL_BOM_MAT_DEL          = 88,   //删除菜品原料
    URL_BOM_MAT_UPDATE       = 89,   //修改菜品原料
    URL_BOM_MAT_ADD          = 90,   //添加菜品原料
    URL_BOM_MAT_NEW          = 91,   //查询新添加原料页
    URL_BOM_SAVE_UPDATE      = 92,   //修改菜品
    URL_BOM_MAT_LIST         = 93,   //获取原料列表

    /***************  采购订单接口  ***************/
    URL_PUR_SEL_ALL          = 95,   //显示所有采购订单
    URL_PUR_INDENT           = 96,   //添加采购订单页
    URL_PUR_ADD_INDENT       = 97,   //添加采购订单
    URL_PUR_SEL              = 98,   //查询采购订单信息
    URL_PUR_GET_MAT          = 100,  //查询供应商原料信息
    URL_PUR_UPDATE           = 101,  //修改采购订单
    URL_PUR_ADD_MAT          = 102,  //添加采购原料
    URL_PUR_DEL_MAT          = 103,  //删除采购原料
    URL_PUR_SEL_MAT          = 104,  //查询采购原料信息
    URL_PUR_UPDATE_MAT       = 105,  //修改采购原料
    URL_PUR_EXAMINE          = 106,  //确认供应商和原料
    URL_PUR_AFFIRMPAGE       = 107,  //确认采购页
    URL_PUR_AFFIRM           = 108,  //确认采购
    URL_PUR_COPY             = 109,  //历史采购订单复制
    URL_PUR_DEL              = 110,  //删除订单
    URL_PUR_SEL_TEMPLATE     = 111,  //查询所有采购模板
    URL_PUR_NUMBER           = 112,  //设置采购数量页
    URL_PUR_TEMPLATE_ADD     = 113,  //通过模板生成采购订单
    URL_PUR_SEL_DISPOSE      = 114,  //查询操作记录
    URL_PUR_SELECT_PAGE      = 115,  //筛选采购单页
    URL_PUR_SELECT           = 116,  //筛选采购单结果
    URL_PUR_EXTEND           = 117,  //导出采购订单

    /***************  采购入库接口  ***************/
    URL_STO_SEL            = 120,   //显示所有入库订单
    URL_STO_GET_ID         = 121,   //查询单个入库单
    URL_STO_SEL_DATA       = 122,   //查询入库单信息
    URL_STO_SEL_MAT        = 123,   //查询供应商原料信息
    URL_STO_ADD_MAT        = 124,   //添加原料
    URL_STO_GET_MAT        = 125,   //查询原料
    URL_STO_UPDATE_MAT     = 126,   //修改原料
    URL_STO_DEL_MAT        = 127,   //删除原料
    URL_STO_SEL_SIDE       = 128,   //显示副仓库页
    URL_STO_JUDGE          = 129,   //判断仓库是否可以设置分仓
    URL_STO_UPDATE_SIDE    = 130,   //添加副仓库
    URL_STO_DEL_SIDE       = 131,   //删除副仓库
    URL_STO_COPY_ORDER     = 132,   //历史采购订单导入
    URL_STO_ADD_STO_PAGE   = 133,   //添加入库单页面
    URL_STO_ADD            = 134,   //添加入库单
    URL_STO_UPDATE         = 135,   //修改入库单
    URL_STO_REFUSE         = 136,   //拒绝收货
    URL_STO_CONFIRM_PAGE   = 137,   //确认收货页
    URL_STO_CONFIRM        = 138,   //确认收货
    URL_STO_DEL            = 139,   //删除入库单
    URL_STO_RECONFIRM      = 140,   //反确认
    URL_STO_DEL_PAGE       = 141,   //删除原料页
    URL_STO_SELECT_PUR     = 142,   //查询采购订单
    URL_STO_EXPORT_EMAIL   = 143,   //导出到邮箱
    URL_STO_SEL_DISPOSE    = 144,   //查询操作记录
    URL_STO_SELECT_PAGE    = 145,   //筛选入库单页
    URL_STO_SELECT         = 146,   //筛选入库单结果
    URL_STO_FINISH         = 147,   //入库完成
    URL_STO_FINISH_HINT    = 148,   //入库提示

    /***************  采购退货接口  ***************/
    URL_RETURN_SEL          = 150,   //显示所有退货订单
    URL_RETURN_DATA         = 151,   //查询退货单信息
    URL_RETURN_UPDATE       = 152,   //修改退货单
    URL_RETURN_ADD_PAGE     = 153,   //添加退货订单页
    URL_RETURN_ADD          = 154,   //添加退货单
    URL_RETURN_SEL_MAT      = 155,   //查询供应商原料信息
    URL_RETURN_ADD_MAT      = 156,   //添加原料
    URL_RETURN_GET_MAT      = 157,   //查询原料
    URL_RETURN_UPDATE_MAT   = 158,   //修改原料
    URL_RETURN_DEL_MAT      = 159,   //删除原料
    URL_RETURN_SEL_SIDE     = 160,   //显示副仓库页
    URL_RETURN_JUDGE        = 161,   //判断仓库是否可以设置分仓
    URL_RETURN_UPDATE_SIDE  = 162,   //添加副仓库
    URL_RETURN_DEL_SIDE     = 163,   //删除副仓库
    URL_RETURN_COPY_ORDER   = 164,   //历史退货单导入
    URL_RETURN_CONFIRM      = 165,   //确认退货
    URL_RETURN_DEL_STO      = 166,   //删除退货单
    URL_RETURN_SEL_DISPOSE  = 167,   //查询操作记录
    URL_RETURN_DEL_MAT_SHOW = 168,   //批量删除原料页
    URL_RETURN_SELECT_PAGE  = 169,   //筛选退货单页
    URL_RETURN_SELECT       = 170,   //筛选退货单结果
    URL_RETURN_EXTEND       = 171,   //导出退货单

    /***************  安全库存采购接口  ***************/
    URL_SAFETY_SEL          = 175,   //显示已设置上下限原料
    URL_SAFETY_AFFIRM       = 176,   //确认采购

    /***************  原料供应商接口  ***************/
    URL_DEFAULT_SEL          = 180,   //显示所有原料页面
    URL_DEFAULT_GET_MAT      = 181,   //原料详情页
    URL_DEFAULT_UPDATE_SUP   = 182,   //修改默认供应商
    URL_DEFAULT_GET_SUP      = 183,   //获取原料供应商

    /***************  实时库存查询接口  ***************/
    URL_TIME_MAT_LIST         = 185,   //实时库存查询列表
    URL_TIME_SEL_MAT          = 186,   //查询原料库存详情
    URL_TIME_SEND_EMAIL       = 187,   //导出实时库存

    /***************  库存调整接口  ***************/
    URL_ADJ_ADD_INV           = 190,   //添加调整单
    URL_ADJ_TYPE              = 191,   //获取调整单类型
    URL_ADJ_GET_MAT           = 192,   //获取原料
    URL_ADJ_ADD_MAT           = 193,   //添加原料
    URL_ADJ_GET_INV_LIST      = 194,   //获取库存调整列表
    URL_ADJ_GET_DET           = 195,   //获取调整单详情
    URL_ADJ_GET_MAT_DET       = 196,   //获取原料详情
    URL_ADJ_UPDATE_DASIC      = 197,   //修改调整单的基本信息
    URL_ADJ_UPDATE_MAT        = 198,   //修改调整原料
    URL_ADJ_ADD_REASON        = 199,   //添加调整原因
    URL_ADJ_GET_REASON        = 200,   //获取调整原因列表
    URL_ADJ_DEL_REASON        = 201,   //删除调整原因
    URL_ADJ_DEL_MAT           = 202,   //删除调整原料
    URL_ADJ_SEND_EMAIL        = 203,   //导出库存调整单
    URL_ADJ_WAREHOUSE         = 204,   //获取仓库列表
    URL_ADJ_DEL               = 205,   //删除调整单
    URL_ADJ_SEL_DISPOSE       = 206,   //查询操作记录
    URL_ADJ_PRESENT           = 207,   //提交
    URL_ADJ_SELECT_PAGE       = 208,   //筛选调整单页
    URL_ADJ_SELECT            = 209,   //筛选调整单结果
    URL_ADJ_CONVERT           = 210,   //单位转换

    /***************  仓库盘存接口  ***************/
    URL_CHECK_SEL_ALL         = 215,   //显示所有仓库盘存单
    URL_CHECK_SEL             = 216,   //查询盘存单信息
    URL_CHECK_ADD_PAGE        = 217,   //添加盘存单页
    URL_CHECK_ADD             = 218,   //添加盘存单
    URL_CHECK_UPDATE          = 219,   //修改盘存单
    URL_CHECK_MAT_PAGE        = 220,   //显示盘存原料页
    URL_CHECK_ADD_MAT_PAGE    = 221,   //添加盘存原料页
    URL_CHECK_ADD_MAT         = 222,   //添加盘存原料
    URL_CHECK_UPDATE_MAT_PAGE = 223,   //修改盘存原料页
    URL_CHECK_UPDATE_MAT      = 224,   //修改盘存原料
    URL_CHECK_UNIT_UPDATE_NUM = 225,   //修改单位，改变原料数量
    URL_CHECK_UPDATE_NUM      = 226,   //修改盘存原料数量（批量修改）
    URL_CHECK_CANCEL          = 227,   //取消盘存
    URL_CHECK_DEL             = 228,   //删除盘存
    URL_CHECK_IMPORT          = 229,   //历史盘存单导入
    URL_CHECK_AFFIRM          = 230,   //确认盘存
    URL_CHECK_SEND_EMAIL      = 231,   //导出仓库盘存单
    URL_CHECK_SEL_DISPOSE     = 232,   //查询操作记录
    URL_CHECK_DEL_MAT         = 233,   //删除盘存原料
    URL_CHECK_SELECT_PAGE     = 234,   //筛选盘存单页
    URL_CHECK_SELECT          = 235,   //筛选盘存单结果

    /***************  库存变更记录接口  ***************/
    URL_CHANCE_SEL_MAT        = 240,   //查询页面
    URL_CHANCE_MAT_LIST       = 241,   //查询结果页
    URL_CHANCE_ALL_MAT        = 242,   //查询结果页
    URL_CHANCE_GET_MAT        = 243,   //原料单个变更记录
    URL_CHANCE_EXTEND         = 244,   //导出变更记录

    /***************  成本调价接口  ***************/
    URL_COST_SEL_ALL          = 250,   //查询所有调价单
    URL_COST_PRICE            = 251,   //入库原料成本价列表
    URL_COST_ADD              = 252,   //添加调价单
    URL_COST_SEL_MAT          = 253,   //显示调价原料页
    URL_COST_ADD_MAT          = 254,   //添加调价原料
    URL_COST_SEL              = 255,   //查询调价单信息
    URL_COST_UPDATE           = 256,   //修改调价单
    URL_COST_DEL              = 257,   //删除调价单
    URL_COST_GET_MAT          = 258,   //查询调价原料信息
    URL_COST_UPDATE_MAT       = 259,   //修改调价原料
    URL_COST_UPDATE_PAGE      = 260,   //批量修改页
    URL_COST_UPDATE_ALL_MAT   = 261,   //批量修改
    URL_COST_DEL_MAT          = 262,   //删除调价原料
    URL_COST_PRESENT          = 263,   //提交调价单（提交过后不能删除）
    URL_COST_AFFIRM           = 264,   //确认调价
    URL_COST_SEL_DISPOSE      = 265,   //查询操作记录
    URL_COST_SELECT_PAGE      = 266,   //筛选调价单页
    URL_COST_SELECT           = 267,   //筛选调价单结果

    /***************  库存上下限接口  ***************/
    URL_REST_SEL_MAT          = 270,   //显示所有原料页面
    URL_REST_GET_MAT          = 271,   //设置原料上下限页面
    URL_REST_UPDATE_MAT       = 272,   //修改原料上下限支持批量修改

    /***************  店内调拨接口  ***************/
    URL_ALLOT_SEL_ALL          = 275,   //查询所有调拨单
    URL_ALLOT_ADD_PAGE         = 276,   //添加调拨单页
    URL_ALLOT_ADD              = 277,   //添加调拨单
    URL_ALLOT_SEL              = 278,   //查询调拨单
    URL_ALLOT_UPDATE           = 279,   //修改调拨单
    URL_ALLOT_DEL              = 280,   //删除调拨单
    URL_ALLOT_SEL_MAT          = 281,   //添加调拨原料页
    URL_ALLOT_ADD_MAT          = 282,   //添加调拨原料
    URL_ALLOT_GET_MAT          = 283,   //查询调拨原料
    URL_ALLOT_UPDATE_MAT       = 284,   //修改调拨原料
    URL_ALLOT_DEL_MAT          = 285,   //删除调拨原料
    URL_ALLOT_UPDATE_ALL_PAGE  = 286,   //批量修改页
    URL_ALLOT_UPDATE_ALL_MAT   = 287,   //批量修改
    URL_ALLOT_PRESEND          = 288,   //确认提交
    URL_ALLOT_CANCEL           = 289,   //拒绝调拨
    URL_ALLOT_AFFIRM           = 290,   //调拨完成
    URL_ALLOT_RECONFIRM        = 291,   //反确认
    URL_ALLOT_SEND_EMAIL       = 292,   //导出调拨单
    URL_ALLOT_SEL_DISPOSE      = 293,   //查询操作记录
    URL_ALLOT_SELECT_PAGE      = 294,   //筛选调拨单页
    URL_ALLOT_SELECT           = 295,   //筛选调拨单结果

    /***************  报表中心接口  ***************/
    URL_STATE_STO_PAGE         = 300,   //采购入库明细报表--查询页
    URL_STATE_STORAGE          = 301,   //采购入库明细报表
    URL_STATE_STORAGE_EXTEND   = 302,   //导出采购入库明细报表
    URL_STATE_STO_GATHER_PAGE  = 303,   //采购入库汇总报表--查询页
    URL_STATE_STORAGE_GATHER   = 304,   //采购入库汇总报表
    URL_STATE_STO_GAT_EXTEND   = 305,   //导出采购入库汇总报表
    URL_STATE_RET_PAGE         = 306,   //采购退货明细报表--查询页
    URL_STATE_RETURNS          = 307,   //采购退货明细报表
    URL_STATE_RETURNS_EXTEND   = 308,   //导出采购退货明细报表
    URL_STATE_ADJ_PAGE         = 309,   //调整单明细报表--查询页
    URL_STATE_ADJUST           = 310,   //调整单明细报表
    URL_STATE_ADJUST_EXTEND    = 311,   //导出调整单明细报表
    URL_STATE_CHECK_PAGE       = 312,   //盘存单明细报表--查询页
    URL_STATE_CHECK            = 313,   //盘存单明细报表
    URL_STATE_CHECK_EXTEND     = 314,   //导出盘存单明细报表
    URL_STATE_CHK_GATHER_PAGE  = 315,   //盘存单汇总报表--查询页
    URL_STATE_CHECK_GATHER     = 316,   //盘存单汇总报表
    URL_STATE_CHK_GAT_EXTEND   = 317,   //导出盘存单汇总报表
    URL_STATE_SUP_PAGE         = 318,   //供应商供货明细报表--查询页
    URL_STATE_SUPPLIER         = 319,   //供应商供货明细报表
    URL_STATE_SUPPLIER_EXTEND  = 320,   //供应商供货明细报表
    URL_STATE_SUP_GATHER_PAGE  = 321,   //供应商供货汇总报表--查询页
    URL_STATE_SUP_GATHER       = 322,   //供应商供货汇总报表
    URL_STATE_SUP_GAT_EXTEND   = 323,   //供应商供货汇总报表
    URL_STATE_SELECT_MAT_PAGE  = 324,   //原料销售报表--查询页
    URL_STATE_SELECT_MAT       = 325,   //原料销售报表
    URL_STATE_SEL_MAT_EXTEND   = 326,   //原料销售报表-导出

    /***************  支出结算接口  ***************/
    URL_ACCOUNT_ALL_NUMBER     = 330,   //显示所有入库和退货单
    URL_ACCOUNT_STO_PAGE       = 331,   //入库单修改页面
    URL_ACCOUNT_RET_PAGE       = 332,   //退货单修改页面
    URL_ACCOUNT_AFFIRM_PRO     = 333,   //确认对账
    URL_ACCOUNT_AFFIRM_ACC     = 334,   //确认结算
    URL_ACCOUNT_SEL_DISPOSE    = 335,   //查询操作记录
    URL_ACCOUNT_STO_MAT_INFO   = 336,   //查询入库原料信息
    URL_ACCOUNT_RET_MAT_INFO   = 337,   //查询退货原料信息
    URL_ACCOUNT_FILTRATE_PAGE  = 338,   //筛选页
    URL_ACCOUNT_FILTRATE       = 339,   //查询
    URL_ACCOUNT_EXTEND         = 340,   //导出


    /***************  销售接口      ***************/
    URL_TODAY_SEL_TODAY        = 345,   //当天营业数据

    /***************  更新接口      ***************/
    URL_UPDATE_CLIENT           = 350,   //检查更新

    URLMAX,
};
}

#endif // PROTOCOL_H
