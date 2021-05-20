#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QTextEdit>

#include "canvas.h"
#include "utils/particle.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QHBoxLayout* mainLayout;
    Canvas* canvas;
    QWidget* widget;
    QVBoxLayout *toolsLayout;
    QTextEdit* textEdit;
    Particle* particle;
    void init();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
