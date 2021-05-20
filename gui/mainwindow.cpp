#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{    
    this->setFixedSize(600, 470);
    widget = new QWidget();
    this->setCentralWidget(widget);

    mainLayout = new QHBoxLayout();
    widget->setLayout(mainLayout);

    canvas = new Canvas();
    mainLayout->addWidget(canvas);

    toolsLayout = new QVBoxLayout();
    textEdit = new QTextEdit();
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
}

