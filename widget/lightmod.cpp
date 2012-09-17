#include "lightmod.h"
#include "ui_lightmod.h"

lightMod::lightMod(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::lightMod)
{
    ui->setupUi(this);
    connect(ui->rA, SIGNAL(valueChanged(int)), this, SLOT(changeAmb()));
    connect(ui->gA, SIGNAL(valueChanged(int)), this, SLOT(changeAmb()));
    connect(ui->bA, SIGNAL(valueChanged(int)), this, SLOT(changeAmb()));
    connect(ui->rD, SIGNAL(valueChanged(int)), this, SLOT(changeDif()));
    connect(ui->gD, SIGNAL(valueChanged(int)), this, SLOT(changeDif()));
    connect(ui->bD, SIGNAL(valueChanged(int)), this, SLOT(changeDif()));
    connect(ui->rS, SIGNAL(valueChanged(int)), this, SLOT(changeSpec()));
    connect(ui->gS, SIGNAL(valueChanged(int)), this, SLOT(changeSpec()));
    connect(ui->bS, SIGNAL(valueChanged(int)), this, SLOT(changeSpec()));
    connect(ui->heightSlide, SIGNAL(valueChanged(int)), this, SLOT(changeHeight()));
}

lightMod::~lightMod()
{
    delete ui;
}

void lightMod::changeAmb()
{
    emit updateAmb(ui->rA->value(), ui->gA->value(), ui->bA->value());
}

void lightMod::changeDif()
{
    emit updateDif(ui->rD->value(), ui->gD->value(), ui->bD->value());
}

void lightMod::changeSpec()
{
    emit updateSpec(ui->rS->value(), ui->gS->value(), ui->bS->value());
}

void lightMod::changeHeight()
{
    emit updateHeight(ui->heightSlide->value());
}


void lightMod::setAmbValue(float r, float g, float b)
{
    cout << "Funcio del form, poso valors " << r << " " << g << " " << b << endl;

    ui->rA->setValue(r*255);
    ui->gA->setValue(g*255);
    ui->bA->setValue(b*255);
}

void lightMod::setDifValue(float r, float g, float b)
{
    ui->rD->setValue(r*255);
    ui->gD->setValue(g*255);
    ui->bD->setValue(b*255);
}

void lightMod::setSpecValue(float r, float g, float b)
{
    ui->rS->setValue(r*255);
    ui->gS->setValue(g*255);
    ui->bS->setValue(b*255);
}

void lightMod::setHeightValue(int h)
{
    ui->heightSlide->setValue(h);
}
