/********************************************************************************
** Form generated from reading UI file 'principal.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINCIPAL_H
#define UI_PRINCIPAL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_Principal
{
public:
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    GLWidget *gLWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *fps;
    QLabel *fpsText;
    QFrame *frame;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_5;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *scenePanel;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_2;
    QPushButton *reset;
    QGroupBox *renderBox;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *immediateButton;
    QRadioButton *vertexArrayButton;
    QRadioButton *bufferObjectButton;
    QCheckBox *checkBox_3;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QWidget *Principal)
    {
        if (Principal->objectName().isEmpty())
            Principal->setObjectName(QString::fromUtf8("Principal"));
        Principal->setEnabled(true);
        Principal->resize(917, 548);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Principal->sizePolicy().hasHeightForWidth());
        Principal->setSizePolicy(sizePolicy);
        Principal->setContextMenuPolicy(Qt::NoContextMenu);
        horizontalLayout_3 = new QHBoxLayout(Principal);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        gLWidget = new GLWidget(Principal);
        gLWidget->setObjectName(QString::fromUtf8("gLWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(gLWidget->sizePolicy().hasHeightForWidth());
        gLWidget->setSizePolicy(sizePolicy1);
        gLWidget->setMinimumSize(QSize(525, 400));
        gLWidget->setMaximumSize(QSize(50000, 50000));
        gLWidget->setFocusPolicy(Qt::StrongFocus);

        verticalLayout_4->addWidget(gLWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        fps = new QLabel(Principal);
        fps->setObjectName(QString::fromUtf8("fps"));
        fps->setFrameShape(QFrame::WinPanel);

        horizontalLayout_2->addWidget(fps);

        fpsText = new QLabel(Principal);
        fpsText->setObjectName(QString::fromUtf8("fpsText"));
        fpsText->setFrameShape(QFrame::NoFrame);

        horizontalLayout_2->addWidget(fpsText);


        verticalLayout_4->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_4);

        frame = new QFrame(Principal);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(180, 0));
        frame->setMaximumSize(QSize(300, 16777215));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_8 = new QVBoxLayout(frame);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        tabWidget = new QTabWidget(frame);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMinimumSize(QSize(180, 0));
        tabWidget->setMaximumSize(QSize(280, 16777215));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        scenePanel = new QGroupBox(tab);
        scenePanel->setObjectName(QString::fromUtf8("scenePanel"));
        sizePolicy1.setHeightForWidth(scenePanel->sizePolicy().hasHeightForWidth());
        scenePanel->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(scenePanel);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_2 = new QPushButton(scenePanel);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy2);
        pushButton_2->setMinimumSize(QSize(0, 0));

        verticalLayout->addWidget(pushButton_2);

        reset = new QPushButton(scenePanel);
        reset->setObjectName(QString::fromUtf8("reset"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(reset->sizePolicy().hasHeightForWidth());
        reset->setSizePolicy(sizePolicy3);
        reset->setMinimumSize(QSize(0, 0));

        verticalLayout->addWidget(reset);


        verticalLayout_3->addWidget(scenePanel);

        renderBox = new QGroupBox(tab);
        renderBox->setObjectName(QString::fromUtf8("renderBox"));
        verticalLayout_2 = new QVBoxLayout(renderBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        immediateButton = new QRadioButton(renderBox);
        immediateButton->setObjectName(QString::fromUtf8("immediateButton"));

        verticalLayout_2->addWidget(immediateButton);

        vertexArrayButton = new QRadioButton(renderBox);
        vertexArrayButton->setObjectName(QString::fromUtf8("vertexArrayButton"));

        verticalLayout_2->addWidget(vertexArrayButton);

        bufferObjectButton = new QRadioButton(renderBox);
        bufferObjectButton->setObjectName(QString::fromUtf8("bufferObjectButton"));

        verticalLayout_2->addWidget(bufferObjectButton);


        verticalLayout_3->addWidget(renderBox);

        checkBox_3 = new QCheckBox(tab);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setChecked(true);

        verticalLayout_3->addWidget(checkBox_3);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_7 = new QVBoxLayout(tab_2);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        tabWidget->addTab(tab_2, QString());

        verticalLayout_5->addWidget(tabWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy4);

        horizontalLayout->addWidget(pushButton);


        verticalLayout_5->addLayout(horizontalLayout);


        verticalLayout_8->addLayout(verticalLayout_5);


        horizontalLayout_3->addWidget(frame);


        retranslateUi(Principal);
        QObject::connect(pushButton, SIGNAL(clicked()), Principal, SLOT(close()));
        QObject::connect(reset, SIGNAL(clicked()), gLWidget, SLOT(Reset()));
        QObject::connect(checkBox_3, SIGNAL(clicked()), gLWidget, SLOT(hiddenParts()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), gLWidget, SLOT(LoadObject()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Principal);
    } // setupUi

    void retranslateUi(QWidget *Principal)
    {
        Principal->setWindowTitle(QApplication::translate("Principal", "Principal", 0, QApplication::UnicodeUTF8));
        fps->setText(QString());
        fpsText->setText(QApplication::translate("Principal", "FPS", 0, QApplication::UnicodeUTF8));
        scenePanel->setTitle(QApplication::translate("Principal", "Opcions de l'escena", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Principal", "Carregar Objecte", 0, QApplication::UnicodeUTF8));
        reset->setText(QApplication::translate("Principal", "Reset escena", 0, QApplication::UnicodeUTF8));
        renderBox->setTitle(QApplication::translate("Principal", "Opcions de pintat", 0, QApplication::UnicodeUTF8));
        immediateButton->setText(QApplication::translate("Principal", "Immediat", 0, QApplication::UnicodeUTF8));
        vertexArrayButton->setText(QApplication::translate("Principal", "Vertex Array", 0, QApplication::UnicodeUTF8));
        bufferObjectButton->setText(QApplication::translate("Principal", "Vertex Buffer Oject", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QApplication::translate("Principal", "Z-Buffer + Culling", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Principal", "Escena", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Principal", "Tab 2", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Principal", "&Exit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Principal: public Ui_Principal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINCIPAL_H
