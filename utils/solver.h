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

};

class RhsFunction {
public:
    virtual State apply(State state) = 0;
};

class EMFieldMovingFunction : public RhsFunction {
    double electricFieldValue;
    double magneticFieldValue;
    Point3D electricFieldDirection;
    Point3D magneticFieldDirection;
public:
    State apply(State state) override;
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

//    EulerSolver(const EulerSolver &es) {
//        if (&es != this) {
//            previousStates = es.previousStates;
//            onUpdateConsumer = es.onUpdateConsumer;
//            rhsFunction = es.rhsFunction;
//            h = es.h;
//            maxIterations = es.maxIterations;
//        }
//    }

public:
    EulerSolver(
            std::shared_ptr<RhsFunction> rhsFunction,
            std::function<void(State)> onUpdateConsumer_,
            double h_ = 0.01, int maxIterations_ = 10000);


    void solve(State initialState) override;
};





#endif //SPBETU_DYNAMICSYSTEMS_COURSEWORK_SOLVER_H
