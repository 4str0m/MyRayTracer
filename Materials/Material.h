#ifndef MATERIAL_H
#define MATERIAL_H

#include "../Utils/Color.h"

struct Material
{
    Color c;

    public:
        Material(Color c)
        : c(c) {}

    private:
};

#endif // MATERIAL_H
