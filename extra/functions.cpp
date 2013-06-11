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
    saida = aux.sprintf("%.3f %.3f\n",scene->radius,scene->focal);
    saida += aux.sprintf("%.3f %.3f %.3f %.3f\n",scene->projection.x(),scene->projection.y(),scene->projection.z(),scene->projection.w());
    saida += aux.sprintf("%.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f\n",scene->viewer[0].x(),scene->viewer[0].y(),scene->viewer[0].z(),scene->viewer[1].x(),scene->viewer[1].y(),scene->viewer[1].z(),scene->viewer[2].x(),scene->viewer[2].y(),scene->viewer[2].z());
    saida += aux.sprintf("\n%d\n",(int)scene->objects.size());
    for (unsigned int i=0;i<scene->objects.size();i++){
        saida += scene->objects.at(i)->saveObject();
    }
    saida += aux.sprintf("\n%d \n",scene->lights.size());
    for (unsigned int i=0;i<scene->lights.size();i++){
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
    float r1,r2,r3,r4;
    file >> r1 >> r2;
    scene->setDOF(r1,r2);
    file >> r1 >> r2 >> r3 >> r4;
    scene->pushProjection(r1,r2,r3,r4);
    Vec4 eye,at,up;
    file >> eye.x1 >> eye.x2 >> eye.x3 >> at.x1 >> at.x2 >> at.x3 >> up.x1 >> up.x2 >> up.x3;
    scene->pushViewer(eye,at,up);
    file >> obj_count;
    for(int i=0;i<obj_count;i++){
        file >> type;
        if (type == "e"){
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
            Cone *cone = new Cone();
            cone->setTransform(transform);
            cone->setMaterial(material);
            file >> x >> y >> z;
            Vec4 amb = Vec4(x,y,z);
            file >> x >> y >> z;
            Vec4 diff = Vec4(x,y,z);
            file >> x >> y >> z;
            Vec4 spe = Vec4(x,y,z);
            float value;
            file >> value;
            float shine = value;
            cone->getMesh()->setMaterial(amb,diff,spe,shine,material);
            file >> value;
            float reflection = value;
            cone->getMesh()->setReflection(reflection);
            file >> value;
            float refraction = value;
            cone->getMesh()->setRefraction(refraction);
            float glossyrefraction,glossyreflection;
            file >> glossyreflection >> glossyrefraction;
            cone->getMesh()->setGlossyReflection(glossyreflection);
            cone->getMesh()->setGlossyRefraction(glossyrefraction);
            Vec4 motion;
            file >> motion.x1 >> motion.x2 >> motion.x3;
            cone->setMotion(motion);
            char val;
            file >> val;
            if (val == 'f')
                cone->setEnabled(false);
            else
                cone->setEnabled(true);
            file >> val;
            if (val == 'f')
                cone->setSelected(false);
            else
                cone->setSelected(true);
            char names[120];
            file.getline(names,120);
            //fgets(name,file);
            cone->setName(QString(names));
            scene->objects.push_back(cone);
        }
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
            file >> x >> y >> z;
            Vec4 amb = Vec4(x,y,z);
            file >> x >> y >> z;
            Vec4 diff = Vec4(x,y,z);
            file >> x >> y >> z;
            Vec4 spe = Vec4(x,y,z);
            float value;
            file >> value;
            float shine = value;
            cube->getMesh()->setMaterial(amb,diff,spe,shine,material);
            file >> value;
            float reflection = value;
            cube->getMesh()->setReflection(reflection);
            file >> value;
            float refraction = value;
            cube->getMesh()->setRefraction(refraction);
            float glossyrefraction,glossyreflection;
            file >> glossyreflection >> glossyrefraction;
            cube->getMesh()->setGlossyReflection(glossyreflection);
            cube->getMesh()->setGlossyRefraction(glossyrefraction);
            Vec4 motion;
            file >> motion.x1 >> motion.x2 >> motion.x3;
            cube->setMotion(motion);
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
            Plane *plane = new Plane();
            plane->setTransform(transform);
            plane->setMaterial(material);
            file >> x >> y >> z;
            Vec4 amb = Vec4(x,y,z);
            file >> x >> y >> z;
            Vec4 diff = Vec4(x,y,z);
            file >> x >> y >> z;
            Vec4 spe = Vec4(x,y,z);
            float value;
            file >> value;
            float shine = value;
            plane->getMesh()->setMaterial(amb,diff,spe,shine,material);
            file >> value;
            float reflection = value;
            plane->getMesh()->setReflection(reflection);
            file >> value;
            float refraction = value;
            plane->getMesh()->setRefraction(refraction);
            float glossyrefraction,glossyreflection;
            file >> glossyreflection >> glossyrefraction;
            plane->getMesh()->setGlossyReflection(glossyreflection);
            plane->getMesh()->setGlossyRefraction(glossyrefraction);
            Vec4 motion;
            file >> motion.x1 >> motion.x2 >> motion.x3;
            plane->setMotion(motion);
            char val;
            file >> val;
            if (val == 'f')
                plane->setEnabled(false);
            else
                plane->setEnabled(true);
            file >> val;
            if (val == 'f')
                plane->setSelected(false);
            else
                plane->setSelected(true);
            char names[120];
            file.getline(names,120);
            //fgets(name,file);
            plane->setName(QString(names));
            scene->objects.push_back(plane);
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
            Sphere *sphere = new Sphere();
            sphere->setTransform(transform);
            sphere->setMaterial(material);
            file >> x >> y >> z;
            Vec4 amb = Vec4(x,y,z);
            file >> x >> y >> z;
            Vec4 diff = Vec4(x,y,z);
            file >> x >> y >> z;
            Vec4 spe = Vec4(x,y,z);
            float value;
            file >> value;
            float shine = value;
            sphere->getMesh()->setMaterial(amb,diff,spe,shine,material);
            file >> value;
            float reflection = value;
            sphere->getMesh()->setReflection(reflection);
            file >> value;
            float refraction = value;
            sphere->getMesh()->setRefraction(refraction);
            float glossyrefraction,glossyreflection;
            file >> glossyreflection >> glossyrefraction;
            sphere->getMesh()->setGlossyReflection(glossyreflection);
            sphere->getMesh()->setGlossyRefraction(glossyrefraction);
            Vec4 motion;
            file >> motion.x1 >> motion.x2 >> motion.x3;
            sphere->setMotion(motion);
            char val;
            file >> val;
            if (val == 'f')
                sphere->setEnabled(false);
            else
                sphere->setEnabled(true);
            file >> val;
            if (val == 'f')
                sphere->setSelected(false);
            else
                sphere->setSelected(true);
            char names[120];
            file.getline(names,120);
            //fgets(name,file);
            sphere->setName(QString(names));
            scene->objects.push_back(sphere);
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
            file >> x >> y >> z;
            Vec4 amb = Vec4(x,y,z);
            file >> x >> y >> z;
            Vec4 diff = Vec4(x,y,z);
            file >> x >> y >> z;
            Vec4 spe = Vec4(x,y,z);
            float value;
            file >> value;
            float shine = value;
            cylinder->getMesh()->setMaterial(amb,diff,spe,shine,material);
            file >> value;
            float reflection = value;
            cylinder->getMesh()->setReflection(reflection);
            file >> value;
            float refraction = value;
            cylinder->getMesh()->setRefraction(refraction);
            float glossyrefraction,glossyreflection;
            file >> glossyreflection >> glossyrefraction;
            cylinder->getMesh()->setGlossyReflection(glossyreflection);
            cylinder->getMesh()->setGlossyRefraction(glossyrefraction);
            Vec4 motion;
            file >> motion.x1 >> motion.x2 >> motion.x3;
            cylinder->setMotion(motion);
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
            file >> x >> y >> z;
            Vec4 amb = Vec4(x,y,z);
            file >> x >> y >> z;
            Vec4 diff = Vec4(x,y,z);
            file >> x >> y >> z;
            Vec4 spe = Vec4(x,y,z);
            float value;
            file >> value;
            float shine = value;
            prism->getMesh()->setMaterial(amb,diff,spe,shine,material);
            file >> value;
            float reflection = value;
            prism->getMesh()->setReflection(reflection);
            file >> value;
            float refraction = value;
            prism->getMesh()->setRefraction(refraction);
            float glossyrefraction,glossyreflection;
            file >> glossyreflection >> glossyrefraction;
            prism->getMesh()->setGlossyReflection(glossyreflection);
            prism->getMesh()->setGlossyRefraction(glossyrefraction);
            Vec4 motion;
            file >> motion.x1 >> motion.x2 >> motion.x3;
            prism->setMotion(motion);
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
            file >> x >> y >> z;
            Vec4 amb = Vec4(x,y,z);
            file >> x >> y >> z;
            Vec4 diff = Vec4(x,y,z);
            file >> x >> y >> z;
            Vec4 spe = Vec4(x,y,z);
            float value;
            file >> value;
            float shine = value;
            hemi->getMesh()->setMaterial(amb,diff,spe,shine,material);
            file >> value;
            float reflection = value;
            hemi->getMesh()->setReflection(reflection);
            file >> value;
            float refraction = value;
            hemi->getMesh()->setRefraction(refraction);
            float glossyrefraction,glossyreflection;
            file >> glossyreflection >> glossyrefraction;
            hemi->getMesh()->setGlossyReflection(glossyreflection);
            hemi->getMesh()->setGlossyRefraction(glossyrefraction);
            Vec4 motion;
            file >> motion.x1 >> motion.x2 >> motion.x3;
            hemi->setMotion(motion);
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
        }else if (type == "r"){
            AreaLight *arealight = new AreaLight();
            float x,y,z;
            file >> x >> y >> z;
            QColor color;
            color.setRgb(x*255,y*255,z*255);
            arealight->setAmbientColor(color);
            file >> x >> y >> z;
            color.setRgb(x*255,y*255,z*255);
            arealight->setSpecularColor(color);
            file >> x >> y >> z;
            color.setRgb(x*255,y*255,z*255);
            arealight->setDiffuseColor(color);
            file >> x >> y >> z;
            arealight->setPosition(Vec4(x,y,z));
            file >> x >> y >> z;
            arealight->setAttenuation(Vec4(x,y,z));
            file >> x >> y >> z;
            arealight->setVecA(Vec4(x,y,z));
            file >> x >> y >> z;
            arealight->setVecB(Vec4(x,y,z));
            file >> val;
            if(val == 'f')
                arealight->setEnabled(false);
            else
                arealight->setEnabled(true);
            file >> val;
            if(val == 'f')
                arealight->setVisible(false);
            else
                arealight->setVisible(true);
            file >> val;
            if(val == 'f')
                arealight->setSelected(false);
            else
                arealight->setSelected(true);
            char names[120];
            file.getline(names,120);
            arealight->setName(names);
            scene->lights.push_back(arealight);

        }
        else if (type == "d"){
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
            spotlight->setAngleInner(var);
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
