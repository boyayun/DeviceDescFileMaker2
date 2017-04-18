#include "addfunctionswidget.h"
#include "ui_addfunctionswidget.h"

#define QDEBUG() qDebug()<<"addfunctionswidget.cpp"<<__LINE__

AddFunctionsWidget::AddFunctionsWidget(QList<FunctionStruct*>list, QDialog *parent) :
    QDialog(parent),
    ui(new Ui::AddFunctionsWidget)
{
    ui->setupUi(this);
    this->setWindowTitle("Add a Function");
    this->funlist.clear();
    this->funlist.append(list);
    init();
}

AddFunctionsWidget::~AddFunctionsWidget()
{
    delete ui;
}

void AddFunctionsWidget::init()
{
    for(int i=0; i<funlist.size();i++)
    {
        MyListWidgetItem *myItem = new MyListWidgetItem(funlist.at(i)->getFunctionName(),funlist.at(i)->getVarIndex());
        this->selectedListItemList.append(myItem);
        this->ui->selectlistWidget->addItem(myItem);
    }
}

MyListWidgetItem::MyListWidgetItem(const QString text, int varIndex):QListWidgetItem(text)
{
    QDEBUG()<<"varIndex"<<varIndex;
    this->varIndex = varIndex;
}

int MyListWidgetItem::getVarIndex() const
{
    return varIndex;
}

MyListWidgetItem::~MyListWidgetItem()
{
    //  PRINTLOG("MyListWidgetItemdestruct");
}

void AddFunctionsWidget::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    MyListWidgetItem *myItem = new MyListWidgetItem(item->text(),((MyListWidgetItem*)item)->getVarIndex());
    for(int i=0; i<selectedListItemList.size(); i++)
    {
        if(selectedListItemList.at(i)->getVarIndex() == myItem->getVarIndex())
        {
            QDEBUG()<<"功能重复添加";
            return;
        }
    }
    if(myItem->getVarIndex() == VARINDEXPOWER)
    {
        QDEBUG()<<"添加电源功能";
        this->selectedListItemList.insert(0,myItem);
        this->ui->selectlistWidget->insertItem(0,myItem);
    }
    else if(myItem->getVarIndex() == VARINDEXWARNING)
    {
        QDEBUG()<<"添加报警功能";
        this->selectedListItemList.append(myItem);
        this->ui->selectlistWidget->addItem(myItem);
    }
    else if(this->selectedListItemList.size() != 0)
    {
        if(this->selectedListItemList.last()->getVarIndex() == VARINDEXWARNING)
        {
            QDEBUG()<<this->selectedListItemList.count();
            QDEBUG()<<this->selectedListItemList.count();
            this->selectedListItemList.insert((this->selectedListItemList.count()-1),myItem);
            this->ui->selectlistWidget->insertItem((this->ui->selectlistWidget->count()-1),myItem);
        }
        else
        {
            this->selectedListItemList.append(myItem);
            this->ui->selectlistWidget->addItem(myItem);
        }
    }
    else
    {
        this->selectedListItemList.append(myItem);
        this->ui->selectlistWidget->addItem(myItem);
    }
    QDEBUG()<<"添加的功能数"<<QString::number(ui->selectlistWidget->count());
}

void AddFunctionsWidget::on_selectlistWidget_itemDoubleClicked(QListWidgetItem *item)
{
    int row = this->ui->selectlistWidget->row(item);
    selectedListItemList.removeAt(row);
    delete ui->selectlistWidget->takeItem(row);
    QDEBUG()<<"选择的功能数"<<QString::number(ui->selectlistWidget->count());
}

void AddFunctionsWidget::on_searchlineEdit_textChanged(const QString &arg1)
{
    for(int i=0;i<listItemList.size();i++)
    {
        if(listItemList.at(i)->text().contains(arg1))
        {
            this->listItemList.at(i)->setHidden(false);
        }
        else
        {
            this->listItemList.at(i)->setHidden(true);
        }
    }
}

void AddFunctionsWidget::on_selectFunButton_clicked()
{
    Functionselect *funMenu = new Functionselect();
    connect(funMenu, SIGNAL(signalSelectedFunction(QList<int>)), this, SLOT(slotFunmenu(QList<int>)));
    funMenu->exec();
}

void AddFunctionsWidget::slotFunmenu(QList<int>list)
{
    QString str = "";
    QSqlQuery query;
    this->listItemList.clear();
    this->ui->listWidget->clear();
    for(int i=0; i<list.size(); i++)
    {
        str = QString::number(list.at(i));
        str = "select id,gcmd_name_ch from general_command where((device_class=" + str +
                " and gcmd_type <> 4)"
                "or ((id = 999999) and (device_class="+str+")))"
                                                           " order by id";
        PRINTLOG(str);
        if(query.exec(str))
        {
            PRINTLOG("gcmd_name_ch");
            while(query.next())
            {
                MyListWidgetItem *i = new  MyListWidgetItem(query.value("gcmd_name_ch").toString(),
                                                            query.value("id").toInt());
                this->listItemList.append(i);
                this->ui->listWidget->addItem(i);
            }
        }
    }
}

void AddFunctionsWidget::on_addpushButton_clicked()
{
    QString str = "";
    QSqlQuery query;

    funlist.clear();
    for(int i=0; i<selectedListItemList.size(); i++)
    {
        str = QString::number(selectedListItemList.at(i)->getVarIndex());
        str = "SELECT * FROM general_command ,parameter_default where id = (" +
                str + ")and general_command.id = parameter_default.general_command_id";

        if(query.exec(str))
        {
            query.next();
            PRINTLOG(query.value("gcmd_name_ch").toString());
            FunctionStruct *f = new FunctionStruct();
            f->setFunctionName(query.value("gcmd_name_ch").toString());
            f->setDirection(query.value("direction").toInt());
            f->setVarIndex(query.value("id").toInt());
            f->setVarType(query.value("gcmd_type").toInt());
            f->setNewVarType(query.value("gcmd_type").toInt(), false);
            f->setDeviceType(query.value("device_class").toString());
            f->setOrderType(query.value("cmdType").toString());
            f->setParameters(query.value("parameter").toString());
            f->setParaNew(query.value("parameter").toString());
            f->setDisType(query.value("distype").toInt());
            f->setUserLeverLimit("0");
            f->setDisUnit("0");
            f->setDisName(f->getFunctionName());
            f->setDisplay(true);

            PRINTLOG(f->getDisType());
            QString orderStr;
            switch(f->getVarType())
            {
            case VARCMD:
            {
                cmdParameters cp = f->getCmdParameters();
                orderStr = f->getStr(f->getVarIndex(), 4, true);
                orderStr.append(f->getStr(cp.parameter1.toInt(), 2, true));
                cp.para1_other = orderStr;
                orderStr = f->getStr(f->getVarIndex(), 4, true);
                orderStr.append(f->getStr(cp.parameter2.toInt(), 2, true));
                cp.para2_other = orderStr;
                _disCmd dc;
                dc.value1 = cp.parameter1;
                dc.value2 = cp.parameter2;
                dc.string1 = cp.dis1;
                dc.string2 = cp.dis2;
                f->setParameter(cp);
                f->setDisCmd(dc);
            }
                break;

            case VARNUMBER:
            {
                numberParamters np = f->getNumberParameters();
                f->setDisUnit(np.uint);
                np.kFactor = "1";
                np.cFactor = "0";
                orderStr = f->getStr(f->getVarIndex(), 4, true);
                orderStr.append(f->getStr(np.defaultValue.toInt(), 4, true));
                np.otherPara = orderStr;
                np.endian = VALUEBIGEND;
                np.other.valueLen = "2";
                np.other.valuePos = "2";
                if(f->getDirection() == DIRRD)
                {
                    _disNumber dn;
                    dn.disPara = np.defaultValue;
                    dn.disScaling = np.scalling;
                    f->setDisNumber(dn);
                }
                else if(f->getDirection() == DIRWD)
                {
                    _disScroll ds;
                    ds.disMax = np.max;
                    ds.disMin = np.min;
                    ds.disDefault = np.defaultValue;
                    ds.disStep = "1";
                    f->setDisScroll(ds);
                }
                f->setParameter(np);
            }
                break;

            case VARENUMBERATE:
            {
                enumParameters ep = f->getenumParameters();
                _disEnum de;
                for(int i=0; i<ep.enumParaList.size(); i++)
                {
                    orderStr = f->getStr(f->getVarIndex(), 4, true);
                    orderStr.append(f->getStr(ep.enumParaList.at(i)->value.toInt(), 2, true));
                    ep.enumParaList.at(i)->otherPara = orderStr;
                    ep.enumParaList.at(i)->isSlect = true;

                    _disEnumPara *dep = new _disEnumPara;
                    dep->value = ep.enumParaList.at(i)->value;
                    dep->string = ep.enumParaList.at(i)->display;
                    de.disEnumList.append(dep);
                }
                f->setParameter(ep);
                f->setDisEnum(de);
            }
                break;

            case VARALARM:
            {
                f->setDisplay(false);
            }
                break;

            case VARDATE:
            {
                orderStr = f->getStr(f->getVarIndex(), 4, true);
                dateTimeParameters dp = f->getDateTimeParameters();
                orderStr.append(f->getStr(dp.date.year(), 4, false));
                orderStr.append(f->getStr(dp.date.month(), 2, false));
                orderStr.append(f->getStr(dp.date.day(), 2, false));
                dp.otherPara = orderStr;
                dp.yearOther.valueLen = "2";
                dp.yearOther.valuePos = "2";
                dp.monthOther.valueLen = "1";
                dp.monthOther.valuePos = "4";
                dp.endian = VALUEBIGEND;
                dp.dayOther.valueLen = "1";
                dp.dayOther.valuePos = "5";

                _disDateTime dd;
                dd.disYear = dp.yearDis;
                dd.disMonth = dp.monthDis;
                dd.disDay = dp.dayDis;

                f->setParameter(dp);
                f->setDisDateTime(dd);
            }
                break;

            case VARTIME:
            {
                orderStr = f->getStr(f->getVarIndex(), 4, true);
                dateTimeParameters tp = f->getDateTimeParameters();
                orderStr.append(f->getStr(tp.time.hour(), 2, false));
                orderStr.append(f->getStr(tp.time.minute(), 2, false));
                orderStr.append(f->getStr(tp.time.second(), 2, false));
                tp.otherPara = orderStr;

                tp.hourOther.valueLen = "1";
                tp.hourOther.valuePos = "2";
                tp.minOther.valueLen = "1";
                tp.minOther.valuePos = "3";
                tp.endian = VALUEBIGEND;
                tp.secOther.valueLen = "1";
                tp.secOther.valuePos = "4";

                _disDateTime dt;
                dt.disHour = tp.hourDis;
                dt.disMin = tp.minuteDis;
                dt.disSec = tp.secondDis;

                f->setParameter(tp);
                f->setDisDateTime(dt);
            }
                break;

            case VARDATETIME:
            {
                orderStr = f->getStr(f->getVarIndex(), 4, true);
                dateTimeParameters dtp = f->getDateTimeParameters();
                orderStr.append(f->getStr(dtp.date.year(), 4, false));
                orderStr.append(f->getStr(dtp.date.month(), 2, false));
                orderStr.append(f->getStr(dtp.date.day(), 2, false));
                orderStr.append(f->getStr(dtp.time.hour(), 2, false));
                orderStr.append(f->getStr(dtp.time.minute(), 2, false));
                orderStr.append(f->getStr(dtp.time.second(), 2, false));
                dtp.otherPara = orderStr;
                dtp.yearOther.valueLen = "2";
                dtp.yearOther.valuePos = "2";
                dtp.monthOther.valueLen = "1";
                dtp.monthOther.valuePos = "4";
                dtp.dayOther.valueLen = "1";
                dtp.dayOther.valuePos = "5";
                dtp.hourOther.valueLen = "1";
                dtp.hourOther.valuePos = "6";
                dtp.minOther.valueLen = "1";
                dtp.minOther.valuePos = "7";
                dtp.endian = VALUEBIGEND;
                dtp.secOther.valueLen = "1";
                dtp.secOther.valuePos = "8";

                _disDateTime ddt;
                ddt.disYear = dtp.yearDis;
                ddt.disMonth = dtp.monthDis;
                ddt.disDay = dtp.dayDis;
                ddt.disHour = dtp.hourDis;
                ddt.disMin = dtp.minuteDis;
                ddt.disSec = dtp.secondDis;

                f->setParameter(dtp);
                f->setDisDateTime(ddt);
            }
                break;

            default:
                break;
            }
            funlist.append(f);
        }
    }
    PRINTLOG(str);

    emit signalAddFunctions(funlist);
    this->close();
}

void AddFunctionsWidget::on_cancelpushButton_clicked()
{
    this->close();
}
