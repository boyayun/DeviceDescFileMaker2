/********************************************************************************
** Form generated from reading UI file 'functionclass.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FUNCTIONCLASS_H
#define UI_FUNCTIONCLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_functionclass
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *functionclass)
    {
        if (functionclass->objectName().isEmpty())
            functionclass->setObjectName(QStringLiteral("functionclass"));
        functionclass->resize(400, 300);
        pushButton = new QPushButton(functionclass);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(310, 10, 75, 23));
        pushButton_2 = new QPushButton(functionclass);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(310, 50, 75, 23));

        retranslateUi(functionclass);

        QMetaObject::connectSlotsByName(functionclass);
    } // setupUi

    void retranslateUi(QWidget *functionclass)
    {
        functionclass->setWindowTitle(QApplication::translate("functionclass", "Form", 0));
        pushButton->setText(QApplication::translate("functionclass", "OK", 0));
        pushButton_2->setText(QApplication::translate("functionclass", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class functionclass: public Ui_functionclass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FUNCTIONCLASS_H
