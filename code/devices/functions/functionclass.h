#ifndef FUNCTIONCLASS_H
#define FUNCTIONCLASS_H

#include <QWidget>
#include <QDialog>

namespace Ui {
class functionclass;
}

class functionclass : public QDialog
{
    Q_OBJECT

public:
    explicit functionclass(QDialog *parent = 0);
    ~functionclass();

private:
    Ui::functionclass *ui;
};

#endif // FUNCTIONCLASS_H
