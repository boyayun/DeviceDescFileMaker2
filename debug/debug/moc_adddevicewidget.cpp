/****************************************************************************
** Meta object code from reading C++ file 'adddevicewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../code/devices/adddevicewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adddevicewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AddDeviceWidget_t {
    QByteArrayData data[5];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AddDeviceWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AddDeviceWidget_t qt_meta_stringdata_AddDeviceWidget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "AddDeviceWidget"
QT_MOC_LITERAL(1, 16, 20), // "signalUpdateTreeList"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 17), // "slotClass1Changed"
QT_MOC_LITERAL(4, 56, 27) // "on_createpushButton_clicked"

    },
    "AddDeviceWidget\0signalUpdateTreeList\0"
    "\0slotClass1Changed\0on_createpushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddDeviceWidget[] = {

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
       1,    0,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   30,    2, 0x08 /* Private */,
       4,    0,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void AddDeviceWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AddDeviceWidget *_t = static_cast<AddDeviceWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalUpdateTreeList(); break;
        case 1: _t->slotClass1Changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_createpushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AddDeviceWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AddDeviceWidget::signalUpdateTreeList)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject AddDeviceWidget::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AddDeviceWidget.data,
      qt_meta_data_AddDeviceWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AddDeviceWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddDeviceWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AddDeviceWidget.stringdata0))
        return static_cast<void*>(const_cast< AddDeviceWidget*>(this));
    return QDialog::qt_metacast(_clname);
}

int AddDeviceWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void AddDeviceWidget::signalUpdateTreeList()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
