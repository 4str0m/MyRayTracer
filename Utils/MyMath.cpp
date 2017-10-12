#include "MyMath.h"

namespace std
{
    double clamp(double v, double min, double max) { return v < max ? v < min ? min : v : max; }
}
