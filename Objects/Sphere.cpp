#include "Sphere.h"

bool Sphere::intersects(const Ray& ray) const
{
    return ray.distanceFrom(m_pos) <= m_radius;
}
