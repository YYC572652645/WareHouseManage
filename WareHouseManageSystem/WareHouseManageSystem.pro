#-------------------------------------------------
#
# Project created by QtCreator 2017-11-20T10:25:58
#
#-------------------------------------------------

QT       += core gui network printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WareHouseManageSystem
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow/mainwindow.cpp \
    login/logindialog.cpp \
    titlebar/titlebar.cpp \
    httpclient/httpclient.cpp \
    baseinfomanage/baseinfomanage.cpp \
    warehousemanage/warehousemanage.cpp \
    purchasemanage/purchasemanage.cpp \
    qcustomplot/qcustomplot.cpp \
    todayhousemoney/todayhousemoney.cpp \
    reporttable/reporttable.cpp \
    login/pushbutton/pushbutton.cpp \
    baseinfomanage/materialsetup/materwidget/materialwidget.cpp \
    baseinfomanage/materialsetup/materialcontrol/materialcontrol.cpp \
    baseinfomanage/materialsetup/lookimage/lookimage.cpp \
    baseinfomanage/materialsetup/addmaterial/addmaterial.cpp \
    baseinfomanage/materialsetup/addunitsite/addunitsite.cpp \
    baseinfomanage/materialsetup/materialtype/materialtype.cpp \
    messagebox/messagedialog.cpp \
    baseinfomanage/materialsetup/addunit/addunit.cpp \
    baseinfomanage/materialsetup/exchangetype/exchangetype.cpp \
    baseinfomanage/warehousesetup/warehousewidget/warehousewidget.cpp \
    baseinfomanage/warehousesetup/addcommodity/addcommodity.cpp \
    baseinfomanage/suppliersetup/supplierwidget/supplierwidget.cpp \
    baseinfomanage/suppliersetup/supmaterial/supmaterial.cpp \
    baseinfomanage/suppliersetup/addtype/addtype.cpp \
    baseinfomanage/templatesetup/templatewidget/templatewidget.cpp \
    baseinfomanage/templatesetup/edittemplate/edittemplate.cpp \
    baseinfomanage/materialratiosetup/materialratiowidget/materialratiowidget.cpp \
    baseinfomanage/materialratiosetup/selectmaterial/selectmaterial.cpp \
    baseinfomanage/materialratiosetup/materialinfo/materialinfo.cpp \
    purchasemanage/purchaseorder/purchaseorder.cpp \
    purchasemanage/purchaseorder/addpurmaterial/addpurmaterial.cpp \
    purchasemanage/purchaseorder/materialpurinfo/materialpurinfo.cpp \
    purchasemanage/purchaseorder/confirmmat/confirmmat.cpp \
    purchasemanage/purchaseorder/importhistory/importhistory.cpp \
    purchasemanage/purchaseorder/templatepur/templatepur.cpp \
    purchasemanage/purchasestorage/materialstoinfo/materialstoinfo.cpp \
    purchasemanage/purchasestorage/addstomaterial/addstomaterial.cpp \
    purchasemanage/purchasestorage/purchasestorage.cpp \
    purchasemanage/purchasestorage/importallhistory/importallhistory.cpp \
    purchasemanage/purchasestorage/refusewidget/refusewidget.cpp \
    purchasemanage/purchasestorage/startreceive/startreceive.cpp \
    purchasemanage/purchasestorage/subposition/subposition.cpp \
    purchasemanage/loginfo/loginfo.cpp \
    purchasemanage/purreturngood/purreturngood.cpp \
    purchasemanage/purreturngood/addretmaterial/addretmaterial.cpp \
    purchasemanage/purreturngood/materialretinfo/materialretinfo.cpp \
    purchasemanage/purreturngood/subretposition/subretposition.cpp \
    purchasemanage/purreturngood/importrethistory/importrethistory.cpp \
    purchasemanage/purchasesafe/purchasesafe.cpp \
    purchasemanage/purchasesafe/confirmsafemat/confirmsafemat.cpp \
    materialsupplier/materialsupplier.cpp \
    materialsupplier/defaultmatinfo/defaultmatinfo.cpp \
    materialsupplier/setdefaultsup/setdefaultsup.cpp \
    warehousemanage/realtimeinventory/realtimeinventory.cpp \
    warehousemanage/timematinfo/timematinfo.cpp \
    exportemail/exportemail.cpp \
    warehousemanage/inventoryadjust/inventoryadjust.cpp \
    warehousemanage/inventoryadjust/addadjmaterial/addadjmaterial.cpp \
    warehousemanage/inventoryadjust/materialadjinfo/materialadjinfo.cpp \
    reasonwidget/reasonwidget.cpp \
    warehousemanage/inventorycheck/inventorycheck.cpp \
    warehousemanage/inventorycheck/materialcheckinfo/materialcheckinfo.cpp \
    warehousemanage/inventorycheck/addcheckmat/addcheckmat.cpp \
    warehousemanage/inventorycheck/materialchectdet/materialcheckdet.cpp \
    warehousemanage/inventorycheck/importcheckhistory/importcheckhistory.cpp \
    warehousemanage/inventorychange/inventorychange.cpp \
    warehousemanage/inventorychange/inventorylog/inventorylog.cpp \
    warehousemanage/inventorychange/inventorydet/inventorydet.cpp \
    warehousemanage/costadjustment/costadjustment.cpp \
    warehousemanage/costadjustment/costprice/costprice.cpp \
    warehousemanage/costadjustment/addcostmaterial/addcostmaterial.cpp \
    warehousemanage/costadjustment/materialcostinfo/materialcostinfo.cpp \
    warehousemanage/inventorylimit/inventorylimit.cpp \
    warehousemanage/inventorylimit/limitmatinfo/defaultlimitinfo.cpp \
    warehousemanage/inventorylimit/setdefaultlimit/setdefaultlimit.cpp \
    warehousemanage/inventorytransfer/inventorytransfer.cpp \
    warehousemanage/inventorytransfer/addtranmaterial/addtranmaterial.cpp \
    warehousemanage/inventorytransfer/materialtrandet/materialtrandet.cpp \
    warehousemanage/inventorytransfer/refusetranwidget/refusetranwidget.cpp \
    warehousemanage/inventorytransfer/extendtranemail/extendtranemail.cpp \
    warehousemanage/inventoryadjust/extendadjemail/extendadjemail.cpp \
    warehousemanage/inventorycheck/extendcheckemail/extendcheckemail.cpp \
    accountmanage/accountmanage.cpp \
    reporttable/selectwidget/selectwidget.cpp \
    version/versiondialog.cpp \
    purchasemanage/purchaseorder/extendpuremail/extendpuremail.cpp \
    purchasemanage/purreturngood/extendretemail/extendretemail.cpp \
    pushmessage/pushmessage.cpp \
    flowlayout/flowlayout.cpp \
    administermanage/administermanage.cpp \
    administermanage/editauthority/editauthority.cpp \
    administermanage/addauthority/addauthority.cpp \
    global/globaldef.cpp \
    global/message/message.cpp \
    httpclient/messageurl/messageurl.cpp \
    config/jsonconfig/jsonconfig.cpp \
    config/qreadwrite/qreadwriteini.cpp \
    accountmanage/accountexport/accountexport.cpp \
    purchasemanage/purchasestorage/extendstorage/extendstorage.cpp \
    checkupdate/checkupdate.cpp


HEADERS  +=  mainwindow/mainwindow.h \
    login/logindialog.h \
    titlebar/titlebar.h \
    httpclient/httpclient.h \
    baseinfomanage/baseinfomanage.h \
    warehousemanage/warehousemanage.h \
    purchasemanage/purchasemanage.h \
    qcustomplot/qcustomplot.h \
    todayhousemoney/todayhousemoney.h \
    reporttable/reporttable.h \
    httpclient/httpkey.h \
    login/pushbutton/pushbutton.h \
    baseinfomanage/materialsetup/materwidget/materialwidget.h \
    baseinfomanage/materialsetup/materialcontrol/materialcontrol.h \
    baseinfomanage/materialsetup/lookimage/lookimage.h \
    httpclient/protocol.h \
    baseinfomanage/materialsetup/addmaterial/addmaterial.h \
    baseinfomanage/materialsetup/addunitsite/addunitsite.h \
    baseinfomanage/materialsetup/materialtype/materialtype.h \
    messagebox/messagedialog.h \
    baseinfomanage/materialsetup/addunit/addunit.h \
    baseinfomanage/materialsetup/exchangetype/exchangetype.h \
    baseinfomanage/warehousesetup/warehousewidget/warehousewidget.h \
    baseinfomanage/warehousesetup/addcommodity/addcommodity.h \
    baseinfomanage/suppliersetup/supplierwidget/supplierwidget.h \
    baseinfomanage/suppliersetup/supmaterial/supmaterial.h \
    baseinfomanage/suppliersetup/addtype/addtype.h \
    baseinfomanage/templatesetup/templatewidget/templatewidget.h \
    baseinfomanage/templatesetup/edittemplate/edittemplate.h \
    baseinfomanage/materialratiosetup/materialratiowidget/materialratiowidget.h \
    baseinfomanage/materialratiosetup/selectmaterial/selectmaterial.h \
    baseinfomanage/materialratiosetup/materialinfo/materialinfo.h \
    purchasemanage/purchaseorder/purchaseorder.h \
    purchasemanage/purchaseorder/addpurmaterial/addpurmaterial.h \
    purchasemanage/purchaseorder/materialpurinfo/materialpurinfo.h \
    purchasemanage/purchaseorder/confirmmat/confirmmat.h \
    purchasemanage/purchaseorder/importhistory/importhistory.h \
    purchasemanage/purchaseorder/templatepur/templatepur.h \
    purchasemanage/purchasestorage/materialstoinfo/materialstoinfo.h \
    purchasemanage/purchasestorage/addstomaterial/addstomaterial.h \
    purchasemanage/purchasestorage/purchasestorage.h \
    purchasemanage/purchasestorage/importallhistory/importallhistory.h \
    purchasemanage/purchasestorage/refusewidget/refusewidget.h \
    purchasemanage/purchasestorage/startreceive/startreceive.h \
    purchasemanage/purchasestorage/subposition/subposition.h \
    purchasemanage/loginfo/loginfo.h \
    purchasemanage/purreturngood/purreturngood.h \
    purchasemanage/purreturngood/addretmaterial/addretmaterial.h \
    purchasemanage/purreturngood/materialretinfo/materialretinfo.h \
    purchasemanage/purreturngood/subretposition/subretposition.h \
    purchasemanage/purreturngood/importrethistory/importrethistory.h \
    purchasemanage/purchasesafe/purchasesafe.h \
    purchasemanage/purchasesafe/confirmsafemat/confirmsafemat.h \
    materialsupplier/materialsupplier.h \
    materialsupplier/defaultmatinfo/defaultmatinfo.h \
    materialsupplier/setdefaultsup/setdefaultsup.h \
    warehousemanage/realtimeinventory/realtimeinventory.h \
    warehousemanage/timematinfo/timematinfo.h \
    exportemail/exportemail.h \
    warehousemanage/inventoryadjust/inventoryadjust.h \
    warehousemanage/inventoryadjust/addadjmaterial/addadjmaterial.h \
    warehousemanage/inventoryadjust/materialadjinfo/materialadjinfo.h \
    reasonwidget/reasonwidget.h \
    warehousemanage/inventorycheck/inventorycheck.h \
    warehousemanage/inventorycheck/materialcheckinfo/materialcheckinfo.h \
    warehousemanage/inventorycheck/addcheckmat/addcheckmat.h \
    warehousemanage/inventorycheck/materialchectdet/materialcheckdet.h \
    warehousemanage/inventorycheck/importcheckhistory/importcheckhistory.h \
    warehousemanage/inventorychange/inventorychange.h \
    warehousemanage/inventorychange/inventorylog/inventorylog.h \
    warehousemanage/inventorychange/inventorydet/inventorydet.h \
    warehousemanage/costadjustment/costadjustment.h \
    warehousemanage/costadjustment/costprice/costprice.h \
    warehousemanage/costadjustment/addcostmaterial/addcostmaterial.h \
    warehousemanage/costadjustment/materialcostinfo/materialcostinfo.h \
    warehousemanage/inventorylimit/inventorylimit.h \
    warehousemanage/inventorylimit/limitmatinfo/defaultlimitinfo.h \
    warehousemanage/inventorylimit/setdefaultlimit/setdefaultlimit.h \
    warehousemanage/inventorytransfer/inventorytransfer.h \
    warehousemanage/inventorytransfer/addtranmaterial/addtranmaterial.h \
    warehousemanage/inventorytransfer/materialtrandet/materialtrandet.h \
    warehousemanage/inventorytransfer/refusetranwidget/refusetranwidget.h \
    warehousemanage/inventorytransfer/extendtranemail/extendtranemail.h \
    warehousemanage/inventoryadjust/extendadjemail/extendadjemail.h \
    warehousemanage/inventorycheck/extendcheckemail/extendcheckemail.h \
    accountmanage/accountmanage.h \
    reporttable/selectwidget/selectwidget.h \
    version/versiondialog.h \
    purchasemanage/purchaseorder/extendpuremail/extendpuremail.h \
    purchasemanage/purreturngood/extendretemail/extendretemail.h \
    pushmessage/pushmessage.h \
    flowlayout/flowlayout.h \
    administermanage/administermanage.h \
    administermanage/editauthority/editauthority.h \
    administermanage/addauthority/addauthority.h \
    global/globaldef.h \
    global/message/message.h \
    global/postarg/postarg.h \
    httpclient/messageurl/messageurl.h \
    config/jsonconfig/jsonconfig.h \
    config/qreadwrite/qreadwriteini.h \
    accountmanage/accountexport/accountexport.h \
    purchasemanage/purchasestorage/extendstorage/extendstorage.h \
    checkupdate/checkupdate.h

FORMS    +=  mainwindow/mainwindow.ui \
    login/logindialog.ui \
    baseinfomanage/baseinfomanage.ui \
    warehousemanage/warehousemanage.ui \
    purchasemanage/purchasemanage.ui \
    todayhousemoney/todayhousemoney.ui \
    reporttable/reporttable.ui \
    baseinfomanage/materialsetup/materwidget/materialwidget.ui \
    baseinfomanage/materialsetup/materialcontrol/materialcontrol.ui \
    baseinfomanage/materialsetup/lookimage/lookimage.ui \
    baseinfomanage/materialsetup/addmaterial/addmaterial.ui \
    baseinfomanage/materialsetup/addunitsite/addunitsite.ui \
    baseinfomanage/materialsetup/materialtype/materialtype.ui \
    messagebox/messagedialog.ui \
    baseinfomanage/materialsetup/addunit/addunit.ui \
    baseinfomanage/materialsetup/exchangetype/exchangetype.ui \
    baseinfomanage/warehousesetup/warehousewidget/warehousewidget.ui \
    baseinfomanage/warehousesetup/addcommodity/addcommodity.ui \
    baseinfomanage/suppliersetup/supplierwidget/supplierwidget.ui \
    baseinfomanage/suppliersetup/supmaterial/supmaterial.ui \
    baseinfomanage/suppliersetup/addtype/addtype.ui \
    baseinfomanage/templatesetup/templatewidget/templatewidget.ui \
    baseinfomanage/templatesetup/edittemplate/edittemplate.ui \
    baseinfomanage/materialratiosetup/materialratiowidget/materialratiowidget.ui \
    baseinfomanage/materialratiosetup/selectmaterial/selectmaterial.ui \
    baseinfomanage/materialratiosetup/materialinfo/materialinfo.ui \
    purchasemanage/purchaseorder/purchaseorder.ui \
    purchasemanage/purchaseorder/addpurmaterial/addpurmaterial.ui \
    purchasemanage/purchaseorder/materialpurinfo/materialpurinfo.ui \
    purchasemanage/purchaseorder/confirmmat/confirmmat.ui \
    purchasemanage/purchaseorder/importhistory/importhistory.ui \
    purchasemanage/purchaseorder/templatepur/templatepur.ui \
    purchasemanage/purchasestorage/materialstoinfo/materialstoinfo.ui \
    purchasemanage/purchasestorage/addstomaterial/addstomaterial.ui \
    purchasemanage/purchasestorage/purchasestorage.ui \
    purchasemanage/purchasestorage/importallhistory/importallhistory.ui \
    purchasemanage/purchasestorage/refusewidget/refusewidget.ui \
    purchasemanage/purchasestorage/startreceive/startreceive.ui \
    purchasemanage/purchasestorage/subposition/subposition.ui \
    purchasemanage/loginfo/loginfo.ui \
    purchasemanage/purreturngood/purreturngood.ui \
    purchasemanage/purreturngood/addretmaterial/addretmaterial.ui \
    purchasemanage/purreturngood/materialretinfo/materialretinfo.ui \
    purchasemanage/purreturngood/subretposition/subretposition.ui \
    purchasemanage/purreturngood/importrethistory/importrethistory.ui \
    purchasemanage/purchasesafe/purchasesafe.ui \
    purchasemanage/purchasesafe/confirmsafemat/confirmsafemat.ui \
    materialsupplier/materialsupplier.ui \
    materialsupplier/defaultmatinfo/defaultmatinfo.ui \
    materialsupplier/setdefaultsup/setdefaultsup.ui \
    warehousemanage/realtimeinventory/realtimeinventory.ui \
    warehousemanage/timematinfo/timematinfo.ui \
    exportemail/exportemail.ui \
    warehousemanage/inventoryadjust/inventoryadjust.ui \
    warehousemanage/inventoryadjust/addadjmaterial/addadjmaterial.ui \
    warehousemanage/inventoryadjust/materialadjinfo/materialadjinfo.ui \
    reasonwidget/reasonwidget.ui \
    warehousemanage/inventorycheck/inventorycheck.ui \
    warehousemanage/inventorycheck/materialcheckinfo/materialcheckinfo.ui \
    warehousemanage/inventorycheck/addcheckmat/addcheckmat.ui \
    warehousemanage/inventorycheck/materialchectdet/materialcheckdet.ui \
    warehousemanage/inventorycheck/importcheckhistory/importcheckhistory.ui \
    warehousemanage/inventorychange/inventorychange.ui \
    warehousemanage/inventorychange/inventorylog/inventorylog.ui \
    warehousemanage/inventorychange/inventorydet/inventorydet.ui \
    warehousemanage/costadjustment/costadjustment.ui \
    warehousemanage/costadjustment/costprice/costprice.ui \
    warehousemanage/costadjustment/addcostmaterial/addcostmaterial.ui \
    warehousemanage/costadjustment/materialcostinfo/materialcostinfo.ui \
    warehousemanage/inventorylimit/inventorylimit.ui \
    warehousemanage/inventorylimit/limitmatinfo/defaultlimitinfo.ui \
    warehousemanage/inventorylimit/setdefaultlimit/setdefaultlimit.ui \
    warehousemanage/inventorytransfer/inventorytransfer.ui \
    warehousemanage/inventorytransfer/addtranmaterial/addtranmaterial.ui \
    warehousemanage/inventorytransfer/materialtrandet/materialtrandet.ui \
    warehousemanage/inventorytransfer/refusetranwidget/refusetranwidget.ui \
    warehousemanage/inventorytransfer/extendtranemail/extendtranemail.ui \
    warehousemanage/inventoryadjust/extendadjemail/extendadjemail.ui \
    warehousemanage/inventorycheck/extendcheckemail/extendcheckemail.ui \
    accountmanage/accountmanage.ui \
    reporttable/selectwidget/selectwidget.ui \
    version/versiondialog.ui \
    purchasemanage/purchaseorder/extendpuremail/extendpuremail.ui \
    purchasemanage/purreturngood/extendretemail/extendretemail.ui \
    pushmessage/pushmessage.ui \
    administermanage/administermanage.ui \
    administermanage/editauthority/editauthority.ui \
    administermanage/addauthority/addauthority.ui \
    accountmanage/accountexport/accountexport.ui \
    purchasemanage/purchasestorage/extendstorage/extendstorage.ui \
    checkupdate/checkupdate.ui

RESOURCES += \
    res.qrc

RC_FILE += myapp.rc

TRANSLATIONS += english.ts\
                chinese.ts

QMAKE_CXXFLAGS +=  -Wno-unused-parameter
