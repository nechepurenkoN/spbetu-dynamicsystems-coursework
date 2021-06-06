cmake_minimum_required(VERSION 3.19)
project(spbetu_dynamicsystems_coursework)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH "C:\\Qt\\5.15.2\\mingw81_64")
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt53DCore REQUIRED)
find_package(Qt53DInput REQUIRED)
find_package(Qt53DExtras REQUIRED)
find_package(Qt53DRender REQUIRED)
include_directories(gui)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
add_executable(spbetu_dynamicsystems_coursework
        gui/scenemodifier.cpp
        gui/scenemodifier.h
        gui/mainwindow.cpp
        gui/mainwindow.h
        gui/plane.cpp
        gui/plane.h
        gui/sphere.cpp
        gui/sphere.h
        gui/displaysurface.cpp
        gui/displaysurface.h
        session/session.cpp
        session/session.h
        solvers/euler.cpp
        solvers/euler.h
        solvers/rk4.cpp
        solvers/rk4.h
        solvers/ab3.cpp
        solvers/ab3.h
        solvers/solver.cpp
        solvers/solver.h
        utils/particle.cpp
        utils/particle.h
        utils/point3d.cpp
        utils/point3d.h
        utils/rhsfunction.cpp
        utils/rhsfunction.h
        utils/state.cpp
        utils/state.h
        tests/runner.cpp
        tests/runner.h
        main.cpp)
target_link_libraries(spbetu_dynamicsystems_coursework Qt5::Core)
target_link_libraries(spbetu_dynamicsystems_coursework Qt5::Widgets)
target_link_libraries(spbetu_dynamicsystems_coursework Qt5::Gui)
target_link_libraries(spbetu_dynamicsystems_coursework Qt5::3DCore)
target_link_libraries(spbetu_dynamicsystems_coursework Qt5::3DExtras)
target_link_libraries(spbetu_dynamicsystems_coursework Qt5::3DInput)
target_link_libraries(spbetu_dynamicsystems_coursework Qt5::3DRender)
