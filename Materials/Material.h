#ifndef MATERIAL_H
#define MATERIAL_H

#include "../Utils/Color.h"

struct Material
{
    Color diffuseColor;
    Color specularColor;
    Color ambientColor;

    public:
        Material(Color dc = {0}, Color sc = {0}, Color ac = {0})
        : diffuseColor(dc), specularColor(sc), ambientColor(ac) {}

};

#endif // MATERIAL_H
