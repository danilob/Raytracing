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
int max_depth = 5;
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
    this->widget = NULL;
}

RayTracing::RayTracing(Scene *sc,GLWidget *rcast,Vec4 color,bool otimized)
{
    this->scene = sc;//
    this->widget = rcast;
    this->backgroundcolor = color;//
    this->otimized = otimized;
    withhbb = false;
}

void RayTracing::setScene(Scene *scene)
{
    this->scene = scene;
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


    changetoviewer = changetoviewer.transpose();
    changetoviewer.setTranslate(scene->viewer[0]);


    int height = (int)(scene->viewport[1]*(proportion/100.0));
    int width = (int)(scene->viewport[0]*(proportion/100.0));
    std::vector<Vec4> matriz;
    std::vector<Vec4> sum;
    sum.clear();
    matriz.clear();
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

    //int c = samples*width*height/omp_get_num_threads();
    int c =  (height / (8) * width) + (samples * (height/8) * width);
    Vec4 dir;
    Ray ray;
    QRgb value;
    //Vec4 rays_color = Vec4();

    for(unsigned int j=0;j<height;j++)
        for(unsigned int i=0;i<width;i++){
            matriz.push_back( Vec4(0,0,0));
        }

    int i,j,t;
    float znear = -scene->projection.x3;
    //se por acaso um objeto tiver o efeito motion blur sera desconsiderado o uso do hierarquical bounding boxes
    for (int i=0;i<scene->objects.size();i++)
        if(scene->objects.at(i)->getMotion()!=Vec4()) withhbb = false;
    //omp_set_num_threads(samples);
    //QImage image = QImage(scenewidth,sceneheight,QImage::Format_RGB32);
//#pragma omp parallel
//#pragma omp for  schedule(static,c) nowait private(i,j,alfa,beta,ray,dir,depth,in,val)  collapse(3)one) private(i,j,alfa,beta,ray,dir,depth,in,val) shared(count,znear,matriz,w,h,deltax,deltay,samples,changetoviewer,width,height) num_threads(samples)
    //{

    for (t=0;t<samples;t++){

    //#pragma omp barrier

        for(j=0;j<height;j++){
            for (i=0;i<width;i++){

                if(samples==0){
                    alfa  = -w/2.0 + deltax/2.0  + i*deltax;
                    beta  = -h/2.0 + deltay/2.0 + j*deltay;
                }else{
                    alfa  = -w/2.0 + deltax*myrand  + i*deltax;
                    beta  = -h/2.0 + deltay*myrand + j*deltay;
                }

                dir.setVec4(alfa,beta,znear);
                //teste para verificar se o cenário tem o efeito de depth of field
                if (!(scene->radius>0 && scene->focal>0)){
                    ray.setOrigin(changetoviewer.transpose().vector(Vec4(0,0,0)));
                    ray.setDirection(changetoviewer.transpose().vector(dir));
                }else{
                    Ray dof = depthOfField(dir,scene->radius,scene->focal);
                    ray.setOrigin(changetoviewer.transpose().vector(dof.origin));
                    ray.setDirection(changetoviewer.transpose().vector(dof.direction));
                }
                ray.setDirection((ray.direction - ray.origin).unitary());


                depth = 0;
                count++;
                widget->setValueProgressRay(count);
                in = false;
                //#pragma omp critical
                //#pragma omp reduction (+:matriz)
               // {
                    //val = rayIntersection(ray);
                //val = rayIntersection(ray);
               // #pragma omp critical

                    matriz.at(i+(j*width)) += rayIntersection(ray);

                    //if(val==Vec4()) count++;



                //}
            }
        }


//        for(j=0;j<height;j++)
//            for(i=0;i<width;i++)
//                sum.at(i+(j*width)) += matriz.at(i+(j*width));


    }
    //printf("Espaços negros: %d",count);
    gettimeofday(&tempo_fim,NULL);
      tf = (double)tempo_fim.tv_usec + ((double)tempo_fim.tv_sec * (1000000.0));
      ti = (double)tempo_inicio.tv_usec + ((double)tempo_inicio.tv_sec * (1000000.0));
      tempo = (tf - ti)/1000000;
      printf("Tempo gasto em segundos %.3f\n",tempo);

    for(int j=0;j<height;j++)
        for(int i =0;i<width;i++){
            matriz.at(i+(j*width)) /= samples;
            value = qRgb((matriz.at(i+(j*width)).x()*255),(matriz.at(i+(j*width)).y()*255),(matriz.at(i+(j*width)).z()*255));
            pixels->setPixel(i,height-(j+1),value);
        }
    widget->showSampleRender(pixels);


}




Vec4 RayTracing::rayIntersection(Ray ray)
{

        RayIntersection *ray_intersection = new RayIntersection();
        Object *obj = NULL;
        ray_intersection->t = scene->projection.x4;
        ray_intersection->tmin = 0;
        if (withhbb){
        bool hit  = hierachicalbb->HBBIntersection(ray_intersection,ray,obj);
        obj = ray_intersection->obj;

        if (!(hit)){
            delete ray_intersection;
            return this->backgroundcolor;
        }else{
            Vec4 pixel = calculatePixelColor(obj,ray_intersection->normal,ray_intersection->material,ray.positionRay(ray_intersection->t),ray);
            delete ray_intersection;
            return pixel;
        }
        }else{
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

            if (ray_intersection->normal==Vec4()){
                delete ray_intersection;
                return this->backgroundcolor;
            }else{
                Vec4 pixel = calculatePixelColor(obj,ray_intersection->normal,ray_intersection->material,ray.positionRay(ray_intersection->t),ray);
                delete ray_intersection;
                return pixel;
            }
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

                if (scene->lights.at(i)->isEnabled()){
                    /* testar se a direção do ponto observado a luz está obstruido */
                    if ((testObstruction(raio)==Vec4())){
                        aux = aux + scene->lights.at(i)->calculateColor(intercept,normal,scene->viewer[0],material,l);
                    }


                if((material->reflection>0 || material->glossyreflection>0) && depth<max_depth){
                    depth++;
                    if(material->glossyreflection>0)
                       aux = aux + (rayIntersection(Ray::rayReflectGlossy(intercept,r.direction,normal,1-material->getGlossyReflection())))*material->getReflection();
                    else
                       aux = aux + (rayIntersection(Ray::rayReflect(intercept,r.direction,normal)))*material->getReflection();

                }
                if(material->refraction>1 && depth<max_depth){
                    depth++;
                    float reflectance = Ray::reflectance(v,normal,1.0,material->getRefraction());
                    if (material->glossyrefraction>0){
                        aux = aux  + (rayIntersection(Ray::rayReflectGlossy(intercept,r.direction,normal,1-material->getGlossyRefraction())))*(reflectance);
                        aux = aux  + (rayIntersection(Ray::rayRefractGlossy(intercept,r.direction,normal,1,material->getRefraction(),1-material->getGlossyRefraction())))*(1-reflectance);//*fabs(1-kr);
                    }else{
                        aux = aux  + (rayIntersection(Ray::rayReflect(intercept,r.direction,normal)))*(reflectance);
                        aux = aux  + (rayIntersection(Ray::rayRefract(intercept,r.direction,normal,1,material->getRefraction())))*(1-reflectance);//*fabs(1-kr);
                    }
                }


                }
                obj->setEnabled(true);
                color = color + aux;


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
    ray_intersection->tmin = 0.0009;
    if (withhbb){
        bool hit  = hierachicalbb->HBBIntersection(ray_intersection,ray);

        if (hit && ray_intersection->t<distLight){
            Vec4 Pintercept = ray.positionRay(ray_intersection->t);
            delete ray_intersection;
            return Pintercept;
        }
    }else
    {
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
    ray_intersection->t = scene->projection.x4;
    ray_intersection->tmin = 0;
    bool hit = hierachicalbb->HBBIntersection(ray_intersection,ray,obj);
    if (hit) return ray_intersection->obj;
    return NULL;

}

RayTracing::~RayTracing()
{
     delete[]scene;
     delete[]widget;
}





