#ifndef ORTHOGRAPHICCAMERA_H
#define ORTHOGRAPHICCAMERA_H

#include <Camera.h>


class OrthographicCamera : public Camera
{
    public:
        OrthographicCamera(size_t w, size_t h, const Vector3f& p)
        :   Camera(w,h,p) {}

        Ray getRayAtPixel(float x, float y) const override;
};

#endif // ORTHOGRAPHICCAMERA_H
