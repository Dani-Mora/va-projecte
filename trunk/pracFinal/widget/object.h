#ifndef OBJECTE_H
#define OBJECTE_H

#include "model.h"
#include "point.h"
#include <vector>
#include <iostream>
using namespace std;

class Object {
public:

    Object();

    void updateToPrimaryCube(int id, float scale, float orientation, float rotationOffset, Point position);

    void update(int id, Model& mod, float scale, float orientation, float rotationOffset, Point position);

    void createRender();

    void render(bool lighting);

    void scaleTo(float size);

    int getID();

    float getRad();

    Point getCenter();

    void move (Point position);

    void moveRotate (Point position, float orientation);

    void rotate (float orientation);

    void setRotation (float orientation);

    float getOrientation();

    float distanceBetweenObjects(Object &other);

    int isInContact(Object &other, float precisionOffset);

    Box getBoundingBox();

    //atributs
    protected:

    void pintaCube(bool lighting);

    #define MODEL 1
    #define CUBE 0

    int _id;
    Model _mod;
    float _scale;
    float _orientation;
    float _rotationOffset;
    Point _center;
    float _rad;
    int _displayListIndex;
    int _displayListIndex2;
    int _displayListModelFlat;
    int _displayListModelLight;
    int _iniciat;
    int _type;



};

#endif // OBJECTE_H
