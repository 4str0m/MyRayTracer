#include "Vec4.h"

Vec4 Vec4::operator-() const
{
    return *this * -1;
}

Vec4 Vec4::operator+(const Vec4& o) const
{
    return Vec4(x+o.x, y+o.y, z+o.z);
}
Vec4 Vec4::operator-(const Vec4& o) const
{
    return *this + (-o);
}
Vec4 Vec4::operator*(double d) const
{
    return Vec4(x*d, y*d, z*d);
}

Vec4& Vec4::operator+=(const Vec4& o)
{
    *this = *this + o;
    return *this;
}
Vec4& Vec4::operator-=(const Vec4& o)
{
    *this = *this - o;
    return *this;
}

Vec4& Vec4::operator*=(double d)
{
    x *= d;
    y *= d;
    z *= d;
    return *this;
}

Vec4 Vec4::cross(const Vec4& o) const
{
    return Vec4(y*o.z - z*o.y, z*o.x - x*o.z, x*o.y - y*o.x);
}

double Vec4::mag() const
{
    return sqrt(sqrMag());
}
double Vec4::sqrMag() const
{
    return x*x + y*y + z*z;
}

Vec4 Vec4::normalized() const
{
    double m = mag();
    return Vec4(x / m, y / m, z / m);
}
