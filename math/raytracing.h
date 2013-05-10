#ifndef RAYTRACING_H
#define RAYTRACING_H

#include "vec4.h"
class Ray;
class Scene;
class Object;
class Light;
class Material;
struct Face;
class CastingWidget;
class HBB;
class RayTracing
{
public:
    RayTracing();
    RayTracing(Scene* scene,CastingWidget *rcast,Vec4 color,bool otimized=true);
    void   setScene(Scene* scene);
    void   rayTracing(GLubyte* pixels);                              //retorna a matrix de pixels
    Vec4   rayIntersection(Ray ray);                                 //retorna a cor do pixel final a partir do raio lançado de forma otimizada
    Vec4   rayIntersectionSecond(Ray ray);                                 //retorna a cor do pixel final a partir do raio lançado de forma otimizada
    Vec4   calculatePixelColor(Object *obj,Vec4 normal,Material* material,Vec4 intercept, Ray v); //calcula a iluminação na forma otimizada passando o ponto interseptado, seu vetor normal e o material do objeto
    bool   testObstruction(Ray ray);
    Vec4   rayReflect(Ray ray);
    Vec4   rayRefract(Ray ray);
    ~RayTracing();
public:
    Scene* scene;
    CastingWidget *raycast;
    Vec4 backgroundcolor;
    bool otimized;
    HBB  *hierachicalbb;


};
#endif // RAYTRACING_H
