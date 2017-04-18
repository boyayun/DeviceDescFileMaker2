/********************************************************************************
** Form generated from reading UI file 'deviceinformationwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICEINFORMATIONWIDGET_H
#define UI_DEVICEINFORMATIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_deviceInformationWidget
{
public:
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_5;
    QComboBox *applyUserBox;
    QLabel *label_8;
    QComboBox *linkBox;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QLineEdit *modelIDlineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QComboBox *primaryClass;
    QComboBox *minorClass;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label;
    QLineEdit *manufactureIDLineedit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *urllineEdit;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *updateCheckbox;
    QCheckBox *synCheckBox;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *sleepCheckBox;
    QCheckBox *otherparaCheckBox;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *savepushButton;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *namelineEdit;
    QHBoxLayout *horizontalLayout_11;
    QLabel *lable_1;
    QLineEdit *fileVerEdit;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *deviceInformationWidget)
    {
        if (deviceInformationWidget->objectName().isEmpty())
            deviceInformationWidget->setObjectName(QStringLiteral("deviceInformationWidget"));
        deviceInformationWidget->resize(400, 384);
        deviceInformationWidget->setStyleSheet(QStringLiteral("border-color: rgb(0, 0, 0);"));
        gridLayout_2 = new QGridLayout(deviceInformationWidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        frame = new QFrame(deviceInformationWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setStyleSheet(QStringLiteral("border-color: rgb(0, 0, 0);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_10->addWidget(label_5);

        applyUserBox = new QComboBox(frame);
        applyUserBox->setObjectName(QStringLiteral("applyUserBox"));

        horizontalLayout_10->addWidget(applyUserBox);

        label_8 = new QLabel(frame);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_10->addWidget(label_8);

        linkBox = new QComboBox(frame);
        linkBox->setObjectName(QStringLiteral("linkBox"));

        horizontalLayout_10->addWidget(linkBox);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_10, 2, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_8->addWidget(label_7);

        modelIDlineEdit = new QLineEdit(frame);
        modelIDlineEdit->setObjectName(QStringLiteral("modelIDlineEdit"));

        horizontalLayout_8->addWidget(modelIDlineEdit);


        gridLayout->addLayout(horizontalLayout_8, 3, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        primaryClass = new QComboBox(frame);
        primaryClass->setObjectName(QStringLiteral("primaryClass"));

        horizontalLayout_3->addWidget(primaryClass);

        minorClass = new QComboBox(frame);
        minorClass->setObjectName(QStringLiteral("minorClass"));

        horizontalLayout_3->addWidget(minorClass);


        gridLayout->addLayout(horizontalLayout_3, 4, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_7->addWidget(label);

        manufactureIDLineedit = new QLineEdit(frame);
        manufactureIDLineedit->setObjectName(QStringLiteral("manufactureIDLineedit"));

        horizontalLayout_7->addWidget(manufactureIDLineedit);


        gridLayout->addLayout(horizontalLayout_7, 5, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_6->addWidget(label_6);

        urllineEdit = new QLineEdit(frame);
        urllineEdit->setObjectName(QStringLiteral("urllineEdit"));

        horizontalLayout_6->addWidget(urllineEdit);


        gridLayout->addLayout(horizontalLayout_6, 6, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        updateCheckbox = new QCheckBox(frame);
        updateCheckbox->setObjectName(QStringLiteral("updateCheckbox"));

        horizontalLayout_5->addWidget(updateCheckbox);

        synCheckBox = new QCheckBox(frame);
        synCheckBox->setObjectName(QStringLiteral("synCheckBox"));

        horizontalLayout_5->addWidget(synCheckBox);


        gridLayout->addLayout(horizontalLayout_5, 7, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        sleepCheckBox = new QCheckBox(frame);
        sleepCheckBox->setObjectName(QStringLiteral("sleepCheckBox"));

        horizontalLayout_4->addWidget(sleepCheckBox);

        otherparaCheckBox = new QCheckBox(frame);
        otherparaCheckBox->setObjectName(QStringLiteral("otherparaCheckBox"));

        horizontalLayout_4->addWidget(otherparaCheckBox);


        gridLayout->addLayout(horizontalLayout_4, 8, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        savepushButton = new QPushButton(frame);
        savepushButton->setObjectName(QStringLiteral("savepushButton"));

        horizontalLayout_9->addWidget(savepushButton);


        gridLayout->addLayout(horizontalLayout_9, 9, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        namelineEdit = new QLineEdit(frame);
        namelineEdit->setObjectName(QStringLiteral("namelineEdit"));

        horizontalLayout->addWidget(namelineEdit);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        lable_1 = new QLabel(frame);
        lable_1->setObjectName(QStringLiteral("lable_1"));

        horizontalLayout_11->addWidget(lable_1);

        fileVerEdit = new QLineEdit(frame);
        fileVerEdit->setObjectName(QStringLiteral("fileVerEdit"));

        horizontalLayout_11->addWidget(fileVerEdit);


        gridLayout->addLayout(horizontalLayout_11, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 10, 0, 1, 1);


        gridLayout_2->addWidget(frame, 0, 0, 1, 1);

#ifndef QT_NO_SHORTCUT
        label_5->setBuddy(applyUserBox);
        label_8->setBuddy(linkBox);
#endif // QT_NO_SHORTCUT

        retranslateUi(deviceInformationWidget);

        QMetaObject::connectSlotsByName(deviceInformationWidget);
    } // setupUi

    void retranslateUi(QWidget *deviceInformationWidget)
    {
        deviceInformationWidget->setWindowTitle(QApplication::translate("deviceInformationWidget", "Form", Q_NULLPTR));
        label_5->setText(QApplication::translate("deviceInformationWidget", "\351\200\202\347\224\250\347\224\250\346\210\267\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("deviceInformationWidget", "\351\200\232\350\256\257\351\223\276\350\267\257\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("deviceInformationWidget", "\345\236\213\345\217\267\344\273\243\347\240\201\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("deviceInformationWidget", "\350\256\276\345\244\207\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("deviceInformationWidget", "\345\216\202\345\225\206\347\274\226\347\240\201\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("deviceInformationWidget", "URL \345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        updateCheckbox->setText(QApplication::translate("deviceInformationWidget", "\346\230\257\345\220\246\346\224\257\346\214\201\345\234\250\347\272\277\345\215\207\347\272\247", Q_NULLPTR));
        synCheckBox->setText(QApplication::translate("deviceInformationWidget", "\346\224\257\346\214\201\346\227\266\351\227\264\345\220\214\346\255\245", Q_NULLPTR));
        sleepCheckBox->setText(QApplication::translate("deviceInformationWidget", "\344\274\221\347\234\240", Q_NULLPTR));
        otherparaCheckBox->setText(QApplication::translate("deviceInformationWidget", "\347\254\254\344\270\211\346\226\271\345\205\274\345\256\271\350\256\276\345\244\207\345\234\260\345\235\200", Q_NULLPTR));
        savepushButton->setText(QApplication::translate("deviceInformationWidget", "\344\277\235\345\255\230", Q_NULLPTR));
        label_2->setText(QApplication::translate("deviceInformationWidget", "\350\256\276\345\244\207\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        lable_1->setText(QApplication::translate("deviceInformationWidget", "\346\226\207\344\273\266\347\211\210\346\234\254\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class deviceInformationWidget: public Ui_deviceInformationWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICEINFORMATIONWIDGET_H
