/****************************************************************************
** Meta object code from reading C++ file 'cronometre.h'
**
** Created:
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../crono/cronometre.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cronometre.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Cronometre[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      27,   11,   11,   11, 0x05,
      41,   11,   11,   11, 0x05,
      55,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      72,   11,   11,   11, 0x0a,
      80,   11,   11,   11, 0x0a,
      89,   11,   11,   11, 0x0a,
      98,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Cronometre[] = {
    "Cronometre\0\0iniciarCrono()\0pausarCrono()\0"
    "canviaColor()\0resetejarCrono()\0acaba()\0"
    "inicia()\0pausar()\0reinicia()\0"
};

const QMetaObject Cronometre::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Cronometre,
      qt_meta_data_Cronometre, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Cronometre::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Cronometre::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Cronometre::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Cronometre))
        return static_cast<void*>(const_cast< Cronometre*>(this));
    return QWidget::qt_metacast(_clname);
}

int Cronometre::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: iniciarCrono(); break;
        case 1: pausarCrono(); break;
        case 2: canviaColor(); break;
        case 3: resetejarCrono(); break;
        case 4: acaba(); break;
        case 5: inicia(); break;
        case 6: pausar(); break;
        case 7: reinicia(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Cronometre::iniciarCrono()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Cronometre::pausarCrono()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Cronometre::canviaColor()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Cronometre::resetejarCrono()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
