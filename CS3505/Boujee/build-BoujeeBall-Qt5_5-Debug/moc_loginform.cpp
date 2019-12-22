/****************************************************************************
** Meta object code from reading C++ file 'loginform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../edu-app-team-boujee/loginform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loginform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LoginForm_t {
    QByteArrayData data[27];
    char stringdata0[397];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LoginForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LoginForm_t qt_meta_stringdata_LoginForm = {
    {
QT_MOC_LITERAL(0, 0, 9), // "LoginForm"
QT_MOC_LITERAL(1, 10, 17), // "createUserTeacher"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 8), // "username"
QT_MOC_LITERAL(4, 38, 8), // "password"
QT_MOC_LITERAL(5, 47, 15), // "updateUserLevel"
QT_MOC_LITERAL(6, 63, 5), // "level"
QT_MOC_LITERAL(7, 69, 17), // "deleteUserTeacher"
QT_MOC_LITERAL(8, 87, 8), // "openItUp"
QT_MOC_LITERAL(9, 96, 11), // "loginActive"
QT_MOC_LITERAL(10, 108, 11), // "enableLogin"
QT_MOC_LITERAL(11, 120, 10), // "modeSelect"
QT_MOC_LITERAL(12, 131, 10), // "modeCancel"
QT_MOC_LITERAL(13, 142, 24), // "handleCreateTeacherClick"
QT_MOC_LITERAL(14, 167, 24), // "handleUpdateTeacherClick"
QT_MOC_LITERAL(15, 192, 24), // "handleDeleteTeacherClick"
QT_MOC_LITERAL(16, 217, 21), // "handleBackButtonClick"
QT_MOC_LITERAL(17, 239, 19), // "handleOpenAnalytics"
QT_MOC_LITERAL(18, 259, 15), // "clickedUsername"
QT_MOC_LITERAL(19, 275, 15), // "clickedPassword"
QT_MOC_LITERAL(20, 291, 22), // "clickedCreateUserAdmin"
QT_MOC_LITERAL(21, 314, 26), // "clickedCreatePasswordAdmin"
QT_MOC_LITERAL(22, 341, 18), // "clickedUpdateAdmin"
QT_MOC_LITERAL(23, 360, 18), // "clickedDeleteAdmin"
QT_MOC_LITERAL(24, 379, 7), // "setEcho"
QT_MOC_LITERAL(25, 387, 3), // "tab"
QT_MOC_LITERAL(26, 391, 5) // "enter"

    },
    "LoginForm\0createUserTeacher\0\0username\0"
    "password\0updateUserLevel\0level\0"
    "deleteUserTeacher\0openItUp\0loginActive\0"
    "enableLogin\0modeSelect\0modeCancel\0"
    "handleCreateTeacherClick\0"
    "handleUpdateTeacherClick\0"
    "handleDeleteTeacherClick\0handleBackButtonClick\0"
    "handleOpenAnalytics\0clickedUsername\0"
    "clickedPassword\0clickedCreateUserAdmin\0"
    "clickedCreatePasswordAdmin\0"
    "clickedUpdateAdmin\0clickedDeleteAdmin\0"
    "setEcho\0tab\0enter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LoginForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  124,    2, 0x06 /* Public */,
       5,    2,  129,    2, 0x06 /* Public */,
       7,    1,  134,    2, 0x06 /* Public */,
       8,    0,  137,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,  138,    2, 0x0a /* Public */,
      10,    0,  139,    2, 0x0a /* Public */,
      11,    0,  140,    2, 0x0a /* Public */,
      12,    0,  141,    2, 0x0a /* Public */,
      13,    0,  142,    2, 0x0a /* Public */,
      14,    0,  143,    2, 0x0a /* Public */,
      15,    0,  144,    2, 0x0a /* Public */,
      16,    0,  145,    2, 0x0a /* Public */,
      17,    0,  146,    2, 0x0a /* Public */,
      18,    0,  147,    2, 0x08 /* Private */,
      19,    0,  148,    2, 0x08 /* Private */,
      20,    0,  149,    2, 0x08 /* Private */,
      21,    0,  150,    2, 0x08 /* Private */,
      22,    0,  151,    2, 0x08 /* Private */,
      23,    0,  152,    2, 0x08 /* Private */,
      24,    0,  153,    2, 0x08 /* Private */,
      25,    0,  154,    2, 0x08 /* Private */,
      26,    0,  155,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    6,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LoginForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LoginForm *_t = static_cast<LoginForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->createUserTeacher((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->updateUserLevel((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->deleteUserTeacher((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->openItUp(); break;
        case 4: _t->loginActive(); break;
        case 5: _t->enableLogin(); break;
        case 6: _t->modeSelect(); break;
        case 7: _t->modeCancel(); break;
        case 8: _t->handleCreateTeacherClick(); break;
        case 9: _t->handleUpdateTeacherClick(); break;
        case 10: _t->handleDeleteTeacherClick(); break;
        case 11: _t->handleBackButtonClick(); break;
        case 12: _t->handleOpenAnalytics(); break;
        case 13: _t->clickedUsername(); break;
        case 14: _t->clickedPassword(); break;
        case 15: _t->clickedCreateUserAdmin(); break;
        case 16: _t->clickedCreatePasswordAdmin(); break;
        case 17: _t->clickedUpdateAdmin(); break;
        case 18: _t->clickedDeleteAdmin(); break;
        case 19: _t->setEcho(); break;
        case 20: _t->tab(); break;
        case 21: _t->enter(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LoginForm::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoginForm::createUserTeacher)) {
                *result = 0;
            }
        }
        {
            typedef void (LoginForm::*_t)(QString , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoginForm::updateUserLevel)) {
                *result = 1;
            }
        }
        {
            typedef void (LoginForm::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoginForm::deleteUserTeacher)) {
                *result = 2;
            }
        }
        {
            typedef void (LoginForm::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoginForm::openItUp)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject LoginForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LoginForm.data,
      qt_meta_data_LoginForm,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LoginForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoginForm::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LoginForm.stringdata0))
        return static_cast<void*>(const_cast< LoginForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int LoginForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void LoginForm::createUserTeacher(QString _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LoginForm::updateUserLevel(QString _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void LoginForm::deleteUserTeacher(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void LoginForm::openItUp()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
