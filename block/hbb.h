#ifndef HBB_H
#define HBB_H
#include "object.h"
#include "cube.h"
#include "math/rayintersection.h"
#include <vector>
class HBB: public Cube
{
public:
    Object *left;
    Object *right;
    HBB *left_node;
    HBB *right_node;
    Cube box;


public:
    HBB();
    HBB(std::vector<Object*> objects,int axis);
    ~HBB();
    bool hit(RayIntersection *intersect);
    void sortObjects(std::vector<Object*> objects,int axis);
    //void drawStructure();
};

#endif // HBB_H
