#ifndef CAMERA_H
#define CAMERA_H

#include <stdlib.h>

#include <Eigen/Dense>
using namespace Eigen;

#include "../Utils/Ray.h"
#include "../Utils/MyMath.h"

class Camera
{
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    public:
        Camera(size_t w, size_t h, const Vector3d& p)
        :   m_width(w)
        ,   m_height(h)
        ,   m_pos(p)
        ,   m_eyeDir(Vector3d::UnitZ())
        ,   m_rightDir(Vector3d::UnitX())
        ,   m_upDir(Vector3d::UnitY())
        {
            Transform<double, 3, Affine> t(Matrix<double, 3, 3>::Identity());
            t.rotate(AngleAxisd(20*M_PI/180., Vector3d::UnitX()));
            m_eyeDir = t*m_eyeDir;
            m_rightDir = t*m_rightDir;
            m_upDir = t*m_upDir;
        }

        virtual ~Camera() = default;

        virtual Ray getRayAtPixel(double x, double y) const = 0;

        inline size_t getWidth() const { return m_width; }
        inline size_t getHeight() const { return m_height; }

    protected:
        size_t m_width;
        size_t m_height;
        Vector3d m_pos;
        Vector3d m_eyeDir;
        Vector3d m_rightDir;
        Vector3d m_upDir;
};

#endif // CAMERA_H
