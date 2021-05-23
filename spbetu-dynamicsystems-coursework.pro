QT += 3dcore 3drender 3dinput 3dextras
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    gui/plane.cpp \
    gui/sphere.cpp \
    main.cpp \
    gui/mainwindow.cpp \
    gui/scenemodifier.cpp \
    session/session.cpp \
    solvers/euler.cpp \
    solvers/rk4.cpp \
    solvers/solver.cpp \
    utils/rhsfunction.cpp \
    utils/particle.cpp \
    utils/point3d.cpp \
    utils/state.cpp

HEADERS += \
    gui/mainwindow.h \
    gui/plane.h \
    gui/scenemodifier.h \
    gui/sphere.h \
    gui/sphere.h \
    session/session.h \
    solvers/euler.h \
    solvers/rk4.h \
    utils/rhsfunction.h \
    utils/particle.h \
    utils/point3d.h \
    utils/state.h

CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
