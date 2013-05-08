#ifndef RAYINTERSECTION_H
#define RAYINTERSECTION_H
#include "math/vec4.h"
#include "structure/mesh.h"

class Ray;

class Material;

class RayIntersection
{
public:
    RayIntersection();
    void rayBoxIntersection(Mesh *mesh, Ray ray,Matrix4x4 transform,Vec4 max,Vec4 min);
    void rayPlanIntersection(Mesh *mesh, Ray ray);
    void rayCylinderIntersection(Mesh *mesh,Matrix4x4 transform, Ray ray);
    void raySphereIntersection(Mesh *mesh, Matrix4x4 transform, Ray ray);
    void rayHemiSphereIntersection(Mesh *mesh, Matrix4x4 transform, Ray ray);
    void rayPlaneIntersection(Face face,Ray ray);
    ~RayIntersection();
public:
    float t,tmin;
    Vec4 normal;
    Material *material;



};

#endif // RAYINTERSECTION_H
