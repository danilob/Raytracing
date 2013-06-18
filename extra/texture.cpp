#include "texture.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <QRgb>
Texture::Texture()
{
}

Texture::Texture(QImage *img)
{
    image = img;
    this->type = TYPE_TEXTURE_BUMP;
    this->mapping = MAP_DEFAULT;
    bump = true;
}

void Texture::setTypeMapping(int t_mapping)
{
    this->mapping = t_mapping;
}

int Texture::getTypeMapping()
{
    return this->mapping;
}

void Texture::setTypeTexture(int t_type)
{
    this->type = t_type;
}

int Texture::getTypeTexture()
{
    return this->type;
}

Vec4 Texture::getColorTexture(Vec4 map)
{
    QRgb color = image->pixel(map.x()*image->width(),map.y()*image->height());
    return Vec4(qRed(color)/255.0,qGreen(color)/255.0,qBlue(color)/255.0);
}

Vec4 Texture::getColorNormalBump(Vec4 n, Vec4 map)
{

    if(!bump) return n;
    //Vec4 normal = (Vec4(map.x(),0,0)^Vec4(0,map.y(),0));
    Vec4 A = (n ^ Vec4(1,0,0)).unitary();
    Vec4 B = (n ^ A).unitary();
    QRgb color = image->pixel(map.x()*image->width(),map.y()*image->height());
    Vec4 bump1 =  Vec4(qRed(color)/255.0,qGreen(color)/255.0,qBlue(color)/255.0);
    Vec4 map2 = Vec4(1-map.x(),1-map.y());
    //map = Vec4(map.x(),0);

    //QRgb color = image->pixel(map.x()*image->width(),map.y()*image->height());
    //Vec4 bump2 =  Vec4(qRed(color)/255.0,qGreen(color)/255.0,qBlue(color)/255.0);
    //Vec4 bu = Vec4(bump1.x());
    //Vec4 bv = Vec4(0,bump1.y());
    Vec4 bu = (getColor(map2.x(),map.y()) - getColor(map.x(),map.y())+getColor(map2.x(),map2.y())-getColor(map.x(),map2.y()))/(2*((Vec4(map2.x())+Vec4(map.x())).module()));
    Vec4 bv = (getColor(map.x(),map2.y()) - getColor(map.x(),map.y())+getColor(map2.x(),map2.y())-getColor(map2.x(),map.y()))/(2*((Vec4(0,map2.y())+Vec4(0,map.y())).module()));
    //Vec4 D = (bu.mult(A) - bv.mult(B));
    Vec4 D = bv.mult((A^n)/n.module()) + bu.mult((n^B)/n.module());
    return (n + D);

}

Vec4 Texture::getColorPointBump(Vec4 normal, Vec4 map, Vec4 pit)
{
    QRgb color = image->pixel(map.x()*image->width(),map.y()*image->height());
    Vec4 bump1 =  Vec4(qRed(color)/255.0,qGreen(color)/255.0,qBlue(color)/255.0);
    return pit + (bump1.mult(normal))/normal.module();

}

Vec4 Texture::getColor(float x, float y)
{
    QRgb color = image->pixel(x*image->width(),y*image->height());
    return  Vec4(qRed(color)/255.0,qGreen(color)/255.0,qBlue(color)/255.0);

}
