#include "Triangle.h"

bool Triangle::intersect(const Ray& ray, IntersectionData *intersectionData) const
{
    const static Vector3d transformedP0 = m_t * p0;
    const static Vector3d transformedP1 = m_t * p1;
    const static Vector3d transformedP2 = m_t * p2;
    const static Vector3d transformedN  = m_t * n;

    /* first compute intersection with plane containing triangle */
    double denom = ray.d.dot(transformedN);
    if (denom == 0)
        return false;
    double d = (transformedP0 - ray.o).dot(transformedN) / denom;
    if (d < DELTA_INTERSECT)
        return false;

    Vector3d u = transformedP1 - transformedP0;
    Vector3d v = transformedP2 - transformedP0;

    Vector3d w = ray.at(d) - transformedP0;

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
        intersectionData->n = transformedN;
        intersectionData->mat = m_mat;
    }
    return true;
}
