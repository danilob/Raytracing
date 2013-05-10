#ifndef HBB_H
#define HBB_H
#include "object.h"
#include "cube.h"
#include "math/rayintersection.h"
#include <vector>
<<<<<<< HEAD
class HBB: public Object
=======
class HBB: public Cube
>>>>>>> 490f827284db0ec9110c12375bcf57acbf56b06a
{
public:
    Object *left;
    Object *right;
    HBB *left_node;
    HBB *right_node;
    Cube box;
<<<<<<< HEAD
    Object *select;
=======
>>>>>>> 490f827284db0ec9110c12375bcf57acbf56b06a


public:
    HBB();
    HBB(std::vector<Object*> objects,int axis);
    ~HBB();
    bool hit(RayIntersection *intersect);
<<<<<<< HEAD
    std::vector<Object*> sortObjects(std::vector<Object*> objects,int axis);
    void drawStructure();
     void        setSelected(bool b) {};           //seta o objeto como selecionado para possiveis alterações
     bool        isSelected() {};                  //verifica se o objeto esta selecionado
     void        setEnabled(bool b) {};            //seta o objeto como habilitado para o raycasting e para desenho
     bool        isEnabled() {};                   //verifica se o objeto esta habilitado
     void        setMaterial(int) {};              //aplica um determinado material ao objeto
     Mesh*       getMesh() {};                     //extrai a malha do objeto
     Matrix4x4   getMatrixTransformation() {return box.transform;}     //extrai a matriz de transformação do objeto
     void        setTransform(Matrix4x4 m) {};     //aplica uma determinada matriz de tranformação ao objeto
     QString     getName() {};                     //extrai o nome do objeto
     void        setName(QString name) {};         //seta um nome para o objeto
     int         getNumFaces() {};                 //extrai a quantidade de faces do objeto
     int         getNumVertexs() {};               //extrai a quantidade de vertices do objeto
     int         getIdMaterial() {};               //extrai o identificador do material utilizado no objeto
     void        tryIntersection(RayIntersection *intersect,Ray ray){}; //testa a interseção do raio com o objeto
     bool        HBBIntersection(RayIntersection *intersect,Ray ray,Object *obj=NULL);
     void        wireframe() {};                   //desenha o objeto como wireframe
     void        draw() {};                        //desenha o objeto
     void        refreshNormals() {};              //atualiza os vetores normais do objeto
     QString     saveObject() {};                  //adiconar parametros do abjeto ao arquivo
     Cube        boundingBox() {};                 //retorna a boudingbox do objeto
     Vec4        getMax() {};                      //retorna o extremo máximo do objeto, não necessariamente este ponto esta no objeto
     Vec4        getMin() {};                      //retorna o extremo mínimo do objeto, não necessariamente este ponto esta no objeto
     Vec4        getCenter() {};                   //retorna o ponto médio do objeto, não necessariamente este ponto esta no objeto
     bool        hitBox(Ray r,Matrix4x4 transform);

=======
    void sortObjects(std::vector<Object*> objects,int axis);
    //void drawStructure();
>>>>>>> 490f827284db0ec9110c12375bcf57acbf56b06a
};

#endif // HBB_H
