#include "functionclass.h"
#include "ui_functionclass.h"

functionclass::functionclass(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::functionclass)
{
    ui->setupUi(this);
}

functionclass::~functionclass()
{
    delete ui;
}
