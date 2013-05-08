#include "ray.h"
//#define ERROR 0.001
Ray::Ray()
{
    origin.setVec4(0,0,0,1);
    direction.setVec4(0,0,0,0);

    //t = 0;
}
Ray::Ray(Vec4 ori,Vec4 dir)
{
    origin    = ori;
    direction = dir;
    //if (dir.module()==0) dir = Vec4(1,1,1,0);
    inverse_direction = Vec4(1.0/dir.x1, 1.0/dir.x2, 1.0/dir.x3);
    sign[0] = (inverse_direction.x1 < 0);
    sign[1] = (inverse_direction.x2 < 0);
    sign[2] = (inverse_direction.x3 < 0);
}



Vec4 Ray::positionRay(float t)
{
    return origin + direction*t;

}

void Ray::setDirection(Vec4 dir)
{
    direction = dir;
    //if (dir.module()==0) dir = Vec4(1,1,1,0);
    inverse_direction = Vec4(1.0/dir.x1, 1.0/dir.x2, 1.0/dir.x3);
    sign[0] = (inverse_direction.x1 < 0);
    sign[1] = (inverse_direction.x2 < 0);
    sign[2] = (inverse_direction.x3 < 0);

}

void Ray::setOrigin(Vec4 ori)
{
    origin = ori;
}

