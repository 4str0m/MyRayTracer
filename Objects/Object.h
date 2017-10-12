#ifndef OBJECT_H
#define OBJECT_H

#include <Eigen/Dense>
using namespace Eigen;

#include "../Utils/Ray.h"
#include "../Utils/IntersectionData.h"
#include "../Materials/Material.h"
#include "../Utils/MyMath.h"

#define DELTA_INTERSECT 0.01

class Object
{
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    public:
        Object(Material *mat)
        : m_mat(mat)
        , m_t(Matrix<double, 3, 3>::Identity()) {}

        virtual ~Object() = default;

        virtual bool intersect(const Ray& ray, IntersectionData *intersectionData) const = 0;

        Object& rotate(double angle, const Vector3d& axis)
        {
            m_t.rotate(AngleAxisd(angle*M_PI/180., axis));
            return *this;
        }
        Object& translate(const Vector3d& v)
        {
            m_t.translate(v);
            return *this;
        }
        Object& scale(const Vector3d& s)
        {
            m_t.scale(s);
            return *this;
        }

    protected:
        const Material *m_mat;
        Transform<double, 3, Affine> m_t;
};

#endif // OBJECT_H
