#ifndef PLANE_H
#define PLANE_H

#include "object.h"
#include "math/matrix4x4.h"
#include "structure/mesh.h"
#include "cube.h"
#include <vector>

class Plane: public Object
{
private:
    Vec4      vertexs[4];     //vertice corrente do objeto
    Vec4      initvertexs[4]; //vertices iniciais do objeto
    Vec4      normals[1];     //normal corrente do objeto
    Vec4      initnormals[1]; //normal inicial do objeto
    Mesh*     mesh;           //estrutura de faces e vertices para o desenho
    Matrix4x4 transform;      //matriz de transformação do objeto
    QString   name;           //nome do objeto
    Vec4      motion;         //efeito de translação motion blur do objeto
    bool      selected;       //verifica se o objeto esta selecionado
    bool      enabled;        //verifica se o objeto esta ativo
public:
    Plane();
    ~Plane();
    void      draw();
    void      aplyTransform(Matrix4x4 t);
    void      refreshNormals();
    void      setIdentityTransform();
    void      setMaterial(int material);
    void      wireframe();
    void      changeCoords(Matrix4x4 matrix);
    Mesh*     getMesh();
    void      setName(QString nm);
    QString   getName();
    int       getIdMaterial();
    void      tryIntersection(RayIntersection *intersect,Ray ray);
    void      setSelected(bool b);
    bool      isSelected();
    void      setEnabled(bool b);
    bool      isEnabled();
    Matrix4x4 getMatrixTransformation();
    int       getNumFaces();
    int       getNumVertexs();
    void      setTransform(Matrix4x4 m);
    QString   saveObject();
    Cube      boundingBox();
    Vec4      getMin();
    Vec4      getMax();
    Vec4      getCenter();
    void      setMotion(Vec4 m);
    Vec4      getMotion();



};


#endif // PLANE_H
