#ifndef CONFIG
#define CONFIG

#include <QDebug>

#pragma execution_character_set("utf-8")

#define QDEBUG() qDebug()<<__FILE__<<__LINE__
#define PRINTLOG(x) qDebug()<<__FILE__<<__LINE__<<(x);

class config
{
public:
    config();

    /*字符串转byteArray*/
    static QByteArray strTobyteArray(const QString &str)
    {
        QString strtemp = str;
        QByteArray array;
        if(strtemp.length() % 2 != 0)
        {
            strtemp.insert(0, "0");
        }
        for(int i=0; i<strtemp.length(); i+=2)
        {
            array.append(strtemp.mid(i, 2).toInt(NULL, 16));
        }
        return array;
    }

    /*int转字符串*/
    /*value：要转的值， len: 转后的长度， b：0转成10进制，1转成16进制*/
    static QString getStr(const int &value, const int &len, const bool &b)
    {
        QString str;
        if(b)
        {
            str = QString::number(value, 16).toUpper();
        }
        else
        {
            str = QString::number(value, 10).toUpper();
        }
        int tmplen = str.length();
        if(len > tmplen)
        {
            for(int i=0; i<(len - tmplen); i++)
            {
                str.insert(0, "0");
            }
        }
        qDebug()<<__FILE__<<__LINE__<<"str"<<str;
        return  str;
    }

};
#endif // CONFIG

