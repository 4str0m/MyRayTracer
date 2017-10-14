#ifndef SPHERE_H
#define SPHERE_H

#include <Object.h>


class Sphere : public Object
{
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    public:
        Sphere(Material *mat, float r, const Vector3f& p)
        : Object(mat), m_radius(r), m_pos(p) {}

        bool intersect(const Ray& ray, IntersectionData *intersectionData) const override;

    private:
        float m_radius;
        Vector3f m_pos;
};

#endif // SPHERE_H
