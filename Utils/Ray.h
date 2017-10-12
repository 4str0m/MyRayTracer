#ifndef RAY_H
#define RAY_H

#include <Eigen/Dense>
using namespace Eigen;

struct Ray
{
    Vector3d o;
    Vector3d d;

    public:
        Ray(Vector3d o, Vector3d d)
        : o(o), d(d.normalized()) {}

        double distanceFrom(const Vector3d& p) const;

        inline Vector3d at(double t) const { return o + d * t; }
};

#endif // RAY_H
