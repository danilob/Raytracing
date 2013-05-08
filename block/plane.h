#ifndef PLANE_H
#define PLANE_H

#include "object.h"
#include "math/matrix4x4.h"
#include "structure/mesh.h"
#include "cube.h"
#include <vector>

class Plane: public Object
{
public:
    Mesh* mesh;
    Vec4 vertexs[4];
    Vec4 initvertexs[4];
    Vec4 normals[1];
    Vec4 initnormals[1];
    Matrix4x4 transform;
    QString name;
    bool selected;
    bool enabled;

public:
    Plane();
    void draw();
    void aplyTransform(Matrix4x4 t);
    void refreshNormals();
    void setIdentityTransform();
    void setMaterial(int material);
    void wireframe();
    void changeCoords(Matrix4x4 matrix);
    Mesh* getMesh();
    void setName(QString nm);
    QString getName();
    int getIdMaterial();
    void tryIntersection(RayIntersection *intersect,Ray ray);
    void setSelected(bool b);
    bool isSelected();
    void setEnabled(bool b);
    bool isEnabled();
    Matrix4x4 getMatrixTransformation();
    int getNumFaces(){ return 1;}
    int getNumVertexs(){return 1;}
    void setTransform(Matrix4x4 m);
    QString saveObject();
    ~Plane();
    Cube boundingBox();
    Vec4 getMin();
    Vec4 getMax();
    Vec4 getCenter();



};


#endif // PLANE_H
