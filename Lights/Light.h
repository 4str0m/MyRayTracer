#ifndef LIGHT_H
#define LIGHT_H

#include "../Utils/Vec4.h"
#include "../Utils/Color.h"

struct Light
{
    public:
        Light(Vec4 p, Color c, double pow)
        : pos(p), c(c), power(pow) {}

    public:
        Vec4 pos;
        Color c;
        double power;
};

#endif // LIGHT_H
