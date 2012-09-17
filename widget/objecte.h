#ifndef _OBJECTE_H_
#define _OBJECTE_H_
#include <vector>
#include <stdio.h>
#include "point.h"
#include "model.h"
#include "box.h"


using namespace std;

class Objecte
{
 protected:
  std::string nom;
  Point pos;    // posicio sobre el terra
  float scale;	   // mida en unitats
  float orientation;  //orientaci respecte Y
  Point centre;
  float radi; // Radi de l'esfera contenidora
  Box capsa; // Per si l'objecte necessita la seva propia capsa
  float factorEscalar; // factor escalar actual
  int id;

  bool selected;

 public:
  Objecte(std::string nom, Point p, float scl, float ori);
  ~Objecte(void);

  void Render(Model &,int mode);

  void calcularCapsa(Model &);
  std::string getNom();
  Point getPosition();
  float getScale();
  float getOrientation();
  void setOrientation(float orien);

  Box getCapsa();

  void moureObjecte(Point nou);


  Point getCentre();
  float getRadi();

  void setId(unsigned int id);
  unsigned int getId();
};

#endif
