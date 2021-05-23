//
// Created by 79612 on 22.05.2021.
//

#ifndef SPBETU_DYNAMICSYSTEMS_COURSEWORK_SOLVER_H
#define SPBETU_DYNAMICSYSTEMS_COURSEWORK_SOLVER_H

#include <functional>
#include <queue>
#include <utility>
#include <memory>
#include "point3d.h"


class State {
public:
    Point3D coordinate;
    Point3D velocity;
    double charge;

    State(const Point3D &coordinate, const Point3D &velocity, double charge);
};

std::ostream &operator<<(std::ostream &os, const State &state);

class RhsFunction {
public:
    virtual State apply(State state) = 0;
};

class EMFieldMovingFunction : public RhsFunction {
    double electricFieldValue;

private:
    double magneticFieldValue;
    Point3D electricFieldDirection;
    Point3D magneticFieldDirection;
public:
    EMFieldMovingFunction(const Point3D &electricFieldDirection, const Point3D &magneticFieldDirection,
                          double electricFieldValue, double magneticFieldValue);

    State apply(State state) override;

    void setElectricFieldValue(double electricFieldValue);

    void setMagneticFieldValue(double magneticFieldValue);

    void setElectricFieldDirection(const Point3D &electricFieldDirection);

    void setMagneticFieldDirection(const Point3D &magneticFieldDirection);
};

class Solver {
public:
    virtual void solve(State initialState) = 0;
};

class EulerSolver : public Solver {
    std::queue<State> previousStates;
    std::shared_ptr<RhsFunction> rhsFunction;
    std::function<void(State)> onUpdateConsumer;
    double h;
    int maxIterations = 0;
protected:
    State step();

public:
    EulerSolver(
            std::shared_ptr<RhsFunction> rhsFunction,
            std::function<void(State)> onUpdateConsumer_,
            double h_ = 0.01, int maxIterations_ = 10000);


    void solve(State initialState) override;
};


#endif //SPBETU_DYNAMICSYSTEMS_COURSEWORK_SOLVER_H
