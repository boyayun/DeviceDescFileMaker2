/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_N;
    QAction *action_S;
    QAction *actionManage;
    QAction *action_Q;
    QAction *action_H;
    QAction *action;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu_M;
    QMenu *menu_2;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(772, 512);
        action_N = new QAction(MainWindow);
        action_N->setObjectName(QStringLiteral("action_N"));
        action_S = new QAction(MainWindow);
        action_S->setObjectName(QStringLiteral("action_S"));
        actionManage = new QAction(MainWindow);
        actionManage->setObjectName(QStringLiteral("actionManage"));
        action_Q = new QAction(MainWindow);
        action_Q->setObjectName(QStringLiteral("action_Q"));
        action_H = new QAction(MainWindow);
        action_H->setObjectName(QStringLiteral("action_H"));
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 772, 23));
        menu_M = new QMenu(menuBar);
        menu_M->setObjectName(QStringLiteral("menu_M"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menu_M->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu_M->addAction(action_N);
        menu_M->addAction(action_Q);
        menu_2->addAction(action);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        action_N->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\357\274\210&N\357\274\211", Q_NULLPTR));
        action_S->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\357\274\210&S\357\274\211", Q_NULLPTR));
        actionManage->setText(QApplication::translate("MainWindow", "Manage", Q_NULLPTR));
        action_Q->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272\357\274\210&Q)", Q_NULLPTR));
        action_H->setText(QApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", Q_NULLPTR));
        action->setText(QApplication::translate("MainWindow", "\344\275\234\350\200\205", Q_NULLPTR));
        menu_M->setTitle(QApplication::translate("MainWindow", "\350\217\234\345\215\225\357\274\210&M\357\274\211", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\345\205\263\344\272\216", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
