#ifndef RAYTRACING_H
#define RAYTRACING_H

#include "vec4.h"
class Ray;
class Scene;
class Object;
class Light;
class Material;
struct Face;
class GLWidget;
class HBB;
class RayTracing
{
public:
    RayTracing();
    RayTracing(Scene* scene,GLWidget *rcast,Vec4 color,bool otimized=true);
    void rayTracing(QImage *pixels, int proportion, int samples);
    void   setScene(Scene* scene);
    void   rayTracing(GLubyte* pixels);                              //retorna a matrix de pixels
    Vec4   rayIntersection(Ray ray);                                 //retorna a cor do pixel final a partir do raio lançado de forma otimizada
    Vec4   rayIntersectionSecond(Ray ray);                                 //retorna a cor do pixel final a partir do raio lançado de forma otimizada
    Vec4   calculatePixelColor(Object *obj,Vec4 normal,Material* material,Vec4 intercept, Ray v); //calcula a iluminação na forma otimizada passando o ponto interseptado, seu vetor normal e o material do objeto
    Vec4   testObstruction(Ray ray);
    Ray    depthOfField(Vec4 pixel,float radius,float distancefocus);
    static Object* objectClicked(Scene* scn,int width,int height);   //retorna o objeto selecionado no clique da tela
    static Object* getObject(Ray ray, Scene *scene);

    ~RayTracing();
public:
    Scene* scene;
    GLWidget *raycast;
    Vec4 backgroundcolor;
    bool otimized;
    HBB  *hierachicalbb;
    bool withhbb;


};
#endif // RAYTRACING_H
