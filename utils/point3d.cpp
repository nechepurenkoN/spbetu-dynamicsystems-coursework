//
// Created by 79612 on 23.05.2021.
//

#include "point3d.h"
#include <stdlib.h>
#include <cmath>

Point3D operator+(const Point3D &lhs, const Point3D &rhs) {
    return Point3D(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

double operator*(const Point3D &lhs, const Point3D &rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

Point3D operator*(double scalar, const Point3D &rhs) {
    return Point3D(scalar * rhs.x, scalar * rhs.y, scalar * rhs.z);
}

std::ostream &operator<<(std::ostream &os, const Point3D &point) {
    os << "[" << point.x << " " << point.y << " " << point.z << "]";
    return os;
}

Point3D Point3D::cross(const Point3D &rhs) {
    return Point3D(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x);
}

Point3D::Point3D(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

bool operator==(const Point3D &lhs, const Point3D &rhs) {
    return std::abs(lhs.x - rhs.x) <= 1e-6
           && std::abs(lhs.y - rhs.y) <= 1e-6
           && std::abs(lhs.z - rhs.z) <= 1e-6;
}

double Point3D::absoluteValue() {
    return std::sqrt(x*x + y*y + z*z);
}

Point3D Point3D::normalize() {
    return absoluteValue() * Point3D(x, y, z);
}
