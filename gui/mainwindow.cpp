#include "mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent) {
    particle = new Particle(0, 0, 0, 0, 0, 0);
    mainWidget = new QWidget();
    mainLayout = new QHBoxLayout();
    toolsLayout = new QVBoxLayout();
    view = new Qt3DExtras::Qt3DWindow();
    container = QWidget::createWindowContainer(view);
    xSpeedSlider = new QSlider(Qt::Horizontal);
    ySpeedSlider = new QSlider(Qt::Horizontal);
    zSpeedSlider = new QSlider(Qt::Horizontal);
    init();
    auto ptr = std::shared_ptr<RhsFunction>(new EMFieldMovingFunction(
            Point3D(1, 0, 0),
            Point3D(0, 0, 1), 2, 3));
    auto s = std::shared_ptr<Solver>(new EulerSolver(
            ptr,
            [this](State state) -> void {
                std::cout << state << std::endl;
                updateParticle(state.coordinate);
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            }, 0.001, 1000
    ));
    State state(Point3D(1,0,0), Point3D(1,1,1), 1);
    s->solve(state);
}

void MainWindow::init() {
    setFixedSize(600, 470);
    container->setFixedSize(450, 450);
    setCentralWidget(mainWidget);
    view->defaultFrameGraph()->setClearColor(QColor(QRgb(0x4d4d4f)));
    mainWidget->setLayout(mainLayout);
    mainLayout->addWidget(container);
    mainLayout->addLayout(toolsLayout);

    toolsLayout->setAlignment(Qt::AlignTop);
    xSpeedSlider->setRange(0, 300);
    ySpeedSlider->setRange(0, 300);
    zSpeedSlider->setRange(0, 300);

    xSpeedSlider->setValue(particle->getX() * 100);
    ySpeedSlider->setValue(particle->getY() * 100);
    zSpeedSlider->setValue(particle->getZ() * 100);

    toolsLayout->addWidget(new QLabel("X"));
    toolsLayout->addWidget(xSpeedSlider);
    toolsLayout->addWidget(new QLabel("Y"));
    toolsLayout->addWidget(ySpeedSlider);
    toolsLayout->addWidget(new QLabel("Z"));
    toolsLayout->addWidget(zSpeedSlider);

    connect(xSpeedSlider, &QSlider::valueChanged, particle, &Particle::setXSpeed);
    connect(ySpeedSlider, &QSlider::valueChanged, particle, &Particle::setYSpeed);
    connect(zSpeedSlider, &QSlider::valueChanged, particle, &Particle::setZSpeed);

    rootEntity = new Qt3DCore::QEntity();

    // Camera
    cameraEntity = view->camera();

    cameraEntity->lens()->setPerspectiveProjection(45.0f, 16.0f / 9.0f, 0.1f, 1000.0f);
    cameraEntity->setPosition(QVector3D(0, 0, 20.0f));
    cameraEntity->setUpVector(QVector3D(0, 1, 0));
    cameraEntity->setViewCenter(QVector3D(0, 0, 0));

    Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(rootEntity);
    light = new Qt3DRender::QPointLight(lightEntity);
    light->setColor("white");
    light->setIntensity(1);
    lightEntity->addComponent(light);
    Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform(lightEntity);
    lightTransform->setTranslation(cameraEntity->position());
    lightEntity->addComponent(lightTransform);

    // For camera controls
    camController = new Qt3DExtras::QFirstPersonCameraController(rootEntity);
    camController->setCamera(cameraEntity);

    // Scenemodifier
    modifier = new SceneModifier(rootEntity, particle);
    view->setRootEntity(rootEntity);

}

void MainWindow::updateParticle(Point3D s)
{
    particle->setX(s.x);
    particle->setY(s.y);
    particle->setZ(s.z);
}

MainWindow::~MainWindow() {
    delete mainLayout;
    delete mainWidget;
    delete toolsLayout;
    delete particle;
    delete view;
    delete container;
    delete rootEntity;
    delete cameraEntity;
    delete lightEntity;
    delete light;
    delete camController;
    delete modifier;
    delete xSpeedSlider;
    delete ySpeedSlider;
    delete zSpeedSlider;
}

