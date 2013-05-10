#ifndef MATERIAL_H
#define MATERIAL_H
#include <GL/glut.h>
#include <QColor>
//tipos pedra
#define MATERIAL_EMERALD        0
#define MATERIAL_JADE           1
#define MATERIAL_OBSIDIAN       2
#define MATERIAL_PEARL          3
#define MATERIAL_RUBY           4
#define MATERIAL_TURQUOSIE      5
//tipos metal
#define MATERIAL_BRONZE         6
#define MATERIAL_BRONZE_POLIERT 7
#define MATERIAL_CHROME         8
#define MATERIAL_GOLD           9
#define MATERIAL_GOLD_POLIERT   10
#define MATERIAL_COPPER         11 //KUPFER
#define MATERIAL_COPPER_POLIERT 12 //KUPFER
#define MATERIAL_BRASS          13 //MESSING
#define MATERIAL_SILVER         14
#define MATERIAL_SILVER_POLIERT 15
#define MATERIAL_ZINN           16
//tipos kunstoff
#define MATERIAL_GUMMI          17
#define MATERIAL_PLASTIK        18

//cores
#define MATERIAL_BLACK_PLASTIC  19
#define MATERIAL_CYAN_PLASTIC   20
#define MATERIAL_GREEN_PLASTIC  21
#define MATERIAL_RED_PLASTIC    22
#define MATERIAL_WHITE_PLASTIC  23
#define MATERIAL_YELLOW_PLASTIC 24
#define MATERIAL_BLACK_RUBBER   25
#define MATERIAL_CYAN_RUBBER    26
#define MATERIAL_GREEN_RUBER    27
#define MATERIAL_RED_RUBBER     28
#define MATERIAL_WHITE_RUBBER   29
#define MATERIAL_YELLOW_RUBBER  30




class Material
{
public:
    Material();

public:
 float ambient[4];
 float diffuse[4];
 float specular[4];
 float shininess;
 float refl;    /* reflection 0-1 */
 float transp;  /* transparency 0-1 */

 void static setMaterial(Material *mat,int type);
 void static setMaterialOpenGL(int type);
 Material* getMaterial(int type);
 QColor static getColorMaterial(int type);


};

#endif // MATERIAL_H
