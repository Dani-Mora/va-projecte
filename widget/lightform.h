#ifndef LIGHTFORM_H
#define LIGHTFORM_H

#include <QTabWidget>

namespace Ui {
    class lightForm;
}

class lightForm : public QTabWidget
{
    Q_OBJECT

public:
    explicit lightForm(QWidget *parent = 0);
    ~lightForm();

private:
    Ui::lightForm *ui;
    int id;

public slots:
   void changeColor();
   void changeHeight();
   void changeEncesa();
   void setColor(int r, int g, int b); // Posa als slides els valor actuals del focus seleccionat
   void setHeightValue(int h);
   void setTitle(int l);
   void setActivateLight(bool a);

signals:
   void updateColor(int r, int g, int b); // Avisa d'una modificació en el focus actual
   void updateHeight(int h);
   void updateActivate(bool b);
};

#endif // LIGHTFORM_H
