#include "rayintersection.h"
<<<<<<< HEAD
#include "block/object.h"
=======

>>>>>>> 490f827284db0ec9110c12375bcf57acbf56b06a
#include "math/ray.h"
#define APROXIMATE 0.001
bool teste = true;

//calculo para interseção ray-plane limitado
bool tryInterceptionPointFace(Face face, Vec4 point)
{
        Vec4 a,b,c,n; //coordenadas do triangulo
        for(int i=0;i<face.vertexs.size()-2;i++){
            n.setVec4(face.normals.at(0)->x1,face.normals.at(0)->x2,face.normals.at(0)->x3);
            a.setVec4(face.vertexs.at(0)->x1,face.vertexs.at(0)->x2,face.vertexs.at(0)->x3);
            b.setVec4(face.vertexs.at(i+1)->x1,face.vertexs.at(i+1)->x2,face.vertexs.at(i+1)->x3);
            c.setVec4(face.vertexs.at(i+2)->x1,face.vertexs.at(i+2)->x2,face.vertexs.at(i+2)->x3);
            if (Vec4::crossProduct((b-a),(point-a))*n > 0 && Vec4::crossProduct((c-b),(point-b))*n > 0 && Vec4::crossProduct((a-c),(point-c))*n > 0) return true;

        }
        return false;
}





RayIntersection::RayIntersection()
{
    this->t=INFINITY;
    this->tmin=0;
    this->normal = Vec4(0,0,0);
    this->material = new Material();
<<<<<<< HEAD
    //this->obj = NULL;
=======
>>>>>>> 490f827284db0ec9110c12375bcf57acbf56b06a


}

<<<<<<< HEAD
void RayIntersection::rayBoxIntersection(Mesh *mesh, Ray ray, Matrix4x4 transform,Vec4 max, Vec4 min,Object *obj)
{
    Vec4 bounds[2];
    bounds[0] = min;//Vec4(-0.5,-0.5,-0.5);
    bounds[1] = max;//Vec4(0.5,0.5,0.5);
=======
void RayIntersection::rayBoxIntersection(Mesh *mesh, Ray ray, Matrix4x4 transform,Vec4 max, Vec4 min)
{
    Vec4 bounds[2];
    bounds[0] = min;
    bounds[1] = max;
>>>>>>> 490f827284db0ec9110c12375bcf57acbf56b06a
    Ray copy;
    copy.setOrigin(transform.transform_origin_ray(transform,ray.origin));
    copy.setDirection(transform.transform_direction_ray(transform,ray.direction));
    float tmin, tmax, tymin, tymax, tzmin, tzmax;
    tmin = (bounds[copy.sign[0]].x() - copy.origin.x()) * copy.inverse_direction.x();
    tmax = (bounds[1-copy.sign[0]].x() - copy.origin.x()) * copy.inverse_direction.x();
    tymin = (bounds[copy.sign[1]].y() - copy.origin.y()) * copy.inverse_direction.y();
    tymax = (bounds[1-copy.sign[1]].y() - copy.origin.y()) * copy.inverse_direction.y();
    if ( (tmin > tymax) || (tymin > tmax) )
        return ;
    if (tymin > tmin)
        tmin = tymin;
    if (tymax < tmax)
        tmax = tymax;
    tzmin = (bounds[copy.sign[2]].z() - copy.origin.z()) * copy.inverse_direction.z();
    tzmax = (bounds[1-copy.sign[2]].z() - copy.origin.z()) * copy.inverse_direction.z();
    if ( (tmin > tzmax) || (tzmin > tmax) )
        return ;
    if (tzmin > tmin)
        tmin = tzmin;
    if (tzmax < tmax)
        tmax = tzmax;
    if (!( (tmin < t) && (tmax > tmin) )) return;

    for (int i=0;i<mesh->faces.size();i++){
        Vec4 p1,n;
        p1.setVec4(mesh->faces.at(i).vertexs[0]->x1,mesh->faces.at(i).vertexs[0]->x2,mesh->faces.at(i).vertexs[0]->x3);
        n.setVec4(mesh->faces.at(i).normals[0]->x(),mesh->faces.at(i).normals[0]->y(),mesh->faces.at(i).normals[0]->z());
        if ((!(fabs(n*(ray.direction))<APROXIMATE))){
            float t_ = (n*p1 - ray.origin*n)/(n*(ray.direction));
            if((t_<this->t) && t_>this->tmin){
                if (tryInterceptionPointFace(mesh->faces.at(i),ray.positionRay(t_))){
                    this->t = t_;
                    this->normal = n.unitary();
                    this->material->setMaterial(material,mesh->getMaterial());
<<<<<<< HEAD
                    this->obj = obj;
=======
>>>>>>> 490f827284db0ec9110c12375bcf57acbf56b06a
                }
            }
        }


    }
}

<<<<<<< HEAD
void RayIntersection::rayPlanIntersection(Mesh *mesh, Ray ray, Object *obj)
=======
void RayIntersection::rayPlanIntersection(Mesh *mesh, Ray ray)
>>>>>>> 490f827284db0ec9110c12375bcf57acbf56b06a
{
    Vec4 p1,n;
    p1.setVec4(mesh->faces.at(0).vertexs[0]->x1,mesh->faces.at(0).vertexs[0]->x2,mesh->faces.at(0).vertexs[0]->x3);
    n.setVec4(mesh->faces.at(0).normals[0]->x(),mesh->faces.at(0).normals[0]->y(),mesh->faces.at(0).normals[0]->z());
    if ((!(fabs(n*(ray.direction))<APROXIMATE))){
        float t_ = (n*p1 - ray.origin*n)/(n*(ray.direction));
        if((t_<this->t) && t_>this->tmin){
            if (tryInterceptionPointFace(mesh->faces.at(0),ray.positionRay(t_))){
                this->t = t_;
                this->normal = n.unitary();
                this->material->setMaterial(material,mesh->getMaterial());
<<<<<<< HEAD
                this->obj = obj;
=======
>>>>>>> 490f827284db0ec9110c12375bcf57acbf56b06a
            }
        }
    }
}

<<<<<<< HEAD
void RayIntersection::rayCylinderIntersection(Mesh *mesh,Matrix4x4 transform, Ray ray, Object *obj)
=======
void RayIntersection::rayCylinderIntersection(Mesh *mesh,Matrix4x4 transform, Ray ray)
>>>>>>> 490f827284db0ec9110c12375bcf57acbf56b06a
{

    Ray ray_copy;
    Ray line(Vec4(0,0.0,0),Vec4(0,1,0));

    ray_copy.setOrigin(transform.transform_origin_ray(transform,ray.origin));
    ray_copy.setDirection(transform.transform_direction_ray(transform,ray.direction));


    Vec4 cl = line.origin - line.direction*(line.origin*line.direction);
    Vec4 pl = ray_copy.origin - line.direction*(ray_copy.origin*line.direction);
    Vec4 dl = ray_copy.direction - line.direction*(ray_copy.direction*line.direction);

    float a,b,c,delta;

    a = dl*dl;
    b = (pl*dl - cl*pl)*2;
    c = pl*pl -2*(pl*cl) - cl*cl - 1.0;


        delta = b*b - 4*a*c;
        if (delta<0.0) return;
        float t0,t1;
        t0 = (-b-sqrt(delta))/(2*a);
        t1 = (-b+sqrt(delta))/(2*a);
        if (t1<t0){
            float aux;
            aux = t0;
            t0 = t1;
            t1 = aux;

        }
        if(t0<0.0) return;
        Vec4 pos = ray_copy.positionRay(t0);
        Vec4 lin = line.positionRay(sqrt(pow((pos-Vec4(0,0,0)).module(),2)-1));
        Vec4 n = (pos-Vec4(0,0,0)) - lin*(pos*lin);
        n = n.unitary();
        //

        if(pos.x2>1){
            n = Vec4(0,1,0);
            float est = (n*Vec4(0,1,0) - ray_copy.origin*n)/(n*(ray_copy.direction));
            if (est<0.0) return;
            Vec4 posi = ray_copy.positionRay(est);
            if (((posi.x()*posi.x() + posi.z()*posi.z())<=1)){
                t0 = est;
                pos = posi;
            }else{
                return;
            }
        }
        if(pos.x2<0){
            n = Vec4(0,-1,0);
            float est = (n*Vec4(0,0,0) - ray_copy.origin*n)/(n*(ray_copy.direction));
            if (est<0.0) return;
            Vec4 posi = ray_copy.positionRay(est);
            if (((posi.x()*posi.x() + posi.z()*posi.z())<=1)){
                t0 = est;
                pos = posi;
            }else{
                return;
            }
        }


        pos = transform.transform_position_ray(transform,pos);
        n =  transform.transform_normal_ray(transform,n);
        t0 = (pos - ray.origin).module();


        if (t0<t && t0>tmin){
            t = t0;
            this->normal = n.unitary();
            this->material->setMaterial(material,mesh->getMaterial());
<<<<<<< HEAD
            this->obj = obj;
=======
>>>>>>> 490f827284db0ec9110c12375bcf57acbf56b06a
        }


}

<<<<<<< HEAD
void RayIntersection::raySphereIntersection(Mesh *mesh, Matrix4x4 transform, Ray ray,Object *obj)
=======
void RayIntersection::raySphereIntersection(Mesh *mesh, Matrix4x4 transform, Ray ray)
>>>>>>> 490f827284db0ec9110c12375bcf57acbf56b06a
{

    Ray copy;
    copy.setOrigin(transform.transform_origin_ray(transform,ray.origin));
    copy.setDirection(transform.transform_direction_ray(transform,ray.direction));
    float a,b,c,delta,t0,t1,t_;
    c = copy.origin.x()*copy.origin.x() + copy.origin.y()*copy.origin.y() + copy.origin.z()*copy.origin.z() -1;
    b = 2*copy.origin.x()*copy.direction.x() + 2*copy.origin.y()*copy.direction.y() + 2*copy.origin.z()*copy.direction.z();
    a = copy.direction.x()*copy.direction.x() + copy.direction.y()*copy.direction.y() + copy.direction.z()*copy.direction.z();

    delta = b*b - 4*a*c;
    Vec4 pos,n;
    if (delta<0.0){
       return;

    }else{
    t0 = (-b - sqrt(delta))/(2*a);
    t1 = (-b + sqrt(delta))/(2*a);
    t_ = fmin(t0,t1);
    pos = copy.positionRay(t_);
    n   = pos;
    }/*
    if (pos.x2 <APROXIMATE){
        n = Vec4(0,-1,0);
        float est = (n*Vec4(0,0,0) - copy.origin*n)/(n*(copy.direction));
        if (est<APROXIMATE) return;
        Vec4 posi = copy.positionRay(est);
        if (((posi.x()*posi.x() + posi.z()*posi.z())<=1)){
            t_ = est;
            pos = posi;
        }else{
            return;
        }
    }
    }*/



    pos = transform.transform_position_ray(transform,pos);
    n = transform.transform_normal_ray(transform,n);
    t_ = (pos - ray.origin).module();
    if (t_<t && t_>tmin) {
        this->t = t_;
        this->normal = n.unitary();
        this->material->setMaterial(material,mesh->getMaterial());
<<<<<<< HEAD
        this->obj = obj;
=======
>>>>>>> 490f827284db0ec9110c12375bcf57acbf56b06a
    }



}

<<<<<<< HEAD
void RayIntersection::rayHemiSphereIntersection(Mesh *mesh, Matrix4x4 transform, Ray ray, Object *obj)
=======
void RayIntersection::rayHemiSphereIntersection(Mesh *mesh, Matrix4x4 transform, Ray ray)
>>>>>>> 490f827284db0ec9110c12375bcf57acbf56b06a
{
    Ray copy;
    copy.setOrigin(transform.transform_origin_ray(transform,ray.origin));
    copy.setDirection(transform.transform_direction_ray(transform,ray.direction));
    float a,b,c,delta,t0,t1,t_;
    c = copy.origin.x()*copy.origin.x() + copy.origin.y()*copy.origin.y() + copy.origin.z()*copy.origin.z() -1;
    b = 2*copy.origin.x()*copy.direction.x() + 2*copy.origin.y()*copy.direction.y() + 2*copy.origin.z()*copy.direction.z();
    a = copy.direction.x()*copy.direction.x() + copy.direction.y()*copy.direction.y() + copy.direction.z()*copy.direction.z();

    delta = b*b - 4*a*c;
    Vec4 pos,n;
    if (delta<0.0){
       return;

    }else{
    t0 = (-b - sqrt(delta))/(2*a);
    t1 = (-b + sqrt(delta))/(2*a);
    t_ = fmin(t0,t1);
    pos = copy.positionRay(t_);
    n   = pos;
    if (pos.x2 <APROXIMATE){
        n = Vec4(0,-1,0);
        float est = (n*Vec4(0,0,0) - copy.origin*n)/(n*(copy.direction));
        if (est<APROXIMATE) return;
        Vec4 posi = copy.positionRay(est);
        if (((posi.x()*posi.x() + posi.z()*posi.z())<=1)){
            t_ = est;
            pos = posi;
        }else{
            return;
        }
    }
    }



    pos = transform.transform_position_ray(transform,pos);
    n = transform.transform_normal_ray(transform,n);
    t_ = (pos - ray.origin).module();
    if (t_<t && t_>tmin) {
        this->t = t_;
        this->normal = n.unitary();
        this->material->setMaterial(material,mesh->getMaterial());
<<<<<<< HEAD
        this->obj = obj;
=======
>>>>>>> 490f827284db0ec9110c12375bcf57acbf56b06a
    }



}

RayIntersection::~RayIntersection()
{
<<<<<<< HEAD
    delete material;
    //delete obj;
=======

    delete material;
>>>>>>> 490f827284db0ec9110c12375bcf57acbf56b06a
}


