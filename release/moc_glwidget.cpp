/****************************************************************************
** Meta object code from reading C++ file 'glwidget.h'
**
** Created: Fri Jun 14 11:04:54 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../interface/glwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'glwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GLWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      60,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      14,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   10,    9,    9, 0x05,
      62,   55,    9,    9, 0x05,
      97,    9,    9,    9, 0x05,
     123,  113,    9,    9, 0x05,
     157,  146,    9,    9, 0x05,
     180,    9,    9,    9, 0x05,
     197,    9,    9,    9, 0x05,
     219,  215,    9,    9, 0x05,
     253,  247,    9,    9, 0x05,
     285,  279,    9,    9, 0x05,
     310,  304,    9,    9, 0x05,
     330,    9,    9,    9, 0x05,
     350,    9,    9,    9, 0x05,
     368,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
     387,  385,    9,    9, 0x0a,
     404,  402,    9,    9, 0x0a,
     418,  385,    9,    9, 0x0a,
     434,  385,    9,    9, 0x0a,
     456,  454,    9,    9, 0x0a,
     470,  113,    9,    9, 0x0a,
     499,  146,    9,    9, 0x0a,
     528,  525,    9,    9, 0x0a,
     548,  543,    9,    9, 0x0a,
     563,    9,    9,    9, 0x0a,
     586,  525,    9,    9, 0x0a,
     613,    9,    9,    9, 0x0a,
     631,  402,    9,    9, 0x0a,
     661,  654,    9,    9, 0x0a,
     691,  402,    9,    9, 0x0a,
     715,  713,    9,    9, 0x0a,
     761,  402,    9,    9, 0x0a,
     796,  385,    9,    9, 0x0a,
     825,  819,    9,    9, 0x0a,
     857,  819,    9,    9, 0x0a,
     889,  819,    9,    9, 0x0a,
     926,  922,    9,    9, 0x0a,
     962,  958,    9,    9, 0x0a,
     997,  993,    9,    9, 0x0a,
    1037, 1031,    9,    9, 0x0a,
    1064, 1031,    9,    9, 0x0a,
    1096, 1031,    9,    9, 0x0a,
    1126,  454,    9,    9, 0x0a,
    1158, 1156,    9,    9, 0x0a,
    1185,  385,    9,    9, 0x0a,
    1212,  385,    9,    9, 0x0a,
    1242,  385,    9,    9, 0x0a,
    1285, 1272,    9,    9, 0x0a,
    1305,  385,    9,    9, 0x0a,
    1336,  454,    9,    9, 0x0a,
    1367,    9,    9,    9, 0x0a,
    1393, 1389,    9,    9, 0x0a,
    1407,  215,    9,    9, 0x0a,
    1438,    9, 1434,    9, 0x0a,
    1463,    9, 1456,    9, 0x0a,
    1495,    9, 1474,    9, 0x0a,
    1533,    9, 1513,    9, 0x0a,
    1569, 1550,    9,    9, 0x0a,
    1605,    9, 1434,    9, 0x0a,
    1618,  304,    9,    9, 0x0a,
    1643,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GLWidget[] = {
    "GLWidget\0\0objects\0"
    "listingObjects(std::vector<Object*>)\0"
    "lights\0listingLights(std::vector<Light*>)\0"
    "getCamEye(Vec4)\0eye,at,up\0"
    "getCam(Vec4,Vec4,Vec4)\0projection\0"
    "updateProjection(Vec4)\0widgetWidth(int)\0"
    "widgetHeight(int)\0obj\0showObjectSelected(Object*)\0"
    "light\0showLightSelected(Light*)\0state\0"
    "stateSelected(int)\0value\0setProgressRay(int)\0"
    "showSample(QImage*)\0radiusDOF(double)\0"
    "focalDOF(double)\0b\0showGrid(bool)\0i\0"
    "sizeGrid(int)\0solidGrid(bool)\0"
    "showViewports(bool)\0s\0showHBB(bool)\0"
    "updateCamera(Vec4,Vec4,Vec4)\0"
    "updateProjectionOut(Vec4)\0id\0"
    "setObject(int)\0type\0addObject(int)\0"
    "removeObjectSelected()\0"
    "setMaterialAllObjects(int)\0setDefaultWorld()\0"
    "setSelectedObject(int)\0motion\0"
    "setMotionObjectSelected(Vec4)\0"
    "setSelectedLight(int)\0m\0"
    "setTransformMatrixToObjectSelected(Matrix4x4)\0"
    "setIdMaterialToObjectSelected(int)\0"
    "setLightSelected(bool)\0color\0"
    "setLightSelectedDiffuse(QColor)\0"
    "setLightSelectedAmbient(QColor)\0"
    "setLightSelectedSpecular(QColor)\0dir\0"
    "setLightSelectedDirection(Vec4)\0pos\0"
    "setLightSelectedPosition(Vec4)\0att\0"
    "setLightSelectedAttenuation(Vec4)\0"
    "angle\0setLightSelectedAngle(int)\0"
    "setLightSelectedAngleInner(int)\0"
    "setLightSelectedExponent(int)\0"
    "setLightSelectedName(QString)\0a\0"
    "setLightSelectedVecA(Vec4)\0"
    "setLightSelectedVecB(Vec4)\0"
    "setEnabledLightSelected(bool)\0"
    "setVisibleLightSelected(bool)\0"
    "radius,focal\0setDOF(float,float)\0"
    "setEnabledObjectSelected(bool)\0"
    "setNameObjectSelected(QString)\0"
    "removeLightSelected()\0val\0addLight(int)\0"
    "setSelectedObject(Object*)\0int\0"
    "getItemSelected()\0Scene*\0getScene()\0"
    "std::vector<Object*>\0getObjectsScene()\0"
    "std::vector<Light*>\0getLightsScene()\0"
    "qw,percent,samples\0"
    "renderScene(QGraphicsView*,int,int)\0"
    "numberRays()\0setValueProgressRay(int)\0"
    "showSampleRender(QImage*)\0"
};

void GLWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GLWidget *_t = static_cast<GLWidget *>(_o);
        switch (_id) {
        case 0: _t->listingObjects((*reinterpret_cast< std::vector<Object*>(*)>(_a[1]))); break;
        case 1: _t->listingLights((*reinterpret_cast< std::vector<Light*>(*)>(_a[1]))); break;
        case 2: _t->getCamEye((*reinterpret_cast< Vec4(*)>(_a[1]))); break;
        case 3: _t->getCam((*reinterpret_cast< Vec4(*)>(_a[1])),(*reinterpret_cast< Vec4(*)>(_a[2])),(*reinterpret_cast< Vec4(*)>(_a[3]))); break;
        case 4: _t->updateProjection((*reinterpret_cast< Vec4(*)>(_a[1]))); break;
        case 5: _t->widgetWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->widgetHeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->showObjectSelected((*reinterpret_cast< Object*(*)>(_a[1]))); break;
        case 8: _t->showLightSelected((*reinterpret_cast< Light*(*)>(_a[1]))); break;
        case 9: _t->stateSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->setProgressRay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->showSample((*reinterpret_cast< QImage*(*)>(_a[1]))); break;
        case 12: _t->radiusDOF((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->focalDOF((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->showGrid((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->sizeGrid((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->solidGrid((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->showViewports((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->showHBB((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->updateCamera((*reinterpret_cast< Vec4(*)>(_a[1])),(*reinterpret_cast< Vec4(*)>(_a[2])),(*reinterpret_cast< Vec4(*)>(_a[3]))); break;
        case 20: _t->updateProjectionOut((*reinterpret_cast< Vec4(*)>(_a[1]))); break;
        case 21: _t->setObject((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->addObject((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->removeObjectSelected(); break;
        case 24: _t->setMaterialAllObjects((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->setDefaultWorld(); break;
        case 26: _t->setSelectedObject((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->setMotionObjectSelected((*reinterpret_cast< Vec4(*)>(_a[1]))); break;
        case 28: _t->setSelectedLight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->setTransformMatrixToObjectSelected((*reinterpret_cast< Matrix4x4(*)>(_a[1]))); break;
        case 30: _t->setIdMaterialToObjectSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->setLightSelected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 32: _t->setLightSelectedDiffuse((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 33: _t->setLightSelectedAmbient((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 34: _t->setLightSelectedSpecular((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 35: _t->setLightSelectedDirection((*reinterpret_cast< Vec4(*)>(_a[1]))); break;
        case 36: _t->setLightSelectedPosition((*reinterpret_cast< Vec4(*)>(_a[1]))); break;
        case 37: _t->setLightSelectedAttenuation((*reinterpret_cast< Vec4(*)>(_a[1]))); break;
        case 38: _t->setLightSelectedAngle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 39: _t->setLightSelectedAngleInner((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 40: _t->setLightSelectedExponent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 41: _t->setLightSelectedName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 42: _t->setLightSelectedVecA((*reinterpret_cast< Vec4(*)>(_a[1]))); break;
        case 43: _t->setLightSelectedVecB((*reinterpret_cast< Vec4(*)>(_a[1]))); break;
        case 44: _t->setEnabledLightSelected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 45: _t->setVisibleLightSelected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 46: _t->setDOF((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 47: _t->setEnabledObjectSelected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 48: _t->setNameObjectSelected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 49: _t->removeLightSelected(); break;
        case 50: _t->addLight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 51: _t->setSelectedObject((*reinterpret_cast< Object*(*)>(_a[1]))); break;
        case 52: { int _r = _t->getItemSelected();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 53: { Scene* _r = _t->getScene();
            if (_a[0]) *reinterpret_cast< Scene**>(_a[0]) = _r; }  break;
        case 54: { std::vector<Object*> _r = _t->getObjectsScene();
            if (_a[0]) *reinterpret_cast< std::vector<Object*>*>(_a[0]) = _r; }  break;
        case 55: { std::vector<Light*> _r = _t->getLightsScene();
            if (_a[0]) *reinterpret_cast< std::vector<Light*>*>(_a[0]) = _r; }  break;
        case 56: _t->renderScene((*reinterpret_cast< QGraphicsView*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 57: { int _r = _t->numberRays();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 58: _t->setValueProgressRay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 59: _t->showSampleRender((*reinterpret_cast< QImage*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GLWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GLWidget::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_GLWidget,
      qt_meta_data_GLWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GLWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GLWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GLWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GLWidget))
        return static_cast<void*>(const_cast< GLWidget*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int GLWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 60)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 60;
    }
    return _id;
}

// SIGNAL 0
void GLWidget::listingObjects(std::vector<Object*> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GLWidget::listingLights(std::vector<Light*> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GLWidget::getCamEye(Vec4 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GLWidget::getCam(Vec4 _t1, Vec4 _t2, Vec4 _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void GLWidget::updateProjection(Vec4 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void GLWidget::widgetWidth(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void GLWidget::widgetHeight(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void GLWidget::showObjectSelected(Object * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void GLWidget::showLightSelected(Light * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void GLWidget::stateSelected(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void GLWidget::setProgressRay(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void GLWidget::showSample(QImage * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void GLWidget::radiusDOF(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void GLWidget::focalDOF(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}
QT_END_MOC_NAMESPACE
