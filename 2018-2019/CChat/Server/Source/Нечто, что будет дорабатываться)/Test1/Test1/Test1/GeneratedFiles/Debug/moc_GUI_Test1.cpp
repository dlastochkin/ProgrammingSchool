/****************************************************************************
** Meta object code from reading C++ file 'GUI_Test1.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GUI_Test1.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GUI_Test1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ServerGUI_t {
    QByteArrayData data[14];
    char stringdata0[178];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ServerGUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ServerGUI_t qt_meta_stringdata_ServerGUI = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ServerGUI"
QT_MOC_LITERAL(1, 10, 17), // "startServerSignal"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 16), // "stopServerSignal"
QT_MOC_LITERAL(4, 46, 21), // "sendMessageConectSlot"
QT_MOC_LITERAL(5, 68, 8), // "messsage"
QT_MOC_LITERAL(6, 77, 15), // "sendMessageSlot"
QT_MOC_LITERAL(7, 93, 9), // "traceSlot"
QT_MOC_LITERAL(8, 103, 8), // "kickSlot"
QT_MOC_LITERAL(9, 112, 12), // "showMoreSlot"
QT_MOC_LITERAL(10, 125, 15), // "startOrStopSlot"
QT_MOC_LITERAL(11, 141, 21), // "mediaStateChangedSlot"
QT_MOC_LITERAL(12, 163, 9), // "addClient"
QT_MOC_LITERAL(13, 173, 4) // "name"

    },
    "ServerGUI\0startServerSignal\0\0"
    "stopServerSignal\0sendMessageConectSlot\0"
    "messsage\0sendMessageSlot\0traceSlot\0"
    "kickSlot\0showMoreSlot\0startOrStopSlot\0"
    "mediaStateChangedSlot\0addClient\0name"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ServerGUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   66,    2, 0x08 /* Private */,
       6,    1,   69,    2, 0x08 /* Private */,
       7,    0,   72,    2, 0x08 /* Private */,
       8,    0,   73,    2, 0x08 /* Private */,
       9,    0,   74,    2, 0x08 /* Private */,
      10,    0,   75,    2, 0x08 /* Private */,
      11,    0,   76,    2, 0x08 /* Private */,
      12,    1,   77,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,

       0        // eod
};

void ServerGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ServerGUI *_t = static_cast<ServerGUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startServerSignal(); break;
        case 1: _t->stopServerSignal(); break;
        case 2: _t->sendMessageConectSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->sendMessageSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->traceSlot(); break;
        case 5: _t->kickSlot(); break;
        case 6: _t->showMoreSlot(); break;
        case 7: _t->startOrStopSlot(); break;
        case 8: _t->mediaStateChangedSlot(); break;
        case 9: _t->addClient((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ServerGUI::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServerGUI::startServerSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ServerGUI::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServerGUI::stopServerSignal)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject ServerGUI::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ServerGUI.data,
      qt_meta_data_ServerGUI,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ServerGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ServerGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ServerGUI.stringdata0))
        return static_cast<void*>(const_cast< ServerGUI*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ServerGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void ServerGUI::startServerSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void ServerGUI::stopServerSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
