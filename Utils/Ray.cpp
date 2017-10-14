#include "Ray.h"

float Ray::distanceFrom(const Vector3f& p) const
{
    return (o - p).cross(d).norm() / d.norm();
}
