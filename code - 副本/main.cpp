#include <QApplication>
#include <QDir>
#include <QSqlDatabase>
#include <QSettings>
#include <settingwidget.h>
#include <QProgressBar>
#include <QPrinter>
#include <QtMath>

#include "mainwindow.h"

bool connectToDataBase()
{
    QSqlDatabase dataBase = QSqlDatabase::addDatabase("QMYSQL");
    QSettings s("setting.ini",QSettings::IniFormat); //配置文件读取配置信息
    if(s.value("Address").toString() == "")
    {
//        dataBase.setHostName("192.168.0.117");
        dataBase.setHostName("124.251.36.88");
    }
    else
    {
        dataBase.setHostName(s.value("Address").toString());
    }
    if(s.value("Port").toString() == "")
    {
        dataBase.setPort(3306);
    }
    else
    {
        dataBase.setPort(s.value("Port").toInt());
    }
    dataBase.setDatabaseName("generalcommand");

    dataBase.setUserName("jiaqi");
    dataBase.setPassword("123456");
    try
    {
         bool isOpen = dataBase.open();
         if(isOpen)
         {
//            QSqlQuery query("SET NAMES gbk");         //本地数据库
            QSqlQuery query("SET NAMES utf8");          //服务器数据库
            return query.exec("select 1 ");
         }
         else
         {
             return false;
         }
    }
    catch (...)
    {
         return false;
    }
    return true;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*加载mysql驱动*/
    QString strLibPath(QDir::toNativeSeparators(QApplication::applicationDirPath())+
                       QDir::separator()+"plugins");
    PRINTLOG(strLibPath);
    qApp->addLibraryPath(strLibPath);
    qApp->addLibraryPath("./plugins");

    if(connectToDataBase())
    {
        MainWindow *w = new MainWindow();
        w->show();
    }
    else
    {
        SettingWidget *s = new SettingWidget();
        s->show();
    }
    return a.exec();
}
