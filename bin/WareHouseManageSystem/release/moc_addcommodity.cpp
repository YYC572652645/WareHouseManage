/****************************************************************************
** Meta object code from reading C++ file 'addcommodity.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../WareHouseManageSystem/baseinfomanage/warehousesetup/addcommodity/addcommodity.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addcommodity.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AddCommodity_t {
    QByteArrayData data[11];
    char stringdata0[198];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AddCommodity_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AddCommodity_t qt_meta_stringdata_AddCommodity = {
    {
QT_MOC_LITERAL(0, 0, 12), // "AddCommodity"
QT_MOC_LITERAL(1, 13, 7), // "sendAdd"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 8), // "sendType"
QT_MOC_LITERAL(4, 31, 25), // "on_pushButtonSave_clicked"
QT_MOC_LITERAL(5, 57, 27), // "on_pushButtonCancel_clicked"
QT_MOC_LITERAL(6, 85, 27), // "on_pushButtonSearch_clicked"
QT_MOC_LITERAL(7, 113, 26), // "on_tableWidgetData_clicked"
QT_MOC_LITERAL(8, 140, 5), // "index"
QT_MOC_LITERAL(9, 146, 25), // "on_treeWidgetData_clicked"
QT_MOC_LITERAL(10, 172, 25) // "on_checkBoxSelect_clicked"

    },
    "AddCommodity\0sendAdd\0\0sendType\0"
    "on_pushButtonSave_clicked\0"
    "on_pushButtonCancel_clicked\0"
    "on_pushButtonSearch_clicked\0"
    "on_tableWidgetData_clicked\0index\0"
    "on_treeWidgetData_clicked\0"
    "on_checkBoxSelect_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddCommodity[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    1,   59,    2, 0x08 /* Private */,
       9,    1,   62,    2, 0x08 /* Private */,
      10,    0,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    8,
    QMetaType::Void, QMetaType::QModelIndex,    8,
    QMetaType::Void,

       0        // eod
};

void AddCommodity::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AddCommodity *_t = static_cast<AddCommodity *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendAdd(); break;
        case 1: _t->sendType(); break;
        case 2: _t->on_pushButtonSave_clicked(); break;
        case 3: _t->on_pushButtonCancel_clicked(); break;
        case 4: _t->on_pushButtonSearch_clicked(); break;
        case 5: _t->on_tableWidgetData_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->on_treeWidgetData_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->on_checkBoxSelect_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AddCommodity::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AddCommodity::sendAdd)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AddCommodity::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AddCommodity::sendType)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject AddCommodity::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AddCommodity.data,
      qt_meta_data_AddCommodity,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AddCommodity::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddCommodity::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AddCommodity.stringdata0))
        return static_cast<void*>(const_cast< AddCommodity*>(this));
    return QWidget::qt_metacast(_clname);
}

int AddCommodity::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void AddCommodity::sendAdd()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void AddCommodity::sendType()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
