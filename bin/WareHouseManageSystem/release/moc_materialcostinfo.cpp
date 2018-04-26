/****************************************************************************
** Meta object code from reading C++ file 'materialcostinfo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../WareHouseManageSystem/warehousemanage/costadjustment/materialcostinfo/materialcostinfo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'materialcostinfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MaterialCostInfo_t {
    QByteArrayData data[7];
    char stringdata0[136];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MaterialCostInfo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MaterialCostInfo_t qt_meta_stringdata_MaterialCostInfo = {
    {
QT_MOC_LITERAL(0, 0, 16), // "MaterialCostInfo"
QT_MOC_LITERAL(1, 17, 25), // "on_pushButtonSave_clicked"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 27), // "on_pushButtonCancel_clicked"
QT_MOC_LITERAL(4, 72, 24), // "on_pushButtonDel_clicked"
QT_MOC_LITERAL(5, 97, 33), // "on_spinBoxPriceAfter_valueCha..."
QT_MOC_LITERAL(6, 131, 4) // "arg1"

    },
    "MaterialCostInfo\0on_pushButtonSave_clicked\0"
    "\0on_pushButtonCancel_clicked\0"
    "on_pushButtonDel_clicked\0"
    "on_spinBoxPriceAfter_valueChanged\0"
    "arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MaterialCostInfo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    1,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    6,

       0        // eod
};

void MaterialCostInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MaterialCostInfo *_t = static_cast<MaterialCostInfo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButtonSave_clicked(); break;
        case 1: _t->on_pushButtonCancel_clicked(); break;
        case 2: _t->on_pushButtonDel_clicked(); break;
        case 3: _t->on_spinBoxPriceAfter_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MaterialCostInfo::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MaterialCostInfo.data,
      qt_meta_data_MaterialCostInfo,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MaterialCostInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MaterialCostInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MaterialCostInfo.stringdata0))
        return static_cast<void*>(const_cast< MaterialCostInfo*>(this));
    return QWidget::qt_metacast(_clname);
}

int MaterialCostInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
