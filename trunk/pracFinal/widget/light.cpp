#include "light.h"

Light::Light()        
{


    _type = AMBIENT;
    Enabled = false;

    pos.x = 0;
    pos.y = 0;
    pos.z = 0;

    _ambientRed= 0;
    _ambientGreen= 0;
    _ambientBlue= 0;

    _specularRed= 0;
    _specularGreen= 0;
    _specularBlue= 0;

    _diffuseRed= 0;
    _diffuseGreen= 0;
    _diffuseBlue= 0;

    _angle=0;
    orientation =0;

}
