/****************************************************************************
** Meta object code from reading C++ file 'diagnosis.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "diagnosis.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'diagnosis.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Diagnosis_t {
    QByteArrayData data[13];
    char stringdata0[124];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Diagnosis_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Diagnosis_t qt_meta_stringdata_Diagnosis = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Diagnosis"
QT_MOC_LITERAL(1, 10, 8), // "sendDiag"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 3), // "msg"
QT_MOC_LITERAL(4, 24, 4), // "init"
QT_MOC_LITERAL(5, 29, 11), // "instantiate"
QT_MOC_LITERAL(6, 41, 7), // "symptom"
QT_MOC_LITERAL(7, 49, 13), // "push_on_stack"
QT_MOC_LITERAL(8, 63, 27), // "determine_member_concl_list"
QT_MOC_LITERAL(9, 91, 6), // "varble"
QT_MOC_LITERAL(10, 98, 13), // "isInsantiated"
QT_MOC_LITERAL(11, 112, 3), // "var"
QT_MOC_LITERAL(12, 116, 7) // "yesOrNo"

    },
    "Diagnosis\0sendDiag\0\0msg\0init\0instantiate\0"
    "symptom\0push_on_stack\0determine_member_concl_list\0"
    "varble\0isInsantiated\0var\0yesOrNo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Diagnosis[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   52,    2, 0x08 /* Private */,
       5,    1,   53,    2, 0x08 /* Private */,
       7,    0,   56,    2, 0x08 /* Private */,
       8,    1,   57,    2, 0x08 /* Private */,
      10,    1,   60,    2, 0x08 /* Private */,
      12,    1,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Bool, QMetaType::QString,   11,
    QMetaType::QString, QMetaType::QString,    3,

       0        // eod
};

void Diagnosis::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Diagnosis *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendDiag((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->init(); break;
        case 2: _t->instantiate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->push_on_stack(); break;
        case 4: _t->determine_member_concl_list((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: { bool _r = _t->isInsantiated((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: { QString _r = _t->yesOrNo((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Diagnosis::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Diagnosis::sendDiag)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Diagnosis::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Diagnosis.data,
    qt_meta_data_Diagnosis,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Diagnosis::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Diagnosis::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Diagnosis.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Diagnosis::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Diagnosis::sendDiag(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
