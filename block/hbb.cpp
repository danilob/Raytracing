#include "hbb.h"

HBB::HBB()
{
}

HBB::HBB(std::vector<Object*> objects, int axis)
{
    std::vector<Object*> copy;
    for(int i=0; i<objects.size();i++) copy.push_back(objects.at(i));
    int n = copy.size();
    if (n==1){
        left = copy.at(0);
        right = NULL;
        box = left->boundingBox();
    }
    else if(n==2){
        left = copy.at(0);
        right = copy.at(1);
        box = box.combineCube(left->boundingBox(),right->boundingBox());
        box.wireframe();
    }else{
        sortObjects(copy,axis);
        std::vector<Object*> l;
        std::vector<Object*> r;
        for (int i=0;i<n/2-1;i++){
            l.push_back(copy.at(i));
        }
        for (int i=n/2;i<n-1;i++){
            r.push_back(copy.at(i));
        }
        left = new HBB(l,(axis+1)%3);
        right = new HBB(r,(axis+1)%3);
        box = box.combineCube(left_node->box,right_node->box);
    }

}

HBB::~HBB()
{
    delete left;
    delete right;
}

void HBB::sortObjects(std::vector<Object*> objects, int axis)
{
    std::vector<Object*> copy;
    for(int i=0; i<objects.size();i++) copy.push_back(objects.at(i));
    int pos;
    switch (axis){
        case 0 :{ //então organizaremos seguinto o eixo x
                    for(int i=0; i<objects.size();i++){
                        pos = i;
                        for(int j=i+1;j<objects.size();j++){
                                if (objects.at(pos)->getCenter().x()>objects.at(j)->getCenter().x()){
                                    pos = j;
                                    //comp++;
                                }
                            }
                            if (i!=pos){
                                Object* temp;
                                temp = objects.at(pos);
                                objects.at(pos) = objects.at(i);
                                objects.at(i) = temp;
                            }
                        }
                }
        case 1:{//Falso -> então organizaremos seguindo o eixo y
                    for(int i=0; i<objects.size();i++){
                        pos = i;
                        for(int j=i+1;j<objects.size();j++){
                                if (objects.at(pos)->getCenter().y()>objects.at(j)->getCenter().y()){
                                    pos = j;
                                    //comp++;
                                }
                            }
                            if (i!=pos){
                                Object* temp;
                                temp = objects.at(pos);
                                objects.at(pos) = objects.at(i);
                                objects.at(i) = temp;

                            }
                    }
                }
        case 2:{
                    for(int i=0; i<objects.size();i++){
                        pos = i;
                        for(int j=i+1;j<objects.size();j++){
                                if (objects.at(pos)->getCenter().z()>objects.at(j)->getCenter().z()){
                                    pos = j;
                                    //comp++;
                                }
                            }
                            if (i!=pos){
                                Object* temp;
                                temp = objects.at(pos);
                                objects.at(pos) = objects.at(i);
                                objects.at(i) = temp;

                            }
                    }
                }
    }

    //return copy;

}


