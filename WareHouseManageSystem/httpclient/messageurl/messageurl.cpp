#include "messageurl.h"
#include "global/globaldef.h"
#include <QDebug>

MessageUrl * MessageUrl::instance = new MessageUrl();

/*********************      构造函数            *******************/
MessageUrl::MessageUrl()
{
    this->initStandardMsgUrl();
}

/*********************      初始化函数            *******************/
void MessageUrl::initMessageUrl(QString strDomain)
{
    QString strPrefix = strDomain + "public/index/";

    urlList = new QString[MESSAGESIZE];

    /***************   登录接口   ***************/
    urlList[PROTOCOL::URL_USER_LOGIN]   = strPrefix + "Login/Login";
    urlList[PROTOCOL::URL_LOGIN_OUT]    = strPrefix + "login/loginOut?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_USER_LIST]    = strPrefix + "user/userList?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_USER_ADD]     = strPrefix + "user/userAdd?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_USER_EDIT]    = strPrefix + "user/userEdit?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_USER_DEL]     = strPrefix + "user/userDel?token=%1&user_id=%2";

    /***************   权限接口   ***************/
    urlList[PROTOCOL::URL_RULE_LIST]    = strPrefix + "Rule/ruleList";
    urlList[PROTOCOL::URL_RULE_ADD]     = strPrefix + "Rule/ruleAdd?name=%1&uri=%2";
    urlList[PROTOCOL::URL_RULE_EDIT]    = strPrefix + "Rule/ruleEdit?rule_id=%1&name=%2&uri=%3";
    urlList[PROTOCOL::URL_RULE_DEL]     = strPrefix + "Rule/ruleDel?rule_id=%1";

    /***************   用户组接口   ***************/
    urlList[PROTOCOL::URL_GROUP_LIST]   = strPrefix + "Group/groupList";
    urlList[PROTOCOL::URL_GROUP_ADD]    = strPrefix + "Group/groupAdd?title=%1&status=%2&rule_ids=%3";
    urlList[PROTOCOL::URL_GROUP_EDIT]   = strPrefix + "Group/groupEdit?group_id=%1&title=%2&status=%3&rule_ids=%4";
    urlList[PROTOCOL::URL_GROUP_DEL]    = strPrefix + "Group/groupDel?group_id=%1";

    /***************   原料设置   ***************/
    urlList[PROTOCOL::URL_MAT_LIST]       = strPrefix + "Material/materialList?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_MAT_DETAILS]    = strPrefix + "Material/materialDetails?material_id=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_MAT_IMAGE]      = strDomain + "%1";
    urlList[PROTOCOL::URL_ADD_MAT_SHOW]   = strPrefix + "material/materialAddList?material_name=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_MAT_ADD]        = strPrefix + "material/materialAdd?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_CATE_EDIT_SHOW] = strPrefix + "info/categoryEditPage?category_id=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_MAT_EDIT]       = strPrefix + "material/materialEdit?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_MAT_DEL]        = strPrefix + "material/materialDel?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_DEL_MAT]        = strPrefix + "material/delMaterial?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_FINALLY_CAT]    = strPrefix + "info/finallyCategory?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_MAT_EXG_TYPE]   = strPrefix + "material/updateCategory?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_MAT_EMAIL]      = strPrefix + "material/sendEmail?token=%1&user_id=%2";

    /***************   分类接口   ***************/
    urlList[PROTOCOL::URL_MAT_CAT_LIST]   = strPrefix + "info/categoryList?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_MAT_LIST_SHOW]  = strPrefix + "info/categoryList?token=%1&user_id=%2&num=1";
    urlList[PROTOCOL::URL_CATEGORY_ADD]   = strPrefix + "info/categoryAdd?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_CATEGORY_EDIT]  = strPrefix + "info/categoryEdit?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_CATEGORY_DEL]   = strPrefix + "info/categoryDel?token=%1&user_id=%2";

    /***************   单位接口   ***************/
    urlList[PROTOCOL::URL_UNIT_LIST]     = strPrefix + "unit/unitList?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_ADD_UNIT]      = strPrefix + "unit/addUnit?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_DEL_UNIT]      = strPrefix + "unit/delUnit?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_SEL_SIDE]      = strPrefix + "material/selSide?unit_id=%1&token=%2&user_id=%3";

    /***************   仓库接口   ***************/
    urlList[PROTOCOL::URL_WARHOS_LIST]       = strPrefix + "Warehouse/getWarehouseList?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_WARHOS_DETAILS]    = strPrefix + "Warehouse/WarehouseDetails?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_WARHOS_GOODS_TYPE] = strPrefix + "Warehouse/getClassification?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_WARHOS_GOODS_LIST] = strPrefix + "Warehouse/getGoodsList?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_WARHOS_ADD]        = strPrefix + "Warehouse/addWarehouse?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_WARHOS_EDIT]       = strPrefix + "Warehouse/updataWarehouse?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_WARHOS_DEL]        = strPrefix + "Warehouse/deleteWarehouse?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_WARHOS_SEARCH]     = strPrefix + "Search/warehouseSearch?token=%1&user_id=%2";

    /***************   供应商接口   ***************/
    urlList[PROTOCOL::URL_SUP_ADD_SUP]        = strPrefix + "Supplier/addSupplier?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_SUP_ADD_SUP_MAT]    = strPrefix + "Supplier/addSupplierMaterial?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_SUP_ADD_SUP_CAT]    = strPrefix + "Supplier/addSupplierCategory?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_SUP_GET_SUP_CAT]    = strPrefix + "Supplier/getSupplierCategory?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_SUP_UPDATE_SUP_CAT] = strPrefix + "Supplier/updateSupplierCategory?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_SUP_DEL_SUP_CAT]    = strPrefix + "Supplier/deleteSupplierCategory?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_SUP_GET_SUP_LIST]   = strPrefix + "Supplier/getSupplierList?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_SUP_DETAILS]        = strPrefix + "Supplier/supplierDetails?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_SUP_UPDATE_SUP]     = strPrefix + "Supplier/updateSupplier?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_SUP_DEL_SUP_MAT]    = strPrefix + "Supplier/deleteSupplierMaterial?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_SUP_DEL_SUP]        = strPrefix + "Supplier/deleteSupplier?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_SUP_SEL_MATERIAL]   = strPrefix + "Supplier/selMaterial?supplier_id=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_SUP_GET_MATERIAL]   = strPrefix + "Supplier/getMaterial?supplier_id=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_SUP_EXTEND]         = strPrefix + "Supplier/sendEmail?token=%1&user_id=%2";

    /***************   模板接口   ***************/
    urlList[PROTOCOL::URL_TEM_MAT_LIST]       = strPrefix + "template/materialList?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_TEM_ADD_TEM]        = strPrefix + "template/addTemplate?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_TEM_ADD_MAT]        = strPrefix + "template/addMaterial?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_TEM_LIST]           = strPrefix + "template/templateList?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_TEM_DETAILS]        = strPrefix + "template/templateDetails?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_TEM_UPDATE]         = strPrefix + "template/updataTempalte?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_TEM_DEL_MAT]        = strPrefix + "template/deleteMateria?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_TEM_DELETE]         = strPrefix + "template/deleteTemplate?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_TEM_GET_MAT_LIST]   = strPrefix + "template/getMateriaList?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_TEM_MAT_TYPE_LIST]  = strPrefix + "info/categoryList?token=%1&user_id=%2";

    /***************   菜品原料配比接口   ***************/
    urlList[PROTOCOL::URL_BOM_FOOD_LIST]    = strPrefix + "bom/foodList?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_BOM_FOOD_GETID]   = strPrefix + "bom/foodGetId?food_id=%1&pid=%2&food_name=%3&token=%4&user_id=%5";
    urlList[PROTOCOL::URL_BOM_MAT_OLD]      = strPrefix + "bom/foodGetOldMaterial?bom_material_id=%1&food_id=%2&category_id=%3&token=%4&user_id=%5";
    urlList[PROTOCOL::URL_BOM_MAT_DEL]      = strPrefix + "bom/foodDelMaterial?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_BOM_MAT_UPDATE]   = strPrefix + "bom/foodUpdateMaterial?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_BOM_MAT_ADD]      = strPrefix + "bom/foodAddMaterial?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_BOM_MAT_NEW]      = strPrefix + "bom/foodGetNewMaterial?bom_id=%1&material_id=%2&token=%3&user_id=%4";
    urlList[PROTOCOL::URL_BOM_SAVE_UPDATE]  = strPrefix + "bom/foodAddId?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_BOM_MAT_LIST]     = strPrefix + "Material/materialList?token=%1&user_id=%2";

    /***************  采购订单接口  ***************/
    urlList[PROTOCOL::URL_PUR_SEL_ALL]      = strPrefix + "purchase/selAllPurchase?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_PUR_INDENT]       = strPrefix + "purchase/PurchaseIndent?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_PUR_ADD_INDENT]   = strPrefix + "purchase/addPurchaseIndent?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_PUR_SEL]          = strPrefix + "purchase/selPurchase?purchase_number=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_PUR_GET_MAT]      = strPrefix + "purchase/GetMaterial?purchase_number=%1&supplier_id=%2&token=%3&user_id=%4";
    urlList[PROTOCOL::URL_PUR_UPDATE]       = strPrefix + "purchase/updatePurchase?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_PUR_ADD_MAT]      = strPrefix + "purchase/addMaterial?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_PUR_DEL_MAT]      = strPrefix + "purchase/delMaterial?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_PUR_SEL_MAT]      = strPrefix + "purchase/selMaterial?material_id=%1&purchase_number=%2&purchase_state=%3&token=%4&user_id=%5";
    urlList[PROTOCOL::URL_PUR_UPDATE_MAT]   = strPrefix + "purchase/updateMaterial?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_PUR_EXAMINE]      = strPrefix + "purchase/examine?supplier_id=%1&material_id=%2&token=%3&user_id=%4";
    urlList[PROTOCOL::URL_PUR_AFFIRMPAGE]   = strPrefix + "purchase/affirmPage?purchase_number=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_PUR_AFFIRM]       = strPrefix + "purchase/affirm?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_PUR_COPY]         = strPrefix + "purchase/copyPurchase?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_PUR_DEL]          = strPrefix + "purchase/delPurchase?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_PUR_SEL_TEMPLATE] = strPrefix + "purchase/selTemplate?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_PUR_NUMBER]       = strPrefix + "purchase/purchaseNumber?template_id=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_PUR_TEMPLATE_ADD] = strPrefix + "purchase/templateAddPurchase?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_PUR_SEL_DISPOSE]  = strPrefix + "dispose/selDispose?number=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_PUR_SELECT_PAGE]  = strPrefix + "purchase/filtrate_page?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_PUR_SELECT]       = strPrefix + "purchase/filtrate?state_id=%1&supplier_id=%2&time=%3&token=%4&user_id=%5";
    urlList[PROTOCOL::URL_PUR_EXTEND]       = strPrefix + "purchase/sendEmail?token=%1&user_id=%2";

    /***************  采购入库接口  ***************/
    urlList[PROTOCOL::URL_STO_SEL]          = strPrefix + "storage/selStorage?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_STO_GET_ID]       = strPrefix + "storage/selStorageGetId?storage_id=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_STO_SEL_DATA]     = strPrefix + "storage/selStorageData?storage_id=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_STO_SEL_MAT]      = strPrefix + "storage/selMaterial?storage_number=%1&supplier_id=%2&token=%3&user_id=%4";
    urlList[PROTOCOL::URL_STO_ADD_MAT]      = strPrefix + "storage/addMaterial?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_STO_GET_MAT]      = strPrefix + "storage/getMaterial?storage_material_id=%1&storage_state=%2&warehouse_id=%3&token=%4&user_id=%5";
    urlList[PROTOCOL::URL_STO_UPDATE_MAT]   = strPrefix + "storage/updateMaterial?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_STO_DEL_MAT]      = strPrefix + "storage/delMaterial?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_STO_SEL_SIDE]     = strPrefix + "storage/selSideWarehouse?unit_name=%1&number=%2&total_money=%3&storage_material_id=%4&token=%5&user_id=%6";
    urlList[PROTOCOL::URL_STO_JUDGE]        = strPrefix + "storage/judge?storage_material_id=%1&warehouse_id=%2&token=%3&user_id=%4";
    urlList[PROTOCOL::URL_STO_UPDATE_SIDE]  = strPrefix + "storage/updateSideWarehouse?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_STO_DEL_SIDE]     = strPrefix + "storage/delSideWarehouse?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_STO_COPY_ORDER]   = strPrefix + "storage/copyOrder?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_STO_ADD_STO_PAGE] = strPrefix + "storage/addStorage_page?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_STO_ADD]          = strPrefix + "storage/addStorage?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_STO_UPDATE]       = strPrefix + "storage/updateStorage?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_STO_REFUSE]       = strPrefix + "storage/refuse?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_STO_CONFIRM_PAGE] = strPrefix + "storage/checkout_page?storage_number=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_STO_CONFIRM]      = strPrefix + "storage/checkout?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_STO_DEL]          = strPrefix + "storage/delStorage?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_STO_RECONFIRM]    = strPrefix + "storage/reconfirm?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_STO_DEL_PAGE]     = strPrefix + "storage/delMaterial_page?storage_number=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_STO_SELECT_PUR]   = strPrefix + "purchase/selAllPurchase?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_STO_EXPORT_EMAIL] = strPrefix + "storage/sendEmail?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_STO_SEL_DISPOSE]  = strPrefix + "dispose/selDispose?number=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_STO_SELECT_PAGE]  = strPrefix + "storage/filtrate_page?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_STO_SELECT]       = strPrefix + "storage/filtrate?state_id=%1&supplier_id=%2&warehouse_id=%3&time=%4&token=%5&user_id=%6";
    urlList[PROTOCOL::URL_STO_FINISH]       = strPrefix + "storage/confirm_receipt?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_STO_FINISH_HINT]  = strPrefix + "storage/storage_hint?token=%1&user_id=%2";

    /***************  采购退货接口  ***************/
    urlList[PROTOCOL::URL_RETURN_SEL]          = strPrefix + "returns/selReturns?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_RETURN_DATA]         = strPrefix + "returns/selReturnsData?returns_id=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_RETURN_UPDATE]       = strPrefix + "returns/updatereturns?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_RETURN_ADD_PAGE]     = strPrefix + "returns/addReturns_page?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_RETURN_ADD]          = strPrefix + "returns/addReturns?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_RETURN_SEL_MAT]      = strPrefix + "returns/selMaterial?returns_number=%1&supplier_id=%2&token=%3&user_id=%4";
    urlList[PROTOCOL::URL_RETURN_ADD_MAT]      = strPrefix + "returns/addMaterial?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_RETURN_GET_MAT]      = strPrefix + "returns/getMaterial?returns_material_id=%1&returns_state=%2&warehouse_id=%3&token=%4&user_id=%5";
    urlList[PROTOCOL::URL_RETURN_UPDATE_MAT]   = strPrefix + "returns/updateMaterial?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_RETURN_DEL_MAT]      = strPrefix + "returns/delMaterial?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_RETURN_SEL_SIDE]     = strPrefix + "returns/selSideWarehouse?unit_name=%1&number=%2&total_money=%3&returns_material_id=%4&token=%5&user_id=%6";
    urlList[PROTOCOL::URL_RETURN_JUDGE]        = strPrefix + "returns/judge?returns_material_id=%1&warehouse_id=%2&token=%3&user_id=%4";
    urlList[PROTOCOL::URL_RETURN_UPDATE_SIDE]  = strPrefix + "returns/updateSideWarehouse?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_RETURN_DEL_SIDE]     = strPrefix + "returns/delSideWarehouse?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_RETURN_COPY_ORDER]   = strPrefix + "returns/copyOrder?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_RETURN_CONFIRM]      = strPrefix + "returns/confirm_receipt?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_RETURN_DEL_STO]      = strPrefix + "returns/delReturns?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_RETURN_SEL_DISPOSE]  = strPrefix + "dispose/selDispose?number=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_RETURN_DEL_MAT_SHOW] = strPrefix + "returns/delMaterial_page?returns_number=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_RETURN_SELECT_PAGE]  = strPrefix + "returns/filtrate_page?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_RETURN_SELECT]       = strPrefix + "returns/filtrate?state_id=%1&supplier_id=%2&time=%3&token=%4&user_id=%5";
    urlList[PROTOCOL::URL_RETURN_EXTEND]       = strPrefix + "returns/sendEmail?token=%1&user_id=%2";

    /***************  安全库存采购接口  ***************/
    urlList[PROTOCOL::URL_SAFETY_SEL]        = strPrefix + "safety/selMaterial?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_SAFETY_AFFIRM]     = strPrefix + "safety/affirm?token=%1&user_id=%2";

    /***************  原料供应商接口  ***************/
    urlList[PROTOCOL::URL_DEFAULT_SEL]        = strPrefix + "Default_supplier/selMaterial?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_DEFAULT_GET_MAT]    = strPrefix + "Default_supplier/getMaterial?material_id=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_DEFAULT_UPDATE_SUP] = strPrefix + "Default_supplier/updateSupplier?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_DEFAULT_GET_SUP]    = strPrefix + "Supplier/getSupplierList?token=%1&user_id=%2";

    /***************  实时库存查询接口  ***************/
    urlList[PROTOCOL::URL_TIME_MAT_LIST]      = strPrefix + "timeinventory/warehouseMaterialList?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_TIME_SEL_MAT]       = strPrefix + "timeinventory/selWarehouseMaterial?material_id=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_TIME_SEND_EMAIL]    = strPrefix + "timeinventory/sendEmail?token=%1&user_id=%2";

    /***************  库存调整接口  ***************/
    urlList[PROTOCOL::URL_ADJ_ADD_INV]      = strPrefix + "Adjustment/addInventory?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_ADJ_TYPE]         = strPrefix + "Adjustment/AdjustmentType?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_ADJ_GET_MAT]      = strPrefix + "Adjustment/getMaterial?odd_numbers=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_ADJ_ADD_MAT]      = strPrefix + "Adjustment/addMaterial?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_ADJ_GET_INV_LIST] = strPrefix + "Adjustment/getInventoryList?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_ADJ_GET_DET]      = strPrefix + "Adjustment/getDetails?odd_numbers=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_ADJ_GET_MAT_DET]  = strPrefix + "Adjustment/getMaterialDetails?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_ADJ_UPDATE_DASIC] = strPrefix + "Adjustment/updataDasic?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_ADJ_UPDATE_MAT]   = strPrefix + "Adjustment/updataMaterial?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_ADJ_ADD_REASON]   = strPrefix + "Adjustment/addReason?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_ADJ_GET_REASON]   = strPrefix + "Adjustment/getReason?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_ADJ_DEL_REASON]   = strPrefix + "Adjustment/deleteReason?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_ADJ_DEL_MAT]      = strPrefix + "Adjustment/deleteMaterial?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_ADJ_SEND_EMAIL]   = strPrefix + "Adjustment/sendEmail?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_ADJ_WAREHOUSE]    = strPrefix + "Warehouse/getWarehouseList?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_ADJ_DEL]          = strPrefix + "Adjustment/deleteAdjustment?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_ADJ_SEL_DISPOSE]  = strPrefix + "dispose/selDispose?number=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_ADJ_PRESENT]      = strPrefix + "Adjustment/present?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_ADJ_SELECT_PAGE]  = strPrefix + "Adjustment/filtrate_page?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_ADJ_SELECT]       = strPrefix + "Adjustment/filtrate?state_id=%1&type_id=%2&warehouse_id=%3&time=%4&token=%5&user_id=%6";
    urlList[PROTOCOL::URL_ADJ_CONVERT]      = strPrefix + "Adjustment/conversion?material_id=%1&warehouse_id=%2&unit_id=%3&number=%4&token=%5&user_id=%6";

    /***************  仓库盘存接口  ***************/
    urlList[PROTOCOL::URL_CHECK_SEL_ALL]         = strPrefix + "check/selCheckAll?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_CHECK_SEL]             = strPrefix + "check/selCheck?warehouse_check_id=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_CHECK_ADD_PAGE]        = strPrefix + "check/addCheck_page?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_CHECK_ADD]             = strPrefix + "check/addCheck?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_CHECK_UPDATE]          = strPrefix + "check/updateCheck?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_CHECK_MAT_PAGE]        = strPrefix + "check/checkMaterial_page?check_number=%1&check_state=%2&token=%3&user_id=%4";
    urlList[PROTOCOL::URL_CHECK_ADD_MAT_PAGE]    = strPrefix + "check/addCheckMaterial_page?check_number=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_CHECK_ADD_MAT]         = strPrefix + "check/addCheckMaterial?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_CHECK_UPDATE_MAT_PAGE] = strPrefix + "check/updateCheckMaterial_page?warehouse_check_material_id=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_CHECK_UPDATE_MAT]      = strPrefix + "check/updateCheckMaterial?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_CHECK_UNIT_UPDATE_NUM] = strPrefix + "check/unitUpdateNumber?material_id=%1&old_unit=%2&new_unit=%3&paper_number=%4&reality_number=%5&token=%6&user_id=%7";
    urlList[PROTOCOL::URL_CHECK_UPDATE_NUM]      = strPrefix + "check/updateNumber?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_CHECK_CANCEL]          = strPrefix + "check/cancel?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_CHECK_DEL]             = strPrefix + "check/delCheck?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_CHECK_IMPORT]          = strPrefix + "check/copyOrder?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_CHECK_AFFIRM]          = strPrefix + "check/affirm_check?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_CHECK_SEND_EMAIL]      = strPrefix + "check/sendEmail?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_CHECK_SEL_DISPOSE]     = strPrefix + "dispose/selDispose?number=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_CHECK_DEL_MAT]         = strPrefix + "check/delMaterial?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_CHECK_SELECT_PAGE]     = strPrefix + "check/filtrate_page?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_CHECK_SELECT]          = strPrefix + "check/filtrate?state_id=%1&warehouse_id=%2&time=%3&token=%4&user_id=%5";

    /***************  库存变更记录接口  ***************/
    urlList[PROTOCOL::URL_CHANCE_SEL_MAT]        = strPrefix + "change/selMaterial?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_CHANCE_MAT_LIST]       = strPrefix + "change/materialList?warehouse_id=%1&time=%2&material=%3&token=%4&user_id=%5";
    urlList[PROTOCOL::URL_CHANCE_ALL_MAT]        = strPrefix + "change/getAllMaterial?warehouse_id=%1&time=%2&material_id=%3&token=%4&user_id=%5";
    urlList[PROTOCOL::URL_CHANCE_GET_MAT]        = strPrefix + "change/getMaterial?warehouse_id=%1&material_id=%2&number=%3&reality_time=%4&token=%5&user_id=%6";
    urlList[PROTOCOL::URL_CHANCE_EXTEND]         = strPrefix + "change/sendEmail?token=%1&user_id=%2";

    /***************  成本调价接口  ***************/
    urlList[PROTOCOL::URL_COST_SEL_ALL]          = strPrefix + "readjust/selAllReadjust?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_COST_PRICE]            = strPrefix + "readjust/costPriceList?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_COST_ADD]              = strPrefix + "readjust/addReadjust?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_COST_SEL_MAT]          = strPrefix + "readjust/selMaterial?readjust_number=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_COST_ADD_MAT]          = strPrefix + "readjust/addMaterial?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_COST_SEL]              = strPrefix + "readjust/selReadjust?readjust_id=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_COST_UPDATE]           = strPrefix + "readjust/updateReadjust?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_COST_DEL]              = strPrefix + "readjust/delReadjust?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_COST_GET_MAT]          = strPrefix + "readjust/getMaterial?readjust_material_id=%1&state=%2&token=%3&user_id=%4";
    urlList[PROTOCOL::URL_COST_UPDATE_MAT]       = strPrefix + "readjust/updateMaterial?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_COST_UPDATE_PAGE]      = strPrefix + "readjust/updateAllMaterial_page?readjust_number=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_COST_UPDATE_ALL_MAT]   = strPrefix + "readjust/updateAllMaterial?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_COST_DEL_MAT]          = strPrefix + "readjust/delMaterial?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_COST_PRESENT]          = strPrefix + "readjust/present?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_COST_AFFIRM]           = strPrefix + "readjust/affirm?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_COST_SEL_DISPOSE]      = strPrefix + "dispose/selDispose?number=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_COST_SELECT_PAGE]      = strPrefix + "readjust/filtrate_page?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_COST_SELECT]           = strPrefix + "readjust/filtrate?state_id=%1&time=%2&token=%3&user_id=%4";

    /***************  库存上下限接口  ***************/
    urlList[PROTOCOL::URL_REST_SEL_MAT]          = strPrefix + "restrictions/selMaterial?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_REST_GET_MAT]          = strPrefix + "restrictions/getMaterial?material_id=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_REST_UPDATE_MAT]       = strPrefix + "restrictions/updateMaterial?token=%1&user_id=%2";

    /***************  店内调拨接口  ***************/
    urlList[PROTOCOL::URL_ALLOT_SEL_ALL]         = strPrefix + "allot/selAllAllot?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_ALLOT_ADD_PAGE]        = strPrefix + "allot/addAllot_page?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_ALLOT_ADD]             = strPrefix + "allot/addAllot?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_ALLOT_SEL]             = strPrefix + "allot/selAllot?allot_number=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_ALLOT_UPDATE]          = strPrefix + "allot/updateAllot?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_ALLOT_DEL]             = strPrefix + "allot/delAllot?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_ALLOT_SEL_MAT]         = strPrefix + "allot/selMaterial?allot_number=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_ALLOT_ADD_MAT]         = strPrefix + "allot/addMaterial?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_ALLOT_GET_MAT]         = strPrefix + "allot/getMaterial?allot_material_id=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_ALLOT_UPDATE_MAT]      = strPrefix + "allot/updateMaterial?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_ALLOT_DEL_MAT]         = strPrefix + "allot/delMaterial?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_ALLOT_UPDATE_ALL_PAGE] = strPrefix + "allot/updateAllMaterial_page?allot_number=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_ALLOT_UPDATE_ALL_MAT]  = strPrefix + "allot/updateAllMaterial?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_ALLOT_PRESEND]         = strPrefix + "allot/present?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_ALLOT_CANCEL]          = strPrefix + "allot/cancel?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_ALLOT_AFFIRM]          = strPrefix + "allot/affirm?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_ALLOT_RECONFIRM]       = strPrefix + "allot/reconfirm?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_ALLOT_SEND_EMAIL]      = strPrefix + "allot/sendEmail?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_ALLOT_SEL_DISPOSE]     = strPrefix + "dispose/selDispose?number=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_ALLOT_SELECT_PAGE]     = strPrefix + "allot/filtrate_page?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_ALLOT_SELECT]          = strPrefix + "allot/filtrate?state_id=%1&out_warehouse_id=%2&enter_warehouse_id=%3&time=%4&token=%5&user_id=%6";

    /***************  报表中心接口  ***************/
    urlList[PROTOCOL::URL_STATE_STO_PAGE]        = strPrefix + "statement/select_storage_detail_log_page?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_STATE_STORAGE]         = strPrefix + "statement/select_storage_detail_log?state=%1&supplier_id=%2&warehouse_id=%3&time_type=%4&time=%5&token=%6&user_id=%7";
    urlList[PROTOCOL::URL_STATE_STORAGE_EXTEND]  = strPrefix + "statement/select_storage_detail_log?state=%1&supplier_id=%2&warehouse_id=%3&time_type=%4&time=%5&email=%6&token=%7&user_id=%8";
    urlList[PROTOCOL::URL_STATE_STO_GATHER_PAGE] = strPrefix + "statement/select_storage_gather_log_page?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_STATE_STORAGE_GATHER]  = strPrefix + "statement/select_storage_gather_log?state=%1&supplier_id=%2&warehouse_id=%3&time_type=%4&time=%5&material=%6&category_id=%7&token=%8&user_id=%9";
    urlList[PROTOCOL::URL_STATE_STO_GAT_EXTEND]  = strPrefix + "statement/select_storage_gather_log?state=%1&supplier_id=%2&warehouse_id=%3&time_type=%4&time=%5&material=%6&category_id=%7&email=%8&token=%9&user_id=%10";
    urlList[PROTOCOL::URL_STATE_RET_PAGE]        = strPrefix + "statement/select_returns_detail_log_page?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_STATE_RETURNS]         = strPrefix + "statement/select_returns_detail_log?state=%1&supplier_id=%2&warehouse_id=%3&time_type=%4&time=%5&token=%6&user_id=%7";
    urlList[PROTOCOL::URL_STATE_RETURNS_EXTEND]  = strPrefix + "statement/select_returns_detail_log?state=%1&supplier_id=%2&warehouse_id=%3&time_type=%4&time=%5&email=%6&token=%7&user_id=%8";
    urlList[PROTOCOL::URL_STATE_ADJ_PAGE]        = strPrefix + "statement/select_adjustment_detail_log_page?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_STATE_ADJUST]          = strPrefix + "statement/select_adjustment_detail_log?type_id=%1&warehouse_id=%2&time_type=%3&time=%4&token=%5&user_id=%6";
    urlList[PROTOCOL::URL_STATE_ADJUST_EXTEND]   = strPrefix + "statement/select_adjustment_detail_log?type_id=%1&warehouse_id=%2&time_type=%3&time=%4&email=%5&token=%6&user_id=%7";
    urlList[PROTOCOL::URL_STATE_CHECK_PAGE]      = strPrefix + "statement/select_check_detail_log_page?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_STATE_CHECK]           = strPrefix + "statement/select_check_detail_log?state=%1&warehouse_id=%2&time=%3&token=%4&user_id=%5";
    urlList[PROTOCOL::URL_STATE_CHECK_EXTEND]    = strPrefix + "statement/select_check_detail_log?state=%1&warehouse_id=%2&time=%3&email=%4&token=%5&user_id=%6";
    urlList[PROTOCOL::URL_STATE_CHK_GATHER_PAGE] = strPrefix + "statement/select_check_gather_log_page?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_STATE_CHECK_GATHER]    = strPrefix + "statement/select_check_gather_log?category_id=%1&warehouse_id=%2&time=%3&token=%4&user_id=%5";
    urlList[PROTOCOL::URL_STATE_CHK_GAT_EXTEND]  = strPrefix + "statement/select_check_gather_log?category_id=%1&warehouse_id=%2&time=%3&email=%4&token=%5&user_id=%6";
    urlList[PROTOCOL::URL_STATE_SUP_PAGE]        = strPrefix + "statement/select_supplier_detail_log_page?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_STATE_SUPPLIER]        = strPrefix + "statement/select_supplier_detail_log?supplier_id=%1&operation_id=%2&time=%3&material=%4&token=%5&user_id=%6";
    urlList[PROTOCOL::URL_STATE_SUPPLIER_EXTEND] = strPrefix + "statement/select_supplier_detail_log?supplier_id=%1&operation_id=%2&time=%3&material=%4&email=%5&token=%6&user_id=%7";
    urlList[PROTOCOL::URL_STATE_SUP_GATHER_PAGE] = strPrefix + "statement/select_supplier_gather_log_page?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_STATE_SUP_GATHER]      = strPrefix + "statement/select_supplier_gather_log?supplier_id=%1&category_id=%2&operation_id=%3&time=%4&material=%5&token=%6&user_id=%7";
    urlList[PROTOCOL::URL_STATE_SUP_GAT_EXTEND]  = strPrefix + "statement/select_supplier_gather_log?supplier_id=%1&category_id=%2&operation_id=%3&time=%4&material=%5&email=%6&token=%7&user_id=%8";
    urlList[PROTOCOL::URL_STATE_SELECT_MAT_PAGE] = strPrefix + "statement/select_material_market_log_page?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_STATE_SELECT_MAT]      = strPrefix + "statement/select_material_market_log?time=%1&name=%2&token=%3&user_id=%4";
    urlList[PROTOCOL::URL_STATE_SEL_MAT_EXTEND]  = strPrefix + "statement/select_material_market_log?time=%1&name=%2&email=%3&token=%4&user_id=%5";

    /***************  支出结算接口  ***************/
    urlList[PROTOCOL::URL_ACCOUNT_ALL_NUMBER]    = strPrefix + "account/AllNumbers?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_ACCOUNT_STO_PAGE]      = strPrefix + "account/storage_update_page?number=%1&account_time=%2&token=%3&user_id=%4";
    urlList[PROTOCOL::URL_ACCOUNT_RET_PAGE]      = strPrefix + "account/returns_update_page?number=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_ACCOUNT_AFFIRM_PRO]    = strPrefix + "account/affirm_proofread?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_ACCOUNT_AFFIRM_ACC]    = strPrefix + "account/affirm_account?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_ACCOUNT_SEL_DISPOSE]   = strPrefix + "dispose/selDispose?number=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_ACCOUNT_STO_MAT_INFO]  = strPrefix + "account/storage_material?storage_delivery_id=%1&token=%2&user_id=%3";
    urlList[PROTOCOL::URL_ACCOUNT_RET_MAT_INFO]  = strPrefix + "returns/getMaterial?returns_material_id=%1&returns_state=%2&warehouse_id=%3&token=%4&user_id=%5";   
    urlList[PROTOCOL::URL_ACCOUNT_FILTRATE_PAGE] = strPrefix + "account/filtrate_page?token=%1&user_id=%2";
    urlList[PROTOCOL::URL_ACCOUNT_FILTRATE]      = strPrefix + "account/filtrate?state_id=%1&supplier_id=%2&type_id=%3&time=%4&token=%5&user_id=%6";
    urlList[PROTOCOL::URL_ACCOUNT_EXTEND]        = strPrefix + "account/sendEmail?token=%1&user_id=%2";

    /***************  销售接口  ***************/
    urlList[PROTOCOL::URL_TODAY_SEL_TODAY]       = strPrefix + "today/selToday?token=%1&user_id=%2";

    /***************  更新接口  ***************/
    urlList[PROTOCOL::URL_UPDATE_CLIENT]         = strDomain + "WindowsClient/update.json";
}

/*********************      测试服务器路径       *******************/
void MessageUrl::initTestMessageUrl()
{
    QString strDomain = "http://erp.cloudabull.com/";

    this->initMessageUrl(strDomain);
}

/*********************      正式服务器路径       *******************/
void MessageUrl::initStandardMsgUrl()
{
    QString strDomain = "http://erp.yeaytvshop.com/";

    this->initMessageUrl(strDomain);
}

/*********************      获取对象            *******************/
MessageUrl *MessageUrl::getInstance()
{
    return instance;
}

/*********************      获取链接            *******************/
QString MessageUrl::getUrl(int type)
{
    if(type < 0 || type >= MESSAGESIZE) return NULL;

    return urlList[type];
}




