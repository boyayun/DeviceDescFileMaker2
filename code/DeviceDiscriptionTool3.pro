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

TARGET = DeviceDescFileMaker
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    devicetreewidget.cpp \
    devices/functions/functionlistwidget.cpp \
    functionstruct.cpp \
    mypushbutton.cpp \
    devices/functions/parameterwidget.cpp \
    devices/functions/addfunctionswidget.cpp \
    devices/deviceinformationwidget.cpp \
    devices/filegenerater.cpp \
    settingwidget.cpp \
    aboutdialog.cpp \
    deviceinformation.cpp \
    devices/functions/functionselect.cpp

HEADERS  += mainwindow.h \
    config.h \
    devicetreewidget.h \
    devices/functions/functionlistwidget.h \
    functionstruct.h \
    mypushbutton.h \
    devices/functions/parameterwidget.h \
    devices/functions/addfunctionswidget.h \
    devices/deviceinformationwidget.h \
    devices/filegenerater.h \
    settingwidget.h \
    aboutdialog.h \
    deviceinformation.h \
    devicefunction.h \
    devices/functions/functionselect.h

FORMS    += mainwindow.ui \
    devices/functions/parameterwidget.ui \
    devices/functions/addfunctionswidget.ui \
    devices/deviceinformationwidget.ui \
    settingwidget.ui \
    aboutdialog.ui \
    devices/functions/functionselect.ui
UI_DIR = ./UI

RESOURCES += \
    doc.qrc
