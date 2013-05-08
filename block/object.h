#ifndef OBJECT_H
#define OBJECT_H

#include <QString>
#include "math/vec4.h"
#include "math/matrix4x4.h"
#include "structure/mesh.h"
#include "math/ray.h"
#include "math/rayintersection.h"
class Cube;

class Object
{
public:

    virtual void        setSelected(bool b) = 0;           //seta o objeto como selecionado para possiveis alterações
    virtual bool        isSelected() = 0;                  //verifica se o objeto esta selecionado
    virtual void        setEnabled(bool b) = 0;            //seta o objeto como habilitado para o raycasting e para desenho
    virtual bool        isEnabled() = 0;                   //verifica se o objeto esta habilitado
    virtual void        setMaterial(int) = 0;              //aplica um determinado material ao objeto
    virtual Mesh*       getMesh() = 0;                     //extrai a malha do objeto
    virtual Matrix4x4   getMatrixTransformation() = 0;     //extrai a matriz de transformação do objeto
    virtual void        setTransform(Matrix4x4 m) = 0;     //aplica uma determinada matriz de tranformação ao objeto
    virtual QString     getName() = 0;                     //extrai o nome do objeto
    virtual void        setName(QString name) = 0;         //seta um nome para o objeto
    virtual int         getNumFaces() = 0;                 //extrai a quantidade de faces do objeto
    virtual int         getNumVertexs() = 0;               //extrai a quantidade de vertices do objeto
    virtual int         getIdMaterial() = 0;               //extrai o identificador do material utilizado no objeto
    virtual void        tryIntersection(RayIntersection *intersect,Ray ray) = 0; //testa a interseção do raio com o objeto
    virtual void        wireframe() = 0;                   //desenha o objeto como wireframe
    virtual void        draw() = 0;                        //desenha o objeto
    virtual void        refreshNormals() = 0;              //atualiza os vetores normais do objeto
    virtual QString     saveObject() = 0;                      //adiconar parametros do abjeto ao arquivo
    virtual Cube        boundingBox() = 0;
    virtual Vec4        getMax() = 0;
    virtual Vec4        getMin() = 0;
    virtual Vec4        getCenter() = 0;






};





#endif // OBJECT_H
