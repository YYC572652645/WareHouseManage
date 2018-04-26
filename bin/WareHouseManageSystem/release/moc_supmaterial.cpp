/****************************************************************************
** Meta object code from reading C++ file 'supmaterial.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../WareHouseManageSystem/baseinfomanage/suppliersetup/supmaterial/supmaterial.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'supmaterial.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SupMaterial_t {
    QByteArrayData data[9];
    char stringdata0[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SupMaterial_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SupMaterial_t qt_meta_stringdata_SupMaterial = {
    {
QT_MOC_LITERAL(0, 0, 11), // "SupMaterial"
QT_MOC_LITERAL(1, 12, 9), // "sendCount"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 25), // "on_pushButtonSave_clicked"
QT_MOC_LITERAL(4, 49, 27), // "on_pushButtonCancel_clicked"
QT_MOC_LITERAL(5, 77, 24), // "on_pushButtonAdd_clicked"
QT_MOC_LITERAL(6, 102, 33), // "on_tableWidgetAllMaterial_cli..."
QT_MOC_LITERAL(7, 136, 5), // "index"
QT_MOC_LITERAL(8, 142, 24) // "on_pushButtonDel_clicked"

    },
    "SupMaterial\0sendCount\0\0on_pushButtonSave_clicked\0"
    "on_pushButtonCancel_clicked\0"
    "on_pushButtonAdd_clicked\0"
    "on_tableWidgetAllMaterial_clicked\0"
    "index\0on_pushButtonDel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SupMaterial[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   47,    2, 0x08 /* Private */,
       4,    0,   48,    2, 0x08 /* Private */,
       5,    0,   49,    2, 0x08 /* Private */,
       6,    1,   50,    2, 0x08 /* Private */,
       8,    0,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    7,
    QMetaType::Void,

       0        // eod
};

void SupMaterial::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SupMaterial *_t = static_cast<SupMaterial *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_pushButtonSave_clicked(); break;
        case 2: _t->on_pushButtonCancel_clicked(); break;
        case 3: _t->on_pushButtonAdd_clicked(); break;
        case 4: _t->on_tableWidgetAllMaterial_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->on_pushButtonDel_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SupMaterial::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SupMaterial::sendCount)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject SupMaterial::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SupMaterial.data,
      qt_meta_data_SupMaterial,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SupMaterial::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SupMaterial::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SupMaterial.stringdata0))
        return static_cast<void*>(const_cast< SupMaterial*>(this));
    return QWidget::qt_metacast(_clname);
}

int SupMaterial::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void SupMaterial::sendCount(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
