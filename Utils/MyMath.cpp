#include "MyMath.h"

namespace Eigen
{
    Vector3d reflect(const Vector3d& v1, const Vector3d& v2)
    {
        return v1 - 2 * v2 * v1.dot(v2);
    }

}

namespace std
{
    double clamp(double v, double min, double max) { return v < max ? v < min ? min : v : max; }
}
