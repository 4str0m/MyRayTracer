#ifndef MYMATH_H
#define MYMATH_H

#include <Eigen/Geometry>
using namespace Eigen;

static constexpr float M_PI = 3.141592653589793238462643383279;

namespace Eigen
{

    Vector3f reflect(const Vector3f& v1, const Vector3f& v2);

}

namespace math
{
    float clamp(float v, float min, float max);
    float map(float v, float iMin, float iMax, float fMin, float fMax);
}

template<typename T>
T tripolate(const T& v1, const T& v2, const T& v3, float t, float s, float u)
{
    return v1 * u + v2 * s + v3 * t;
}

#endif // MYMATH_H
