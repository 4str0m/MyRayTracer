#ifndef SPHERE_H
#define SPHERE_H

#include <Object.h>


class Sphere : public Object
{
    public:
        Sphere(double r, Vec4 p)
        : m_radius(r), m_pos(p) {}

        bool intersects(const Ray& ray) const override;

    private:
        double m_radius;
        Vec4 m_pos;
};

#endif // SPHERE_H
