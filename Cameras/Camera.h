#ifndef CAMERA_H
#define CAMERA_H

#include <stdlib.h>

#include <Eigen/Dense>
using namespace Eigen;

#include "../Utils/Ray.h"


class Camera
{
    public:
        Camera(size_t w, size_t h, Vector3d p, Vector3d dir)
        :   m_width(w)
        ,   m_height(h)
        ,   m_pos(p)
        ,   m_eyeDir(dir.normalized())
        ,   m_rightDir(m_eyeDir.cross(Vector3d(0,0,1)).normalized())
        ,   m_upDir(m_eyeDir.cross(m_rightDir).normalized()) {
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
