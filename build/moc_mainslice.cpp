/****************************************************************************
** Meta object code from reading C++ file 'mainslice.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CakeHeap_For_Mac/mainslice.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainslice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainSlice_t {
    QByteArrayData data[3];
    char stringdata0[23];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainSlice_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainSlice_t qt_meta_stringdata_MainSlice = {
    {
QT_MOC_LITERAL(0, 0, 9), // "MainSlice"
QT_MOC_LITERAL(1, 10, 11), // "updateLabel"
QT_MOC_LITERAL(2, 22, 0) // ""

    },
    "MainSlice\0updateLabel\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainSlice[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void MainSlice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainSlice *_t = static_cast<MainSlice *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateLabel(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MainSlice::staticMetaObject = {
    { &QPieSlice::staticMetaObject, qt_meta_stringdata_MainSlice.data,
      qt_meta_data_MainSlice,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainSlice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainSlice::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainSlice.stringdata0))
        return static_cast<void*>(const_cast< MainSlice*>(this));
    return QPieSlice::qt_metacast(_clname);
}

int MainSlice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPieSlice::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
