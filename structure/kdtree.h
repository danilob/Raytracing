#ifndef KDTREE_H
#define KDTREE_H
#include <vector>
#include <QList>
#include "math/vec4.h"
class Photon;

class KdTree
{
public:
    Photon *node;
    KdTree *leftKdTree;
    KdTree *rightKdTree;
    QList<Photon*> maxHeap;
    //static int nphotons;


    KdTree(std::vector<Photon*> photons);
    KdTree* balance(std::vector<Photon*> photons);
    void setNumPhotons(int num);
    int getLargestDimCube(std::vector<Photon*> photons); //retorna o eixo onde o cubo é maior
    QList<Photon*> getPhotonsList(std::vector<Photon*> photons);
    std::vector<Photon*> getPhotonsVector(QList<Photon*> photons);
    QList<Photon*> mergeSort(int flag,int begin,int end, QList<Photon*> Photons);
    QList<Photon*> getHeapKdTree();
    QList<Photon*> quickSort(int flag,int left,int right, QList<Photon*> Photons);
    void locatePhotons(KdTree* n,Vec4 pos,int maxphotons,QList<Photon*> photon);
    int particion(int flag,int left,int right, QList<Photon*> Photons);
    void showHeap();
    void clearHeap();
};

#endif // KDTREE_H
