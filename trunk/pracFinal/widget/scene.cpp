#include "scene.h"
#include <math.h>


MaterialLib Scene::matlib;

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::Render()
{
  // Aquí s'ha de pintar l'escena

    _lab.Render(_lighting);

    for (int i = 0; i < modelInstance.size(); ++i) {
        if (i == 0 and !_firstPerson) modelInstance[i].render(_lighting);
        else if (i != 0) modelInstance[i].render(_lighting);
    }
    for (int i = 0; i < _cubeInstance.size(); ++i) {
        _cubeInstance[i].render(_lighting);
    }
    if (_focus.Enabled && _lighting) {
         renderFocus();
    }

}

Point Scene::getCenter() {
    return _lab.getCenter();
}

void Scene::aturaJoc() {
    cout << "GAME OVER" << endl;
    this->disableSpot();
    _gameOver = true;
    _loadEnemies = false;
    _loadMainCharacter = false;
    modelInstance.erase(modelInstance.begin(),modelInstance.end());
    _cubeInstance.erase(_cubeInstance.begin(),_cubeInstance.end());
}

void Scene::pausaJoc() {
    cout << "GAME PAUSED" << endl;
    _pause = true;
}


void Scene::resume() {
    _pause = false;
}

bool Scene::pause() {
    return _pause;
}

float Scene::getRadi() {
    return _lab.getRadiContentSphere();
}

void Scene::setEnemies (int num) {
    nombreEnemics = num;
}

void Scene::setLaberint (int tamany) {
    _lab.update(tamany,tamany, 1);
    this->initFocus();
}

void Scene::InitializeScene () {
    _gameOver = true;
    _pause = false;
    _cubeInstance = vector<Object> (0);
    labSize = LAB_WIDTH;
    nombreEnemics = ENEMICS;
    _initialRotation = ROTATION;
    _lighting = LIGHTING;
    _focus.Enabled = FOCUSENABLED;
    _ambient.Enabled = AMBIENTENABLED;
    _spot.Enabled = SPOTENABLED;
    this->initAmbientalLight();
    this->initFocus();
    _loadMainModel = false;
    _loadEnemieModel = false;
    _loadMainCharacter = false;
    _loadEnemies = false;
}

void Scene::refresh() {

    srand(this->nombreEnemics+this->labSize);

    // Si tots els models estan carregats
    if (_loadEnemies && _loadMainCharacter) {
         //cout << "Starting Refresh" << endl;
        // Si el nombre de refresh es multiple de 4
        if (modRefresh == 0) {

              for (int i = 1; i < modelInstance.size(); ++i) {

               bool aconseguit = false;
               while (!aconseguit) {
                   int random = rand()%10;
                   if (random > 8) {
                       //rotate
                      // cout << "Model " << i << " rotate" << endl;
                       random = rand()%2;
                       if (random == 1) rotate (modelInstance[i],90);
                       else rotate (modelInstance[i],-90);
                       aconseguit = true;
                   }
                   else {
                       //cout << "Model " << i << "try to " << endl;
                       random = rand()%2;
                       if (random == 1) aconseguit = move (modelInstance[i],1, TRUE, -1);
                       else aconseguit = move (modelInstance[i],-1, TRUE, -1);
                       //if (aconseguit) cout << "movement done" << endl;
                       //else cout << "failed to move";
                   }
               }
            }
        }

        // En qualsevol cas, realitza moviment de cubs
        for (int i =0; i < _cubeInstance.size(); ++i) {
            bool movement = move (_cubeInstance[i],0.25, TRUE, 0);
            // El moviment no s'ha pogut realitzar
            if (!movement || isInContact(_cubeInstance[i], 0, 0.75)) {
                 Point center;
                center = _cubeInstance[i].getCenter();
                for (int j = 1; j < this->modelInstance.size(); ++j) {
                    if (_cubeInstance[i].isInContact (modelInstance[j], 0.75)) {
                        cout << "Enemic eliminat" << endl;
                        modelInstance.erase(modelInstance.begin()+j);
                   }
                }
                _cubeInstance.erase(_cubeInstance.begin()+i);
            }
        }
        // Recalcula la llanterna;
        if (this->_spot.Enabled) this->initSpot();


        // Augmenta el modRefresh
        ++modRefresh;
        modRefresh = modRefresh%4;
    }
}


bool Scene::isInContact (Object& model, int ownIndex, float precisionOffset) {
    for (int j = 0; j < this->modelInstance.size(); ++j) {
        if (j != ownIndex && model.isInContact (modelInstance[j], precisionOffset)) {
            return true;
        }
    }
    return false;
}

void Scene::setFirstPerson(bool mode) {
    _firstPerson = mode;
}

bool Scene::gameOver() {
    return _gameOver;
}


void Scene::start () {
    _pause = false;
    _gameOver = false;
}

void Scene::loadMainCharacter (const char *name) {
    Model model(name);
    model.readObj(name, Scene::matlib);    
    if (_loadMainModel) models[0] = model;
    else if (_loadEnemieModel) {
        models.push_back(models[0]);
        models[0] = model;
    }
    else this->models.push_back(model);
    setMainCharacter();
}

void Scene::setMainCharacter() {    
    Object mainCharacter;
    Point pos = _lab.getCenterTile();
    mainCharacter.update(0,models[0],1, 0, _initialRotation,pos);
    mainCharacter.scaleTo(1);
    if (_loadMainCharacter) modelInstance[0] = mainCharacter;
    else if (_loadEnemies) {
        modelInstance.push_back(modelInstance[0]);
        modelInstance[0] = mainCharacter;
    }
    else modelInstance.push_back(mainCharacter);
    if (_lighting) initSpot();
    _loadMainCharacter = true;
    _loadMainModel = true;
}

void Scene::loadEnemies (const char *finalName) {
    Model model(finalName);
    model.readObj(finalName, Scene::matlib);
    this->models.push_back(model);
    for (int i = 0; i < nombreEnemics; ++i) {
        Object enemic;
        int seed = i;
        Point pos;
        while (!this->positionAvailable(pos = _lab.getRandomLocation(seed++), -1));

        enemic.update(i+1,models[models.size()-1],1,0, 0, pos);
        enemic.scaleTo(1);        
        modelInstance.push_back(enemic);
    }
    _loadEnemies = true;
    _loadEnemieModel = true;
}

bool Scene::move(Object &mainCharacter, float distance, bool collision, int ownIndex) {
    Point pos = mainCharacter.getCenter();
    float ori = mainCharacter.getOrientation();

    if (ori == 180) pos.z += distance;
    else if (ori == 0) pos.z -= distance;
    else if (ori == 270) pos.x += distance;
    else if (ori == 90) pos.x -= distance;

    if (_lab.isWalkable(pos) && (positionAvailable(pos, ownIndex) || !collision)) {
        mainCharacter.move(pos);
        return true;
    }
    else if (pos == getMainCharacterPosition() || !(positionAvailable(pos, ownIndex)) && ownIndex == 0) {
        aturaJoc();
        return false;
    }
    else return false;
}

void Scene::rotate(Object &mainCharacter, float angle) {
    mainCharacter.rotate(angle);
}

bool Scene::positionAvailable(Point &pos, int ownIndex) {

    for (int i = 0; i < modelInstance.size(); ++i) {
        if (modelInstance[i].getCenter() == pos and i != ownIndex) {
            //cout << "Retorno false perque " << i << "est`a a la posici´o pos i ownIndex =  " << ownIndex << endl;
            return false;
        }
    }
   // cout<< "Retorno true" << endl;
    return true;

}

void Scene::fakeColorRender() {
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // netejem buffer
    glDrawBuffer(GL_BACK); // indiquem back buffer;

    this->_lab.fakeColorRender();

}

void Scene::swapTile(int i, int j) {
    Point pos = _lab.tileToPosition(i, j);
    bool possible = this->positionAvailable(pos, -1);
    if (possible) {
        cout <<     "swap i = "<< i << "swap j = " << j << endl;
        _lab.swapTile(i, j);
    }
}

Point Scene::getMainCharacterPosition() {
    return modelInstance[0].getCenter();
}

float Scene::getMainCharacterOrientation() {
    return modelInstance[0].getOrientation();
}

Point Scene::getEnemiePosition (int index) {
    return modelInstance[index].getCenter();
}

void Scene::keyDown() {
    move(modelInstance[0], -1, TRUE, 0);
}

void Scene::keyUp() {
    move(modelInstance[0], 1, TRUE, 0);
}

void Scene::keyRight() {
    rotate(modelInstance[0], -90);

}

void Scene::keyLeft() {
    rotate(modelInstance[0], 90);
}

void Scene::keyX() {

    if (_cubeInstance.size() < 1) {
        Object cube;
        //cout << "La posici´o del personatge es: " << modelInstance[0].getCenter() << endl;
        Point pos;
        pos.x = modelInstance[0].getCenter().x;
        pos.y = modelInstance[0].getCenter().y;
        pos.z = modelInstance[0].getCenter().z;
        cube.updateToPrimaryCube(_cubeInstance.size()*10, 0.2, modelInstance[0].getOrientation(), 0, pos);
        _cubeInstance.push_back(cube);
    }
}


void Scene::setRotationDreta() {
    _initialRotation = 0;
    this->setMainCharacter();
}

void Scene::setRotationEsquerra() {
    _initialRotation = 180;
    this->setMainCharacter();
}

void Scene::setRotationAmunt() {
    _initialRotation = 90;
    this->setMainCharacter();
}

void Scene::setRotationAvall() {
    _initialRotation = 270;
    this->setMainCharacter();
}


/*---------------------------------------------------------------------*/

/*------------------- FUNCIONS ILLUMINACIO-----------------------------*/

/*---------------------------------------------------------------------*/

void Scene::initAmbientalLight() {
    if (_ambient.Enabled) enableAmbientalLight();
    _ambient._diffuseRed = AMBIENTRED;
    _ambient._diffuseGreen = AMBIENTGREEN;
    _ambient._diffuseBlue = AMBIENTGREEN;
    _ambient._specularRed = AMBIENTRED;
    _ambient._specularGreen = AMBIENTGREEN;
    _ambient._specularBlue = AMBIENTGREEN;
}

void Scene::initFocus() {

    // Situa el focus
    _focus.pos = this->getCenter();
    _focus.pos.y = 10;

    GLfloat v[4] = {_focus.pos.x, _focus.pos.y, _focus.pos.z, 1};
    glLightfv(GL_LIGHT1, GL_POSITION, v);


    // Posa els colors diffuse i specular segons els parametres
    _focus._diffuseRed = FOCUSRED;
    _focus._diffuseGreen = FOCUSGREEN;
    _focus._diffuseBlue = FOCUSBLUE;
    GLfloat v1[4] = {_focus._diffuseRed, _focus._diffuseGreen, _focus._diffuseBlue, 1};
    glLightfv(GL_LIGHT1, GL_DIFFUSE, v1);

    _focus._specularRed = FOCUSRED;
    _focus._specularGreen = FOCUSGREEN;
    _focus._specularBlue = FOCUSBLUE;
    GLfloat v2[4] = {_focus._specularRed, _focus._specularGreen, _focus._specularBlue, 1};
    glLightfv(GL_LIGHT1, GL_SPECULAR, v2);

    // Posa el color ambient segons el par`ametre estandard
    GLfloat v3[4] = {0, 0, 0, 1};
    glLightfv(GL_LIGHT1, GL_AMBIENT,v3);
    if (_focus.Enabled) glEnable(GL_LIGHT1);

}

void Scene::initSpot() {

    //Localitza el personatge
    this->_spot.pos = modelInstance[0].getCenter();
    this->_spot.pos.y = 0.5;
    GLfloat v[4] = {modelInstance[0].getCenter().x, 0.5, modelInstance[0].getCenter().z, 1};
    glLightfv(GL_LIGHT2, GL_POSITION, v);

    //Calcula el color
    _spot._diffuseRed = SPOTRED;
    _spot._diffuseGreen = SPOTGREEN;
    _spot._diffuseBlue = SPOTBLUE;

    _spot._specularRed = SPOTRED;
    _spot._specularGreen = SPOTGREEN;
    _spot._specularBlue = SPOTBLUE;

    GLfloat v2[4] = {SPOTRED, SPOTGREEN, SPOTBLUE ,1};
    glLightfv(GL_LIGHT2, GL_DIFFUSE, v2);
    glLightfv(GL_LIGHT2, GL_SPECULAR, v2);

    _spot._ambientRed = 0;
    _spot._ambientGreen = 0;
    _spot._ambientBlue = 0;
    GLfloat v3[4] = {0, 0, 0 ,1};
    glLightfv(GL_LIGHT2, GL_AMBIENT,v3);

    //Calcula la direccio del focus
    float orientation = modelInstance[0].getOrientation();
    _spot.orientation = orientation;

    if (orientation == 0) {
        GLfloat v4[4] = {0,0,-1,1};
        glLightfv(GL_LIGHT2,GL_SPOT_DIRECTION,v4);
    }
    else if (orientation == 90) {
        GLfloat v4[4] = {-1,0,0,1};
        glLightfv(GL_LIGHT2,GL_SPOT_DIRECTION,v4);
    }
    else if (orientation == 180) {
        GLfloat v4[4] = {0,0,1,1};
        glLightfv(GL_LIGHT2,GL_SPOT_DIRECTION,v4);
    }
    else {
        GLfloat v4[4] = {1,0,0,1};
        glLightfv(GL_LIGHT2,GL_SPOT_DIRECTION,v4);
    }

    _spot._angle = SPOTANGLE;
    glLightf(GL_LIGHT2,GL_SPOT_CUTOFF,SPOTANGLE);
    if (SPOTENABLED) this->enableSpot();
}

void Scene::enableFocus() {
    _focus.Enabled = true;
    glEnable(GL_LIGHT1);
}

void Scene::disableFocus() {
    _focus.Enabled = false;
    glDisable(GL_LIGHT1);
}

void Scene::enableAmbientalLight() {
    _ambient.Enabled = true;
    glEnable(GL_LIGHT0);
}

void Scene::disableAmbientalLight() {
    _ambient.Enabled = false;
    glDisable(GL_LIGHT0);
}

void Scene::enableSpot() {
    _spot.Enabled = true;
    glEnable(GL_LIGHT2);
}

void Scene::disableSpot() {
    _spot.Enabled = false;
    glDisable(GL_LIGHT2);
}

void Scene::updateFocus() {
    GLfloat v[4] = {_focus.pos.x, _focus.pos.y, _focus.pos.z, 1};
    glLightfv(GL_LIGHT1, GL_POSITION, v);

    GLfloat v1[4] = {_focus._diffuseRed, _focus._diffuseGreen, _focus._diffuseBlue, 1};
    glLightfv(GL_LIGHT1, GL_DIFFUSE, v1);

    GLfloat v2[4] = {_focus._specularRed, _focus._specularGreen, _focus._specularBlue, 1};
    glLightfv(GL_LIGHT1, GL_SPECULAR, v2);
}

void Scene::setFocusX(float x) {
    this->_focus.pos.x = x;
    updateFocus();
}

void Scene::setFocusZ(float z) {
    this->_focus.pos.z = z;
    updateFocus();
}

void Scene::setGreenFocus(float x) {
    this->_focus._diffuseGreen = x;
    this->_focus._specularGreen = x;
    updateFocus();
}

void Scene::setRedFocus(float x) {
    this->_focus._diffuseRed = x;
    this->_focus._specularRed = x;
    updateFocus();
}

void Scene::setBlueFocus(float x) {
    this->_focus._diffuseBlue = x;
    this->_focus._specularBlue = x;
    updateFocus();
}

void Scene::updateAmbient() {
    GLfloat v1[4] = {_ambient._diffuseRed, _ambient._diffuseGreen, _ambient._diffuseBlue, 1};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, v1);

    GLfloat v2[4] = {_ambient._specularRed, _ambient._specularGreen, _ambient._specularBlue, 1};
    glLightfv(GL_LIGHT0, GL_SPECULAR, v2);
}

void Scene::setGreenAmbientalLight(float x) {
    this->_ambient._diffuseGreen = x;
    this->_ambient._specularGreen = x;
    updateAmbient();
}

void Scene::setRedAmbientalLight(float x) {
    this->_ambient._diffuseRed = x;
    this->_ambient._specularRed = x;
    updateAmbient();
}

void Scene::setBlueAmbientalLight(float x) {
    this->_ambient._diffuseBlue = x;
    this->_ambient._specularBlue = x;
    updateAmbient();
}

//inici codi --
void Scene::initPointLight() {

    // Situa el focus
    _point.pos = 0;
    _point.pos.y = 10;

    GLfloat v[4] = {_point.pos.x, _point.pos.y, _point.pos.z, 1};
    glLightfv(GL_LIGHT3, GL_POSITION, v);

    // Posa els colors diffuse i specular segons els parametres
    _point._diffuseRed = POINTRED;
    _point._diffuseGreen = POINTGREEN;
    _point._diffuseBlue = POINTBLUE;
    GLfloat v1[4] = {_point._diffuseRed, _point._diffuseGreen, _point._diffuseBlue, 1};
    glLightfv(GL_LIGHT3, GL_DIFFUSE, v1);

    _focus._specularRed = POINTRED;
    _focus._specularGreen = POINTGREEN;
    _focus._specularBlue = POINTBLUE;
    GLfloat v2[4] = {_point._specularRed, _point._specularGreen, _point._specularBlue, 1};
    glLightfv(GL_LIGHT3, GL_SPECULAR, v2);
}

void Scene::setPointLight() {
    this->disableAmbientalLight();
    this->disableFocus();
    this->disableSpot();

    this->initPointLight();
    glEnable(GL_LIGHT3);
    _point.Enabled = true;

}

void Scene::movePointLight() {
    if (_point.Enabled) {
        if (_point.pos.x == 0 && _point.pos.z == 0) _point.pos.x = this->labSize;
        else if (_point.pos.x != 0 && _point.pos.z != 0) _point.pos.x = 0;
        else if (_point.pos.x != 0 && _point.pos.z == 0) _point.pos.z = this->labSize;
        else _point.pos.z = 0;

        GLfloat v[4] = {_point.pos.x, _point.pos.y, _point.pos.z, 1};
        glLightfv(GL_LIGHT3, GL_POSITION, v);
        }

}

// fi

void Scene::updateSpot() {

    GLfloat v1[4] = {_spot._diffuseRed, _spot._diffuseGreen, _spot._diffuseBlue, 1};
    glLightfv(GL_LIGHT2, GL_DIFFUSE, v1);

    GLfloat v2[4] = {_spot._specularRed, _spot._specularGreen, _spot._specularBlue, 1};
    glLightfv(GL_LIGHT2, GL_SPECULAR, v2);

    GLfloat v3[4] = {_spot._ambientRed, _spot._ambientGreen, _spot._ambientBlue, 1};
    glLightfv(GL_LIGHT2, GL_AMBIENT, v3);
}

void Scene::setGreenSpot(float x) {
    this->_spot._diffuseGreen = x;
    this->_spot._specularGreen = x;
    this->_spot._ambientGreen = x;
    updateSpot();
}

void Scene::setRedSpot(float x) {
    this->_spot._diffuseRed = x;
    this->_spot._specularRed = x;
    this->_spot._ambientRed = x;
    updateSpot();
}

void Scene::setBlueSpot(float x) {
    this->_spot._diffuseBlue = x;
    this->_spot._specularBlue = x;
    this->_spot._ambientBlue = x;
    updateSpot();
}

void Scene::renderFocus () {
    glDisable(GL_LIGHTING);

    Point posini;
    posini.x = _focus.pos.x  - 0.1;
    posini.y = _focus.pos.y  - 0.1;
    posini.z = _focus.pos.z  - 0.1;

    Point posfi;
    posfi.x = _focus.pos.x  + 0.1;
    posfi.y = _focus.pos.y  + 0.1;
    posfi.z = _focus.pos.z  + 0.1;

    glColor3f(_focus._diffuseRed,_focus._diffuseGreen,_focus._diffuseBlue);
    PintaCaixa(posini, posfi);

    glEnable(GL_LIGHTING);
}

void Scene::PintaCaixa (Point &posini, Point &posfi)
{
  glBegin(GL_QUADS);
  glNormal3f(0.0, -1.0, 0.0);
  glVertex3f(posini.x, posini.y, posini.z);
  glVertex3f(posfi.x, posini.y, posini.z);
  glVertex3f(posfi.x, posini.y, posfi.z);
  glVertex3f(posini.x, posini.y, posfi.z);

  glNormal3f(0.0, 1.0, 0.0);
  glVertex3f(posini.x, posfi.y, posini.z);
  glVertex3f(posini.x, posfi.y, posfi.z);
  glVertex3f(posfi.x, posfi.y, posfi.z);
  glVertex3f(posfi.x, posfi.y, posini.z);

  glNormal3f(-1.0, 0.0, 0.0);
  glVertex3f(posini.x, posini.y, posini.z);
  glVertex3f(posini.x, posini.y, posfi.z);
  glVertex3f(posini.x, posfi.y, posfi.z);
  glVertex3f(posini.x, posfi.y, posini.z);

  glNormal3f(1.0, 0.0, 0.0);
  glVertex3f(posfi.x, posini.y, posini.z);
  glVertex3f(posfi.x, posfi.y, posini.z);
  glVertex3f(posfi.x, posfi.y, posfi.z);
  glVertex3f(posfi.x, posini.y, posfi.z);

  glNormal3f(0.0, 0.0, -1.0);
  glVertex3f(posini.x, posini.y, posini.z);
  glVertex3f(posini.x, posfi.y, posini.z);
  glVertex3f(posfi.x, posfi.y, posini.z);
  glVertex3f(posfi.x, posini.y, posini.z);
  
  glNormal3f(0.0, 0.0, 1.0);
  glVertex3f(posini.x, posini.y, posfi.z);
  glVertex3f(posfi.x, posini.y, posfi.z);
  glVertex3f(posfi.x, posfi.y, posfi.z);
  glVertex3f(posini.x, posfi.y, posfi.z);

  glEnd();
}
