#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include "Light.h"

class PointLight : public Light
{
    public:
        PointLight(const Vector3f& pos, Color c, float pow)
        : Light(pos, c, pow) {}
};

#endif // POINTLIGHT_H
