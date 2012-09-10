#ifndef LABPLACEMENT_H
#define LABPLACEMENT_H
#include <vector>
#include "point.h"

class LabPlacement
{


private:

// Atributs d'emplaçament


public:
    LabPlacement(int pi=0., int pj=0., int ppos=0.);

    // atributs
    float i, j, pos;
};

#endif // LABPLACEMENT_H
