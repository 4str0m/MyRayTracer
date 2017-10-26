#ifndef VERTEX_H
#define VERTEX_H

#include <Eigen/Geometry>
using namespace Eigen;

#include "Color.h"

struct Vertex
{
    Vector3f    pos;
    Vector3f    n;
    Vector2f    uv;
    Color       color;

    public:
        Vertex(const Vector3f &pos, const Vector3f &n, const Vector2f &uv, const Color &color)
        :   pos(pos)
        ,   n(n)
        ,   uv(uv)
        ,   color(color)
        {}
};

#endif // VERTEX_H
