#include "laberint.h"
#include <string>
#include <cmath>


Laberint::Laberint () {
    update (DEFAULT_WIDTH, DEFAULT_HEIGHT, 1);
}

Laberint::Laberint(const int& width, const int& height, const int& seed)
{
    update (width, height, seed);
}

void Laberint::update(const int& width, const int& height, const int& seed)
{
    _width = width;
    _height = height;

    srand(seed);
    _laberint = vector<vector<int> > (_width, vector<int> (_height));
    for (int i = 0;  i < _width; ++i) {
        for (int j = 0; j < _height; ++j) {
            int ran = rand()%PRECISIO_RANDOM;
            if( (float)ran/PRECISIO_RANDOM < 0.7 || j == width/2-1 && i == height/2-1) {
                _laberint[i][j] = TERRA;
            }
            else {
                _laberint[i][j] = PARET;
            }
        }
    }    

    // Calcula la bounding box
    Point initPoint;
    initPoint.x = 0;
    initPoint.y = 0;
    initPoint.z = 0;

    _boundingBox = Box (initPoint);

    Point maxPoint;
    maxPoint.x = _width;
    maxPoint.y = PARET_HEIGHT;
    maxPoint.z = _height;

    _boundingBox.update(maxPoint);
    _rad = Vector (maxPoint).length();
    _center = _boundingBox.getCenter();
    //cout << _center.x << " " << _center.y << " " << _center.z;

}

void Laberint::swapTile (int i, int j) {
    //cout << "Tile swaped is at: " << i << " "<< j << endl;
    if (i < 0 or j < 0 or i > _width or j > _height);
    else {
        if (_laberint[i][j] == TERRA) _laberint[i][j] = PARET;
        else _laberint[i][j] = TERRA;
    }
}

bool Laberint::isWalkable (Point pos) {
    if (pos.x >= this->_height or pos.z >= this->_width or pos.x <= 0 or pos.z <= 0) {
        //cout << "Fora límits" << endl;
        return false;
    }
    else if (_laberint[pos.z][pos.x] == TERRA) return true;
    else return false;
}


float Laberint::getTileSize() {
    return TILE_SIZE;
}

Point Laberint::getRandomLocation(int seed) {
    srand (seed);
    float x = rand()%_width;
    float z = rand()%_height;
    while (_laberint[z][x] == PARET) {
        x = rand()%_width;
        z = rand()%_height;
    }

    Point ret;
    ret.x = x + ((float)TILE_SIZE / 2);
    ret.z = z + ((float)TILE_SIZE / 2);
    ret.y = 0 ;
    //cout << "ENEMIC A: " << ret << endl;
    return ret;

}

Point Laberint::tileToPosition(int i, int j) {
    Point ret;
    ret.x = j + ((float)TILE_SIZE / 2);
    ret.z = i + ((float)TILE_SIZE / 2);
    ret.y = (float)PARET_HEIGHT / 2 ;
    return ret;
}

int Laberint::positionToXTile (Point pos) {
    return pos.x - ((float)TILE_SIZE / 2);
}

int Laberint::positionToYTile (Point pos) {
    return pos.z - ((float)TILE_SIZE / 2);
}

Point Laberint::getCenterTile() {
    Point center;
    center.x = (_width/2-1) + ((float)TILE_SIZE / 2);
    center.z = (_height/2-1) + ((float)TILE_SIZE / 2);
    center.y = (float)PARET_HEIGHT / 2 ;
    return center;
}


float Laberint::getRadiContentSphere () {
    return _rad;
}

Point Laberint::getCenter () {
    return this->_center;
}

void Laberint::PintaCaixa (Point &posini, Point &posfi)
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

void Laberint::Render(bool lighting) {

    for (int i = 0; i < _width; ++i) {
        for (int j = 0; j < _height; ++j) {

            Point ini;
            Point fi;

            switch (_laberint[i][j]) {
            case TERRA:
                ini.x = j*TILE_SIZE;
                ini.y = 0;
                ini.z = i*TILE_SIZE;
                fi.x = j+1;
                fi.y = TERRA_HEIGHT;
                fi.z = i+TILE_SIZE;
                if (!lighting) {
                    glColor3f (0.5,0.5,0.5);
                }
                else {
                    GLfloat f[4] = {0.5, 0.5, 0.5, 1};
                    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, f);
                    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, f);
                    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, f);
                    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, f);
                }
                PintaCaixa (ini, fi);
                break;

            case PARET:
                ini.x = j*TILE_SIZE;
                ini.y = 0;
                ini.z = i*TILE_SIZE;
                fi.x = j+1;
                fi.y = PARET_HEIGHT;
                fi.z = i+TILE_SIZE;

                if (!lighting) glColor3f (1,0,0);
                else {
                    GLfloat f[4] = {1, 0, 0, 1};
                    glMaterialfv(GL_FRONT, GL_AMBIENT, f);
                    glMaterialfv(GL_FRONT, GL_DIFFUSE, f);
                    glMaterialfv(GL_FRONT, GL_SPECULAR, f);
                    glMaterialfv(GL_FRONT, GL_SHININESS, f);
                }
                PintaCaixa (ini,fi);
                break;
            }
        }
    }

}

void Laberint::fakeColorRender() {

    for (int i = 0; i < _width; ++i) {
        for (int j = 0; j < _height; ++j) {

            Point ini;
            Point fi;

            switch (_laberint[i][j]) {
            case TERRA:
                ini.x = j*TILE_SIZE;
                ini.y = 0;
                ini.z = i*TILE_SIZE;
                fi.x = j+1;
                fi.y = TERRA_HEIGHT;
                fi.z = i+TILE_SIZE;
                glColor3ub (i,j,0);
                PintaCaixa (ini, fi);
                break;

            case PARET:
                ini.x = j*TILE_SIZE;
                ini.y = 0;
                ini.z = i*TILE_SIZE;
                fi.x = j+1;
                fi.y = PARET_HEIGHT;
                fi.z = i+TILE_SIZE;

                glColor3ub  (i,j,0);
                PintaCaixa (ini,fi);
                break;
            }
        }
    }

}
