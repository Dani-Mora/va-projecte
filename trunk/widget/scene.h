#ifndef _Scene_H_
#define _Scene_H_
#include "objecte.h"
#include "model.h"
#include "light.h"
#include <QtOpenGL/qgl.h>


class Scene
{
 private:

  // Tindrem un model geomètric del polígon base i un model de l'objecte
  // geomètric que es carrega. Tindrem també un vector amb possibles instàncies
  // d'aquest model geomètric carregat (instàncies o referències a l'objecte).
  Model polBase; // terra de la escena
  Model modelObj;
  std::vector<Objecte> lobjectes; //conte vector d'objectes

  /* Esfera contenidora */
  Box capsa; // capsa contenidora de l'escena
  float radi;
  Point centre;

  Light light0;


 public:
  static MaterialLib matlib;	  // col·lecció de materials

  Scene();

  void Init();
  void construirBase();

  /* Renders */
  void RenderColor();
  void RenderLight();
  void RenderBack();
  void RenderVAO();

  void AddOneObject(Objecte &); // afegeix un sol objecte i borra els anterior
  void AddObjecte(Objecte &); // afegeix un objecte mes
  void setModel(Model &);

  Objecte obteObjecte(int num);
  Model getModel();

  /* Calcul escena */
  void calcularCapsa(); // calcula la capsa conetnidora de l'escena
  float getRadi(); // retorna el radi de la capsa contenidora de l'escena
  Point getCentre();
  double getAlturaScene();
  double getRadiObj(int num);

  /* Seleccio */
  void seleccionarCara(int x, int y, int b);
  int seleccionarObjecte(int xClick, int yClick, int height);

  /* Parametres camera primera persona */
  Point eye;
  Point VRP;

  /* Lighting */

  void changeColor0R(int r);
  void changeColor0G(int r);
  void changeColor0B(int r);
  void setLight0Colors(GLfloat r, GLfloat g, GLfloat b);
  float *getLight0Color();

  void initLights();

  bool foraBase(int x, int z);
  void reset();
  int numObjectes();

};

#endif

