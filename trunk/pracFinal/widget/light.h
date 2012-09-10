#ifndef LIGHT_H
#define LIGHT_H
#include "point.h"
class Light
{
public:

    #define AMBIENT 0
    #define FOCUS 1
    #define SPOT 2


    Light();



    int _type;
    bool Enabled;

    float _angle;
    int orientation;


    Point pos;

    float _ambientRed;
    float _ambientGreen;
    float _ambientBlue;

    float _specularRed;
    float _specularGreen;
    float _specularBlue;

    float _diffuseRed;
    float _diffuseGreen;
    float _diffuseBlue;
};

#endif // LIGHT_H
