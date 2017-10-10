#include "Color.h"

std::ostream& operator<<(std::ostream& os, const Color& c)
{
    os << (int)c.r << " " << (int)c.g << " " << (int)c.b;
    return os;
}
