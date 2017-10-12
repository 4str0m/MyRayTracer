#ifndef VEC4_H
#define VEC4_H

#include <math.h>
#include <iostream>

class Vec4
{
    public:
        static const Vec4 Z;
        static const Vec4 Y;
        static const Vec4 X;

    public:
        Vec4()
        : x(0), y(0), z(0), w(0) {}

        Vec4(double x, double y, double z)
        : x(x), y(y), z(z), w(0) {}

        Vec4 operator-() const;
        Vec4 operator+(const Vec4& o) const;
        Vec4 operator-(const Vec4& o) const;
        Vec4 operator*(double d) const;
        Vec4 operator/(double d) const;

        Vec4& operator+=(const Vec4& o);
        Vec4& operator-=(const Vec4& o);
        Vec4& operator*=(double d);

        Vec4 cross(const Vec4& o) const;
        double dot(const Vec4& o) const;

        Vec4 reflect(const Vec4& o) const;

        double mag() const;
        double sqrMag() const;
        Vec4 normalized() const;

    public:
        double x;
        double y;
        double z;
        double w; // unused
};

std::ostream& operator<<(std::ostream& os, const Vec4& v);

#endif // VEC4_H
