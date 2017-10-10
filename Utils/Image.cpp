#include "Image.h"

#include <fstream>

void Image::saveImage(std::string fileName)
{
    std::ofstream out((fileName + ".ppm").c_str());

    out << "P3\n" << m_width << "\n" << m_height << "\n255\n";

    for (size_t y = 0; y < m_height; ++y)
    {
        for (size_t x = 0; x < m_width; ++x)
        {
            out << m_pixels[x + y * m_width] << " ";
        }
        out << std::endl;
    }
    out << std::endl;
}

