#ifndef SCENE_H
#define SCENE_H
#include <vector>
#include "block/object.h"
#include "block/cube.h"
#include "block/prism.h"
#include "block/hemisphere.h"
#include "block/cylinder.h"
#include "block/plane.h"
#include "block/cone.h"
#include "block/sphere.h"
#include "structure/light.h"

#define BLOCK_CUBE        0
#define BLOCK_CYLINDER    1
#define BLOCK_HEMISPHERE  2
#define BLOCK_PRISM       3
#define PLANALTO          4
#define BLOCK_PLANE       5
#define BLOCK_SPHERE      6
#define BLOCK_CONE        7



class Scene
{
public:
    Scene();

    void pushObjects(Object *obj); //adiciona um objeto na cena
    void pushObjects(int define,int material=0); //carrega objetos para cena de acordo com os defines
    void addObject(int type);
    void pushViewer(Vec4 eye,Vec4 at, Vec4 up);
    void pushLights(Light *light);
    //void calculatePixels(GLubyte* pixels,int width,int height);
    void drawObjectsOpenGL(bool wireframe=false);
    void renderLightsOpenGL();
    void pushViewport(int width,int height);
    void pushProjection(float angle,float aspect,float near,float far);
    void pushBackgroundColor(Vec4 background);
    void setMaterialAllObjects(int id);
    ~Scene();

public:
    std::vector<Object*> objects; //objetos da cena
    std::vector<Object*>::iterator iter;
    std::vector<Light*> lights;   //luzes da cena
    std::vector<Light*>::iterator iterl;
    Vec4 background_color;              //cor de fundo
    Vec4 viewer[3];               //posicão do observador
    Vec4 projection;              //valores de projeção: angle, aspect, near,far
    int viewport[2];              //dimensões da janela de visualização
    bool push_obj;                //flag que indica se eh possivel adicionar objetos

};

#endif // SCENE_H
