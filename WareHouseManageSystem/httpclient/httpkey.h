﻿#ifndef HTTPKEY_H
#define HTTPKEY_H

/***************************************************************
   功能:所有的JSON的Key

   创建人:YYC

   创建时间:2017-11-21
**************************************************************/

#include <QString>
#include "login/logindialog.h"
#include "mainwindow/mainwindow.h"

namespace HTTPKEY
{
const static QString MAIN                 = "main";
const static QString VICE                 = "vice";
const static QString CODE                 = "code";
const static QString MSG                  = "msg";
const static QString TOKEN                = "token";
const static QString USRID                = "user_id";
const static QString MATERIALID           = "material_id";
const static QString MATERIALDATA         = "material_data";
const static QString MATERIALNUMBER       = "material_number";
const static QString NAME                 = "name";
const static QString BARCODE              = "bar_code";
const static QString RES                  = "res";
const static QString CATEGORY             = "category";
const static QString CATEGORYNAME         = "category_name";
const static QString UNIT                 = "unit";
const static QString UNITNAME             = "unit_name";
const static QString SIDEUNIT             = "side_unit";
const static QString SIDEID               = "side_id";
const static QString CATEGORYID           = "category_id";
const static QString UNITID               = "unit_id";
const static QString TERM                 = "term";
const static QString STANDARD             = "standard";
const static QString ISWAREHOUSEUNIT      = "is_warehouse_unit";
const static QString ISWAREHOUSEUNITNAME  = "is_warehouse_unit_name";
const static QString ISPRICEUNIT          = "is_price_unit";
const static QString ISPRICEUNITNAME      = "is_price_unit_name";
const static QString ISPRICENAME          = "is_price_name";
const static QString ISSUPPLYUNIT         = "is_supply_unit";
const static QString IMAGE                = "image";
const static QString PID                  = "pid";
const static QString STOREID              = "store_id";
const static QString LEVEL                = "level";
const static QString CATEGORYLIST         = "categoryList";
const static QString UNITLIST             = "unitList";
const static QString UNIT_LIST            = "unit_list";
const static QString UNITPRICE            = "unit_price";
const static QString ENCODING             = "encoding";
const static QString SIDEUNITID           = "side_unit_id";
const static QString SIDENAME             = "side_name";
const static QString WAREHOUSEID          = "warehouse_id";
const static QString WAREHOUSE            = "warehouse";
const static QString WAREHOUSELIST        = "warehouse_list";
const static QString WAREHOUSE_LIST       = "warehouseList";
const static QString WAREHOUSENAME        = "warehouse_name";
const static QString WAREHOUSEUNITNAME    = "warehouse_unit_name";
const static QString FOODCATEGORYNAME     = "food_category_name";
const static QString FOODNAME             = "food_name";
const static QString FOODCATEGORY         = "food_category";
const static QString FOOD                 = "food";
const static QString FOODID               = "food_id";
const static QString FOODCATEGORYID       = "food_category_id";
const static QString SUPPLIERCATEGORYID   = "supplier_category_id";
const static QString SUPPLIERCATEGORYNAME = "supplier_category_name";
const static QString SUPPLIERID           = "supplier_id";
const static QString SUPPLIERNUM          = "supplier_num";
const static QString SUPPLIER             = "supplier";
const static QString NUMBER               = "number";
const static QString SUPPLIERNAME         = "supplier_name";
const static QString LINKMAN              = "linkman";
const static QString PHONE                = "phone";
const static QString EMAIL                = "email";
const static QString INVOICE              = "invoice";
const static QString TAXRATE              = "tax_rate";
const static QString INVOICEPHONE         = "invoice_phone";
const static QString WECHAT               = "wechat";
const static QString FAXNUMBER            = "fax_number";
const static QString CONTACTADDRESS       = "contact_address";
const static QString BANKDEPOSIT          = "bank_deposit";
const static QString BANKACCOUNT          = "bank_account";
const static QString BANKNAME             = "bank_name";
const static QString SOFTDELETE           = "soft_delete";
const static QString COUNT                = "count";
const static QString SUPPLIERCATEGORY     = "supplier_category";
const static QString SUPPLIERLIST         = "supplier_list";
const static QString SUPPLIER_LIST        = "supplierList";
const static QString MATERIAL             = "material";
const static QString MATERIALPRICE        = "material_price";
const static QString MATERIALCATEGORY     = "material_category";
const static QString MATERIALCATEGORYNAME = "material_category_name";
const static QString MATERIALLIST         = "material_list";
const static QString TEMPLATENAME         = "template_name";
const static QString TEMPLATEID           = "template_id";
const static QString TEMPLATE             = "template";
const static QString TEMPLATEREMARK       = "template_remarks";
const static QString ITEM                 = "item";
const static QString BOMID                = "bom_id";
const static QString BOM                  = "bom";
const static QString COST                 = "cost";
const static QString COSTPRICE            = "cost_price";
const static QString PROFIT               = "profit";
const static QString PRODUCTWAREHOUSE     = "product_warehouse";
const static QString CLASSIFICATIONID     = "classification_id";
const static QString RATIO                = "ratio";
const static QString MATERIALNAME         = "material_name";
const static QString EXPENDNUMBER         = "expend_number";
const static QString BOMMATERIALID        = "bom_material_id";
const static QString PURCHASEID           = "purchase_id";
const static QString PURCHASEDATA         = "purchase_data";
const static QString PURCHASENUMBER       = "purchase_number";
const static QString PURWAREHOUSE         = "purchase_warehouse";
const static QString ARRIVALTIME          = "arrival_time";
const static QString PURCHASESTATE        = "purchase_state";
const static QString PURCHASEREMARK       = "purchase_remark";
const static QString PURCHASEPRICE        = "purchase_price";
const static QString PURCHASEAMOUNT       = "purchase_amount";
const static QString PURCHASEUNITNAME     = "purchase_unit_name";
const static QString PURCHASEUNIT         = "purchase_unit";
const static QString INVENTORY            = "inventory";
const static QString PURCHASEMATERIALID   = "purchase_material_id";
const static QString TOTALMONEY           = "total_money";
const static QString STORAGEID            = "storage_id";
const static QString STORAGENUMBER        = "storage_number";
const static QString STORAGETIME          = "storage_time";
const static QString STORAGESTATE         = "storage_state";
const static QString STORAGEDATA          = "storage_data";
const static QString STORAGEREMARK        = "storage_remark";
const static QString STORAGEPRICE         = "storage_price";
const static QString STORAGEAMOUNT        = "storage_amount";
const static QString STORAGEMATTERIALID   = "storage_material_id";
const static QString ASSISTANTWAREHOUSE   = "assistant_warehouse";
const static QString STORAGEUNIT          = "storage_unit";
const static QString MATERIALWAREHOUSEID  = "material_warehouse_id";
const static QString OPERATIONID          = "operation_id";
const static QString OPERATION            = "operation";
const static QString OPERATIONTYPE        = "operation_type";
const static QString OPERATIONTIME        = "operation_time";
const static QString USERNAME             = "username";
const static QString PASSWORD             = "password";
const static QString CAUSE                = "cause";
const static QString RETURNSID            = "returns_id";
const static QString RETURNS              = "returns";
const static QString RETURNSNUMBER        = "returns_number";
const static QString RETURNSTIME          = "returns_time";
const static QString RETURNSSTATE         = "returns_state";
const static QString RETURNSDATA          = "returns_data";
const static QString RETURNSMATERIALID    = "returns_material_id";
const static QString RETURNSWAREHOUSEID   = "returns_warehouse_id";
const static QString RETURNSAMOUNT        = "returns_amount";
const static QString RETURNSPRICE         = "returns_price";
const static QString RETURNSUNIT          = "returns_unit";
const static QString RETURNSCAUSE         = "returns_cause";
const static QString UPPERLIMIT           = "upper_limit";
const static QString LOWERLIMIT           = "lower_limit";
const static QString PURCHASE             = "purchase";
const static QString STORAGE              = "storage";
const static QString STORAGENAME          = "store_name";
const static QString DEFAULTSUPPLIERID    = "default_supplier_id";
const static QString SUMNUMBER            = "sum(number)";
const static QString SUMTOTALMONEY        = "sum(total_money)";
const static QString HINT                 = "hint";
const static QString LIST                 = "list";
const static QString ADJUSTMENTID         = "adjustment_id";
const static QString ADJUSTMENT           = "adjustment";
const static QString ADJUSTMENTTYPE       = "adjustment_type";
const static QString TIME                 = "time";
const static QString ODDNUMBERS           = "odd_numbers";
const static QString WHETHERSUBMIT        = "whether_submit";
const static QString JIBEN                = "jiben";
const static QString REMARKS              = "remarks";
const static QString REMARK               = "remark";
const static QString TYPENAME             = "type_name";
const static QString TYPEID               = "type_id";
const static QString TYPE                 = "type";
const static QString REASON               = "reason";
const static QString REASONID             = "reason_id";
const static QString ADJUSTQUANTITY       = "adjust_quantity";
const static QString LASTNUMBER           = "last_number";
const static QString RELATIONSHIPID       = "relationship_id";
const static QString REALITYTIME          = "reality_time";
const static QString CHECKSTATE           = "check_state";
const static QString CHECKTIME            = "check_time";
const static QString CHECKNUMBER          = "check_number";
const static QString WAREHOUSECHECKID     = "warehouse_check_id";
const static QString CHECKDATA            = "checkData";
const static QString CHECK                = "check";
const static QString CHECKTOTALMONEY      = "check_total_money";
const static QString DIFFERENCETOTALMONEY = "difference_total_money";
const static QString PRICE                = "price";
const static QString REALITYNUMBER        = "reality_number";
const static QString WAREHOUSECHECKMATID  = "warehouse_check_material_id";
const static QString PAPERNUMBER          = "paper_number";
const static QString DIFFERENCENUMBER     = "difference_number";
const static QString DATE                 = "date";
const static QString ORDER                = "order";
const static QString ORDERNUMBER          = "order_number";
const static QString OPERATIONNAME        = "operation_name";
const static QString TIME1                = "time1";
const static QString TIME2                = "time2";
const static QString READJUSTNUMBER       = "readjust_number";
const static QString READJUSTTIME         = "readjust_time";
const static QString STATE                = "state";
const static QString STATEID              = "state_id";
const static QString STATENAME            = "state_name";
const static QString NUM                  = "num";
const static QString READJUST             = "readjust";
const static QString READJUSTID           = "readjust_id";
const static QString OLDPRICE             = "old_price";
const static QString NEWPRICE             = "new_price";
const static QString READJUSTMATID        = "readjust_material_id";
const static QString DIFFERENCEPRICE      = "difference_price";
const static QString ENTERNAME            = "enter_name";
const static QString OUTNAME              = "out_name";
const static QString ALLOTTIME            = "allot_time";
const static QString ALLOTID              = "allot_id";
const static QString ALLOTNUMBER          = "allot_number";
const static QString ENTERWAREHOUSEID     = "enter_warehouse_id";
const static QString OUTWAREHOUSEID       = "out_warehouse_id";
const static QString ALLOT                = "allot";
const static QString ALLOTMATERIALID      = "allot_material_id";
const static QString ACCOUNTSTATE         = "account_state";
const static QString ACCOUNTTIME          = "account_time";
const static QString RETURNSREMARK        = "returns_remark";
const static QString PROOFREADTIME        = "proofread_time";
const static QString TIMETYPE             = "time_type";
const static QString TIMEFRAME            = "time_frame";
const static QString BUSINESSTIME         = "business_time";
const static QString EARNINGS             = "earnings";
const static QString MARKETPEICE          = "market_price";
const static QString MARKETTIME           = "market_time";
const static QString VERSION              = "version";
const static QString FILELIST             = "fileList";
const static QString PATH                 = "path";
const static QString USERLIST             = "userList";
const static QString USERID               = "user_id";
const static QString RULEID               = "rule_id";
const static QString GROUPID              = "group_id";
const static QString RULENAME             = "rule_name";
const static QString CONTROLLERNAME       = "controller_name";
const static QString RULE                 = "rule";
const static QString RULELIST             = "ruleList";
const static QString SAFETY               = "safety";
const static QString TIMEINVENTORY        = "timeinventory";
const static QString CHANGE               = "change";
const static QString RESTRICTIONS         = "restrictions";
const static QString DEFAULTSUPPLIER      = "defaultSupplier";
const static QString ACCOUNT              = "account";
const static QString TODAY                = "today";
const static QString STATEMENT            = "statement";
const static QString USER                 = "user";
const static QString MATERIALWAREHOUSE    = "material_warehouse";
const static QString STORAGEDELIVERYID    = "storage_delivery_id";
const static QString PRODUCTIONDATE       = "production_date";
const static QString DATADATA             = "data";
const static QString ENGDATA              = "engData";
}
#endif // HTTPKEY_H