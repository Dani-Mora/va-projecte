/****************************************************************************
** Meta object code from reading C++ file 'lightform.h'
**
** Created: Fri Jun 3 17:30:21 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../lightform.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lightform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_lightForm[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   11,   10,   10, 0x05,
      44,   42,   10,   10, 0x05,
      64,   62,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      85,   10,   10,   10, 0x0a,
      99,   10,   10,   10, 0x0a,
     114,   10,   10,   10, 0x0a,
     129,   11,   10,   10, 0x0a,
     151,   42,   10,   10, 0x0a,
     173,  171,   10,   10, 0x0a,
     189,  187,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_lightForm[] = {
    "lightForm\0\0r,g,b\0updateColor(int,int,int)\0"
    "h\0updateHeight(int)\0b\0updateActivate(bool)\0"
    "changeColor()\0changeHeight()\0"
    "changeEncesa()\0setColor(int,int,int)\0"
    "setHeightValue(int)\0l\0setTitle(int)\0"
    "a\0setActivateLight(bool)\0"
};

const QMetaObject lightForm::staticMetaObject = {
    { &QTabWidget::staticMetaObject, qt_meta_stringdata_lightForm,
      qt_meta_data_lightForm, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &lightForm::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *lightForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *lightForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_lightForm))
        return static_cast<void*>(const_cast< lightForm*>(this));
    return QTabWidget::qt_metacast(_clname);
}

int lightForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateColor((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: updateHeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: updateActivate((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: changeColor(); break;
        case 4: changeHeight(); break;
        case 5: changeEncesa(); break;
        case 6: setColor((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 7: setHeightValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: setTitle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: setActivateLight((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void lightForm::updateColor(int _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void lightForm::updateHeight(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void lightForm::updateActivate(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
