/****************************************************************************
** Meta object code from reading C++ file 'materialsupplier.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../WareHouseManageSystem/materialsupplier/materialsupplier.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'materialsupplier.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MaterialSupplier_t {
    QByteArrayData data[7];
    char stringdata0[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MaterialSupplier_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MaterialSupplier_t qt_meta_stringdata_MaterialSupplier = {
    {
QT_MOC_LITERAL(0, 0, 16), // "MaterialSupplier"
QT_MOC_LITERAL(1, 17, 28), // "on_tableWidget_doubleClicked"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 5), // "index"
QT_MOC_LITERAL(4, 53, 30), // "on_pushButtonAllSelect_clicked"
QT_MOC_LITERAL(5, 84, 29), // "on_pushButtonNoSelect_clicked"
QT_MOC_LITERAL(6, 114, 26) // "on_pushButtonSetUp_clicked"

    },
    "MaterialSupplier\0on_tableWidget_doubleClicked\0"
    "\0index\0on_pushButtonAllSelect_clicked\0"
    "on_pushButtonNoSelect_clicked\0"
    "on_pushButtonSetUp_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MaterialSupplier[] = {

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
       1,    1,   34,    2, 0x08 /* Private */,
       4,    0,   37,    2, 0x08 /* Private */,
       5,    0,   38,    2, 0x08 /* Private */,
       6,    0,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MaterialSupplier::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MaterialSupplier *_t = static_cast<MaterialSupplier *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_tableWidget_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->on_pushButtonAllSelect_clicked(); break;
        case 2: _t->on_pushButtonNoSelect_clicked(); break;
        case 3: _t->on_pushButtonSetUp_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MaterialSupplier::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MaterialSupplier.data,
      qt_meta_data_MaterialSupplier,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MaterialSupplier::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MaterialSupplier::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MaterialSupplier.stringdata0))
        return static_cast<void*>(const_cast< MaterialSupplier*>(this));
    return QWidget::qt_metacast(_clname);
}

int MaterialSupplier::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
