#include "tests/runner.h"
#include "gui/mainwindow.h"

#include <QApplication>
#include <QLocale>

int main(int argc, char *argv[])
{
    Runner r;
    r.run();
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    return a.exec();
}
