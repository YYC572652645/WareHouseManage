#ifndef POSTARG_H
#define POSTARG_H
#include <QString>


/***************************************************************
   功能:POST提交表单参数

   创建人:YYC

   创建时间:2017-11-21
**************************************************************/

namespace POSTARG
{
const static QString LOGINARG         = "number=%1&username=%2&password=%3";

const static QString MATERIALADD      = "name=%1&category_id=%2&bar_code=%3&unit_id=%4"
                                        "&standard=%5&term=%6&is_warehouse_unit=%7&"
                                        "is_price_unit=%8&is_supply_unit=%9&image64=%10&sideList=%11";

const static QString MATERIALEDIT     = "material_id=%1&name=%2&category_id=%3&bar_code=%4"
                                        "&unit_id=%5&standard=%6&term=%7&is_warehouse_unit=%8"
                                        "&is_price_unit=%9&is_supply_unit=%10&image64=%11&sideList=%12";

const static QString MATERIALTYPEADD  = "name=%1&pid=%2&encoding=%3";
const static QString MATERIALTYPEEDIT = "name=%1&pid=%2&encoding=%3&category_id=%4";
const static QString MATERIALTYPEDEL  = "category_id=%1";
const static QString UNITNAME         = "name=%1";
const static QString UNITID           = "unit_id=%1";
const static QString UPDATECAT        = "listId=%1&category_id=%2";
const static QString WARHOSID         = "warehouse_id=%1";
const static QString ADDWAREHOUSE     = "name=%1&food_category_id=%2&food_id=%3";
const static QString WAREHOUSESEARCH  = "food_name=%1";

const static QString UPDATEWAREHOUSE  = "warehouse_id=%1&name=%2&food_category_id=%3&food_id=%4"
                                        "&food_category_delete=%5&food_delete=%6";

const static QString SUPPLIERID       = "supplier_id=%1";
const static QString DELETESUP        = "supplier_id=%1";
const static QString DELETESUPCAT     = "supplier_category_id=%1";
const static QString ADDSUPCAT        = "supplier_category_name=%1";
const static QString UPDATESUPCAT     = "supplier_category_id=%1&supplier_category_name=%2";

const static QString ADDSUPMATERIAL   = "material_id=%1&supplier_id=%2";
const static QString DELSUPMATERIAL   = "material_id=%1&supplier_id=%2";

const static QString ADDSUPPLIER      = "supplier_name=%1&number=%2&linkman=%3&supplier_category_id=%4"
                                        "&phone=%5&email=%6&invoice=%7&tax_rate=%8&invoice_phone=%9"
                                        "&wechat=%10&fax_number=%11&contact_address=%12&bank_deposit=%13"
                                        "&bank_account=%14&bank_name=%15";

const static QString UPDATESUPPLIER   = "supplier_name=%1&number=%2&linkman=%3&supplier_category_id=%4"
                                        "&phone=%5&email=%6&invoice=%7&tax_rate=%8&invoice_phone=%9"
                                        "&wechat=%10&fax_number=%11&contact_address=%12&bank_deposit=%13"
                                        "&bank_account=%14&bank_name=%15&supplier_id=%16";

const static QString ADDTEMPLATE      = "template_name=%1&template_remarks=%2";
const static QString TEMDETAIL        = "template_id=%1";
const static QString TEMDELETE        = "template_id=%1";
const static QString TEMGETTYPE       = "category_id=%1";
const static QString TEMADDMATERIAL   = "template_id=%1&material_id=%2";
const static QString TEMDELMATERIAL   = "template_id=%1&material_id=%2";
const static QString TEMUPDATE        = "template_id=%1&template_name=%2&template_remarks=%3";
const static QString FOODADDMAT       = "food_id=%1&material_id=%2&warehouse_id=%3&unit_id=%4&expend_number=%5";
const static QString FOODDELMAT       = "bom_material_id=%1";
const static QString FOODEDITMAT      = "bom_material_id=%1&unit_id=%2&expend_number=%3&warehouse_id=%4";
const static QString FOODADDID        = "bom_id=%1&cost=%2&cost_price=%3&product_warehouse=%4";
const static QString ADDPURINDENT     = "supplier_id=%1&purchase_warehouse=%2&purchase_remark=%3&arrival_time=%4";
const static QString ADDPURMAT        = "material_id=%1&purchase_number=%2&supplier_id=%3";
const static QString DELPURMAT        = "purchase_material_id=%1";
const static QString DELPUR           = "purchase_number=%1";
const static QString UPDATEPUR        = "purchase_number=%1&supplier_id=%2&purchase_warehouse=%3&arrival_time=%4&purchase_remark=%5";
const static QString UPDATEMAT        = "purchase_material_id=%1&purchase_price=%2&purchase_unit=%3&purchase_amount=%4&total_money=%5";
const static QString AFFIRM           = "purchase_number=%1";
const static QString COPYPUR          = "purchase_id=%1";
const static QString STOADDMAT        = "material_id=%1&storage_number=%2&supplier_id=%3&warehouse_id=%4&storage_state=%5";
const static QString STODELMAT        = "storage_material_id=%1";
const static QString ADDSTORAGE       = "supplier_id=%1&warehouse_id=%2&storage_time=%3&storage_remark=%4";
const static QString IMPORTPUR        = "purchase_number=%1";
const static QString IMPORTSTO        = "storage_number=%1";
const static QString REFUSE           = "storage_number=%1&cause=%2";
const static QString STOAFFIRM        = "storage_number=%1&warehouse_material=%2";
const static QString UPDATESTO        = "storage_number=%1&warehouse_id=%2&storage_time=%3&storage_remark=%4&supplier_id=%5&storage_state=%6";
const static QString SENDEMAIL        = "email=%1&number=%2";
const static QString DELSTO           = "storage_number=%1";
const static QString UPDATESTOMAT     = "storage_material_id=%1&storage_unit=%2&storage_price=%3&production_date=%4&storage_state=%5"
                                        "&storage_amount=%6&total_money=%7&assistant_warehouse=%8";
const static QString UPDATESIDEW      = "warehouse_id=%1&number=%2&total_money=%3&storage_material_id=%4";
const static QString DELETESIDEW      = "storage_material_id=%1&warehouse_id=%2&material_warehouse_id=%3&number=%4&total_money=%5";
const static QString EXPORTPUR        = "material_list=%1";
const static QString UPDATERET        = "returns_number=%1&warehouse_id=%2&returns_time=%3&returns_remark=%4&supplier_id=%5&returns_state=%6";
const static QString ADDRET           = "supplier_id=%1&warehouse_id=%2&returns_time=%3&returns_remark=%4";
const static QString RETADDMAT        = "material_id=%1&returns_number=%2&supplier_id=%3&warehouse_id=%4";
const static QString RETDELMAT        = "returns_material_id=%1";
const static QString UPDATERETSIDE    = "warehouse_id=%1&number=%2&total_money=%3&returns_material_id=%4";
const static QString UPDATERETMAT     = "returns_material_id=%1&returns_unit=%2&returns_price=%3"
                                        "&returns_amount=%4&total_money=%5&returns_cause=%6&assistant_warehouse=%7";
const static QString DELETESIDERET    = "returns_material_id=%1&warehouse_id=%2&returns_warehouse_id=%3&number=%4&total_money=%5";
const static QString DELRET           = "returns_number=%1";
const static QString CONFIRMRET       = "returns_number=%1";
const static QString COPYRET          = "returns_number=%1";
const static QString SAFETYAFFIRM     = "affirmList=%1";
const static QString UPDATESUPLIST    = "material_id=%1&supplier_id=%2";
const static QString EXPORTEMAIL      = "email=%1";
const static QString ADDINVENTORY     = "type_id=%1&warehouse_id=%2&time=%3&remarks=%4";
const static QString ADDINVMAT        = "odd_numbers=%1&material_id=%2&warehouse_id=%3";
const static QString DELINVMAT        = "relationship_id=%1";
const static QString DELINVENTORY     = "odd_numbers=%1";
const static QString UPDATEDASIC      = "odd_numbers=%1&remarks=%2&warehouse_id=%3&type_id=%4&time=%5";
const static QString ADJEXPORTEMAIL   = "email=%1&number=%2";
const static QString ADJGETMATDET     = "material_id=%1&odd_numbers=%2&warehouse_id=%3&whether_submit=%4";
const static QString ADJUPDATEMAT     = "adjust_quantity=%1&odd_numbers=%2&material_id=%3&reason=%4&unit_id=%5&warehouse_id=%6";
const static QString DELREASON        = "reason_id=%1";
const static QString ADDREASON        = "reason=%1";
const static QString PRESENT          = "odd_numbers=%1";
const static QString ADDCHECK         = "warehouse_id=%1";
const static QString DELCHECK         = "check_number=%1";
const static QString UPDATECHECK      = "check_number=%1&warehouse_id=%2";
const static QString CHECKEMAIL       = "email=%1&number=%2";
const static QString ADDCHECKMAT      = "check_number=%1&material_id=%2&warehouse_id=%3";
const static QString AFFIRMCHECK      = "check_number=%1&warehouse_id=%2";
const static QString CANCELCHECK      = "check_number=%1";
const static QString UPDATECHECKMAT   = "warehouse_check_material_id=%1&unit_id=%2&paper_number=%3&reality_number=%4&difference_number=%5";
const static QString DELCHECKMAT      = "warehouse_check_material_id=%1";
const static QString IMPORTCHECK      = "check_number=%1";
const static QString COPYCHECK        = "check_number=%1";
const static QString UNITUPDATE       = "material_id=%1&old_unit=%2&new_unit=%3&paper_number=%4&reality_number=%5";
const static QString MATERIALDATE     = "materialDate=%1";
const static QString ADDCOST          = "remark=%1";
const static QString SUBMITCOST       = "readjust_number=%1";
const static QString CONFIRMCOST      = "readjust_number=%1";
const static QString UPDATECOSTMAT    = "readjust_material_id=%1&difference_price=%2&old_price=%3&new_price=%4";
const static QString UPDATEREADJUST   = "readjust_id=%1&remark=%2";
const static QString DELCOST          = "readjust_number=%1";
const static QString ADDCOSTMAT       = "material=%1";
const static QString DELCOSTMAT       = "readjust_material_id=%1";
const static QString UPDATEALLMAT     = "del=%1&update=%2";
const static QString UPDATETRANMAT    = "update=%1";
const static QString UPDATERESTLIST   = "material_id=%1&upper_limit=%2&lower_limit=%3";
const static QString ADDTRAN          = "enter_warehouse_id=%1&out_warehouse_id=%2&allot_time=%3&remark=%4";
const static QString DELTRAN          = "allot_number=%1";
const static QString FINISHTRAN       = "allot_number=%1";
const static QString SUBMITTRAN       = "allot_number=%1";
const static QString REFUSETRAN       = "allot_number=%1&cause=%2";
const static QString UPDATETRAN       = "allot_id=%1&allot_time=%2&remark=%3";
const static QString ADDTRANMAT       = "material=%1";
const static QString DELTRANMAT       = "allot_material_id=%1";
const static QString UPDATETRANONEMAT = "allot_material_id=%1&unit_id=%2&number=%3";
const static QString AFFIRMACCOUNT    = "number=%1&reality_time=%2";
const static QString PUREXPORTEMAIL   = "email=%1&number=%2";
const static QString RETEXPORTEMAIL   = "email=%1&number=%2";
const static QString ADDUSER          = "username=%1&password=%2";
const static QString DELETEUSER       = "user_id=%1";
const static QString EDITUSER         = "user_id=%1&username=%2&password=%3&rule=%4";
const static QString STOFINISH        = "storage_number=%1";
const static QString ACCOUNTEXTEND    = "email=%1&account=%2";
const static QString EXTENDEMAIL      = "email=%1";

}

#endif // POSTARG_H
