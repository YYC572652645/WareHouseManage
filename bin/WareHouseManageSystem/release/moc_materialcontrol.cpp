/****************************************************************************
** Meta object code from reading C++ file 'materialcontrol.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../WareHouseManageSystem/baseinfomanage/materialsetup/materialcontrol/materialcontrol.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'materialcontrol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MaterialControl_t {
    QByteArrayData data[14];
    char stringdata0[269];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MaterialControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MaterialControl_t qt_meta_stringdata_MaterialControl = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MaterialControl"
QT_MOC_LITERAL(1, 16, 9), // "openImage"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 25), // "on_pushButtonSave_clicked"
QT_MOC_LITERAL(4, 53, 27), // "on_pushButtonCancel_clicked"
QT_MOC_LITERAL(5, 81, 30), // "on_pushButtonLookImage_clicked"
QT_MOC_LITERAL(6, 112, 15), // "slotAddUnitSite"
QT_MOC_LITERAL(7, 128, 14), // "receiveAddSave"
QT_MOC_LITERAL(8, 143, 15), // "receiveInfoSave"
QT_MOC_LITERAL(9, 159, 5), // "index"
QT_MOC_LITERAL(10, 165, 14), // "receiveDelSave"
QT_MOC_LITERAL(11, 180, 15), // "slotComboxClick"
QT_MOC_LITERAL(12, 196, 42), // "on_listWidgetAddMaterialInfo_..."
QT_MOC_LITERAL(13, 239, 29) // "on_pushButtonDelImage_clicked"

    },
    "MaterialControl\0openImage\0\0"
    "on_pushButtonSave_clicked\0"
    "on_pushButtonCancel_clicked\0"
    "on_pushButtonLookImage_clicked\0"
    "slotAddUnitSite\0receiveAddSave\0"
    "receiveInfoSave\0index\0receiveDelSave\0"
    "slotComboxClick\0"
    "on_listWidgetAddMaterialInfo_doubleClicked\0"
    "on_pushButtonDelImage_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MaterialControl[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    1,   75,    2, 0x08 /* Private */,
      10,    1,   78,    2, 0x08 /* Private */,
      11,    0,   81,    2, 0x08 /* Private */,
      12,    1,   82,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    9,
    QMetaType::Void,

       0        // eod
};

void MaterialControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MaterialControl *_t = static_cast<MaterialControl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openImage(); break;
        case 1: _t->on_pushButtonSave_clicked(); break;
        case 2: _t->on_pushButtonCancel_clicked(); break;
        case 3: _t->on_pushButtonLookImage_clicked(); break;
        case 4: _t->slotAddUnitSite(); break;
        case 5: _t->receiveAddSave(); break;
        case 6: _t->receiveInfoSave((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->receiveDelSave((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->slotComboxClick(); break;
        case 9: _t->on_listWidgetAddMaterialInfo_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 10: _t->on_pushButtonDelImage_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MaterialControl::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MaterialControl.data,
      qt_meta_data_MaterialControl,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MaterialControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MaterialControl::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MaterialControl.stringdata0))
        return static_cast<void*>(const_cast< MaterialControl*>(this));
    return QWidget::qt_metacast(_clname);
}

int MaterialControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
