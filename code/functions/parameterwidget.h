#ifndef PARAMETERWIDGET_H
#define PARAMETERWIDGET_H

#include <QWidget>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QLineEdit>
#include <QLabel>
#include <QRadioButton>
#include <QIntValidator>
#include <QButtonGroup>
#include <QSpacerItem>
#include <QList>
#include <QComboBox>
#include <QSqlQuery>
#include <QListWidgetItem>
#include <QMessageBox>

#include "functionstruct.h"

class AlarmListWidgetItem : public QListWidgetItem
{
public:
    explicit AlarmListWidgetItem(const int varIndex, QString text,int alarmclass);

    int getVarIndex() const;
    void setVarIndex(int value);


    QString getAlarmString() const;
    void setAlarmString(const QString &value);

    int getAlamClass() const;
    void setAlamClass(int value);

private:
    int varIndex;
    int alamClass;
    QString alarmString;
};

namespace Ui {
class ParameterWidget;
}

class ParameterWidget : public QDialog
{
    Q_OBJECT

public:
    ParameterWidget(FunctionStruct *f,QDialog *parent=0);
    ~ParameterWidget();

private slots:
    void on_SaveButton_clicked();
    void slotVarTypeChanged(int index);
    void slotReturnTypeChanged(int);
    void slotSingleActiongChanged(int);
    void slotOutNumberChanged(int);
    void slotDisEnumNumerChanged(int);
    void slotIsdisplayClicked(bool b);
    void slotDisTypeChanged(int index);
private:
    Ui::ParameterWidget *ui;
    FunctionStruct *functionStruct;

    QList<QLabel*> alarmTextList;
    QList<QLineEdit*> valueEditList,otherParaList,disEditList, statuaList;
    QList<QCheckBox*> enumIsSelectList;
    QList<QLineEdit *> alarmNameEditList,alarmCodeEditList;
    QList<QComboBox *> alarmClassCombox;
    QList<QRadioButton *> defaultRadionList;
    QList<QLineEdit*>outParaList, outParaDscList, outOrderList, outStatusList;
    QList<QRadioButton*>outDefaultList;
    QList<QLineEdit*>disEnumParaList, disEnumStrList, disEnumPicList;
    QList<QCheckBox*> disEnumIsSelectList;

    void init();
    void setCmdPara();
    void setNumberPara();
    void setEunmPara();
    void setAlarmPara();
    void setDatePara();
    void setTimePara();
    void SetDateTimePara();
    void saveDisPara();

    int curVarType = 0;
    int curDisType = 0;

    cmdParameters getCmdParameters();
    numberParamters getNumParameters();
    enumParameters getEnumParameters();
    dateTimeParameters getDataParameters();
    dateTimeParameters getTimeParameters();
    dateTimeParameters getDatetimeParas();
    _varOutType getOutParas();

    alarmParameters getAlarmPara();
};

#endif // PARAMETERWIDGET_H
