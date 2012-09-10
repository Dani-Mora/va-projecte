#ifndef _COLOR_H_
#define _COLOR_H_

#include <iostream>
using namespace std;

class Color
{
 public:
  Color (const Color &c);
  Color(float aa=0, float b=0, float c=0, float d=1);
  Color();
  Color& operator=(const Color&);

  // atributs
  float v[4];
  float &r,&g,&b,&a ;	// components RGB del color
};

ostream& operator<< (ostream &os, const Color &c);

#endif
