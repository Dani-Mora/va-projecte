#ifndef LIGHTMOD_H
#define LIGHTMOD_H

#include <QTabWidget>
#include <iostream>
using namespace std;

namespace Ui {
    class lightMod;
}

class lightMod : public QTabWidget
{
    Q_OBJECT

public:
    explicit lightMod(QWidget *parent = 0);
    ~lightMod();
    void setAmb(int r, int g, int b);
    void setDif(int r, int g, int b);
    void setSpec(int r, int g, int b);
    void setHeight(int h);

private:
    Ui::lightMod *ui;


public slots:
    void changeAmb();
    void changeDif();
    void changeSpec();
    void changeHeight();
    void setAmbValue(float r, float g, float b);
    void setDifValue(float r, float g, float b);
    void setSpecValue(float r, float g, float b);
    void setHeightValue(int h);

signals:
    void updateAmb(int r, int g, int b);
    void updateDif(int , int g, int b);
    void updateSpec(int , int g, int b);
    void updateHeight(int h);
};

#endif // LIGHTMOD_H
