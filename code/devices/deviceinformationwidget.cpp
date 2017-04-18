#include "deviceinformationwidget.h"
#include "ui_deviceinformationwidget.h"
#include <QMessageBox>

deviceInformationWidget::deviceInformationWidget(bool b, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deviceInformationWidget)
{
    ui->setupUi(this);
    this->ui->frame->setStyleSheet(".QFrame{border:1px solid black}");
//    QRegExp regx("[0-9]+$");
//    QValidator *validator = new QRegExpValidator(regx);
//    this->ui->modelIDlineEdit->setValidator(validator);
    this->ui->modelIDlineEdit->setMaxLength(6);
//    this->ui->fileVerEdit->setValidator(validator);
    this->ui->fileVerEdit->setText("01");
    //    this->ui->manufactureIDLineedit->setValidator(validator);
    this->ui->manufactureIDLineedit->setMaxLength(13);
    this->ui->manufactureIDLineedit->setText("6924575716026");
    this->ui->applyUserBox->setFixedWidth(150);
    this->ui->applyUserBox->addItem("所有用户");
    this->ui->applyUserBox->addItem("家庭用户");
    this->ui->applyUserBox->addItem("生产厂");
    this->ui->applyUserBox->addItem("系统集成商");

    this->ui->linkBox->setFixedWidth(150);
    this->ui->linkBox->addItem("以太网");
    this->ui->linkBox->addItem("WIFI");
    this->ui->linkBox->addItem("Zigbee");
    this->ui->linkBox->addItem("485总线");
    this->ui->linkBox->addItem("蓝牙");
    this->ui->linkBox->addItem("电力线");
    this->ui->linkBox->addItem("RF无线");
    this->ui->linkBox->addItem("红外");

    this->ui->urllineEdit->setText("http://www.tcl-smarthome.com/");

    isNewflag = b;
    if(isNewflag)
    {
        init();
        slotClass1Changed(0);
    }
    else
    {
        this->ui->primaryClass->setEnabled(false);
        this->ui->minorClass->setEnabled(false);
        this->ui->primaryClass->addItem("");
        this->ui->minorClass->addItem("");
    }
}

deviceInformationWidget::~deviceInformationWidget()
{
    delete ui;
}

void deviceInformationWidget::init()
{
    QSqlQuery query;
    QString str = "select * from device_class1 where id > 0 order by id";
    query.exec(str);
    while(query.next())
    {
        this->ui->primaryClass->addItem(query.value("class_name").toString());
    }
    connect(ui->primaryClass,SIGNAL(currentIndexChanged(int)),this,SLOT(slotClass1Changed(int)));
}

void deviceInformationWidget::slotClass1Changed(int class1)
{
    ui->minorClass->clear();
    class1 +=1;
    QSqlQuery query;
    QString str = "select * from device_class2 where class1_id = (:class1_id) order by class2_id";
    query.prepare(str);
    query.bindValue(":class1_id",class1);
    if(query.exec())
    {
        while(query.next())
        {
            this->ui->minorClass->addItem(query.value("class2_name").toString());
        }
    }
    else
    {
        QMessageBox::warning(this,"Waring!","数据库连接已断开，请重新启动程序");
    }
}

void deviceInformationWidget::updateDeviceInfo(DeviceInformation *deviceInfo, int index)
{
    this->deviceIndex = index;

    this->ui->namelineEdit->setText(deviceInfo->getDeviceName());
    this->ui->fileVerEdit->setText(deviceInfo->getFileVer());
    this->ui->applyUserBox->setCurrentIndex(deviceInfo->getApplyUser());
    this->ui->modelIDlineEdit->setText(deviceInfo->getModelCode());
    this->ui->primaryClass->setItemText(0,deviceInfo->getPrimaryClass());
    this->ui->minorClass->setItemText(0,deviceInfo->getMinorClass());
    this->ui->manufactureIDLineedit->setText(deviceInfo->getManufactureId());
    this->ui->urllineEdit->setText(deviceInfo->getUrlAdress());
    this->ui->linkBox->setCurrentIndex(deviceInfo->getLinkWay());
    this->ui->updateCheckbox->setChecked(deviceInfo->getUpdate());
    this->ui->synCheckBox->setChecked(deviceInfo->getClockSync());
    this->ui->sleepCheckBox->setChecked(deviceInfo->getSleep());
    this->ui->otherparaCheckBox->setChecked(deviceInfo->getOtherPara());
}

void deviceInformationWidget::on_savepushButton_clicked()
{
    this->deviceName = this->ui->namelineEdit->text();
    this->fileVer = this->ui->fileVerEdit->text();
    this->applyUser = this->ui->applyUserBox->currentIndex();
    this->deviceModelID = this->ui->modelIDlineEdit->text();
    if(isNewflag)
    {
        this->primaryModelCode = this->ui->primaryClass->currentIndex()+1;
        this->monirModelCode = this->ui->minorClass->currentIndex()+1;
    }
    this->primaryModel = this->ui->primaryClass->currentText();
    this->monirModel = this->ui->minorClass->currentText();
    this->manufactureID = this->ui->manufactureIDLineedit->text();
    this->url = this->ui->urllineEdit->text();
    this->linkWay = this->ui->linkBox->currentIndex()+1;
    this->isUpdate = this->ui->updateCheckbox->isChecked();
    this->isSync = this->ui->synCheckBox->isChecked();
    this->isSleep = this->ui->sleepCheckBox->isChecked();
    this->isOtherpara = this->ui->otherparaCheckBox->isChecked();

    emit signalSavebutton(this, isNewflag, deviceIndex);

    if(isNewflag)
    {
        this->close();
    }
}
