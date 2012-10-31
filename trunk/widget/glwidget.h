#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include<QTimer>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QFileDialog>
#include "point.h"
#include "scene.h"
#include "lightform.h"

class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = 0);
    void updateLight0();
    void rotate(int x, int y);

protected:
    void initializeGL ();
    void setCamera();
    void paintGL ();
    void resizeGL (int width, int height);
    void iniPerspective();
    void setEyeOrtho();
    void setEyePers();
    double getDistancia();
    void iniOrtho();
    void camOptima(float radi, Point centre);
    void setCameraMode(); // ajusta parametres de la camara en funcio de l'estat

    virtual void mousePressEvent (QMouseEvent *e);
    virtual void mouseReleaseEvent (QMouseEvent *e);
    virtual void mouseMoveEvent (QMouseEvent *e);
    virtual void keyPressEvent (QKeyEvent *event);

    double angleX, angleY, anglecam, ra, fovy, aspect, zNear, zFar;
    double left,bottom;

    Point VRP, eye;
    Scene scene;

    // Atributs de mode
    typedef  enum {NONE, ROTATE, ZOOM, EXAMEN, PAN} InteractiveAction;
    typedef  enum {INI, PERSPECTIVE, ORTHO, FIRST} CameraType;
    typedef  enum {INIT, DUPLICATE, MODIFICAR_T, MOVE} EditionType;
    InteractiveAction DoingInteractive;
    CameraType  cameraMode;
    EditionType editionMode;

    int   xClick, yClick, angleGiratY, angleGiratX;
    bool light, focus0, hid;

    // Rendering attributes
    typedef  enum {IMMEDIATE, VERTEX_ARRAY, BUFFER_OBJECT} RenderType;
    RenderType renderType;

    // FPS
    double frameCount;
    QTimer *timer;
    void initializeFPSMonitoring();
    void increaseFPS();

    // Shaders
    unsigned int vertexShaderId;
    unsigned int fragmentShaderId;
    unsigned int program;
    void initializeShaders();

public slots:
     void LoadObject ();
     void Reset();
     void resetPerspective();
     void setImmediateRender();
     void setVertexArrayRender();
     void setVertexBufferObjectRender();
     void refreshFPS();
     void loadShader();
     void setShaders(bool a);

signals:
     void updateFPS(double a);

};

#endif
