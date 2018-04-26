#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/***************************************************************
   功能:主窗口

   创建人:YYC

   创建时间:2017-11-22
**************************************************************/

#include <QMainWindow>
#include "baseinfomanage/baseinfomanage.h"
#include "warehousemanage/warehousemanage.h"
#include "purchasemanage/purchasemanage.h"
#include "todayhousemoney/todayhousemoney.h"
#include "reporttable/reporttable.h"
#include "materialsupplier/materialsupplier.h"
#include "accountmanage/accountmanage.h"
#include "version/versiondialog.h"
#include "pushmessage/pushmessage.h"
#include "administermanage/administermanage.h"
#include "checkupdate/checkupdate.h"
#include <QTranslator>

namespace Ui {
class MainWindow;
}

#define MAINWINDOW       MainWindow::getInstance()
#define MATERIALWIDGET   MainWindow::getInstance()->getBaseInfoManage().getMaterialWidget()
#define WARHSEWIDGET     MainWindow::getInstance()->getBaseInfoManage().getWareHouseWidget()
#define SUPWIDGET        MainWindow::getInstance()->getBaseInfoManage().getSupplierWidget()
#define TEMWIDGET        MainWindow::getInstance()->getBaseInfoManage().getTemplateWidget()
#define MATRATIOWIDGET   MainWindow::getInstance()->getBaseInfoManage().getMaterialRatioWidget()
#define PURORDERWIDGET   MainWindow::getInstance()->getPurchaseManage().getPurchaseOrder()
#define PURSTOWIDGET     MainWindow::getInstance()->getPurchaseManage().getPurchaseStorage()
#define PURRETWIDGET     MainWindow::getInstance()->getPurchaseManage().getPurReturnGood()
#define SAFRETWIDGET     MainWindow::getInstance()->getPurchaseManage().getPurchaseSafe()
#define DEFAULTWIDGET    MainWindow::getInstance()->getMatSupplier()
#define WAREHOUSEWIDGET  MainWindow::getInstance()->getWareHouseManage().getRealTimeInventory()
#define ADJUSTWIDGET     MainWindow::getInstance()->getWareHouseManage().getInventoryAdjust()
#define CHECKWIDGET      MainWindow::getInstance()->getWareHouseManage().getInventoryCheck()
#define CHANGEWIDGET     MainWindow::getInstance()->getWareHouseManage().getInventoryChange()
#define COSTWIDGET       MainWindow::getInstance()->getWareHouseManage().getCostAdjustment()
#define RESTWIDGET       MainWindow::getInstance()->getWareHouseManage().getInventoryLimit()
#define TRANWIDGET       MainWindow::getInstance()->getWareHouseManage().getInventoryTransfer()
#define ACCOUNTWIDGET    MainWindow::getInstance()->getAccountManage()
#define REPORTWIDGET     MainWindow::getInstance()->getReportTable()
#define TODAYWIDGET      MainWindow::getInstance()->getTodayHouseMoney()
#define ADMINISTERMANAGE MainWindow::getInstance()->getAdministerManage()


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    static MainWindow *getInstance();              //单例模式
    void setExeName(QString exeName);              //应用名称
    void exitExe(const Map &mapData);              //退出应用程序
    void checkUpdate();                            //检查更新
    void setStatusInfo();                          //设置状态栏信息
    void translateLanguage();                      //翻译
    void showError(QString errorMsg);              //显示错误信息
    void readJson(QNetworkReply *reply, int type); //解析json
    BaseInfoManage &getBaseInfoManage();           //获取基础管理对象
    PurchaseManage &getPurchaseManage();           //获取采购管理
    MaterialSupplier &getMatSupplier();            //获取原料供应商
    WareHouseManage &getWareHouseManage();         //获取库存管理
    AccountManage &getAccountManage();             //获取支出结算
    ReportTable &getReportTable();                 //今日报表
    TodayHouseMoney &getTodayHouseMoney();         //获取今日消费
    AdministerManage &getAdministerManage();       //获取权限管理

private slots:
    void closeNowTab(int index);                                 //关闭当前页
    void on_actionTodayHouseMoney_triggered();                   //今日入库金额
    void on_actionTableCenter_triggered();                       //报表中心
    void on_actionExit_triggered();                              //退出登录
    void on_actionBaseInfo_triggered();                          //基础功能
    void on_actionPurManage_triggered();                         //进货常用功能
    void on_actionWareHouseManage_triggered();                   //库管常用功能
    void on_actionMatSup_triggered();                            //原料供应商
    void on_actionAccount_triggered();                           //支出结算
    void on_actionSwitchLanguage_triggered();                    //切换语言
    void on_actionVersion_triggered();                           //版本信息
    void on_actionUpdate_triggered();                            //检查更新
    void updateClient();                                         //更新客户端
    void on_actionAdministrator_triggered();                     //管理员管理

private:
    Ui::MainWindow *ui;
    explicit MainWindow(QWidget *parent = 0);                    //构造函数
    ~MainWindow();                                               //析构函数

    static MainWindow * instance;
    BaseInfoManage  baseInfoManage;                              //基本信息管理
    WareHouseManage wareHouseManage;                             //仓库管理
    PurchaseManage purchaseManage;                               //采购管理
    TodayHouseMoney todayHouseMoney;                             //今日入库金额
    ReportTable     reportTable;                                 //报表中心
    MaterialSupplier matSupplier;                                //原料供应商
    AccountManage accountManage;                                 //支出结算
    VersionDialog versionDialog;                                 //版本信息
    AdministerManage administerManage;                           //权限管理
    PushMessage pushMessage;                                     //消息显示
    CheckUpdate checkUpdateWidget;                               //启动更新
    QString exeName;                                             //应用程序名称
    bool language;
    bool isAutoUpdateFlage;

    QString dataInfo;
    QString engDataInfo;
    void initControl();                                         //初始化控件
    void addTabWidget(QWidget *widget, const QString &title);   //添加窗口
};

#endif // MAINWINDOW_H
