/****************************************************************************
** Meta object code from reading C++ file 'extendcheckemail.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../WareHouseManageSystem/warehousemanage/inventorycheck/extendcheckemail/extendcheckemail.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'extendcheckemail.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ExtendCheckEmail_t {
    QByteArrayData data[6];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ExtendCheckEmail_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ExtendCheckEmail_t qt_meta_stringdata_ExtendCheckEmail = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ExtendCheckEmail"
QT_MOC_LITERAL(1, 17, 27), // "on_pushButtonExport_clicked"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 26), // "on_tableWidgetData_clicked"
QT_MOC_LITERAL(4, 73, 5), // "index"
QT_MOC_LITERAL(5, 79, 28) // "on_checkBoxAllSelect_clicked"

    },
    "ExtendCheckEmail\0on_pushButtonExport_clicked\0"
    "\0on_tableWidgetData_clicked\0index\0"
    "on_checkBoxAllSelect_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ExtendCheckEmail[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    1,   30,    2, 0x08 /* Private */,
       5,    0,   33,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    4,
    QMetaType::Void,

       0        // eod
};

void ExtendCheckEmail::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ExtendCheckEmail *_t = static_cast<ExtendCheckEmail *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButtonExport_clicked(); break;
        case 1: _t->on_tableWidgetData_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->on_checkBoxAllSelect_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject ExtendCheckEmail::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ExtendCheckEmail.data,
      qt_meta_data_ExtendCheckEmail,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ExtendCheckEmail::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExtendCheckEmail::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ExtendCheckEmail.stringdata0))
        return static_cast<void*>(const_cast< ExtendCheckEmail*>(this));
    return QWidget::qt_metacast(_clname);
}

int ExtendCheckEmail::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
