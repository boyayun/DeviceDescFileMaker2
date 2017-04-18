/********************************************************************************
** Form generated from reading UI file 'userinformationwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINFORMATIONWIDGET_H
#define UI_USERINFORMATIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserInformationWidget
{
public:
    QGridLayout *gridLayout;
    QLineEdit *userLineEdit;
    QLineEdit *phoneLineEdit;
    QLineEdit *factureIdLineEdit;
    QLineEdit *nameLineEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *UserInformationWidget)
    {
        if (UserInformationWidget->objectName().isEmpty())
            UserInformationWidget->setObjectName(QStringLiteral("UserInformationWidget"));
        UserInformationWidget->resize(400, 300);
        gridLayout = new QGridLayout(UserInformationWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        userLineEdit = new QLineEdit(UserInformationWidget);
        userLineEdit->setObjectName(QStringLiteral("userLineEdit"));

        gridLayout->addWidget(userLineEdit, 0, 1, 1, 1);

        phoneLineEdit = new QLineEdit(UserInformationWidget);
        phoneLineEdit->setObjectName(QStringLiteral("phoneLineEdit"));

        gridLayout->addWidget(phoneLineEdit, 2, 1, 1, 1);

        factureIdLineEdit = new QLineEdit(UserInformationWidget);
        factureIdLineEdit->setObjectName(QStringLiteral("factureIdLineEdit"));

        gridLayout->addWidget(factureIdLineEdit, 3, 1, 1, 1);

        nameLineEdit = new QLineEdit(UserInformationWidget);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        gridLayout->addWidget(nameLineEdit, 1, 1, 1, 1);

        label = new QLabel(UserInformationWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(UserInformationWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(UserInformationWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(UserInformationWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);


        retranslateUi(UserInformationWidget);

        QMetaObject::connectSlotsByName(UserInformationWidget);
    } // setupUi

    void retranslateUi(QWidget *UserInformationWidget)
    {
        UserInformationWidget->setWindowTitle(QApplication::translate("UserInformationWidget", "Form", 0));
        label->setText(QApplication::translate("UserInformationWidget", "User\357\274\232", 0));
        label_2->setText(QApplication::translate("UserInformationWidget", "Name\357\274\232", 0));
        label_3->setText(QApplication::translate("UserInformationWidget", "Phone\357\274\232", 0));
        label_4->setText(QApplication::translate("UserInformationWidget", "FacID\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class UserInformationWidget: public Ui_UserInformationWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINFORMATIONWIDGET_H
