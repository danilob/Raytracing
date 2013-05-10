#include "mesh.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
Mesh::Mesh()
{
    faces.clear();
//    displayListId = -1;
//    displayListIdNormalFace = -1;
//    displayListIdNormalVertex = -1;
    //typematerial = new Material;
    id_material = 0;

}

void Mesh::draw()
{
//    if (displayListId!=-1){
//        glCallList(displayListId);
//        return;
//    }

//    displayListId = glGenLists(1);

//    glNewList(displayListId, GL_COMPILE);

//glEnable(GL_COLOR_MATERIAL);

    //glColorMaterial ( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE ) ;

      glPushMatrix();


     // setMaterial(0);
      setMaterials();
      //glColor3f(0.2,0.2,0.2);
      //GLfloat yellow[] = {0.5f, 0.5f, 0.5f, 1.0f};
      //glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, yellow);
      //glMultMatrixd(transform.getMatrix());
        for(unsigned int i=0;i<faces.size();i++){
            //glColor3f(0.5,0.5,0.5);
            //glColorMaterial ( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE ) ;
<<<<<<< HEAD
            //drawNormalFace(faces[i]);
=======
            drawNormalFace(faces[i]);
>>>>>>> 490f827284db0ec9110c12375bcf57acbf56b06a
            if(faces[i].normals.size()==1){
                glNormal3fv(&faces[i].normals[0]->x1);
            }
            glBegin(GL_POLYGON);
            if(faces[i].normals.size()<=1){

                Vec4 n = getNormalFace(faces[i]);
                glNormal3f(n.x1,n.x2,n.x3);
            }
            for(unsigned int j=0;j<faces[i].vertexs.size();j++){
                if(j<faces[i].normals.size() && faces[i].normals.size()>1){
                    glNormal3fv(&faces[i].normals[j]->x1);

                }
                glVertex3fv(&faces[i].vertexs[j]->x1);
            }
            glEnd();
//            glColor3f(1,0,0);
//            glBegin(GL_LINES);
//            for(unsigned int j=0;j<faces[i].vertexs.size();j++){
//                if(j<faces[i].normals.size() && faces[i].normals.size()>1){
//                glVertex3dv(&faces[i].vertexs[j]->x1);
//                glVertex3d(faces[i].vertexs[j]->x1+0.5*faces[i].normals[j]->x1,faces[i].vertexs[j]->x2+0.5*faces[i].normals[j]->x2,faces[i].vertexs[j]->x3+0.5*faces[i].normals[j]->x3);
//                }
//                glColor3f(0.0,1,0.0);
//                if(j<faces[i].normals.size() && faces[i].normals.size()>1){
//                glVertex3dv(&faces[i].vertexs[j]->x1);
//                glVertex3d(faces[i].vertexs[j]->x1+0.5+0.5*faces[i].normals[j]->x1,faces[i].vertexs[j]->x2+0.5+0.5*faces[i].normals[j]->x2,faces[i].vertexs[j]->x3+0.5+0.5*faces[i].normals[j]->x3);
//                }
//            }
//            glEnd();
            //
        }

        glPopMatrix();

}




void Mesh::setMaterial(int type)
{

    id_material = type;
}

void Mesh::setMaterials()
{
   Material::setMaterialOpenGL(id_material);

}

Vec4 Mesh::getNormalFace(Face face)
{
    if (face.vertexs.size()<3){
        return Vec4();
    }

    Vec4 v[3],res;
    for (unsigned int i=0;i<2;i++){
        v[i].setVec4(face.vertexs[i]->x1,face.vertexs[i]->x2,face.vertexs[i]->x3);
    }
    v[2].setVec4(face.vertexs[face.vertexs.size()-1]->x1,face.vertexs[face.vertexs.size()-1]->x2,face.vertexs[face.vertexs.size()-1]->x3);

    res = (v[1]-v[0])^(v[2]-v[0]);

    return res/res.module();

}

int Mesh::getMaterial()
{
    return id_material;
}

void Mesh::drawNormalVertex()
{

    glPushMatrix();

    for(unsigned int i=0;i<faces.size();i++){
        glColor3f(1,0,0);
        glBegin(GL_LINES);
        for(unsigned int j=0;j<faces[i].vertexs.size();j++){
            if(j<faces[i].normals.size() && faces[i].normals.size()>1){
                glVertex3fv(&faces[i].vertexs[j]->x1);
                glVertex3f(faces[i].vertexs[j]->x1+0.5*faces[i].normals[j]->x1,faces[i].vertexs[j]->x2+0.5*faces[i].normals[j]->x2,faces[i].vertexs[j]->x3+0.5*faces[i].normals[j]->x3);
            }
        }
        glEnd();
    }

    glPopMatrix();

}

void Mesh::drawNormalFace(Face face)
{
    if (face.vertexs.size()!=4){
        return;
    }

    Vec4 res;
//    for (unsigned int i=0;i<2;i++){
//        v[i].setVec4(face.vertexs[i]->x1,face.vertexs[i]->x2,face.vertexs[i]->x3);
//    }
//    v[2].setVec4(face.vertexs[face.vertexs.size()-1]->x1,face.vertexs[face.vertexs.size()-1]->x2,face.vertexs[face.vertexs.size()-1]->x3);

    res = Vec4(face.normals[0]->x(),face.normals[0]->y(),face.normals[0]->z());

    //res = res;
    Vec4 pmedio;
    for(int i=0;i<face.vertexs.size();i++){
        pmedio = pmedio + Vec4(face.vertexs[i]->x1,face.vertexs[i]->x2,face.vertexs[i]->x3);
    }
    pmedio = pmedio/face.vertexs.size();
    glDisable(GL_LIGHTING);
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex3f(pmedio.x(),pmedio.y(),pmedio.z());
    glVertex3f(pmedio.x()+res.x(),pmedio.y()+res.y(),pmedio.z()+res.z());
    glEnd();
    glEnable(GL_LIGHTING);
}

