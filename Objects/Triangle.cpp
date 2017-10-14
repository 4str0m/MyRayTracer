#include "Triangle.h"

bool Triangle::intersect(const Ray& ray, IntersectionData *intersectionData) const
{
    const static Vector3f transformedP0 = m_t * p0;
    const static Vector3f transformedP1 = m_t * p1;
    const static Vector3f transformedP2 = m_t * p2;
    const static Vector3f transformedN  = m_t * n;

    /* first compute intersection with plane containing triangle */
    float denom = ray.d.dot(transformedN);
    if (denom == 0)
        return false;
    float d = (transformedP0 - ray.o).dot(transformedN) / denom;
    if (d < DELTA_INTERSECT)
        return false;

    Vector3f u = transformedP1 - transformedP0;
    Vector3f v = transformedP2 - transformedP0;

    Vector3f w = ray.at(d) - transformedP0;

    float uv = u.dot(v);
    float wv = w.dot(v);
    float wu = w.dot(u);
    float vv = v.dot(v);
    float uu = u.dot(u);

    float denom2 = uv*uv - uu*vv;

    float s1 = (uv*wv - vv*wu) / denom2;
    float t1 = (uv*wu - uu*wv) / denom2;

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
