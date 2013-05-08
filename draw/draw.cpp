#include "draw.h"
#include "GL/glut.h"
#include "interface/scene.h"
Draw::Draw()
{

}

void Draw::drawPlane(int size, bool solid, bool texture)
{

    if(!solid){
        glDisable(GL_LIGHTING);
        glPushMatrix();
        glColor3f(0.5,0.5,0.5);
        glBegin(GL_LINES);
        for(int i=-size;i<=size;i++){
            for(int j=size;j>=-size;j--){
                glVertex3f(i,0,j);
                glVertex3f(i,0,-j);
                glVertex3f(i,0,j);
                glVertex3f(-i,0,j);
            }
        }
        glEnd();
        glPopMatrix();
        glEnable(GL_LIGHTING);
    }else{
        Material *mat = new Material();
        mat->setMaterial(mat,MATERIAL_GUMMI);
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,mat->ambient);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat->diffuse);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat->specular);
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, mat->shininess*128);
        glPushMatrix();

        glBegin(GL_QUADS);
            glNormal3f(0,1,0);
            glVertex3f(size,0,size);
            glVertex3f(size,0,-size);
            glVertex3f(-size,0,-size);
            glVertex3f(-size,0,size);
        glEnd();
        glPopMatrix();
    }
}



void Draw::drawArrow(Vec4 *position_,double size)
{
    glPushMatrix();
    int _pbase = 30;
    double length_ = 1.5;
    double radius = 0.7*length_;
    double alpha  = 2*M_PI/_pbase;
        Vec4 vertexs[_pbase+1];
        for (int i=0;i<_pbase;i++){
            vertexs[i].setVec4(cos(alpha*i)*radius+position_->x1*length_,position_->x2*length_,sin(alpha*i)*radius+position_->x3*length_);
        }
        vertexs[_pbase] = Vec4(-position_->x1,-position_->x2,-position_->x3);
        Vec4 normal;
        glTranslated(size*position_->x1,size*position_->x2,size*position_->x3);
        glBegin(GL_POLYGON);
            for (int i=0;i<_pbase;i++){
                glVertex3d(vertexs[i].x1,vertexs[i].x2,vertexs[i].x3);
            }
        glEnd();
        glBegin(GL_TRIANGLES);
            for (int i=0;i<_pbase;i++){
                if(i<_pbase-1){

                    glVertex3d(vertexs[i].x1,vertexs[i].x2,vertexs[i].x3);
                    glVertex3d(vertexs[i+1].x1,vertexs[i+1].x2,vertexs[i+1].x3);
                    glVertex3d(vertexs[_pbase].x1,vertexs[_pbase].x2,vertexs[_pbase].x3);
                }else{

                    glVertex3d(vertexs[i].x1,vertexs[i].x2,vertexs[i].x3);
                    glVertex3d(vertexs[0].x1,vertexs[0].x2,vertexs[0].x3);
                    glVertex3d(vertexs[_pbase].x1,vertexs[_pbase].x2,vertexs[_pbase].x3);
                }
            }
        glEnd();
        glPopMatrix();
}

void Draw::drawSpot(Vec4 *position_, Vec4 *direction,double angle)
{
    glPushMatrix();
    int _pbase = 30;
    //double length_ = 1.0;
    double radius = atan(M_PI*angle/180.0);
    double alpha  = 2*M_PI/_pbase;

        Vec4 vertexs[_pbase+1];
        for (int i=0;i<_pbase;i++){
            vertexs[i].setVec4(cos(alpha*i)*radius+(position_->x1+direction->x1),(position_->x2+direction->x2),sin(alpha*i)*radius+(position_->x3+direction->x3));
        }
        vertexs[_pbase] = Vec4(position_->x1,position_->x2,position_->x3);
        Vec4 normal;
        glTranslated(position_->x1,position_->x2,position_->x3);
        glBegin(GL_LINES);
            for (int i=0;i<_pbase;i++){
                    glVertex3d(vertexs[_pbase].x1,vertexs[_pbase].x2,vertexs[_pbase].x3) ;
                    glVertex3d(vertexs[i].x1,vertexs[i].x2,vertexs[i].x3);
            }
        glEnd();

    glPopMatrix();
}
