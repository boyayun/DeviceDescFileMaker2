/****************************************************************************
** Meta object code from reading C++ file 'addfunctionswidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../code/functions/addfunctionswidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addfunctionswidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AddFunctionsWidget_t {
    QByteArrayData data[15];
    char stringdata0[292];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AddFunctionsWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AddFunctionsWidget_t qt_meta_stringdata_AddFunctionsWidget = {
    {
QT_MOC_LITERAL(0, 0, 18), // "AddFunctionsWidget"
QT_MOC_LITERAL(1, 19, 18), // "signalAddFunctions"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 22), // "QList<FunctionStruct*>"
QT_MOC_LITERAL(4, 62, 31), // "on_listWidget_itemDoubleClicked"
QT_MOC_LITERAL(5, 94, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(6, 111, 4), // "item"
QT_MOC_LITERAL(7, 116, 29), // "on_searchlineEdit_textChanged"
QT_MOC_LITERAL(8, 146, 4), // "arg1"
QT_MOC_LITERAL(9, 151, 24), // "on_addpushButton_clicked"
QT_MOC_LITERAL(10, 176, 27), // "on_cancelpushButton_clicked"
QT_MOC_LITERAL(11, 204, 37), // "on_selectlistWidget_itemDoubl..."
QT_MOC_LITERAL(12, 242, 26), // "on_selectFunButton_clicked"
QT_MOC_LITERAL(13, 269, 11), // "slotFunmenu"
QT_MOC_LITERAL(14, 281, 10) // "QList<int>"

    },
    "AddFunctionsWidget\0signalAddFunctions\0"
    "\0QList<FunctionStruct*>\0"
    "on_listWidget_itemDoubleClicked\0"
    "QListWidgetItem*\0item\0"
    "on_searchlineEdit_textChanged\0arg1\0"
    "on_addpushButton_clicked\0"
    "on_cancelpushButton_clicked\0"
    "on_selectlistWidget_itemDoubleClicked\0"
    "on_selectFunButton_clicked\0slotFunmenu\0"
    "QList<int>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddFunctionsWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   57,    2, 0x08 /* Private */,
       7,    1,   60,    2, 0x08 /* Private */,
       9,    0,   63,    2, 0x08 /* Private */,
      10,    0,   64,    2, 0x08 /* Private */,
      11,    1,   65,    2, 0x08 /* Private */,
      12,    0,   68,    2, 0x08 /* Private */,
      13,    1,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,    2,

       0        // eod
};

void AddFunctionsWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AddFunctionsWidget *_t = static_cast<AddFunctionsWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalAddFunctions((*reinterpret_cast< QList<FunctionStruct*>(*)>(_a[1]))); break;
        case 1: _t->on_listWidget_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->on_searchlineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_addpushButton_clicked(); break;
        case 4: _t->on_cancelpushButton_clicked(); break;
        case 5: _t->on_selectlistWidget_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 6: _t->on_selectFunButton_clicked(); break;
        case 7: _t->slotFunmenu((*reinterpret_cast< QList<int>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AddFunctionsWidget::*_t)(QList<FunctionStruct*> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AddFunctionsWidget::signalAddFunctions)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject AddFunctionsWidget::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AddFunctionsWidget.data,
      qt_meta_data_AddFunctionsWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AddFunctionsWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddFunctionsWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AddFunctionsWidget.stringdata0))
        return static_cast<void*>(const_cast< AddFunctionsWidget*>(this));
    return QDialog::qt_metacast(_clname);
}

int AddFunctionsWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void AddFunctionsWidget::signalAddFunctions(QList<FunctionStruct*> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
