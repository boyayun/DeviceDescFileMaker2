#ifndef FUNCTIONLISTWIDGET_H
#define FUNCTIONLISTWIDGET_H

#include <QObject>
#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QSqlQuery>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QStringList>
#include <QSqlResult>
#include <QList>
#include <QPushButton>
#include <QComboBox>
#include <QHeaderView>
#include <QFileDialog>

#include "config.h"
#include "functionstruct.h"
#include "editbutton.h"
#include "mypushbutton.h"
#include "devices/functions/parameterwidget.h"
#include "devices/functions/addfunctionswidget.h"
#include "devices/filegenerater.h"

#define MANUFACTUREIDLEN 13 //厂商ID长度
#define MODELIDLEN   6  // 型号ID长度

#define COMMAND_COLUMN 0
#define NAME_COLUMN  1
#define DIRECTION_COLUMN  2
#define OPERATION_COLUMN 3


#define VARINDEXPOWER   31
#define VARINDEXWARNING 999999

class FunctionListWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FunctionListWidget(QWidget *parent = 0);
private:
    void init();
    void updateFunctionUi();

    QVBoxLayout *mainLayout;
    QHBoxLayout *operationLayout;
    QTableWidget *tableWidget;
    QList <FunctionStruct *> functionList;
    QPushButton *addFunctionButton;
    QPushButton *saveFunctionButton;
    QPushButton *upmoveButton;
    QPushButton *downmoveButton;
    QPushButton *createButton;
    QPushButton *deleteButton;
    AddFunctionsWidget *addFunctionWidget;
    ParameterWidget *parameterWidget;
    DeviceInformation *h;

    int id;
    void insertAFunction(FunctionStruct * f);

    bool upDateFunctionToDataBase(FunctionStruct *f);
    bool insertFunctionToDataBase(FunctionStruct *f);
    bool deleteFunctionFromDataBase();

    QTableWidgetItem * getNewTableWidgetItem(FunctionStruct *f);


signals:

    void signalParameters(FunctionStruct *f);

    void signalSavedFunctionlist(int,QList<FunctionStruct*>);

public slots:
    void slotUpdateDeviceID(DeviceInformation *deviceinfo, int id);

    void slotEditClicked(FunctionStruct *f);

private slots:
    void slotAdd(bool);

    void slotSaveFunctions(bool);

    void slotAddFunctions(QList<FunctionStruct*> funList);

    void slotUpMovedClicked(bool);

    void slotDownMovedClicked(bool);

    void slotCreateClicked(bool);

    void slotDeleteClicked(bool);

    void slotCellClicked(int row, int column);
};

#endif // FUNCTIONLISTWIDGET_H
