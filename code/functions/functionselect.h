#ifndef FUNCTIONSELECT_H
#define FUNCTIONSELECT_H

#include <QDialog>
#include <QSqlQuery>
#include <QDebug>
#include <QCheckBox>
#include <QList>
#include <QSplitter>
#include <QLayout>
#include <QEvent>
#include <QCloseEvent>

namespace Ui {
class functionselect;
}

class MycheckBox : public QCheckBox
{
    Q_OBJECT
public:
    explicit MycheckBox(const QString &text, const int id);
    ~MycheckBox();

private slots:
    void slotCheck(bool);

public:
    bool isSelect;
    int id;
};

class Functionselect : public QDialog
{
    Q_OBJECT

public:
    explicit Functionselect(QWidget *parent = 0);

    ~Functionselect();

signals:
    void signalSelectedFunction(QList<int>);

private:
    QCheckBox *check;
    Ui::functionselect *ui;

    QLayout *checkLayout;

    QList<int>funSelectedList;
    QList<MycheckBox*> functionClassList;
    void init();
    void accept();
    void reject();
    void closeEvent(QCloseEvent *event);
};

#endif // FUNCTIONSELECT_H
