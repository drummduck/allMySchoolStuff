/****************************************************************************
** Meta object code from reading C++ file 'soundsystem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../edu-app-team-boujee/soundsystem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'soundsystem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SoundSystem_t {
    QByteArrayData data[17];
    char stringdata0[208];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SoundSystem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SoundSystem_t qt_meta_stringdata_SoundSystem = {
    {
QT_MOC_LITERAL(0, 0, 11), // "SoundSystem"
QT_MOC_LITERAL(1, 12, 11), // "playSuccess"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 10), // "playBounce"
QT_MOC_LITERAL(4, 36, 7), // "playYay"
QT_MOC_LITERAL(5, 44, 10), // "playBallin"
QT_MOC_LITERAL(6, 55, 13), // "playExplosion"
QT_MOC_LITERAL(7, 69, 14), // "playLoginMusic"
QT_MOC_LITERAL(8, 84, 15), // "playLevelSelect"
QT_MOC_LITERAL(9, 100, 15), // "playLessonMusic"
QT_MOC_LITERAL(10, 116, 12), // "playOneMusic"
QT_MOC_LITERAL(11, 129, 12), // "playTwoMusic"
QT_MOC_LITERAL(12, 142, 14), // "playThreeMusic"
QT_MOC_LITERAL(13, 157, 13), // "playFourMusic"
QT_MOC_LITERAL(14, 171, 13), // "playFiveMusic"
QT_MOC_LITERAL(15, 185, 12), // "playSixMusic"
QT_MOC_LITERAL(16, 198, 9) // "playExtra"

    },
    "SoundSystem\0playSuccess\0\0playBounce\0"
    "playYay\0playBallin\0playExplosion\0"
    "playLoginMusic\0playLevelSelect\0"
    "playLessonMusic\0playOneMusic\0playTwoMusic\0"
    "playThreeMusic\0playFourMusic\0playFiveMusic\0"
    "playSixMusic\0playExtra"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SoundSystem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x0a /* Public */,
       3,    0,   90,    2, 0x0a /* Public */,
       4,    0,   91,    2, 0x0a /* Public */,
       5,    0,   92,    2, 0x0a /* Public */,
       6,    0,   93,    2, 0x0a /* Public */,
       7,    0,   94,    2, 0x0a /* Public */,
       8,    0,   95,    2, 0x0a /* Public */,
       9,    0,   96,    2, 0x0a /* Public */,
      10,    0,   97,    2, 0x0a /* Public */,
      11,    0,   98,    2, 0x0a /* Public */,
      12,    0,   99,    2, 0x0a /* Public */,
      13,    0,  100,    2, 0x0a /* Public */,
      14,    0,  101,    2, 0x0a /* Public */,
      15,    0,  102,    2, 0x0a /* Public */,
      16,    0,  103,    2, 0x0a /* Public */,

 // slots: parameters
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
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SoundSystem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SoundSystem *_t = static_cast<SoundSystem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->playSuccess(); break;
        case 1: _t->playBounce(); break;
        case 2: _t->playYay(); break;
        case 3: _t->playBallin(); break;
        case 4: _t->playExplosion(); break;
        case 5: _t->playLoginMusic(); break;
        case 6: _t->playLevelSelect(); break;
        case 7: _t->playLessonMusic(); break;
        case 8: _t->playOneMusic(); break;
        case 9: _t->playTwoMusic(); break;
        case 10: _t->playThreeMusic(); break;
        case 11: _t->playFourMusic(); break;
        case 12: _t->playFiveMusic(); break;
        case 13: _t->playSixMusic(); break;
        case 14: _t->playExtra(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject SoundSystem::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SoundSystem.data,
      qt_meta_data_SoundSystem,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SoundSystem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SoundSystem::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SoundSystem.stringdata0))
        return static_cast<void*>(const_cast< SoundSystem*>(this));
    return QObject::qt_metacast(_clname);
}

int SoundSystem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
