#include "Texture.h"

#include "MyMath.h"

Color Texture::sampleColor(const Vector2f &texCoord) const
{
    float x = std::clamp(texCoord.x(), 0.0, 1.0);
    float y = std::clamp(texCoord.y(), 0.0, 1.0);
    int index = (int)(x * (m_width-1)) + (int)(y * (m_height-1)) * m_width;
    return Color(m_data[index*3]/255.0, m_data[index*3+1]/255.0, m_data[index*3+2]/255.0);
}
