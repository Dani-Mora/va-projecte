#ifndef LABERINT_H
#define LABERINT_H
#include <vector>
#include "point.h"
#include <QtOpenGL/qgl.h>
#include "model.h"
#include "box.h"
#include "labPlacement.h"

class Laberint
{

#define PRECISIO_RANDOM 100

#define DEFAULT_WIDTH 10
#define DEFAULT_HEIGHT 10

#define TILE_SIZE 1
#define PARET_HEIGHT 1
#define TERRA_HEIGHT 0.25

#define TERRA 0
#define PARET 1

 private:

 // Atributs laberint
 int _width;
 int _height;
 float _rad;
 Box _boundingBox;
 Point _center;


 //Estructures de dades auxiliars
 vector< vector<int> > _laberint;


 void PintaCaixa (Point &posini, Point &posfi);

public:

  // Constructores
  Laberint ();
  Laberint (const int& width, const int& height, const int& seed);

  // Modificadores
  void update(const int& width, const int& height, const int& seed);
  void swapTile (int i, int j);

  // Consultores
  float getRadiContentSphere();
  bool isWalkable(Point pos);
  Point getCenter();
  Point getCenterTile();
  float getTileSize();
  Point getRandomLocation(int seed);
  Point tileToPosition(int i, int j);
  int positionToXTile (Point pos);
  int positionToYTile (Point pos);
  // Mètodes de Render
  void Render(bool lighting);
  void fakeColorRender();

};


#endif // LABERINT_H
