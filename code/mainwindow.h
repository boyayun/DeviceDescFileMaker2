#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QDebug>
#include <QSettings>
#include <QMessageBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QSplitter>
#include<QWidgetItem>
#include <QStackedWidget>
#include <QDesktopServices>
#include <QList>

#include "deviceinformation.h"
#include "devicelistwidget.h"
#include "devicetreewidget.h"
#include "config.h"
#include "devices/functions/functionlistwidget.h"
#include "functionstruct.h"
#include "devices/functions/parameterwidget.h"
#include "devices/deviceinformationwidget.h"
#include "devices/adddevicewidget.h"
#include "managefunctionwidget.h"
#include "settingwidget.h"
#include "aboutdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    MainWindow(int,QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSplitter *mainSplitter;
    QSplitter *deviceSplitter;
    DeviceListWidget *deviceListWidget;
    DeviceTreeWidget *deviceTreeWidget;
    FunctionListWidget *functionListWidget;
    QList<DeviceInformation*> devInfoList;
    QStackedWidget *stackWidget;
    deviceInformationWidget *addDeviceWidget;
    deviceInformationWidget *deviceinfoWidget;

    void setting();
    void wrDeviceIni();
    void wrDeviceIni(int index);
    void wrFunlistIni(int index);
    void readDeviceIni();
private slots:
    void slotDeviceSaved(deviceInformationWidget *deviceinfo, bool, int index);

    void slotDeviceItemClicked(QTreeWidgetItem* widgetItem,int n);

    void slotAddDevice(bool);

    void slotHelp(bool);

    void slotAuthor(bool);

    void slotDeleteIndex(int);

    void slotFunclistSaved(int,QList<FunctionStruct*>);
};

#endif // MAINWINDOW_H
