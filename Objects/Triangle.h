#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <Object.h>


class Triangle final : public Object
{
    public:
        Triangle(Material *mat, Vec4 p0, Vec4 p1, Vec4 p2)
        :   Object(mat)
        ,   p0(p0)
        ,   p1(p1)
        ,   p2(p2)
        ,   n((p1-p0).cross(p2-p0).normalized()) {}

        bool intersect(const Ray& ray, IntersectionData *intersectionData) const override;

    private:
        Vec4 p0;
        Vec4 p1;
        Vec4 p2;

        Vec4 n;
};

#endif // TRIANGLE_H
