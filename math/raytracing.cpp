#include "raytracing.h"
#include "interface/scene.h"
#include "math/ray.h"
#include "block/object.h"
#include "structure/light.h"
#include "rayintersection.h"
#include "block/hbb.h"
#define ERROR 0.001
#include "interface/castingwidget.h"
static int max_depth = 4;
static float distLight = 0;
static int intersect =0;
static int notintersect =0;
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h> // RAND_MAX é definido em stdlib.h
static int depth = 0;
static bool in = false;
static bool withhbb = true;

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
    int soft = 100;
    double ti,tf,tempo; // ti = tempo inicial // tf = tempo final
      ti = tf = tempo = 0;
      timeval tempo_inicio,tempo_fim;
      gettimeofday(&tempo_inicio,NULL);
    for(int j=0;j<scene->viewport[1];j++)
        for (int i=0;i<scene->viewport[0];i++){
            Vec4 rays_color;
            //teste de motion blur
            Vec4 position0 = scene->objects.at(0)->getMatrixTransformation().getTranslateSeted();
            Vec4 rotate0 = scene->objects.at(0)->getMatrixTransformation().getRotationSeted();
            Vec4 scale0 = scene->objects.at(0)->getMatrixTransformation().getScaleSeted();

            Vec4 position1 = scene->objects.at(1)->getMatrixTransformation().getTranslateSeted();
            Vec4 rotate1 = scene->objects.at(1)->getMatrixTransformation().getRotationSeted();
            Vec4 scale1 = scene->objects.at(1)->getMatrixTransformation().getScaleSeted();

            Vec4 position2 = scene->objects.at(2)->getMatrixTransformation().getTranslateSeted();
            Vec4 rotate2 = scene->objects.at(2)->getMatrixTransformation().getRotationSeted();
            Vec4 scale2 = scene->objects.at(2)->getMatrixTransformation().getScaleSeted();


            for(int k=0;k<soft;k++){
                Matrix4x4 new_mat;
                new_mat.setIdentity();
                Vec4 nextposition2 = position2+Vec4(0,-2,0);
                Vec4 newposition2 = position2 + (nextposition2 - position2)*myrand;
                new_mat.scale(scale2.x(),scale2.y(),scale2.z());
                new_mat.setRotationX(rotate2.x());
                new_mat.setRotationY(rotate2.y());
                new_mat.setRotationZ(rotate2.z());
                new_mat.setTranslate(newposition2);
                scene->objects.at(2)->setTransform(new_mat);
                new_mat.setIdentity();
                Vec4 nextposition0 = position0+Vec4(0,-2,0);
                Vec4 newposition0 = position0 + (nextposition0 - position0)*myrand;
                new_mat.scale(scale0.x(),scale0.y(),scale0.z());
                new_mat.setRotationX(rotate0.x());
                new_mat.setRotationY(rotate0.y());
                new_mat.setRotationZ(rotate0.z());
                new_mat.setTranslate(newposition0);
                scene->objects.at(0)->setTransform(new_mat);
                new_mat.setIdentity();
                Vec4 nextposition1 = position1+Vec4(0,-1.5,0);
                Vec4 newposition1 = position1 + (nextposition1- position1)*myrand;
                new_mat.scale(scale1.x(),scale1.y(),scale1.z());
                new_mat.setRotationX(rotate1.x());
                new_mat.setRotationY(rotate1.y());
                new_mat.setRotationZ(rotate1.z());
                new_mat.setTranslate(newposition1);
                scene->objects.at(1)->setTransform(new_mat);



                float alfa,beta;
                if(k==0){
                    alfa  = -w/2.0 + deltax/2.0  + i*deltax;
                    beta  = -h/2.0 + deltay/2.0 + j*deltay;
                }else{
                    alfa  = -w/2.0 + deltax*myrand  + i*deltax;
                    beta  = -h/2.0 + deltay*myrand + j*deltay;
                }

                Vec4 dir(alfa,beta,-scene->projection.x3);
                //Ray dof = depthOfField(dir,2.0,50);
                //Ray ray(changetoviewer.transpose().vector(dof.origin),changetoviewer.transpose().vector(dof.direction));
                Ray ray(changetoviewer.transpose().vector(Vec4(0,0,0)),changetoviewer.transpose().vector(dir));
                ray.setDirection((ray.direction - ray.origin).unitary());

                rays_color = rays_color + rayIntersection(ray);
                depth = 0;
                in = false;
                new_mat.setIdentity();
                new_mat.scale(scale0.x(),scale0.y(),scale0.z());
                new_mat.setRotationX(rotate0.x());
                new_mat.setRotationY(rotate0.y());
                new_mat.setRotationZ(rotate0.z());
                new_mat.setTranslate(position0);
                scene->objects.at(0)->setTransform(new_mat);
                new_mat.setIdentity();
                new_mat.scale(scale1.x(),scale1.y(),scale1.z());
                new_mat.setRotationX(rotate1.x());
                new_mat.setRotationY(rotate1.y());
                new_mat.setRotationZ(rotate1.z());
                new_mat.setTranslate(position1);
                scene->objects.at(1)->setTransform(new_mat);
                new_mat.setIdentity();
                new_mat.scale(scale2.x(),scale2.y(),scale2.z());
                new_mat.setRotationX(rotate2.x());
                new_mat.setRotationY(rotate2.y());
                new_mat.setRotationZ(rotate2.z());
                new_mat.setTranslate(position2);
                scene->objects.at(2)->setTransform(new_mat);
            }

            count++;
            raycast->setValueProgress(count);
            rays_color = rays_color / soft;
            color[(scene->viewport[0]*j)+(i)] = rays_color;

//            if (otimized) color[(scene->viewport[0]*j)+(i)] = rayIntersection(ray);
//            else color[(scene->viewport[0]*j)+(i)] = rayIntersectionNotOtimized(ray);
        }

    for(int i=0;i<scene->viewport[0]*scene->viewport[1];i++){
        pixels[3*i]   = ((int)(color[i].x1*255))%256;
        pixels[3*i+1] = ((int)(color[i].x2*255))%256;
        pixels[3*i+2] = ((int)(color[i].x3*255))%256;
    }
    gettimeofday(&tempo_fim,NULL);
      tf = (double)tempo_fim.tv_usec + ((double)tempo_fim.tv_sec * (1000000.0));
      ti = (double)tempo_inicio.tv_usec + ((double)tempo_inicio.tv_sec * (1000000.0));
      tempo = (tf - ti)/1000000;
      printf("Tempo gasto em segundos %.3f\n",tempo);
    //printf("hits: %d",hit);

}



Vec4 RayTracing::rayIntersection(Ray ray)
{

        RayIntersection *ray_intersection = new RayIntersection();
        Object *obj = NULL;
        //float aux = scene->projection.x4;
        ray_intersection->t = scene->projection.x4;
        ray_intersection->tmin = 0;
        if (withhbb){
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
            notintersect++;
            //raycast->setValueNotIntersectRay(notintersect);
            //delete obj;
            delete ray_intersection;
            return this->backgroundcolor;
        }else{
            intersect++;
            //raycast->setValueIntersectRay(intersect);
            Vec4 pixel = calculatePixelColor(obj,ray_intersection->normal,ray_intersection->material,ray.positionRay(ray_intersection->t),ray);
            //printf("\nNome: %s",obj->getName().toLocal8Bit().data());
            delete ray_intersection;
            //delete obj;
            return pixel;
        }
        }else{
            //Object *obj = &aux2;
            //obj = ray_intersection->obj;
            float aux = scene->projection.x4;

            for(int i=0;i<scene->objects.size();i++){

                if(scene->objects.at(i)->isEnabled()){
                    scene->objects.at(i)->tryIntersection(ray_intersection,ray);
                }
                if (ray_intersection->t<aux){
                    obj = scene->objects.at(i);
                    aux = ray_intersection->t;
                }

            }
            //printf("\nt=%.8f",ray_intersection->t);
            if (ray_intersection->normal==Vec4()){
                notintersect++;
                //raycast->setValueNotIntersectRay(notintersect);
                //delete obj;
                delete ray_intersection;
                return this->backgroundcolor;
            }else{
                intersect++;
                //raycast->setValueIntersectRay(intersect);
                Vec4 pixel = calculatePixelColor(obj,ray_intersection->normal,ray_intersection->material,ray.positionRay(ray_intersection->t),ray);
                //printf("\nNome: %s",obj->getName().toLocal8Bit().data());
                delete ray_intersection;
                //delete obj;
                return pixel;
            }
        }

}

Vec4 RayTracing::rayIntersectionSecond(Ray ray)
{
    RayIntersection *ray_intersection = new RayIntersection();
    Object *obj = NULL;
    float aux = scene->projection.x4;
    ray_intersection->t = scene->projection.x4;
    ray_intersection->tmin = 0;
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


Vec4 RayTracing::calculatePixelColor(Object *obj,Vec4 normal, Material *material, Vec4 intercept,Ray r)
{

        Vec4 color = Vec4(0,0,0);
        Vec4 aux = Vec4(0,0,0);
        int raios = 1;
        //double fator =1.0;
        for (int i=1;i<scene->lights.size();i++){

            for (int k=0; k<raios;k++){
                obj->setEnabled(false);
                Vec4 l = scene->lights.at(i)->randLight();
                Vec4 v = (r.direction);
               if((v*(normal*(-1)))<0.0) normal = normal*(-1);


                distLight = (l - intercept).module();
                Ray raio = Ray(intercept,(l - intercept).unitary());
                //Vec4 refl = inter(normal*((l*normal)*2) - l);

                if (scene->lights.at(i)->isEnabled()){
                    /* testar se a direção do ponto observado a luz está obstruido */
                    if ((testObstruction(raio)==Vec4())){
                        //if(material->transp==0) aux = aux + scene->lights.at(i)->calculateColor(intercept,normal,scene->viewer[0],material,l);//*(1-material->transp);
                        aux = aux + scene->lights.at(i)->calculateColor(intercept,normal,scene->viewer[0],material,l);

                    }


                if(material->refl!=0 && depth<max_depth){
                    depth++;
                    aux = aux + (rayIntersection(Ray::rayReflect(intercept,r.direction,normal)))*material->refl;
                }
                if(material->transp!=0 && depth<max_depth){
                    depth++;
                    float n1 = 1.0;
                    float n2 = 1.5;
                    float reflectance = Ray::reflectance(v,normal,n1,n2);
                    aux = aux  + (rayIntersection(Ray::rayReflect(intercept,r.direction,normal)))*(reflectance);
                    aux = aux  + (rayIntersection(Ray::rayRefract(intercept,r.direction,normal,n1,n2)))*material->transp*(1-reflectance);//*fabs(1-kr);
                }


                }
                obj->setEnabled(true);

            }


            color = color + aux;
            //aux = Vec4();


        }

        color = color + scene->lights.at(0)->calculateColor(intercept,normal,scene->viewer[0],material,Vec4());
        color.x1 = fmin(color.x1,1.0);
        color.x2 = fmin(color.x2,1.0);
        color.x3 = fmin(color.x3,1.0);

        return color;
}

Vec4 RayTracing::testObstruction(Ray ray)
{
    RayIntersection *ray_intersection = new RayIntersection();
    ray_intersection->t = distLight;
    //ray_intersection->t = 1;
    ray_intersection->tmin = 0.0009;
    if (withhbb){
    bool hit  = hierachicalbb->HBBIntersection(ray_intersection,ray);
//    ray_intersection->tmin = 0;
//    for(int i=0;i<scene->objects.size();i++){

//        if(scene->objects.at(i)->isEnabled()) scene->objects.at(i)->tryIntersection(ray_intersection,ray);

//    }
    if (hit && ray_intersection->t<distLight){
         Vec4 Pintercept = ray.positionRay(ray_intersection->t);
         delete ray_intersection;
         return Pintercept;
    }
    }else{
            for(int i=0;i<scene->objects.size();i++){

                if(scene->objects.at(i)->isEnabled()) scene->objects.at(i)->tryIntersection(ray_intersection,ray);

            }
            if (ray_intersection->t<distLight && ray_intersection->normal!=Vec4()){
                 Vec4 Pintercept = ray.positionRay(ray_intersection->t);
                 delete ray_intersection;
                 return Pintercept;
            }

    }
    delete ray_intersection;
    return Vec4();
}

Ray RayTracing::depthOfField(Vec4 pixel,float radius, float distancefocus)
{
    float d = pixel.z();
    float f = -distancefocus;
    Vec4  p = Vec4(pixel.x()*(f/d),pixel.y()*(f/d),f);
    Vec4  o = Vec4(1,0,0)*(-radius/2)+Vec4(0,1,0)*(-radius/2)+Vec4(1,0,0)*radius*(myrand)+Vec4(0,1,0)*radius*(myrand);
    return Ray(o,p);


}


RayTracing::~RayTracing()
{
     delete[]scene;
    delete[]raycast;
}





