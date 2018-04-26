/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../WareHouseManageSystem/mainwindow/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[398];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 11), // "closeNowTab"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 5), // "index"
QT_MOC_LITERAL(4, 30, 34), // "on_actionTodayHouseMoney_trig..."
QT_MOC_LITERAL(5, 65, 30), // "on_actionTableCenter_triggered"
QT_MOC_LITERAL(6, 96, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(7, 120, 27), // "on_actionBaseInfo_triggered"
QT_MOC_LITERAL(8, 148, 28), // "on_actionPurManage_triggered"
QT_MOC_LITERAL(9, 177, 34), // "on_actionWareHouseManage_trig..."
QT_MOC_LITERAL(10, 212, 25), // "on_actionMatSup_triggered"
QT_MOC_LITERAL(11, 238, 26), // "on_actionAccount_triggered"
QT_MOC_LITERAL(12, 265, 33), // "on_actionSwitchLanguage_trigg..."
QT_MOC_LITERAL(13, 299, 26), // "on_actionVersion_triggered"
QT_MOC_LITERAL(14, 326, 25), // "on_actionUpdate_triggered"
QT_MOC_LITERAL(15, 352, 12), // "updateClient"
QT_MOC_LITERAL(16, 365, 32) // "on_actionAdministrator_triggered"

    },
    "MainWindow\0closeNowTab\0\0index\0"
    "on_actionTodayHouseMoney_triggered\0"
    "on_actionTableCenter_triggered\0"
    "on_actionExit_triggered\0"
    "on_actionBaseInfo_triggered\0"
    "on_actionPurManage_triggered\0"
    "on_actionWareHouseManage_triggered\0"
    "on_actionMatSup_triggered\0"
    "on_actionAccount_triggered\0"
    "on_actionSwitchLanguage_triggered\0"
    "on_actionVersion_triggered\0"
    "on_actionUpdate_triggered\0updateClient\0"
    "on_actionAdministrator_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

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
       1,    1,   84,    2, 0x08 /* Private */,
       4,    0,   87,    2, 0x08 /* Private */,
       5,    0,   88,    2, 0x08 /* Private */,
       6,    0,   89,    2, 0x08 /* Private */,
       7,    0,   90,    2, 0x08 /* Private */,
       8,    0,   91,    2, 0x08 /* Private */,
       9,    0,   92,    2, 0x08 /* Private */,
      10,    0,   93,    2, 0x08 /* Private */,
      11,    0,   94,    2, 0x08 /* Private */,
      12,    0,   95,    2, 0x08 /* Private */,
      13,    0,   96,    2, 0x08 /* Private */,
      14,    0,   97,    2, 0x08 /* Private */,
      15,    0,   98,    2, 0x08 /* Private */,
      16,    0,   99,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closeNowTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_actionTodayHouseMoney_triggered(); break;
        case 2: _t->on_actionTableCenter_triggered(); break;
        case 3: _t->on_actionExit_triggered(); break;
        case 4: _t->on_actionBaseInfo_triggered(); break;
        case 5: _t->on_actionPurManage_triggered(); break;
        case 6: _t->on_actionWareHouseManage_triggered(); break;
        case 7: _t->on_actionMatSup_triggered(); break;
        case 8: _t->on_actionAccount_triggered(); break;
        case 9: _t->on_actionSwitchLanguage_triggered(); break;
        case 10: _t->on_actionVersion_triggered(); break;
        case 11: _t->on_actionUpdate_triggered(); break;
        case 12: _t->updateClient(); break;
        case 13: _t->on_actionAdministrator_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
