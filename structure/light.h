#ifndef LIGHT_H
#define LIGHT_H
#include "math/vec4.h"
#include "extra/material.h"


#define LIGHT_AMBIENT     0
#define LIGHT_DIRECTIONAL 1
#define LIGHT_PONTUAL     2
#define LIGHT_SPOT        3


class Light
{
public:
    virtual void       drawLight() = 0;
    virtual void       drawLightOpenGL(int flag_light = -1) = 0;
    virtual void       drawReferenceLight() = 0;
    virtual Vec4       calculateColor(Vec4 pit,Vec4 n,Vec4 viewer, Material *m,Vec4 pos) = 0;
    virtual QString    getName() = 0;
    virtual void       setName(QString name) = 0;
    virtual bool       isEnabled() = 0;
    virtual void       setEnabled(bool b) = 0;
    virtual bool       isSelected() = 0;
    virtual void       setSelected(bool b) = 0;
    virtual bool       isVisible() = 0;
    virtual void       setVisible(bool b) = 0;
    virtual void       setAmbientColor(QColor color) = 0;
    virtual QColor     getAmbientColor() = 0;
    virtual void       setSpecularColor(QColor color) = 0;
    virtual QColor     getSpecularColor() = 0;
    virtual void       setDiffuseColor(QColor color) = 0;
    virtual QColor     getDiffuseColor() = 0;
    virtual int        getTypeLight() = 0;
    virtual void       setPosition(Vec4 pos) = 0;
    virtual Vec4       getPosition() = 0;
    virtual void       setDirection(Vec4 pos) = 0;
    virtual Vec4       getDirection() = 0;
    virtual void       setAttenuation(Vec4 pos) = 0;
    virtual Vec4       getAttenuation() = 0;
    virtual int        getAngle() = 0;
    virtual void       setAngle(int angle) = 0;
    virtual void       setExponent(int exp) = 0;
    virtual int        getExponent() = 0;
    virtual QString    saveLight() = 0;
    virtual Vec4       randLight() = 0;

};

class AmbientLight: public Light
{
public:
    AmbientLight();
    void       setLight(Vec4 spec);
    void       drawLight(){}
    void       drawReferenceLight(){}
    Vec4       calculateColor(Vec4 pit,Vec4 n,Vec4 viewer, Material *m,Vec4 pos=Vec4(0,0,0));
    void       drawLightOpenGL(int flag_light = -1);
    QString    getName();
    void       setName(QString name);
    bool       isEnabled(){}
    void       setEnabled(bool){}
    bool       isVisible();
    void       setVisible(bool);
    void       setAmbientColor(QColor);
    QColor     getAmbientColor();
    void       setSpecularColor(QColor){}
    QColor     getSpecularColor(){}
    void       setDiffuseColor(QColor){}
    QColor     getDiffuseColor(){}
    int        getTypeLight();
    void       setSelected(bool);
    bool       isSelected();
    void       setPosition(Vec4){}
    Vec4       getPosition(){}
    void       setDirection(Vec4){}
    Vec4       getDirection(){}
    void       setAttenuation(Vec4){}
    Vec4       getAttenuation(){}
    int        getAngle(){}
    void       setAngle(int angle){}
    void       setExponent(int exp){}
    int        getExponent(){}
    QString    saveLight();
    Vec4       randLight(){}


private:
    Vec4*      ambient_light;
    QString    name;
    bool       visible;
    bool       selected;

};

class DirectionalLight: public Light
{
public:
    DirectionalLight();
    void setLight(Vec4* pos, Vec4* diff, Vec4* spec, Vec4* amb= new Vec4(1,1,1,1.0));                           //tipo de luz que tem o vetor de direção
    void drawLight(){};
    void drawReferenceLight();
    void drawLightOpenGL(int flag_light);
    Vec4 calculateColor(Vec4 pit,Vec4 n,Vec4 viewer, Material *m,Vec4 pos=Vec4(0,0,0));
    QString    getName();
    void       setName(QString name);
    bool       isEnabled();
    void       setEnabled(bool b);
    bool       isVisible();
    void       setVisible(bool b);
    void       setAmbientColor(QColor color);
    QColor     getAmbientColor();
    void       setSpecularColor(QColor color);
    QColor     getSpecularColor();
    void       setDiffuseColor(QColor color);
    QColor     getDiffuseColor();
    int        getTypeLight();
    void       setSelected(bool b);
    bool       isSelected();
    void       setPosition(Vec4 pos){}
    Vec4       getPosition(){}
    void       setDirection(Vec4 pos);
    Vec4       getDirection();
    void       setAttenuation(Vec4 pos){}
    Vec4       getAttenuation(){}
    int        getAngle(){}
    void       setAngle(int angle){}
    void       setExponent(int exp){}
    int        getExponent(){}
    QString    saveLight();
    Vec4       randLight(){}
private:
    Vec4*      diffuse_light;
    Vec4*      specular_light;
    Vec4*      ambient_light;
    Vec4*      direction_light;
    bool       enabled;
    bool       visible;
    bool       selected;
    QString    name;
};

class PontualLight: public Light
{
public:
    PontualLight();
    void setLight(Vec4* pos, Vec4* diff, Vec4* spec,Vec4* amb= new Vec4(1,1,1,1.0));                                //tipo de luz que tem uma posição fixa
    void drawLight(){};
    void drawReferenceLight();
    void drawLightOpenGL(int flag_light);
    Vec4 calculateColor(Vec4 pit,Vec4 n,Vec4 viewer, Material *m,Vec4 pos=Vec4(0,0,0));
    QString    getName();
    void       setName(QString name);
    bool       isEnabled();
    void       setEnabled(bool b);
    bool       isVisible();
    void       setVisible(bool b);
    void       setAmbientColor(QColor color);
    QColor     getAmbientColor();
    void       setSpecularColor(QColor color);
    QColor     getSpecularColor();
    void       setDiffuseColor(QColor color);
    QColor     getDiffuseColor();
    float      attenuation(float distance);
    int        getTypeLight();
    void       setSelected(bool b);
    bool       isSelected();
    void       setPosition(Vec4 pos);
    Vec4       getPosition();
    void       setDirection(Vec4 pos){}
    Vec4       getDirection(){}
    void       setAttenuation(Vec4 pos);
    Vec4       getAttenuation();
    int        getAngle(){}
    void       setAngle(int angle){}
    void       setExponent(int exp){}
    int        getExponent(){}
    QString    saveLight();
    Vec4       randLight();
    ~PontualLight();
private:
    Vec4*      position_light;
    Vec4*      diffuse_light;
    Vec4*      specular_light;
    Vec4*      ambient_light;
    Vec4*      factor_attenuation;   //constante, linear, quadratico
    bool       enabled;
    bool       visible;
    bool       selected;
    QString    name;
};

class SpotLight: public Light
{
public:
    SpotLight();
    void setLight(int angle, int expoent,Vec4* pos,Vec4 *dir, Vec4* diff, Vec4* spec,Vec4* amb= new Vec4(1,1,1,1.0));  //tipo de luz que tem um ângulo de direção
    void drawLight(){};
    void drawReferenceLight();
    void drawLightOpenGL(int flag_light);
    Vec4 calculateColor(Vec4 pit,Vec4 n,Vec4 viewer, Material *m,Vec4 pos=Vec4(0,0,0));
    QString    getName();
    void       setName(QString name);
    bool       isEnabled();
    void       setEnabled(bool b);
    bool       isVisible();
    void       setVisible(bool b);
    bool       isSelected();
    void       setSelected(bool b);
    void       setAmbientColor(QColor color);
    QColor     getAmbientColor();
    void       setSpecularColor(QColor color);
    QColor     getSpecularColor();
    void       setDiffuseColor(QColor color);
    QColor     getDiffuseColor();
    float      attenuation(float distance);
    int        getTypeLight();
    Vec4       randLight(){}

    void       setPosition(Vec4 pos);
    Vec4       getPosition();
    void       setDirection(Vec4 pos);
    Vec4       getDirection();
    void       setAttenuation(Vec4 pos);
    Vec4       getAttenuation();
    int        getAngle();
    void       setAngle(int angle);
    void       setExponent(int exp);
    int        getExponent();

    int        isInConeSpot(Vec4 pit);
    float      isInDualConeSpot(Vec4 pit);

    QString    saveLight();


private:
    Vec4*     position_light;
    Vec4*     diffuse_light;
    Vec4*     specular_light;
    Vec4*     ambient_light;
    Vec4*     factor_attenuation;   //constante, linear, quadratico
    Vec4*     direction_light;
    int       angle_light;
    int       expoent_light;         //fator de atenuação da luz spot
    bool      enabled;
    bool      visible;
    bool      selected;
    QString   name;
};


#endif // LIGHT_H
