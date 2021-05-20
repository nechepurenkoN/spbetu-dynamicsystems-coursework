#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{    
    particle = new Particle(10, 10, 1, 2);
    widget = new QWidget();
    mainLayout = new QHBoxLayout();
    canvas = new Canvas(particle);
    toolsLayout = new QVBoxLayout();
    textEdit = new QTextEdit();
    init();
}

void MainWindow::init(){
    setFixedSize(600, 470);
    setCentralWidget(widget);
    widget->setLayout(mainLayout);
    mainLayout->addWidget(canvas);
    toolsLayout->addWidget(textEdit);
    mainLayout->addLayout(toolsLayout);
}

MainWindow::~MainWindow()
{
    delete mainLayout;
    delete canvas;
    delete widget;
    delete toolsLayout;
    delete textEdit;
    delete particle;
}

