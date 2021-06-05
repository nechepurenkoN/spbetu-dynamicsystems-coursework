#include "mainwindow.h"

#include <memory>


MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent) {
    eFieldCoord = QVector3D(1, 0, 0);
    mFieldCoord = QVector3D(0, 0.1, 1);
    rhs = std::shared_ptr<RhsFunction>(new EMFieldMovingFunction(
            Point3D(eFieldCoord.x(), eFieldCoord.y(), eFieldCoord.z()),
            Point3D(mFieldCoord.x(), mFieldCoord.y(), mFieldCoord.z()), 2, 3));
    mainWidget = new QWidget();
    mainLayout = new QHBoxLayout();
    toolsLayout = new QVBoxLayout();
    view = new Qt3DExtras::Qt3DWindow();
    container = QWidget::createWindowContainer(view);
    session = Session();
    init();
    generateParticles();
    session.start(particles, rhs);

}

void MainWindow::init() {
    setFixedSize(600, 470);
    container->setFixedSize(450, 450);
    setCentralWidget(mainWidget);
    view->defaultFrameGraph()->setClearColor(QColor(QRgb(0xaaaaaa)));
    mainWidget->setLayout(mainLayout);
    mainLayout->addWidget(container);
    mainLayout->addLayout(toolsLayout);

    toolsLayout->setAlignment(Qt::AlignTop);

    rootEntity = new Qt3DCore::QEntity();

    // Camera
    cameraEntity = view->camera();

    cameraEntity->lens()->setPerspectiveProjection(45.0f, 16.0f / 9.0f, 0.1f, 1000.0f);
    cameraEntity->setPosition(QVector3D(11.0f, 5.0f, 20.0f));
    cameraEntity->setUpVector(QVector3D(0, 1, 0));
    cameraEntity->setViewCenter(QVector3D(0, 0, 0));

    Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(rootEntity);
    light = new Qt3DRender::QPointLight(lightEntity);
    light->setColor("white");
    light->setIntensity(1);
    lightEntity->addComponent(light);
    Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform(lightEntity);
    lightTransform->setTranslation(QVector3D(20.0f, 20.0f, 20.0f));
    lightEntity->addComponent(lightTransform);

    // For camera controls
    camController = new Qt3DExtras::QFirstPersonCameraController(rootEntity);
    camController->setCamera(cameraEntity);

    // Scenemodifier
    modifier = new SceneModifier(rootEntity, eFieldCoord, mFieldCoord);
    view->setRootEntity(rootEntity);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    std::cout << "terminating solver thread" << std::endl;
    session.stop();
}

MainWindow::~MainWindow() {
    delete mainLayout;
    delete mainWidget;
    delete toolsLayout;
    delete view;
    delete container;
    delete rootEntity;
    delete cameraEntity;
    delete lightEntity;
    delete light;
    delete camController;
    delete modifier;
    for (auto &particle : particles) {
        delete particle;
    }
}

void MainWindow::generateParticles() {
    for (int i = 0; i < 3; i++) {
        auto *p = new Particle(0, 0, 0);
        auto *s = new Sphere(rootEntity, p);
        modifier->addSphere(s);
        particles.push_back(p);
    }
}

