#ifndef OBJECT_H
#define OBJECT_H

#include <Eigen/Geometry>
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
        , m_t(Matrix<float, 3, 3>::Identity()) {}

        virtual ~Object() = default;

        virtual bool intersect(const Ray& ray, IntersectionData *intersectionData) const = 0;

        virtual Object& rotate(float angle, const Vector3f& axis)
        {
            m_t.rotate(AngleAxisf(angle*M_PI/180., axis));
            return *this;
        }
        virtual Object& translate(const Vector3f& v)
        {
            m_t.translate(v);
            return *this;
        }
        virtual Object& scale(const Vector3f& s)
        {
            m_t.scale(s);
            return *this;
        }

    protected:
        const Material *m_mat;
        Transform<float, 3, Affine> m_t;
};

#endif // OBJECT_H
