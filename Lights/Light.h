#ifndef LIGHT_H
#define LIGHT_H

#include <Eigen/Geometry>
using namespace Eigen;
#include "../Utils/Color.h"

struct Light
{
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    public:
        Light(const Vector3f& p, Color c, float pow)
        : pos(p), c(c), power(pow) {}

    public:
        Vector3f pos;
        Color c;
        float power;
};

#endif // LIGHT_H
