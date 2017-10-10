#include "Ray.h"

double Ray::distanceFrom(const Vec4& p) const
{
    Vec4 pp = pos - p;
    return pp.cross(dir).mag() / dir.mag();
}
