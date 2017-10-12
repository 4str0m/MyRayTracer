#ifndef CAMERA_H
#define CAMERA_H

#include <stdlib.h>

#include "../Utils/Vec4.h"
#include "../Utils/Ray.h"

class Camera
{
    public:
        Camera(size_t w, size_t h, Vec4 p, Vec4 dir)
        :   m_width(w)
        ,   m_height(h)
        ,   m_pos(p)
        ,   m_eyeDir(dir.normalized())
        ,   m_rightDir(m_eyeDir.cross(Vec4::Z).normalized())
        ,   m_upDir(m_eyeDir.cross(m_rightDir).normalized()) {
        }

        virtual ~Camera() = default;

        virtual Ray getRayAtPixel(double x, double y) const = 0;

        inline size_t getWidth() const { return m_width; }
        inline size_t getHeight() const { return m_height; }

    protected:
        size_t m_width;
        size_t m_height;
        Vec4 m_pos;
        Vec4 m_eyeDir;
        Vec4 m_rightDir;
        Vec4 m_upDir;
};

#endif // CAMERA_H
