#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <Object.h>


class Triangle final : public Object
{
    public:
        Triangle(Material *mat, Vector3d p0, Vector3d p1, Vector3d p2)
        :   Object(mat)
        ,   p0(p0)
        ,   p1(p1)
        ,   p2(p2)
        ,   n((p1-p0).cross(p2-p0).normalized()) {}

        bool intersect(const Ray& ray, IntersectionData *intersectionData) const override;

    private:
        Vector3d p0;
        Vector3d p1;
        Vector3d p2;

        Vector3d n;
};

#endif // TRIANGLE_H
