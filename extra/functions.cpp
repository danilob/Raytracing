#include "functions.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <GL/gl.h>

#include <QFileInfo>
using namespace std;

Functions::Functions()
{
}


bool Functions::saveImage(int width, int height, const std::string &fileName)
{

    FILE *fScreenshot;
    int size = width * height * 3;
    GLubyte *pixels = new GLubyte [size];

    //verifica se foi possível a alocação de memória
    if (pixels == NULL) return false;

    //fileName.push_back(".tga");
    fScreenshot = fopen(fileName.c_str(),"wb");

    glPixelStorei(GL_PACK_ALIGNMENT, 1);
    glReadBuffer(GL_BACK_LEFT);
    glReadPixels(0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, pixels);




    //converte para o formato RGB

    unsigned char temp;
    int i = 0;
    while (i < size)
    {
        temp = pixels[i];       //grab blue
        pixels[i] = pixels[i+2];//assign red to blue
        pixels[i+2] = temp;     //assign blue to red
        i += 3;     //skip to next blue byte
    }

    //contiguração do formato TGA
    unsigned char TGAheader[12]={0,0,2,0,0,0,0,0,0,0,0,0};
    unsigned char header[6] = {width%256,width/256,height%256,height/256,24,0};

    fwrite(TGAheader, sizeof(unsigned char), 12, fScreenshot);
    fwrite(header, sizeof(unsigned char), 6, fScreenshot);
    fwrite(pixels, sizeof(GLubyte), size, fScreenshot);
    fclose(fScreenshot);

    delete [] pixels;
    return true;

}

bool Functions::saveScene(Scene* scene, QString fileName)
{
    QFile sFile(fileName);
    QString saida,aux;
    saida = aux.sprintf("%d \n",scene->objects.size());
    for (int i=0;i<scene->objects.size();i++){
        saida += scene->objects.at(i)->saveObject();
    }
    saida += aux.sprintf("\n%d\n",scene->lights.size());
    for (int i=0;i<scene->lights.size();i++){
        saida += scene->lights.at(i)->saveLight();
    }
    if(!fileName.isEmpty()){
        if(sFile.open(QFile::WriteOnly | QFile::Text)){
            QTextStream out(&sFile);
            out << saida;
            sFile.flush();
            sFile.close();
            return true;
        }
    }
    return false;

}

bool Functions::loadScene(Scene *scene, const string &fileName)
{
    scene->objects.clear();
    scene->lights.clear();

    ifstream file(fileName.data(), ios::in);
    if(!file)
    {
        cerr << "File \"" << fileName << "\" not found." << endl;
        return false;
    }

    string type;
    int obj_count;
    file >> obj_count;
    for(int i=0;i<obj_count;i++){
        file >> type;
        if (type == "c"){
            float x,y,z;
            Vec4 aux;
            file >> x >> y >> z;
            aux.setVec4(x,y,z);
            Matrix4x4 transform;
            //transform.setTranslate(aux);
            file >> x >> y >> z;
            //aux.setVec4(x,y,z);
            transform.scale(x,y,z);
            file >> x >> y >> z;
            //aux.setVec4(x,y,z);
            transform.setRotationZ(z);
            transform.setRotationY(y);
            transform.setRotationX(x);
            transform.setTranslate(aux);
            int material;
            file >> material;
            Cube *cube = new Cube();
            cube->setTransform(transform);
            cube->setMaterial(material);

            char val;
            file >> val;
            if (val == 'f')
                cube->setEnabled(false);
            else
                cube->setEnabled(true);
            file >> val;
            if (val == 'f')
                cube->setSelected(false);
            else
                cube->setSelected(true);
            char names[120];
            file.getline(names,120);
            //fgets(name,file);
            cube->setName(QString(names));
            scene->objects.push_back(cube);
        }
        else if(type == "t"){
            float x,y,z;
            Vec4 aux;
            file >> x >> y >> z;
            aux.setVec4(x,y,z);
            Matrix4x4 transform;
            //transform.setTranslate(aux);
            file >> x >> y >> z;
            //aux.setVec4(x,y,z);
            transform.scale(x,y,z);
            file >> x >> y >> z;
            //aux.setVec4(x,y,z);
            transform.setRotationZ(z);
            transform.setRotationY(y);
            transform.setRotationX(x);
            transform.setTranslate(aux);
            int material;
            file >> material;
            Plane *cylinder = new Plane();
            cylinder->setTransform(transform);
            cylinder->setMaterial(material);

            char val;
            file >> val;
            if (val == 'f')
                cylinder->setEnabled(false);
            else
                cylinder->setEnabled(true);
            file >> val;
            if (val == 'f')
                cylinder->setSelected(false);
            else
                cylinder->setSelected(true);
            char names[120];
            file.getline(names,120);
            //fgets(name,file);
            cylinder->setName(QString(names));
            scene->objects.push_back(cylinder);
        }
        else if(type == "s"){
            float x,y,z;
            Vec4 aux;
            file >> x >> y >> z;
            aux.setVec4(x,y,z);
            Matrix4x4 transform;
            //transform.setTranslate(aux);
            file >> x >> y >> z;
            //aux.setVec4(x,y,z);
            transform.scale(x,y,z);
            file >> x >> y >> z;
            //aux.setVec4(x,y,z);
            transform.setRotationZ(z);
            transform.setRotationY(y);
            transform.setRotationX(x);
            transform.setTranslate(aux);
            int material;
            file >> material;
            Sphere *cylinder = new Sphere();
            cylinder->setTransform(transform);
            cylinder->setMaterial(material);

            char val;
            file >> val;
            if (val == 'f')
                cylinder->setEnabled(false);
            else
                cylinder->setEnabled(true);
            file >> val;
            if (val == 'f')
                cylinder->setSelected(false);
            else
                cylinder->setSelected(true);
            char names[120];
            file.getline(names,120);
            //fgets(name,file);
            cylinder->setName(QString(names));
            scene->objects.push_back(cylinder);
        }
        else if(type == "y"){
            float x,y,z;
            Vec4 aux;
            file >> x >> y >> z;
            aux.setVec4(x,y,z);
            Matrix4x4 transform;
            //transform.setTranslate(aux);
            file >> x >> y >> z;
            //aux.setVec4(x,y,z);
            transform.scale(x,y,z);
            file >> x >> y >> z;
            //aux.setVec4(x,y,z);
            transform.setRotationZ(z);
            transform.setRotationY(y);
            transform.setRotationX(x);
            transform.setTranslate(aux);
            int material;
            file >> material;
            Cylinder *cylinder = new Cylinder();
            cylinder->setTransform(transform);
            cylinder->setMaterial(material);

            char val;
            file >> val;
            if (val == 'f')
                cylinder->setEnabled(false);
            else
                cylinder->setEnabled(true);
            file >> val;
            if (val == 'f')
                cylinder->setSelected(false);
            else
                cylinder->setSelected(true);
            char names[120];
            file.getline(names,120);
            //fgets(name,file);
            cylinder->setName(QString(names));
            scene->objects.push_back(cylinder);
        }else if(type == "p"){
            float x,y,z;
            Vec4 aux;
            file >> x >> y >> z;
            aux.setVec4(x,y,z);
            Matrix4x4 transform;
            //transform.setTranslate(aux);
            file >> x >> y >> z;
            //aux.setVec4(x,y,z);
            transform.scale(x,y,z);
            file >> x >> y >> z;
            //aux.setVec4(x,y,z);
            transform.setRotationZ(z);
            transform.setRotationY(y);
            transform.setRotationX(x);
            transform.setTranslate(aux);
            int material;
            file >> material;
            Prism *prism = new Prism();
            prism->setTransform(transform);
            prism->setMaterial(material);

            char val;
            file >> val;
            if (val == 'f')
                prism->setEnabled(false);
            else
                prism->setEnabled(true);
            file >> val;
            if (val == 'f')
                prism->setSelected(false);
            else
                prism->setSelected(true);
            char names[120];
            file.getline(names,120);
            //fgets(name,file);
            prism->setName(QString(names));
            scene->objects.push_back(prism);
        }else{
            float x,y,z;
            Vec4 aux;
            file >> x >> y >> z;
            aux.setVec4(x,y,z);
            Matrix4x4 transform;
            //transform.setTranslate(aux);
            file >> x >> y >> z;
            //aux.setVec4(x,y,z);
            transform.scale(x,y,z);
            file >> x >> y >> z;
            //aux.setVec4(x,y,z);
            transform.setRotationZ(z);
            transform.setRotationY(y);
            transform.setRotationX(x);
            transform.setTranslate(aux);
            int material;
            file >> material;
            HemiSphere *hemi = new HemiSphere();
            hemi->setTransform(transform);
            hemi->setMaterial(material);

            char val;
            file >> val;
            if (val == 'f')
                hemi->setEnabled(false);
            else
                hemi->setEnabled(true);
            file >> val;
            if (val == 'f')
                hemi->setSelected(false);
            else
                hemi->setSelected(true);
            char names[120];
            file.getline(names,120);
            //fgets(name,file);
            hemi->setName(QString(names));
            scene->objects.push_back(hemi);
        }
    }
    int light_count;
    file >> light_count;
    for (int i=0;i<light_count;i++){
        file >> type;
        char val;
        if (type == "a"){

            AmbientLight *ambientelight = new AmbientLight();
            float x,y,z;
            file >> x >> y >> z;
            QColor color;
            color.setRgb(x*255,y*255,z*255);
            ambientelight->setAmbientColor(color);
            char val;
            file >> val;
            if(val == 'f')
                ambientelight->setSelected(false);
            else
                ambientelight->setSelected(true);
            char names[120];
            file.getline(names,120);
            ambientelight->setName(QString(names));
            scene->lights.push_back(ambientelight);
        }else if (type == "o"){
            PontualLight *pontuallight = new PontualLight();
            float x,y,z;
            file >> x >> y >> z;
            QColor color;
            color.setRgb(x*255,y*255,z*255);
            pontuallight->setAmbientColor(color);
            file >> x >> y >> z;
            color.setRgb(x*255,y*255,z*255);
            pontuallight->setSpecularColor(color);
            file >> x >> y >> z;
            color.setRgb(x*255,y*255,z*255);
            pontuallight->setDiffuseColor(color);
            file >> x >> y >> z;
            pontuallight->setPosition(Vec4(x,y,z));
            file >> x >> y >> z;
            pontuallight->setAttenuation(Vec4(x,y,z));
            file >> val;
            if(val == 'f')
                pontuallight->setEnabled(false);
            else
                pontuallight->setEnabled(true);
            file >> val;
            if(val == 'f')
                pontuallight->setVisible(false);
            else
                pontuallight->setVisible(true);
            file >> val;
            if(val == 'f')
                pontuallight->setSelected(false);
            else
                pontuallight->setSelected(true);
            char names[120];
            file.getline(names,120);
            pontuallight->setName(names);
            scene->lights.push_back(pontuallight);

        }else if (type == "d"){
            DirectionalLight *directionlight = new DirectionalLight();
            float x,y,z;
            file >> x >> y >> z;
            QColor color;
            color.setRgb(x*255,y*255,z*255);
            directionlight->setAmbientColor(color);
            file >> x >> y >> z;
            color.setRgb(x*255,y*255,z*255);
            directionlight->setSpecularColor(color);
            file >> x >> y >> z;
            color.setRgb(x*255,y*255,z*255);
            directionlight->setDiffuseColor(color);
            file >> x >> y >> z;
            directionlight->setDirection(Vec4(x,y,z));
            file >> val;

            if(val == 'f')
                directionlight->setEnabled(false);
            else
                directionlight->setEnabled(true);
            file >> val;
            if(val == 'f')
                directionlight->setVisible(false);
            else
                directionlight->setVisible(true);
            file >> val;
            if(val == 'f')
                directionlight->setSelected(false);
            else
                directionlight->setSelected(true);
            char names[120];
            file.getline(names,120);
            directionlight->setName(names);
            scene->lights.push_back(directionlight);
        }else{ //caso spot
            SpotLight *spotlight = new SpotLight();
            float x,y,z;
            file >> x >> y >> z;
            QColor color;
            color.setRgb(x*255,y*255,z*255);
            spotlight->setAmbientColor(color);
            file >> x >> y >> z;
            color.setRgb(x*255,y*255,z*255);
            spotlight->setSpecularColor(color);
            file >> x >> y >> z;
            color.setRgb(x*255,y*255,z*255);
            spotlight->setDiffuseColor(color);
            file >> x >> y >> z;
            spotlight->setPosition(Vec4(x,y,z));
            file >> x >> y >> z;
            spotlight->setDirection(Vec4(x,y,z));
            file >> x >> y >> z;
            spotlight->setAttenuation(Vec4(x,y,z));
            int var;
            file >> var;
            spotlight->setAngle(var);
            file >> var;
            spotlight->setExponent(var);
            file >> val;

            if(val == 'f')
                spotlight->setEnabled(false);
            else
                spotlight->setEnabled(true);
            file >> val;
            if(val == 'f')
                spotlight->setVisible(false);
            else
                spotlight->setVisible(true);
            file >> val;
            if(val == 'f')
                spotlight->setSelected(false);
            else
                spotlight->setSelected(true);
            char names[120];
            file.getline(names,120);
            spotlight->setName(names);
            scene->lights.push_back(spotlight);

        }
    }
    file.close();


}
