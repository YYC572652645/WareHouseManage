#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "global/globaldef.h"
#include "httpclient/httpkey.h"
#include <QDebug>
#include <QProcess>
#include "messagebox/messagedialog.h"
#include <QMessageBox>

MainWindow * MainWindow::instance = NULL;

/*********************      构造函数           *******************/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
  ,ui(new Ui::MainWindow)
  ,language(false), isAutoUpdateFlage(false)
{
    ui->setupUi(this);
    this->initControl();
}

/*********************      析构函数            *******************/
MainWindow::~MainWindow()
{
    delete ui;
}

/*********************      初始化控件          *******************/
void MainWindow::initControl()
{
    //设置标题栏可关闭
    ui->tabWidgetContent->setTabsClosable(true);
    connect(ui->tabWidgetContent, SIGNAL(tabCloseRequested(int)), this, SLOT(closeNowTab(int)));
    this->setWindowTitle(GLOBALDEF::APPNAME);

    connect(&pushMessage, SIGNAL(updateClient()),   this, SLOT(updateClient()));
    connect(&checkUpdateWidget, SIGNAL(okUpdate()), this, SLOT(updateClient()));
}

/*********************      添加窗口            *******************/
void MainWindow::addTabWidget(QWidget *widget, const QString &title)
{
    if(NULL == widget) return;

    if(ui->tabWidgetContent->indexOf(widget) < 0)
    {
        ui->tabWidgetContent->addTab(widget, title);
    }
    ui->tabWidgetContent->setCurrentWidget(widget);
}

/************************   关闭当前页          ********************/
void MainWindow::closeNowTab(int index)
{
    ui->tabWidgetContent->removeTab(index);
}

/************************   今日入库金额         ********************/
void MainWindow::on_actionTodayHouseMoney_triggered()
{
    addTabWidget(&todayHouseMoney, GLOBALDEF::TODAYHOUSEMONEY);
    todayHouseMoney.showWidget();
}

/************************   报表中心            ********************/
void MainWindow::on_actionTableCenter_triggered()
{
    addTabWidget(&reportTable, GLOBALDEF::REPORTTABLE);
}

/************************   单例模式            ********************/
MainWindow *MainWindow::getInstance()
{
    if(NULL == instance)
    {
        instance = new MainWindow();
    }

    return instance;
}

/************************   应用名称            ********************/
void MainWindow::setExeName(QString exeName)
{
    this->exeName = exeName;
}

/************************   退出应用程序         ********************/
void MainWindow::exitExe(const Map &mapData)
{
    if(mapData.value(HTTPKEY::CODE).toInt()) return;

    QProcess process;
    process.startDetached(this->exeName, QStringList());

    this->close();
}

/************************   检查更新         ********************/
void MainWindow::checkUpdate()
{
    isAutoUpdateFlage = true;
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_UPDATE_CLIENT), PROTOCOL::URL_UPDATE_CLIENT);
}

/************************   设置状态栏信息            ********************/
void MainWindow::setStatusInfo()
{
    pushMessage.showWidget(language);
}

/************************   退出登录            ********************/
void MainWindow::on_actionExit_triggered()
{
    int ok = MESSAGEBOX->showMessageBox(this, tr("确认退出吗？"), true, false);

    if(ok != QDialog::Accepted) return;

    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_LOGIN_OUT), PROTOCOL::URL_LOGIN_OUT);
}

/************************   获取采购管理         ********************/
PurchaseManage &MainWindow::getPurchaseManage()
{
    return purchaseManage;
}

/************************   获取基础管理对象     ********************/
BaseInfoManage &MainWindow::getBaseInfoManage()
{
    return baseInfoManage;
}

/************************   基础功能     ********************/
void MainWindow::on_actionBaseInfo_triggered()
{
    addTabWidget(&baseInfoManage, GLOBALDEF::BASEINFO);
}

/************************   进货常用功能     ********************/
void MainWindow::on_actionPurManage_triggered()
{
    addTabWidget(&purchaseManage, GLOBALDEF::PURCHASEINFO);
}

/************************   库管常用功能     ********************/
void MainWindow::on_actionWareHouseManage_triggered()
{
    addTabWidget(&wareHouseManage, GLOBALDEF::WAREHOUSEINFO);
}

/************************   原料供应商     ********************/
void MainWindow::on_actionMatSup_triggered()
{
    addTabWidget(&matSupplier, GLOBALDEF::MATERIALSUPPLIER);
    matSupplier.showWidget();
}

/************************   获取库存管理     ********************/
WareHouseManage &MainWindow::getWareHouseManage()
{
    return wareHouseManage;
}

/************************   获取原料供应商     ********************/
MaterialSupplier &MainWindow::getMatSupplier()
{
    return matSupplier;
}

/*********************      获取支出结算       *******************/
AccountManage &MainWindow::getAccountManage()
{
    return accountManage;
}

/*********************      获取权限管理          *******************/
AdministerManage &MainWindow::getAdministerManage()
{
    return administerManage;
}

/*********************      支出结算          *******************/
void MainWindow::on_actionAccount_triggered()
{
    addTabWidget(&accountManage, GLOBALDEF::ACCOUNTMANAGE);
    accountManage.showWidget();
}

/*********************      今日报表          *******************/
ReportTable &MainWindow::getReportTable()
{
    return reportTable;
}

/*********************      获取今日消费            *******************/
TodayHouseMoney &MainWindow::getTodayHouseMoney()
{
    return todayHouseMoney;
}

/*********************      切换语言            *******************/
void MainWindow::on_actionSwitchLanguage_triggered()
{
    int ok = MESSAGEBOX->showMessageBox(this, tr("确认切换语言吗？"), true, false);

    if(ok != QDialog::Accepted) return;

    if(ui->actionSwitchLanguage->text() == "切换为英文")
    {
        CONFIGJSON->setLanguage("1");
    }
    else
    {
        CONFIGJSON->setLanguage("0");
    }
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_LOGIN_OUT), PROTOCOL::URL_LOGIN_OUT);
}

/*********************      版本信息            *******************/
void MainWindow::on_actionVersion_triggered()
{
    if(CONFIGJSON->getLanguage().toInt())
    {
        versionDialog.showWidget(engDataInfo);
    }
    else
    {
        versionDialog.showWidget(dataInfo);
    }
}

/*********************      检查更新            *******************/
void MainWindow::on_actionUpdate_triggered()
{
    isAutoUpdateFlage = false;
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_UPDATE_CLIENT), PROTOCOL::URL_UPDATE_CLIENT);
}

/*********************  更新客户端       *********************/
void MainWindow::updateClient()
{
    HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_LOGIN_OUT), PROTOCOL::URL_LOGIN_OUT);

    QStringList strList = this->exeName.split('\\');
    QString updatePath = this->exeName.remove(strList.last()) + "update.exe";

    QProcess process;
    process.startDetached(updatePath, QStringList());
}

/*********************  解析json       *********************/
void MainWindow::readJson(QNetworkReply *reply, int type)
{
    if(NULL == reply || reply->error() != QNetworkReply::NoError)
    {
        MAINWINDOW->setStatusInfo();
        return;
    }

    if(reply->error() == QNetworkReply::NoError)
    {
        QByteArray arrayData = reply->readAll();

        QJsonParseError err;
        QJsonDocument jsonDom = QJsonDocument::fromJson(QString(arrayData).toUtf8(), &err);

        qDebug()<<QString(arrayData);
        if(err.error == QJsonParseError::NoError)
        {
            QJsonObject jsonObject = jsonDom.object();

            if(type == PROTOCOL::URL_UPDATE_CLIENT)
            {
                QString strVersion  = jsonObject.value(HTTPKEY::VERSION).toString();
                dataInfo            = jsonObject.value(HTTPKEY::DATADATA).toString();
                engDataInfo         = jsonObject.value(HTTPKEY::ENGDATA).toString();

                if(!isAutoUpdateFlage)
                {
                    if(strVersion.toDouble() > GLOBALDEF::VERSION.toDouble())
                    {
                        if(CONFIGJSON->getLanguage().toInt())
                        {
                            checkUpdateWidget.showWidget(engDataInfo);
                        }
                        else
                        {
                            checkUpdateWidget.showWidget(dataInfo);
                        }
                    }
                    else
                    {
                        checkUpdateWidget.showWidget(NULL, true);
                    }
                }
                else
                {
                    if(strVersion.toDouble() > GLOBALDEF::VERSION.toDouble())
                    {
                        pushMessage.showUpdateWidget();
                    }
                }
            }

            reply->close();
        }
    }
}

/*********************  管理员管理       *********************/
void MainWindow::on_actionAdministrator_triggered()
{
    addTabWidget(&administerManage, GLOBALDEF::AUTHORITYMANAGE);
    administerManage.showWidget();
}

/*********************      翻译            *******************/
void MainWindow::translateLanguage()
{
    GLOBALDEF::APPNAME          = "WareHouse Management System";
    GLOBALDEF::SYSTEMPORT       = "system prompt";
    GLOBALDEF::NUMBERISNOTNULL  = "Consumption can not be empty!";
    GLOBALDEF::WARHOSISNOTNULL  = "whse name can not be empty!";
    GLOBALDEF::CONFIRMDEL       = "Confirm delete?";
    GLOBALDEF::CLEARSITEUNIT    = "Modify the main unit will empty sub-unit information, to continue?";
    GLOBALDEF::NETWORKERROR     = "Network Error";
    GLOBALDEF::ADDSUCCESS       = "added successfully";
    GLOBALDEF::DELSUCCESS       = "successfully deleted";
    GLOBALDEF::EDITSUCCESS      = "successfully modified";
    GLOBALDEF::SUBMITSUCCESS    = "submitted successfully";
    GLOBALDEF::IMPORTSUCCESS    = "import successful";
    GLOBALDEF::EXPORTSUCCESS    = "export successful";
    GLOBALDEF::EXITSUCCESS      = "return successful";
    GLOBALDEF::CONFIRMSUCCESS   = "acceptance successful";
    GLOBALDEF::MAKESUCCESS      = "generated successfully";
    GLOBALDEF::RECONFIRMSUCCESS = "anti-recognition success";
    GLOBALDEF::SUCCESS          = "success";
    GLOBALDEF::BASEINFO         = "basic function";
    GLOBALDEF::WAREHOUSEINFO    = "library commonly function";
    GLOBALDEF::PURCHASEINFO     = "purchase commonly used function";
    GLOBALDEF::CALESINFO        = "daily expenses settlement";
    GLOBALDEF::FINANCEINFO      = "financial system docking";
    GLOBALDEF::MATERIALSUPPLIER = "mat supplier";
    GLOBALDEF::USERINFO         = "user management";
    GLOBALDEF::PERMISSIONINFO   = "authority management";
    GLOBALDEF::TODAYHOUSEMONEY  = "amount of storage today";
    GLOBALDEF::REPORTTABLE      = "report center";
    GLOBALDEF::ACCOUNTMANAGE    = "payout";
    GLOBALDEF::MATERIALSETUP    = "mat setting";
    GLOBALDEF::LOOKIMAGE        = "picture preview";
    GLOBALDEF::ADDUNITSIDE      = "add sub-unit";
    GLOBALDEF::ADDMATERIALNAME  = "add name of mat";
    GLOBALDEF::SUPMATERIAL      = "supplier mat";
    GLOBALDEF::TABADDMATERIAL   = "add mat";
    GLOBALDEF::TABMATERIALINFO  = "mat info";
    GLOBALDEF::ADDUNITNAME      = "add unit name";
    GLOBALDEF::SELECTMATERIAL   = "choose mat";
    GLOBALDEF::MATRATIOSETUP    = "mat ratio management";
    GLOBALDEF::TEMPLATESETUP    = "template management";
    GLOBALDEF::ADDTEMMATERIAL   = "add template mat";
    GLOBALDEF::EDITTEMMATERIAL  = "edit template mat";
    GLOBALDEF::EXCHANGETYPEMORE = "batch edit type";
    GLOBALDEF::DELMATERIAL      = "delete mat";
    GLOBALDEF::EXCHANGETYPE     = "switch category";
    GLOBALDEF::DELETEDATA       = "delete data";
    GLOBALDEF::MATERIALTYPE     = "mat category";
    GLOBALDEF::SELECTIMAGE      = "select image";
    GLOBALDEF::IMAGETOOLTIP     = "Image size: less than or equal to 200k \n Picture format: jpg png ico jpeg bmp format";
    GLOBALDEF::SAVETEXT         = " save";
    GLOBALDEF::OKUPDATE         = " confirm change";
    GLOBALDEF::SIDETEXT         = "sub-unit";
    GLOBALDEF::MAXLIMITPOT      = "You can only add up to four sub-units";
    GLOBALDEF::WAREHOUSEMANAGE  = "whse management";
    GLOBALDEF::SUPPLIERMANAGE   = "supplier management";
    GLOBALDEF::ADDCOMMODITY     = "add good";
    GLOBALDEF::ADDCOMMODITYTYPE = "add product category";
    GLOBALDEF::ADDWARHOS        = "add warehouse";
    GLOBALDEF::WARHOSINFO       = "whse info";
    GLOBALDEF::ADDSUPPLIER      = "add supplier";
    GLOBALDEF::SUPPLIERINFO     = "supplier info";
    GLOBALDEF::ADDTEMPLATE      = "add template";
    GLOBALDEF::TEMPLATEINFO     = "template info";
    GLOBALDEF::SUPPLYMATINFO    = "currently offers %1 mat";
    GLOBALDEF::PLEASESELECT     = "please choose";
    GLOBALDEF::ADDSUPTYPE       = "add supplier category";
    GLOBALDEF::UPDATESUPTYPE    = "modify supplier category";
    GLOBALDEF::TOTALCOUNT       = "total %1 items";
    GLOBALDEF::ALLTYPE          = "all categories";
    GLOBALDEF::PURCHASEORDER    = "purchase order management";
    GLOBALDEF::ADDPURCHASE      = "add purchase order";
    GLOBALDEF::PURINFO          = "purchase order detail";
    GLOBALDEF::ADDPURMATERIAL   = "add purchasing mat";
    GLOBALDEF::EDITPURMATERIAL  = "edit purchase of mat";
    GLOBALDEF::ADDSTOMATERIAL   = "add storage mat";
    GLOBALDEF::EDITSTOMATERIAL  = "edit storage mat";
    GLOBALDEF::MATERIALINFO     = "mat info";
    GLOBALDEF::CONFIRMMAT       = "confirm the purchase of mat";
    GLOBALDEF::IMPORTHISTORY    = "import history order";
    GLOBALDEF::TEMPLATEPUR      = "template";
    GLOBALDEF::PURCHASESTORAGE  = "purchasing storage management";
    GLOBALDEF::ADDSTORAGE       = "add storage order";
    GLOBALDEF::STORAGEINFO      = "receipt detail";
    GLOBALDEF::REFUSEREASON     = "denial reason";
    GLOBALDEF::RECONFIRMREASON  = "anti-recognition of reason";
    GLOBALDEF::STARTRECEIVE     = "start acceptance";
    GLOBALDEF::STOEXTEND        = "storage list export";
    GLOBALDEF::SUBPOSITION      = "add sub-position";
    GLOBALDEF::LOGINFO          = "processing record";
    GLOBALDEF::ADDRETURN        = "add return order";
    GLOBALDEF::RETURNINFO       = "return detail";
    GLOBALDEF::SETDEFAULTSUP    = "set the default supplier in batch";
    GLOBALDEF::WAREHOUSESELECT  = "inventory select";
    GLOBALDEF::EXTEND           = "export";
    GLOBALDEF::TIMEINFO         = "stock detail";
    GLOBALDEF::EXPORTEMAIL      = "export to email";
    GLOBALDEF::ADDADJUST        = "add inventory adjustment list";
    GLOBALDEF::ADJUSTINFO       = "inventory adjustment order detail";
    GLOBALDEF::CHECKINFO        = "whse inventory detail";
    GLOBALDEF::ADDCHECK         = "add whse inventory";
    GLOBALDEF::ADJREASON        = "adjust reason";
    GLOBALDEF::CHECKMATERIAL    = "inventory of mat";
    GLOBALDEF::ADDCHECKMATERIAL = "add inventory mat";
    GLOBALDEF::INVENLOG         = "inventory change records";
    GLOBALDEF::INVENCHANGE      = "stock adjustment";
    GLOBALDEF::COSTINFO         = "cost adjustment list detail";
    GLOBALDEF::ADDCOST          = "add cost adjustment list";
    GLOBALDEF::TOTALONUMBER     = "total:%1 items";
    GLOBALDEF::COSTPRICESEE     = "cost list";
    GLOBALDEF::SETDEFAULTLIMIT  = "set the upper and lower inventory limits";
    GLOBALDEF::TRANINFO         = "transfer detail";
    GLOBALDEF::TRANADD          = "add transfer order";
    GLOBALDEF::SELECTTABLE      = "report center";
    GLOBALDEF::ADDRETURNMAT     = "add return mat";
    GLOBALDEF::EDIDRETURNMAT    = "edit the return mat";
    GLOBALDEF::AUTHORITYMANAGE  = "authority management";

    MESSAGE::NONET           = "No network at this time";
    MESSAGE::LOGINFAILMSG    = "Login failed";
    MESSAGE::SITEISEXIST     = "Sub-unit already exists, please choose again!";
    MESSAGE::CONVERNOTNULL   = "Conversion can not be empty, please confirm!";
    MESSAGE::PLEASESELECT    = "Please choose the sub unit!";
    MESSAGE::MAINSITENOTSAME = "Sub-unit can not be the same as the main unit, please choose again!";
    MESSAGE::SUPNAMEISNULL   = "Supplier name is empty!";
    MESSAGE::SUPNUMBERISNULL = "Supplier ID is empty!";
    MESSAGE::SUPPEOISNULL    = "Contact is empty!";
    MESSAGE::SUPPHONEISNULL  = "Cell phone number is empty!";
    MESSAGE::SUPTAXISNULL    = "Tax rate is empty!";
    MESSAGE::TEMNAMEISNULL   = "Template name is empty!";
    MESSAGE::TOTOLERROR      = "The sum of the total is equal to 100!";
    MESSAGE::PURMATMSG       = "There is a supplier of material can not be supplied, to continue?";
    MESSAGE::EMAILISWRONG    = "E-mail format is incorrect!";
    MESSAGE::NOSTOERROR      = "There is no sub-whse material, can no longer add sub-positions!";
    MESSAGE::NOPURMAT        = "No purchase of material, can not generate purchase orders!";
    MESSAGE::MAKEPURMAT      = "Do you want to generate a purchase order?";
    MESSAGE::PLEASESELECTMAT = "Please choose the material!";
    MESSAGE::SETSUPPLIER     = "%1 ingredients selected, confirm that you want to set the default supplier?";
    MESSAGE::PLEASESETSUP    = "Please select the material that need batch operation first!";
    MESSAGE::SUPCANNOTSET    = "If the set supplier does not supply the current material, it cannot be set. Confirm to continue?";
    MESSAGE::ISPRESENT       = "After the submission will be the appropriate inventory adjustment, to confirm it to submit it?";
    MESSAGE::STARTNOTEND     = "Start date can not be greater than the end date!";
    MESSAGE::RESTCANNOT      = "The upper limit must be greater than the lower limit!";
    MESSAGE::RESTUPNULL      = "After setting the upper limit can not be set to empty!";
    MESSAGE::RESTLONULL      = "Has set the lower limit can not be set to null!";
    MESSAGE::TRANCANOTSAME   = "Transfer out of whse and transferred to the whse can not be the same!";
    MESSAGE::CATCANNOTNULL   = "Material classification can not be empty!";
    MESSAGE::MAINNOTNULL     = "The main unit can not be empty!";
    MESSAGE::CANNOTMYSELF    = "Higher classification can not be their own!";
    MESSAGE::SUPCANNOTNULL   = "Supplier must fill!";
    MESSAGE::TYPECANNOTNULL  = "Type required!";
    MESSAGE::NODATA          = "No data currently!";
    MESSAGE::SUPNOTNULL      = "Suppliers can not be empty!";
    MESSAGE::WARHSENOTNULL   = "Whse can not be empty!";


    MESSAGE::DATAERROR         = "Data error!";
    MESSAGE::ADDERROR          = "Add failed!";
    MESSAGE::DELERROR          = "Failed to delete!";
    MESSAGE::EDITERROR         = "Failed to edit!";
    MESSAGE::SELECTERROR       = "Select failed!";
    MESSAGE::MATISEXSIT        = "Already exists the same raw material name!";
    MESSAGE::CATEXSITERROR     = "This category already exists!";
    MESSAGE::FIRSTDELCATMAT    = "Please delete the raw materials or warehouse containing the category!";
    MESSAGE::FIRSTDELCATCHILD  = "Please delete the sub-category!";
    MESSAGE::MOVETHISCAT       = "The materials that already exist under the superior category will all be moved to this category!";
    MESSAGE::REMOVECATMAT      = "Please remove the materials in the ratio of materials!";
    MESSAGE::REMOVEWARHSEMAT   = "Please remove the materials in the warehouse, forcibly deleted will clear the warehouse materials!";
    MESSAGE::UNITISEXIST       = "This unit already exists!";
    MESSAGE::UNITICANNOTDEL    = "The unit is in use, can not be deleted!";
    MESSAGE::EXTENDERROR       = "Export failed!";
    MESSAGE::WARNAMENOTEXIST   = "Warehouse name does not exist!";
    MESSAGE::WARNAMEEXIST      = "Warehouse name already exists!";

    MESSAGE::FIRSTREMOVEWARNAT = "Please remove the materials in the warehouse!";
    MESSAGE::SUPCATEXIST       = "Vendor category name already exists!";
    MESSAGE::SUPEXISTOTHERCAT  = "There are other suppliers under the supplier, not allowed to delete!";
    MESSAGE::PHONEERROR        = "Phone number format is incorrect!";
    MESSAGE::INVPHONEERROR     = "Invoice contact phone number format is incorrect!";
    MESSAGE::EMAILERROR        = "E-mail format is incorrect!";
    MESSAGE::SUPEXIST          = "The current supplier name already exists!";
    MESSAGE::SUPNUMBEREXIST    = "Supplier ID already exists!";
    MESSAGE::TEMNOTNULL        = "Template name can not be empty!";
    MESSAGE::TEMEXIST          = "Already exists the same purchase template name!";
    MESSAGE::MATEXIST          = "Can not be configured to repeat the material!";
    MESSAGE::FIRSTSETWAR       = "Please set up a production warehouse!";
    MESSAGE::PRICENOTZERO      = "Manually set the cost can not be 0!";
    MESSAGE::SUBWAREXIST       = "Have added the sub-positions, please choose again!";
    MESSAGE::SUBWARSAME        = "Sub-positions can not be repeated with the main warehouse, please choose again!";
    MESSAGE::WARINVING         = "Warehouse is inventory, the end or cancel inventory to complete the transfer!";
    MESSAGE::WARNOTEXIST       = "Warehouse does not exist!";
    MESSAGE::SUPNOTEXIST       = "The supplier does not exist!";
    MESSAGE::RECONFIRMNOTNULL  = "Anti-confirmed the reasons can not be empty!";
    MESSAGE::NOWWARINVING      = "Current warehouse inventory!";
    MESSAGE::WARMAYDEL         = "Transferred to the warehouse has been deleted or transferred out of the warehouse has been deleted!";
    MESSAGE::SUPNOTGIVEMAT     = "The supplier does not supply the raw material, can not be set!";
    MESSAGE::CHECKISEXIST      = "The warehouse already has an inventory list in inventory!";
    MESSAGE::TEMPLATEMATNULL   = "The template material is empty and cannot be used. Please go to the homepage - purchasing template settings page to confirm template information!";
    MESSAGE::INCOMINGNOTEXIST  = "The current purchase order or storage order does not exist!";
    MESSAGE::MATERIALNOTEXIST  = "The material does not exist！";
    MESSAGE::TRANSFERING       = "The warehouse is in inventory. Ending or canceling the inventory can complete the transfer!";
    MESSAGE::BARCODEEXIST      = "Barcode already exists!";
    MESSAGE::NUMBERNOTZERO     = "The number of warehousing cannot be 0!";
    MESSAGE::NOTSHOPLOGIN      = "The store is not logged in or the login is invalid!";
    MESSAGE::NOTADMINLOGIN     = "The administrator is not logged in or the login is invalid!";
    MESSAGE::NOPRIORITY        = "No permission to access!";
    MESSAGE::ADMINSTEREXIST    = "The administrator name already exists!";
    MESSAGE::MATNOTFINISH      = "The current warehouse orders have not fully accepted materials!";
    MESSAGE::ORDERNOMAT        = "The current order has no materials!";
    MESSAGE::OPERATEFAILED     = "Operation failed or raw material classification has not been modified!";
    MESSAGE::ERROR             = "Error！";

    MESSAGE::errorData[ZERO].errorText  = "login failed";
    MESSAGE::errorData[ONE].errorText   = "login successful";
    MESSAGE::errorData[TWO].errorText   = "data error";
    MESSAGE::errorData[THREE].errorText = "shop does not exist";

    MESSAGE::operType[ZERO].operText       = "form single";
    MESSAGE::operType[ONE].operText        = "submit";
    MESSAGE::operType[TWO].operText        = "anti-recognition";
    MESSAGE::operType[THREE].operText      = "purchasing completed";
    MESSAGE::operType[FOUR].operText       = "confirm that the purchase is automatically created";
    MESSAGE::operType[FIVE].operText       = "received";
    MESSAGE::operType[SIX].operText        = "refused to accept the goods";
    MESSAGE::operType[SEVEN].operText      = "return completed";
    MESSAGE::operType[EIGHT].operText      = "adjustment completed";
    MESSAGE::operType[NINE].operText       = "inventory completed";
    MESSAGE::operType[TEN].operText        = "cancel inventory";
    MESSAGE::operType[ELEVEN].operText     = "confirm price adjustment";
    MESSAGE::operType[TWELEVE].operText    = "refused to allocate";
    MESSAGE::operType[THIRTHTEEN].operText = "transfer completed";

    language = true;
    this->setWindowTitle(GLOBALDEF::APPNAME);
}

/*********************      显示错误信息            *******************/
void MainWindow::showError(QString errorMsg)
{
    MESSAGEBOX->showMessageBox(this, errorMsg);
}

