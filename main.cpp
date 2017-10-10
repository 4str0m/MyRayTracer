#include <iostream>

#include "Sphere.h"
#include "Image.h"

int main()
{
    size_t W(500), H(500);

    Image img(W, H);

    Sphere s(100, {W/2, H/2, 0});

    Vec4 dir(0, 0, 1);
    for(size_t y = 0; y < H; ++y)
    {
        for(size_t x = 0; x < W; ++x)
        {
            int gray(0);
            for(double dy = y; dy < y+1; dy += .1)
            {
                for(double dx = x; dx < x+1; dx += .1)
                {
                    Ray r({dx, dy, -10}, dir);
                    if (s.intersects(r))
                    {
                        gray += 255;
                    }
                }
            }
            img.setPixel(x, y, {255});
        }
    }

    img.saveImage("img");
    return 0;
}
