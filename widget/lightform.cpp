#include "lightform.h"
#include "ui_lightform.h"
#include <iostream>
using namespace std;

lightForm::lightForm(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::lightForm)
{
    ui->setupUi(this);
    // A l'inici la llum seleccionada es la 0 i el color el default
    this->setWindowTitle("Modificant focus Light0");
    ui->tab1->setEnabled(false);
    ui->tab_2->setEnabled(false);

    ui->rSlide->setValue(150);
    ui->gSlide->setValue(150);
    ui->bSlide->setValue(150);

    // Fem connects
    connect(ui->rSlide, SIGNAL(valueChanged(int)), this, SLOT(changeColor()));
    connect(ui->gSlide, SIGNAL(valueChanged(int)), this, SLOT(changeColor()));
    connect(ui->bSlide, SIGNAL(valueChanged(int)), this, SLOT(changeColor()));
    connect(ui->heightSlide, SIGNAL(valueChanged(int)), this, SLOT(changeHeight()));
    connect(ui->activate, SIGNAL(clicked()), this, SLOT(changeEncesa()));
}

lightForm::~lightForm()
{
    delete ui;
}

/* Funcions que es criden en modificar valors */

void lightForm::changeColor()
{
    emit updateColor(ui->rSlide->value(), ui->gSlide->value(), ui->bSlide->value());
}


void lightForm::changeHeight()
{
    emit updateHeight(ui->heightSlide->value());
}

void lightForm::changeEncesa()
{
    emit updateActivate(ui->activate->checkState());
}

/* Es criden en seleccionar un focus, per fer un set dels slides */

void lightForm::setTitle(int id)
{
    if (id == -1) {
        this->setWindowTitle("Modificant focus Light0");
        ui->tab1->setEnabled(false);
        ui->tab_2->setEnabled(false);
    }
    else {
        ui->tab1->setEnabled(true);
        ui->tab_2->setEnabled(true);
        if (id == 0) this->setWindowTitle("Modificant focus Light1");
        else if (id == 1) this->setWindowTitle("Modificant focus Light2");
        else this->setWindowTitle("Modificant focus Light3");
    }
}

void lightForm::setColor(int r, int g, int b)
{
    ui->rSlide->setValue(r);
    ui->gSlide->setValue(g);
    ui->bSlide->setValue(b);

}

void lightForm::setHeightValue(int h)
{
    ui->heightSlide->setValue(h);
}

void lightForm::setActivateLight(bool a)
{
    ui->activate->setChecked(a);
}
