#ifndef STRUCTURE_H
#define STRUCTURE_H
#include "math/vec4.h"
#include "math/matrix4x4.h"
#include "extra/material.h"
#include <vector>


struct Face{
    std::vector<Vec4*> vertexs;
    std::vector<Vec4*> normals;
    //Vec4* textureCoord[3];

};


class Mesh
{
public:
    std::vector<Vec4> normals;
    std::vector<Face> faces;
    int id_material;

public:
    Mesh();
    void draw();
    //void drawNormalFace(); //tentar fazer depois
    void setMaterial(int type=0);          //setar a propriedade de material do mesh
    void drawNormalVertex();
    void drawNormalFace(Face face);
    void setMaterials();                   //desenhar o meterial
    static Vec4 getNormalFace(Face face);
    int getMaterial();



};


#endif // STRUCTURE_H
