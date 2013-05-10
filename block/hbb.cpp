#include "hbb.h"

HBB::HBB()
{
    left = NULL;
    right = NULL;
    left_node = NULL;
    right_node = NULL;
    box = Cube();
    select = NULL;
}

HBB::HBB(std::vector<Object*> objects, int axis)
{
    select = NULL;
    std::vector<Object*> copy;
    for(int i=0; i<objects.size();i++) copy.push_back(objects.at(i));
    int n = copy.size();
    if (n==1){
        left = copy.at(0);
        right = NULL;
        box = Cube(left->getMin(),left->getMax());
        left_node = NULL;
        right_node = NULL;
    }
    else if(n==2){
        left = copy.at(0);
        right = copy.at(1);
        box = box.combineCube(left->boundingBox(),right->boundingBox());
        left_node = NULL;
        right_node = NULL;
    }else{
        //ordenar segundo o eixo
        std::vector<Object*> sort = sortObjects(copy,axis);
        for(int i=0; i<sort.size();i++) copy.at(i) = sort.at(i);

        std::vector<Object*> l;
        std::vector<Object*> r;
        for (int i=0;i<n/2;i++){
            l.push_back(copy.at(i));
        }
        for (int i=n/2;i<n;i++){
            r.push_back(copy.at(i));
        }

        left_node  = new HBB(l,(axis+1)%3);
        right_node = new HBB(r,(axis+1)%3);
        left = NULL;
        right = NULL;
        box = box.combineCube(left_node->box,right_node->box);
    }

}

HBB::~HBB()
{
    delete left;
    delete right;
    delete left_node;
    delete right_node;
    delete select;
}

std::vector<Object*> HBB::sortObjects(std::vector<Object*> objects, int axis)
{
    int pos;
    switch (axis){
        case 0 :{ //então organizaremos seguinto o eixo x
                    for(int i=0; i<objects.size();i++){
                        pos = i;
                        for(int j=i+1;j<objects.size();j++){
                                if (objects.at(pos)->getCenter().x()>objects.at(j)->getCenter().x()){

                                }
                            }
                            if (i!=pos){
                                Object* temp;
                                temp = objects.at(pos);
                                objects.at(pos) = objects.at(i);
                                objects.at(i) = temp;
                            }
                        }
                    break;
                }
        case 1:{//então organizaremos seguindo o eixo y
                    for(int i=0; i<objects.size();i++){
                        pos = i;
                        for(int j=i+1;j<objects.size();j++){
                                if (objects.at(pos)->getCenter().y()>objects.at(j)->getCenter().y()){
                                    pos = j;
                                }
                            }
                            if (i!=pos){
                                Object* temp;
                                temp = objects.at(pos);
                                objects.at(pos) = objects.at(i);
                                objects.at(i) = temp;

                            }
                    }
                    break;
                }
        case 2:{
                    for(int i=0; i<objects.size();i++){
                        pos = i;
                        for(int j=i+1;j<objects.size();j++){
                                if (objects.at(pos)->getCenter().z()>objects.at(j)->getCenter().z()){
                                    pos = j;
                                }
                            }
                            if (i!=pos){
                                Object* temp;
                                temp = objects.at(pos);
                                objects.at(pos) = objects.at(i);
                                objects.at(i) = temp;

                            }
                    }
                    break;
                }
    }
    return objects;

}

void HBB::drawStructure()
{
    if(left_node!=NULL) left_node->drawStructure();
    if(right_node!=NULL) right_node->drawStructure();
    Cube(box.getMax(),box.getMin()).wireframe();
}

bool HBB::HBBIntersection(RayIntersection *intersect, Ray ray, Object *obj)
{
    if(hitBox(ray,box.getMatrixTransformation())){
        bool left_hit,right_hit;
        left_hit = right_hit = true;
        if(left_node!=NULL) left_hit = left_node->HBBIntersection(intersect,ray,obj);
        if(right_node!=NULL) right_hit = right_node->HBBIntersection(intersect,ray,obj);
        if((left_hit || right_hit)){
            float t1,t2;
            if(left!=NULL){
                left->tryIntersection(intersect,ray);
                t1 = intersect->t;
            }
            if(right!=NULL){
                right->tryIntersection(intersect,ray);
                t2 = intersect->t;
            }
            if(intersect->normal==Vec4()) return false;
            //if(t1==t2) select = left;
            //else       select = right;
            return true;
        }else{
            return false;
        }
        //if(left!=NULL) left->tryIntersection(intersect,ray);
        //if(right!=NULL) right->tryIntersection(intersect,ray);
    }

    return false;

}

bool HBB::hitBox(Ray ray, Matrix4x4 transform)
{
    Vec4 bounds[2];
    bounds[0] = Vec4(-0.5,-0.5,-0.5);
    bounds[1] = Vec4(0.5,0.5,0.5);
    Ray copy;
    copy.setOrigin(transform.transform_origin_ray(transform,ray.origin));
    copy.setDirection(transform.transform_direction_ray(transform,ray.direction));
    float tmin, tmax, tymin, tymax, tzmin, tzmax;
    tmin = (bounds[copy.sign[0]].x() - copy.origin.x()) * copy.inverse_direction.x();
    tmax = (bounds[1-copy.sign[0]].x() - copy.origin.x()) * copy.inverse_direction.x();
    tymin = (bounds[copy.sign[1]].y() - copy.origin.y()) * copy.inverse_direction.y();
    tymax = (bounds[1-copy.sign[1]].y() - copy.origin.y()) * copy.inverse_direction.y();
    if ( (tmin > tymax) || (tymin > tmax) )
        return false;
    if (tymin > tmin)
        tmin = tymin;
    if (tymax < tmax)
        tmax = tymax;
    tzmin = (bounds[copy.sign[2]].z() - copy.origin.z()) * copy.inverse_direction.z();
    tzmax = (bounds[1-copy.sign[2]].z() - copy.origin.z()) * copy.inverse_direction.z();
    if ( (tmin > tzmax) || (tzmin > tmax) )
        return false;
    if (tzmin > tmin)
        tmin = tzmin;
    if (tzmax < tmax)
        tmax = tzmax;
    if (!( (tmin < tmax))) return false;
    return true;
}


