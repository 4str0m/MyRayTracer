#ifndef COLOR_H
#define COLOR_H

#include <inttypes.h>

#include <iostream>

struct Color
{
    public:
        static const Color BLACK;
        static const Color WHITE;
        static const Color RED;

        float r;
        float g;
        float b;

    public:
        Color(float gray = 0.0)
        : Color(gray, gray, gray) {}

        Color(float r, float g, float b)
        : r(r), g(g), b(b) {}

        inline Color operator+(const Color& o) const { return {r+o.r, g+o.g, b+o.b}; }
        inline Color operator*(const Color& o) const { return {r*o.r, g*o.g, b*o.b}; }
        inline Color operator*(float s) const { return {r*s, g*s, b*s}; }
        inline Color operator/(float s) const { return {r/s, g/s, b/s}; }

        Color& operator+=(const Color& o) { *this = *this + o; return *this; }
        Color& operator*=(const Color& o) {*this = *this * o; return *this; }
        Color& operator*=(float s) { *this = *this * s; return *this; }
        Color& operator/=(float s) { *this = *this / s; return *this; }

        Color& clamp();

    private:
        static float clampColVal(float v) { return v < 1.0 ? v < 0.0 ? 0.0 : v : 1.0; }

};

std::ostream& operator<<(std::ostream& os, const Color& c);

#endif // COLOR_H
