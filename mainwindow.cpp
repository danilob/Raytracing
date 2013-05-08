#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math/vec4.h"
#include <QPalette>
bool type_view = false;
bool info = false;
bool infolight = false;
int  type_light = -1;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setFixedSize(1118,670);
    defaultCamera();
    ui->widget->setFocusPolicy(Qt::StrongFocus);
    connect(ui->viewports,SIGNAL(clicked(bool)),ui->widget,SLOT(showViewports(bool)));
    connect(ui->widget,SIGNAL(stateSelected(int)),this,SLOT(stateSelected(int)));
    connect(ui->widget,SIGNAL(updateProjection(Vec4)),this,SLOT(refreshPerspective(Vec4)));
    connect(ui->sizeGrid,SIGNAL(valueChanged(int)),this,SLOT(callsizeGrid(int)));
    connect(ui->showGrid,SIGNAL(clicked(bool)),this,SLOT(callshowGrid(bool)));
    connect(ui->solidgrid,SIGNAL(clicked(bool)),this,SLOT(callsolidGrid(bool)));
    connect(ui->anglePerspective,SIGNAL(valueChanged(double)),this,SLOT(setProjection()));
    connect(ui->farPerspective,SIGNAL(valueChanged(double)),this,SLOT(setProjection()));
    connect(ui->nearPerspective,SIGNAL(valueChanged(double)),this,SLOT(setProjection()));
    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(typeViwer(int)));
    ui->progressBar->setValue(0);
    setColorMaterialView(0);
    setColorMaterialObject(0);
    //ui->progressBar->setMaximum(ui->widget_2->numberRays());
    //color backgroud ray casting
    connect(ui->sliderRed,SIGNAL(valueChanged(int)),this,SLOT(onColorBackgroudCastingChange()));
    connect(ui->sliderGreen,SIGNAL(valueChanged(int)),this,SLOT(onColorBackgroudCastingChange()));
    connect(ui->sliderBlue,SIGNAL(valueChanged(int)),this,SLOT(onColorBackgroudCastingChange()));

    onColorBackgroudCastingChange();
    //status dos raios
    connect(ui->widgetRay,SIGNAL(setIntersectRay(int)),ui->l_rayi,SLOT(setNum(int)));
    connect(ui->widgetRay,SIGNAL(setNotIntersectRay(int)),ui->l_rayni,SLOT(setNum(int)));
    //verificar a forma do lançamento dos raios
    connect(ui->checkBoxOtimized,SIGNAL(clicked(bool)),ui->widgetRay,SLOT(setOtimized(bool)));


    //connects relativos a iluminação
    connect(ui->widget,SIGNAL(listingLights(std::vector<Light*>)),this,SLOT(lightsList(std::vector<Light*>)));

    connect(ui->difuseRed,SIGNAL(valueChanged(int)),this,SLOT(onColorDiffuseChange()));
    connect(ui->difuseGreen,SIGNAL(valueChanged(int)),this,SLOT(onColorDiffuseChange()));
    connect(ui->difuseBlue,SIGNAL(valueChanged(int)),this,SLOT(onColorDiffuseChange()));

    connect(ui->specularRed,SIGNAL(valueChanged(int)),this,SLOT(onColorSpecularChange()));
    connect(ui->specularGreen,SIGNAL(valueChanged(int)),this,SLOT(onColorSpecularChange()));
    connect(ui->specularBlue,SIGNAL(valueChanged(int)),this,SLOT(onColorSpecularChange()));

    connect(ui->ambientRed,SIGNAL(valueChanged(int)),this,SLOT(onColorAmbientChange()));
    connect(ui->ambientGreen,SIGNAL(valueChanged(int)),this,SLOT(onColorAmbientChange()));
    connect(ui->ambientBlue,SIGNAL(valueChanged(int)),this,SLOT(onColorAmbientChange()));
    enableLightTab(false);

    connect(ui->widget,SIGNAL(showLightSelected(Light*)),this,SLOT(infoLight(Light*)));
    connect(ui->lights_list,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(selectLight()));

    connect(ui->ambientRed,SIGNAL(valueChanged(int)),this,SLOT(setPropertiesLights()));
    connect(ui->ambientGreen,SIGNAL(valueChanged(int)),this,SLOT(setPropertiesLights()));
    connect(ui->ambientBlue,SIGNAL(valueChanged(int)),this,SLOT(setPropertiesLights()));

    connect(ui->difuseRed,SIGNAL(valueChanged(int)),this,SLOT(setPropertiesLights()));
    connect(ui->difuseGreen,SIGNAL(valueChanged(int)),this,SLOT(setPropertiesLights()));
    connect(ui->difuseBlue,SIGNAL(valueChanged(int)),this,SLOT(setPropertiesLights()));

    connect(ui->specularRed,SIGNAL(valueChanged(int)),this,SLOT(setPropertiesLights()));
    connect(ui->specularGreen,SIGNAL(valueChanged(int)),this,SLOT(setPropertiesLights()));
    connect(ui->specularBlue,SIGNAL(valueChanged(int)),this,SLOT(setPropertiesLights()));

    connect(ui->positionxLight,SIGNAL(valueChanged(double)),this,SLOT(setPropertiesLights()));
    connect(ui->positionyLight,SIGNAL(valueChanged(double)),this,SLOT(setPropertiesLights()));
    connect(ui->positionzLight,SIGNAL(valueChanged(double)),this,SLOT(setPropertiesLights()));

    connect(ui->directionxLight,SIGNAL(valueChanged(double)),this,SLOT(setPropertiesLights()));
    connect(ui->directionyLight,SIGNAL(valueChanged(double)),this,SLOT(setPropertiesLights()));
    connect(ui->directionzLight,SIGNAL(valueChanged(double)),this,SLOT(setPropertiesLights()));

    connect(ui->attenuationcLight,SIGNAL(valueChanged(double)),this,SLOT(setPropertiesLights()));
    connect(ui->attenuationlLight,SIGNAL(valueChanged(double)),this,SLOT(setPropertiesLights()));
    connect(ui->attenuationqLight,SIGNAL(valueChanged(double)),this,SLOT(setPropertiesLights()));

    connect(ui->enableLight,SIGNAL(clicked(bool)),this,SLOT(setPropertiesLights()));
    connect(ui->visibleLight,SIGNAL(clicked(bool)),this,SLOT(setPropertiesLights()));
    connect(ui->selectedLight,SIGNAL(clicked(bool)),this,SLOT(selectLight()));

    connect(ui->anglespotLight,SIGNAL(valueChanged(int)),this,SLOT(setPropertiesLights()));
    connect(ui->exponentSpotLight,SIGNAL(valueChanged(int)),this,SLOT(setPropertiesLights()));

    connect(ui->nameLight,SIGNAL(editingFinished()),this,SLOT(updateListLights()));
    connect(ui->delLight,SIGNAL(clicked()),this,SLOT(delLightSelected()));
    connect(ui->addDirectional,SIGNAL(clicked()),this,SLOT(addDirectionalLight()));
    connect(ui->addSpot,SIGNAL(clicked()),this,SLOT(addSpotLight()));
    connect(ui->addPontual,SIGNAL(clicked()),this,SLOT(addPontualLight()));


    //connects relativos aos objetos
    connect(ui->delObj,SIGNAL(clicked()),this,SLOT(delObtectSelected()));
    connect(ui->addCube,SIGNAL(clicked()),this,SLOT(AddObjectCube()));
    connect(ui->addCylinder,SIGNAL(clicked()),this,SLOT(AddObjectCylinder()));
    connect(ui->addHemisphere,SIGNAL(clicked()),this,SLOT(AddObjectHemiSphere()));
    connect(ui->addPrism,SIGNAL(clicked()),this,SLOT(AddObjectPrism()));
    connect(ui->rotx,SIGNAL(valueChanged(int)),this,SLOT(setPropertyObject()));
    connect(ui->roty,SIGNAL(valueChanged(int)),this,SLOT(setPropertyObject()));
    connect(ui->rotz,SIGNAL(valueChanged(int)),this,SLOT(setPropertyObject()));
    connect(ui->transx,SIGNAL(valueChanged(double)),this,SLOT(setPropertyObject()));
    connect(ui->transy,SIGNAL(valueChanged(double)),this,SLOT(setPropertyObject()));
    connect(ui->transz,SIGNAL(valueChanged(double)),this,SLOT(setPropertyObject()));
    connect(ui->scalex,SIGNAL(valueChanged(double)),this,SLOT(setPropertyObject()));
    connect(ui->scaley,SIGNAL(valueChanged(double)),this,SLOT(setPropertyObject()));
    connect(ui->scalez,SIGNAL(valueChanged(double)),this,SLOT(setPropertyObject()));
    connect(ui->nomeObj,SIGNAL(editingFinished()),this,SLOT(updateListObjects()));
    connect(ui->materialobject,SIGNAL(activated(int)),this,SLOT(setPropertyObject()));
    connect(ui->widget,SIGNAL(listingObjects(std::vector<Object*>)),this,SLOT(objectsList(std::vector<Object*>)));
    connect(ui->objects_list,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(selectObject()));
    connect(ui->objects_list,SIGNAL(currentRowChanged(int)),this,SLOT(selectObject()));
    connect(ui->selectedObj,SIGNAL(clicked(bool)),this,SLOT(selectObject()));
    connect(ui->enableObj,SIGNAL(clicked(bool)),this,SLOT(setPropertyObject()));
    connect(ui->widget,SIGNAL(showObjectSelected(Object*)),this,SLOT(infoObject(Object*)));

    enableObjectTab(false);
    updateListObjects();
    updateListLights();
    connect(ui->materialobject,SIGNAL(currentIndexChanged(int)),this,SLOT(setColorMaterialObject(int)));
    connect(ui->comboBox_3,SIGNAL(currentIndexChanged(int)),this,SLOT(setColorMaterialView(int)));



}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::updadePositionCamera()
{
    Vec4 eye,at,up;
    eye.setVec4(ui->dEyex->value(),ui->dEyey->value(),ui->dEyez->value());
    at.setVec4(ui->dAtx->value(),ui->dAty->value(),ui->dAtz->value());
    up.setVec4(ui->dUpx->value(),ui->dUpy->value(),ui->dUpz->value());
    ui->widget->updateCamera(eye,at,up);
//    //

//    QString valueEye = QString("(%1,%2,%3)").arg(ui->dEyex->value()).arg(ui->dEyey->value()).arg(ui->dEyez->value());
//    QString valueAt = QString("(%1,%2,%3)").arg(ui->dAtx->value()).arg(ui->dAty->value()).arg(ui->dAtz->value());
//    QString valueUp = QString("(%1,%2,%3)").arg(ui->dUpx->value()).arg(ui->dUpy->value()).arg(ui->dUpz->value());



    ui->widget->updateCameraGL();
    if (type_view) ui->comboBox->setCurrentIndex(0);
    type_view = false;

}

void MainWindow::defaultCamera()
{
    ui->dEyex->setValue(40.0);
    ui->dEyey->setValue(50.0);
    ui->dEyez->setValue(40.0);

    ui->dAtx->setValue(0.0);
    ui->dAty->setValue(0.0);
    ui->dAtz->setValue(0.0);

    ui->dUpx->setValue(0.0);
    ui->dUpy->setValue(1.0);
    ui->dUpz->setValue(0.0);

    ui->widget->setDefaultWorld();
    updadePositionCamera();
    //ui->comboBox->setCurrentIndex(0);

}

void MainWindow::defaultPositionCamera()
{
    defaultCamera();
    QString valueEye = QString("(%1,%2,%3)").arg(ui->dEyex->value()).arg(ui->dEyey->value()).arg(ui->dEyez->value());
    QString valueAt = QString("(%1,%2,%3)").arg(ui->dAtx->value()).arg(ui->dAty->value()).arg(ui->dAtz->value());
    QString valueUp = QString("(%1,%2,%3)").arg(ui->dUpx->value()).arg(ui->dUpy->value()).arg(ui->dUpz->value());
    //ui->comboBox->setCurrentIndex(0);


}

void MainWindow::typeViwer(int value)
{
    switch (value){

    case 1:{ //top
        ui->dEyex->setValue(0.0);
        ui->dEyey->setValue(50.0);
        ui->dEyez->setValue(1.0);

        ui->dAtx->setValue(0.0);
        ui->dAty->setValue(0.0);
        ui->dAtz->setValue(0.0);

        ui->dUpx->setValue(0.0);
        ui->dUpy->setValue(1.0);
        ui->dUpz->setValue(0.0);
break;

        //updadePositionCamera();
    }
    case 2:{ //bottom
        ui->dEyex->setValue(0.0);
        ui->dEyey->setValue(-50.0);
        ui->dEyez->setValue(1.0);

        ui->dAtx->setValue(0.0);
        ui->dAty->setValue(0.0);
        ui->dAtz->setValue(0.0);

        ui->dUpx->setValue(0.0);
        ui->dUpy->setValue(1.0);
        ui->dUpz->setValue(0.0);
        break;


        //updadePositionCamera();
    }
    case 3:{ //right
        ui->dEyex->setValue(50.0);
        ui->dEyey->setValue(0.0);
        ui->dEyez->setValue(-4.0);

        ui->dAtx->setValue(0.0);
        ui->dAty->setValue(7.0);
        ui->dAtz->setValue(0.0);

        ui->dUpx->setValue(0.0);
        ui->dUpy->setValue(1.0);
        ui->dUpz->setValue(0.0);
 break;

        //updadePositionCamera();
    }
    case 4:{ //left
        ui->dEyex->setValue(-50.0);
        ui->dEyey->setValue(0.0);
        ui->dEyez->setValue(-3.0);

        ui->dAtx->setValue(0.0);
        ui->dAty->setValue(9.0);
        ui->dAtz->setValue(0.0);

        ui->dUpx->setValue(0.0);
        ui->dUpy->setValue(1.0);
        ui->dUpz->setValue(0.0);
break;

        //updadePositionCamera();
    }
    case 5:{ //front
        ui->dEyex->setValue(0.0);
        ui->dEyey->setValue(0.0);
        ui->dEyez->setValue(45.0);

        ui->dAtx->setValue(0.0);
        ui->dAty->setValue(5.0);
        ui->dAtz->setValue(0.0);

        ui->dUpx->setValue(0.0);
        ui->dUpy->setValue(1.0);
        ui->dUpz->setValue(0.0);

break;
        //updadePositionCamera();
    }
    case 6:{ //back
        ui->dEyex->setValue(-4.0);
        ui->dEyey->setValue(0.0);
        ui->dEyez->setValue(-45.0);

        ui->dAtx->setValue(0.0);
        ui->dAty->setValue(5.0);
        ui->dAtz->setValue(0.0);

        ui->dUpx->setValue(0.0);
        ui->dUpy->setValue(1.0);
        ui->dUpz->setValue(0.0);

break;

    }
    }
    updadePositionCamera();
    type_view = true;
}

void MainWindow::setCamEye(Vec4 eye)
{
    ui->dEyex->setValue(eye.x1);
    ui->dEyey->setValue(eye.x2);
    ui->dEyez->setValue(eye.x3);
    //ui->comboBox->setCurrentIndex(0);
}

void MainWindow::setCam(Vec4 eye, Vec4 at, Vec4 up)
{
    ui->dEyex->setValue(eye.x1);
    ui->dEyey->setValue(eye.x2);
    ui->dEyez->setValue(eye.x3);

    ui->dUpx->setValue(up.x1);
    ui->dUpy->setValue(up.x2);
    ui->dUpz->setValue(up.x3);

    ui->dAtx->setValue(at.x1);
    ui->dAty->setValue(at.x2);
    ui->dAtz->setValue(at.x3);

    //ui->comboBox->setCurrentIndex(0);

}

void MainWindow::refreshPerspective(Vec4 projection)
{
    ui->anglePerspective->setValue(projection.x());
    ui->nearPerspective->setValue(projection.z());
    ui->farPerspective->setValue(projection.w());
    QString value = QString("%1").arg(projection.y());
    ui->label_aspect->setText(value);
}


void MainWindow::copyScene()
{
    ui->widgetRay->setScene(ui->widget->getScene());
}

void MainWindow::setMaxProgress()
{
    ui->progressBar->setMaximum(ui->widgetRay->numberRays());
    ui->l_rayt->setNum(ui->widgetRay->numberRays());
    ui->l_rayni->setNum(0);
    ui->l_rayi->setNum(0);
}

void MainWindow::onColorBackgroudCastingChange()
{
   m_color.setRgb(ui->sliderRed->value(),ui->sliderGreen->value(),ui->sliderBlue->value());
   QPalette pal = ui->backgroudCasting->palette();
   pal.setColor(QPalette::Window,m_color);
   ui->backgroudCasting->setPalette(pal);
   emit colorBackgroudCastingChange(m_color);
}

void MainWindow::on_btnSaveImgRay_clicked()
{
    QString mfile = QFileDialog::getSaveFileName(this,"Save Screen Shot RayCasting");
    ui->widgetRay->saveScreen(mfile);
}

void MainWindow::on_btnSaveSceneOpenGL_clicked()
{
    QString mfile = QFileDialog::getSaveFileName(this,"Save Screen Shot OpenGL");
    ui->widget->saveImagem(mfile);
}

void MainWindow::objectsList(std::vector<Object*> objects)
{
    ui->objects_list->clear();
    for(int i=0;i<objects.size();i++){
        QString s;
        s.setNum(i);
        s.push_back(" - ");
        s.push_back(objects.at(i)->getName());
        ui->objects_list->addItem(s);
    }
    if (!ui->objects_list->hasFocus()) enableObjectTab(false);
}

void MainWindow::selectObject()
{

    int item = -1;
    if(ui->selectedObj->isChecked() || ui->objects_list->hasFocus()){
        ui->selectedObj->setChecked(true);
        for(int i=0;i < ui->objects_list->count();i++){
            if(ui->objects_list->item(i)->isSelected()){
                item = i;

                break;
            }
      }
    }
    if(item>-1) enableObjectTab(true);
    else enableObjectTab(false);
    ui->widget->setSelectedObject(item);

}

void MainWindow::infoObject(Object *obj)
{
    Vec4 rot,translate,scale;
    rot = obj->getMatrixTransformation().getRotationSeted();
    translate = obj->getMatrixTransformation().getTranslateSeted();
    scale = obj->getMatrixTransformation().getScaleSeted();
    QString s;
    info = true;
    if(ui->rotx->value() != (int)rot.x())  ui->rotx->setValue((int)rot.x());
    if(ui->roty->value() != (int)rot.y())  ui->roty->setValue((int)rot.y());
    if(ui->rotz->value() != (int)rot.z())  ui->rotz->setValue((int)rot.z());

    if(ui->transx->value() != translate.x()) ui->transx->setValue(translate.x());
    if(ui->transy->value() != translate.y()) ui->transy->setValue(translate.y());
    if(ui->transz->value() != translate.z()) ui->transz->setValue(translate.z());

    if(ui->scalex->value() != scale.x()) ui->scalex->setValue(scale.x());
    if(ui->scaley->value() != scale.y()) ui->scaley->setValue(scale.y());
    if(ui->scalez->value() != scale.z()) ui->scalez->setValue(scale.z());

    ui->nface->setNum(obj->getNumFaces());
    ui->nvertex->setNum(obj->getNumVertexs());
    ui->materialobject->setCurrentIndex(obj->getIdMaterial());
    ui->nomeObj->setText(obj->getName());
    ui->enableObj->setChecked(obj->isEnabled());
    info = false;
}




void MainWindow::setPropertyObject()
{
    if (!info){
    Matrix4x4 mat;
    mat.setIdentity();
    mat.scale(ui->scalex->value(),ui->scaley->value(),ui->scalez->value());
    mat.setRotationZ(ui->rotz->value());
    mat.setRotationY(ui->roty->value());
    mat.setRotationX(ui->rotx->value());
    mat.translate(ui->transx->value(),ui->transy->value(),ui->transz->value());



    ui->widget->setTransformMatrixToObjectSelected(mat);

    ui->widget->setIdMaterialToObjectSelected(ui->materialobject->currentIndex());




    ui->widget->setEnabledObjectSelected(ui->enableObj->isChecked());
    }




}

void MainWindow::enableObjectTab(bool e)
{
    if (e){
        ui->rotx->setEnabled(true);
        ui->roty->setEnabled(true);
        ui->rotz->setEnabled(true);
        ui->scalex->setEnabled(true);
        ui->scaley->setEnabled(true);
        ui->scalez->setEnabled(true);
        ui->transx->setEnabled(true);
        ui->transy->setEnabled(true);
        ui->transz->setEnabled(true);
        ui->materialobject->setEnabled(true);
        ui->nomeObj->setEnabled(true);
        ui->delObj->setEnabled(true);
        ui->enableObj->setEnabled(true);
        ui->selectedObj->setEnabled(true);
        ui->materialColorObject->setVisible(true);
    }else{
        ui->rotx->setEnabled(false);
        ui->roty->setEnabled(false);
        ui->rotz->setEnabled(false);
        ui->scalex->setEnabled(false);
        ui->scaley->setEnabled(false);
        ui->scalez->setEnabled(false);
        ui->transx->setEnabled(false);
        ui->transy->setEnabled(false);
        ui->transz->setEnabled(false);
        ui->materialobject->setEnabled(false);
        ui->nomeObj->setEnabled(false);
        ui->delObj->setEnabled(false);
        ui->enableObj->setEnabled(false);
        ui->selectedObj->setEnabled(false);
        ui->materialColorObject->setVisible(false);
    }
}

void MainWindow::updateListObjects()
{
    ui->widget->setNameObjectSelected(ui->nomeObj->text());
    for(int i=0;i<ui->widget->getObjectsScene().size();i++){
        QString s;
        s.setNum(i);
        s.push_back(" - ");
        s.push_back(ui->widget->getObjectsScene().at(i)->getName());
        if(ui->objects_list->count()==i) ui->objects_list->addItem(s);
        ui->objects_list->item(i)->setText(s);
    }
}

void MainWindow::AddObjectCube()
{
    ui->widget->addObject(0);
    updateListObjects();
}

void MainWindow::AddObjectCylinder()
{
    ui->widget->addObject(1);
    updateListObjects();
}

void MainWindow::AddObjectHemiSphere()
{
    ui->widget->addObject(2);
    updateListObjects();
}

void MainWindow::AddObjectPrism()
{
    ui->widget->addObject(3);
    updateListObjects();
}

void MainWindow::delObtectSelected()
{
    ui->widget->removeObjectSelected();
}

void MainWindow::lightsList(std::vector<Light*> lights)
{
    ui->lights_list->clear();

    for(int i=0;i<lights.size();i++){
        QString s;
        s.setNum(i);
        s.push_back(" - ");
        s.push_back(lights.at(i)->getName());
        ui->lights_list->addItem(s);
    }

    if (!ui->lights_list->hasFocus()) enableLightTab(false);
}

void MainWindow::onColorSpecularChange()
{
    m_color_specular.setRgb(ui->specularRed->value(),ui->specularGreen->value(),ui->specularBlue->value());
    QPalette pal = ui->specularWidget->palette();
    pal.setColor(QPalette::Window,m_color_specular);
    ui->specularWidget->setPalette(pal);
    emit colorSpecularChange(m_color_specular);
}


void MainWindow::onColorAmbientChange()
{
    m_color_ambient.setRgb(ui->ambientRed->value(),ui->ambientGreen->value(),ui->ambientBlue->value());
    QPalette pal = ui->ambientWidget->palette();
    pal.setColor(QPalette::Window,m_color_ambient);
    ui->ambientWidget->setPalette(pal);
    emit colorAmbientChange(m_color_ambient);
}

void MainWindow::onColorDiffuseChange()
{
    m_color_difuse.setRgb(ui->difuseRed->value(),ui->difuseGreen->value(),ui->difuseBlue->value());
    QPalette pal = ui->difuseWidget->palette();
    pal.setColor(QPalette::Window,m_color_difuse);
    ui->difuseWidget->setPalette(pal);
    emit colorDiffuseChange(m_color_difuse);
}

void MainWindow::selectLight()
{
    int item = -1;
    if(ui->selectedLight->isChecked() || ui->lights_list->hasFocus()){
        ui->selectedLight->setChecked(true);
        for(int i=0;i < ui->lights_list->count();i++){
            if(ui->lights_list->item(i)->isSelected()){
                item = i;
                break;
            }
      }
    }
    if(item<0) enableLightTab(false);
    else enableLightTab(true);
    ui->widget->setSelectedLight(item);

}

void MainWindow::enableLightTab(bool e)
{
    if(e){
        switch(type_light){
        case (LIGHT_AMBIENT):{
            ui->specularBlue->setEnabled(false);
            ui->specularBlue->setValue(0);
            ui->sliderSpecularBlue->setEnabled(false);
            ui->specularRed->setEnabled(false);
            ui->specularRed->setValue(0);
            ui->sliderSpecularRed->setEnabled(false);
            ui->specularGreen->setEnabled(false);
            ui->specularGreen->setValue(0);
            ui->sliderSpecularGreen->setEnabled(false);

            ui->ambientBlue->setEnabled(true);
            ui->sliderAmbientBlue->setEnabled(true);
            ui->ambientRed->setEnabled(true);
            ui->sliderAmbientRed->setEnabled(true);
            ui->ambientGreen->setEnabled(true);
            ui->sliderAmbientGreen->setEnabled(true);

            ui->difuseBlue->setEnabled(false);
            ui->difuseBlue->setValue(0);
            ui->sliderDiffuseBlue->setEnabled(false);
            ui->difuseRed->setEnabled(false);
            ui->difuseRed->setValue(false);
            ui->sliderDiffuseRed->setEnabled(false);
            ui->difuseGreen->setEnabled(false);
            ui->difuseGreen->setValue(0);
            ui->sliderDiffuseGreen->setEnabled(false);

            ui->nameLight->setEnabled(true);
            ui->delLight->setEnabled(false);
            ui->enableLight->setEnabled(false);
            ui->visibleLight->setEnabled(false);
            ui->selectedLight->setEnabled(true);

            ui->positionxLight->setEnabled(false);
            ui->positionyLight->setEnabled(false);
            ui->positionzLight->setEnabled(false);

            ui->directionxLight->setEnabled(false);
            ui->directionyLight->setEnabled(false);
            ui->directionzLight->setEnabled(false);

            ui->attenuationcLight->setEnabled(false);
            ui->attenuationlLight->setEnabled(false);
            ui->attenuationqLight->setEnabled(false);

            ui->anglespotLight->setEnabled(false);
            ui->exponentSpotLight->setEnabled(false);
            break;
        }
        case (LIGHT_SPOT):{
            ui->specularBlue->setEnabled(true);
            ui->sliderSpecularBlue->setEnabled(true);
            ui->specularRed->setEnabled(true);
            ui->sliderSpecularRed->setEnabled(true);
            ui->specularGreen->setEnabled(true);
            ui->sliderSpecularGreen->setEnabled(true);

            ui->ambientBlue->setEnabled(true);
            ui->sliderAmbientBlue->setEnabled(true);
            ui->ambientRed->setEnabled(true);
            ui->sliderAmbientRed->setEnabled(true);
            ui->ambientGreen->setEnabled(true);
            ui->sliderAmbientGreen->setEnabled(true);

            ui->difuseBlue->setEnabled(true);
            ui->sliderDiffuseBlue->setEnabled(true);
            ui->difuseRed->setEnabled(true);
            ui->sliderDiffuseRed->setEnabled(true);
            ui->difuseGreen->setEnabled(true);
            ui->sliderDiffuseGreen->setEnabled(true);

            ui->nameLight->setEnabled(true);
            ui->delLight->setEnabled(true);
            ui->enableLight->setEnabled(true);
            ui->visibleLight->setEnabled(true);
            ui->selectedLight->setEnabled(true);

            ui->positionxLight->setEnabled(true);
            ui->positionyLight->setEnabled(true);
            ui->positionzLight->setEnabled(true);

            ui->directionxLight->setEnabled(true);
            ui->directionyLight->setEnabled(true);
            ui->directionzLight->setEnabled(true);

            ui->attenuationcLight->setEnabled(true);
            ui->attenuationlLight->setEnabled(true);
            ui->attenuationqLight->setEnabled(true);

            ui->anglespotLight->setEnabled(true);
            ui->exponentSpotLight->setEnabled(true);
            break;
        }
        case (LIGHT_DIRECTIONAL):{
            ui->specularBlue->setEnabled(true);
            ui->sliderSpecularBlue->setEnabled(true);
            ui->specularRed->setEnabled(true);
            ui->sliderSpecularRed->setEnabled(true);
            ui->specularGreen->setEnabled(true);
            ui->sliderSpecularGreen->setEnabled(true);

            ui->ambientBlue->setEnabled(true);
            ui->sliderAmbientBlue->setEnabled(true);
            ui->ambientRed->setEnabled(true);
            ui->sliderAmbientRed->setEnabled(true);
            ui->ambientGreen->setEnabled(true);
            ui->sliderAmbientGreen->setEnabled(true);

            ui->difuseBlue->setEnabled(true);
            ui->sliderDiffuseBlue->setEnabled(true);
            ui->difuseRed->setEnabled(true);
            ui->sliderDiffuseRed->setEnabled(true);
            ui->difuseGreen->setEnabled(true);
            ui->sliderDiffuseGreen->setEnabled(true);

            ui->nameLight->setEnabled(true);
            ui->delLight->setEnabled(true);
            ui->enableLight->setEnabled(true);
            ui->visibleLight->setEnabled(true);
            ui->selectedLight->setEnabled(true);

            ui->positionxLight->setEnabled(false);
            ui->positionyLight->setEnabled(false);
            ui->positionzLight->setEnabled(false);

            ui->directionxLight->setEnabled(true);
            ui->directionyLight->setEnabled(true);
            ui->directionzLight->setEnabled(true);

            ui->attenuationcLight->setEnabled(false);
            ui->attenuationlLight->setEnabled(false);
            ui->attenuationqLight->setEnabled(false);

            ui->anglespotLight->setEnabled(false);
            ui->exponentSpotLight->setEnabled(false);
            break;
        }
        case (LIGHT_PONTUAL):{
            ui->specularBlue->setEnabled(true);
            ui->sliderSpecularBlue->setEnabled(true);
            ui->specularRed->setEnabled(true);
            ui->sliderSpecularRed->setEnabled(true);
            ui->specularGreen->setEnabled(true);
            ui->sliderSpecularGreen->setEnabled(true);

            ui->ambientBlue->setEnabled(true);
            ui->sliderAmbientBlue->setEnabled(true);
            ui->ambientRed->setEnabled(true);
            ui->sliderAmbientRed->setEnabled(true);
            ui->ambientGreen->setEnabled(true);
            ui->sliderAmbientGreen->setEnabled(true);

            ui->difuseBlue->setEnabled(true);
            ui->sliderDiffuseBlue->setEnabled(true);
            ui->difuseRed->setEnabled(true);
            ui->sliderDiffuseRed->setEnabled(true);
            ui->difuseGreen->setEnabled(true);
            ui->sliderDiffuseGreen->setEnabled(true);

            ui->nameLight->setEnabled(true);
            ui->delLight->setEnabled(true);
            ui->enableLight->setEnabled(true);
            ui->visibleLight->setEnabled(true);
            ui->selectedLight->setEnabled(true);

            ui->positionxLight->setEnabled(true);
            ui->positionyLight->setEnabled(true);
            ui->positionzLight->setEnabled(true);

            ui->directionxLight->setEnabled(false);
            ui->directionyLight->setEnabled(false);
            ui->directionzLight->setEnabled(false);

            ui->attenuationcLight->setEnabled(true);
            ui->attenuationlLight->setEnabled(true);
            ui->attenuationqLight->setEnabled(true);

            ui->anglespotLight->setEnabled(false);
            ui->exponentSpotLight->setEnabled(false);
            break;
        }
        }

    }else{
        ui->specularBlue->setEnabled(false);
        ui->sliderSpecularBlue->setEnabled(false);
        ui->specularRed->setEnabled(false);
        ui->sliderSpecularRed->setEnabled(false);
        ui->specularGreen->setEnabled(false);
        ui->sliderSpecularGreen->setEnabled(false);

        ui->ambientBlue->setEnabled(false);
        ui->sliderAmbientBlue->setEnabled(false);
        ui->ambientRed->setEnabled(false);
        ui->sliderAmbientRed->setEnabled(false);
        ui->ambientGreen->setEnabled(false);
        ui->sliderAmbientGreen->setEnabled(false);

        ui->difuseBlue->setEnabled(false);
        ui->sliderDiffuseBlue->setEnabled(false);
        ui->difuseRed->setEnabled(false);
        ui->sliderDiffuseRed->setEnabled(false);
        ui->difuseGreen->setEnabled(false);
        ui->sliderDiffuseGreen->setEnabled(false);

        ui->nameLight->setEnabled(false);
        ui->delLight->setEnabled(false);
        ui->enableLight->setEnabled(false);
        ui->visibleLight->setEnabled(false);
        ui->selectedLight->setEnabled(false);

        ui->positionxLight->setEnabled(false);
        ui->positionyLight->setEnabled(false);
        ui->positionzLight->setEnabled(false);

        ui->directionxLight->setEnabled(false);
        ui->directionyLight->setEnabled(false);
        ui->directionzLight->setEnabled(false);

        ui->attenuationcLight->setEnabled(false);
        ui->attenuationlLight->setEnabled(false);
        ui->attenuationqLight->setEnabled(false);

        ui->anglespotLight->setEnabled(false);
        ui->exponentSpotLight->setEnabled(false);

    }
}

void MainWindow::infoLight(Light *light)
{

    infolight = true;
    type_light = light->getTypeLight();
    enableLightTab(true);
    switch(type_light){
    case (LIGHT_AMBIENT):{
        //ui->visibleLight->setChecked(light->isVisible());
        ui->nameLight->setText(light->getName());
        QColor color;
        color = light->getAmbientColor();
        ui->ambientRed->setValue(color.red());
        ui->ambientGreen->setValue(color.green());
        ui->ambientBlue->setValue(color.blue());
        //ui->selectedLight->setChecked(light->isSelected());
        break;
    }
    case (LIGHT_SPOT):{

        ui->nameLight->setText(light->getName());
        QColor color;
        color = light->getAmbientColor();
        ui->ambientRed->setValue(color.red());
        ui->ambientGreen->setValue(color.green());
        ui->ambientBlue->setValue(color.blue());
        color = light->getSpecularColor();
        ui->specularRed->setValue(color.red());
        ui->specularGreen->setValue(color.green());
        ui->specularBlue->setValue(color.blue());
        color = light->getDiffuseColor();
        ui->difuseRed->setValue(color.red());
        ui->difuseGreen->setValue(color.green());
        ui->difuseBlue->setValue(color.blue());
        Vec4 position = light->getPosition();
        ui->positionxLight->setValue(position.x());
        ui->positionyLight->setValue(position.y());
        ui->positionzLight->setValue(position.z());
        Vec4 direction = light->getDirection();
        ui->directionxLight->setValue(direction.x());
        ui->directionyLight->setValue(direction.y());
        ui->directionzLight->setValue(direction.z());
        Vec4 attenuation = light->getAttenuation();
        ui->attenuationcLight->setValue(attenuation.x());
        ui->attenuationlLight->setValue(attenuation.y());
        ui->attenuationqLight->setValue(attenuation.z());
        ui->exponentSpotLight->setValue(light->getExponent());
        ui->anglespotLight->setValue(light->getAngle());
        ui->enableLight->setChecked(light->isEnabled());
        ui->visibleLight->setChecked(light->isVisible());
        //ui->selectedLight->setChecked(light->isSelected());

        break;
    }
    case (LIGHT_DIRECTIONAL):{
        ui->nameLight->setText(light->getName());
        QColor color;
        color = light->getAmbientColor();
        ui->ambientRed->setValue(color.red());
        ui->ambientGreen->setValue(color.green());
        ui->ambientBlue->setValue(color.blue());
        color = light->getSpecularColor();
        ui->specularRed->setValue(color.red());
        ui->specularGreen->setValue(color.green());
        ui->specularBlue->setValue(color.blue());
        color = light->getDiffuseColor();
        ui->difuseRed->setValue(color.red());
        ui->difuseGreen->setValue(color.green());
        ui->difuseBlue->setValue(color.blue());
        Vec4 direction = light->getDirection();
        ui->directionxLight->setValue(direction.x());
        ui->directionyLight->setValue(direction.y());
        ui->directionzLight->setValue(direction.z());
        ui->enableLight->setChecked(light->isEnabled());
        ui->visibleLight->setChecked(light->isVisible());
        //ui->selectedLight->setChecked(light->isSelected());
        break;
    }
    case (LIGHT_PONTUAL):{
        ui->visibleLight->setChecked(light->isVisible());
        ui->enableLight->setChecked(light->isEnabled());
        ui->nameLight->setText(light->getName());
        QColor color;
        color = light->getAmbientColor();
        ui->ambientRed->setValue(color.red());
        ui->ambientGreen->setValue(color.green());
        ui->ambientBlue->setValue(color.blue());
        color = light->getSpecularColor();
        ui->specularRed->setValue(color.red());
        ui->specularGreen->setValue(color.green());
        ui->specularBlue->setValue(color.blue());
        color = light->getDiffuseColor();
        ui->difuseRed->setValue(color.red());
        ui->difuseGreen->setValue(color.green());
        ui->difuseBlue->setValue(color.blue());
        Vec4 position = light->getPosition();
        ui->positionxLight->setValue(position.x());
        ui->positionyLight->setValue(position.y());
        ui->positionzLight->setValue(position.z());
        Vec4 attenuation = light->getAttenuation();
        ui->attenuationcLight->setValue(attenuation.x());
        ui->attenuationlLight->setValue(attenuation.y());
        ui->attenuationqLight->setValue(attenuation.z());

        //ui->selectedLight->setChecked(light->isSelected());
        break;
    }
    }
    infolight = false;
}

void MainWindow::setPropertiesLights()
{
    if (!infolight){
        switch(type_light){
        case (LIGHT_PONTUAL):{

            //ui->widget->setSelectedLight(ui->selectedLight->isChecked());
            ui->widget->setLightSelectedAmbient(m_color_ambient);
            ui->widget->setEnabledLightSelected(ui->enableLight->isChecked());
            ui->widget->setVisibleLightSelected(ui->visibleLight->isChecked());
            Vec4 position(ui->positionxLight->value(),ui->positionyLight->value(),ui->positionzLight->value());
            ui->widget->setLightSelectedPosition(position);
            Vec4 attenuation(ui->attenuationcLight->value(),ui->attenuationlLight->value(),ui->attenuationqLight->value());
            ui->widget->setLightSelectedAttenuation(attenuation);
            //ui->widget->setSelectedLight(ui->selectedLight->isChecked());

            break;
        }
        case (LIGHT_SPOT):{

            //ui->widget->setSelectedLight(ui->selectedLight->isChecked());
            ui->widget->setLightSelectedAmbient(m_color_ambient);
            ui->widget->setLightSelectedSpecular(m_color_specular);
            ui->widget->setLightSelectedDiffuse(m_color_difuse);
            ui->widget->setEnabledLightSelected(ui->enableLight->isChecked());
            ui->widget->setVisibleLightSelected(ui->visibleLight->isChecked());
            Vec4 position(ui->positionxLight->value(),ui->positionyLight->value(),ui->positionzLight->value());
            ui->widget->setLightSelectedPosition(position);
            Vec4 direction(ui->directionxLight->value(),ui->directionyLight->value(),ui->directionzLight->value());
            ui->widget->setLightSelectedDirection(direction);
            Vec4 attenuation(ui->attenuationcLight->value(),ui->attenuationlLight->value(),ui->attenuationqLight->value());
            ui->widget->setLightSelectedAttenuation(attenuation);
            ui->widget->setLightSelectedAngle(ui->anglespotLight->value());
            ui->widget->setLightSelectedExponent(ui->exponentSpotLight->value());
            //ui->widget->setSelectedLight(ui->selectedLight->isChecked());

            break;
        }
        case (LIGHT_DIRECTIONAL):{

            //ui->widget->setSelectedLight(ui->selectedLight->isChecked());
            ui->widget->setLightSelectedAmbient(m_color_ambient);
            ui->widget->setLightSelectedSpecular(m_color_specular);
            ui->widget->setLightSelectedDiffuse(m_color_difuse);
            ui->widget->setEnabledLightSelected(ui->enableLight->isChecked());
            ui->widget->setVisibleLightSelected(ui->visibleLight->isChecked());
            //ui->widget->setSelectedLight(ui->selectedLight->isChecked());
            Vec4 direction(ui->directionxLight->value(),ui->directionyLight->value(),ui->directionzLight->value());
            ui->widget->setLightSelectedDirection(direction);
            break;
        }
        case (LIGHT_AMBIENT):{
            ui->widget->setLightSelectedAmbient(m_color_ambient);
            ui->widget->setLightSelectedSpecular(m_color_specular);
            ui->widget->setLightSelectedDiffuse(m_color_difuse);
            ui->widget->setEnabledLightSelected(ui->enableLight->isChecked());
            ui->widget->setVisibleLightSelected(ui->visibleLight->isChecked());
            //ui->widget->setSelectedLight(ui->selectedLight->isChecked());
            break;
        }
        }
    }


}

void MainWindow::updateListLights()
{

    ui->widget->setLightSelectedName(ui->nameLight->text());
    for(int i=0;i<ui->widget->getLightsScene().size();i++){
        QString s;
        s.setNum(i);
        s.push_back(" - ");
        s.push_back(ui->widget->getLightsScene().at(i)->getName());
        if(ui->lights_list->count()==i) ui->lights_list->addItem(s);
        ui->lights_list->item(i)->setText(s);
    }

}

void MainWindow::delLightSelected()
{
    ui->widget->removeLightSelected();
    updateListLights();
}

void MainWindow::addPontualLight()
{
    ui->widget->addLight(LIGHT_PONTUAL);
}

void MainWindow::addDirectionalLight()
{
    ui->widget->addLight(LIGHT_DIRECTIONAL);
}

void MainWindow::addSpotLight()
{
    ui->widget->addLight(LIGHT_SPOT);
}

void MainWindow::callshowGrid(bool b)
{
    ui->sizeGrid->setEnabled(b);
    ui->widget->showGrid(b);
}

void MainWindow::callsizeGrid(int val)
{
    ui->widget->sizeGrid(val);
}

void MainWindow::setColorMaterialView(int i)
{
    QColor color = Material::getColorMaterial(i);
    m_color_material_view.setRgb(color.red(),color.green(),color.blue());
    QPalette pal = ui->materialColorView->palette();
    pal.setColor(QPalette::Window,m_color_material_view);
    ui->materialColorView->setPalette(pal);


}

void MainWindow::setColorMaterialObject(int i)
{
    QColor color = Material::getColorMaterial(i);
    m_color_material_object.setRgb(color.red(),color.green(),color.blue());
    QPalette pal = ui->materialColorObject->palette();
    pal.setColor(QPalette::Window,m_color_material_object);
    ui->materialColorObject->setPalette(pal);

}

void MainWindow::callsolidGrid(bool b)
{
    ui->widget->solidGrid(b);
}

void MainWindow::stateSelected(int st)
{
    if(st==0){
        ui->stateSelected->setText("Set Vector At View Camera");
    }
    if(st==Qt::Key_R){
        ui->stateSelected->setText("Mode Rotate Object");
    }
    if(st==Qt::Key_S){
        ui->stateSelected->setText("Mode Scale Object");
    }
    if(st==Qt::Key_T){
        ui->stateSelected->setText("Mode Translate Object");
    }
}

void MainWindow::setProjection()
{
    ui->widget->updateProjectionOut(Vec4(ui->anglePerspective->value(),0,ui->nearPerspective->value(),ui->farPerspective->value()));
}

void MainWindow::on_SaveScene_clicked()
{
    QString mfile = QFileDialog::getSaveFileName(this,"Save Scene");
    ui->widget->saveScene(mfile);
}

void MainWindow::on_pushButton_2_clicked()
{
    QString mfile = QFileDialog::getOpenFileName(this,"Load Scene");
    ui->widget->loadScene(mfile);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->widget->addObject(BLOCK_SPHERE);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->widget->addObject(BLOCK_PLANE);
}

void MainWindow::on_createHBB_clicked()
{
    ui->widget->getHBB();
}
