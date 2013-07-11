#include "photon.h"
#include "math/rayintersection.h"
#include "interface/scene.h"
int depthMax = 3;
float raio = 1.0;
Photon::Photon()
{
}

Photon::Photon(Vec4 pos, Vec4 dir)
{
    position = pos;
    direction = dir;

}

Photon::Photon(Vec4 pos, Vec4 dir, Vec4 pow)
{
    position = pos;
    direction = dir;
    power = pow;

}

void Photon::setPosition(Vec4 pos)
{
    position = pos;
}

Vec4 Photon::getPosition()
{
    return position;
}

void Photon::setDirection(Vec4 dir)
{
    direction = dir;
}

Vec4 Photon::getDirection()
{
    return direction;
}

void Photon::setPower(Vec4 pow)
{
    power = pow;
}

Vec4 Photon::getPower()
{
    return power;
}

void Photon::setFlag(int flag)
{
    this->flag = flag;
}

PhotonMap::PhotonMap()
{
    photons.clear();
    this->scene = NULL;
}

int PhotonMap::getSize()
{
    return photons.size();
}

void PhotonMap::setScene(Scene *scn)
{
    this->scene = scn;
    hbb = new HBB(scene->objects,1);
}

void PhotonMap::addPhoton(Photon *photon)
{
    photons.push_back(photon);
}

void PhotonMap::constructPhotonMap(std::vector<Photon*> emitphotons)
{

    for(unsigned int i=0;i<emitphotons.size();i++){
        srandom(time(NULL));
        getHitPhoton(emitphotons.at(i),depthMax);
    }
    constructKdTree();
}

void PhotonMap::getHitPhoton(Photon *photon, int depth)
{
    if (!depth) return;
    Ray ray(photon->getPosition(),photon->getDirection());
    RayIntersection* intersect = new RayIntersection();
    Object* obj;
    bool hit  = hbb->HBBIntersection(intersect,ray,obj);
    if (!hit) return; //caso não tenha interceptado nenhum objeto
    obj = intersect->obj;
    Vec4 pHit = ray.positionRay(intersect->t); //ponto do hit
    //gerar novo photon caso o objeto tenha propriedades reflexivas ou refratarias, com a mesma profundidade
    if((photon->direction*(intersect->normal*(-1)))<0.0) intersect->normal = intersect->normal*(-1);
    if (intersect->material->getReflection()>0 || intersect->material->getRefraction()>0){

        if (intersect->material->getRefraction()>0){
            //iremos rolar a roleta para escolher entre a reflexão ou refração
            float rolete = myrand;
            if (rolete>0.5){//reflexão
                Ray reflection = Ray::rayReflect(pHit,photon->direction,intersect->normal);
                Photon* p = new Photon(reflection.origin,reflection.direction,photon->getPower());
                getHitPhoton(p,depth);
            }else{//refração
                Ray refraction = Ray::rayRefract(pHit,photon->direction,intersect->normal,1.0,intersect->material->getRefraction());
                Photon* p = new Photon(refraction.origin,refraction.direction,photon->getPower());
                getHitPhoton(p,depth);
            }
        }else{//iremos gerar um ray de reflexão
            Ray reflection = Ray::rayReflect(pHit,photon->direction,intersect->normal);
            Photon* p = new Photon(reflection.origin,reflection.direction,photon->getPower());
            getHitPhoton(p,depth);
        }
        return;
    }
    //caso contrário houve um hit em um material difuso, primeiro passo será adicionar este hit no photon map
    //em seguida decidir se o raio continua ou para.

    Photon* p = new Photon(pHit,photon->getDirection()*(-1),photon->getPower()); //valor do ponto de hit, direção para origem do raio e power do photon
    photons.push_back(p);

    //calculo da sobrevivencia do photon
    Vec4 diff = obj->getMesh()->getMaterialM()->getDiffuse().unitary();
    Vec4 spe = obj->getMesh()->getMaterialM()->getSpecular().unitary();
    Vec4 pow = photon->getPower();
    //energia máxima da diffusa e da especular
    float Pd = fmax(fmax(diff.x()*pow.x(),diff.y()*pow.y()),diff.z()*pow.z())/fmax(fmax(pow.x(),pow.y()),pow.z());
    float Ps = fmax(fmax(spe.x()*pow.x(),spe.y()*pow.y()),spe.z()*pow.z())/fmax(fmax(pow.x(),pow.y()),pow.z());

    float epsilon = myrand; //roleta russa

    if(epsilon>=0 && epsilon<=Pd){//reflexão difusa
        Ray reflection = Ray::rayReflect(pHit,photon->getDirection(),intersect->normal);
        Vec4 pow = (photon->getPower().mult(diff))/Pd;
        Photon* p = new Photon(reflection.origin,reflection.direction,pow);
        getHitPhoton(p,depth-1);
    }else if(epsilon>Pd && epsilon<=(Pd+Ps)){ //reflexão especular
        Ray reflection = Ray::rayReflect(pHit,photon->getDirection(),intersect->normal);
        Vec4 pow = (photon->getPower().mult(spe))/Ps;
        Photon* p = new Photon(reflection.origin,reflection.direction,pow);
        getHitPhoton(p,depth-1);
    }else{ //absorção
        return;
    }
}

void PhotonMap::constructKdTree()
{
    kdtree = new KdTree(photons);
}

Vec4 PhotonMap::radiance(Vec4 position, Vec4 dir, Vec4 n,Material *mat)
{
    //return Vec4();
    QList<Photon*> nearPth;
    nearPth.clear();
    //kdtree->showHeap();
    //return Vec4();
    kdtree->clearHeap();
    kdtree->locatePhotons(kdtree,position,100,nearPth);
    nearPth = kdtree->maxHeap;
    //printf("\nSize: %d",nearPth.size());
    if (nearPth.size()==0) return Vec4();

    //return Vec4();
    int nears = 100;
    Vec4 flux;
    int i=0;
    while (nears){
        if (Vec4::dist(position,nearPth.at(i)->position)<=raio){
            nears--;
            //brdf
            Vec4 l = nearPth.at(i)->getDirection();
            Vec4 r = (n*((l*n)*2) - l);
            Vec4 v = (dir-position)/(dir-position).module();
            r = (r+v)/(r+v).module();
            float brdf = fmax(pow((r*n),mat->shininess*128),0);
            Vec4 val(mat->specular[0],mat->specular[1],mat->specular[2]);
            flux += nearPth.at(i)->getPower().mult(val)*brdf;
        }
        i++;
        if(i==nearPth.size()) break;
    }
    return flux/(M_PI*raio*raio);
}

void PhotonMap::drawPhotonMap()
{
    glDisable(GL_LIGHTING);
    glPointSize(1.5);
    glBegin(GL_POINTS);
        for(unsigned int i=0;i<photons.size();i++){
            Vec4 p = photons.at(i)->getPosition();
            Vec4 color = photons.at(i)->getPower();
            glColor3f(color.x(),color.y(),color.z());
            glVertex3f(p.x(),p.y(),p.z());
        }
    glEnd();
    glEnable(GL_LIGHTING);
}
