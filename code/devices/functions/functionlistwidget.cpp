#include "functionlistwidget.h"
#include <QAbstractItemView>
#include <qabstractitemview.h>
#include <QDialog>
#include <QMessageBox>

#define QDEBUG() qDebug()<<__FILE__<<__LINE__

FunctionListWidget::FunctionListWidget(QWidget *parent) : QWidget(parent)
{
    this->mainLayout = new QVBoxLayout();
    this->operationLayout = new QHBoxLayout();
    this->tableWidget = new QTableWidget();
    connect(tableWidget,SIGNAL(cellClicked(int,int)),this,SLOT(slotCellClicked(int,int)));
    init();
    this->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   // 不可编辑
    this->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  // #整行选中的方式
    mainLayout->addWidget(tableWidget);
    this->mainLayout->addLayout(operationLayout);
    this->setLayout(mainLayout);
}

void FunctionListWidget::init()
{
    QStringList headers;
    headers<<"Command"<<"Name"<<"Direction"<<"Operation";
    this->tableWidget->setColumnCount(4);
    this->tableWidget->setHorizontalHeaderLabels(headers);
    //    this->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    this->tableWidget->setAlternatingRowColors(true);
    //    this->tableWidget->verticalHeader()->setHidden(true);
    this->saveFunctionButton = new QPushButton("保存");
    connect(saveFunctionButton,SIGNAL(clicked(bool)),this,SLOT(slotSaveFunctions(bool)));
    this->addFunctionButton = new QPushButton("增加");
    connect(addFunctionButton,SIGNAL(clicked(bool)),this,SLOT(slotAdd(bool)));
    this->upmoveButton = new QPushButton("上移");
    connect(upmoveButton,SIGNAL(clicked(bool)),this,SLOT(slotUpMovedClicked(bool)));
    this->downmoveButton = new QPushButton("下移");
    connect(downmoveButton,SIGNAL(clicked(bool)),this,SLOT(slotDownMovedClicked(bool)));
    this->createButton = new QPushButton("生成");
    connect(createButton,SIGNAL(clicked(bool)),this,SLOT(slotCreateClicked(bool)));
    this->deleteButton = new QPushButton("删除");
    connect(deleteButton,SIGNAL(clicked(bool)),this,SLOT(slotDeleteClicked(bool)));

    this->operationLayout->addWidget(this->upmoveButton);
    this->operationLayout->addWidget(this->downmoveButton);
    this->operationLayout->addWidget(this->saveFunctionButton);
    this->operationLayout->addWidget(this->addFunctionButton);
    this->operationLayout->addWidget(this->createButton);
    this->operationLayout->addWidget(this->deleteButton);
}

void FunctionListWidget::slotUpdateDeviceID(DeviceInformation *deviceinfo, int id)
{
    h = deviceinfo;
    this->functionList.clear();
//    for(int i=0; )
    functionList.append(deviceinfo->getfunList());
    this->id = id;
    QDEBUG()<<functionList.size();
    updateFunctionUi();
}

void FunctionListWidget::slotEditClicked(FunctionStruct *f)
{
    PRINTLOG(f->getFunctionName());
    if(this->parameterWidget == NULL)
    {
        delete this->parameterWidget;
    }
    parameterWidget = new ParameterWidget(f);
    parameterWidget->exec();
}

void FunctionListWidget::slotSaveFunctions(bool)
{
    emit signalSavedFunctionlist(id,functionList);
}

void FunctionListWidget::slotAdd(bool)
{
    PRINTLOG("AddFunctions");
    this->addFunctionWidget = new AddFunctionsWidget(this->functionList);
    connect(this->addFunctionWidget,SIGNAL(signalAddFunctions(QList<FunctionStruct*>)),this,SLOT(slotAddFunctions(QList<FunctionStruct*>)));
    this->addFunctionWidget->exec();
}

void FunctionListWidget::updateFunctionUi()
{
    this->tableWidget->setRowCount(0);
    QDEBUG()<<tableWidget->rowCount();

    for(int i=0; i<functionList.size(); ++i)
    {
        QDEBUG()<<"functionName"<<functionList.at(i)->getFunctionName();
        QDEBUG()<<"公共指令:"<<functionList.at(i)->getVarIndex();

        int rowCount = tableWidget->rowCount();
        this->tableWidget->insertRow(rowCount);
        this->tableWidget->setItem(rowCount,0,new QTableWidgetItem(QString::number(functionList.at(i)->getVarIndex())));
        this->tableWidget->setItem(rowCount,1, new QTableWidgetItem(functionList.at(i)->getFunctionName()));
        this->tableWidget->setItem(rowCount,2,new QTableWidgetItem(QString::number(functionList.at(i)->getDirection())));
        MyPushButton *myButton = new MyPushButton(functionList.at(i));
        this->tableWidget->setCellWidget(rowCount,3,myButton);
        connect(myButton,SIGNAL(signalClicked(FunctionStruct*)),this,SLOT(slotEditClicked(FunctionStruct*)));
    }
}

void FunctionListWidget::slotAddFunctions(QList<FunctionStruct*> List)
{
    functionList.clear();
    functionList.append(List);
    updateFunctionUi();
}

void FunctionListWidget::slotUpMovedClicked(bool)
{
    PRINTLOG(this->tableWidget->currentRow());
    int currentRow = this->tableWidget->currentRow();
    if(currentRow > 0)
    {
        QTableWidgetItem *commandItem = tableWidget->takeItem(currentRow,COMMAND_COLUMN);
        QTableWidgetItem *nameItem = tableWidget->takeItem(currentRow,NAME_COLUMN);
        QTableWidgetItem *directionItem = tableWidget->takeItem(currentRow,DIRECTION_COLUMN);
        QTableWidgetItem *precommandItem = tableWidget->takeItem(currentRow-1,COMMAND_COLUMN);
        QTableWidgetItem *prenameItem = tableWidget->takeItem(currentRow-1,NAME_COLUMN);
        QTableWidgetItem *predirectionItem = tableWidget->takeItem(currentRow-1,DIRECTION_COLUMN);

        tableWidget->setItem(currentRow,COMMAND_COLUMN,precommandItem);
        tableWidget->setItem(currentRow,NAME_COLUMN,prenameItem);
        tableWidget->setItem(currentRow,DIRECTION_COLUMN,predirectionItem);
        tableWidget->setItem(currentRow -1,COMMAND_COLUMN,commandItem);
        tableWidget->setItem(currentRow -1,NAME_COLUMN,nameItem);
        tableWidget->setItem(currentRow -1,DIRECTION_COLUMN,directionItem);

        MyPushButton *currentPushButton = (MyPushButton *)(tableWidget->cellWidget(currentRow,OPERATION_COLUMN));
        MyPushButton *prePushButton = (MyPushButton *)(tableWidget->cellWidget(currentRow-1,OPERATION_COLUMN));
        FunctionStruct *f = currentPushButton->getFunctionStruct();

        currentPushButton->setFunctionStruct(prePushButton->getFunctionStruct());
        prePushButton->setFunctionStruct(f);

        functionList.insert(currentRow-1,functionList.takeAt(currentRow));

        this->tableWidget->selectRow(currentRow-1);
    }
    slotCellClicked(this->tableWidget->currentRow(), 0);
}

void FunctionListWidget::slotDownMovedClicked(bool)
{
    int currentRow = this->tableWidget->currentRow();
    int total = this->tableWidget->rowCount();
    PRINTLOG(this->tableWidget->currentRow());
    PRINTLOG("NEXT");

    if(currentRow < total-1 && currentRow >= 0)
    {

        QTableWidgetItem *commandItem = tableWidget->takeItem(currentRow,COMMAND_COLUMN);
        QTableWidgetItem *nameItem = tableWidget->takeItem(currentRow,NAME_COLUMN);
        QTableWidgetItem *directionItem = tableWidget->takeItem(currentRow,DIRECTION_COLUMN);
        QTableWidgetItem *nextcommandItem = tableWidget->takeItem(currentRow+1,COMMAND_COLUMN);
        QTableWidgetItem *nextnameItem = tableWidget->takeItem(currentRow+1,NAME_COLUMN);
        QTableWidgetItem *nextdirectionItem = tableWidget->takeItem(currentRow+1,DIRECTION_COLUMN);

        tableWidget->setItem(currentRow,COMMAND_COLUMN,nextcommandItem);
        tableWidget->setItem(currentRow,NAME_COLUMN,nextnameItem);
        tableWidget->setItem(currentRow,DIRECTION_COLUMN,nextdirectionItem);
        tableWidget->setItem(currentRow +1,COMMAND_COLUMN,commandItem);
        tableWidget->setItem(currentRow +1,NAME_COLUMN,nameItem);
        tableWidget->setItem(currentRow +1,DIRECTION_COLUMN,directionItem);

        MyPushButton *currentPushButton = (MyPushButton *)(tableWidget->cellWidget(currentRow,OPERATION_COLUMN));
        MyPushButton *nextPushButton = (MyPushButton *)(tableWidget->cellWidget(currentRow+1,OPERATION_COLUMN));
        FunctionStruct *f = currentPushButton->getFunctionStruct();
        currentPushButton->setFunctionStruct(nextPushButton->getFunctionStruct());
        nextPushButton->setFunctionStruct(f);
        functionList.insert(currentRow+1,functionList.takeAt(currentRow));
        this->tableWidget->selectRow(currentRow+1);
    }
    slotCellClicked(this->tableWidget->currentRow(), 0);
}

void FunctionListWidget::slotCreateClicked(bool)
{
    QString defaultFileName;

    if(h->getOtherPara())
    {
        defaultFileName = "A";
    }
    else
    {
        defaultFileName = "0";
    }
    if(h->getManufactureId().length() == MANUFACTUREIDLEN)
    {
        defaultFileName += h->getManufactureId();
    }
    else
    {
        QMessageBox::warning(this, "警告", "厂商ID格式错误");
        return;
    }

    if(QString::number(h->getPrimaryClassCode(), 16).length() == 1)
    {
        defaultFileName +="0" + QString::number(h->getPrimaryClassCode(), 16).toUpper();
    }
    else
    {
        defaultFileName += QString::number(h->getPrimaryClassCode(), 16).toUpper();
    }

    if(QString::number(h->getMinorClassCode(), 16).length() == 1)
    {
        defaultFileName += "0" + QString::number(h->getMinorClassCode(), 16).toUpper();
    }
    else
    {
        defaultFileName += QString::number(h->getMinorClassCode(), 16).toUpper();
    }

    if(h->getModelCode().length() == MODELIDLEN)
    {
        defaultFileName += h->getModelCode();
    }
    else
    {
        QMessageBox::warning(this, "警告", "型号ID格式错误");
        return;
    }
    defaultFileName += "0" + QString::number(h->getLinkWay(),16).toUpper();
    defaultFileName += "000000";

    QDEBUG()<<"文件名"<<defaultFileName;
    QString fileName = QFileDialog::getSaveFileName(this,"SaveFile",defaultFileName,"xml(*.xml);");
    if(fileName.isNull())
    {
        return;
    }

    if(QFileInfo(fileName).suffix() == "json")
    {
//        GenerateDescriptionFile g;
//        g.CreateJson(head,list);
    }
    else if (QFileInfo(fileName).suffix() == "xml")
    {
            FileGenerater g;

            g.CreateXml(fileName, h, &functionList);
            g.CreateDocument(fileName,&functionList);
    }
    else
    {

    }
}

void FunctionListWidget::slotCellClicked(int row, int column)
{
    qDebug()<<__FILE__<<__LINE__<<"行:"<<row<<"列："<<column;
    qDebug()<<"总行数："<<tableWidget->rowCount();

    if(tableWidget->rowCount() == 0)
    {
        return;
    }
    if(row == 0)
    {
        upmoveButton->setEnabled(false);
        if(row == (tableWidget->rowCount()-1))
        {
            downmoveButton->setEnabled(false);
        }
        else if(functionList.at(row)->getVarIndex() == VARINDEXPOWER)
        {
            downmoveButton->setEnabled(false);
        }
        else
        {
            downmoveButton->setEnabled(true);
        }
    }
    else if(row == (tableWidget->rowCount()-1))
    {
        downmoveButton->setEnabled(false);
        if(functionList.at(row)->getVarIndex() == VARINDEXWARNING)
        {
            upmoveButton->setEnabled(false);
        }
        else
        {
            upmoveButton->setEnabled(true);
        }
    }
    else
    {
        upmoveButton->setEnabled(true);
        downmoveButton->setEnabled(true);
    }
    if(row == 1)
    {
        if(functionList.first()->getVarIndex() == VARINDEXPOWER)
        {
            upmoveButton->setEnabled(false);
        }
    }
    if(row == (tableWidget->rowCount()-2))
    {
        if(functionList.last()->getVarIndex() == VARINDEXWARNING)
        {
            downmoveButton->setEnabled(false);
        }
    }
}

void FunctionListWidget::slotDeleteClicked(bool)
{
    PRINTLOG("");
    int currentRow = this->tableWidget->currentRow();
    PRINTLOG(currentRow);
    int row = this->tableWidget->rowCount();
    QDEBUG()<<"row数量"<<row;
    if(row > 0)
    {
        functionList.takeAt(currentRow);
        tableWidget->removeRow(currentRow);
        if(currentRow >= tableWidget->rowCount())
        {
             tableWidget->selectRow(currentRow-1);
        }
        else
        {
            tableWidget->selectRow(currentRow);
        }
        slotCellClicked(this->tableWidget->currentRow(), 0);
    }
}
