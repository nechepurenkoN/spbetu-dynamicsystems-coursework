#include "tests/energyequilibrium.h"
#include "tests/trajectory.h"
#include "gui/mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
//    Trajectory t;
//    t.run();
//    energyequilibrium e;
//    e.run();
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    return a.exec();
}
