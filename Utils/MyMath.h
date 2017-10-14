#ifndef MYMATH_H
#define MYMATH_H

#include <Eigen/Geometry>
using namespace Eigen;

static constexpr float M_PI = 3.141592653589793238462643383279;

namespace Eigen
{

    Vector3f reflect(const Vector3f& v1, const Vector3f& v2);

}

namespace std
{
    float clamp(float v, float min, float max);
}

#endif // MYMATH_H
