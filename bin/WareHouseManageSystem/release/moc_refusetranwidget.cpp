/****************************************************************************
** Meta object code from reading C++ file 'refusetranwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../WareHouseManageSystem/warehousemanage/inventorytransfer/refusetranwidget/refusetranwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'refusetranwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RefuseTranWidget_t {
    QByteArrayData data[4];
    char stringdata0[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RefuseTranWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RefuseTranWidget_t qt_meta_stringdata_RefuseTranWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "RefuseTranWidget"
QT_MOC_LITERAL(1, 17, 23), // "on_pushButtonOk_clicked"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 27) // "on_pushButtonCancel_clicked"

    },
    "RefuseTranWidget\0on_pushButtonOk_clicked\0"
    "\0on_pushButtonCancel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RefuseTranWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x08 /* Private */,
       3,    0,   25,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RefuseTranWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RefuseTranWidget *_t = static_cast<RefuseTranWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButtonOk_clicked(); break;
        case 1: _t->on_pushButtonCancel_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject RefuseTranWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RefuseTranWidget.data,
      qt_meta_data_RefuseTranWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RefuseTranWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RefuseTranWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RefuseTranWidget.stringdata0))
        return static_cast<void*>(const_cast< RefuseTranWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int RefuseTranWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
