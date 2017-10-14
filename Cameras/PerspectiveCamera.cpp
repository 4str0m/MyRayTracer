#include "PerspectiveCamera.h"

Ray PerspectiveCamera::getRayAtPixel(float x, float y) const
{
    Vector3f dir = m_rightDir * (x-m_width*.5) + m_upDir * (-y+m_height*.5) + m_eyeDir * m_focalLength;
    return {m_pos, dir};
}
