#ifndef EDITTEMPLATE_H
#define EDITTEMPLATE_H

/***************************************************************
   功能:编辑模板原料

   创建人:YYC

   创建时间:2017-12-21
**************************************************************/

#include <QWidget>
#include "titlebar/titlebar.h"

namespace Ui {
class EditTemplate;
}

class EditTemplate : public QWidget
{
    Q_OBJECT

public:
    explicit EditTemplate(QWidget *parent = 0); //构造函数
    ~EditTemplate();                            //析构函数
    void showWidget();                          //显示窗口
    void setMapMatList(const MapList &value);   //设置数据列表
    MapList getMapMatList() const;              //获取原料数据
    MapList getMapSelectList() const;           //获取选择的列表
    void setTemplateId(const QString &value);   //设置模板ID
    void setMapSelectList(const MapList &value);//设置选中原料

private slots:
    void on_pushButtonSave_clicked();           //保存事件
    void on_pushButtonCancel_clicked();         //取消事件
    void on_tableWidgetData_clicked(const QModelIndex &index); //单击选中
    void on_checkBoxAllSelect_clicked();        //设置全选

private:
    Ui::EditTemplate *ui;
    TitleBar * titleBar;                        //标题栏
    QString templateId;                         //模板ID
    void initControl();                         //初始化控件
    void resizeEvent(QResizeEvent *event);      //重置窗口大小
    QList<Map>mapMatList;                       //原料数据
    QList<Map>mapSelectList;                    //选中的数据
};

#endif // EDITTEMPLATE_H
