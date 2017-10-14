#ifndef RAY_H
#define RAY_H

#include <Eigen/Geometry>
using namespace Eigen;

struct Ray
{
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    Vector3f o;
    Vector3f d;

    public:
        Ray(const Vector3f& o, const Vector3f& d)
        : o(o), d(d.normalized()) {}

        float distanceFrom(const Vector3f& p) const;

        inline Vector3f at(float t) const { return o + d * t; }
};

#endif // RAY_H
