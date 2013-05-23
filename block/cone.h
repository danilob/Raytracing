#ifndef CONE_H
#define CONE_H
#include "object.h"
#include "structure/mesh.h"
#include "math/matrix4x4.h"
#include "cube.h"
#define SEGMENTS 40

class Cone: public Object
{
private:
    Mesh* mesh;
    Vec4 vertexs[(SEGMENTS)+1];
    Vec4 initvertexs[SEGMENTS+1];
    Vec4 normals[(SEGMENTS+2)];
    Vec4 initnormals[(SEGMENTS+2)];
    Vec4 ymax,ymin;
    Matrix4x4 transform;
    QString name;
    bool selected;
    bool enabled;

public:
    Cone();
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
    void refreshVertexs();
};


#endif // CONE_H
