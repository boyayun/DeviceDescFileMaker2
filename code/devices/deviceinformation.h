#ifndef DEVICEINFORMATION_H
#define DEVICEINFORMATION_H

#include <QString>
#include <QStringList>
#include <QList>
#include <QMap>
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>

#include "functions/functionstruct.h"

class DeviceInformation
{
public:
    DeviceInformation();

    QString getDeviceName() const;
    void setDeviceName(const QString &value);

    QString getDeviceModel() const;
    void setDeviceModel(const QString &value);

    QString getModelCode() const;
    void setModelCode(const QString &value);

    QString getFileVer() const;
    void setFileVer(const QString &value);

    int getApplyUser() const;
    void setApplyUser(const int value);

    int getPrimaryClassCode() const;
    void setPrimaryClassCode(const int value);

    int getMinorClassCode() const;
    void setMinorClassCode(const int value);

    QString getManufactureId() const;
    void setManufactureId(const QString &value);

    QString getUrlAdress() const;
    void setUrlAdress(const QString &value);

    int getLinkWay() const;
    void setLinkWay(const int value);

    bool getUpdate() const;
    void setUpdate(const bool value);

    bool getClockSync() const;
    void setClockSync(const bool value);

    bool getSleep() const;
    void setSleep(const bool value);

    bool getOtherPara() const;
    void setOtherPara(const bool value);

    QList<FunctionStruct*>getfunList();
    void setfunList(QList<FunctionStruct*> list);

private:
    QString deviceName;     // 设备名称
    QString deviceModel;    // 设备型号
    QString fileVer;        // 文件版本
    int     applyUser;      // 适用用户
    QString modelCode;      // 型号代码
    int     primaryClassCode;   //设备大类号
    int     minorClassCode; //设备小类号
    QString manufactureId;  // 厂商编码
    QString urlAdress;      // 网址
    int  linkWay;           //链路方式
    bool isUpdate;            // 在线升级
    bool isClockSync;         // 时间同步
    bool isSleep;             // 睡眠
    bool isOtherPara;         // 第三方参数

    QList<FunctionStruct*> functionList;
};

#endif // USERINFORMATION_H
