#-------------------------------------------------
#
# Project created by QtCreator 2016-04-21T10:16:11
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += network
qtHaveModule(printsupport): QT += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DeviceDescFileMaker2.0
TEMPLATE = app

RC_ICONS = devout.ico

SOURCES += main.cpp\
        mainwindow.cpp \
    settingwidget.cpp \
    aboutdialog.cpp \
    devices/deviceinformationwidget.cpp\
    devices/filegenerater.cpp\
    devices/deviceinformation.cpp \
    devices/devicetreewidget.cpp \
    functions/addfunctionswidget.cpp \
    functions/functionlistwidget.cpp \
    functions/functionselect.cpp \
    functions/functionstruct.cpp \
    functions/mypushbutton.cpp \
    functions/parameterwidget.cpp

HEADERS  += mainwindow.h \
    settingwidget.h \
    aboutdialog.h \
    config.h \
    devices/deviceinformationwidget.h \
    devices/filegenerater.h \
    devices/deviceinformation.h \
    devices/devicetreewidget.h \
    functions/addfunctionswidget.h \
    functions/functionlistwidget.h \
    functions/functionselect.h \
    functions/functionstruct.h \
    functions/mypushbutton.h \
    functions/parameterwidget.h

FORMS    += mainwindow.ui \
    settingwidget.ui \
    aboutdialog.ui \
    devices/deviceinformationwidget.ui \
    functions/addfunctionswidget.ui \
    functions/functionselect.ui \
    functions/parameterwidget.ui
UI_DIR = ./UI

RESOURCES += \
    doc.qrc\
