#include "raytracing.h"
#include "interface/scene.h"
#include "math/ray.h"
#include "block/object.h"
#include "structure/light.h"
#include "rayintersection.h"
#include "block/hbb.h"
#define ERROR 0.001
#include "interface/glwidget.h"
#include <omp.h>
static int max_depth = 4;
static float distLight = 0;
static int intersect =0;
static int notintersect =0;
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h> // RAND_MAX é definido em stdlib.h
static int depth = 0;
static bool in = false;


#define myrand ((float)(random())/(float)(RAND_MAX) )

RayTracing::RayTracing()
{
    this->scene = NULL;
    this->raycast = NULL;
}

RayTracing::RayTracing(Scene *sc,GLWidget *rcast,Vec4 color,bool otimized)
{
    this->scene = sc;//
    this->raycast = rcast;
    this->backgroundcolor = color;//
    this->otimized = otimized;
    withhbb = false;
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
    int soft = 20;
    double ti,tf,tempo; // ti = tempo inicial // tf = tempo final
      ti = tf = tempo = 0;
      timeval tempo_inicio,tempo_fim;
      gettimeofday(&tempo_inicio,NULL);
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
                //Ray dof = depthOfField(dir,2.0,50);
                //Ray ray(changetoviewer.transpose().vector(dof.origin),changetoviewer.transpose().vector(dof.direction));
                Ray ray(changetoviewer.transpose().vector(Vec4(0,0,0)),changetoviewer.transpose().vector(dir));
                ray.setDirection((ray.direction - ray.origin).unitary());
                rays_color = rays_color + rayIntersection(ray);
                depth = 0;
                in = false;
            }

            count++;
            //raycast->setValueProgress(count);
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
void RayTracing::rayTracing(QImage *pixels, int proportion,int samples)
{
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


    //Vec4 color[scene->viewport[0]*scene->viewport[1]];
    int height = (int)(scene->viewport[1]*(proportion/100.0));
    int width = (int)(scene->viewport[0]*(proportion/100.0));

    float h = 2.0*scene->projection.x3*(tan(M_PI*scene->projection.x1/360.0));
    float w = h*scene->projection.x2;
    float deltax = w/width;
    float deltay = h/height;
    notintersect = 0;
    intersect = 0;
    int count = 0;
        double ti,tf,tempo; // ti = tempo inicial // tf = tempo final
          ti = tf = tempo = 0;
          timeval tempo_inicio,tempo_fim;
          gettimeofday(&tempo_inicio,NULL);
    float alfa,beta;
    omp_set_num_threads(8);
    int c = (height/omp_get_num_threads()*width);
    Vec4 dir;
    Ray ray;
    QRgb value;
    Vec4 rays_color = Vec4();

    #pragma omp parallel for schedule(dynamic,c) collapse(3)
    for(int j=0;j<height;j++){
        for (int i=0;i<width;i++){

            for(int k=0;k<samples;k++){
                if(samples==0){
                    alfa  = -w/2.0 + deltax/2.0  + i*deltax;
                    beta  = -h/2.0 + deltay/2.0 + j*deltay;
                }else{
                    alfa  = -w/2.0 + deltax*myrand  + i*deltax;
                    beta  = -h/2.0 + deltay*myrand + j*deltay;
                }

                dir.setVec4(alfa,beta,-scene->projection.x3);
                //Ray dof = depthOfField(dir,2.0,50);
                //Ray ray(changetoviewer.transpose().vector(dof.origin),changetoviewer.transpose().vector(dof.direction));
                ray.setOrigin(changetoviewer.transpose().vector(Vec4(0,0,0)));
                ray.setDirection(changetoviewer.transpose().vector(dir));
                ray.setDirection((ray.direction - ray.origin).unitary());
                #pragma omp reduction(+:rays_color)
                {
                rays_color = rays_color + rayIntersection(ray);
                }
                depth = 0;
                in = false;
                if(samples-1==k){
//                    #pragma omp atomic
//                    count++;
//                    raycast->setValueProgressRay(count);
               #pragma omp critical
                    {
                    rays_color = rays_color / samples;
                }
                    //color[(scene->viewport[0]*j)+(i)] = rays_color;
                    value = qRgb(rays_color.x()*255, rays_color.y()*255,rays_color.z()*255);
                    pixels->setPixel(i,height-(j+1),value);
                #pragma omp critical
                {
                    rays_color = Vec4();
                }
                }


            }
            //#pragma omp barrier


        }
    }
    gettimeofday(&tempo_fim,NULL);
      tf = (double)tempo_fim.tv_usec + ((double)tempo_fim.tv_sec * (1000000.0));
      ti = (double)tempo_inicio.tv_usec + ((double)tempo_inicio.tv_sec * (1000000.0));
      tempo = (tf - ti)/1000000;
      printf("Tempo gasto em segundos %.3f\n",tempo);

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
        for (int i=1;i<scene->lights.size();i++){   
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


//                if(material->refl!=0 && depth<max_depth){
//                    depth++;
//                    aux = aux + (rayIntersection(Ray::rayReflect(intercept,r.direction,normal)))*material->refl;
//                }
//                if(material->transp!=0 && depth<max_depth){
//                    depth++;
//                    float n1 = 1.0;
//                    float n2 = 1.5;
//                    float reflectance = Ray::reflectance(v,normal,n1,n2);
//                    aux = aux  + (rayIntersection(Ray::rayReflect(intercept,r.direction,normal)))*(reflectance);
//                    aux = aux  + (rayIntersection(Ray::rayRefract(intercept,r.direction,normal,n1,n2)))*material->transp*(1-reflectance);//*fabs(1-kr);
//                }


                }
                obj->setEnabled(true);




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

Object *RayTracing::objectClicked(Scene *scn, int width, int height)
{
    Matrix4x4 changetoviewer;
    changetoviewer.setIdentity();
    Vec4 kv,iv,jv,kvl,ivl,jvl;
    kv = (scn->viewer[0] - scn->viewer[1])/((scn->viewer[0] - scn->viewer[1]).module());
    iv = (scn->viewer[2] ^ kv)/(scn->viewer[2] ^ kv).module();
    jv = (kv ^ iv)/(kv ^ iv).module();
    ivl.setVec4(iv.x1,jv.x1,kv.x1);
    jvl.setVec4(iv.x2,jv.x2,kv.x2);
    kvl.setVec4(iv.x3,jv.x3,kv.x3);
    Vec4 translate(-(iv*scn->viewer[0]),-(jv*scn->viewer[0]),-(kv*scn->viewer[0]));

    changetoviewer.setAxisX(iv);
    changetoviewer.setAxisY(jv);
    changetoviewer.setAxisZ(kv);
    changetoviewer.setTranslate(translate);

    changetoviewer = changetoviewer.transpose();
    changetoviewer.setTranslate(scn->viewer[0]);





    float h = 2.0*scn->projection.x3*(tan(M_PI*scn->projection.x1/360.0));
    float w = h*scn->projection.x2;
    float deltax = w/scn->viewport[0];
    float deltay = h/scn->viewport[1];

    int j = height;
    int i = width;


    float alfa,beta;

    alfa  = -w/2.0 + deltax/2.0  + i*deltax;
    beta  = -h/2.0 + deltay/2.0 + j*deltay;


    Vec4 dir(alfa,beta,-scn->projection.x3);
    Ray ray(changetoviewer.transpose().vector(Vec4(0,0,0)),changetoviewer.transpose().vector(dir));
    ray.setDirection((ray.direction - ray.origin).unitary());

    return getObject(ray,scn);
}

Object* RayTracing::getObject(Ray ray,Scene* scene)
{
    RayIntersection *ray_intersection = new RayIntersection();
    Object *obj = NULL;
    HBB *hierachicalbb = new HBB(scene->objects,1);
    //float aux = scene->projection.x4;
    ray_intersection->t = scene->projection.x4;
    ray_intersection->tmin = 0;
    bool hit = hierachicalbb->HBBIntersection(ray_intersection,ray,obj);
    if (hit) return ray_intersection->obj;
    //delete hierachicalbb;
    return NULL;

}

RayTracing::~RayTracing()
{
     delete[]scene;
    delete[]raycast;
}





