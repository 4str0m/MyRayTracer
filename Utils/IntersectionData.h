#ifndef INTERSECTIONDATA_H
#define INTERSECTIONDATA_H

#include "Vec4.h"
#include "../Materials/Material.h"

struct IntersectionData
{
    double d;
    Vec4 pos;
    Vec4 n;
    const Material *mat;
};

#endif // INTERSECTIONDATA_H
