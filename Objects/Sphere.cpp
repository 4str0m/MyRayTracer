#include "Sphere.h"

bool Sphere::intersect(const Ray& ray, IntersectionData *intersectionData) const
{
    double a = ray.d.dot(ray.d);
    Vec4 oc = ray.o - m_pos;
    double b = 2*(ray.d.dot(oc));
    double c = oc.dot(oc) - m_radius*m_radius;

    double det = b*b - 4*a*c;
    if (det < 0)
        return false;
    double sqrtdet = sqrt(det);
    double d1 = (-b - sqrtdet) / (2*a);
    double d2 = (-b + sqrtdet) / (2*a);

    if (d2 < 0 && d1 < 0)
        return false; // the two points land behind the ray

    intersectionData->pos = ray.o + ray.d * (d1 < d2 && d1 > 0 ? d1 : d2);
    intersectionData->normal = (intersectionData->pos - m_pos).normalized();
    return true;
}
