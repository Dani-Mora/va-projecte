#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <stdio.h>
#include <vector>
#include "vertex.h"
#include "box.h"
#include "face.h"
#include "material_lib.h"

using namespace std;

// Object - permet representar un objecte 3D
class Model
{
 public:
  Model(std::string);
  Model();
  // llegeix un model en format OBJ
  void readObj(const char* filename, MaterialLib& matlib);

  // calcula la capsa del model
  void updateBoundingBox();

  // retorna la capsa del model (previament s'ha d'haver calculat)
  Box boundingBox() const;

  void RenderFlatMaterial();
  void RenderWithLight();

  std::string getNom();

 private:
  void make_face ( char **words, int nwords, int material );
  void netejaDades ();
  void computeNormals();

 public:
  vector<Vertex> vertices;  // vector amb els vertexs de l'objecte
  vector<Face> faces;       // vector amb les cares de l'objecte

  void modifName (std::string n);

 private: 
  std::string name;
  Box _boundingBox;   // caixa contenidora de l'objecte.
};


#endif
