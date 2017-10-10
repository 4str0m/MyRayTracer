#ifndef RAY_H
#define RAY_H

#include "Vec4.h"

struct Ray
{
    Vec4 pos;
    Vec4 dir;

    public:
        Ray(Vec4 pos, Vec4 dir)
        : pos(pos), dir(dir) {}

        double distanceFrom(const Vec4& p) const;

};

#endif // RAY_H
