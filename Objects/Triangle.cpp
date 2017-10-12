#include "Triangle.h"

bool Triangle::intersect(const Ray& ray, IntersectionData *intersectionData) const
{
    /* first compute intersection with plane containing triangle */
    double denom = ray.d.dot(n);
    if (denom == 0)
        return false;
    double d = (p0 - ray.o).dot(n) / denom;
    if (d < DELTA_INTERSECT)
        return false;

    Vec4 u = p1 - p0;
    Vec4 v = p2 - p0;

    Vec4 w = ray.at(d) - p0;

    double uv = u.dot(v);
    double wv = w.dot(v);
    double wu = w.dot(u);
    double vv = v.dot(v);
    double uu = u.dot(u);

    double denom2 = uv*uv - uu*vv;

    double s1 = (uv*wv - vv*wu) / denom2;
    double t1 = (uv*wu - uu*wv) / denom2;

    // check if point in triangle
    if (s1 < 0 || t1 < 0 || s1+t1 > 1)
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
