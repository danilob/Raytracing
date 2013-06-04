#ifndef HEMISPHERE_H
#define HEMISPHERE_H
#include "object.h"
#include "structure/mesh.h"
#include "math/matrix4x4.h"
#include "cube.h"
#define SLICES 40 //linhas horizontais
#define STACKS 40 //linhas verticais

class HemiSphere: public Object
{
public:
    Mesh* mesh;
    Vec4 vertexs[(SLICES*STACKS)+1];
    Vec4 initvertexs[(SLICES*STACKS)+1];
    Vec4 normals[(SLICES*STACKS)+2];
    Vec4 initnormals[(SLICES*STACKS)+2];
    Matrix4x4 transform;
    QString name;
    bool enabled;
    bool selected;
public:
    HemiSphere();
    void draw();
    void refreshNormals();
    void aplyTransform(Matrix4x4 t);
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
    Vec4 refreshVertexs();


};

#endif // HEMISPHERE_H
