/****************************************************************************
** Meta object code from reading C++ file 'GameWorld.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../edu-app-team-boujee/GameWorld.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GameWorld.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GameWorld_t {
    QByteArrayData data[20];
    char stringdata0[260];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameWorld_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameWorld_t qt_meta_stringdata_GameWorld = {
    {
QT_MOC_LITERAL(0, 0, 9), // "GameWorld"
QT_MOC_LITERAL(1, 10, 7), // "success"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 11), // "std::string"
QT_MOC_LITERAL(4, 31, 20), // "launcherAngleChanged"
QT_MOC_LITERAL(5, 52, 18), // "changeBallLocation"
QT_MOC_LITERAL(6, 71, 13), // "playExplosion"
QT_MOC_LITERAL(7, 85, 14), // "onTopBasketHit"
QT_MOC_LITERAL(8, 100, 14), // "onBotBasketHit"
QT_MOC_LITERAL(9, 115, 8), // "onRimHit"
QT_MOC_LITERAL(10, 124, 14), // "onBackboardHit"
QT_MOC_LITERAL(11, 139, 9), // "onBallOut"
QT_MOC_LITERAL(12, 149, 19), // "changeLauncherAngle"
QT_MOC_LITERAL(13, 169, 5), // "angle"
QT_MOC_LITERAL(14, 175, 23), // "changeLauncherMagnitude"
QT_MOC_LITERAL(15, 199, 9), // "magnitude"
QT_MOC_LITERAL(16, 209, 13), // "onObstacleHit"
QT_MOC_LITERAL(17, 223, 14), // "onBallHitsBall"
QT_MOC_LITERAL(18, 238, 13), // "onDynamiteHit"
QT_MOC_LITERAL(19, 252, 7) // "b2Body*"

    },
    "GameWorld\0success\0\0std::string\0"
    "launcherAngleChanged\0changeBallLocation\0"
    "playExplosion\0onTopBasketHit\0"
    "onBotBasketHit\0onRimHit\0onBackboardHit\0"
    "onBallOut\0changeLauncherAngle\0angle\0"
    "changeLauncherMagnitude\0magnitude\0"
    "onObstacleHit\0onBallHitsBall\0onDynamiteHit\0"
    "b2Body*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameWorld[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   84,    2, 0x06 /* Public */,
       4,    1,   89,    2, 0x06 /* Public */,
       5,    2,   92,    2, 0x06 /* Public */,
       6,    0,   97,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   98,    2, 0x0a /* Public */,
       8,    0,   99,    2, 0x0a /* Public */,
       9,    0,  100,    2, 0x0a /* Public */,
      10,    0,  101,    2, 0x0a /* Public */,
      11,    0,  102,    2, 0x0a /* Public */,
      12,    1,  103,    2, 0x0a /* Public */,
      14,    1,  106,    2, 0x0a /* Public */,
      16,    0,  109,    2, 0x0a /* Public */,
      17,    0,  110,    2, 0x0a /* Public */,
      18,    1,  111,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    2,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   13,
    QMetaType::Void, QMetaType::Double,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19,    2,

       0        // eod
};

void GameWorld::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameWorld *_t = static_cast<GameWorld *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->success((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->launcherAngleChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->changeBallLocation((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 3: _t->playExplosion(); break;
        case 4: _t->onTopBasketHit(); break;
        case 5: _t->onBotBasketHit(); break;
        case 6: _t->onRimHit(); break;
        case 7: _t->onBackboardHit(); break;
        case 8: _t->onBallOut(); break;
        case 9: _t->changeLauncherAngle((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->changeLauncherMagnitude((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->onObstacleHit(); break;
        case 12: _t->onBallHitsBall(); break;
        case 13: _t->onDynamiteHit((*reinterpret_cast< b2Body*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GameWorld::*_t)(std::string , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameWorld::success)) {
                *result = 0;
            }
        }
        {
            typedef void (GameWorld::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameWorld::launcherAngleChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (GameWorld::*_t)(double , double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameWorld::changeBallLocation)) {
                *result = 2;
            }
        }
        {
            typedef void (GameWorld::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameWorld::playExplosion)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject GameWorld::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GameWorld.data,
      qt_meta_data_GameWorld,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GameWorld::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameWorld::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GameWorld.stringdata0))
        return static_cast<void*>(const_cast< GameWorld*>(this));
    return QObject::qt_metacast(_clname);
}

int GameWorld::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void GameWorld::success(std::string _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GameWorld::launcherAngleChanged(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GameWorld::changeBallLocation(double _t1, double _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GameWorld::playExplosion()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
