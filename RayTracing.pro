#-------------------------------------------------
#
# Project created by QtCreator 2012-10-13T16:17:40
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = RayTracing
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    interface/glwidget.cpp \
    math/vec4.cpp \
    block/object.cpp \
    math/matrix4x4.cpp \
    block/cube.cpp \
    block/prism.cpp \
    block/cylinder.cpp \
    block/hemisphere.cpp \
    structure/mesh.cpp \
    extra/functions.cpp \
    draw/draw.cpp \
    math/quaternion.cpp \
    interface/scene.cpp \
    structure/light.cpp \
    extra/material.cpp \
    interface/castingwidget.cpp \
    math/ray.cpp \
    math/raycasting.cpp \
    math/rayintersection.cpp \
    block/plane.cpp \
    block/sphere.cpp \
    math/raytracing.cpp \
    block/hbb.cpp \
    extra/effects.cpp


HEADERS  += mainwindow.h \
    interface/glwidget.h \
    math/vec4.h \
    block/object.h \
    math/matrix4x4.h \
    block/cube.h \
    block/prism.h \
    block/cylinder.h \
    block/hemisphere.h \
    structure/mesh.h \
    extra/functions.h \
    draw/draw.h \
    math/quaternion.h \
    interface/scene.h \
    structure/light.h \
    extra/material.h \
    interface/castingwidget.h \
    math/ray.h \
    math/raycasting.h \
    math/rayintersection.h \
    block/plane.h \
    block/sphere.h \
    math/raytracing.h \
    block/hbb.h \
    extra/effects.h


FORMS    += mainwindow.ui

LIBS     += -lGLU -lglut
