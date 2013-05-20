#include "material.h"
#include <math/vec4.h>
Material::Material()
{
    refl   = 0.0;
    transp = 0.0;
}

void Material::setMaterial(Material *mat, int type)
{
    switch (type){
    case MATERIAL_GOLD:{
        mat->ambient[0] = 0.25;
        mat->ambient[1] = 0.20;
        mat->ambient[2] = 0.07;
        mat->ambient[3] = 1.0;

        mat->specular[0] = 0.63;
        mat->specular[1] = 0.65;
        mat->specular[2] = 0.37;
        mat->specular[3] = 1.0;

        mat->diffuse[0] = 0.75;
        mat->diffuse[1] = 0.61;
        mat->diffuse[2] = 0.23;
        mat->diffuse[3] = 1.0;

        mat->shininess = 0.2;
        break;

    }
    case MATERIAL_GOLD_POLIERT:{
        mat->ambient[0] = 0.25;
        mat->ambient[1] = 0.22;
        mat->ambient[2] = 0.06;
        mat->ambient[3] = 1.0;

        mat->specular[0] = 0.80;
        mat->specular[1] = 0.72;
        mat->specular[2] = 0.21;
        mat->specular[3] = 1.0;

        mat->diffuse[0] = 0.35;
        mat->diffuse[1] = 0.31;
        mat->diffuse[2] = 0.09;
        mat->diffuse[3] = 1.0;

        mat->shininess = 0.078;
        break;

    }
    case MATERIAL_BRONZE:{
        mat->ambient[0] = 0.21;
        mat->ambient[1] = 0.13;
        mat->ambient[2] = 0.05;
        mat->ambient[3] = 1.0;

        mat->specular[0] = 0.39;
        mat->specular[1] = 0.27;
        mat->specular[2] = 0.17;
        mat->specular[3] = 1.0;

        mat->diffuse[0] = 0.71;
        mat->diffuse[1] = 0.43;
        mat->diffuse[2] = 0.18;
        mat->diffuse[3] = 1.0;

        mat->shininess = 0.2;
        break;

    }
    case MATERIAL_BRONZE_POLIERT:{
        mat->ambient[0] = 0.25;
        mat->ambient[1] = 0.15;
        mat->ambient[2] = 0.06;
        mat->ambient[3] = 1.0;

        mat->specular[0] = 0.40;
        mat->specular[1] = 0.24;
        mat->specular[2] = 0.10;
        mat->specular[3] = 1.0;

        mat->diffuse[0] = 0.77;
        mat->diffuse[1] = 0.46;
        mat->diffuse[2] = 0.20;
        mat->diffuse[3] = 1.0;

        mat->shininess = 0.6;
        break;

    }
    case MATERIAL_CHROME:{
        mat->ambient[0] = 0.25;
        mat->ambient[1] = 0.25;
        mat->ambient[2] = 0.25;
        mat->ambient[3] = 1.0;

        mat->specular[0] = 0.77;
        mat->specular[1] = 0.77;
        mat->specular[2] = 0.77;
        mat->specular[3] = 1.0;

        mat->diffuse[0] = 0.40;
        mat->diffuse[1] = 0.40;
        mat->diffuse[2] = 0.40;
        mat->diffuse[3] = 1.0;

        mat->shininess = 0.6;
        mat->refl = 0;
        mat->transp = 0;
        break;

    }
    case MATERIAL_COPPER:{
        mat->ambient[0] = 0.19;
        mat->ambient[1] = 0.07;
        mat->ambient[2] = 0.02;
        mat->ambient[3] = 1.0;

        mat->specular[0] = 0.26;
        mat->specular[1] = 0.14;
        mat->specular[2] = 0.09;
        mat->specular[3] = 1.0;

        mat->diffuse[0] = 0.70;
        mat->diffuse[1] = 0.27;
        mat->diffuse[2] = 0.08;
        mat->diffuse[3] = 1.0;

        mat->shininess = 0.1;
        break;

    }
    case MATERIAL_COPPER_POLIERT:{
        mat->ambient[0] = 0.23;
        mat->ambient[1] = 0.09;
        mat->ambient[2] = 0.03;
        mat->ambient[3] = 1.0;

        mat->specular[0] = 0.58;
        mat->specular[1] = 0.22;
        mat->specular[2] = 0.07;
        mat->specular[3] = 1.0;

        mat->diffuse[0] = 0.55;
        mat->diffuse[1] = 0.21;
        mat->diffuse[2] = 0.07;
        mat->diffuse[3] = 1.0;

        mat->shininess = 0.4;
        break;

    }
    case MATERIAL_BRASS:{
        mat->ambient[0] = 0.33;
        mat->ambient[1] = 0.22;
        mat->ambient[2] = 0.03;
        mat->ambient[3] = 1.0;

        mat->specular[0] = 0.99;
        mat->specular[1] = 0.94;
        mat->specular[2] = 0.81;
        mat->specular[3] = 1.0;

        mat->diffuse[0] = 0.78;
        mat->diffuse[1] = 0.57;
        mat->diffuse[2] = 0.11;
        mat->diffuse[3] = 1.0;

        mat->shininess = 0.218;
        break;

    }
    case MATERIAL_SILVER:{
        mat->ambient[0] = 0.0;
        mat->ambient[1] = 0.0;
        mat->ambient[2] = 0.0;
        mat->ambient[3] = 1.0;

        mat->specular[0] = 0.0;
        mat->specular[1] = 0.0;
        mat->specular[2] = 0.0;
        mat->specular[3] = 1.0;

        mat->diffuse[0] = 0.51;
        mat->diffuse[1] = 0.51;
        mat->diffuse[2] = 0.51;
        mat->diffuse[3] = 1.0;

        mat->shininess = 0.4;
        break;

    }
    case MATERIAL_SILVER_POLIERT:{
        mat->ambient[0] = 0;
        mat->ambient[1] = 0;
        mat->ambient[2] = 0;
        mat->ambient[3] = 1.0;

        mat->specular[0] = 0;
        mat->specular[1] = 0;
        mat->specular[2] = 0;
        mat->specular[3] = 1.0;

        mat->diffuse[0] = 0;
        mat->diffuse[1] = 0;
        mat->diffuse[2] = 0;
        mat->diffuse[3] = 1.0;

        mat->shininess = 0.7;
        mat->refl   = 1.0;
        mat->transp = 0.0;
        break;

    }
    case MATERIAL_ZINN:{
        mat->ambient[0] = 0.11;
        mat->ambient[1] = 0.06;
        mat->ambient[2] = 0.11;
        mat->ambient[3] = 1.0;

        mat->specular[0] = 0.33;
        mat->specular[1] = 0.33;
        mat->specular[2] = 0.52;
        mat->specular[3] = 1.0;

        mat->diffuse[0] = 0.43;
        mat->diffuse[1] = 0.47;
        mat->diffuse[2] = 0.54;
        mat->diffuse[3] = 1.0;

        mat->shininess = 0.076;
        break;

    }
    case MATERIAL_GUMMI:{
        mat->ambient[0] = 0.02;
        mat->ambient[1] = 0.02;
        mat->ambient[2] = 0.02;
        mat->ambient[3] = 1.0;

        mat->specular[0] = 0.40;
        mat->specular[1] = 0.40;
        mat->specular[2] = 0.40;
        mat->specular[3] = 1.0;

        mat->diffuse[0] = 0.01;
        mat->diffuse[1] = 0.01;
        mat->diffuse[2] = 0.01;
        mat->diffuse[3] = 1.0;

        mat->shininess = 0.0781;
        break;

    }
    case MATERIAL_PLASTIK:{
        mat->ambient[0] = 0;
        mat->ambient[1] = 0;
        mat->ambient[2] = 0;
        mat->ambient[3] = 1.0;

        mat->specular[0] = 0.5;
        mat->specular[1] = 0.5;
        mat->specular[2] = 0.5;
        mat->specular[3] = 1.0;

        mat->diffuse[0] = 0.01;
        mat->diffuse[1] = 0.01;
        mat->diffuse[2] = 0.01;
        mat->diffuse[3] = 1.0;

        mat->shininess = 0.25;
        break;


    }
    case MATERIAL_EMERALD:{
        mat->ambient[0] = 0.0215;
        mat->ambient[1] = 0.1745;
        mat->ambient[2] = 0.0215;
        mat->ambient[3] = 1.0;

        mat->specular[0] = 0.633;
        mat->specular[1] = 0.727811;
        mat->specular[2] = 0.633;
        mat->specular[3] = 1.0;

        mat->diffuse[0] = 0.07568;
        mat->diffuse[1] = 0.61424;
        mat->diffuse[2] = 0.07568;
        mat->diffuse[3] = 1.0;

        mat->shininess = 0.6;
        break;

    }
    case MATERIAL_JADE:{
        mat->ambient[0] = 0.135;
        mat->ambient[1] = 0.2225;
        mat->ambient[2] = 0.1575;
        mat->ambient[3] = 1.0;

        mat->specular[0] = 0.31622;
        mat->specular[1] = 0.31622;
        mat->specular[2] = 0.31622;
        mat->specular[3] = 1.0;

        mat->diffuse[0] = 0.54;
        mat->diffuse[1] = 0.89;
        mat->diffuse[2] = 0.63;
        mat->diffuse[3] = 1.0;

        mat->shininess = 0.1;
        mat->refl = 0;
        mat->transp = 0;

        break;

    }
    case MATERIAL_OBSIDIAN:{
        mat->ambient[0] = 0.05375;
        mat->ambient[1] = 0.05;
        mat->ambient[2] = 0.06625;
        mat->ambient[3] = 1.0;

        mat->specular[0] = 0.332741;
        mat->specular[1] = 0.328634;
        mat->specular[2] = 0.346435;
        mat->specular[3] = 1.0;

        mat->diffuse[0] = 0.18275;
        mat->diffuse[1] = 0.17;
        mat->diffuse[2] = 0.22525;
        mat->diffuse[3] = 1.0;

        mat->shininess = 0.3;
        mat->transp = 0.0;
        mat->refl = 0.0;
        break;

    }
    case MATERIAL_PEARL:{
        mat->ambient[0] = 0.25;
        mat->ambient[1] = 0.20725;
        mat->ambient[2] = 0.20725;
        mat->ambient[3] = 1.0;

        mat->specular[0] = 0.296648;
        mat->specular[1] = 0.296648;
        mat->specular[2] = 0.296648;
        mat->specular[3] = 1.0;

        mat->diffuse[0] = 1.0;
        mat->diffuse[1] = 0.829;
        mat->diffuse[2] = 0.829;
        mat->diffuse[3] = 1.0;

        mat->shininess = 0.088;
        break;

    }
    case MATERIAL_RUBY:{
        mat->ambient[0] = 0.1745;
        mat->ambient[1] = 0.01175;
        mat->ambient[2] = 0.01175;
        mat->ambient[3] = 1.0;

        mat->specular[0] = 0.727811;
        mat->specular[1] = 0.626959;
        mat->specular[2] = 0.626959;
        mat->specular[3] = 1.0;

        mat->diffuse[0] = 0.61424;
        mat->diffuse[1] = 0.04136;
        mat->diffuse[2] = 0.04136;
        mat->diffuse[3] = 1.0;

        mat->shininess = 0.6;
        mat->transp = 0.0;
        mat->refl = 0.0;
        break;

    }
    case MATERIAL_TURQUOSIE:{
        mat->ambient[0] = 0.1;
        mat->ambient[1] = 0.18725;
        mat->ambient[2] = 0.1745;
        mat->ambient[3] = 1.0;

        mat->specular[0] = 0.297254;
        mat->specular[1] = 0.30829;
        mat->specular[2] = 0.306678;
        mat->specular[3] = 1.0;

        mat->diffuse[0] = 0.396;
        mat->diffuse[1] = 0.74151;
        mat->diffuse[2] = 0.69102;
        mat->diffuse[3] = 1.0;

        mat->shininess = 0.1;

        break;

    }
    case MATERIAL_BLACK_PLASTIC:{
        mat->ambient[0] = 0;
        mat->ambient[1] = 0;
        mat->ambient[2] = 0;
        mat->ambient[3] = 1.0;

        mat->specular[0] = 0;
        mat->specular[1] = 0;
        mat->specular[2] = 0;
        mat->specular[3] = 1.0;

        mat->diffuse[0] = 0.0;
        mat->diffuse[1] = 0.0;
        mat->diffuse[2] = 0.0;
        mat->diffuse[3] = 1.0;

        mat->shininess = 0.25;
        mat->refl = 1.0;
        mat->transp = 0.0;
        break;

    }
    case MATERIAL_BLACK_RUBBER:{
        mat->ambient[0] = 0.0;
        mat->ambient[1] = 0.0;
        mat->ambient[2] = 0.0;
        mat->ambient[3] = 1.0;

        mat->specular[0] = 0.0;
        mat->specular[1] = 0.0;
        mat->specular[2] = 0.0;
        mat->specular[3] = 1.0;

        mat->diffuse[0] = 0.00;
        mat->diffuse[1] = 0.00;
        mat->diffuse[2] = 0.00;
        mat->diffuse[3] = 1.0;

        mat->shininess = 0.078125;
        mat->transp = 1.0;
        mat->refl = 0.0;

        break;

    }
    case MATERIAL_CYAN_PLASTIC:{
        mat->ambient[0] = 0;
        mat->ambient[1] = 0.1;
        mat->ambient[2] = 0.06;
        mat->ambient[3] = 1.0;

        mat->specular[0] = 0.50196078;
        mat->specular[1] = 0.50196078;
        mat->specular[2] = 0.50196078;
        mat->specular[3] = 1.0;

        mat->diffuse[0] = 0;
        mat->diffuse[1] = 0.509803;
        mat->diffuse[2] = 0.509803;
        mat->diffuse[3] = 1.0;

        mat->shininess = 0.25;
        break;

    }
    case MATERIAL_CYAN_RUBBER:{
        mat->ambient[0] = 0;
        mat->ambient[1] = 0.05;
        mat->ambient[2] = 0.05;
        mat->ambient[3] = 1.0;

        mat->specular[0] = 0.04;
        mat->specular[1] = 0.7;
        mat->specular[2] = 0.7;
        mat->specular[3] = 1.0;

        mat->diffuse[0] = 0.4;
        mat->diffuse[1] = 0.5;
        mat->diffuse[2] = 0.5;
        mat->diffuse[3] = 1.0;

        mat->shininess = 0.078125;
        break;

    }
    case MATERIAL_GREEN_PLASTIC:{
        mat->ambient[0] = 0;
        mat->ambient[1] = 0;
        mat->ambient[2] = 0;
        mat->ambient[3] = 1.0;

        mat->specular[0] = 0.45;
        mat->specular[1] = 0.55;
        mat->specular[2] = 0.45;
        mat->specular[3] = 1.0;

        mat->diffuse[0] = 0.1;
        mat->diffuse[1] = 0.35;
        mat->diffuse[2] = 0.1;
        mat->diffuse[3] = 1.0;

        mat->shininess = 0.25;
        break;

    }
    case MATERIAL_GREEN_RUBER:{
        mat->ambient[0] = 0;
        mat->ambient[1] = 0.05;
        mat->ambient[2] = 0;
        mat->ambient[3] = 1.0;

        mat->specular[0] = 0.04;
        mat->specular[1] = 0.7;
        mat->specular[2] = 0.04;
        mat->specular[3] = 1.0;

        mat->diffuse[0] = 0.4;
        mat->diffuse[1] = 0.5;
        mat->diffuse[2] = 0.4;
        mat->diffuse[3] = 1.0;

        mat->shininess = 0.078125;
        break;

    }
    case MATERIAL_RED_PLASTIC:{
        mat->ambient[0] = 0;
        mat->ambient[1] = 0;
        mat->ambient[2] = 0;
        mat->ambient[3] = 1.0;

        mat->specular[0] = 0.7;
        mat->specular[1] = 0.6;
        mat->specular[2] = 0.6;
        mat->specular[3] = 1.0;

        mat->diffuse[0] = 0.5;
        mat->diffuse[1] = 0;
        mat->diffuse[2] = 0;
        mat->diffuse[3] = 1.0;

        mat->shininess = 0.25;
        break;

    }
    case MATERIAL_RED_RUBBER:{
        mat->ambient[0] = 0.05;
        mat->ambient[1] = 0;
        mat->ambient[2] = 0;
        mat->ambient[3] = 1.0;

        mat->specular[0] = 0.7;
        mat->specular[1] = 0.04;
        mat->specular[2] = 0.04;
        mat->specular[3] = 1.0;

        mat->diffuse[0] = 0.5;
        mat->diffuse[1] = 0.4;
        mat->diffuse[2] = 0.4;
        mat->diffuse[3] = 1.0;

        mat->shininess = 0.078125;
        break;

    }
    case MATERIAL_WHITE_PLASTIC:{
        mat->ambient[0] = 0;
        mat->ambient[1] = 0;
        mat->ambient[2] = 0;
        mat->ambient[3] = 1.0;

        mat->specular[0] = 0.7;
        mat->specular[1] = 0.7;
        mat->specular[2] = 0.7;
        mat->specular[3] = 1.0;

        mat->diffuse[0] = 0.55;
        mat->diffuse[1] = 0.55;
        mat->diffuse[2] = 0.55;
        mat->diffuse[3] = 1.0;

        mat->shininess = 0.25;
        break;

    }
    case MATERIAL_WHITE_RUBBER:{
        mat->ambient[0] = 0.05;
        mat->ambient[1] = 0.05;
        mat->ambient[2] = 0.05;
        mat->ambient[3] = 1.0;

        mat->specular[0] = 0.7;
        mat->specular[1] = 0.7;
        mat->specular[2] = 0.7;
        mat->specular[3] = 1.0;

        mat->diffuse[0] = 0.5;
        mat->diffuse[1] = 0.5;
        mat->diffuse[2] = 0.5;
        mat->diffuse[3] = 1.0;

        mat->shininess = 0.078125;
        break;

    }
    case MATERIAL_YELLOW_PLASTIC:{
        mat->ambient[0] = 0;
        mat->ambient[1] = 0;
        mat->ambient[2] = 0;
        mat->ambient[3] = 1.0;

        mat->specular[0] = 0.6;
        mat->specular[1] = 0.6;
        mat->specular[2] = 0.5;
        mat->specular[3] = 1.0;

        mat->diffuse[0] = 0.5;
        mat->diffuse[1] = 0.5;
        mat->diffuse[2] = 0;
        mat->diffuse[3] = 1.0;

        mat->shininess = 0.25;
        break;

    }
    case MATERIAL_YELLOW_RUBBER:{
        mat->ambient[0] = 0.05;
        mat->ambient[1] = 0.05;
        mat->ambient[2] = 0;
        mat->ambient[3] = 1.0;

        mat->specular[0] = 0.7;
        mat->specular[1] = 0.7;
        mat->specular[2] = 0.04;
        mat->specular[3] = 1.0;

        mat->diffuse[0] = 0.5;
        mat->diffuse[1] = 0.5;
        mat->diffuse[2] = 0.4;
        mat->diffuse[3] = 1.0;

        mat->shininess = 0.078125;
        break;

    }

    }
}

void Material::setMaterialOpenGL(int type)
{
    Material *mat = new Material();
    setMaterial(mat,type);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,mat->ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat->diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat->specular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, mat->shininess*128);
}

Material* Material::getMaterial(int type)
{
    Material *mat = new Material();
    setMaterial(mat,type);
    return mat;
}

QColor Material::getColorMaterial(int type)
{
    Material *mat = new Material();
    setMaterial(mat,type);
    Vec4 colorvec((mat->diffuse[0]),(mat->diffuse[1]),(mat->diffuse[2]));
    QColor color;
    color.setRgb(((int)(colorvec.x()*255)%256),((int)(colorvec.y()*255)%256),((int)(colorvec.z()*255)%256));
    return color;
}
