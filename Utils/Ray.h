#ifndef RAY_H
#define RAY_H

#include "Vec4.h"

struct Ray
{
    Vec4 o;
    Vec4 d;

    public:
        Ray(Vec4 o, Vec4 d)
        : o(o), d(d.normalized()) {}

        double distanceFrom(const Vec4& p) const;
};

#endif // RAY_H
