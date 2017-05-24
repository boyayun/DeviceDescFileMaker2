/****************************************************************************
** Meta object code from reading C++ file 'deviceinformationwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../code/devices/deviceinformationwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'deviceinformationwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_deviceInformationWidget_t {
    QByteArrayData data[7];
    char stringdata0[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_deviceInformationWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_deviceInformationWidget_t qt_meta_stringdata_deviceInformationWidget = {
    {
QT_MOC_LITERAL(0, 0, 23), // "deviceInformationWidget"
QT_MOC_LITERAL(1, 24, 16), // "signalSavebutton"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 24), // "deviceInformationWidget*"
QT_MOC_LITERAL(4, 67, 25), // "on_savepushButton_clicked"
QT_MOC_LITERAL(5, 93, 17), // "slotClass1Changed"
QT_MOC_LITERAL(6, 111, 6) // "class1"

    },
    "deviceInformationWidget\0signalSavebutton\0"
    "\0deviceInformationWidget*\0"
    "on_savepushButton_clicked\0slotClass1Changed\0"
    "class1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_deviceInformationWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   36,    2, 0x08 /* Private */,
       5,    1,   37,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool, QMetaType::Int,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void deviceInformationWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        deviceInformationWidget *_t = static_cast<deviceInformationWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalSavebutton((*reinterpret_cast< deviceInformationWidget*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->on_savepushButton_clicked(); break;
        case 2: _t->slotClass1Changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< deviceInformationWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (deviceInformationWidget::*_t)(deviceInformationWidget * , bool , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&deviceInformationWidget::signalSavebutton)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject deviceInformationWidget::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_deviceInformationWidget.data,
      qt_meta_data_deviceInformationWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *deviceInformationWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *deviceInformationWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_deviceInformationWidget.stringdata0))
        return static_cast<void*>(const_cast< deviceInformationWidget*>(this));
    return QDialog::qt_metacast(_clname);
}

int deviceInformationWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void deviceInformationWidget::signalSavebutton(deviceInformationWidget * _t1, bool _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
