/****************************************************************************
** Meta object code from reading C++ file 'functionlistwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../code/functions/functionlistwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'functionlistwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FunctionListWidget_t {
    QByteArrayData data[23];
    char stringdata0[324];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FunctionListWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FunctionListWidget_t qt_meta_stringdata_FunctionListWidget = {
    {
QT_MOC_LITERAL(0, 0, 18), // "FunctionListWidget"
QT_MOC_LITERAL(1, 19, 16), // "signalParameters"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 15), // "FunctionStruct*"
QT_MOC_LITERAL(4, 53, 1), // "f"
QT_MOC_LITERAL(5, 55, 23), // "signalSavedFunctionlist"
QT_MOC_LITERAL(6, 79, 22), // "QList<FunctionStruct*>"
QT_MOC_LITERAL(7, 102, 18), // "slotUpdateDeviceID"
QT_MOC_LITERAL(8, 121, 18), // "DeviceInformation*"
QT_MOC_LITERAL(9, 140, 10), // "deviceinfo"
QT_MOC_LITERAL(10, 151, 2), // "id"
QT_MOC_LITERAL(11, 154, 15), // "slotEditClicked"
QT_MOC_LITERAL(12, 170, 7), // "slotAdd"
QT_MOC_LITERAL(13, 178, 17), // "slotSaveFunctions"
QT_MOC_LITERAL(14, 196, 16), // "slotAddFunctions"
QT_MOC_LITERAL(15, 213, 7), // "funList"
QT_MOC_LITERAL(16, 221, 18), // "slotUpMovedClicked"
QT_MOC_LITERAL(17, 240, 20), // "slotDownMovedClicked"
QT_MOC_LITERAL(18, 261, 17), // "slotCreateClicked"
QT_MOC_LITERAL(19, 279, 17), // "slotDeleteClicked"
QT_MOC_LITERAL(20, 297, 15), // "slotCellClicked"
QT_MOC_LITERAL(21, 313, 3), // "row"
QT_MOC_LITERAL(22, 317, 6) // "column"

    },
    "FunctionListWidget\0signalParameters\0"
    "\0FunctionStruct*\0f\0signalSavedFunctionlist\0"
    "QList<FunctionStruct*>\0slotUpdateDeviceID\0"
    "DeviceInformation*\0deviceinfo\0id\0"
    "slotEditClicked\0slotAdd\0slotSaveFunctions\0"
    "slotAddFunctions\0funList\0slotUpMovedClicked\0"
    "slotDownMovedClicked\0slotCreateClicked\0"
    "slotDeleteClicked\0slotCellClicked\0row\0"
    "column"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FunctionListWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       5,    2,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    2,   82,    2, 0x0a /* Public */,
      11,    1,   87,    2, 0x0a /* Public */,
      12,    1,   90,    2, 0x08 /* Private */,
      13,    1,   93,    2, 0x08 /* Private */,
      14,    1,   96,    2, 0x08 /* Private */,
      16,    1,   99,    2, 0x08 /* Private */,
      17,    1,  102,    2, 0x08 /* Private */,
      18,    1,  105,    2, 0x08 /* Private */,
      19,    1,  108,    2, 0x08 /* Private */,
      20,    2,  111,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 6,    2,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8, QMetaType::Int,    9,   10,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 6,   15,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   21,   22,

       0        // eod
};

void FunctionListWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FunctionListWidget *_t = static_cast<FunctionListWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalParameters((*reinterpret_cast< FunctionStruct*(*)>(_a[1]))); break;
        case 1: _t->signalSavedFunctionlist((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QList<FunctionStruct*>(*)>(_a[2]))); break;
        case 2: _t->slotUpdateDeviceID((*reinterpret_cast< DeviceInformation*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->slotEditClicked((*reinterpret_cast< FunctionStruct*(*)>(_a[1]))); break;
        case 4: _t->slotAdd((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->slotSaveFunctions((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->slotAddFunctions((*reinterpret_cast< QList<FunctionStruct*>(*)>(_a[1]))); break;
        case 7: _t->slotUpMovedClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->slotDownMovedClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->slotCreateClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->slotDeleteClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->slotCellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FunctionListWidget::*_t)(FunctionStruct * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FunctionListWidget::signalParameters)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (FunctionListWidget::*_t)(int , QList<FunctionStruct*> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FunctionListWidget::signalSavedFunctionlist)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject FunctionListWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FunctionListWidget.data,
      qt_meta_data_FunctionListWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FunctionListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FunctionListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FunctionListWidget.stringdata0))
        return static_cast<void*>(const_cast< FunctionListWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int FunctionListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void FunctionListWidget::signalParameters(FunctionStruct * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FunctionListWidget::signalSavedFunctionlist(int _t1, QList<FunctionStruct*> _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
