#include "kdtree.h"
#include "photon.h"
int comp = 0;
float d2 = 0;
float delta = 0;
float delta2 = 2.0;
int nphotons = 0;
KdTree::KdTree(std::vector<Photon*> photons)
{
    if (photons.size()==0) return;
    nphotons ++;
    int dim = getLargestDimCube(photons);
//    QList<Photon*> pth = getPhotonsList(photons);
    QList<Photon*> pth = quickSort(dim,0,photons.size()-1,getPhotonsList(photons));
    QList<Photon*> s1;
    QList<Photon*> s2;
    if(pth.size()>1)
        s1  = pth.mid(0,pth.size()/2);
    if(pth.size()>2)
        s2  = pth.mid(pth.size()/2+1,pth.size());
    pth.at(pth.size()/2)->setFlag(dim);
    node = pth.value(pth.size()/2);
//    Photon* p = pth.at(pth.size()/2);
//    p->setFlag(dim);
    leftKdTree = NULL;
    rightKdTree = NULL;
//    printf("Photon size: %d, s1: %d, s2: %d node: <%3.3f, %3.3f, %3.3f>\n",pth.size(),s1.size(),s2.size(),node->getPosition().x(),node->getPosition().y(),node->getPosition().z()); //debug
    if(s1.size()>0)
        leftKdTree = new KdTree(getPhotonsVector(s1));
    if(s2.size()>0)
        rightKdTree = new KdTree(getPhotonsVector(s2));
}

KdTree *KdTree::balance(std::vector<Photon*> photons)
{
//    int dim = getLargestDimCube(photons);
//    QList<Photon*> pth = mergeSort(dim,0,photons.size(),getPhotonsList(photons));
//    QList<Photon*> s1  = pth.mid(0,pth.length()/2-1);
//    QList<Photon*> s2  = pth.mid(pth.length()/2+1,pth.length()-1);
//    photons.at(pth.length()/2)->setFlag(dim);
//    node = photons.at(pth.length()/2);
//    left = balance(getPhotonsVector(s1));
    //    right = balance(getPhotonsVector(s2));
}

void KdTree::setNumPhotons(int num)
{
    nphotons = num;
}

int KdTree::getLargestDimCube(std::vector<Photon*> photons)
{
    Vec4 min = photons.at(0)->getPosition()
        ,max = photons.at(0)->getPosition();
    for(unsigned int i=1;i<photons.size();i++){
        Vec4 p = photons.at(i)->getPosition();
        if (max.x()<=p.x()) max.x1 = p.x();
        if (max.y()<=p.y()) max.x2 = p.y();
        if (max.z()<=p.z()) max.x3 = p.z();

        if (min.x()>=p.x()) min.x1 = p.x();
        if (min.y()>=p.y()) min.x2 = p.y();
        if (min.z()>=p.z()) min.x3 = p.z();
    }
    float z = (max - Vec4(max.x(),max.y(),min.z())).module();
    float y = (min - Vec4(min.x(),max.y(),min.z())).module();
    float x = (min - Vec4(max.x(),min.y(),min.z())).module();
    if(x>=y && x>=z)
        return 0; //dimensão maior é a de eixo x
    else if(y>=x && y>=z)
        return 1; //dimensão maior é a de eixo y
    else
        return 2; //dimensão maior é a de eixo z
}

QList<Photon*> KdTree::getPhotonsList(std::vector<Photon*> photons)
{
    QList<Photon*> lphoton;
    for(unsigned int i=0;i<photons.size();i++){
        lphoton.append(photons.at(i));
    }
    return lphoton;
}

std::vector<Photon*> KdTree::getPhotonsVector(QList<Photon*> photons)
{
    std::vector<Photon*> vphoton;
    for(unsigned int i=0;i<photons.size();i++){
        vphoton.push_back(photons.value(i));
    }
    return vphoton;
}

QList<Photon*> KdTree::mergeSort(int flag, int begin, int end,QList<Photon*> Photons)
{
        int left = 0, right = 0, half = 0;
        int i = 0;
        QList<Photon*> Ps;
        Ps.append(Photons.at(0));
        if(begin==end) return Ps;

            half = (begin + end)/2;
            mergeSort(flag,begin,half,Photons);
            mergeSort(flag,half+1,end,Photons);

            left = begin;
            right = half+1;

            Photon *t[Photons.size()];// = new Photon*[Photons.size()];//(Point3D *) malloc(sizeof(Point3D)* sizeof(Point3D) * (end-begin+1));

            for(i = begin;i <= end;i++)
            {
                switch (flag){
                case 0:{
                    if(right > end || (left <= half && Photons.value(left)->getPosition().x() <= Photons.value(right)->getPosition().x()))
                    {

                            t[i] = Photons.value(left);
                            comp++;
                            left++;
                    }
                    else
                    {
                            t[i] = Photons.value(right);
                            right++;
                    }
                 }
                 case 1:{
                    if(right > end || (left <= half && Photons.value(left)->getPosition().y() <= Photons.value(right)->getPosition().y()))
                    {

                            comp++;
                            t[i] = Photons.value(left);
                            left++;
                    }
                    else
                    {

                            t[i] = Photons.value(right);
                            right++;
                    }
                 }
                 case 2:
                 if(right > end || (left <= half && Photons.value(left)->getPosition().z() <= Photons.value(right)->getPosition().z()))
                    {

                            comp++;
                            t[i] = Photons.value(left);
                            left++;
                    }
                    else
                    {

                            t[i] = Photons.value(right);
                            right++;
                    }
                 }

            }

            for(i = begin;i <= end;i++)
                    Photons.replace(i,t[i]);
            return Photons;
}

int KdTree::particion(int flag,int left,int right,QList<Photon*> Photons){
    int i, j;
    i = left;
    //switch (flag){
    if (flag==0){
    for (j = left + 1; j <= right; j++) {
      if (Photons.value(j)->getPosition().x1 < Photons.value(left)->getPosition().x1) {
         i++;
         Photons.move(j,i);
      }
    }
    Photons.move(left,i);
    }
    if (flag==1){
    for (j = left + 1; j <= right; j++) {
      if (Photons.value(j)->getPosition().x2 < Photons.value(left)->getPosition().x2) {
         i++;
         Photons.move(j,i);
      }
    }
    Photons.move(left,i);
    }
    if (flag==2){
    for (j = left + 1; j <= right; j++) {
      if (Photons.value(j)->getPosition().x3 < Photons.value(left)->getPosition().x3) {
         i++;
         Photons.move(j,i);
      }
    }
    Photons.move(left,i);
    }

    return i;
}

QList<Photon*> KdTree::quickSort(int flag,int left, int right,QList<Photon*> Photons) { //modifica a estrutura do Points
  int r;
  if (right > left) {

    r = particion(flag,left,right,Photons);
    quickSort(flag,left, r - 1,Photons);
    quickSort(flag,r + 1, right,Photons);
  }
  return Photons;
}


QList<Photon*> KdTree::getHeapKdTree()
{
    QList<Photon*> total;
    total.append(this->node);
    if (leftKdTree!=NULL)
        total.append(leftKdTree->getHeapKdTree());
    if (rightKdTree!=NULL)
        total.append(rightKdTree->getHeapKdTree());
    return total;
}

void KdTree::showHeap()
{
//    Vec4 p = node->getPosition();
//    printf("%d <%3.3f, %3.3f, %3.3f>\n",p.x(),p.y(),p.z());
//    left->showHeap();
//    right->showHeap();

    QList<Photon*> pth = this->getHeapKdTree();
    for(unsigned int i=0;i<pth.length();i++){
        Vec4 p = pth.at(i)->getPosition();
        printf("\n\n%d <%3.3f, %3.3f, %3.3f>\n",i,p.x(),p.y(),p.z());
    }
}

void KdTree::clearHeap()
{
    maxHeap.clear();
}

void KdTree::locatePhotons(KdTree* kd,Vec4 pos,int maxphotons,QList<Photon*> photons)
{
    //float delta=0;
    delta2 = Vec4::distSquared(kd->node->position,pos);
    //printf("\Photons: %d",kd->nphotons);
    //return;
    if(kd->leftKdTree!=NULL && kd->rightKdTree!=NULL){
    //if( kd->getHeapKdTree().size() < maxphotons) { //examine child nodes
        //printf("\Photons: %d",kd->nphotons);
        //Compute distance to plane (just a subtract)
        Vec4 plane;
        float signal;
        if(kd->node->flag==0){
            plane.setVec4(kd->node->position.x(),0,0);
            signal = kd->node->position.x();
        }else if(kd->node->flag==1){
            plane.setVec4(0,kd->node->position.y(),0);
            signal = kd->node->position.y();
        }else{
            plane.setVec4(0,0,kd->node->position.z());
            signal = kd->node->position.z();
        }
        delta = Vec4::distPlane(pos,plane);
        d2 = 50.0;//Vec4::distSquared(pos,kd->node->position);
        printf("\ndelta: %3.2f, delta2: %3.2f",delta,delta2);

        if (delta < 0) { //We are left of the plane - search left subtree first
            //printf("\nHear!");
            if(signal<0){
                locatePhotons(kd->leftKdTree,pos,maxphotons,photons);
//                if ( delta2 < d2 ){
//                    locatePhotons(kd->rightKdTree,pos,maxphotons,photons); //check right subtree
//                    photons.append(kd->node);
//                    maxHeap.append(kd->node);
//                }
            }else{
                locatePhotons(kd->rightKdTree,pos,maxphotons,photons);
//                if ( delta2 < d2 ){
//                    locatePhotons(kd->leftKdTree,pos,maxphotons,photons); //check right subtree
//                    photons.append(kd->node);
//                    maxHeap.append(kd->node);
//                }
            }
        } else { //We are right of the plane - search right subtree first
            //printf("\nHear2!");
            if(signal<0){
            locatePhotons(kd->rightKdTree,pos,maxphotons,photons);
//            if ( delta2 < d2 )
//                locatePhotons(kd->leftKdTree,pos,maxphotons,photons); //check left subtree
            }else{
                locatePhotons(kd->leftKdTree,pos,maxphotons,photons);
//                if ( delta2 < d2 )
//                    locatePhotons(kd->rightKdTree,pos,maxphotons,photons); //check left subtree
            }
        }
    }
    if ( delta2 < d2 ) { //Check if the photon is close enough?
        //QList<Photon*> photon;
        photons.append(kd->node);
        maxHeap.append(kd->node);
        printf("\nIn!");
        //d2 = Vec4::distSquared(pos,kd->node->position);
    }
    //Compute true squared distance to photon

    //δ2 = squared distance from photon p to x
    //if (photons.size()>50) return;


}

