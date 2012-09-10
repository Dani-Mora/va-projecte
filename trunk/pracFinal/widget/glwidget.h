#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QFileDialog>
#include <QTimer>
#include "point.h"
#include "scene.h"

class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = 0);

protected:
    void initializeGL ();
    void paintGL ();
    void resizeGL (int width, int height);

    // Valors per defecte visualització

    /*#define CAMERAX 5
    #define CAMERAY 5
    #define CAMERAZ 5*/

    #define CAMDIST 5

    #define VRPX 5
    #define VRPY 0
    #define VRPZ 5

    /*#define UPX 0
    #define UPY 0
    #define UPZ -1*/

    #define FOV 55
    #define NEAR 0.1
    #define FAR 100.0
    #define HEIGHT 400
    #define WIDTH 400

    #define DEFAULT_ORIX 90;
    #define DEFAULT_ORIY 0;
    #define DEFAULT_ORIZ 0;

    #define DEFAULTPANX 0;
    #define DEFAULTPANY 0;

    // Atributs de la visualització

    /* Posicio de l'observador */
    //Point _camera;

    /* Distància de la càmera a l'escena*/
    float _camDist;

    /* Pan */
    float _panx;
    float _pany;

    /* Orientació de la càmera*/
    float _orix ;
    float _oriy ;
    float _oriz ;

    /* View Reference point */
    Point _vrp;

    /* Vector up */
    //Point _up;

    /* Angle vertical d'obertura de la camera */
    float _fov;

    /* Distància pla near */
    float _near;

    /* Distància horitzó */
    float _far;

    /*  Mida de la vista */
    float _height;
    float _width;

    /* Timers */
    QTimer *_timer;

    /* Primera persona */
    bool _firstPerson;



    //----------------------------------------------------------//
    //                      FUNCIONS                            //
    //----------------------------------------------------------//

    /**
     Inicialitza les variables que s'utilitzaran durant la visualització amb els valors per defecte
    */
    void initVariables();

    /**
      Inicialitza la càmera amb els valors per defecte per primera vegada
    */
    void initCamera();

    /**
      Localitza la camera amb els valor corresponents segons l'execució en curs i actualitza el GL
     */
    void setCamera();

    /**
      Gestiona els click del mouse
    */
    virtual void mousePressEvent (QMouseEvent *e);

    /**
      Gestiona els realease del mouse
    */
    virtual void mouseReleaseEvent (QMouseEvent *e);

    /**
      Gestiona els moviments del mouse
    */
    virtual void mouseMoveEvent (QMouseEvent *e);

    /**
      Gestiona events de teclar
    */
    virtual void keyPressEvent (QKeyEvent *event);

    /**
      Inicialitza la iluminació de l'escena
    */
    void initLighting();

    /**
      Inicialitza la gestió de cares ocultes
    */
    void initCulling();

    Scene scene;

    typedef  enum {NONE, ROTATE, ZOOM, PAN, FAKECOLOR} InteractiveAction;
    InteractiveAction DoingInteractive;

    int   xClick, yClick;


//----------------------------------------------------------//
//                      SLOTS                               //
//----------------------------------------------------------//

  public slots:

    /**
     Carrega personatges i enemics i comença el joc activant timers.
    */
    void CarregaPersonatge ();

    /**
     Carrega personatges i enemics i comença el joc activant timers.
    */
    void carregaEnemics ();


    /**
      Canvia la mida del laberint
     */
    void canviaLaberint(int tamany);

    /**
     Canvia el nombre d'enemics de l'escena
     */
    void canviaEnemics(int num);

    /**
     Seteja la càmera a la posició per defecte i la projecció per defecte
    */
    void resetCamera();

    /**
      Refresca l'escena recalculant la posició dels seus elements i moviments de personatge.Acaba el joc si cal.
     */
    void refresh();

    /**
      Mou la càmera a primera persona
    */
    void primeraPersona();

    /**
      Comença el joc
    */
    void startGame();

    /**
      Comença el joc
    */
    void pausaJoc();

    /**
      Atura el joc. Elimina personatges i atura els timer
    */

    void aturaJoc();

    /**
      Gira el personatge a la dreta
    */
    void rotateRight();

    /**
      Gira el personatge a la dreta
    */
    void rotateUp();

    /**
      Gira el personatge a la dreta
    */
    void rotateLeft();

    /**
      Gira el personatge a la dreta
    */
    void rotateDown();

    /**
      Activa les cares ocultes
    */
    void enableCulling();

    /**
      Desactiva les cares ocultes
    */
    void disableCulling();

    /**
      Activa la llum ambiental
    */
    void enableAmbientalLight();

    /**
      Desactiva la llum ambiental
    */
    void disableAmbientalLight();

    /**
      Activa la llanterna
    */
    void enableSpot();

    /**
      Desactiva la llanterna
    */
    void disableSpot();

    /**
      Activa el focus superior
    */
    void enableFocus();

    /**
      Desactiva el focus superior
    */
    void disableFocus();

    /**
      Canvia la posició x del focus
    */
    void setFocusX (double x);

    /**
      Canvia la posició y del focus
    */
    void setFocusZ (double z);

    /**
      Canvia composició de verds del focus superior
    */
    void setGreenFocus(int x);

    /**
      Canvia composició de vermells del focus superior
    */
    void setRedFocus(int x);

    /**
      Canvia composició de blaus del focus superior
    */
    void setBlueFocus(int x);

    /**
      Canvia composició de verds de la llanterna
    */
    void setGreenSpot(int x);

    /**
      Canvia composició de vermells de la llanterna
    */
    void setRedSpot(int x);

    /**
      Canvia composició de blaus de la llanterna
    */
    void setBlueSpot(int x);

    /**
      Canvia composició de verds de la llum ambiental
    */
    void setGreenAmbientalLight(int x);

    /**
      Canvia composició de vermells de la llum ambiental
    */
    void setRedAmbientalLight(int x);

    /**
      Canvia composició de blaus de la llum ambiental
    */
    void setBlueAmbientalLight(int x);

};

#endif
