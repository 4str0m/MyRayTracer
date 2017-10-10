#include "Color.h"

std::ostream& operator<<(std::ostream& os, const Color& c)
{
    os << (int)(c.r * 255) << " " << (int)(c.g * 255) << " " << (int)(c.b * 255);
    return os;
}

Color& Color::clamp()
{
    r = clampColVal(r);
    g = clampColVal(g);
    b = clampColVal(b);
    return *this;
}
