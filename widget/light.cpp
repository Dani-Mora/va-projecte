#include <cmath>
#include <iostream>
#include <QtOpenGL/qgl.h>
#include "light.h"

using namespace std;

Light::Light()
{


}

/* Posició */

void Light::setPos(Point p)
{
    this->pos = p;
}

Point Light::getPos()
{
    return this->pos;
}


/* Getters colors llum */

float* Light::getAmb()
{
    return this->amb;
}

float* Light::getDif()
{
    return this->dif;
}

float* Light::getSpec()
{
    return this->spec;
}

/* Setters colors llum */

void Light::setAmb(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
    this->amb[0] = r;
    this->amb[1] = g;
    this->amb[2] = b;
    this->amb[3] = a;
}

void Light::setDif(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
    this->dif[0] = r;
    this->dif[1] = g;
    this->dif[2] = b;
    this->dif[3] = a;
}

void Light::setSpec(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
    this->spec[0] = r;
    this->spec[1] = g;
    this->spec[2] = b;
    this->spec[3] = a;
}


/* Associated object */

void Light::setObject(int id)
{
    this->idObj = id;
}

int Light::getObject()
{
    return this->idObj;
}

/* Used/not used, set in the scene */

bool Light::getUsada()
{
    return this->usada;
}

void Light::setUsada(bool b)
{
    this->usada = b;
}

/* Set but activate or not */

bool Light::getEncesa()
{
    return this->encesa;
}

void Light::setEncesa(bool b)
{
    this->encesa = b;
}


/* Render */

void Light::Render()
{

    glBegin (GL_QUADS);

    if (this->encesa) glColor3f(dif[0], dif[1], dif[2]);
    else glColor3f(0, 0, 0);

    glVertex3f(pos.x -0.1,pos.y-0.1,pos.z -0.1);
    glVertex3f(pos.x +0.1,pos.y-0.1,pos.z -0.1);
    glVertex3f(pos.x +0.1,pos.y-0.1,pos.z +0.1);
    glVertex3f(pos.x -0.1,pos.y-0.1,pos.z +0.1);

    glVertex3f(pos.x -0.1,pos.y+0.1,pos.z +0.1);
    glVertex3f(pos.x +0.1,pos.y+0.1,pos.z +0.1);
    glVertex3f(pos.x +0.1,pos.y+0.1,pos.z -0.1);
    glVertex3f(pos.x -0.1,pos.y+0.1,pos.z -0.1);

    glVertex3f(pos.x +0.1,pos.y+0.1,pos.z -0.1);
    glVertex3f(pos.x +0.1,pos.y+0.1,pos.z +0.1);
    glVertex3f(pos.x +0.1,pos.y-0.1,pos.z +0.1);
    glVertex3f(pos.x +0.1,pos.y-0.1,pos.z -0.1);

    glVertex3f(pos.x -0.1,pos.y-0.1,pos.z -0.1);
    glVertex3f(pos.x -0.1,pos.y-0.1,pos.z +0.1);
    glVertex3f(pos.x -0.1,pos.y+0.1,pos.z +0.1);
    glVertex3f(pos.x -0.1,pos.y+0.1,pos.z -0.1);

    glVertex3f(pos.x -0.1,pos.y-0.1,pos.z +0.1);
    glVertex3f(pos.x +0.1,pos.y-0.1,pos.z +0.1);
    glVertex3f(pos.x +0.1,pos.y+0.1,pos.z +0.1);
    glVertex3f(pos.x -0.1,pos.y+0.1,pos.z +0.1);

    glVertex3f(pos.x -0.1,pos.y+0.1,pos.z -0.1);
    glVertex3f(pos.x +0.1,pos.y+0.1,pos.z -0.1);
    glVertex3f(pos.x +0.1,pos.y-0.1,pos.z -0.1);
    glVertex3f(pos.x -0.1,pos.y-0.1,pos.z -0.1);

    glEnd();
}
