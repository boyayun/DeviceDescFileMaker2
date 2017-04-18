/********************************************************************************
** Form generated from reading UI file 'addfunctionswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFUNCTIONSWIDGET_H
#define UI_ADDFUNCTIONSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddFunctionsWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *searchlineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;
    QListWidget *selectlistWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *selectFunButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelpushButton;
    QPushButton *addpushButton;

    void setupUi(QWidget *AddFunctionsWidget)
    {
        if (AddFunctionsWidget->objectName().isEmpty())
            AddFunctionsWidget->setObjectName(QStringLiteral("AddFunctionsWidget"));
        AddFunctionsWidget->resize(400, 305);
        gridLayout = new QGridLayout(AddFunctionsWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(AddFunctionsWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        searchlineEdit = new QLineEdit(AddFunctionsWidget);
        searchlineEdit->setObjectName(QStringLiteral("searchlineEdit"));

        gridLayout->addWidget(searchlineEdit, 0, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(AddFunctionsWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        label = new QLabel(AddFunctionsWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        listWidget = new QListWidget(AddFunctionsWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        horizontalLayout->addWidget(listWidget);

        selectlistWidget = new QListWidget(AddFunctionsWidget);
        selectlistWidget->setObjectName(QStringLiteral("selectlistWidget"));

        horizontalLayout->addWidget(selectlistWidget);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        selectFunButton = new QPushButton(AddFunctionsWidget);
        selectFunButton->setObjectName(QStringLiteral("selectFunButton"));

        horizontalLayout_2->addWidget(selectFunButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        cancelpushButton = new QPushButton(AddFunctionsWidget);
        cancelpushButton->setObjectName(QStringLiteral("cancelpushButton"));

        horizontalLayout_2->addWidget(cancelpushButton);

        addpushButton = new QPushButton(AddFunctionsWidget);
        addpushButton->setObjectName(QStringLiteral("addpushButton"));

        horizontalLayout_2->addWidget(addpushButton);


        gridLayout->addLayout(horizontalLayout_2, 3, 0, 1, 2);


        retranslateUi(AddFunctionsWidget);

        QMetaObject::connectSlotsByName(AddFunctionsWidget);
    } // setupUi

    void retranslateUi(QWidget *AddFunctionsWidget)
    {
        AddFunctionsWidget->setWindowTitle(QApplication::translate("AddFunctionsWidget", "Form", Q_NULLPTR));
        label_3->setText(QApplication::translate("AddFunctionsWidget", "\346\220\234\347\264\242", Q_NULLPTR));
        label_2->setText(QApplication::translate("AddFunctionsWidget", "\345\276\205\346\267\273\345\212\240\345\212\237\350\203\275\345\210\227\350\241\250:", Q_NULLPTR));
        label->setText(QApplication::translate("AddFunctionsWidget", "\345\267\262\346\267\273\345\212\240\345\212\237\350\203\275\345\210\227\350\241\250: ", Q_NULLPTR));
        selectFunButton->setText(QApplication::translate("AddFunctionsWidget", "\351\200\211\346\213\251\345\212\237\350\203\275", Q_NULLPTR));
        cancelpushButton->setText(QApplication::translate("AddFunctionsWidget", "\345\217\226\346\266\210", Q_NULLPTR));
        addpushButton->setText(QApplication::translate("AddFunctionsWidget", "\346\267\273\345\212\240", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddFunctionsWidget: public Ui_AddFunctionsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFUNCTIONSWIDGET_H
