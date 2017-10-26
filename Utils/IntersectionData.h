#ifndef INTERSECTIONDATA_H
#define INTERSECTIONDATA_H

#include <Eigen/Geometry>
using namespace Eigen;

#include "Color.h"

class Material;

struct IntersectionData
{
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    float d;
    Vector3f pos;
    Vector3f n;
    Color c = Color::BLACK;
    const Material *mat;
    float blendFactor = 0.5;
};

#endif // INTERSECTIONDATA_H
