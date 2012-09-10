#include "object.h"
#include "model.h"
#include <iostream>
#include <QtOpenGL/qgl.h>
#include "box.h"
#include <math.h>



Object::Object() {
    _iniciat = 0;
}

void Object::updateToPrimaryCube (int id, float scale, float orientation, float rotationOffset, Point position) {
    this->_id  = id;
    this->_type = CUBE;
    Box bb;
    bb.maxb = Point (1,1,1);
    bb.minb = Point (-1,-1,-1);
    _center = position;
    _scale = scale;
    _orientation = orientation;
    _rotationOffset = rotationOffset;

    // Calcula el radi de l'esfera contenidora
    Point xVect;
    xVect.x =  1;
    xVect.y =  1;
    xVect.z =  1;
    Vector vec(xVect);
    _rad = vec.length();
    _rad = vec.length()* scale/2;
    createRender();
}

void Object::update(int id, Model& mod, float scale, float orientation, float rotationOffset, Point position) {

    this->_id  = id;
    this->_mod = mod;
    this->_type = MODEL;
    mod.updateBoundingBox();
    Box bb = _mod.boundingBox();
    _center = position;
    _scale = scale;
    _orientation = orientation;
    _rotationOffset = rotationOffset;


    // Calcula el radi de l'esfera contenidora
    Point xVect;
    xVect.x =  bb.maxb.x - _center.x;
    xVect.y =  bb.maxb.y - _center.y;
    xVect.z =  bb.maxb.z - _center.z;
    Vector vec(xVect);
    _rad = vec.length()* scale/ 2;
    createRender();

}

void Object::move(Point position) {
    _center = position;
    createRender();
}

void Object::moveRotate(Point position, float orientation) {
    if (orientation < 0) orientation = 360 - ((int)_orientation)%360;
    _orientation = orientation;
    _center = position;
    createRender();
}

void Object::rotate(float orientation) {
    if (orientation < 0) orientation = 360 + orientation;
    _orientation += orientation;
    _orientation = ((int)_orientation)%360;
    createRender();
    //cout << "Orientation " << _orientation << endl;
}

void Object::setRotation(float orientation) {
    _orientation = orientation;
    createRender();
}

float Object::getRad() {
    return _rad;
}

Point Object::getCenter() {
    return _center;
}

float Object::getOrientation() {
    return this->_orientation;
}


void Object::scaleTo(float size) {
    Box bb;
    if (_type == CUBE) {
        bb.maxb = Point (1,1,1);
        bb.minb = Point (-1,-1,-1);
    }
    else bb = this->_mod.boundingBox();
    int newX = bb.maxb.x-bb.minb.x;
    int newY =  bb.maxb.z-bb.minb.z;
    float realSize = sqrt(newX*newX+newY*newY);
    this->_scale = (size/realSize);
    this->_rad = _rad* (size/realSize);
    //cout   << "Scale at " << _scale << endl;
    createRender();
}

float Object::distanceBetweenObjects(Object &other) {
    Point xVect;
    xVect.x =  other.getCenter().x - _center.x;
    xVect.y =  other.getCenter().y - _center.y;
    xVect.z =  other.getCenter().z - _center.z;
    Vector vec(xVect);
    float distance = vec.length();

    return distance;
}

int Object::isInContact(Object &other, float precisionOffset) {
    float contactDistance = this->getRad()+ other.getRad();
    float distance = distanceBetweenObjects(other);
    if (contactDistance-precisionOffset >= distance) return 1;
    else return 0;
}


void Object::createRender() {

    if (_iniciat != 0) glDeleteLists(_displayListIndex, 1);
    else {

        if (_type == MODEL) {
            _displayListModelLight = glGenLists(1);
            glNewList(_displayListModelLight, GL_COMPILE);
            _mod.RenderWithLight();;
            glEndList();

            _displayListModelFlat = glGenLists(1);
            glNewList(_displayListModelFlat, GL_COMPILE);
            _mod.RenderFlatMaterial();
            glEndList();
        }
        if (_type == CUBE) {
            _displayListModelLight = glGenLists(1);
            glNewList(_displayListModelLight, GL_COMPILE);
            pintaCube(true);
            glEndList();

            _displayListModelFlat = glGenLists(1);
            glNewList(_displayListModelFlat, GL_COMPILE);
            pintaCube(false);
            glEndList();
        }

    }

    _iniciat = 1;
    _displayListIndex = glGenLists(2);
    _displayListIndex2 = _displayListIndex+1;

    Point realCenter = _mod.boundingBox().getCenter();
    //cout <<    "El bounding box té centre a " << realCenter << endl;

    glNewList(_displayListIndex, GL_COMPILE);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glTranslatef(_center.x, _center.y, _center.z);
        glRotatef(_orientation + _rotationOffset , 0.0, 1.0, 0.0);
        glScalef(_scale, _scale, _scale);
        glTranslatef(-realCenter.x, -this->getBoundingBox().minb.y, -realCenter.z);
    glEndList();

    glNewList(_displayListIndex2, GL_COMPILE);
        glPopMatrix();
    glEndList();
}

void Object::render(bool lighting) {
    glCallList(_displayListIndex);
    if (lighting) glCallList(_displayListModelLight);
    else glCallList(_displayListModelFlat);
    glCallList(_displayListIndex2);
}

Box Object::getBoundingBox() {
    if (this->_type == MODEL) {
        return this->_mod.boundingBox();
    }
    else {
        Box bb;
        bb.maxb = Point (1,1,1);
        bb.minb = Point (-1,-1,-1);
        return bb;
    }
}

int Object::getID() {
    return _id;
}

void Object::pintaCube (bool lighting) {

      Point posfi = Point (1,1,1);
      Point posini = Point (-1,-1,-1);

      if (!lighting) glColor3f (1,1,0);
      else {
          GLfloat f[4] = {1, 1, 0, 1};
          glMaterialfv(GL_FRONT, GL_AMBIENT, f);
          glMaterialfv(GL_FRONT, GL_DIFFUSE, f);
          glMaterialfv(GL_FRONT, GL_SPECULAR, f);
          glMaterialfv(GL_FRONT, GL_SHININESS, f);
      }

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


