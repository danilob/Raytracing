#ifndef RAYINTERSECTION_H
#define RAYINTERSECTION_H
#include "math/vec4.h"
#include "structure/mesh.h"

<<<<<<< HEAD

class Ray;
class Object;
=======
class Ray;

>>>>>>> 490f827284db0ec9110c12375bcf57acbf56b06a
class Material;

class RayIntersection
{
public:
    RayIntersection();
<<<<<<< HEAD
    void rayBoxIntersection(Mesh *mesh, Ray ray,Matrix4x4 transform,Vec4 max,Vec4 min,Object *obj);
    void rayPlanIntersection(Mesh *mesh, Ray ray,Object *obj);
    void rayCylinderIntersection(Mesh *mesh,Matrix4x4 transform, Ray ray,Object *obj);
    void raySphereIntersection(Mesh *mesh, Matrix4x4 transform, Ray ray, Object *obj);
    void rayHemiSphereIntersection(Mesh *mesh, Matrix4x4 transform, Ray ray,Object *obj);
=======
    void rayBoxIntersection(Mesh *mesh, Ray ray,Matrix4x4 transform,Vec4 max,Vec4 min);
    void rayPlanIntersection(Mesh *mesh, Ray ray);
    void rayCylinderIntersection(Mesh *mesh,Matrix4x4 transform, Ray ray);
    void raySphereIntersection(Mesh *mesh, Matrix4x4 transform, Ray ray);
    void rayHemiSphereIntersection(Mesh *mesh, Matrix4x4 transform, Ray ray);
>>>>>>> 490f827284db0ec9110c12375bcf57acbf56b06a
    void rayPlaneIntersection(Face face,Ray ray);
    ~RayIntersection();
public:
    float t,tmin;
    Vec4 normal;
    Material *material;
<<<<<<< HEAD
    Object *obj;
=======
>>>>>>> 490f827284db0ec9110c12375bcf57acbf56b06a



};

#endif // RAYINTERSECTION_H
