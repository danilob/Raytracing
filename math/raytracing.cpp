#include "raytracing.h"
#include "interface/scene.h"
#include "math/ray.h"
#include "block/object.h"
#include "structure/light.h"
#include "rayintersection.h"
<<<<<<< HEAD
#include "block/hbb.h"
=======

>>>>>>> 490f827284db0ec9110c12375bcf57acbf56b06a
#define ERROR 0.001
#include "interface/castingwidget.h"
static int intersect =0;
static int notintersect =0;
#include <stdio.h>
#include <stdlib.h> // RAND_MAX é definido em stdlib.h
static int depth = 0;
static bool in = false;
#define myrand ((float)(random())/(float)(RAND_MAX) )

RayTracing::RayTracing()
{
    this->scene = NULL;
    this->raycast = NULL;
}

RayTracing::RayTracing(Scene *sc,CastingWidget *rcast,Vec4 color,bool otimized)
{
    this->scene = sc;//
    this->raycast = rcast;
    this->backgroundcolor = color;//
    this->otimized = otimized;
}

void RayTracing::setScene(Scene *scene)
{
    this->scene = scene;
}

void RayTracing::rayTracing(GLubyte *pixels)
{
    //pixels = new GLubyte [(int)scene->viewport[0]*(int)scene->viewport[1]*3];
    srandom(time(NULL));
    Matrix4x4 changetoviewer;
    changetoviewer.setIdentity();
    Vec4 kv,iv,jv,kvl,ivl,jvl;
    kv = (scene->viewer[0] - scene->viewer[1])/((scene->viewer[0] - scene->viewer[1]).module());
    iv = (scene->viewer[2] ^ kv)/(scene->viewer[2] ^ kv).module();
    jv = (kv ^ iv)/(kv ^ iv).module();
    ivl.setVec4(iv.x1,jv.x1,kv.x1);
    jvl.setVec4(iv.x2,jv.x2,kv.x2);
    kvl.setVec4(iv.x3,jv.x3,kv.x3);
    Vec4 translate(-(iv*scene->viewer[0]),-(jv*scene->viewer[0]),-(kv*scene->viewer[0]));

    changetoviewer.setAxisX(iv);
    changetoviewer.setAxisY(jv);
    changetoviewer.setAxisZ(kv);
    changetoviewer.setTranslate(translate);

    //changetoviewer.showMatrix4x4();
    //changetoviewer.transpose().vector(Vec4(0,0,0)).showVec4();
    changetoviewer = changetoviewer.transpose();
    changetoviewer.setTranslate(scene->viewer[0]);


    Vec4 color[scene->viewport[0]*scene->viewport[1]];


    float h = 2.0*scene->projection.x3*(tan(M_PI*scene->projection.x1/360.0));
    float w = h*scene->projection.x2;
    float deltax = w/scene->viewport[0];
    float deltay = h/scene->viewport[1];
    notintersect = 0;
    intersect = 0;
    int count = 0;
<<<<<<< HEAD
    int soft = 20;
=======
    int soft = 50;
>>>>>>> 490f827284db0ec9110c12375bcf57acbf56b06a
    for(int j=0;j<scene->viewport[1];j++)
        for (int i=0;i<scene->viewport[0];i++){
            Vec4 rays_color;
            for(int k=0;k<soft;k++){
                float alfa,beta;
                if(k==0){
                    alfa  = -w/2.0 + deltax/2.0  + i*deltax;
                    beta  = -h/2.0 + deltay/2.0 + j*deltay;
                }else{
                    alfa  = -w/2.0 + deltax*myrand  + i*deltax;
                    beta  = -h/2.0 + deltay*myrand + j*deltay;
                }

                Vec4 dir(alfa,beta,-scene->projection.x3);
                Ray ray(changetoviewer.transpose().vector(Vec4(0,0,0)),changetoviewer.transpose().vector(dir));
                ray.setDirection((ray.direction - ray.origin).unitary());
                rays_color = rays_color + rayIntersection(ray);
                depth = 0;
            }
            count++;
            raycast->setValueProgress(count);
            rays_color = rays_color / soft;
            color[(scene->viewport[0]*j)+(i)] = rays_color;
            in = false;
//            if (otimized) color[(scene->viewport[0]*j)+(i)] = rayIntersection(ray);
//            else color[(scene->viewport[0]*j)+(i)] = rayIntersectionNotOtimized(ray);
        }

    for(int i=0;i<scene->viewport[0]*scene->viewport[1];i++){
        pixels[3*i]   = ((int)(color[i].x1*255))%256;
        pixels[3*i+1] = ((int)(color[i].x2*255))%256;
        pixels[3*i+2] = ((int)(color[i].x3*255))%256;
    }
    //printf("hits: %d",hit);

}



Vec4 RayTracing::rayIntersection(Ray ray)
{

        RayIntersection *ray_intersection = new RayIntersection();
        Object *obj = NULL;
<<<<<<< HEAD
        //float aux = scene->projection.x4;
        ray_intersection->t = scene->projection.x4;
        ray_intersection->tmin = scene->projection.x3;
        bool hit  = hierachicalbb->HBBIntersection(ray_intersection,ray,obj);
        obj = ray_intersection->obj;
        //Object *obj = &aux2;
        //obj = ray_intersection->obj;
//        for(int i=0;i<scene->objects.size();i++){

//            if(scene->objects.at(i)->isEnabled()){
//                scene->objects.at(i)->tryIntersection(ray_intersection,ray);
//            }
//            if (ray_intersection->t<aux){
//                obj = scene->objects.at(i);
//                aux = ray_intersection->t;
//            }

//        }
        //printf("\nt=%.8f",ray_intersection->t);
        if (!(hit)){
=======
        float aux = scene->projection.x4;
        ray_intersection->t = scene->projection.x4;
        ray_intersection->tmin = scene->projection.x3;
        for(int i=0;i<scene->objects.size();i++){

            if(scene->objects.at(i)->isEnabled()){
                scene->objects.at(i)->tryIntersection(ray_intersection,ray);
            }
            if (ray_intersection->t<aux){
                obj = scene->objects.at(i);
                aux = ray_intersection->t;
            }

        }
        if (!(ray_intersection->t!=scene->projection.x4)){
>>>>>>> 490f827284db0ec9110c12375bcf57acbf56b06a
            notintersect++;
            //raycast->setValueNotIntersectRay(notintersect);
            //delete obj;
            delete ray_intersection;
            return this->backgroundcolor;
        }else{
            intersect++;
            //raycast->setValueIntersectRay(intersect);
            Vec4 pixel = calculatePixelColor(obj,ray_intersection->normal,ray_intersection->material,ray.positionRay(ray_intersection->t),ray);
<<<<<<< HEAD
            //printf("\nNome: %s",obj->getName().toLocal8Bit().data());
=======
>>>>>>> 490f827284db0ec9110c12375bcf57acbf56b06a
            delete ray_intersection;
            //delete obj;
            return pixel;
        }

}

<<<<<<< HEAD
Vec4 RayTracing::rayIntersectionSecond(Ray ray)
{
    RayIntersection *ray_intersection = new RayIntersection();
    Object *obj = NULL;
    float aux = scene->projection.x4;
    ray_intersection->t = scene->projection.x4;
    ray_intersection->tmin = 0.01;
    for(int i=0;i<scene->objects.size();i++){

        if(scene->objects.at(i)->isEnabled()){
            scene->objects.at(i)->tryIntersection(ray_intersection,ray);
        }
        if (ray_intersection->t<aux){
            obj = scene->objects.at(i);
            aux = ray_intersection->t;
        }

    }
    if (!(ray_intersection->t!=scene->projection.x4)){
        notintersect++;
        //raycast->setValueNotIntersectRay(notintersect);
        //delete obj;
        delete ray_intersection;
        return this->backgroundcolor;
    }else{
        intersect++;
        //raycast->setValueIntersectRay(intersect);
        Vec4 pixel = calculatePixelColor(obj,ray_intersection->normal,ray_intersection->material,ray.positionRay(ray_intersection->t),ray);
        delete ray_intersection;
        //delete obj;
        return pixel;
    }
}

=======
>>>>>>> 490f827284db0ec9110c12375bcf57acbf56b06a

Vec4 RayTracing::calculatePixelColor(Object *obj,Vec4 normal, Material *material, Vec4 intercept,Ray r)
{

        Vec4 color = Vec4(0,0,0);
        Vec4 aux = Vec4(0,0,0);
        int raios = 1;
        //double fator =1.0;
        for (int i=1;i<scene->lights.size();i++){
            obj->setEnabled(false);
            for (int k=0; k<raios;k++){
<<<<<<< HEAD
                Vec4 l = scene->lights.at(i)->randLight();
                Vec4 v = (r.direction);
                Vec4 ri = v - normal*(2*(v*normal));
                ri = ri.unitary();
                Ray raio = Ray(intercept,(l - intercept).unitary());
                //Vec4 refl = inter(normal*((l*normal)*2) - l);
                Ray reflt = Ray(intercept,((ri)));
                if (scene->lights.at(i)->isEnabled())
                    /* testar se a direção do ponto observado a luz está obstruido */
                    if (!(testObstruction(raio))){
                        aux = aux + scene->lights.at(i)->calculateColor(intercept,normal,scene->viewer[0],material,l);//*(1-material->transp);

                    }
                obj->setEnabled(true);
                if(material->refl!=0 && depth<20){
                    depth++;
                    aux = aux + (rayIntersection(reflt))*material->refl;
                }
                if(material->transp<=1 && material->transp>0 && depth<20){
                    depth++;

                    float ratio;
                    if(in){
                        ratio = material->transp;
                        normal = normal*(-1);
                    }else{
                        ratio = 1.0/material->transp;
                    }
                    float cosi = (v*normal)*(-1);
                    float fat = 1 - (pow(ratio,2)*(1 - cosi*cosi));
                    if (fat < 0) return Vec4();
                    Vec4 refra = v*(ratio) +normal*((ratio*cosi)-sqrt(fat));
                    refra = refra.unitary();
                    Ray refrt(intercept,refra);
                    if (in){
                        in = false;
                    }else{
                        in = true;
                    }
                    aux = aux + (rayIntersection(refrt))*material->transp;
                }
=======
            Vec4 l = scene->lights.at(i)->randLight();
            Vec4 v = (r.direction);
            Vec4 ri = normal*(2*(v*normal)) - v;
            ri = ri.unitary();
            Ray raio = Ray(intercept,(l - intercept).unitary());
            //Vec4 refl = inter(normal*((l*normal)*2) - l);
            Ray reflt = Ray(intercept,((ri)));
            if (scene->lights.at(i)->isEnabled())
                /* testar se a direção do ponto observado a luz está obstruido */
                if (!(testObstruction(raio))){
                    aux = aux + scene->lights.at(i)->calculateColor(intercept,normal,scene->viewer[0],material,l)*(1-material->transp);

                }
            obj->setEnabled(true);
            if(material->refl!=0){
                //depth++;
                aux = aux + (rayIntersection(reflt))*material->refl;
            }
            if(material->transp<=1 && material->transp>0){
                //depth++;

                float ratio;
                if(in){
                    ratio = material->transp;
                    normal = normal*(-1);
                }else{
                    ratio = 1.0/material->transp;
                }
                float cosi = (v*normal)*(-1);
                float fat = 1 - (pow(ratio,2)*(1 - cosi*cosi));
                if (fat < 0) return Vec4();
                Vec4 refra = v*(ratio) +normal*((ratio*cosi)-sqrt(fat));
                refra = refra.unitary();
                Ray refrt(intercept,refra);
                if (in){
                    in = false;
                }else{
                    in = true;
                }
                aux = aux + (rayIntersection(refrt))*material->transp;
            }
>>>>>>> 490f827284db0ec9110c12375bcf57acbf56b06a

            }


            color = color + aux/raios;
            //aux = Vec4();


        }

        color = color + scene->lights.at(0)->calculateColor(intercept,normal,scene->viewer[0],material,Vec4());
        color.x1 = fmin(color.x1,1.0);
        color.x2 = fmin(color.x2,1.0);
        color.x3 = fmin(color.x3,1.0);

        return color;
}

bool RayTracing::testObstruction(Ray ray)
{
    RayIntersection *ray_intersection = new RayIntersection();
    ray_intersection->t = INFINITY;
<<<<<<< HEAD
    ray_intersection->tmin = 0;
=======
    ray_intersection->tmin = -1;
>>>>>>> 490f827284db0ec9110c12375bcf57acbf56b06a
    for(int i=0;i<scene->objects.size();i++){

        if(scene->objects.at(i)->isEnabled()) scene->objects.at(i)->tryIntersection(ray_intersection,ray);

    }
    if ((ray_intersection->t!=INFINITY)){
         delete ray_intersection;
         return true;
    }
    delete ray_intersection;
    return false;
}

Vec4 RayTracing::rayReflect(Ray ray)//reflexao
{
}

Vec4 RayTracing::rayRefract(Ray ray)//transparencia
{
}

RayTracing::~RayTracing()
{
     delete[]scene;
    delete[]raycast;
}





