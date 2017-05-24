
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    addDeviceWidget = NULL;
    setWindowTitle("设备描述文件生成工具V2.1");
    readDeviceIni();
    setting();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setting()
{
    mainSplitter = new QSplitter(Qt::Horizontal);

    deviceSplitter = new QSplitter(Qt::Vertical);
    stackWidget = new QStackedWidget();

    mainSplitter->addWidget(deviceSplitter);
    mainSplitter->addWidget(stackWidget);
    mainSplitter->setStretchFactor(0,3);
    mainSplitter->setStretchFactor(1,4);
    this->setCentralWidget(mainSplitter);

    functionListWidget = new FunctionListWidget();
    functionListWidget->setEnabled(false);
    connect(functionListWidget, SIGNAL(signalSavedFunctionlist(int,QList<FunctionStruct*>)),this, SLOT(slotFunclistSaved(int,QList<FunctionStruct*>)));

    deviceinfoWidget = new deviceInformationWidget(0, this);
    connect(deviceinfoWidget, SIGNAL(signalSavebutton(deviceInformationWidget*,bool,int)), this, SLOT(slotDeviceSaved(deviceInformationWidget*,bool,int)));

    stackWidget->addWidget(functionListWidget);
    stackWidget->addWidget(deviceinfoWidget);

    deviceTreeWidget = new DeviceTreeWidget(devInfoList); // 设备列表，前端显示
    connect(deviceTreeWidget,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(slotDeviceItemClicked(QTreeWidgetItem*,int)));
    connect(deviceTreeWidget,SIGNAL(signalDeleteIndex(int)),this, SLOT(slotDeleteIndex(int)));
    deviceSplitter->addWidget(deviceTreeWidget);
    deviceSplitter->setStretchFactor(0,1);
    deviceSplitter->setStretchFactor(1,5);
    deviceSplitter->setAutoFillBackground(true);

    connect(ui->action_N,SIGNAL(triggered(bool)),this,SLOT(slotAddDevice(bool)));
    connect(ui->action_Q,SIGNAL(triggered(bool)),this,SLOT(close()));
    connect(ui->action,SIGNAL(triggered(bool)),this,SLOT(slotAuthor(bool)));
}

void MainWindow::slotDeviceItemClicked(QTreeWidgetItem *widgetItem, int )
{
    MyTreeWidgetItem *myWidgetItem = (MyTreeWidgetItem *)widgetItem->parent();
    if(widgetItem->parent())
    {
        if(widgetItem->text(0).contains("D"))
        {
            this->deviceinfoWidget->updateDeviceInfo(devInfoList.at(myWidgetItem->getDeviceId()), myWidgetItem->getDeviceId());
            this->stackWidget->setCurrentWidget(deviceinfoWidget);
        }
        else
        {
            qDebug()<<widgetItem->parent()->text(0);
            this->functionListWidget->slotUpdateDeviceID(devInfoList.at(myWidgetItem->getDeviceId()),myWidgetItem->getDeviceId());
            this->functionListWidget->setEnabled(true);
            this->stackWidget->setCurrentWidget(functionListWidget);
        }
    }
}

void MainWindow::slotAddDevice(bool)
{
    if(addDeviceWidget == NULL)
    {
        addDeviceWidget = new deviceInformationWidget(1, this);
        connect(addDeviceWidget, SIGNAL(signalSavebutton(deviceInformationWidget*,bool,int)), this, SLOT(slotDeviceSaved(deviceInformationWidget*,bool,int)));
    }
    addDeviceWidget->exec();
}

void MainWindow::slotFunclistSaved(int index, QList<FunctionStruct*>list)
{
    devInfoList.at(index)->setfunList(list);
    wrFunlistIni(index);
}

void MainWindow::slotDeviceSaved(deviceInformationWidget* deviceinfo,bool b,int index)
{
    if(b)
    {
        DeviceInformation* devInfo = new DeviceInformation();
        devInfo->setDeviceName(deviceinfo->deviceName);
        devInfo->setFileVer(deviceinfo->fileVer);
        devInfo->setApplyUser(deviceinfo->applyUser);
        devInfo->setModelCode(deviceinfo->deviceModelID);
        devInfo->setPrimaryClassCode(deviceinfo->primaryModelCode);
        devInfo->setMinorClassCode(deviceinfo->monirModelCode);
        devInfo->setManufactureId(deviceinfo->manufactureID);
        devInfo->setUrlAdress(deviceinfo->url);
        devInfo->setLinkWay(deviceinfo->linkWay);
        devInfo->setUpdate(deviceinfo->isUpdate);
        devInfo->setClockSync(deviceinfo->isSync);
        devInfo->setSleep(deviceinfo->isSleep);
        devInfo->setOtherPara(deviceinfo->isOtherpara);

        this->devInfoList.append(devInfo);
        wrDeviceIni();
        this->deviceTreeWidget->updateTreeWidget(devInfoList);
    }
    else
    {
        devInfoList.at(index)->setDeviceName(deviceinfo->deviceName);
        devInfoList.at(index)->setFileVer(deviceinfo->fileVer);
        devInfoList.at(index)->setApplyUser(deviceinfo->applyUser);
        devInfoList.at(index)->setModelCode(deviceinfo->deviceModelID);
        devInfoList.at(index)->setPrimaryClassCode(deviceinfo->primaryModelCode);
        devInfoList.at(index)->setMinorClassCode(deviceinfo->monirModelCode);
        devInfoList.at(index)->setManufactureId(deviceinfo->manufactureID);
        devInfoList.at(index)->setUrlAdress(deviceinfo->url);
        devInfoList.at(index)->setLinkWay(deviceinfo->linkWay);
        devInfoList.at(index)->setUpdate(deviceinfo->isUpdate);
        devInfoList.at(index)->setClockSync(deviceinfo->isSync);
        devInfoList.at(index)->setSleep(deviceinfo->isSleep);
        devInfoList.at(index)->setOtherPara(deviceinfo->isOtherpara);
        wrDeviceIni();
        this->deviceTreeWidget->updateTreeWidget(deviceinfo->deviceName);
    }
}

void MainWindow::readDeviceIni()
{
    QSettings deviceIni("device.ini",QSettings::IniFormat);
    deviceIni.setIniCodec("UTF-8");

    int size = deviceIni.beginReadArray("deviceInfo");
    int sizefunction = 0;
    for (int i = 0; i < size; ++i)
    {
        deviceIni.setArrayIndex(i);
        DeviceInformation *myDeviceInfo = new DeviceInformation();
        devInfoList.append(myDeviceInfo);

        devInfoList.at(i)->setDeviceName(deviceIni.value("deviceName").toString());
        devInfoList.at(i)->setDeviceModel(deviceIni.value("deviceModel").toString());
        devInfoList.at(i)->setFileVer(deviceIni.value("fileVer").toString());
        devInfoList.at(i)->setApplyUser(deviceIni.value("applyUser").toInt());
        devInfoList.at(i)->setModelCode(deviceIni.value("modelCode").toString());
        devInfoList.at(i)->setPrimaryClassCode(deviceIni.value("primaryClassCode").toInt());
        devInfoList.at(i)->setMinorClassCode(deviceIni.value("minorClassCode").toInt());
        devInfoList.at(i)->setManufactureId(deviceIni.value("manufactureId").toString());
        devInfoList.at(i)->setUrlAdress(deviceIni.value("urlAdress").toString());
        devInfoList.at(i)->setLinkWay(deviceIni.value("linkWay").toInt());
        devInfoList.at(i)->setUpdate(deviceIni.value("isUpdate").toInt());
        devInfoList.at(i)->setClockSync(deviceIni.value("isClockSync").toInt());
        devInfoList.at(i)->setSleep(deviceIni.value("isSleep").toInt());
        devInfoList.at(i)->setOtherPara(deviceIni.value("isOtherPara").toInt());

        sizefunction = deviceIni.beginReadArray("functionList");
        QList<FunctionStruct*>myFunlist;
        for(int j=0; j<sizefunction; ++j)
        {
            deviceIni.setArrayIndex(j);
            FunctionStruct *myfun = new FunctionStruct();
            myFunlist.append(myfun);

            myFunlist.at(j)->setFunctionName(deviceIni.value("funName").toString());
            myFunlist.at(j)->setVarType(deviceIni.value("varType").toInt());
            myFunlist.at(j)->setParameters(deviceIni.value("parameter").toString());
            myFunlist.at(j)->setDeviceType(deviceIni.value("deviceType").toString());

            myFunlist.at(j)->setVarIndex(deviceIni.value("varIndex").toInt());
            myFunlist.at(j)->setUserLeverLimit(deviceIni.value("userFunLimit").toString());
            myFunlist.at(j)->setDisplay(deviceIni.value("display").toInt());
            myFunlist.at(j)->setDirection(deviceIni.value("direction").toInt());

            myFunlist.at(j)->setOrderType(deviceIni.value("cmdtype").toString());
            myFunlist.at(j)->setNewVarType(deviceIni.value("newVarType").toInt());
            myFunlist.at(j)->setReturType(deviceIni.value("returnType").toInt());
            myFunlist.at(j)->setDataPos(deviceIni.value("datapos").toString());
            myFunlist.at(j)->setDataLength(deviceIni.value("dataLength").toString());
            myFunlist.at(j)->setDataType(deviceIni.value("datatype").toString());
            myFunlist.at(j)->setLength(deviceIni.value("length").toString());
            myFunlist.at(j)->setParaNew(deviceIni.value("paraNew").toString());

            myFunlist.at(j)->setDisType(deviceIni.value("distype").toInt());
            myFunlist.at(j)->setDisUnit(deviceIni.value("disunit").toString());
            myFunlist.at(j)->setDisName(deviceIni.value("disname").toString());
            myFunlist.at(j)->setIconIndex(deviceIni.value("dispic").toString());
            myFunlist.at(j)->setDisPara(deviceIni.value("dispara").toString());
        }
        devInfoList.at(i)->setfunList(myFunlist);
        deviceIni.endArray();
    }
    deviceIni.endArray();
}

void MainWindow::wrDeviceIni()
{
    QSettings deviceIni("device.ini",QSettings::IniFormat);
    deviceIni.setIniCodec("UTF-8");

    deviceIni.beginWriteArray("deviceInfo");
    for (int i = 0; i < devInfoList.size(); ++i)
    {
        deviceIni.setArrayIndex(i);
        deviceIni.setValue("deviceName", devInfoList.at(i)->getDeviceName());
        deviceIni.setValue("deviceModel", devInfoList.at(i)->getDeviceModel());
        deviceIni.setValue("fileVer", devInfoList.at(i)->getFileVer());
        deviceIni.setValue("applyUser", QString::number(devInfoList.at(i)->getApplyUser()));
        deviceIni.setValue("modelCode", devInfoList.at(i)->getModelCode());
        deviceIni.setValue("primaryClassCode", QString::number(devInfoList.at(i)->getPrimaryClassCode()));
        deviceIni.setValue("minorClassCode", QString::number(devInfoList.at(i)->getMinorClassCode()));
        deviceIni.setValue("manufactureId", devInfoList.at(i)->getManufactureId());
        deviceIni.setValue("urlAdress", devInfoList.at(i)->getUrlAdress());
        deviceIni.setValue("linkWay", QString::number(devInfoList.at(i)->getLinkWay()));
        deviceIni.setValue("isUpdate", QString::number(devInfoList.at(i)->getUpdate()));
        deviceIni.setValue("isClockSync", QString::number(devInfoList.at(i)->getClockSync()));
        deviceIni.setValue("isSleep", QString::number(devInfoList.at(i)->getSleep()));
        deviceIni.setValue("isOtherPara", QString::number(devInfoList.at(i)->getOtherPara()));
        wrFunlistIni(i);
    }
    deviceIni.endArray();
}

void MainWindow::wrFunlistIni(int index)
{
    QSettings deviceIni("device.ini",QSettings::IniFormat);
    deviceIni.setIniCodec("UTF-8");

    deviceIni.beginWriteArray("deviceInfo");
    deviceIni.setArrayIndex(index);

    QList<FunctionStruct*>funList;
    funList.clear();
    funList.append(devInfoList.at(index)->getfunList());

    FunctionStruct* function = NULL;

    qDebug()<<"第"<<QString::number(index)<<"个设备";
    qDebug()<<"功能总数:"<<QString::number(funList.size());

    deviceIni.beginWriteArray("functionList");
    for(int i=0; i<funList.size(); i++)
    {
        function = funList.at(i);
        deviceIni.setArrayIndex(i);

        deviceIni.setValue("funName",function->getFunctionName());
        deviceIni.setValue("varType", QString::number(function->getVarType()));
        deviceIni.setValue("parameter", function->getParameters());
        deviceIni.setValue("deviceType", function->getDeviceType());

        deviceIni.setValue("varIndex",QString::number(function->getVarIndex()));
        deviceIni.setValue("userFunLimit", function->getUserLeverLimit());
        deviceIni.setValue("display", QString::number(function->getDisplay()));
        deviceIni.setValue("direction", QString::number(function->getDirection()));

        deviceIni.setValue("cmdtype", function->getOrderType());
        deviceIni.setValue("newVarType", QString::number(function->getNewVarType()));
        deviceIni.setValue("returnType", QString::number(function->getReturnType()));
        deviceIni.setValue("datapos", function->getDataPos());
        deviceIni.setValue("dataLength", function->getDataLength());
        deviceIni.setValue("length", function->getLength());
        deviceIni.setValue("paraNew",function->getParaNew());

        deviceIni.setValue("datatype", function->getDataType());
        deviceIni.setValue("distype", QString::number(function->getDisType()));
        deviceIni.setValue("disunit", function->getDisUnit());
        deviceIni.setValue("disname", function->getDisName());
        deviceIni.setValue("dispic", function->getIconIndex());
        deviceIni.setValue("dispara", function->getDisPara());
    }
    deviceIni.endArray();
    deviceIni.endArray();

    deviceIni.beginWriteArray("deviceInfo");
    deviceIni.setArrayIndex(devInfoList.size()-1);
    deviceIni.endArray();
}

void MainWindow::slotDeleteIndex(int index)
{
    devInfoList.removeAt(index);

    QSettings deviceIni("device.ini",QSettings::IniFormat);
    deviceIni.setIniCodec("UTF-8");

    deviceIni.clear();
    wrDeviceIni();
    this->deviceTreeWidget->updateTreeWidget(devInfoList);
}

void MainWindow::slotAuthor(bool)
{
    AboutDialog abouts;
    abouts.exec();
}
