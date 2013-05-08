#include "prism.h"

Prism::Prism()
{
    //valores default do prisma de base triangular reto
    double cathetus = 1.0;
    double height   = 1.0;

    vertexs[0].setVec4(0.0,0.0,0.0);
    vertexs[1].setVec4(0.0,0.0,cathetus);
    vertexs[2].setVec4(cathetus,0.0,0.0);
    vertexs[3].setVec4(0.0,height,0.0);
    vertexs[4].setVec4(0.0,height,cathetus);
    vertexs[5].setVec4(cathetus,height,0.0);
    initvertexs[0].setVec4(0.0,0.0,0.0);
    initvertexs[1].setVec4(0.0,0.0,cathetus);
    initvertexs[2].setVec4(cathetus,0.0,0.0);
    initvertexs[3].setVec4(0.0,height,0.0);
    initvertexs[4].setVec4(0.0,height,cathetus);
    initvertexs[5].setVec4(cathetus,height,0.0);
transform.setIdentity();
    refreshNormals();
    mesh = new Mesh();

    Face face[5];

    face[0].vertexs.push_back(&vertexs[0]);
    face[0].vertexs.push_back(&vertexs[2]);
    face[0].vertexs.push_back(&vertexs[1]);
    face[0].normals.push_back(&normals[0]);
//    face[0].normals.push_back(&normals[0]);
//    face[0].normals.push_back(&normals[0]);
    mesh->faces.push_back(face[0]);

    face[1].vertexs.push_back(&vertexs[3]);
    face[1].vertexs.push_back(&vertexs[4]);
    face[1].vertexs.push_back(&vertexs[5]);
    face[1].normals.push_back(&normals[1]);
//    face[1].normals.push_back(&normals[1]);
//    face[1].normals.push_back(&normals[1]);
    mesh->faces.push_back(face[1]);

    face[2].vertexs.push_back(&vertexs[2]);
    face[2].vertexs.push_back(&vertexs[5]);
    face[2].vertexs.push_back(&vertexs[4]);
    face[2].vertexs.push_back(&vertexs[1]);
    face[2].normals.push_back(&normals[2]);
//    face[2].normals.push_back(&normals[2]);
//    face[2].normals.push_back(&normals[2]);
//    face[2].normals.push_back(&normals[2]);
    mesh->faces.push_back(face[2]);

    face[3].vertexs.push_back(&vertexs[0]);
    face[3].vertexs.push_back(&vertexs[3]);
    face[3].vertexs.push_back(&vertexs[5]);
    face[3].vertexs.push_back(&vertexs[2]);
    face[3].normals.push_back(&normals[3]);
//    face[3].normals.push_back(&normals[3]);
//    face[3].normals.push_back(&normals[3]);
//    face[3].normals.push_back(&normals[3]);
    mesh->faces.push_back(face[3]);

    face[4].vertexs.push_back(&vertexs[0]);
    face[4].vertexs.push_back(&vertexs[1]);
    face[4].vertexs.push_back(&vertexs[4]);
    face[4].vertexs.push_back(&vertexs[3]);
    face[4].normals.push_back(&normals[4]);
//    face[4].normals.push_back(&normals[4]);
//    face[4].normals.push_back(&normals[4]);
//    face[4].normals.push_back(&normals[4]);
    mesh->faces.push_back(face[4]);
    enabled = true;
    selected = false;


}

void Prism::refreshNormals()
{
    //normais a face
    normals[0] = Vec4::crossProduct(vertexs[2]-vertexs[0],vertexs[1]-vertexs[2]).unitary(); //vertices:0,1,2
    normals[1] = Vec4::crossProduct(vertexs[4]-vertexs[3],vertexs[5]-vertexs[4]).unitary(); //vertices:3,4,5
    normals[2] = Vec4::crossProduct(vertexs[5]-vertexs[2],vertexs[4]-vertexs[5]).unitary(); //vertices:1,2,4,5
    normals[3] = Vec4::crossProduct(vertexs[3]-vertexs[0],vertexs[5]-vertexs[3]).unitary(); //vertices:0,2,3,5
    normals[4] = Vec4::crossProduct(vertexs[0]-vertexs[3],vertexs[1]-vertexs[0]).unitary(); //vertices:0,1,3,4

    //normal do vertice é a média das normais as faces que o vertice pertence
//    normals[0] = ((normal[0]+normal[3]+normal[4])/3.0).unitary();
//    normals[1] = ((normal[0]+normal[2]+normal[4])/3.0).unitary();
//    normals[2] = ((normal[0]+normal[2]+normal[3])/3.0).unitary();
//    normals[3] = ((normal[1]+normal[3]+normal[4])/3.0).unitary();
//    normals[4] = ((normal[1]+normal[2]+normal[4])/3.0).unitary();
//    normals[5] = ((normal[1]+normal[2]+normal[3])/3.0).unitary();
}

void Prism::draw()
{
    if(isEnabled()){

    glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );

    for(int i=0;i<6;i++){
        vertexs[i] = transform.transpose().vector(initvertexs[i]);
    }
    refreshNormals();

    mesh->draw();
    }
    if (selected){

        glColor3f(1,1,1);
        glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
        mesh->draw();

    }
}

void Prism::wireframe()
{

    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    for(int i=0;i<6;i++){
        vertexs[i] = transform.transpose().vector(initvertexs[i]);
    }
    refreshNormals();
    mesh->draw();
}

void Prism::aplyTransform(Matrix4x4 t)
{
    transform = transform.multMatrix(transform,t);
    transform = t;

}

void Prism::setIdentityTransform()
{
    transform.setIdentity();
}


void Prism::setMaterial(int material)
{
    mesh->setMaterial(material);
}

void Prism::changeCoords(Matrix4x4 matrix)
{
    transform = transform.multMatrix(transform,matrix);
    for(int i=0;i<6;i++){
        vertexs[i] = transform.transpose().vector(initvertexs[i]);
    }
    refreshNormals();
}

Mesh * Prism::getMesh()
{
    return mesh;
}

void Prism::setName(QString nm)
{
    name = nm;
}

QString Prism::getName()
{
    return name;
}

int Prism::getIdMaterial()
{
    return mesh->getMaterial();
}

void Prism::tryIntersection(RayIntersection *intersect, Ray ray)
{
    float pmax[3] = {-INFINITY};
    float pmin[3] = {INFINITY};
    Vec4 bounds[2];
    for (int i=0;i<6;i++){
        if(pmin[0]>=vertexs[i].x1 && pmin[1]>=vertexs[i].x2 && pmin[2]>=vertexs[i].x3){
            pmin[0] = vertexs[i].x1;
            pmin[1] = vertexs[i].x2;
            pmin[2] = vertexs[i].x3;
            bounds[0] = vertexs[i];
        }
        if(pmax[0]<=vertexs[i].x1 && pmax[1]<=vertexs[i].x2 && pmax[2]<=vertexs[i].x3){
            pmax[0] = vertexs[i].x1;
            pmax[1] = vertexs[i].x2;
            pmax[2] = vertexs[i].x3;
            bounds[1] = vertexs[i];
        }
    }
    intersect->rayBoxIntersection(mesh,ray,transform,bounds[1],bounds[0]);
}

void Prism::setSelected(bool b)
{
    selected = b;
}

bool Prism::isSelected()
{
    return selected;
}

void Prism::setEnabled(bool b)
{
    enabled = b;
}

bool Prism::isEnabled()
{
    return enabled;
}

Matrix4x4 Prism::getMatrixTransformation()
{
    return transform;
}

int Prism::getNumFaces()
{
    return mesh->faces.size();
}

int Prism::getNumVertexs()
{
    return 6;
}

void Prism::setTransform(Matrix4x4 m)
{
    transform = m;
}



QString Prism::saveObject()
{
    QString obj;
    QString aux;
    obj += "p ";
    Vec4 parameters;
    //translacao
    parameters = transform.getTranslateSeted();
    obj += aux.sprintf("%.3f %.3f %.3f ",parameters.x(),parameters.y(),parameters.z());
    //escala
    parameters = transform.getScaleSeted();
    obj += aux.sprintf("%.3f %.3f %.3f ",parameters.x(),parameters.y(),parameters.z());
    //rotação
    parameters = transform.getRotationSeted();
    obj += aux.sprintf("%.3f %.3f %.3f ",parameters.x(),parameters.y(),parameters.z());
    obj += aux.sprintf("%d ",this->getIdMaterial());
    if (this->enabled)
        obj += "t ";
    else
        obj += "f ";
    if (this->selected)
        obj += "t ";
    else
        obj += "f ";
    obj +=this->name+"\n";
    return obj;
}


Vec4 Prism::getMin()
{

    float pmin[3] = {INFINITY};
    Vec4 min;
    for (int i=0;i<6;i++){
        if(pmin[0]>=vertexs[i].x1 && pmin[1]>=vertexs[i].x2 && pmin[2]>=vertexs[i].x3){
            pmin[0] = vertexs[i].x1;
            pmin[1] = vertexs[i].x2;
            pmin[2] = vertexs[i].x3;
            min = vertexs[i];
        }

    }
    return min;

}

Vec4 Prism::getMax()
{
    float pmax[3] = {-INFINITY};

    Vec4 max;
    for (int i=0;i<6;i++){

        if(pmax[0]<=vertexs[i].x1 && pmax[1]<=vertexs[i].x2 && pmax[2]<=vertexs[i].x3){
            pmax[0] = vertexs[i].x1;
            pmax[1] = vertexs[i].x2;
            pmax[2] = vertexs[i].x3;
            max = vertexs[i];
        }
    }
    return max;

}

Cube Prism::boundingBox()
{
    return Cube(this->getMin(),this->getMax());
}

Vec4 Prism::getCenter()
{
    return (this->getMax()-this->getMin())/2.0;
}
