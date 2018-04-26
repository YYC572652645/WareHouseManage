#ifndef TEMPLATEWIDGET_H
#define TEMPLATEWIDGET_H

/***************************************************************
   功能:模板设置

   创建人:YYC

   创建时间:2017-12-21
**************************************************************/

#include <QWidget>
#include <QNetworkReply>
#include "titlebar/titlebar.h"
#include "baseinfomanage/templatesetup/edittemplate/edittemplate.h"

namespace Ui {
class TemplateWidget;
}

class TemplateWidget : public QWidget
{
    Q_OBJECT

public:
    enum SAVETYPE{CICKTYPE, SELECTTYPE};
    enum SAVEDATATYPE{NOSAVE, HAVESAVE};
    explicit TemplateWidget(QWidget *parent = 0);            //构造函数
    ~TemplateWidget();                                       //析构函数

    void showWidget();                                       //显示窗口
    void readJson(QNetworkReply *reply, int type);           //解析JSON

private slots:
    void on_pushButtonAddTem_clicked();                      //添加模板
    void on_tableWidgetTemplate_clicked(const QModelIndex &index); //模板信息
    void on_pushButtonSave_clicked();                        //保存
    void on_pushButtonDelTem_clicked();                      //删除模板
    void on_pushButtonAddTemMatInfo_clicked();               //添加原料模板
    void on_pushButtonAddTemMat_clicked();                   //添加原料模板
    void on_pushButtonSaveInfo_clicked();                    //更新信息
    void on_pushButtonCancelInfo_clicked();                  //取消函数
    void on_pushButtonCancel_clicked();                      //取消函数
    void deleteMaterial();                                   //删除原料

private:
    Ui::TemplateWidget *ui;
    EditTemplate *addTemnplate;                              //添加模板原料
    EditTemplate *editTemnplate;                             //编辑模板原料
    QString templateId;                                      //模板ID
    int clickType;                                           //类型
    int saveType;                                            //保存类型
    void initControl();                                      //初始化控件
    void setTableTemplateData();                             //设置模板列表数据
    void setControlInfoData();                               //设置模板详情
    void clearInfo();                                        //清空信息
    QWidget *createWidget(QString matName, QString barCode); //创建信息面板
    bool selectType;
    MapList mapTemplateList;
    MapList mapItemList;
    QMap<QString, QString>mapTemDetail;
    QList<QPushButton *>pushButtonList;
};

#endif // TEMPLATEWIDGET_H
