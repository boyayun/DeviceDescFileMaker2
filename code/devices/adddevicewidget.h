#ifndef ADDDEVICEWIDGET_H
#define ADDDEVICEWIDGET_H

#include <QDialog>
#include "deviceinformation.h"
#include <QMessageBox>

namespace Ui {
class AddDeviceWidget;
}

class AddDeviceWidget : public QDialog
{
    Q_OBJECT

public:
    explicit AddDeviceWidget(DeviceInformation *deviceInfo, QWidget *parent = 0);
    ~AddDeviceWidget();

private:
    Ui::AddDeviceWidget *ui;
    DeviceInformation *deviceInformation;
    void init();
    void autoInput();
    int getModelID();

    bool isPassInputCheck();
signals:
    void signalUpdateTreeList();

private slots:
    void slotClass1Changed(int);
    void on_createpushButton_clicked();
};

#endif // ADDDEVICEWIDGET_H
