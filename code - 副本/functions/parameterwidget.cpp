#include "parameterwidget.h"
#include "ui_parameterwidget.h"

ParameterWidget::ParameterWidget(FunctionStruct *f, QDialog *parent):
    QDialog(parent),
    ui(new Ui::ParameterWidget)
{
    ui->setupUi(this);
    this->functionStruct = f;
    init();
}

ParameterWidget::~ParameterWidget()
{
    delete ui;
}

void ParameterWidget::init()
{
    ui->orderParaTextEdit->setReadOnly(true);
    ui->orderVarindex->setReadOnly(true);
    ui->orderName->setReadOnly(true);
    ui->orderCmdTypeEdit->setReadOnly(true);
    ui->orderDataTypeEdit->setReadOnly(true);
    ui->orderDeviceTypeEdit->setReadOnly(true);
    this->ui->orderName->setText(functionStruct->getFunctionName());
    this->ui->orderVarindex->setText(QString::number(functionStruct->getVarIndex()));
    switch (functionStruct->getDirection())
    {
    case DIRWR:
        this->ui->orderWrite->setChecked(true);
        break;

    case DIRRD:
        this->ui->orderRead->setChecked(true);
        break;

    case DIRWD:
        this->ui->orderReadwrite->setChecked(true);
        break;

    default:
        break;
    }

    QSqlQuery query;
    QString str = "select * from device_class1 where id = " + functionStruct->getDeviceType();
    QDEBUG()<<str;
    if(!query.exec(str))
    {
        QDEBUG()<<"databaseError";
    }
    query.next();
    this->ui->orderDeviceTypeEdit->setText(query.value("class_name").toString());

    str = "select * from command_type where id = " + QString::number(functionStruct->getVarType());
    QDEBUG()<<str;
    if(!query.exec(str))
    {
        QDEBUG()<<"databaseError";
    }
    query.next();
    this->ui->orderDataTypeEdit->setText(query.value("type_name").toString());

    ui->orderCmdTypeEdit->setText(functionStruct->getOrderType());
    ui->orderParaTextEdit->setPlainText(functionStruct->getParameters());
    ui->functionLimit->setText(functionStruct->getUserLeverLimit());
    QStringList strList;
    strList.append(DATATYPEHEX);
    strList.append(DATATYPEBCD);
    strList.append(DATATYPEASCLL);

    ui->dataTypeBox->addItems(strList);
    ui->dataTypeBox->setCurrentIndex(functionStruct->getDataType().toInt());

    ui->returnTypeBox->addItem("状态域");
    ui->returnTypeBox->addItem("状态位");
    connect(ui->returnTypeBox, SIGNAL(currentIndexChanged(int)), this, SLOT(slotReturnTypeChanged(int)));
    ui->returnTypeBox->setCurrentIndex(functionStruct->getReturnType());

    QDEBUG()<<"varindex"<<functionStruct->getVarIndex();

    str = "select * from command_type where (id > 0) order by id";
    if(!query.exec(str))
    {
        QDEBUG()<<"databaseError";
    }
    QDEBUG()<<str;
    while(query.next())
    {
        this->ui->varTypeBox->addItem(query.value("type_name").toString());
    }
    ui->varTypeBox->setCurrentIndex(functionStruct->getNewVarType()-1);

    ui->functionLimit->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->returnedValLen->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->startPos->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->dataLength->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->bytePos->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->bitPos->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));

    ui->cmdParameter1LineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]{5}")));
    ui->cmdParameter2LineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]{5}")));
    ui->cmdReturn1->setValidator(new QRegExpValidator(QRegExp("[a-fA-F0-9]{40}")));
    ui->cmdReturn2->setValidator(new QRegExpValidator(QRegExp("[a-fA-F0-9]{40}")));
    ui->cmdOrder1Edit->setValidator(new QRegExpValidator(QRegExp("[a-fA-F0-9]{40}")));
    ui->cmdOrder2Edit->setValidator(new QRegExpValidator(QRegExp("[a-fA-F0-9]{40}")));

    ui->NumberMaxlineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]{5}")));
    ui->NumberMinlineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]{5}")));
    ui->NumberDefaultlineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]{5}")));
    ui->klineEdit->setValidator(new QRegExpValidator(QRegExp("[.0-9]{5}")));
    ui->clineEdit_2->setValidator(new QRegExpValidator(QRegExp("[.0-9]{5}")));
    ui->numberOrderEdit->setValidator(new QRegExpValidator(QRegExp("[a-fA-F0-9]{40}")));
    ui->numberParaLen->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->numberParaOffset->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->NumberScallinglineEdit->setValidator(new QRegExpValidator(QRegExp("[.0-9]{10}")));

    ui->alarmClass->setValidator(new QRegExpValidator(QRegExp("[0-9]{1}")));

    ui->dateOrder->setValidator(new QRegExpValidator(QRegExp("[a-fA-F0-9]{40}")));
    ui->dateYSteplineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->dateYearLen->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->dateYearOffset->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->dateMSteplineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->dateMonLen->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->dateMonOffset->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->dateDSteplineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->dateDayLen->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->dateDayOffset->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->yearC->setValidator(new QRegExpValidator(QRegExp("[0-9]{5}")));
    ui->datetimeYearC->setValidator(new QRegExpValidator(QRegExp("[0-9]{5}")));

    ui->timeOrder->setValidator(new QRegExpValidator(QRegExp("[a-fA-F0-9]{40}")));
    ui->timeHStepLineedit->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->timeHourLen->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->timeHourOffset->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->timeMStepLineedit->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->timeMinLen->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->timeMinOffset->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->timeSStepLineedit->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->timeSecLen->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->timeSecOffset->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));

    ui->datetimeOrder->setValidator(new QRegExpValidator(QRegExp("[a-fA-F0-9]{40}")));
    ui->datetimeYearStep->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->datetimeYearLen->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->datetimeYearOffset->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->datetimeMonStep->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->datetimeMonLen->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->datetimeMonOffset->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->datetimeSecStep->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->datetimeDayLen->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->datetimeDayOffset->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->datetimeHourStep->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->datetimeHourLen->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->datetimeHourOffset->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->datetimeMinStep->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->datetimeMinLen->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->datetimeMinOffset->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->datetimeSecStep->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->datetimeSecLen->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->datetimeSecOffset->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));

    ui->triggerPara->setValidator(new QRegExpValidator(QRegExp("[0-9]{5}")));
    ui->singleReturn->setValidator(new QRegExpValidator(QRegExp("[a-fA-F0-9]{40}")));
    ui->operationOrder->setValidator(new QRegExpValidator(QRegExp("[a-fA-F0-9]{40}")));

    ui->numberParaEndian->addItem("大端");
    ui->numberParaEndian->addItem("小端");

    ui->dateEndian->addItem("大端");
    ui->dateEndian->addItem("小端");

    ui->timeEndian->addItem("大端");
    ui->timeEndian->addItem("小端");

    ui->datetimeEndian->addItem("大端");
    ui->datetimeEndian->addItem("小端");

    ui->isDisplay->setChecked(functionStruct->getDisplay());
    slotIsdisplayClicked(ui->isDisplay->isChecked());
    QStringList disTypeList;
    disTypeList.append("静态文字");
    disTypeList.append("静态图片");
    disTypeList.append("日期型");
    disTypeList.append("时间型");
    disTypeList.append("数字型");
    disTypeList.append("开关型");
    disTypeList.append("枚举型");
    disTypeList.append("滚动条型");
    disTypeList.append("日期时间型");
    ui->disTypeBox->addItems(disTypeList);
    ui->disTypeBox->setCurrentIndex(functionStruct->getDisType()-1);

    strList.clear();
    strList.append("无单位");
    strList.append("摄氏度");
    strList.append("百分比");
    strList.append("千克");
    strList.append("伏特");
    strList.append("安培");
    strList.append("赫兹");
    strList.append("千瓦");
    strList.append("千瓦时");
    strList.append("小时");
    strList.append("分钟");
    strList.append("秒");
    strList.append("微克每立方米");
    strList.append("毫克每立方米");
    strList.append("千米每小时");
    strList.append("米");
    strList.append("毫米");
    strList.append("华氏度");
    strList.append("度");
    ui->disScrollUnit->addItems(strList);
    ui->disScrollUnit->setCurrentIndex(functionStruct->getDisUnit().toInt());
    ui->NumberUnitcomboBox->addItems(strList);

    ui->disName->setText(functionStruct->getDisName());
    ui->disFunPic->setText(functionStruct->getIconIndex());
    ui->disFunPic->setValidator(new QRegExpValidator(QRegExp("[0-9]{5}")));
}

cmdParameters ParameterWidget::getCmdParameters()
{
    cmdParameters c = functionStruct->getCmdParameters();
    if(curVarType == VARCMD)
    {
        c.parameter1 = ui->cmdParameter1LineEdit->text();
        c.parameter2 = ui->cmdParameter2LineEdit->text();
        c.dis1 = ui->cmdDis1LineEdit->text();
        c.dis2 = ui->cmdDis2LineEdit->text();
        c.statusValue1 = ui->cmdReturn1->text();
        c.statusValue2 = ui->cmdReturn2->text();
        c.para1_other = ui->cmdOrder1Edit->text();
        c.para2_other = ui->cmdOrder2Edit->text();
        if(this->ui->cmdDefault1Radibtn->isChecked())
        {
            c.defaultValue = c.parameter1;
        }
        else
        {
            c.defaultValue = c.parameter2;
        }
    }
    else if(curVarType == VARSINGLE)
    {
        c.parameter1 = ui->triggerPara->text();
        c.dis1 = ui->triggerDis->text();
        c.statusValue1 = ui->singleReturn->text();
        c.para1_other = ui->operationOrder->text();
        c.parameter2 = ui->triggerPara_2->text();
        c.dis2 = ui->triggerDis_2->text();
        c.statusValue2 = ui->singleReturn_2->text();
    }
    else
    {
        c.statusValue1 = ui->eventReturn->text();
    }
    return c;
}

numberParamters ParameterWidget::getNumParameters()
{
    numberParamters n;
    n.max = ui->NumberMaxlineEdit->text();
    n.min = ui->NumberMinlineEdit->text();
    n.defaultValue = ui->NumberDefaultlineEdit->text();
    n.scalling = ui->NumberScallinglineEdit->text();
    n.uint = QString::number(ui->NumberUnitcomboBox->currentIndex());
    n.kFactor = ui->klineEdit->text();
    n.cFactor = ui->clineEdit_2->text();
    n.otherPara = ui->numberOrderEdit->text();
    n.endian = QString::number(ui->numberParaEndian->currentIndex()+1);
    n.other.valueLen = ui->numberParaLen->text();
    n.other.valuePos = ui->numberParaOffset->text();
    return n;
}

enumParameters ParameterWidget::getEnumParameters()
{
    enumParameters e;
    for(int i=0; i<valueEditList.size(); i++)
    {
        _enumPara* enumPara = new _enumPara;
        enumPara->isSlect = enumIsSelectList.at(i)->isChecked();
        enumPara->value = valueEditList.at(i)->text();
        enumPara->display = disEditList.at(i)->text();
        enumPara->statusValue = statuaList.at(i)->text();
        enumPara->otherPara = otherParaList.at(i)->text();
        e.enumParaList.append(enumPara);
        if(defaultRadionList.at(i)->isChecked())
        {
            e.defaultValue = valueEditList.at(i)->text();
        }
    }
    return e;
}

dateTimeParameters ParameterWidget::getDataParameters()
{
    dateTimeParameters d = functionStruct->getDateTimeParameters();
    d.maxDate = ui->dateMaxEdit->date();
    d.minDate = ui->dateMinEdit->date();
    d.date = ui->dateDefault->date();
    d.dayStep = ui->dateYSteplineEdit->text();
    d.monthStep = ui->dateMSteplineEdit->text();
    d.yearStep = ui->dateYSteplineEdit->text();

    d.otherPara = ui->dateOrder->text();
    d.yearOther.valueLen = ui->dateYearLen->text();
    d.yearOther.valuePos = ui->dateYearOffset->text();
    d.yearC = ui->yearC->text();
    d.monthOther.valueLen = ui->dateMonLen->text();
    d.monthOther.valuePos = ui->dateMonOffset->text();
    d.dayOther.valueLen = ui->dateDayLen->text();
    d.dayOther.valuePos = ui->dateDayOffset->text();
    d.endian = QString::number(ui->dateEndian->currentIndex()+1);
    return d;
}

dateTimeParameters ParameterWidget::getTimeParameters()
{
    dateTimeParameters t = functionStruct->getDateTimeParameters();
    t.maxTime = ui->timeMaxEdit->time();
    t.minTime = ui->timeMinEdit->time();
    t.time = ui->timeEdit->time();
    t.hourStep = ui->timeHStepLineedit->text();
    t.minuteStep = ui->timeMStepLineedit->text();
    t.secondStep = ui->timeSStepLineedit->text();

    t.otherPara = ui->timeOrder->text();
    t.hourOther.valueLen = ui->timeHourLen->text();
    t.hourOther.valuePos = ui->timeHourOffset->text();
    t.minOther.valueLen = ui->timeMinLen->text();
    t.minOther.valuePos = ui->timeMinOffset->text();
    t.secOther.valueLen = ui->timeSecLen->text();
    t.secOther.valuePos = ui->timeSecOffset->text();
    t.endian = QString::number(ui->timeEndian->currentIndex()+1);
    return t;
}

dateTimeParameters ParameterWidget::getDatetimeParas()
{
    dateTimeParameters dt = functionStruct->getDateTimeParameters();
    dt.maxDate = ui->datetimeDateMax->date();
    dt.minDate = ui->datetimeDateMin->date();
    dt.date = ui->datetimeDateDefault->date();
    dt.yearStep = ui->datetimeYearStep->text();
    dt.monthStep = ui->datetimeMonStep->text();
    dt.dayStep = ui->datetimeDayStep->text();

    dt.maxTime = ui->datetimeTimeMax->time();
    dt.minTime = ui->datetimeTimeMin->time();
    dt.time = ui->datetimeTimeDefault->time();
    dt.hourStep = ui->datetimeHourStep->text();
    dt.minuteStep = ui->datetimeMinStep->text();
    dt.secondStep = ui->datetimeSecStep->text();

    dt.otherPara = ui->datetimeOrder->text();
    dt.yearOther.valueLen = ui->datetimeYearLen->text();
    dt.yearOther.valuePos = ui->datetimeYearOffset->text();
    dt.yearC = ui->datetimeYearC->text();
    dt.monthOther.valueLen = ui->datetimeMonLen->text();
    dt.monthOther.valuePos = ui->datetimeMonOffset->text();
    dt.dayOther.valueLen = ui->datetimeDayLen->text();
    dt.dayOther.valuePos = ui->datetimeDayOffset->text();
    dt.hourOther.valueLen = ui->datetimeHourLen->text();
    dt.hourOther.valuePos = ui->datetimeHourOffset->text();
    dt.minOther.valueLen = ui->datetimeMinLen->text();
    dt.minOther.valuePos = ui->datetimeMinOffset->text();
    dt.secOther.valueLen = ui->datetimeSecLen->text();
    dt.secOther.valuePos = ui->datetimeSecOffset->text();
    dt.endian = QString::number(ui->datetimeEndian->currentIndex()+1);

    return dt;
}

_varOutType ParameterWidget::getOutParas()
{
    _varOutType out;
    for(int i=0; i<ui->outParaNumber->value(); i++)
    {
        _varOutItem *item = new _varOutItem;
        item->paraValue = outParaList.at(i)->text();
        item->paraDsc = outParaDscList.at(i)->text();
        item->statusValue = outStatusList.at(i)->text();
        item->paraOrder = outOrderList.at(i)->text();
        item->isDefault = outDefaultList.at(i)->isChecked();
        out.itemList.append(item);
    }
    return out;
}

alarmParameters ParameterWidget::getAlarmPara()
{
    alarmParameters ap = functionStruct->getAlarmParameters();
    ap.alarmClass = ui->alarmClass->text();
    ap.alarmText = ui->alarmText->text();
    return ap;
}

void ParameterWidget::saveDisPara()
{
    functionStruct->setDisplay(ui->isDisplay->isChecked());
    functionStruct->setDisType(curDisType);
    functionStruct->setDisUnit(QString::number(ui->disScrollUnit->currentIndex()));
    functionStruct->setDisName(ui->disName->text());
    functionStruct->setIconIndex(ui->disFunPic->text());

    QDEBUG()<<"当前显示类型"<<curDisType;

    if(!ui->isDisplay->isCheckable())
    {
        return;
    }
    if(curDisType == DISSTRING)
    {
        functionStruct->setDisString(ui->disStr->text());
    }
    else if(curDisType == DISPICTURE)
    {
        functionStruct->setDisPic(ui->disPic->text());
    }
    else if(curDisType == DISDATE)
    {
        _disDateTime dispara = functionStruct->getDisDateTime();
        dispara.disYear = ui->disDateYear->text();
        dispara.disMonth = ui->disDateMon->text();
        dispara.disDay = ui->disDateDay->text();
        functionStruct->setDisDateTime(dispara);
    }
    else if(curDisType == DISTIME)
    {
        _disDateTime dispara = functionStruct->getDisDateTime();
        dispara.disHour = ui->disTimeHour->text();
        dispara.disMin = ui->disTimeMin->text();
        dispara.disSec = ui->disTimeSec->text();
        functionStruct->setDisDateTime(dispara);
    }
    else if(curDisType == DISNUMBER)
    {
        _disNumber dispara;
        dispara.disPara = ui->disNumberDefault->text();
        dispara.disScaling = ui->disNumberScall->text();
        functionStruct->setDisNumber(dispara);
    }
    else if(curDisType == DISCMD)
    {
        _disCmd dispara;
        dispara.value1 = ui->disCmdValue1->text();
        dispara.value2 = ui->disCmdValue2->text();
        dispara.string1 = ui->disCmdstr1->text();
        dispara.string2 = ui->disCmdstr2->text();
        dispara.pic1 = ui->disCmdpic1->text();
        dispara.pic2 = ui->disCmdPic2->text();
        functionStruct->setDisCmd(dispara);
    }
    else if(curDisType == DISENUMBERATE)
    {
        _disEnum dispara;
        for(int i=0; i<ui->disEnumNumber->value(); i++)
        {
            _disEnumPara *enumpara = new _disEnumPara;
            enumpara->select = disEnumIsSelectList.at(i)->isChecked();
            enumpara->value = disEnumParaList.at(i)->text();
            enumpara->string = disEnumStrList.at(i)->text();
            enumpara->pic = disEnumPicList.at(i)->text();
            dispara.disEnumList.append(enumpara);
        }
        functionStruct->setDisEnum(dispara);
    }
    else if(curDisType == DISSCROL)
    {
        _disScroll dispara;
        dispara.disDefault = ui->disScrollDefaul->text();
        dispara.disMax = ui->disScrollMax->text();
        dispara.disMin = ui->disScrollMin->text();
        dispara.disStep = ui->disScrollStep->text();
        functionStruct->setDisScroll(dispara);
    }
    else if(curDisType == DISDATETIME)
    {
        _disDateTime dispara;
        dispara.disYear = ui->disDatetimeYear->text();
        dispara.disMonth = ui->disDatetimeMon->text();
        dispara.disDay = ui->disDatetimeDay->text();
        dispara.disHour = ui->disDatetimeHour->text();
        dispara.disMin = ui->disDatetimeMin->text();
        dispara.disSec = ui->disDatetimeSec->text();
        functionStruct->setDisDateTime(dispara);
    }
    else
    {
        QDEBUG()<<"未知显示类型";
    }
}

void ParameterWidget::on_SaveButton_clicked()
{
    int varType = curVarType;
    functionStruct->setUserLeverLimit(ui->functionLimit->text());
    functionStruct->setLength(ui->returnedValLen->text());
    functionStruct->setReturType(ui->returnTypeBox->currentIndex());
    if(ui->returnTypeBox->currentIndex() == RETURNBYTE)
    {
        functionStruct->setDataPos(ui->startPos->text());
        functionStruct->setDataLength(ui->dataLength->text());
    }
    else
    {
        functionStruct->setDataPos(ui->bytePos->text());
        functionStruct->setDataLength(ui->bitPos->text());
    }
    functionStruct->setDataType(QString::number(ui->dataTypeBox->currentIndex()));
    functionStruct->setNewVarType(varType);
    QDEBUG()<<"当前变量类型"<<varType;

    if((varType == VARCMD) || (varType == VARSINGLE) || (varType == VAREVENT))
    {
        cmdParameters c = getCmdParameters();
        this->functionStruct->setParameter(c);
    }
    else if(varType == VARNUMBER)
    {
        numberParamters n = getNumParameters();
        this->functionStruct->setParameter(n);
    }
    else if(varType == VARENUMBERATE)
    {
        enumParameters e = getEnumParameters();
        this->functionStruct->setParameter(e);
    }
    else if(varType == VARALARM)
    {
        alarmParameters ap = getAlarmPara();
        this->functionStruct->setParameter(ap);
    }
    else if(varType == VARDATE)
    {
        dateTimeParameters dt = getDataParameters();
        this->functionStruct->setParameter(dt);
    }
    else if(varType == VARTIME)
    {
        dateTimeParameters dt = getTimeParameters();
        this->functionStruct->setParameter(dt);
    }
    else if(varType == VARDATETIME)
    {
        dateTimeParameters dt = getDatetimeParas();
        this->functionStruct->setParameter(dt);
    }
    else if(varType == VAROUT)
    {
        _varOutType outType = getOutParas();
        this->functionStruct->setParameter(outType);
    }
    else if(varType == VARINPUT)
    {

    }
    else
    {
        QDEBUG()<<"变量类型错误";
    }
    saveDisPara();
    this->close();
}

void ParameterWidget::setCmdPara()
{
    cmdParameters cp = functionStruct->getCmdParameters();
    this->ui->cmdParameter1LineEdit->setText(cp.parameter1);
    this->ui->cmdParameter2LineEdit->setText(cp.parameter2);
    this->ui->cmdDis1LineEdit->setText(cp.dis1);
    this->ui->cmdDis2LineEdit->setText(cp.dis2);
    this->ui->cmdOrder1Edit->setText(cp.para1_other);
    this->ui->cmdOrder2Edit->setText(cp.para2_other);
    ui->cmdReturn1->setText(cp.statusValue1);
    ui->cmdReturn2->setText(cp.statusValue2);

    if(cp.defaultValue == cp.parameter1)
    {
        this->ui->cmdDefault1Radibtn->setChecked(true);
    }
    else
    {
        this->ui->cmdDefault2Radibtn->setChecked(true);
    }
    if(functionStruct->getVarType() == VARCMD)
    {
        ui->cmdParameter1LineEdit->setEnabled(false);
        ui->cmdDis1LineEdit->setEnabled(false);
        ui->cmdParameter2LineEdit->setEnabled(false);
        ui->cmdDis2LineEdit->setEnabled(false);
    }
}

void ParameterWidget::setNumberPara()
{
    numberParamters np = functionStruct->getNumberParameters();
    this->ui->NumberMaxlineEdit->setText(np.max);
    this->ui->NumberMinlineEdit->setText(np.min);
    this->ui->NumberDefaultlineEdit->setText(np.defaultValue);
    ui->klineEdit->setText(np.kFactor);
    ui->clineEdit_2->setText(np.cFactor);
    this->ui->NumberScallinglineEdit->setText(np.scalling);
    this->ui->NumberUnitcomboBox->setCurrentIndex(np.uint.toInt());
    this->ui->numberOrderEdit->setText(np.otherPara);
    this->ui->numberParaLen->setText(np.other.valueLen);
    this->ui->numberParaOffset->setText(np.other.valuePos);
    this->ui->numberParaEndian->setCurrentIndex(np.endian.toInt()-1);

    if(functionStruct->getVarType() == VARNUMBER)
    {
//        ui->NumberDefaultlineEdit->setEnabled(false);
//        ui->NumberMaxlineEdit->setEnabled(false);
//        ui->NumberMinlineEdit->setEnabled(false);
//        ui->NumberScallinglineEdit->setEnabled(false);
//        ui->NumberUnitcomboBox->setEnabled(false);
    }
}

void ParameterWidget::setEunmPara()
{
    if(functionStruct->getVarType() == VARENUMBERATE)
    {
        enumParameters e = functionStruct->getenumParameters();
        QDEBUG()<<"枚举数量"<<e.enumParaList.size();

        for(int i=0; i<e.enumParaList.size(); i++)
        {
            QCheckBox *slect = new QCheckBox();
            QLineEdit *vle = new QLineEdit();
            QLineEdit *dle = new QLineEdit();
            QLineEdit *state = new QLineEdit();
            QLineEdit *otherEdit = new QLineEdit();
            QRadioButton *rb = new QRadioButton();

            vle->setEnabled(false);
            dle->setEnabled(false);
            state->setValidator(new QRegExpValidator(QRegExp("[a-fA-F0-9]{40}")));
            otherEdit->setValidator(new QRegExpValidator(QRegExp("[a-fA-F0-9]{40}")));

            slect->setChecked(e.enumParaList.at(i)->isSlect);
            vle->setText(e.enumParaList.at(i)->value);
            dle->setText(e.enumParaList.at(i)->display);
            state->setText(e.enumParaList.at(i)->statusValue);
            otherEdit->setText(e.enumParaList.at(i)->otherPara);

            if(e.enumParaList.at(i)->value == e.defaultValue)
            {
                rb->setChecked(true);
            }
            else
            {
                rb->setChecked(false);
            }

            this->enumIsSelectList.append(slect);
            this->valueEditList.append(vle);
            this->statuaList.append(state);
            this->otherParaList.append(otherEdit);
            this->disEditList.append(dle);
            this->defaultRadionList.append(rb);

            ui->gridLayout_3->addWidget(slect,i,0,1,1);
            ui->gridLayout_3->addWidget(vle,i,1,1,1);
            ui->gridLayout_3->addWidget(dle,i,2,1,1);
            ui->gridLayout_3->addWidget(state, i, 3, 1, 1);
            ui->gridLayout_3->addWidget(otherEdit,i,4,1,1);
            ui->gridLayout_3->addWidget(rb,i,5,1,1);

            ui->gridLayout_3->setColumnStretch(0, 1);
            ui->gridLayout_3->setColumnStretch(1, 3);
            ui->gridLayout_3->setColumnStretch(2, 3);
            ui->gridLayout_3->setColumnStretch(3, 3);
            ui->gridLayout_3->setColumnStretch(4, 6);

            ui->gridLayout_3->setContentsMargins(15, 0, 0, 0);
        }
    }
}

void ParameterWidget::setAlarmPara()
{
    if(functionStruct->getVarType() == VARALARM)
    {
        alarmParameters ap = functionStruct->getAlarmParameters();
        ui->alarmClass->setEnabled(false);
        ui->alarmText->setEnabled(false);
        ui->alarmClass->setText(ap.alarmClass);
        ui->alarmText->setText(ap.alarmText);
    }
    else
    {
        QDEBUG()<<"待续";
    }
}

void ParameterWidget::setDatePara()
{
    if((functionStruct->getVarType() == VARDATE) || (functionStruct->getVarType() == VARDATETIME))
    {
        dateTimeParameters dp = functionStruct->getDateTimeParameters();
        this->ui->dateMaxEdit->setDate(dp.maxDate);
        this->ui->dateMinEdit->setDate(dp.minDate);
        this->ui->dateDefault->setDate(dp.date);
        this->ui->dateYSteplineEdit->setText(dp.yearStep);
        this->ui->dateMSteplineEdit->setText(dp.monthStep);
        this->ui->dateDSteplineEdit->setText(dp.dayStep);
        ui->dateOrder->setText(dp.otherPara);
        ui->dateYearLen->setText(dp.yearOther.valueLen);
        ui->dateYearOffset->setText(dp.yearOther.valuePos);
        ui->yearC->setText(dp.yearC);
        ui->dateMonLen->setText(dp.monthOther.valueLen);
        ui->dateMonOffset->setText(dp.monthOther.valuePos);
        ui->dateDayLen->setText(dp.dayOther.valueLen);
        ui->dateDayOffset->setText(dp.dayOther.valuePos);
        ui->dateEndian->setCurrentIndex(dp.endian.toInt()-1);

        ui->dateMaxEdit->setEnabled(false);
        ui->dateMinEdit->setEnabled(false);
    }
}

void ParameterWidget::setTimePara()
{
    QDEBUG()<<"时间型变量";
    if((functionStruct->getVarType() == VARTIME) || (functionStruct->getVarType() == VARDATETIME))
    {
        dateTimeParameters tp = functionStruct->getDateTimeParameters();
        this->ui->timeMaxEdit->setTime(tp.maxTime);
        this->ui->timeMinEdit->setTime(tp.minTime);
        this->ui->timeEdit->setTime(tp.time);
        this->ui->timeHStepLineedit->setText(tp.hourStep);
        this->ui->timeMStepLineedit->setText(tp.minuteStep);
        this->ui->timeSStepLineedit->setText(tp.secondStep);

        ui->timeOrder->setText(tp.otherPara);
        ui->timeHourLen->setText(tp.hourOther.valueLen);
        ui->timeHourOffset->setText(tp.hourOther.valuePos);
        ui->timeMinLen->setText(tp.minOther.valueLen);
        ui->timeMinOffset->setText(tp.minOther.valuePos);
        ui->timeSecLen->setText(tp.secOther.valueLen);
        ui->timeSecOffset->setText(tp.secOther.valuePos);
        ui->timeEndian->setCurrentIndex(tp.endian.toInt()-1);

        ui->timeMaxEdit->setEnabled(false);
        ui->timeMinEdit->setEnabled(false);
    }
}

void ParameterWidget::SetDateTimePara()
{
    if((functionStruct->getVarType() == VARDATE) || (functionStruct->getVarType() == VARTIME) || (functionStruct->getVarType() == VARDATETIME))
    {
        dateTimeParameters dtp = functionStruct->getDateTimeParameters();
        this->ui->datetimeDateMax->setDate(dtp.maxDate);
        this->ui->datetimeDateMin->setDate(dtp.minDate);
        this->ui->datetimeDateDefault->setDate(dtp.date);
        this->ui->datetimeYearStep->setText(dtp.yearStep);
        this->ui->datetimeMonStep->setText(dtp.monthStep);
        this->ui->datetimeDayStep->setText(dtp.dayStep);
        this->ui->datetimeTimeMax->setTime(dtp.maxTime);
        this->ui->datetimeTimeMin->setTime(dtp.minTime);
        this->ui->datetimeTimeDefault->setTime(dtp.time);
        this->ui->datetimeHourStep->setText(dtp.hourStep);
        this->ui->datetimeMinStep->setText(dtp.minuteStep);
        this->ui->datetimeSecStep->setText(dtp.secondStep);

        ui->datetimeOrder->setText(dtp.otherPara);
        ui->datetimeYearLen->setText(dtp.yearOther.valueLen);
        ui->datetimeYearOffset->setText(dtp.yearOther.valuePos);
        ui->datetimeYearC->setText(dtp.yearC);
        ui->datetimeMonLen->setText(dtp.monthOther.valueLen);
        ui->datetimeMonOffset->setText(dtp.monthOther.valuePos);
        ui->datetimeDayLen->setText(dtp.dayOther.valueLen);
        ui->datetimeDayOffset->setText(dtp.dayOther.valuePos);
        ui->datetimeHourLen->setText(dtp.hourOther.valueLen);
        ui->datetimeHourOffset->setText(dtp.hourOther.valuePos);
        ui->datetimeMinLen->setText(dtp.minOther.valueLen);
        ui->datetimeMinOffset->setText(dtp.minOther.valuePos);
        ui->datetimeSecLen->setText(dtp.secOther.valueLen);
        ui->datetimeSecOffset->setText(dtp.secOther.valuePos);
        ui->datetimeEndian->setCurrentIndex(dtp.endian.toInt()-1);
        if(functionStruct->getVarType() == VARDATETIME)
        {
            ui->datetimeDateMax->setEnabled(false);
            ui->datetimeDateMin->setEnabled(false);
            ui->datetimeTimeMax->setEnabled(false);
            ui->datetimeTimeMin->setEnabled(false);
        }
        else if(functionStruct->getVarType() == VARDATE)
        {
            ui->datetimeDateMax->setEnabled(false);
            ui->datetimeDateMin->setEnabled(false);
        }
        else
        {
            ui->datetimeTimeMax->setEnabled(false);
            ui->datetimeTimeMin->setEnabled(false);
        }
    }
}

void ParameterWidget::slotVarTypeChanged(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
    curVarType = index+1;

    ui->isDisplay->setEnabled(true);
    ui->isDisplay->setChecked(true);
    this->slotIsdisplayClicked(true);
    ui->returnedValLen->setText(functionStruct->getLength());
    ui->returnedValLen->setEnabled(true);
    ui->returnTypeBox->setCurrentIndex(functionStruct->getReturnType());
    ui->returnTypeBox->setEnabled(true);
    ui->startPos->setText(functionStruct->getDataPos());
    ui->dataLength->setText(functionStruct->getDataLength());
    ui->startPos->setEnabled(true);
    ui->dataLength->setEnabled(true);

    QDEBUG()<<"当前显示类型"<<ui->varTypeBox->currentText();
    QDEBUG()<<"defaultVartype"<<functionStruct->getVarType();
    QDEBUG()<<"newVartype"<<functionStruct->getNewVarType();
    QDEBUG()<<"parameters"<<functionStruct->getParameters();
    QDEBUG()<<"paraNew"<<functionStruct->getParaNew();

    if(curVarType == VARCMD)
    {
        setCmdPara();
    }
    else if(curVarType == VARNUMBER)
    {
        setNumberPara();
    }
    else if(curVarType == VARENUMBERATE)
    {
        setEunmPara();
    }
    else if(curVarType == VARALARM)
    {
        ui->isDisplay->setEnabled(false);
        ui->isDisplay->setChecked(false);
        this->slotIsdisplayClicked(false);
        setAlarmPara();
    }
    else if(curVarType == VARDATE)
    {
        setDatePara();
    }
    else if(curVarType == VARTIME)
    {
        setTimePara();
    }
    else if(curVarType == VARDATETIME)
    {
        SetDateTimePara();
    }
    else if(curVarType == VARSINGLE)
    {
        cmdParameters cp = functionStruct->getCmdParameters();
        if(functionStruct->getVarType() == VARCMD)
        {
            ui->operationAction->clear();
            ui->operationAction->addItem(cp.dis1);
            ui->operationAction->addItem(cp.dis2);
            ui->operationAction->setCurrentText(cp.dis1);
            ui->triggerPara->setEnabled(false);
            ui->triggerDis->setEnabled(false);
            ui->triggerPara_2->setEnabled(false);
            ui->triggerDis_2->setEnabled(false);
        }
        else
        {
            ui->label_9->setVisible(false);
            ui->operationAction->setVisible(false);
            ui->triggerPara->setText(cp.parameter1);
            ui->triggerDis->setText(cp.dis1);
            ui->singleReturn->setText(cp.statusValue1);
            ui->operationOrder->setText(cp.para1_other);
            ui->triggerPara_2->setText(cp.parameter2);
            ui->triggerDis_2->setText(cp.dis2);
            ui->singleReturn_2->setText(cp.statusValue2);
        }
    }
    else if(curVarType == VAROUT)
    {
        ui->label_90->setVisible(false);
        ui->isDisplay->setEnabled(false);
        ui->isDisplay->setChecked(false);
        this->slotIsdisplayClicked(false);
        ui->outParaNumber->setValue(functionStruct->getOutPara().itemList.size());
    }
    else if(curVarType == VARINPUT)
    {
        ui->returnedValLen->setText("0");
        ui->returnedValLen->setEnabled(false);
        ui->returnTypeBox->setCurrentIndex(RETURNNULL);
        ui->returnTypeBox->setEnabled(false);
        ui->startPos->setText("");
        ui->dataLength->setText("0");
        ui->startPos->setEnabled(false);
        ui->dataLength->setEnabled(false);
    }
    else if(curVarType == VAREVENT)
    {
        ui->returnedValLen->setText("0");
        ui->returnedValLen->setEnabled(false);
        ui->isDisplay->setEnabled(false);
        ui->isDisplay->setChecked(false);
        this->slotIsdisplayClicked(false);
        if(functionStruct->getVarType() == VARCMD)
        {
            cmdParameters cp = functionStruct->getCmdParameters();
            ui->eventReturn->setText(cp.statusValue1);
        }
    }
    else
    {
        QDEBUG()<<"变量类型错误";
    }
}

void ParameterWidget::slotReturnTypeChanged(int index)
{
    ui->returnStacked->setCurrentIndex(index);
    switch(index)
    {
    case RETURNBYTE:
        ui->startPos->setText(functionStruct->getDataPos());
        ui->dataLength->setText(functionStruct->getDataLength());
        break;

    case RETURNBIT:
        ui->bytePos->setText(functionStruct->getDataPos());
        ui->bitPos->setText(functionStruct->getDataLength());
        break;

    default:
        QDEBUG()<<"未知返回类型";
        break;
    }
}

void ParameterWidget::slotSingleActiongChanged(int index)
{
    QDEBUG()<<"单操作型动作"<<index;
    cmdParameters cmdPara = functionStruct->getCmdParameters();
    if(index == 0)
    {
        ui->triggerPara->setText(cmdPara.parameter1);
        ui->triggerDis->setText(cmdPara.dis1);
        ui->singleReturn->setText(cmdPara.statusValue1);
        ui->operationOrder->setText(cmdPara.para1_other);
        ui->triggerPara_2->setText(cmdPara.parameter2);
        ui->triggerDis_2->setText(cmdPara.dis2);
        ui->singleReturn_2->setText(cmdPara.statusValue2);
    }
    else if(index == 1)
    {
        ui->triggerPara->setText(cmdPara.parameter2);
        ui->triggerDis->setText(cmdPara.dis2);
        ui->singleReturn->setText(cmdPara.statusValue2);
        ui->operationOrder->setText(cmdPara.para2_other);
        ui->triggerPara_2->setText(cmdPara.parameter1);
        ui->triggerDis_2->setText(cmdPara.dis1);
        ui->singleReturn_2->setText(cmdPara.statusValue1);
    }
}

void ParameterWidget::slotOutNumberChanged(int value)
{
    QDEBUG()<<"输出型ITEM数量"<<value;

    _varOutType outType = functionStruct->getOutPara();
    QDEBUG()<<"paraNumber"<<outType.itemList.size();

    int itemNumber = outParaList.size();
    QDEBUG()<<"list中Item数量"<<itemNumber;

    for(int i=0; i<itemNumber; i++)
    {
        outParaList.at(i)->setVisible(false);
        outParaDscList.at(i)->setVisible(false);
        outStatusList.at(i)->setVisible(false);
        outOrderList.at(i)->setVisible(false);
        outDefaultList.at(i)->setVisible(false);
    }

    for(int i=0; i<value; i++)
    {
        if(i<outParaList.size())
        {
            outParaList.at(i)->setVisible(true);
            outParaDscList.at(i)->setVisible(true);
            outStatusList.at(i)->setVisible(true);
            outOrderList.at(i)->setVisible(true);
            outDefaultList.at(i)->setVisible(false);
        }
        else
        {
            QLineEdit* outPara = new QLineEdit();
            QLineEdit* outParaDsc = new QLineEdit();
            QLineEdit* outStatus = new QLineEdit();
            QLineEdit* outOrder = new QLineEdit();
            QRadioButton* outDefault = new QRadioButton();

            outPara->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
            outStatus->setValidator(new QRegExpValidator(QRegExp("[a-fA-F0-9]{40}")));
            outOrder->setValidator(new QRegExpValidator(QRegExp("[a-fA-F0-9]{40}")));

            outParaList.append(outPara);
            outParaDscList.append(outParaDsc);
            outStatusList.append(outStatus);
            outOrderList.append(outOrder);
            outDefaultList.append(outDefault);

            ui->outLayout->addWidget(outPara, i, 1, 1, 1);
            ui->outLayout->addWidget(outParaDsc, i, 2, 1, 1);
            ui->outLayout->addWidget(outStatus, i, 3, 1, 1);
            ui->outLayout->addWidget(outOrder, i, 4, 1, 1);
            ui->outLayout->addWidget(outDefault, i, 5, 1, 1);

            ui->outLayout->setColumnStretch(1,2);
            ui->outLayout->setColumnStretch(2,2);
            ui->outLayout->setColumnStretch(3,2);
            ui->outLayout->setColumnStretch(4,6);

            if(i<outType.itemList.size())
            {
                outPara->setText(outType.itemList.at(i)->paraValue);
                outParaDsc->setText(outType.itemList.at(i)->paraDsc);
                outStatus->setText(outType.itemList.at(i)->statusValue);
                outOrder->setText(outType.itemList.at(i)->paraOrder);
                outDefault->setChecked(outType.itemList.at(i)->isDefault);
            }

            else if(functionStruct->getVarType() == VARCMD)
            {
                if(i<2)
                {
                    outPara->setEnabled(false);
                    outParaDsc->setEnabled(false);
                    cmdParameters cp = functionStruct->getCmdParameters();
                    if(0 == i)
                    {
                        outPara->setText(cp.parameter1);
                        outParaDsc->setText(cp.dis1);
                        if(outOrder->text() == "")
                        {
                            outOrder->setText(cp.para1_other);
                        }
                        if(outStatus->text() == "")
                        {
                            outStatus->setText(cp.statusValue1);
                        }
                    }
                    else if(1 == i)
                    {
                        outPara->setText(cp.parameter2);
                        outParaDsc->setText(cp.dis2);
                        if(outStatus->text() == "")
                        {
                            outStatus->setText(cp.statusValue2);
                        }
                        if(outOrder->text() == "")
                        {
                            outOrder->setText(cp.para2_other);
                        }
                    }
                }
            }
            else if(functionStruct->getVarType() == VARENUMBERATE)
            {
                enumParameters ep = functionStruct->getenumParameters();
                QDEBUG()<<"enumParaList.size"<<ep.enumParaList.size();
                if(i<ep.enumParaList.size())
                {
                    outPara->setEnabled(false);
                    outParaDsc->setEnabled(false);

                    outPara->setText(ep.enumParaList.at(i)->value);
                    outParaDsc->setText(ep.enumParaList.at(i)->display);
                    if(outStatus->text() == "")
                    {
                        outStatus->setText(ep.enumParaList.at(i)->statusValue);
                    }
                    if(outOrder->text() == "")
                    {
                        outOrder->setText(ep.enumParaList.at(i)->otherPara);
                    }
                }
            }
        }
    }
}

/*显示部分*/
void ParameterWidget::slotDisEnumNumerChanged(int value)
{
    QDEBUG()<<"显示枚举ITEM数量"<<value;

    _disEnum disEnum = functionStruct->getDisEnum();
    QDEBUG()<<"disEnumItemNumber"<<disEnum.disEnumList.size();

    int itemNumber = disEnumParaList.size();
    QDEBUG()<<"list中Item数量"<<itemNumber;

    for(int i=0; i<itemNumber; i++)
    {
        disEnumIsSelectList.at(i)->setVisible(false);
        disEnumParaList.at(i)->setVisible(false);
        disEnumStrList.at(i)->setVisible(false);
        disEnumPicList.at(i)->setVisible(false);
    }
    for(int i=0; i<value; i++)
    {
        if(i<disEnumIsSelectList.size())
        {
            disEnumIsSelectList.at(i)->setVisible(true);
            disEnumParaList.at(i)->setVisible(true);
            disEnumStrList.at(i)->setVisible(true);
            disEnumPicList.at(i)->setVisible(true);
        }
        else
        {
            QCheckBox* select = new QCheckBox();
            QLineEdit* value = new QLineEdit();
            QLineEdit* str = new QLineEdit();
            QLineEdit* pic = new QLineEdit();

            disEnumIsSelectList.append(select);
            disEnumParaList.append(value);
            disEnumStrList.append(str);
            disEnumPicList.append(pic);

            ui->gridLayout_14->addWidget(select, i, 0, 1, 1);
            ui->gridLayout_14->addWidget(value, i, 1, 1, 1);
            ui->gridLayout_14->addWidget(str, i, 2, 1, 1);
            ui->gridLayout_14->addWidget(pic, i, 3, 1, 1);

            ui->gridLayout_14->setColumnStretch(0, 1);
            ui->gridLayout_14->setColumnStretch(1, 5);
            ui->gridLayout_14->setColumnStretch(2, 5);
            ui->gridLayout_14->setColumnStretch(3, 5);

            ui->gridLayout_14->setContentsMargins(12, 0, 0, 0);

            value->setValidator(new QRegExpValidator(QRegExp("[0-9]{5}")));
            pic->setValidator(new QRegExpValidator(QRegExp("[0-9]{5}")));
            if(i< disEnum.disEnumList.size())
            {
                select->setChecked(disEnum.disEnumList.at(i)->select);
                value->setText(disEnum.disEnumList.at(i)->value);
                str->setText(disEnum.disEnumList.at(i)->string);
                pic->setText(disEnum.disEnumList.at(i)->pic);
            }
            if(functionStruct->getVarType() == VARENUMBERATE)
            {
                value->setEnabled(false);
                enumParameters ep = functionStruct->getenumParameters();
                if(i < ep.enumParaList.size())
                {
                    select->setChecked(ep.enumParaList.at(i)->isSlect);
                    value->setText(ep.enumParaList.at(i)->value);
                    if(str->text() == "")
                    {
                        str->setText(ep.enumParaList.at(i)->display);
                    }
                }
            }
            else if(functionStruct->getVarType() == VARCMD)
            {
                select->setEnabled(false);
                value->setEnabled(false);
                cmdParameters cp = functionStruct->getCmdParameters();
                if(i == 0)
                {
                    select->setChecked(true);
                    value->setText(cp.parameter1);
                    if(str->text() == "")
                    {
                        str->setText(cp.dis1);
                    }
                }
                else if(i == 1)
                {
                    select->setChecked(true);
                    value->setText(cp.parameter2);
                    if(str->text() == "")
                    {
                        str->setText(cp.dis2);
                    }
                }
            }
        }
    }
}

void ParameterWidget::slotIsdisplayClicked(bool b)
{
    if(b)
    {
        QDEBUG()<<"显示";
        ui->disTypeBox->setEnabled(true);
        ui->disScrollUnit->setEnabled(true);
        ui->stackedWidget_display->setEnabled(true);
        ui->disName->setEnabled(true);
        ui->disFunPic->setEnabled(true);
    }
    else
    {
        QDEBUG()<<"不显示";
        ui->disTypeBox->setEnabled(false);
        ui->disScrollUnit->setEnabled(false);
        ui->stackedWidget_display->setEnabled(false);
        ui->disName->setEnabled(false);
        ui->disFunPic->setEnabled(false);
    }
}

void ParameterWidget::slotDisTypeChanged(int index)
{
    ui->stackedWidget_display->setCurrentIndex(index);
    curDisType = index + 1;
    QDEBUG()<<"当前显示类型"<<ui->disTypeBox->currentText();
    if(curDisType == DISSTRING)
    {
        QDEBUG()<<"保存显示类型字符";
        QString disStr = functionStruct->getDisString();
        ui->disStr->setText(disStr);
    }
    if(curDisType == DISPICTURE)
    {
        QDEBUG()<<"保存显示类型图片";
        QString disPic = functionStruct->getDisPic();
        ui->disPic->setValidator(new QRegExpValidator(QRegExp("[0-9]{5}")));
        ui->disPic->setText(disPic);
    }
    if(curDisType == DISDATE)
    {
        QDEBUG()<<"保存显示类型日期";
        _disDateTime disDate = functionStruct->getDisDateTime();
        ui->disDateYear->setText(disDate.disYear);
        ui->disDateMon->setText(disDate.disMonth);
        ui->disDateDay->setText(disDate.disDay);
        if(ui->disDateYear->text() == "")
        {
            ui->disDateYear->setText("年");
        }
        if(ui->disDateMon->text() == "")
        {
            ui->disDateMon->setText("月");
        }
        if(ui->disDateDay->text() == "")
        {
            ui->disDateDay->setText("日");
        }
    }
    if(curDisType == DISTIME)
    {
        QDEBUG()<<"保存显示类型时间";
        _disDateTime disTime = functionStruct->getDisDateTime();
        ui->disTimeHour->setText(disTime.disHour);
        ui->disTimeMin->setText(disTime.disMin);
        ui->disTimeSec->setText(disTime.disSec);
        if(ui->disTimeHour->text() == "")
        {
            ui->disTimeHour->setText("时");
        }
        if(ui->disTimeMin->text() == "")
        {
            ui->disTimeMin->setText("分");
        }
        if(ui->disTimeSec->text() == "")
        {
            ui->disTimeSec->setText("秒");
        }
    }
    if(curDisType == DISNUMBER)
    {
        QDEBUG()<<"保存显示类型数字";
        _disNumber disNumber = functionStruct->getDisNumber();
        ui->disNumberDefault->setText(disNumber.disPara);
        ui->disNumberScall->setText(disNumber.disScaling);
        ui->disNumberScall->setValidator(new QRegExpValidator(QRegExp("[.0-9]{10}")));
        ui->disNumberDefault->setValidator(new QRegExpValidator(QRegExp("[0-9]{5}")));
        if(functionStruct->getVarType() == VARNUMBER)
        {
            numberParamters np = functionStruct->getNumberParameters();
            ui->disNumberDefault->setText(np.defaultValue);
//            ui->disNumberDefault->setEnabled(false);
            if(ui->disNumberScall->text() == "")
            {
                ui->disNumberScall->setText(np.scalling);
            }
        }
    }

    if(curDisType == DISCMD)
    {
        QDEBUG()<<"保存显示类型命令";
        _disCmd disCmd = functionStruct->getDisCmd();
        ui->disCmdValue1->setText(disCmd.value1);
        ui->disCmdValue2->setText(disCmd.value2);
        ui->disCmdstr1->setText(disCmd.string1);
        ui->disCmdpic1->setText(disCmd.pic1);
        ui->disCmdstr2->setText(disCmd.string2);
        ui->disCmdPic2->setText(disCmd.pic2);
        ui->disCmdValue1->setValidator(new QRegExpValidator(QRegExp("[0-9]{5}")));
        ui->disCmdValue2->setValidator(new QRegExpValidator(QRegExp("[0-9]{5}")));
        ui->disCmdpic1->setValidator(new QRegExpValidator(QRegExp("[0-9]{5}")));
        ui->disCmdPic2->setValidator(new QRegExpValidator(QRegExp("[0-9]{5}")));
        if(functionStruct->getVarType() == VARCMD)
        {
            cmdParameters cp = functionStruct->getCmdParameters();
            ui->disCmdValue1->setText(cp.parameter1);
            ui->disCmdValue2->setText(cp.parameter2);
            ui->disCmdValue1->setEnabled(false);
            ui->disCmdValue2->setEnabled(false);
            if(disCmd.string1 == "")
            {
                ui->disCmdstr1->setText(cp.dis1);
            }
            if(disCmd.string2 == "")
            {
                ui->disCmdstr2->setText(cp.dis2);
            }
        }
    }
    if(curDisType == DISENUMBERATE)
    {
        QDEBUG()<<"保存显示类型枚举";
        if(functionStruct->getVarType() == VARENUMBERATE)
        {
            ui->disEnumNumber->setEnabled(false);
            ui->disEnumNumber->setValue(functionStruct->getenumParameters().enumParaList.size());
        }
        else if(functionStruct->getVarType() == VARCMD)
        {
            ui->disEnumNumber->setEnabled(false);
            ui->disEnumNumber->setValue(2);
        }
        else
        {
            ui->disEnumNumber->setValue(functionStruct->getDisEnum().disEnumList.size());
        }
    }
    if(curDisType == DISSCROL)
    {
        QDEBUG()<<"保存显示类型滚动条";
        _disScroll disScroll = functionStruct->getDisScroll();
        ui->disScrollDefaul->setText(disScroll.disDefault);
        ui->disScrollMax->setText(disScroll.disMax);
        ui->disScrollMin->setText(disScroll.disMin);
        ui->disScrollStep->setText(disScroll.disStep);
        ui->disScrollDefaul->setValidator(new QRegExpValidator(QRegExp("[0-9]{5}")));
        ui->disScrollMax->setValidator(new QRegExpValidator(QRegExp("[0-9]{5}")));
        ui->disScrollMin->setValidator(new QRegExpValidator(QRegExp("[0-9]{5}")));
        ui->disScrollStep->setValidator(new QRegExpValidator(QRegExp("[0-9]{5}")));
        ui->disScrollUnit->setValidator(new QRegExpValidator(QRegExp("[.0-9]{10}")));
        if(functionStruct->getVarType() == VARNUMBER)
        {
//            ui->disScrollDefaul->setEnabled(false);
//            ui->disScrollMax->setEnabled(false);
//            ui->disScrollMin->setEnabled(false);
//            ui->disScrollStep->setEnabled(false);
            numberParamters np = functionStruct->getNumberParameters();
            if(ui->disScrollDefaul->text() == "")
            {
                ui->disScrollDefaul->setText(np.defaultValue);
            }
            if(ui->disScrollMax->text() == "")
            {
                ui->disScrollMax->setText(np.max);
            }
            if(ui->disScrollMin->text() == "")
            {
                ui->disScrollMin->setText(np.min);
            }
        }
    }
    if(curDisType == DISDATETIME)
    {
        _disDateTime disDateTime = functionStruct->getDisDateTime();
        ui->disDatetimeYear->setText(disDateTime.disYear);
        ui->disDatetimeMon->setText(disDateTime.disMonth);
        ui->disDatetimeDay->setText(disDateTime.disDay);
        ui->disDatetimeHour ->setText(disDateTime.disHour);
        ui->disDatetimeMin->setText(disDateTime.disMin);
        ui->disDatetimeSec->setText(disDateTime.disSec);

        if(ui->disDatetimeYear->text() == "")
        {
            ui->disDatetimeYear->setText("年");
        }
        if(ui->disDatetimeMon->text() == "")
        {
            ui->disDatetimeMon->setText("月");
        }
        if(ui->disDatetimeDay->text() == "")
        {
            ui->disDatetimeDay->setText("日");
        }
        if(ui->disDatetimeHour->text() == "")
        {
            ui->disDatetimeHour->setText("时");
        }
        if(ui->disDatetimeMin->text() == "")
        {
            ui->disDatetimeMin->setText("分");
        }
        if(ui->disDatetimeSec->text() == "")
        {
            ui->disDatetimeSec->setText("秒");
        }
    }
}
