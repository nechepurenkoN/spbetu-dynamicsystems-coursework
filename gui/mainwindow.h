#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QTextEdit>

#include "canvas.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QHBoxLayout* mainLayout;
    Canvas* canvas;
    QWidget* widget;
    QVBoxLayout *toolsLayout;
    QTextEdit* textEdit;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
