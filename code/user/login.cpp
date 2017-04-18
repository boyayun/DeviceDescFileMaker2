#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setWindowTitle("Login");
   // this->setWindowFlags(Qt::FramelessWindowHint);
    setWindowFlags(Qt::WindowTitleHint | Qt::CustomizeWindowHint);
//    this->ui->registerpushButton->setFlat(true);
}

Login::~Login()
{
    delete ui;
}

void Login::on_loginBtn_clicked()
{

    QString username = ui->userNameLedt->text();
    QString passwd = ui->passwdLedt->text();

    QString sqlStr = "select id from user where user_name = '"+username +"' and user_passwd = '"+passwd+"'";
    QSqlQuery query;
    if(query.exec(sqlStr))
    {
        query.next();
        if(query.value("id").toInt())
        {
            emit signalLoginState(query.value("id").toInt());
            this->close();
        }
        else
        {
            this->ui->label->setStyleSheet("color: red");
            this->ui->label->setText("用户名或密码错误");
        }
    }
}

void Login::on_cancleBtn_clicked()
{
    exit(-1);
}

void Login::keyPressEvent(QKeyEvent *e)
{

}
