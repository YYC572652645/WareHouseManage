/****************************************************************************
** Meta object code from reading C++ file 'templatewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../WareHouseManageSystem/baseinfomanage/templatesetup/templatewidget/templatewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'templatewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TemplateWidget_t {
    QByteArrayData data[13];
    char stringdata0[306];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TemplateWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TemplateWidget_t qt_meta_stringdata_TemplateWidget = {
    {
QT_MOC_LITERAL(0, 0, 14), // "TemplateWidget"
QT_MOC_LITERAL(1, 15, 27), // "on_pushButtonAddTem_clicked"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 30), // "on_tableWidgetTemplate_clicked"
QT_MOC_LITERAL(4, 75, 5), // "index"
QT_MOC_LITERAL(5, 81, 25), // "on_pushButtonSave_clicked"
QT_MOC_LITERAL(6, 107, 27), // "on_pushButtonDelTem_clicked"
QT_MOC_LITERAL(7, 135, 34), // "on_pushButtonAddTemMatInfo_cl..."
QT_MOC_LITERAL(8, 170, 30), // "on_pushButtonAddTemMat_clicked"
QT_MOC_LITERAL(9, 201, 29), // "on_pushButtonSaveInfo_clicked"
QT_MOC_LITERAL(10, 231, 31), // "on_pushButtonCancelInfo_clicked"
QT_MOC_LITERAL(11, 263, 27), // "on_pushButtonCancel_clicked"
QT_MOC_LITERAL(12, 291, 14) // "deleteMaterial"

    },
    "TemplateWidget\0on_pushButtonAddTem_clicked\0"
    "\0on_tableWidgetTemplate_clicked\0index\0"
    "on_pushButtonSave_clicked\0"
    "on_pushButtonDelTem_clicked\0"
    "on_pushButtonAddTemMatInfo_clicked\0"
    "on_pushButtonAddTemMat_clicked\0"
    "on_pushButtonSaveInfo_clicked\0"
    "on_pushButtonCancelInfo_clicked\0"
    "on_pushButtonCancel_clicked\0deleteMaterial"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TemplateWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    1,   65,    2, 0x08 /* Private */,
       5,    0,   68,    2, 0x08 /* Private */,
       6,    0,   69,    2, 0x08 /* Private */,
       7,    0,   70,    2, 0x08 /* Private */,
       8,    0,   71,    2, 0x08 /* Private */,
       9,    0,   72,    2, 0x08 /* Private */,
      10,    0,   73,    2, 0x08 /* Private */,
      11,    0,   74,    2, 0x08 /* Private */,
      12,    0,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TemplateWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TemplateWidget *_t = static_cast<TemplateWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButtonAddTem_clicked(); break;
        case 1: _t->on_tableWidgetTemplate_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->on_pushButtonSave_clicked(); break;
        case 3: _t->on_pushButtonDelTem_clicked(); break;
        case 4: _t->on_pushButtonAddTemMatInfo_clicked(); break;
        case 5: _t->on_pushButtonAddTemMat_clicked(); break;
        case 6: _t->on_pushButtonSaveInfo_clicked(); break;
        case 7: _t->on_pushButtonCancelInfo_clicked(); break;
        case 8: _t->on_pushButtonCancel_clicked(); break;
        case 9: _t->deleteMaterial(); break;
        default: ;
        }
    }
}

const QMetaObject TemplateWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TemplateWidget.data,
      qt_meta_data_TemplateWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TemplateWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TemplateWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TemplateWidget.stringdata0))
        return static_cast<void*>(const_cast< TemplateWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int TemplateWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
