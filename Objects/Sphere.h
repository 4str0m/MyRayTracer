#ifndef SPHERE_H
#define SPHERE_H

#include <Object.h>


class Sphere : public Object
{
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    public:
        Sphere(Material *mat, double r, const Vector3d& p)
        : Object(mat), m_radius(r), m_pos(p) {}

        bool intersect(const Ray& ray, IntersectionData *intersectionData) const override;

    private:
        double m_radius;
        Vector3d m_pos;
};

#endif // SPHERE_H
