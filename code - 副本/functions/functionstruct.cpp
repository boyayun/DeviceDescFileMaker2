#include "functionstruct.h"

FunctionStruct::FunctionStruct()
{
}

int FunctionStruct::getVarIndex() const
{
    return varIndex;
}

void FunctionStruct::setVarIndex(int value)
{
    varIndex = value;
}

QString FunctionStruct::getFunctionName() const
{
    return functionName;
}

void FunctionStruct::setFunctionName(const QString &value)
{
    functionName = value;
}

void FunctionStruct::setUserLeverLimit(const QString value)
{
    UserLevelLimit = value;
}

QString FunctionStruct::getUserLeverLimit() const
{
    return UserLevelLimit;
}

int FunctionStruct::getDirection() const
{
    return direction;
}

void FunctionStruct::setDirection(int value)
{
    direction = value;
}

int FunctionStruct::getVarType() const
{
    return varType;
}

void FunctionStruct::setVarType(int value)
{
    varType = value;
}

int FunctionStruct::getNewVarType() const
{
    return newVarType;
}

void FunctionStruct::setNewVarType(const int value)
{
    newVarType = value;
}

QString FunctionStruct::getDeviceType() const
{
    return deviceType;
}

void FunctionStruct::setDeviceType(const QString &value)
{
    deviceType = value;
}

QString FunctionStruct::getOrderType() const
{
    return orderType;
}

void FunctionStruct::setOrderType(const QString &value)
{
    orderType = value;
}

QString FunctionStruct::getParaNew() const
{
    return paraNew;
}

void FunctionStruct::setParaNew(const QString &value)
{
    paraNew = value;
}

QString FunctionStruct::getParameters() const
{
    return parameters;
}

void FunctionStruct::setParameters(const QString &value)
{
    parameters = value;
}

int FunctionStruct::getReturnType() const
{
    return returnType;
}

void FunctionStruct::setReturType(const int &value)
{
    returnType = value;
}

QString FunctionStruct::getDataPos() const
{
    return dataPos;
}

void FunctionStruct::setDataPos(QString value)
{
    dataPos = value;
}

QString FunctionStruct::getDataLength() const
{
    return dataLength;
}

void FunctionStruct::setDataLength(const QString &value)
{
    dataLength = value;
}

QString FunctionStruct::getLength() const
{
    return length;
}

void FunctionStruct::setLength(const QString value)
{
    length = value;
}
QString FunctionStruct::getDataType() const
{
    return dataType;
}

void FunctionStruct::setDataType(const QString &value)
{
    dataType = value;
}

void FunctionStruct::setParameter(const cmdParameters &c)
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(parameters.toUtf8());
    QJsonObject jsonObj = jsonDoc.object();

    jsonObj.insert("on",c.parameter1.toInt());
    jsonObj.insert("off",c.parameter2.toInt());
    jsonObj.insert("defaultValue",c.defaultValue.toInt());
    jsonObj.insert("disoff",c.dis2);
    jsonObj.insert("dison",c.dis1);
    jsonObj.insert("para1_other", c.para1_other);
    jsonObj.insert("para2_other", c.para2_other);
    jsonObj.insert("status1", c.statusValue1);
    jsonObj.insert("status2", c.statusValue2);
//    jsonObj.insert("curValue", c.curValue);
//    jsonObj.insert("dis", c.dis);
//    jsonObj.insert("status", c.statusValue);
//    jsonObj.insert("otherOrder",c.otherOrder);
    QJsonDocument d(jsonObj);
    QString str(d.toJson(QJsonDocument::Compact));
    setParaNew(str);
    QDEBUG()<<str;
}

void FunctionStruct::setParameter(const numberParamters &n)
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(parameters.toUtf8());
    QJsonObject jsonObj = jsonDoc.object();

    jsonObj.insert("Max",n.max.toDouble());
    jsonObj.insert("Min",n.min.toDouble());
    jsonObj.insert("DefaultValue",n.defaultValue.toDouble());
    jsonObj.insert("k", n.kFactor);
    jsonObj.insert("c", n.cFactor);
    jsonObj.insert("disScaling",n.scalling.toDouble());
    jsonObj.insert("unit",n.uint.toInt());
    jsonObj.insert("otherPara", n.otherPara);
    jsonObj.insert("valueEndian", n.endian);
    jsonObj.insert("valueLen", n.other.valueLen);
    jsonObj.insert("valuePos", n.other.valuePos);

    QJsonDocument d(jsonObj);
    QString strnew(d.toJson(QJsonDocument::Compact));
    setParaNew(strnew);
    QDEBUG()<<"NUMBER"<<strnew;
}

void FunctionStruct::setParameter(const enumParameters &e)
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(parameters.toUtf8());
    QJsonObject jsonObj = jsonDoc.object();

    jsonObj.insert("DefaultValues",e.defaultValue.toInt());
    QJsonArray valueArray, otherArray, disArray, selectArray, statusArray;

    for(int i=0; i<e.enumParaList.size(); i++)
    {
        valueArray.append(e.enumParaList.at(i)->value.toInt());
        otherArray.append(e.enumParaList.at(i)->otherPara);
        disArray.append(e.enumParaList.at(i)->display);
        selectArray.append(e.enumParaList.at(i)->isSlect);
        statusArray.append(e.enumParaList.at(i)->statusValue);
    }

    jsonObj.insert("ParameterItems",disArray);
    jsonObj.insert("OtherPara", otherArray);
    jsonObj.insert("ParameterValues",valueArray);
    jsonObj.insert("isSelect", selectArray);
    jsonObj.insert("status", statusArray);

    QJsonDocument d(jsonObj);
    QString str(d.toJson(QJsonDocument::Compact));
    setParaNew(str);
    QDEBUG()<<"enum"<<str;
}

void FunctionStruct::setParameter(const alarmParameters &a)
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(parameters.toUtf8());
    QJsonObject jsonObj = jsonDoc.object();
    jsonObj.insert("alarmclass", a.alarmClass.toInt());
    jsonObj.insert("alarmstring", a.alarmText);
    QJsonDocument d(jsonObj);
    QString str(d.toJson(QJsonDocument::Compact));
    setParaNew(str);
    QDEBUG()<<str;
}

void FunctionStruct::setParameter(const dateTimeParameters &dt)
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(parameters.toUtf8());
    QJsonObject jsonObj = jsonDoc.object();

    jsonObj.insert("maxDate",dt.maxDate.toString("yyyy-MM-dd"));
    jsonObj.insert("minDate",dt.minDate.toString("yyyy-MM-dd"));
    jsonObj.insert("date",dt.date.toString("yyyy-MM-dd"));
    jsonObj.insert("yearStep",dt.yearStep.toInt());
    jsonObj.insert("yearC", dt.yearC);
    jsonObj.insert("monthStep",dt.monthStep.toInt());
    jsonObj.insert("dayStep",dt.dayStep.toInt());
    jsonObj.insert("disYear",dt.yearDis);
    jsonObj.insert("disMonth",dt.monthDis);
    jsonObj.insert("disDay",dt.dayDis);
    jsonObj.insert("minTime",dt.minTime.toString("h:m:s"));
    jsonObj.insert("maxTime",dt.maxTime.toString("h:m:s"));
    jsonObj.insert("time",dt.time.toString("h:m:s"));
    jsonObj.insert("hourStep",dt.hourStep.toInt());
    jsonObj.insert("minuteStep",dt.minuteStep.toInt());
    jsonObj.insert("secondStep",dt.secondStep.toInt());
    jsonObj.insert("disHour",dt.hourDis);
    jsonObj.insert("disMinute",dt.minuteDis);
    jsonObj.insert("disSecond",dt.secondDis);

    jsonObj.insert("otherPara", dt.otherPara);
    jsonObj.insert("yearvalueLen", dt.yearOther.valueLen);
    jsonObj.insert("yearvaluePos", dt.yearOther.valuePos);
    jsonObj.insert("monvalueLen", dt.monthOther.valueLen);
    jsonObj.insert("monvaluePos", dt.monthOther.valuePos);
    jsonObj.insert("dayvalueLen", dt.dayOther.valueLen);
    jsonObj.insert("dayvaluePos", dt.dayOther.valuePos);
    jsonObj.insert("hourvalueLen", dt.hourOther.valueLen);
    jsonObj.insert("hourvaluePos", dt.hourOther.valuePos);
    jsonObj.insert("minvalueLen", dt.minOther.valueLen);
    jsonObj.insert("minvaluePos", dt.minOther.valuePos);
    jsonObj.insert("secvalueLen", dt.secOther.valueLen);
    jsonObj.insert("secvaluePos", dt.secOther.valuePos);
    jsonObj.insert("endian", dt.endian);

    QJsonDocument doc(jsonObj);
    QString str(doc.toJson(QJsonDocument::Compact));
    setParaNew(str);
    QDEBUG()<<"datetime"<<str;
}

void FunctionStruct::setParameter(const _varOutType &t)
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(parameters.toUtf8());
    QJsonObject jsonObj = jsonDoc.object();
    QJsonArray paraValue, paraDsc, paraOrder, isDefault, status;

    for(int i=0; i<t.itemList.size(); i++)
    {
        paraValue.append(t.itemList.at(i)->paraValue);
        paraDsc.append(t.itemList.at(i)->paraDsc);
        paraOrder.append(t.itemList.at(i)->paraOrder);
        isDefault.append(t.itemList.at(i)->isDefault);
        status.append(t.itemList.at(i)->statusValue);
    }
    jsonObj.insert("paraValue", paraValue);
    jsonObj.insert("paraDsc", paraDsc);
    jsonObj.insert("paraOrder", paraOrder);
    jsonObj.insert("isDefault", isDefault);
    jsonObj.insert("status", status);

    QJsonDocument doc(jsonObj);
    QString str(doc.toJson(QJsonDocument::Compact));
    setParaNew(str);
    QDEBUG()<<"out"<<str;
}

cmdParameters FunctionStruct::getCmdParameters()
{
    QString jsonStr = paraNew;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonStr.toUtf8());
    cmdParameters cmdparameter;
    if(jsonDoc.isObject())
    {
        QJsonObject jsonObj = jsonDoc.object();
        cmdparameter.defaultValue = QString::number(jsonObj.value("defaultValue").toInt());
        cmdparameter.dis1 = jsonObj.value("dison").toString();
        cmdparameter.dis2 = jsonObj.value("disoff").toString();
        cmdparameter.parameter1 = QString::number(jsonObj.value("on").toInt());
        cmdparameter.parameter2 = QString::number(jsonObj.value("off").toInt());
        cmdparameter.para1_other = jsonObj.value("para1_other").toString();
        cmdparameter.para2_other = jsonObj.value("para2_other").toString();
        cmdparameter.statusValue1 = jsonObj.value("status1").toString();
        cmdparameter.statusValue2 = jsonObj.value("status2").toString();
//        cmdparameter.curValue = jsonObj.value("curValue").toString();
//        cmdparameter.dis = jsonObj.value("dis").toString();
//        cmdparameter.statusValue = jsonObj.value("status").toString();
//        cmdparameter.otherOrder = jsonObj.value("otherOrder").toString();
    }
    else
    {
        QDEBUG()<<"ERROR!";
    }
    return cmdparameter;
}

numberParamters FunctionStruct::getNumberParameters()
{
    QString jsonStr = paraNew;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonStr.toUtf8());
    numberParamters np;
    if(jsonDoc.isObject())
    {
        QJsonObject jsonObj = jsonDoc.object();
        np.max = QString::number(jsonObj.value("Max").toDouble());
        np.min = QString::number(jsonObj.value("Min").toDouble());
        np.defaultValue = QString::number(jsonObj.value("DefaultValue").toDouble());
        np.kFactor = jsonObj.value("k").toString();
        np.cFactor = jsonObj.value("c").toString();
        np.scalling = QString::number(jsonObj.value("disScaling").toDouble());
        np.uint = QString::number(jsonObj.value("unit").toInt());

        np.otherPara = jsonObj.value("otherPara").toString();
        np.endian = jsonObj.value("valueEndian").toString();
        np.other.valueLen = jsonObj.value("valueLen").toString();
        np.other.valuePos = jsonObj.value("valuePos").toString();
    }
    else
    {
        PRINTLOG("ERROR!");
    }
    return np;
}

enumParameters FunctionStruct::getenumParameters()
{
    QString jsonStr = paraNew;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonStr.toUtf8());
    enumParameters ep;
    if(jsonDoc.isObject())
    {
        QJsonObject jsonObj = jsonDoc.object();
        ep.defaultValue  = QString::number(jsonObj.value("DefaultValues").toInt());
        QJsonArray valueArray = jsonObj.value("ParameterValues").toArray();
        QJsonArray itemArray = jsonObj.value("ParameterItems").toArray();
        QJsonArray otherArray = jsonObj.value("OtherPara").toArray();
        QJsonArray isSelectArray = jsonObj.value("isSelect").toArray();
        QJsonArray statusArray = jsonObj.value("status").toArray();
        for(int i=0; i<valueArray.size(); i++)
        {
            _enumPara *enumPara = new _enumPara;
            enumPara->value = QString::number(valueArray.at(i).toInt());
            enumPara->display = itemArray.at(i).toString();
            enumPara->otherPara = otherArray.at(i).toString();
            enumPara->isSlect = isSelectArray.at(i).toBool();
            enumPara->statusValue = statusArray.at(i).toString();
            ep.enumParaList.append(enumPara);
        }
    }
    else
    {
        PRINTLOG("ERROR!");
    }
    return ep;
}

alarmParameters FunctionStruct::getAlarmParameters()
{
    QString jsonStr = paraNew;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonStr.toUtf8());
    alarmParameters ap;
    if(jsonDoc.isObject())
    {
        QJsonObject jsonObj = jsonDoc.object();
        ap.alarmClass = QString::number(jsonObj.value("alarmclass").toInt());
        ap.alarmText = jsonObj.value("alarmstring").toString();
    }
    else
    {
        PRINTLOG("ERROR!");
    }
    return ap;
}

dateTimeParameters FunctionStruct::getDateTimeParameters()
{
    dateTimeParameters dtp;
    QString jsonStr = paraNew;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonStr.toUtf8());

    if(jsonDoc.isObject())
    {
        QJsonObject jsonObj = jsonDoc.object();
        dtp.maxDate = QDate::fromString(jsonObj.value("maxDate").toString(),"yyyy-MM-dd");
        dtp.minDate = QDate::fromString(jsonObj.value("minDate").toString(),"yyyy-MM-dd");
        dtp.date = QDate::fromString(jsonObj.value("date").toString(),"yyyy-MM-dd");
        dtp.yearStep = QString::number(jsonObj.value("yearStep").toInt());
        dtp.yearC = jsonObj.value("yearC").toString();
        dtp.monthStep = QString::number(jsonObj.value("monthStep").toInt());
        dtp.dayStep = QString::number(jsonObj.value("dayStep").toInt());
        dtp.yearDis = jsonObj.value("disYear").toString();
        dtp.monthDis = jsonObj.value("disMonth").toString();
        dtp.dayDis = jsonObj.value("disDay").toString();
        dtp.maxTime = QTime::fromString(jsonObj.value("maxTime").toString(),"h:m:s");
        dtp.minTime = QTime::fromString(jsonObj.value("minTime").toString(),"h:m:s");
        dtp.time = QTime::fromString(jsonObj.value("time").toString(),"h:m:s");
        dtp.hourStep = QString::number(jsonObj.value("hourStep").toInt());
        dtp.minuteStep= QString::number(jsonObj.value("minuteStep").toInt());
        dtp.secondStep = QString::number(jsonObj.value("secondStep").toInt());
        dtp.hourDis = jsonObj.value("disHour").toString();
        dtp.minuteDis=jsonObj.value("disMinute").toString();
        dtp.secondDis =jsonObj.value("disSecond").toString();

        dtp.yearOther.valueLen = jsonObj.value("yearvalueLen").toString();
        dtp.yearOther.valuePos = jsonObj.value("yearvaluePos").toString();
        dtp.monthOther.valueLen = jsonObj.value("monvalueLen").toString();
        dtp.monthOther.valuePos = jsonObj.value("monvaluePos").toString();
        dtp.dayOther.valueLen = jsonObj.value("dayvalueLen").toString();
        dtp.dayOther.valuePos = jsonObj.value("dayvaluePos").toString();
        dtp.hourOther.valueLen = jsonObj.value("hourvalueLen").toString();
        dtp.hourOther.valuePos = jsonObj.value("hourvaluePos").toString();
        dtp.minOther.valueLen = jsonObj.value("minvalueLen").toString();
        dtp.minOther.valuePos = jsonObj.value("minvaluePos").toString();
        dtp.secOther.valueLen = jsonObj.value("secvalueLen").toString();
        dtp.secOther.valuePos = jsonObj.value("secvaluePos").toString();
        dtp.endian = jsonObj.value("endian").toString();
        dtp.otherPara = jsonObj.value("otherPara").toString();
    }
    else
    {
        PRINTLOG("ERROR!");
    }
    return dtp;
}

_varOutType FunctionStruct::getOutPara()
{
    _varOutType outType;
    QString jsonStr = paraNew;

    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonStr.toUtf8());
    if(jsonDoc.isObject())
    {
        QJsonObject itemObj = jsonDoc.object();
        QJsonArray paraValue = itemObj.value("paraValue").toArray();
        QJsonArray paraDsc = itemObj.value("paraDsc").toArray();
        QJsonArray paraOrder = itemObj.value("paraOrder").toArray();
        QJsonArray isDefault = itemObj.value("isDefault").toArray();
        QJsonArray status = itemObj.value("status").toArray();
        for(int i=0; i<paraValue.size(); i++)
        {
            _varOutItem *varout = new _varOutItem;
            varout->paraValue = paraValue.at(i).toString();
            varout->paraDsc = paraDsc.at(i).toString();
            varout->paraOrder = paraOrder.at(i).toString();
            varout->isDefault = isDefault.at(i).toBool();
            varout->statusValue = status.at(i).toString();
            outType.itemList.append(varout);
        }
    }
    else
    {
        QDEBUG()<<"error";
    }
    return outType;
}

int FunctionStruct::getDisType() const
{
    return disType;
}

void FunctionStruct::setDisType(int value)
{
    disType = value;
}

bool FunctionStruct::getDisplay() const
{
    return isDisplay;
}

void FunctionStruct::setDisplay(const bool value)
{
    isDisplay = value;
}

QString FunctionStruct::getDisName() const
{
    return disName;
}

void FunctionStruct::setDisName(const QString &value)
{
    disName = value;
}

QString FunctionStruct::getIconIndex() const
{
    return iconIndex;
}

void FunctionStruct::setIconIndex(const QString &value)
{
    iconIndex = value;
}

QString FunctionStruct::getDisUnit() const
{
    return disUnit;
}

void FunctionStruct::setDisUnit(const QString &value)
{
    disUnit = value;
}

QString FunctionStruct::getDisPara() const
{
    return disPara;
}

void FunctionStruct::setDisPara(const QString &value)
{
    disPara = value;
}

QString FunctionStruct::getDisString() const
{
    QString string;
    QString jsonStr = getDisPara();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonStr.toUtf8());
    if(jsonDoc.isObject())
    {
        QJsonObject jsonObj = jsonDoc.object();
        string = jsonObj.value("string").toString();
    }
    else
    {
        QDEBUG()<<"error";
    }
    return string;
}

void FunctionStruct::setDisString(const QString &value)
{
    QJsonObject jsonObj;
    jsonObj.insert("string", value);
    QJsonDocument jsonDoc;
    jsonDoc.setObject(jsonObj);
    QString str(jsonDoc.toJson());
    setDisPara(str);
}

QString FunctionStruct::getDisPic() const
{
    QString pic;
    QString jsonStr = getDisPara();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonStr.toUtf8());
    if(jsonDoc.isObject())
    {
        QJsonObject jsonObj = jsonDoc.object();
        pic = jsonObj.value("pic").toString();
    }
    else
    {
        QDEBUG()<<"error";
    }
    return pic;
}

void FunctionStruct::setDisPic(const QString &value)
{
    QJsonObject jsonObj;
    jsonObj.insert("pic", value);
    QJsonDocument jsonDoc;
    jsonDoc.setObject(jsonObj);
    QString str(jsonDoc.toJson());
    setDisPara(str);
}

_disCmd FunctionStruct::getDisCmd() const
{
    _disCmd discmd;
    QString jsonStr = getDisPara();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonStr.toUtf8());
    if(jsonDoc.isObject())
    {
        QJsonObject jsonObj = jsonDoc.object();
        discmd.value1 = jsonObj.value("value1").toString();
        discmd.string1 = jsonObj.value("string1").toString();
        discmd.pic1 = jsonObj.value("pic1").toString();
        discmd.value2 = jsonObj.value("value2").toString();
        discmd.string2 = jsonObj.value("string2").toString();
        discmd.pic2 = jsonObj.value("pic2").toString();
    }
    else
    {
        QDEBUG()<<"error";
    }
    return discmd;
}

void FunctionStruct::setDisCmd(const _disCmd &value)
{
    QJsonObject jsonObj;
    jsonObj.insert("value1", value.value1);
    jsonObj.insert("string1", value.string1);
    jsonObj.insert("pic1", value.pic1);
    jsonObj.insert("value2", value.value2);
    jsonObj.insert("string2", value.string2);
    jsonObj.insert("pic2", value.pic2);
    QJsonDocument jsonDoc;
    jsonDoc.setObject(jsonObj);
    QString str(jsonDoc.toJson());
    setDisPara(str);
}

_disEnum FunctionStruct::getDisEnum() const
{
    _disEnum disEnum;
    QString jsonStr = getDisPara();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonStr.toUtf8());
    if(jsonDoc.isObject())
    {
        QJsonObject jsonObj = jsonDoc.object();
        QJsonArray selectArray = jsonObj.value("select").toArray();
        QJsonArray valueArray = jsonObj.value("value").toArray();
        QJsonArray strArray = jsonObj.value("str").toArray();
        QJsonArray picArray = jsonObj.value("pic").toArray();
        for(int i=0; i<strArray.size(); i++)
        {
            _disEnumPara *enumpara = new _disEnumPara;
            enumpara->select = selectArray.at(i).toBool();
            enumpara->value = valueArray.at(i).toString();
            enumpara->string = strArray.at(i).toString();
            enumpara->pic = picArray.at(i).toString();
            disEnum.disEnumList.append(enumpara);
        }
    }
    else
    {
        QDEBUG()<<"error";
    }
    return disEnum;
}

void FunctionStruct::setDisEnum(const _disEnum &value)
{
    QJsonObject jsonObj;
    QJsonArray selectArray, valueArray,strArray, picArray;
    for(int i=0; i<value.disEnumList.size(); i++)
    {
        selectArray.append(value.disEnumList.at(i)->select);
        valueArray.append(value.disEnumList.at(i)->value);
        strArray.append(value.disEnumList.at(i)->string);
        picArray.append(value.disEnumList.at(i)->pic);
    }
    jsonObj.insert("select", selectArray);
    jsonObj.insert("value", valueArray);
    jsonObj.insert("str", strArray);
    jsonObj.insert("pic", picArray);
    QJsonDocument jsonDoc;
    jsonDoc.setObject(jsonObj);
    QString str(jsonDoc.toJson());
    QDEBUG()<<"dispara"<<str;
    setDisPara(str);
}
_disDateTime FunctionStruct::getDisDateTime() const
{
    _disDateTime disDataTime;
    QString jsonStr = getDisPara();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonStr.toUtf8());
    if(jsonDoc.isObject())
    {
        QJsonObject jsonObj = jsonDoc.object();
        disDataTime.disYear = jsonObj.value("year").toString();
        disDataTime.disMonth = jsonObj.value("month").toString();
        disDataTime.disDay = jsonObj.value("day").toString();
        disDataTime.disHour = jsonObj.value("hour").toString();
        disDataTime.disMin = jsonObj.value("min").toString();
        disDataTime.disSec = jsonObj.value("sec").toString();
    }
    else
    {
        QDEBUG()<<"error";
    }
    return disDataTime;
}

void FunctionStruct::setDisDateTime(const _disDateTime &value)
{
    QJsonObject jsonObj;
    jsonObj.insert("year", value.disYear);
    jsonObj.insert("month", value.disMonth);
    jsonObj.insert("day", value.disDay);
    jsonObj.insert("hour", value.disHour);
    jsonObj.insert("min", value.disMin);
    jsonObj.insert("sec", value.disSec);
    QJsonDocument jsonDoc;
    jsonDoc.setObject(jsonObj);
    QString str(jsonDoc.toJson());
    setDisPara(str);
}

_disNumber FunctionStruct::getDisNumber() const
{
    _disNumber disNumber;
    QString jsonStr = getDisPara();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonStr.toUtf8());
    if(jsonDoc.isObject())
    {
        QJsonObject jsonObj = jsonDoc.object();
        disNumber.disPara = jsonObj.value("para").toString();
        disNumber.disScaling = jsonObj.value("scaling").toString();
    }
    else
    {
        QDEBUG()<<"error";
    }
    return disNumber;
}

void FunctionStruct::setDisNumber(const _disNumber &value)
{
    QJsonObject jsonObj;
    jsonObj.insert("para", value.disPara);
    jsonObj.insert("scaling", value.disScaling);
    QJsonDocument jsonDoc;
    jsonDoc.setObject(jsonObj);
    QString str(jsonDoc.toJson());
    setDisPara(str);
}

_disScroll FunctionStruct::getDisScroll() const
{
    _disScroll disScroll;
    QString jsonStr = getDisPara();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonStr.toUtf8());
    if(jsonDoc.isObject())
    {
        QJsonObject jsonObj = jsonDoc.object();
        disScroll.disMax = jsonObj.value("max").toString();
        disScroll.disMin = jsonObj.value("min").toString();
        disScroll.disStep = jsonObj.value("step").toString();
        disScroll.disDefault = jsonObj.value("para").toString();
    }
    else
    {
        QDEBUG()<<"error";
    }
    return disScroll;
}

void FunctionStruct::setDisScroll(const _disScroll &value)
{
    QJsonObject jsonObj;
    jsonObj.insert("max", value.disMax);
    jsonObj.insert("min", value.disMin);
    jsonObj.insert("step", value.disStep);
    jsonObj.insert("para", value.disDefault);
    QJsonDocument jsonDoc;
    jsonDoc.setObject(jsonObj);
    QString str(jsonDoc.toJson());
    setDisPara(str);
}
