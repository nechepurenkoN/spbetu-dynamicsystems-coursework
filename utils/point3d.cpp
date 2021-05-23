//
// Created by 79612 on 23.05.2021.
//

#include "point3d.h"

Point3D operator+(const Point3D &lhs, const Point3D &rhs) {
    return Point3D(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

double operator*(const Point3D &lhs, const Point3D &rhs) {
    return lhs.x*rhs.x + lhs.y*rhs.y + lhs.z*rhs.z;
}

Point3D operator*(const double &scalar, const Point3D &rhs) {
    return Point3D(scalar * rhs.x, scalar * rhs.y, scalar * rhs.z);
}

Point3D Point3D::cross(const Point3D &rhs) {
    return Point3D(y*rhs.z - z*rhs.y, z*rhs.x - x*rhs.z, x*rhs.y-y*rhs.x);
}

Point3D::Point3D(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}
