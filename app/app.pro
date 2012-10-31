#-------------------------------------------------
#
# Project created by QtCreator 2010-09-29T17:51:16
#
#-------------------------------------------------

QT       += opengl

TARGET = PracticaVIG
TEMPLATE = app

INCLUDEPATH += ../widget ../crono
LIBS += ../widget/libglwidgetplugin.so -lGLEW -lGLU -lGL

SOURCES += main.cpp\
        principal.cpp \
    ../crono/cronometre.cpp

HEADERS  += principal.h \
    ../crono/cronometre.h

FORMS    += principal.ui
