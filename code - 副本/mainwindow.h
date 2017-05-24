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

#include "devices/deviceinformation.h"
#include "devices/devicetreewidget.h"
#include "functions/functionlistwidget.h"
#include "functions/functionstruct.h"
#include "functions/parameterwidget.h"
#include "devices/deviceinformationwidget.h"
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

    void slotAuthor(bool);

    void slotDeleteIndex(int);

    void slotFunclistSaved(int,QList<FunctionStruct*>);
};

#endif // MAINWINDOW_H
