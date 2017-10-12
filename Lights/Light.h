#ifndef LIGHT_H
#define LIGHT_H

#include <Eigen/Dense>
using namespace Eigen;
#include "../Utils/Color.h"

struct Light
{
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    public:
        Light(const Vector3d& p, Color c, double pow)
        : pos(p), c(c), power(pow) {}

    public:
        Vector3d pos;
        Color c;
        double power;
};

#endif // LIGHT_H
