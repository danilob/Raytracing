#ifndef PHOTON_H
#define PHOTON_H
#include "math/vec4.h"
#include <vector>
#include "block/hbb.h"
#include "structure/kdtree.h"

class Scene;
class Photon
{
public:
    Vec4 position;
    Vec4 direction;
    Vec4 power;       //r,g,b
    //float phi,theta;  //direção de onde a luz incidiu
    int flag;         //valor utilizado na kd-tree
    Photon();
    Photon(Vec4 pos, Vec4 dir);
    Photon(Vec4 pos, Vec4 dir,Vec4 pow);
    void setPosition(Vec4 pos);
    Vec4 getPosition();
    void setDirection(Vec4 dir);
    Vec4 getDirection();
    void setPower(Vec4 pow);
    Vec4 getPower();
    void setFlag(int flag);
};

class PhotonMap
{
public:
    std::vector<Photon*> photons;
    Scene* scene;
    KdTree *kdtree;
    HBB* hbb;

public:
    PhotonMap();
    int getSize();
    void setScene(Scene* scn);
    void addPhoton(Photon* photon);
    void constructPhotonMap(std::vector<Photon*> emitphotons); //constroí o photon map a partir dos photons emitidos inicialmente
    void getHitPhoton(Photon* photon,int depth); //adiciona onde os photons encontram uma superfície difusa até uma certa profundidade
    void constructKdTree();
    Vec4 radiance(Vec4 position,Vec4 dir,Vec4 n,Material *mat);
    void drawPhotonMap();



};


#endif // PHOTON_H
