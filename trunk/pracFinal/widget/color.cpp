#include "color.h"

Color::Color (const Color &c) : r(v[0]), g(v[1]), b(v[2]), a(v[3])
{
  v[0] = c.v[0];
  v[1] = c.v[1];
  v[2] = c.v[2];
  v[3] = c.v[3];
}

Color::Color(float a, float b, float c, float d) 
: r(v[0]), g(v[1]), b(v[2]), a(v[3]) 
{
  v[0] = a;
  v[1] = b;
  v[2] = c;
  v[3] = d;
}

Color::Color() 
: r(v[0]), g(v[1]), b(v[2]), a(v[3]) 
{
  v[0] = v[1] = v[2] = 0;
  v[3] = 1;
}

Color& Color::operator=(const Color& c)
{
  Color col(c);
  return col;
}

ostream& operator<< (ostream &os, const Color &c) 
{
  os << c.v[0] << ", " << c.v[1] << ", " << c.v[2] << ", " << c.v[3] << endl;
  return os;
}

