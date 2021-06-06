#include "mainwindow.h"

#include <memory>


MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent) {
    eFieldNormal = QVector3D(1, 0, 0);
    mFields.push_back(new UniformField(-1, Point3D(0, 0, 1)));
    mFields.push_back(new UniformField(-1, Point3D(0, 1, 0)));
    displayCoord = QVector3D(10, 0, 0);
    auto ptr = new EMFieldMovingFunction();
    ptr->addElectricField(new UniformField(10, Point3D(eFieldNormal.x(), eFieldNormal.y(), eFieldNormal.z())));
    for (auto field: mFields){
        ptr->addMagneticField(field);
    }
    ptr->addDisplay(displayCoord, eFieldNormal);
    rhs = std::shared_ptr<RhsFunction>(ptr);
    mainWidget = new QWidget();
    mainLayout = new QHBoxLayout();
    toolsWidget = new QWidget();
    toolsLayout = new QVBoxLayout();
    verticalFieldValue = new QLabel();
    horizontalFieldValue = new QLabel();
    verticalFieldLabel = new QLabel("Up-Down Field:");
    horizontalFieldLabel = new QLabel("Left-Right Field:");
    defaultViewButton = new QPushButton("Default View");
    view = new Qt3DExtras::Qt3DWindow();
    container = QWidget::createWindowContainer(view);
    session = Session();
    init();
    generateParticles();
    session.start(particles, rhs, verticalFieldValue, horizontalFieldValue);

}

void MainWindow::init() {
    setMinimumSize(600, 470);
    showMaximized();
    setCentralWidget(mainWidget);
    view->defaultFrameGraph()->setClearColor(QColor(QRgb(0xaaaaaa)));
    mainWidget->setLayout(mainLayout);
    mainLayout->addWidget(container);
    toolsWidget->setLayout(toolsLayout);
    toolsWidget->setMaximumWidth(200);
    mainLayout->addWidget(toolsWidget);

    toolsLayout->setAlignment(Qt::AlignTop);

    QFont fontLabel("Arial", 15, QFont::Bold);
    QFont fontValue("Arial", 15);
    verticalFieldLabel->setFont(fontLabel);
    verticalFieldValue->setFont(fontValue);
    horizontalFieldLabel->setFont(fontLabel);
    horizontalFieldValue->setFont(fontValue);

    toolsLayout->addWidget(verticalFieldLabel);
    toolsLayout->addWidget(verticalFieldValue);
    toolsLayout->addWidget(horizontalFieldLabel);
    toolsLayout->addWidget(horizontalFieldValue);
    defaultViewButton->setFocusPolicy(Qt::NoFocus);
    toolsLayout->addWidget(defaultViewButton);

    rootEntity = new Qt3DCore::QEntity();

    // Camera
    cameraEntity = view->camera();

    cameraEntity->lens()->setPerspectiveProjection(45.0f, 16.0f / 9.0f, 0.1f, 1000.0f);
    cameraEntity->setPosition(QVector3D(-20.0f, 5.0f, 10.0f));
    cameraEntity->setUpVector(QVector3D(0, 1, 0));
    cameraEntity->setViewCenter(QVector3D(0, 0, 0));

    Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(rootEntity);
    light = new Qt3DRender::QPointLight(lightEntity);
    light->setColor("white");
    light->setIntensity(1);
    lightEntity->addComponent(light);
    Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform(lightEntity);
    lightTransform->setTranslation(QVector3D(-20.0f, 20.0f, 20.0f));
    lightEntity->addComponent(lightTransform);

    // For camera controls
    camController = new Qt3DExtras::QFirstPersonCameraController(rootEntity);
    camController->setCamera(cameraEntity);

    // Scenemodifier
    std::vector<QVector3D> mFieldsCoords;
    for (auto field: mFields){
        mFieldsCoords.push_back(QVector3D(field->direction.x, field->direction.y, field->direction.z));
    }
    modifier = new SceneModifier(rootEntity, eFieldNormal, mFieldsCoords, displayCoord);
    view->setRootEntity(rootEntity);

    connect(defaultViewButton, &QPushButton::clicked, this, &MainWindow::setDefaultView);

}

void MainWindow::closeEvent(QCloseEvent *event) {
    std::cout << "terminating solver thread" << std::endl;
    session.stop();
}

MainWindow::~MainWindow() {
    delete mainLayout;
    delete mainWidget;
    delete toolsWidget;
    delete toolsLayout;
    delete verticalFieldLabel;
    delete verticalFieldValue;
    delete horizontalFieldLabel;
    delete horizontalFieldValue;
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
    for (int i = 0; i < 121; i++) {
        auto *p = new Particle(0, 0, 0);
        auto *s = new Sphere(rootEntity, p);
        modifier->addSphere(s);
        particles.push_back(p);
    }
}

void MainWindow::setDefaultView()
{
    cameraEntity->setPosition(QVector3D(-20.0f, 0.0f, 0.0f));
    cameraEntity->setUpVector(QVector3D(0, 1, 0));
    cameraEntity->setViewCenter(QVector3D(0, 0, 0));
}

