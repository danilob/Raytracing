#include "texture.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
Texture::Texture()
{
}
typedef struct
{
    GLubyte Header[12];	//TGA File Header
} TGAHeader;

typedef struct
{
    GLubyte		header[6]; // First 6 Useful Bytes From The Header
    GLuint		bytesPerPixel; //Holds Number Of Bytes Per Pixel Used In The TGA File
    GLuint		imageSize; // Used To Store The Image Size When Setting Aside Ram
    GLuint		temp; //Temporary Variable
    GLuint		type;
    GLuint		Height;	// Height of Image
    GLuint		Width;	//Width of Image
    GLuint		Bpp; //Bits Per Pixel
} TGA;

TGAHeader tgaheader; // TGA header
TGA tga; //TGA image data


GLubyte uTGAcompare[12] = {0,0,2, 0,0,0,0,0,0,0,0,0}; // Uncompressed TGA Header
GLubyte cTGAcompare[12] = {0,0,10,0,0,0,0,0,0,0,0,0}; // Compressed TGA Header


bool Texture::loadTGA(const char *filename, int *width, int *height, int *components)
{
    FILE * fTGA;
    fTGA = fopen(filename, "rb");

    if(fTGA == NULL)
    {
        printf("Error could not open texture file");
        return false;
    }

    if(fread(&tgaheader, sizeof(TGAHeader), 1, fTGA) == 0)
    {
        printf("Error could not read file header");
        if(fTGA != NULL)
        {
            fclose(fTGA);
        }
        return false;
    }
    // See if header matches the predefined header of
    // an Uncompressed TGA image
    if(memcmp(uTGAcompare, &tgaheader, sizeof(tgaheader)) == 0)
    {
        GLuint cswap;
        if(fread(tga.header, sizeof(tga.header), 1, fTGA) == 0)
        {
            printf("Error could not read info header");
            if(fTGA != NULL)
            {
                fclose(fTGA);
            }
            return false;
        }

        this->width  = tga.header[1] * 256 + tga.header[0];
        this->height = tga.header[3] * 256 + tga.header[2];
        this->bpp	= tga.header[4];
        tga.Width		= this->width;
        tga.Height		= this->height;
        tga.Bpp			= this->bpp;

        if((this->width <= 0) || (this->height <= 0) || ((this->bpp != 24) && (this->bpp !=32)))
        {
            printf("Error invalid texture information");
            if(fTGA != NULL)
            {
                fclose(fTGA);
            }
            return false;
        }

        if(this->bpp == 24)
        {
            this->type	= GL_RGB;
        }
        else
        {
            this->type	= GL_RGBA;
        }

        tga.bytesPerPixel	= (tga.Bpp / 8);
        tga.imageSize		= (tga.bytesPerPixel * tga.Width * tga.Height);
        this->imageData	= (GLubyte *)malloc(tga.imageSize);

        if(this->imageData == NULL)
        {
            printf("Error could not allocate memory for image");
            fclose(fTGA);
            return NULL;
        }

        if(fread(this->imageData, 1, tga.imageSize, fTGA) != tga.imageSize)
        {
            printf("Error could not read image data");
            if(this->imageData != NULL)
            {
                free(this->imageData);
            }
            fclose(fTGA);
            return NULL;
        }

        /* Byte Swapping Optimized By Steve Thomas */
        for(cswap = 0; cswap < (int)tga.imageSize; cswap += tga.bytesPerPixel)
        {
            this->imageData[cswap] ^= this->imageData[cswap+2] ^=
            this->imageData[cswap] ^= this->imageData[cswap+2];
        }

        fclose(fTGA);
    }
    else if(memcmp(cTGAcompare, &tgaheader, sizeof(tgaheader)) == 0)
    {
        GLuint pixelcount	= tga.Height * tga.Width;
        GLuint currentpixel	= 0;
        GLuint currentbyte	= 0;
        GLubyte * colorbuffer = (GLubyte *)malloc(tga.bytesPerPixel);

        if(fread(tga.header, sizeof(tga.header), 1, fTGA) == 0)
        {
            printf("Error could not read info header");
            if(fTGA != NULL)
            {
                fclose(fTGA);
            }
            return NULL;
        }

        this->width  = tga.header[1] * 256 + tga.header[0];
        this->height = tga.header[3] * 256 + tga.header[2];
        this->bpp	= tga.header[4];
        tga.Width		= this->width;
        tga.Height		= this->height;
        tga.Bpp			= this->bpp;

        if((this->width <= 0) || (this->height <= 0) || ((this->bpp != 24) && (this->bpp !=32)))
        {
            printf("Error Invalid texture information");
            if(fTGA != NULL)
            {
                fclose(fTGA);
            }
            return NULL;
        }

        tga.bytesPerPixel	= (tga.Bpp / 8);
        tga.imageSize		= (tga.bytesPerPixel * tga.Width * tga.Height);
        this->imageData	= (GLubyte *)malloc(tga.imageSize);

        if(this->imageData == NULL)
        {
            printf("Error could not allocate memory for image");
            fclose(fTGA);
            return NULL;
        }

        do
        {
            GLubyte chunkheader = 0;

            if(fread(&chunkheader, sizeof(GLubyte), 1, fTGA) == 0)
            {
                printf("Error could not read RLE header");
                if(fTGA != NULL)
                {
                    fclose(fTGA);
                }
                if(this->imageData != NULL)
                {
                    free(this->imageData);
                }
                return NULL;
            }

            if(chunkheader < 128)
            {
                short counter;
                chunkheader++;
                for(counter = 0; counter < chunkheader; counter++)
                {
                    if(fread(colorbuffer, 1, tga.bytesPerPixel, fTGA) != tga.bytesPerPixel)
                    {
                        printf("Error could not read image data");

                        if(fTGA != NULL)
                        {
                            fclose(fTGA);
                        }

                        if(colorbuffer != NULL)
                        {
                            free(colorbuffer);
                        }

                        if(this->imageData != NULL)
                        {
                            free(this->imageData);
                        }

                        return NULL;
                    }

                    this->imageData[currentbyte		] = colorbuffer[2];
                    this->imageData[currentbyte + 1	] = colorbuffer[1];
                    this->imageData[currentbyte + 2	] = colorbuffer[0];

                    if(tga.bytesPerPixel == 4)
                    {
                        this->imageData[currentbyte + 3] = colorbuffer[3];
                    }

                    currentbyte += tga.bytesPerPixel;
                    currentpixel++;

                    if(currentpixel > pixelcount)
                    {
                        printf("Error too many pixels read");

                        if(fTGA != NULL)
                        {
                            fclose(fTGA);
                        }

                        if(colorbuffer != NULL)
                        {
                            free(colorbuffer);
                        }

                        if(this->imageData != NULL)
                        {
                            free(this->imageData);
                        }

                        return NULL;
                    }
                }
            }
            else
            {
                /* chunkheader > 128 RLE data, next color  reapeated chunkheader - 127 times */
                short counter;
                chunkheader -= 127;
                if(fread(colorbuffer, 1, tga.bytesPerPixel, fTGA) != tga.bytesPerPixel)
                {
                    printf("Error could not read from file");

                    if(fTGA != NULL)
                    {
                        fclose(fTGA);
                    }

                    if(colorbuffer != NULL)
                    {
                        free(colorbuffer);
                    }

                    if(this->imageData != NULL)
                    {
                        free(this->imageData);
                    }

                    return NULL;
                }

                for(counter = 0; counter < chunkheader; counter++)
                {
                    this->imageData[currentbyte		] = colorbuffer[2];
                    this->imageData[currentbyte + 1	] = colorbuffer[1];
                    this->imageData[currentbyte + 2	] = colorbuffer[0];

                    if(tga.bytesPerPixel == 4)
                    {
                        this->imageData[currentbyte + 3] = colorbuffer[3];
                    }

                    currentbyte += tga.bytesPerPixel;
                    currentpixel++;

                    if(currentpixel > pixelcount)
                    {
                        printf("Error too many pixels read");

                        if(fTGA != NULL)
                        {
                            fclose(fTGA);
                        }

                        if(colorbuffer != NULL)
                        {
                            free(colorbuffer);
                        }

                        if(this->imageData != NULL)
                        {
                            free(this->imageData);
                        }

                        return NULL;
                    }
                }
            }
        }

        while(currentpixel < pixelcount);
        fclose(fTGA);
    }
    else
    {
        printf("Error TGA file be type 2 or type 10 ");
        fclose(fTGA);
        return false;
    }
    (*width) = this->width;
    (*height) = this->height;
    if(this->bpp == 24)
        (*components)	= 3;
    else
        (*components)	= 4;
    return true;
}
