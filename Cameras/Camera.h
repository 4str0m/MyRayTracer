#ifndef CAMERA_H
#define CAMERA_H

#include <stdlib.h>

#include <Eigen/Geometry>
using namespace Eigen;

#include "../Utils/Ray.h"
#include "../Utils/MyMath.h"

class Camera
{
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    public:
        Camera(size_t w, size_t h, const Vector3f& p)
        :   m_width(w)
        ,   m_height(h)
        ,   m_pos(p)
        ,   m_eyeDir(Vector3f::UnitZ())
        ,   m_rightDir(Vector3f::UnitX())
        ,   m_upDir(Vector3f::UnitY())
        {
            Transform<float, 3, Affine> t(Matrix<float, 3, 3>::Identity());
            t.rotate(AngleAxisf(-20*M_PI/180.f, Vector3f::UnitY()));
            t.rotate(AngleAxisf(20*M_PI/180.f, Vector3f::UnitX()));
            m_eyeDir = t*m_eyeDir;
            m_rightDir = t*m_rightDir;
            m_upDir = t*m_upDir;
        }

        virtual ~Camera() = default;

        virtual Ray getRayAtPixel(float x, float y) const = 0;

        inline size_t getWidth() const { return m_width; }
        inline size_t getHeight() const { return m_height; }

    protected:
        size_t m_width;
        size_t m_height;
        Vector3f m_pos;
        Vector3f m_eyeDir;
        Vector3f m_rightDir;
        Vector3f m_upDir;
};

#endif // CAMERA_H
