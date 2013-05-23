#ifndef RAYINTERSECTION_H
#define RAYINTERSECTION_H
#include "math/vec4.h"
#include "structure/mesh.h"


class Ray;
class Object;
class Material;

class RayIntersection
{
public:
    RayIntersection();
    void rayBoxIntersection(Mesh *mesh, Ray ray,Matrix4x4 transform,Vec4 max,Vec4 min,Object *obj);
    void rayPlanIntersection(Mesh *mesh, Ray ray,Object *obj);
    void rayCylinderIntersection(Mesh *mesh,Matrix4x4 transform, Ray ray,Object *obj);
    void rayConeIntersection(Mesh *mesh,Matrix4x4 transform, Ray ray,Object *obj);
    void raySphereIntersection(Mesh *mesh, Matrix4x4 transform, Ray ray, Object *obj);
    void rayHemiSphereIntersection(Mesh *mesh, Matrix4x4 transform, Ray ray,Object *obj);
    void rayPlaneIntersection(Face face,Ray ray);
    ~RayIntersection();
public:
    float t,tmin;
    Vec4 normal;
    Material *material;
    Object *obj;



};

#endif // RAYINTERSECTION_H
