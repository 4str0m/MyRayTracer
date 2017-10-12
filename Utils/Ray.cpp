#include "Ray.h"

double Ray::distanceFrom(const Vector3d& p) const
{
    return (o - p).cross(d).norm() / d.norm();
}
