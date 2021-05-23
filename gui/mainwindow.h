#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "scenemodifier.h"
#include "../session/session.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QTextEdit>
#include <QLabel>
#include <QSlider>

#include <Qt3DExtras/qt3dwindow.h>
#include <Qt3DExtras/qforwardrenderer.h>
#include <Qt3DExtras/qfirstpersoncameracontroller.h>

#include <Qt3DCore/qentity.h>
#include <Qt3DCore/qtransform.h>

#include <Qt3DRender/qcamera.h>
#include <Qt3DRender/qpointlight.h>

#include <iostream>



class MainWindow : public QMainWindow
{
    Q_OBJECT

    QHBoxLayout* mainLayout;
    QWidget* mainWidget;

    Qt3DExtras::Qt3DWindow *view;
    QWidget *container;
    Qt3DCore::QEntity *rootEntity;
    Qt3DRender::QCamera *cameraEntity;
    Qt3DCore::QEntity *lightEntity;
    Qt3DRender::QPointLight *light;
    Qt3DExtras::QFirstPersonCameraController *camController;
    SceneModifier *modifier;

    QVBoxLayout *toolsLayout;
    QSlider *xSpeedSlider;
    QSlider *ySpeedSlider;
    QSlider *zSpeedSlider;
    Particle* particle;
    std::thread solverThread;
    void init();
    void updateParticle(Point3D s);
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
