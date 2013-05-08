#ifndef RAY_H
#define RAY_H

#include "vec4.h"

class Ray
{
public:
    Ray();
    Ray(Vec4 ori,Vec4 dir);       //inicializa o raio com determinada origem e direção (vetor unitário)
    Vec4 positionRay(float t);    //retorna o vetor da posição do raio em determinado parâmetro t
    void setDirection(Vec4 dir);  //seta a direção do raio
    void setOrigin(Vec4 ori);     //seta a origem do raio

public:
    Vec4 origin;
    Vec4 direction;
    Vec4 inverse_direction;
    int sign[3];

};

#endif // RAY_H
