#include "Plane.h"

bool Plane::intersect(const Ray& ray, IntersectionData *intersectionData) const
{
    double denom = ray.d.dot(n);
    if (denom == 0)
        return false;
    double d = (p - ray.o).dot(n) / denom;
    if (d < DELTA_INTERSECT)
        return false;

    if (intersectionData)
    {
        intersectionData->d = d;
        intersectionData->pos = ray.at(d);
        intersectionData->n = n;
        intersectionData->mat = m_mat;
    }
    return true;
}
