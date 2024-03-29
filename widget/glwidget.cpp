#include <GL/glew.h>
#include "glwidget.h"
#include <math.h>
#include <QString>
#include "textfile.h"

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
}

void GLWidget::initializeGL()
{

  glClearColor(0.4f, 0.4f, 0.8f, 1.0f);
  glEnable(GL_DEPTH_TEST);

  // ini modes
  cameraMode = INI;
  editionMode = INIT;

  // Activem il·luminació i culling
  light =  false;
  hid = focus0 = true; // culling i focus0 a true
  glEnable(GL_DEPTH_TEST); // Activem z-buffer
  glCullFace(GL_BACK); // Mode Culling: back-face
  glEnable(GL_CULL_FACE); // Activem culling

  glEnable(GL_LIGHT0); // Activem llum 0
  glEnable(GL_LIGHTING); // Desactivem il·luminació

  // Fem el GL Normalize, només un cop!
  glEnable(GL_NORMALIZE);

  // ini Escena
  scene.Init();

  // ini Càmara
  this->setEyePers();
  iniPerspective();
  this->camOptima(scene.getRadi(), scene.getCentre());

  // Ini parametres càmara
  zNear = 5;
  zFar = 60;
  left = bottom = -10;

  // Ini angles de gir
  this->angleGiratX = 0;
  this->angleGiratY = 0;

  // Initial render type: Immediate
  renderType = IMMEDIATE;

  // FPS
  this->initializeFPSMonitoring();

  // Shaders. Default -> no shaders
  this->initializeShaders();
}

double GLWidget::getDistancia()
{
    int aux = (eye.x -VRP.x)*(eye.x -VRP.x) + (eye.y -VRP.y)*(eye.y -VRP.y) + (eye.z -VRP.z)*(eye.z -VRP.z);
    double dist = sqrt(aux);
    return dist;
}

void GLWidget::resizeGL (int width, int height)
{
    float ra = (float)width/(float)height;
    float inc = abs(2*10*ra -2*10);
    bottom = left = 10;
    if(ra>1) left = (10 + inc/2);
    else if (ra < 1) bottom = (10 + inc/2);
    glViewport (0, 0, width, height);
}

void GLWidget::setEyeOrtho()
{
    eye.x = 0;
    eye.y = 20;
    eye.z = 0;
}

void GLWidget::setEyePers()
{
    eye.x = 25;
    eye.y = 25;
    eye.z = 25;
}


void GLWidget::rotate(int x, int y)
{
    double dist = this->getDistancia();

    GLfloat mv[16];
    glMatrixMode(GL_MODELVIEW);
    glGetFloatv(GL_MODELVIEW_MATRIX, mv);
    glLoadIdentity();
    glTranslatef(0,0,-dist);
    glRotatef(5.3, x, y, 0.0);
    glTranslatef(0,0,dist);
    glMultMatrixf(mv);
}

void GLWidget::setCameraMode()
{

    this->scene.calcularCapsa();
    double radi = this->scene.getRadi();
    switch(cameraMode) {
        case (PERSPECTIVE):
            this->setEyePers();
            this->camOptima(scene.getRadi(), scene.getCentre());
            this->iniPerspective(); // el centre de la capsa es el centre de l'objecte
            zNear = this->getDistancia() - radi;
            zFar = this->getDistancia() + radi + 1;
            break;
        case (ORTHO):
            this->setEyeOrtho();
            zNear = scene.getAlturaScene();
            zFar = this->getDistancia() + 2;
            VRP.x = 0; VRP.y = 0; VRP.z = 0;
            this->iniOrtho();
            break;
        default:
            this->setEyePers();
            this->camOptima(scene.getRadi(), scene.getCentre());
             zNear = this->getDistancia() - radi;
            zFar = this->getDistancia() + radi + 1;

            this->iniPerspective();
    }
}

void GLWidget::iniPerspective()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eye.x,eye.y,eye.z,VRP.x,VRP.y,VRP.z, 0, 1, 0);
}

void GLWidget::iniOrtho()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eye.x,eye.y,eye.z,VRP.x,VRP.y,VRP.z,0,0,-1);
}

void GLWidget::setCamera()
{
    // Definim tipus de camera segons el mode on estiguem
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float aspect = (float)width()/(float)height();

    if (cameraMode == ORTHO) glOrtho(-left,left,-bottom,bottom,zNear,zFar);
    else  gluPerspective(fovy, aspect , zNear, zFar);
}

void GLWidget::paintGL( void )
{

  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  this->setCamera();

  // dibuixar eixos aplicacio
  glBegin(GL_LINES);
  glColor3f(1,0,0); glVertex3f(0,0,0); glVertex3f(20,0,0); // X
  glColor3f(0,1,0); glVertex3f(0,0,0); glVertex3f(0,20,0); // Y
  glColor3f(0,0,1); glVertex3f(0,0,0); glVertex3f(0,0,20); // Z
  glEnd();

  // Scene Render depending on the render mode
  switch(renderType)
  {

    case (VERTEX_ARRAY):
      this->scene.RenderVertexArray();
      break;
    case (BUFFER_OBJECT):
      this->scene.RenderVertexBufferObject();
      break;
    default:
      this->scene.RenderLight();
      break;
  };

  this->increaseFPS();
}  

/* EVENTS */

void GLWidget::mousePressEvent( QMouseEvent *e)
{
  xClick = e->x();
  yClick = e->y();

  //ZOOM/ROTATE
  if (cameraMode == PERSPECTIVE || cameraMode == INI) {
    if (e->button()&Qt::LeftButton &&
      ! (e->modifiers()&(Qt::ShiftModifier|Qt::AltModifier|Qt::ControlModifier)))
    {
        DoingInteractive = ROTATE;
    }
    else if (e->button()&Qt::LeftButton &&  e->modifiers() &Qt::ShiftModifier)
    {
      DoingInteractive = ZOOM;
    }
  }
}

void GLWidget::keyPressEvent(QKeyEvent *e)
{
  switch (e->key())
  {
    case Qt::Key_F:
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        updateGL();
        break;
    case Qt::Key_S:
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        updateGL();
        break;
    default: e->ignore();
  }
}

void GLWidget::mouseReleaseEvent( QMouseEvent *)
{
  DoingInteractive = NONE;
}

void GLWidget::mouseMoveEvent(QMouseEvent *e)
{
  int difX, difY;
  difX = e->x() - xClick;
  difY = e->y() - yClick;

  if (DoingInteractive == ROTATE)
  {

    // guardem angles firats
    this->angleGiratX += difX;
    this->angleGiratY += difY;

    this->rotate(difY, difX);

  }

  else if (DoingInteractive == ZOOM)
  {
    fovy += difY;
    if (fovy >= 180) fovy = 179;
    else if (fovy <= 0) fovy = 1;
  }

  updateGL();

  xClick = e->x();
  yClick = e->y();
}

/* Modifica l'VRP i el fovy en mode perspectiva */
void GLWidget::camOptima(float radi, Point centre)
{
    // fem que l'objecte s'ajusti al màxim a la camara
    float cc = (eye.x - centre.x) * (eye.x - centre.x) + (eye.y - centre.y) * (eye.y - centre.y) + (eye.z - centre.z) * (eye.z - centre.z);
    cc = sqrt(cc);

    float tan = radi/cc; // tangent
    float angle = atan(tan); // tenim angle fovy/2;
    angle = angle * 180/M_PI; // passem a radiants

    fovy = 2*angle; // actualitzem angle obertura
    VRP = centre; // actualitzem punt on mirem
}


/* FPS Refreshing */

void GLWidget::initializeFPSMonitoring()
{
    // Initialize frame count
    this->frameCount = 0;

    // Initialize timer
    this->timer = new QTimer();
    this->connect(this->timer, SIGNAL(timeout()), this, SLOT(refreshFPS()));
    this->timer->start(1000);
}

void GLWidget::refreshFPS()
{
    emit this->updateFPS(this->frameCount);
    this->frameCount = 0;
}

void GLWidget::increaseFPS()
{
    // Increase frame count
    this->frameCount++;
}

/* Shaders */

char* convertStringToChar(QString path)
{
    QByteArray bArray = path.toLocal8Bit();
    return bArray.data();
}

bool isVertexShader(QString path)
{
    return path.endsWith(".vert");
}

bool isFragmentShader(QString path)
{
    return path.endsWith(".frag");
}

bool isShaderPath(QString path)
{
    return (isFragmentShader(path) || isVertexShader(path));
}

void GLWidget::initializeShaders()
{
    glewInit();

    this->program = glCreateProgram();

    this->vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
    this->fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
}

void GLWidget::setUniformFloatValue(const char *name, float value)
{
    GLint location = glGetUniformLocation(this->program, name);
    cout << "Location: " << location << endl;
    if (location != -1)
    {
        glUniform1f(location, value);
        cout << "Variable " << name << " found" << endl;
    }
    else
    {
        cout << "Variable " << name << " not found" << endl;
    }

    updateGL();
}

/* SLOTS */

/* Object Loader Slot */

void GLWidget::LoadObject()
{
  QString model = QFileDialog::getOpenFileName(this, tr("Open File"), "../data", tr("Objectes (*.obj)"));
  if (model != "")
  {

    const char *nomModel = model.toLatin1();

    scene.Init();

    // Carreguem model
    Model mod("Model1");
    mod.readObj(nomModel, Scene::matlib);
    scene.setModel(mod);

    // Afegim objecte a l'escena
    Objecte ob("Objecte",Point(0,0,0),float(2.0),float(1.0)); //creem objecte
    ob.calcularCapsa(mod);

    // Afegim objecte a l'escena
    scene.AddOneObject(ob); //afegim objecte a l'escena

    cameraMode = INI;
    editionMode = INIT;
    this->setCameraMode();

    updateGL();
  }
}

void GLWidget::resetPerspective()
{
    if (cameraMode == PERSPECTIVE || cameraMode == INI) {
        this->setCameraMode();
        updateGL();
    }
}

void GLWidget::Reset()
{
    cameraMode = INI;
    editionMode = INIT;
    scene.reset();

    this->setCameraMode();

    updateGL();
}

void GLWidget::setImmediateRender()
{
    renderType = IMMEDIATE;
    updateGL();
}

void GLWidget::setVertexArrayRender()
{
    renderType = VERTEX_ARRAY;
    updateGL();
}

void GLWidget::setVertexBufferObjectRender()
{
    renderType = BUFFER_OBJECT;
    updateGL();
}

// We only read shaders that end with .frag and .vert so we can identify them
void GLWidget::loadShader()
{
    QString shaderPath = QFileDialog::getOpenFileName(this, tr("Open File"), "../data", tr("Shaders (FS/VS) (*.frag *.vert)"));
    if (isShaderPath(shaderPath))
    {
        char *charPath = convertStringToChar(shaderPath);
        const char *shaderCode = textFileRead(charPath);

        int idShader;

        if (isVertexShader(shaderPath))
        {
            idShader = this->vertexShaderId;
        }
        else
        {
            idShader = this->fragmentShaderId;
        }

        glShaderSource(idShader,1, &shaderCode, NULL);


        glCompileShader(idShader);
        glAttachShader(this->program, idShader);

        glLinkProgram(this->program);

        updateGL();
    }
    else
    {
        cout << "Invalid shader extension" << endl;
    }
}

void GLWidget::setShaders(bool state)
{
    if (state)
    {
        glUseProgram(this->program);
    }
    else
    {
        glUseProgram(NULL);
    }
    updateGL();
}

void GLWidget::setCheckerboardValue(int value)
{
    float valor = (float) value;
    cout << "Envio valor " << value << endl;
    int params;
    glGetProgramiv(this->program, GL_ACTIVE_UNIFORMS,  &params);
    cout << "uniform variables num: " << params << endl;

    std::vector<GLchar> nameData(256);
    for(int unif = 0; unif < params; ++unif)
    {
      GLint arraySize = 0;
      GLenum type = 0;
      GLsizei actualLength = 0;
      glGetActiveUniform(this->program, unif, nameData.size(), &actualLength, &arraySize, &type, &nameData[0]);
      std::string name((char*)&nameData[0], actualLength - 1);
      cout << "name: " << name << endl;
    }

    this->setUniformFloatValue("celes", valor);
}
