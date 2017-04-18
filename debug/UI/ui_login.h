/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *userNameLedt;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *passwdLedt;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *cancleBtn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *loginBtn;
    QPushButton *registerpushButton;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(224, 158);
        gridLayout = new QGridLayout(Login);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(Login);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        userNameLedt = new QLineEdit(Login);
        userNameLedt->setObjectName(QStringLiteral("userNameLedt"));
        userNameLedt->setMaxLength(20);
        userNameLedt->setFrame(true);

        horizontalLayout->addWidget(userNameLedt);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(Login);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        passwdLedt = new QLineEdit(Login);
        passwdLedt->setObjectName(QStringLiteral("passwdLedt"));
        passwdLedt->setMaxLength(20);
        passwdLedt->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(passwdLedt);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        label = new QLabel(Login);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        cancleBtn = new QPushButton(Login);
        cancleBtn->setObjectName(QStringLiteral("cancleBtn"));

        horizontalLayout_4->addWidget(cancleBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        loginBtn = new QPushButton(Login);
        loginBtn->setObjectName(QStringLiteral("loginBtn"));

        horizontalLayout_4->addWidget(loginBtn);


        verticalLayout->addLayout(horizontalLayout_4);

        registerpushButton = new QPushButton(Login);
        registerpushButton->setObjectName(QStringLiteral("registerpushButton"));
        registerpushButton->setAutoDefault(false);

        verticalLayout->addWidget(registerpushButton);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        QWidget::setTabOrder(userNameLedt, passwdLedt);
        QWidget::setTabOrder(passwdLedt, loginBtn);
        QWidget::setTabOrder(loginBtn, cancleBtn);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Dialog", 0));
        label_2->setText(QApplication::translate("Login", "\347\224\250\346\210\267\345\220\215\357\274\232", 0));
        userNameLedt->setText(QApplication::translate("Login", "admin", 0));
        label_3->setText(QApplication::translate("Login", "\345\257\206  \347\240\201\357\274\232", 0));
        passwdLedt->setText(QApplication::translate("Login", "123456", 0));
        label->setText(QString());
        cancleBtn->setText(QApplication::translate("Login", "\345\217\226\346\266\210", 0));
        loginBtn->setText(QApplication::translate("Login", "\347\231\273\345\275\225", 0));
        registerpushButton->setText(QApplication::translate("Login", "\346\263\250\345\206\214", 0));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
