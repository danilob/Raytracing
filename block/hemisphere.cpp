#include "hemisphere.h"

HemiSphere::HemiSphere()
{

    double radius = 1.0;
    double alpha = 2*M_PI / STACKS;
    double beta = M_PI_2 / SLICES;
    for (int i = SLICES;i>0;i--){
        double  ratio_radius = sqrt((pow(radius,2)-pow(sin(beta*(i-1))*radius,2)));
        for(int j=0;j<STACKS;j++){
            vertexs[j+(STACKS*(SLICES-i))].setVec4(cos(alpha*j)*ratio_radius,sin(beta*(i-1))*radius,sin(alpha*j)*ratio_radius);
            initvertexs[j+(STACKS*(SLICES-i))] = vertexs[j+(STACKS*(SLICES-i))];
            normals[j+(STACKS*(SLICES-i))] = Vec4(vertexs[j+(STACKS*(SLICES-i))]).unitary();
            initnormals[j+(STACKS*(SLICES-i))] = normals[j+(STACKS*(SLICES-i))];
        }
    }
    vertexs[STACKS*SLICES] = Vec4(0.0,radius,0.0);
    initvertexs[STACKS*SLICES] = vertexs[STACKS*SLICES];
    normals[STACKS*SLICES] = Vec4(0.0,radius,0.0).unitary();
    initnormals[STACKS*SLICES] = normals[STACKS*SLICES];
    normals[(STACKS*SLICES)+1] = Vec4(0.0,-1.0,0.0).unitary();
    initnormals[STACKS*SLICES+1] = Vec4(0.0,-1.0,0.0).unitary();
    transform.setIdentity();
    mesh = new Mesh();

    Face face[(STACKS*SLICES)+(STACKS+1)];
    //desenho da lateral do hemisferio
    for(int i=SLICES-1;i>0;i--){
        for(int j=0;j<STACKS;j++){
        if(j<STACKS-1){
            face[j+(STACKS*(SLICES-i))].vertexs.push_back(&vertexs[j+(STACKS*(SLICES-i))]);
            face[j+(STACKS*(SLICES-i))].vertexs.push_back(&vertexs[j+(STACKS*(SLICES-i-1))]);
            face[j+(STACKS*(SLICES-i))].vertexs.push_back(&vertexs[j+(STACKS*(SLICES-i-1))+1]);
            face[j+(STACKS*(SLICES-i))].vertexs.push_back(&vertexs[j+(STACKS*(SLICES-i))+1]);
            face[j+(STACKS*(SLICES-i))].normals.push_back(&normals[j+(STACKS*(SLICES-i))]);
            face[j+(STACKS*(SLICES-i))].normals.push_back(&normals[j+(STACKS*(SLICES-i-1))]);
            face[j+(STACKS*(SLICES-i))].normals.push_back(&normals[j+(STACKS*(SLICES-i))+1]);
            face[j+(STACKS*(SLICES-i))].normals.push_back(&normals[j+(STACKS*(SLICES-i-1)+1)]);
        }else{
            face[j+(STACKS*(SLICES-i))].vertexs.push_back(&vertexs[j+(STACKS*(SLICES-i))]);
            face[j+(STACKS*(SLICES-i))].vertexs.push_back(&vertexs[j+(STACKS*(SLICES-i-1))]);
            face[j+(STACKS*(SLICES-i))].vertexs.push_back(&vertexs[STACKS+((j+1)*(SLICES-i-2))]);
            face[j+(STACKS*(SLICES-i))].vertexs.push_back(&vertexs[STACKS+((j+1)*(SLICES-i-1))]);
            face[j+(STACKS*(SLICES-i))].normals.push_back(&normals[j+(STACKS*(SLICES-i))]);
            face[j+(STACKS*(SLICES-i))].normals.push_back(&normals[j+(STACKS*(SLICES-i-1))]);
            face[j+(STACKS*(SLICES-i))].normals.push_back(&normals[STACKS+((j+1)*(SLICES-i-2))]);
            face[j+(STACKS*(SLICES-i))].normals.push_back(&normals[STACKS+((j+1)*(SLICES-i-1))]);
        }
        mesh->faces.push_back(face[j+(STACKS*(SLICES-i))]);
        }
    }
    //desenho do fundo da esfera

    for(int j=0;j<STACKS;j++){
        if(j<STACKS-1){
            face[j+(STACKS*(SLICES))].vertexs.push_back(&vertexs[STACKS*SLICES]);
            face[j+(STACKS*(SLICES))].vertexs.push_back(&vertexs[j+1]);
            face[j+(STACKS*(SLICES))].vertexs.push_back(&vertexs[j]);
            face[j+(STACKS*(SLICES))].normals.push_back(&normals[STACKS*SLICES]);
            face[j+(STACKS*(SLICES))].normals.push_back(&normals[j+1]);
            face[j+(STACKS*(SLICES))].normals.push_back(&normals[j]);

        }else{
            face[j+(STACKS*(SLICES))].vertexs.push_back(&vertexs[j]);
            face[j+(STACKS*(SLICES))].vertexs.push_back(&vertexs[STACKS*SLICES]);
            face[j+(STACKS*(SLICES))].vertexs.push_back(&vertexs[0]);
            face[j+(STACKS*(SLICES))].normals.push_back(&normals[j]);
            face[j+(STACKS*(SLICES))].normals.push_back(&normals[STACKS*SLICES]);
            face[j+(STACKS*(SLICES))].normals.push_back(&normals[0]);

        }
        mesh->faces.push_back(face[j+(STACKS*(SLICES))]);
    }

    for(int i=0;i<STACKS;i++){
        face[(STACKS*SLICES)+STACKS].vertexs.push_back(&vertexs[i+STACKS*(SLICES-1)]);
        if (i==0)
            face[(STACKS*SLICES)+STACKS].normals.push_back(&normals[(STACKS*SLICES)+1]);
    }
    mesh->faces.push_back(face[(STACKS*SLICES)+STACKS]);

    enabled = true;
    selected = false;
}

void HemiSphere::draw()
{
    if(isEnabled()){
    glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
    refreshNormals();

    mesh->draw();
    }
    if (selected){

        glColor3f(1,1,1);
        glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
        mesh->draw();

    }


}

void HemiSphere::wireframe()
{
    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    refreshNormals();

    mesh->draw();


}

void HemiSphere::aplyTransform(Matrix4x4 t)
{
    transform = transform.multMatrix(transform,t);
    transform = t;
    //transform.scale(2,2,2);
    //mesh->transform = transform;

//    for (int i=0;i>8;i++){
//        transform.transpose();
//        vertexs[i] = transform.vector(vertexs[i]);
    //    }
}

void HemiSphere::setIdentityTransform()
{
    transform.setIdentity();
}


void HemiSphere::refreshNormals()
{
    for (int i = SLICES;i>0;i--){

        for(int j=0;j<STACKS;j++){

            vertexs[j+(STACKS*(SLICES-i))] = transform.transpose().vector(initvertexs[j+(STACKS*(SLICES-i))]);
            normals[j+(STACKS*(SLICES-i))] = transform.transform_normal_ray(transform,initnormals[j+(STACKS*(SLICES-i))]).unitary();
        }
    }

    vertexs[STACKS*SLICES] = transform.transpose().vector(initvertexs[STACKS*SLICES]);
    normals[STACKS*SLICES] = transform.transform_normal_ray(transform,initnormals[STACKS*SLICES]).unitary();
    normals[STACKS*SLICES+1] = transform.transform_normal_ray(transform,initnormals[STACKS*SLICES+1]).unitary();
}

void HemiSphere::setMaterial(int material)
{
    mesh->setMaterial(material);
}

void HemiSphere::changeCoords(Matrix4x4 matrix)
{
    transform = transform.multMatrix(transform,matrix);
    refreshNormals();
}

Mesh * HemiSphere::getMesh()
{
    return mesh;
}

void HemiSphere::setName(QString nm)
{
    name = nm;
}

QString HemiSphere::getName()
{
    return name;
}

int HemiSphere::getIdMaterial()
{
    return mesh->getMaterial();
}

void HemiSphere::tryIntersection(RayIntersection *intersect, Ray ray)
{


        intersect->rayHemiSphereIntersection(mesh,transform,ray);
}

void HemiSphere::setSelected(bool b)
{
    selected = b;
}

bool HemiSphere::isSelected()
{
    return selected;
}

void HemiSphere::setEnabled(bool b)
{
    enabled = b;
}

bool HemiSphere::isEnabled()
{
    return enabled;
}

Matrix4x4 HemiSphere::getMatrixTransformation()
{
    return transform;
}

int HemiSphere::getNumFaces()
{
    return mesh->faces.size();
}

int HemiSphere::getNumVertexs()
{
    return SLICES*STACKS + 1;
}

void HemiSphere::setTransform(Matrix4x4 m)
{
    transform = m;
}

QString HemiSphere::saveObject()
{
    QString obj;
    QString aux;
    obj += "h ";
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


Vec4 HemiSphere::getMin()
{

    float pmin[3] = {INFINITY};
    Vec4 min;
    for (int i=0;i<SLICES*STACKS+1;i++){
        if(pmin[0]>=vertexs[i].x1 && pmin[1]>=vertexs[i].x2 && pmin[2]>=vertexs[i].x3){
            pmin[0] = vertexs[i].x1;
            pmin[1] = vertexs[i].x2;
            pmin[2] = vertexs[i].x3;
            min = vertexs[i];
        }

    }
    return min;

}

Vec4 HemiSphere::getMax()
{
    float pmax[3] = {-INFINITY};

    Vec4 max;
    for (int i=0;i<SLICES*STACKS+1;i++){

        if(pmax[0]<=vertexs[i].x1 && pmax[1]<=vertexs[i].x2 && pmax[2]<=vertexs[i].x3){
            pmax[0] = vertexs[i].x1;
            pmax[1] = vertexs[i].x2;
            pmax[2] = vertexs[i].x3;
            max = vertexs[i];
        }
    }
    return max;

}

Cube HemiSphere::boundingBox()
{
    return Cube(this->getMin(),this->getMax());
}

Vec4 HemiSphere::getCenter()
{
    return (this->getMax()-this->getMin())/2.0;
}

