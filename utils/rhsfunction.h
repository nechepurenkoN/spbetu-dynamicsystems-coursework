//
// Created by 79612 on 23.05.2021.
//

#ifndef SPBETU_DYNAMICSYSTEMS_COURSEWORK_RHSFUNCTION_H
#define SPBETU_DYNAMICSYSTEMS_COURSEWORK_RHSFUNCTION_H

#include "../utils/state.h"
#include "../utils/point3d.h"
#include <QVector3D>
#include <vector>

class RhsFunction {
public:
    virtual State apply(State state) = 0;
};

class UniformField {

public:
    double value;
    Point3D direction;

    UniformField(double value, const Point3D &direction);
};

class EMFieldMovingFunction : public RhsFunction {
private:
    std::vector<UniformField *> electricFields;
    std::vector<UniformField *> magneticFields;
    Point3D displayTranspose;
    Point3D displayNormal;

public:

    void addDisplay(QVector3D trans, QVector3D normal);

    bool terminatePredicate(Point3D &coord);

    State apply(State state) override;

    void addElectricField(UniformField *field);

    void addMagneticField(UniformField *field);

    std::vector<UniformField *> &getElectricFields();

    std::vector<UniformField *> &getMagneticFields();

    ~EMFieldMovingFunction() noexcept;
};


#endif //SPBETU_DYNAMICSYSTEMS_COURSEWORK_RHSFUNCTION_H
