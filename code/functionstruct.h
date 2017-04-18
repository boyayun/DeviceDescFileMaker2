#ifndef FUNCTIONSTRUCT_H
#define FUNCTIONSTRUCT_H

#include <QObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include "config.h"
#include <QLabel>
#include <QList>
#include <QMap>
#include <QTime>
#include <QDate>
#include <QDateTime>

#define VARCMD 1
#define VARNUMBER 2
#define VARENUMBERATE 3
#define VARALARM 4
#define VARDATE 5
#define VARTIME 6
#define VARDATETIME 7
#define VARSINGLE 8
#define VAROUT  9
#define VARINPUT  10

#define DISSTRING 1
#define DISPICTURE 2
#define DISDATE 3
#define DISTIME 4
#define DISNUMBER 5
#define DISCMD 6
#define DISENUMBERATE 7
#define DISSCROL 8
#define DISDATETIME 9

#define DATATYPENULL "未知类型"
#define DATATYPEUINT8 "无符号字符型"
#define DATATYPEINT8 "有符号字符型"
#define DATATYPEUINT16 "无符号SHORT型"
#define DATATYPEINT16 "有符号SHORT型"
#define DATATYPEUINT32 "无符号LONG型"
#define DATATYPEINT32 "有符号LONG型"

#define PARATYPEDEC "1"
#define PARATYPEHEX "2"

#define VALUEBIGEND "1"
#define VALUELITTLEEND "2"

#define DIRWR 1
#define DIRRD 2
#define DIRWD 3

class warningStruct
{
public:
    warningStruct();
    int getVarindex() const;
    void setVarindex(const int);

    QString getWarnName() const;
    void setWarnName(const QString &);

    int getWarnClass() const;
    void setWarnClass(const int);

private:
    int varIndex;
    QString warnName;
    int warnClass;
};

typedef struct
{
    QString valuePos;
    QString valueLen;
}_otherPara;

typedef struct _cmdParameters
{
    QString parameter1;
    QString para1_other;
    QString statusValue1;
    QString parameter2;
    QString para2_other;
    QString statusValue2;
    QString defaultValue;
    QString dis1;
    QString dis2;
    QString curValue;
    QString statusValue;
    QString otherOrder;
}cmdParameters;

typedef struct _numberParameters
{
    QString max;
    QString min;
    QString scalling;
    QString uint;
    QString defaultValue;
    QString kFactor;
    QString cFactor;
    QString endian;
    QString otherPara;
    _otherPara other;
}numberParamters;

typedef struct
{
    bool isSlect = false;
    QString value;
    QString otherPara;
    QString statusValue;
    QString display;
}_enumPara;

typedef struct _enumParameters
{
    QString defaultValue;
    QList<_enumPara*> enumParaList;
}enumParameters;

typedef struct _alarmParameters
{
    QList<warningStruct*>warningList;
}alarmParameters;

typedef struct _dateTimeParameters
{
    QDate maxDate;
    QDate minDate;
    QDate date;
    QString yearDis;
    QString monthDis;
    QString dayDis;
    QString yearStep;
    QString yearC;
    QString monthStep;
    QString dayStep;
    QTime maxTime;
    QTime minTime;
    QTime time;
    QString hourStep;
    QString minuteStep;
    QString secondStep;
    QString hourDis;
    QString minuteDis;
    QString secondDis;

    QString endian;
    QString otherPara;
    _otherPara yearOther;
    _otherPara monthOther;
    _otherPara dayOther;
    _otherPara hourOther;
    _otherPara minOther;
    _otherPara secOther;
}dateTimeParameters;

typedef struct
{
    QString paraValue;
    QString paraDsc;
    QString paraOrder;
    QString statusValue;
    bool    isDefault;
}_varOutItem;

typedef struct
{
    QList<_varOutItem*>itemList;
}_varOutType;

typedef struct
{
    QString DisplayString;
}_disString;

typedef struct
{
    QString DisplayPictrueIndex;
}_disPictrue;

typedef struct
{
    QString disPara;
    QString disScaling;
}_disNumber;

typedef struct
{
    QString value;
    QString string;
    QString pic;
}_disEnumPara;

typedef struct
{
    QString value1;
    QString string1;
    QString pic1;
    QString value2;
    QString string2;
    QString pic2;
}_disCmd;

typedef struct
{
    QList<_disEnumPara*>disEnumList;
}_disEnum;

typedef struct
{
    QString disMax;
    QString disMin;
    QString disStep;
    QString disDefault;
}_disScroll;

typedef struct
{
    QString disYear;
    QString disMonth;
    QString disDay;
    QString disHour;
    QString disMin;
    QString disSec;
}_disDateTime;

class FunctionStruct
{
public:
    FunctionStruct();

    /*value：要转的值， len: 转后的长度， b：0转成10进制，1转成16进制*/
    QString getStr(int value, int len, bool b)
    {
        QString str;
        if(b)
        {
            str = QString::number(value, 16).toUpper();
        }
        else
        {
            str = QString::number(value, 10).toUpper();
        }
        int tmplen = str.length();
        if(len > tmplen)
        {
            for(int i=0; i<(len - tmplen); i++)
            {
                str.insert(0, "0");
            }
        }
        qDebug()<<__FILE__<<__LINE__<<"str"<<str;
        return  str;
    }

    int getVarIndex() const;
    void setVarIndex(int value);

    QString getFunctionName() const;
    void setFunctionName(const QString &value);

    QString getUserLeverLimit() const;
    void setUserLeverLimit(const QString value);

    int getDirection() const;
    void setDirection(int value);

    int getNewVarType() const;
    void setNewVarType(const int value, bool b);

    QString getParaNew() const;
    void setParaNew(const QString &value);

    QString getDeviceType() const;
    void setDeviceType(const QString &value);

    QString  getOrderType() const;
    void setOrderType(const QString &value);

    int getVarType() const;
    void setVarType(int value);

    int getDisType() const;
    void setDisType(int value);

    bool getDisplay() const;
    void setDisplay(const bool value);

    QString getParameters() const;
    void setParameters(const QString &value);

    void setParameter(const cmdParameters &c);
    void setParameter(const numberParamters &n);
    void setParameter(const enumParameters &e);
    void setParameter(const alarmParameters &a);
    void setParameter(const dateTimeParameters &dt);
    void setParameter(const _varOutType &t);

    cmdParameters getCmdParameters();
    numberParamters getNumberParameters();
    enumParameters getenumParameters();
    alarmParameters getAlarmParameters();
    dateTimeParameters getDateTimeParameters();
    _varOutType getOutPara();

    QString getDisString() const;
    void setDisString(const QString &value);

    QString getDisPic() const;
    void setDisPic(const QString &value);

    _disCmd getDisCmd() const;
    void setDisCmd(const _disCmd &value);

    _disEnum getDisEnum() const;
    void setDisEnum(const _disEnum &value);

    _disDateTime getDisDateTime() const;
    void setDisDateTime(const _disDateTime &value);

    _disNumber getDisNumber() const;
    void setDisNumber(const _disNumber &value);

    _disScroll getDisScroll() const;
    void setDisScroll(const _disScroll &value);

    int getId() const;
    void setId(int value);

    QString getLength() const;
    void setLength(const QString value);

    QString getDataType() const;
    void setDataType(const QString &value);

    int getDataPos() const;
    void setDataPos(int value);

    int getBitPos() const;
    void setBitPos(int value);

    QString getDisName() const;
    void setDisName(const QString &value);

    QString getIconIndex() const;
    void setIconIndex(const QString &value);

    QString getDisUnit() const;
    void setDisUnit(const QString &value);

    QString getDisPara() const;
    void setDisPara(const QString &value);
private:
    int id = 0;

    int varIndex = 0;           // 公共指令 如31
    QString UserLevelLimit; // 功能使用权限
    QString functionName;   // 功能名
    int direction = 0;          // 方向
    int varType = 0;            // 变量类型
    int newVarType = 0;     //默认变量类型
    QString deviceType;     //设备类型
    QString orderType;      // 指令类型

    int disType = 0;            // 显示类型
    bool isDisplay = false;         // 是否显示
    QString disName;        //显示名字
    QString iconIndex;      //图标编号
    QString disUnit;        //显示单位
    QString paraNew;    //默认参数
    QString parameters;     // 参数值
    QString disPara;        //显示参数值
    QString length = 0;             // 返回状态长度
    QString dataType = 0;           // 数据类型

    int dataPos = 0;            // 功能在返回状态中的字节位置
    int bitPos = 0;             // 报警项的位位置
};

#endif // FUNCTIONSTRUCT_H
