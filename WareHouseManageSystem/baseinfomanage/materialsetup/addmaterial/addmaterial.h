#ifndef ADDMATERIAL_H
#define ADDMATERIAL_H
#include "titlebar/titlebar.h"
#include <QWidget>

/***************************************************************
   功能:添加原料

   创建人:YYC

   创建时间:2017-12-16
**************************************************************/

namespace Ui {
class AddMaterial;
}

class AddMaterial : public QWidget
{
    Q_OBJECT

public:
    explicit AddMaterial(QWidget *parent = 0);  //构造函数
    ~AddMaterial();                             //析构函数
    void showWidget();                          //显示窗口
    QString getMaterialName() const;            //获取原料名称

private slots:
    void on_pushButtonOk_clicked();             //确定按钮
    void on_pushButtonCancel_clicked();         //取消按钮

signals:
    void sendOk();                              //发送按钮

private:
    Ui::AddMaterial *ui;
    QString materialName;                       //原料名称

    TitleBar * titleBar;                        //标题栏
    void initControl();                         //初始化控件
    void resizeEvent(QResizeEvent *event);      //重置窗口大小
};

#endif // ADDMATERIAL_H
