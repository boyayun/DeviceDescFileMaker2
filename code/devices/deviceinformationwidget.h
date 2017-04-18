#ifndef DEVICEINFORMATIONWIDGET_H
#define DEVICEINFORMATIONWIDGET_H

#include <QWidget>
#include <QDialog>
#include <QSqlQuery>
#include <qstringlist.h>
#include "config.h"
#include "deviceinformation.h"

namespace Ui {
class deviceInformationWidget;
}

class deviceInformationWidget : public QDialog
{
    Q_OBJECT

public:
    explicit deviceInformationWidget(bool b,QWidget *parent = 0);
    ~deviceInformationWidget();
    void updateDeviceInfo(DeviceInformation *deviceInfo, int index);
    void init();

    QString deviceName;
    QString fileVer;
    int     applyUser;
    QString deviceModelID;
    int primaryModelCode;
    QString primaryModel;
    int monirModelCode;
    QString monirModel;
    QString manufactureID;
    QString url;

    int  linkWay;
    bool isUpdate;
    bool isSync;
    bool isSleep;
    bool isOtherpara;
signals:
    void signalSavebutton(deviceInformationWidget*,bool,int);

private slots:
    void on_savepushButton_clicked();
    void slotClass1Changed(int class1);
private:
    Ui::deviceInformationWidget *ui;
    bool isNewflag;         // 新建
    int deviceIndex;        // 设备索引
};

#endif // DEVICEINFORMATIONWIDGET_H
