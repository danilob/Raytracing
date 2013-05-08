#ifndef DRAW_H
#define DRAW_H
#include "block/cube.h"
#include "block/cylinder.h"
#include "block/prism.h"
#include "block/hemisphere.h"
class Draw
{

public:
    Draw();
    static void drawPlane(int size,bool solid,bool texture=false);
    static void drawArrow(Vec4* position_,double size=1.0);
    static void drawSpot(Vec4* position_,Vec4* direction,double angle);

};

#endif // DRAW_H
