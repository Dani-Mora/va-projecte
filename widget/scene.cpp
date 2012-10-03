#include "scene.h"
#include <math.h>


MaterialLib Scene::matlib;

Scene::Scene():polBase("Base"), modelObj("model")
{}

void Scene::Init()
{
  // reinicio vector objectes
  this->lobjectes.clear();
  // construeixo poligon base
  construirBase ();
  // calculo capsa contenidora
  calcularCapsa();

  // ini Llums escena
  this->initLights();  
}


/* Il·luminació */

void Scene::initLights()
{
    /* Inicialitzo dades focus 0 */
    GLfloat color[4] = {1.0, 1.0, 1.0, 1.0};
    this->light0.setAmb(color[0], color[1], color[2], color[3]);
    this->light0.setDif(color[0], color[1], color[2], color[3]);
    this->light0.setSpec(color[0], color[1], color[2], color[3]);
    this->light0.setObject(-1); // no te objecte associat ni posicio concreta
    this->light0.setUsada(true);
    this->light0.setEncesa(true);
}


/* Canvi colors llum 0 */
void Scene::setLight0Colors(GLfloat r, GLfloat g, GLfloat b)
{

    GLfloat color[4] = {r, g, b, 1.0};

    this->light0.setAmb(r,g,b,(float)1.0);
    this->light0.setDif(r,g,b,(float)1.0);
    this->light0.setSpec(r,g,b,(float)1.0);

    glLightfv(GL_LIGHT0, GL_AMBIENT, color);
    glLightfv(GL_LIGHT0, GL_SPECULAR, color);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, color);
}

void Scene::changeColor0R(int r)
{
    GLfloat *actual = light0.getDif();
    GLfloat raux = (float)r/255;
    GLfloat gaux = actual[1];
    GLfloat baux = actual[2];

    this->setLight0Colors(raux, gaux, baux);
}

void Scene::changeColor0G(int g)
{
    GLfloat *actual = light0.getDif();
    GLfloat raux = actual[0];
    GLfloat gaux = (float)g/255;
    GLfloat baux = actual[2];

    this->setLight0Colors(raux, gaux, baux);
}

void Scene::changeColor0B(int b)
{
    GLfloat *actual = light0.getDif();
    GLfloat raux = actual[0];
    GLfloat gaux = actual[1];
    GLfloat baux = (float)b/255;

    this->setLight0Colors(raux, gaux, baux);
}

float* Scene::getLight0Color()
{
   float* aux = this->light0.getDif();
   return aux;
}


/* Funcions de la classe */

void Scene::construirBase ()
{
  // Construim el poligon base, el terra
  Vertex v1(Point(-10,0,-10));
  Vertex v2(Point(-10,0,10));
  Vertex v3(Point(10,0,10));
  Vertex v4(Point(10,0,-10));
  polBase.vertices.push_back(v1);
  polBase.vertices.push_back(v2);
  polBase.vertices.push_back(v3);
  polBase.vertices.push_back(v4);

  Face face(0,1,2,3);
  face.normal = Vector(0,1,0); //declara normal, vector vertical
  face.material = 0;
  polBase.faces.push_back(face);
}

/* Renders */

// Render de l'escena usant colors
void Scene::RenderColor()
{

  polBase.RenderColor();

  for (unsigned int i = 0; i < lobjectes.size(); ++i) lobjectes[i].Render(modelObj,0);

  // calculo capsa escena i pinto
  this->calcularCapsa();
  capsa.Render();
}

// Render de l'escena amb color fals
void Scene::RenderBack()
{
  for (unsigned int i = 0; i < lobjectes.size(); ++i) lobjectes[i].Render(modelObj,1);
}

// Render de l'escena usant materials -> il·luminació
void Scene::RenderLight()
{
  polBase.RenderLight();

  for (unsigned int i = 0; i < lobjectes.size(); ++i) lobjectes[i].Render(modelObj,3);

  // calculo capsa escena i pinto
  this->calcularCapsa();
  capsa.Render();
}

void Scene::RenderVertexArray()
{
    polBase.RenderLight();

    for (unsigned int i = 0; i < lobjectes.size(); ++i) lobjectes[i].Render(modelObj,2);

    // calculo capsa escena i pinto
    this->calcularCapsa();
    capsa.Render();
}

void Scene::renderVertexBufferObject()
{
    // ...
}

/* Objctes a l'scene */

void Scene::AddObjecte(Objecte &oref)
{
  lobjectes.push_back(oref);
}

void Scene::AddOneObject(Objecte &oref)
{
  lobjectes.clear();
  lobjectes.push_back(oref);
  lobjectes[0].setId(0);
}

Objecte Scene::obteObjecte(int num)
{
    return lobjectes[num];
}

void Scene::setModel(Model &modelOb)
{
    modelObj = modelOb;
    modelObj.generateVertexArray();
}

Model Scene::getModel()
{
    return this->modelObj;
}

bool Scene::foraBase(int x, int z)
{
    if (x <= -10 || x >= 10) return true;
    if (z <= -10 || z >= 10) return true;
    return false;
}

/* CALCUL ESCENA */

/* Calcul de l'escena */
void Scene::calcularCapsa()
{
    // recorrer objectes i agafar el min i el max punt
    Point min = Point (-10, 0, -10);
    Point max = Point (10,0,10); // agafem com a punts de referencia els de la base
    for (unsigned int i = 0; i < lobjectes.size(); ++i) {
        Box aux = lobjectes[i].getCapsa();
        if (aux.maxb.x > max.x) max.x = aux.maxb.x;
        if (aux.maxb.y > max.y) max.y = aux.maxb.y;
        if (aux.maxb.z > max.z) max.z = aux.maxb.z;

        if (aux.minb.x < min.x) min.x = aux.minb.x;
        if (aux.minb.y < min.y) min.y = aux.minb.y;
        if (aux.minb.z < min.z) min.z = aux.minb.z;
    }

    this->capsa.minb = min;
    this->capsa.maxb = max;

    float puntX, puntY, puntZ;
    puntX = ((capsa.maxb.x - capsa.minb.x)/2) + capsa.minb.x;
    puntY = ((capsa.maxb.y - capsa.minb.y)/2) + capsa.minb.y;
    puntZ = ((capsa.maxb.z - capsa.minb.z)/2) + capsa.minb.z;
    this->centre = Point(puntX,puntY,puntZ);

    // Calculem radi de l'esfera contenidora
    Point punt = capsa.maxb;
    float aux = (centre.x - punt.x)*(centre.x - punt.x) + (centre.y - punt.y)*(centre.y - punt.y) + (centre.z - punt.z)*(centre.z - punt.z);
    this->radi = sqrt(aux);
}

/* cal usar aquestes funcions despres de calcular la capsa!! */
float Scene::getRadi()
{
    return this->radi;
}

Point Scene::getCentre()
{
    return this->centre;
}

double Scene::getAlturaScene()
{
    return this->capsa.maxb.y;
}

void Scene::reset()
{
    // Esborrem objectes excepte el primer
    while(lobjectes.size() > 1) lobjectes.pop_back();

    // Ini llums
    this->initLights();
    glDisable(GL_LIGHT1);
    glDisable(GL_LIGHT2);
    glDisable(GL_LIGHT3);
}

/* Funcions de seleccio */

void Scene::seleccionarCara(int x, int y,int height)
{
    GLubyte buff [3];
    glReadBuffer(GL_BACK);
    glReadPixels(x, height - y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, buff);

    /* Mirem si el color trobat correspon a alguna de les cares */
    int cara = buff[1] + buff[2]*255;
    if (cara >= 0 && (unsigned int)cara < modelObj.faces.size()) modelObj.setCaraSel(cara);
    else modelObj.setCaraSel(-1);
}

double Scene::getRadiObj(int num)
{
    if (num < 0 || lobjectes.size() <= (unsigned int)num) return -1;
    else return lobjectes[num].getRadi();
}

int Scene::numObjectes()
{
    return lobjectes.size();
}

