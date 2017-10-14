#ifndef PERSPECTIVECAMERA_H
#define PERSPECTIVECAMERA_H

#include <Camera.h>

class PerspectiveCamera : public Camera
{
    public:
        PerspectiveCamera(size_t w, size_t h, const Vector3f& p, size_t focalLength)
        :   Camera(w,h,p)
        ,   m_focalLength(focalLength) {}

        Ray getRayAtPixel(float x, float y) const override;

    private:
        float m_focalLength;
};

#endif // PERSPECTIVECAMERA_H
