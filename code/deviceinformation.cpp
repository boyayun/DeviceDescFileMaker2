#include "deviceinformation.h"

DeviceInformation::DeviceInformation()
{

}

QString DeviceInformation::getDeviceName() const
{
    return deviceName;
}

void DeviceInformation::setDeviceName(const QString &value)
{
    deviceName = value;
}

QString DeviceInformation::getDeviceModel() const
{
    return deviceModel;
}

void DeviceInformation::setDeviceModel(const QString &value)
{
    deviceModel = value;
}

QString DeviceInformation::getFileVer() const
{
    return fileVer;
}

void DeviceInformation::setFileVer(const QString &value)
{
    fileVer = value;
}

int DeviceInformation::getApplyUser() const
{
    return applyUser;
}

void DeviceInformation::setApplyUser(const int value)
{
    applyUser = value;
}

QString DeviceInformation::getModelCode() const
{
    return modelCode;
}

void DeviceInformation::setModelCode(const QString &value)
{
    modelCode = value;
}

int DeviceInformation::getPrimaryClassCode() const
{
    return primaryClassCode;
}

void DeviceInformation::setPrimaryClassCode(const int value)
{
    primaryClassCode = value;
}

QString DeviceInformation::getPrimaryClass() const
{
    return primaryClass;
}

void DeviceInformation::setPrimaryClass(const QString &value)
{
    primaryClass = value;
}

int DeviceInformation::getMinorClassCode() const
{
    return minorClassCode;
}

void DeviceInformation::setMinorClassCode(const int value)
{
    minorClassCode = value;
}

QString DeviceInformation::getMinorClass() const
{
    return minorClass;
}

void DeviceInformation::setMinorClass(const QString &value)
{
    minorClass = value;
}

QString DeviceInformation::getManufactureId() const
{
    return manufactureId;
}

void DeviceInformation::setManufactureId(const QString &value)
{
    manufactureId = value;
}

QString DeviceInformation::getUrlAdress() const
{
    return urlAdress;
}

void DeviceInformation::setUrlAdress(const QString &value)
{
    urlAdress = value;
}

int DeviceInformation::getLinkWay() const
{
    return linkWay;
}

void DeviceInformation::setLinkWay(const int value)
{
    linkWay = value;
}

bool DeviceInformation::getUpdate() const
{
    return isUpdate;
}

void DeviceInformation::setUpdate(const bool value)
{
    isUpdate = value;
}

bool DeviceInformation::getClockSync() const
{
    return isClockSync;
}

void DeviceInformation::setClockSync(const bool value)
{
    isClockSync = value;
}

bool DeviceInformation::getSleep() const
{
    return isSleep;
}

void DeviceInformation::setSleep(const bool value)
{
    isSleep = value;
}

bool DeviceInformation::getOtherPara() const
{
    return isOtherPara;
}

void DeviceInformation::setOtherPara(const bool value)
{
    isOtherPara =value;
}

QList<FunctionStruct*>DeviceInformation::getfunList()
{
    return functionList;
}

void DeviceInformation::setfunList(QList<FunctionStruct*> list)
{
    functionList.clear();
    functionList.append(list);
}
