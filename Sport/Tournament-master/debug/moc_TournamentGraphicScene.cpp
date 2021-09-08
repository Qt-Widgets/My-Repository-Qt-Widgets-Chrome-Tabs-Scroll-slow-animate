/****************************************************************************
** Meta object code from reading C++ file 'TournamentGraphicScene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../TournamentGraphicScene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TournamentGraphicScene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TournamentGraphicScene_t {
    QByteArrayData data[11];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TournamentGraphicScene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TournamentGraphicScene_t qt_meta_stringdata_TournamentGraphicScene = {
    {
QT_MOC_LITERAL(0, 0, 22), // "TournamentGraphicScene"
QT_MOC_LITERAL(1, 23, 11), // "itemClicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 6), // "Match*"
QT_MOC_LITERAL(4, 43, 5), // "match"
QT_MOC_LITERAL(5, 49, 7), // "Player*"
QT_MOC_LITERAL(6, 57, 6), // "winner"
QT_MOC_LITERAL(7, 64, 15), // "settingsPressed"
QT_MOC_LITERAL(8, 80, 16), // "addPlayerPressed"
QT_MOC_LITERAL(9, 97, 13), // "requestUpdate"
QT_MOC_LITERAL(10, 111, 13) // "onItemClicked"

    },
    "TournamentGraphicScene\0itemClicked\0\0"
    "Match*\0match\0Player*\0winner\0settingsPressed\0"
    "addPlayerPressed\0requestUpdate\0"
    "onItemClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TournamentGraphicScene[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       7,    0,   44,    2, 0x06 /* Public */,
       8,    0,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   46,    2, 0x08 /* Private */,
      10,    2,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,

       0        // eod
};

void TournamentGraphicScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TournamentGraphicScene *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->itemClicked((*reinterpret_cast< Match*(*)>(_a[1])),(*reinterpret_cast< Player*(*)>(_a[2]))); break;
        case 1: _t->settingsPressed(); break;
        case 2: _t->addPlayerPressed(); break;
        case 3: _t->requestUpdate(); break;
        case 4: _t->onItemClicked((*reinterpret_cast< Match*(*)>(_a[1])),(*reinterpret_cast< Player*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TournamentGraphicScene::*)(Match * , Player * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TournamentGraphicScene::itemClicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TournamentGraphicScene::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TournamentGraphicScene::settingsPressed)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TournamentGraphicScene::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TournamentGraphicScene::addPlayerPressed)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TournamentGraphicScene::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsScene::staticMetaObject>(),
    qt_meta_stringdata_TournamentGraphicScene.data,
    qt_meta_data_TournamentGraphicScene,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TournamentGraphicScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TournamentGraphicScene::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TournamentGraphicScene.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsScene::qt_metacast(_clname);
}

int TournamentGraphicScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void TournamentGraphicScene::itemClicked(Match * _t1, Player * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TournamentGraphicScene::settingsPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void TournamentGraphicScene::addPlayerPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
