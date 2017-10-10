#ifndef SPHERE_H
#define SPHERE_H

#include <Object.h>


class Sphere : public Object
{
    public:
        Sphere(double r, Vec4 p)
        : Object({1.0, 0, 0}), m_radius(r), m_pos(p) {}

        bool intersect(const Ray& ray, IntersectionData *intersectionData) const override;

    private:
        double m_radius;
        Vec4 m_pos;
};

#endif // SPHERE_H
