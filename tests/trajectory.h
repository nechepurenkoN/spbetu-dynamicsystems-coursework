#ifndef TRAJECTORY_H
#define TRAJECTORY_H
#include <vector>
#include <cmath>
#include <fstream>

#include <utils/point3d.h>
#include <utils/rhsfunction.h>
#include <utils/state.h>

#include <solvers/rk4.h>
#include <solvers/ab3.h>
#include <solvers/euler.h>

class Trajectory
{
public:
    void run();
};

#endif // TRAJECTORY_H
