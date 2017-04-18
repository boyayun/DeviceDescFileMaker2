/********************************************************************************
** Form generated from reading UI file 'adddevicewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDEVICEWIDGET_H
#define UI_ADDDEVICEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddDeviceWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *deviceNameLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *DeviceModelLineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QComboBox *class1comboBox;
    QComboBox *class2comboBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *ManufactureIDLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLineEdit *urllineEdit;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *updatecheckBox;
    QCheckBox *synccheckBox;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer;
    QPushButton *createpushButton;

    void setupUi(QDialog *AddDeviceWidget)
    {
        if (AddDeviceWidget->objectName().isEmpty())
            AddDeviceWidget->setObjectName(QStringLiteral("AddDeviceWidget"));
        AddDeviceWidget->resize(400, 300);
        verticalLayout = new QVBoxLayout(AddDeviceWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(AddDeviceWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        deviceNameLineEdit = new QLineEdit(AddDeviceWidget);
        deviceNameLineEdit->setObjectName(QStringLiteral("deviceNameLineEdit"));

        horizontalLayout->addWidget(deviceNameLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(AddDeviceWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        DeviceModelLineEdit = new QLineEdit(AddDeviceWidget);
        DeviceModelLineEdit->setObjectName(QStringLiteral("DeviceModelLineEdit"));

        horizontalLayout_3->addWidget(DeviceModelLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_3 = new QLabel(AddDeviceWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_5->addWidget(label_3);

        class1comboBox = new QComboBox(AddDeviceWidget);
        class1comboBox->setObjectName(QStringLiteral("class1comboBox"));

        horizontalLayout_5->addWidget(class1comboBox);

        class2comboBox = new QComboBox(AddDeviceWidget);
        class2comboBox->setObjectName(QStringLiteral("class2comboBox"));

        horizontalLayout_5->addWidget(class2comboBox);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(AddDeviceWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        ManufactureIDLineEdit = new QLineEdit(AddDeviceWidget);
        ManufactureIDLineEdit->setObjectName(QStringLiteral("ManufactureIDLineEdit"));

        horizontalLayout_4->addWidget(ManufactureIDLineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_5 = new QLabel(AddDeviceWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        urllineEdit = new QLineEdit(AddDeviceWidget);
        urllineEdit->setObjectName(QStringLiteral("urllineEdit"));

        horizontalLayout_2->addWidget(urllineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        updatecheckBox = new QCheckBox(AddDeviceWidget);
        updatecheckBox->setObjectName(QStringLiteral("updatecheckBox"));

        horizontalLayout_6->addWidget(updatecheckBox);

        synccheckBox = new QCheckBox(AddDeviceWidget);
        synccheckBox->setObjectName(QStringLiteral("synccheckBox"));

        horizontalLayout_6->addWidget(synccheckBox);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        createpushButton = new QPushButton(AddDeviceWidget);
        createpushButton->setObjectName(QStringLiteral("createpushButton"));

        horizontalLayout_7->addWidget(createpushButton);


        verticalLayout->addLayout(horizontalLayout_7);


        retranslateUi(AddDeviceWidget);

        QMetaObject::connectSlotsByName(AddDeviceWidget);
    } // setupUi

    void retranslateUi(QDialog *AddDeviceWidget)
    {
        AddDeviceWidget->setWindowTitle(QApplication::translate("AddDeviceWidget", "Dialog", 0));
        label->setText(QApplication::translate("AddDeviceWidget", "\350\256\276\345\244\207\345\220\215\347\247\260\357\274\232", 0));
        label_2->setText(QApplication::translate("AddDeviceWidget", "\350\256\276\345\244\207\345\236\213\345\217\267\357\274\232", 0));
        label_3->setText(QApplication::translate("AddDeviceWidget", "\350\256\276\345\244\207\347\261\273\345\236\213\357\274\232", 0));
        label_4->setText(QApplication::translate("AddDeviceWidget", "\345\216\202\345\225\206\347\274\226\347\240\201\357\274\232", 0));
        label_5->setText(QApplication::translate("AddDeviceWidget", "URL \345\234\260\345\235\200\357\274\232", 0));
        updatecheckBox->setText(QApplication::translate("AddDeviceWidget", "\345\234\250\347\272\277\345\215\207\347\272\247", 0));
        synccheckBox->setText(QApplication::translate("AddDeviceWidget", "\346\227\266\351\227\264\345\220\214\346\255\245", 0));
        createpushButton->setText(QApplication::translate("AddDeviceWidget", "\345\256\214\346\210\220", 0));
    } // retranslateUi

};

namespace Ui {
    class AddDeviceWidget: public Ui_AddDeviceWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDEVICEWIDGET_H
