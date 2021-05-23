//
// Created by 79612 on 23.05.2021.
//

#ifndef SPBETU_DYNAMICSYSTEMS_COURSEWORK_RHSFUNCTION_H
#define SPBETU_DYNAMICSYSTEMS_COURSEWORK_RHSFUNCTION_H
#include "../utils/state.h"
#include "../utils/point3d.h"


class RhsFunction {
public:
    virtual State apply(State state) = 0;
};

class EMFieldMovingFunction : public RhsFunction {
private:
    double electricFieldValue;
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


#endif //SPBETU_DYNAMICSYSTEMS_COURSEWORK_RHSFUNCTION_H
