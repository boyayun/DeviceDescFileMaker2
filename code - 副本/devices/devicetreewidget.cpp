#include "devicetreewidget.h"
#include <qwidget.h>
#include <QEvent>
#include <qmenu.h>
#include <QPoint>
#include <QTextCodec>
#include <QContextMenuEvent>
#include <qobject.h>

DeviceTreeWidget::DeviceTreeWidget(QList<DeviceInformation*>devInfoList)
{
    this->setHeaderLabel("DeviceName");

    if(!devInfoList.isEmpty())
    {
        for(int i=0; i<devInfoList.size();i++)
        {
            MyTreeWidgetItem *item = new MyTreeWidgetItem(QStringList(devInfoList.at(i)->getDeviceName()));
            this->addTopLevelItem(item);
            item->setDeviceId(i);
            item->addChild(new QTreeWidgetItem(QStringList("DeviceInformation")));
            item->addChild(new QTreeWidgetItem(QStringList("ParametersInformation")));
        }
    }
}

void DeviceTreeWidget::contextMenuEvent(QContextMenuEvent *event)
{
    QTreeWidgetItem *item = this->currentItem();

    if((item->childCount() != 0)&&(item == this->itemAt(event->pos())))
    {
        qDebug()<<QString("右键事件");
        QMenu *menu = new QMenu(this);
        QAction *actiondel = new QAction("删除设备", this);

        menu->addAction(actiondel);
        connect(actiondel ,SIGNAL(triggered()),this,SLOT(slotDelete()));
        menu->exec(QCursor::pos());
    }
}

void DeviceTreeWidget::slotDelete()
{
    qDebug()<<"右键有效";
    MyTreeWidgetItem *item = (MyTreeWidgetItem*)this->currentItem();
    int index = item->getDeviceId();
    emit signalDeleteIndex(index);
}

void DeviceTreeWidget::updateTreeWidget(QList<DeviceInformation *> devInfoList)
{
    this->clear();
    this->setHeaderLabel("DeviceName");
    if(!devInfoList.isEmpty())
    {
        for(int i=0; i<devInfoList.size();i++)
        {
            MyTreeWidgetItem *item = new MyTreeWidgetItem(QStringList(devInfoList.at(i)->getDeviceName()));
            this->addTopLevelItem(item);
            item->setDeviceId(i);
            item->addChild(new QTreeWidgetItem(QStringList("DeviceInformation")));
            item->addChild(new QTreeWidgetItem(QStringList("ParametersInformation")));
        }
    }
}

void DeviceTreeWidget::updateTreeWidget(QString str)
{
    this->currentItem()->parent()->setText(0,str);
}

MyTreeWidgetItem::MyTreeWidgetItem(const QStringList &strings):QTreeWidgetItem(strings)
{

}

int MyTreeWidgetItem::getDeviceId() const
{
    return deviceId;
}

void MyTreeWidgetItem::setDeviceId(int value)
{
    deviceId = value;
}

