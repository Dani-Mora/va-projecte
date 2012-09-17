#ifndef LIGHT_H
#define LIGHT_H

#include "point.h"
#include <iostream>
#include <QtOpenGL/qgl.h>

using namespace std;

class Light
{
private:
    Point pos;
    GLfloat amb[4];
    GLfloat dif[4];
    GLfloat spec[4];
    bool usada; // ens diu si està en ús o en espera de ser assignada
    bool encesa;
    int idObj; // ens diu la id de l'objecte que te associat. Si no en té, -1

public:
    Light();
    void Render();
    Point getPos();
    void setPos(Point p);
    GLfloat* getAmb();
    GLfloat* getDif();
    GLfloat* getSpec();
    void setAmb(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
    void setDif(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
    void setSpec(GLfloat r, GLfloat g, GLfloat b, GLfloat a);

    void setObject(int a);
    int getObject();
    bool getUsada();
    void setUsada(bool b);
    bool getEncesa();
    void setEncesa(bool b);
};

#endif // LIGHT_H
