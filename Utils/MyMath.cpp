#include "MyMath.h"

namespace Eigen
{
    Vector3f reflect(const Vector3f& v1, const Vector3f& v2)
    {
        return v1 - 2 * v2 * v1.dot(v2);
    }

}

namespace std
{
    float clamp(float v, float min, float max) { return v < max ? v < min ? min : v : max; }
    float map(float v, float iMin, float iMax, float fMin, float fMax)
    {
        return fMin + (v - iMin) * (fMax - fMin) / (iMax - iMin);
    }
}
