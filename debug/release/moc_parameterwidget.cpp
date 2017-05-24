/****************************************************************************
** Meta object code from reading C++ file 'parameterwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../code/functions/parameterwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'parameterwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ParameterWidget_t {
    QByteArrayData data[12];
    char stringdata0[198];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ParameterWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ParameterWidget_t qt_meta_stringdata_ParameterWidget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ParameterWidget"
QT_MOC_LITERAL(1, 16, 21), // "on_SaveButton_clicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 18), // "slotVarTypeChanged"
QT_MOC_LITERAL(4, 58, 5), // "index"
QT_MOC_LITERAL(5, 64, 21), // "slotReturnTypeChanged"
QT_MOC_LITERAL(6, 86, 24), // "slotSingleActiongChanged"
QT_MOC_LITERAL(7, 111, 20), // "slotOutNumberChanged"
QT_MOC_LITERAL(8, 132, 23), // "slotDisEnumNumerChanged"
QT_MOC_LITERAL(9, 156, 20), // "slotIsdisplayClicked"
QT_MOC_LITERAL(10, 177, 1), // "b"
QT_MOC_LITERAL(11, 179, 18) // "slotDisTypeChanged"

    },
    "ParameterWidget\0on_SaveButton_clicked\0"
    "\0slotVarTypeChanged\0index\0"
    "slotReturnTypeChanged\0slotSingleActiongChanged\0"
    "slotOutNumberChanged\0slotDisEnumNumerChanged\0"
    "slotIsdisplayClicked\0b\0slotDisTypeChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ParameterWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    1,   55,    2, 0x08 /* Private */,
       5,    1,   58,    2, 0x08 /* Private */,
       6,    1,   61,    2, 0x08 /* Private */,
       7,    1,   64,    2, 0x08 /* Private */,
       8,    1,   67,    2, 0x08 /* Private */,
       9,    1,   70,    2, 0x08 /* Private */,
      11,    1,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Int,    4,

       0        // eod
};

void ParameterWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ParameterWidget *_t = static_cast<ParameterWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_SaveButton_clicked(); break;
        case 1: _t->slotVarTypeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->slotReturnTypeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->slotSingleActiongChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->slotOutNumberChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->slotDisEnumNumerChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->slotIsdisplayClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->slotDisTypeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ParameterWidget::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ParameterWidget.data,
      qt_meta_data_ParameterWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ParameterWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ParameterWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ParameterWidget.stringdata0))
        return static_cast<void*>(const_cast< ParameterWidget*>(this));
    return QDialog::qt_metacast(_clname);
}

int ParameterWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
