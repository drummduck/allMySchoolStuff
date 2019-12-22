/****************************************************************************
** Meta object code from reading C++ file 'networkmonitor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../edu-app-team-boujee/networkmonitor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'networkmonitor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NetworkMonitor_t {
    QByteArrayData data[23];
    char stringdata0[289];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NetworkMonitor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NetworkMonitor_t qt_meta_stringdata_NetworkMonitor = {
    {
QT_MOC_LITERAL(0, 0, 14), // "NetworkMonitor"
QT_MOC_LITERAL(1, 15, 17), // "updateCurrentUser"
QT_MOC_LITERAL(2, 33, 11), // "std::string"
QT_MOC_LITERAL(3, 45, 0), // ""
QT_MOC_LITERAL(4, 46, 7), // "newUser"
QT_MOC_LITERAL(5, 54, 18), // "updateCurrentLevel"
QT_MOC_LITERAL(6, 73, 8), // "newLevel"
QT_MOC_LITERAL(7, 82, 18), // "updateNotification"
QT_MOC_LITERAL(8, 101, 5), // "error"
QT_MOC_LITERAL(9, 107, 13), // "accessGranted"
QT_MOC_LITERAL(10, 121, 12), // "accessDenied"
QT_MOC_LITERAL(11, 134, 22), // "errorMessageFromServer"
QT_MOC_LITERAL(12, 157, 3), // "msg"
QT_MOC_LITERAL(13, 161, 13), // "openUpWebpage"
QT_MOC_LITERAL(14, 175, 12), // "generateHtml"
QT_MOC_LITERAL(15, 188, 11), // "getResponse"
QT_MOC_LITERAL(16, 200, 19), // "handleFacebookShare"
QT_MOC_LITERAL(17, 220, 7), // "message"
QT_MOC_LITERAL(18, 228, 8), // "filename"
QT_MOC_LITERAL(19, 237, 16), // "finishedFacebook"
QT_MOC_LITERAL(20, 254, 14), // "QNetworkReply*"
QT_MOC_LITERAL(21, 269, 5), // "reply"
QT_MOC_LITERAL(22, 275, 13) // "resetListener"

    },
    "NetworkMonitor\0updateCurrentUser\0"
    "std::string\0\0newUser\0updateCurrentLevel\0"
    "newLevel\0updateNotification\0error\0"
    "accessGranted\0accessDenied\0"
    "errorMessageFromServer\0msg\0openUpWebpage\0"
    "generateHtml\0getResponse\0handleFacebookShare\0"
    "message\0filename\0finishedFacebook\0"
    "QNetworkReply*\0reply\0resetListener"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NetworkMonitor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    3, 0x06 /* Public */,
       5,    1,   77,    3, 0x06 /* Public */,
       7,    1,   80,    3, 0x06 /* Public */,
       9,    0,   83,    3, 0x06 /* Public */,
      10,    0,   84,    3, 0x06 /* Public */,
      11,    1,   85,    3, 0x06 /* Public */,
      13,    0,   88,    3, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    1,   89,    3, 0x0a /* Public */,
      15,    0,   92,    3, 0x0a /* Public */,
      16,    2,   93,    3, 0x0a /* Public */,
      19,    1,   98,    3, 0x0a /* Public */,
      22,    0,  101,    3, 0x0a /* Public */,

 // signals: parameters
    0x80000000 | 2, 0x80000000 | 2,    4,
    QMetaType::Int, QMetaType::Int,    6,
    0x80000000 | 2, 0x80000000 | 2,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 2,   12,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 2,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::QString,   17,   18,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void,

       0        // eod
};

void NetworkMonitor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NetworkMonitor *_t = static_cast<NetworkMonitor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { std::string _r = _t->updateCurrentUser((*reinterpret_cast< std::string(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< std::string*>(_a[0]) = _r; }  break;
        case 1: { int _r = _t->updateCurrentLevel((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: { std::string _r = _t->updateNotification((*reinterpret_cast< std::string(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< std::string*>(_a[0]) = _r; }  break;
        case 3: _t->accessGranted(); break;
        case 4: _t->accessDenied(); break;
        case 5: _t->errorMessageFromServer((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 6: _t->openUpWebpage(); break;
        case 7: _t->generateHtml((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 8: _t->getResponse(); break;
        case 9: _t->handleFacebookShare((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 10: _t->finishedFacebook((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 11: _t->resetListener(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef std::string (NetworkMonitor::*_t)(std::string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetworkMonitor::updateCurrentUser)) {
                *result = 0;
            }
        }
        {
            typedef int (NetworkMonitor::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetworkMonitor::updateCurrentLevel)) {
                *result = 1;
            }
        }
        {
            typedef std::string (NetworkMonitor::*_t)(std::string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetworkMonitor::updateNotification)) {
                *result = 2;
            }
        }
        {
            typedef void (NetworkMonitor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetworkMonitor::accessGranted)) {
                *result = 3;
            }
        }
        {
            typedef void (NetworkMonitor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetworkMonitor::accessDenied)) {
                *result = 4;
            }
        }
        {
            typedef void (NetworkMonitor::*_t)(std::string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetworkMonitor::errorMessageFromServer)) {
                *result = 5;
            }
        }
        {
            typedef void (NetworkMonitor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetworkMonitor::openUpWebpage)) {
                *result = 6;
            }
        }
    }
}

const QMetaObject NetworkMonitor::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_NetworkMonitor.data,
      qt_meta_data_NetworkMonitor,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NetworkMonitor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NetworkMonitor::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NetworkMonitor.stringdata0))
        return static_cast<void*>(const_cast< NetworkMonitor*>(this));
    return QObject::qt_metacast(_clname);
}

int NetworkMonitor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
std::string NetworkMonitor::updateCurrentUser(std::string _t1)
{
    std::string _t0 = std::string();
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}

// SIGNAL 1
int NetworkMonitor::updateCurrentLevel(int _t1)
{
    int _t0 = int();
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
    return _t0;
}

// SIGNAL 2
std::string NetworkMonitor::updateNotification(std::string _t1)
{
    std::string _t0 = std::string();
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
    return _t0;
}

// SIGNAL 3
void NetworkMonitor::accessGranted()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void NetworkMonitor::accessDenied()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void NetworkMonitor::errorMessageFromServer(std::string _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void NetworkMonitor::openUpWebpage()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
