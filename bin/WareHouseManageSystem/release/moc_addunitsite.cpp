/****************************************************************************
** Meta object code from reading C++ file 'addunitsite.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../WareHouseManageSystem/baseinfomanage/materialsetup/addunitsite/addunitsite.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addunitsite.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AddUnitSite_t {
    QByteArrayData data[15];
    char stringdata0[309];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AddUnitSite_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AddUnitSite_t qt_meta_stringdata_AddUnitSite = {
    {
QT_MOC_LITERAL(0, 0, 11), // "AddUnitSite"
QT_MOC_LITERAL(1, 12, 11), // "sendAddSave"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 12), // "sendInfoSave"
QT_MOC_LITERAL(4, 38, 11), // "sendDelSave"
QT_MOC_LITERAL(5, 50, 25), // "on_pushButtonSave_clicked"
QT_MOC_LITERAL(6, 76, 27), // "on_pushButtonCancel_clicked"
QT_MOC_LITERAL(7, 104, 39), // "on_comboBoxSiteUnit_currentIn..."
QT_MOC_LITERAL(8, 144, 4), // "arg1"
QT_MOC_LITERAL(9, 149, 28), // "on_checkBoxWareHouse_clicked"
QT_MOC_LITERAL(10, 178, 24), // "on_checkBoxPrice_clicked"
QT_MOC_LITERAL(11, 203, 25), // "on_checkBoxSupply_clicked"
QT_MOC_LITERAL(12, 229, 26), // "on_lineEditLeft_textEdited"
QT_MOC_LITERAL(13, 256, 27), // "on_lineEditRight_textEdited"
QT_MOC_LITERAL(14, 284, 24) // "on_pushButtonDel_clicked"

    },
    "AddUnitSite\0sendAddSave\0\0sendInfoSave\0"
    "sendDelSave\0on_pushButtonSave_clicked\0"
    "on_pushButtonCancel_clicked\0"
    "on_comboBoxSiteUnit_currentIndexChanged\0"
    "arg1\0on_checkBoxWareHouse_clicked\0"
    "on_checkBoxPrice_clicked\0"
    "on_checkBoxSupply_clicked\0"
    "on_lineEditLeft_textEdited\0"
    "on_lineEditRight_textEdited\0"
    "on_pushButtonDel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddUnitSite[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    1,   75,    2, 0x06 /* Public */,
       4,    1,   78,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   81,    2, 0x08 /* Private */,
       6,    0,   82,    2, 0x08 /* Private */,
       7,    1,   83,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    1,   89,    2, 0x08 /* Private */,
      13,    1,   92,    2, 0x08 /* Private */,
      14,    0,   95,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,

       0        // eod
};

void AddUnitSite::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AddUnitSite *_t = static_cast<AddUnitSite *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendAddSave(); break;
        case 1: _t->sendInfoSave((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sendDelSave((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_pushButtonSave_clicked(); break;
        case 4: _t->on_pushButtonCancel_clicked(); break;
        case 5: _t->on_comboBoxSiteUnit_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_checkBoxWareHouse_clicked(); break;
        case 7: _t->on_checkBoxPrice_clicked(); break;
        case 8: _t->on_checkBoxSupply_clicked(); break;
        case 9: _t->on_lineEditLeft_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->on_lineEditRight_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->on_pushButtonDel_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AddUnitSite::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AddUnitSite::sendAddSave)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AddUnitSite::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AddUnitSite::sendInfoSave)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (AddUnitSite::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AddUnitSite::sendDelSave)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject AddUnitSite::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AddUnitSite.data,
      qt_meta_data_AddUnitSite,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AddUnitSite::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddUnitSite::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AddUnitSite.stringdata0))
        return static_cast<void*>(const_cast< AddUnitSite*>(this));
    return QWidget::qt_metacast(_clname);
}

int AddUnitSite::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void AddUnitSite::sendAddSave()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void AddUnitSite::sendInfoSave(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AddUnitSite::sendDelSave(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
