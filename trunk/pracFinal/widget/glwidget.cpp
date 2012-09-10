#include "glwidget.h"
#include <math.h>

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
}

void GLWidget::initializeGL()
{



  char* locale = setlocale(LC_ALL,NULL);
  setlocale(LC_NUMERIC, "C");
  setlocale(LC_ALL, locale);

  glClearColor(0.4f, 0.4f, 0.8f, 1.0f);
  glEnable(GL_DEPTH_TEST);

  // Afegiu totes les inicialitzacions que necessiteu,
  // tant de l'escena com de la càmera
  initCamera();
  initCulling();
  initLighting();

  // Inicialitzar l'escena
  scene.InitializeScene();


}

void GLWidget::initVariables() {

    // Inicialitza el punt on es troba la càmera
    /*_camera.x = CAMERAX;
    _camera.y = CAMERAY;
    _camera.z = CAMERAZ;*/

    //Inicialitza el vector up
    /*_up.x = UPX;
    _up.y = UPY;
    _up.z = UPZ;*/

    // Inicialitza la distancia de la càmera a l'escena
    _camDist = CAMDIST;

    //Inicialitza la rotació de l'escena
    _orix = DEFAULT_ORIX;
    _oriy = DEFAULT_ORIY;
    _oriz = DEFAULT_ORIZ;

    //Inicialitza el PAN predeterminat
    _panx = DEFAULTPANX;
    _pany = DEFAULTPANY;

    // Inicialitza el visual reference point
    _vrp.x = VRPX;
    _vrp.y = VRPY;
    _vrp.z = VRPZ;

    //Inicialitza l'angle de projeccio
    _fov = FOV;

    // Inicialitza els plans near i far;
    _near = NEAR;
    _far = FAR;

    // Inicialitza la mida de la vista
    _width = WIDTH;
    _height = HEIGHT;

    _timer = new QTimer(this);
    connect(_timer, SIGNAL(timeout()), this, SLOT(refresh()));

    _firstPerson = false;

}


void GLWidget::refresh() {
    scene.refresh();
    if(scene.gameOver() || scene.pause()) {
        _timer->stop();
    }
    updateGL();
}


void GLWidget::initCamera(){
    // Inicialitza
    initVariables();
    _vrp = scene.getCenter();
    /*_camera= scene.getCenter();*/
    _camDist = scene.getRadi();
    setCamera();

}

void GLWidget::initCulling(){
    glCullFace(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
}

void GLWidget::enableCulling(){
    initCulling();
    updateGL();
}

void GLWidget::disableCulling(){
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);
    updateGL();
}


void GLWidget::enableFocus() {
    scene.enableFocus();
    updateGL();
}

void GLWidget::disableFocus() {
    scene.disableFocus();
    updateGL();
}

void GLWidget::enableAmbientalLight() {
    scene.enableAmbientalLight();
    updateGL();
}

void GLWidget::disableAmbientalLight() {
    scene.disableAmbientalLight();
    updateGL();
}

void GLWidget::enableSpot() {
    scene.enableSpot();
    updateGL();
}

void GLWidget::disableSpot() {
    scene.disableSpot();
    updateGL();
}

void GLWidget::setFocusX(double x) {
    scene.setFocusX((float) x);
    updateGL();
}

void GLWidget::setFocusZ(double z) {
    scene.setFocusZ((float) z);
    updateGL();
}

void GLWidget::setGreenFocus(int x) {
    float z  = (float) x/100;
    scene.setGreenFocus(z);
    updateGL();
}

void GLWidget::setRedFocus(int x) {
    float z  = (float) x/100;
    scene.setRedFocus(z);
    updateGL();
}

void GLWidget::setBlueFocus(int x) {
    float z  = (float) x/100;
    scene.setBlueFocus(z);
    updateGL();
}

void GLWidget::setGreenSpot(int x) {
    float z  = (float) x/100;
    scene.setGreenSpot(z);
    updateGL();
}

void GLWidget::setRedSpot(int x) {
    float z  = (float) x/100;
    scene.setRedSpot(z);
    updateGL();
}

void GLWidget::setBlueSpot(int x) {
    float z  = (float) x/100;
    scene.setBlueSpot(z);
    updateGL();
}

void GLWidget::setGreenAmbientalLight(int x) {
    float z  = (float) x/100;
    scene.setGreenAmbientalLight(z);
    updateGL();
}

void GLWidget::setRedAmbientalLight(int x) {
    float z  = (float) x/100;
    scene.setRedAmbientalLight(z);
    updateGL();
}

void GLWidget::setBlueAmbientalLight(int x) {
    float z  = (float) x/100;
    scene.setBlueAmbientalLight(z);
    updateGL();
}

void GLWidget::initLighting(){
    glEnable(GL_NORMALIZE);
    glEnable(GL_FRONT);
    glEnable(GL_LIGHTING);
}

void GLWidget::resetCamera(){
    // Inicialitza
    initVariables();
    scene.setFirstPerson(false);
    _vrp = scene.getCenter();
    /*_camera= scene.getCenter();*/
    _camDist = scene.getRadi();
    setCamera();
    updateGL();

}

void GLWidget::setCamera () {

    if (!_firstPerson) {
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        //Allunya a la distància corresponent
        glTranslatef(0,0,-_camDist);

        //Aplica el PAN
        glTranslatef(_panx,_pany,0);

        //Fa rotacions segons correspon
        glRotatef(_orix,1,0,0);
        glRotatef(_oriy,0,1,0);
        glRotatef(_oriz,0,0,1);

        //Enfoca al punt de mira
        glTranslatef(-_vrp.x,-_vrp.y,-_vrp.z);

        // Calcula la projecció de la càmera
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        gluPerspective( _fov, (float)_width/_height, _near, _far);
    }
    else {

        // Calcula la projecció de la càmera
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();


        //Fa rotacions segons correspon
        glRotatef(-scene.getMainCharacterOrientation(),0,1,0);

        //Enfoca al punt de mira
        glTranslatef(-scene.getMainCharacterPosition().x,-scene.getMainCharacterPosition().y-0.25,-scene.getMainCharacterPosition().z);

        // Calcula la projecció de la càmera
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        //Perspective amb 90 d'obertura
        gluPerspective( 90, (float)_width/_height, _near, _far);

    }

}


void GLWidget::resizeGL (int width, int height)
{
  glViewport (0, 0, width, height);
}



void GLWidget::paintGL( void )
{
  setCamera();
  glDisable(GL_LIGHTING);
  // dibuixar eixos aplicacio
  glBegin(GL_LINES);
  glColor3f(1,0,0); glVertex3f(0,0,0); glVertex3f(20,0,0); // X
  glColor3f(0,1,0); glVertex3f(0,0,0); glVertex3f(0,20,0); // Y
  glColor3f(0,0,1); glVertex3f(0,0,0); glVertex3f(0,0,20); // Z
  glEnd();
  glEnable(GL_LIGHTING);
  scene.Render();
}



void GLWidget::mousePressEvent( QMouseEvent *e)
{
  xClick = e->x();
  yClick = e->y();

  if (e->button()&Qt::LeftButton &&  
      ! (e->modifiers()&(Qt::ShiftModifier|Qt::AltModifier|Qt::ControlModifier)))
  {
    DoingInteractive = ROTATE;
  }
  else if (e->button()&Qt::LeftButton &&  e->modifiers() &Qt::ShiftModifier)
  {
    DoingInteractive = ZOOM;
  }
  else if (e->button()&Qt::LeftButton &&  e->modifiers() &Qt::ControlModifier)
  {
    DoingInteractive = PAN;
  }
  else if (e->button()&Qt::MidButton) {
      glDisable(GL_LIGHTING);
      this->scene.fakeColorRender();
      GLubyte color[3];
      glReadBuffer(GL_BACK);
      glReadPixels(xClick, this->height() - yClick, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, color);
      int i = color[0];
      int j = color[1];
      this->scene.swapTile(i,j);
      glEnable(GL_LIGHTING);
      updateGL();
  }


}

void GLWidget::keyPressEvent(QKeyEvent *e)
{
  switch (e->key())
  {
    case Qt::Key_F:
        glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
        updateGL ();
        break;
    case Qt::Key_S:
        glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
        updateGL ();
        break;
    case Qt::Key_Down:
        if(!scene.gameOver() && !scene.pause()) {
            scene.keyDown();
            updateGL ();
        }
        break;
    case Qt::Key_Up:
        if(!scene.gameOver() && !scene.pause()) {
            scene.keyUp();
            updateGL ();
        }
        break;
    case Qt::Key_Right:
        if(!scene.gameOver() && !scene.pause()) {
            scene.keyRight();
            updateGL ();
        }
        break;
    case Qt::Key_Left:
        if(!scene.gameOver() && !scene.pause()) {
            scene.keyLeft();
            updateGL ();
        }
        break;
    case Qt::Key_X:
        if(!scene.gameOver() && !scene.pause()) {
            scene.keyX();
            updateGL ();
        }
        break;
        //inici codi --
    case Qt::Key_T:
            scene.setPointLight();
            updateGL ();
        break;
    case Qt::Key_Y:
            scene.movePointLight();
            updateGL ();
        break;
        // fi
    default: e->ignore(); break;
  }
  updateGL();
}

void GLWidget::mouseReleaseEvent( QMouseEvent *)
{
  DoingInteractive = NONE;
}

void GLWidget::mouseMoveEvent(QMouseEvent *e)
{
  // Aqui cal que es calculi i s'apliqui la rotaci, el zoom o el pan
  // com s'escaigui...
  if (DoingInteractive == ROTATE)
  {
    // Fem la rotacio
    _oriy -= (xClick-e->x())/2;
    _orix -= (yClick-e->y())/2;
  }
  else if (DoingInteractive == ZOOM)
  {
    // Fem el zoom
      _fov -= (yClick-e->y());
      if(_fov > 179) _fov = 179;
      else if(_fov < 1) _fov = 1;
  }
  else if (DoingInteractive==PAN)
  {
    // Fem el pan
      _panx -= (xClick-e->x())/4;
      _pany += (yClick-e->y())/4;
  }

  xClick = e->x();
  yClick = e->y();

  updateGL();
}

void GLWidget::CarregaPersonatge ()
{
  // Aquí s'ha de carregar el personatge.    

    QString name = QFileDialog::getOpenFileName(this, tr("Open File"), "../models", tr("Objectes (*.obj)"));
    if(name != ""){
        const char *finalName = name.toLatin1();
        scene.loadMainCharacter(finalName);
        updateGL();
    }


}


void GLWidget::carregaEnemics ()
{
  // Aquí s'ha de carregar el personatge.

    QString name = QFileDialog::getOpenFileName(this, tr("Open File"), "../models", tr("Objectes (*.obj)"));
    if(name != ""){
        const char *finalName = name.toLatin1();
        scene.loadEnemies(finalName);
        updateGL();
    }


}

void GLWidget::startGame () {
    if (scene.pause()) {
        scene.resume();
    }
    else scene.start();
    _timer->start(25);
    updateGL();
}

void GLWidget::aturaJoc() {
    _timer->stop();
    scene.resume();
    scene.aturaJoc();
    updateGL();
}


void GLWidget::pausaJoc() {
    _timer->stop();
    scene.pausaJoc();
    updateGL();
}

void GLWidget::canviaLaberint(int tamany) {
    scene.setLaberint(tamany);
    this->resetCamera();
    updateGL();
}

void GLWidget::canviaEnemics(int num) {
    scene.setEnemies(num);
    updateGL();
}

void GLWidget::primeraPersona() {
    _firstPerson = true;
    scene.setFirstPerson (true);
    updateGL();
}

void GLWidget::rotateRight() {
    scene.setRotationDreta();
    updateGL();
}

void GLWidget::rotateDown() {
    scene.setRotationAvall();
    updateGL();
}

void GLWidget::rotateUp() {
    scene.setRotationAmunt();
    updateGL();
}

void GLWidget::rotateLeft() {
    scene.setRotationEsquerra();
    updateGL();
}


