#include "selectwidget.h"
#include "ui_selectwidget.h"
#include <QListView>
#include "httpclient/httpkey.h"
#include <QStringList>
#include <QDesktopWidget>
#include "messagebox/messagedialog.h"

/*********************  构造函数       *********************/
SelectWidget::SelectWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelectWidget), widgetType(0)
{
    ui->setupUi(this);

    this->initControl();
}

/*********************  析构函数       *********************/
SelectWidget::~SelectWidget()
{
    delete ui;
}

/*********************  显示窗口       *********************/
void SelectWidget::showWidget(int type)
{
    this->activateWindow();
    this->showMaximized();
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    this->clearInfo();
    widgetType = type;

    QStringList headerList;
    if(type == STO_GATHER_PAGE)
    {
        ui->labelState->setText(tr(" 单据状态："));
        ui->labelWareHouse->setText(tr(" 入库仓库："));
        ui->labelMatType->show();
        ui->comboBoxMatType->show();
        ui->lineEditMaterial->show();
        ui->labelSup->show();
        ui->comboBoxSupplier->show();
        ui->labelDateType->show();
        ui->comboBoxTimeType->show();
        ui->labelWareHouse->show();
        ui->comboBoxWareHouse->show();
        ui->labelState->show();
        ui->comboBoxState->show();
        for(int i = 0; i < buttonList.size(); i ++)
        {
            buttonList.at(i)->show();
        }

        headerList.append(tr("店铺名称"));
        headerList.append(tr("入库仓库"));
        headerList.append(tr("供应商"));
        headerList.append(tr("原料名称"));
        headerList.append(tr("原料分类"));
        headerList.append(tr("条形码"));
        headerList.append(tr("规格"));
        headerList.append(tr("数量"));
        headerList.append(tr("计价单位"));
        headerList.append(tr("金额"));
    }
    else if(type == STO_PAGE || type == RET_PAGE)
    {
        if(type == RET_PAGE) ui->labelWareHouse->setText(tr(" 退货仓库："));
        else ui->labelWareHouse->setText(tr(" 入库仓库："));

        ui->labelState->setText(tr(" 单据状态："));
        ui->labelMatType->setHidden(true);
        ui->comboBoxMatType->setHidden(true);
        ui->lineEditMaterial->setHidden(true);
        ui->labelDateType->show();
        ui->comboBoxTimeType->show();
        ui->labelWareHouse->show();
        ui->comboBoxWareHouse->show();

        ui->labelState->show();
        ui->comboBoxState->show();
        for(int i = 0; i < buttonList.size(); i ++)
        {
            buttonList.at(i)->show();
        }

        ui->labelSup->show();
        ui->comboBoxSupplier->show();

        headerList.append(tr("店铺名称"));
        headerList.append(tr("单号"));
        headerList.append(tr("单据业务日期"));
        headerList.append(tr("单机操作日期"));
        headerList.append(tr("状态"));
        headerList.append(tr("入库仓库"));
        headerList.append(tr("供应商"));
        headerList.append(tr("原料名称"));
        headerList.append(tr("原料分类"));
        headerList.append(tr("条形码"));
        headerList.append(tr("规格"));
        headerList.append(tr("入库单位"));
        headerList.append(tr("数量"));
        headerList.append(tr("计价单位"));
        headerList.append(tr("单价"));
        headerList.append(tr("金额"));
    }
    else if(type == ADJ_PAGE)
    {
        ui->labelMatType->setHidden(true);
        ui->comboBoxMatType->setHidden(true);
        ui->lineEditMaterial->setHidden(true);
        ui->labelSup->setHidden(true);
        ui->comboBoxSupplier->setHidden(true);
        ui->labelDateType->show();
        ui->comboBoxTimeType->show();
        ui->labelWareHouse->show();
        ui->comboBoxWareHouse->show();
        ui->labelState->setText(tr(" 调整类型："));
        ui->labelWareHouse->setText(tr(" 调整仓库："));

        for(int i = 0; i < buttonList.size(); i ++)
        {
            buttonList.at(i)->setHidden(true);
        }

        headerList.append(tr("店铺名称"));
        headerList.append(tr("单号"));
        headerList.append(tr("单据业务日期"));
        headerList.append(tr("单机操作日期"));
        headerList.append(tr("状态"));
        headerList.append(tr("调整仓库"));
        headerList.append(tr("调整类型"));
        headerList.append(tr("原料名称"));
        headerList.append(tr("原料分类"));
        headerList.append(tr("条形码"));
        headerList.append(tr("规格"));
        headerList.append(tr("入库单位"));
        headerList.append(tr("数量"));
        headerList.append(tr("计价单位"));
        headerList.append(tr("单价"));
        headerList.append(tr("金额"));
    }
    else if(type == CHECK_PAGE)
    {
        ui->labelMatType->setHidden(true);
        ui->comboBoxMatType->setHidden(true);
        ui->lineEditMaterial->setHidden(true);
        ui->labelSup->setHidden(true);
        ui->comboBoxSupplier->setHidden(true);
        ui->labelDateType->setHidden(true);
        ui->comboBoxTimeType->setHidden(true);
        ui->labelWareHouse->show();
        ui->comboBoxWareHouse->show();
        ui->labelState->show();
        ui->comboBoxState->show();
        ui->labelState->setText(tr(" 单据状态："));
        ui->labelWareHouse->setText(tr(" 盘存仓库："));

        for(int i = 0; i < buttonList.size(); i ++)
        {
            buttonList.at(i)->setHidden(true);
        }

        headerList.append(tr("店铺名称"));
        headerList.append(tr("单号"));
        headerList.append(tr("状态"));
        headerList.append(tr("盘存仓库"));
        headerList.append(tr("原料名称"));
        headerList.append(tr("原料分类"));
        headerList.append(tr("条形码"));
        headerList.append(tr("规格"));
        headerList.append(tr("盘存单位"));
        headerList.append(tr("账面数量"));
        headerList.append(tr("盘存数量"));
        headerList.append(tr("差异数量"));
        headerList.append(tr("计价单位"));
        headerList.append(tr("单价"));
        headerList.append(tr("盘存金额"));
        headerList.append(tr("差异金额"));
    }
    else if(type == CHECK_GATHER_PAGE)
    {
        ui->labelMatType->show();
        ui->comboBoxMatType->show();
        ui->lineEditMaterial->setHidden(true);
        ui->labelSup->setHidden(true);
        ui->comboBoxSupplier->setHidden(true);
        ui->labelDateType->setHidden(true);
        ui->comboBoxTimeType->setHidden(true);
        ui->labelState->setHidden(true);
        ui->comboBoxState->setHidden(true);
        ui->labelWareHouse->show();
        ui->comboBoxWareHouse->show();
        ui->labelState->setText(tr(" 单据状态："));
        ui->labelWareHouse->setText(tr(" 盘存仓库："));

        for(int i = 0; i < buttonList.size(); i ++)
        {
            buttonList.at(i)->setHidden(true);
        }

        headerList.append(tr("店铺名称"));
        headerList.append(tr("原料名称"));
        headerList.append(tr("原料分类"));
        headerList.append(tr("条形码"));
        headerList.append(tr("规格"));
        headerList.append(tr("计价单位"));
        headerList.append(tr("单价"));
        headerList.append(tr("盈亏金额"));
    }
    else if(type == SUP_PAGE)
    {
        ui->labelMatType->setHidden(true);
        ui->comboBoxMatType->setHidden(true);
        ui->lineEditMaterial->show();
        ui->labelSup->show();
        ui->comboBoxSupplier->show();
        ui->labelDateType->setHidden(true);
        ui->comboBoxTimeType->setHidden(true);
        ui->labelWareHouse->setHidden(true);
        ui->comboBoxWareHouse->setHidden(true);
        ui->labelState->show();
        ui->comboBoxState->show();
        ui->labelState->setText(tr(" 操作类型："));

        for(int i = 0; i < buttonList.size(); i ++)
        {
            buttonList.at(i)->show();
        }

        headerList.append(tr("店铺名称"));
        headerList.append(tr("供应商编码"));
        headerList.append(tr("供应商名称"));
        headerList.append(tr("操作时间"));
        headerList.append(tr("操作"));
        headerList.append(tr("原料名称"));
        headerList.append(tr("原料分类"));
        headerList.append(tr("条形码"));
        headerList.append(tr("规格"));
        headerList.append(tr("计价单位"));
        headerList.append(tr("数量"));
        headerList.append(tr("金额"));
    }
    else if(type == SUP_GATHER_PAGE)
    {
        ui->labelMatType->show();
        ui->comboBoxMatType->show();
        ui->lineEditMaterial->show();
        ui->labelSup->show();
        ui->comboBoxSupplier->show();
        ui->labelWareHouse->setHidden(true);
        ui->comboBoxWareHouse->setHidden(true);
        ui->labelDateType->setHidden(true);
        ui->comboBoxTimeType->setHidden(true);
        ui->labelState->show();
        ui->comboBoxState->show();
        ui->labelState->setText(tr(" 操作类型："));

        for(int i = 0; i < buttonList.size(); i ++)
        {
            buttonList.at(i)->show();
        }

        headerList.append(tr("店铺名称"));
        headerList.append(tr("供应商编码"));
        headerList.append(tr("供应商名称"));
        headerList.append(tr("操作"));
        headerList.append(tr("原料名称"));
        headerList.append(tr("原料分类"));
        headerList.append(tr("条形码"));
        headerList.append(tr("规格"));
        headerList.append(tr("计价单位"));
        headerList.append(tr("单价"));
        headerList.append(tr("数量"));
        headerList.append(tr("金额"));
    }
    else if(type == MAT_SELECT_PAGE)
    {
        ui->labelMatType->setHidden(true);
        ui->comboBoxMatType->setHidden(true);
        ui->labelSup->setHidden(true);
        ui->comboBoxSupplier->setHidden(true);
        ui->labelWareHouse->setHidden(true);
        ui->comboBoxWareHouse->setHidden(true);
        ui->labelDateType->setHidden(true);
        ui->comboBoxTimeType->setHidden(true);
        ui->labelState->setHidden(true);
        ui->comboBoxState->setHidden(true);
        ui->lineEditMaterial->show();

        for(int i = 0; i < buttonList.size(); i ++)
        {
            buttonList.at(i)->show();
        }

        headerList.append(tr("点餐单号"));
        headerList.append(tr("菜品名称"));
        headerList.append(tr("原料名称"));
        headerList.append(tr("数量"));
        headerList.append(tr("单价"));
        headerList.append(tr("配比单位"));
        headerList.append(tr("仓库单位"));
        headerList.append(tr("总金额"));
        headerList.append(tr("销售时间"));
    }

    ui->tableWidget->setColumnCount(headerList.size());
    ui->tableWidget->setHorizontalHeaderLabels(headerList);

    for(int i = 0; i < headerList.size(); i ++)
    {
        ui->tableWidget->setColumnWidth(i, 220);
    }

    if(headerList.size() * 220 < QApplication::desktop()->width())
    {
        ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    }
}

/*********************  设置控件数据       *********************/
void SelectWidget::setControlData()
{
    ui->comboBoxState->clear();
    if(widgetType == ADJ_PAGE)
    {
        for(int  i = 0; i < mapListState.size(); i ++)
        {
            QString stateName = mapListState.at(i).value(HTTPKEY::TYPENAME);

            if(CONFIGJSON->getLanguage().toInt())
            {
                if(stateName == GLOBALDEF::CHIALL)             stateName = GLOBALDEF::ENGALL;
                else if(stateName == GLOBALDEF::CHIDISTRIBUTE) stateName = GLOBALDEF::ENGDISTRIBUTE;
                else if(stateName == GLOBALDEF::CHIRECEIVED)   stateName = GLOBALDEF::ENGRECEIVED;
                else if(stateName == GLOBALDEF::CHIREJECT)     stateName = GLOBALDEF::ENGREJECT;
            }
            ui->comboBoxState->addItem(stateName);
        }
    }
    else if(widgetType == SUP_PAGE || widgetType == SUP_GATHER_PAGE)
    {
        for(int  i = 0; i < mapListState.size(); i ++)
        {
            QString stateName = mapListState.at(i).value(HTTPKEY::OPERATIONNAME);

            if(CONFIGJSON->getLanguage().toInt())
            {
                if(stateName == GLOBALDEF::CHIALL)          stateName = GLOBALDEF::ENGALL;
                else if(stateName == GLOBALDEF::CHISTORAGE) stateName = GLOBALDEF::ENGSTORAGE;
                else if(stateName == GLOBALDEF::CHIRETURNS) stateName = GLOBALDEF::ENGRETURNS;
            }
            ui->comboBoxState->addItem(stateName);
        }
    }
    else
    {
        for(int  i = 0; i < mapListState.size(); i ++)
        {
            QString stateName = mapListState.at(i).value(HTTPKEY::STATENAME);

            if(CONFIGJSON->getLanguage().toInt())
            {
                if(stateName == GLOBALDEF::CHIALL)             stateName = GLOBALDEF::ENGALL;
                else if(stateName == GLOBALDEF::CHIUNSUBMIT)   stateName = GLOBALDEF::ENGUNSUBMIT;
                else if(stateName == GLOBALDEF::CHICOMPLETE)   stateName = GLOBALDEF::ENGCOMPLETE;
                else if(stateName == GLOBALDEF::CHIRECEIVED)   stateName = GLOBALDEF::ENGRECEIVED;
                else if(stateName == GLOBALDEF::CHIREJECT)     stateName = GLOBALDEF::ENGREJECT;
                else if(stateName == GLOBALDEF::CHIDISTRIBUTE) stateName = GLOBALDEF::ENGDISTRIBUTE;
                else if(stateName == GLOBALDEF::CHIRETURN)     stateName = GLOBALDEF::ENGRETURN;
                else if(stateName == GLOBALDEF::CHIINVENT)     stateName = GLOBALDEF::ENGINVENT;
                else if(stateName == GLOBALDEF::CHIINVENTD)    stateName = GLOBALDEF::ENGINVENTD;
            }
            ui->comboBoxState->addItem(stateName);
        }
    }

    ui->comboBoxSupplier->clear();
    for(int  i = 0; i < mapListSupplier.size(); i ++)
    {
        QString supName = mapListSupplier.at(i).value(HTTPKEY::SUPPLIERNAME);

        if(CONFIGJSON->getLanguage().toInt())
        {
            if(supName == GLOBALDEF::CHIALL)  supName = GLOBALDEF::ENGALL;
        }
        ui->comboBoxSupplier->addItem(supName);
    }

    ui->comboBoxWareHouse->clear();
    for(int  i = 0; i < mapListWareHouse.size(); i ++)
    {
        QString whseName = mapListWareHouse.at(i).value(HTTPKEY::WAREHOUSENAME);

        if(CONFIGJSON->getLanguage().toInt())
        {
            if(whseName == GLOBALDEF::CHIALL)  whseName = GLOBALDEF::ENGALL;
        }

        ui->comboBoxWareHouse->addItem(whseName);
    }

    ui->comboBoxTimeType->clear();
    for(int  i = 0; i < typeList.size(); i ++)
    {
        QString typeName = typeList.at(i);

        if(CONFIGJSON->getLanguage().toInt())
        {
            if(typeName == GLOBALDEF::CHIBUSINESS)  typeName = GLOBALDEF::ENGBUSINESS;
            if(typeName == GLOBALDEF::CHIOPERATION) typeName = GLOBALDEF::ENGOPERATION;
        }

        ui->comboBoxTimeType->addItem(typeName);
    }

    ui->comboBoxMatType->clear();
    for(int  i = 0; i < mapListMatCat.size(); i ++)
    {
        QString matTypeName = mapListMatCat.at(i).value(HTTPKEY::CATEGORYNAME);

        if(CONFIGJSON->getLanguage().toInt())
        {
            if(matTypeName == GLOBALDEF::CHIALL)  matTypeName = GLOBALDEF::ENGALL;
        }

        ui->comboBoxMatType->addItem(matTypeName);
    }
}

/*********************  设置表格数据       *********************/
void SelectWidget::setTableData()
{
    ui->tableWidget->setRowCount(mapListData.size());
    if(widgetType == STO_PAGE || widgetType == RET_PAGE || widgetType == ADJ_PAGE)
    {
        for(int i = 0; i < mapListData.size(); i ++)
        {
            ui->tableWidget->setItem(i, ZERO,       DATA(mapListData.at(i).value(HTTPKEY::STORAGENAME)));
            ui->tableWidget->setItem(i, ONE,        DATA(mapListData.at(i).value(HTTPKEY::ORDERNUMBER)));
            ui->tableWidget->setItem(i, TWO,        DATA(QDateTime::fromTime_t(mapListData.at(i).value(HTTPKEY::BUSINESSTIME).toUInt()).toString("yyyy-MM-dd")));
            ui->tableWidget->setItem(i, THREE,      DATA(QDateTime::fromTime_t(mapListData.at(i).value(HTTPKEY::OPERATIONTIME).toUInt()).toString("yyyy-MM-dd")));

            QString stateText;
            switch(mapListData.at(i).value(HTTPKEY::STATE).toInt())
            {
            case ZERO:stateText = tr("配送中");break;
            case ONE: stateText = tr("已收货");break;
            case TWO: stateText = tr("已拒绝");break;
            }

            if(widgetType == ADJ_PAGE)
            {
                stateText = mapListData.at(i).value(HTTPKEY::STATE).toInt() == 0 ? tr("未提交") : tr("已调整");
            }
            else if(widgetType == RET_PAGE)
            {
                stateText = mapListData.at(i).value(HTTPKEY::STATE).toInt() == 0 ? tr("未提交") : tr("退货完成");
            }

            ui->tableWidget->setItem(i, FOUR,       DATA(stateText));
            ui->tableWidget->setItem(i, FIVE,       DATA(mapListData.at(i).value(HTTPKEY::WAREHOUSENAME)));

            if(widgetType == ADJ_PAGE)
            {
                ui->tableWidget->setItem(i, SIX,    DATA(mapListData.at(i).value(HTTPKEY::TYPENAME)));
            }
            else
            {
                ui->tableWidget->setItem(i, SIX,    DATA(mapListData.at(i).value(HTTPKEY::SUPPLIERNAME)));
            }

            ui->tableWidget->setItem(i, SEVEN,      DATA(mapListData.at(i).value(HTTPKEY::MATERIALNAME)));
            ui->tableWidget->setItem(i, EIGHT,      DATA(mapListData.at(i).value(HTTPKEY::MATERIALCATEGORYNAME)));
            ui->tableWidget->setItem(i, NINE,       DATA(mapListData.at(i).value(HTTPKEY::BARCODE)));
            ui->tableWidget->setItem(i, TEN,        DATA(mapListData.at(i).value(HTTPKEY::STANDARD)));
            ui->tableWidget->setItem(i, ELEVEN,     DATA(mapListData.at(i).value(HTTPKEY::UNITNAME)));
            ui->tableWidget->setItem(i, TWELEVE,    DATA(mapListData.at(i).value(HTTPKEY::NUMBER)));
            ui->tableWidget->setItem(i, THIRTHTEEN, DATA(mapListData.at(i).value(HTTPKEY::ISPRICEUNITNAME)));
            ui->tableWidget->setItem(i, FOURTHTEEN, DATA(mapListData.at(i).value(HTTPKEY::PRICE)));
            ui->tableWidget->setItem(i, FIFTHTEEN,  DATA(mapListData.at(i).value(HTTPKEY::TOTALMONEY)));

            for(int j = 0; j < ui->tableWidget->columnCount(); j ++)
            {
                SETTABLECENTER(ui->tableWidget->item(i, j));
            }
        }
    }
    else if(widgetType == STO_GATHER_PAGE)
    {
        for(int i = 0; i < mapListData.size(); i ++)
        {
            ui->tableWidget->setItem(i, ZERO,  DATA(mapListData.at(i).value(HTTPKEY::STORAGENAME)));
            ui->tableWidget->setItem(i, ONE,   DATA(mapListData.at(i).value(HTTPKEY::WAREHOUSENAME)));
            ui->tableWidget->setItem(i, TWO,   DATA(mapListData.at(i).value(HTTPKEY::SUPPLIERNAME)));
            ui->tableWidget->setItem(i, THREE, DATA(mapListData.at(i).value(HTTPKEY::MATERIALNAME)));
            ui->tableWidget->setItem(i, FOUR,  DATA(mapListData.at(i).value(HTTPKEY::MATERIALCATEGORYNAME)));
            ui->tableWidget->setItem(i, FIVE,  DATA(mapListData.at(i).value(HTTPKEY::BARCODE)));
            ui->tableWidget->setItem(i, SIX,   DATA(mapListData.at(i).value(HTTPKEY::STANDARD)));
            ui->tableWidget->setItem(i, SEVEN, DATA(mapListData.at(i).value(HTTPKEY::NUMBER)));
            ui->tableWidget->setItem(i, EIGHT, DATA(mapListData.at(i).value(HTTPKEY::ISPRICEUNITNAME)));
            ui->tableWidget->setItem(i, NINE,  DATA(mapListData.at(i).value(HTTPKEY::TOTALMONEY)));

            for(int j = 0; j < ui->tableWidget->columnCount(); j ++)
            {
                SETTABLECENTER(ui->tableWidget->item(i, j));
            }
        }
    }
    else if(widgetType == CHECK_PAGE)
    {
        for(int i = 0; i < mapListData.size(); i ++)
        {
            ui->tableWidget->setItem(i, ZERO,       DATA(mapListData.at(i).value(HTTPKEY::STORAGENAME)));
            ui->tableWidget->setItem(i, ONE,        DATA(mapListData.at(i).value(HTTPKEY::ORDERNUMBER)));
            QString stateText;
            switch(mapListData.at(i).value(HTTPKEY::STATE).toInt())
            {
            case ZERO:stateText = tr("盘存中");break;
            case ONE: stateText = tr("已盘存");break;
            case TWO: stateText = tr("取消盘存");break;
            }

            ui->tableWidget->setItem(i, TWO,        DATA(stateText));
            ui->tableWidget->setItem(i, THREE,      DATA(mapListData.at(i).value(HTTPKEY::WAREHOUSENAME)));
            ui->tableWidget->setItem(i, FOUR,       DATA(mapListData.at(i).value(HTTPKEY::MATERIALNAME)));
            ui->tableWidget->setItem(i, FIVE,       DATA(mapListData.at(i).value(HTTPKEY::MATERIALCATEGORYNAME)));
            ui->tableWidget->setItem(i, SIX,        DATA(mapListData.at(i).value(HTTPKEY::BARCODE)));
            ui->tableWidget->setItem(i, SEVEN,      DATA(mapListData.at(i).value(HTTPKEY::STANDARD)));
            ui->tableWidget->setItem(i, EIGHT,      DATA(mapListData.at(i).value(HTTPKEY::UNITNAME)));
            ui->tableWidget->setItem(i, NINE,       DATA(mapListData.at(i).value(HTTPKEY::PAPERNUMBER)));
            ui->tableWidget->setItem(i, TEN,        DATA(mapListData.at(i).value(HTTPKEY::REALITYNUMBER)));
            ui->tableWidget->setItem(i, ELEVEN,     DATA(mapListData.at(i).value(HTTPKEY::DIFFERENCENUMBER)));
            ui->tableWidget->setItem(i, TWELEVE,    DATA(mapListData.at(i).value(HTTPKEY::ISPRICEUNITNAME)));
            ui->tableWidget->setItem(i, THIRTHTEEN, DATA(mapListData.at(i).value(HTTPKEY::PRICE)));
            ui->tableWidget->setItem(i, FOURTHTEEN, DATA(mapListData.at(i).value(HTTPKEY::CHECKTOTALMONEY)));
            ui->tableWidget->setItem(i, FIFTHTEEN,  DATA(mapListData.at(i).value(HTTPKEY::DIFFERENCETOTALMONEY)));

            for(int j = 0; j < ui->tableWidget->columnCount(); j ++)
            {
                SETTABLECENTER(ui->tableWidget->item(i, j));
            }
        }
    }
    else if(widgetType == CHECK_GATHER_PAGE)
    {
        for(int i = 0; i < mapListData.size(); i ++)
        {
            ui->tableWidget->setItem(i, ZERO,   DATA(mapListData.at(i).value(HTTPKEY::STORAGENAME)));
            ui->tableWidget->setItem(i, ONE,    DATA(mapListData.at(i).value(HTTPKEY::MATERIALNAME)));
            ui->tableWidget->setItem(i, TWO,    DATA(mapListData.at(i).value(HTTPKEY::MATERIALCATEGORYNAME)));
            ui->tableWidget->setItem(i, THREE,  DATA(mapListData.at(i).value(HTTPKEY::BARCODE)));
            ui->tableWidget->setItem(i, FOUR,   DATA(mapListData.at(i).value(HTTPKEY::STANDARD)));
            ui->tableWidget->setItem(i, FIVE,   DATA(mapListData.at(i).value(HTTPKEY::ISPRICEUNITNAME)));
            ui->tableWidget->setItem(i, SIX,    DATA(mapListData.at(i).value(HTTPKEY::PRICE)));
            ui->tableWidget->setItem(i, SEVEN,  DATA(mapListData.at(i).value(HTTPKEY::EARNINGS)));

            for(int j = 0; j < ui->tableWidget->columnCount(); j ++)
            {
                SETTABLECENTER(ui->tableWidget->item(i, j));
            }
        }
    }
    else if(widgetType == SUP_PAGE)
    {
        for(int i = 0; i < mapListData.size(); i ++)
        {
            ui->tableWidget->setItem(i, ZERO,    DATA(mapListData.at(i).value(HTTPKEY::STORAGENAME)));
            ui->tableWidget->setItem(i, ONE,     DATA(mapListData.at(i).value(HTTPKEY::SUPPLIERNUM)));
            ui->tableWidget->setItem(i, TWO,     DATA(mapListData.at(i).value(HTTPKEY::SUPPLIERNAME)));
            ui->tableWidget->setItem(i, THREE,   DATA(QDateTime::fromTime_t(mapListData.at(i).value(HTTPKEY::OPERATIONTIME).toUInt()).toString("yyyy-MM-dd")));
            ui->tableWidget->setItem(i, FOUR,    DATA(mapListData.at(i).value(HTTPKEY::OPERATIONTYPE) == "1" ? tr("入库") : tr("退货")));
            ui->tableWidget->setItem(i, FIVE,    DATA(mapListData.at(i).value(HTTPKEY::MATERIALNAME)));
            ui->tableWidget->setItem(i, SIX,     DATA(mapListData.at(i).value(HTTPKEY::MATERIALCATEGORYNAME)));
            ui->tableWidget->setItem(i, SEVEN,   DATA(mapListData.at(i).value(HTTPKEY::BARCODE)));
            ui->tableWidget->setItem(i, EIGHT,   DATA(mapListData.at(i).value(HTTPKEY::STANDARD)));
            ui->tableWidget->setItem(i, NINE,    DATA(mapListData.at(i).value(HTTPKEY::ISPRICEUNITNAME)));
            ui->tableWidget->setItem(i, TEN,     DATA(mapListData.at(i).value(HTTPKEY::PRICE)));
            ui->tableWidget->setItem(i, ELEVEN,  DATA(mapListData.at(i).value(HTTPKEY::NUMBER)));
            ui->tableWidget->setItem(i, TWELEVE, DATA(mapListData.at(i).value(HTTPKEY::TOTALMONEY)));

            for(int j = 0; j < ui->tableWidget->columnCount(); j ++)
            {
                SETTABLECENTER(ui->tableWidget->item(i, j));
            }
        }
    }
    else if(widgetType == SUP_GATHER_PAGE)
    {
        for(int i = 0; i < mapListData.size(); i ++)
        {
            ui->tableWidget->setItem(i, ZERO,   DATA(mapListData.at(i).value(HTTPKEY::STORAGENAME)));
            ui->tableWidget->setItem(i, ONE,    DATA(mapListData.at(i).value(HTTPKEY::SUPPLIERNUM)));
            ui->tableWidget->setItem(i, TWO,    DATA(mapListData.at(i).value(HTTPKEY::SUPPLIERNAME)));
            ui->tableWidget->setItem(i, THREE,  DATA(mapListData.at(i).value(HTTPKEY::OPERATIONTYPE) == "1" ? tr("入库") : tr("退货")));
            ui->tableWidget->setItem(i, FOUR,   DATA(mapListData.at(i).value(HTTPKEY::MATERIALNAME)));
            ui->tableWidget->setItem(i, FIVE,   DATA(mapListData.at(i).value(HTTPKEY::MATERIALCATEGORYNAME)));
            ui->tableWidget->setItem(i, SIX,    DATA(mapListData.at(i).value(HTTPKEY::BARCODE)));
            ui->tableWidget->setItem(i, SEVEN,  DATA(mapListData.at(i).value(HTTPKEY::STANDARD)));
            ui->tableWidget->setItem(i, EIGHT,  DATA(mapListData.at(i).value(HTTPKEY::ISPRICEUNITNAME)));
            ui->tableWidget->setItem(i, NINE,   DATA(mapListData.at(i).value(HTTPKEY::PRICE)));
            ui->tableWidget->setItem(i, TEN,    DATA(mapListData.at(i).value(HTTPKEY::NUMBER)));
            ui->tableWidget->setItem(i, ELEVEN, DATA(mapListData.at(i).value(HTTPKEY::TOTALMONEY)));

            for(int j = 0; j < ui->tableWidget->columnCount(); j ++)
            {
                SETTABLECENTER(ui->tableWidget->item(i, j));
            }
        }
    }
    else if(widgetType == MAT_SELECT_PAGE)
    {
        for(int i = 0; i < mapListData.size(); i ++)
        {
            ui->tableWidget->setItem(i, ZERO,   DATA(mapListData.at(i).value(HTTPKEY::ORDERNUMBER)));
            ui->tableWidget->setItem(i, ONE,    DATA(mapListData.at(i).value(HTTPKEY::FOODNAME)));
            ui->tableWidget->setItem(i, TWO,    DATA(mapListData.at(i).value(HTTPKEY::MATERIALNAME)));
            ui->tableWidget->setItem(i, THREE,  DATA(mapListData.at(i).value(HTTPKEY::NUMBER)));
            ui->tableWidget->setItem(i, FOUR,   DATA(mapListData.at(i).value(HTTPKEY::PRICE)));
            ui->tableWidget->setItem(i, FIVE,   DATA(mapListData.at(i).value(HTTPKEY::UNITNAME)));
            ui->tableWidget->setItem(i, SIX,    DATA(mapListData.at(i).value(HTTPKEY::WAREHOUSEUNITNAME)));
            ui->tableWidget->setItem(i, SEVEN,  DATA(mapListData.at(i).value(HTTPKEY::TOTALMONEY)));
            ui->tableWidget->setItem(i, EIGHT,  DATA(mapListData.at(i).value(HTTPKEY::MARKETTIME)));

            for(int j = 0; j < ui->tableWidget->columnCount(); j ++)
            {
                SETTABLECENTER(ui->tableWidget->item(i, j));
            }
        }
    }

    if(mapListData.size() == 0)
    {
        MESSAGEBOX->showMessageBox(this, MESSAGE::NODATA);
    }
}

/*********************  初始化控件       *********************/
void SelectWidget::initControl()
{
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    buttonList.append(ui->pushButtonYesterday);
    buttonList.append(ui->pushButtonThisWeek);
    buttonList.append(ui->pushButtonLastWeek);
    buttonList.append(ui->pushButtonThisMonth);
    buttonList.append(ui->pushButtonLastMonth);

    ui->comboBoxState->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxSupplier->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxWareHouse->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxTimeType->setFocusPolicy(Qt::NoFocus);
    ui->comboBoxMatType->setFocusPolicy(Qt::NoFocus);

    ui->comboBoxState->setView(new QListView());
    ui->comboBoxSupplier->setView(new QListView());
    ui->comboBoxWareHouse->setView(new QListView());
    ui->comboBoxTimeType->setView(new QListView());
    ui->comboBoxMatType->setView(new QListView());

    ui->comboBoxState->view()->setMinimumWidth(200);
    ui->comboBoxSupplier->view()->setMinimumWidth(200);
    ui->comboBoxWareHouse->view()->setMinimumWidth(200);
    ui->comboBoxTimeType->view()->setMinimumWidth(200);
    ui->comboBoxMatType->view()->setMinimumWidth(200);

    ui->dateEditEndTime->setCalendarPopup(true);
    ui->dateEditStartTime->setCalendarPopup(true);

    ui->dateEditEndTime->setFocusPolicy(Qt::NoFocus);
    ui->dateEditStartTime->setFocusPolicy(Qt::NoFocus);

    SETTABLEWIDGET(ui->tableWidget);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    connect(&exportEmail, SIGNAL(sendEmail(QString)), this, SLOT(receiveEmailText(QString)));

    if(CONFIGJSON->getLanguage().toInt())
    {
        ui->dateEditStartTime->calendarWidget()->setLocale(QLocale(QLocale::English));
        ui->dateEditEndTime->calendarWidget()->setLocale(QLocale(QLocale::English));
    }

    //根据分辨率适配
    QDesktopWidget *desktop = QApplication::desktop();

    int height = 30;
    if(desktop->height() >= GLOBALDEF::DESKTOPHEIGHT)
    {
        this->setStyleSheet(GLOBALDEF::THISSTYLE);

        height = 30;
    }
    else
    {
        this->setStyleSheet(GLOBALDEF::SMALLSTYLE);
        height = 20;
    }

    ui->labelState->setMinimumHeight(height);
    ui->labelSup->setMinimumHeight(height);
    ui->labelWareHouse->setMinimumHeight(height);
    ui->labelMatType->setMinimumHeight(height);
    ui->labelDateType->setMinimumHeight(height);
    ui->labelBeginTime->setMinimumHeight(height);
    ui->labelEndTime->setMinimumHeight(height);

    FlowLayout *flowLayout = new FlowLayout(ui->widgetControl);

    flowLayout->addWidget(ui->labelState);
    flowLayout->addWidget(ui->comboBoxState);
    flowLayout->addWidget(ui->labelSup);
    flowLayout->addWidget(ui->comboBoxSupplier);
    flowLayout->addWidget(ui->labelWareHouse);
    flowLayout->addWidget(ui->comboBoxWareHouse);
    flowLayout->addWidget(ui->labelMatType);
    flowLayout->addWidget(ui->comboBoxMatType);
    flowLayout->addWidget(ui->labelDateType);
    flowLayout->addWidget(ui->comboBoxTimeType);
    flowLayout->addWidget(ui->labelBeginTime);
    flowLayout->addWidget(ui->dateEditStartTime);
    flowLayout->addWidget(ui->labelEndTime);
    flowLayout->addWidget(ui->dateEditEndTime);
    flowLayout->addWidget(ui->lineEditMaterial);
    flowLayout->addWidget(ui->pushButtonYesterday);
    flowLayout->addWidget(ui->pushButtonThisWeek);
    flowLayout->addWidget(ui->pushButtonLastWeek);
    flowLayout->addWidget(ui->pushButtonThisMonth);
    flowLayout->addWidget(ui->pushButtonLastMonth);
    flowLayout->addWidget(ui->pushButtonSelect);
    flowLayout->addWidget(ui->pushButtonExtendEmail);

    ui->widgetControl->setLayout(flowLayout);
}

/*********************  设置选中        *********************/
void SelectWidget::setCheckButton(QPushButton *button)
{
    if(NULL == button) return;
    for(int i = 0; i < buttonList.size(); i ++)
    {
        if(button != buttonList.at(i))
        {
            if(button->isChecked())
            {
                buttonList.at(i)->setChecked(false);
                buttonList.at(i)->setStyleSheet(GLOBALDEF::PUTON);
            }
        }
    }

    if(button->isChecked())
    {
        button->setStyleSheet(GLOBALDEF::PUTDOWN);
    }
    else
    {
        button->setStyleSheet(GLOBALDEF::PUTON);
    }
}

void SelectWidget::setMapListMatCat(const MapList &value)
{
    mapListMatCat = value;
}

void SelectWidget::setMapListData(const MapList &value)
{
    mapListData = value;
}

/*********************  设置时间        *********************/
void SelectWidget::setDateTime(QString name)
{
    QString strTime;
    for(int i = 0; i < mapListTime.size(); i ++)
    {
        if(mapListTime.at(i).value(HTTPKEY::NAME) == name)
        {
            strTime = mapListTime.at(i).value(HTTPKEY::TIME);
        }
    }

    if(!strTime.isEmpty())
    {
        QStringList strList = strTime.split(',');

        if(strList.size() >= TWO)
        {
            QString strBegin = strList.at(ZERO);
            ui->dateEditStartTime->setDate(QDateTime::fromTime_t(strBegin.toUInt()).date());

            QString strEnd = strList.at(ONE);
            ui->dateEditEndTime->setDate(QDateTime::fromTime_t(strEnd.toUInt()).date());
        }
    }
}

void SelectWidget::setTypeList(const List &value)
{
    typeList = value;
}

void SelectWidget::setMapListTime(const MapList &value)
{
    mapListTime = value;
}

void SelectWidget::setMapListWareHouse(const MapList &value)
{
    mapListWareHouse = value;
}

void SelectWidget::setMapListSupplier(const MapList &value)
{
    mapListSupplier = value;
}

void SelectWidget::setMapListState(const MapList &value)
{
    mapListState = value;
}

/*********************  昨日        *********************/
void SelectWidget::on_pushButtonYesterday_clicked()
{
    this->setCheckButton(ui->pushButtonYesterday);

    this->setDateTime("昨天");
}

/*********************  本周        *********************/
void SelectWidget::on_pushButtonThisWeek_clicked()
{
    this->setCheckButton(ui->pushButtonThisWeek);

    this->setDateTime("本周");
}

/*********************  上周        *********************/
void SelectWidget::on_pushButtonLastWeek_clicked()
{
    this->setCheckButton(ui->pushButtonLastWeek);
    this->setDateTime("上周");
}

/*********************  本月        *********************/
void SelectWidget::on_pushButtonThisMonth_clicked()
{
    this->setCheckButton(ui->pushButtonThisMonth);
    this->setDateTime("本月");
}

/*********************  上月        *********************/
void SelectWidget::on_pushButtonLastMonth_clicked()
{
    this->setCheckButton(ui->pushButtonLastMonth);
    this->setDateTime("上月");
}

/*********************  查询报表        *********************/
void SelectWidget::on_pushButtonSelect_clicked()
{
    if(ui->dateEditStartTime->dateTime().toTime_t() > ui->dateEditEndTime->dateTime().toTime_t())
    {
        MESSAGEBOX->showMessageBox(this, MESSAGE::STARTNOTEND);
        return;
    }

    selectExtend(true);
}

/*********************  查询或导出        *********************/
void SelectWidget::selectExtend(bool typeFlage)
{
    strTime = QString::number(ui->dateEditStartTime->dateTime().toTime_t()) + "," +
            QString::number(ui->dateEditEndTime->dateTime().toTime_t());

    if(widgetType == STO_GATHER_PAGE)
    {
        if(typeFlage)
        {
            if(ui->comboBoxState->currentIndex() < 0     || ui->comboBoxState->currentIndex() >= mapListState.size())         return;
            if(ui->comboBoxMatType->currentIndex() < 0   || ui->comboBoxMatType->currentIndex() >= mapListMatCat.size())      return;
            if(ui->comboBoxSupplier->currentIndex() < 0  || ui->comboBoxSupplier->currentIndex() >= mapListSupplier.size())   return;
            if(ui->comboBoxWareHouse->currentIndex() < 0 || ui->comboBoxWareHouse->currentIndex() >= mapListWareHouse.size()) return;
            if(ui->comboBoxTimeType->currentIndex() < 0  || ui->comboBoxTimeType->currentIndex() >= typeList.size())          return;

            matCatId    = mapListMatCat.at(ui->comboBoxMatType->currentIndex()).value(HTTPKEY::CATEGORYID);
            stateId     = mapListState.at(ui->comboBoxState->currentIndex()).value(HTTPKEY::STATEID);
            supplierId  = mapListSupplier.at(ui->comboBoxSupplier->currentIndex()).value(HTTPKEY::SUPPLIERID);
            wareHouseID = mapListWareHouse.at(ui->comboBoxWareHouse->currentIndex()).value(HTTPKEY::WAREHOUSEID);
            timeType    = QString::number(ui->comboBoxTimeType->currentIndex());
            materialText = ui->lineEditMaterial->text();

            HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STATE_STORAGE_GATHER)
                                  .arg(stateId, supplierId, wareHouseID, timeType, strTime, materialText, matCatId), PROTOCOL::URL_STATE_STORAGE_GATHER);
        }
        else
        {
            HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STATE_STO_GAT_EXTEND)
                                  .arg(stateId, supplierId, wareHouseID, timeType, strTime, materialText, matCatId, emailText), PROTOCOL::URL_STATE_STO_GAT_EXTEND);
        }
    }
    else if(widgetType == STO_PAGE || widgetType == RET_PAGE)
    {
        if(typeFlage)
        {
            if(ui->comboBoxState->currentIndex() < 0     || ui->comboBoxState->currentIndex() >= mapListState.size())         return;
            if(ui->comboBoxSupplier->currentIndex() < 0  || ui->comboBoxSupplier->currentIndex() >= mapListSupplier.size())   return;
            if(ui->comboBoxWareHouse->currentIndex() < 0 || ui->comboBoxWareHouse->currentIndex() >= mapListWareHouse.size()) return;
            if(ui->comboBoxTimeType->currentIndex() < 0  || ui->comboBoxTimeType->currentIndex() >= typeList.size())          return;

            stateId     = mapListState.at(ui->comboBoxState->currentIndex()).value(HTTPKEY::STATEID);
            supplierId  = mapListSupplier.at(ui->comboBoxSupplier->currentIndex()).value(HTTPKEY::SUPPLIERID);
            wareHouseID = mapListWareHouse.at(ui->comboBoxWareHouse->currentIndex()).value(HTTPKEY::WAREHOUSEID);
            timeType    = QString::number(ui->comboBoxTimeType->currentIndex());


            int urlType = widgetType == STO_PAGE ? PROTOCOL::URL_STATE_STORAGE : PROTOCOL::URL_STATE_RETURNS;

            HTTPCLIENT->getUrlReq(MESSAGEURL(urlType)
                                  .arg(stateId, supplierId, wareHouseID, timeType, strTime), urlType);
        }
        else
        {
            int urlType = widgetType == STO_PAGE ? PROTOCOL::URL_STATE_STORAGE_EXTEND : PROTOCOL::URL_STATE_RETURNS_EXTEND;

            HTTPCLIENT->getUrlReq(MESSAGEURL(urlType)
                                  .arg(stateId, supplierId, wareHouseID, timeType, strTime, emailText), urlType);
        }
    }
    else if(widgetType == ADJ_PAGE)
    {
        if(typeFlage)
        {
            if(ui->comboBoxState->currentIndex() < 0     || ui->comboBoxState->currentIndex() >= mapListState.size())         return;
            if(ui->comboBoxWareHouse->currentIndex() < 0 || ui->comboBoxWareHouse->currentIndex() >= mapListWareHouse.size()) return;
            if(ui->comboBoxTimeType->currentIndex() < 0  || ui->comboBoxTimeType->currentIndex() >= typeList.size())          return;

            typeId      = mapListState.at(ui->comboBoxState->currentIndex()).value(HTTPKEY::TYPEID);
            wareHouseID = mapListWareHouse.at(ui->comboBoxWareHouse->currentIndex()).value(HTTPKEY::WAREHOUSEID);
            timeType    = QString::number(ui->comboBoxTimeType->currentIndex());

            HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STATE_ADJUST)
                                  .arg(typeId, wareHouseID, timeType, strTime), PROTOCOL::URL_STATE_ADJUST);
        }
        else
        {
            HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STATE_ADJUST_EXTEND)
                                  .arg(typeId, wareHouseID, timeType, strTime, emailText), PROTOCOL::URL_STATE_ADJUST_EXTEND);
        }
    }
    else if(widgetType == CHECK_PAGE)
    {
        if(typeFlage)
        {
            if(ui->comboBoxState->currentIndex() < 0     || ui->comboBoxState->currentIndex() >= mapListState.size())         return;
            if(ui->comboBoxWareHouse->currentIndex() < 0 || ui->comboBoxWareHouse->currentIndex() >= mapListWareHouse.size()) return;

            stateId     = mapListState.at(ui->comboBoxState->currentIndex()).value(HTTPKEY::STATEID);
            wareHouseID = mapListWareHouse.at(ui->comboBoxWareHouse->currentIndex()).value(HTTPKEY::WAREHOUSEID);

            HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STATE_CHECK)
                                  .arg(stateId, wareHouseID, strTime), PROTOCOL::URL_STATE_CHECK);
        }
        else
        {
            HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STATE_CHECK_EXTEND)
                                  .arg(stateId, wareHouseID, strTime, emailText), PROTOCOL::URL_STATE_CHECK_EXTEND);
        }
    }
    else if(widgetType == CHECK_GATHER_PAGE)
    {
        if(typeFlage)
        {
            if(ui->comboBoxMatType->currentIndex() < 0   || ui->comboBoxMatType->currentIndex() >= mapListMatCat.size())      return;
            if(ui->comboBoxWareHouse->currentIndex() < 0 || ui->comboBoxWareHouse->currentIndex() >= mapListWareHouse.size()) return;

            matCatId    = mapListMatCat.at(ui->comboBoxMatType->currentIndex()).value(HTTPKEY::CATEGORYID);
            wareHouseID = mapListWareHouse.at(ui->comboBoxWareHouse->currentIndex()).value(HTTPKEY::WAREHOUSEID);

            HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STATE_CHECK_GATHER)
                                  .arg(matCatId, wareHouseID, strTime), PROTOCOL::URL_STATE_CHECK_GATHER);
        }
        else
        {
            HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STATE_CHK_GAT_EXTEND)
                                  .arg(matCatId, wareHouseID, strTime, emailText), PROTOCOL::URL_STATE_CHK_GAT_EXTEND);
        }
    }
    else if(widgetType == SUP_PAGE)
    {
        if(typeFlage)
        {
            if(ui->comboBoxState->currentIndex() < 0     || ui->comboBoxState->currentIndex() >= mapListState.size())         return;
            if(ui->comboBoxSupplier->currentIndex() < 0  || ui->comboBoxSupplier->currentIndex() >= mapListSupplier.size())   return;

            operationId  = mapListState.at(ui->comboBoxState->currentIndex()).value(HTTPKEY::OPERATIONID);
            supplierId  = mapListSupplier.at(ui->comboBoxSupplier->currentIndex()).value(HTTPKEY::SUPPLIERID);
            materialText = ui->lineEditMaterial->text();

            HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STATE_SUPPLIER)
                                  .arg(supplierId, operationId, strTime, materialText), PROTOCOL::URL_STATE_SUPPLIER);
        }
        else
        {
            HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STATE_SUPPLIER_EXTEND)
                                  .arg(supplierId, operationId, strTime, materialText, emailText), PROTOCOL::URL_STATE_SUPPLIER_EXTEND);
        }
    }
    else if(widgetType == SUP_GATHER_PAGE)
    {
        if(typeFlage)
        {
            if(ui->comboBoxState->currentIndex() < 0     || ui->comboBoxState->currentIndex() >= mapListState.size())         return;
            if(ui->comboBoxSupplier->currentIndex() < 0  || ui->comboBoxSupplier->currentIndex() >= mapListSupplier.size())   return;
            if(ui->comboBoxMatType->currentIndex() < 0  || ui->comboBoxMatType->currentIndex() >= mapListMatCat.size())   return;

            matCatId    = mapListMatCat.at(ui->comboBoxMatType->currentIndex()).value(HTTPKEY::CATEGORYID);
            operationId  = mapListState.at(ui->comboBoxState->currentIndex()).value(HTTPKEY::OPERATIONID);
            supplierId  = mapListSupplier.at(ui->comboBoxSupplier->currentIndex()).value(HTTPKEY::SUPPLIERID);
            materialText = ui->lineEditMaterial->text();

            HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STATE_SUP_GATHER)
                                  .arg(supplierId, matCatId, operationId, strTime, materialText), PROTOCOL::URL_STATE_SUP_GATHER);
        }
        else

        {
            HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STATE_SUP_GAT_EXTEND)
                                  .arg(supplierId, matCatId, operationId, strTime, materialText, emailText), PROTOCOL::URL_STATE_SUP_GAT_EXTEND);
        }
    }
    else if(widgetType == MAT_SELECT_PAGE)
    {
        if(typeFlage)
        {
            materialText = ui->lineEditMaterial->text();

            HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STATE_SELECT_MAT)
                                  .arg(strTime, materialText), PROTOCOL::URL_STATE_SELECT_MAT);
        }
        else
        {
            HTTPCLIENT->getUrlReq(MESSAGEURL(PROTOCOL::URL_STATE_SEL_MAT_EXTEND)
                                  .arg(strTime, materialText, emailText), PROTOCOL::URL_STATE_SEL_MAT_EXTEND);
        }
    }
}


/*********************  清空信息        *********************/
void SelectWidget::clearInfo()
{
    for(int i = 0; i < buttonList.size(); i ++)
    {
        buttonList.at(i)->setChecked(false);
        buttonList.at(i)->setStyleSheet(GLOBALDEF::PUTON);
    }

    mapListState.clear();
    mapListSupplier.clear();
    mapListWareHouse.clear();
    mapListTime.clear();
    mapListData.clear();
    mapListMatCat.clear();
    typeList.clear();

    ui->comboBoxState->clear();
    ui->comboBoxSupplier->clear();
    ui->comboBoxWareHouse->clear();
    ui->comboBoxTimeType->clear();
    ui->comboBoxMatType->clear();
    ui->lineEditMaterial->clear();

    matCatId.clear();
    stateId.clear();
    supplierId.clear();
    wareHouseID.clear();
    timeType.clear();
    strTime.clear();
    materialText.clear();
    operationId.clear();
    typeId.clear();
    emailText.clear();

    ui->dateEditEndTime->setDate(QDate::currentDate());
    ui->dateEditStartTime->setDate(QDate::currentDate());
}

/*********************  导出到邮箱        *********************/
void SelectWidget::on_pushButtonExtendEmail_clicked()
{
    exportEmail.showWidget();
}

/*********************  接收邮箱号        *********************/
void SelectWidget::receiveEmailText(QString emailText)
{
    this->emailText = emailText;
    selectExtend(false);
}
