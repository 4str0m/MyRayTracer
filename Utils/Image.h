#ifndef IMAGE_H
#define IMAGE_H

#include <string>

#include "Color.h"

class Image
{
    public:
        Image(size_t w, size_t h)
        : m_width(w), m_height(h)
        {
            m_pixels = new Color[w * h];
        }

        ~Image()
        {
            delete [] m_pixels;
        }

        void saveImage(std::string fileName);

        Color getPixel(size_t x, size_t y) { return isIndexValid(x,y) ? m_pixels[x + y*m_width] : Color(); }
        void setPixel(size_t x, size_t y, const Color& c) { if (isIndexValid(x,y)) m_pixels[x + y*m_width] = c; }

    private:
        inline bool isIndexValid(size_t x, size_t y) { return x < m_width && y < m_height; }

    private:
        size_t m_width;
        size_t m_height;

        Color *m_pixels;
};

#endif // IMAGE_H
