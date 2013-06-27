#ifndef TEXTURE_H
#define TEXTURE_H
#include <GL/glut.h>
#include <string>
#include <QImage>
#include "math/vec4.h"

#define TYPE_ONLY_TEXTURE 0
<<<<<<< HEAD
#define TYPE_REPLACE_TEXTURE 2
#define TYPE_TEXTURE_BUMP 3
=======
#define TYPE_REPLACE_TEXTURE 1
#define TYPE_TEXTURE_BUMP 1
>>>>>>> 94a1fb96a2c7b21de884cd13ce7fb194c1d00b9d
#define MAP_TILING 2
#define MAP_DEFAULT 3
#define PLANAR_MAPPING 4

class Texture
{
public:
    QImage *image;

    int  	type;	//tipo de uso da textura
    int     mapping; //informa o tipo de mapping se é tiling ou não
    bool    bump;
public:
    Texture();
    Texture(QImage* img);
    void setTypeMapping(int t_mapping);
    int  getTypeMapping();
    void setTypeTexture(int t_type);
    int  getTypeTexture();
    Vec4 getColorTexture(Vec4 map);
    Vec4 getColorNormalBump(Vec4 normal,Vec4 map);
    Vec4 getColorPointBump(Vec4 normal,Vec4 map,Vec4 pit);
    Vec4 getColor(float x, float y);
<<<<<<< HEAD
    Vec4 sample(Vec4 val);
=======
>>>>>>> 94a1fb96a2c7b21de884cd13ce7fb194c1d00b9d

};

#endif // TEXTURE_H
