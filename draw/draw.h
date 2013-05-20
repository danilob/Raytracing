#ifndef DRAW_H
#define DRAW_H
#include "math/vec4.h"
//#include "block/cube.h"
//#include "block/cylinder.h"
//#include "block/prism.h"
//#include "block/hemisphere.h"
class Draw
{

public:
    Draw();
    static void drawPlane(int size,bool solid,bool texture=false);
    static void drawArrow(Vec4* position_,double size=1.0);
    static void drawSpot(Vec4* position_,Vec4* direction,double angle);
    static void drawPoint(Vec4 v,int size=1,Vec4 color=Vec4(1,1,1));

};

#endif // DRAW_H
