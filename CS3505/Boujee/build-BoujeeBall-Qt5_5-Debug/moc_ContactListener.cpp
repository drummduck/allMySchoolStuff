/****************************************************************************
** Meta object code from reading C++ file 'ContactListener.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../edu-app-team-boujee/ContactListener.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ContactListener.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ContactListener_t {
    QByteArrayData data[12];
    char stringdata0[136];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ContactListener_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ContactListener_t qt_meta_stringdata_ContactListener = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ContactListener"
QT_MOC_LITERAL(1, 16, 12), // "topBasketHit"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 12), // "botBasketHit"
QT_MOC_LITERAL(4, 43, 15), // "ballOutOfBounds"
QT_MOC_LITERAL(5, 59, 6), // "rimHit"
QT_MOC_LITERAL(6, 66, 12), // "backboardHit"
QT_MOC_LITERAL(7, 79, 11), // "bounceSound"
QT_MOC_LITERAL(8, 91, 11), // "obstacleHit"
QT_MOC_LITERAL(9, 103, 12), // "ballHitsBall"
QT_MOC_LITERAL(10, 116, 11), // "dynamiteHit"
QT_MOC_LITERAL(11, 128, 7) // "b2Body*"

    },
    "ContactListener\0topBasketHit\0\0"
    "botBasketHit\0ballOutOfBounds\0rimHit\0"
    "backboardHit\0bounceSound\0obstacleHit\0"
    "ballHitsBall\0dynamiteHit\0b2Body*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ContactListener[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,
       5,    0,   62,    2, 0x06 /* Public */,
       6,    0,   63,    2, 0x06 /* Public */,
       7,    0,   64,    2, 0x06 /* Public */,
       8,    0,   65,    2, 0x06 /* Public */,
       9,    0,   66,    2, 0x06 /* Public */,
      10,    1,   67,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,    2,

       0        // eod
};

void ContactListener::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ContactListener *_t = static_cast<ContactListener *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->topBasketHit(); break;
        case 1: _t->botBasketHit(); break;
        case 2: _t->ballOutOfBounds(); break;
        case 3: _t->rimHit(); break;
        case 4: _t->backboardHit(); break;
        case 5: _t->bounceSound(); break;
        case 6: _t->obstacleHit(); break;
        case 7: _t->ballHitsBall(); break;
        case 8: _t->dynamiteHit((*reinterpret_cast< b2Body*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ContactListener::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ContactListener::topBasketHit)) {
                *result = 0;
            }
        }
        {
            typedef void (ContactListener::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ContactListener::botBasketHit)) {
                *result = 1;
            }
        }
        {
            typedef void (ContactListener::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ContactListener::ballOutOfBounds)) {
                *result = 2;
            }
        }
        {
            typedef void (ContactListener::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ContactListener::rimHit)) {
                *result = 3;
            }
        }
        {
            typedef void (ContactListener::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ContactListener::backboardHit)) {
                *result = 4;
            }
        }
        {
            typedef void (ContactListener::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ContactListener::bounceSound)) {
                *result = 5;
            }
        }
        {
            typedef void (ContactListener::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ContactListener::obstacleHit)) {
                *result = 6;
            }
        }
        {
            typedef void (ContactListener::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ContactListener::ballHitsBall)) {
                *result = 7;
            }
        }
        {
            typedef void (ContactListener::*_t)(b2Body * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ContactListener::dynamiteHit)) {
                *result = 8;
            }
        }
    }
}

const QMetaObject ContactListener::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ContactListener.data,
      qt_meta_data_ContactListener,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ContactListener::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ContactListener::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ContactListener.stringdata0))
        return static_cast<void*>(const_cast< ContactListener*>(this));
    if (!strcmp(_clname, "b2ContactListener"))
        return static_cast< b2ContactListener*>(const_cast< ContactListener*>(this));
    return QObject::qt_metacast(_clname);
}

int ContactListener::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void ContactListener::topBasketHit()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void ContactListener::botBasketHit()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void ContactListener::ballOutOfBounds()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void ContactListener::rimHit()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void ContactListener::backboardHit()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void ContactListener::bounceSound()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void ContactListener::obstacleHit()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void ContactListener::ballHitsBall()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}

// SIGNAL 8
void ContactListener::dynamiteHit(b2Body * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_END_MOC_NAMESPACE
