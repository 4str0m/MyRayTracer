#ifndef INTERSECTIONDATA_H
#define INTERSECTIONDATA_H

#include <Eigen/Geometry>
using namespace Eigen;

class Material;

struct IntersectionData
{
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    float d;
    Vector3f pos;
    Vector3f n;
    const Material *mat;
};

#endif // INTERSECTIONDATA_H
