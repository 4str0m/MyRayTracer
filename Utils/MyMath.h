#ifndef MYMATH_H
#define MYMATH_H

namespace std
{
    double clamp(double v, double min, double max) { return v < max ? v < min ? min : v : max; }
}

#endif // MYMATH_H
