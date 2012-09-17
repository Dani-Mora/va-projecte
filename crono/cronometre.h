#ifndef CRONOMETRE_H
#define CRONOMETRE_H

#include <QtGui/QWidget>

#include <qwidget.h>
#include<QLayout>
#include<QPushButton>
#include<QLabel>
#include<QSpinBox>
#include<QLCDNumber>
#include<QTimer>


class Cronometre : public QWidget {
  Q_OBJECT

  public:
    Cronometre(QWidget *parent = 0);

  private:
    int numEvents, interval, numero;
    QPushButton *inici;
    QPushButton *pausa;
    QPushButton *reset;
    QSpinBox *valor;
    QLabel *seg1;
    QLabel *seg2;
    QLCDNumber  *pantalla;
    QHBoxLayout *botons;
    QHBoxLayout *segons;
    QVBoxLayout *main;
    QTimer *temps;
    void pintaSegon();

  signals:
    void iniciarCrono();
    void pausarCrono();
    void canviaColor();
    void resetejarCrono();

   public slots:
    void acaba();
    void inicia();
    void pausar();
    void reinicia();
};

#endif
