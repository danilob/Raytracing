#ifndef TEXTURE_H
#define TEXTURE_H
#include <GL/glut.h>
#include <string>
#include <QImage>
#include "math/vec4.h"

#define TYPE_ONLY_TEXTURE 0
#define TYPE_REPLACE_TEXTURE 1
#define MAP_TILING 2
#define MAP_DEFAULT 3
#define PLANAR_MAPPING 4

class Texture
{
public:
    QImage *image;

    int  	type;	//tipo de uso da textura
    int     mapping; //informa o tipo de mapping se é tiling ou não
public:
    Texture();
    Texture(QImage* img);
    void setTypeMapping(int t_mapping);
    int  getTypeMapping();
    void setTypeTexture(int t_type);
    int  getTypeTexture();
    Vec4 getColorTexture(Vec4 map);

};

#endif // TEXTURE_H
