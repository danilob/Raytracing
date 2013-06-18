/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Jun 17 19:35:54 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <interface/glwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionQuit;
    QAction *actionGrid;
    QAction *actionPropertiesScene;
    QAction *actionCube;
    QAction *actionCylinder;
    QAction *actionHemisphere;
    QAction *actionPrism;
    QAction *actionSphere;
    QAction *actionArea;
    QAction *actionDirectional;
    QAction *actionPontual;
    QAction *actionSpot;
    QAction *actionGlossy_Reflection;
    QAction *actionGlossy_Refraction;
    QAction *actionMotion_Blur;
    QAction *actionDepth_of_Field;
    QAction *actionScreenShot;
    QAction *actionScreanShot_Render;
    QAction *actionCone;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_9;
    QScrollArea *scrollObject;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBoxPropertiesObj;
    QGridLayout *gridLayout_11;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *ambMaterial;
    QPushButton *diffMaterial;
    QPushButton *speMaterial;
    QLineEdit *nomeObj;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *selectedObj;
    QCheckBox *enableObj;
    QLabel *label_10;
    QLabel *label_13;
    QPushButton *loadTexture;
    QComboBox *materialobject;
    QVBoxLayout *verticalLayout_3;
    QDoubleSpinBox *transx;
    QDoubleSpinBox *transy;
    QDoubleSpinBox *transz;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_10;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_35;
    QDoubleSpinBox *glossyreflection;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_34;
    QDoubleSpinBox *glossyrefraction;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_33;
    QDoubleSpinBox *reflection;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_32;
    QDoubleSpinBox *refraction;
    QHBoxLayout *horizontalLayout_18;
    QDoubleSpinBox *xmotion;
    QDoubleSpinBox *ymotion;
    QDoubleSpinBox *zmotion;
    QLabel *label_36;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_14;
    QDoubleSpinBox *shiniMaterial;
    QVBoxLayout *verticalLayout_4;
    QSpinBox *rotx;
    QSpinBox *roty;
    QSpinBox *rotz;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_16;
    QLabel *label_15;
    QLabel *label_17;
    QLabel *label_11;
    QLabel *label_12;
    QPushButton *deleteObj;
    QVBoxLayout *verticalLayout_5;
    QDoubleSpinBox *scalex;
    QDoubleSpinBox *scaley;
    QDoubleSpinBox *scalez;
    QGraphicsView *onScreenImage;
    QScrollArea *scrollLight;
    QWidget *scrollAreaWidgetContents_4;
    QFormLayout *formLayout;
    QGroupBox *groupBoxPropertieLight;
    QVBoxLayout *verticalLayout_8;
    QFrame *nameLightLayout;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_20;
    QLineEdit *nameLight;
    QHBoxLayout *optionLayout;
    QCheckBox *selectedLight;
    QCheckBox *visibleLight;
    QCheckBox *enableLight;
    QFrame *orientationLight;
    QGridLayout *gridLayout_7;
    QFrame *positionLayoutLight;
    QVBoxLayout *positionLayout;
    QLabel *label_21;
    QDoubleSpinBox *positionxLight;
    QDoubleSpinBox *positionyLight;
    QDoubleSpinBox *positionzLight;
    QFrame *directionLayoutLight;
    QVBoxLayout *directionLayout;
    QLabel *label_22;
    QDoubleSpinBox *directionxLight;
    QDoubleSpinBox *directionyLight;
    QDoubleSpinBox *directionzLight;
    QFrame *vectorsLayoutLight;
    QVBoxLayout *vectorsLayout;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_24;
    QHBoxLayout *horizontalLayout_10;
    QDoubleSpinBox *vecAx;
    QDoubleSpinBox *vecAy;
    QDoubleSpinBox *vecAz;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_25;
    QHBoxLayout *horizontalLayout_11;
    QDoubleSpinBox *vecBx;
    QDoubleSpinBox *vecBy;
    QDoubleSpinBox *vecBz;
    QFrame *attenuationLayoutLight;
    QVBoxLayout *attenuationLayout;
    QLabel *label_23;
    QHBoxLayout *horizontalLayout_9;
    QDoubleSpinBox *attenuationcLight;
    QDoubleSpinBox *attenuationlLight;
    QDoubleSpinBox *attenuationqLight;
    QFrame *ADSLight;
    QHBoxLayout *horizontalLayout;
    QFrame *ambienteProperty;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_26;
    QPushButton *ambMaterial_2;
    QFrame *diffuseProperty;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_27;
    QPushButton *diffMaterial_2;
    QFrame *specularProperty;
    QVBoxLayout *verticalLayoutSpe;
    QLabel *label_28;
    QPushButton *speMaterial_2;
    QFrame *angleSpotLayoutLight;
    QVBoxLayout *angleSpotLayout;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_29;
    QSpinBox *anglespotLight;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_30;
    QSpinBox *anglespotinnerLight;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_31;
    QSpinBox *exponentSpotLight;
    QPushButton *deleteLight;
    QFrame *frame_3;
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QWidget *tabOpenGL;
    QGridLayout *gridLayout_3;
    GLWidget *widgetOpenGL;
    QWidget *tabRender;
    QGridLayout *gridLayout_6;
    QGraphicsView *graphicsRender;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QGridLayout *gridLayout_4;
    QToolBox *toolBox;
    QWidget *page;
    QGridLayout *gridLayout_5;
    QListWidget *objects_list;
    QWidget *page_3;
    QGridLayout *gridLayout_8;
    QListWidget *lights_list;
    QWidget *page_2;
    QCheckBox *showHBB;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_12;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_37;
    QDoubleSpinBox *radiusDOF;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_38;
    QDoubleSpinBox *focalDOF;
    QWidget *page_4;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_18;
    QSpinBox *numSamples;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_19;
    QSpinBox *proportion;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *btnRender;
    QProgressBar *progressRender;
    QScrollArea *scrollAreaBottom;
    QWidget *scrollAreaWidgetContents_2;
    QGroupBox *groupBox;
    QDoubleSpinBox *dEyex;
    QDoubleSpinBox *dEyey;
    QDoubleSpinBox *dEyez;
    QDoubleSpinBox *dAtx;
    QDoubleSpinBox *dAty;
    QDoubleSpinBox *dAtz;
    QDoubleSpinBox *dUpx;
    QDoubleSpinBox *dUpy;
    QDoubleSpinBox *dUpz;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QGroupBox *groupBox_2;
    QDoubleSpinBox *anglePerspective;
    QDoubleSpinBox *nearPerspective;
    QDoubleSpinBox *farPerspective;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QGroupBox *groupBox_3;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QSpinBox *sizeGrid;
    QLabel *height_l;
    QLabel *width_l;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuObject;
    QMenu *menuLights;
    QMenu *menuObject_2;
    QMenu *menuLight;
    QMenu *menuOptions;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(913, 843);
        MainWindow->setMaximumSize(QSize(2000000, 16777215));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionGrid = new QAction(MainWindow);
        actionGrid->setObjectName(QString::fromUtf8("actionGrid"));
        actionGrid->setCheckable(true);
        actionGrid->setChecked(true);
        actionPropertiesScene = new QAction(MainWindow);
        actionPropertiesScene->setObjectName(QString::fromUtf8("actionPropertiesScene"));
        actionPropertiesScene->setCheckable(true);
        actionPropertiesScene->setChecked(true);
        actionCube = new QAction(MainWindow);
        actionCube->setObjectName(QString::fromUtf8("actionCube"));
        actionCylinder = new QAction(MainWindow);
        actionCylinder->setObjectName(QString::fromUtf8("actionCylinder"));
        actionHemisphere = new QAction(MainWindow);
        actionHemisphere->setObjectName(QString::fromUtf8("actionHemisphere"));
        actionPrism = new QAction(MainWindow);
        actionPrism->setObjectName(QString::fromUtf8("actionPrism"));
        actionSphere = new QAction(MainWindow);
        actionSphere->setObjectName(QString::fromUtf8("actionSphere"));
        actionArea = new QAction(MainWindow);
        actionArea->setObjectName(QString::fromUtf8("actionArea"));
        actionDirectional = new QAction(MainWindow);
        actionDirectional->setObjectName(QString::fromUtf8("actionDirectional"));
        actionPontual = new QAction(MainWindow);
        actionPontual->setObjectName(QString::fromUtf8("actionPontual"));
        actionSpot = new QAction(MainWindow);
        actionSpot->setObjectName(QString::fromUtf8("actionSpot"));
        actionGlossy_Reflection = new QAction(MainWindow);
        actionGlossy_Reflection->setObjectName(QString::fromUtf8("actionGlossy_Reflection"));
        actionGlossy_Refraction = new QAction(MainWindow);
        actionGlossy_Refraction->setObjectName(QString::fromUtf8("actionGlossy_Refraction"));
        actionMotion_Blur = new QAction(MainWindow);
        actionMotion_Blur->setObjectName(QString::fromUtf8("actionMotion_Blur"));
        actionDepth_of_Field = new QAction(MainWindow);
        actionDepth_of_Field->setObjectName(QString::fromUtf8("actionDepth_of_Field"));
        actionScreenShot = new QAction(MainWindow);
        actionScreenShot->setObjectName(QString::fromUtf8("actionScreenShot"));
        actionScreanShot_Render = new QAction(MainWindow);
        actionScreanShot_Render->setObjectName(QString::fromUtf8("actionScreanShot_Render"));
        actionCone = new QAction(MainWindow);
        actionCone->setObjectName(QString::fromUtf8("actionCone"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_9 = new QGridLayout();
        gridLayout_9->setSpacing(6);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        scrollObject = new QScrollArea(centralWidget);
        scrollObject->setObjectName(QString::fromUtf8("scrollObject"));
        scrollObject->setMinimumSize(QSize(250, 0));
        scrollObject->setMaximumSize(QSize(250, 16777215));
        scrollObject->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 248, 749));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBoxPropertiesObj = new QGroupBox(scrollAreaWidgetContents);
        groupBoxPropertiesObj->setObjectName(QString::fromUtf8("groupBoxPropertiesObj"));
        groupBoxPropertiesObj->setEnabled(true);
        groupBoxPropertiesObj->setMaximumSize(QSize(230, 16777215));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        groupBoxPropertiesObj->setFont(font);
        groupBoxPropertiesObj->setStyleSheet(QString::fromUtf8("QGroupBox::title { \n"
"   \n"
"     subcontrol-position: top left; /* position at the top left*/ \n"
"  padding: 2px 13px;\n"
"   margin-top: -5px;\n"
"    \n"
" }\n"
"\n"
"QGroupBox{\n"
"   border: 1px solid rgb(182, 181, 179);\n"
"  border-radius: 5px;\n"
"}"));
        groupBoxPropertiesObj->setFlat(false);
        gridLayout_11 = new QGridLayout(groupBoxPropertiesObj);
        gridLayout_11->setSpacing(2);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(2, 5, 2, 2);
        frame = new QFrame(groupBoxPropertiesObj);
        frame->setObjectName(QString::fromUtf8("frame"));
        horizontalLayout_3 = new QHBoxLayout(frame);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        ambMaterial = new QPushButton(frame);
        ambMaterial->setObjectName(QString::fromUtf8("ambMaterial"));
        ambMaterial->setAutoFillBackground(true);
        ambMaterial->setFlat(false);

        horizontalLayout_3->addWidget(ambMaterial);

        diffMaterial = new QPushButton(frame);
        diffMaterial->setObjectName(QString::fromUtf8("diffMaterial"));

        horizontalLayout_3->addWidget(diffMaterial);

        speMaterial = new QPushButton(frame);
        speMaterial->setObjectName(QString::fromUtf8("speMaterial"));

        horizontalLayout_3->addWidget(speMaterial);


        gridLayout_11->addWidget(frame, 8, 0, 1, 2);

        nomeObj = new QLineEdit(groupBoxPropertiesObj);
        nomeObj->setObjectName(QString::fromUtf8("nomeObj"));

        gridLayout_11->addWidget(nomeObj, 1, 0, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        selectedObj = new QCheckBox(groupBoxPropertiesObj);
        selectedObj->setObjectName(QString::fromUtf8("selectedObj"));

        horizontalLayout_2->addWidget(selectedObj);

        enableObj = new QCheckBox(groupBoxPropertiesObj);
        enableObj->setObjectName(QString::fromUtf8("enableObj"));

        horizontalLayout_2->addWidget(enableObj);


        gridLayout_11->addLayout(horizontalLayout_2, 2, 0, 1, 2);

        label_10 = new QLabel(groupBoxPropertiesObj);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_11->addWidget(label_10, 0, 0, 1, 1);

        label_13 = new QLabel(groupBoxPropertiesObj);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_11->addWidget(label_13, 5, 1, 1, 1);

        loadTexture = new QPushButton(groupBoxPropertiesObj);
        loadTexture->setObjectName(QString::fromUtf8("loadTexture"));

        gridLayout_11->addWidget(loadTexture, 12, 0, 1, 2);

        materialobject = new QComboBox(groupBoxPropertiesObj);
        materialobject->setObjectName(QString::fromUtf8("materialobject"));

        gridLayout_11->addWidget(materialobject, 10, 0, 1, 2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        transx = new QDoubleSpinBox(groupBoxPropertiesObj);
        transx->setObjectName(QString::fromUtf8("transx"));
        transx->setLayoutDirection(Qt::LeftToRight);
        transx->setWrapping(false);
        transx->setAlignment(Qt::AlignCenter);
        transx->setMinimum(-9999);
        transx->setMaximum(9999);
        transx->setValue(0);

        verticalLayout_3->addWidget(transx);

        transy = new QDoubleSpinBox(groupBoxPropertiesObj);
        transy->setObjectName(QString::fromUtf8("transy"));
        transy->setAlignment(Qt::AlignCenter);
        transy->setMinimum(-9999);
        transy->setMaximum(9999);
        transy->setValue(0);

        verticalLayout_3->addWidget(transy);

        transz = new QDoubleSpinBox(groupBoxPropertiesObj);
        transz->setObjectName(QString::fromUtf8("transz"));
        transz->setAlignment(Qt::AlignCenter);
        transz->setMinimum(-9999);
        transz->setMaximum(9999);
        transz->setValue(0);

        verticalLayout_3->addWidget(transz);


        gridLayout_11->addLayout(verticalLayout_3, 4, 0, 1, 2);

        groupBox_4 = new QGroupBox(groupBoxPropertiesObj);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setFont(font);
        gridLayout_10 = new QGridLayout(groupBox_4);
        gridLayout_10->setSpacing(0);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(0, 5, 0, 5);
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_35 = new QLabel(groupBox_4);
        label_35->setObjectName(QString::fromUtf8("label_35"));

        horizontalLayout_17->addWidget(label_35);

        glossyreflection = new QDoubleSpinBox(groupBox_4);
        glossyreflection->setObjectName(QString::fromUtf8("glossyreflection"));
        glossyreflection->setDecimals(3);
        glossyreflection->setMaximum(1);
        glossyreflection->setSingleStep(0.25);

        horizontalLayout_17->addWidget(glossyreflection);


        gridLayout_10->addLayout(horizontalLayout_17, 3, 0, 1, 1);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_34 = new QLabel(groupBox_4);
        label_34->setObjectName(QString::fromUtf8("label_34"));

        horizontalLayout_13->addWidget(label_34);

        glossyrefraction = new QDoubleSpinBox(groupBox_4);
        glossyrefraction->setObjectName(QString::fromUtf8("glossyrefraction"));
        glossyrefraction->setDecimals(3);
        glossyrefraction->setMaximum(1);
        glossyrefraction->setSingleStep(0.25);

        horizontalLayout_13->addWidget(glossyrefraction);


        gridLayout_10->addLayout(horizontalLayout_13, 2, 0, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_33 = new QLabel(groupBox_4);
        label_33->setObjectName(QString::fromUtf8("label_33"));

        horizontalLayout_12->addWidget(label_33);

        reflection = new QDoubleSpinBox(groupBox_4);
        reflection->setObjectName(QString::fromUtf8("reflection"));
        reflection->setDecimals(3);
        reflection->setMaximum(1);
        reflection->setSingleStep(0.25);

        horizontalLayout_12->addWidget(reflection);


        gridLayout_10->addLayout(horizontalLayout_12, 1, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_32 = new QLabel(groupBox_4);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        horizontalLayout_8->addWidget(label_32);

        refraction = new QDoubleSpinBox(groupBox_4);
        refraction->setObjectName(QString::fromUtf8("refraction"));
        refraction->setDecimals(3);
        refraction->setMinimum(0);
        refraction->setMaximum(5);
        refraction->setSingleStep(0.25);

        horizontalLayout_8->addWidget(refraction);


        gridLayout_10->addLayout(horizontalLayout_8, 0, 0, 1, 1);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(0);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        xmotion = new QDoubleSpinBox(groupBox_4);
        xmotion->setObjectName(QString::fromUtf8("xmotion"));
        xmotion->setDecimals(1);
        xmotion->setMinimum(-99);

        horizontalLayout_18->addWidget(xmotion);

        ymotion = new QDoubleSpinBox(groupBox_4);
        ymotion->setObjectName(QString::fromUtf8("ymotion"));
        ymotion->setDecimals(1);
        ymotion->setMinimum(-99);

        horizontalLayout_18->addWidget(ymotion);

        zmotion = new QDoubleSpinBox(groupBox_4);
        zmotion->setObjectName(QString::fromUtf8("zmotion"));
        zmotion->setDecimals(1);
        zmotion->setMinimum(-99);

        horizontalLayout_18->addWidget(zmotion);


        gridLayout_10->addLayout(horizontalLayout_18, 5, 0, 1, 1);

        label_36 = new QLabel(groupBox_4);
        label_36->setObjectName(QString::fromUtf8("label_36"));

        gridLayout_10->addWidget(label_36, 4, 0, 1, 1);


        gridLayout_11->addWidget(groupBox_4, 11, 0, 1, 2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_14 = new QLabel(groupBoxPropertiesObj);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_4->addWidget(label_14);

        shiniMaterial = new QDoubleSpinBox(groupBoxPropertiesObj);
        shiniMaterial->setObjectName(QString::fromUtf8("shiniMaterial"));
        shiniMaterial->setDecimals(3);
        shiniMaterial->setMaximum(1);
        shiniMaterial->setSingleStep(0.05);

        horizontalLayout_4->addWidget(shiniMaterial);


        gridLayout_11->addLayout(horizontalLayout_4, 9, 0, 1, 2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetMinimumSize);
        rotx = new QSpinBox(groupBoxPropertiesObj);
        rotx->setObjectName(QString::fromUtf8("rotx"));
        rotx->setAlignment(Qt::AlignCenter);
        rotx->setMinimum(0);
        rotx->setMaximum(360);

        verticalLayout_4->addWidget(rotx);

        roty = new QSpinBox(groupBoxPropertiesObj);
        roty->setObjectName(QString::fromUtf8("roty"));
        roty->setAlignment(Qt::AlignCenter);
        roty->setMinimum(0);
        roty->setMaximum(360);

        verticalLayout_4->addWidget(roty);

        rotz = new QSpinBox(groupBoxPropertiesObj);
        rotz->setObjectName(QString::fromUtf8("rotz"));
        rotz->setAlignment(Qt::AlignCenter);
        rotz->setMinimum(0);
        rotz->setMaximum(360);

        verticalLayout_4->addWidget(rotz);


        gridLayout_11->addLayout(verticalLayout_4, 6, 0, 1, 1);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        label_16 = new QLabel(groupBoxPropertiesObj);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_19->addWidget(label_16);

        label_15 = new QLabel(groupBoxPropertiesObj);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_19->addWidget(label_15);

        label_17 = new QLabel(groupBoxPropertiesObj);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_19->addWidget(label_17);


        gridLayout_11->addLayout(horizontalLayout_19, 7, 0, 1, 2);

        label_11 = new QLabel(groupBoxPropertiesObj);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_11->addWidget(label_11, 3, 0, 1, 1);

        label_12 = new QLabel(groupBoxPropertiesObj);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_11->addWidget(label_12, 5, 0, 1, 1);

        deleteObj = new QPushButton(groupBoxPropertiesObj);
        deleteObj->setObjectName(QString::fromUtf8("deleteObj"));

        gridLayout_11->addWidget(deleteObj, 14, 0, 1, 2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        scalex = new QDoubleSpinBox(groupBoxPropertiesObj);
        scalex->setObjectName(QString::fromUtf8("scalex"));
        scalex->setAlignment(Qt::AlignCenter);
        scalex->setMinimum(0);
        scalex->setMaximum(9999);
        scalex->setSingleStep(0.5);
        scalex->setValue(0);

        verticalLayout_5->addWidget(scalex);

        scaley = new QDoubleSpinBox(groupBoxPropertiesObj);
        scaley->setObjectName(QString::fromUtf8("scaley"));
        scaley->setAlignment(Qt::AlignCenter);
        scaley->setMinimum(0);
        scaley->setMaximum(9999);
        scaley->setSingleStep(0.5);
        scaley->setValue(0);

        verticalLayout_5->addWidget(scaley);

        scalez = new QDoubleSpinBox(groupBoxPropertiesObj);
        scalez->setObjectName(QString::fromUtf8("scalez"));
        scalez->setAlignment(Qt::AlignCenter);
        scalez->setMinimum(0);
        scalez->setMaximum(9999);
        scalez->setSingleStep(0.5);
        scalez->setValue(0);

        verticalLayout_5->addWidget(scalez);


        gridLayout_11->addLayout(verticalLayout_5, 6, 1, 1, 1);

        onScreenImage = new QGraphicsView(groupBoxPropertiesObj);
        onScreenImage->setObjectName(QString::fromUtf8("onScreenImage"));

        gridLayout_11->addWidget(onScreenImage, 13, 0, 1, 2);


        verticalLayout_2->addWidget(groupBoxPropertiesObj);

        scrollObject->setWidget(scrollAreaWidgetContents);

        gridLayout_9->addWidget(scrollObject, 0, 0, 1, 1);

        scrollLight = new QScrollArea(centralWidget);
        scrollLight->setObjectName(QString::fromUtf8("scrollLight"));
        scrollLight->setMinimumSize(QSize(250, 0));
        scrollLight->setMaximumSize(QSize(250, 16777215));
        scrollLight->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 254, 672));
        formLayout = new QFormLayout(scrollAreaWidgetContents_4);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        groupBoxPropertieLight = new QGroupBox(scrollAreaWidgetContents_4);
        groupBoxPropertieLight->setObjectName(QString::fromUtf8("groupBoxPropertieLight"));
        groupBoxPropertieLight->setMinimumSize(QSize(230, 0));
        groupBoxPropertieLight->setMaximumSize(QSize(230, 16777215));
        groupBoxPropertieLight->setFont(font);
        groupBoxPropertieLight->setStyleSheet(QString::fromUtf8("QGroupBox::title { \n"
"   \n"
"     subcontrol-position: top left; /* position at the top left*/ \n"
"  padding: 2px 13px;\n"
"   margin-top: -5px;\n"
"    \n"
" }\n"
"\n"
"QGroupBox{\n"
"   border: 1px solid rgb(182, 181, 179);\n"
"  border-radius: 5px;\n"
"}"));
        verticalLayout_8 = new QVBoxLayout(groupBoxPropertieLight);
        verticalLayout_8->setSpacing(2);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(2, 1, 1, 3);
        nameLightLayout = new QFrame(groupBoxPropertieLight);
        nameLightLayout->setObjectName(QString::fromUtf8("nameLightLayout"));
        verticalLayout_7 = new QVBoxLayout(nameLightLayout);
        verticalLayout_7->setSpacing(1);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 5, 0, 0);
        label_20 = new QLabel(nameLightLayout);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        verticalLayout_7->addWidget(label_20);

        nameLight = new QLineEdit(nameLightLayout);
        nameLight->setObjectName(QString::fromUtf8("nameLight"));

        verticalLayout_7->addWidget(nameLight);


        verticalLayout_8->addWidget(nameLightLayout);

        optionLayout = new QHBoxLayout();
        optionLayout->setSpacing(0);
        optionLayout->setObjectName(QString::fromUtf8("optionLayout"));
        selectedLight = new QCheckBox(groupBoxPropertieLight);
        selectedLight->setObjectName(QString::fromUtf8("selectedLight"));
        selectedLight->setTristate(false);

        optionLayout->addWidget(selectedLight);

        visibleLight = new QCheckBox(groupBoxPropertieLight);
        visibleLight->setObjectName(QString::fromUtf8("visibleLight"));

        optionLayout->addWidget(visibleLight);

        enableLight = new QCheckBox(groupBoxPropertieLight);
        enableLight->setObjectName(QString::fromUtf8("enableLight"));

        optionLayout->addWidget(enableLight);


        verticalLayout_8->addLayout(optionLayout);

        orientationLight = new QFrame(groupBoxPropertieLight);
        orientationLight->setObjectName(QString::fromUtf8("orientationLight"));
        gridLayout_7 = new QGridLayout(orientationLight);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setHorizontalSpacing(1);
        positionLayoutLight = new QFrame(orientationLight);
        positionLayoutLight->setObjectName(QString::fromUtf8("positionLayoutLight"));
        positionLayout = new QVBoxLayout(positionLayoutLight);
        positionLayout->setSpacing(1);
        positionLayout->setContentsMargins(0, 0, 0, 0);
        positionLayout->setObjectName(QString::fromUtf8("positionLayout"));
        label_21 = new QLabel(positionLayoutLight);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        positionLayout->addWidget(label_21);

        positionxLight = new QDoubleSpinBox(positionLayoutLight);
        positionxLight->setObjectName(QString::fromUtf8("positionxLight"));
        positionxLight->setMinimum(-5000);
        positionxLight->setMaximum(5000);

        positionLayout->addWidget(positionxLight);

        positionyLight = new QDoubleSpinBox(positionLayoutLight);
        positionyLight->setObjectName(QString::fromUtf8("positionyLight"));
        positionyLight->setMinimum(-5000);
        positionyLight->setMaximum(5000);

        positionLayout->addWidget(positionyLight);

        positionzLight = new QDoubleSpinBox(positionLayoutLight);
        positionzLight->setObjectName(QString::fromUtf8("positionzLight"));
        positionzLight->setMinimum(-5000);
        positionzLight->setMaximum(5000);

        positionLayout->addWidget(positionzLight);


        gridLayout_7->addWidget(positionLayoutLight, 0, 0, 1, 1);

        directionLayoutLight = new QFrame(orientationLight);
        directionLayoutLight->setObjectName(QString::fromUtf8("directionLayoutLight"));
        directionLayout = new QVBoxLayout(directionLayoutLight);
        directionLayout->setSpacing(1);
        directionLayout->setContentsMargins(0, 0, 0, 0);
        directionLayout->setObjectName(QString::fromUtf8("directionLayout"));
        label_22 = new QLabel(directionLayoutLight);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        directionLayout->addWidget(label_22);

        directionxLight = new QDoubleSpinBox(directionLayoutLight);
        directionxLight->setObjectName(QString::fromUtf8("directionxLight"));
        directionxLight->setMinimum(-5000);
        directionxLight->setMaximum(5000);

        directionLayout->addWidget(directionxLight);

        directionyLight = new QDoubleSpinBox(directionLayoutLight);
        directionyLight->setObjectName(QString::fromUtf8("directionyLight"));
        directionyLight->setMinimum(-5000);
        directionyLight->setMaximum(5000);

        directionLayout->addWidget(directionyLight);

        directionzLight = new QDoubleSpinBox(directionLayoutLight);
        directionzLight->setObjectName(QString::fromUtf8("directionzLight"));
        directionzLight->setMinimum(-5000);
        directionzLight->setMaximum(5000);

        directionLayout->addWidget(directionzLight);


        gridLayout_7->addWidget(directionLayoutLight, 0, 1, 1, 1);


        verticalLayout_8->addWidget(orientationLight);

        vectorsLayoutLight = new QFrame(groupBoxPropertieLight);
        vectorsLayoutLight->setObjectName(QString::fromUtf8("vectorsLayoutLight"));
        vectorsLayout = new QVBoxLayout(vectorsLayoutLight);
        vectorsLayout->setSpacing(1);
        vectorsLayout->setContentsMargins(0, 0, 0, 0);
        vectorsLayout->setObjectName(QString::fromUtf8("vectorsLayout"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label_24 = new QLabel(vectorsLayoutLight);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        verticalLayout_9->addWidget(label_24);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(1);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        vecAx = new QDoubleSpinBox(vectorsLayoutLight);
        vecAx->setObjectName(QString::fromUtf8("vecAx"));
        vecAx->setMinimum(-5000);
        vecAx->setMaximum(5000);

        horizontalLayout_10->addWidget(vecAx);

        vecAy = new QDoubleSpinBox(vectorsLayoutLight);
        vecAy->setObjectName(QString::fromUtf8("vecAy"));
        vecAy->setMinimum(-5000);
        vecAy->setMaximum(5000);

        horizontalLayout_10->addWidget(vecAy);

        vecAz = new QDoubleSpinBox(vectorsLayoutLight);
        vecAz->setObjectName(QString::fromUtf8("vecAz"));
        vecAz->setMinimum(-5000);
        vecAz->setMaximum(5000);

        horizontalLayout_10->addWidget(vecAz);


        verticalLayout_9->addLayout(horizontalLayout_10);


        vectorsLayout->addLayout(verticalLayout_9);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        label_25 = new QLabel(vectorsLayoutLight);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        verticalLayout_10->addWidget(label_25);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(1);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        vecBx = new QDoubleSpinBox(vectorsLayoutLight);
        vecBx->setObjectName(QString::fromUtf8("vecBx"));
        vecBx->setMinimum(-5000);
        vecBx->setMaximum(5000);

        horizontalLayout_11->addWidget(vecBx);

        vecBy = new QDoubleSpinBox(vectorsLayoutLight);
        vecBy->setObjectName(QString::fromUtf8("vecBy"));
        vecBy->setMinimum(-5000);
        vecBy->setMaximum(5000);

        horizontalLayout_11->addWidget(vecBy);

        vecBz = new QDoubleSpinBox(vectorsLayoutLight);
        vecBz->setObjectName(QString::fromUtf8("vecBz"));
        vecBz->setMinimum(-5000);
        vecBz->setMaximum(5000);

        horizontalLayout_11->addWidget(vecBz);


        verticalLayout_10->addLayout(horizontalLayout_11);


        vectorsLayout->addLayout(verticalLayout_10);


        verticalLayout_8->addWidget(vectorsLayoutLight);

        attenuationLayoutLight = new QFrame(groupBoxPropertieLight);
        attenuationLayoutLight->setObjectName(QString::fromUtf8("attenuationLayoutLight"));
        attenuationLayout = new QVBoxLayout(attenuationLayoutLight);
        attenuationLayout->setSpacing(2);
        attenuationLayout->setContentsMargins(0, 0, 0, 0);
        attenuationLayout->setObjectName(QString::fromUtf8("attenuationLayout"));
        label_23 = new QLabel(attenuationLayoutLight);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        attenuationLayout->addWidget(label_23);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(1);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        attenuationcLight = new QDoubleSpinBox(attenuationLayoutLight);
        attenuationcLight->setObjectName(QString::fromUtf8("attenuationcLight"));
        attenuationcLight->setMinimum(-5000);
        attenuationcLight->setMaximum(5000);

        horizontalLayout_9->addWidget(attenuationcLight);

        attenuationlLight = new QDoubleSpinBox(attenuationLayoutLight);
        attenuationlLight->setObjectName(QString::fromUtf8("attenuationlLight"));
        attenuationlLight->setMinimum(-5000);
        attenuationlLight->setMaximum(5000);

        horizontalLayout_9->addWidget(attenuationlLight);

        attenuationqLight = new QDoubleSpinBox(attenuationLayoutLight);
        attenuationqLight->setObjectName(QString::fromUtf8("attenuationqLight"));
        attenuationqLight->setMinimum(-5000);
        attenuationqLight->setMaximum(5000);

        horizontalLayout_9->addWidget(attenuationqLight);


        attenuationLayout->addLayout(horizontalLayout_9);


        verticalLayout_8->addWidget(attenuationLayoutLight);

        ADSLight = new QFrame(groupBoxPropertieLight);
        ADSLight->setObjectName(QString::fromUtf8("ADSLight"));
        horizontalLayout = new QHBoxLayout(ADSLight);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ambienteProperty = new QFrame(ADSLight);
        ambienteProperty->setObjectName(QString::fromUtf8("ambienteProperty"));
        verticalLayout_11 = new QVBoxLayout(ambienteProperty);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(1, 1, 1, 1);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        label_26 = new QLabel(ambienteProperty);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        verticalLayout_11->addWidget(label_26);

        ambMaterial_2 = new QPushButton(ambienteProperty);
        ambMaterial_2->setObjectName(QString::fromUtf8("ambMaterial_2"));
        ambMaterial_2->setAutoFillBackground(true);
        ambMaterial_2->setFlat(false);

        verticalLayout_11->addWidget(ambMaterial_2);


        horizontalLayout->addWidget(ambienteProperty);

        diffuseProperty = new QFrame(ADSLight);
        diffuseProperty->setObjectName(QString::fromUtf8("diffuseProperty"));
        verticalLayout_12 = new QVBoxLayout(diffuseProperty);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(1, 1, 1, 1);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        label_27 = new QLabel(diffuseProperty);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        verticalLayout_12->addWidget(label_27);

        diffMaterial_2 = new QPushButton(diffuseProperty);
        diffMaterial_2->setObjectName(QString::fromUtf8("diffMaterial_2"));

        verticalLayout_12->addWidget(diffMaterial_2);


        horizontalLayout->addWidget(diffuseProperty);

        specularProperty = new QFrame(ADSLight);
        specularProperty->setObjectName(QString::fromUtf8("specularProperty"));
        specularProperty->setAutoFillBackground(false);
        verticalLayoutSpe = new QVBoxLayout(specularProperty);
        verticalLayoutSpe->setSpacing(6);
        verticalLayoutSpe->setContentsMargins(1, 1, 1, 1);
        verticalLayoutSpe->setObjectName(QString::fromUtf8("verticalLayoutSpe"));
        label_28 = new QLabel(specularProperty);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        verticalLayoutSpe->addWidget(label_28);

        speMaterial_2 = new QPushButton(specularProperty);
        speMaterial_2->setObjectName(QString::fromUtf8("speMaterial_2"));

        verticalLayoutSpe->addWidget(speMaterial_2);


        horizontalLayout->addWidget(specularProperty);


        verticalLayout_8->addWidget(ADSLight);

        angleSpotLayoutLight = new QFrame(groupBoxPropertieLight);
        angleSpotLayoutLight->setObjectName(QString::fromUtf8("angleSpotLayoutLight"));
        angleSpotLayout = new QVBoxLayout(angleSpotLayoutLight);
        angleSpotLayout->setSpacing(1);
        angleSpotLayout->setContentsMargins(0, 0, 0, 0);
        angleSpotLayout->setObjectName(QString::fromUtf8("angleSpotLayout"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_29 = new QLabel(angleSpotLayoutLight);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        horizontalLayout_14->addWidget(label_29);

        anglespotLight = new QSpinBox(angleSpotLayoutLight);
        anglespotLight->setObjectName(QString::fromUtf8("anglespotLight"));
        anglespotLight->setMaximum(180);

        horizontalLayout_14->addWidget(anglespotLight);


        angleSpotLayout->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_30 = new QLabel(angleSpotLayoutLight);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        horizontalLayout_15->addWidget(label_30);

        anglespotinnerLight = new QSpinBox(angleSpotLayoutLight);
        anglespotinnerLight->setObjectName(QString::fromUtf8("anglespotinnerLight"));
        anglespotinnerLight->setMaximum(180);

        horizontalLayout_15->addWidget(anglespotinnerLight);


        angleSpotLayout->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_31 = new QLabel(angleSpotLayoutLight);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        horizontalLayout_16->addWidget(label_31);

        exponentSpotLight = new QSpinBox(angleSpotLayoutLight);
        exponentSpotLight->setObjectName(QString::fromUtf8("exponentSpotLight"));
        exponentSpotLight->setMaximum(128);

        horizontalLayout_16->addWidget(exponentSpotLight);


        angleSpotLayout->addLayout(horizontalLayout_16);


        verticalLayout_8->addWidget(angleSpotLayoutLight);

        deleteLight = new QPushButton(groupBoxPropertieLight);
        deleteLight->setObjectName(QString::fromUtf8("deleteLight"));

        verticalLayout_8->addWidget(deleteLight);


        formLayout->setWidget(0, QFormLayout::LabelRole, groupBoxPropertieLight);

        scrollLight->setWidget(scrollAreaWidgetContents_4);

        gridLayout_9->addWidget(scrollLight, 0, 1, 1, 1);

        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::NoFrame);
        frame_3->setFrameShadow(QFrame::Plain);
        gridLayout_2 = new QGridLayout(frame_3);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tabWidget = new QTabWidget(frame_3);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabOpenGL = new QWidget();
        tabOpenGL->setObjectName(QString::fromUtf8("tabOpenGL"));
        gridLayout_3 = new QGridLayout(tabOpenGL);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        widgetOpenGL = new GLWidget(tabOpenGL);
        widgetOpenGL->setObjectName(QString::fromUtf8("widgetOpenGL"));

        gridLayout_3->addWidget(widgetOpenGL, 0, 0, 1, 1);

        tabWidget->addTab(tabOpenGL, QString());
        tabRender = new QWidget();
        tabRender->setObjectName(QString::fromUtf8("tabRender"));
        gridLayout_6 = new QGridLayout(tabRender);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        graphicsRender = new QGraphicsView(tabRender);
        graphicsRender->setObjectName(QString::fromUtf8("graphicsRender"));

        gridLayout_6->addWidget(graphicsRender, 0, 0, 1, 1);

        tabWidget->addTab(tabRender, QString());

        gridLayout_2->addWidget(tabWidget, 0, 0, 1, 1);


        gridLayout_9->addWidget(frame_3, 0, 2, 1, 1);

        scrollArea_3 = new QScrollArea(centralWidget);
        scrollArea_3->setObjectName(QString::fromUtf8("scrollArea_3"));
        scrollArea_3->setMinimumSize(QSize(250, 0));
        scrollArea_3->setMaximumSize(QSize(250, 16777215));
        scrollArea_3->setStyleSheet(QString::fromUtf8(""));
        scrollArea_3->setFrameShape(QFrame::StyledPanel);
        scrollArea_3->setFrameShadow(QFrame::Plain);
        scrollArea_3->setLineWidth(2);
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 248, 688));
        gridLayout_4 = new QGridLayout(scrollAreaWidgetContents_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        toolBox = new QToolBox(scrollAreaWidgetContents_3);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setStyleSheet(QString::fromUtf8(""));
        toolBox->setFrameShape(QFrame::NoFrame);
        toolBox->setFrameShadow(QFrame::Sunken);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 98, 96));
        gridLayout_5 = new QGridLayout(page);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        objects_list = new QListWidget(page);
        objects_list->setObjectName(QString::fromUtf8("objects_list"));

        gridLayout_5->addWidget(objects_list, 0, 0, 1, 1);

        toolBox->addItem(page, QString::fromUtf8("Objects"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        page_3->setGeometry(QRect(0, 0, 98, 96));
        gridLayout_8 = new QGridLayout(page_3);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        lights_list = new QListWidget(page_3);
        lights_list->setObjectName(QString::fromUtf8("lights_list"));

        gridLayout_8->addWidget(lights_list, 0, 0, 1, 1);

        toolBox->addItem(page_3, QString::fromUtf8("Lights"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 230, 546));
        showHBB = new QCheckBox(page_2);
        showHBB->setObjectName(QString::fromUtf8("showHBB"));
        showHBB->setGeometry(QRect(0, 10, 219, 22));
        groupBox_5 = new QGroupBox(page_2);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(0, 50, 221, 84));
        groupBox_5->setFont(font);
        groupBox_5->setStyleSheet(QString::fromUtf8("QGroupBox::title { \n"
"   \n"
"     subcontrol-position: top left; /* position at the top left*/ \n"
"  padding: 2px 13px;\n"
"   margin-top: -5px;\n"
"    \n"
" }\n"
"\n"
"QGroupBox{\n"
"   border: 1px solid rgb(182, 181, 179);\n"
"  border-radius: 5px;\n"
"}"));
        gridLayout_12 = new QGridLayout(groupBox_5);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        label_37 = new QLabel(groupBox_5);
        label_37->setObjectName(QString::fromUtf8("label_37"));

        horizontalLayout_21->addWidget(label_37);

        radiusDOF = new QDoubleSpinBox(groupBox_5);
        radiusDOF->setObjectName(QString::fromUtf8("radiusDOF"));

        horizontalLayout_21->addWidget(radiusDOF);


        gridLayout_12->addLayout(horizontalLayout_21, 0, 0, 1, 1);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_38 = new QLabel(groupBox_5);
        label_38->setObjectName(QString::fromUtf8("label_38"));

        horizontalLayout_20->addWidget(label_38);

        focalDOF = new QDoubleSpinBox(groupBox_5);
        focalDOF->setObjectName(QString::fromUtf8("focalDOF"));

        horizontalLayout_20->addWidget(focalDOF);


        gridLayout_12->addLayout(horizontalLayout_20, 1, 0, 1, 1);

        toolBox->addItem(page_2, QString::fromUtf8("Scene"));
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        page_4->setGeometry(QRect(0, 0, 98, 28));
        layoutWidget = new QWidget(page_4);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 10, 221, 129));
        verticalLayout_6 = new QVBoxLayout(layoutWidget);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_18 = new QLabel(layoutWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_5->addWidget(label_18);

        numSamples = new QSpinBox(layoutWidget);
        numSamples->setObjectName(QString::fromUtf8("numSamples"));
        numSamples->setMinimum(1);
        numSamples->setMaximum(500);

        horizontalLayout_5->addWidget(numSamples);


        verticalLayout_6->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_19 = new QLabel(layoutWidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_6->addWidget(label_19);

        proportion = new QSpinBox(layoutWidget);
        proportion->setObjectName(QString::fromUtf8("proportion"));
        proportion->setMinimum(25);
        proportion->setMaximum(500);
        proportion->setSingleStep(5);
        proportion->setValue(100);

        horizontalLayout_6->addWidget(proportion);


        verticalLayout_6->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        btnRender = new QPushButton(layoutWidget);
        btnRender->setObjectName(QString::fromUtf8("btnRender"));
        btnRender->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_7->addWidget(btnRender);

        progressRender = new QProgressBar(layoutWidget);
        progressRender->setObjectName(QString::fromUtf8("progressRender"));
        progressRender->setValue(0);

        horizontalLayout_7->addWidget(progressRender);


        verticalLayout_6->addLayout(horizontalLayout_7);

        toolBox->addItem(page_4, QString::fromUtf8("Render Options"));

        gridLayout_4->addWidget(toolBox, 0, 0, 1, 1);

        scrollArea_3->setWidget(scrollAreaWidgetContents_3);

        gridLayout_9->addWidget(scrollArea_3, 0, 3, 1, 1);


        verticalLayout->addLayout(gridLayout_9);

        scrollAreaBottom = new QScrollArea(centralWidget);
        scrollAreaBottom->setObjectName(QString::fromUtf8("scrollAreaBottom"));
        scrollAreaBottom->setMinimumSize(QSize(0, 100));
        scrollAreaBottom->setMaximumSize(QSize(16777215, 100));
        scrollAreaBottom->setFrameShape(QFrame::NoFrame);
        scrollAreaBottom->setFrameShadow(QFrame::Plain);
        scrollAreaBottom->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 893, 100));
        groupBox = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 321, 80));
        groupBox->setFont(font);
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox::title { \n"
"   \n"
"     subcontrol-position: top left; /* position at the top left*/ \n"
"  padding: 2px 13px;\n"
"   margin-top: -5px;\n"
"    \n"
" }\n"
"\n"
"QGroupBox{\n"
"   border: 1px solid rgb(182, 181, 179);\n"
"  border-radius: 5px;\n"
"}"));
        dEyex = new QDoubleSpinBox(groupBox);
        dEyex->setObjectName(QString::fromUtf8("dEyex"));
        dEyex->setGeometry(QRect(70, 10, 78, 21));
        dEyex->setMinimum(-9000);
        dEyex->setMaximum(9000);
        dEyey = new QDoubleSpinBox(groupBox);
        dEyey->setObjectName(QString::fromUtf8("dEyey"));
        dEyey->setGeometry(QRect(150, 10, 78, 21));
        dEyey->setMinimum(-9000);
        dEyey->setMaximum(9000);
        dEyez = new QDoubleSpinBox(groupBox);
        dEyez->setObjectName(QString::fromUtf8("dEyez"));
        dEyez->setGeometry(QRect(230, 10, 78, 21));
        QFont font1;
        font1.setPointSize(11);
        dEyez->setFont(font1);
        dEyez->setMinimum(-9000);
        dEyez->setMaximum(9000);
        dAtx = new QDoubleSpinBox(groupBox);
        dAtx->setObjectName(QString::fromUtf8("dAtx"));
        dAtx->setGeometry(QRect(70, 30, 78, 21));
        dAtx->setMinimum(-9000);
        dAtx->setMaximum(9000);
        dAty = new QDoubleSpinBox(groupBox);
        dAty->setObjectName(QString::fromUtf8("dAty"));
        dAty->setGeometry(QRect(150, 30, 78, 21));
        dAty->setMinimum(-9000);
        dAty->setMaximum(9000);
        dAtz = new QDoubleSpinBox(groupBox);
        dAtz->setObjectName(QString::fromUtf8("dAtz"));
        dAtz->setGeometry(QRect(230, 30, 78, 21));
        dAtz->setMinimum(-9000);
        dAtz->setMaximum(9000);
        dUpx = new QDoubleSpinBox(groupBox);
        dUpx->setObjectName(QString::fromUtf8("dUpx"));
        dUpx->setGeometry(QRect(70, 50, 78, 21));
        dUpx->setMaximum(1);
        dUpy = new QDoubleSpinBox(groupBox);
        dUpy->setObjectName(QString::fromUtf8("dUpy"));
        dUpy->setGeometry(QRect(150, 50, 78, 21));
        dUpy->setMaximum(1);
        dUpz = new QDoubleSpinBox(groupBox);
        dUpz->setObjectName(QString::fromUtf8("dUpz"));
        dUpz->setGeometry(QRect(230, 50, 78, 21));
        dUpz->setMaximum(1);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 66, 17));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 30, 66, 17));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 50, 66, 17));
        groupBox_2 = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(340, 10, 191, 80));
        groupBox_2->setFont(font);
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox::title { \n"
"   \n"
"     subcontrol-position: top left; /* position at the top left*/ \n"
"  padding: 2px 13px;\n"
"   margin-top: -5px;\n"
"    \n"
" }\n"
"\n"
"QGroupBox{\n"
"   border: 1px solid rgb(182, 181, 179);\n"
"  border-radius: 5px;\n"
"}"));
        anglePerspective = new QDoubleSpinBox(groupBox_2);
        anglePerspective->setObjectName(QString::fromUtf8("anglePerspective"));
        anglePerspective->setGeometry(QRect(70, 10, 120, 21));
        anglePerspective->setMinimum(5);
        anglePerspective->setMaximum(180);
        nearPerspective = new QDoubleSpinBox(groupBox_2);
        nearPerspective->setObjectName(QString::fromUtf8("nearPerspective"));
        nearPerspective->setGeometry(QRect(70, 30, 120, 21));
        nearPerspective->setMinimum(0.01);
        nearPerspective->setMaximum(100);
        farPerspective = new QDoubleSpinBox(groupBox_2);
        farPerspective->setObjectName(QString::fromUtf8("farPerspective"));
        farPerspective->setGeometry(QRect(70, 50, 120, 21));
        farPerspective->setMinimum(0.01);
        farPerspective->setMaximum(1e+07);
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 10, 66, 17));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 30, 66, 17));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 50, 66, 17));
        groupBox_3 = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(540, 10, 141, 80));
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(true);
        font2.setUnderline(false);
        font2.setWeight(75);
        font2.setStrikeOut(false);
        font2.setKerning(true);
        groupBox_3->setFont(font2);
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox::title { \n"
"   \n"
"     subcontrol-position: top left; /* position at the top left*/ \n"
"  padding: 2px 13px;\n"
"   margin-top: -5px;\n"
"    \n"
" }\n"
"\n"
"QGroupBox{\n"
"   border: 1px solid rgb(182, 181, 179);\n"
"  border-radius: 5px;\n"
"}"));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 10, 66, 17));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 30, 66, 17));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 50, 66, 17));
        sizeGrid = new QSpinBox(groupBox_3);
        sizeGrid->setObjectName(QString::fromUtf8("sizeGrid"));
        sizeGrid->setGeometry(QRect(80, 10, 60, 21));
        sizeGrid->setMinimum(0);
        sizeGrid->setMaximum(900);
        sizeGrid->setValue(20);
        height_l = new QLabel(groupBox_3);
        height_l->setObjectName(QString::fromUtf8("height_l"));
        height_l->setGeometry(QRect(80, 30, 66, 17));
        width_l = new QLabel(groupBox_3);
        width_l->setObjectName(QString::fromUtf8("width_l"));
        width_l->setGeometry(QRect(80, 50, 66, 17));
        scrollAreaBottom->setWidget(scrollAreaWidgetContents_2);

        verticalLayout->addWidget(scrollAreaBottom);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 913, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuObject = new QMenu(menuBar);
        menuObject->setObjectName(QString::fromUtf8("menuObject"));
        menuLights = new QMenu(menuBar);
        menuLights->setObjectName(QString::fromUtf8("menuLights"));
        menuObject_2 = new QMenu(menuLights);
        menuObject_2->setObjectName(QString::fromUtf8("menuObject_2"));
        menuLight = new QMenu(menuLights);
        menuLight->setObjectName(QString::fromUtf8("menuLight"));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuObject->menuAction());
        menuBar->addAction(menuLights->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menuObject->addAction(actionGrid);
        menuObject->addAction(actionPropertiesScene);
        menuLights->addAction(menuObject_2->menuAction());
        menuLights->addAction(menuLight->menuAction());
        menuLights->addSeparator();
        menuObject_2->addAction(actionCube);
        menuObject_2->addAction(actionCone);
        menuObject_2->addAction(actionCylinder);
        menuObject_2->addAction(actionHemisphere);
        menuObject_2->addAction(actionPrism);
        menuObject_2->addAction(actionSphere);
        menuLight->addSeparator();
        menuLight->addAction(actionArea);
        menuLight->addAction(actionDirectional);
        menuLight->addAction(actionPontual);
        menuLight->addAction(actionSpot);
        menuOptions->addAction(actionScreenShot);
        menuOptions->addAction(actionScreanShot_Render);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        toolBox->setCurrentIndex(2);
        toolBox->layout()->setSpacing(6);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Ray Tracing by Danilo Borges", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionGrid->setText(QApplication::translate("MainWindow", "Grid", 0, QApplication::UnicodeUTF8));
        actionGrid->setShortcut(QApplication::translate("MainWindow", "G", 0, QApplication::UnicodeUTF8));
        actionPropertiesScene->setText(QApplication::translate("MainWindow", "Properties Scene", 0, QApplication::UnicodeUTF8));
        actionPropertiesScene->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", 0, QApplication::UnicodeUTF8));
        actionCube->setText(QApplication::translate("MainWindow", "Cube", 0, QApplication::UnicodeUTF8));
        actionCube->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        actionCylinder->setText(QApplication::translate("MainWindow", "Cylinder", 0, QApplication::UnicodeUTF8));
        actionCylinder->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", 0, QApplication::UnicodeUTF8));
        actionHemisphere->setText(QApplication::translate("MainWindow", "Hemisphere", 0, QApplication::UnicodeUTF8));
        actionHemisphere->setShortcut(QApplication::translate("MainWindow", "Ctrl+H", 0, QApplication::UnicodeUTF8));
        actionPrism->setText(QApplication::translate("MainWindow", "Prism", 0, QApplication::UnicodeUTF8));
        actionPrism->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", 0, QApplication::UnicodeUTF8));
        actionSphere->setText(QApplication::translate("MainWindow", "Sphere", 0, QApplication::UnicodeUTF8));
        actionSphere->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionArea->setText(QApplication::translate("MainWindow", "Area", 0, QApplication::UnicodeUTF8));
        actionArea->setShortcut(QApplication::translate("MainWindow", "Shift+A", 0, QApplication::UnicodeUTF8));
        actionDirectional->setText(QApplication::translate("MainWindow", "Directional", 0, QApplication::UnicodeUTF8));
        actionDirectional->setShortcut(QApplication::translate("MainWindow", "Shift+D", 0, QApplication::UnicodeUTF8));
        actionPontual->setText(QApplication::translate("MainWindow", "Pontual", 0, QApplication::UnicodeUTF8));
        actionPontual->setShortcut(QApplication::translate("MainWindow", "Shift+P", 0, QApplication::UnicodeUTF8));
        actionSpot->setText(QApplication::translate("MainWindow", "Spot", 0, QApplication::UnicodeUTF8));
        actionSpot->setShortcut(QApplication::translate("MainWindow", "Shift+S", 0, QApplication::UnicodeUTF8));
        actionGlossy_Reflection->setText(QApplication::translate("MainWindow", "Glossy Reflection", 0, QApplication::UnicodeUTF8));
        actionGlossy_Refraction->setText(QApplication::translate("MainWindow", "Glossy Refraction", 0, QApplication::UnicodeUTF8));
        actionMotion_Blur->setText(QApplication::translate("MainWindow", "Motion Blur", 0, QApplication::UnicodeUTF8));
        actionDepth_of_Field->setText(QApplication::translate("MainWindow", "Depth of Field", 0, QApplication::UnicodeUTF8));
        actionScreenShot->setText(QApplication::translate("MainWindow", "ScreenShot OpenGL", 0, QApplication::UnicodeUTF8));
        actionScreenShot->setShortcut(QApplication::translate("MainWindow", "Alt+S", 0, QApplication::UnicodeUTF8));
        actionScreanShot_Render->setText(QApplication::translate("MainWindow", "ScreenShot Render", 0, QApplication::UnicodeUTF8));
        actionCone->setText(QApplication::translate("MainWindow", "Cone", 0, QApplication::UnicodeUTF8));
        actionCone->setShortcut(QApplication::translate("MainWindow", "Ctrl+E", 0, QApplication::UnicodeUTF8));
        groupBoxPropertiesObj->setTitle(QApplication::translate("MainWindow", "Properties Object", 0, QApplication::UnicodeUTF8));
        ambMaterial->setText(QApplication::translate("MainWindow", "amb", 0, QApplication::UnicodeUTF8));
        diffMaterial->setText(QApplication::translate("MainWindow", "diff", 0, QApplication::UnicodeUTF8));
        speMaterial->setText(QApplication::translate("MainWindow", "spe", 0, QApplication::UnicodeUTF8));
        selectedObj->setText(QApplication::translate("MainWindow", "Select", 0, QApplication::UnicodeUTF8));
        enableObj->setText(QApplication::translate("MainWindow", "Enable", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Name", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "Scale", 0, QApplication::UnicodeUTF8));
        loadTexture->setText(QApplication::translate("MainWindow", "Add Texture", 0, QApplication::UnicodeUTF8));
        materialobject->clear();
        materialobject->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "NO DEFINE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "EMERALD", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "JADE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "OBSIDIAN", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "PEARL", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "RUBY", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "TURQUOSIE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "BRONZE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "BRONZE POLIERT", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "CHROME", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "GOLD", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "GOLD POLIERT", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "COPPER", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "COPPER POLIERT", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "BRASS", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "SILVER", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "SILVER POLIERT", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ZINN", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "GUMMI", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "PLASTIC", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "BLACK PLASTIC", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "CYAN PLASTIC", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "GREEN PLASTIC", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "RED PLASTIC", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "WHITE PLASTIC", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "YELLOW PLASTIC", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "BLACK RUBBER", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "CYAN RUBBER", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "GREEN RUBBER", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "RED RUBBER", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "WHITE RUBBER", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "YELLOW RUBBER", 0, QApplication::UnicodeUTF8)
        );
        transx->setPrefix(QApplication::translate("MainWindow", "x : ", 0, QApplication::UnicodeUTF8));
        transx->setSuffix(QString());
        transy->setPrefix(QApplication::translate("MainWindow", "y : ", 0, QApplication::UnicodeUTF8));
        transz->setPrefix(QApplication::translate("MainWindow", "z : ", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Effects", 0, QApplication::UnicodeUTF8));
        label_35->setText(QApplication::translate("MainWindow", "Glossy Reflection", 0, QApplication::UnicodeUTF8));
        label_34->setText(QApplication::translate("MainWindow", "Glossy Refraction", 0, QApplication::UnicodeUTF8));
        label_33->setText(QApplication::translate("MainWindow", "Reflection", 0, QApplication::UnicodeUTF8));
        label_32->setText(QApplication::translate("MainWindow", "Refraction", 0, QApplication::UnicodeUTF8));
        xmotion->setPrefix(QApplication::translate("MainWindow", "x: ", 0, QApplication::UnicodeUTF8));
        ymotion->setPrefix(QApplication::translate("MainWindow", "y: ", 0, QApplication::UnicodeUTF8));
        zmotion->setPrefix(QApplication::translate("MainWindow", "z: ", 0, QApplication::UnicodeUTF8));
        label_36->setText(QApplication::translate("MainWindow", "Motion Blur", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "Shininess", 0, QApplication::UnicodeUTF8));
        rotx->setPrefix(QApplication::translate("MainWindow", "x : ", 0, QApplication::UnicodeUTF8));
        roty->setPrefix(QApplication::translate("MainWindow", "y : ", 0, QApplication::UnicodeUTF8));
        rotz->setPrefix(QApplication::translate("MainWindow", "z : ", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "Ambient", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "Diffuse", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindow", "Specular", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "Translate", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "Rotate", 0, QApplication::UnicodeUTF8));
        deleteObj->setText(QApplication::translate("MainWindow", "Delete", 0, QApplication::UnicodeUTF8));
        scalex->setPrefix(QApplication::translate("MainWindow", "x : ", 0, QApplication::UnicodeUTF8));
        scaley->setPrefix(QApplication::translate("MainWindow", "y : ", 0, QApplication::UnicodeUTF8));
        scalez->setPrefix(QApplication::translate("MainWindow", "z : ", 0, QApplication::UnicodeUTF8));
        groupBoxPropertieLight->setTitle(QApplication::translate("MainWindow", "Properties Light", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindow", "Name", 0, QApplication::UnicodeUTF8));
        selectedLight->setText(QApplication::translate("MainWindow", "Select", 0, QApplication::UnicodeUTF8));
        visibleLight->setText(QApplication::translate("MainWindow", "Visible", 0, QApplication::UnicodeUTF8));
        enableLight->setText(QApplication::translate("MainWindow", "Enable", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MainWindow", "Position", 0, QApplication::UnicodeUTF8));
        positionxLight->setPrefix(QApplication::translate("MainWindow", "x : ", 0, QApplication::UnicodeUTF8));
        positionyLight->setPrefix(QApplication::translate("MainWindow", "y : ", 0, QApplication::UnicodeUTF8));
        positionzLight->setPrefix(QApplication::translate("MainWindow", "z : ", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MainWindow", "Direction", 0, QApplication::UnicodeUTF8));
        directionxLight->setPrefix(QApplication::translate("MainWindow", "x : ", 0, QApplication::UnicodeUTF8));
        directionyLight->setPrefix(QApplication::translate("MainWindow", "y : ", 0, QApplication::UnicodeUTF8));
        directionzLight->setPrefix(QApplication::translate("MainWindow", "z : ", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("MainWindow", "Vec A", 0, QApplication::UnicodeUTF8));
        vecAx->setPrefix(QApplication::translate("MainWindow", "x : ", 0, QApplication::UnicodeUTF8));
        vecAy->setPrefix(QApplication::translate("MainWindow", "y : ", 0, QApplication::UnicodeUTF8));
        vecAz->setPrefix(QApplication::translate("MainWindow", "z : ", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("MainWindow", "Vec B", 0, QApplication::UnicodeUTF8));
        vecBx->setPrefix(QApplication::translate("MainWindow", "x : ", 0, QApplication::UnicodeUTF8));
        vecBy->setPrefix(QApplication::translate("MainWindow", "y : ", 0, QApplication::UnicodeUTF8));
        vecBz->setPrefix(QApplication::translate("MainWindow", "z : ", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("MainWindow", "Attenuation", 0, QApplication::UnicodeUTF8));
        attenuationcLight->setPrefix(QApplication::translate("MainWindow", "c : ", 0, QApplication::UnicodeUTF8));
        attenuationlLight->setPrefix(QApplication::translate("MainWindow", "l : ", 0, QApplication::UnicodeUTF8));
        attenuationqLight->setPrefix(QApplication::translate("MainWindow", "q : ", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("MainWindow", "Ambient", 0, QApplication::UnicodeUTF8));
        ambMaterial_2->setText(QApplication::translate("MainWindow", "amb", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("MainWindow", "   Diffuse", 0, QApplication::UnicodeUTF8));
        diffMaterial_2->setText(QApplication::translate("MainWindow", "diff", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("MainWindow", "Specular", 0, QApplication::UnicodeUTF8));
        speMaterial_2->setText(QApplication::translate("MainWindow", "spe", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("MainWindow", "Angle", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("MainWindow", "Inner Angle", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("MainWindow", "Exp", 0, QApplication::UnicodeUTF8));
        deleteLight->setText(QApplication::translate("MainWindow", "Delete", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabOpenGL), QApplication::translate("MainWindow", "OpenGL", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabRender), QApplication::translate("MainWindow", "Render", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("MainWindow", "Objects", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(page_3), QApplication::translate("MainWindow", "Lights", 0, QApplication::UnicodeUTF8));
        showHBB->setText(QApplication::translate("MainWindow", "Show HBB", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Effect Depth of Field", 0, QApplication::UnicodeUTF8));
        label_37->setText(QApplication::translate("MainWindow", "Radius", 0, QApplication::UnicodeUTF8));
        label_38->setText(QApplication::translate("MainWindow", "Focal Length", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("MainWindow", "Scene", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindow", "Samples", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindow", "Out Proportion", 0, QApplication::UnicodeUTF8));
        proportion->setSuffix(QApplication::translate("MainWindow", "%", 0, QApplication::UnicodeUTF8));
        btnRender->setText(QApplication::translate("MainWindow", "Render", 0, QApplication::UnicodeUTF8));
        progressRender->setFormat(QApplication::translate("MainWindow", "%p% Done!", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(page_4), QApplication::translate("MainWindow", "Render Options", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Camera", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Eye", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "At", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Up", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Perspective", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Angle", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Near", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Far", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Info", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Size Grid", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Height", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Width", 0, QApplication::UnicodeUTF8));
        height_l->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        width_l->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuObject->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
        menuLights->setTitle(QApplication::translate("MainWindow", "Add", 0, QApplication::UnicodeUTF8));
        menuObject_2->setTitle(QApplication::translate("MainWindow", "Object", 0, QApplication::UnicodeUTF8));
        menuLight->setTitle(QApplication::translate("MainWindow", "Light", 0, QApplication::UnicodeUTF8));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Options", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
