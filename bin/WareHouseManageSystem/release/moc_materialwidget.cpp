/****************************************************************************
** Meta object code from reading C++ file 'materialwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../WareHouseManageSystem/baseinfomanage/materialsetup/materwidget/materialwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'materialwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MaterialWidget_t {
    QByteArrayData data[18];
    char stringdata0[400];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MaterialWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MaterialWidget_t qt_meta_stringdata_MaterialWidget = {
    {
QT_MOC_LITERAL(0, 0, 14), // "MaterialWidget"
QT_MOC_LITERAL(1, 15, 32), // "on_pushButtonAddMaterial_clicked"
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 22), // "on_tableWidget_clicked"
QT_MOC_LITERAL(4, 72, 5), // "index"
QT_MOC_LITERAL(5, 78, 26), // "on_tabWidget_tabBarClicked"
QT_MOC_LITERAL(6, 105, 18), // "receiveAddMaterial"
QT_MOC_LITERAL(7, 124, 14), // "receiveAddUnit"
QT_MOC_LITERAL(8, 139, 24), // "on_pushButtonAdd_clicked"
QT_MOC_LITERAL(9, 164, 35), // "on_treeWidgetCateGory_doubleC..."
QT_MOC_LITERAL(10, 200, 28), // "on_pushButtonAddUnit_clicked"
QT_MOC_LITERAL(11, 229, 28), // "on_pushButtonDelUnit_clicked"
QT_MOC_LITERAL(12, 258, 23), // "slotReceiveExchangeType"
QT_MOC_LITERAL(13, 282, 27), // "on_pushButtonExtend_clicked"
QT_MOC_LITERAL(14, 310, 16), // "receiveEmailText"
QT_MOC_LITERAL(15, 327, 9), // "emailText"
QT_MOC_LITERAL(16, 337, 30), // "on_pushButtonDeleteMat_clicked"
QT_MOC_LITERAL(17, 368, 31) // "on_pushButtonChangeType_clicked"

    },
    "MaterialWidget\0on_pushButtonAddMaterial_clicked\0"
    "\0on_tableWidget_clicked\0index\0"
    "on_tabWidget_tabBarClicked\0"
    "receiveAddMaterial\0receiveAddUnit\0"
    "on_pushButtonAdd_clicked\0"
    "on_treeWidgetCateGory_doubleClicked\0"
    "on_pushButtonAddUnit_clicked\0"
    "on_pushButtonDelUnit_clicked\0"
    "slotReceiveExchangeType\0"
    "on_pushButtonExtend_clicked\0"
    "receiveEmailText\0emailText\0"
    "on_pushButtonDeleteMat_clicked\0"
    "on_pushButtonChangeType_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MaterialWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    1,   85,    2, 0x08 /* Private */,
       5,    1,   88,    2, 0x08 /* Private */,
       6,    0,   91,    2, 0x08 /* Private */,
       7,    0,   92,    2, 0x08 /* Private */,
       8,    0,   93,    2, 0x08 /* Private */,
       9,    1,   94,    2, 0x08 /* Private */,
      10,    0,   97,    2, 0x08 /* Private */,
      11,    0,   98,    2, 0x08 /* Private */,
      12,    1,   99,    2, 0x08 /* Private */,
      13,    0,  102,    2, 0x08 /* Private */,
      14,    1,  103,    2, 0x08 /* Private */,
      16,    0,  106,    2, 0x08 /* Private */,
      17,    0,  107,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MaterialWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MaterialWidget *_t = static_cast<MaterialWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButtonAddMaterial_clicked(); break;
        case 1: _t->on_tableWidget_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->on_tabWidget_tabBarClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->receiveAddMaterial(); break;
        case 4: _t->receiveAddUnit(); break;
        case 5: _t->on_pushButtonAdd_clicked(); break;
        case 6: _t->on_treeWidgetCateGory_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->on_pushButtonAddUnit_clicked(); break;
        case 8: _t->on_pushButtonDelUnit_clicked(); break;
        case 9: _t->slotReceiveExchangeType((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_pushButtonExtend_clicked(); break;
        case 11: _t->receiveEmailText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->on_pushButtonDeleteMat_clicked(); break;
        case 13: _t->on_pushButtonChangeType_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MaterialWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MaterialWidget.data,
      qt_meta_data_MaterialWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MaterialWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MaterialWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MaterialWidget.stringdata0))
        return static_cast<void*>(const_cast< MaterialWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int MaterialWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
