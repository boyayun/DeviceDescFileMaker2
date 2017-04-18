/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_3;

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName(QStringLiteral("AboutDialog"));
        AboutDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(AboutDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(AboutDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QString::fromUtf8("font: 75 20pt \"\345\256\213\344\275\223\";\n"
"color: rgb(0, 0, 255);"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(AboutDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_4 = new QLabel(AboutDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        label_3 = new QLabel(AboutDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setCursor(QCursor(Qt::PointingHandCursor));
        label_3->setStyleSheet(QStringLiteral("color: rgb(0, 85, 255);"));

        verticalLayout->addWidget(label_3);


        retranslateUi(AboutDialog);

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QApplication::translate("AboutDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("AboutDialog", " \350\256\276\345\244\207\346\217\217\350\277\260\346\226\207\344\273\266\347\224\237\346\210\220\345\267\245\345\205\267", Q_NULLPTR));
        label_2->setText(QApplication::translate("AboutDialog", "\347\211\210\346\234\254\357\274\2322.0", Q_NULLPTR));
        label_4->setText(QApplication::translate("AboutDialog", "\344\275\234\350\200\205\357\274\232\346\255\246\346\234\211\344\272\256\343\200\202", Q_NULLPTR));
        label_3->setText(QApplication::translate("AboutDialog", "\302\251\345\214\227\344\272\254\346\231\272\350\266\243\345\256\266\347\247\221\346\212\200\346\234\211\351\231\220\345\205\254\345\217\270\343\200\202\344\277\235\347\225\231\346\211\200\346\234\211\346\235\203\345\210\251\343\200\202", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
