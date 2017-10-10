#include "Ray.h"

double Ray::distanceFrom(const Vec4& p) const
{
    return (o - p).cross(d).mag() / d.mag();
}
