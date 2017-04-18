#include "parameterwidget.h"
#include "ui_parameterwidget.h"

#define QDEBUG() qDebug()<<"parameterwidget.cpp"<<__LINE__

ParameterWidget::ParameterWidget(FunctionStruct *f, QDialog *parent):
    QDialog(parent),
    ui(new Ui::ParameterWidget)
{
    ui->setupUi(this);

    this->ui->AlarmtableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   // 不可编辑
    this->ui->AlarmtableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  // #整行选中的方式

    this->functionStruct = f;
    init();
}

ParameterWidget::~ParameterWidget()
{
    delete ui;
}

void ParameterWidget::init()
{
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
    query.exec(str);
    query.next();
    this->ui->orderDeviceTypeEdit->setText(query.value("class_name").toString());

    str = "select * from command_type where id = " + QString::number(functionStruct->getVarType());
    QDEBUG()<<str;
    query.exec(str);
    query.next();
    this->ui->orderDataTypeEdit->setText(query.value("type_name").toString());

    ui->orderCmdTypeEdit->setText(functionStruct->getOrderType());
    ui->orderParaTextEdit->setPlainText(functionStruct->getParameters());
    ui->functionLimit->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->returnedValLen->setEnabled(false);
    ui->dataTypeBox->setEnabled(false);
    QStringList strList;
    strList.append(DATATYPENULL);
    strList.append(DATATYPEUINT8);
    strList.append(DATATYPEINT8);
    strList.append(DATATYPEUINT16);
    strList.append(DATATYPEINT16);
    strList.append(DATATYPEUINT32);
    strList.append(DATATYPEINT32);
    ui->dataTypeBox->addItems(strList);
    ui->dataTypeBox->setCurrentIndex(functionStruct->getDataType().toInt());

    if(functionStruct->getUserLeverLimit() != "")
    {
        ui->functionLimit->setText(functionStruct->getUserLeverLimit());
    }
    else
    {
        ui->functionLimit->setText("0");
    }

    QDEBUG()<<"varindex"<<functionStruct->getVarIndex();
    if(functionStruct->getVarIndex() != 999999)
    {
        str = "select * from command_type where (id > 0 and id <> 4) order by id";
        query.exec(str);
        QDEBUG()<<str;
        while(query.next())
        {
            this->ui->varTypeBox->addItem(query.value("type_name").toString());
        }
        if(functionStruct->getNewVarType() < VARALARM)
        {
            ui->varTypeBox->setCurrentIndex(functionStruct->getNewVarType()-1);
        }
        else
        {
           ui->varTypeBox->setCurrentIndex(functionStruct->getNewVarType()-2);
        }
    }
    else
    {
        ui->functionLimit->setEnabled(false);
        ui->functionLimit->setText("0");
        ui->isDisplay->setEnabled(false);
        ui->varTypeBox->addItem("报警");
        ui->varTypeBox->setEnabled(false);
    }

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

    ui->disName->setText(functionStruct->getDisName());
    ui->disFunPic->setText(functionStruct->getIconIndex());
    ui->disFunPic->setValidator(new QRegExpValidator(QRegExp("[0-9]{5}")));
}

cmdParameters ParameterWidget::getCmdParameters()
{
    cmdParameters c = functionStruct->getCmdParameters();
    if(curVarType == VARCMD)
    {
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
        c.curValue = ui->triggerPara->text();
        c.otherOrder = ui->operationOrder->text();
    }
    return c;
}

numberParamters ParameterWidget::getNumParameters()
{
    numberParamters n = functionStruct->getNumberParameters();
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
    enumParameters e = functionStruct->getenumParameters();
    for(int i=0; i<e.enumParaList.size(); i++)
    {
        e.enumParaList.at(i)->isSlect = enumIsSelectList.at(i)->isChecked();
        if(defaultRadionList.at(i)->isChecked())
        {
            e.defaultValue = e.enumParaList.at(i)->value;
        }
        e.enumParaList.at(i)->otherPara = otherParaList.at(i)->text();
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
    dateTimeParameters dt; // = functionStruct->getDateTimeParameters();
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
    for(int i=0; i<outParaList.size(); i++)
    {
        _varOutItem *item = new _varOutItem;
        item->paraValue = outParaList.at(i)->text();
        item->paraDsc = outParaDscList.at(i)->text();
        item->paraOrder = outOrderList.at(i)->text();
        item->isDefault = outDefaultList.at(i)->isChecked();
        out.itemList.append(item);
    }
    return out;
}

alarmParameters ParameterWidget::getAlarmParameters2()
{
    QTableWidget *tableWidget = this->ui->AlarmtableWidget;
    alarmParameters ap;

    for(int i=0;i<tableWidget->rowCount();i++)
    {
        QDEBUG()<<tableWidget->item(i,0)->text().toInt();
        QDEBUG()<<tableWidget->item(i,1)->text();
        QDEBUG()<<tableWidget->item(i,2)->text().toInt();
        warningStruct *mywarn = new warningStruct();
        mywarn->setVarindex(tableWidget->item(i,0)->text().toInt());
        mywarn->setWarnName(tableWidget->item(i,1)->text());
        mywarn->setWarnClass(tableWidget->item(i,2)->text().toInt());
        ap.warningList.append(mywarn);
    }
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
        for(int i=0; i<disEnumParaList.size(); i++)
        {
            _disEnumPara *enumpara = new _disEnumPara;
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
    functionStruct->setDataType(QString::number(ui->dataTypeBox->currentIndex()));
    functionStruct->setNewVarType(varType, true);
    QDEBUG()<<"当前变量类型"<<varType;

    if((varType == VARCMD) || (varType == VARSINGLE))
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
        qDebug()<<"vartype"<<varType;
        alarmParameters ap = getAlarmParameters2();
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

void ParameterWidget::slotAlarmItemClicked(QListWidgetItem *item)
{
    AlarmListWidgetItem * alarmItem = (AlarmListWidgetItem *)(item);
    QTableWidget *tableWidget = this->ui->AlarmtableWidget;
    int row = tableWidget->rowCount();
    for(int i=0; i<row; i++)
    {
        if(alarmItem->getVarIndex() == tableWidget->item(i,0)->text().toInt())
        {
            return;
        }
    }
    tableWidget->insertRow(row);
    tableWidget->setItem(row,0,new QTableWidgetItem(QString::number(alarmItem->getVarIndex())));
    tableWidget->setItem(row,1,new QTableWidgetItem(alarmItem->getAlarmString()));
    tableWidget->setItem(row,2,new QTableWidgetItem(QString::number(alarmItem->getAlamClass())));

    int len = tableWidget->rowCount()/8;
    if(tableWidget->rowCount()%8 != 0)
    {
        len++;
    }
    ui->returnedValLen->setText(QString::number(len));
    ui->dataTypeBox->setCurrentIndex(len+len-1);
}

AlarmListWidgetItem::AlarmListWidgetItem(const int varIndex, QString text, int alarmclass):QListWidgetItem(text)
{
    this->alarmString = text;
    this->varIndex = varIndex;
    this->alamClass = alarmclass;

}

int AlarmListWidgetItem::getVarIndex() const
{
    return varIndex;
}

void AlarmListWidgetItem::setVarIndex(int value)
{
    varIndex = value;
}

QString AlarmListWidgetItem::getAlarmString() const
{
    return alarmString;
}

void AlarmListWidgetItem::setAlarmString(const QString &value)
{
    alarmString = value;
}

int AlarmListWidgetItem::getAlamClass() const
{
    return alamClass;
}

void AlarmListWidgetItem::setAlamClass(int value)
{
    alamClass = value;
}

void ParameterWidget::setCmdPara()
{
    ui->returnedValLen->setText("1");
    ui->dataTypeBox->setCurrentText(DATATYPEUINT8);
    ui->cmdParameter1LineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]{5}")));
    ui->cmdParameter2LineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]{5}")));
    ui->cmdOrder1Edit->setValidator(new QRegExpValidator(QRegExp("[a-fA-F0-9]{20}")));;
    ui->cmdOrder2Edit->setValidator(new QRegExpValidator(QRegExp("[a-fA-F0-9]{20}")));

    cmdParameters cp = functionStruct->getCmdParameters();
    this->ui->cmdParameter1LineEdit->setText(cp.parameter1);
    this->ui->cmdParameter2LineEdit->setText(cp.parameter2);
    this->ui->cmdDis1LineEdit->setText(cp.dis1);
    this->ui->cmdDis2LineEdit->setText(cp.dis2);
    if(cp.para1_other != "")
    {
        this->ui->cmdOrder1Edit->setText(cp.para1_other);
    }
    else
    {
        QString orderStr = functionStruct->getStr(functionStruct->getVarIndex(), 4, true);
        orderStr.append(functionStruct->getStr(cp.parameter1.toInt(), 2, true));
        this->ui->cmdOrder1Edit->setText(orderStr);
    }
    if(cp.para2_other != "")
    {
        this->ui->cmdOrder2Edit->setText(cp.para2_other);
    }
    else
    {
        QString orderStr = functionStruct->getStr(functionStruct->getVarIndex(), 4, true);
        orderStr.append(functionStruct->getStr(cp.parameter2.toInt(), 2, true));
        this->ui->cmdOrder2Edit->setText(orderStr);
    }
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
        ui->cmdParameter2LineEdit->setEnabled(false);
    }
}

void ParameterWidget::setNumberPara()
{
    ui->returnedValLen->setText("2");
    ui->dataTypeBox->setCurrentText(DATATYPEUINT16);

    ui->numberParaEndian->addItem("大端");
    ui->numberParaEndian->addItem("小端");
    QStringList strList;
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
    ui->NumberUnitcomboBox->addItems(strList);
    ui->NumberMaxlineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]{5}")));
    ui->NumberMinlineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]{5}")));
    ui->NumberDefaultlineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]{5}")));
    ui->klineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]{5}")));
    ui->clineEdit_2->setValidator(new QRegExpValidator(QRegExp("[0-9]{5}")));
    ui->numberOrderEdit->setValidator(new QRegExpValidator(QRegExp("[a-fA-F0-9]{20}")));
    ui->numberParaLen->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->numberParaOffset->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->NumberScallinglineEdit->setValidator(new QRegExpValidator(QRegExp("[.0-9]{10}")));

    numberParamters np = functionStruct->getNumberParameters();
    this->ui->NumberMaxlineEdit->setText(np.max);
    this->ui->NumberMinlineEdit->setText(np.min);
    this->ui->NumberDefaultlineEdit->setText(np.defaultValue);
    ui->klineEdit->setText(np.kFactor);
    ui->clineEdit_2->setText(np.cFactor);
    this->ui->NumberScallinglineEdit->setText(np.scalling);
    this->ui->NumberUnitcomboBox->setCurrentIndex(np.uint.toInt());

    if(np.otherPara != "")
    {
        this->ui->numberOrderEdit->setText(np.otherPara);
        this->ui->numberParaLen->setText(np.other.valueLen);
        this->ui->numberParaOffset->setText(np.other.valuePos);
    }
    else
    {
        QString orderStr = functionStruct->getStr(functionStruct->getVarIndex(), 4, true);
        orderStr.append(functionStruct->getStr(np.defaultValue.toInt(), 4, true));
        this->ui->numberOrderEdit->setText(orderStr);
        ui->numberParaLen->setText("2");
        ui->numberParaOffset->setText("2");
    }
    if(np.endian != "")
    {
        this->ui->numberParaEndian->setCurrentIndex(np.endian.toInt()-1);
    }
    else
    {
        ui->numberParaEndian->setCurrentIndex(0);
    }
    if(functionStruct->getVarType() == VARNUMBER)
    {
        ui->NumberMaxlineEdit->setEnabled(false);
        ui->NumberMinlineEdit->setEnabled(false);
        ui->NumberScallinglineEdit->setEnabled(false);
        ui->NumberUnitcomboBox->setEnabled(false);
    }
}

void ParameterWidget::setEunmPara()
{
    ui->returnedValLen->setText("1");
    ui->dataTypeBox->setCurrentText(DATATYPEUINT8);
    if(functionStruct->getVarType() == VARENUMBERATE)
    {
        enumParameters e = functionStruct->getenumParameters();
        QDEBUG()<<"枚举数量"<<e.enumParaList.size();

        for(int i=0; i<e.enumParaList.size(); i++)
        {
            QCheckBox *slect = new QCheckBox();
            QLineEdit *vle = new QLineEdit();
            QLineEdit *dle = new QLineEdit();
            QLineEdit *otherEdit = new QLineEdit();
            QRadioButton *rb = new QRadioButton();

            vle->setEnabled(false);
            dle->setEnabled(false);
            otherEdit->setValidator(new QRegExpValidator(QRegExp("[.0-9]{10}")));

            slect->setChecked(e.enumParaList.at(i)->isSlect);
            vle->setText(e.enumParaList.at(i)->value);
            dle->setText(e.enumParaList.at(i)->display);
            if(e.enumParaList.at(i)->otherPara != "")
            {
                otherEdit->setText(e.enumParaList.at(i)->otherPara);
            }
            else
            {
                 QString orderStr = functionStruct->getStr(functionStruct->getVarIndex(), 4, true);
                 orderStr.append(functionStruct->getStr(e.enumParaList.at(i)->value.toInt(), 2, true));
                 otherEdit->setText(orderStr);
            }
            if(e.enumParaList.at(i)->value == e.defaultValue)
            {
                rb->setChecked(true);
            }

            this->enumIsSelectList.append(slect);
            this->valueEditList.append(vle);
            this->otherParaList.append(otherEdit);
            this->disEditList.append(dle);
            this->defaultRadionList.append(rb);

            ui->gridLayout_3->addWidget(slect,i,0,1,1);
            ui->gridLayout_3->addWidget(vle,i,1,1,1);
            ui->gridLayout_3->addWidget(dle,i,2,1,1);
            ui->gridLayout_3->addWidget(otherEdit,i,3,1,1);
            ui->gridLayout_3->addWidget(rb,i,4,1,1);

            ui->gridLayout_3->setColumnStretch(0, 1);
            ui->gridLayout_3->setColumnStretch(1, 3);
            ui->gridLayout_3->setColumnStretch(2, 3);
            ui->gridLayout_3->setColumnStretch(3, 6);

            ui->gridLayout_3->setContentsMargins(15, 0, 0, 0);
        }
    }
}

void ParameterWidget::setAlarmPara()
{
    if(functionStruct->getVarType() == VARALARM)
    {
        alarmParameters ap = functionStruct->getAlarmParameters();

        int len = ap.warningList.size()/8;
        if(ap.warningList.size()%8 != 0)
        {
            len++;
        }
        ui->returnedValLen->setText(QString::number(len));
        ui->dataTypeBox->setCurrentIndex((len+len-1));
        connect(this->ui->AlarmlistWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(slotAlarmItemClicked(QListWidgetItem*)));
        connect(this->ui->AlarmtableWidget,SIGNAL(cellClicked(int,int)),this,SLOT(slotAlarmCellClicked(int,int)));
        for(int i=0;i<ap.warningList.size();i++)
        {
            this->ui->AlarmtableWidget->insertRow(i);
            this->ui->AlarmtableWidget->setItem(i,0,new QTableWidgetItem(QString::number(ap.warningList.at(i)->getVarindex())));
            this->ui->AlarmtableWidget->setItem(i,1,new QTableWidgetItem(ap.warningList.at(i)->getWarnName()));
            this->ui->AlarmtableWidget->setItem(i,2,new QTableWidgetItem(QString::number(ap.warningList.at(i)->getWarnClass())));
        }
    }
    else
    {
        QDEBUG()<<"待续";
    }
}

void ParameterWidget::setDatePara()
{
    ui->returnedValLen->setText("4");
    ui->dataTypeBox->setCurrentText(DATATYPEUINT8);

    ui->dateEndian->addItem("大端");
    ui->dateEndian->addItem("小端");

    ui->dateOrder->setValidator(new QRegExpValidator(QRegExp("[a-fA-F0-9]{20}")));
    ui->dateYSteplineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->dateYearLen->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->dateYearOffset->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->dateMSteplineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->dateMonLen->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->dateMonOffset->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->dateDSteplineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->dateDayLen->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->dateDayOffset->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));

    dateTimeParameters dp = functionStruct->getDateTimeParameters();
    this->ui->dateMaxEdit->setDate(dp.maxDate);
    this->ui->dateMinEdit->setDate(dp.minDate);
    this->ui->dateDefault->setDate(dp.date);
    this->ui->dateYSteplineEdit->setText(dp.yearStep);
    this->ui->dateMSteplineEdit->setText(dp.monthStep);
    this->ui->dateDSteplineEdit->setText(dp.dayStep);

    if(dp.otherPara != "")
    {
        ui->dateOrder->setText(dp.otherPara);
        ui->dateYearLen->setText(dp.yearOther.valueLen);
        ui->dateYearOffset->setText(dp.yearOther.valuePos);
        ui->dateMonLen->setText(dp.monthOther.valueLen);
        ui->dateMonOffset->setText(dp.monthOther.valuePos);
        ui->dateDayLen->setText(dp.dayOther.valueLen);
        ui->dateDayOffset->setText(dp.dayOther.valuePos);
    }
    else
    {
        QString orderStr = functionStruct->getStr(functionStruct->getVarIndex(), 4, true);
        orderStr.append(functionStruct->getStr(dp.date.year(), 4, false));
        orderStr.append(functionStruct->getStr(dp.date.month(), 2, false));
        orderStr.append(functionStruct->getStr(dp.date.day(), 2, false));
        ui->dateOrder->setText(orderStr);
        ui->dateYearLen->setText("2");
        ui->dateYearOffset->setText("2");
        ui->dateMonLen->setText("1");
        ui->dateMonOffset->setText("4");
        ui->dateDayLen->setText("1");
        ui->dateDayOffset->setText("5");
    }
    if(dp.endian != "")
    {
        ui->dateEndian->setCurrentIndex(dp.endian.toInt()-1);
    }
    else
    {
        ui->dateEndian->setCurrentIndex(0);
    }
}

void ParameterWidget::setTimePara()
{
    QDEBUG()<<"时间型变量";
    ui->returnedValLen->setText("3");
    ui->dataTypeBox->setCurrentText(DATATYPEUINT8);

    ui->timeEndian->clear();
    ui->timeEndian->addItem("大端");
    ui->timeEndian->addItem("小端");

    ui->timeOrder->setValidator(new QRegExpValidator(QRegExp("[a-fA-F0-9]{20}")));
    ui->timeHStepLineedit->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->timeHourLen->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->timeHourOffset->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->timeMStepLineedit->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->timeMinLen->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->timeMinOffset->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->timeSStepLineedit->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->timeSecLen->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
    ui->timeSecOffset->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));

    dateTimeParameters tp = functionStruct->getDateTimeParameters();
    this->ui->timeMaxEdit->setTime(tp.maxTime);
    this->ui->timeMinEdit->setTime(tp.minTime);
    this->ui->timeEdit->setTime(tp.time);
    this->ui->timeHStepLineedit->setText(tp.hourStep);
    this->ui->timeMStepLineedit->setText(tp.minuteStep);
    this->ui->timeSStepLineedit->setText(tp.secondStep);

    if(tp.otherPara != "")
    {
        ui->timeOrder->setText(tp.otherPara);
        ui->timeHourLen->setText(tp.hourOther.valueLen);
        ui->timeHourOffset->setText(tp.hourOther.valuePos);
        ui->timeMinLen->setText(tp.minOther.valueLen);
        ui->timeMinOffset->setText(tp.minOther.valuePos);
        ui->timeSecLen->setText(tp.secOther.valueLen);
        ui->timeSecOffset->setText(tp.secOther.valuePos);
    }
    else
    {
        QString orderStr = functionStruct->getStr(functionStruct->getVarIndex(), 4, true);
        orderStr.append(functionStruct->getStr(tp.time.hour(), 2, false));
        orderStr.append(functionStruct->getStr(tp.time.minute(), 2, false));
        orderStr.append(functionStruct->getStr(tp.time.second(), 2, false));
        ui->timeOrder->setText(orderStr);
        ui->timeHourLen->setText("1");
        ui->timeHourOffset->setText("2");
        ui->timeMinLen->setText("1");
        ui->timeMinOffset->setText("3");
        ui->timeSecLen->setText("1");
        ui->timeSecOffset->setText("4");
    }

    if(tp.endian != "")
    {
        ui->timeEndian->setCurrentIndex(tp.endian.toInt()-1);
    }
    else
    {
        ui->timeEndian->setCurrentIndex(0);
    }
}

void ParameterWidget::SetDateTimePara()
{
    ui->returnedValLen->setText("7");
    ui->dataTypeBox->setCurrentText(DATATYPEUINT8);

    ui->datetimeEndian->clear();
    ui->datetimeEndian->addItem("大端");
    ui->datetimeEndian->addItem("小端");

    ui->datetimeOrder->setValidator(new QRegExpValidator(QRegExp("[a-fA-F0-9]{20}")));
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

    if(dtp.otherPara != "")
    {
        ui->datetimeOrder->setText(dtp.otherPara);
        ui->datetimeYearLen->setText(dtp.yearOther.valueLen);
        ui->datetimeYearOffset->setText(dtp.yearOther.valuePos);
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
    }
    else
    {
        QString orderStr = functionStruct->getStr(functionStruct->getVarIndex(), 4, true);
        orderStr.append(functionStruct->getStr(dtp.date.year(), 4, false));
        orderStr.append(functionStruct->getStr(dtp.date.month(), 2, false));
        orderStr.append(functionStruct->getStr(dtp.date.day(), 2, false));
        orderStr.append(functionStruct->getStr(dtp.time.hour(), 2, false));
        orderStr.append(functionStruct->getStr(dtp.time.minute(), 2, false));
        orderStr.append(functionStruct->getStr(dtp.time.second(), 2, false));

        ui->datetimeOrder->setText(orderStr);
        ui->datetimeYearLen->setText("2");
        ui->datetimeYearOffset->setText("2");
        ui->datetimeMonLen->setText("1");
        ui->datetimeMonOffset->setText("4");
        ui->datetimeDayLen->setText("1");
        ui->datetimeDayOffset->setText("5");
        ui->datetimeHourLen->setText("1");
        ui->datetimeHourOffset->setText("6");
        ui->datetimeMinLen->setText("1");
        ui->datetimeMinOffset->setText("7");
        ui->datetimeSecLen->setText("1");
        ui->datetimeSecOffset->setText("8");
    }
    if(dtp.endian != "")
    {
        ui->datetimeEndian->setCurrentIndex(dtp.endian.toInt()-1);
    }
    else
    {
        ui->datetimeEndian->setCurrentIndex(0);
    }
}

void ParameterWidget::slotVarTypeChanged(int index)
{
    if(functionStruct->getVarType() == VARALARM)
    {
        ui->stackedWidget->setCurrentIndex(VARALARM-1);
        curVarType = VARALARM;
    }
    else if(index < (VARALARM-1))
    {
        curVarType = index+1;
        ui->stackedWidget->setCurrentIndex(index);
    }
    else
    {
        curVarType = index+2;
        ui->stackedWidget->setCurrentIndex(index+1);
    }
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
        ui->returnedValLen->setText("1");
        ui->dataTypeBox->setCurrentText(DATATYPEUINT8);

        ui->triggerPara->setValidator(new QRegExpValidator(QRegExp("[0-9]{5}")));
        ui->operationOrder->setValidator(new QRegExpValidator(QRegExp("[a-fA-F0-9]{20}")));
        cmdParameters cp = functionStruct->getCmdParameters();
        ui->operationAction->clear();
        ui->operationAction->addItem(cp.dis1);
        ui->operationAction->addItem(cp.dis2);
        ui->operationAction->setCurrentText(cp.curValue);
        if(functionStruct->getVarType() == VARCMD)
        {
            ui->triggerPara->setEnabled(false);
            ui->triggerDis->setEnabled(false);
        }
    }
    else if(curVarType == VAROUT)
    {
        ui->returnedValLen->setText("0");
        ui->isDisplay->setEnabled(false);
        ui->isDisplay->setChecked(false);
        this->slotIsdisplayClicked(false);
        ui->dataTypeBox->setCurrentText(DATATYPEUINT8);
        ui->outParaNumber->setValue(functionStruct->getOutPara().itemList.size());
    }
    else if(curVarType == VARINPUT)
    {
        ui->returnedValLen->setText("1");
        ui->dataTypeBox->setCurrentText(DATATYPENULL);
        QDEBUG()<<"待续";
    }
    else
    {
        QDEBUG()<<"变量类型错误";
    }
}

void ParameterWidget::on_alarmUpMove_clicked()
{
    int currentRow = ui->AlarmtableWidget->currentRow();
    if(currentRow > 0)
    {
        QTableWidgetItem *alarmcode = ui->AlarmtableWidget->takeItem(currentRow,0);
        QTableWidgetItem *alarmname = ui->AlarmtableWidget->takeItem(currentRow,1);
        QTableWidgetItem *alarmclass = ui->AlarmtableWidget->takeItem(currentRow,2);
        QTableWidgetItem *prealarmcode = ui->AlarmtableWidget->takeItem(currentRow-1,0);
        QTableWidgetItem *prealarmname = ui->AlarmtableWidget->takeItem(currentRow-1,1);
        QTableWidgetItem *prealarmclass = ui->AlarmtableWidget->takeItem(currentRow-1,2);

        ui->AlarmtableWidget->setItem(currentRow,0,prealarmcode);
        ui->AlarmtableWidget->setItem(currentRow,1,prealarmname);
        ui->AlarmtableWidget->setItem(currentRow,2,prealarmclass);
        ui->AlarmtableWidget->setItem(currentRow-1,0,alarmcode);
        ui->AlarmtableWidget->setItem(currentRow-1,1,alarmname);
        ui->AlarmtableWidget->setItem(currentRow-1,2,alarmclass);

        this->ui->AlarmtableWidget->selectRow(currentRow-1);
        slotAlarmCellClicked(this->ui->AlarmtableWidget->currentRow(), 0);
    }
}

void ParameterWidget::on_alarmDowmMove_clicked()
{
    int rowCount = ui->AlarmtableWidget->rowCount();
    int currentRow = ui->AlarmtableWidget->currentRow();
    if(currentRow < rowCount -1 )
    {
        QTableWidgetItem *alarmcode = ui->AlarmtableWidget->takeItem(currentRow,0);
        QTableWidgetItem *alarmname = ui->AlarmtableWidget->takeItem(currentRow,1);
        QTableWidgetItem *alarmclass = ui->AlarmtableWidget->takeItem(currentRow,2);
        QTableWidgetItem *prealarmcode = ui->AlarmtableWidget->takeItem(currentRow+1,0);
        QTableWidgetItem *prealarmname = ui->AlarmtableWidget->takeItem(currentRow+1,1);
        QTableWidgetItem *prealarmclass = ui->AlarmtableWidget->takeItem(currentRow+1,2);

        ui->AlarmtableWidget->setItem(currentRow,0,prealarmcode);
        ui->AlarmtableWidget->setItem(currentRow,1,prealarmname);
        ui->AlarmtableWidget->setItem(currentRow,2,prealarmclass);
        ui->AlarmtableWidget->setItem(currentRow+1,0,alarmcode);
        ui->AlarmtableWidget->setItem(currentRow+1,1,alarmname);
        ui->AlarmtableWidget->setItem(currentRow+1,2,alarmclass);

        this->ui->AlarmtableWidget->selectRow(currentRow+1);
        slotAlarmCellClicked(this->ui->AlarmtableWidget->currentRow(), 0);
    }

}

void ParameterWidget::on_alarmDelete_clicked()
{
    int currentRow = ui->AlarmtableWidget->currentRow();
    if(currentRow >= 0)
    {
        ui->AlarmtableWidget->removeRow(currentRow);
        if(currentRow >= ui->AlarmtableWidget->rowCount())
        {
            ui->AlarmtableWidget->selectRow(currentRow-1);
        }
        else
        {
            ui->AlarmtableWidget->selectRow(currentRow);
        }
        slotAlarmCellClicked(this->ui->AlarmtableWidget->currentRow(), 0);
    }

    int len = ui->AlarmtableWidget->rowCount()/8;
    if(ui->AlarmtableWidget->rowCount()%8 != 0)
    {
        len++;
    }
    ui->returnedValLen->setText(QString::number(len));
    ui->dataTypeBox->setCurrentIndex(len+len-1);
}

void ParameterWidget::slotAlarmCellClicked(int row, int column)
{
    QDEBUG()<<"行:"<<row<<"列："<<column;
    qDebug()<<"总行数："<<this->ui->AlarmtableWidget->rowCount();

    if(row == 0)
    {
        this->ui->alarmUpMove->setEnabled(false);
        if(row == (this->ui->AlarmtableWidget->rowCount()-1))
        {
            this->ui->alarmDowmMove->setEnabled(false);
        }
        else
        {
            this->ui->alarmDowmMove->setEnabled(true);
        }
    }
    else if(row == (this->ui->AlarmtableWidget->rowCount()-1))
    {
        this->ui->alarmDowmMove->setEnabled(false);
        this->ui->alarmUpMove->setEnabled(true);
    }
    else
    {
        this->ui->alarmUpMove->setEnabled(true);
        this->ui->alarmDowmMove->setEnabled(true);
    }
}

void ParameterWidget::on_ButtonWarnSelect_clicked()
{
    Functionselect *functionMenu = new Functionselect();
    connect(functionMenu, SIGNAL(signalSelectedFunction(QList<int>)), this, SLOT(slotFunmenu(QList<int>)));
    functionMenu->exec();
}

void ParameterWidget::slotFunmenu(QList<int> list)
{
    QString str = "";
    QSqlQuery query;
    this->ui->AlarmlistWidget->clear();
    for(int i=0; i<list.size(); i++)
    {
        str = QString::number(list.at(i));
        str = "select * from general_command,parameter_default where(device_class=" + str +
                " and gcmd_type = 4"
                " and id<>999999"
                " and general_command.id = parameter_default.general_command_id)"
                " order by id";
        QDEBUG()<<str;
        if(query.exec(str))
        {
            while(query.next())
            {
                PRINTLOG(query.value("gcmd_name_ch").toString());
                QString jsonStr = query.value("parameter").toString();
                QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonStr.toUtf8());

                if(jsonDoc.isObject())
                {
                    QJsonObject jsonObj = jsonDoc.object().value("alarmItem").toArray().first().toObject();
                    ui->AlarmlistWidget->addItem(new AlarmListWidgetItem(jsonObj.value("alarmcode").toInt(),
                                                                         jsonObj.value("alarmstring").toString(),
                                                                         jsonObj.value("alarmclass").toInt()));
                }
            }
        }
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
    }
    else if(index == 1)
    {
        ui->triggerPara->setText(cmdPara.parameter2);
        ui->triggerDis->setText(cmdPara.dis2);
    }
    if(cmdPara.otherOrder != "")
    {
        this->ui->operationOrder->setText(cmdPara.otherOrder);
    }
    else
    {
        QString orderStr = functionStruct->getStr(functionStruct->getVarIndex(), 4, true);
        orderStr.append(functionStruct->getStr(ui->triggerPara->text().toInt(), 2, true));
        this->ui->operationOrder->setText(orderStr);
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
        delete outParaList.takeLast();
        delete outParaDscList.takeLast();
        delete outOrderList.takeLast();
        delete outDefaultList.takeLast();
    }

    for(int i=0; i<value; i++)
    {
        QLineEdit* outPara = new QLineEdit();
        QLineEdit* outParaDsc = new QLineEdit();
        QLineEdit* outOrder = new QLineEdit();
        QRadioButton* outDefault = new QRadioButton();

        outPara->setValidator(new QRegExpValidator(QRegExp("[0-9]{2}")));
        outOrder->setValidator(new QRegExpValidator(QRegExp("[a-fA-F0-9]{20}")));

        outParaList.append(outPara);
        outParaDscList.append(outParaDsc);
        outOrderList.append(outOrder);
        outDefaultList.append(outDefault);

        ui->outLayout->addWidget(outPara, i, 1, 1, 1);
        ui->outLayout->addWidget(outParaDsc, i, 2, 1, 1);
        ui->outLayout->addWidget(outOrder, i, 3, 1, 1);
        ui->outLayout->addWidget(outDefault, i, 4, 1, 1);
        ui->outLayout->setColumnStretch(1,2);
        ui->outLayout->setColumnStretch(2,2);
        ui->outLayout->setColumnStretch(3,6);

        if(i<outType.itemList.size())
        {
            outPara->setText(outType.itemList.at(i)->paraValue);
            outParaDsc->setText(outType.itemList.at(i)->paraDsc);
            outOrder->setText(outType.itemList.at(i)->paraOrder);
            outDefault->setChecked(outType.itemList.at(i)->isDefault);
        }

        if(functionStruct->getVarType() == VARCMD)
        {
            ui->dataTypeBox->setCurrentText(DATATYPEUINT8);
            if(i<2)
            {
                outPara->setEnabled(false);
                outParaDsc->setEnabled(false);
                cmdParameters cp = functionStruct->getCmdParameters();
                if(0 == i)
                {
                    if(outPara->text() == "")
                    {
                        outPara->setText(cp.parameter1);
                    }
                    if(outParaDsc->text() == "")
                    {
                        outParaDsc->setText(cp.dis1);
                    }
                }
                else if(1 == i)
                {
                    if(outPara->text() == "")
                    {
                        outPara->setText(cp.parameter2);
                    }
                    if(outParaDsc->text() == "")
                    {
                        outParaDsc->setText(cp.dis2);
                    }
                }

                outPara->setEnabled(false);
                outParaDsc->setEnabled(false);
                if(outOrder->text() == "")
                {
                    QString orderStr = functionStruct->getStr(functionStruct->getVarIndex(), 4, true);
                    orderStr.append(functionStruct->getStr(outPara->text().toInt(), 2, true));
                    outOrder->setText(orderStr);
                }
            }
        }
        else if(functionStruct->getVarType() == VARENUMBERATE)
        {
            ui->dataTypeBox->setCurrentText(DATATYPEUINT8);

            enumParameters ep = functionStruct->getenumParameters();
            QDEBUG()<<"enumParaList.size"<<ep.enumParaList.size();
            if(i<ep.enumParaList.size())
            {
                outPara->setEnabled(false);
                outParaDsc->setEnabled(false);
                if(outPara->text() == "")
                {
                    outPara->setText(ep.enumParaList.at(i)->value);
                }
                if(outParaDsc->text() == "")
                {
                    outParaDsc->setText(ep.enumParaList.at(i)->display);
                }
                if(outOrder->text() == "")
                {
                    QString orderStr = functionStruct->getStr(functionStruct->getVarIndex(), 4, true);
                    orderStr.append(functionStruct->getStr(outPara->text().toInt(), 2, true));
                    outOrder->setText(orderStr);
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
        delete disEnumParaList.takeLast();
        delete disEnumStrList.takeLast();
        delete disEnumPicList.takeLast();
    }
    for(int i=0; i<value; i++)
    {
        QLineEdit* value = new QLineEdit();
        QLineEdit* str = new QLineEdit();
        QLineEdit* pic = new QLineEdit();

        disEnumParaList.append(value);
        disEnumStrList.append(str);
        disEnumPicList.append(pic);

        ui->gridLayout_14->addWidget(value, i, 0, 1, 1);
        ui->gridLayout_14->addWidget(str, i, 1, 1, 1);
        ui->gridLayout_14->addWidget(pic, i, 2, 1, 1);

        value->setValidator(new QRegExpValidator(QRegExp("[0-9]{5}")));
        pic->setValidator(new QRegExpValidator(QRegExp("[0-9]{5}")));
        if(i< disEnum.disEnumList.size())
        {
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
                value->setText(ep.enumParaList.at(i)->value);
                if(str->text() == "")
                {
                    str->setText(ep.enumParaList.at(i)->display);
                }
            }
        }
        else if(functionStruct->getVarType() == VARCMD)
        {
            value->setEnabled(false);
            cmdParameters cp = functionStruct->getCmdParameters();
            if(i == 0)
            {
                value->setText(cp.parameter1);
                if(str->text() == "")
                {
                    str->setText(cp.dis1);
                }
            }
            else if(i == 1)
            {
                value->setText(cp.parameter2);
                if(str->text() == "")
                {
                    str->setText(cp.dis2);
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
            ui->disNumberDefault->setEnabled(false);
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
            ui->disScrollDefaul->setEnabled(false);
            ui->disScrollMax->setEnabled(false);
            ui->disScrollMin->setEnabled(false);
            numberParamters np = functionStruct->getNumberParameters();
            ui->disScrollDefaul->setText(np.defaultValue);
            ui->disScrollMax->setText(np.max);
            ui->disScrollMin->setText(np.min);
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
