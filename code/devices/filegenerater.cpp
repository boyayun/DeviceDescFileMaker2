#include "filegenerater.h"

#define QDEBUG() qDebug()<<__FILE__<<__LINE__

FileGenerater::FileGenerater()
{
    FunctionPos = 0;
}

void FileGenerater::CreateXml(QString fileName, DeviceInformation *h, QList<FunctionStruct *> *l)
{
    QFile file(fileName);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug()<<"OPEN SUCESS";

        QXmlStreamWriter writer(&file);

        writer.writeStartDocument();
        writer.writeStartElement(ROOT);
        writeHeadXml(&writer,h); // 写头部
        writeFunctionXml(&writer,l); //写Function
        writer.writeEndElement();//根目录
        writer.writeEndDocument();
    }
}

void FileGenerater::writeHeadXml(QXmlStreamWriter *w, DeviceInformation *h)
{
    w->writeStartElement(HEADINFORMATION);
    w->writeTextElement(DDVERSION,VERSION_DEVFILE_STD);    //v0.2
    w->writeTextElement(DDFILEVER, h->getFileVer());
    w->writeTextElement(DDDEVICETYPE, ("0"+QString::number(h->getApplyUser(),16).toUpper())); //
    w->writeTextElement(MANUFACTURERCODE, h->getManufactureId());
    w->writeTextElement(DDSTANDBY, ("0"+QString::number(h->getSleep())));

    QString str = "";
    if(QString::number(h->getPrimaryClassCode(), 16).length() == 1)
    {
        str +="0" + QString::number(h->getPrimaryClassCode(), 16).toUpper();
    }
    else
    {
        str += QString::number(h->getPrimaryClassCode(), 16).toUpper();
    }

    if(QString::number(h->getMinorClassCode(), 16).length() == 1)
    {
        str += "0" + QString::number(h->getMinorClassCode(), 16).toUpper();
    }
    else
    {
        str += QString::number(h->getMinorClassCode(), 16).toUpper();
    }
    w->writeTextElement(DEVICETYPEID, str);
    w->writeTextElement(MODELID, h->getModelCode());
    w->writeTextElement(DEVICENAME, h->getDeviceName());
    w->writeTextElement(DDURLLENGTH,TOSTRING(h->getUrlAdress().length()));
    w->writeTextElement(DDURL, h->getUrlAdress());

    if(h->getUpdate())
    {
        w->writeTextElement(UPDATE, ("01"));
    }
    if(h->getClockSync())
    {
        w->writeTextElement(SYNCHRONOUS, "01");
    }
    w->writeEndElement();
}

void FileGenerater::writeFunctionXml(QXmlStreamWriter *w, QList<FunctionStruct *> *l)
{
    w->writeStartElement(FUNCTIONLIST);
    for(int i=0;i<l->size();i++)
    {
        w->writeStartElement(FUNCTION);
        w->writeTextElement(VARINDEX,TOSTRING(l->at(i)->getVarIndex()));
        w->writeTextElement(USERLEVELLIMIT, l->at(i)->getUserLeverLimit());
        w->writeTextElement(DISPLAY,QString::number(l->at(i)->getDisplay()));
        w->writeTextElement(DIRECTION,QString::number(l->at(i)->getDirection()));
        writeVarTypeDesc(w,l->at(i));
        FunctionPos += l->at(i)->getLength().toInt();
        writeDisTypeDesc(w,l->at(i));
        FunctionNumber++;
        w->writeEndElement();
    }
    w->writeEndElement();
}

void FileGenerater::writeVarTypeDesc(QXmlStreamWriter *w, FunctionStruct *f)
{
    w->writeStartElement(VARTYPEDESC);

    QDEBUG()<<"类型"<<f->getNewVarType();

    int vartype = f->getNewVarType();
    w->writeTextElement(VARTYPE,TOSTRING(vartype));

    PRINTLOG(f->getLength());
    w->writeTextElement(VARLENGTH, f->getLength());
    w->writeTextElement(DATAPOS,TOSTRING(this->FunctionPos));
    w->writeTextElement(DATATYPE,f->getDataType());

    if(vartype == VARCMD)
    {
        w->writeStartElement(CMDPARAMETERS);
        cmdParameters cp =  f->getCmdParameters();
        w->writeTextElement(ITEM, cp.parameter1);
        w->writeTextElement(OTHER, cp.para1_other);
        w->writeTextElement(STATUSVALUE, cp.statusValue1);
        w->writeTextElement(ITEM, cp.parameter2);
        w->writeTextElement(OTHER, cp.para2_other);
        w->writeTextElement(STATUSVALUE, cp.statusValue2);
        w->writeTextElement(DEFAULTVALUE, cp.defaultValue);
    }
    else if(vartype == VARNUMBER)
    {
        w->writeStartElement(NUMBERPARA);
        numberParamters np = f->getNumberParameters();
        w->writeTextElement(MAX,np.max);
        w->writeTextElement(MIN,np.min);
        w->writeTextElement(SCALLING,np.scalling);
        w->writeTextElement(UNIT,np.uint);
        w->writeTextElement(DEFAULTVALUE,np.defaultValue);
        w->writeTextElement(VALUEPOS, np.other.valuePos);
        w->writeTextElement(VALUELEN, np.other.valueLen);
        w->writeTextElement(KFACTOR, np.kFactor);
        w->writeTextElement(CFACTOR, np.cFactor);
        w->writeTextElement(VALUEENDIAN, np.endian);
        w->writeTextElement(NUMBERCMD, np.otherPara);
    }
    else if(vartype == VARENUMBERATE)
    {
        w->writeStartElement(ENUMBERATEPARA);
        enumParameters ep = f->getenumParameters();
        int temp = 0;
        for(int i=0; i<ep.enumParaList.size();i++)
        {
            if(ep.enumParaList.at(i)->isSlect)
            {
                temp++;
            }
        }
        w->writeTextElement(ITEMNUM,QString::number(temp));
        w->writeTextElement(DEFAULTVALUE,ep.defaultValue);
        for(int i=0; i<ep.enumParaList.size();i++)
        {
            if(ep.enumParaList.at(i)->isSlect)
            {
                w->writeTextElement(ITEM, ep.enumParaList.at(i)->value);
                w->writeTextElement(ENUMCMD, ep.enumParaList.at(i)->otherPara);
                w->writeTextElement(STATUSVALUE, ep.enumParaList.at(i)->statusValue);
            }
        }
    }
    else if(vartype == VARALARM)
    {
        w->writeStartElement(ALARMPARA);
        alarmParameters ap;
        ap  = f->getAlarmParameters();
        int bitpos = 0;

        for(int i=0;i<ap.warningList.size();i++)
        {
            w->writeStartElement(ALARMITEM);
            w->writeTextElement(DATAPOS,TOSTRING(FunctionPos));
            f->setDataPos(FunctionPos);
            BitPos.append(7-bitpos);
            w->writeTextElement(ALARMBITPOS,TOSTRING(7-bitpos));
            w->writeTextElement(ALARMCODE,TOSTRING(ap.warningList.at(i)->getVarindex()));
            w->writeTextElement(ALARMCLASS,TOSTRING(ap.warningList.at(i)->getWarnClass()));
            w->writeTextElement(ALARMSTRING,ap.warningList.at(i)->getWarnName());
            w->writeEndElement();
            bitpos++;
            if(bitpos==8)
            {
                FunctionPos++;
                bitpos = 0;
            }
        }
    }
    else if(vartype == VARDATE)
    {
        w->writeStartElement(DATEPARA);
        dateTimeParameters datetime = f->getDateTimeParameters();

        w->writeTextElement(YEAR, TOSTRING(datetime.date.year()));
        w->writeTextElement(YEARMAX, TOSTRING(datetime.maxDate.year()));
        w->writeTextElement(YEARMIN, TOSTRING(datetime.minDate.year()));
        w->writeTextElement(YEARSTEP, datetime.yearStep);
        w->writeTextElement(YEARC, datetime.yearC);
        w->writeTextElement(YEARPOS, datetime.yearOther.valuePos);
        w->writeTextElement(YEARLEN, datetime.yearOther.valueLen);

        w->writeTextElement(MONTH, TOSTRING(datetime.date.month()));
        w->writeTextElement(MONTHMAX, TOSTRING(datetime.maxDate.month()));
        w->writeTextElement(MONTHMIN, TOSTRING(datetime.minDate.month()));
        w->writeTextElement(MONTHSTEP, datetime.monthStep);
        w->writeTextElement(MONTHPOS, datetime.monthOther.valuePos);
        w->writeTextElement(MONTHLENGTH, datetime.monthOther.valueLen);

        w->writeTextElement(DAY, TOSTRING(datetime.date.day()));
        w->writeTextElement(DAYMAX, TOSTRING(datetime.maxDate.day()));
        w->writeTextElement(DAYMIN, TOSTRING(datetime.minDate.day()));
        w->writeTextElement(DAYSTEP, datetime.dayStep);
        w->writeTextElement(DAYPOS, datetime.dayOther.valuePos);
        w->writeTextElement(DAYLENGTH, datetime.dayOther.valueLen);

        w->writeTextElement(DATEENDIAN, datetime.endian);
        w->writeTextElement(DATECMD, datetime.otherPara);
    }
    else if(vartype == VARTIME)
    {
        w->writeStartElement(TIMEPARA);
        dateTimeParameters datetime = f->getDateTimeParameters();

        w->writeTextElement(HOUR, TOSTRING(datetime.time.hour()));
        w->writeTextElement(HOURMAX, TOSTRING(datetime.maxTime.hour()));
        w->writeTextElement(HOURMIN, TOSTRING(datetime.minTime.hour()));
        w->writeTextElement(HOURSTEP, datetime.hourStep);
        w->writeTextElement(HOURPOS, datetime.hourOther.valuePos);
        w->writeTextElement(HOURLENGTH, datetime.hourOther.valueLen);

        w->writeTextElement(MINUTE, TOSTRING(datetime.time.minute()));
        w->writeTextElement(MINUTEMAX, TOSTRING(datetime.maxTime.minute()));
        w->writeTextElement(MINUTEMIN, TOSTRING(datetime.minTime.minute()));
        w->writeTextElement(MINUTESTEP, datetime.minuteStep);
        w->writeTextElement(MINUTEPOS, datetime.minOther.valuePos);
        w->writeTextElement(MINUTELENGTH, datetime.minOther.valueLen);

        w->writeTextElement(SECOND, TOSTRING(datetime.time.second()));
        w->writeTextElement(SECONDMAX, TOSTRING(datetime.maxTime.second()));
        w->writeTextElement(SECONDMIN, TOSTRING(datetime.minTime.second()));
        w->writeTextElement(SECONDSTEP, datetime.secondStep);
        w->writeTextElement(SECONDPOS, datetime.secOther.valuePos);
        w->writeTextElement(SECONDLENGTH, datetime.secOther.valueLen);

        w->writeTextElement(TIMEENDIAN, datetime.endian);
        w->writeTextElement(TIMECMD, datetime.otherPara);
    }
    else if(vartype == VARDATETIME)
    {
        w->writeStartElement(DATETIMEPARA);
        dateTimeParameters datetime = f->getDateTimeParameters();

        w->writeTextElement(YEAR, TOSTRING(datetime.date.year()));
        w->writeTextElement(YEARMAX, TOSTRING(datetime.maxDate.year()));
        w->writeTextElement(YEARMIN, TOSTRING(datetime.minDate.year()));
        w->writeTextElement(YEARSTEP, datetime.yearStep);
        w->writeTextElement(YEARC, datetime.yearC);
        w->writeTextElement(YEARPOS, datetime.yearOther.valuePos);
        w->writeTextElement(YEARLEN, datetime.yearOther.valueLen);

        w->writeTextElement(MONTH, TOSTRING(datetime.date.month()));
        w->writeTextElement(MONTHMAX, TOSTRING(datetime.maxDate.month()));
        w->writeTextElement(MONTHMIN, TOSTRING(datetime.minDate.month()));
        w->writeTextElement(MONTHSTEP, datetime.monthStep);
        w->writeTextElement(MONTHPOS, datetime.monthOther.valuePos);
        w->writeTextElement(MONTHLENGTH, datetime.monthOther.valueLen);

        w->writeTextElement(DAY, TOSTRING(datetime.date.day()));
        w->writeTextElement(DAYMAX, TOSTRING(datetime.maxDate.day()));
        w->writeTextElement(DAYMIN, TOSTRING(datetime.minDate.day()));
        w->writeTextElement(DAYSTEP, datetime.dayStep);
        w->writeTextElement(DAYPOS, datetime.dayOther.valuePos);
        w->writeTextElement(DAYLENGTH, datetime.dayOther.valueLen);

        w->writeTextElement(HOUR, TOSTRING(datetime.time.hour()));
        w->writeTextElement(HOURMAX, TOSTRING(datetime.maxTime.hour()));
        w->writeTextElement(HOURMIN, TOSTRING(datetime.minTime.hour()));
        w->writeTextElement(HOURSTEP, datetime.hourStep);
        w->writeTextElement(HOURPOS, datetime.hourOther.valuePos);
        w->writeTextElement(HOURLENGTH, datetime.hourOther.valueLen);

        w->writeTextElement(MINUTE, TOSTRING(datetime.time.minute()));
        w->writeTextElement(MINUTEMAX, TOSTRING(datetime.maxTime.minute()));
        w->writeTextElement(MINUTEMIN, TOSTRING(datetime.minTime.minute()));
        w->writeTextElement(MINUTESTEP, datetime.minuteStep);
        w->writeTextElement(MINUTEPOS, datetime.minOther.valuePos);
        w->writeTextElement(MINUTELENGTH, datetime.minOther.valueLen);

        w->writeTextElement(SECOND, TOSTRING(datetime.time.second()));
        w->writeTextElement(SECONDMAX, TOSTRING(datetime.maxTime.second()));
        w->writeTextElement(SECONDMIN, TOSTRING(datetime.minTime.second()));
        w->writeTextElement(SECONDSTEP, datetime.secondStep);
        w->writeTextElement(SECONDPOS, datetime.secOther.valuePos);
        w->writeTextElement(SECONDLENGTH, datetime.secOther.valueLen);

        w->writeTextElement(DATETIMEENDIAN, datetime.endian);
        w->writeTextElement(DATETIMECMD, datetime.otherPara);
    }
    else if(vartype == VARSINGLE)
    {
        w->writeStartElement(SINGLECMDPARA);
        cmdParameters cp = f->getCmdParameters();
        w->writeTextElement(ITEM, cp.curValue);
        w->writeTextElement(DEFAULTVALUE, cp.curValue);
        w->writeTextElement(SINGLECMD_CMD, cp.otherOrder);
        w->writeTextElement(STATUSVALUE, cp.statusValue);
    }
    else if(vartype == VAROUT)
    {
        w->writeStartElement(OUTPUTPARA);
        _varOutType op = f->getOutPara();
        w->writeTextElement(OUTNUMBER, TOSTRING(op.itemList.size()));
        for(int i=0; i<op.itemList.size(); i++)
        {
            w->writeTextElement(ITEM, op.itemList.at(i)->paraValue);
            w->writeTextElement(OTHER, op.itemList.at(i)->paraOrder);
            w->writeTextElement(STATUSVALUE, op.itemList.at(i)->statusValue);
        }
    }
    else if(vartype == VARINPUT)
    {
        w->writeStartElement(INPUTPARA);
        w->writeTextElement("Null", "");
    }
    w->writeEndElement();
    w->writeEndElement();
}

void FileGenerater::writeDisTypeDesc(QXmlStreamWriter *w, FunctionStruct *f)
{
    if(!f->getDisplay())
    {
        return;
    }
    w->writeStartElement(DISTYPEDESC);
    w->writeTextElement(DISTYPE,TOSTRING(f->getDisType()));
    w->writeTextElement(DISPLAYTEXT,f->getDisName());
    w->writeTextElement(DISPLAYICON, f->getIconIndex());
    w->writeTextElement(DISUNIT, f->getDisUnit());

    w->writeStartElement(DISPARAMETERS);
    int distype = f->getDisType();
    if(distype == DISCMD)
    {
        _disCmd disCmd = f->getDisCmd();
        w->writeStartElement(DISPLAYITEM);
        w->writeTextElement(DISITEMSTRING, disCmd.string1);
        w->writeTextElement(DISITEMPICTURE, disCmd.pic1);
        w->writeEndElement();
        w->writeStartElement(DISPLAYITEM);
        w->writeTextElement(DISITEMSTRING, disCmd.string2);
        w->writeTextElement(DISITEMPICTURE, disCmd.pic2);
        w->writeEndElement();
    }
    else if(distype == DISNUMBER)
    {
        _disNumber disNumber = f->getDisNumber();
        w->writeTextElement(DISNUMBERVALUE, disNumber.disPara);
        w->writeTextElement(DISSCALING, disNumber.disScaling);
    }
    else if(distype == DISENUMBERATE)
    {
        _disEnum disEnum = f->getDisEnum();
        enumParameters ep = f->getenumParameters();

        for(int i=0; i<disEnum.disEnumList.size(); i++)
        {
            if(ep.enumParaList.at(i)->isSlect)
            {
                w->writeStartElement(DISPLAYITEM);
                w->writeTextElement(DISITEMSTRING, disEnum.disEnumList.at(i)->string);
                w->writeTextElement(DISITEMPICTURE, disEnum.disEnumList.at(i)->pic);
                w->writeEndElement();
            }
        }
    }
    else if(distype == DISDATE)
    {
        _disDateTime disDate = f->getDisDateTime();
        w->writeTextElement(DISPLAYYEAR, disDate.disYear);
        w->writeTextElement(DISPLAYMONTH, disDate.disMonth);
        w->writeTextElement(DISPLAYDAY, disDate.disDay);
    }
    else if(distype == DISTIME)
    {
        _disDateTime disTime = f->getDisDateTime();
        w->writeTextElement(DISPLAYHOUR, disTime.disHour);
        w->writeTextElement(DISPLAYMINUTE, disTime.disMin);
        w->writeTextElement(DISPLAYSECOND, disTime.disSec);
    }
    else if(distype == DISDATETIME)
    {
        _disDateTime disDateTime = f->getDisDateTime();
        w->writeTextElement(DISPLAYYEAR, disDateTime.disYear);
        w->writeTextElement(DISPLAYMONTH, disDateTime.disMonth);
        w->writeTextElement(DISPLAYDAY, disDateTime.disDay);
        w->writeTextElement(DISPLAYHOUR, disDateTime.disHour);
        w->writeTextElement(DISPLAYMINUTE, disDateTime.disMin);
        w->writeTextElement(DISPLAYSECOND, disDateTime.disSec);
    }
    else if(distype == DISSCROL)
    {
        _disScroll disScroll = f->getDisScroll();
        w->writeTextElement(DISPLAYMAX, disScroll.disMax);
        w->writeTextElement(DISPLAYMIN, disScroll.disMin);
        w->writeTextElement(DISPLAYSTEP, disScroll.disStep);
        w->writeTextElement(DISPLAYDEFAULT ,disScroll.disDefault);
    }
    else if(distype == DISSTRING)
    {

    }
    else if(distype == DISPICTURE)
    {

    }
    w->writeEndElement();
    w->writeEndElement();
}

void FileGenerater::CreateDocument(QString fileName, QList<FunctionStruct *> *l)
{
    PRINTLOG("");
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName+".pdf");
    QFile helpfile(":/doc.html");
    qDebug()<<helpfile.open(QFile::ReadOnly);
    QByteArray helpcontent =  helpfile.readAll();
    qDebug()<<helpcontent.size();
    QTextDocument *doc = new QTextDocument();
    QTextCursor cursor(doc);
    cursor.insertHtml(helpcontent);

    WriteDoc(&cursor,l);
    doc->print(&printer);
}

void FileGenerater::WriteDoc(QTextCursor *cursor, QList<FunctionStruct *> *l)
{

    QTextTableFormat tableFormat;
    QTextCharFormat titleFormat;
    QTextCharFormat titleFormat2;
    QTextCharFormat textFormat;

    QFont textFont;
    textFont.setFamily("Microsoft YaHei");
    textFont.setPointSize(10);
    textFont.setBold(false);

    QFont titleFont;
    titleFont.setFamily("Microsoft YaHei");
    titleFont.setPointSize(16);
    titleFont.setBold(true);
    titleFormat.setFont(titleFont);
    QFont titleFont2;
    titleFont2.setFamily("Microsoft YaHei");
    titleFont2.setPointSize(14);
    titleFont2.setBold(true);
    titleFormat2.setFont(titleFont2);

    cursor->insertBlock();
    cursor->setPosition(cursor->document()->lastBlock().position());
    cursor->insertText("5 设备",titleFormat);
   cursor->insertBlock();
    cursor->setPosition(cursor->document()->lastBlock().position());

    cursor->insertText("5.1 控制命令\n",titleFormat2);


   QTextCharFormat fragFormat;
    QFont fragfont;
    fragfont.setPointSize(8);
    fragfont.setFamily("Microsoft YaHei");
    fragfont.setItalic(true);
    fragfont.setBold(false);
    fragFormat.setFont(fragfont);
    cursor->insertBlock();

    cursor->setPosition(cursor->document()->lastBlock().position());
    cursor->insertText("    一个控制帧的数据域由功能号（在一个设备中唯一标识一个功能），功能码（命令控制字）以及参数构成，详细控制命令见下表:\n",textFormat);
    cursor->insertText("                               表5-1 控制命令表",fragFormat);


    cursor->insertBlock();

    cursor->setPosition(cursor->document()->lastBlock().position());

    FunctionStruct *alarmf = NULL;
    tableFormat.setAlignment(Qt::AlignCenter);
    tableFormat.setWidth(400);
    cursor->insertBlock();

    cursor->setPosition(cursor->document()->lastBlock().position());
    QTextTable *table = cursor->insertTable(1,5,tableFormat);
    table->cellAt(0,0).firstCursorPosition().insertText("功能名称");
    table->cellAt(0,1).firstCursorPosition().insertText("功能号");
    table->cellAt(0,2).firstCursorPosition().insertText("功能码");
    table->cellAt(0,3).firstCursorPosition().insertText("参数长度");
    table->cellAt(0,4).firstCursorPosition().insertText("参数说明");

    int controlrowcount = 1;
    for(int i=0;i<l->size();i++)
    {
        FunctionStruct *f = l->at(i);
        if(f->getDirection()==3)
        {
            qDebug()<<f->getFunctionName();

            table->insertRows(controlrowcount,1);
            table->cellAt(controlrowcount,0).firstCursorPosition().insertText(f->getFunctionName());
            table->cellAt(controlrowcount,2).firstCursorPosition().insertText(QString::number(f->getVarIndex(),16));
            table->cellAt(controlrowcount,3).firstCursorPosition().insertText(f->getLength()+"Byte");
            table->cellAt(controlrowcount,4).firstCursorPosition().insertText(getDescribe((f)));
            controlrowcount++;
        }
        if(f->getVarType() == VARALARM)
        {
            qDebug()<<f->getFunctionName();
            alarmf = f;
        }
    }
    qDebug()<<"Rowcount is "<<controlrowcount;

    //上报状态格式部分
    cursor->insertBlock();
     cursor->setPosition(cursor->document()->lastBlock().position());

    cursor->insertText("5.2 状态上报格式\n",titleFormat2);
    cursor->insertText("    状态上报要求将设备所有状态全部以状态帧的形式上报，字节"
                       "偏移表示相对于状态帧的数据的第0个字节的偏移量，位偏移表示相对于字节偏移的"
                       "位偏移(如一个变量字节偏移为10，位偏移为7，表示第10个字节的第7位)。\n",textFormat);
    cursor->insertText("                         表5-2 状态上报格式表",fragFormat);
    QTextTable *tableState = cursor->insertTable(1,3,tableFormat);
    tableState->cellAt(0,0).firstCursorPosition().insertText("功能名称");
    tableState->cellAt(0,1).firstCursorPosition().insertText("字节偏移");
    tableState->cellAt(0,2).firstCursorPosition().insertText("长度");

    int count = 0;
    int datapos = 0;
    int bitpos = 0;

    for(int i=0;i<l->size();i++)
    {
        FunctionStruct *f = l->at(i);
        tableState->insertRows(count+1,1);
        tableState->cellAt(count+1,0).firstCursorPosition().insertText(f->getFunctionName(),textFormat);
        tableState->cellAt(count+1,1).firstCursorPosition().insertText(QString::number(datapos),textFormat);
        tableState->cellAt(count+1,2).firstCursorPosition().insertText(f->getLength()+"Byte",textFormat);
        count++;
        datapos += f->getLength().toInt();
    }
//    报警部分
    if(alarmf!=NULL)
    {
        cursor->setPosition(cursor->document()->lastBlock().position());
        cursor->insertText("5.3 报警定义\n",titleFormat2);
        cursor->insertText("    当设备有报警或者故障需要上报，设备以报警帧/异常帧的形式将故障代码发送"
                           "出去，报警码如下表所示：\n",textFormat);
        cursor->insertText("                      表5-3 设备报警表",fragFormat);
        qDebug()<<alarmf->getFunctionName();
        alarmParameters alarmp= alarmf->getAlarmParameters();
        QTextTable *tableAmarl = cursor->insertTable(1,5,tableFormat);

        tableAmarl->cellAt(0,0).firstCursorPosition().insertText("报警码");
        tableAmarl->cellAt(0,1).firstCursorPosition().insertText("报警名称");
        tableAmarl->cellAt(0,2).firstCursorPosition().insertText("报警级别");
        tableAmarl->cellAt(0,3).firstCursorPosition().insertText("字节偏移");
        tableAmarl->cellAt(0,4).firstCursorPosition().insertText("位偏移");
        for(int i=0;i<alarmp.warningList.size();i++)
        {
            tableAmarl->insertRows(i+1,1);
            tableAmarl->cellAt(i+1,0).firstCursorPosition().insertText(QString::number(alarmp.warningList.at(i)->getVarindex()));
            tableAmarl->cellAt(i+1,1).firstCursorPosition().insertText(alarmp.warningList.at(i)->getWarnName());
            tableAmarl->cellAt(i+1,2).firstCursorPosition().insertText(QString::number(alarmp.warningList.at(i)->getWarnClass()));
            tableAmarl->cellAt(i+1,3).firstCursorPosition().insertText(QString::number(datapos));
            tableAmarl->cellAt(i+1,4).firstCursorPosition().insertText(QString::number(7-bitpos));

            bitpos++;
            if(bitpos == 8)
            {
                datapos++;
                bitpos = 0;
            }
        }
    }
    qDebug()<<BitPos;
    qDebug()<<BytePos;
}

void FileGenerater::WriteDescribe(FunctionStruct *f)
{
    int vartype = f->getVarType();
    if(vartype == VARCMD)
    {

    }
    else if(vartype == VARTIME)
    {

    }
}

QString FileGenerater::getDescribe(FunctionStruct *f)
{
    int vartype = f->getVarType();
    QString s;
    if(vartype == VARCMD)
    {
        s+=f->getCmdParameters().parameter1+":"
                +f->getCmdParameters().dis1+"\n"+
                f->getCmdParameters().parameter2+":"
                +f->getCmdParameters().dis2;

    }
    else if(vartype == VARNUMBER)
    {
        numberParamters n = f->getNumberParameters();
        s+="最大值:"+n.max+"\n"
                +"最小值："+n.min+"\n"
                +"分辨率："+n.scalling+"\n"+
                n.min+"和"+n.max+
                "表示实际值："+n.min.toInt()/n.scalling.toInt()+"到"
                +n.max.toInt()/n.scalling.toInt();

    }
    else if(vartype == VARENUMBERATE)
    {
        enumParameters e = f->getenumParameters();
        for(int i=0; i<e.enumParaList.size(); i++)
        {
            s += e.enumParaList.at(i)->value + ":" + e.enumParaList.at(i)->otherPara + e.enumParaList.at(i)->display;
        }
    }
    else if(vartype == VARTIME)
    {
        s+="|时(1Byte)|分（1Byte）|秒（1Byte）";
    }
    else if(vartype == VARDATE)
    {
        s+="|年（2Byte，大端）|月（1Byte）|日（1Byte）|";
    }
    return s;
}
