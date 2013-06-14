#ifndef TEXTURE_H
#define TEXTURE_H
#include <GL/glut.h>
#include <string>
class Texture
{
public:
    std::string path;
    GLubyte	* imageData; // Image Data (Up To 32 Bits)
    GLuint	bpp;	//Image Color Depth In Bits Per Pixel
    GLuint	width;	//Image Width
    GLuint	height;	//Image Height
    GLuint	texID; // Texture ID Used To Select A Texture
    GLuint	type;	//Image Type (GL_RGB, GL_RGBA)
public:
    Texture();
    bool loadTGA(const char* filename, int *width, int *height, int *components);
};

#endif // TEXTURE_H
