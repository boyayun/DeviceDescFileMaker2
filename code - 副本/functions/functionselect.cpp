#include "functionselect.h"
#include "ui_functionselect.h"

#define QDEBUG() qDebug()<<"functionselect.cpp"<<__LINE__

MycheckBox::MycheckBox(const QString &text, const int id):
    QCheckBox(text)
{
    this->isSelect = false;
    this->id = id;
    connect(this, SIGNAL(clicked(bool)), this, SLOT(slotCheck(bool)));
}

MycheckBox::~MycheckBox()
{

}

void MycheckBox::slotCheck(bool b)
{
    QDEBUG()<<"isSelect:"<<b;
    this->isSelect = b;
}

Functionselect::Functionselect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::functionselect)
{
    ui->setupUi(this);
    this->init();
}

Functionselect::~Functionselect()
{
    delete ui;
}

void Functionselect::init()
{
    QSqlQuery query;
    QString str = "select * from device_class1";

    QDEBUG()<<"str"<<str;

    if(query.exec(str))
    {
        while(query.next())
        {
            MycheckBox *fun = new MycheckBox(query.value("class_name").toString(),query.value("id").toInt());
            this->ui->checkLayout->addWidget(fun);
            this->functionClassList.append(fun);
            QDEBUG()<<"大类名："<<this->functionClassList.last()->text();
        }
        QDEBUG()<<"功能类型总数"<<this->ui->checkLayout->count();
    }
    else
    {
        delete this;
        QDEBUG()<<"数据库连接错误";
    }
}

void Functionselect::accept()
{
    QDEBUG()<<"functionClassList:"<<functionClassList.size();
    funSelectedList.clear();
    for(int i=0; i<functionClassList.size(); i++)
    {
        if(true == functionClassList.at(i)->isSelect)
        {
            funSelectedList.append(functionClassList.at(i)->id);
        }
    }
    emit signalSelectedFunction(funSelectedList);
    this->close();
}

void Functionselect::reject()
{
    this->close();
}

void Functionselect::closeEvent(QCloseEvent *event)
{
    event->accept();
}
