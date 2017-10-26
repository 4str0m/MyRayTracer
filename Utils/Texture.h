#ifndef TEXTURE_H
#define TEXTURE_H

#include "stb_image.h"
#include "Color.h"

#include <Eigen/Geometry>
using namespace Eigen;

class Texture
{
    public:
        Texture(const char* fileName)
        {
            //stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
            m_data = stbi_load(fileName, &m_width, &m_height, &m_nrChannels, 0);
        }
        virtual ~Texture()
        {
            stbi_image_free(m_data);
        }

        Color sampleColor(const Vector2f &texCoord) const;

    private:
        unsigned char* m_data;
        int m_width;
        int m_height;
        int m_nrChannels;
};

#endif // TEXTURE_H
