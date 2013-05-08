#ifndef PRISM_H
#define PRISM_H

#include "object.h"
#include "math/matrix4x4.h"
#include "structure/mesh.h"
#include <vector>
#include "cube.h"

class Prism: public Object
{
public:
    Mesh* mesh;
    Vec4 vertexs[6];
    Vec4 initvertexs[6];
    Vec4 normals[5];
    Matrix4x4 transform;
    QString name;
    bool selected;
    bool enabled;

public:
    Prism();
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
    int getNumFaces();
    int getNumVertexs();
    void setTransform(Matrix4x4 m);
    QString saveObject();
    Cube boundingBox();
    Vec4 getMin();
    Vec4 getMax();
    Vec4 getCenter();



};

#endif // PRISM_H
