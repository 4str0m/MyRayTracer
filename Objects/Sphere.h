#ifndef SPHERE_H
#define SPHERE_H

#include <Object.h>


class Sphere : public Object
{
    public:
        Sphere(Material *mat, double r, Vec4 p)
        : Object(mat), m_radius(r), m_pos(p) {}

        bool intersect(const Ray& ray, IntersectionData *intersectionData) const override;

    private:
        double m_radius;
        Vec4 m_pos;
};

#endif // SPHERE_H
