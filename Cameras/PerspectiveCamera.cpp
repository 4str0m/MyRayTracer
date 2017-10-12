#include "PerspectiveCamera.h"

Ray PerspectiveCamera::getRayAtPixel(double x, double y) const
{
    Vec4 dir = m_rightDir * (x - m_width/2.) + m_upDir * (y - m_height/2.) + m_eyeDir * m_focalLength;
    return {m_pos, dir.normalized()};
}
