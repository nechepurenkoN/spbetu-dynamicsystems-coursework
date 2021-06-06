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
#include <QCloseEvent>
#include <Qt3DExtras/qt3dwindow.h>
#include <Qt3DExtras/qforwardrenderer.h>
#include <Qt3DExtras/qfirstpersoncameracontroller.h>

#include <Qt3DCore/qentity.h>
#include <Qt3DCore/qtransform.h>

#include <Qt3DRender/qcamera.h>
#include <Qt3DRender/qpointlight.h>

#include <QPushButton>
#include <iostream>

#include "../utils/rhsfunction.h"
#include "../session/session.h"


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
    std::vector<Particle*> particles;
    QWidget *toolsWidget;
    QVBoxLayout *toolsLayout;

    QLabel *verticalFieldLabel;
    QLabel *horizontalFieldLabel;
    QLabel *verticalFieldValue;
    QLabel *horizontalFieldValue;

    QPushButton* defaultViewButton;

    QVector3D eFieldNormal;
    std::vector<UniformField*> mFields;
    QVector3D displayCoord;
    std::shared_ptr<RhsFunction> rhs;
    Session session;
    void init();

    void closeEvent(QCloseEvent* event);
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void generateParticles();

private slots:
    void setDefaultView();
};
#endif // MAINWINDOW_H
