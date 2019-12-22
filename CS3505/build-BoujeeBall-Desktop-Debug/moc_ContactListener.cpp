/****************************************************************************
** Meta object code from reading C++ file 'ContactListener.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../edu-app-team-boujee/ContactListener.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ContactListener.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ContactListener[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,
      32,   16,   16,   16, 0x05,
      47,   16,   16,   16, 0x05,
      65,   16,   16,   16, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ContactListener[] = {
    "ContactListener\0\0topBasketHit()\0"
    "botBasketHit()\0ballOutOfBounds()\0"
    "ballBounce()\0"
};

void ContactListener::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ContactListener *_t = static_cast<ContactListener *>(_o);
        switch (_id) {
        case 0: _t->topBasketHit(); break;
        case 1: _t->botBasketHit(); break;
        case 2: _t->ballOutOfBounds(); break;
        case 3: _t->ballBounce(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ContactListener::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ContactListener::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ContactListener,
      qt_meta_data_ContactListener, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ContactListener::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ContactListener::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ContactListener::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ContactListener))
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
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ContactListener::topBasketHit()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ContactListener::botBasketHit()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void ContactListener::ballOutOfBounds()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void ContactListener::ballBounce()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
