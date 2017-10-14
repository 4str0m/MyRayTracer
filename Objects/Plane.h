#ifndef PLANE_H
#define PLANE_H

#include "Object.h"

#include <Eigen/Geometry>
using namespace Eigen;


class Plane : public Object
{
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    public:
        Plane(Material *mat, const Vector3f& p, const Vector3f& n)
        : Object(mat), p(p), n(n) {}

        bool intersect(const Ray& ray, IntersectionData *intersectionData) const override;

    private:
        Vector3f p;
        Vector3f n;
};

#endif // PLANE_H
