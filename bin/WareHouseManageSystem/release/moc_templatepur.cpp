/****************************************************************************
** Meta object code from reading C++ file 'templatepur.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../WareHouseManageSystem/purchasemanage/purchaseorder/templatepur/templatepur.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'templatepur.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TemplatePur_t {
    QByteArrayData data[5];
    char stringdata0[85];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TemplatePur_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TemplatePur_t qt_meta_stringdata_TemplatePur = {
    {
QT_MOC_LITERAL(0, 0, 11), // "TemplatePur"
QT_MOC_LITERAL(1, 12, 33), // "on_commandLinkButtonOrder_cli..."
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 31), // "on_listWidgetData_doubleClicked"
QT_MOC_LITERAL(4, 79, 5) // "index"

    },
    "TemplatePur\0on_commandLinkButtonOrder_clicked\0"
    "\0on_listWidgetData_doubleClicked\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TemplatePur[] = {

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
       3,    1,   25,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    4,

       0        // eod
};

void TemplatePur::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TemplatePur *_t = static_cast<TemplatePur *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_commandLinkButtonOrder_clicked(); break;
        case 1: _t->on_listWidgetData_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject TemplatePur::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TemplatePur.data,
      qt_meta_data_TemplatePur,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TemplatePur::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TemplatePur::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TemplatePur.stringdata0))
        return static_cast<void*>(const_cast< TemplatePur*>(this));
    return QWidget::qt_metacast(_clname);
}

int TemplatePur::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
