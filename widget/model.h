#ifndef _MODEL_H_
#define _MODEL_H_

#include <stdio.h>
#include <vector>
#include "vertex.h"
#include "box.h"
#include "face.h"
#include "material_lib.h"


using namespace std;

// Model - permet representar un objecte 3D
class Model
{
 public:
  Model(std::string);

  // llegeix un model en format OBJ
  void readObj(const char* filename, MaterialLib& matlib);

  // calcula la capsa del model
  void updateBoundingBox();

  // retorna la capsa del model (previament s'ha d'haver calculat)
  Box boundingBox() const;

  // Rendering
  void RenderColor();
  void RenderLight();
  void RenderColorFals(int id);

  // Vertex Arrays
  float *vertexs;
  float *normals;
  float *colors;
  int vertexNumber;
  void RenderVA();
  void initVertexArray();

  // VBO
  void renderVBO();
  void initVBO();

  void setCaraSel(int c);
  int caraSel;

 private:
  void make_face ( char **words, int nwords, int material );
  void netejaDades ();
  void computeNormals();
  void printVertexArray();

 public:
  vector<Vertex> vertices;  // vector amb els vertexs de l'objecte
  vector<Face> faces;       // vector amb les cares de l'objecte

 private:
  std::string name;
  Box _boundingBox;   // caixa contenidora de l'objecte.
  unsigned int vertexBufferID;
  unsigned int normalBufferID;
  unsigned int colorBufferID;
};


#endif
