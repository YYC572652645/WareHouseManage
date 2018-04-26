/****************************************************************************
** Meta object code from reading C++ file 'materialstoinfo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../WareHouseManageSystem/purchasemanage/purchasestorage/materialstoinfo/materialstoinfo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'materialstoinfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MaterialStoInfo_t {
    QByteArrayData data[13];
    char stringdata0[245];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MaterialStoInfo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MaterialStoInfo_t qt_meta_stringdata_MaterialStoInfo = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MaterialStoInfo"
QT_MOC_LITERAL(1, 16, 12), // "delWareHouse"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 11), // "valueChange"
QT_MOC_LITERAL(4, 42, 5), // "value"
QT_MOC_LITERAL(5, 48, 25), // "on_pushButtonSave_clicked"
QT_MOC_LITERAL(6, 74, 27), // "on_pushButtonCancel_clicked"
QT_MOC_LITERAL(7, 102, 25), // "on_comboBoxUnit_activated"
QT_MOC_LITERAL(8, 128, 4), // "arg1"
QT_MOC_LITERAL(9, 133, 29), // "on_spinBoxNumber_valueChanged"
QT_MOC_LITERAL(10, 163, 24), // "on_pushButtonDel_clicked"
QT_MOC_LITERAL(11, 188, 27), // "on_pushButtonAddNew_clicked"
QT_MOC_LITERAL(12, 216, 28) // "on_spinBoxPrice_valueChanged"

    },
    "MaterialStoInfo\0delWareHouse\0\0valueChange\0"
    "value\0on_pushButtonSave_clicked\0"
    "on_pushButtonCancel_clicked\0"
    "on_comboBoxUnit_activated\0arg1\0"
    "on_spinBoxNumber_valueChanged\0"
    "on_pushButtonDel_clicked\0"
    "on_pushButtonAddNew_clicked\0"
    "on_spinBoxPrice_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MaterialStoInfo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    1,   60,    2, 0x08 /* Private */,
       5,    0,   63,    2, 0x08 /* Private */,
       6,    0,   64,    2, 0x08 /* Private */,
       7,    1,   65,    2, 0x08 /* Private */,
       9,    1,   68,    2, 0x08 /* Private */,
      10,    0,   71,    2, 0x08 /* Private */,
      11,    0,   72,    2, 0x08 /* Private */,
      12,    1,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    8,

       0        // eod
};

void MaterialStoInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MaterialStoInfo *_t = static_cast<MaterialStoInfo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->delWareHouse(); break;
        case 1: _t->valueChange((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->on_pushButtonSave_clicked(); break;
        case 3: _t->on_pushButtonCancel_clicked(); break;
        case 4: _t->on_comboBoxUnit_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_spinBoxNumber_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->on_pushButtonDel_clicked(); break;
        case 7: _t->on_pushButtonAddNew_clicked(); break;
        case 8: _t->on_spinBoxPrice_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MaterialStoInfo::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MaterialStoInfo.data,
      qt_meta_data_MaterialStoInfo,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MaterialStoInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MaterialStoInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MaterialStoInfo.stringdata0))
        return static_cast<void*>(const_cast< MaterialStoInfo*>(this));
    return QWidget::qt_metacast(_clname);
}

int MaterialStoInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
