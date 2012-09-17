/********************************************************************************
** Form generated from reading UI file 'lightform.ui'
**
** Created: Mon Jun 6 17:02:21 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIGHTFORM_H
#define UI_LIGHTFORM_H

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

class Ui_lightForm
{
public:
    QWidget *tab;
    QLabel *label;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSlider *rSlide;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSlider *gSlide;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QSlider *bSlide;
    QWidget *tab1;
    QSlider *heightSlide;
    QLabel *label_5;
    QWidget *tab_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer;
    QCheckBox *activate;

    void setupUi(QTabWidget *lightForm)
    {
        if (lightForm->objectName().isEmpty())
            lightForm->setObjectName(QString::fromUtf8("lightForm"));
        lightForm->resize(341, 255);
        lightForm->setMinimumSize(QSize(341, 255));
        lightForm->setMaximumSize(QSize(341, 255));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 231, 16));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 50, 291, 161));
        QFont font1;
        font1.setPointSize(11);
        groupBox->setFont(font1);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        rSlide = new QSlider(groupBox);
        rSlide->setObjectName(QString::fromUtf8("rSlide"));
        rSlide->setMaximum(255);
        rSlide->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(rSlide);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        gSlide = new QSlider(groupBox);
        gSlide->setObjectName(QString::fromUtf8("gSlide"));
        gSlide->setMaximum(255);
        gSlide->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(gSlide);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        bSlide = new QSlider(groupBox);
        bSlide->setObjectName(QString::fromUtf8("bSlide"));
        bSlide->setMaximum(255);
        bSlide->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(bSlide);


        verticalLayout->addLayout(horizontalLayout_3);

        lightForm->addTab(tab, QString());
        tab1 = new QWidget();
        tab1->setObjectName(QString::fromUtf8("tab1"));
        heightSlide = new QSlider(tab1);
        heightSlide->setObjectName(QString::fromUtf8("heightSlide"));
        heightSlide->setGeometry(QRect(20, 80, 271, 61));
        heightSlide->setContextMenuPolicy(Qt::DefaultContextMenu);
        heightSlide->setMinimum(0);
        heightSlide->setMaximum(47);
        heightSlide->setOrientation(Qt::Horizontal);
        label_5 = new QLabel(tab1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 30, 291, 16));
        label_5->setFont(font);
        lightForm->addTab(tab1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        layoutWidget = new QWidget(tab_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(21, 30, 161, 22));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        horizontalLayout_4->addWidget(label_6);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        activate = new QCheckBox(layoutWidget);
        activate->setObjectName(QString::fromUtf8("activate"));
        activate->setChecked(true);

        horizontalLayout_4->addWidget(activate);

        lightForm->addTab(tab_2, QString());

        retranslateUi(lightForm);

        lightForm->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(lightForm);
    } // setupUi

    void retranslateUi(QTabWidget *lightForm)
    {
        lightForm->setWindowTitle(QApplication::translate("lightForm", "TabWidget", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("lightForm", "Tria el color de la llum seleccionada", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("lightForm", "Light Color", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("lightForm", "R", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("lightForm", "G", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("lightForm", "B", 0, QApplication::UnicodeUTF8));
        lightForm->setTabText(lightForm->indexOf(tab), QApplication::translate("lightForm", "Color", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("lightForm", "Modifica l'al\303\247ada relativa a l'objecte del focus", 0, QApplication::UnicodeUTF8));
        lightForm->setTabText(lightForm->indexOf(tab1), QApplication::translate("lightForm", "Height", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("lightForm", "Focus Activat", 0, QApplication::UnicodeUTF8));
        activate->setText(QString());
        lightForm->setTabText(lightForm->indexOf(tab_2), QApplication::translate("lightForm", "Activate/Desactivate", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class lightForm: public Ui_lightForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIGHTFORM_H
