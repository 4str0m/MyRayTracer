#ifndef PERSPECTIVECAMERA_H
#define PERSPECTIVECAMERA_H

#include <Camera.h>

class PerspectiveCamera : public Camera
{
    public:
        PerspectiveCamera(size_t w, size_t h, Vector3d p, Vector3d dir, size_t focalLength)
        :   Camera(w,h,p,dir)
        ,   m_focalLength(focalLength) {}

        Ray getRayAtPixel(double x, double y) const override;

    private:
        double m_focalLength;
};

#endif // PERSPECTIVECAMERA_H
