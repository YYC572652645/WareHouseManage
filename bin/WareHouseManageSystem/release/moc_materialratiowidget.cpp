/****************************************************************************
** Meta object code from reading C++ file 'materialratiowidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../WareHouseManageSystem/baseinfomanage/materialratiosetup/materialratiowidget/materialratiowidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'materialratiowidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MaterialRatioWidget_t {
    QByteArrayData data[9];
    char stringdata0[198];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MaterialRatioWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MaterialRatioWidget_t qt_meta_stringdata_MaterialRatioWidget = {
    {
QT_MOC_LITERAL(0, 0, 19), // "MaterialRatioWidget"
QT_MOC_LITERAL(1, 20, 25), // "on_treeWidgetData_clicked"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 5), // "index"
QT_MOC_LITERAL(4, 53, 29), // "on_pushButtonSaveInfo_clicked"
QT_MOC_LITERAL(5, 83, 31), // "on_pushButtonCancelInfo_clicked"
QT_MOC_LITERAL(6, 115, 30), // "on_pushButtonAddNewMat_clicked"
QT_MOC_LITERAL(7, 146, 31), // "on_listWidgetData_doubleClicked"
QT_MOC_LITERAL(8, 178, 19) // "on_checkBox_clicked"

    },
    "MaterialRatioWidget\0on_treeWidgetData_clicked\0"
    "\0index\0on_pushButtonSaveInfo_clicked\0"
    "on_pushButtonCancelInfo_clicked\0"
    "on_pushButtonAddNewMat_clicked\0"
    "on_listWidgetData_doubleClicked\0"
    "on_checkBox_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MaterialRatioWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x08 /* Private */,
       4,    0,   47,    2, 0x08 /* Private */,
       5,    0,   48,    2, 0x08 /* Private */,
       6,    0,   49,    2, 0x08 /* Private */,
       7,    1,   50,    2, 0x08 /* Private */,
       8,    0,   53,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void,

       0        // eod
};

void MaterialRatioWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MaterialRatioWidget *_t = static_cast<MaterialRatioWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_treeWidgetData_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->on_pushButtonSaveInfo_clicked(); break;
        case 2: _t->on_pushButtonCancelInfo_clicked(); break;
        case 3: _t->on_pushButtonAddNewMat_clicked(); break;
        case 4: _t->on_listWidgetData_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->on_checkBox_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MaterialRatioWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MaterialRatioWidget.data,
      qt_meta_data_MaterialRatioWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MaterialRatioWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MaterialRatioWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MaterialRatioWidget.stringdata0))
        return static_cast<void*>(const_cast< MaterialRatioWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int MaterialRatioWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
