#ifndef _Scene_H_
#define _Scene_H_
#include "model.h"
#include "object.h"
#include <QtOpenGL/qgl.h>
#include "laberint.h"
#include <string>
#include "light.h"

class Scene
{
 private:
	
  // Dades de l'escena

#define LAB_WIDTH 10
#define LAB_HEIGHT 10
#define SEED 3
#define ENEMICS 3
#define ROTATION 0
#define LIGHTING true
#define FOCUSRED 0.6
#define FOCUSGREEN 0.6
#define FOCUSBLUE 0.6
#define SPOTRED 0.6
#define SPOTGREEN 0.6
#define SPOTBLUE 0
#define AMBIENTRED 1
#define AMBIENTGREEN 1
#define AMBIENTBLUE 1
    // inici codi --
#define POINTRED 0.8
#define POINTGREEN 0.8
#define POINTBLUE 0
    // fi
#define AMBIENTENABLED true
#define SPOTENABLED true
#define FOCUSENABLED true
#define SPOTANGLE 45
#define NOMBREMODELS 2


 public:
  Laberint _lab;

  static MaterialLib matlib;	  // col·lecció de materials

  std::vector<Model> models;
  std::vector<Object> modelInstance;
  std::vector<Object> _cubeInstance;
  int nombreEnemics;
  int labSize;
  int _initialRotation;
  int modRefresh;
  bool _gameOver;
  bool _pause;
  bool _firstPerson;
  bool _lighting;
  bool _loadEnemies;
  bool _loadMainCharacter;
  bool _loadMainModel;
  bool _loadEnemieModel;

  Light _focus;
  Light _spot;
  Light _ambient;
  Light _point;


  Scene();
  ~Scene();

  void Render();
  void InitializeScene ();
  Point getCenter();
  float getRadi();
  void loadMainCharacter(const char *name);
  void setMainCharacter();
  void loadEnemies(const char* fileName);
  void start();
  void pausaJoc();
  void resume();
  bool pause();
  void keyDown();
  void keyUp();
  void keyLeft();
  void keyRight();
  void keyX();
  void setRotationDreta();
  void setRotationEsquerra();
  void setRotationAmunt();
  void setRotationAvall();
  void refresh();
  bool gameOver();
  void setEnemies(int num);
  void setLaberint (int tamany);
  void aturaJoc();
  void fakeColorRender();
  void swapTile(int i, int j);
  bool isInContact (Object& model, int ownIndex, float precisionOffset);
  Point getMainCharacterPosition();
  float getMainCharacterOrientation();
  void setFirstPerson (bool mode);
  void initAmbientalLight();
  void initFocus();

  void enableAmbientalLight();
  void disableAmbientalLight();
  void enableSpot();
  void disableSpot();
  void enableFocus();
  void disableFocus();

  void setFocusZ(float z);
  void setFocusX(float x);
  void setGreenFocus(float x);
  void setRedFocus(float x);
  void setBlueFocus(float x);
  void setGreenSpot(float x);
  void setRedSpot(float x);
  void setBlueSpot(float x);
  void setGreenAmbientalLight(float x);
  void setRedAmbientalLight(float x);
  void setBlueAmbientalLight(float x);
  // inici codi --
  void initPointLight();
  void setPointLight();
  void movePointLight();
// fi

private:
  void loadModels();
  bool move(Object &mainCharacter, float distance, bool collision, int ownIndex);
  void rotate(Object &mainCharacter, float angle);
  Point getEnemiePosition(int index);
  bool positionAvailable(Point &pos, int ownIndex);
  void PintaCaixa (Point &posini, Point &posfi);
  void updateFocus();
  void updateSpot();
  void updateAmbient();
  void renderFocus();
  void initSpot();

};

#endif

