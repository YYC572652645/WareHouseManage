/****************************************************************************
** Meta object code from reading C++ file 'inventorychange.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../WareHouseManageSystem/warehousemanage/inventorychange/inventorychange.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'inventorychange.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_InventoryChange_t {
    QByteArrayData data[10];
    char stringdata0[176];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_InventoryChange_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_InventoryChange_t qt_meta_stringdata_InventoryChange = {
    {
QT_MOC_LITERAL(0, 0, 15), // "InventoryChange"
QT_MOC_LITERAL(1, 16, 35), // "on_comboBoxTime_currentIndexC..."
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 4), // "arg1"
QT_MOC_LITERAL(4, 58, 27), // "on_pushButtonSelect_clicked"
QT_MOC_LITERAL(5, 86, 27), // "on_pushButtonExport_clicked"
QT_MOC_LITERAL(6, 114, 32), // "on_tableWidgetData_doubleClicked"
QT_MOC_LITERAL(7, 147, 5), // "index"
QT_MOC_LITERAL(8, 153, 12), // "receiveEmail"
QT_MOC_LITERAL(9, 166, 9) // "emailText"

    },
    "InventoryChange\0on_comboBoxTime_currentIndexChanged\0"
    "\0arg1\0on_pushButtonSelect_clicked\0"
    "on_pushButtonExport_clicked\0"
    "on_tableWidgetData_doubleClicked\0index\0"
    "receiveEmail\0emailText"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InventoryChange[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08 /* Private */,
       4,    0,   42,    2, 0x08 /* Private */,
       5,    0,   43,    2, 0x08 /* Private */,
       6,    1,   44,    2, 0x08 /* Private */,
       8,    1,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    7,
    QMetaType::Void, QMetaType::QString,    9,

       0        // eod
};

void InventoryChange::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        InventoryChange *_t = static_cast<InventoryChange *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_comboBoxTime_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_pushButtonSelect_clicked(); break;
        case 2: _t->on_pushButtonExport_clicked(); break;
        case 3: _t->on_tableWidgetData_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 4: _t->receiveEmail((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject InventoryChange::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_InventoryChange.data,
      qt_meta_data_InventoryChange,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *InventoryChange::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InventoryChange::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_InventoryChange.stringdata0))
        return static_cast<void*>(const_cast< InventoryChange*>(this));
    return QWidget::qt_metacast(_clname);
}

int InventoryChange::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
