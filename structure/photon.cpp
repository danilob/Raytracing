#include "photon.h"
#include "math/rayintersection.h"
#include "interface/scene.h"

Photon::Photon()
{
}

Photon::Photon(Vec4 pos, Vec4 dir)
{
    position = pos;
    direction = dir;
    status = DIRECT;
    type = GLOBAL;
}

Photon::Photon(Vec4 pos, Vec4 dir, Vec4 pow, int flag)
{
    position = pos;
    direction = dir;
    power = pow;
    this->flag = flag;
    status = DIRECT;
    type = GLOBAL;
}

Photon::Photon(Vec4 pos, Vec4 dir, Vec4 pow)
{
    position = pos;
    direction = dir;
    power = pow;
    status = DIRECT;
    type = GLOBAL;
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

int Photon::getFlag()
{
    return flag;
}

void Photon::setStatus(int status)
{
    this->status = status;
}

int Photon::getStatus()
{
    return this->status;
}

void Photon::setType(int type)
{
    this->type = type;
}

int Photon::getType()
{
    return type;
}

PhotonMap::PhotonMap()
{
    kdtree = new KdTree();
    caustic =  new KdTree();
    this->scene = NULL;
    radiusGlobal = 0.75;
    radiusCaustic = 0.15;
    depthMax = 4;
    fat = 0.01;
}

int PhotonMap::getSizeGlobal()
{
    return kdtree->photons.size();
}


void PhotonMap::setScene(Scene *scn)
{
    this->scene = scn;
    hbb = new HBB(scene->objects,1);
}


void PhotonMap::constructPhotonMap(std::vector<Photon*> emitphotons)
{
    globalPhotons = 0;
    causticPhotons = 0;
    kdtree = new KdTree();
    srandom(time(NULL));
    for(unsigned int i=0;i<emitphotons.size();i++){
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
                if(photon->getType()==CAUSTIC) p->setType(CAUSTIC);
                p->setStatus(REFLECTED);
                getHitPhoton(p,depth);
            }else{//refração
                Ray refraction = Ray::rayRefract(pHit,photon->direction,intersect->normal,1.0,intersect->material->getRefraction());
                Photon* p = new Photon(refraction.origin,refraction.direction,photon->getPower());
                if(photon->getStatus()==DIRECT || photon->getStatus()==REFRACTED) p->setStatus(REFRACTED);
                else p->setStatus(REFLECTED);
                if(photon->getType()==CAUSTIC) p->setType(CAUSTIC);
                getHitPhoton(p,depth);
            }
        }else{//iremos gerar um ray de reflexão
            Ray reflection = Ray::rayReflect(pHit,photon->direction,intersect->normal);
            Photon* p = new Photon(reflection.origin,reflection.direction,photon->getPower());
            if(photon->getType()==CAUSTIC) p->setType(CAUSTIC);
            getHitPhoton(p,depth);
        }
        return;

    }
    //caso contrário houve um hit em um material difuso, primeiro passo será adicionar este hit no photon map
    //em seguida decidir se o raio continua ou para.
    //if(depth!=depthMax){
    Photon* p = new Photon(pHit,photon->getDirection()*(-1),photon->getPower());
    if(photon->getStatus()==REFRACTED){
        if(photon->getType()==CAUSTIC) p->setType(CAUSTIC);
        p->setPower(p->getPower()*fat);
        p->setStatus(DIFUSED);
        caustic->addPhoton(p); //kdtree de caustica
        causticPhotons++;
    }else{
        if(photon->getType()==CAUSTIC) p->setType(CAUSTIC);
        if(depth==0 && p->getStatus()!=REFLECTED)
            p->setStatus(DIRECT);
        else{
            p->setStatus(REFLECTED);
        }
        p->setPower(p->getPower()*fat);
        if(!(p->getStatus()==DIRECT)){
            kdtree->addPhoton(p); //kdtree global
            globalPhotons++;
       }

    }
         //valor do ponto de hit, direção para origem do raio e power do photon
        //photons.push_back(p);

    //}

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
        Vec4 ri = reflection.direction.unitary();
        float du = myrand;
        float dv = myrand;
        Vec4  ul = ri^intersect->normal;
        ul = ul.unitary();
        Vec4 vl = ri^ul;
        ri = ri + ul*du + vl*dv;
        pow = ((pow.mult(diff))/Pd);
        Photon* p = new Photon(reflection.origin,ri.unitary(),pow);
        p->setStatus(REFLECTED);
        getHitPhoton(p,depth-1);
    }else if(epsilon>Pd && epsilon<=(Pd+Ps)){ //reflexão especular
        Ray reflection = Ray::rayReflect(pHit,photon->getDirection(),intersect->normal);
        Vec4 l = reflection.direction;
        Vec4 r = (intersect->normal*((l*intersect->normal)*2) - l);
        Vec4 v = (l-pHit)/(l-pHit).module();
        r = (r+v)/(r+v).module();
        Vec4 ri = r.unitary();
        float du = myrand;
        float dv = myrand;
        Vec4  ul = ri^intersect->normal;
        ul = ul.unitary();
        Vec4 vl = ri^ul;
        ri = ri + ul*du + vl*dv;
        pow = ((pow.mult(spe))/Ps);
        Photon* p = new Photon(reflection.origin,ri.unitary(),pow);
        p->setStatus(REFLECTED);
        getHitPhoton(p,depth-1);
    }else{ //absorção
        return;
    }
}

void PhotonMap::constructKdTree()
{

    if(!kdtree->photons.empty())
        kdtree->createHeap();
    if(!caustic->photons.empty())
        caustic->createHeap();

}

bool first2 = true;
Vec4 PhotonMap::radiance(Vec4 position, Vec4 dir, Vec4 n,Material *mat)
{

    kdtree->clearHeap();
    caustic->clearHeap();

    if(!kdtree->photons.empty())
        kdtree->locatePhotons(0,position,100,radiusGlobal);
    if(!caustic->photons.empty())
        caustic->locatePhotons(0,position,60,radiusCaustic);
    float factor = 1;
    if (kdtree->maxHeap.size()==0) return Vec4();


    //return Vec4();
    int nears = 100;
    Vec4 flux = Vec4(0,0,0);
    Vec4 fluxcaustic = Vec4(0,0,0);
    float distMax = Vec4::distSquared(kdtree->maxHeap.at(0)->getPosition(),position);
    int i=kdtree->maxHeap.size();
    float k = 5.;
    int ni=0;
    while (nears){
        if(kdtree->maxHeap.at(i-1)->getStatus()!=DIFUSED && kdtree->maxHeap.at(i-1)->getType()!=CAUSTIC){
            Vec4 l = kdtree->maxHeap.at(i-1)->getDirection().unitary();
            if(Vec4::dist(kdtree->maxHeap.at(i-1)->position,position)<radiusGlobal){
                if((n*l>0)){
                    float wpc = 1. - Vec4::dist(kdtree->maxHeap.at(i-1)->position,position)/(distMax);
                    if(wpc<0) wpc=0.05;
                    if(kdtree->maxHeap.at(i-1)->getStatus()==DIRECT)
                        flux += (kdtree->maxHeap.at(i-1)->getPower()*0.5*wpc*factor);
                    else
                        flux += (kdtree->maxHeap.at(i-1)->getPower()*wpc*factor);
                    nears--;
                    ni++;
                }
            }
        }
        i--;
        if(i==0) break;
    }
    flux = (flux/(M_PI*distMax)); //com filtro
    if(ni<8) flux = Vec4();
    if (caustic->maxHeap.size()==0) return flux;
    i=caustic->maxHeap.size();
    distMax = Vec4::distSquared(caustic->maxHeap.at(0)->getPosition(),position);
    ni=0;
    nears = 60;
    float alfa = 1.818;
    float beta = 1.953;
    while (nears){
        if(caustic->maxHeap.at(i-1)->getStatus()==DIFUSED){
            Vec4 l = caustic->maxHeap.at(i-1)->getDirection().unitary();
            if(Vec4::dist(caustic->maxHeap.at(i-1)->position,position)<radiusCaustic){
                if((n*l>0)){
                    float dp = Vec4::distSquared(caustic->maxHeap.at(i-1)->position,position);
                    float r2 = distMax;
                    float wpc = alfa*(1. - (1. -(exp(-(beta*(dp/(2.*r2)))))/(1. -(exp(-beta)))));
                    fluxcaustic += (caustic->maxHeap.at(i-1)->getPower()*wpc*factor);
                    nears--;
                    ni++;
                }
            }
        }
        i--;
        if(i==0) break;
    }

    fluxcaustic = (fluxcaustic/(M_PI*distMax)); //com filtro
    if(ni<8) fluxcaustic = Vec4();
    //else printf("\nValor flux: <%3.8f,%3.8f,%3.8f>",fluxcaustic.x(),fluxcaustic.y(),fluxcaustic.z());
    return flux+fluxcaustic;
}

void PhotonMap::drawPhotonMap()
{
    glDisable(GL_LIGHTING);
    glPointSize(1.5);
    glBegin(GL_POINTS);
        for(unsigned int i=0;i<kdtree->photons.size();i++){
            Vec4 p = kdtree->photons.at(i)->getPosition();
            Vec4 color = kdtree->photons.at(i)->getPower()*(1./fat);
            glColor3f(color.x(),color.y(),color.z());
            glVertex3f(p.x(),p.y(),p.z());
        }
    glEnd();
    glEnable(GL_LIGHTING);
}

void PhotonMap::setDepth(int depthM)
{
    this->depthMax = depthM;
}

void PhotonMap::setRadiusGlogal(float rglobal)
{
    this->radiusGlobal = rglobal;
}

void PhotonMap::setRadiusCaustic(float rcaustic)
{
    this->radiusCaustic = rcaustic;
}

void PhotonMap::setFatorScalarPhoton(float factor)
{
    this->fat = factor;
}
