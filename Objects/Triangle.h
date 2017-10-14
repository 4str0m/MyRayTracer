#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <Object.h>


class Triangle final : public Object
{
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    public:
        Triangle(const Material *mat, const Vector3f& p0, const Vector3f& p1, const Vector3f& p2)
        :   Object(mat)
        ,   p0(p0)
        ,   p1(p1)
        ,   p2(p2)
        {
            n = (p1-p0).cross(p2-p0).normalized();
        }

        bool intersect(const Ray& ray, IntersectionData *intersectionData) const override;

    private:
        Vector3f p0;
        Vector3f p1;
        Vector3f p2;

        Vector3f n;
};

#endif // TRIANGLE_H
