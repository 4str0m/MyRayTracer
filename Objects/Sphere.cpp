#include "Sphere.h"

bool Sphere::intersect(const Ray& ray, IntersectionData *intersectionData) const
{
    Vector3f transformedPos = m_t*m_pos;

    float a = ray.d.dot(ray.d);
    Vector3f oc = ray.o - transformedPos;
    float b = 2*(ray.d.dot(oc));
    float c = oc.dot(oc) - m_radius*m_radius;

    float det = b*b - 4*a*c;
    if (det < 0)
        return false;
    float sqrtdet = sqrt(det);
    float d1 = (-b - sqrtdet) / (2*a);
    float d2 = (-b + sqrtdet) / (2*a);

    if (d2 < DELTA_INTERSECT && d1 < DELTA_INTERSECT)
        return false; // the two points land behind the ray

    if (intersectionData)
    {
        intersectionData->d = d1 < d2 && d1 > DELTA_INTERSECT ? d1 : d2;
        intersectionData->pos = ray.at(intersectionData->d);
        intersectionData->n = (intersectionData->pos - transformedPos).normalized();
        intersectionData->mat = m_mat;
    }
    return true;
}
