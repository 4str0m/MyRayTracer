#include "OrthographicCamera.h"

Ray OrthographicCamera::getRayAtPixel(float x, float y) const
{
    return {{x-m_width/2.f, y-m_height/2.f, -100}, m_eyeDir};
}

