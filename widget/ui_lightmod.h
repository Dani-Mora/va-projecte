/********************************************************************************
** Form generated from reading UI file 'lightmod.ui'
**
** Created: Tue May 24 20:15:53 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIGHTMOD_H
#define UI_LIGHTMOD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_desactive
{
public:
    QWidget *color;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *text1;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_20;
    QLabel *r_7;
    QSlider *rA;
    QHBoxLayout *horizontalLayout_21;
    QLabel *g_7;
    QSlider *gA;
    QHBoxLayout *horizontalLayout_22;
    QLabel *b_7;
    QSlider *bA;
    QSpacerItem *verticalSpacer;
    QWidget *height;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *text2;
    QSlider *heightSlide;
    QWidget *tab;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QCheckBox *activateF;

    void setupUi(QTabWidget *desactive)
    {
        if (desactive->objectName().isEmpty())
            desactive->setObjectName(QString::fromUtf8("desactive"));
        desactive->resize(400, 200);
        desactive->setMinimumSize(QSize(400, 200));
        desactive->setMaximumSize(QSize(400, 200));
        desactive->setTabPosition(QTabWidget::North);
        color = new QWidget();
        color->setObjectName(QString::fromUtf8("color"));
        verticalLayout_3 = new QVBoxLayout(color);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        text1 = new QLabel(color);
        text1->setObjectName(QString::fromUtf8("text1"));

        horizontalLayout_3->addWidget(text1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(horizontalLayout_3);

        groupBox_7 = new QGroupBox(color);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        verticalLayout = new QVBoxLayout(groupBox_7);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        r_7 = new QLabel(groupBox_7);
        r_7->setObjectName(QString::fromUtf8("r_7"));

        horizontalLayout_20->addWidget(r_7);

        rA = new QSlider(groupBox_7);
        rA->setObjectName(QString::fromUtf8("rA"));
        rA->setMaximum(255);
        rA->setOrientation(Qt::Horizontal);

        horizontalLayout_20->addWidget(rA);


        verticalLayout->addLayout(horizontalLayout_20);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        g_7 = new QLabel(groupBox_7);
        g_7->setObjectName(QString::fromUtf8("g_7"));

        horizontalLayout_21->addWidget(g_7);

        gA = new QSlider(groupBox_7);
        gA->setObjectName(QString::fromUtf8("gA"));
        gA->setMaximum(255);
        gA->setOrientation(Qt::Horizontal);

        horizontalLayout_21->addWidget(gA);


        verticalLayout->addLayout(horizontalLayout_21);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        b_7 = new QLabel(groupBox_7);
        b_7->setObjectName(QString::fromUtf8("b_7"));

        horizontalLayout_22->addWidget(b_7);

        bA = new QSlider(groupBox_7);
        bA->setObjectName(QString::fromUtf8("bA"));
        bA->setMaximum(255);
        bA->setOrientation(Qt::Horizontal);

        horizontalLayout_22->addWidget(bA);


        verticalLayout->addLayout(horizontalLayout_22);


        verticalLayout_3->addWidget(groupBox_7);

        verticalSpacer = new QSpacerItem(20, 14, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        desactive->addTab(color, QString());
        height = new QWidget();
        height->setObjectName(QString::fromUtf8("height"));
        widget = new QWidget(height);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 31, 311, 61));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        text2 = new QLabel(widget);
        text2->setObjectName(QString::fromUtf8("text2"));

        verticalLayout_2->addWidget(text2);

        heightSlide = new QSlider(widget);
        heightSlide->setObjectName(QString::fromUtf8("heightSlide"));
        heightSlide->setMinimum(0);
        heightSlide->setMaximum(50);
        heightSlide->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(heightSlide);

        desactive->addTab(height, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        widget1 = new QWidget(tab);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(30, 30, 86, 15));
        horizontalLayout_4 = new QHBoxLayout(widget1);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget1);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_4->addWidget(label);

        activateF = new QCheckBox(widget1);
        activateF->setObjectName(QString::fromUtf8("activateF"));
        activateF->setChecked(true);

        horizontalLayout_4->addWidget(activateF);

        desactive->addTab(tab, QString());

        retranslateUi(desactive);

        desactive->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(desactive);
    } // setupUi

    void retranslateUi(QTabWidget *desactive)
    {
        desactive->setWindowTitle(QApplication::translate("desactive", "TabWidget", 0, QApplication::UnicodeUTF8));
        text1->setText(QApplication::translate("desactive", "Modifica els components RGB del color de la llum seleccionada", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("desactive", "Light Color", 0, QApplication::UnicodeUTF8));
        r_7->setText(QApplication::translate("desactive", "R", 0, QApplication::UnicodeUTF8));
        g_7->setText(QApplication::translate("desactive", "G", 0, QApplication::UnicodeUTF8));
        b_7->setText(QApplication::translate("desactive", "B", 0, QApplication::UnicodeUTF8));
        desactive->setTabText(desactive->indexOf(color), QApplication::translate("desactive", "Color", 0, QApplication::UnicodeUTF8));
        text2->setText(QApplication::translate("desactive", "Selecciona l'altura relativa a l'objecte", 0, QApplication::UnicodeUTF8));
        desactive->setTabText(desactive->indexOf(height), QApplication::translate("desactive", "Height", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("desactive", "Focus Activat", 0, QApplication::UnicodeUTF8));
        activateF->setText(QString());
        desactive->setTabText(desactive->indexOf(tab), QApplication::translate("desactive", "Activate/Desactivate", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class desactive: public Ui_desactive {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIGHTMOD_H
