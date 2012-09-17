#include "cronometre.h"

// Librerías Qt
#include <qwidget.h>


/******************************************************************************
 * Constructor del Widget.                                                    *
 ******************************************************************************/
Cronometre::Cronometre(QWidget *parent) : QWidget(parent) {

  //posem a 0 els events
  numEvents = 0;

  // inicialitzem variable que marca els segons entre num
  interval = 0;

  //timer
  temps = new QTimer(this);

  //segons a pantalla
  numero = 0;

  //numeros
  pantalla = new QLCDNumber(this);

  //part els labels i l'SpinBox
  seg1 = new QLabel("Interval cada",this,0);
  seg2 = new QLabel("segons", this, 0);

  //botons
  inici = new QPushButton("Iniciar", this);
  pausa = new QPushButton("Pausar", this);
  reset = new QPushButton("Reset", this);

  valor = new QSpinBox(this);
  valor->setRange(1,10);

  segons = new QHBoxLayout;
  botons = new QHBoxLayout;
  main = new QVBoxLayout(this);

  segons->addWidget(seg1);
  segons->addWidget(valor);
  segons->addWidget(seg2);

  botons->addWidget(inici);
  botons->addWidget(pausa);
  botons->addWidget(reset);

  main->addWidget(pantalla);
  main->addLayout(segons);
  main->addLayout(botons);
  this->setLayout(main);

  connect(inici, SIGNAL(clicked()), this, SLOT(inicia())); //iniciar el crono
  connect(temps, SIGNAL(timeout()), this, SLOT(acaba())); //acaba interval
  connect(pausa, SIGNAL(clicked()), this, SLOT(pausar())); //parem el crono
  connect(reset, SIGNAL(clicked()), this, SLOT(reinicia())); //reiniciem el cronometre

}

void Cronometre::inicia() {
  temps->start(1000);
  interval = valor->value();
  emit iniciarCrono();
}

void Cronometre::pausar() {
  temps->stop();
  emit pausarCrono();
}


void Cronometre::pintaSegon() {
  ++numero;
  if (numero == 60) numero = 0;
  pantalla -> display(numero);
}

void Cronometre::acaba() {
  numEvents++;
  pintaSegon();
  if (numEvents == interval) {
    numEvents = 0;
    emit canviaColor();
  }
  temps->start(1000);
}

void Cronometre::reinicia() {
  numero = 0;
  pantalla -> display(0);
  interval = valor->value();
  numEvents = 0;
  emit resetejarCrono();
}
