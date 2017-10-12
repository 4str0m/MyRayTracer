#include "Vec4.h"

const Vec4 Vec4::Z(0, 0, 1);
const Vec4 Vec4::Y(0, 1, 0);
const Vec4 Vec4::X(1, 0, 0);

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
Vec4 Vec4::operator/(double d) const
{
    return operator*(1./d);
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

Vec4 Vec4::reflect(const Vec4& o) const
{
    Vec4 n = o.normalized();
    return *this - n * 2 * this->dot(n);
}

double Vec4::mag() const
{
    return sqrt(sqrMag());
}
double Vec4::sqrMag() const
{
    return x*x + y*y + z*z;
}

double Vec4::dot(const Vec4& o) const
{
    return x*o.x + y*o.y + z*o.z;
}

Vec4 Vec4::normalized() const
{
    return *this / mag();
}

std::ostream& operator<<(std::ostream& os, const Vec4& v)
{
    os << v.x << ", " << v.y << ", " << v.z;
    return os;
}
