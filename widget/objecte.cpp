#include "objecte.h"
#include "box.h"
#include <QtOpenGL/qgl.h>
#include "scene.h"
#include "math.h"

Objecte::Objecte(std::string n, Point p, float scl, float ori):
  nom(n), pos(p), scale(scl), orientation(ori)
{
}

Objecte::~Objecte(void)
{
}

std::string nom;
float scale;	   // mida en unitats
float orientation;  //orientaci respecte Y

void Objecte::calcularCapsa(Model &modelObj)
{
    Box t = modelObj.boundingBox();
    // Calculo factor d'escalat
    float major = max(abs(t.minb.x - t.maxb.x), abs(t.minb.z - t.maxb.z));
    factorEscalar = scale/ major;

    // Calculo moviment per centrar
    Point move;
    move.x = -((t.maxb.x - t.minb.x)/2 + t.minb.x);
    move.y = -t.minb.y;
    move.z = -((t.maxb.z - t.minb.z)/2 + t.minb.z);

    // Calculo la capsa propia de l'ibjecte
    capsa.minb = (t.minb + move) * factorEscalar + pos;
    capsa.maxb = (t.maxb + move) * factorEscalar + pos;

    // Calculem el centre de la capsa contenidora
    float puntX, puntY, puntZ;
    puntX = ((capsa.maxb.x - capsa.minb.x)/2) + capsa.minb.x;
    puntY = ((capsa.maxb.y - capsa.minb.y)/2) + capsa.minb.y;
    puntZ = ((capsa.maxb.z - capsa.minb.z)/2) + capsa.minb.z;
    centre = Point(puntX,puntY,puntZ);

    // Calculem radi de l'esfera contenidora
    Point punt = capsa.maxb;
    float aux = (centre.x - punt.x)*(centre.x - punt.x) + (centre.y - punt.y)*(centre.y - punt.y) + (centre.z - punt.z)*(centre.z - punt.z);

    radi = sqrt(aux);

}

/*  RENDERING */

void Objecte::Render(Model &modelObj, int mode)
{

    glMatrixMode(GL_MODELVIEW);

    Box t = modelObj.boundingBox();

    // Calculo moviment per centrar
    Point move;
    move.x = -((t.maxb.x - t.minb.x)/2 + t.minb.x);
    move.y = -t.minb.y;
    move.z = -((t.maxb.z - t.minb.z)/2 + t.minb.z);

    glPushMatrix();
    glTranslatef(pos.x, pos.y, pos.z);
    glRotatef(orientation, 0.0, 1.0, 0.0);
    glScaled(factorEscalar, factorEscalar, factorEscalar);
    glTranslatef(move.x, move.y, move.z);

    if (mode == 0) modelObj.RenderColor();
    else if (mode == 1) modelObj.RenderColorFals(this->getId());
    else if (mode == 2) modelObj.RenderVertexArray();
    else if (mode == 3) modelObj.RenderVBO();
    else modelObj.RenderLight();

    modelObj.boundingBox().Render();
    glPopMatrix();

    // la capsa es calcula be pero no es rota be :_
}

std::string Objecte::getNom()
{
  return nom;
}

Point Objecte::getPosition()
{
   return pos;
}

float Objecte::getScale()
{
   return scale;
}

float Objecte::getOrientation()
{
   return orientation;
}

void Objecte::setOrientation(float orien)
{
    this->orientation = orien;
}


Point Objecte::getCentre()
{
    return centre;

}

float Objecte::getRadi()
{
    return radi;

}

Box Objecte::getCapsa()
{
    return capsa;
}

void Objecte::moureObjecte(Point nou)
{
    Point moviment = Point(nou.x - pos.x, nou.y - pos.y, nou.z - pos.z);

    // Recalculo capsa contenidora
    capsa.minb += moviment;
    capsa.maxb += moviment;  

    // fi codi //
    pos = nou;
}

/* Id */

void Objecte::setId(unsigned int id)
{
    this->id = id;
}

unsigned int Objecte::getId()
{
    return this->id;
}
