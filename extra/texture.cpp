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
    this->type = TYPE_REPLACE_TEXTURE;
    this->mapping = MAP_DEFAULT;
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
