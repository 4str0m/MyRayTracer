#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include "Light.h"

class PointLight : public Light
{
    public:
        PointLight(Vector3d pos, Color c, double pow)
        : Light(pos, c, pow) {}
};

#endif // POINTLIGHT_H
