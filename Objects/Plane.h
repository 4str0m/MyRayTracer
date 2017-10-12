#ifndef PLANE_H
#define PLANE_H

#include "Object.h"

#include <Eigen/Dense>
using namespace Eigen;


class Plane : public Object
{
    public:
        Plane(Material *mat, Vector3d p, Vector3d n)
        : Object(mat), p(p), n(n) {}

        bool intersect(const Ray& ray, IntersectionData *intersectionData) const override;

    private:
        Vector3d p;
        Vector3d n;
};

#endif // PLANE_H
