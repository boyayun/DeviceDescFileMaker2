#ifndef FILEGENERATER_H
#define FILEGENERATER_H

#include<QList>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include<QXmlStreamWriter>
#include<QFile>
#include<QDebug>
#include<stdint.h>
#include<iostream>
#include<QTextStream>
#include<QTextBlock>
#include<QTextDocument>
#include<QTextTable>
#include <QtPrintSupport/QPrinter>

#include "functions/functionstruct.h"
#include "deviceinformation.h"

#define VERSION_DEVFILE_STD "02"        //20172017年1月18日 版本为02

#define TOSTRING(x)  (QString::number(x))
#define ROOT "DeviceDescription"             // 根节点
#define HEADINFORMATION "DeviceInformation"  // 设备头标记
#define DDVERSION "D_Version"                // 描述文件标准本号
#define DDFILEVER "D_FileVer"                // 描述文件版本号
#define DDDEVICETYPE "D_Devictype"           // 文件使用者类型
#define MANUFACTURERCODE "Manufacturer"      // 厂商编码
#define DDSTANDBY       "D_Standby"          // 支持睡眠
#define DEVICETYPEID "TypeID"                // 设备大小类
#define MODELID      "Model_ID"              // 设备型号代码
#define DEVICENAME "Dev_Name"                // 设备名称
#define DDURLLENGTH   "D_URL_Length"         // URL长度
#define DDURL   "D_URL"                      // 描述文件地址
#define UPDATE       "Update"                // 具备在线升级能力
#define SYNCHRONOUS  "Synchronous"           // 具备时间同步能力

#define FUNCTIONLIST "FuncList"              // 功能列表标识
#define FUNCTION     "Function"              // 功能描述标识
#define VARINDEX       "VarIndex"            // 功能控制码
#define USERLEVELLIMIT "UserLimit"           // 功能使用权限
#define DISPLAY        "Display"             // 是否显示
#define DIRECTION      "Direction"           // 操作权限，1，只写：2：只读，3：读写

#define VARTYPEDESC    "VarDesc"             // 类型描述标识
#define FUNTYPE        "FunType"             // 功能类型
#define VARTYPE        "VarType"             // 变量类型

#define STATUSBIT      "StatusBit"           // 状态位
#define BYTEPOS        "BytePos"             // 字节位置
#define BITPOS         "BitPos"              // 位所在位置

#define STATUSFIELD    "StatusField"         // 状态域
#define DATAPOS        "DataPos"             // 位置
#define DATALENGTH     "DataLength"          // 参数长度

#define VARLENGTH      "VarLength"           // 变量长度
#define DATATYPE       "DataType"            // 数据类型

#define CMDPARAMETERS  "CmdParameters"       // 类型参数标识
#define ITEM           "Item"                // 变量值
#define STATUSVALUE    "StatusValue"         // 变量值对应的操作指令中的数据
#define OTHER          "Item_Cmd"            // 变量值对应的操作指令

#define DEFAULTVALUE   "Default"             // 默认值

#define NUMBERPARA      "NumberParam"        // 数字类型参数
#define MAX             "Max"                // 最大值
#define MIN             "Min"                // 最小值
#define SCALLING        "Scalling"           // 分辨率
#define UNIT            "Unit"               // 单位

#define VALUEPOS        "ValuePos"           // 参数值位置
#define VALUELEN        "ValueLength"        // 参数值长度
#define KFACTOR         "K"                  // K参数
#define CFACTOR         "C"                  // C参数
#define VALUEENDIAN     "ValueEndian"        // 参数值大小端
#define NUMBERCMD       "Number_Cmd"         // 变量值对应的操作指令

#define ENUMBERATEPARA  "EnumberateParam"    // 枚举类型参数
#define ITEMNUM         "ItemNum"            // 子项数量
#define ENUMCMD         "Enumberate_Cmd"     // 变量值对应的操作指令

#define ALARMPARA       "AlarmParam"         // 报警类型参数
#define ALARMCODE       "AlarmCode"          // 报警码
#define ALARMCLASS      "AlarmClass"         // 报警级别
#define ALARMSTRING     "AlarmString"        // 报警内容

#define DATEPARA        "DateParam"          // 日期类型参数
#define YEAR            "Year"               // 年
#define YEARMAX         "YearMax"            // 年最大值
#define YEARMIN         "YearMin"            // 年最小值
#define YEARSTEP        "YearStep"           // 年步长
#define YEARC           "Year_C"             // 年修正系数
#define YEARPOS         "Year_Pos"           // 年有效值位置
#define YEARLEN         "Year_Length"        // 年有效值长度
#define MONTH           "Month"              // 月
#define MONTHMAX        "MonthMax"           // 月最大值
#define MONTHMIN        "MonthMin"           // 月最小值
#define MONTHSTEP       "MonthStep"          // 月步长
#define MONTHPOS        "Month_Pos"           // 月有效值位置
#define MONTHLENGTH     "Month_Length"        // 月有效值长度
#define DAY             "Day"               // 日
#define DAYMAX          "DayMax"             // 日最大值
#define DAYMIN          "DayMin"             // 日最小值
#define DAYSTEP         "DayStep"            // 日步长
#define DAYPOS          "Day_Pos"             // 日有效值位置
#define DAYLENGTH       "Day_Length"          // 日有效值长度
#define DATEENDIAN      "Date_Endian"        // 日期有效值大小端
#define DATECMD         "Date_Cmd"           // 日期第三方指令

#define TIMEPARA        "TimeParam"          // 时间类型参数
#define HOUR            "Hour"               // 时
#define HOURMAX         "HourMax"            // 时最大值
#define HOURMIN         "HourMin"            // 时最小值
#define HOURSTEP        "HourStep"           // 时步长
#define HOURPOS         "Hour_Pos"            // 时有效值位置
#define HOURLENGTH      "Hour_Length"         // 时有效长度
#define MINUTE          "Minute"            //分
#define MINUTEMAX       "MinuteMax"          // 分最大值
#define MINUTEMIN       "MinuteMin"          // 分最小值
#define MINUTESTEP      "MinuteStep"         // 分步长
#define MINUTEPOS       "Minute_Pos"          // 分有效值位置
#define MINUTELENGTH    "Minute_Length"       // 分有效值长度
#define SECOND          "Second"            // 秒
#define SECONDMAX       "SecondMax"          // 秒最大值
#define SECONDMIN       "SecondMin"          // 秒最小值
#define SECONDSTEP      "SecondStep"         // 秒步长
#define SECONDPOS       "Second_Pos"          // 秒有效值位置
#define SECONDLENGTH    "Second_Length"       // 秒有效值长度
#define TIMEENDIAN      "Time_Endian"        // 时间有效值大小端
#define TIMECMD         "Time_Cmd"           // 时间第三方指令

#define DATETIMEPARA    "DateTimeParam"      // 日期时间类型参数
#define DATETIMEENDIAN  "DateTime_Endian"    // 日期时间有效值大小端
#define DATETIMECMD     "DateTime_Cmd"       // 日期时间第三方指令

#define SINGLECMDPARA   "SingleCmdParam"     // 单操作类型参数
#define SINGLECMD_CMD   "SingleCmd_Cmd"      // 单操作第三方指令

#define OUTPUTPARA      "OutputParam"        // 输出类型参数
#define OUTNUMBER       "ItemAumout"         // 参数数量

#define INPUTPARA       "InputVarParameters" // 输入类型参数

#define MESSAGEPARA     "MessageVarPara"     // 事件类型参数

#define DISTYPEDESC     "DisDesc"             // 显示描述标识
#define DISTYPE         "DisType"             // 显示类型
#define DISPLAYTEXT     "DisplayText"         // 显示字符串
#define DISPLAYICON     "DisplayIconIndex"    // 显示图标编号
#define DISUNIT         "DisplayUnit"         // 显示单位
#define DISPARAMETERS   "DisParameters"       // 显示参数集合

#define STRINGPARA      "StringParameters"    // 静态文字
#define PICTRUEPARA     "PictrueParameters"   // 静态图片
#define DATEPARADIS     "DateParameters"      // 日期型
#define TIMEPARADIS     "TimeParameters"      // 时间型
#define NUMBERPARADIS   "NumberParameters"    // 数字型
#define CMDPARADIS      "CmdParameters"       // 开关型
#define ENUMPARADIS     "EnumberateParameters"// 枚举型
#define SCROLLPARADIS   "ScrollParameters"    // 滚动条型
#define DATETIMEPARADIS "DatetimeParameters"  // 日期时间型

#define DISPLAYSTRING   "DisplayString"       // 显示字符串
#define DISPLAYPICTURE  "DisplayPictureIndex" // 显示图标编号

#define DISNUMBERVALUE  "Display_Paramerter"  // 显示参数
#define DISSCALING      "Scaling"             // 显示分辨率

#define DISPLAYYEAR     "DisplayYear"         // 年显示
#define DISPLAYMONTH    "DisplayMonth"        // 月显示
#define DISPLAYDAY      "DisplayDay"          // 日显示

#define DISPLAYHOUR     "DisplayHour"         // 时显示
#define DISPLAYMINUTE   "DisplayMinute"       // 分显示
#define DISPLAYSECOND   "DisplaySecond"       // 秒显示
#define DISPLAYITEM     "DisplayItem"         // 显示
#define DISITEMSTRING   "DisplayItemString"   // 显示字符串
#define DISITEMPICTURE  "DisplayPictureIndex" // 显示图片索引

#define DISPLAYMAX     "DisplayMax"           // 显示最大值
#define DISPLAYMIN     "DisplayMin"           // 显示最小值
#define DISPLAYSTEP     "DisplayStep"         // 显示步长
#define DISPLAYUNIT     "DisplayUnit"         // 显示单位序号
#define DISPLAYDEFAULT  "DisplayDefault"      // 默认显示

class FileGenerater
{
public:
    FileGenerater();
    void CreateXml(QString fileName, DeviceInformation *h, QList<FunctionStruct *> *l);
    void writeHeadXml(QXmlStreamWriter *w, DeviceInformation *h);
    void writeFunctionXml(QXmlStreamWriter *w,QList<FunctionStruct *> *l);

    void writeVarTypeDesc(QXmlStreamWriter *w, FunctionStruct *f);
    void writeDisTypeDesc(QXmlStreamWriter *w, FunctionStruct *f);

    void CreateDocument(QString fileName,QList<FunctionStruct *> *l);

    void WriteDoc(QTextCursor *cursor, QList<FunctionStruct *> *l);

    void WriteDescribe(FunctionStruct *f);

    QString getDescribe(FunctionStruct *f);

private:
};

#endif // FILEGENERATER_H
