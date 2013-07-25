/****************************************************************************
** Meta object code from reading C++ file 'castingwidget.h'
**
** Created: Thu Jul 25 03:16:19 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../interface/castingwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'castingwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CastingWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,
      32,   14,   14,   14, 0x05,
      53,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      77,   14,   14,   14, 0x0a,
      99,   14,   14,   14, 0x0a,
     125,   14,   14,   14, 0x0a,
     157,  154,   14,   14, 0x0a,
     178,   14,  174,   14, 0x0a,
     191,   14,   14,   14, 0x0a,
     215,  209,   14,   14, 0x0a,
     243,  241,   14,   14, 0x0a,
     265,  261,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CastingWidget[] = {
    "CastingWidget\0\0setProgress(int)\0"
    "setIntersectRay(int)\0setNotIntersectRay(int)\0"
    "setValueProgress(int)\0setValueIntersectRay(int)\0"
    "setValueNotIntersectRay(int)\0sc\0"
    "setScene(Scene*)\0int\0numberRays()\0"
    "testeRayCasting()\0color\0"
    "backgroudColorRay(QColor)\0b\0"
    "setOtimized(bool)\0str\0saveScreen(QString)\0"
};

void CastingWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CastingWidget *_t = static_cast<CastingWidget *>(_o);
        switch (_id) {
        case 0: _t->setProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setIntersectRay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setNotIntersectRay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setValueProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setValueIntersectRay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setValueNotIntersectRay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setScene((*reinterpret_cast< Scene*(*)>(_a[1]))); break;
        case 7: { int _r = _t->numberRays();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 8: _t->testeRayCasting(); break;
        case 9: _t->backgroudColorRay((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 10: _t->setOtimized((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->saveScreen((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CastingWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CastingWidget::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_CastingWidget,
      qt_meta_data_CastingWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CastingWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CastingWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CastingWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CastingWidget))
        return static_cast<void*>(const_cast< CastingWidget*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int CastingWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void CastingWidget::setProgress(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CastingWidget::setIntersectRay(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CastingWidget::setNotIntersectRay(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
