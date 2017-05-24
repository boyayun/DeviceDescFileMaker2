#ifndef ADDFUNCTIONSWIDGET_H
#define ADDFUNCTIONSWIDGET_H

#include <QWidget>
#include <QDialog>
#include <QSqlQuery>
#include <QListWidgetItem>
#include <QList>

#include "functionstruct.h"
#include "functionselect.h"
#include "config.h"

class MyListWidgetItem : public QListWidgetItem
{
public:
    explicit MyListWidgetItem(const QString text,int varIndex);
    int getVarIndex() const;
    ~MyListWidgetItem();

private:
    int varIndex;
};


namespace Ui {
class AddFunctionsWidget;
}

#define VARINDEXPOWER   31
#define VARINDEXWARNING 999999

class AddFunctionsWidget : public QDialog
{
    Q_OBJECT
public:
    explicit AddFunctionsWidget(QList<FunctionStruct *> list, QDialog *parent = 0);
    ~AddFunctionsWidget();
    QList<FunctionStruct*> getFunctionList();

private slots:
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_searchlineEdit_textChanged(const QString &arg1);

    void on_addpushButton_clicked();

    void on_cancelpushButton_clicked();

    void on_selectlistWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_selectFunButton_clicked();

    void slotFunmenu(QList<int>);

private:
    Ui::AddFunctionsWidget *ui;
    int deviceclass1;
    QList<FunctionStruct*> funlist;
    QList<MyListWidgetItem *> listItemList;
    QList<MyListWidgetItem *> selectedListItemList;

    void init();
signals:
    void signalAddFunctions(QList<FunctionStruct*>);
};

#endif // ADDFUNCTIONSWIDGET_H
