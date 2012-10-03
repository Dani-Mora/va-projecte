#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Principal)
{
    ui->setupUi(this);

    this->connect(this->ui->immediateButton, SIGNAL(clicked()), this->ui->gLWidget, SLOT(setImmediateRender()));
    this->connect(this->ui->vertexArrayButton, SIGNAL(clicked()), this->ui->gLWidget, SLOT(setVertexArrayRender()));
    this->connect(this->ui->bufferObjectButton, SIGNAL(clicked()), this->ui->gLWidget, SLOT(setVertexBufferObjectRender()));
}

Principal::~Principal()
{
    delete ui;
}

void Principal::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
