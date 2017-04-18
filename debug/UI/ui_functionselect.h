/********************************************************************************
** Form generated from reading UI file 'functionselect.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FUNCTIONSELECT_H
#define UI_FUNCTIONSELECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_functionselect
{
public:
    QGridLayout *gridLayout;
    QGridLayout *checkLayout;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *functionselect)
    {
        if (functionselect->objectName().isEmpty())
            functionselect->setObjectName(QStringLiteral("functionselect"));
        functionselect->setEnabled(true);
        functionselect->resize(297, 198);
        functionselect->setSizeGripEnabled(false);
        gridLayout = new QGridLayout(functionselect);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setHorizontalSpacing(6);
        gridLayout->setContentsMargins(9, 9, -1, -1);
        checkLayout = new QGridLayout();
        checkLayout->setObjectName(QStringLiteral("checkLayout"));

        gridLayout->addLayout(checkLayout, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(functionselect);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 0, 1, 1, 1);

        gridLayout->setColumnStretch(0, 5);
        gridLayout->setColumnStretch(1, 1);

        retranslateUi(functionselect);
        QObject::connect(buttonBox, SIGNAL(accepted()), functionselect, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), functionselect, SLOT(reject()));

        QMetaObject::connectSlotsByName(functionselect);
    } // setupUi

    void retranslateUi(QDialog *functionselect)
    {
        functionselect->setWindowTitle(QApplication::translate("functionselect", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class functionselect: public Ui_functionselect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FUNCTIONSELECT_H
