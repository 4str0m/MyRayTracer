#ifndef MYMATH_H
#define MYMATH_H

#include <Eigen/Dense>
using namespace Eigen;

static constexpr double M_PI = 3.141592653589793238462643383279;

namespace Eigen
{

    Vector3d reflect(const Vector3d& v1, const Vector3d& v2);

}

namespace std
{
    double clamp(double v, double min, double max);
}

#endif // MYMATH_H
