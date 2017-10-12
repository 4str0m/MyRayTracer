#ifndef INTERSECTIONDATA_H
#define INTERSECTIONDATA_H

#include "Vec4.h"

class Material;

struct IntersectionData
{
    double d;
    Vec4 pos;
    Vec4 n;
    const Material *mat;
};

#endif // INTERSECTIONDATA_H
