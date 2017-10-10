#ifndef COLOR_H
#define COLOR_H

#include <inttypes.h>

#include <iostream>

struct Color
{
    uint8_t r;
    uint8_t g;
    uint8_t b;

    public:
        Color(uint8_t gray = 0)
        : r(gray), g(gray), b(gray) {}

        Color(uint8_t r, uint8_t g, uint8_t b)
        : r(r), g(g), b(b) {}

};

std::ostream& operator<<(std::ostream& os, const Color& c);

#endif // COLOR_H
