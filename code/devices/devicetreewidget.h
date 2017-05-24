#ifndef DEVICETREEWIDGET_H
#define DEVICETREEWIDGET_H

#include <QObject>
#include <QWidget>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QMap>
#include <QDebug>
#include <QList>
#include <QAction>

#include "deviceinformationwidget.h"
#include "deviceinformation.h"

class MyTreeWidgetItem : public QObject, public QTreeWidgetItem
{
    Q_OBJECT
public:
    MyTreeWidgetItem(const QStringList &strings);
    int getDeviceId() const;
    void setDeviceId(int value);

private:
    int deviceId;
};

class DeviceTreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    DeviceTreeWidget(QList<DeviceInformation*>devInfoList);
    void updateTreeWidget(QList<DeviceInformation *> devInfoList);
    void updateTreeWidget(QString str);
protected:
     void contextMenuEvent(QContextMenuEvent *event);

signals:
     void signalDeleteIndex(int);

private slots:
    void slotDelete();
};

#endif // DEVICETREEWIDGET_H
