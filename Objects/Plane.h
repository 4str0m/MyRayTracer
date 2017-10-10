#ifndef PLANE_H
#define PLANE_H

#include "Object.h"

#include "../Utils/Vec4.h"


class Plane : public Object
{
    public:
        Plane(Material *mat, Vec4 p, Vec4 n)
        : Object(mat), p(p), n(n) {}

        bool intersect(const Ray& ray, IntersectionData *intersectionData) const override;

    private:
        Vec4 p;
        Vec4 n;
};

#endif // PLANE_H
