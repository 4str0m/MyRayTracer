#ifndef INTERSECTIONDATA_H
#define INTERSECTIONDATA_H

#include <Eigen/Dense>
using namespace Eigen;

class Material;

struct IntersectionData
{
    double d;
    Vector3d pos;
    Vector3d n;
    const Material *mat;
};

#endif // INTERSECTIONDATA_H
